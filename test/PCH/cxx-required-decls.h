begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-required-decls.cpp
end_comment

begin_struct
struct|struct
name|S
block|{
name|S
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|S
name|globS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ext_foo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|bar
init|=
operator|++
name|ext_foo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|glob_var
decl_stmt|;
end_decl_stmt

end_unit

