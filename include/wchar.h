begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c)1999 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999, 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Julian Coleman.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: wchar.h,v 1.8 2000/12/22 05:31:42 itojun Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_WCHAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_WCHAR_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_WCHAR_T_
name|wchar_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_MBSTATE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_MBSTATE_T_
name|mbstate_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_MBSTATE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_WINT_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_WINT_T_
name|wint_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_WINT_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEOF
end_ifndef

begin_define
define|#
directive|define
name|WEOF
value|((wint_t)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
if|#
directive|if
literal|0
comment|/* XXX: not implemented */
type|size_t	mbrlen(const char * __restrict, size_t, mbstate_t * __restrict); size_t	mbrtowc(wchar_t * __restrict, const char * __restrict, size_t, 	    mbstate_t * __restrict); int	mbsinit(const mbstate_t *); size_t	mbsrtowcs(wchar_t * __restrict, const char ** __restrict, size_t, 	    mbstate_t * __restrict); size_t	wcrtomb(char * __restrict, wchar_t, mbstate_t * __restrict);
endif|#
directive|endif
name|wchar_t
modifier|*
name|wcscat
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wcschr
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wcscmp
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wcscpy
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcscspn
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcslen
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wcsncat
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wcsncmp
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wcsncpy
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wcspbrk
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wcsrchr
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: not implemented */
end_comment

begin_endif
unit|size_t	wcsrtombs(char * __restrict, const wchar_t ** __restrict, size_t, 	    mbstate_t * __restrict);
endif|#
directive|endif
end_endif

begin_function_decl
name|size_t
name|wcsspn
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wcsstr
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wmemchr
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|wchar_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wmemcmp
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wmemcpy
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wmemmove
parameter_list|(
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wchar_t
modifier|*
name|wmemset
parameter_list|(
name|wchar_t
modifier|*
parameter_list|,
name|wchar_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcslcat
parameter_list|(
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcslcpy
parameter_list|(
name|wchar_t
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: not implemented */
end_comment

begin_endif
unit|int	wcswidth(const wchar_t *, size_t); int	wcwidth(wchar_t);
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
comment|/* !_WCHAR_H_ */
end_comment

end_unit

