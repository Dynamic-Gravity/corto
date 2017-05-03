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

#ifndef CORTO_RBTREE_H_
#define CORTO_RBTREE_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Make this structure public as this will
 * eliminate the need for an allocation when
 * traversing the tree */
#ifndef HEIGHT_LIMIT
#define HEIGHT_LIMIT 24 /* 16M nodes in a single tree */
#endif 
typedef struct jsw_rbtrav jsw_rbtrav_t;
typedef struct jsw_rbtree jsw_rbtree_t;
typedef struct jsw_rbnode jsw_rbnode_t;
struct jsw_rbtrav {
  jsw_rbtree_t *tree;               /* Paired tree */
  jsw_rbnode_t *it;                 /* Current node */
  jsw_rbnode_t *path[HEIGHT_LIMIT]; /* Traversal path */
  size_t        top;                /* Top of stack */
  corto_int32   changes;
};

CORTO_EXPORT corto_rbtree corto_rbtreeNew(corto_type keyType);
CORTO_EXPORT corto_rbtree corto_rbtreeNew_w_func(corto_equals_cb compare);
CORTO_EXPORT void corto_rbtreeFree(corto_rbtree tree);

CORTO_EXPORT void* corto_rbtreeGet(corto_rbtree tree, void* key);
CORTO_EXPORT void* corto_rbtreeGetPtr(corto_rbtree tree, void* key);
CORTO_EXPORT void corto_rbtreeSet(corto_rbtree tree, const void* key, void* value);
CORTO_EXPORT void* corto_rbtreeFindOrSet(corto_rbtree tree, const void* key, void* value);
CORTO_EXPORT void corto_rbtreeRemove(corto_rbtree tree, void* key);
CORTO_EXPORT corto_bool corto_rbtreeHasKey(corto_rbtree tree, const void* key, void** value);
CORTO_EXPORT corto_bool corto_rbtreeHasKey_w_cmp(corto_rbtree tree, const void* key, void** value, corto_equals_cb cmp);
CORTO_EXPORT void* corto_rbtreeMin(corto_rbtree tree, void** key_out);
CORTO_EXPORT void* corto_rbtreeMax(corto_rbtree tree, void** key_out);
CORTO_EXPORT void* corto_rbtreeNext(corto_rbtree tree, void* key, void** key_out);
CORTO_EXPORT void* corto_rbtreePrev(corto_rbtree tree, void* key, void** key_out);
CORTO_EXPORT corto_uint32 corto_rbtreeSize(corto_rbtree tree);
CORTO_EXPORT int corto_rbtreeWalk(corto_rbtree tree, corto_elementWalk_cb callback, void* userData);
CORTO_EXPORT int corto_rbtreeWalkPtr(corto_rbtree tree, corto_elementWalk_cb callback, void* userData);

#define corto_rbtreeIter(tree) _corto_rbtreeIter(tree, alloca(sizeof(struct jsw_rbtrav)));
CORTO_EXPORT corto_iter _corto_rbtreeIter(corto_rbtree tree, void *udata);
CORTO_EXPORT corto_type corto_rbtreeKeyType(corto_rbtree tree);
CORTO_EXPORT corto_bool corto_rbtreeIterChanged(corto_iter *iter);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_RBTREE_H_ */
