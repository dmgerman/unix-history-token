begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 vector compare absolute intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|uint32x2_t
name|test_vcale_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcale_f32
return|return
name|vcale_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facge.v2i32.v2f32
comment|// no check for ret here, as there is a bitcast
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcaleq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcaleq_f32
return|return
name|vcaleq_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facge.v4i32.v4f32{{.*a2,.*a1}}
comment|// no check for ret here, as there is a bitcast
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcalt_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcalt_f32
return|return
name|vcalt_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facgt.v2i32.v2f32{{.*a2,.*a1}}
comment|// no check for ret here, as there is a bitcast
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcaltq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcaltq_f32
return|return
name|vcaltq_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facgt.v4i32.v4f32{{.*a2,.*a1}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcagtq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcagtq_f64
return|return
name|vcagtq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facgt.v2i64.v2f64{{.*a1,.*a2}}
comment|// no check for ret here, as there is a bitcast
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcaltq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcaltq_f64
return|return
name|vcaltq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facgt.v2i64.v2f64{{.*a2,.*a1}}
comment|// no check for ret here, as there is a bitcast
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcageq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcageq_f64
return|return
name|vcageq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facge.v2i64.v2f64{{.*a1,.*a2}}
comment|// no check for ret here, as there is a bitcast
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcaleq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vcaleq_f64
return|return
name|vcaleq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.facge.v2i64.v2f64{{.*a2,.*a1}}
comment|// no check for ret here, as there is a bitcast
block|}
end_function

end_unit

