begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify -pedantic
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
comment|// expected-error {{use of tagged type 'xyz' without 'struct' tag}}
end_comment

begin_decl_stmt
name|myenum
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of tagged type 'myenum' without 'enum' tag}}
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
comment|// expected-warning {{incompatible pointer types returning 'int *', expected 'float *'}}
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

end_unit

