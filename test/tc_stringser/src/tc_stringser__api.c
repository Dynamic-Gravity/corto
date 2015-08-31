/* tc_stringser__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_stringser__meta.h"
#include "tc_stringser__api.h"

tc_stringser_classCompositeCollection tc_stringser_classCompositeCollection__new(void) {
    return cx_declare(cx_type(tc_stringser_classCompositeCollection_o));
}

tc_stringser_classCompositeCollection tc_stringser_classCompositeCollectionDeclare(cx_object _parent, cx_string _name) {
    return cx_declareChild(_parent, _name, cx_type(tc_stringser_classCompositeCollection_o));
}

int tc_stringser_classCompositeCollectionDefine(tc_stringser_classCompositeCollection _this, tc_stringser_arrayOfClassInherit a, tc_stringser_arrayOfClassNested b, tc_stringser_sequenceOfClassInherit c, tc_stringser_listOfClassNested d, tc_stringser_listOfClassInherit e) {
    memcpy(_this->a, a, sizeof(tc_stringser_arrayOfClassInherit));
    memcpy(_this->b, b, sizeof(tc_stringser_arrayOfClassNested));
    _this->c = c;
    _this->d = d;
    _this->e = e;
    return cx_define(_this);
}

tc_stringser_classCompositeCollection tc_stringser_classCompositeCollectionCreate(tc_stringser_arrayOfClassInherit a, tc_stringser_arrayOfClassNested b, tc_stringser_sequenceOfClassInherit c, tc_stringser_listOfClassNested d, tc_stringser_listOfClassInherit e) {
    tc_stringser_classCompositeCollection _this;
    _this = cx_declare(cx_type(tc_stringser_classCompositeCollection_o));
    memcpy(_this->a, a, sizeof(tc_stringser_arrayOfClassInherit));
    memcpy(_this->b, b, sizeof(tc_stringser_arrayOfClassNested));
    _this->c = c;
    _this->d = d;
    _this->e = e;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

tc_stringser_classInherit tc_stringser_classInherit__new(void) {
    return cx_declare(cx_type(tc_stringser_classInherit_o));
}

tc_stringser_classInherit tc_stringser_classInheritDeclare(cx_object _parent, cx_string _name) {
    return cx_declareChild(_parent, _name, cx_type(tc_stringser_classInherit_o));
}

int tc_stringser_classInheritDefine(tc_stringser_classInherit _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_stringser_color f_1, tc_stringser_moveMode g_1) {
    tc_stringser_classPrimitives(_this)->a = a;
    tc_stringser_classPrimitives(_this)->b = b;
    tc_stringser_classPrimitives(_this)->c = c;
    tc_stringser_classPrimitives(_this)->d = d;
    tc_stringser_classPrimitives(_this)->e = (e ? cx_strdup(e) : NULL);
    tc_stringser_classPrimitives(_this)->f = f;
    tc_stringser_classPrimitives(_this)->g = g;
    _this->a = a_1;
    _this->b = b_1;
    _this->c = c_1;
    _this->d = d_1;
    _this->e = (e_1 ? cx_strdup(e_1) : NULL);
    _this->f = f_1;
    _this->g = g_1;
    return cx_define(_this);
}

tc_stringser_classInherit tc_stringser_classInheritCreate(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g, cx_bool a_1, cx_char b_1, cx_int32 c_1, cx_float32 d_1, cx_string e_1, tc_stringser_color f_1, tc_stringser_moveMode g_1) {
    tc_stringser_classInherit _this;
    _this = cx_declare(cx_type(tc_stringser_classInherit_o));
    tc_stringser_classPrimitives(_this)->a = a;
    tc_stringser_classPrimitives(_this)->b = b;
    tc_stringser_classPrimitives(_this)->c = c;
    tc_stringser_classPrimitives(_this)->d = d;
    tc_stringser_classPrimitives(_this)->e = (e ? cx_strdup(e) : NULL);
    tc_stringser_classPrimitives(_this)->f = f;
    tc_stringser_classPrimitives(_this)->g = g;
    _this->a = a_1;
    _this->b = b_1;
    _this->c = c_1;
    _this->d = d_1;
    _this->e = (e_1 ? cx_strdup(e_1) : NULL);
    _this->f = f_1;
    _this->g = g_1;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

tc_stringser_classNested tc_stringser_classNested__new(void) {
    return cx_declare(cx_type(tc_stringser_classNested_o));
}

tc_stringser_classNested tc_stringser_classNestedDeclare(cx_object _parent, cx_string _name) {
    return cx_declareChild(_parent, _name, cx_type(tc_stringser_classNested_o));
}

int tc_stringser_classNestedDefine(tc_stringser_classNested _this, tc_stringser_classPrimitives a, tc_stringser_classInherit b, tc_stringser_arrayOfInt c, tc_stringser_sequenceOfInt d, tc_stringser_listOfInt e) {
    a ? cx_claim(a, "element <0x8a24418>.a") : 0; _this->a = a;
    b ? cx_claim(b, "element <0x8a24418>.b") : 0; _this->b = b;
    memcpy(_this->c, c, sizeof(tc_stringser_arrayOfInt));
    _this->d = d;
    _this->e = e;
    return cx_define(_this);
}

tc_stringser_classNested tc_stringser_classNestedCreate(tc_stringser_classPrimitives a, tc_stringser_classInherit b, tc_stringser_arrayOfInt c, tc_stringser_sequenceOfInt d, tc_stringser_listOfInt e) {
    tc_stringser_classNested _this;
    _this = cx_declare(cx_type(tc_stringser_classNested_o));
    a ? cx_claim(a, "element <0x8a24418>.a") : 0; _this->a = a;
    b ? cx_claim(b, "element <0x8a24418>.b") : 0; _this->b = b;
    memcpy(_this->c, c, sizeof(tc_stringser_arrayOfInt));
    _this->d = d;
    _this->e = e;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

tc_stringser_classPrimitives tc_stringser_classPrimitives__new(void) {
    return cx_declare(cx_type(tc_stringser_classPrimitives_o));
}

tc_stringser_classPrimitives tc_stringser_classPrimitivesDeclare(cx_object _parent, cx_string _name) {
    return cx_declareChild(_parent, _name, cx_type(tc_stringser_classPrimitives_o));
}

int tc_stringser_classPrimitivesDefine(tc_stringser_classPrimitives _this, cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g) {
    _this->a = a;
    _this->b = b;
    _this->c = c;
    _this->d = d;
    _this->e = (e ? cx_strdup(e) : NULL);
    _this->f = f;
    _this->g = g;
    return cx_define(_this);
}

tc_stringser_classPrimitives tc_stringser_classPrimitivesCreate(cx_bool a, cx_char b, cx_int32 c, cx_float32 d, cx_string e, tc_stringser_color f, tc_stringser_moveMode g) {
    tc_stringser_classPrimitives _this;
    _this = cx_declare(cx_type(tc_stringser_classPrimitives_o));
    _this->a = a;
    _this->b = b;
    _this->c = c;
    _this->d = d;
    _this->e = (e ? cx_strdup(e) : NULL);
    _this->f = f;
    _this->g = g;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

void tc_stringser_listOfClassInheritInsert(tc_stringser_listOfClassInherit list, tc_stringser_classInherit element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfClassInheritAppend(tc_stringser_listOfClassInherit list, tc_stringser_classInherit element) {
    cx_llAppend(list, (void*)element);
}

tc_stringser_classInherit tc_stringser_listOfClassInherit__takeFirst(tc_stringser_listOfClassInherit list) {
    return (tc_stringser_classInherit)cx_llTakeFirst(list);
}

tc_stringser_classInherit tc_stringser_listOfClassInherit__last(tc_stringser_listOfClassInherit list) {
    return (tc_stringser_classInherit)cx_llLast(list);
}

void tc_stringser_listOfClassInherit__clear(tc_stringser_listOfClassInherit list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        cx_release(element);
    }
}

tc_stringser_classInherit tc_stringser_listOfClassInherit__get(tc_stringser_listOfClassInherit list, cx_uint32 index) {
    return (tc_stringser_classInherit)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfClassInheritSize(tc_stringser_listOfClassInherit list) {
    return cx_llSize(list);
}

tc_stringser_classInherit tc_stringser_sequenceOfClassInheritAppend(tc_stringser_sequenceOfClassInherit *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(tc_stringser_classInherit_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfClassInheritSize(tc_stringser_sequenceOfClassInherit *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(tc_stringser_classInherit_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(tc_stringser_classInherit_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void tc_stringser_sequenceOfClassInherit__clear(tc_stringser_sequenceOfClassInherit *seq) {
    tc_stringser_sequenceOfClassInheritSize(seq, 0);
}

void tc_stringser_listOfClassNestedInsert(tc_stringser_listOfClassNested list, tc_stringser_classNested element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfClassNestedAppend(tc_stringser_listOfClassNested list, tc_stringser_classNested element) {
    cx_llAppend(list, (void*)element);
}

tc_stringser_classNested tc_stringser_listOfClassNested__takeFirst(tc_stringser_listOfClassNested list) {
    return (tc_stringser_classNested)cx_llTakeFirst(list);
}

tc_stringser_classNested tc_stringser_listOfClassNested__last(tc_stringser_listOfClassNested list) {
    return (tc_stringser_classNested)cx_llLast(list);
}

void tc_stringser_listOfClassNested__clear(tc_stringser_listOfClassNested list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        cx_release(element);
    }
}

tc_stringser_classNested tc_stringser_listOfClassNested__get(tc_stringser_listOfClassNested list, cx_uint32 index) {
    return (tc_stringser_classNested)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfClassNestedSize(tc_stringser_listOfClassNested list) {
    return cx_llSize(list);
}

tc_stringser_classNested tc_stringser_sequenceOfClassNestedAppend(tc_stringser_sequenceOfClassNested *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(tc_stringser_classNested_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfClassNestedSize(tc_stringser_sequenceOfClassNested *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(tc_stringser_classNested_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(tc_stringser_classNested_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void tc_stringser_sequenceOfClassNested__clear(tc_stringser_sequenceOfClassNested *seq) {
    tc_stringser_sequenceOfClassNestedSize(seq, 0);
}

void tc_stringser_listOfClassPrimitivesInsert(tc_stringser_listOfClassPrimitives list, tc_stringser_classPrimitives element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfClassPrimitivesAppend(tc_stringser_listOfClassPrimitives list, tc_stringser_classPrimitives element) {
    cx_llAppend(list, (void*)element);
}

tc_stringser_classPrimitives tc_stringser_listOfClassPrimitives__takeFirst(tc_stringser_listOfClassPrimitives list) {
    return (tc_stringser_classPrimitives)cx_llTakeFirst(list);
}

tc_stringser_classPrimitives tc_stringser_listOfClassPrimitives__last(tc_stringser_listOfClassPrimitives list) {
    return (tc_stringser_classPrimitives)cx_llLast(list);
}

void tc_stringser_listOfClassPrimitives__clear(tc_stringser_listOfClassPrimitives list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        cx_release(element);
    }
}

tc_stringser_classPrimitives tc_stringser_listOfClassPrimitives__get(tc_stringser_listOfClassPrimitives list, cx_uint32 index) {
    return (tc_stringser_classPrimitives)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfClassPrimitivesSize(tc_stringser_listOfClassPrimitives list) {
    return cx_llSize(list);
}

tc_stringser_classPrimitives tc_stringser_sequenceOfClassPrimitivesAppend(tc_stringser_sequenceOfClassPrimitives *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(tc_stringser_classPrimitives_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfClassPrimitivesSize(tc_stringser_sequenceOfClassPrimitives *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(tc_stringser_classPrimitives_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(tc_stringser_classPrimitives_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void tc_stringser_sequenceOfClassPrimitives__clear(tc_stringser_sequenceOfClassPrimitives *seq) {
    tc_stringser_sequenceOfClassPrimitivesSize(seq, 0);
}

void tc_stringser_listOfColorInsert(tc_stringser_listOfColor list, tc_stringser_color element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfColorAppend(tc_stringser_listOfColor list, tc_stringser_color element) {
    cx_llAppend(list, (void*)element);
}

tc_stringser_color tc_stringser_listOfColor__takeFirst(tc_stringser_listOfColor list) {
    return (tc_stringser_color)cx_llTakeFirst(list);
}

tc_stringser_color tc_stringser_listOfColor__last(tc_stringser_listOfColor list) {
    return (tc_stringser_color)cx_llLast(list);
}

void tc_stringser_listOfColor__clear(tc_stringser_listOfColor list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

tc_stringser_color tc_stringser_listOfColor__get(tc_stringser_listOfColor list, cx_uint32 index) {
    return (tc_stringser_color)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfColorSize(tc_stringser_listOfColor list) {
    return cx_llSize(list);
}

tc_stringser_color* tc_stringser_sequenceOfColorAppend(tc_stringser_sequenceOfColor *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(tc_stringser_color_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfColorSize(tc_stringser_sequenceOfColor *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(tc_stringser_color_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void tc_stringser_sequenceOfColor__clear(tc_stringser_sequenceOfColor *seq) {
    tc_stringser_sequenceOfColorSize(seq, 0);
}

void tc_stringser_listOfBoolInsert(tc_stringser_listOfBool list, cx_bool element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfBoolAppend(tc_stringser_listOfBool list, cx_bool element) {
    cx_llAppend(list, (void*)element);
}

cx_bool tc_stringser_listOfBool__takeFirst(tc_stringser_listOfBool list) {
    return (cx_bool)cx_llTakeFirst(list);
}

cx_bool tc_stringser_listOfBool__last(tc_stringser_listOfBool list) {
    return (cx_bool)cx_llLast(list);
}

void tc_stringser_listOfBool__clear(tc_stringser_listOfBool list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_bool tc_stringser_listOfBool__get(tc_stringser_listOfBool list, cx_uint32 index) {
    return (cx_bool)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfBoolSize(tc_stringser_listOfBool list) {
    return cx_llSize(list);
}

void tc_stringser_listOfCharInsert(tc_stringser_listOfChar list, cx_char element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfCharAppend(tc_stringser_listOfChar list, cx_char element) {
    cx_llAppend(list, (void*)element);
}

cx_char tc_stringser_listOfChar__takeFirst(tc_stringser_listOfChar list) {
    return (cx_char)cx_llTakeFirst(list);
}

cx_char tc_stringser_listOfChar__last(tc_stringser_listOfChar list) {
    return (cx_char)cx_llLast(list);
}

void tc_stringser_listOfChar__clear(tc_stringser_listOfChar list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_char tc_stringser_listOfChar__get(tc_stringser_listOfChar list, cx_uint32 index) {
    return (cx_char)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfCharSize(tc_stringser_listOfChar list) {
    return cx_llSize(list);
}

void tc_stringser_listOfFloatInsert(tc_stringser_listOfFloat list, cx_float32 element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfFloatAppend(tc_stringser_listOfFloat list, cx_float32 element) {
    cx_llAppend(list, (void*)element);
}

cx_float32 tc_stringser_listOfFloat__takeFirst(tc_stringser_listOfFloat list) {
    return (cx_float32)cx_llTakeFirst(list);
}

cx_float32 tc_stringser_listOfFloat__last(tc_stringser_listOfFloat list) {
    return (cx_float32)cx_llLast(list);
}

void tc_stringser_listOfFloat__clear(tc_stringser_listOfFloat list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_float32 tc_stringser_listOfFloat__get(tc_stringser_listOfFloat list, cx_uint32 index) {
    return (cx_float32)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfFloatSize(tc_stringser_listOfFloat list) {
    return cx_llSize(list);
}

void tc_stringser_listOfIntInsert(tc_stringser_listOfInt list, cx_int32 element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfIntAppend(tc_stringser_listOfInt list, cx_int32 element) {
    cx_llAppend(list, (void*)element);
}

cx_int32 tc_stringser_listOfInt__takeFirst(tc_stringser_listOfInt list) {
    return (cx_int32)cx_llTakeFirst(list);
}

cx_int32 tc_stringser_listOfInt__last(tc_stringser_listOfInt list) {
    return (cx_int32)cx_llLast(list);
}

void tc_stringser_listOfInt__clear(tc_stringser_listOfInt list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_int32 tc_stringser_listOfInt__get(tc_stringser_listOfInt list, cx_uint32 index) {
    return (cx_int32)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfIntSize(tc_stringser_listOfInt list) {
    return cx_llSize(list);
}

void tc_stringser_listOfMoveModeInsert(tc_stringser_listOfMoveMode list, tc_stringser_moveMode element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfMoveModeAppend(tc_stringser_listOfMoveMode list, tc_stringser_moveMode element) {
    cx_llAppend(list, (void*)element);
}

tc_stringser_moveMode tc_stringser_listOfMoveMode__takeFirst(tc_stringser_listOfMoveMode list) {
    return (tc_stringser_moveMode)cx_llTakeFirst(list);
}

tc_stringser_moveMode tc_stringser_listOfMoveMode__last(tc_stringser_listOfMoveMode list) {
    return (tc_stringser_moveMode)cx_llLast(list);
}

void tc_stringser_listOfMoveMode__clear(tc_stringser_listOfMoveMode list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

tc_stringser_moveMode tc_stringser_listOfMoveMode__get(tc_stringser_listOfMoveMode list, cx_uint32 index) {
    return (tc_stringser_moveMode)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfMoveModeSize(tc_stringser_listOfMoveMode list) {
    return cx_llSize(list);
}

void tc_stringser_listOfStringInsert(tc_stringser_listOfString list, cx_string element) {
    cx_llInsert(list, (void*)element);
}

void tc_stringser_listOfStringAppend(tc_stringser_listOfString list, cx_string element) {
    cx_llAppend(list, (void*)element);
}

cx_string tc_stringser_listOfString__takeFirst(tc_stringser_listOfString list) {
    return (cx_string)cx_llTakeFirst(list);
}

cx_string tc_stringser_listOfString__last(tc_stringser_listOfString list) {
    return (cx_string)cx_llLast(list);
}

void tc_stringser_listOfString__clear(tc_stringser_listOfString list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_string tc_stringser_listOfString__get(tc_stringser_listOfString list, cx_uint32 index) {
    return (cx_string)cx_llGet(list, index);
}

cx_uint32 tc_stringser_listOfStringSize(tc_stringser_listOfString list) {
    return cx_llSize(list);
}

tc_stringser_moveMode* tc_stringser_sequenceOfMoveModeAppend(tc_stringser_sequenceOfMoveMode *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(tc_stringser_moveMode_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfMoveModeSize(tc_stringser_sequenceOfMoveMode *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(tc_stringser_moveMode_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void tc_stringser_sequenceOfMoveMode__clear(tc_stringser_sequenceOfMoveMode *seq) {
    tc_stringser_sequenceOfMoveModeSize(seq, 0);
}

cx_bool* tc_stringser_sequenceOfBoolAppend(tc_stringser_sequenceOfBool *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_bool_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfBoolSize(tc_stringser_sequenceOfBool *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_bool_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void tc_stringser_sequenceOfBool__clear(tc_stringser_sequenceOfBool *seq) {
    tc_stringser_sequenceOfBoolSize(seq, 0);
}

cx_char* tc_stringser_sequenceOfCharAppend(tc_stringser_sequenceOfChar *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_char_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfCharSize(tc_stringser_sequenceOfChar *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_char_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void tc_stringser_sequenceOfChar__clear(tc_stringser_sequenceOfChar *seq) {
    tc_stringser_sequenceOfCharSize(seq, 0);
}

cx_float32* tc_stringser_sequenceOfFloatAppend(tc_stringser_sequenceOfFloat *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_float32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfFloatSize(tc_stringser_sequenceOfFloat *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_float32_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void tc_stringser_sequenceOfFloat__clear(tc_stringser_sequenceOfFloat *seq) {
    tc_stringser_sequenceOfFloatSize(seq, 0);
}

cx_int32* tc_stringser_sequenceOfIntAppend(tc_stringser_sequenceOfInt *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfIntSize(tc_stringser_sequenceOfInt *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_int32_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void tc_stringser_sequenceOfInt__clear(tc_stringser_sequenceOfInt *seq) {
    tc_stringser_sequenceOfIntSize(seq, 0);
}

cx_string* tc_stringser_sequenceOfStringAppend(tc_stringser_sequenceOfString *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void tc_stringser_sequenceOfStringSize(tc_stringser_sequenceOfString *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_string_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void tc_stringser_sequenceOfString__clear(tc_stringser_sequenceOfString *seq) {
    tc_stringser_sequenceOfStringSize(seq, 0);
}

