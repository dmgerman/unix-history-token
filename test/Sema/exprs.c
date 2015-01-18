begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only
end_comment

begin_comment
comment|// PR 8876 - don't warn about trivially unreachable null derefs.  Note that
end_comment

begin_comment
comment|// we put this here because the reachability analysis only kicks in for
end_comment

begin_comment
comment|// suppressing false positives when code has no errors.
end_comment

begin_define
define|#
directive|define
name|PR8876
parameter_list|(
name|err_ptr
parameter_list|)
value|do {\     if (err_ptr) *(int*)(err_ptr) = 1;\   } while (0)
end_define

begin_define
define|#
directive|define
name|PR8876_pos
parameter_list|(
name|err_ptr
parameter_list|)
value|do {\     if (!err_ptr) *(int*)(err_ptr) = 1;\   } while (0)
end_define

begin_comment
comment|// Test that we don't report divide-by-zero errors in unreachable code.
end_comment

begin_comment
comment|// This test should be left as is, as it also tests CFG functionality.
end_comment

begin_function
name|void
name|radar9171946
parameter_list|()
block|{
if|if
condition|(
literal|0
condition|)
block|{
literal|0
operator|/
operator|(
literal|0
condition|?
literal|1
else|:
literal|0
operator|)
expr_stmt|;
comment|// expected-warning {{expression result unused}}
block|}
block|}
end_function

begin_function
name|int
name|test_pr8876
parameter_list|()
block|{
name|PR8876
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|PR8876_pos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{indirection of non-volatile null pointer will be deleted, not trap}} expected-note{{consider using __builtin_trap() or qualifying pointer with 'volatile'}}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PR 8183 - Handle null pointer constants on the left-side of the '&&', and reason about
end_comment

begin_comment
comment|// this when determining the reachability of the null pointer dereference on the right side.
end_comment

begin_function
name|void
name|pr8183
parameter_list|(
name|unsigned
name|long
name|long
name|test
parameter_list|)
block|{
call|(
name|void
call|)
argument_list|(
operator|(
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
operator|)
operator|&&
operator|(
operator|*
operator|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
operator|(
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
operator|)
operator|)
operator|=
operator|(
call|(
name|unsigned
name|long
name|long
call|)
argument_list|(
operator|(
name|test
operator|)
argument_list|)
operator|%
call|(
name|unsigned
name|long
name|long
call|)
argument_list|(
operator|(
literal|1000000000
operator|)
argument_list|)
operator|)
operator|)
argument_list|)
expr_stmt|;
comment|// no-warning
operator|(
operator|*
operator|(
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
operator|(
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
operator|)
operator|)
operator|=
operator|(
call|(
name|unsigned
name|long
name|long
call|)
argument_list|(
operator|(
name|test
operator|)
argument_list|)
operator|%
call|(
name|unsigned
name|long
name|long
call|)
argument_list|(
operator|(
literal|1000000000
operator|)
argument_list|)
operator|)
operator|)
expr_stmt|;
comment|// expected-warning {{indirection of non-volatile null pointer will be deleted, not trap}} expected-note {{consider using __builtin_trap() or qualifying pointer with 'volatile'}}
block|}
end_function

begin_comment
comment|// PR1966
end_comment

begin_function
specifier|_Complex
name|double
name|test1
parameter_list|()
block|{
return|return
name|__extension__
literal|1.0if
return|;
block|}
end_function

begin_function
specifier|_Complex
name|double
name|test2
parameter_list|()
block|{
return|return
literal|1.0if
return|;
comment|// expected-warning {{imaginary constants are a GNU extension}}
block|}
end_function

begin_comment
comment|// rdar://6097308
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
operator|(
name|__extension__
name|x
operator|)
operator|=
literal|10
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6162726
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
specifier|static
name|int
name|var
decl_stmt|;
name|var
operator|=
operator|+
literal|5
expr_stmt|;
comment|// expected-warning {{use of unary operator that may be intended as compound assignment (+=)}}
name|var
operator|=
operator|-
literal|5
expr_stmt|;
comment|// expected-warning {{use of unary operator that may be intended as compound assignment (-=)}}
name|var
operator|=
operator|+
literal|5
expr_stmt|;
comment|// no warning when space between the = and +.
name|var
operator|=
operator|-
literal|5
expr_stmt|;
name|var
operator|=
operator|+
literal|5
expr_stmt|;
comment|// no warning when the subexpr of the unary op has no space before it.
name|var
operator|=
operator|-
literal|5
expr_stmt|;
define|#
directive|define
name|FIVE
value|5
name|var
operator|=
operator|-
name|FIVE
expr_stmt|;
comment|// no warning with macros.
name|var
operator|=
operator|-
name|FIVE
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6319320
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|int
modifier|*
name|X
parameter_list|,
name|float
modifier|*
name|P
parameter_list|)
block|{
operator|(
name|float
operator|*
operator|)
name|X
operator|=
name|P
expr_stmt|;
comment|// expected-error {{assignment to cast is illegal, lvalue casts are not supported}}
define|#
directive|define
name|FOO
value|((float*) X)
name|FOO
operator|=
name|P
expr_stmt|;
comment|// expected-error {{assignment to cast is illegal, lvalue casts are not supported}}
block|}
end_function

begin_function
name|void
name|test6
parameter_list|()
block|{
name|int
name|X
decl_stmt|;
name|X
argument_list|()
expr_stmt|;
comment|// expected-error {{called object type 'int' is not a function or function pointer}}
block|}
end_function

begin_function
name|void
name|test7
parameter_list|(
name|int
modifier|*
name|P
parameter_list|,
specifier|_Complex
name|float
name|Gamma
parameter_list|)
block|{
name|P
operator|=
operator|(
name|P
operator|-
literal|42
operator|)
operator|+
name|Gamma
operator|*
literal|4
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression ('int *' and '_Complex float')}}
block|}
end_function

begin_comment
comment|// rdar://6095061
end_comment

begin_function
name|int
name|test8
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|__builtin_choose_expr
argument_list|(
literal|0
argument_list|,
literal|42
argument_list|,
name|i
argument_list|)
operator|=
literal|10
expr_stmt|;
return|return
name|i
return|;
block|}
end_function

begin_comment
comment|// PR3386
end_comment

begin_struct
struct|struct
name|f
block|{
name|int
name|x
range|:
literal|4
decl_stmt|;
name|float
name|y
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|test9
parameter_list|(
name|struct
name|f
modifier|*
name|P
parameter_list|)
block|{
name|int
name|R
decl_stmt|;
name|R
operator|=
name|__alignof
argument_list|(
name|P
operator|->
name|x
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid application of 'alignof' to bit-field}}
name|R
operator|=
name|__alignof
argument_list|(
name|P
operator|->
name|y
argument_list|)
expr_stmt|;
comment|// ok.
name|R
operator|=
sizeof|sizeof
argument_list|(
name|P
operator|->
name|x
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid application of 'sizeof' to bit-field}}
return|return
name|R
return|;
block|}
end_function

begin_comment
comment|// PR3562
end_comment

begin_function
name|void
name|test10
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
struct|struct
name|S
block|{
name|double
name|a
index|[
name|n
index|]
decl_stmt|;
comment|// expected-error {{fields must have a constant size}}
block|}
name|s
struct|;
name|double
name|x
init|=
name|s
operator|.
name|a
index|[
literal|0
index|]
decl_stmt|;
comment|// should not get another error here.
block|}
end_function

begin_define
define|#
directive|define
name|MYMAX
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|__extension__ ({ __typeof__(A) __a = (A); __typeof__(B) __b = (B); __a< __b ? __b : __a; })
end_define

begin_struct
struct|struct
name|mystruct
block|{
name|int
name|A
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test11
parameter_list|(
name|struct
name|mystruct
name|P
parameter_list|,
name|float
name|F
parameter_list|)
block|{
name|MYMAX
argument_list|(
name|P
argument_list|,
name|F
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression ('typeof (P)' (aka 'struct mystruct') and 'typeof (F)' (aka 'float'))}}
block|}
end_function

begin_comment
comment|// PR3753
end_comment

begin_function
name|int
name|test12
parameter_list|(
specifier|const
name|char
modifier|*
name|X
parameter_list|)
block|{
return|return
name|X
operator|==
literal|"foo"
return|;
comment|// expected-warning {{comparison against a string literal is unspecified (use strncmp instead)}}
block|}
end_function

begin_function
name|int
name|test12b
parameter_list|(
specifier|const
name|char
modifier|*
name|X
parameter_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|X
operator|==
literal|"foo"
argument_list|)
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// rdar://6719156
end_comment

begin_function
name|void
name|test13
parameter_list|(
name|void
function_decl|(
modifier|^
name|P
function_decl|)
parameter_list|()
parameter_list|)
block|{
comment|// expected-error {{blocks support disabled - compile with -fblocks}}
name|P
argument_list|()
expr_stmt|;
name|P
operator|=
lambda|^
parameter_list|()
block|{}
expr_stmt|;
comment|// expected-error {{blocks support disabled - compile with -fblocks}}
block|}
end_function

begin_function
name|void
name|test14
parameter_list|()
block|{
typedef|typedef
name|long
name|long
name|__m64
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
typedef|typedef
name|short
name|__v4hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
comment|// Ok.
name|__v4hi
name|a
decl_stmt|;
name|__m64
name|mask
init|=
call|(
name|__m64
call|)
argument_list|(
operator|(
name|__v4hi
operator|)
name|a
operator|>
operator|(
name|__v4hi
operator|)
name|a
argument_list|)
decl_stmt|;
block|}
end_function

begin_comment
comment|// PR5242
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
modifier|*
name|test15_t
typedef|;
end_typedef

begin_function
name|test15_t
name|test15
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|test15_t
operator|)
literal|0
operator|+
operator|(
name|test15_t
operator|)
literal|0
return|;
comment|// expected-error {{invalid operands to binary expression ('test15_t' (aka 'unsigned long *') and 'test15_t')}}
block|}
end_function

begin_comment
comment|// rdar://7446395
end_comment

begin_function
name|void
name|test16
parameter_list|(
name|float
name|x
parameter_list|)
block|{
name|x
operator|==
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{invalid operands to binary expression}}
end_comment

begin_comment
comment|// PR6004
end_comment

begin_function
name|void
name|test17
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|x
operator|=
name|x
operator|/
literal|0
expr_stmt|;
comment|// expected-warning {{division by zero is undefined}}
name|x
operator|=
name|x
operator|%
literal|0
expr_stmt|;
comment|// expected-warning {{remainder by zero is undefined}}
name|x
operator|/=
literal|0
expr_stmt|;
comment|// expected-warning {{division by zero is undefined}}
name|x
operator|%=
literal|0
expr_stmt|;
comment|// expected-warning {{remainder by zero is undefined}}
name|x
operator|=
sizeof|sizeof
argument_list|(
name|x
operator|/
literal|0
argument_list|)
expr_stmt|;
comment|// no warning.
block|}
end_function

begin_comment
comment|// PR6501& PR11857
end_comment

begin_function_decl
name|void
name|test18_a
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note 2 {{'test18_a' declared here}}
end_comment

begin_function_decl
name|void
name|test18_b
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'test18_b' declared here}}
end_comment

begin_function_decl
name|void
name|test18_c
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note 2 {{'test18_c' declared here}}
end_comment

begin_function_decl
name|void
name|test18_d
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'test18_d' declared here}}
end_comment

begin_function_decl
name|void
name|test18_e
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'test18_e' declared here}}
end_comment

begin_function
name|void
name|test18
parameter_list|(
name|int
name|b
parameter_list|)
block|{
name|test18_a
argument_list|(
name|b
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// expected-error {{too many arguments to function call, expected single argument 'a', have 2}}
name|test18_a
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call, single argument 'a' was not specified}}
name|test18_b
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call, expected 1, have 0}}
name|test18_c
argument_list|(
name|b
argument_list|)
expr_stmt|;
comment|// expected-error {{too few arguments to function call, expected 2, have 1}}
name|test18_c
argument_list|(
name|b
argument_list|,
name|b
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// expected-error {{too many arguments to function call, expected 2, have 3}}
name|test18_d
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call, at least argument 'a' must be specified}}
name|test18_e
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call, expected at least 2, have 0}}
block|}
end_function

begin_comment
comment|// PR7569
end_comment

begin_function
name|void
name|test19
parameter_list|()
block|{
operator|*
operator|(
name|int
operator|*
operator|)
literal|0
operator|=
literal|0
expr_stmt|;
comment|// expected-warning {{indirection of non-volatile null pointer}} \
comment|// expected-note {{consider using __builtin_trap}}
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
literal|0
operator|=
literal|0
expr_stmt|;
comment|// Ok.
comment|// rdar://9269271
name|int
name|x
init|=
operator|*
operator|(
name|int
operator|*
operator|)
literal|0
decl_stmt|;
comment|// expected-warning {{indirection of non-volatile null pointer}} \
comment|// expected-note {{consider using __builtin_trap}}
name|int
name|x2
init|=
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
literal|0
decl_stmt|;
comment|// Ok.
name|int
modifier|*
name|p
init|=
operator|&
operator|(
operator|*
operator|(
name|int
operator|*
operator|)
literal|0
operator|)
decl_stmt|;
comment|// Ok;
block|}
end_function

begin_function
name|int
name|test20
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|&&
literal|4
return|;
comment|// expected-warning {{use of logical '&&' with constant operand}} \
comment|// expected-note {{use '&' for a bitwise operation}} \
comment|// expected-note {{remove constant to silence this warning}}
return|return
name|x
operator|&&
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|==
literal|4
return|;
comment|// no warning, RHS is logical op.
comment|// no warning, this is an idiom for "true" in old C style.
return|return
name|x
operator|&&
operator|(
name|signed
name|char
operator|)
literal|1
return|;
return|return
name|x
operator|||
literal|0
return|;
return|return
name|x
operator|||
literal|1
return|;
return|return
name|x
operator|||
operator|-
literal|1
return|;
comment|// expected-warning {{use of logical '||' with constant operand}} \
comment|// expected-note {{use '|' for a bitwise operation}}
return|return
name|x
operator|||
literal|5
return|;
comment|// expected-warning {{use of logical '||' with constant operand}} \
comment|// expected-note {{use '|' for a bitwise operation}}
return|return
name|x
operator|&&
literal|0
return|;
return|return
name|x
operator|&&
literal|1
return|;
return|return
name|x
operator|&&
operator|-
literal|1
return|;
comment|// expected-warning {{use of logical '&&' with constant operand}} \
comment|// expected-note {{use '&' for a bitwise operation}} \
comment|// expected-note {{remove constant to silence this warning}}
return|return
name|x
operator|&&
literal|5
return|;
comment|// expected-warning {{use of logical '&&' with constant operand}} \
comment|// expected-note {{use '&' for a bitwise operation}} \
comment|// expected-note {{remove constant to silence this warning}}
return|return
name|x
operator|||
operator|(
literal|0
operator|)
return|;
return|return
name|x
operator|||
operator|(
literal|1
operator|)
return|;
return|return
name|x
operator|||
operator|(
operator|-
literal|1
operator|)
return|;
comment|// expected-warning {{use of logical '||' with constant operand}} \
comment|// expected-note {{use '|' for a bitwise operation}}
return|return
name|x
operator|||
operator|(
literal|5
operator|)
return|;
comment|// expected-warning {{use of logical '||' with constant operand}} \
comment|// expected-note {{use '|' for a bitwise operation}}
return|return
name|x
operator|&&
operator|(
literal|0
operator|)
return|;
return|return
name|x
operator|&&
operator|(
literal|1
operator|)
return|;
return|return
name|x
operator|&&
operator|(
operator|-
literal|1
operator|)
return|;
comment|// expected-warning {{use of logical '&&' with constant operand}} \
comment|// expected-note {{use '&' for a bitwise operation}} \
comment|// expected-note {{remove constant to silence this warning}}
return|return
name|x
operator|&&
operator|(
literal|5
operator|)
return|;
comment|// expected-warning {{use of logical '&&' with constant operand}} \
comment|// expected-note {{use '&' for a bitwise operation}} \
comment|// expected-note {{remove constant to silence this warning}}
block|}
end_function

begin_struct_decl
struct_decl|struct
name|Test21
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note 2 {{forward declaration}}
end_comment

begin_function
name|void
name|test21
parameter_list|(
specifier|volatile
name|struct
name|Test21
modifier|*
name|ptr
parameter_list|)
block|{
name|void
name|test21_help
argument_list|(
name|void
argument_list|)
decl_stmt|;
operator|(
name|test21_help
argument_list|()
operator|,
operator|*
name|ptr
operator|)
expr_stmt|;
comment|// expected-error {{incomplete type 'struct Test21' where a complete type is required}}
operator|(
operator|*
name|ptr
operator|,
name|test21_help
argument_list|()
operator|)
expr_stmt|;
comment|// expected-error {{incomplete type 'struct Test21' where a complete type is required}}
block|}
end_function

begin_comment
comment|// Make sure we do function/array decay.
end_comment

begin_function
name|void
name|test22
parameter_list|()
block|{
if|if
condition|(
literal|"help"
condition|)
operator|(
name|void
operator|)
literal|0
expr_stmt|;
if|if
condition|(
name|test22
condition|)
comment|// expected-warning {{address of function 'test22' will always evaluate to 'true'}} \
comment|// expected-note {{prefix with the address-of operator to silence this warning}}
operator|(
name|void
operator|)
literal|0
expr_stmt|;
if|if
condition|(
operator|&
name|test22
condition|)
operator|(
name|void
operator|)
literal|0
expr_stmt|;
block|}
end_function

end_unit

