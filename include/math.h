begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)math.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|HUGE_VAL
value|1e500
end_define

begin_comment
comment|/* IEEE: positive infinity */
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
name|HUGE
value|HUGE_VAL
end_define

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

begin_function_decl
name|__BEGIN_DECLS
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
name|ceil
parameter_list|(
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
name|cosh
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
name|sin
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
name|sqrt
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
name|tanh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

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
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

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
name|drem
parameter_list|(
name|double
parameter_list|,
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
name|double
name|expm1
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
name|isinf
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isnan
argument_list|(
name|double
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|double
name|log1p
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
name|scalb
parameter_list|(
name|double
parameter_list|,
name|int
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

