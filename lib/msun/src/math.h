begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_comment
comment|/*  * from: @(#)fdlibm.h 5.1 93/09/24  * $Id: math.h,v 1.5 1997/08/31 22:12:19 bde Exp $  */
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

begin_comment
comment|/*  * ANSI/POSIX  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|__infinity
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HUGE_VAL
value|(*(double *) __infinity)
end_define

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

begin_define
define|#
directive|define
name|HUGE
value|MAXFLOAT
end_define

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

begin_decl_stmt
name|__BEGIN_DECLS
comment|/*  * ANSI/POSIX  */
specifier|extern
name|double
name|acos
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|asin
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|atan
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|atan2
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|cos
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|sin
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|tan
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|cosh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|sinh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|tanh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|exp
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|frexp
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|ldexp
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|log
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|log10
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|modf
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|pow
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|sqrt
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|ceil
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|fabs
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|floor
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|fmod
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|double
name|erf
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|erfc
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|gamma
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|hypot
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isinf
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isnan
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|finite
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|j0
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|j1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|jn
name|__P
argument_list|(
operator|(
name|int
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|lgamma
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|y0
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|y1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|yn
name|__P
argument_list|(
operator|(
name|int
operator|,
name|double
operator|)
argument_list|)
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

begin_decl_stmt
specifier|extern
name|double
name|acosh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|asinh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|atanh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|cbrt
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|logb
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|nextafter
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|remainder
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|scalb
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|matherr
name|__P
argument_list|(
operator|(
expr|struct
name|exception
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * IEEE Test Vector  */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|significand
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Functions callable from C, intended to support IEEE arithmetic.  */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|copysign
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ilogb
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|rint
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|scalbn
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * BSD math library entry points  */
end_comment

begin_function_decl
specifier|extern
name|double
name|cabs
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|double
name|drem
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|expm1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|log1p
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Reentrant version of gamma& lgamma; passes signgam back by reference  * as the second argument; user must allocate space for signgam.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_REENTRANT
end_ifdef

begin_decl_stmt
specifier|extern
name|double
name|gamma_r
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|lgamma_r
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _REENTRANT */
end_comment

begin_comment
comment|/* float versions of ANSI/POSIX functions */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|acosf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|asinf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|atanf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|atan2f
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|cosf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|sinf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|tanf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|coshf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|sinhf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|tanhf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|expf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|frexpf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|ldexpf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|logf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|log10f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|modff
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|powf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|sqrtf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|ceilf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|fabsf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|floorf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|fmodf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|erff
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|erfcf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|gammaf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|hypotf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isnanf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|finitef
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|j0f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|j1f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|jnf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|lgammaf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|y0f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|y1f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|ynf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|acoshf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|asinhf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|atanhf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|cbrtf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|logbf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|nextafterf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|remainderf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scalbf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * float version of IEEE Test Vector  */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|significandf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Float versions of functions callable from C, intended to support  * IEEE arithmetic.  */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|copysignf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ilogbf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|rintf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scalbnf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * float versions of BSD math library entry points  */
end_comment

begin_function_decl
specifier|extern
name|float
name|cabsf
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|float
name|dremf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|expm1f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|log1pf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Float versions of reentrant version of gamma& lgamma; passes  * signgam back by reference as the second argument; user must  * allocate space for signgam.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_REENTRANT
end_ifdef

begin_decl_stmt
specifier|extern
name|float
name|gammaf_r
name|__P
argument_list|(
operator|(
name|float
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|lgammaf_r
name|__P
argument_list|(
operator|(
name|float
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _REENTRANT */
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
comment|/* _MATH_H_ */
end_comment

end_unit

