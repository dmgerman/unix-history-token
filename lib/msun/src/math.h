begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_comment
comment|/*  * from: @(#)fdlibm.h 5.1 93/09/24  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MATH_H_
end_ifndef

begin_define
define|#
directive|define
name|_MATH_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<machine/_limits.h>
end_include

begin_comment
comment|/*  * ANSI/POSIX  */
end_comment

begin_union
specifier|extern
specifier|const
union|union
name|__infinity_un
block|{
name|unsigned
name|char
name|__uc
index|[
literal|8
index|]
decl_stmt|;
name|double
name|__ud
decl_stmt|;
block|}
name|__infinity
union|;
end_union

begin_union
specifier|extern
specifier|const
union|union
name|__nan_un
block|{
name|unsigned
name|char
name|__uc
index|[
sizeof|sizeof
argument_list|(
name|float
argument_list|)
index|]
decl_stmt|;
name|float
name|__uf
decl_stmt|;
block|}
name|__nan
union|;
end_union

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|3
operator|,
literal|3
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|&&
name|__INTEL_COMPILER
operator|>=
literal|800
operator|)
end_if

begin_define
define|#
directive|define
name|__MATH_BUILTIN_CONSTANTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|3
operator|,
literal|0
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__MATH_BUILTIN_RELOPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__MATH_BUILTIN_CONSTANTS
end_ifdef

begin_define
define|#
directive|define
name|HUGE_VAL
value|__builtin_huge_val()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE_VAL
value|(__infinity.__ud)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_define
define|#
directive|define
name|FP_ILOGB0
value|(-__INT_MAX)
end_define

begin_define
define|#
directive|define
name|FP_ILOGBNAN
value|__INT_MAX
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__MATH_BUILTIN_CONSTANTS
end_ifdef

begin_define
define|#
directive|define
name|HUGE_VALF
value|__builtin_huge_valf()
end_define

begin_define
define|#
directive|define
name|HUGE_VALL
value|__builtin_huge_vall()
end_define

begin_define
define|#
directive|define
name|INFINITY
value|__builtin_inf()
end_define

begin_define
define|#
directive|define
name|NAN
value|__builtin_nan("")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE_VALF
value|(float)HUGE_VAL
end_define

begin_define
define|#
directive|define
name|HUGE_VALL
value|(long double)HUGE_VAL
end_define

begin_define
define|#
directive|define
name|INFINITY
value|HUGE_VALF
end_define

begin_define
define|#
directive|define
name|NAN
value|(__nan.__uf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MATH_BUILTIN_CONSTANTS */
end_comment

begin_define
define|#
directive|define
name|MATH_ERRNO
value|1
end_define

begin_define
define|#
directive|define
name|MATH_ERREXCEPT
value|2
end_define

begin_define
define|#
directive|define
name|math_errhandling
value|MATH_ERREXCEPT
end_define

begin_comment
comment|/* XXX We need a<machine/math.h>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FP_FAST_FMA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|FP_FAST_FMAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FP_FAST_FMAF
end_define

begin_comment
comment|/* Symbolic constants to classify floating point numbers. */
end_comment

begin_define
define|#
directive|define
name|FP_INFINITE
value|0x01
end_define

begin_define
define|#
directive|define
name|FP_NAN
value|0x02
end_define

begin_define
define|#
directive|define
name|FP_NORMAL
value|0x04
end_define

begin_define
define|#
directive|define
name|FP_SUBNORMAL
value|0x08
end_define

begin_define
define|#
directive|define
name|FP_ZERO
value|0x10
end_define

begin_define
define|#
directive|define
name|fpclassify
parameter_list|(
name|x
parameter_list|)
define|\
value|((sizeof (x) == sizeof (float)) ? __fpclassifyf(x) \     : (sizeof (x) == sizeof (double)) ? __fpclassifyd(x) \     : __fpclassifyl(x))
end_define

begin_define
define|#
directive|define
name|isfinite
parameter_list|(
name|x
parameter_list|)
define|\
value|((sizeof (x) == sizeof (float)) ? __isfinitef(x)	\     : (sizeof (x) == sizeof (double)) ? __isfinite(x)	\     : __isfinitel(x))
end_define

begin_define
define|#
directive|define
name|isinf
parameter_list|(
name|x
parameter_list|)
define|\
value|((sizeof (x) == sizeof (float)) ? __isinff(x)	\     : (sizeof (x) == sizeof (double)) ? isinf(x)	\     : __isinfl(x))
end_define

begin_define
define|#
directive|define
name|isnan
parameter_list|(
name|x
parameter_list|)
define|\
value|((sizeof (x) == sizeof (float)) ? isnanf(x)		\     : (sizeof (x) == sizeof (double)) ? isnan(x)	\     : __isnanl(x))
end_define

begin_define
define|#
directive|define
name|isnormal
parameter_list|(
name|x
parameter_list|)
define|\
value|((sizeof (x) == sizeof (float)) ? __isnormalf(x)	\     : (sizeof (x) == sizeof (double)) ? __isnormal(x)	\     : __isnormall(x))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__MATH_BUILTIN_RELOPS
end_ifdef

begin_define
define|#
directive|define
name|isgreater
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_isgreater((x), (y))
end_define

begin_define
define|#
directive|define
name|isgreaterequal
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_isgreaterequal((x), (y))
end_define

begin_define
define|#
directive|define
name|isless
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_isless((x), (y))
end_define

begin_define
define|#
directive|define
name|islessequal
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_islessequal((x), (y))
end_define

begin_define
define|#
directive|define
name|islessgreater
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_islessgreater((x), (y))
end_define

begin_define
define|#
directive|define
name|isunordered
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_isunordered((x), (y))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isgreater
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(!isunordered((x), (y))&& (x)> (y))
end_define

begin_define
define|#
directive|define
name|isgreaterequal
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(!isunordered((x), (y))&& (x)>= (y))
end_define

begin_define
define|#
directive|define
name|isless
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(!isunordered((x), (y))&& (x)< (y))
end_define

begin_define
define|#
directive|define
name|islessequal
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(!isunordered((x), (y))&& (x)<= (y))
end_define

begin_define
define|#
directive|define
name|islessgreater
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(!isunordered((x), (y))&& \ 					((x)> (y) || (y)> (x)))
end_define

begin_define
define|#
directive|define
name|isunordered
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(isnan(x) || isnan(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MATH_BUILTIN_RELOPS */
end_comment

begin_define
define|#
directive|define
name|signbit
parameter_list|(
name|x
parameter_list|)
define|\
value|((sizeof (x) == sizeof (float)) ? __signbitf(x)	\     : (sizeof (x) == sizeof (double)) ? __signbit(x)	\     : __signbitl(x))
end_define

begin_typedef
typedef|typedef
name|__double_t
name|double_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__float_t
name|float_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISO_C_VISIBLE>= 1999 */
end_comment

begin_comment
comment|/*  * XOPEN/SVID  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|M_E
value|2.7182818284590452354
end_define

begin_comment
comment|/* e */
end_comment

begin_define
define|#
directive|define
name|M_LOG2E
value|1.4426950408889634074
end_define

begin_comment
comment|/* log 2e */
end_comment

begin_define
define|#
directive|define
name|M_LOG10E
value|0.43429448190325182765
end_define

begin_comment
comment|/* log 10e */
end_comment

begin_define
define|#
directive|define
name|M_LN2
value|0.69314718055994530942
end_define

begin_comment
comment|/* log e2 */
end_comment

begin_define
define|#
directive|define
name|M_LN10
value|2.30258509299404568402
end_define

begin_comment
comment|/* log e10 */
end_comment

begin_define
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define

begin_comment
comment|/* pi */
end_comment

begin_define
define|#
directive|define
name|M_PI_2
value|1.57079632679489661923
end_define

begin_comment
comment|/* pi/2 */
end_comment

begin_define
define|#
directive|define
name|M_PI_4
value|0.78539816339744830962
end_define

begin_comment
comment|/* pi/4 */
end_comment

begin_define
define|#
directive|define
name|M_1_PI
value|0.31830988618379067154
end_define

begin_comment
comment|/* 1/pi */
end_comment

begin_define
define|#
directive|define
name|M_2_PI
value|0.63661977236758134308
end_define

begin_comment
comment|/* 2/pi */
end_comment

begin_define
define|#
directive|define
name|M_2_SQRTPI
value|1.12837916709551257390
end_define

begin_comment
comment|/* 2/sqrt(pi) */
end_comment

begin_define
define|#
directive|define
name|M_SQRT2
value|1.41421356237309504880
end_define

begin_comment
comment|/* sqrt(2) */
end_comment

begin_define
define|#
directive|define
name|M_SQRT1_2
value|0.70710678118654752440
end_define

begin_comment
comment|/* 1/sqrt(2) */
end_comment

begin_define
define|#
directive|define
name|MAXFLOAT
value|((float)3.40282346638528860e+38)
end_define

begin_decl_stmt
specifier|extern
name|int
name|signgam
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE || __XSI_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Old value from 4.4BSD-Lite math.h; this is probably better. */
end_comment

begin_define
define|#
directive|define
name|HUGE
value|HUGE_VAL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE
value|MAXFLOAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/*  * Most of these functions depend on the rounding mode and have the side  * effect of raising floating-point exceptions, so they are not declared  * as __pure2.  In C99, FENV_ACCESS affects the purity of these functions.  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
comment|/*  * ANSI/POSIX  */
name|int
name|__fpclassifyd
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__fpclassifyf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__fpclassifyl
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isfinitef
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isfinite
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isfinitel
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isinff
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isinfl
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isnanl
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isnormalf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isnormal
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__isnormall
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__signbit
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__signbitf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__signbitl
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|acos
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|asin
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atan
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atan2
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cos
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sin
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|tan
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cosh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sinh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|tanh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|exp
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|frexp
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_function_decl
name|double
name|ldexp
parameter_list|(
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log10
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|modf
parameter_list|(
name|double
parameter_list|,
name|double
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_function_decl
name|double
name|pow
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sqrt
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|ceil
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|fabs
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|floor
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|fmod
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These functions are not in C90.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__ISO_C_VISIBLE
operator|>=
literal|1999
operator|||
name|__XSI_VISIBLE
end_if

begin_function_decl
name|double
name|acosh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|asinh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atanh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cbrt
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|erf
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|erfc
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|exp2
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|expm1
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|fma
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|hypot
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ilogb
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_macro
name|int
argument_list|(
argument|isinf
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|double
operator|)
name|__pure2
expr_stmt|;
end_expr_stmt

begin_macro
name|int
argument_list|(
argument|isnan
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|double
operator|)
name|__pure2
expr_stmt|;
end_expr_stmt

begin_function_decl
name|double
name|lgamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|llrint
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|llround
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log1p
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|logb
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lrint
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lround
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|nextafter
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|remainder
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|remquo
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|rint
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE || __ISO_C_VISIBLE>= 1999 || __XSI_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_function_decl
name|double
name|j0
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|j1
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|jn
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|scalb
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|y0
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|y1
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|yn
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__XSI_VISIBLE
operator|<=
literal|500
operator|||
name|__BSD_VISIBLE
end_if

begin_function_decl
name|double
name|gamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE || __XSI_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_decl_stmt
name|double
name|copysign
argument_list|(
name|double
argument_list|,
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|fdim
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|fmax
argument_list|(
name|double
argument_list|,
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|fmin
argument_list|(
name|double
argument_list|,
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|nearbyint
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|round
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|scalbln
parameter_list|(
name|double
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|scalbn
parameter_list|(
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|tgamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|trunc
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * BSD math library entry points  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|double
name|drem
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|finite
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isnanf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Reentrant version of gamma& lgamma; passes signgam back by reference  * as the second argument; user must allocate space for signgam.  */
end_comment

begin_function_decl
name|double
name|gamma_r
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|lgamma_r
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * IEEE Test Vector  */
end_comment

begin_function_decl
name|double
name|significand
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/* float versions of ANSI/POSIX functions */
end_comment

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_function_decl
name|float
name|acosf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|asinf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|atanf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|atan2f
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|cosf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|sinf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|tanf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|coshf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|sinhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|tanhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|exp2f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|expf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|expm1f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|frexpf
parameter_list|(
name|float
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_decl_stmt
name|int
name|ilogbf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|float
name|ldexpf
parameter_list|(
name|float
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|log10f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|log1pf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|logf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|modff
parameter_list|(
name|float
parameter_list|,
name|float
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_function_decl
name|float
name|powf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|sqrtf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|ceilf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|float
name|fabsf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|float
name|floorf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|fmodf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|roundf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|erff
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|erfcf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|hypotf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|lgammaf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|acoshf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|asinhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|atanhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|cbrtf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|logbf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|float
name|copysignf
argument_list|(
name|float
argument_list|,
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|long
name|llrintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|llroundf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lrintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lroundf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|nearbyintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|nextafterf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|remainderf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|remquof
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|rintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|scalblnf
parameter_list|(
name|float
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|scalbnf
parameter_list|(
name|float
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|truncf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|fdimf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|fmaf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|float
name|fmaxf
argument_list|(
name|float
argument_list|,
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|fminf
argument_list|(
name|float
argument_list|,
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * float versions of BSD math library entry points  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|float
name|dremf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|finitef
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|float
name|gammaf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|j0f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|j1f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|jnf
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|scalbf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|y0f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|y1f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|ynf
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Float versions of reentrant version of gamma& lgamma; passes  * signgam back by reference as the second argument; user must  * allocate space for signgam.  */
end_comment

begin_function_decl
name|float
name|gammaf_r
parameter_list|(
name|float
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|lgammaf_r
parameter_list|(
name|float
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * float version of IEEE Test Vector  */
end_comment

begin_function_decl
name|float
name|significandf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/*  * long double versions of ISO/POSIX math functions  */
end_comment

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	acoshl(long double); long double	acosl(long double); long double	asinhl(long double); long double	asinl(long double); long double	atan2l(long double, long double); long double	atanhl(long double); long double	atanl(long double); long double	cbrtl(long double);
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|double
name|ceill
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|double
name|copysignl
argument_list|(
name|long
name|double
argument_list|,
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	coshl(long double); long double	cosl(long double); long double	erfcl(long double); long double	erfl(long double); long double	exp2l(long double); long double	expl(long double); long double	expm1l(long double);
endif|#
directive|endif
end_endif

begin_decl_stmt
name|long
name|double
name|fabsl
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|double
name|fdiml
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|floorl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|fmal
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|double
name|fmaxl
argument_list|(
name|long
name|double
argument_list|,
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|fminl
argument_list|(
name|long
name|double
argument_list|,
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	fmodl(long double, long double);
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|double
name|frexpl
parameter_list|(
name|long
name|double
name|value
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	hypotl(long double, long double);
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ilogbl
argument_list|(
name|long
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|double
name|ldexpl
parameter_list|(
name|long
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	lgammal(long double); long long	llrintl(long double);
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|long
name|llroundl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	log10l(long double); long double	log1pl(long double); long double	log2l(long double); long double	logbl(long double); long double	logl(long double); long		lrintl(long double);
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|lroundl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|modfl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	nanl(const char *) __pure2; long double	nearbyintl(long double);
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|double
name|nextafterl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|nexttoward
parameter_list|(
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|nexttowardf
parameter_list|(
name|float
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|nexttowardl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	powl(long double, long double); long double	remainderl(long double, long double); long double	remquol(long double, long double, int *); long double	rintl(long double);
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|double
name|roundl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|scalblnl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|scalbnl
parameter_list|(
name|long
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long double	sinhl(long double); long double	sinl(long double); long double	sqrtl(long double); long double	tanhl(long double); long double	tanl(long double); long double	tgammal(long double);
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|double
name|truncl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISO_C_VISIBLE>= 1999 */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MATH_H_ */
end_comment

end_unit

