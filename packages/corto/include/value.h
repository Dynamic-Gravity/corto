/*
 * corto_value.h
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#ifndef CORTO_VALUE_H_
#define CORTO_VALUE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum corto_valueKind {
    CORTO_OBJECT = 0,
    CORTO_BASE = 1, /* serialize inheritance relation */
    CORTO_VALUE = 2,
    CORTO_LITERAL = 3,
    CORTO_MEMBER = 4,
    CORTO_ELEMENT = 5,
    CORTO_MAP_ELEMENT = 6,
    CORTO_CONSTANT = 7 /* must be last */
}corto_valueKind;

typedef enum corto_literalKind {
    CORTO_LITERAL_BOOLEAN,
    CORTO_LITERAL_CHARACTER,
    CORTO_LITERAL_INTEGER,
    CORTO_LITERAL_UNSIGNED_INTEGER,
    CORTO_LITERAL_FLOATING_POINT,
    CORTO_LITERAL_STRING,
    CORTO_LITERAL_NULL
}corto_literalKind;

/* corto_value
 *  Structure that is capable of expressing values in a metadata-organized stack. Used by serializer and as expression result.
 */
typedef struct corto_value corto_value;
struct corto_value {
    corto_value* parent;
    corto_valueKind kind;
    union {
        struct {
            corto_object o;
            corto_type t;
        } object;
        struct {
            corto_object o;
            corto_type t;
            void *v;
        } base;
        struct {
            corto_object o;
            corto_type t;
            void* v;
            corto_uint64 storage; /* Optional storage for a value. */
        } value;
        struct {
            corto_literalKind kind;
            union {
                corto_bool _boolean;
                corto_char _character;
                corto_int64 _integer;
                corto_uint64 _unsigned_integer;
                corto_float64 _floating_point;
                corto_string _string;
            } v;
        } literal;
        struct {
            corto_object o;
            corto_member t;
            void* v;
        } member;
        struct {
            corto_object o;
            corto_constant* t;
            void* v;
        } constant;
        struct {
            corto_object o;
            struct {
                corto_type type;
                uint32_t index;
            } t;
            void* v;
        } element;
        struct {
            corto_object o;
            struct {
                corto_type type;
                corto_type keyType;
                void *key;
            }t;
            void* v;
        } mapElement;
    } is;
};

/* value API */
CORTO_EXPORT corto_type corto_value_typeof(corto_value *val);
CORTO_EXPORT void* corto_value_ptrof(corto_value *val);
CORTO_EXPORT int16_t corto_value_ptrset(corto_value *val, void *ptr);
CORTO_EXPORT corto_object corto_value_objectof(corto_value *val);
CORTO_EXPORT uint32_t corto_value_indexof(corto_value *val);
CORTO_EXPORT int16_t corto_value_memberof(corto_value *val, corto_string member, corto_value *out);

/* value expression API */
CORTO_EXPORT int16_t corto_value_unary(corto_operatorKind _operator, corto_value *value, corto_value *result);
CORTO_EXPORT int16_t corto_value_binary(corto_operatorKind _operator, corto_value *operand1, corto_value *operand2, corto_value *result);
CORTO_EXPORT int16_t _corto_value_cast(corto_value *in, corto_type dstType, corto_value *out);

/* Initializers */
CORTO_EXPORT corto_value corto_value_init(void);
CORTO_EXPORT void corto_value_free(corto_value *v);
CORTO_EXPORT corto_value _corto_value_object(corto_object o, corto_type t);
CORTO_EXPORT corto_value _corto_value_base(void *v, corto_type t);
CORTO_EXPORT corto_value _corto_value_value(void *v, corto_type t);
CORTO_EXPORT corto_value corto_value_member(corto_object o, corto_member t, void *v);
CORTO_EXPORT corto_value corto_value_constant(corto_object o, corto_constant *c, void *v);
CORTO_EXPORT corto_value _corto_value_element(corto_object o, corto_type t, uint32_t index, void *v);
CORTO_EXPORT corto_value corto_value_mapElement(corto_object o, corto_type t, corto_type keyType, void *key, void *v);
CORTO_EXPORT corto_value corto_value_literal(corto_literalKind kind, void *value);
CORTO_EXPORT corto_value corto_value_bool(corto_bool value);
CORTO_EXPORT corto_value corto_value_char(corto_char value);
CORTO_EXPORT corto_value corto_value_uint(corto_uint64 value);
CORTO_EXPORT corto_value corto_value_int(corto_uint64 value);
CORTO_EXPORT corto_value corto_value_float(corto_float64 value);
CORTO_EXPORT corto_value corto_value_string(corto_string value);

/* Helpers */
CORTO_EXPORT char* corto_value_exprStr(corto_value *val, char *buffer, unsigned int length);
int16_t corto_binaryExpr_getType(
    corto_type leftType,
    corto_bool t1ByRef,
    corto_type rightType,
    corto_bool t2ByRef,
    corto_operatorKind _operator,
    corto_type *operandType,
    corto_type *resultType);

CORTO_EXPORT int16_t corto_value_fromcontent(corto_value *v, corto_string contentType, corto_string content);
CORTO_EXPORT corto_string corto_value_contentof(corto_value *v, corto_string contentType);

/* Type safe macro's */
#define corto_value_object(o, t) _corto_value_object(o, corto_type(t))
#define corto_value_base(v, t) _corto_value_base(v, corto_type(t))
#define corto_value_value(v, t) _corto_value_value(v, corto_type(t))
#define corto_value_element(o, t, i, v) _corto_value_element(o, corto_type(t), i, v)
#define corto_value_mapElement(o, t, kt, k, v) _corto_value_mapElement(o, corto_type(t), corto_type(kt), k, v)
#define corto_value_cast(in, dstType, out) _corto_value_cast(in, corto_type(dstType), out)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_VALUE_H_ */
