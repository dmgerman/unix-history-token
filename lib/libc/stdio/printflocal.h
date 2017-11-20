begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Flags used during conversion.  */
end_comment

begin_define
define|#
directive|define
name|ALT
value|0x001
end_define

begin_comment
comment|/* alternate form */
end_comment

begin_define
define|#
directive|define
name|LADJUST
value|0x004
end_define

begin_comment
comment|/* left adjustment */
end_comment

begin_define
define|#
directive|define
name|LONGDBL
value|0x008
end_define

begin_comment
comment|/* long double */
end_comment

begin_define
define|#
directive|define
name|LONGINT
value|0x010
end_define

begin_comment
comment|/* long integer */
end_comment

begin_define
define|#
directive|define
name|LLONGINT
value|0x020
end_define

begin_comment
comment|/* long long integer */
end_comment

begin_define
define|#
directive|define
name|SHORTINT
value|0x040
end_define

begin_comment
comment|/* short integer */
end_comment

begin_define
define|#
directive|define
name|ZEROPAD
value|0x080
end_define

begin_comment
comment|/* zero (as opposed to blank) pad */
end_comment

begin_define
define|#
directive|define
name|FPT
value|0x100
end_define

begin_comment
comment|/* Floating point number */
end_comment

begin_define
define|#
directive|define
name|GROUPING
value|0x200
end_define

begin_comment
comment|/* use grouping ("'" flag) */
end_comment

begin_comment
comment|/* C99 additional size modifiers: */
end_comment

begin_define
define|#
directive|define
name|SIZET
value|0x400
end_define

begin_comment
comment|/* size_t */
end_comment

begin_define
define|#
directive|define
name|PTRDIFFT
value|0x800
end_define

begin_comment
comment|/* ptrdiff_t */
end_comment

begin_define
define|#
directive|define
name|INTMAXT
value|0x1000
end_define

begin_comment
comment|/* intmax_t */
end_comment

begin_define
define|#
directive|define
name|CHARINT
value|0x2000
end_define

begin_comment
comment|/* print char using int format */
end_comment

begin_comment
comment|/*  * Macros for converting digits to letters and vice versa  */
end_comment

begin_define
define|#
directive|define
name|to_digit
parameter_list|(
name|c
parameter_list|)
value|((c) - '0')
end_define

begin_define
define|#
directive|define
name|is_digit
parameter_list|(
name|c
parameter_list|)
value|((unsigned)to_digit(c)<= 9)
end_define

begin_define
define|#
directive|define
name|to_char
parameter_list|(
name|n
parameter_list|)
value|((n) + '0')
end_define

begin_comment
comment|/* Size of the static argument table. */
end_comment

begin_define
define|#
directive|define
name|STATIC_ARG_TBL_SIZE
value|8
end_define

begin_union
union|union
name|arg
block|{
name|int
name|intarg
decl_stmt|;
name|u_int
name|uintarg
decl_stmt|;
name|long
name|longarg
decl_stmt|;
name|u_long
name|ulongarg
decl_stmt|;
name|long
name|long
name|longlongarg
decl_stmt|;
name|unsigned
name|long
name|long
name|ulonglongarg
decl_stmt|;
name|ptrdiff_t
name|ptrdiffarg
decl_stmt|;
name|size_t
name|sizearg
decl_stmt|;
name|intmax_t
name|intmaxarg
decl_stmt|;
name|uintmax_t
name|uintmaxarg
decl_stmt|;
name|void
modifier|*
name|pvoidarg
decl_stmt|;
name|char
modifier|*
name|pchararg
decl_stmt|;
name|signed
name|char
modifier|*
name|pschararg
decl_stmt|;
name|short
modifier|*
name|pshortarg
decl_stmt|;
name|int
modifier|*
name|pintarg
decl_stmt|;
name|long
modifier|*
name|plongarg
decl_stmt|;
name|long
name|long
modifier|*
name|plonglongarg
decl_stmt|;
name|ptrdiff_t
modifier|*
name|pptrdiffarg
decl_stmt|;
name|ssize_t
modifier|*
name|pssizearg
decl_stmt|;
name|intmax_t
modifier|*
name|pintmaxarg
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_FLOATING_POINT
name|double
name|doublearg
decl_stmt|;
name|long
name|double
name|longdoublearg
decl_stmt|;
endif|#
directive|endif
name|wint_t
name|wintarg
decl_stmt|;
name|wchar_t
modifier|*
name|pwchararg
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Handle positional parameters. */
end_comment

begin_function_decl
name|int
name|__find_arguments
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|,
name|union
name|arg
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__find_warguments
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|va_list
parameter_list|,
name|union
name|arg
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

