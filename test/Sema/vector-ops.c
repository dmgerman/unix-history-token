begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -Wvector-conversions
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
comment|// expected-error{{invalid argument type 'v2f' to unary}}
comment|// Arrays
name|int
name|array1
index|[
name|v2ua
index|]
decl_stmt|;
comment|// expected-error{{size of array has non-integer type 'v2u'}}
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

end_unit

