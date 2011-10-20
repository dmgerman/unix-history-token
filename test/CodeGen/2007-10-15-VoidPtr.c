begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o /dev/null
end_comment

begin_function
name|void
name|bork
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|)
block|{
operator|(
operator|*
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|(
operator|&
operator|(
name|data
index|[
literal|37
index|]
operator|)
index|[
literal|927
index|]
operator|)
operator|=
literal|0
operator|)
expr_stmt|;
block|}
end_function

end_unit

