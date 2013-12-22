begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin9 \
end_comment

begin_comment
comment|// RUN:   -target-abi aapcs \
end_comment

begin_comment
comment|// RUN:   -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   -mfloat-abi hard \
end_comment

begin_comment
comment|// RUN:   -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-unknown-nacl-gnueabi \
end_comment

begin_comment
comment|// RUN:  -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:  -mfloat-abi hard \
end_comment

begin_comment
comment|// RUN:  -ffreestanding \
end_comment

begin_comment
comment|// RUN:  -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_struct
struct|struct
name|homogeneous_struct
block|{
name|float
name|f
index|[
literal|2
index|]
decl_stmt|;
name|float
name|f3
decl_stmt|;
name|float
name|f4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc %struct.homogeneous_struct @test_struct(float %{{.*}}, float %{{.*}}, float %{{.*}}, float %{{.*}})
end_comment

begin_function_decl
specifier|extern
name|struct
name|homogeneous_struct
name|struct_callee
parameter_list|(
name|struct
name|homogeneous_struct
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|struct
name|homogeneous_struct
name|test_struct
parameter_list|(
name|struct
name|homogeneous_struct
name|arg
parameter_list|)
block|{
return|return
name|struct_callee
argument_list|(
name|arg
argument_list|)
return|;
block|}
end_function

begin_struct
struct|struct
name|nested_array
block|{
name|double
name|d
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_array(double %{{.*}}, double %{{.*}}, double %{{.*}}, double %{{.*}})
end_comment

begin_function_decl
specifier|extern
name|void
name|array_callee
parameter_list|(
name|struct
name|nested_array
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_array
parameter_list|(
name|struct
name|nested_array
name|arg
parameter_list|)
block|{
name|array_callee
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|complex_callee
parameter_list|(
name|__complex__
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_complex(double %{{.*}}, double %{{.*}})
end_comment

begin_function
name|void
name|test_complex
parameter_list|(
name|__complex__
name|double
name|cd
parameter_list|)
block|{
name|complex_callee
argument_list|(
name|cd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Long double is the same as double on AAPCS, it should be homogeneous.
end_comment

begin_function_decl
specifier|extern
name|void
name|complex_long_callee
parameter_list|(
name|__complex__
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_complex_long(double %{{.*}}, double %{{.*}})
end_comment

begin_function
name|void
name|test_complex_long
parameter_list|(
name|__complex__
name|long
name|double
name|cd
parameter_list|)
block|{
name|complex_callee
argument_list|(
name|cd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Structs with more than 4 elements of the base type are not treated
end_comment

begin_comment
comment|// as homogeneous aggregates.  Test that.
end_comment

begin_struct
struct|struct
name|big_struct
block|{
name|float
name|f1
decl_stmt|;
name|float
name|f
index|[
literal|2
index|]
decl_stmt|;
name|float
name|f3
decl_stmt|;
name|float
name|f4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_big([5 x i32] %{{.*}})
end_comment

begin_function_decl
specifier|extern
name|void
name|big_callee
parameter_list|(
name|struct
name|big_struct
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_big
parameter_list|(
name|struct
name|big_struct
name|arg
parameter_list|)
block|{
name|big_callee
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Make sure that aggregates with multiple base types are not treated as
end_comment

begin_comment
comment|// homogeneous aggregates.
end_comment

begin_struct
struct|struct
name|heterogeneous_struct
block|{
name|float
name|f1
decl_stmt|;
name|int
name|i2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_hetero([2 x i32] %{{.*}})
end_comment

begin_function_decl
specifier|extern
name|void
name|hetero_callee
parameter_list|(
name|struct
name|heterogeneous_struct
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_hetero
parameter_list|(
name|struct
name|heterogeneous_struct
name|arg
parameter_list|)
block|{
name|hetero_callee
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Neon multi-vector types are homogeneous aggregates.
end_comment

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc<16 x i8> @f0(<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}})
end_comment

begin_function
name|int8x16_t
name|f0
parameter_list|(
name|int8x16x4_t
name|v4
parameter_list|)
block|{
return|return
name|vaddq_s8
argument_list|(
name|v4
operator|.
name|val
index|[
literal|0
index|]
argument_list|,
name|v4
operator|.
name|val
index|[
literal|3
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ...and it doesn't matter whether the vectors are exactly the same, as long
end_comment

begin_comment
comment|// as they have the same size.
end_comment

begin_struct
struct|struct
name|neon_struct
block|{
name|int8x8x2_t
name|v12
decl_stmt|;
name|int32x2_t
name|v3
decl_stmt|;
name|int16x4_t
name|v4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_neon(<8 x i8> %{{.*}},<8 x i8> %{{.*}},<2 x i32> %{{.*}},<4 x i16> %{{.*}})
end_comment

begin_function_decl
specifier|extern
name|void
name|neon_callee
parameter_list|(
name|struct
name|neon_struct
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_neon
parameter_list|(
name|struct
name|neon_struct
name|arg
parameter_list|)
block|{
name|neon_callee
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define arm_aapcs_vfpcc void @f33(%struct.s33* byval %s)
end_comment

begin_struct
struct|struct
name|s33
block|{
name|char
name|buf
index|[
literal|32
operator|*
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f33
parameter_list|(
name|struct
name|s33
name|s
parameter_list|)
block|{ }
end_function

end_unit

