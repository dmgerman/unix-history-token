begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: test.h,v 1.6 2001/04/03 01:53:01 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  Abstractions for writing a libsm test program. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_TEST_H
end_ifndef

begin_define
define|#
directive|define
name|SM_TEST_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

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
name|SM_TEST
parameter_list|(
name|cond
parameter_list|)
value|sm_test(cond, #cond, __FILE__, __LINE__)
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
name|SM_TEST
parameter_list|(
name|cond
parameter_list|)
value|sm_test(cond, "cond", __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|SmTestIndex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SmTestNumErrors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_test_begin
name|__P
argument_list|(
operator|(
name|int
name|_argc
operator|,
name|char
operator|*
operator|*
name|_argv
operator|,
name|char
operator|*
name|_testname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sm_test
name|__P
argument_list|(
operator|(
name|bool
name|_success
operator|,
name|char
operator|*
name|_expr
operator|,
name|char
operator|*
name|_filename
operator|,
name|int
name|_lineno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_test_end
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_TEST_H */
end_comment

end_unit

