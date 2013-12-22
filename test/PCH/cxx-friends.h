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

begin_decl_stmt
name|namespace
name|Lazy
block|{
struct|struct
name|S
block|{
name|friend
name|void
name|doNotDeserialize
parameter_list|()
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// Reduced testcase from libc++'s<valarray>. Used to crash with modules
end_comment

begin_comment
comment|// enabled.
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|valarray
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|valarray
block|{
name|valarray
argument_list|()
block|;
name|template
operator|<
name|class
name|U
operator|>
name|friend
expr|struct
name|valarray
block|;
name|template
operator|<
name|class
name|U
operator|>
name|friend
name|U
operator|*
name|begin
argument_list|(
name|valarray
operator|<
name|U
operator|>
operator|&
name|v
argument_list|)
block|; }
expr_stmt|;
struct|struct
name|gslice
block|{
name|valarray
operator|<
name|int
operator|>
name|size
expr_stmt|;
name|gslice
argument_list|()
block|{}
block|}
struct|;
block|}
end_decl_stmt

end_unit

