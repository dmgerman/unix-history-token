begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t&&
end_comment

begin_comment
comment|// RUN: clang-cc --html-diags=%t -checker-cfref %s
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
modifier|*
name|p
init|=
operator|&
name|x
decl_stmt|;
if|if
condition|(
name|x
operator|>
literal|10
condition|)
block|{
if|if
condition|(
name|x
operator|==
literal|22
condition|)
name|p
operator|=
literal|0
expr_stmt|;
block|}
operator|*
name|p
operator|=
literal|10
expr_stmt|;
block|}
end_function

end_unit

