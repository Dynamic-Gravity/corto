
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <ftw.h>

#if __linux__
#include <linux/limits.h>
#else
#include <limits.h>
#endif

#include "corto.h"

/*
 * Receives:
 * - the error code
 * - an initial message
 * The name for the error code will be appended.
 */
static void printError(int e, const char *msg) {
    corto_seterr("%s: %s", msg, strerror(e));
}

int corto_fileTest(const char* filefmt, ...) {
    FILE* exists = NULL;
    va_list arglist;

    va_start(arglist, filefmt);
    char *file = corto_venvparse(filefmt, arglist);
    va_end(arglist);

    if (file) {
        exists = fopen(file, "rb");
        if (exists) {
            fclose(exists);
        }
    }

    corto_dealloc(file);

    return (exists != 0);
}

int corto_isdir(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int corto_touch(const char *file) {
    FILE* touch = NULL;

    if (file) {
        touch = fopen(file, "ab");
        if (touch) {
            fclose(touch);
        }
    }

    return touch ? 0 : -1;
}

int corto_chdir(const char *name) {
    if (chdir(name)) {
        corto_seterr("%s: %s", name, strerror(errno));
        return -1;
    }
    return 0;
}

char* corto_cwd(void) {
    corto_id cwd;
    getcwd(cwd, sizeof(cwd));
    return corto_setThreadString(cwd);
}

int corto_mkdir(const char *name) {
    int _errno = 0;
    char msg[PATH_MAX];

    if (mkdir(name, 0700)) {
        _errno = errno;

        /* If error is ENOENT an element in the prefix of the name
         * doesn't exist. Recursively create pathname, and retry. */
        if (errno == ENOENT) {
            /* Allocate so as to not run out of stackspace in recursive call */
            char *prefix = corto_strdup(name);
            char *ptr = &prefix[strlen(prefix)-1], ch;
            while ((ch = *ptr) && (ptr >= prefix)) {
                if (ch == '/') {
                    *ptr = '\0';
                    break;
                }
                ptr--;
            }
            if (ch == '/') {
                if (!corto_mkdir(prefix)) {
                    /* Retry current directory */
                    if (!mkdir(name, 0700)) {
                        _errno = 0;
                    } else {
                        _errno = errno;
                    }
                } else {
                    goto error;
                }
            } else {
                goto error; /* If no prefix is found, report error */
            }
            corto_dealloc(prefix);
        }

        /* Post condition for function is that directory exists so don't
         * report an error if it already did. */
        if (_errno && (_errno != EEXIST)) {
            goto error;
        }
    }

    return 0;
error:
    sprintf(msg, "%s", name);
    printError(errno, msg);
    return -1;
}

int corto_cp(const char *sourcePath, const char *destinationPath) {
    int _errno = 0;
    char msg[PATH_MAX];
    FILE *destinationFile;
    FILE *sourceFile;

    if (!(sourceFile = fopen(sourcePath, "rb"))) {
        _errno = errno;
        sprintf(msg, "cannot open file '%s'", sourcePath);
        goto error;
    }

    if (!(destinationFile = fopen(destinationPath, "wb"))) {
        _errno = errno;
        sprintf(msg, "cannot open file '%s'", sourcePath);
        fclose(sourceFile);
        goto error;
    }

    /* "no real standard portability"
     * http://www.cplusplus.com/reference/cstdio/fseek/ */
    if (fseek(sourceFile, 0, SEEK_END)) {
        _errno = errno;
        sprintf(msg, "cannot traverse file '%s'", sourcePath);
        goto error_CloseFiles;
    }

    long fileSizeResult;
    size_t fileSize;
    fileSizeResult = ftell(sourceFile);
    if (fileSizeResult == -1) {
        sprintf(msg, "cannot obtain filesize from file %s", sourcePath);
        goto error_CloseFiles;
    }
    /* Now we can be sure that fileSizeResult doesn't contain a
     * negative value */
    fileSize = fileSizeResult;

    rewind(sourceFile);

    char *buffer = corto_alloc(fileSize);
    if (!buffer) {
        _errno = 0;
        sprintf(msg, "cannot allocate buffer for copying files");
        goto error_CloseFiles;
    }

    if (fread(buffer, 1, fileSize, sourceFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "cannot read the file %s", sourcePath);
        goto error_CloseFiles_FreeBuffer;
    }

    if (fwrite(buffer, 1, fileSize, destinationFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "cannot write to the file %s", destinationPath);
        goto error_CloseFiles_FreeBuffer;
    }

    corto_dealloc(buffer);
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;

error_CloseFiles_FreeBuffer:
    free(buffer);
error_CloseFiles:
    fclose(sourceFile);
    fclose(destinationFile);
error:
    printError(_errno, msg);
    return -1;
}

/* Remove a file. Returns 0 if OK, -1 if failed */
int corto_rm(const char *name) {
    int result = 0;

    if (remove(name)) {
        /* Don't care if file didn't exist since the postcondition
         * is that file doesn't exist. */
        if (errno != EEXIST) {
            result = -1;
        }
    }

    return result;
}

static int corto_rmtreeCallback(
  const char *path,
  const struct stat *sb,
  int typeflag,
  struct FTW *ftwbuf)
{
    CORTO_UNUSED(sb);
    CORTO_UNUSED(typeflag);
    CORTO_UNUSED(ftwbuf);
    remove(path);
    return 0;
}

/* Recursively remove a directory */
int corto_rmtree(const char *name) {
    return nftw(name, corto_rmtreeCallback, 20, FTW_DEPTH);
}

/* Read the contents of a directory */
corto_ll corto_opendir(const char *name) {
    DIR *dp;
    struct dirent *ep;
    corto_ll result = NULL;

    dp = opendir (name);

    if (dp != NULL) {
        result = corto_llNew();
        while ((ep = readdir (dp))) {
            if (*ep->d_name != '.') {
                corto_llAppend(result, corto_strdup(ep->d_name));
            }
        }
        closedir (dp);
    }

    return result;
}

void corto_closedir(corto_ll dir) {
    corto_iter iter = corto_llIter(dir);

    while(corto_iterHasNext(&iter)) {
        corto_dealloc(corto_iterNext(&iter));
    }
    corto_llFree(dir);
}

corto_pid corto_procrun(const char* exec, char *argv[]) {
    pid_t pid = fork();

    if (pid == 0) {

        /* Child process */
        if (execvp(exec, argv)) {
            corto_error("core: failed to start process '%s'", exec);
            abort();
        }
    } else if (pid > 0) {
        /* Parent process */
    } else {
        /* Failure */
    }

    return pid;
}

#include "unistd.h"
#include <fcntl.h>

corto_pid corto_procrunRedirect(
    const char* exec, char *argv[], FILE *in, FILE *out, FILE *err)
{
    pid_t pid = fork();

    if (pid == 0) {
        FILE *devnull = NULL;
        if (!out || !err) {
            devnull = fopen("/dev/null", "w");
            if (!devnull) {
                corto_error("corto: failed to open /dev/null");
                abort();
            }
        }

        if (dup2(fileno(out ? out : devnull), STDOUT_FILENO) < 0) {
            corto_error("corto: failed to redirect stdout for '%s': %s", exec, strerror(errno));
            abort();
        }
        if (out) fclose(out);

        if (dup2(fileno(err ? err : devnull), STDERR_FILENO) < 0) {
            corto_error("corto: failed to redirect stderr for '%s': %s", exec, strerror(errno));
            abort();
        }

        if (err) fclose(err);
        if (devnull) fclose(devnull);

        if (dup2(fileno(in), STDIN_FILENO) < 0) {
            corto_error("corto: failed to redirect stdin for '%s': %s", exec, strerror(errno));
            abort();
        }
        if (in) fclose(in);

        /* Child process */
        if (execvp(exec, argv)) {
            corto_error("corto: failed to start process '%s'", exec);
            abort();
        }
    } else if (pid > 0) {
        /* Parent process */
    } else {
        /* Failure */
    }

    return pid;
}

int corto_prockill(corto_pid pid, corto_procsignal sig) {
    return kill(pid, sig);
}

int corto_procwait(corto_pid pid, int8_t *rc) {
    int status = 0;
    int result = 0;

    if (waitpid(pid, &status, 0) != pid) {
        corto_seterr("wait for %d failed: %s", pid, strerror(errno));
        return -1;
    }

    if (WIFSIGNALED(status)) {
        result = WTERMSIG(status);
    } else {
        if (rc) {
            *rc = WEXITSTATUS(status);
        }
    }

    return result;
}

int corto_proccheck(corto_pid pid, int8_t *rc) {
    int status = 0;
    int result = 0;

    result = waitpid(pid, &status, WNOHANG);
    if (!result) {
        /* Process did not change state, still running */
    } else if (WIFSIGNALED(status)) {
        /* Process exited with a signal */
        result = WTERMSIG(status);
    } else {
        /* Process exited normally */
        if (rc) {
            *rc = WEXITSTATUS(status);
        }
        result = -1;
    }

    return result;
}
