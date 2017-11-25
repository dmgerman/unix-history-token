begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2001-2011 The FreeBSD Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPLEX_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPLEX_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|<
literal|199901
end_if

begin_define
define|#
directive|define
name|_Complex
value|__complex__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_Complex_I
value|((float _Complex)1.0i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__generic
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
name|__generic
argument_list|(
name|_Complex_I
argument_list|,
name|float
specifier|_Complex
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"_Complex_I must be of type float _Complex"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|complex
value|_Complex
end_define

begin_define
define|#
directive|define
name|I
value|_Complex_I
end_define

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|2011
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_define
define|#
directive|define
name|CMPLX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((double complex){ x, y })
end_define

begin_define
define|#
directive|define
name|CMPLXF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((float complex){ x, y })
end_define

begin_define
define|#
directive|define
name|CMPLXL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((long double complex){ x, y })
end_define

begin_elif
elif|#
directive|elif
name|__GNUC_PREREQ__
argument_list|(
literal|4
operator|,
literal|7
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CMPLX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_complex((double)(x), (double)(y))
end_define

begin_define
define|#
directive|define
name|CMPLXF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_complex((float)(x), (float)(y))
end_define

begin_define
define|#
directive|define
name|CMPLXL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_complex((long double)(x), (long double)(y))
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
comment|/* __ISO_C_VISIBLE>= 2011 */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|double
name|cabs
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|cabsf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|cabsl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|cacos
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|cacosf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|cacosh
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|cacoshf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|complex
name|cacoshl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|complex
name|cacosl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|carg
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|cargf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|cargl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|casin
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|casinf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|casinh
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|casinhf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|complex
name|casinhl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|complex
name|casinl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|catan
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|catanf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|catanh
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|catanhf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|complex
name|catanhl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|complex
name|catanl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|ccos
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|ccosf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|ccosh
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|ccoshf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|cexp
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|cexpf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|cimag
argument_list|(
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|cimagf
argument_list|(
name|float
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|cimagl
argument_list|(
name|long
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|complex
name|conj
argument_list|(
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|complex
name|conjf
argument_list|(
name|float
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|complex
name|conjl
argument_list|(
name|long
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|complex
name|cprojf
argument_list|(
name|float
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|complex
name|cproj
argument_list|(
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|complex
name|cprojl
argument_list|(
name|long
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|creal
argument_list|(
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|crealf
argument_list|(
name|float
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|creall
argument_list|(
name|long
name|double
name|complex
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|complex
name|csin
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|csinf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|csinh
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|csinhf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|csqrt
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|csqrtf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|complex
name|csqrtl
parameter_list|(
name|long
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|ctan
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|ctanf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|complex
name|ctanh
parameter_list|(
name|double
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|complex
name|ctanhf
parameter_list|(
name|float
name|complex
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPLEX_H */
end_comment

end_unit

