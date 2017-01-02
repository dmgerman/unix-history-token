begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -O3 -triple=x86_64-unknown-unknown -target-feature +tbm -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// FIXME: The code generation checks for add/sub and/or are depending on the optimizer.
end_comment

begin_comment
comment|// The REQUIRES keyword will be removed when the FIXME is complete.
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/tbm-intrinsics-fast-isel.ll
end_comment

begin_function
name|unsigned
name|int
name|test__bextri_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__bextri_u32
comment|// CHECK: call i32 @llvm.x86.tbm.bextri.u32(i32 %{{.*}}, i32 1)
return|return
name|__bextri_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__bextri_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__bextri_u64
comment|// CHECK: call i64 @llvm.x86.tbm.bextri.u64(i64 %{{.*}}, i64 2)
return|return
name|__bextri_u64
argument_list|(
name|a
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__bextri_u64_bigint
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__bextri_u64_bigint
comment|// CHECK: call i64 @llvm.x86.tbm.bextri.u64(i64 %{{.*}}, i64 549755813887)
return|return
name|__bextri_u64
argument_list|(
name|a
argument_list|,
literal|0x7fffffffffLL
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blcfill_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcfill_u32
comment|// CHECK: [[TMP:%.*]] = add i32 [[SRC:%.*]], 1
comment|// CHECK-NEXT: %{{.*}} = and i32 [[TMP]], [[SRC]]
return|return
name|__blcfill_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blcfill_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcfill_u64
comment|// CHECK: [[TMPT:%.*]] = add i64 [[SRC:%.*]], 1
comment|// CHECK-NEXT: %{{.*}} = and i64 [[TMP]], [[SRC]]
return|return
name|__blcfill_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blci_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blci_u32
comment|// CHECK: [[TMP:%.*]] = sub i32 -2, [[SRC:%.*]]
comment|// CHECK-NEXT: %{{.*}} = or i32 [[TMP]], [[SRC]]
return|return
name|__blci_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blci_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blci_u64
comment|// CHECK: [[TMP:%.*]] = sub i64 -2, [[SRC:%.*]]
comment|// CHECK-NEXT: %{{.*}} = or i64 [[TMP]], [[SRC]]
return|return
name|__blci_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blcic_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcic_u32
comment|// CHECK: [[TMP1:%.*]] = xor i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i32 [[SRC]], 1
comment|// CHECK-NEXT: {{.*}} = and i32 [[TMP2]], [[TMP1]]
return|return
name|__blcic_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blcic_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcic_u64
comment|// CHECK: [[TMP1:%.*]] = xor i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i64 [[SRC]], 1
comment|// CHECK-NEXT: {{.*}} = and i64 [[TMP2]], [[TMP1]]
return|return
name|__blcic_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blcmsk_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcmsk_u32
comment|// CHECK: [[TMP:%.*]] = add i32 [[SRC:%.*]], 1
comment|// CHECK-NEXT: {{.*}} = xor i32 [[TMP]], [[SRC]]
return|return
name|__blcmsk_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blcmsk_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcmsk_u64
comment|// CHECK: [[TMP:%.*]] = add i64 [[SRC:%.*]], 1
comment|// CHECK-NEXT: {{.*}} = xor i64 [[TMP]], [[SRC]]
return|return
name|__blcmsk_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blcs_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcs_u32
comment|// CHECK: [[TMP:%.*]] = add i32 [[SRC:%.*]], 1
comment|// CHECK-NEXT: {{.*}} = or i32 [[TMP]], [[SRC]]
return|return
name|__blcs_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blcs_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blcs_u64
comment|// CHECK: [[TMP:%.*]] = add i64 [[SRC:%.*]], 1
comment|// CHECK-NEXT: {{.*}} = or i64 [[TMP]], [[SRC]]
return|return
name|__blcs_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blsfill_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blsfill_u32
comment|// CHECK: [[TMP:%.*]] = add i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: {{.*}} = or i32 [[TMP]], [[SRC]]
return|return
name|__blsfill_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blsfill_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blsfill_u64
comment|// CHECK: [[TMP:%.*]] = add i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: {{.*}} = or i64 [[TMP]], [[SRC]]
return|return
name|__blsfill_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blsic_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blsic_u32
comment|// CHECK: [[TMP1:%.*]] = xor i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: {{.*}} = or i32 [[TMP2]], [[TMP1]]
return|return
name|__blsic_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blsic_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__blsic_u64
comment|// CHECK: [[TMP1:%.*]] = xor i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: {{.*}} = or i64 [[TMP2]], [[TMP1]]
return|return
name|__blsic_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__t1mskc_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__t1mskc_u32
comment|// CHECK: [[TMP1:%.*]] = xor i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i32 [[SRC:%.*]], 1
comment|// CHECK-NEXT: {{.*}} = or i32 [[TMP2]], [[TMP1]]
return|return
name|__t1mskc_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__t1mskc_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__t1mskc_u64
comment|// CHECK: [[TMP1:%.*]] = xor i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i64 [[SRC:%.*]], 1
comment|// CHECK-NEXT: {{.*}} = or i64 [[TMP2]], [[TMP1]]
return|return
name|__t1mskc_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__tzmsk_u32
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__tzmsk_u32
comment|// CHECK: [[TMP1:%.*]] = xor i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: {{.*}} = and i32 [[TMP2]], [[TMP1]]
return|return
name|__tzmsk_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__tzmsk_u64
parameter_list|(
name|unsigned
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test__tzmsk_u64
comment|// CHECK: [[TMP1:%.*]] = xor i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: [[TMP2:%.*]] = add i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: {{.*}} = and i64 [[TMP2]], [[TMP1]]
return|return
name|__tzmsk_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

