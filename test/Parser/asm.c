begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
asm|asm ("ret" : : :);
comment|// expected-error {{expected string literal}}
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

end_unit

