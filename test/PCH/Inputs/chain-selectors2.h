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
name|void
operator|)
name|f2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|y
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

begin_decl_stmt
unit|@
name|interface
name|X
argument_list|(
name|Blarg
argument_list|)
decl|-
argument_list|(
name|void
argument_list|)
name|blarg_method
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

