begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// rdar: // 8125274
end_comment

begin_decl_stmt
specifier|static
name|int
name|a16
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{tentative array definition assumed to have one element}}
end_comment

begin_function
name|void
name|f16
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|a16
index|[]
decl_stmt|;
block|}
end_function

begin_comment
comment|// PR10013: Scope of extern declarations extend past enclosing block
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PR10013_x
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|PR10013
parameter_list|(
name|void
parameter_list|)
block|{
name|int
modifier|*
name|PR10013_x
init|=
literal|0
decl_stmt|;
block|{
specifier|extern
name|int
name|PR10013_x
decl_stmt|;
specifier|extern
name|int
name|PR10013_x
decl_stmt|;
block|}
return|return
name|PR10013_x
return|;
comment|// expected-warning{{incompatible pointer to integer conversion}}
block|}
end_function

end_unit

