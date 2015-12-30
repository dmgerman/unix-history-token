begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|__thread
name|int
name|extern_tls
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|extern_tls
operator|=
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

