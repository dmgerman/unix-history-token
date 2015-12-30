begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|g1
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g2
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|%
literal|5
operator|==
literal|0
condition|)
name|g1
operator|++
expr_stmt|;
else|else
name|g2
operator|++
expr_stmt|;
block|}
end_function

end_unit

