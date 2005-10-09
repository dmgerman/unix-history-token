begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1997-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: assertions.h,v 1.17.206.1 2004/03/06 08:14:38 marka Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ASSERTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ASSERTIONS_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_assertiontype_require
block|,
name|isc_assertiontype_ensure
block|,
name|isc_assertiontype_insist
block|,
name|isc_assertiontype_invariant
block|}
name|isc_assertiontype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_assertioncallback_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|isc_assertiontype_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
name|isc_assertioncallback_t
name|isc_assertion_failed
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|isc_assertion_setcallback
parameter_list|(
name|isc_assertioncallback_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|isc_assertion_typetotext
parameter_list|(
name|isc_assertiontype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_CHECK_ALL
end_ifdef

begin_define
define|#
directive|define
name|ISC_CHECK_REQUIRE
value|1
end_define

begin_define
define|#
directive|define
name|ISC_CHECK_ENSURE
value|1
end_define

begin_define
define|#
directive|define
name|ISC_CHECK_INSIST
value|1
end_define

begin_define
define|#
directive|define
name|ISC_CHECK_INVARIANT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_CHECK_NONE
end_ifdef

begin_define
define|#
directive|define
name|ISC_CHECK_REQUIRE
value|0
end_define

begin_define
define|#
directive|define
name|ISC_CHECK_ENSURE
value|0
end_define

begin_define
define|#
directive|define
name|ISC_CHECK_INSIST
value|0
end_define

begin_define
define|#
directive|define
name|ISC_CHECK_INVARIANT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_CHECK_REQUIRE
end_ifndef

begin_define
define|#
directive|define
name|ISC_CHECK_REQUIRE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_CHECK_ENSURE
end_ifndef

begin_define
define|#
directive|define
name|ISC_CHECK_ENSURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_CHECK_INSIST
end_ifndef

begin_define
define|#
directive|define
name|ISC_CHECK_INSIST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_CHECK_INVARIANT
end_ifndef

begin_define
define|#
directive|define
name|ISC_CHECK_INVARIANT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ISC_CHECK_REQUIRE
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|ISC_REQUIRE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((isc_assertion_failed)(__FILE__, __LINE__, \ 					 isc_assertiontype_require, \ 					 #cond), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_REQUIRE
parameter_list|(
name|cond
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_CHECK_REQUIRE */
end_comment

begin_if
if|#
directive|if
name|ISC_CHECK_ENSURE
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|ISC_ENSURE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((isc_assertion_failed)(__FILE__, __LINE__, \ 					 isc_assertiontype_ensure, \ 					 #cond), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_ENSURE
parameter_list|(
name|cond
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_CHECK_ENSURE */
end_comment

begin_if
if|#
directive|if
name|ISC_CHECK_INSIST
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|ISC_INSIST
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((isc_assertion_failed)(__FILE__, __LINE__, \ 					 isc_assertiontype_insist, \ 					 #cond), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_INSIST
parameter_list|(
name|cond
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_CHECK_INSIST */
end_comment

begin_if
if|#
directive|if
name|ISC_CHECK_INVARIANT
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|ISC_INVARIANT
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((isc_assertion_failed)(__FILE__, __LINE__, \ 					 isc_assertiontype_invariant, \ 					 #cond), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_INVARIANT
parameter_list|(
name|cond
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_CHECK_INVARIANT */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ASSERTIONS_H */
end_comment

end_unit

