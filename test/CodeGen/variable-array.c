begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep puts | count 4
end_comment

begin_comment
comment|// PR3248
end_comment

begin_function
name|int
name|a
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
argument_list|(
operator|*
name|y
argument_list|)
index|[
name|x
index|]
expr_stmt|;
return|return
sizeof|sizeof
argument_list|(
operator|*
operator|(
name|puts
argument_list|(
literal|"asdf"
argument_list|)
operator|,
name|y
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// PR3247
end_comment

begin_function
name|int
name|b
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
operator|*
operator|(
name|char
argument_list|(
operator|*
argument_list|)
index|[
name|puts
argument_list|(
literal|"asdf"
argument_list|)
index|]
operator|)
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// PR3247
end_comment

begin_function
name|int
name|c
parameter_list|()
block|{
specifier|static
name|int
argument_list|(
operator|*
name|y
argument_list|)
index|[
name|puts
argument_list|(
literal|"asdf"
argument_list|)
index|]
expr_stmt|;
return|return
sizeof|sizeof
argument_list|(
operator|*
name|y
argument_list|)
return|;
block|}
end_function

end_unit

