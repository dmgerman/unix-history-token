begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -pedantic -Wno-string-plus-int -triple=i686-apple-darwin9
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
specifier|const
name|void
modifier|*
name|X
decl_stmt|;
name|X
operator|=
name|CFSTR
argument_list|(
literal|"\242"
argument_list|)
expr_stmt|;
comment|// expected-warning {{input conversion stopped}}
name|X
operator|=
name|CFSTR
argument_list|(
literal|"\0"
argument_list|)
expr_stmt|;
comment|// no-warning
name|X
operator|=
name|CFSTR
argument_list|(
literal|242
argument_list|)
expr_stmt|;
comment|// expected-error {{CFString literal is not a string constant}} expected-warning {{incompatible integer to pointer conversion}}
name|X
operator|=
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
name|unsigned
operator|*
operator|)
literal|0
argument_list|,
literal|42i
argument_list|)
expr_stmt|;
comment|// expected-warning {{imaginary constants are a GNU extension}}
comment|// PR7600: Pointers are implicitly casted to integers and back.
name|void
modifier|*
name|old_ptr
init|=
name|__sync_val_compare_and_swap
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
comment|// Ensure the return type is correct even when implicit casts are stripped
comment|// away. This triggers an assertion while checking the comparison otherwise.
if|if
condition|(
name|__sync_fetch_and_add
argument_list|(
operator|&
name|old
argument_list|,
literal|1
argument_list|)
operator|==
literal|1
condition|)
block|{   }
block|}
end_function

begin_comment
comment|// overloaded atomics should be declared only once.
end_comment

begin_function
name|void
name|test9_1
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|val
parameter_list|)
block|{
name|__sync_fetch_and_add_4
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test9_2
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|val
parameter_list|)
block|{
name|__sync_fetch_and_add
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test9_3
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|val
parameter_list|)
block|{
name|__sync_fetch_and_add_4
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|__sync_fetch_and_add
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|__sync_fetch_and_add
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|__sync_fetch_and_add_4
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|__sync_fetch_and_add_4
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
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
comment|// expected-error {{argument to '__builtin_eh_return_data_regno' must be a constant integer}}
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
name|__builtin_isles
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// expected-error{{use of unknown builtin}} \
comment|// expected-note{{did you mean '__builtin_isless'?}}
block|}
end_function

begin_function
name|int
name|test13
parameter_list|()
block|{
name|__builtin_eh_return
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// no warning, eh_return never returns.
block|}
end_function

begin_comment
comment|//<rdar://problem/8228293>
end_comment

begin_function
name|void
name|test14
parameter_list|()
block|{
name|int
name|old
decl_stmt|;
name|old
operator|=
name|__sync_fetch_and_min
argument_list|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
operator|&
name|old
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//<rdar://problem/8336581>
end_comment

begin_function
name|void
name|test15
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|__builtin_printf
argument_list|(
literal|"string is %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR7885
end_comment

begin_function
name|int
name|test16
parameter_list|()
block|{
return|return
name|__builtin_constant_p
argument_list|()
operator|+
comment|// expected-error{{too few arguments}}
name|__builtin_constant_p
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
return|;
comment|// expected-error {{too many arguments}}
block|}
end_function

begin_decl_stmt
specifier|const
name|int
name|test17_n
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|test17_c
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|test17_d
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|IntVector
typedef|;
end_typedef

begin_struct
struct|struct
name|Aggregate
block|{
name|int
name|n
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|Enum
block|{
name|EnumValue1
block|,
name|EnumValue2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test17
parameter_list|()
block|{
define|#
directive|define
name|ASSERT
parameter_list|(
modifier|...
parameter_list|)
value|{ int arr[(__VA_ARGS__) ? 1 : -1]; }
define|#
directive|define
name|T
parameter_list|(
modifier|...
parameter_list|)
value|ASSERT(__builtin_constant_p(__VA_ARGS__))
define|#
directive|define
name|F
parameter_list|(
modifier|...
parameter_list|)
value|ASSERT(!__builtin_constant_p(__VA_ARGS__))
comment|// __builtin_constant_p returns 1 if the argument folds to:
comment|//  - an arithmetic constant with value which is known at compile time
name|T
argument_list|(
name|test17_n
argument_list|)
expr_stmt|;
name|T
argument_list|(
operator|&
name|test17_c
index|[
literal|3
index|]
operator|-
name|test17_c
argument_list|)
expr_stmt|;
name|T
argument_list|(
literal|3i + 5
argument_list|)
expr_stmt|;
comment|// expected-warning {{imaginary constant}}
name|T
argument_list|(
literal|4.2
operator|*
literal|7.6
argument_list|)
expr_stmt|;
name|T
argument_list|(
name|EnumValue1
argument_list|)
expr_stmt|;
name|T
argument_list|(
operator|(
expr|enum
name|Enum
operator|)
operator|(
name|int
operator|)
name|EnumValue2
argument_list|)
expr_stmt|;
comment|//  - the address of the first character of a string literal, losslessly cast
comment|//    to any type
name|T
argument_list|(
literal|"string literal"
argument_list|)
expr_stmt|;
name|T
argument_list|(
operator|(
name|double
operator|*
operator|)
literal|"string literal"
argument_list|)
expr_stmt|;
name|T
argument_list|(
literal|"string literal"
operator|+
literal|0
argument_list|)
expr_stmt|;
name|T
argument_list|(
operator|(
name|long
operator|)
literal|"string literal"
argument_list|)
expr_stmt|;
comment|// ... and otherwise returns 0.
name|F
argument_list|(
literal|"string literal"
operator|+
literal|1
argument_list|)
expr_stmt|;
name|F
argument_list|(
operator|&
name|test17_n
argument_list|)
expr_stmt|;
name|F
argument_list|(
name|test17_c
argument_list|)
expr_stmt|;
name|F
argument_list|(
operator|&
name|test17_c
argument_list|)
expr_stmt|;
name|F
argument_list|(
operator|&
name|test17_d
argument_list|)
expr_stmt|;
name|F
argument_list|(
operator|(
expr|struct
name|Aggregate
operator|)
block|{
literal|0
block|,
literal|1
block|}
argument_list|)
expr_stmt|;
name|F
argument_list|(
operator|(
name|IntVector
operator|)
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|}
argument_list|)
expr_stmt|;
comment|// Ensure that a technique used in glibc is handled correctly.
define|#
directive|define
name|OPT
parameter_list|(
modifier|...
parameter_list|)
value|(__builtin_constant_p(__VA_ARGS__)&& strlen(__VA_ARGS__)< 4)
comment|// FIXME: These are incorrectly treated as ICEs because strlen is treated as
comment|// a builtin.
name|ASSERT
argument_list|(
name|OPT
argument_list|(
literal|"abc"
argument_list|)
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|!
name|OPT
argument_list|(
literal|"abcd"
argument_list|)
argument_list|)
expr_stmt|;
comment|// In these cases, the strlen is non-constant, but the __builtin_constant_p
comment|// is 0: the array size is not an ICE but is foldable.
name|ASSERT
argument_list|(
operator|!
name|OPT
argument_list|(
name|test17_c
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{folded}}
name|ASSERT
argument_list|(
operator|!
name|OPT
argument_list|(
operator|&
name|test17_c
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{folded}}
name|ASSERT
argument_list|(
operator|!
name|OPT
argument_list|(
operator|(
name|char
operator|*
operator|)
name|test17_c
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{folded}}
name|ASSERT
argument_list|(
operator|!
name|OPT
argument_list|(
name|test17_d
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{folded}}
name|ASSERT
argument_list|(
operator|!
name|OPT
argument_list|(
operator|&
name|test17_d
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{folded}}
name|ASSERT
argument_list|(
operator|!
name|OPT
argument_list|(
operator|(
name|char
operator|*
operator|)
name|test17_d
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{folded}}
undef|#
directive|undef
name|OPT
undef|#
directive|undef
name|T
undef|#
directive|undef
name|F
block|}
end_function

end_unit

