begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-unknown-unknown -target-feature +tbm -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Don't include mm_malloc.h, it's system specific.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

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
comment|// CHECK: call i32 @llvm.x86.tbm.bextri.u32
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
comment|// CHECK: call i64 @llvm.x86.tbm.bextri.u64
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
comment|// CHECK: call i64 @llvm.x86.tbm.bextri.u64
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

