begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -include %S/exprs.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -fblocks -o %t %S/exprs.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -include-pch %t -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|integer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long_integer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|floating
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|_Complex
name|double
name|floating_complex
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DeclRefExpr
end_comment

begin_decl_stmt
name|int_decl_ref
modifier|*
name|int_ptr1
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum_decl_ref
modifier|*
name|enum_ptr1
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// IntegerLiteral
end_comment

begin_decl_stmt
name|integer_literal
modifier|*
name|int_ptr2
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long_literal
modifier|*
name|long_ptr1
init|=
operator|&
name|long_integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FloatingLiteral + ParenExpr
end_comment

begin_decl_stmt
name|floating_literal
modifier|*
name|double_ptr
init|=
operator|&
name|floating
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ImaginaryLiteral
end_comment

begin_decl_stmt
name|imaginary_literal
modifier|*
name|cdouble_ptr
init|=
operator|&
name|floating_complex
decl_stmt|;
end_decl_stmt

begin_comment
comment|// StringLiteral
end_comment

begin_function
specifier|const
name|char
modifier|*
name|printHello
parameter_list|()
block|{
return|return
name|hello
return|;
block|}
end_function

begin_comment
comment|// CharacterLiteral
end_comment

begin_decl_stmt
name|char_literal
modifier|*
name|int_ptr3
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// UnaryOperator
end_comment

begin_decl_stmt
name|negate_enum
modifier|*
name|int_ptr4
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SizeOfAlignOfExpr
end_comment

begin_macro
name|typeof
argument_list|(
argument|sizeof(float)
argument_list|)
end_macro

begin_expr_stmt
name|size_t_value
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|typeof_sizeof
modifier|*
name|size_t_ptr
init|=
operator|&
name|size_t_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|typeof_sizeof2
modifier|*
name|size_t_ptr2
init|=
operator|&
name|size_t_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ArraySubscriptExpr
end_comment

begin_decl_stmt
name|array_subscript
modifier|*
name|double_ptr1_5
init|=
operator|&
name|floating
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CallExpr
end_comment

begin_decl_stmt
name|call_returning_double
modifier|*
name|double_ptr2
init|=
operator|&
name|floating
decl_stmt|;
end_decl_stmt

begin_comment
comment|// MemberExpr
end_comment

begin_decl_stmt
name|member_ref_double
modifier|*
name|double_ptr3
init|=
operator|&
name|floating
decl_stmt|;
end_decl_stmt

begin_comment
comment|// BinaryOperator
end_comment

begin_decl_stmt
name|add_result
modifier|*
name|int_ptr5
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CompoundAssignOperator
end_comment

begin_decl_stmt
name|addeq_result
modifier|*
name|int_ptr6
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ConditionalOperator
end_comment

begin_decl_stmt
name|conditional_operator
modifier|*
name|double_ptr4
init|=
operator|&
name|floating
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CStyleCastExpr
end_comment

begin_decl_stmt
name|void_ptr
name|vp1
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CompoundLiteral
end_comment

begin_decl_stmt
name|struct
name|S
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|compound_literal
modifier|*
name|sptr
init|=
operator|&
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ExtVectorElementExpr
end_comment

begin_decl_stmt
name|ext_vector_element
modifier|*
name|double_ptr5
init|=
operator|&
name|floating
decl_stmt|;
end_decl_stmt

begin_comment
comment|// InitListExpr
end_comment

begin_function
name|double
name|get_from_double_array
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
return|return
name|double_array
index|[
name|Idx
index|]
return|;
block|}
end_function

begin_comment
comment|/// DesignatedInitExpr
end_comment

begin_function
name|float
name|get_from_designated
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
return|return
name|designated_inits
index|[
literal|2
index|]
operator|.
name|y
return|;
block|}
end_function

begin_comment
comment|// TypesCompatibleExpr
end_comment

begin_decl_stmt
name|types_compatible
modifier|*
name|int_ptr7
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ChooseExpr
end_comment

begin_decl_stmt
name|choose_expr
modifier|*
name|int_ptr8
init|=
operator|&
name|integer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// GNUNullExpr FIXME: needs C++
end_comment

begin_comment
comment|//null_type null = __null;
end_comment

begin_comment
comment|// ShuffleVectorExpr
end_comment

begin_decl_stmt
name|shuffle_expr
modifier|*
name|vec_ptr
init|=
operator|&
name|vec2
decl_stmt|;
end_decl_stmt

end_unit

