begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -g -S -o - | grep {test/FrontendC}
end_comment

begin_comment
comment|// PR676
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|test
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Hello World\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

