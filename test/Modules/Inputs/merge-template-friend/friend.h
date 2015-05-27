begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|ns
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|C
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|A
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|class
operator|::
name|ns
operator|::
name|C
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

