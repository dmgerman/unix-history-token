begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|STATIC_CAST
value|static_cast
end_define

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|foo
argument_list|(
argument|T *p
argument_list|)
block|{
operator|(
name|void
operator|)
name|STATIC_CAST
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
block|; }
end_expr_stmt

end_unit

