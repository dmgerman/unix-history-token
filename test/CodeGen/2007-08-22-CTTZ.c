begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|int
name|bork
parameter_list|(
name|unsigned
name|long
name|long
name|x
parameter_list|)
block|{
comment|// CHECK: llvm.cttz.i64
comment|// CHECK: llvm.cttz.i64
comment|// CHECK-NOT: lshr
return|return
name|__builtin_ctzll
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

end_unit

