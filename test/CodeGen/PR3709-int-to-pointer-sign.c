begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -O1 -triple=x86_64-gnu-linux | grep "i64 -1"
end_comment

begin_comment
comment|// PR3709
end_comment

begin_function
name|long
name|long
name|a
parameter_list|()
block|{
return|return
call|(
name|long
name|long
call|)
argument_list|(
name|int
operator|*
argument_list|)
operator|-
literal|1
return|;
block|}
end_function

end_unit

