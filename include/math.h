begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)math.h	8.1 (Berkeley) 6/2/93  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_comment
comment|/* DBL_MAX from float.h */
end_comment

begin_define
define|#
directive|define
name|HUGE_VAL
value|1.701411834604692294E+38
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE_VAL
value|1e500
end_define

begin_comment
comment|/* IEEE: positive infinity */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_comment
comment|/*  * HUGE for the VAX and Tahoe converts to the largest possible F-float value.  * This implies an understanding of the conversion behavior of atof(3).  It  * was defined to be the largest float so that overflow didn't occur when it  * was assigned to a single precision number.  HUGE_VAL is strongly preferred.  */
end_comment

begin_define
define|#
directive|define
name|HUGE
value|1.701411733192644270E+38
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE
value|HUGE_VAL
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Most of these functions have the side effect of setting errno, except  * in the (broken) BSD libm, so they not declared as __pure2.  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
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

begin_decl_stmt
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

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_decl_stmt
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

begin_comment
comment|/* fundamentally !__pure2 */
end_comment

begin_decl_stmt
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

begin_comment
comment|/*  * These functions are non-ANSI so they can be "right".  The ones that  * don't set errno in [lib]msun are declared as __pure2.  */
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

begin_decl_stmt
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

begin_function_decl
name|double
name|cabs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* we can't describe cabs()'s argument properly */
end_comment

begin_decl_stmt
name|double
name|cbrt
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|double
name|erfc
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|expm1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|finite
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_decl_stmt
name|double
name|infnan
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|isinf
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isnan
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|double
name|log1p
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|logb
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|rint
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|scalb
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

begin_endif
endif|#
directive|endif
end_endif

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

