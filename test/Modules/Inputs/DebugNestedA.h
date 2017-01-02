begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- C++ -*- */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Base
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|A
operator|:
name|public
name|Base
operator|<
name|A
operator|<
name|T
operator|>>
block|{
name|void
name|f
argument_list|()
block|; }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|class
name|F
block|{}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|A
operator|<
name|F
operator|>
name|AF
expr_stmt|;
end_typedef

end_unit

