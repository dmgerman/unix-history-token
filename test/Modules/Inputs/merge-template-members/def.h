begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
operator|>
expr|struct
name|A
block|{
name|int
name|n
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
operator|>
expr|struct
name|B
block|{
typedef|typedef
name|A
operator|<
name|void
operator|>
name|C
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

