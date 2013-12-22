begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|import
name|recursive_visibility_b
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Y
operator|>
name|void
name|g
argument_list|()
block|{
name|f
argument_list|(
argument|typename Y<A1_Inner::X>::type{}
argument_list|)
block|;
name|f
argument_list|(
argument|typename Y<A2_More_Inner::X>::type{}
argument_list|)
block|; }
end_expr_stmt

end_unit

