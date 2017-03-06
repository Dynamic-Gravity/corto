/* $CORTO_GENERATED
 *
 * File.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_File_tc_testNonExistingFile(
    test_File this)
{
/* $begin(test/File/tc_testNonExistingFile) */
    test_assert(corto_testFile("i%20do%20not%20exist") == CORTO_FALSE);
/* $end */
}
