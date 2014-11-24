begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int32x2_t
name|rnd1
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrnd_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x float> @llvm.trunc.v2f32(<2 x float>
end_comment

begin_function
name|int32x4_t
name|rnd3
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<4 x float> @llvm.trunc.v4f32(<4 x float>
end_comment

begin_function
name|int64x2_t
name|rnd5
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.trunc.v2f64(<2 x double>
end_comment

begin_function
name|int32x2_t
name|rnd7
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndn_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x float> @llvm.aarch64.neon.frintn.v2f32(<2 x float>
end_comment

begin_function
name|int32x4_t
name|rnd8
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndnq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<4 x float> @llvm.aarch64.neon.frintn.v4f32(<4 x float>
end_comment

begin_function
name|int64x2_t
name|rnd9
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndnq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.aarch64.neon.frintn.v2f64(<2 x double>
end_comment

begin_function
name|int64x2_t
name|rnd10
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndnq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.aarch64.neon.frintn.v2f64(<2 x double>
end_comment

begin_function
name|int32x2_t
name|rnd11
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndm_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x float> @llvm.floor.v2f32(<2 x float>
end_comment

begin_function
name|int32x4_t
name|rnd12
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndmq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<4 x float> @llvm.floor.v4f32(<4 x float>
end_comment

begin_function
name|int64x2_t
name|rnd13
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndmq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.floor.v2f64(<2 x double>
end_comment

begin_function
name|int64x2_t
name|rnd14
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndmq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.floor.v2f64(<2 x double>
end_comment

begin_function
name|int32x2_t
name|rnd15
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndp_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x float> @llvm.ceil.v2f32(<2 x float>
end_comment

begin_function
name|int32x4_t
name|rnd16
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndpq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<4 x float> @llvm.ceil.v4f32(<4 x float>
end_comment

begin_function
name|int64x2_t
name|rnd18
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndpq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.ceil.v2f64(<2 x double>
end_comment

begin_function
name|int32x2_t
name|rnd19
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrnda_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x float> @llvm.round.v2f32(<2 x float>
end_comment

begin_function
name|int32x4_t
name|rnd20
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndaq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<4 x float> @llvm.round.v4f32(<4 x float>
end_comment

begin_function
name|int64x2_t
name|rnd22
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndaq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.round.v2f64(<2 x double>
end_comment

begin_function
name|int32x2_t
name|rnd23
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndx_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x float> @llvm.rint.v2f32(<2 x float>
end_comment

begin_function
name|int32x4_t
name|rnd24
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndxq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<4 x float> @llvm.rint.v4f32(<4 x float>
end_comment

begin_function
name|int64x2_t
name|rnd25
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndxq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call<2 x double> @llvm.rint.v2f64(<2 x double>
end_comment

end_unit

