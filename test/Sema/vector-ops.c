begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -Wvector-conversion -triple x86_64-apple-darwin10
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|v2u
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|v2s
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|v2f
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_function
name|void
name|test1
parameter_list|(
name|v2u
name|v2ua
parameter_list|,
name|v2s
name|v2sa
parameter_list|,
name|v2f
name|v2fa
parameter_list|)
block|{
comment|// Bitwise binary operators
call|(
name|void
call|)
argument_list|(
name|v2ua
operator|&
name|v2ua
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|v2fa
operator|&
name|v2fa
argument_list|)
expr_stmt|;
comment|// expected-error{{invalid operands to binary expression}}
comment|// Unary operators
call|(
name|void
call|)
argument_list|(
operator|~
name|v2ua
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
operator|~
name|v2fa
argument_list|)
expr_stmt|;
comment|// expected-error{{invalid argument type 'v2f' (vector of 2 'float' values) to unary}}
comment|// Comparison operators
name|v2ua
operator|=
operator|(
name|v2ua
operator|==
name|v2sa
operator|)
expr_stmt|;
comment|// expected-warning{{incompatible vector types assigning to 'v2u' (vector of 2 'unsigned int' values) from '__attribute__((__vector_size__(2 * sizeof(int)))) int' (vector of 2 'int' values}}
name|v2sa
operator|=
operator|(
name|v2ua
operator|==
name|v2sa
operator|)
expr_stmt|;
comment|// Arrays
name|int
name|array1
index|[
name|v2ua
index|]
decl_stmt|;
comment|// expected-error{{size of array has non-integer type 'v2u' (vector of 2 'unsigned int' values}}
name|int
name|array2
index|[
literal|17
index|]
decl_stmt|;
comment|// FIXME: error message below needs type!
call|(
name|void
call|)
argument_list|(
name|array2
index|[
name|v2ua
index|]
argument_list|)
expr_stmt|;
comment|// expected-error{{array subscript is not an integer}}
name|v2u
modifier|*
name|v2u_ptr
init|=
literal|0
decl_stmt|;
name|v2s
modifier|*
name|v2s_ptr
decl_stmt|;
name|v2s_ptr
operator|=
name|v2u_ptr
expr_stmt|;
comment|// expected-warning{{converts between pointers to integer types with different sign}}
block|}
end_function

begin_function
name|void
name|testLogicalVecVec
parameter_list|(
name|v2u
name|v2ua
parameter_list|,
name|v2s
name|v2sa
parameter_list|,
name|v2f
name|v2fa
parameter_list|)
block|{
comment|// Logical operators
name|v2ua
operator|=
name|v2ua
operator|&&
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2u'}}
name|v2ua
operator|=
name|v2ua
operator|||
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2u'}}
name|v2ua
operator|=
name|v2sa
operator|&&
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2u' (vector of 2 'unsigned int' values)}}
name|v2ua
operator|=
name|v2sa
operator|||
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2u' (vector of 2 'unsigned int' values)}}
name|v2ua
operator|=
name|v2ua
operator|&&
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2ua
operator|=
name|v2ua
operator|||
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2ua
operator|=
name|v2sa
operator|&&
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2ua
operator|=
name|v2sa
operator|||
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2sa
operator|=
name|v2sa
operator|&&
name|v2sa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2s'}}
name|v2sa
operator|=
name|v2sa
operator|||
name|v2sa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2s'}}
name|v2sa
operator|=
name|v2ua
operator|&&
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2u'}}
name|v2sa
operator|=
name|v2ua
operator|||
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2u'}}
name|v2sa
operator|=
name|v2sa
operator|&&
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2u' (vector of 2 'unsigned int' values)}}
name|v2sa
operator|=
name|v2sa
operator|||
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2u' (vector of 2 'unsigned int' values)}}
name|v2sa
operator|=
name|v2sa
operator|&&
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2sa
operator|=
name|v2sa
operator|||
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2sa
operator|=
name|v2ua
operator|&&
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2sa
operator|=
name|v2ua
operator|||
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2fa
operator|=
name|v2fa
operator|&&
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2f' (vector of 2 'float' values) and 'v2f'}}
name|v2fa
operator|=
name|v2fa
operator|||
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2f' (vector of 2 'float' values) and 'v2f'}}
name|v2fa
operator|=
name|v2sa
operator|&&
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2fa
operator|=
name|v2sa
operator|||
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2fa
operator|=
name|v2ua
operator|&&
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2fa
operator|=
name|v2ua
operator|||
name|v2fa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2f' (vector of 2 'float' values)}}
name|v2fa
operator|=
name|v2ua
operator|&&
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2u'}}
name|v2fa
operator|=
name|v2ua
operator|||
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2u' (vector of 2 'unsigned int' values) and 'v2u'}}
name|v2fa
operator|=
name|v2sa
operator|&&
name|v2sa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2s'}}
name|v2fa
operator|=
name|v2sa
operator|||
name|v2sa
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2s'}}
name|v2fa
operator|=
name|v2sa
operator|&&
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2u' (vector of 2 'unsigned int' values)}}
name|v2fa
operator|=
name|v2sa
operator|||
name|v2ua
expr_stmt|;
comment|// expected-error {{logical expression with vector types 'v2s' (vector of 2 'int' values) and 'v2u' (vector of 2 'unsigned int' values)}}
block|}
end_function

begin_function
name|void
name|testLogicalVecScalar
parameter_list|(
name|v2u
name|v2ua
parameter_list|,
name|v2s
name|v2sa
parameter_list|,
name|v2f
name|v2fa
parameter_list|)
block|{
name|unsigned
name|u1
decl_stmt|;
name|v2ua
operator|=
name|v2ua
operator|&&
name|u1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'unsigned int' is only supported in C++}}
name|v2ua
operator|=
name|v2ua
operator|||
name|u1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'unsigned int' is only supported in C++}}
name|v2sa
operator|=
name|v2sa
operator|&&
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2s' (vector of 2 'int' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2s' (vector of 2 'int' values) and 'unsigned int')}}
name|v2sa
operator|=
name|v2sa
operator|||
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2s' (vector of 2 'int' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2s' (vector of 2 'int' values) and 'unsigned int')}}
name|v2ua
operator|=
name|v2sa
operator|&&
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2s' (vector of 2 'int' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2s' (vector of 2 'int' values) and 'unsigned int')}}
name|v2ua
operator|=
name|v2sa
operator|||
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2s' (vector of 2 'int' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2s' (vector of 2 'int' values) and 'unsigned int')}}
name|v2sa
operator|=
name|v2ua
operator|&&
name|u1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'unsigned int' is only supported in C++}}
name|v2sa
operator|=
name|v2ua
operator|||
name|u1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'unsigned int' is only supported in C++}}
name|v2ua
operator|=
name|v2fa
operator|&&
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'unsigned int')}}
name|v2ua
operator|=
name|v2fa
operator|||
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'unsigned int')}}
name|v2sa
operator|=
name|v2fa
operator|&&
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'unsigned int')}}
name|v2sa
operator|=
name|v2fa
operator|||
name|u1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'unsigned int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'unsigned int')}}
name|int
name|s1
decl_stmt|;
name|v2ua
operator|=
name|v2ua
operator|&&
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'int' is only supported in C++}}
name|v2ua
operator|=
name|v2ua
operator|||
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'int' is only supported in C++}}
name|v2sa
operator|=
name|v2sa
operator|&&
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'int' is only supported in C++}}
name|v2sa
operator|=
name|v2sa
operator|||
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'int' is only supported in C++}}
name|v2ua
operator|=
name|v2sa
operator|&&
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'int' is only supported in C++}}
name|v2ua
operator|=
name|v2sa
operator|||
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'int' is only supported in C++}}
name|v2sa
operator|=
name|v2ua
operator|&&
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'int' is only supported in C++}}
name|v2sa
operator|=
name|v2ua
operator|||
name|s1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'int' is only supported in C++}}
name|v2ua
operator|=
name|v2fa
operator|&&
name|s1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'int'}}
name|v2ua
operator|=
name|v2fa
operator|||
name|s1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'int'}}
name|v2sa
operator|=
name|v2fa
operator|&&
name|s1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'int'}}
name|v2sa
operator|=
name|v2fa
operator|||
name|s1
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'int' and vector type 'v2f' (vector of 2 'float' values) as implicit conversion would cause truncation}} expected-error {{invalid operands to binary expression ('v2f' (vector of 2 'float' values) and 'int'}}
name|float
name|f1
decl_stmt|;
name|v2ua
operator|=
name|v2ua
operator|&&
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'float' is only supported in C++}}
name|v2ua
operator|=
name|v2ua
operator|||
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'float' is only supported in C++}}
name|v2sa
operator|=
name|v2sa
operator|&&
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'float' is only supported in C++}}
name|v2sa
operator|=
name|v2sa
operator|||
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'float' is only supported in C++}}
name|v2ua
operator|=
name|v2sa
operator|&&
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'float' is only supported in C++}}
name|v2ua
operator|=
name|v2sa
operator|||
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2s' (vector of 2 'int' values) and non-vector type 'float' is only supported in C++}}
name|v2sa
operator|=
name|v2ua
operator|&&
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'float' is only supported in C++}}
name|v2sa
operator|=
name|v2ua
operator|||
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2u' (vector of 2 'unsigned int' values) and non-vector type 'float' is only supported in C++}}
name|v2ua
operator|=
name|v2fa
operator|&&
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2f' (vector of 2 'float' values) and non-vector type 'float' is only supported in C++}}
name|v2ua
operator|=
name|v2fa
operator|||
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2f' (vector of 2 'float' values) and non-vector type 'float' is only supported in C++}}
name|v2sa
operator|=
name|v2fa
operator|&&
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2f' (vector of 2 'float' values) and non-vector type 'float' is only supported in C++}}
name|v2sa
operator|=
name|v2fa
operator|||
name|f1
expr_stmt|;
comment|// expected-error {{logical expression with vector type 'v2f' (vector of 2 'float' values) and non-vector type 'float' is only supported in C++}}
block|}
end_function

end_unit

