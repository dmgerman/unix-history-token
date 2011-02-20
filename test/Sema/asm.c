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
comment|// expected-error {{invalid type 'const volatile void' in asm input for constraint 'r'}}
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

begin_comment
comment|//<rdar://problem/7574870>
end_comment

begin_asm
asm|asm
specifier|volatile
asm|("");
end_asm

begin_comment
comment|// expected-warning {{meaningless 'volatile' on asm outside function}}
end_comment

begin_comment
comment|// PR3904
end_comment

begin_function
name|void
name|test8
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// A number in an input constraint can't point to a read-write constraint.
asm|asm("" : "+r" (i), "=r"(i) :  "0" (i));
comment|// expected-error{{invalid input constraint '0' in asm}}
block|}
end_function

begin_comment
comment|// PR3905
end_comment

begin_function
name|void
name|test9
parameter_list|(
name|int
name|i
parameter_list|)
block|{
asm|asm("" : [foo] "=r" (i), "=r"(i) : "1[foo]"(i));
comment|// expected-error{{invalid input constraint '1[foo]' in asm}}
asm|asm("" : [foo] "=r" (i), "=r"(i) : "[foo]1"(i));
comment|// expected-error{{invalid input constraint '[foo]1' in asm}}
block|}
end_function

begin_decl_stmt
specifier|register
name|int
name|g
name|asm
argument_list|(
literal|"dx"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{global register variables are not supported}}
end_comment

begin_function
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|g
name|asm
argument_list|(
literal|"g_asm"
argument_list|)
init|=
literal|0
decl_stmt|;
specifier|extern
name|int
name|gg
name|asm
argument_list|(
literal|"gg_asm"
argument_list|)
decl_stmt|;
name|__private_extern__
name|int
name|ggg
name|asm
argument_list|(
literal|"ggg_asm"
argument_list|)
decl_stmt|;
name|int
name|a
name|asm
argument_list|(
literal|"a_asm"
argument_list|)
decl_stmt|;
comment|// expected-warning{{ignored asm label 'a_asm' on automatic variable}}
specifier|auto
name|int
name|aa
name|asm
argument_list|(
literal|"aa_asm"
argument_list|)
decl_stmt|;
comment|// expected-warning{{ignored asm label 'aa_asm' on automatic variable}}
specifier|register
name|int
name|r
name|asm
argument_list|(
literal|"cx"
argument_list|)
decl_stmt|;
specifier|register
name|int
name|rr
name|asm
argument_list|(
literal|"rr_asm"
argument_list|)
decl_stmt|;
comment|// expected-error{{unknown register name 'rr_asm' in asm}}
block|}
end_function

end_unit

