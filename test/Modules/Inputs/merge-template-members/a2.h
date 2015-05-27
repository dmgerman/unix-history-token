begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|N
block|{
name|template
operator|<
name|typename
operator|>
expr|struct
name|A
block|{
name|int
name|n
block|;
name|A
argument_list|()
operator|:
name|n
argument_list|()
block|{}
block|}
expr_stmt|;
comment|// Create declaration of A<int>.
typedef|typedef
name|A
operator|<
name|int
operator|>
name|AI
expr_stmt|;
block|}
end_decl_stmt

end_unit

