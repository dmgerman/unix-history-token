begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
operator|>
expr|struct
name|MergeSpecializations
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|MergeSpecializations
operator|<
name|T
index|[]
operator|>
block|{
typedef|typedef
name|int
name|partially_specialized_in_c
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|MergeSpecializations
operator|<
name|bool
operator|>
block|{
typedef|typedef
name|int
name|explicitly_specialized_in_c
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

