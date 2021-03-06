/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Security_setup(
    test_Security this)
{

    corto_voidCreateChild_auto(root_o, a);
    corto_voidCreateChild_auto(a, b);
    corto_voidCreateChild_auto(b, c);
    corto_int32CreateChild_auto(a, d, 10);

    test_TestKeyCreate();

}

void test_Security_tc_authenticate(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    test_assertstr(token, "token_user01");

    token = corto_login("Marvin", "android");
    test_assert(token != NULL);
    test_assertstr(token, "token_user02");

}

void test_Security_tc_authenticateFail(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "41");
    test_assert(token == NULL);

}

void test_Security_tc_authorizeCreate(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    test_assertstr(token, "token_user01");
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_CREATE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_object foo = corto_voidCreateChild(b, "foo");
    corto_release(b);
    test_assert(foo != NULL);

    corto_int16 ret = corto_delete(foo);
    test_assert(ret == 0);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDelete(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_DELETE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);

    corto_object foo = corto_voidCreateChild(b, "foo");
    corto_release(b);
    test_assert(foo != NULL);

    corto_int16 ret = corto_delete(foo);
    test_assert(ret == 0);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedCreate(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_CREATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);

    corto_object foo = corto_voidCreateChild(b, "foo");

    corto_release(b);
    test_assert(foo == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedDelete(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_DELETE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_object foo = corto_voidCreateChild(b, "foo");
    corto_release(b);
    test_assert(foo != NULL);

    corto_int16 ret = corto_delete(foo);
    test_assert(ret != 0);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedLookup(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedResolve(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedScopeClaim(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b/c", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);

    corto_objectseq seq = corto_scopeClaim(b);
    int i;
    for (i = 0; i < seq.length; i ++) {
        test_assert(strcmp(corto_idof(seq.buffer[i]), "c"));
    }
    corto_scopeRelease(seq);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}


int test_Security_tc_authorizeDeniedScopeWalk_walk(
    corto_object o,
    void *userData)
{
    test_assert(strcmp(corto_idof(o), "c"));
    return 1;
}

void test_Security_tc_authorizeDeniedScopeWalk(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b/c", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);

    corto_int16 ret = corto_scopeWalk(
        b, test_Security_tc_authorizeDeniedScopeWalk_walk, NULL);
    test_assert(ret == 1);

    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedSelect(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_iter iter;
    corto_int16 ret = corto_select(".").from("/a/b").iter(&iter);
    test_assert(ret == 0);
    test_assert(!corto_iter_hasNext(&iter));

    ret = corto_select("b").from("/a").iter(&iter);
    test_assert(ret == 0);
    test_assert(!corto_iter_hasNext(&iter));

    ret = corto_select("*")
        .from("/A").iter(&iter);
    test_assert(ret == 0);
    corto_resultIterForeach(iter, result) {
        test_assert(strcmp(result.id, "b"));
    }

    ret = corto_select("..").from("/a/b/c").iter(&iter);
    test_assert(ret == 0);
    test_assert(!corto_iter_hasNext(&iter));

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedUpdate(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/d", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_int32 *d = corto_resolve(root_o, "/a/d");
    test_assert(d != NULL);

    corto_int16 ret = corto_int32Update(d, 20);
    test_assert(ret != 0);

    corto_release(d);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeDeniedUpdateVoid(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_int32 *b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);

    corto_int16 ret = corto_voidUpdate(b);
    test_assert(ret != 0);

    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeLookup(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeResolve(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeSelect(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_iter iter;
    corto_int16 ret = corto_select(".").from("/a/b").iter(&iter);
    test_assert(ret == 0);
    test_assert(corto_iter_hasNext(&iter));

    ret = corto_select("b").from("/a").iter(&iter);
    test_assert(ret == 0);
    test_assert(corto_iter_hasNext(&iter));

    ret = corto_select("*")
        .from("/A").iter(&iter);
    test_assert(ret == 0);
    corto_int32 count = 0;
    corto_resultIterForeach(iter, result) {
        if (!strcmp(result.id, "b")) {
            count ++;
        }
    }
    test_assertint(count, 1);

    ret = corto_select("..").from("/a/b/c").iter(&iter);
    test_assert(ret == 0);
    test_assert(corto_iter_hasNext(&iter));

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeUpdate(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/d", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_int32 *d = corto_resolve(root_o, "/a/d");
    test_assert(d != NULL);

    corto_int16 ret = corto_int32Update(d, 20);
    test_assert(ret == 0);

    corto_release(d);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_authorizeUpdateVoid(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r);

    corto_int32 *b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);

    corto_int16 ret = corto_voidUpdate(b);
    test_assert(ret == 0);

    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyGrantLowerDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyGrantLowerDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyGrantLowerDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyGrantSameDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyGrantSameDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyGrantSameDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyUndefinedLowerDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyUndefinedLowerDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyUndefinedLowerDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyUndefinedSameDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyUndefinedSameDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockDenyUndefinedSameDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockGrantDenyLowerDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockGrantDenyLowerDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockGrantDenyLowerDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockGrantDenySameDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockGrantDenySameDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockGrantDenySameDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockSwitchUser(
    test_Security this)
{
    test_TestLock l = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule r1 = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleListInsert(l->rules, &r1);
    test_AccessRule r2 = {"token_user02", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(l->rules, &r2);

    corto_string token1 = corto_login("Ford Prefect", "42");
    test_assert(token1 != NULL);
    corto_string prev = corto_authenticate(token1);
    test_assert(prev == NULL);

    corto_int32 *b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);

    corto_string token2 = corto_login("Marvin", "android");
    test_assert(token2 != NULL);
    prev = corto_authenticate(token2);
    test_assert(prev == token1);

    b = corto_resolve(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token2);

}

void test_Security_tc_lockUndefinedDenyLowerDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockUndefinedDenyLowerDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockUndefinedDenyLowerDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockUndefinedDenySameDepthHigherPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockUndefinedDenySameDepthLowerPrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

void test_Security_tc_lockUndefinedDenySameDepthSamePrio(
    test_Security this)
{
    corto_string token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    corto_string prev = corto_authenticate(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleListInsert(upper->rules, &uR);

    test_TestLock lower = test_TestLockCreate("/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleListInsert(lower->rules, &lR);

    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);

    prev = corto_authenticate(prev);
    test_assert(prev == token);

}

