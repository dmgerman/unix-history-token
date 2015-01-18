begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|typename
operator|>
expr|struct
name|mersenne_twister_engine
block|{
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|mersenne_twister_engine
operator|&
operator|,
specifier|const
name|mersenne_twister_engine
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
expr|}
block|;   struct
name|random_device
block|{
name|mersenne_twister_engine
operator|<
name|int
operator|>
name|mt
block|;
comment|// require complete type
block|}
block|; }
end_decl_stmt

end_unit

