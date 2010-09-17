begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-static_assert.cpp
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|N
operator|>
expr|struct
name|T
block|{
name|static_assert
argument_list|(
name|N
operator|==
literal|2
argument_list|,
literal|"N is not 2!"
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

end_unit

