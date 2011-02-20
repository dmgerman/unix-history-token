begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin9 \
end_comment

begin_comment
comment|// RUN:   -target-abi apcs-gnu \
end_comment

begin_comment
comment|// RUN:   -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   -mfloat-abi soft \
end_comment

begin_comment
comment|// RUN:   -target-feature +soft-float-abi \
end_comment

begin_comment
comment|// RUN:   -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK: define void @f0(%struct.int8x16x2_t* sret %agg.result,<16 x i8> %{{.*}},<16 x i8> %{{.*}})
end_comment

begin_function
name|int8x16x2_t
name|f0
parameter_list|(
name|int8x16_t
name|a0
parameter_list|,
name|int8x16_t
name|a1
parameter_list|)
block|{
return|return
name|vzipq_s8
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Test direct vector passing.
end_comment

begin_typedef
typedef|typedef
name|float
name|T_float32x2
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|T_float32x4
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|T_float32x8
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|T_float32x16
name|__attribute__
typedef|((
name|__vector_size__
typedef|(64)));
end_typedef

begin_comment
comment|// CHECK: define<2 x float> @f1_0(<2 x float> %{{.*}})
end_comment

begin_function
name|T_float32x2
name|f1_0
parameter_list|(
name|T_float32x2
name|a0
parameter_list|)
block|{
return|return
name|a0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define<4 x float> @f1_1(<4 x float> %{{.*}})
end_comment

begin_function
name|T_float32x4
name|f1_1
parameter_list|(
name|T_float32x4
name|a0
parameter_list|)
block|{
return|return
name|a0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @f1_2(<8 x float>* sret %{{.*}},<8 x float> %{{.*}})
end_comment

begin_function
name|T_float32x8
name|f1_2
parameter_list|(
name|T_float32x8
name|a0
parameter_list|)
block|{
return|return
name|a0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @f1_3(<16 x float>* sret %{{.*}},<16 x float> %{{.*}})
end_comment

begin_function
name|T_float32x16
name|f1_3
parameter_list|(
name|T_float32x16
name|a0
parameter_list|)
block|{
return|return
name|a0
return|;
block|}
end_function

end_unit

