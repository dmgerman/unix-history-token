begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|class
name|Element
operator|>
expr|struct
name|TMatrixT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|TMatrixT
operator|<
name|double
operator|>
name|TMatrixD
expr_stmt|;
end_typedef

begin_function_decl
name|void
name|f
parameter_list|(
specifier|const
name|TMatrixD
modifier|&
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|class
name|Element
operator|>
expr|struct
name|TMatrixT
block|{
name|template
operator|<
name|class
name|Element2
operator|>
name|TMatrixT
argument_list|(
specifier|const
name|TMatrixT
operator|<
name|Element2
operator|>
operator|&
argument_list|)
block|;
operator|~
name|TMatrixT
argument_list|()
block|{}
name|void
name|Determinant
argument_list|()
block|{
name|f
argument_list|(
operator|*
name|this
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_macro
name|template
end_macro

begin_expr_stmt
unit|struct
name|TMatrixT
operator|<
name|float
operator|>
expr_stmt|;
end_expr_stmt

begin_macro
name|template
end_macro

begin_expr_stmt
unit|struct
name|TMatrixT
operator|<
name|double
operator|>
expr_stmt|;
end_expr_stmt

end_unit

