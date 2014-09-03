begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Stefan Farfeleder.  * All rights reserved.  *  * Copyright (c) 2012 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TGMATH_H_
end_ifndef

begin_define
define|#
directive|define
name|_TGMATH_H_
end_define

begin_include
include|#
directive|include
file|<complex.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/*  * This implementation of<tgmath.h> uses the two following macros,  * which are based on the macros described in C11 proposal N1404:  * __tg_impl_simple(x, y, z, fnl, fn, fnf, ...)  *	Invokes fnl() if the corresponding real type of x, y or z is long  *	double, fn() if it is double or any has an integer type, and fnf()  *	otherwise.  * __tg_impl_full(x, y, cfnl, cfn, cfnf, fnl, fn, fnf, ...)  *	Invokes [c]fnl() if the corresponding real type of x or y is long  *	double, [c]fn() if it is double or any has an integer type, and  *	[c]fnf() otherwise.  The function with the 'c' prefix is called if  *	any of x or y is a complex number.  * Both macros call the chosen function with all additional arguments passed  * to them, as given by __VA_ARGS__.  *  * Note that these macros cannot be implemented with C's ?: operator,  * because the return type of the whole expression would incorrectly be long  * double complex regardless of the argument types.  *  * The structure of the C11 implementation of these macros can in  * principle be reused for non-C11 compilers, but due to an integer  * promotion bug for complex types in GCC 4.2, simply let non-C11  * compilers use an inefficient yet reliable version.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|201112L
operator|)
operator|||
expr|\
name|__has_extension
argument_list|(
name|c_generic_selections
argument_list|)
operator|||
name|__GNUC_PREREQ__
argument_list|(
literal|4
operator|,
literal|9
argument_list|)
end_if

begin_define
define|#
directive|define
name|__tg_generic
parameter_list|(
name|x
parameter_list|,
name|cfnl
parameter_list|,
name|cfn
parameter_list|,
name|cfnf
parameter_list|,
name|fnl
parameter_list|,
name|fn
parameter_list|,
name|fnf
parameter_list|)
define|\
value|_Generic(x,							\ 		long double _Complex: cfnl,				\ 		double _Complex: cfn,					\ 		float _Complex: cfnf,					\ 		long double: fnl,					\ 		default: fn,						\ 		float: fnf						\ 	)
end_define

begin_define
define|#
directive|define
name|__tg_type
parameter_list|(
name|x
parameter_list|)
define|\
value|__tg_generic(x, (long double _Complex)0, (double _Complex)0,	\ 	    (float _Complex)0, (long double)0, (double)0, (float)0)
end_define

begin_define
define|#
directive|define
name|__tg_impl_simple
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|fnl
parameter_list|,
name|fn
parameter_list|,
name|fnf
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__tg_generic(							\ 	    __tg_type(x) + __tg_type(y) + __tg_type(z),			\ 	    fnl, fn, fnf, fnl, fn, fnf)(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|__tg_impl_full
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|cfnl
parameter_list|,
name|cfn
parameter_list|,
name|cfnf
parameter_list|,
name|fnl
parameter_list|,
name|fn
parameter_list|,
name|fnf
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__tg_generic(							\ 	    __tg_type(x) + __tg_type(y),				\ 	    cfnl, cfn, cfnf, fnl, fn, fnf)(__VA_ARGS__)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__generic
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__tg_generic_simple
parameter_list|(
name|x
parameter_list|,
name|fnl
parameter_list|,
name|fn
parameter_list|,
name|fnf
parameter_list|)
define|\
value|__generic(x, long double _Complex, fnl,				\ 	    __generic(x, double _Complex, fn,				\ 	        __generic(x, float _Complex, fnf,			\ 	            __generic(x, long double, fnl,			\ 	                __generic(x, float, fnf, fn)))))
end_define

begin_define
define|#
directive|define
name|__tg_impl_simple
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|fnl
parameter_list|,
name|fn
parameter_list|,
name|fnf
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__tg_generic_simple(x,						\ 	    __tg_generic_simple(y,					\ 	        __tg_generic_simple(z, fnl, fnl, fnl),			\ 	        __tg_generic_simple(z, fnl, fnl, fnl),			\ 	        __tg_generic_simple(z, fnl, fnl, fnl)),			\ 	    __tg_generic_simple(y,					\ 	        __tg_generic_simple(z, fnl, fnl, fnl),			\ 	        __tg_generic_simple(z, fnl, fn , fn ),			\ 	        __tg_generic_simple(z, fnl, fn , fn )),			\ 	    __tg_generic_simple(y,					\ 	        __tg_generic_simple(z, fnl, fnl, fnl),			\ 	        __tg_generic_simple(z, fnl, fn , fn ),			\ 	        __tg_generic_simple(z, fnl, fn , fnf)))(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|__tg_generic_full
parameter_list|(
name|x
parameter_list|,
name|cfnl
parameter_list|,
name|cfn
parameter_list|,
name|cfnf
parameter_list|,
name|fnl
parameter_list|,
name|fn
parameter_list|,
name|fnf
parameter_list|)
define|\
value|__generic(x, long double _Complex, cfnl,			\ 	    __generic(x, double _Complex, cfn,				\ 	        __generic(x, float _Complex, cfnf,			\ 	            __generic(x, long double, fnl,			\ 	                __generic(x, float, fnf, fn)))))
end_define

begin_define
define|#
directive|define
name|__tg_impl_full
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|cfnl
parameter_list|,
name|cfn
parameter_list|,
name|cfnf
parameter_list|,
name|fnl
parameter_list|,
name|fn
parameter_list|,
name|fnf
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__tg_generic_full(x,						\ 	    __tg_generic_full(y, cfnl, cfnl, cfnl, cfnl, cfnl, cfnl),	\ 	    __tg_generic_full(y, cfnl, cfn , cfn , cfnl, cfn , cfn ),	\ 	    __tg_generic_full(y, cfnl, cfn , cfnf, cfnl, cfn , cfnf),	\ 	    __tg_generic_full(y, cfnl, cfnl, cfnl, fnl , fnl , fnl ),	\ 	    __tg_generic_full(y, cfnl, cfn , cfn , fnl , fn  , fn  ),	\ 	    __tg_generic_full(y, cfnl, cfn , cfnf, fnl , fn  , fnf ))	\ 	    (__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"<tgmath.h> not implemented for this compiler"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros to save lots of repetition below */
end_comment

begin_define
define|#
directive|define
name|__tg_simple
parameter_list|(
name|x
parameter_list|,
name|fn
parameter_list|)
define|\
value|__tg_impl_simple(x, x, x, fn##l, fn, fn##f, x)
end_define

begin_define
define|#
directive|define
name|__tg_simple2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|fn
parameter_list|)
define|\
value|__tg_impl_simple(x, x, y, fn##l, fn, fn##f, x, y)
end_define

begin_define
define|#
directive|define
name|__tg_simple3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|fn
parameter_list|)
define|\
value|__tg_impl_simple(x, y, z, fn##l, fn, fn##f, x, y, z)
end_define

begin_define
define|#
directive|define
name|__tg_simplev
parameter_list|(
name|x
parameter_list|,
name|fn
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__tg_impl_simple(x, x, x, fn##l, fn, fn##f, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|__tg_full
parameter_list|(
name|x
parameter_list|,
name|fn
parameter_list|)
define|\
value|__tg_impl_full(x, x, c##fn##l, c##fn, c##fn##f, fn##l, fn, fn##f, x)
end_define

begin_define
define|#
directive|define
name|__tg_full2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|fn
parameter_list|)
define|\
value|__tg_impl_full(x, y, c##fn##l, c##fn, c##fn##f, fn##l, fn, fn##f, x, y)
end_define

begin_comment
comment|/* 7.22#4 -- These macros expand to real or complex functions, depending on  * the type of their arguments. */
end_comment

begin_define
define|#
directive|define
name|acos
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, acos)
end_define

begin_define
define|#
directive|define
name|asin
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, asin)
end_define

begin_define
define|#
directive|define
name|atan
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, atan)
end_define

begin_define
define|#
directive|define
name|acosh
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, acosh)
end_define

begin_define
define|#
directive|define
name|asinh
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, asinh)
end_define

begin_define
define|#
directive|define
name|atanh
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, atanh)
end_define

begin_define
define|#
directive|define
name|cos
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, cos)
end_define

begin_define
define|#
directive|define
name|sin
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, sin)
end_define

begin_define
define|#
directive|define
name|tan
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, tan)
end_define

begin_define
define|#
directive|define
name|cosh
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, cosh)
end_define

begin_define
define|#
directive|define
name|sinh
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, sinh)
end_define

begin_define
define|#
directive|define
name|tanh
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, tanh)
end_define

begin_define
define|#
directive|define
name|exp
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, exp)
end_define

begin_define
define|#
directive|define
name|log
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, log)
end_define

begin_define
define|#
directive|define
name|pow
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_full2(x, y, pow)
end_define

begin_define
define|#
directive|define
name|sqrt
parameter_list|(
name|x
parameter_list|)
value|__tg_full(x, sqrt)
end_define

begin_comment
comment|/* "The corresponding type-generic macro for fabs and cabs is fabs." */
end_comment

begin_define
define|#
directive|define
name|fabs
parameter_list|(
name|x
parameter_list|)
value|__tg_impl_full(x, x, cabsl, cabs, cabsf,	\     			    fabsl, fabs, fabsf, x)
end_define

begin_comment
comment|/* 7.22#5 -- These macros are only defined for arguments with real type. */
end_comment

begin_define
define|#
directive|define
name|atan2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, atan2)
end_define

begin_define
define|#
directive|define
name|cbrt
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, cbrt)
end_define

begin_define
define|#
directive|define
name|ceil
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, ceil)
end_define

begin_define
define|#
directive|define
name|copysign
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, copysign)
end_define

begin_define
define|#
directive|define
name|erf
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, erf)
end_define

begin_define
define|#
directive|define
name|erfc
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, erfc)
end_define

begin_define
define|#
directive|define
name|exp2
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, exp2)
end_define

begin_define
define|#
directive|define
name|expm1
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, expm1)
end_define

begin_define
define|#
directive|define
name|fdim
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, fdim)
end_define

begin_define
define|#
directive|define
name|floor
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, floor)
end_define

begin_define
define|#
directive|define
name|fma
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|__tg_simple3(x, y, z, fma)
end_define

begin_define
define|#
directive|define
name|fmax
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, fmax)
end_define

begin_define
define|#
directive|define
name|fmin
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, fmin)
end_define

begin_define
define|#
directive|define
name|fmod
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, fmod)
end_define

begin_define
define|#
directive|define
name|frexp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simplev(x, frexp, x, y)
end_define

begin_define
define|#
directive|define
name|hypot
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, hypot)
end_define

begin_define
define|#
directive|define
name|ilogb
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, ilogb)
end_define

begin_define
define|#
directive|define
name|ldexp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simplev(x, ldexp, x, y)
end_define

begin_define
define|#
directive|define
name|lgamma
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, lgamma)
end_define

begin_define
define|#
directive|define
name|llrint
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, llrint)
end_define

begin_define
define|#
directive|define
name|llround
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, llround)
end_define

begin_define
define|#
directive|define
name|log10
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, log10)
end_define

begin_define
define|#
directive|define
name|log1p
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, log1p)
end_define

begin_define
define|#
directive|define
name|log2
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, log2)
end_define

begin_define
define|#
directive|define
name|logb
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, logb)
end_define

begin_define
define|#
directive|define
name|lrint
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, lrint)
end_define

begin_define
define|#
directive|define
name|lround
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, lround)
end_define

begin_define
define|#
directive|define
name|nearbyint
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, nearbyint)
end_define

begin_define
define|#
directive|define
name|nextafter
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, nextafter)
end_define

begin_define
define|#
directive|define
name|nexttoward
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simplev(x, nexttoward, x, y)
end_define

begin_define
define|#
directive|define
name|remainder
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simple2(x, y, remainder)
end_define

begin_define
define|#
directive|define
name|remquo
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|__tg_impl_simple(x, x, y, remquol, remquo,	\ 			    remquof, x, y, z)
end_define

begin_define
define|#
directive|define
name|rint
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, rint)
end_define

begin_define
define|#
directive|define
name|round
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, round)
end_define

begin_define
define|#
directive|define
name|scalbn
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simplev(x, scalbn, x, y)
end_define

begin_define
define|#
directive|define
name|scalbln
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__tg_simplev(x, scalbln, x, y)
end_define

begin_define
define|#
directive|define
name|tgamma
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, tgamma)
end_define

begin_define
define|#
directive|define
name|trunc
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, trunc)
end_define

begin_comment
comment|/* 7.22#6 -- These macros always expand to complex functions. */
end_comment

begin_define
define|#
directive|define
name|carg
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, carg)
end_define

begin_define
define|#
directive|define
name|cimag
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, cimag)
end_define

begin_define
define|#
directive|define
name|conj
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, conj)
end_define

begin_define
define|#
directive|define
name|cproj
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, cproj)
end_define

begin_define
define|#
directive|define
name|creal
parameter_list|(
name|x
parameter_list|)
value|__tg_simple(x, creal)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TGMATH_H_ */
end_comment

end_unit

