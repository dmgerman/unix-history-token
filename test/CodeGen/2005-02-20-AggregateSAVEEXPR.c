begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -o /dev/null -emit-llvm
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|__complex
name|float
name|c
parameter_list|)
block|{
return|return
name|creal
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function

end_unit

