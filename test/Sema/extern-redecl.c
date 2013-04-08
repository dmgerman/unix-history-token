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

begin_decl_stmt
specifier|static
name|int
name|test1_a
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{tentative array definition assumed to have one element}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test1_a
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rdar://13535367
end_comment

begin_function
name|void
name|test2declarer
parameter_list|()
block|{
specifier|extern
name|int
name|test2_array
index|[
literal|100
index|]
decl_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|test2_array
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|test2v
init|=
sizeof|sizeof
argument_list|(
name|test2_array
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid application of 'sizeof' to an incomplete type 'int []'}}
end_comment

begin_function
name|void
name|test3declarer
parameter_list|()
block|{
block|{
specifier|extern
name|int
name|test3_array
index|[
literal|100
index|]
decl_stmt|;
block|}
specifier|extern
name|int
name|test3_array
index|[]
decl_stmt|;
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|test3_array
argument_list|)
decl_stmt|;
comment|// expected-error {{invalid application of 'sizeof' to an incomplete type 'int []'}}
block|}
end_function

end_unit

