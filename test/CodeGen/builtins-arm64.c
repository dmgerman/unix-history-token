begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-unknown-linux -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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

begin_function
name|void
modifier|*
name|tp
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__builtin_thread_pointer
argument_list|()
return|;
comment|// CHECK: call {{.*}} @llvm.thread.pointer()
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.bitreverse.i32(i32 %a)
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
comment|// CHECK: call {{.*}} @llvm.bitreverse.i64(i64 %a)
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

begin_function
name|unsigned
name|rsr
parameter_list|()
block|{
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = call i64 @llvm.read_register.i64(metadata ![[M0:[0-9]]])
comment|// CHECK-NEXT: trunc i64 [[V0]] to i32
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"1:2:3:4:5"
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|rsr64
parameter_list|()
block|{
comment|// CHECK: call i64 @llvm.read_register.i64(metadata ![[M0:[0-9]]])
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"1:2:3:4:5"
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|rsrp
parameter_list|()
block|{
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = call i64 @llvm.read_register.i64(metadata ![[M0:[0-9]]])
comment|// CHECK-NEXT: inttoptr i64 [[V0]] to i8*
return|return
name|__builtin_arm_rsrp
argument_list|(
literal|"1:2:3:4:5"
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|wsr
parameter_list|(
name|unsigned
name|v
parameter_list|)
block|{
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = zext i32 %v to i64
comment|// CHECK-NEXT: call void @llvm.write_register.i64(metadata ![[M0:[0-9]]], i64 [[V0]])
name|__builtin_arm_wsr
argument_list|(
literal|"1:2:3:4:5"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|wsr64
parameter_list|(
name|unsigned
name|long
name|v
parameter_list|)
block|{
comment|// CHECK: call void @llvm.write_register.i64(metadata ![[M0:[0-9]]], i64 %v)
name|__builtin_arm_wsr64
argument_list|(
literal|"1:2:3:4:5"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|wsrp
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
block|{
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = ptrtoint i8* %v to i64
comment|// CHECK-NEXT: call void @llvm.write_register.i64(metadata ![[M0:[0-9]]], i64 [[V0]])
name|__builtin_arm_wsrp
argument_list|(
literal|"1:2:3:4:5"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: ![[M0]] = !{!"1:2:3:4:5"}
end_comment

end_unit

