begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wall -Werror -triple thumbv7-eabi -target-cpu cortex-a8 -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

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
name|dbg
parameter_list|()
block|{
name|__builtin_arm_dbg
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @llvm.arm.dbg(i32 0)
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

begin_function
name|void
name|prefetch
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|__builtin_arm_prefetch
argument_list|(
operator|&
name|i
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}} @llvm.prefetch(i8* %{{.*}}, i32 0, i32 3, i32 1)
name|__builtin_arm_prefetch
argument_list|(
operator|&
name|i
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}} @llvm.prefetch(i8* %{{.*}}, i32 1, i32 3, i32 1)
name|__builtin_arm_prefetch
argument_list|(
operator|&
name|i
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}} @llvm.prefetch(i8* %{{.*}}, i32 1, i32 3, i32 0)
block|}
end_function

begin_function
name|void
name|ldc
parameter_list|(
specifier|const
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @ldc(i8* %i)
comment|// CHECK: call void @llvm.arm.ldc(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_ldc
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ldcl
parameter_list|(
specifier|const
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @ldcl(i8* %i)
comment|// CHECK: call void @llvm.arm.ldcl(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_ldcl
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ldc2
parameter_list|(
specifier|const
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @ldc2(i8* %i)
comment|// CHECK: call void @llvm.arm.ldc2(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_ldc2
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ldc2l
parameter_list|(
specifier|const
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @ldc2l(i8* %i)
comment|// CHECK: call void @llvm.arm.ldc2l(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_ldc2l
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|stc
parameter_list|(
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @stc(i8* %i)
comment|// CHECK: call void @llvm.arm.stc(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_stc
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|stcl
parameter_list|(
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @stcl(i8* %i)
comment|// CHECK: call void @llvm.arm.stcl(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_stcl
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|stc2
parameter_list|(
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @stc2(i8* %i)
comment|// CHECK: call void @llvm.arm.stc2(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_stc2
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|stc2l
parameter_list|(
name|void
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: define void @stc2l(i8* %i)
comment|// CHECK: call void @llvm.arm.stc2l(i32 1, i32 2, i8* %i)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_stc2l
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cdp
parameter_list|()
block|{
comment|// CHECK: define void @cdp()
comment|// CHECK: call void @llvm.arm.cdp(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_cdp
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cdp2
parameter_list|()
block|{
comment|// CHECK: define void @cdp2()
comment|// CHECK: call void @llvm.arm.cdp2(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6)
comment|// CHECK-NEXT: ret void
name|__builtin_arm_cdp2
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|unsigned
name|mrc
parameter_list|()
block|{
comment|// CHECK: define i32 @mrc()
comment|// CHECK: [[R:%.*]] = call i32 @llvm.arm.mrc(i32 15, i32 0, i32 13, i32 0, i32 3)
comment|// CHECK-NEXT: ret i32 [[R]]
return|return
name|__builtin_arm_mrc
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
literal|13
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|mrc2
parameter_list|()
block|{
comment|// CHECK: define i32 @mrc2()
comment|// CHECK: [[R:%.*]] = call i32 @llvm.arm.mrc2(i32 15, i32 0, i32 13, i32 0, i32 3)
comment|// CHECK-NEXT: ret i32 [[R]]
return|return
name|__builtin_arm_mrc2
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
literal|13
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|mcr
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{
comment|// CHECK: define void @mcr(i32 [[A:%.*]])
comment|// CHECK: call void @llvm.arm.mcr(i32 15, i32 0, i32 [[A]], i32 13, i32 0, i32 3)
name|__builtin_arm_mcr
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
name|a
argument_list|,
literal|13
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mcr2
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{
comment|// CHECK: define void @mcr2(i32 [[A:%.*]])
comment|// CHECK: call void @llvm.arm.mcr2(i32 15, i32 0, i32 [[A]], i32 13, i32 0, i32 3)
name|__builtin_arm_mcr2
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
name|a
argument_list|,
literal|13
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mcrr
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK: define void @mcrr(i64 %{{.*}})
comment|// CHECK: call void @llvm.arm.mcrr(i32 15, i32 0, i32 %{{[0-9]+}}, i32 %{{[0-9]+}}, i32 0)
name|__builtin_arm_mcrr
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
name|a
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mcrr2
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK: define void @mcrr2(i64 %{{.*}})
comment|// CHECK: call void @llvm.arm.mcrr2(i32 15, i32 0, i32 %{{[0-9]+}}, i32 %{{[0-9]+}}, i32 0)
name|__builtin_arm_mcrr2
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
name|a
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|uint64_t
name|mrrc
parameter_list|()
block|{
comment|// CHECK: define i64 @mrrc()
comment|// CHECK: call { i32, i32 } @llvm.arm.mrrc(i32 15, i32 0, i32 0)
return|return
name|__builtin_arm_mrrc
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|mrrc2
parameter_list|()
block|{
comment|// CHECK: define i64 @mrrc2()
comment|// CHECK: call { i32, i32 } @llvm.arm.mrrc2(i32 15, i32 0, i32 0)
return|return
name|__builtin_arm_mrrc2
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|rsr
parameter_list|()
block|{
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = call i32 @llvm.read_register.i32(metadata ![[M0:.*]])
comment|// CHECK-NEXT: ret i32 [[V0]]
return|return
name|__builtin_arm_rsr
argument_list|(
literal|"cp1:2:c3:c4:5"
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|rsr64
parameter_list|()
block|{
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = call i64 @llvm.read_register.i64(metadata ![[M1:.*]])
comment|// CHECK-NEXT: ret i64 [[V0]]
return|return
name|__builtin_arm_rsr64
argument_list|(
literal|"cp1:2:c3"
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
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = call i32 @llvm.read_register.i32(metadata ![[M2:.*]])
comment|// CHECK-NEXT: [[V1:[%A-Za-z0-9.]+]] = inttoptr i32 [[V0]] to i8*
comment|// CHECK-NEXT: ret i8* [[V1]]
return|return
name|__builtin_arm_rsrp
argument_list|(
literal|"sysreg"
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
comment|// CHECK: call void @llvm.write_register.i32(metadata ![[M0]], i32 %v)
name|__builtin_arm_wsr
argument_list|(
literal|"cp1:2:c3:c4:5"
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
name|long
name|v
parameter_list|)
block|{
comment|// CHECK: call void @llvm.write_register.i64(metadata ![[M1]], i64 %v)
name|__builtin_arm_wsr64
argument_list|(
literal|"cp1:2:c3"
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
comment|// CHECK: [[V0:[%A-Za-z0-9.]+]] = ptrtoint i8* %v to i32
comment|// CHECK-NEXT: call void @llvm.write_register.i32(metadata ![[M2]], i32 [[V0]])
name|__builtin_arm_wsrp
argument_list|(
literal|"sysreg"
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: ![[M0]] = !{!"cp1:2:c3:c4:5"}
end_comment

begin_comment
comment|// CHECK: ![[M1]] = !{!"cp1:2:c3"}
end_comment

begin_comment
comment|// CHECK: ![[M2]] = !{!"sysreg"}
end_comment

end_unit

