begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c)1999 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	citrus Id: wctype.h,v 1.4 2000/12/21 01:50:21 itojun Exp  *	$NetBSD: wctype.h,v 1.3 2000/12/22 14:16:16 itojun Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: not implemented */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WCTYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_WCTYPE_H_
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

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_WINT_T_
end_ifdef

begin_undef
unit|typedef	_BSD_WINT_T_    wint_t;
undef|#
directive|undef
name|_BSD_WINT_T_
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

begin_endif
unit|__BEGIN_DECLS int	iswalnum(wint_t); int	iswalpha(wint_t); int	iswblank(wint_t); int	iswcntrl(wint_t); int	iswdigit(wint_t); int	iswgraph(wint_t); int	iswlower(wint_t); int	iswprint(wint_t); int	iswpunct(wint_t); int	iswspace(wint_t); int	iswupper(wint_t); int	iswxdigit(wint_t); wint_t	towlower(wint_t); wint_t	towupper(wint_t); __END_DECLS
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WCTYPE_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

