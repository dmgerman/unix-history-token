begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
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

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-darwin9 -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -w -o - %s | FileCheck -check-prefix=CHECK64 %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__arm64__
end_ifdef

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|// CHECK: define arm_aapcs_vfpcc %struct.homogeneous_struct @test_struct(%struct.homogeneous_struct %{{.*}})
end_comment

begin_comment
comment|// CHECK64: define %struct.homogeneous_struct @test_struct([4 x float] %{{.*}})
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

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_struct_variadic(%struct.homogeneous_struct* {{.*}}, ...)
end_comment

begin_function
name|struct
name|homogeneous_struct
name|test_struct_variadic
parameter_list|(
name|struct
name|homogeneous_struct
name|arg
parameter_list|,
modifier|...
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
comment|// CHECK: define arm_aapcs_vfpcc void @test_array(%struct.nested_array %{{.*}})
end_comment

begin_comment
comment|// CHECK64: define void @test_array([4 x double] %{{.*}})
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
comment|// CHECK: define arm_aapcs_vfpcc void @test_complex({ double, double } %{{.*}})
end_comment

begin_comment
comment|// CHECK64: define void @test_complex([2 x double] %cd.coerce)
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
comment|// CHECK: define arm_aapcs_vfpcc void @test_complex_long({ double, double } %{{.*}})
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

begin_comment
comment|// CHECK64: define void @test_big(%struct.big_struct* %{{.*}})
end_comment

begin_comment
comment|// CHECK64: call void @llvm.memcpy
end_comment

begin_comment
comment|// CHECK64: call void @big_callee(%struct.big_struct*
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

begin_comment
comment|// CHECK64: define void @test_hetero(i64 %{{.*}})
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
comment|// CHECK: define arm_aapcs_vfpcc<16 x i8> @f0(%struct.int8x16x4_t %{{.*}})
end_comment

begin_comment
comment|// CHECK64: define<16 x i8> @f0([4 x<16 x i8>] %{{.*}})
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
comment|// CHECK: define arm_aapcs_vfpcc void @test_neon(%struct.neon_struct %{{.*}})
end_comment

begin_comment
comment|// CHECK64: define void @test_neon([4 x<8 x i8>] %{{.*}})
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
comment|// CHECK-LABEL: define arm_aapcs_vfpcc void @f33(%struct.s33* byval align 1 %s)
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|struct_long_long_int
typedef|;
end_typedef

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_vfp_stack_gpr_split_1(double %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, i32 %j, i64 %k, i32 %l)
end_comment

begin_function
name|void
name|test_vfp_stack_gpr_split_1
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|,
name|double
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|long
name|long
name|k
parameter_list|,
name|int
name|l
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_vfp_stack_gpr_split_2(double %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, i32 %j, [3 x i32], [2 x i64] %k.coerce)
end_comment

begin_function
name|void
name|test_vfp_stack_gpr_split_2
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|,
name|double
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|struct_long_long_int
name|k
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_vfp_stack_gpr_split_3(%struct.struct_long_long_int* noalias sret %agg.result, double %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, [3 x i32], [2 x i64] %k.coerce)
end_comment

begin_function
name|struct_long_long_int
name|test_vfp_stack_gpr_split_3
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|,
name|double
name|i
parameter_list|,
name|struct_long_long_int
name|k
parameter_list|)
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
range|:
literal|4
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|struct_int_bitfield_int
typedef|;
end_typedef

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_test_vfp_stack_gpr_split_bitfield(double %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, i32 %j, i32 %k, [2 x i32], [3 x i32] %l.coerce)
end_comment

begin_function
name|void
name|test_test_vfp_stack_gpr_split_bitfield
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|,
name|double
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|int
name|k
parameter_list|,
name|struct_int_bitfield_int
name|l
parameter_list|)
block|{}
end_function

begin_comment
comment|// Note: this struct requires internal padding
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|long
name|long
name|y
decl_stmt|;
block|}
name|struct_int_long_long
typedef|;
end_typedef

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_vfp_stack_gpr_split_4(double %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, i32 %j, [3 x i32], [2 x i64] %k.coerce)
end_comment

begin_function
name|void
name|test_vfp_stack_gpr_split_4
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|,
name|double
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|struct_int_long_long
name|k
parameter_list|)
block|{}
end_function

begin_comment
comment|// This very large struct (passed byval) uses up the GPRs, so no padding is needed
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
index|[
literal|17
index|]
decl_stmt|;
block|}
name|struct_seventeen_ints
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
index|[
literal|4
index|]
decl_stmt|;
block|}
name|struct_four_ints
typedef|;
end_typedef

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_vfp_stack_gpr_split_5(%struct.struct_seventeen_ints* byval align 4 %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, double %j, [4 x i32] %k.coerce)
end_comment

begin_function
name|void
name|test_vfp_stack_gpr_split_5
parameter_list|(
name|struct_seventeen_ints
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|,
name|double
name|i
parameter_list|,
name|double
name|j
parameter_list|,
name|struct_four_ints
name|k
parameter_list|)
block|{}
end_function

begin_comment
comment|// Here, parameter k would need padding to prevent it from being split, but it
end_comment

begin_comment
comment|// is passed ByVal (due to being> 64 bytes), so the backend handles this instead.
end_comment

begin_function
name|void
name|test_vfp_stack_gpr_split_6
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|double
name|f
parameter_list|,
name|double
name|g
parameter_list|,
name|double
name|h
parameter_list|,
name|double
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|struct_seventeen_ints
name|k
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define arm_aapcs_vfpcc void @test_vfp_stack_gpr_split_6(double %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, i32 %j, %struct.struct_seventeen_ints* byval align 4 %k)
end_comment

end_unit

