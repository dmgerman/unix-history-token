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
file|<sys/_types.h>
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

begin_define
define|#
directive|define
name|FP_ILOGB0
value|(-0x7fffffff - 1)
end_define

begin_comment
comment|/* INT_MIN */
end_comment

begin_define
define|#
directive|define
name|FP_ILOGBNAN
value|0x7fffffff
end_define

begin_comment
comment|/* INT_MAX */
end_comment

begin_define
define|#
directive|define
name|HUGE_VAL
value|(__infinity.__ud)
end_define

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
value|((fpclassify(x)& (FP_INFINITE|FP_NAN)) == 0)
end_define

begin_define
define|#
directive|define
name|isinf
parameter_list|(
name|x
parameter_list|)
value|(fpclassify(x) == FP_INFINITE)
end_define

begin_define
define|#
directive|define
name|isnan
parameter_list|(
name|x
parameter_list|)
value|(fpclassify(x) == FP_NAN)
end_define

begin_define
define|#
directive|define
name|isnanf
parameter_list|(
name|x
parameter_list|)
value|isnan(x)
end_define

begin_define
define|#
directive|define
name|isnormal
parameter_list|(
name|x
parameter_list|)
value|(fpclassify(x) == FP_NORMAL)
end_define

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

begin_define
define|#
directive|define
name|signbit
parameter_list|(
name|x
parameter_list|)
value|__signbit(x)
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

begin_comment
comment|/*  * XOPEN/SVID  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_XOPEN_SOURCE
argument_list|)
end_if

begin_enum
enum|enum
name|fdversion
block|{
name|fdlibm_ieee
init|=
operator|-
literal|1
block|,
name|fdlibm_svid
block|,
name|fdlibm_xopen
block|,
name|fdlibm_posix
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|_LIB_VERSION_TYPE
value|enum fdversion
end_define

begin_define
define|#
directive|define
name|_LIB_VERSION
value|_fdlib_version
end_define

begin_comment
comment|/* if global variable _LIB_VERSION is not desirable, one may  * change the following to be a constant by:  *	#define _LIB_VERSION_TYPE const enum version  * In that case, after one initializes the value _LIB_VERSION (see  * s_lib_version.c) during compile time, it cannot be modified  * in the middle of a program  */
end_comment

begin_decl_stmt
specifier|extern
name|_LIB_VERSION_TYPE
name|_LIB_VERSION
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_IEEE_
value|fdlibm_ieee
end_define

begin_define
define|#
directive|define
name|_SVID_
value|fdlibm_svid
end_define

begin_define
define|#
directive|define
name|_XOPEN_
value|fdlibm_xopen
end_define

begin_define
define|#
directive|define
name|_POSIX_
value|fdlibm_posix
end_define

begin_comment
comment|/* We have a problem when using C++ since `exception' is a reserved    name in C++.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_struct
struct|struct
name|exception
block|{
name|int
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|double
name|arg1
decl_stmt|;
name|double
name|arg2
decl_stmt|;
name|double
name|retval
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * set X_TLOSS = pi*2**52, which is possibly defined in<values.h>  * (one may replace the following line by "#include<values.h>")  */
end_comment

begin_define
define|#
directive|define
name|X_TLOSS
value|1.41484755040568800000e+16
end_define

begin_define
define|#
directive|define
name|DOMAIN
value|1
end_define

begin_define
define|#
directive|define
name|SING
value|2
end_define

begin_define
define|#
directive|define
name|OVERFLOW
value|3
end_define

begin_define
define|#
directive|define
name|UNDERFLOW
value|4
end_define

begin_define
define|#
directive|define
name|TLOSS
value|5
end_define

begin_define
define|#
directive|define
name|PLOSS
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_XOPEN_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE&& !_POSIX_SOURCE */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Most of these functions have the side effect of setting errno, so they  * are not declared as __pure2.  (XXX: this point needs to be revisited,  * since C99 doesn't require the mistake of setting errno, and we mostly  * don't set it anyway.  In C99, pragmas and functions for changing the  * rounding mode affect the purity of these functions.)  */
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
name|__signbit
argument_list|(
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

begin_function_decl
name|double
name|fabs
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

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
comment|/*  * These functions are not in C90 so they can be "right".  The ones that  * never set errno in lib/msun are declared as __pure2.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_function_decl
name|double
name|erf
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|erfc
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|finite
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|gamma
parameter_list|(
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
name|lgamma
parameter_list|(
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
operator|!
name|defined
argument_list|(
name|_XOPEN_SOURCE
argument_list|)
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

begin_decl_stmt
name|double
name|cbrt
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|logb
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

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
name|tgamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_function_decl
name|int
name|matherr
parameter_list|(
name|struct
name|exception
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Functions callable from C, intended to support IEEE arithmetic.  */
end_comment

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
name|int
name|ilogb
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|rint
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/*  * BSD math library entry points  */
end_comment

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
name|double
name|expm1
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|log1p
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Reentrant version of gamma& lgamma; passes signgam back by reference  * as the second argument; user must allocate space for signgam.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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
name|expf
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
name|logf
parameter_list|(
name|float
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

begin_function_decl
name|float
name|fabsf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

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
name|erff
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|float
name|erfcf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|float
name|hypotf
argument_list|(
name|float
argument_list|,
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

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
name|lgammaf
parameter_list|(
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

begin_decl_stmt
name|float
name|cbrtf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|logbf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

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
name|scalbf
parameter_list|(
name|float
parameter_list|,
name|float
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

begin_comment
comment|/*  * Float versions of functions callable from C, intended to support  * IEEE arithmetic.  */
end_comment

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
name|int
name|ilogbf
parameter_list|(
name|float
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
name|scalbnf
parameter_list|(
name|float
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * float versions of BSD math library entry points  */
end_comment

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
name|float
name|expm1f
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|log1pf
argument_list|(
name|float
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Float versions of reentrant version of gamma& lgamma; passes  * signgam back by reference as the second argument; user must  * allocate space for signgam.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_XOPEN_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE&& !_POSIX_SOURCE */
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

