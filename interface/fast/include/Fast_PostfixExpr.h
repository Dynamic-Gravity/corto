/* Fast_PostfixExpr.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_PostfixExpr_H
#define Fast_PostfixExpr_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
db_int16 Fast_PostfixExpr_construct(Fast_PostfixExpr object);

/* virtual ::hyve::Fast::PostfixExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_PostfixExpr_toIc(Fast_PostfixExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::PostfixExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_PostfixExpr_toIc_v(Fast_PostfixExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif
