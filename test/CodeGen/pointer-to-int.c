begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_function
name|int
name|test
parameter_list|(
name|void
modifier|*
name|i
parameter_list|)
block|{
return|return
operator|(
name|int
operator|)
name|i
return|;
block|}
end_function

begin_comment
comment|// rdar://6093986
end_comment

begin_function
name|int
name|test2
parameter_list|(
name|void
parameter_list|)
block|{
name|float
name|x
index|[
literal|2
index|]
decl_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

