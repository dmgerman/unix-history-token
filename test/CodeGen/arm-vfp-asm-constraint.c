begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-unknown-unknown -mfpmath vfp -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: error:
end_comment

begin_function
name|double
name|fabs
parameter_list|(
name|double
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @fabs(
comment|// CHECK: call double asm "vabs.f64 ${0:P}, ${1:P}", "=w,w"(double
asm|__asm__("vabs.f64 %P0, %P1"           : "=w"(x)           : "w"(x));
return|return
name|x
return|;
block|}
end_function

begin_function
name|float
name|fabsf
parameter_list|(
name|float
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @fabsf(
comment|// CHECK: call float asm "vabs.f32 $0, $1", "=t,t"(float
asm|__asm__("vabs.f32 %0, %1"           : "=t"(x)           : "t"(x));
return|return
name|x
return|;
block|}
end_function

begin_function
name|double
name|sqrt
parameter_list|(
name|double
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @sqrt(
comment|// CHECK: call double asm "vsqrt.f64 ${0:P}, ${1:P}", "=w,w"(double
asm|__asm__("vsqrt.f64 %P0, %P1"           : "=w"(x)           : "w"(x));
return|return
name|x
return|;
block|}
end_function

begin_function
name|float
name|sqrtf
parameter_list|(
name|float
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @sqrtf(
comment|// CHECK: call float asm "vsqrt.f32 $0, $1", "=t,t"(float
asm|__asm__("vsqrt.f32 %0, %1"           : "=t"(x)           : "t"(x));
return|return
name|x
return|;
block|}
end_function

end_unit

