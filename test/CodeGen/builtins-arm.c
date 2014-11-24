begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wall -Werror -triple thumbv7-eabi -target-cpu cortex-a8 -O3 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
modifier|*
name|f0
parameter_list|()
block|{
return|return
name|__builtin_thread_pointer
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|f1
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
block|{
name|__clear_cache
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @__clear_cache
end_comment

begin_function
name|void
name|test_eh_return_data_regno
parameter_list|()
block|{
specifier|volatile
name|int
name|res
decl_stmt|;
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store volatile i32 0
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store volatile i32 1
block|}
end_function

begin_function
name|void
name|nop
parameter_list|()
block|{
name|__builtin_arm_nop
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.hint(i32 0)
end_comment

begin_function
name|void
name|yield
parameter_list|()
block|{
name|__builtin_arm_yield
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.hint(i32 1)
end_comment

begin_function
name|void
name|wfe
parameter_list|()
block|{
name|__builtin_arm_wfe
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.hint(i32 2)
end_comment

begin_function
name|void
name|wfi
parameter_list|()
block|{
name|__builtin_arm_wfi
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.hint(i32 3)
end_comment

begin_function
name|void
name|sev
parameter_list|()
block|{
name|__builtin_arm_sev
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.hint(i32 4)
end_comment

begin_function
name|void
name|sevl
parameter_list|()
block|{
name|__builtin_arm_sevl
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.hint(i32 5)
end_comment

begin_function
name|void
name|test_barrier
parameter_list|()
block|{
name|__builtin_arm_dmb
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.arm.dmb(i32 1)
name|__builtin_arm_dsb
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.arm.dsb(i32 2)
name|__builtin_arm_isb
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.arm.isb(i32 3)
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.rbit(i32 %a)
end_comment

begin_function
name|unsigned
name|rbit
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{
return|return
name|__builtin_arm_rbit
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

