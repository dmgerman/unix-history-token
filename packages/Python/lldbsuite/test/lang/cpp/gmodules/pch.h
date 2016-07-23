begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|GenericContainer
block|{
name|private
operator|:
name|T
name|storage
block|;
name|public
operator|:
name|GenericContainer
argument_list|(
argument|T value
argument_list|)
block|{
name|storage
operator|=
name|value
block|;     }
block|; }
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|GenericContainer
operator|<
name|int
operator|>
name|IntContainer
expr_stmt|;
end_typedef

end_unit

