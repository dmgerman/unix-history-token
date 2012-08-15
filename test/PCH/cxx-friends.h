begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-friends.cpp
end_comment

begin_decl_stmt
name|class
name|A
block|{
name|int
name|x
decl_stmt|;
name|friend
name|class
name|F
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|PR12585
block|{
struct|struct
name|future_base
block|{
name|template
operator|<
name|typename
operator|>
name|class
name|setter
expr_stmt|;
block|}
struct|;
name|template
operator|<
name|typename
operator|>
name|class
name|promise
block|{
comment|// We used to inject this into future_base with no access specifier,
comment|// then crash during AST writing.
name|template
operator|<
name|typename
operator|>
name|friend
name|class
name|future_base
operator|::
name|setter
block|;
name|int
name|k
block|;   }
expr_stmt|;
block|}
end_decl_stmt

end_unit

