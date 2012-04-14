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

end_unit

