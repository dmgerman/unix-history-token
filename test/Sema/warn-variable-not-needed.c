begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wall %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
specifier|static
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|bar
parameter_list|()
block|{
specifier|extern
name|int
name|a
decl_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|a
decl_stmt|;
end_decl_stmt

end_unit

