begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: clang-cc -fblocks -include %S/types.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -fblocks -o %t %S/types.h
end_comment

begin_comment
comment|// RUN: clang-cc -fblocks -include-pch %t -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|INT
typedef|;
end_typedef

begin_decl_stmt
name|INT
name|int_value
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(address_space(
literal|1
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|int
name|int_as_one
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_EXT_QUAL
end_comment

begin_decl_stmt
name|ASInt
modifier|*
name|as_int_ptr1
init|=
operator|&
name|int_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{different address spaces}} \
end_comment

begin_comment
comment|// FIXME: expected-warning{{discards qualifiers}}
end_comment

begin_decl_stmt
name|ASInt
modifier|*
name|as_int_ptr2
init|=
operator|&
name|int_as_one
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: TYPE_FIXED_WIDTH_INT
end_comment

begin_comment
comment|// TYPE_COMPLEX
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|Cfloat_val
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Cfloat
modifier|*
name|Cfloat_ptr
init|=
operator|&
name|Cfloat_val
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_POINTER
end_comment

begin_decl_stmt
name|int_ptr
name|int_value_ptr
init|=
operator|&
name|int_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_BLOCK_POINTER
end_comment

begin_function
name|void
name|test_block_ptr
parameter_list|(
name|Block
modifier|*
name|bl
parameter_list|)
block|{
operator|*
name|bl
operator|=
lambda|^
parameter_list|(
name|int
name|x
parameter_list|,
name|float
name|f
parameter_list|)
block|{
return|return
name|x
return|;
block|}
expr_stmt|;
block|}
end_function

begin_comment
comment|// TYPE_CONSTANT_ARRAY
end_comment

begin_decl_stmt
name|five_ints
name|fvi
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_INCOMPLETE_ARRAY
end_comment

begin_decl_stmt
name|float_array
name|fa1
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float_array
name|fa2
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_VARIABLE_ARRAY in stmts.[ch]
end_comment

begin_comment
comment|// TYPE_VECTOR
end_comment

begin_decl_stmt
name|float4
name|f4
init|=
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_EXT_VECTOR
end_comment

begin_decl_stmt
name|ext_float4
name|ef4
init|=
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_FUNCTION_NO_PROTO
end_comment

begin_decl_stmt
name|noproto
name|np1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|np1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|int
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// TYPE_FUNCTION_PROTO
end_comment

begin_decl_stmt
name|proto
name|p1
decl_stmt|;
end_decl_stmt

begin_function
name|float
name|p1
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_decl_stmt
name|proto
modifier|*
name|p2
init|=
name|p1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_TYPEDEF
end_comment

begin_decl_stmt
name|int_ptr_ptr
name|ipp
init|=
operator|&
name|int_value_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TYPE_TYPEOF_EXPR
end_comment

begin_decl_stmt
name|typeof_17
modifier|*
name|t17
init|=
operator|&
name|int_value
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|S
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|typeof_17
name|t17_2
init|=
operator|(
expr|struct
name|S
operator|)
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{incompatible type initializing}}
end_comment

begin_comment
comment|// TYPE_TYPEOF
end_comment

begin_decl_stmt
name|int_ptr_ptr2
name|ipp2
init|=
operator|&
name|int_value_ptr
decl_stmt|;
end_decl_stmt

end_unit

