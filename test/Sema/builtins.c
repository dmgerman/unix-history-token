begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify -pedantic -triple=i686-apple-darwin9
end_comment

begin_comment
comment|// This test needs to set the target because it uses __builtin_ia32_vec_ext_v4si
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|float
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|__builtin_isless
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test2
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|__builtin_islessequal
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// expected-error {{floating point type}}
block|}
end_function

begin_function
name|int
name|test3
parameter_list|(
name|double
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
return|return
name|__builtin_isless
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test4
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
return|return
name|__builtin_islessequal
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// expected-error {{floating point type}}
block|}
end_function

begin_function
name|int
name|test5
parameter_list|(
name|float
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
return|return
name|__builtin_isless
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|b
argument_list|)
return|;
comment|// expected-error {{too many arguments}}
block|}
end_function

begin_function
name|int
name|test6
parameter_list|(
name|float
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
return|return
name|__builtin_islessequal
argument_list|(
name|a
argument_list|)
return|;
comment|// expected-error {{too few arguments}}
block|}
end_function

begin_define
define|#
directive|define
name|CFSTR
value|__builtin___CFStringMakeConstantString
end_define

begin_function
name|void
name|test7
parameter_list|()
block|{
name|CFSTR
argument_list|(
literal|"\242"
argument_list|)
expr_stmt|;
name|CFSTR
argument_list|(
literal|"\0"
argument_list|)
expr_stmt|;
comment|// expected-warning {{ CFString literal contains NUL character }}
name|CFSTR
argument_list|(
literal|242
argument_list|)
expr_stmt|;
comment|// expected-error {{ CFString literal is not a string constant }} expected-warning {{incompatible integer to pointer conversion}}
name|CFSTR
argument_list|(
literal|"foo"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
comment|// expected-error {{too many arguments to function call}}
block|}
end_function

begin_comment
comment|// atomics.
end_comment

begin_function
name|void
name|test9
parameter_list|(
name|short
name|v
parameter_list|)
block|{
name|unsigned
name|i
decl_stmt|,
name|old
decl_stmt|;
name|old
operator|=
name|__sync_fetch_and_add
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call}}
name|old
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|old
argument_list|)
expr_stmt|;
comment|// expected-error {{too few arguments to function call}}
name|old
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|(
name|int
operator|*
operator|*
operator|)
literal|0
argument_list|,
literal|42i
argument_list|)
expr_stmt|;
comment|// expected-warning {{imaginary constants are an extension}}
block|}
end_function

begin_comment
comment|// rdar://7236819
end_comment

begin_function_decl
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__("int3");
name|__builtin_unreachable
argument_list|()
expr_stmt|;
comment|// No warning about falling off the end of a noreturn function.
block|}
end_function

begin_function
name|void
name|test11
parameter_list|(
name|int
name|X
parameter_list|)
block|{
switch|switch
condition|(
name|X
condition|)
block|{
case|case
name|__builtin_eh_return_data_regno
argument_list|(
literal|0
argument_list|)
case|:
comment|// constant foldable.
break|break;
block|}
name|__builtin_eh_return_data_regno
argument_list|(
name|X
argument_list|)
expr_stmt|;
comment|// expected-error {{not an integer constant expression}}
block|}
end_function

begin_comment
comment|// PR5062
end_comment

begin_function_decl
name|void
name|test12
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test12
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_trap
argument_list|()
expr_stmt|;
comment|// no warning because trap is noreturn.
block|}
end_function

begin_function
name|void
name|test_unknown_builtin
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|__builtin_foo
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// expected-error{{use of unknown builtin}}
block|}
end_function

end_unit

