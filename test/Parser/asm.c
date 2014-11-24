begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
comment|// PR7673: Some versions of GCC support an empty clobbers section.
asm|asm ("ret" : : :);
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
asm|asm("foo" : "=r" (a));
comment|// expected-error {{use of undeclared identifier 'a'}}
asm|asm("foo" : : "r" (b));
comment|// expected-error {{use of undeclared identifier 'b'}}
name|asm
specifier|const
operator|(
literal|""
operator|)
expr_stmt|;
comment|// expected-warning {{ignored const qualifier on asm}}
asm|asm
specifier|volatile
asm|("");
name|asm
specifier|restrict
operator|(
literal|""
operator|)
expr_stmt|;
comment|// expected-warning {{ignored restrict qualifier on asm}}
comment|// FIXME: Once GCC supports _Atomic, check whether it allows this.
name|asm
decl|_Atomic
argument_list|(
literal|""
argument_list|)
decl_stmt|;
comment|// expected-warning {{ignored _Atomic qualifier on asm}}
block|}
end_function

begin_comment
comment|// rdar://5952468
end_comment

begin_asm
asm|__asm ;
end_asm

begin_comment
comment|// expected-error {{expected '(' after 'asm'}}
end_comment

begin_comment
comment|//<rdar://problem/10465079> - Don't crash on wide string literals in 'asm'.
end_comment

begin_decl_stmt
name|int
name|foo
name|asm
argument_list|(
literal|L"bar"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use wide string literal in 'asm'}}
end_comment

begin_asm
asm|asm()
comment|// expected-error {{expected string literal in 'asm'}}
comment|// expected-error@-1 {{expected ';' after top-level asm block}}
asm|asm(;
comment|// expected-error {{expected string literal in 'asm'}}
asm|asm("")
comment|// expected-error {{expected ';' after top-level asm block}}
comment|// Unterminated asm strings at the end of the file were causing us to crash, so
comment|// this needs to be last. rdar://15624081
comment|// expected-warning@+3 {{missing terminating '"' character}}
comment|// expected-error@+2 {{expected string literal in 'asm'}}
comment|// expected-error@+1 {{expected ';' after top-level asm block}}
asm|asm("
end_asm

end_unit

