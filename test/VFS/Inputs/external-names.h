begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|void
name|foo
parameter_list|(
name|char
modifier|*
modifier|*
name|c
parameter_list|)
block|{
operator|*
name|c
operator|=
name|__FILE__
expr_stmt|;
name|int
name|x
init|=
name|c
decl_stmt|;
comment|// produce a diagnostic
block|}
end_function

end_unit

