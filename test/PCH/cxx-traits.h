begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-traits.cpp
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_pod
block|{   enum
block|{
name|__value
block|}
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_empty
block|{   enum
block|{
name|__value
block|}
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
operator|...
name|Args
operator|>
expr|struct
name|is_trivially_constructible
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|__is_trivially_constructible
argument_list|(
name|T
argument_list|,
name|Args
operator|...
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

end_unit

