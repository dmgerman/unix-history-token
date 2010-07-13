begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s
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

end_unit

