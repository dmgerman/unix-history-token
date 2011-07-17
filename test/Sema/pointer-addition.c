begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -pedantic
end_comment

begin_typedef
typedef|typedef
name|struct
name|S
name|S
typedef|;
end_typedef

begin_comment
comment|// expected-note 3 {{forward declaration of 'struct S'}}
end_comment

begin_function
name|void
name|a
parameter_list|(
name|S
modifier|*
name|b
parameter_list|,
name|void
modifier|*
name|c
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
literal|0
function_decl|;
name|b
operator|++
expr_stmt|;
comment|// expected-error {{arithmetic on a pointer to an incomplete type}}
name|b
operator|+=
literal|1
expr_stmt|;
comment|// expected-error {{arithmetic on a pointer to an incomplete type}}
name|c
operator|++
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to void is a GNU extension}}
name|c
operator|+=
literal|1
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to void is a GNU extension}}
name|c
operator|--
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to void is a GNU extension}}
name|c
operator|-=
literal|1
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to void is a GNU extension}}
operator|(
name|void
operator|)
name|c
index|[
literal|1
index|]
expr_stmt|;
comment|// expected-warning {{subscript of a pointer to void is a GNU extension}}
name|b
operator|=
literal|1
operator|+
name|b
expr_stmt|;
comment|// expected-error {{arithmetic on a pointer to an incomplete type}}
comment|/* The next couple tests are only pedantic warnings in gcc */
name|void
function_decl|(
modifier|*
name|d
function_decl|)
parameter_list|(
name|S
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
init|=
name|a
function_decl|;
name|d
operator|+=
literal|1
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to the function type 'void (S *, void *)' is a GNU extension}}
name|d
operator|++
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to the function type 'void (S *, void *)' is a GNU extension}}
name|d
operator|--
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to the function type 'void (S *, void *)' is a GNU extension}}
name|d
operator|-=
literal|1
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to the function type 'void (S *, void *)' is a GNU extension}}
call|(
name|void
call|)
argument_list|(
literal|1
operator|+
name|d
argument_list|)
expr_stmt|;
comment|// expected-warning {{arithmetic on a pointer to the function type 'void (S *, void *)' is a GNU extension}}
block|}
end_function

end_unit

