begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_bcs.h,v 1.6 2009/01/11 02:46:24 christos Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_BCS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_BCS_H_
end_define

begin_comment
comment|/*  * predicate/conversion for basic character set.  *  * `Basic character set' is a term defined in the ISO C standard.  * Citrus bcs is, if anything, close to `portable character set'  * defined in the POSIX.  */
end_comment

begin_define
define|#
directive|define
name|_CITRUS_BCS_PRED
parameter_list|(
name|_name_
parameter_list|,
name|_cond_
parameter_list|)
define|\
value|static __inline int _citrus_bcs_##_name_(uint8_t c) { return (_cond_); }
end_define

begin_comment
comment|/*  * predicates.  * Unlike predicates defined in ctype.h, these do not accept EOF.  */
end_comment

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|isblank
argument_list|,
argument|c ==
literal|' '
argument||| c ==
literal|'\t'
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|iseol
argument_list|,
argument|c ==
literal|'\n'
argument||| c ==
literal|'\r'
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|isspace
argument_list|,
argument|_citrus_bcs_isblank(c) || _citrus_bcs_iseol(c) ||     c ==
literal|'\f'
argument||| c ==
literal|'\v'
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|isdigit
argument_list|,
argument|c>=
literal|'0'
argument|&& c<=
literal|'9'
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|isupper
argument_list|,
argument|c>=
literal|'A'
argument|&& c<=
literal|'Z'
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|islower
argument_list|,
argument|c>=
literal|'a'
argument|&& c<=
literal|'z'
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|isalpha
argument_list|,
argument|_citrus_bcs_isupper(c) || _citrus_bcs_islower(c)
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|isalnum
argument_list|,
argument|_citrus_bcs_isdigit(c) || _citrus_bcs_isalpha(c)
argument_list|)
end_macro

begin_macro
name|_CITRUS_BCS_PRED
argument_list|(
argument|isxdigit
argument_list|,
argument|_citrus_bcs_isdigit(c) ||     (c>=
literal|'A'
argument|&& c<=
literal|'F'
argument|) || (c>=
literal|'a'
argument|&& c<=
literal|'f'
argument|)
argument_list|)
end_macro

begin_comment
comment|/*  * transliterate between uppercase and lowercase.  * Unlike transliterator defined in ctype.h, these do not accept EOF.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint8_t
name|_citrus_bcs_toupper
parameter_list|(
name|uint8_t
name|c
parameter_list|)
block|{
return|return
operator|(
name|_citrus_bcs_islower
argument_list|(
name|c
argument_list|)
condition|?
operator|(
name|c
operator|-
literal|'a'
operator|+
literal|'A'
operator|)
else|:
name|c
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint8_t
name|_citrus_bcs_tolower
parameter_list|(
name|uint8_t
name|c
parameter_list|)
block|{
return|return
operator|(
name|_citrus_bcs_isupper
argument_list|(
name|c
argument_list|)
condition|?
operator|(
name|c
operator|-
literal|'A'
operator|+
literal|'a'
operator|)
else|:
name|c
operator|)
return|;
block|}
end_function

begin_function_decl
name|__BEGIN_DECLS
name|int
name|_citrus_bcs_strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_citrus_bcs_strncasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|_citrus_bcs_skip_ws
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|_citrus_bcs_skip_nonws
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|_citrus_bcs_skip_ws_len
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|_citrus_bcs_skip_nonws_len
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_citrus_bcs_trunc_rws_len
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_citrus_bcs_convert_to_lower
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_citrus_bcs_convert_to_upper
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|int
name|_citrus_bcs_strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|_citrus_bcs_strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
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

end_unit

