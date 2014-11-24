begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +bmi -emit-llvm -o - | FileCheck %s
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

begin_comment
comment|// The double underscore intrinsics are for compatibility with
end_comment

begin_comment
comment|// AMD's BMI interface. The single underscore intrinsics
end_comment

begin_comment
comment|// are for compatibility with Intel's BMI interface.
end_comment

begin_comment
comment|// Apart from the underscores, the interfaces are identical
end_comment

begin_comment
comment|// except in one case: although the 'bextr' register-form
end_comment

begin_comment
comment|// instruction is identical in hardware, the AMD and Intel
end_comment

begin_comment
comment|// intrinsics are different!
end_comment

begin_function
name|unsigned
name|short
name|test__tzcnt_u16
parameter_list|(
name|unsigned
name|short
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.cttz.i16
return|return
name|__tzcnt_u16
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__andn_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = xor i32 %{{.*}}, -1
comment|// CHECK-NEXT: %{{.*}} = and i32 %{{.*}}, [[DEST]]
return|return
name|__andn_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__bextr_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.bextr.32
return|return
name|__bextr_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blsi_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = sub i32 0, [[SRC:%.*]]
comment|// CHECK-NEXT: %{{.*}} = and i32 [[SRC]], [[DEST]]
return|return
name|__blsi_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blsmsk_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = xor i32 [[DEST]], [[SRC]]
return|return
name|__blsmsk_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__blsr_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = and i32 [[DEST]], [[SRC]]
return|return
name|__blsr_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test__tzcnt_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.cttz.i32
return|return
name|__tzcnt_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__andn_u64
parameter_list|(
name|unsigned
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|__Y
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = xor i64 %{{.*}}, -1
comment|// CHECK-NEXT: %{{.*}} = and i64 %{{.*}}, [[DEST]]
return|return
name|__andn_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__bextr_u64
parameter_list|(
name|unsigned
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.bextr.64
return|return
name|__bextr_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blsi_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = sub i64 0, [[SRC:%.*]]
comment|// CHECK-NEXT: %{{.*}} = and i64 [[SRC]], [[DEST]]
return|return
name|__blsi_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blsmsk_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = xor i64 [[DEST]], [[SRC]]
return|return
name|__blsmsk_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__blsr_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = and i64 [[DEST]], [[SRC]]
return|return
name|__blsr_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test__tzcnt_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.cttz.i64
return|return
name|__tzcnt_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Intel intrinsics
end_comment

begin_function
name|unsigned
name|short
name|test_tzcnt_u16
parameter_list|(
name|unsigned
name|short
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.cttz.i16
return|return
name|_tzcnt_u16
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_andn_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = xor i32 %{{.*}}, -1
comment|// CHECK-NEXT: %{{.*}} = and i32 %{{.*}}, [[DEST]]
return|return
name|_andn_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_bextr_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|,
name|unsigned
name|int
name|__Z
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.bextr.32
return|return
name|_bextr_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_blsi_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = sub i32 0, [[SRC:%.*]]
comment|// CHECK-NEXT: %{{.*}} = and i32 [[SRC]], [[DEST]]
return|return
name|_blsi_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_blsmsk_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = xor i32 [[DEST]], [[SRC]]
return|return
name|_blsmsk_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_blsr_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i32 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = and i32 [[DEST]], [[SRC]]
return|return
name|_blsr_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_tzcnt_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.cttz.i32
return|return
name|_tzcnt_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_andn_u64
parameter_list|(
name|unsigned
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|__Y
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = xor i64 %{{.*}}, -1
comment|// CHECK-NEXT: %{{.*}} = and i64 %{{.*}}, [[DEST]]
return|return
name|_andn_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_bextr_u64
parameter_list|(
name|unsigned
name|long
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|,
name|unsigned
name|int
name|__Z
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.bextr.64
return|return
name|_bextr_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_blsi_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = sub i64 0, [[SRC:%.*]]
comment|// CHECK-NEXT: %{{.*}} = and i64 [[SRC]], [[DEST]]
return|return
name|_blsi_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_blsmsk_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = xor i64 [[DEST]], [[SRC]]
return|return
name|_blsmsk_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_blsr_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: [[DEST:%.*]] = add i64 [[SRC:%.*]], -1
comment|// CHECK-NEXT: %{{.*}} = and i64 [[DEST]], [[SRC]]
return|return
name|_blsr_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_tzcnt_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.cttz.i64
return|return
name|_tzcnt_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

end_unit

