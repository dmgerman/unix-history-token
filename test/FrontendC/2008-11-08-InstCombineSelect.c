begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -O2 -o -
end_comment

begin_comment
comment|// PR3028
end_comment

begin_decl_stmt
name|int
name|g_187
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g_204
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g_434
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|func_89
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|func_20
parameter_list|(
name|int
name|p_22
parameter_list|)
block|{
if|if
condition|(
literal|1
operator|&
name|p_22
operator||
name|g_204
operator|&
operator|(
literal|1
operator|<
name|g_187
operator|)
operator|-
name|func_89
argument_list|()
condition|)
name|g_434
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

