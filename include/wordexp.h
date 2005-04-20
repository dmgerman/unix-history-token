begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Tim J. Robbins.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WORDEXP_H_
end_ifndef

begin_define
define|#
directive|define
name|_WORDEXP_H_
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

begin_if
if|#
directive|if
name|__XSI_VISIBLE
operator|&&
operator|!
name|defined
argument_list|(
name|_SIZE_T_DECLARED
argument_list|)
end_if

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|__size_t
name|we_wordc
decl_stmt|;
comment|/* count of words matched */
name|char
modifier|*
modifier|*
name|we_wordv
decl_stmt|;
comment|/* pointer to list of words */
name|__size_t
name|we_offs
decl_stmt|;
comment|/* slots to reserve in we_wordv */
name|char
modifier|*
name|we_strings
decl_stmt|;
comment|/* storage for wordv strings */
name|__size_t
name|we_nbytes
decl_stmt|;
comment|/* size of we_strings */
block|}
name|wordexp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for wordexp().  */
end_comment

begin_define
define|#
directive|define
name|WRDE_APPEND
value|0x1
end_define

begin_comment
comment|/* append to previously generated */
end_comment

begin_define
define|#
directive|define
name|WRDE_DOOFFS
value|0x2
end_define

begin_comment
comment|/* we_offs member is valid */
end_comment

begin_define
define|#
directive|define
name|WRDE_NOCMD
value|0x4
end_define

begin_comment
comment|/* disallow command substitution */
end_comment

begin_define
define|#
directive|define
name|WRDE_REUSE
value|0x8
end_define

begin_comment
comment|/* reuse wordexp_t */
end_comment

begin_define
define|#
directive|define
name|WRDE_SHOWERR
value|0x10
end_define

begin_comment
comment|/* don't redirect stderr to /dev/null */
end_comment

begin_define
define|#
directive|define
name|WRDE_UNDEF
value|0x20
end_define

begin_comment
comment|/* disallow undefined shell vars */
end_comment

begin_comment
comment|/*  * Return values from wordexp().  */
end_comment

begin_define
define|#
directive|define
name|WRDE_BADCHAR
value|1
end_define

begin_comment
comment|/* unquoted special character */
end_comment

begin_define
define|#
directive|define
name|WRDE_BADVAL
value|2
end_define

begin_comment
comment|/* undefined variable */
end_comment

begin_define
define|#
directive|define
name|WRDE_CMDSUB
value|3
end_define

begin_comment
comment|/* command substitution not allowed */
end_comment

begin_define
define|#
directive|define
name|WRDE_NOSPACE
value|4
end_define

begin_comment
comment|/* no memory for result */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|WRDE_NOSYS
value|5
end_define

begin_comment
comment|/* obsolete, reserved */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WRDE_SYNTAX
value|6
end_define

begin_comment
comment|/* shell syntax error */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|wordexp
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|wordexp_t
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wordfree
parameter_list|(
name|wordexp_t
modifier|*
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
comment|/* !_WORDEXP_H_ */
end_comment

end_unit

