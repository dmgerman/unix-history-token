begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|int
name|fn
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
name|f
argument_list|()
block|{
name|printf
argument_list|(
literal|"original f..\n"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
name|g
argument_list|()
block|{
name|printf
argument_list|(
literal|"original f..\n"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|f
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

