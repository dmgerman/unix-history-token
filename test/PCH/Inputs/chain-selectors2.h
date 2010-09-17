begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
unit|@
name|interface
name|Y
operator|-
operator|(
name|void
operator|)
name|f
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|double
operator|)
name|f2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|e
expr_stmt|;
end_expr_stmt

begin_function
unit|@
name|end
name|void
name|foo2
parameter_list|()
block|{
comment|// FIXME: Can't verify warnings in headers
comment|//(void)@selector(y);
comment|//(void)@selector(e);
block|}
end_function

end_unit

