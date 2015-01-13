begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sys.h,v 1.17 2011/09/28 14:08:04 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sys.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * sys.h: Put all the stupid compiler and system dependencies here...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_sys
end_ifndef

begin_define
define|#
directive|define
name|_h_sys
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_CDEFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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
name|__attribute__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|8
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|A
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BEGIN_DECLS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|__BEGIN_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|__END_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BEGIN_DECLS
end_define

begin_define
define|#
directive|define
name|__END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|public
end_ifndef

begin_define
define|#
directive|define
name|public
end_define

begin_comment
comment|/* Externally visible functions/variables */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|private
end_ifndef

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_comment
comment|/* Always hidden internals */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|protected
end_ifndef

begin_define
define|#
directive|define
name|protected
end_define

begin_comment
comment|/* Redefined from elsewhere to "static" */
end_comment

begin_comment
comment|/* When we want to hide everything	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__arraycount
end_ifndef

begin_define
define|#
directive|define
name|__arraycount
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof(*(a)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCAT
end_ifndef

begin_define
define|#
directive|define
name|strlcat
value|libedit_strlcat
end_define

begin_function_decl
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_define
define|#
directive|define
name|strlcpy
value|libedit_strlcpy
end_define

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FGETLN
end_ifndef

begin_define
define|#
directive|define
name|fgetln
value|libedit_fgetln
end_define

begin_function_decl
name|char
modifier|*
name|fgetln
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WCSDUP
end_ifndef

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_function_decl
name|wchar_t
modifier|*
name|wcsdup
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_DIAGASSERT
end_ifndef

begin_define
define|#
directive|define
name|_DIAGASSERT
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RCSID
end_ifndef

begin_define
define|#
directive|define
name|__RCSID
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT32_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|((size_t)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REGEX
end_define

begin_comment
comment|/* Use POSIX.2 regular expression functions */
end_comment

begin_undef
undef|#
directive|undef
name|REGEXP
end_undef

begin_comment
comment|/* Use UNIX V8 regular expression functions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sun
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|tgetent
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetflag
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetnum
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgoto
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgetstr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_sys */
end_comment

end_unit

