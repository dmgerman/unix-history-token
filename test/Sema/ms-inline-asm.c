begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-apple-darwin10 -fasm-blocks -Wno-microsoft -verify -fsyntax-only
end_comment

begin_function
name|void
name|t1
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm
asm|__asm
comment|//
asm|expected-error {{__asm used with no assembly instructions}}
block|}
end_function

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|foo
decl_stmt|;
asm|__asm {
asm|mov eax, eax
asm|.unknowndirective
comment|//
asm|expected-error {{unknown directive}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, 1+=2
comment|//
asm|expected-error {{unknown token in expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, 1+++
comment|//
asm|expected-error {{unknown token in expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, LENGTH bar
comment|//
asm|expected-error {{unable to lookup expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, SIZE bar
comment|//
asm|expected-error {{unable to lookup expression}}
asm|}
name|f
argument_list|()
expr_stmt|;
asm|__asm {
asm|mov eax, TYPE bar
comment|//
asm|expected-error {{unable to lookup expression}}
asm|}
block|}
end_function

end_unit

