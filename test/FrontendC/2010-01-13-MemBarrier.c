begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// XFAIL: sparc,powerpc
end_comment

begin_comment
comment|// rdar://7536390
end_comment

begin_function
name|unsigned
name|t
parameter_list|(
name|unsigned
modifier|*
name|ptr
parameter_list|,
name|unsigned
name|val
parameter_list|)
block|{
comment|// CHECK:      @t
comment|// CHECK:      call void @llvm.memory.barrier
comment|// CHECK-NEXT: call i32 @llvm.atomic.swap.i32
comment|// CHECK-NEXT: call void @llvm.memory.barrier
return|return
name|__sync_lock_test_and_set
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

end_unit

