begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|allocator
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|X
block|{
name|virtual
name|allocator
operator|<
name|char
operator|>
name|f
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

end_unit

