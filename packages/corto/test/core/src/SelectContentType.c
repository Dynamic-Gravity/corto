/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_SelectContentType_setup(
    test_SelectContentType this)
{

    /* Create 'json' scope for JSON mount */
    corto_object json_o = corto_voidCreateChild(root_o, "json");

    /* Create 'string' scope for Corto string mount */
    corto_object str_o = corto_voidCreateChild(root_o, "str");

    /* Create 'obj' scope with Corto objects */
    corto_object obj_o = corto_voidCreateChild(root_o, "obj");

    /* Attach json mount to json scope */
    test_JsonReplicatorCreate(json_o);

    /* Attach str mount to str scope */
    test_StringReplicatorCreate(str_o);

    /* Create three objects in 'obj' scope */
    test_PointCreateChild(obj_o, "a", 10, 20);
    test_PointCreateChild(obj_o, "b", 30, 40);
    test_PointCreateChild(obj_o, "c", 50, 60);

}

void test_SelectContentType_tc_selectBinaryFromJson(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_result *result;
    test_Point *p;

    corto_int16 ret = corto_select("json/*").contentType("binary/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 30);
    test_assertint(p->y, 40);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 50);
    test_assertint(p->y, 60);

}

void test_SelectContentType_tc_selectBinaryFromObjects(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_result *result;
    test_Point *p;

    corto_int16 ret = corto_select("obj/*").contentType("binary/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 30);
    test_assertint(p->y, 40);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 50);
    test_assertint(p->y, 60);

}

void test_SelectContentType_tc_selectBinaryFromString(
    test_SelectContentType this)
{
    corto_result *result;
    corto_iter iter;
    test_Point *p;

    corto_int16 ret = corto_select("str/*").contentType("binary/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 30);
    test_assertint(p->y, 40);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    p = (test_Point*)result->value;
    test_assert(p != NULL);
    test_assertint(p->x, 50);
    test_assertint(p->y, 60);

}

void test_SelectContentType_tc_selectJsonFromJson(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_result *result;
    corto_string json;

    corto_int16 ret = corto_select("json/*").contentType("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

}

void test_SelectContentType_tc_selectJsonFromObjects(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_result *result;
    corto_string json;

    corto_int16 ret = corto_select("obj/*").contentType("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

}

void test_SelectContentType_tc_selectJsonFromString(
    test_SelectContentType this)
{
    corto_result *result;
    corto_string json;
    corto_iter iter;

    corto_int16 ret = corto_select("str/*").contentType("text/json").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":10,\"y\":20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":30,\"y\":40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    json = corto_result_getText(result);
    test_assert(json != NULL);
    test_assert(!strcmp(json, "{\"x\":50,\"y\":60}"));

}

void test_SelectContentType_tc_selectStringFromJson(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_result *result;
    corto_string str;

    corto_int16 ret = corto_select("json/*").contentType("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/json"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

}

void test_SelectContentType_tc_selectStringFromObjects(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_result *result;
    corto_string str;

    corto_int16 ret = corto_select("obj/*").contentType("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/obj"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

}

void test_SelectContentType_tc_selectStringFromString(
    test_SelectContentType this)
{
    corto_iter iter;
    corto_result *result;
    corto_string str;

    corto_int16 ret = corto_select("str/*").contentType("text/corto").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{10,20}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{30,40}"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "/str"));
    test_assert(!strcmp(result->type, "/test/Point"));
    str = corto_result_getText(result);
    test_assert(str != NULL);
    test_assert(!strcmp(str, "{50,60}"));

}

