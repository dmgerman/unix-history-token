begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|__thread
name|int
name|tls0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__thread
name|int
name|tls1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__thread
name|int
name|tls2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|tls0
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|tls1
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|tls2
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|tls0
operator|+
name|tls1
operator|+
name|tls2
return|;
block|}
end_function

end_unit

