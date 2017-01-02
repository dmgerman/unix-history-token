begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<vector>
end_include

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|A
block|{
specifier|static
name|bool
name|b
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|A
operator|<
name|T
operator|>
operator|::
name|b
expr_stmt|;
end_expr_stmt

end_unit

