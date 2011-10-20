begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|int
name|test2
parameter_list|(
name|float
name|X
parameter_list|,
name|float
name|Y
parameter_list|)
block|{
comment|// CHECK: fcmp ord float %X, %Y
return|return
operator|!
name|__builtin_isunordered
argument_list|(
name|X
argument_list|,
name|Y
argument_list|)
return|;
block|}
end_function

end_unit

