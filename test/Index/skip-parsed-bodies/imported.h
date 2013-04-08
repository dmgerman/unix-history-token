begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|int
name|some_val
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|imp_foo
parameter_list|()
block|{
operator|++
name|some_val
expr_stmt|;
return|return
name|undef_impval
return|;
block|}
end_function

end_unit

