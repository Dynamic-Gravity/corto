/* cx_struct.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx__interface.h"
#include "cx__class.h"
/* $end */

/* ::cortex::lang::struct::castable(lang::type type) */
cx_bool cx_struct_castable_v(cx_struct _this, cx_type type) {
/* $begin(::cortex::lang::struct::castable) */
    return cx_struct_compatible(_this, type);
/* $end */
}

/* ::cortex::lang::struct::compatible(lang::type type) */
cx_bool cx_struct_compatible_v(cx_struct _this, cx_type type) {
/* $begin(::cortex::lang::struct::compatible) */
    cx_bool result;

    cx_assert(cx_class_instanceof(cx_struct_o, _this), "struct::compatible called on non-struct object.");
    result = FALSE;

    /* Call overloaded type::compatible function first to check for generic compatibility. */
    if (!cx_type_compatible_v(cx_type(_this), type)) {
        /* Type must be at least struct for it to be compatible. */
        if (cx_class_instanceof(cx_struct_o, type)) {
            cx_interface e;

            /* Check if '_this' is superclass of 'type' */
            e = cx_interface(type);
            do {
                e = cx_interface(e)->base;
            }while(e && (e != cx_interface(_this)));
            result = (e == (cx_interface)_this);
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::struct::construct(lang::struct object) */
cx_int16 cx_struct_construct(cx_struct object) {
/* $begin(::cortex::lang::struct::construct) */
    cx_struct base;
    cx_uint16 alignment;
    cx_uint32 size;

    size = 0;

    /* Insert members */
    if (cx__interface_insertMembers(cx_interface(object))) {
        goto error;
    }

    /* Calculate alignment of self */
    alignment = cx__interface_calculateAlignment(cx_interface(object));

    /* Check if struct inherits from another struct */
    base = (cx_struct)cx_interface(object)->base;

    /* Get maximum alignment from self and base-class and copy template parameters */
    if (base) {
        if (!cx_instanceof(cx_typedef(cx_struct_o), base)) {
        	cx_id id, id2;
        	cx_error("struct '%s' inherits from non-struct type '%s'", cx_fullname(object, id), cx_fullname(base, id2));
        	goto error;
        }

        if (cx_type(base)->alignment) {
            if (alignment < cx_type(base)->alignment) {
                alignment = cx_type(base)->alignment;
            }
        }
    }

    /* Set alignment of self */
    cx_type(object)->alignment = alignment;

    /* Get size of base-class */
    if (base) {
        size = cx_type(base)->size;

        if (cx_type(base)->hasResources) {
        	cx_type(object)->hasResources = TRUE;
        }
    }

    /* Calculate size of self */
    size = cx__interface_calculateSize(cx_interface(object), size);

    /* If a class has no members and no base-class, the class will have the size of one word. */
    if (!size) {
        cx_assert(cx_interface(object)->members.length == 0, "struct can't have members and be of size zero.");
        /*size = sizeof(cx_word);*/
    }

    /* Set size of self */
    cx_type(object)->size = size;

    return cx_interface_construct(cx_interface(object));
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::struct::init(lang::struct object) */
cx_int16 cx_struct_init(cx_struct object) {
/* $begin(::cortex::lang::struct::init) */
    /* If not bootstrapping, set baseAccess to GLOBAL | PUBLIC */
    if (cx_checkState(cx_type_o, DB_DEFINED)) {
        object->baseAccess = DB_GLOBAL;
    }

    if (cx_interface_init(cx_interface(object))) {
    	goto error;
    }

    cx_interface(object)->kind = DB_STRUCT;
    cx_type(object)->reference = FALSE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::struct::resolveMember(lang::string name) */
cx_member cx_struct_resolveMember_v(cx_struct _this, cx_string name) {
/* $begin(::cortex::lang::struct::resolveMember) */
    cx_interface base;
    cx_member m;

    m = NULL;
    base = cx_interface(_this);
    do {
        m = cx_interface_resolveMember_v(cx_interface(base), name);
    }while(!m && (base=cx_interface(base)->base));

    return m;
/* $end */
}