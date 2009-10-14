begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
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
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"testing\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

