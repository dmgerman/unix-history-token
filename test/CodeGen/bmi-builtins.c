begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +bmi -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/bmi-intrinsics-fast-isel.ll
end_comment

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
comment|// CHECK-LABEL: test__tzcnt_u16
comment|// CHECK: zext i16 %{{.*}} to i32
comment|// CHECK: icmp ne i32 %{{.*}}, 0
comment|// CHECK: i16 @llvm.cttz.i16(i16 %{{.*}}, i1 true)
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
comment|// CHECK-LABEL: test__andn_u32
comment|// CHECK: xor i32 %{{.*}}, -1
comment|// CHECK: and i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__bextr_u32
comment|// CHECK: i32 @llvm.x86.bmi.bextr.32(i32 %{{.*}}, i32 %{{.*}})
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
comment|// CHECK-LABEL: test__blsi_u32
comment|// CHECK: sub i32 0, %{{.*}}
comment|// CHECK: and i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__blsmsk_u32
comment|// CHECK: sub i32 %{{.*}}, 1
comment|// CHECK: xor i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__blsr_u32
comment|// CHECK: sub i32 %{{.*}}, 1
comment|// CHECK: and i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__tzcnt_u32
comment|// CHECK: icmp ne i32 %{{.*}}, 0
comment|// CHECK: i32 @llvm.cttz.i32(i32 %{{.*}}, i1 true)
return|return
name|__tzcnt_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_tzcnt_32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_tzcnt_32
comment|// CHECK: icmp ne i32 %{{.*}}, 0
comment|// CHECK: i32 @llvm.cttz.i32(i32 %{{.*}}, i1 true)
return|return
name|_mm_tzcnt_32
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
comment|// CHECK-LABEL: test__andn_u64
comment|// CHECK: xor i64 %{{.*}}, -1
comment|// CHECK: and i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__bextr_u64
comment|// CHECK: i64 @llvm.x86.bmi.bextr.64(i64 %{{.*}}, i64 %{{.*}})
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
comment|// CHECK-LABEL: test__blsi_u64
comment|// CHECK: sub i64 0, %{{.*}}
comment|// CHECK: and i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__blsmsk_u64
comment|// CHECK: sub i64 %{{.*}}, 1
comment|// CHECK: xor i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__blsr_u64
comment|// CHECK: sub i64 %{{.*}}, 1
comment|// CHECK: and i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test__tzcnt_u64
comment|// CHECK: icmp ne i64 %{{.*}}, 0
comment|// CHECK: i64 @llvm.cttz.i64(i64 %{{.*}}, i1 true)
return|return
name|__tzcnt_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_tzcnt_64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_tzcnt_64
comment|// CHECK: icmp ne i64 %{{.*}}, 0
comment|// CHECK: i64 @llvm.cttz.i64(i64 %{{.*}}, i1 true)
return|return
name|_mm_tzcnt_64
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
comment|// CHECK-LABEL: test_tzcnt_u16
comment|// CHECK: zext i16 %{{.*}} to i32
comment|// CHECK: icmp ne i32 %{{.*}}, 0
comment|// CHECK: i16 @llvm.cttz.i16(i16 %{{.*}}, i1 true)
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
comment|// CHECK-LABEL: test_andn_u32
comment|// CHECK: xor i32 %{{.*}}, -1
comment|// CHECK: and i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_bextr_u32
comment|// CHECK: and i32 %{{.*}}, 255
comment|// CHECK: and i32 %{{.*}}, 255
comment|// CHECK: shl i32 %{{.*}}, 8
comment|// CHECK: or i32 %{{.*}}, %{{.*}}
comment|// CHECK: i32 @llvm.x86.bmi.bextr.32(i32 %{{.*}}, i32 %{{.*}})
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
comment|// CHECK-LABEL: test_blsi_u32
comment|// CHECK: sub i32 0, %{{.*}}
comment|// CHECK: and i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_blsmsk_u32
comment|// CHECK: sub i32 %{{.*}}, 1
comment|// CHECK: xor i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_blsr_u32
comment|// CHECK: sub i32 %{{.*}}, 1
comment|// CHECK: and i32 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_tzcnt_u32
comment|// CHECK: icmp ne i32 %{{.*}}, 0
comment|// CHECK: i32 @llvm.cttz.i32(i32 %{{.*}}, i1 true)
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
comment|// CHECK-LABEL: test_andn_u64
comment|// CHECK: xor i64 %{{.*}}, -1
comment|// CHECK: and i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_bextr_u64
comment|// CHECK: and i32 %{{.*}}, 255
comment|// CHECK: and i32 %{{.*}}, 255
comment|// CHECK: shl i32 %{{.*}}, 8
comment|// CHECK: or i32 %{{.*}}, %{{.*}}
comment|// CHECK: zext i32 %{{.*}} to i64
comment|// CHECK: i64 @llvm.x86.bmi.bextr.64(i64 %{{.*}}, i64 %{{.*}})
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
comment|// CHECK-LABEL: test_blsi_u64
comment|// CHECK: sub i64 0, %{{.*}}
comment|// CHECK: and i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_blsmsk_u64
comment|// CHECK: sub i64 %{{.*}}, 1
comment|// CHECK: xor i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_blsr_u64
comment|// CHECK: sub i64 %{{.*}}, 1
comment|// CHECK: and i64 %{{.*}}, %{{.*}}
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
comment|// CHECK-LABEL: test_tzcnt_u64
comment|// CHECK: icmp ne i64 %{{.*}}, 0
comment|// CHECK: i64 @llvm.cttz.i64(i64 %{{.*}}, i1 true)
return|return
name|_tzcnt_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

end_unit

