begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-apple-darwin -verify -fsyntax-only -fno-gnu-inline-asm
end_comment

begin_asm
asm|asm ("INST r1, 0");
end_asm

begin_comment
comment|// expected-error {{GNU-style inline assembly is disabled}}
end_comment

begin_expr_stmt
name|void
name|foo
argument_list|()
asm|__asm("__foo_func");
comment|// AsmLabel is OK
name|int
name|foo1
end_expr_stmt

begin_asm
asm|asm("bar1") = 0;
end_asm

begin_comment
comment|// OK
end_comment

begin_asm
asm|asm(" ");
end_asm

begin_comment
comment|// Whitespace is OK
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|long
name|foo
init|=
literal|0
decl_stmt|,
name|bar
decl_stmt|;
asm|asm
specifier|volatile
asm|("INST %0, %1" : "=r"(foo) : "r"(bar));
comment|// expected-error {{GNU-style inline assembly is disabled}}
asm|asm ("");
comment|// Empty is OK
return|return;
block|}
end_function

end_unit

