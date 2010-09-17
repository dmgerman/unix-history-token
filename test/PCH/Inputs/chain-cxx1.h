begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Primary header for C++ chained PCH test
end_comment

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Name not appearing in dependent
end_comment

begin_function_decl
name|void
name|pf
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|namespace
name|ns
block|{
name|void
name|g
parameter_list|()
function_decl|;
name|void
name|pg
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|S
block|{
typedef|typedef
name|int
name|G
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
operator|*
operator|>
block|{
typedef|typedef
name|int
name|H
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

