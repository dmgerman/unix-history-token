begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c)1999 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	citrus Id: wctype.h,v 1.4 2000/12/21 01:50:21 itojun Exp  *	$NetBSD: wctype.h,v 1.3 2000/12/22 14:16:16 itojun Exp $  * $FreeBSD$  */
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
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<_ctype.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_WCTRANS_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|wctrans_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_WCTRANS_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WCTYPE_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|wctype_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_WCTYPE_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WINT_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__wint_t
name|wint_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_WINT_T_DECLARED
end_define

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
name|int
name|iswalnum
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswalpha
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswblank
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswcntrl
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswctype
parameter_list|(
name|wint_t
parameter_list|,
name|wctype_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswdigit
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswgraph
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswlower
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswprint
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswpunct
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswspace
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswupper
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iswxdigit
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|towctrans
parameter_list|(
name|wint_t
parameter_list|,
name|wctrans_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|towlower
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|towupper
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wctrans_t
name|wctrans
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wctype_t
name|wctype
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|wint_t
name|iswascii
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|iswhexnumber
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|iswideogram
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|iswnumber
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|iswphonogram
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|iswrune
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|iswspecial
parameter_list|(
name|wint_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|nextwctype
parameter_list|(
name|wint_t
parameter_list|,
name|wctype_t
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

begin_define
define|#
directive|define
name|iswalnum
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_A|_CTYPE_D)
end_define

begin_define
define|#
directive|define
name|iswalpha
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_A)
end_define

begin_define
define|#
directive|define
name|iswblank
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_B)
end_define

begin_define
define|#
directive|define
name|iswcntrl
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_C)
end_define

begin_define
define|#
directive|define
name|iswctype
parameter_list|(
name|wc
parameter_list|,
name|charclass
parameter_list|)
value|__istype((wc), (charclass))
end_define

begin_define
define|#
directive|define
name|iswdigit
parameter_list|(
name|wc
parameter_list|)
value|__isctype((wc), _CTYPE_D)
end_define

begin_define
define|#
directive|define
name|iswgraph
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_G)
end_define

begin_define
define|#
directive|define
name|iswlower
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_L)
end_define

begin_define
define|#
directive|define
name|iswprint
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_R)
end_define

begin_define
define|#
directive|define
name|iswpunct
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_P)
end_define

begin_define
define|#
directive|define
name|iswspace
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_S)
end_define

begin_define
define|#
directive|define
name|iswupper
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_U)
end_define

begin_define
define|#
directive|define
name|iswxdigit
parameter_list|(
name|wc
parameter_list|)
value|__isctype((wc), _CTYPE_X)
end_define

begin_define
define|#
directive|define
name|towlower
parameter_list|(
name|wc
parameter_list|)
value|__tolower(wc)
end_define

begin_define
define|#
directive|define
name|towupper
parameter_list|(
name|wc
parameter_list|)
value|__toupper(wc)
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|iswascii
parameter_list|(
name|wc
parameter_list|)
value|(((wc)& ~0x7F) == 0)
end_define

begin_define
define|#
directive|define
name|iswhexnumber
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_X)
end_define

begin_define
define|#
directive|define
name|iswideogram
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_I)
end_define

begin_define
define|#
directive|define
name|iswnumber
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_D)
end_define

begin_define
define|#
directive|define
name|iswphonogram
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_Q)
end_define

begin_define
define|#
directive|define
name|iswrune
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), 0xFFFFFF00L)
end_define

begin_define
define|#
directive|define
name|iswspecial
parameter_list|(
name|wc
parameter_list|)
value|__istype((wc), _CTYPE_T)
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
comment|/* _WCTYPE_H_ */
end_comment

end_unit

