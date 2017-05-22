/* native.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_NATIVE__API_H
#define CORTO_NATIVE__API_H

#include <corto/corto.h>
#include <corto/_project.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/native/type */
CORTO_EXPORT corto_native_type _corto_native_typeCreate(corto_string name);
#define corto_native_typeCreate(name) _corto_native_typeCreate(name)
#define corto_native_typeCreate_auto(_id, name) corto_native_type _id = corto_native_typeCreate(name); (void)_id
CORTO_EXPORT corto_native_type _corto_native_typeCreateChild(corto_object _parent, corto_string _id, corto_string name);
#define corto_native_typeCreateChild(_parent, _id, name) _corto_native_typeCreateChild(_parent, _id, name)
#define corto_native_typeCreateChild_auto(_parent, _id, name) corto_native_type _id = corto_native_typeCreateChild(_parent, #_id, name); (void)_id
CORTO_EXPORT corto_int16 _corto_native_typeUpdate(corto_native_type _this, corto_string name);
#define corto_native_typeUpdate(_this, name) _corto_native_typeUpdate(corto_native_type(_this), name)
CORTO_EXPORT corto_native_type _corto_native_typeAssign(corto_native_type _this, corto_string name);
#define corto_native_type__optional_NotSet NULL
#define corto_native_type__optional_Set(name) corto_native_typeAssign((corto_native_type*)corto_ptr_new(corto_native_type_o)), name)
#define corto_native_type__optional_SetCond(cond, name) cond ? corto_native_typeAssign((corto_native_type*)corto_ptr_new(corto_native_type_o), name) : NULL
#define corto_native_typeUnset(_this) _this ? corto_ptr_free(_this, corto_native_type_o), 0 : 0; _this = NULL;
#define corto_native_typeAssign(_this, name) _corto_native_typeAssign(_this, name)
#define corto_native_typeSet(_this, name) _this = _this ? _this : (corto_native_type*)corto_ptr_new(corto_native_type_o); _corto_native_typeAssign(_this, name)

CORTO_EXPORT corto_native_type _corto_native_typeDeclare(void);
#define corto_native_typeDeclare() _corto_native_typeDeclare()
#define corto_native_typeDeclare_auto(_id) corto_native_type _id = corto_native_typeDeclare(); (void)_id
CORTO_EXPORT corto_native_type _corto_native_typeDeclareChild(corto_object _parent, corto_string _id);
#define corto_native_typeDeclareChild(_parent, _id) _corto_native_typeDeclareChild(_parent, _id)
#define corto_native_typeDeclareChild_auto(_parent, _id) corto_native_type _id = corto_native_typeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_native_typeDefine(corto_native_type _this, corto_string name);
#define corto_native_typeDefine(_this, name) _corto_native_typeDefine(corto_native_type(_this), name)


#ifdef __cplusplus
}
#endif
#endif


/* int32seq */
CORTO_EXPORT int32_t* corto_int32seqAppend(corto_int32seq *seq, int32_t element);
CORTO_EXPORT int32_t* corto_int32seqAppendAlloc(corto_int32seq *seq);
CORTO_EXPORT void corto_int32seqSize(corto_int32seq *seq, corto_uint32 length);
CORTO_EXPORT void corto_int32seqClear(corto_int32seq *seq);

/* interfaceseq */
CORTO_EXPORT corto_interface* corto_interfaceseqAppend(corto_interfaceseq *seq, corto_interface element);
CORTO_EXPORT corto_interface* corto_interfaceseqAppendAlloc(corto_interfaceseq *seq);
CORTO_EXPORT void corto_interfaceseqSize(corto_interfaceseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_interfaceseqClear(corto_interfaceseq *seq);

/* interfaceVectorseq */
CORTO_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppend(corto_interfaceVectorseq *seq, corto_interfaceVector element);
CORTO_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppendAlloc(corto_interfaceVectorseq *seq);
CORTO_EXPORT void corto_interfaceVectorseqSize(corto_interfaceVectorseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_interfaceVectorseqClear(corto_interfaceVectorseq *seq);

/* objectlist */
CORTO_EXPORT void corto_objectlistInsert(corto_objectlist list, corto_object element);
CORTO_EXPORT void corto_objectlistAppend(corto_objectlist list, corto_object element);
CORTO_EXPORT void corto_objectlistRemove(corto_objectlist list, corto_object element);
CORTO_EXPORT corto_object corto_objectlistTakeFirst(corto_objectlist list);
CORTO_EXPORT corto_object corto_objectlistLast(corto_objectlist list);
CORTO_EXPORT corto_object corto_objectlistGet(corto_objectlist list, corto_uint32 index);
CORTO_EXPORT corto_uint32 corto_objectlistSize(corto_objectlist list);
CORTO_EXPORT void corto_objectlistClear(corto_objectlist list);

/* objectseq */
CORTO_EXPORT corto_object* corto_objectseqAppend(corto_objectseq *seq, corto_object element);
CORTO_EXPORT corto_object* corto_objectseqAppendAlloc(corto_objectseq *seq);
CORTO_EXPORT void corto_objectseqSize(corto_objectseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_objectseqClear(corto_objectseq *seq);

/* parameterseq */
CORTO_EXPORT corto_parameter* corto_parameterseqAppend(corto_parameterseq *seq, corto_parameter element);
CORTO_EXPORT corto_parameter* corto_parameterseqAppendAlloc(corto_parameterseq *seq);
CORTO_EXPORT void corto_parameterseqSize(corto_parameterseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_parameterseqClear(corto_parameterseq *seq);

/* stringlist */
CORTO_EXPORT void corto_stringlistInsert(corto_stringlist list, corto_string element);
CORTO_EXPORT void corto_stringlistAppend(corto_stringlist list, corto_string element);
CORTO_EXPORT corto_string corto_stringlistTakeFirst(corto_stringlist list);
CORTO_EXPORT corto_string corto_stringlistLast(corto_stringlist list);
CORTO_EXPORT corto_string corto_stringlistGet(corto_stringlist list, corto_uint32 index);
CORTO_EXPORT corto_uint32 corto_stringlistSize(corto_stringlist list);
CORTO_EXPORT void corto_stringlistClear(corto_stringlist list);

/* stringseq */
CORTO_EXPORT corto_string* corto_stringseqAppend(corto_stringseq *seq, corto_string element);
CORTO_EXPORT corto_string* corto_stringseqAppendAlloc(corto_stringseq *seq);
CORTO_EXPORT void corto_stringseqSize(corto_stringseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_stringseqClear(corto_stringseq *seq);

/* wordseq */
CORTO_EXPORT uintptr_t* corto_wordseqAppend(corto_wordseq *seq, uintptr_t element);
CORTO_EXPORT uintptr_t* corto_wordseqAppendAlloc(corto_wordseq *seq);
CORTO_EXPORT void corto_wordseqSize(corto_wordseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_wordseqClear(corto_wordseq *seq);

/* /corto/core/mountSubscriptionList */
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListInsertAlloc(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListInsert(corto_mountSubscriptionList list, corto_mountSubscription* element);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListAppendAlloc(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListAppend(corto_mountSubscriptionList list, corto_mountSubscription* element);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListTakeFirst(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListLast(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListGet(corto_mountSubscriptionList list, corto_uint32 index);
CORTO_EXPORT corto_uint32 corto_mountSubscriptionListSize(corto_mountSubscriptionList list);
CORTO_EXPORT void corto_mountSubscriptionListClear(corto_mountSubscriptionList list);

/* /corto/core/resultList */
CORTO_EXPORT corto_result* corto_resultListInsertAlloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListInsert(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultListAppendAlloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListAppend(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultListTakeFirst(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListLast(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index);
CORTO_EXPORT corto_uint32 corto_resultListSize(corto_resultList list);
CORTO_EXPORT void corto_resultListClear(corto_resultList list);
#define corto_objectIterForeach(iter, elem) \
    corto_object elem;\
    while(corto_iter_hasNext(&iter) ? elem = (corto_object)corto_iter_next(&iter), TRUE : FALSE)

#define corto_resultIterForeach(iter, elem) \
    corto_result elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_result*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)

#define corto_sampleIterForeach(iter, elem) \
    corto_sample elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_sample*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)
