begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-pc-linux-gnu -verify -fsyntax-only
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
asm|asm ("foo\n" : : "a" (i + 2));
asm|asm ("foo\n" : : "a" (f()));
comment|// expected-error {{invalid type 'void' in asm input}}
asm|asm ("foo\n" : "=a" (f()));
comment|// expected-error {{invalid lvalue in asm output}}
asm|asm ("foo\n" : "=a" (i + 2));
comment|// expected-error {{invalid lvalue in asm output}}
asm|asm ("foo\n" : [symbolic_name] "=a" (i) : "[symbolic_name]" (i));
asm|asm ("foo\n" : "=a" (i) : "[" (i));
comment|// expected-error {{invalid input constraint '[' in asm}}
asm|asm ("foo\n" : "=a" (i) : "[foo" (i));
comment|// expected-error {{invalid input constraint '[foo' in asm}}
asm|asm ("foo\n" : "=a" (i) : "[symbolic_name]" (i));
comment|// expected-error {{invalid input constraint '[symbolic_name]' in asm}}
block|}
end_function

begin_function
name|void
name|clobbers
parameter_list|()
block|{
asm|asm ("nop" : : : "ax", "#ax", "%ax");
asm|asm ("nop" : : : "eax", "rax", "ah", "al");
asm|asm ("nop" : : : "0", "%0", "#0");
asm|asm ("nop" : : : "foo");
comment|// expected-error {{unknown register name 'foo' in asm}}
asm|asm ("nop" : : : "52");
asm|asm ("nop" : : : "53");
comment|// expected-error {{unknown register name '53' in asm}}
asm|asm ("nop" : : : "-1");
comment|// expected-error {{unknown register name '-1' in asm}}
asm|asm ("nop" : : : "+1");
comment|// expected-error {{unknown register name '+1' in asm}}
block|}
end_function

begin_comment
comment|// rdar://6094010
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
asm|asm(L"foo" : "=r"(x));
comment|// expected-error {{wide string}}
asm|asm("foo" : L"=r"(x));
comment|// expected-error {{wide string}}
block|}
end_function

begin_comment
comment|//<rdar://problem/6156893>
end_comment

begin_function
name|void
name|test4
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
asm|asm ("nop" : : "r"(*addr));
comment|// expected-error {{invalid type 'void const volatile' in asm input for constraint 'r'}}
asm|asm ("nop" : : "m"(*addr));
asm|asm ("nop" : : "r"(test4(addr)));
comment|// expected-error {{invalid type 'void' in asm input for constraint 'r'}}
asm|asm ("nop" : : "m"(test4(addr)));
comment|// expected-error {{invalid lvalue in asm input for constraint 'm'}}
asm|asm ("nop" : : "m"(f()));
comment|// expected-error {{invalid lvalue in asm input for constraint 'm'}}
block|}
end_function

begin_comment
comment|//<rdar://problem/6512595>
end_comment

begin_function
name|void
name|test5
parameter_list|()
block|{
asm|asm("nop" : : "X" (8));
block|}
end_function

begin_comment
comment|// PR3385
end_comment

begin_function
name|void
name|test6
parameter_list|(
name|long
name|i
parameter_list|)
block|{
asm|asm("nop" : : "er"(i));
block|}
end_function

begin_function
name|void
name|asm_string_tests
parameter_list|(
name|int
name|i
parameter_list|)
block|{
asm|asm("%!");
comment|// simple asm string, %! is not an error.
asm|asm("%!" : );
comment|// expected-error {{invalid % escape in inline assembly string}}
asm|asm("xyz %" : );
comment|// expected-error {{invalid % escape in inline assembly string}}
asm|asm ("%[somename]" :: [somename] "i"(4));
comment|// ok
asm|asm ("%[somename]" :: "i"(4));
comment|// expected-error {{unknown symbolic operand name in inline assembly string}}
asm|asm ("%[somename" :: "i"(4));
comment|// expected-error {{unterminated symbolic operand name in inline assembly string}}
asm|asm ("%[]" :: "i"(4));
comment|// expected-error {{empty symbolic operand name in inline assembly string}}
comment|// PR3258
asm|asm("%9" :: "i"(4));
comment|// expected-error {{invalid operand number in inline asm string}}
asm|asm("%1" : "+r"(i));
comment|// ok, referring to input.
block|}
end_function

begin_comment
comment|// PR4077
end_comment

begin_function
name|int
name|test7
parameter_list|(
name|unsigned
name|long
name|long
name|b
parameter_list|)
block|{
name|int
name|a
decl_stmt|;
asm|asm
specifier|volatile
asm|("foo %0 %1" : "=a" (a) :"0" (b));
comment|// expected-error {{input with type 'unsigned long long' matching output with type 'int'}}
return|return
name|a
return|;
block|}
end_function

end_unit

