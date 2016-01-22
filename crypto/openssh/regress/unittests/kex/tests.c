begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	$OpenBSD: tests.c,v 1.1 2015/01/15 23:41:29 markus Exp $ */
end_comment

begin_comment
comment|/*  * Placed in the public domain  */
end_comment

begin_include
include|#
directive|include
file|"../test_helper/test_helper.h"
end_include

begin_function_decl
name|void
name|kex_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|tests
parameter_list|(
name|void
parameter_list|)
block|{
name|kex_tests
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

