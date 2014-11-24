begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -pedantic
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a1
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|f0
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
index|[
operator|*
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f2
parameter_list|(
name|int
index|[
specifier|const
operator|*
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f3
parameter_list|(
name|int
index|[
specifier|volatile
specifier|const
operator|*
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|f4
function_decl|(
modifier|*
name|XX
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* expected-error {{cannot return}} expected-warning {{type specifier missing, defaults to 'int'}} */
end_comment

begin_expr_stmt
name|char
argument_list|(
operator|(
operator|(
operator|(
operator|*
name|X
operator|)
operator|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
operator|*
name|signal
argument_list|(
name|int
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|aaaa
decl_stmt|,
modifier|*
modifier|*
modifier|*
name|C
decl_stmt|,
modifier|*
decl_stmt|const
name|D
decl_stmt|,
name|B
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|A
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|str
struct_decl|;
end_struct_decl

begin_function
name|void
name|test2
parameter_list|(
name|int
modifier|*
name|P
parameter_list|,
name|int
name|A
parameter_list|)
block|{
struct_decl|struct
name|str
struct_decl|;
comment|// Hard case for array decl, not Array[*].
name|int
name|Array
index|[
operator|*
operator|(
name|int
operator|*
operator|)
name|P
operator|+
name|A
index|]
decl_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|atype
typedef|;
end_typedef

begin_function
name|void
name|test3
parameter_list|(
name|x
parameter_list|,
name|atype
comment|/* expected-error {{unexpected type name 'atype': expected identifier}} */
parameter_list|)
name|int
name|x
decl_stmt|,
name|atype
decl_stmt|;
block|{}
end_function

begin_function
name|void
name|test4
parameter_list|(
name|x
parameter_list|,
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{}
end_function

begin_comment
comment|/* expected-error {{redefinition of parameter 'x'}} */
end_comment

begin_comment
comment|// PR3031
end_comment

begin_expr_stmt
name|int
argument_list|(
name|test5
argument_list|)
operator|,
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{expected identifier or '('}}
end_comment

begin_comment
comment|// PR3963& rdar://6759604 - test error recovery for mistyped "typenames".
end_comment

begin_decl_stmt
name|foo_t
modifier|*
name|d
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{unknown type name 'foo_t'}}
end_comment

begin_decl_stmt
name|foo_t
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{unknown type name 'foo_t'}}
end_comment

begin_function
name|int
name|test6
parameter_list|()
block|{
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// a should be declared.
end_comment

begin_comment
comment|// Use of tagged type without tag. rdar://6783347
end_comment

begin_struct
struct|struct
name|xyz
block|{
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|myenum
block|{
name|ASDFAS
block|}
enum|;
end_enum

begin_decl_stmt
name|xyz
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{must use 'struct' tag to refer to type 'xyz'}}
end_comment

begin_decl_stmt
name|myenum
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{must use 'enum' tag to refer to type 'myenum'}}
end_comment

begin_function
name|float
modifier|*
name|test7
parameter_list|()
block|{
comment|// We should recover 'b' by parsing it with a valid type of "struct xyz", which
comment|// allows us to diagnose other bad things done with y, such as this.
return|return
operator|&
name|b
operator|.
name|y
return|;
comment|// expected-warning {{incompatible pointer types returning 'int *' from a function with result type 'float *'}}
block|}
end_function

begin_function
name|struct
name|xyz
name|test8
parameter_list|()
block|{
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// a should be be marked invalid, no diag.
end_comment

begin_comment
comment|// Verify that implicit int still works.
end_comment

begin_expr_stmt
specifier|static
name|f
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_expr_stmt
specifier|static
name|g
operator|=
literal|4
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_decl_stmt
specifier|static
name|h
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
name|__asm__
argument_list|(
literal|"foo"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|test9
block|{
name|int
name|x
comment|// expected-error {{expected ';' at end of declaration list}}
name|int
name|y
decl_stmt|;
name|int
name|z
comment|// expected-warning {{expected ';' at end of declaration list}}
block|}
struct|;
end_struct

begin_comment
comment|// PR6208
end_comment

begin_struct
struct|struct
name|test10
block|{
name|int
name|a
decl_stmt|;
block|}
decl|static
name|test10x
struct|;
end_struct

begin_struct
struct|struct
name|test11
block|{
name|int
name|a
decl_stmt|;
block|}
decl|const
name|test11x
struct|;
end_struct

begin_comment
comment|// PR6216
end_comment

begin_function
name|void
name|test12
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__builtin_offsetof
argument_list|(
argument|struct { char c; int i; }
argument_list|,
argument|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://7608537
end_comment

begin_struct
struct|struct
name|test13
block|{
name|int
name|a
decl_stmt|;
block|}
argument_list|(
name|test13x
argument_list|)
struct|;
end_struct

begin_comment
comment|//<rdar://problem/8044088>
end_comment

begin_expr_stmt
unit|struct
name|X
operator|<
name|foo
operator|::
name|int
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error{{expected identifier or '('}}
end_comment

begin_comment
comment|// PR7617 - error recovery on missing ;.
end_comment

begin_expr_stmt
name|void
name|test14
argument_list|()
comment|// expected-error {{expected ';' after top level declarator}}
name|void
name|test14a
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
modifier|*
name|test14b
init|=
operator|(
name|void
operator|*
operator|)
name|test14a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Make sure test14a didn't get skipped.
end_comment

begin_comment
comment|// rdar://problem/8358508
end_comment

begin_macro
name|long
end_macro

begin_struct
struct|struct
name|X
block|{
name|int
name|x
decl_stmt|;
block|}
name|test15
argument_list|()
struct|;
end_struct

begin_comment
comment|// expected-error {{'long struct' is invalid}}
end_comment

begin_function
name|void
name|test16
parameter_list|(
name|i
parameter_list|)
name|int
name|i
name|j
decl_stmt|;
block|{ }
end_function

begin_comment
comment|// expected-error {{expected ';' at end of declaration}}
end_comment

begin_function
name|void
name|test17
parameter_list|(
name|i
parameter_list|,
name|j
parameter_list|)
name|int
name|i
decl_stmt|,
name|j
name|k
decl_stmt|;
block|{ }
end_function

begin_comment
comment|// expected-error {{expected ';' at end of declaration}}
end_comment

begin_function
name|void
name|knrNoSemi
parameter_list|(
name|i
parameter_list|)
name|int
name|i
decl_stmt|{
end_function

begin_comment
unit|}
comment|// expected-error {{expected ';' at end of declaration}}
end_comment

begin_comment
comment|// PR12595
end_comment

begin_macro
unit|void
name|test18
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
init|=
literal|4
operator|+
operator|(
literal|5
operator|-
literal|12
operator|)
init|)
decl_stmt|;
comment|// expected-error {{extraneous ')' before ';'}}
block|}
end_block

begin_enum
enum|enum
name|E1
block|{
name|e1
block|}
range|:
comment|// expected-error {{expected ';'}}
range|struct
name|EnumBitfield
block|{
comment|// expected-warning {{struct without named members is a GNU extension}}
block|enum
name|E2
block|{
name|e2
block|}
operator|:
literal|4
block|;
comment|// ok
block|struct
name|S
block|{
name|int
name|n
block|; }
operator|:
comment|// expected-error {{expected ';'}}
block|}
enum|;
end_enum

begin_comment
comment|// PR10982
end_comment

begin_enum
enum|enum
name|E11
block|{
name|A1
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|E12
block|{   ,
comment|// expected-error{{expected identifier}}
name|A2
block|}
enum|;
end_enum

begin_function
name|void
name|func_E12
parameter_list|(
name|enum
name|E12
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
name|A2
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|E13
block|{
literal|1D
operator|,
comment|// expected-error{{expected identifier}}
name|A3
block|}
enum|;
end_enum

begin_function
name|void
name|func_E13
parameter_list|(
name|enum
name|E13
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
name|A3
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|E14
block|{
name|A4
decl|12
block|,
comment|// expected-error{{expected '= constant-expression' or end of enumerator definition}}
name|A4a
block|}
enum|;
end_enum

begin_function
name|void
name|func_E14
parameter_list|(
name|enum
name|E14
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
name|A4a
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|E15
block|{
name|A5
init|=
literal|12
literal|4
block|,
comment|// expected-error{{expected '}' or ','}}
name|A5a
block|}
enum|;
end_enum

begin_function
name|void
name|func_E15
parameter_list|(
name|enum
name|E15
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
name|A5a
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|E16
block|{
name|A6
empty_stmt|;
comment|// expected-error{{expected '= constant-expression' or end of enumerator definition}}
name|A6a
block|}
enum|;
end_enum

end_unit

