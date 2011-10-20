begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// Test case by Eric Postpischil!
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|a
index|[
literal|1
index|]
decl_stmt|;
name|int
name|t
init|=
literal|1
decl_stmt|;
operator|(
operator|(
name|char
argument_list|(
operator|*
argument_list|)
index|[
name|t
index|]
operator|)
name|a
operator|)
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

