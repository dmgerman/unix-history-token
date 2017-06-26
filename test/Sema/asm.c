begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Wno-private-extern -triple i386-pc-linux-gnu -verify -fsyntax-only
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
asm|asm ("foo\n" : : "" (i));
comment|// expected-error {{invalid input constraint '' in asm}}
asm|asm ("foo\n" : "=a" (i) : "" (i));
comment|// expected-error {{invalid input constraint '' in asm}}
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
asm|asm ("nop" : : : "204");
comment|// expected-error {{unknown register name '204' in asm}}
asm|asm ("nop" : : : "-1");
comment|// expected-error {{unknown register name '-1' in asm}}
asm|asm ("nop" : : : "+1");
comment|// expected-error {{unknown register name '+1' in asm}}
specifier|register
name|void
modifier|*
name|clobber_conflict
name|asm
argument_list|(
literal|"%rcx"
argument_list|)
decl_stmt|;
specifier|register
name|void
modifier|*
name|no_clobber_conflict
name|asm
argument_list|(
literal|"%rax"
argument_list|)
decl_stmt|;
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
asm|asm ("nop" : "=r" (no_clobber_conflict) : "r" (clobber_conflict) : "%rcx");
comment|// expected-error {{asm-specifier for input or output variable conflicts with asm clobber list}}
asm|asm ("nop" : "=r" (clobber_conflict) : "r" (no_clobber_conflict) : "%rcx");
comment|// expected-error {{asm-specifier for input or output variable conflicts with asm clobber list}}
asm|asm ("nop" : "=r" (clobber_conflict) : "r" (clobber_conflict) : "%rcx");
comment|// expected-error {{asm-specifier for input or output variable conflicts with asm clobber list}}
asm|asm ("nop" : "=c" (a) : "r" (no_clobber_conflict) : "%rcx");
comment|// expected-error {{asm-specifier for input or output variable conflicts with asm clobber list}}
asm|asm ("nop" : "=r" (no_clobber_conflict) : "c" (c) : "%rcx");
comment|// expected-error {{asm-specifier for input or output variable conflicts with asm clobber list}}
asm|asm ("nop" : "=r" (clobber_conflict) : "c" (c) : "%rcx");
comment|// expected-error {{asm-specifier for input or output variable conflicts with asm clobber list}}
asm|asm ("nop" : "=a" (a) : "b" (b) : "%rcx", "%rbx");
comment|// expected-error {{asm-specifier for input or output variable conflicts with asm clobber list}}
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
specifier|register
name|int
name|rrr
name|asm
argument_list|(
literal|"%"
argument_list|)
decl_stmt|;
comment|// expected-error{{unknown register name '%' in asm}}
block|}
end_function

begin_comment
comment|// This is just an assert because of the boolean conversion.
end_comment

begin_comment
comment|// Feel free to change the assembly to something sensible if it causes a problem.
end_comment

begin_comment
comment|// rdar://problem/9414925
end_comment

begin_function
name|void
name|test11
parameter_list|(
name|void
parameter_list|)
block|{
name|_Bool
name|b
decl_stmt|;
asm|asm
specifier|volatile
asm|("movb %%gs:%P2,%b0" : "=q"(b) : "0"(0), "i"(5L));
block|}
end_function

begin_function
name|void
name|test12
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|int
name|cc
asm|__asm ("cc");
comment|// expected-error{{unknown register name 'cc' in asm}}
block|}
end_function

begin_comment
comment|// PR10223
end_comment

begin_function
name|void
name|test13
parameter_list|(
name|void
parameter_list|)
block|{
name|void
modifier|*
name|esp
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("mov %%esp, %o" : "=r"(esp) : : );
comment|// expected-error {{invalid % escape in inline assembly string}}
block|}
end_function

begin_comment
comment|//<rdar://problem/12700799>
end_comment

begin_struct_decl
struct_decl|struct
name|S
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note 2 {{forward declaration of 'struct S'}}
end_comment

begin_function
name|void
name|test14
parameter_list|(
name|struct
name|S
modifier|*
name|s
parameter_list|)
block|{
asm|__asm("": : "a"(*s));
comment|// expected-error {{dereference of pointer to incomplete type 'struct S'}}
asm|__asm("": "=a" (*s) :);
comment|// expected-error {{dereference of pointer to incomplete type 'struct S'}}
block|}
end_function

begin_comment
comment|// PR15759.
end_comment

begin_function
name|double
name|test15
parameter_list|()
block|{
name|double
name|ret
init|=
literal|0
decl_stmt|;
asm|__asm("0.0":"="(ret));
comment|// expected-error {{invalid output constraint '=' in asm}}
asm|__asm("0.0":"=&"(ret));
comment|// expected-error {{invalid output constraint '=&' in asm}}
asm|__asm("0.0":"+?"(ret));
comment|// expected-error {{invalid output constraint '+?' in asm}}
asm|__asm("0.0":"+!"(ret));
comment|// expected-error {{invalid output constraint '+!' in asm}}
asm|__asm("0.0":"+#"(ret));
comment|// expected-error {{invalid output constraint '+#' in asm}}
asm|__asm("0.0":"+*"(ret));
comment|// expected-error {{invalid output constraint '+*' in asm}}
asm|__asm("0.0":"=%"(ret));
comment|// expected-error {{invalid output constraint '=%' in asm}}
asm|__asm("0.0":"=,="(ret));
comment|// expected-error {{invalid output constraint '=,=' in asm}}
asm|__asm("0.0":"=,g"(ret));
comment|// no-error
asm|__asm("0.0":"=g"(ret));
comment|// no-error
return|return
name|ret
return|;
block|}
end_function

begin_function
name|void
name|iOutputConstraint
parameter_list|(
name|int
name|x
parameter_list|)
block|{
asm|__asm ("nop" : "=ir" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=ri" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=ig" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=im" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=imr" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=i" (x) : :);
comment|// expected-error{{invalid output constraint '=i' in asm}}
asm|__asm ("nop" : "+i" (x) : :);
comment|// expected-error{{invalid output constraint '+i' in asm}}
asm|__asm ("nop" : "=ii" (x) : :);
comment|// expected-error{{invalid output constraint '=ii' in asm}}
asm|__asm ("nop" : "=nr" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=rn" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=ng" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=nm" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=nmr" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=n" (x) : :);
comment|// expected-error{{invalid output constraint '=n' in asm}}
asm|__asm ("nop" : "+n" (x) : :);
comment|// expected-error{{invalid output constraint '+n' in asm}}
asm|__asm ("nop" : "=nn" (x) : :);
comment|// expected-error{{invalid output constraint '=nn' in asm}}
asm|__asm ("nop" : "=Fr" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=rF" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=Fg" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=Fm" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=Fmr" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=F" (x) : :);
comment|// expected-error{{invalid output constraint '=F' in asm}}
asm|__asm ("nop" : "+F" (x) : :);
comment|// expected-error{{invalid output constraint '+F' in asm}}
asm|__asm ("nop" : "=FF" (x) : :);
comment|// expected-error{{invalid output constraint '=FF' in asm}}
asm|__asm ("nop" : "=Er" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=rE" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=Eg" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=Em" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=Emr" (x) : :);
comment|// no-error
asm|__asm ("nop" : "=E" (x) : :);
comment|// expected-error{{invalid output constraint '=E' in asm}}
asm|__asm ("nop" : "+E" (x) : :);
comment|// expected-error{{invalid output constraint '+E' in asm}}
asm|__asm ("nop" : "=EE" (x) : :);
comment|// expected-error{{invalid output constraint '=EE' in asm}}
block|}
end_function

begin_comment
comment|// PR19837
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|register
name|struct
name|foo
name|bar
name|asm
argument_list|(
literal|"esp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{bad type for named register variable}}
end_comment

begin_decl_stmt
specifier|register
name|float
name|baz
name|asm
argument_list|(
literal|"esp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{bad type for named register variable}}
end_comment

begin_decl_stmt
specifier|register
name|int
name|r0
name|asm
argument_list|(
literal|"edi"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{register 'edi' unsuitable for global register variables on this target}}
end_comment

begin_decl_stmt
specifier|register
name|long
name|long
name|r1
name|asm
argument_list|(
literal|"esp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{size of register 'esp' does not match variable size}}
end_comment

begin_decl_stmt
specifier|register
name|int
name|r2
name|asm
argument_list|(
literal|"esp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|f_output_constraint
parameter_list|(
name|void
parameter_list|)
block|{
name|double
name|result
decl_stmt|;
asm|__asm("foo1": "=f" (result));
comment|// expected-error {{invalid output constraint '=f' in asm}}
return|return
name|result
return|;
block|}
end_function

begin_function
name|void
name|fn1
parameter_list|()
block|{
name|int
name|l
decl_stmt|;
asm|__asm__(""           : [l] "=r"(l)           : "[l],m"(l));
comment|// expected-error {{asm constraint has an unexpected number of alternatives: 1 vs 2}}
block|}
end_function

begin_function
name|void
name|fn2
parameter_list|()
block|{
name|int
name|l
decl_stmt|;
asm|__asm__(""           : "+&m"(l));
comment|// expected-error {{invalid output constraint '+&m' in asm}}
block|}
end_function

begin_function
name|void
name|fn3
parameter_list|()
block|{
name|int
name|l
decl_stmt|;
asm|__asm__(""           : "+#r"(l));
comment|// expected-error {{invalid output constraint '+#r' in asm}}
block|}
end_function

begin_function
name|void
name|fn4
parameter_list|()
block|{
name|int
name|l
decl_stmt|;
asm|__asm__(""           : "=r"(l)           : "m#"(l));
block|}
end_function

begin_function
name|void
name|fn5
parameter_list|()
block|{
name|int
name|l
decl_stmt|;
asm|__asm__(""           : [g] "+r"(l)           : "[g]"(l));
comment|// expected-error {{invalid input constraint '[g]' in asm}}
block|}
end_function

begin_function
name|void
name|fn6
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
asm|__asm__(""             : "=rm"(a), "=rm"(a)             : "11m"(a))
comment|// expected-error {{invalid input constraint '11m' in asm}}
block|}
end_function

begin_comment
comment|// PR14269
end_comment

begin_typedef
typedef|typedef
struct|struct
name|test16_foo
block|{
name|unsigned
name|int
name|field1
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|field2
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|field3
range|:
literal|3
decl_stmt|;
block|}
name|test16_foo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|int
name|test16_bar
typedef|;
end_typedef

begin_decl_stmt
specifier|register
name|int
name|test16_baz
name|asm
argument_list|(
literal|"esp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test16
parameter_list|()
block|{
name|test16_foo
name|a
decl_stmt|;
name|test16_bar
name|b
decl_stmt|;
asm|__asm__("movl $5, %0"           : "=rm" (a.field2));
comment|// expected-error {{reference to a bit-field in asm input with a memory constraint '=rm'}}
asm|__asm__("movl $5, %0"           :           : "m" (a.field3));
comment|// expected-error {{reference to a bit-field in asm output with a memory constraint 'm'}}
asm|__asm__("movl $5, %0"           : "=rm" (b[2]));
comment|// expected-error {{reference to a vector element in asm input with a memory constraint '=rm'}}
asm|__asm__("movl $5, %0"           :           : "m" (b[3]));
comment|// expected-error {{reference to a vector element in asm output with a memory constraint 'm'}}
asm|__asm__("movl $5, %0"           : "=rm" (test16_baz));
comment|// expected-error {{reference to a global register variable in asm input with a memory constraint '=rm'}}
asm|__asm__("movl $5, %0"           :           : "m" (test16_baz));
comment|// expected-error {{reference to a global register variable in asm output with a memory constraint 'm'}}
block|}
end_function

begin_function
name|int
name|test17
parameter_list|(
name|int
name|t0
parameter_list|)
block|{
name|int
name|r0
decl_stmt|,
name|r1
decl_stmt|;
asm|__asm ("addl %2, %2\n\t"
literal|"movl $123, %0"
operator|:
literal|"=a"
operator|(
name|r0
operator|)
operator|,
literal|"=&r"
operator|(
name|r1
operator|)
operator|:
literal|"1"
operator|(
name|t0
operator|)
operator|,
comment|// expected-note {{constraint '1' is already present here}}
literal|"1"
operator|(
name|t0
operator|)
block|)
function|;
end_function

begin_comment
comment|// expected-error {{more than one input constraint matches the same output '1'}}
end_comment

begin_return
return|return
name|r0
operator|+
name|r1
return|;
end_return

unit|}
end_unit

