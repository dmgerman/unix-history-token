begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{  }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|bar
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{  }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|baz
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{
comment|// expected-error {{attribute requires 0 argument(s)}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|test0
argument_list|()
block|{
comment|// expected-error {{function with no prototype cannot use 'fastcall' calling convention}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|test1
argument_list|(
name|void
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|test2
argument_list|(
name|int
name|a
argument_list|,
operator|...
argument_list|)
block|{
comment|// expected-error {{variadic function cannot use 'fastcall' calling convention}}
block|}
end_decl_stmt

end_unit

