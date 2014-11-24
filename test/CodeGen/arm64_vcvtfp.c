begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float64x2_t
name|test_vcvt_f64_f32
parameter_list|(
name|float32x2_t
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_f64_f32
return|return
name|vcvt_f64_f32
argument_list|(
name|x
argument_list|)
return|;
comment|// CHECK: fpext<2 x float> {{%.*}} to<2 x double>
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float64x2_t
name|test_vcvt_high_f64_f32
parameter_list|(
name|float32x4_t
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_high_f64_f32
return|return
name|vcvt_high_f64_f32
argument_list|(
name|x
argument_list|)
return|;
comment|// CHECK: [[HIGH:%.*]] = shufflevector<4 x float> {{%.*}},<4 x float> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK-NEXT: fpext<2 x float> [[HIGH]] to<2 x double>
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvt_f32_f64
parameter_list|(
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK: test_vcvt_f32_f64
return|return
name|vcvt_f32_f64
argument_list|(
name|v
argument_list|)
return|;
comment|// CHECK: fptrunc<2 x double> {{%.*}} to<2 x float>
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvt_high_f32_f64
parameter_list|(
name|float32x2_t
name|x
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK: test_vcvt_high_f32_f64
return|return
name|vcvt_high_f32_f64
argument_list|(
name|x
argument_list|,
name|v
argument_list|)
return|;
comment|// CHECK: [[TRUNC:%.*]] = fptrunc<2 x double> {{.*}} to<2 x float>
comment|// CHECK-NEXT: shufflevector<2 x float> {{.*}},<2 x float> [[TRUNC]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvtx_f32_f64
parameter_list|(
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK: test_vcvtx_f32_f64
return|return
name|vcvtx_f32_f64
argument_list|(
name|v
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fcvtxn.v2f32.v2f64
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvtx_high_f32_f64
parameter_list|(
name|float32x2_t
name|x
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK: test_vcvtx_high_f32_f64
return|return
name|vcvtx_high_f32_f64
argument_list|(
name|x
argument_list|,
name|v
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fcvtxn.v2f32.v2f64
comment|// CHECK: shufflevector
comment|// CHECK: ret
block|}
end_function

end_unit

