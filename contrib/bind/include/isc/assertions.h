begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: assertions.h,v 8.3 2000/07/17 07:53:59 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASSERTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|ASSERTIONS_H
value|1
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|assert_require
block|,
name|assert_ensure
block|,
name|assert_insist
block|,
name|assert_invariant
block|}
name|assertion_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|assertion_failure_callback
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|assertion_type
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|assertion_failure_callback
name|__assertion_failed
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_assertion_failure_callback
parameter_list|(
name|assertion_failure_callback
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|assertion_type_to_text
parameter_list|(
name|assertion_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CHECK_ALL
end_ifdef

begin_define
define|#
directive|define
name|CHECK_REQUIRE
value|1
end_define

begin_define
define|#
directive|define
name|CHECK_ENSURE
value|1
end_define

begin_define
define|#
directive|define
name|CHECK_INSIST
value|1
end_define

begin_define
define|#
directive|define
name|CHECK_INVARIANT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CHECK_NONE
end_ifdef

begin_define
define|#
directive|define
name|CHECK_REQUIRE
value|0
end_define

begin_define
define|#
directive|define
name|CHECK_ENSURE
value|0
end_define

begin_define
define|#
directive|define
name|CHECK_INSIST
value|0
end_define

begin_define
define|#
directive|define
name|CHECK_INVARIANT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_REQUIRE
end_ifndef

begin_define
define|#
directive|define
name|CHECK_REQUIRE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_ENSURE
end_ifndef

begin_define
define|#
directive|define
name|CHECK_ENSURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_INSIST
end_ifndef

begin_define
define|#
directive|define
name|CHECK_INSIST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_INVARIANT
end_ifndef

begin_define
define|#
directive|define
name|CHECK_INVARIANT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CHECK_REQUIRE
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|REQUIRE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_require, \ 				       #cond, 0), 0)))
end_define

begin_define
define|#
directive|define
name|REQUIRE_ERR
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_require, \ 				       #cond, 1), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REQUIRE
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_define
define|#
directive|define
name|REQUIRE_ERR
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHECK_REQUIRE */
end_comment

begin_if
if|#
directive|if
name|CHECK_ENSURE
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|ENSURE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_ensure, \ 				       #cond, 0), 0)))
end_define

begin_define
define|#
directive|define
name|ENSURE_ERR
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_ensure, \ 				       #cond, 1), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENSURE
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_define
define|#
directive|define
name|ENSURE_ERR
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHECK_ENSURE */
end_comment

begin_if
if|#
directive|if
name|CHECK_INSIST
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|INSIST
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_insist, \ 				       #cond, 0), 0)))
end_define

begin_define
define|#
directive|define
name|INSIST_ERR
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_insist, \ 				       #cond, 1), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INSIST
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_define
define|#
directive|define
name|INSIST_ERR
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHECK_INSIST */
end_comment

begin_if
if|#
directive|if
name|CHECK_INVARIANT
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|INVARIANT
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_invariant, \ 				       #cond, 0), 0)))
end_define

begin_define
define|#
directive|define
name|INVARIANT_ERR
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || \ 		 ((__assertion_failed)(__FILE__, __LINE__, assert_invariant, \ 				       #cond, 1), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INVARIANT
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_define
define|#
directive|define
name|INVARIANT_ERR
parameter_list|(
name|cond
parameter_list|)
value|((void) (cond))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHECK_INVARIANT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASSERTIONS_H */
end_comment

end_unit

