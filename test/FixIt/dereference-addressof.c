begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fixit -x c %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -x c %t
end_comment

begin_function
name|void
name|ip
parameter_list|(
name|int
modifier|*
name|aPtr
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note{{passing argument to parameter 'aPtr' here}}
end_comment

begin_function
name|void
name|i
parameter_list|(
name|int
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note{{passing argument to parameter 'a' here}}
end_comment

begin_function
name|void
name|ii
parameter_list|(
name|int
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note{{passing argument to parameter 'a' here}}
end_comment

begin_function
name|void
name|fp
parameter_list|(
name|float
modifier|*
name|aPtr
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note{{passing argument to parameter 'aPtr' here}}
end_comment

begin_function
name|void
name|f
parameter_list|(
name|float
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note{{passing argument to parameter 'a' here}}
end_comment

begin_function
name|void
name|f2
parameter_list|(
name|int
modifier|*
name|aPtr
parameter_list|,
name|int
name|a
parameter_list|,
name|float
modifier|*
name|bPtr
parameter_list|,
name|char
name|c
parameter_list|)
block|{
name|float
name|fl
init|=
literal|0
decl_stmt|;
name|ip
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning{{incompatible integer to pointer conversion passing 'int' to parameter of type 'int *'; take the address with&}}
name|i
argument_list|(
name|aPtr
argument_list|)
expr_stmt|;
comment|// expected-warning{{incompatible pointer to integer conversion passing 'int *' to parameter of type 'int'; dereference with *}}
name|ii
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning{{incompatible pointer to integer conversion passing 'int *' to parameter of type 'int'; remove&}}
name|fp
argument_list|(
operator|*
name|bPtr
argument_list|)
expr_stmt|;
comment|// expected-error{{passing 'float' to parameter of incompatible type 'float *'; remove *}}
name|f
argument_list|(
name|bPtr
argument_list|)
expr_stmt|;
comment|// expected-error{{passing 'float *' to parameter of incompatible type 'float'; dereference with *}}
name|a
operator|=
name|aPtr
expr_stmt|;
comment|// expected-warning{{incompatible pointer to integer conversion assigning to 'int' from 'int *'; dereference with *}}
name|fl
operator|=
name|bPtr
operator|+
name|a
expr_stmt|;
comment|// expected-error{{assigning to 'float' from incompatible type 'float *'; dereference with *}}
name|bPtr
operator|=
name|bPtr
index|[
name|a
index|]
expr_stmt|;
comment|// expected-error{{assigning to 'float *' from incompatible type 'float'; take the address with&}}
block|}
end_function

end_unit

