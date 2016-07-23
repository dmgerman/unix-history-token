begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
operator|>
expr|struct
name|_Vector_base
block|{}
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vector
block|{
name|vector
argument_list|()
block|{}
name|vector
argument_list|(
name|_Vector_base
operator|<
name|int
operator|>
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

end_unit

