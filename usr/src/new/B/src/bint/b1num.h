begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b1num.h,v 1.4 85/08/22 16:41:53 timo Exp $ */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Full numeric package: private definitions                            */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A number is modelled as one of zero, unbounded integer,              */
end_comment

begin_comment
comment|/*        unbounded rational or approximate.                            */
end_comment

begin_comment
comment|/*     Zero has a 'length' field of zero, and nothing else.             */
end_comment

begin_comment
comment|/*     A length field of +n means the number is an n digit integer,     */
end_comment

begin_comment
comment|/*        (with digits to some large base).                             */
end_comment

begin_comment
comment|/*     A length of -1 means there follow two floating point numbers,    */
end_comment

begin_comment
comment|/*        one the fraction (zero or .5<= frac<= 1), one the exponent  */
end_comment

begin_comment
comment|/*        with respect to base 2 (should be an integral value).         */
end_comment

begin_comment
comment|/*        (This is so when EXT_RANGE is defined.  Otherwise, there is   */
end_comment

begin_comment
comment|/*        only one field, frac, which is not normalized.  This saves    */
end_comment

begin_comment
comment|/*        code and data space on e.g. the IBM PC, where the natural     */
end_comment

begin_comment
comment|/*        range of double's is sufficient (~1E307).)                    */
end_comment

begin_comment
comment|/*     A length of -2 means there follow two values, pointers to two    */
end_comment

begin_comment
comment|/*        unbounded integers, ie a rational number.                     */
end_comment

begin_comment
comment|/*     A length of -n, n>2, means it is a rational with a print width   */
end_comment

begin_comment
comment|/*        of n-2.                                                       */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*************** Definitions exported for integers *****************/
end_comment

begin_typedef
typedef|typedef
name|int
name|digit
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|integer
block|{
name|HEADER
expr_stmt|;
name|digit
name|dig
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|integer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FreezeSmallInt
parameter_list|(
name|v
parameter_list|,
name|vv
parameter_list|)
define|\
value|(IsSmallInt(v)&& (Freeze1(v, vv), Freeze2(v, vv)))
end_define

begin_define
define|#
directive|define
name|Freeze1
parameter_list|(
name|v
parameter_list|,
name|vv
parameter_list|)
value|((vv).type= Num, (vv).refcnt= Maxrefcnt)
end_define

begin_define
define|#
directive|define
name|Freeze2
parameter_list|(
name|v
parameter_list|,
name|vv
parameter_list|)
define|\
value|((vv).len= (v) != 0, (vv).dig[0]= SmallIntVal(v), (v)=&(vv))
end_define

begin_function_decl
name|integer
name|int_gadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int_canon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int_prod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int_quot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int_gcd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|mk_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int1mul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int_tento
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int_half
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|integer
name|int_mod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|digit
name|int_ldiv
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|int_0
value|((integer) MkSmallInt(0))
end_define

begin_define
define|#
directive|define
name|int_1
value|((integer) MkSmallInt(1))
end_define

begin_define
define|#
directive|define
name|int_2
value|((integer) MkSmallInt(2))
end_define

begin_define
define|#
directive|define
name|int_10
value|((integer) MkSmallInt(10))
end_define

begin_define
define|#
directive|define
name|int_sum
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
value|int_gadd(v, w, 1)
end_define

begin_define
define|#
directive|define
name|int_diff
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
value|int_gadd(v, w, -1)
end_define

begin_define
define|#
directive|define
name|int_neg
parameter_list|(
name|v
parameter_list|)
value|int_gadd(int_0, v, -1)
end_define

begin_define
define|#
directive|define
name|Integral
parameter_list|(
name|v
parameter_list|)
value|(IsSmallInt(v) || Length(v)>=0)
end_define

begin_define
define|#
directive|define
name|Modulo
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)%(b)+(b))%(b))
end_define

begin_define
define|#
directive|define
name|Digit
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((v)->dig[n])
end_define

begin_define
define|#
directive|define
name|Msd
parameter_list|(
name|v
parameter_list|)
value|(IsSmallInt(v) ? SmallIntVal(v) : Digit(v,Length(v)-1))
end_define

begin_define
define|#
directive|define
name|Lsd
parameter_list|(
name|v
parameter_list|)
value|(IsSmallInt(v) ? SmallIntVal(v) : Digit(v,0))
end_define

begin_define
define|#
directive|define
name|Odd
parameter_list|(
name|x
parameter_list|)
value|((x)&1)
end_define

begin_define
define|#
directive|define
name|Even
parameter_list|(
name|x
parameter_list|)
value|(!Odd(x))
end_define

begin_comment
comment|/* Provisional definitions */
end_comment

begin_function_decl
name|value
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Copy
parameter_list|(
name|x
parameter_list|)
value|copy((value)(x))
end_define

begin_comment
comment|/***************** Definitions exported for rationals *****************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|HEADER
expr_stmt|;
name|integer
name|num
decl_stmt|,
name|den
decl_stmt|;
block|}
typedef|*
name|rational
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Numerator
parameter_list|(
name|a
parameter_list|)
value|((a)->num)
end_define

begin_define
define|#
directive|define
name|Denominator
parameter_list|(
name|a
parameter_list|)
value|((a)->den)
end_define

begin_define
define|#
directive|define
name|Rational
parameter_list|(
name|a
parameter_list|)
value|(!IsSmallInt(a)&& Length(a)<-1)
end_define

begin_define
define|#
directive|define
name|Roundsize
parameter_list|(
name|a
parameter_list|)
value|(-2-Length(a))
end_define

begin_function_decl
name|rational
name|mk_rat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rational
name|rat_sum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rational
name|rat_diff
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rational
name|rat_neg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rational
name|rat_prod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rational
name|rat_quot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rational
name|rat_power
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|rational
name|rat_zero
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rational
name|rat_half
decl_stmt|;
end_decl_stmt

begin_function_decl
name|value
name|tento
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_exact
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/***************** Definitions exported for approximate numbers *************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|EXT_RANGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|real
block|{
name|HEADER
expr_stmt|;
name|double
name|frac
decl_stmt|;
ifdef|#
directive|ifdef
name|EXT_RANGE
name|double
name|expo
decl_stmt|;
endif|#
directive|endif
endif|EXT_RANGE
block|}
typedef|*
name|real
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Frac
parameter_list|(
name|v
parameter_list|)
value|((v)->frac)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EXT_RANGE
end_ifdef

begin_define
define|#
directive|define
name|Expo
parameter_list|(
name|v
parameter_list|)
value|((v)->expo)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Expo
parameter_list|(
name|v
parameter_list|)
value|0.0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Approximate
parameter_list|(
name|v
parameter_list|)
value|(!IsSmallInt(v)&& Length(v)==-1)
end_define

begin_define
define|#
directive|define
name|Exact
parameter_list|(
name|v
parameter_list|)
value|(!Approximate(v))
end_define

begin_decl_stmt
specifier|extern
name|real
name|app_0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|real
name|mk_approx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_sum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_diff
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_prod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_quot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_neg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_exp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_log
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|real
name|app_power
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|app_floor
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Numeric constants. */
end_comment

begin_comment
comment|/* (Source: Knuth, The Art of Computer Programming, Vol. 1, Appendix B-1.) */
end_comment

begin_define
define|#
directive|define
name|logtwo
value|0.6931471805599453094172321214581765680755
end_define

begin_define
define|#
directive|define
name|invlogtwo
value|1.4426950408889634073599246810018921374266
end_define

begin_define
define|#
directive|define
name|logten
value|2.3025850929940456840179914546843642076011
end_define

begin_define
define|#
directive|define
name|logBASE
value|(logten*tenlogBASE)
end_define

begin_define
define|#
directive|define
name|twologBASE
value|(logBASE*invlogtwo)
end_define

end_unit

