begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|int
name|p
index|[]
parameter_list|)
block|{
name|p
operator|++
expr_stmt|;
block|}
end_function

end_unit

