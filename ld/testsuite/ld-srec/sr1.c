begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is compiled and linked into the S-record format.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|e1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|e2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|j
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|k
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|l
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|ab
index|[]
init|=
literal|"This is a string constant"
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|fn1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fn2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|fn1
argument_list|(
name|ab
argument_list|)
expr_stmt|;
name|fn2
argument_list|(
literal|"static string constant"
argument_list|)
expr_stmt|;
return|return
name|e1
operator|+
name|e2
operator|+
name|i
operator|+
name|j
operator|+
name|k
operator|+
name|l
return|;
block|}
end_function

begin_function
name|void
name|__main
parameter_list|()
block|{ }
end_function

end_unit

