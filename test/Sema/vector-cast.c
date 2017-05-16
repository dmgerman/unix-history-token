begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify -Wvector-conversion
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|t1
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|char
name|t2
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|t3
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|s2
name|__attribute__
typedef|((
name|vector_size
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|Evalue
init|=
literal|0x10000
block|}
name|E
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|()
block|{
name|t1
name|v1
decl_stmt|;
name|t2
name|v2
decl_stmt|;
name|t3
name|v3
decl_stmt|;
name|s2
name|v4
decl_stmt|;
name|E
name|e
decl_stmt|;
name|e
operator|=
operator|(
name|E
operator|)
name|v4
expr_stmt|;
name|v4
operator|=
operator|(
name|s2
operator|)
name|e
expr_stmt|;
name|v2
operator|=
operator|(
name|t2
operator|)
name|v1
expr_stmt|;
comment|// expected-error {{invalid conversion between vector type \
literal|'t2'
operator|(
name|vector
name|of
literal|16
literal|'char'
name|values
operator|)
name|and
literal|'t1'
operator|(
name|vector
name|of
literal|1
literal|'long long'
name|value
operator|)
name|of
name|different
name|size
block|}
end_function

begin_expr_stmt
unit|}   v1
operator|=
operator|(
name|t1
operator|)
name|v2
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{invalid conversion between vector type \
end_comment

begin_expr_stmt
literal|'t1'
operator|(
name|vector
name|of
literal|1
literal|'long long'
name|value
operator|)
name|and
literal|'t2'
operator|(
name|vector
name|of
literal|16
literal|'char'
name|values
operator|)
name|of
name|different
name|size
end_expr_stmt

begin_expr_stmt
unit|}}
name|v3
operator|=
operator|(
name|t3
operator|)
name|v2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|v1
operator|=
call|(
name|t1
call|)
argument_list|(
name|char
operator|*
argument_list|)
literal|10
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{invalid conversion between vector \
end_comment

begin_expr_stmt
name|type
literal|'t1'
operator|(
name|vector
name|of
literal|1
literal|'long long'
name|value
operator|)
name|and
name|scalar
name|type
literal|'char *'
end_expr_stmt

begin_expr_stmt
unit|}}
name|v1
operator|=
operator|(
name|t1
operator|)
operator|(
name|long
name|long
operator|)
literal|10
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|v1
operator|=
call|(
name|t1
call|)
argument_list|(
name|short
argument_list|)
literal|10
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{invalid conversion between vector \
end_comment

begin_expr_stmt
name|type
literal|'t1'
operator|(
name|vector
name|of
literal|1
literal|'long long'
name|value
operator|)
name|and
name|integer
name|type
literal|'short'
name|of
name|different
name|size
end_expr_stmt

begin_decl_stmt
unit|}}
name|long
name|long
name|r1
init|=
operator|(
name|long
name|long
operator|)
name|v1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|r2
init|=
operator|(
name|short
operator|)
name|v1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid conversion between vector \
end_comment

begin_expr_stmt
name|type
literal|'t1'
operator|(
name|vector
name|of
literal|1
literal|'long long'
name|value
operator|)
name|and
name|integer
name|type
literal|'short'
name|of
name|different
name|size
end_expr_stmt

begin_decl_stmt
unit|}}
name|char
modifier|*
name|r3
init|=
operator|(
name|char
operator|*
operator|)
name|v1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid conversion between vector\
end_comment

begin_expr_stmt
name|type
literal|'t1'
operator|(
name|vector
name|of
literal|1
literal|'long long'
name|value
operator|)
name|and
name|scalar
name|type
literal|'char *'
end_expr_stmt

begin_macro
unit|}} }   void
name|f2
argument_list|(
argument|t2 X
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{passing argument to parameter 'X' here}}
end_comment

begin_function
name|void
name|f3
parameter_list|(
name|t3
name|Y
parameter_list|)
block|{
name|f2
argument_list|(
name|Y
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible vector types passing 't3' (vector of 4 'float' values) to parameter of type 't2' (vector of 16 'char' values)}}
block|}
end_function

begin_typedef
typedef|typedef
name|float
name|float2
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|double
name|float64x1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|double
name|float64x2_t
typedef|;
end_typedef

begin_function_decl
name|float64x1_t
name|vget_low_f64
parameter_list|(
name|float64x2_t
name|__p0
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f4
parameter_list|()
block|{
name|float2
name|f2
decl_stmt|;
name|double
name|d
decl_stmt|,
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|float64x2_t
name|v
init|=
block|{
literal|0.0
block|,
literal|1.0
block|}
decl_stmt|;
name|f2
operator|+=
name|d
expr_stmt|;
comment|// expected-error {{cannot convert between scalar type 'double' and vector type 'float2' (vector of 2 'float' values) as implicit conversion would cause truncation}}
name|d
operator|+=
name|f2
expr_stmt|;
comment|// expected-error {{assigning to 'double' from incompatible type 'float2' (vector of 2 'float' values)}}
name|a
operator|=
literal|3.0
operator|+
name|vget_low_f64
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|b
operator|=
name|vget_low_f64
argument_list|(
name|v
argument_list|)
operator|+
literal|3.0
expr_stmt|;
name|c
operator|=
name|vget_low_f64
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|c
operator|-=
name|vget_low_f64
argument_list|(
name|v
argument_list|)
expr_stmt|;
comment|// LAX conversions between scalar and vector types require same size and one element sized vectors.
name|d
operator|=
name|f2
expr_stmt|;
comment|// expected-error {{assigning to 'double' from incompatible type 'float2'}}
name|d
operator|=
name|d
operator|+
name|f2
expr_stmt|;
comment|// expected-error {{assigning to 'double' from incompatible type 'float2'}}
block|}
end_function

begin_comment
comment|// rdar://15931426
end_comment

begin_comment
comment|// Don't permit a lax conversion to and from a pointer type.
end_comment

begin_typedef
typedef|typedef
name|short
name|short_sizeof_pointer
name|__attribute__
typedef|((
name|vector_size
typedef|(sizeof(
name|void
modifier|*
typedef|))));
end_typedef

begin_function
name|void
name|f5
parameter_list|()
block|{
name|short_sizeof_pointer
name|v
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
name|v
operator|=
name|ptr
expr_stmt|;
comment|// expected-error-re {{assigning to 'short_sizeof_pointer' (vector of {{[0-9]+}} 'short' values) from incompatible type 'void *'}}
name|ptr
operator|=
name|v
expr_stmt|;
comment|// expected-error {{assigning to 'void *' from incompatible type 'short_sizeof_pointer'}}
block|}
end_function

end_unit

