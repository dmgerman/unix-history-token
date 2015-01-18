begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -O3 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|void
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
comment|// CHECK: call {{.*}} @__clear_cache
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.aarch64.rbit.i32(i32 %a)
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

begin_comment
comment|// CHECK: call {{.*}} @llvm.aarch64.rbit.i64(i64 %a)
end_comment

begin_function
name|unsigned
name|long
name|long
name|rbit64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
return|return
name|__builtin_arm_rbit64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|hints
parameter_list|()
block|{
name|__builtin_arm_nop
argument_list|()
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.hint(i32 0)
name|__builtin_arm_yield
argument_list|()
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.hint(i32 1)
name|__builtin_arm_wfe
argument_list|()
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.hint(i32 2)
name|__builtin_arm_wfi
argument_list|()
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.hint(i32 3)
name|__builtin_arm_sev
argument_list|()
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.hint(i32 4)
name|__builtin_arm_sevl
argument_list|()
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.hint(i32 5)
block|}
end_function

begin_function
name|void
name|barriers
parameter_list|()
block|{
name|__builtin_arm_dmb
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.dmb(i32 1)
name|__builtin_arm_dsb
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.dsb(i32 2)
name|__builtin_arm_isb
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|//CHECK: call {{.*}} @llvm.aarch64.isb(i32 3)
block|}
end_function

begin_function
name|void
name|prefetch
parameter_list|()
block|{
name|__builtin_arm_prefetch
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// pstl3keep
comment|// CHECK: call {{.*}} @llvm.prefetch(i8* null, i32 1, i32 1, i32 1)
name|__builtin_arm_prefetch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// pldl1keep
comment|// CHECK: call {{.*}} @llvm.prefetch(i8* null, i32 0, i32 0, i32 1)
name|__builtin_arm_prefetch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// pldl1strm
comment|// CHECK: call {{.*}} @llvm.prefetch(i8* null, i32 0, i32 0, i32 1)
name|__builtin_arm_prefetch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// plil1keep
comment|// CHECK: call {{.*}} @llvm.prefetch(i8* null, i32 0, i32 3, i32 0)
block|}
end_function

end_unit

