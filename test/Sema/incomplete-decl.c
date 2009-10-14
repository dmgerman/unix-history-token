begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_struct_decl
struct_decl|struct
name|foo
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note 5 {{forward declaration of 'struct foo'}}
end_comment

begin_decl_stmt
name|void
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable has incomplete type 'void'}}
end_comment

begin_decl_stmt
name|struct
name|foo
name|f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{tentative definition has type 'struct foo' that is never completed}}
end_comment

begin_decl_stmt
specifier|static
name|void
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable has incomplete type 'void'}}
end_comment

begin_decl_stmt
specifier|static
name|struct
name|foo
name|g
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{tentative definition of variable with internal linkage has incomplete non-array type 'struct foo'}} \
end_comment

begin_expr_stmt
name|expected
operator|-
name|error
block|{
block|{
name|tentative
name|definition
name|has
name|type
literal|'struct foo'
name|that
name|is
name|never
name|completed
block|}
block|}
specifier|extern
name|void
name|d
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|foo
name|e
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ary
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{tentative array definition assumed to have one element}}
end_comment

begin_decl_stmt
name|struct
name|foo
name|bary
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{array has incomplete element type 'struct foo'}}
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
name|int
name|ary
index|[]
decl_stmt|;
comment|// expected-error{{variable has incomplete type 'int []'}}
name|void
name|b
decl_stmt|;
comment|// expected-error {{variable has incomplete type 'void'}}
name|struct
name|foo
name|f
decl_stmt|;
comment|// expected-error {{variable has incomplete type 'struct foo'}}
block|}
end_function

begin_decl_stmt
name|int
name|h
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{tentative array definition assumed to have one element}}
end_comment

begin_expr_stmt
name|int
argument_list|(
operator|*
name|i
argument_list|)
index|[]
operator|=
operator|&
name|h
operator|+
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{arithmetic on pointer to incomplete type 'int (*)[]'}}
end_comment

begin_decl_stmt
name|struct
name|bar
name|j
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable has incomplete type 'struct bar'}} \
end_comment

begin_expr_stmt
name|expected
operator|-
name|note
block|{
block|{
name|forward
name|declaration
name|of
literal|'struct bar'
block|}
block|}
expr|struct
name|bar
name|k
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|bar
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

end_unit

