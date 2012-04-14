begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|S
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|c
argument_list|(
argument|T
argument_list|)
block|{ }
name|template
operator|<
operator|>
expr|struct
name|S
operator|<
name|int
operator|>
block|{
name|void
name|a
argument_list|()
block|{
name|c
argument_list|(
operator|&
name|S
operator|<
name|int
operator|>
operator|::
name|b
argument_list|)
block|;   }
name|void
name|b
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

end_unit

