begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp=libiomp5 -ferror-limit 100 %s
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
name|L1
label|:
name|foo
argument_list|()
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
comment|// expected-error@+1 {{the statement for 'atomic' must be an expression statement of form '++x;', '--x;', 'x++;', 'x--;', 'x binop= expr;', 'x = x binop expr' or 'x = expr binop x', where x is an l-value expression with scalar type}}
block|{
name|foo
argument_list|()
expr_stmt|;
goto|goto
name|L1
goto|;
comment|// expected-error {{use of undeclared label 'L1'}}
block|}
goto|goto
name|L2
goto|;
comment|// expected-error {{use of undeclared label 'L2'}}
pragma|#
directive|pragma
name|omp
name|atomic
comment|// expected-error@+1 {{the statement for 'atomic' must be an expression statement of form '++x;', '--x;', 'x++;', 'x--;', 'x binop= expr;', 'x = x binop expr' or 'x = expr binop x', where x is an l-value expression with scalar type}}
block|{
name|foo
argument_list|()
expr_stmt|;
name|L2
label|:
name|foo
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_struct
struct|struct
name|S
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|readint
parameter_list|()
block|{
name|int
name|a
init|=
literal|0
decl_stmt|,
name|b
init|=
literal|0
decl_stmt|;
comment|// Test for atomic read
pragma|#
directive|pragma
name|omp
name|atomic
name|read
comment|// expected-error@+2 {{the statement for 'atomic read' must be an expression statement of form 'v = x;', where v and x are both lvalue expressions with scalar type}}
comment|// expected-note@+1 {{expected an expression statement}}
empty_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|read
comment|// expected-error@+2 {{the statement for 'atomic read' must be an expression statement of form 'v = x;', where v and x are both lvalue expressions with scalar type}}
comment|// expected-note@+1 {{expected built-in assignment operator}}
name|foo
argument_list|()
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|read
comment|// expected-error@+2 {{the statement for 'atomic read' must be an expression statement of form 'v = x;', where v and x are both lvalue expressions with scalar type}}
comment|// expected-note@+1 {{expected built-in assignment operator}}
name|a
operator|+=
name|b
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|read
comment|// expected-error@+2 {{the statement for 'atomic read' must be an expression statement of form 'v = x;', where v and x are both lvalue expressions with scalar type}}
comment|// expected-note@+1 {{expected lvalue expression}}
name|a
operator|=
literal|0
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|a
operator|=
name|b
expr_stmt|;
comment|// expected-error@+1 {{directive '#pragma omp atomic' cannot contain more than one 'read' clause}}
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|read
name|a
operator|=
name|b
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|readS
parameter_list|()
block|{
name|struct
name|S
name|a
decl_stmt|,
name|b
decl_stmt|;
comment|// expected-error@+1 {{directive '#pragma omp atomic' cannot contain more than one 'read' clause}}
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|read
comment|// expected-error@+2 {{the statement for 'atomic read' must be an expression statement of form 'v = x;', where v and x are both lvalue expressions with scalar type}}
comment|// expected-note@+1 {{expected expression of scalar type}}
name|a
operator|=
name|b
expr_stmt|;
return|return
name|a
operator|.
name|a
return|;
block|}
end_function

begin_function
name|int
name|writeint
parameter_list|()
block|{
name|int
name|a
init|=
literal|0
decl_stmt|,
name|b
init|=
literal|0
decl_stmt|;
comment|// Test for atomic write
pragma|#
directive|pragma
name|omp
name|atomic
name|write
comment|// expected-error@+2 {{the statement for 'atomic write' must be an expression statement of form 'x = expr;', where x is a lvalue expression with scalar type}}
comment|// expected-note@+1 {{expected an expression statement}}
empty_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|write
comment|// expected-error@+2 {{the statement for 'atomic write' must be an expression statement of form 'x = expr;', where x is a lvalue expression with scalar type}}
comment|// expected-note@+1 {{expected built-in assignment operator}}
name|foo
argument_list|()
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|write
comment|// expected-error@+2 {{the statement for 'atomic write' must be an expression statement of form 'x = expr;', where x is a lvalue expression with scalar type}}
comment|// expected-note@+1 {{expected built-in assignment operator}}
name|a
operator|+=
name|b
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|a
operator|=
literal|0
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|a
operator|=
name|b
expr_stmt|;
comment|// expected-error@+1 {{directive '#pragma omp atomic' cannot contain more than one 'write' clause}}
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|write
name|a
operator|=
name|b
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|writeS
parameter_list|()
block|{
name|struct
name|S
name|a
decl_stmt|,
name|b
decl_stmt|;
comment|// expected-error@+1 {{directive '#pragma omp atomic' cannot contain more than one 'write' clause}}
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|write
comment|// expected-error@+2 {{the statement for 'atomic write' must be an expression statement of form 'x = expr;', where x is a lvalue expression with scalar type}}
comment|// expected-note@+1 {{expected expression of scalar type}}
name|a
operator|=
name|b
expr_stmt|;
return|return
name|a
operator|.
name|a
return|;
block|}
end_function

end_unit

