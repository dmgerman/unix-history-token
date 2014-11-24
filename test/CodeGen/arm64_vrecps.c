begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|/// Test vrecpss_f32, vrecpsd_f64 ARM64 intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// vrecpss_f32 -> FRECPS Sd,Sa,Sb
end_comment

begin_comment
comment|//
end_comment

begin_function
name|float32_t
name|test_vrecpss_f32
parameter_list|(
name|float32_t
name|Vdlow
parameter_list|,
name|float32_t
name|Vn
parameter_list|)
block|{
return|return
name|vrecpss_f32
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vrecpss_f32:
comment|// CHECK: frecps  s0, s0, s1
comment|// CHECK-NEXT: ret
block|}
end_function

begin_comment
comment|// vrecpsd_f64 -> FRECPS Dd,Da,Db
end_comment

begin_comment
comment|//
end_comment

begin_function
name|float64_t
name|test_vrecpsd_f64
parameter_list|(
name|float64_t
name|Vdlow
parameter_list|,
name|float64_t
name|Vn
parameter_list|)
block|{
return|return
name|vrecpsd_f64
argument_list|(
name|Vdlow
argument_list|,
name|Vn
argument_list|)
return|;
comment|// CHECK: test_vrecpsd_f64:
comment|// CHECK: frecps d0, d0, d1
comment|// CHECK-NEXT: ret
block|}
end_function

end_unit

