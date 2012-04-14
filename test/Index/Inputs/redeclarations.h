begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|class
name|X
block|{
name|friend
name|class
name|A
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|class
name|B
block|{ }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|C
block|{ }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|class
name|D
block|{
name|B
operator|<
name|D
operator|,
name|class
name|A
operator|>
name|x
expr_stmt|;
name|friend
block|struct
name|C
operator|<
name|A
operator|>
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

