begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -O1 | grep ashr
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -O1 | not grep sdiv
end_comment

begin_function
name|long
name|long
name|test
parameter_list|(
name|int
modifier|*
name|A
parameter_list|,
name|int
modifier|*
name|B
parameter_list|)
block|{
return|return
name|A
operator|-
name|B
return|;
block|}
end_function

end_unit

