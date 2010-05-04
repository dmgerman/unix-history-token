begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %llvmgcc -O1 %s -S |& grep {error: invalid use of array with unspecified bounds}
end_comment

begin_comment
comment|// PR6913
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
name|int
name|x
index|[
literal|10
index|]
index|[
literal|10
index|]
decl_stmt|;
name|int
argument_list|(
operator|*
name|p
argument_list|)
index|[]
operator|=
name|x
expr_stmt|;
comment|//<-- this line is what triggered it
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|p
index|[
name|i
index|]
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
block|}
block|}
end_function

end_unit

