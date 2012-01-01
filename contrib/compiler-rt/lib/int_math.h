begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- int_math.h - internal math inlines ---------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This file is not part of the interface of this library.  *  * This file defines substitutes for the libm functions used in some of the  * compiler-rt implementations, defined in such a way that there is not a direct  * dependency on libm or math.h. Instead, we use the compiler builtin versions  * where available. This reduces our dependencies on the system SDK by foisting  * the responsibility onto the compiler.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MATH_H
end_ifndef

begin_define
define|#
directive|define
name|INT_MATH_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__has_builtin
end_ifndef

begin_define
define|#
directive|define
name|__has_builtin
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CRT_INFINITY
value|__builtin_huge_valf()
end_define

begin_define
define|#
directive|define
name|crt_isinf
parameter_list|(
name|x
parameter_list|)
value|__builtin_isinf((x))
end_define

begin_define
define|#
directive|define
name|crt_isnan
parameter_list|(
name|x
parameter_list|)
value|__builtin_isnan((x))
end_define

begin_comment
comment|/* Define crt_isfinite in terms of the builtin if available, otherwise provide  * an alternate version in terms of our other functions. This supports some  * versions of GCC which didn't have __builtin_isfinite.  */
end_comment

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_isfinite
argument_list|)
end_if

begin_define
define|#
directive|define
name|crt_isfinite
parameter_list|(
name|x
parameter_list|)
value|__builtin_isfinite((x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|crt_isfinite
parameter_list|(
name|x
parameter_list|)
define|\
value|__extension__(({ \       __typeof((x)) x_ = (x); \       !crt_isinf(x_)&& !crt_isnan(x_); \     }))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|crt_copysign
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_copysign((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_copysignf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_copysignf((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_copysignl
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_copysignl((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_fabs
parameter_list|(
name|x
parameter_list|)
value|__builtin_fabs((x))
end_define

begin_define
define|#
directive|define
name|crt_fabsf
parameter_list|(
name|x
parameter_list|)
value|__builtin_fabsf((x))
end_define

begin_define
define|#
directive|define
name|crt_fabsl
parameter_list|(
name|x
parameter_list|)
value|__builtin_fabsl((x))
end_define

begin_define
define|#
directive|define
name|crt_fmax
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_fmax((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_fmaxf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_fmaxf((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_fmaxl
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_fmaxl((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_logb
parameter_list|(
name|x
parameter_list|)
value|__builtin_logb((x))
end_define

begin_define
define|#
directive|define
name|crt_logbf
parameter_list|(
name|x
parameter_list|)
value|__builtin_logbf((x))
end_define

begin_define
define|#
directive|define
name|crt_logbl
parameter_list|(
name|x
parameter_list|)
value|__builtin_logbl((x))
end_define

begin_define
define|#
directive|define
name|crt_scalbn
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_scalbn((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_scalbnf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_scalbnf((x), (y))
end_define

begin_define
define|#
directive|define
name|crt_scalbnl
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_scalbnl((x), (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_MATH_H */
end_comment

end_unit

