/* Fast_MemberExpr.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_MemberExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);

db_int16 Fast_MemberExpr_resolveMember(Fast_MemberExpr object, db_type type, db_string member) {
	db_object o = NULL;

	if (db_instanceof(db_typedef(db_interface_o), type) && !strcmp(member, "super")) {
		if (db_interface(type)->base) {
			object->member = NULL;
			Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_interface(type)->base));
		} else {
			db_id id;
			Fast_Parser_error(yparser(), "type '%s' has no base", db_fullname(type, id));
			goto error;
		}
	} else {
		if (db_instanceof(db_typedef(db_interface_o), type)) {
			o = db_interface_resolveMember(db_interface(type), member);
		}
		if (!o) {
			/* If no members are found for name, look for methods */
			o = db_type_resolveProcedure(type, member);
			if (!o) {
				db_id id;
				Fast_Parser_error(yparser(), "unresolved member '%s' for type '%s'", member, db_fullname(type, id));
				goto error;
			}
			Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_function(o)->returnType->real));
		} else {
			Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_member(o)->type->real));
		}
		object->member = o; db_keep_ext(object, o, "Keep object for member-expression");
	}

	Fast_Expression(object)->isReference = Fast_Expression_getType(Fast_Expression(object))->reference;

	return 0;
error:
	return -1;
}

/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object) */
db_int16 Fast_MemberExpr_construct(Fast_MemberExpr object) {
/* $begin(::hyve::Fast::MemberExpr::construct) */
	db_type lvalueType;
	db_type exprType;

	Fast_Node(object)->kind = FAST_Member;
    
    if (!(object->lvalue && object->rvalue)) {
        goto error;
    }

	/* If member-object can be determined at compile-time, resolve it */
	lvalueType = Fast_Expression_getType(object->lvalue);
	if (lvalueType) { /* Type must be a known object at compile-time */
		if (Fast_Node(object->rvalue)->kind == FAST_Literal) { /* Member-expression must be a literal */
			switch(Fast_Literal(object->rvalue)->kind) {
			case FAST_Integer: /* Resolve the nth member of a type */
				Fast_Parser_error(yparser(), "resolving members by index not yet supported");
				goto error;
				break;
			case FAST_String: /* Resolve member by name */
				if (Fast_MemberExpr_resolveMember(object, lvalueType, Fast_String(object->rvalue)->value)) {
					goto error;
				}
				break;
			default:
				Fast_Parser_error(yparser(), "invalid member expression");
				goto error;
				break;
			}
		}
	}

    if ((exprType = Fast_Expression_getType(Fast_Expression(object))) && exprType->reference) {
    	Fast_Expression(object)->forceReference = TRUE;
    }

	return 0;
error:
	return -1;
/* $end */
}

/* virtual ::hyve::Fast::MemberExpr::hasSideEffects() */
db_bool Fast_MemberExpr_hasSideEffects(Fast_MemberExpr _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    db_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::hasSideEffects()'.", db_nameof(_this));
        _result = ((db_bool(*)(Fast_MemberExpr))_method->_parent.impl)(_this);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this);
    }
    
    return _result;
}

/* ::hyve::Fast::MemberExpr::hasSideEffects() */
db_bool Fast_MemberExpr_hasSideEffects_v(Fast_MemberExpr _this) {
/* $begin(::hyve::Fast::MemberExpr::hasSideEffects) */
    return Fast_Expression_hasSideEffects(_this->lvalue);
/* $end */
}

/* virtual ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_MemberExpr_toIc(Fast_MemberExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.", db_nameof(_this));
        _result = ((db_ic(*)(Fast_MemberExpr, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_MemberExpr_toIc_v(Fast_MemberExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::MemberExpr::toIc) */
	db_icMember result;
	db_member member;
	db_ic lvalue;
	DB_UNUSED(stored);
	DB_UNUSED(storage);

	/* Get lvalue & rvalue */
	lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, FALSE);

	if (Fast_Node(_this->rvalue)->kind == FAST_Literal) {
		if (Fast_Literal(_this->rvalue)->kind == FAST_String) {
			db_interface baseType = db_interface(Fast_Expression_getType(_this->lvalue));
			member = db_interface_resolveMember(baseType, Fast_String(_this->rvalue)->value);
		} else {
			Fast_Parser_error(yparser(), "dynamic resolving of members not yet supported.");
			goto error;
		}
	} else {
		Fast_Parser_error(yparser(), "dynamic resolving of members not yet supported.");
		goto error;
	}

	result = db_icMember__create(program, Fast_Node(_this)->line, (db_icStorage)lvalue, member);

	return (db_ic)result;
error:
	return NULL;
/* $end */
}