begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Vector
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|List
block|{
name|public
operator|:
name|void
name|push_back
argument_list|(
name|T
argument_list|)
block|;    struct
name|node
block|{}
block|;
name|node
operator|*
name|head
block|;
name|unsigned
name|size
block|; }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|A
block|{
name|class
name|Y
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|class
name|WhereAmI
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|A
operator|::
name|WhereAmI
block|{
name|public
operator|:
specifier|static
name|void
name|func
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Outer
block|{   struct
name|Inner
block|{}
block|; }
expr_stmt|;
end_expr_stmt

end_unit

