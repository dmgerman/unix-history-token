begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Dependent header for C++ chained PCH test
end_comment

begin_comment
comment|// Overload function from primary
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Add function with different name
end_comment

begin_function_decl
name|void
name|f2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Reopen namespace
end_comment

begin_decl_stmt
name|namespace
name|ns
block|{
comment|// Overload function from primary
name|void
name|g
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|// Add different name
name|void
name|g2
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// Specialize template from primary
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|S
operator|<
name|int
operator|>
block|{
typedef|typedef
name|int
name|I
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Partially specialize
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|S
operator|<
name|T
operator|&
operator|>
block|{
typedef|typedef
name|int
name|J
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Specialize previous partial specialization
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|S
operator|<
name|int
operator|*
operator|>
block|{
typedef|typedef
name|int
name|K
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Specialize the partial specialization from this file
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|S
operator|<
name|int
operator|&
operator|>
block|{
typedef|typedef
name|int
name|L
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

