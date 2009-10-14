begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* GCC wasn't handling 64 bit constants right fixed */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|long
name|long
name|Var
init|=
literal|123455678902ll
decl_stmt|;
name|printf
argument_list|(
literal|"%lld\n"
argument_list|,
name|Var
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

