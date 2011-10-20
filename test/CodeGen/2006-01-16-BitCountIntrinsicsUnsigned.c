begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|unsigned
name|t2
parameter_list|(
name|unsigned
name|X
parameter_list|)
block|{
comment|// CHECK: t2
comment|// CHECK: llvm.ctlz.i32
return|return
name|__builtin_clz
argument_list|(
name|X
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|t1
parameter_list|(
name|int
name|X
parameter_list|)
block|{
comment|// CHECK: t1
comment|// CHECK: llvm.ctlz.i32
return|return
name|__builtin_clz
argument_list|(
name|X
argument_list|)
return|;
block|}
end_function

end_unit

