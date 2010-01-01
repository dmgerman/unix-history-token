begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_function
name|void
modifier|*
name|test
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|i
return|;
block|}
end_function

end_unit

