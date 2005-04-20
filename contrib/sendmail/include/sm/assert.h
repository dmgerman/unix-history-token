begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: assert.h,v 1.10 2001/06/07 20:04:53 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm abnormal program termination and assertion checking **  See libsm/assert.html for documentation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_ASSERT_H
end_ifndef

begin_define
define|#
directive|define
name|SM_ASSERT_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_include
include|#
directive|include
file|<sm/debug.h>
end_include

begin_comment
comment|/* **  abnormal program termination */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*SM_ABORT_HANDLER_T
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_extern
extern|extern SM_DEAD(void sm_abort_at __P(( 	const char *
operator|,
extern|int
operator|,
extern|const char *
end_extern

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_abort_sethandler
name|__P
argument_list|(
operator|(
name|SM_ABORT_HANDLER_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern SM_DEAD(void PRINTFLIKE(1
operator|,
extern|2
end_extern

begin_decl_stmt
unit|)
name|sm_abort
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|);
end_decl_stmt

begin_comment
comment|/* **  assertion checking */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CHECK_ALL
end_ifndef

begin_define
define|#
directive|define
name|SM_CHECK_ALL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CHECK_ALL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CHECK_REQUIRE
end_ifndef

begin_define
define|#
directive|define
name|SM_CHECK_REQUIRE
value|SM_CHECK_ALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CHECK_REQUIRE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CHECK_ENSURE
end_ifndef

begin_define
define|#
directive|define
name|SM_CHECK_ENSURE
value|SM_CHECK_ALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CHECK_ENSURE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CHECK_ASSERT
end_ifndef

begin_define
define|#
directive|define
name|SM_CHECK_ASSERT
value|SM_CHECK_ALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CHECK_ASSERT */
end_comment

begin_if
if|#
directive|if
name|SM_CHECK_REQUIRE
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_REQUIRE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || (sm_abort_at(__FILE__, __LINE__, \ 	"SM_REQUIRE(" #cond ") failed"), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_define
define|#
directive|define
name|SM_REQUIRE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || (sm_abort_at(__FILE__, __LINE__, \ 	"SM_REQUIRE(cond) failed"), 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CHECK_REQUIRE */
end_comment

begin_define
define|#
directive|define
name|SM_REQUIRE
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
comment|/* SM_CHECK_REQUIRE */
end_comment

begin_define
define|#
directive|define
name|SM_REQUIRE_ISA
parameter_list|(
name|obj
parameter_list|,
name|magic
parameter_list|)
define|\
value|SM_REQUIRE((obj) != NULL&& (obj)->sm_magic == (magic))
end_define

begin_if
if|#
directive|if
name|SM_CHECK_ENSURE
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_ENSURE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || (sm_abort_at(__FILE__, __LINE__, \ 	"SM_ENSURE(" #cond ") failed"), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_define
define|#
directive|define
name|SM_ENSURE
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || (sm_abort_at(__FILE__, __LINE__, \ 	"SM_ENSURE(cond) failed"), 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CHECK_ENSURE */
end_comment

begin_define
define|#
directive|define
name|SM_ENSURE
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
comment|/* SM_CHECK_ENSURE */
end_comment

begin_if
if|#
directive|if
name|SM_CHECK_ASSERT
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_ASSERT
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || (sm_abort_at(__FILE__, __LINE__, \ 	"SM_ASSERT(" #cond ") failed"), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_define
define|#
directive|define
name|SM_ASSERT
parameter_list|(
name|cond
parameter_list|)
define|\
value|((void) ((cond) || (sm_abort_at(__FILE__, __LINE__, \ 	"SM_ASSERT(cond) failed"), 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CHECK_ASSERT */
end_comment

begin_define
define|#
directive|define
name|SM_ASSERT
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
comment|/* SM_CHECK_ASSERT */
end_comment

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmExpensiveRequire
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmExpensiveEnsure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmExpensiveAssert
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_ASSERT_H */
end_comment

end_unit

