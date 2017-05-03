/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef CORTO_LL_H_
#define CORTO_LL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_llNode_s* corto_llNode;

typedef struct corto_llIter_s {
    corto_ll list;
    corto_llNode cur;
    corto_llNode next;
} corto_llIter_s;

CORTO_EXPORT corto_ll corto_llNew(void);
CORTO_EXPORT void corto_llFree(corto_ll);

/* Walk list */
CORTO_EXPORT int corto_llWalk(corto_ll list, corto_elementWalk_cb callback, void* userdata);

/* Walk list, return pointers to elements */
CORTO_EXPORT int corto_llWalkPtr(corto_ll list, corto_elementWalk_cb callback, void* userdata);

/* Insert at start. */
CORTO_EXPORT void corto_llInsert(corto_ll list, void* data);

/* Insert at end */
CORTO_EXPORT void corto_llAppend(corto_ll list, void* data);

/* Remove object */
CORTO_EXPORT void* corto_llRemove(corto_ll list, void* o);

/* Replace object */
CORTO_EXPORT void corto_llReplace(corto_ll list, void* o, void* by);

/* Take first */
CORTO_EXPORT void* corto_llTakeFirst(corto_ll);

/* Random access read */
CORTO_EXPORT void* corto_llGet(corto_ll list, int index);

/* Get element ptr */
CORTO_EXPORT void* corto_llGetPtr(corto_ll list, int index);

/* Find object - performs semantic comparison */
CORTO_EXPORT void* corto_llFind(corto_ll list, corto_compare_cb callback, void* o);

/* Check if object is in list - simple compare on address */
CORTO_EXPORT unsigned int corto_llHasObject(corto_ll list, void* o);

/* Last element */
CORTO_EXPORT void* corto_llLast(corto_ll list);

/* Get listsize */
CORTO_EXPORT int corto_llSize(corto_ll list);

/* Obtain regular iterator, not valid outside scope of origin. */
#define corto_llIter(list) _corto_llIter(list, alloca(sizeof(corto_llIter_s)));
CORTO_EXPORT corto_iter _corto_llIter(corto_ll, void *udata);

/* Obtain persistent iterator. Requries corto_iter_release to be called */
CORTO_EXPORT corto_iter corto_llIterAlloc(corto_ll);

/* Iterator cleanup functions */
CORTO_EXPORT void corto_llIterRelease(corto_iter *iter);

/* Append one list to another */
CORTO_EXPORT void corto_llAppendList(corto_ll l1, corto_ll l2);

/* Insert one list into another */
CORTO_EXPORT void corto_llInsertList(corto_ll l1, corto_ll l2);

/* Reverse list */
CORTO_EXPORT void corto_llReverse(corto_ll list);

/* Clear list */
CORTO_EXPORT void corto_llClear(corto_ll list);

/* Copy list */
CORTO_EXPORT corto_ll corto_llCopy(corto_ll list);

/* Iterator implementation */
CORTO_EXPORT void corto_llIterMoveFirst(corto_iter* iter);
CORTO_EXPORT void *corto_llIterMove(corto_iter* iter, unsigned int index);
CORTO_EXPORT int corto_llIterHasNext(corto_iter* iter);
CORTO_EXPORT void* corto_llIterNext(corto_iter* iter);
CORTO_EXPORT void* corto_llIterNextPtr(corto_iter* iter);
CORTO_EXPORT void* corto_llIterRemove(corto_iter* iter);
CORTO_EXPORT void corto_llIterInsert(corto_iter* iter, void* o);
CORTO_EXPORT void corto_llIterSet(corto_iter* iter, void* o);

/* Functional-style */
typedef void* (*corto_mapAction)(void* elem, void* data);
CORTO_EXPORT corto_ll corto_llMap(corto_ll l, corto_mapAction f, void* data);


#ifdef __cplusplus
}
#endif

#endif
