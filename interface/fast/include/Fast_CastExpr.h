/* Fast_CastExpr.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_CastExpr_H
#define Fast_CastExpr_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::CastExpr::construct(Fast::CastExpr object) */
db_int16 Fast_CastExpr_construct(Fast_CastExpr object);

/* virtual ::hyve::Fast::CastExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CastExpr_toIc(Fast_CastExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::CastExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CastExpr_toIc_v(Fast_CastExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif
