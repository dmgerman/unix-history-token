begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -target-abi darwinpcs -ffreestanding -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define signext i8 @f0()
end_comment

begin_function
name|char
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Struct as return type. Aggregates<= 16 bytes are passed directly and round
end_comment

begin_comment
comment|// up to multiple of 8 bytes.
end_comment

begin_comment
comment|// CHECK: define i64 @f1()
end_comment

begin_struct
struct|struct
name|s1
block|{
name|char
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s1
name|f1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f2()
end_comment

begin_struct
struct|struct
name|s2
block|{
name|short
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s2
name|f2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f3()
end_comment

begin_struct
struct|struct
name|s3
block|{
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s3
name|f3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f4()
end_comment

begin_struct
struct|struct
name|s4
block|{
struct|struct
name|s4_0
block|{
name|int
name|f0
decl_stmt|;
block|}
name|f0
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s4
name|f4
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f5()
end_comment

begin_struct
struct|struct
name|s5
block|{
struct|struct
block|{ }
name|f0
struct|;
name|int
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s5
name|f5
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f6()
end_comment

begin_struct
struct|struct
name|s6
block|{
name|int
name|f0
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s6
name|f6
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f7()
end_comment

begin_struct
struct|struct
name|s7
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f0
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s7
name|f7
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f8()
end_comment

begin_struct
struct|struct
name|s8
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f0
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s8
name|f8
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f9()
end_comment

begin_struct
struct|struct
name|s9
block|{
name|int
name|f0
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s9
name|f9
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f10()
end_comment

begin_struct
struct|struct
name|s10
block|{
name|int
name|f0
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s10
name|f10
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f11()
end_comment

begin_struct
struct|struct
name|s11
block|{
name|int
label|:
literal|0
expr_stmt|;
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s11
name|f11
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f12()
end_comment

begin_union
union|union
name|u12
block|{
name|char
name|f0
decl_stmt|;
name|short
name|f1
decl_stmt|;
name|int
name|f2
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u12
name|f12
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// Homogeneous Aggregate as return type will be passed directly.
end_comment

begin_comment
comment|// CHECK: define %struct.s13 @f13()
end_comment

begin_struct
struct|struct
name|s13
block|{
name|float
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s13
name|f13
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define %union.u14 @f14()
end_comment

begin_union
union|union
name|u14
block|{
name|float
name|f0
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u14
name|f14
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f15()
end_comment

begin_function
name|void
name|f15
parameter_list|(
name|struct
name|s7
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f16()
end_comment

begin_function
name|void
name|f16
parameter_list|(
name|struct
name|s8
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f17()
end_comment

begin_struct
struct|struct
name|s17
block|{
name|short
name|f0
range|:
literal|13
decl_stmt|;
name|char
name|f1
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s17
name|f17
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f18()
end_comment

begin_struct
struct|struct
name|s18
block|{
name|short
name|f0
decl_stmt|;
name|char
name|f1
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s18
name|f18
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f19()
end_comment

begin_struct
struct|struct
name|s19
block|{
name|int
name|f0
decl_stmt|;
name|struct
name|s8
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s19
name|f19
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f20()
end_comment

begin_struct
struct|struct
name|s20
block|{
name|struct
name|s8
name|f1
decl_stmt|;
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s20
name|f20
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f21()
end_comment

begin_struct
struct|struct
name|s21
block|{
struct|struct
block|{}
name|f1
struct|;
name|int
name|f0
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s21
name|f21
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f22()
end_comment

begin_comment
comment|// CHECK: define i64 @f23()
end_comment

begin_comment
comment|// CHECK: define i64 @f24()
end_comment

begin_comment
comment|// CHECK: define i128 @f25()
end_comment

begin_comment
comment|// CHECK: define { float, float } @f26()
end_comment

begin_comment
comment|// CHECK: define { double, double } @f27()
end_comment

begin_function
specifier|_Complex
name|char
name|f22
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
specifier|_Complex
name|short
name|f23
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
specifier|_Complex
name|int
name|f24
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
specifier|_Complex
name|long
name|long
name|f25
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
specifier|_Complex
name|float
name|f26
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
specifier|_Complex
name|double
name|f27
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f28()
end_comment

begin_struct
struct|struct
name|s28
block|{
specifier|_Complex
name|char
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s28
name|f28
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f29()
end_comment

begin_struct
struct|struct
name|s29
block|{
specifier|_Complex
name|short
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s29
name|f29
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f30()
end_comment

begin_struct
struct|struct
name|s30
block|{
specifier|_Complex
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s30
name|f30
parameter_list|()
block|{}
end_function

begin_struct
struct|struct
name|s31
block|{
name|char
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f31
parameter_list|(
name|struct
name|s31
name|s
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @f31(i64 %s.coerce)
end_comment

begin_comment
comment|// CHECK: %s = alloca %struct.s31, align 8
end_comment

begin_comment
comment|// CHECK: trunc i64 %s.coerce to i8
end_comment

begin_comment
comment|// CHECK: store i8 %{{.*}},
end_comment

begin_struct
struct|struct
name|s32
block|{
name|double
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f32
parameter_list|(
name|struct
name|s32
name|s
parameter_list|)
block|{ }
end_function

begin_comment
comment|// Expand Homogeneous Aggregate.
end_comment

begin_comment
comment|// CHECK: @f32(double %{{.*}})
end_comment

begin_comment
comment|// A composite type larger than 16 bytes should be passed indirectly.
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

begin_comment
comment|// CHECK: define void @f33(%struct.s33* %s)
end_comment

begin_struct
struct|struct
name|s34
block|{
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|f34
parameter_list|(
name|struct
name|s34
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g34
parameter_list|(
name|struct
name|s34
modifier|*
name|s
parameter_list|)
block|{
name|f34
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @g34(%struct.s34* %s)
end_comment

begin_comment
comment|// CHECK: %[[a:.*]] = load i8* %{{.*}}
end_comment

begin_comment
comment|// CHECK: zext i8 %[[a]] to i64
end_comment

begin_comment
comment|// CHECK: call void @f34(i64 %{{.*}})
end_comment

begin_comment
comment|/*  * Check that va_arg accesses stack according to ABI alignment  */
end_comment

begin_function
name|long
name|long
name|t1
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: t1
name|__builtin_va_list
name|ap
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: add i32 %{{.*}} 7
comment|// CHECK-NOT: and i32 %{{.*}} -8
name|long
name|long
name|ll
init|=
name|__builtin_va_arg
argument_list|(
argument|ap
argument_list|,
argument|long long
argument_list|)
decl_stmt|;
name|__builtin_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|ll
return|;
block|}
end_function

begin_function
name|double
name|t2
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: t2
name|__builtin_va_list
name|ap
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: add i32 %{{.*}} 7
comment|// CHECK-NOT: and i32 %{{.*}} -8
name|double
name|ll
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|double
argument_list|)
decl_stmt|;
name|__builtin_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|ll
return|;
block|}
end_function

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// Homogeneous Vector Aggregate as return type and argument type.
end_comment

begin_comment
comment|// CHECK: define %struct.int8x16x2_t @f0_0(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
end_comment

begin_function
name|int8x16x2_t
name|f0_0
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
comment|// Vector with length bigger than 16-byte is illegal and is passed indirectly.
end_comment

begin_comment
comment|// CHECK: define void @f1_2(<8 x float>* noalias sret  %{{.*}},<8 x float>*)
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
comment|// CHECK: define void @f1_3(<16 x float>* noalias sret %{{.*}},<16 x float>*)
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

begin_comment
comment|// Testing alignment with aggregates: HFA, aggregates with size<= 16 bytes and
end_comment

begin_comment
comment|// aggregates with size> 16 bytes.
end_comment

begin_struct
struct|struct
name|s35
block|{
name|float
name|v
index|[
literal|4
index|]
decl_stmt|;
comment|//Testing HFA.
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s35
name|s35_with_align
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|4
argument|))
argument_list|)
name|float
name|float32x4_t
typedef|;
end_typedef

begin_function
name|float32x4_t
name|f35
parameter_list|(
name|int
name|i
parameter_list|,
name|s35_with_align
name|s1
parameter_list|,
name|s35_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define<4 x float> @f35(i32 %i, float %s1.0, float %s1.1, float %s1.2, float %s1.3, float %s2.0, float %s2.1, float %s2.2, float %s2.3)
comment|// CHECK: %s1 = alloca %struct.s35, align 16
comment|// CHECK: %s2 = alloca %struct.s35, align 16
comment|// CHECK: %[[a:.*]] = bitcast %struct.s35* %s1 to<4 x float>*
comment|// CHECK: load<4 x float>* %[[a]], align 16
comment|// CHECK: %[[b:.*]] = bitcast %struct.s35* %s2 to<4 x float>*
comment|// CHECK: load<4 x float>* %[[b]], align 16
name|float32x4_t
name|v
init|=
name|vaddq_f32
argument_list|(
operator|*
operator|(
name|float32x4_t
operator|*
operator|)
operator|&
name|s1
argument_list|,
operator|*
operator|(
name|float32x4_t
operator|*
operator|)
operator|&
name|s2
argument_list|)
decl_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_struct
struct|struct
name|s36
block|{
name|int
name|v
index|[
literal|4
index|]
decl_stmt|;
comment|//Testing 16-byte aggregate.
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s36
name|s36_with_align
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|4
argument|))
argument_list|)
name|int
name|int32x4_t
typedef|;
end_typedef

begin_function
name|int32x4_t
name|f36
parameter_list|(
name|int
name|i
parameter_list|,
name|s36_with_align
name|s1
parameter_list|,
name|s36_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define<4 x i32> @f36(i32 %i, i128 %s1.coerce, i128 %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s36, align 16
comment|// CHECK: %s2 = alloca %struct.s36, align 16
comment|// CHECK: store i128 %s1.coerce, i128* %{{.*}}, align 1
comment|// CHECK: store i128 %s2.coerce, i128* %{{.*}}, align 1
comment|// CHECK: %[[a:.*]] = bitcast %struct.s36* %s1 to<4 x i32>*
comment|// CHECK: load<4 x i32>* %[[a]], align 16
comment|// CHECK: %[[b:.*]] = bitcast %struct.s36* %s2 to<4 x i32>*
comment|// CHECK: load<4 x i32>* %[[b]], align 16
name|int32x4_t
name|v
init|=
name|vaddq_s32
argument_list|(
operator|*
operator|(
name|int32x4_t
operator|*
operator|)
operator|&
name|s1
argument_list|,
operator|*
operator|(
name|int32x4_t
operator|*
operator|)
operator|&
name|s2
argument_list|)
decl_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_struct
struct|struct
name|s37
block|{
name|int
name|v
index|[
literal|18
index|]
decl_stmt|;
comment|//Testing large aggregate.
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s37
name|s37_with_align
typedef|;
end_typedef

begin_function
name|int32x4_t
name|f37
parameter_list|(
name|int
name|i
parameter_list|,
name|s37_with_align
name|s1
parameter_list|,
name|s37_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define<4 x i32> @f37(i32 %i, %struct.s37* %s1, %struct.s37* %s2)
comment|// CHECK: %[[a:.*]] = bitcast %struct.s37* %s1 to<4 x i32>*
comment|// CHECK: load<4 x i32>* %[[a]], align 16
comment|// CHECK: %[[b:.*]] = bitcast %struct.s37* %s2 to<4 x i32>*
comment|// CHECK: load<4 x i32>* %[[b]], align 16
name|int32x4_t
name|v
init|=
name|vaddq_s32
argument_list|(
operator|*
operator|(
name|int32x4_t
operator|*
operator|)
operator|&
name|s1
argument_list|,
operator|*
operator|(
name|int32x4_t
operator|*
operator|)
operator|&
name|s2
argument_list|)
decl_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_decl_stmt
name|s37_with_align
name|g37
decl_stmt|;
end_decl_stmt

begin_function
name|int32x4_t
name|caller37
parameter_list|()
block|{
comment|// CHECK: caller37
comment|// CHECK: %[[a:.*]] = alloca %struct.s37, align 16
comment|// CHECK: %[[b:.*]] = alloca %struct.s37, align 16
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: call<4 x i32> @f37(i32 3, %struct.s37* %[[a]], %struct.s37* %[[b]])
return|return
name|f37
argument_list|(
literal|3
argument_list|,
name|g37
argument_list|,
name|g37
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// rdar://problem/12648441
end_comment

begin_comment
comment|// Test passing structs with size< 8,< 16 and> 16
end_comment

begin_comment
comment|// with alignment of 16 and without
end_comment

begin_comment
comment|// structs with size<= 8 bytes, without alignment attribute
end_comment

begin_comment
comment|// passed as i64 regardless of the align attribute
end_comment

begin_struct
struct|struct
name|s38
block|{
name|int
name|i
decl_stmt|;
name|short
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s38
name|s38_no_align
typedef|;
end_typedef

begin_comment
comment|// passing structs in registers
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f38
parameter_list|(
name|int
name|i
parameter_list|,
name|s38_no_align
name|s1
parameter_list|,
name|s38_no_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f38(i32 %i, i64 %s1.coerce, i64 %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s38, align 8
comment|// CHECK: %s2 = alloca %struct.s38, align 8
comment|// CHECK: store i64 %s1.coerce, i64* %{{.*}}, align 1
comment|// CHECK: store i64 %s2.coerce, i64* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s38* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s38* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s38* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s38* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_decl_stmt
name|s38_no_align
name|g38
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|s38_no_align
name|g38_2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|caller38
parameter_list|()
block|{
comment|// CHECK: define i32 @caller38()
comment|// CHECK: %[[a:.*]] = load i64* bitcast (%struct.s38* @g38 to i64*), align 1
comment|// CHECK: %[[b:.*]] = load i64* bitcast (%struct.s38* @g38_2 to i64*), align 1
comment|// CHECK: call i32 @f38(i32 3, i64 %[[a]], i64 %[[b]])
return|return
name|f38
argument_list|(
literal|3
argument_list|,
name|g38
argument_list|,
name|g38_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// passing structs on stack
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f38_stack
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|int
name|i8
parameter_list|,
name|int
name|i9
parameter_list|,
name|s38_no_align
name|s1
parameter_list|,
name|s38_no_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f38_stack(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, i32 %i8, i32 %i9, i64 %s1.coerce, i64 %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s38, align 8
comment|// CHECK: %s2 = alloca %struct.s38, align 8
comment|// CHECK: store i64 %s1.coerce, i64* %{{.*}}, align 1
comment|// CHECK: store i64 %s2.coerce, i64* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s38* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s38* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s38* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s38* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|i8
operator|+
name|i9
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller38_stack
parameter_list|()
block|{
comment|// CHECK: define i32 @caller38_stack()
comment|// CHECK: %[[a:.*]] = load i64* bitcast (%struct.s38* @g38 to i64*), align 1
comment|// CHECK: %[[b:.*]] = load i64* bitcast (%struct.s38* @g38_2 to i64*), align 1
comment|// CHECK: call i32 @f38_stack(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i64 %[[a]], i64 %[[b]])
return|return
name|f38_stack
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
name|g38
argument_list|,
name|g38_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// structs with size<= 8 bytes, with alignment attribute
end_comment

begin_struct
struct|struct
name|s39
block|{
name|int
name|i
decl_stmt|;
name|short
name|s
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s39
name|s39_with_align
typedef|;
end_typedef

begin_comment
comment|// passing aligned structs in registers
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f39
parameter_list|(
name|int
name|i
parameter_list|,
name|s39_with_align
name|s1
parameter_list|,
name|s39_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f39(i32 %i, i128 %s1.coerce, i128 %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s39, align 16
comment|// CHECK: %s2 = alloca %struct.s39, align 16
comment|// CHECK: store i128 %s1.coerce, i128* %{{.*}}, align 1
comment|// CHECK: store i128 %s2.coerce, i128* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s39* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s39* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s39* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s39* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_decl_stmt
name|s39_with_align
name|g39
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|s39_with_align
name|g39_2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|caller39
parameter_list|()
block|{
comment|// CHECK: define i32 @caller39()
comment|// CHECK: %[[a:.*]] = load i128* bitcast (%struct.s39* @g39 to i128*), align 1
comment|// CHECK: %[[b:.*]] = load i128* bitcast (%struct.s39* @g39_2 to i128*), align 1
comment|// CHECK: call i32 @f39(i32 3, i128 %[[a]], i128 %[[b]])
return|return
name|f39
argument_list|(
literal|3
argument_list|,
name|g39
argument_list|,
name|g39_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// passing aligned structs on stack
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f39_stack
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|int
name|i8
parameter_list|,
name|int
name|i9
parameter_list|,
name|s39_with_align
name|s1
parameter_list|,
name|s39_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f39_stack(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, i32 %i8, i32 %i9, i128 %s1.coerce, i128 %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s39, align 16
comment|// CHECK: %s2 = alloca %struct.s39, align 16
comment|// CHECK: store i128 %s1.coerce, i128* %{{.*}}, align 1
comment|// CHECK: store i128 %s2.coerce, i128* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s39* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s39* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s39* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s39* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|i8
operator|+
name|i9
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller39_stack
parameter_list|()
block|{
comment|// CHECK: define i32 @caller39_stack()
comment|// CHECK: %[[a:.*]] = load i128* bitcast (%struct.s39* @g39 to i128*), align 1
comment|// CHECK: %[[b:.*]] = load i128* bitcast (%struct.s39* @g39_2 to i128*), align 1
comment|// CHECK: call i32 @f39_stack(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i128 %[[a]], i128 %[[b]])
return|return
name|f39_stack
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
name|g39
argument_list|,
name|g39_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// structs with size<= 16 bytes, without alignment attribute
end_comment

begin_struct
struct|struct
name|s40
block|{
name|int
name|i
decl_stmt|;
name|short
name|s
decl_stmt|;
name|int
name|i2
decl_stmt|;
name|short
name|s2
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s40
name|s40_no_align
typedef|;
end_typedef

begin_comment
comment|// passing structs in registers
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f40
parameter_list|(
name|int
name|i
parameter_list|,
name|s40_no_align
name|s1
parameter_list|,
name|s40_no_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f40(i32 %i, [2 x i64] %s1.coerce, [2 x i64] %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s40, align 8
comment|// CHECK: %s2 = alloca %struct.s40, align 8
comment|// CHECK: store [2 x i64] %s1.coerce, [2 x i64]* %{{.*}}, align 1
comment|// CHECK: store [2 x i64] %s2.coerce, [2 x i64]* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s40* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s40* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s40* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s40* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_decl_stmt
name|s40_no_align
name|g40
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|s40_no_align
name|g40_2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|caller40
parameter_list|()
block|{
comment|// CHECK: define i32 @caller40()
comment|// CHECK: %[[a:.*]] = load [2 x i64]* bitcast (%struct.s40* @g40 to [2 x i64]*), align 1
comment|// CHECK: %[[b:.*]] = load [2 x i64]* bitcast (%struct.s40* @g40_2 to [2 x i64]*), align 1
comment|// CHECK: call i32 @f40(i32 3, [2 x i64] %[[a]], [2 x i64] %[[b]])
return|return
name|f40
argument_list|(
literal|3
argument_list|,
name|g40
argument_list|,
name|g40_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// passing structs on stack
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f40_stack
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|int
name|i8
parameter_list|,
name|int
name|i9
parameter_list|,
name|s40_no_align
name|s1
parameter_list|,
name|s40_no_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f40_stack(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, i32 %i8, i32 %i9, [2 x i64] %s1.coerce, [2 x i64] %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s40, align 8
comment|// CHECK: %s2 = alloca %struct.s40, align 8
comment|// CHECK: store [2 x i64] %s1.coerce, [2 x i64]* %{{.*}}, align 1
comment|// CHECK: store [2 x i64] %s2.coerce, [2 x i64]* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s40* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s40* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s40* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s40* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|i8
operator|+
name|i9
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller40_stack
parameter_list|()
block|{
comment|// CHECK: define i32 @caller40_stack()
comment|// CHECK: %[[a:.*]] = load [2 x i64]* bitcast (%struct.s40* @g40 to [2 x i64]*), align 1
comment|// CHECK: %[[b:.*]] = load [2 x i64]* bitcast (%struct.s40* @g40_2 to [2 x i64]*), align 1
comment|// CHECK: call i32 @f40_stack(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, [2 x i64] %[[a]], [2 x i64] %[[b]])
return|return
name|f40_stack
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
name|g40
argument_list|,
name|g40_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// structs with size<= 16 bytes, with alignment attribute
end_comment

begin_struct
struct|struct
name|s41
block|{
name|int
name|i
decl_stmt|;
name|short
name|s
decl_stmt|;
name|int
name|i2
decl_stmt|;
name|short
name|s2
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s41
name|s41_with_align
typedef|;
end_typedef

begin_comment
comment|// passing aligned structs in registers
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f41
parameter_list|(
name|int
name|i
parameter_list|,
name|s41_with_align
name|s1
parameter_list|,
name|s41_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f41(i32 %i, i128 %s1.coerce, i128 %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s41, align 16
comment|// CHECK: %s2 = alloca %struct.s41, align 16
comment|// CHECK: store i128 %s1.coerce, i128* %{{.*}}, align 1
comment|// CHECK: store i128 %s2.coerce, i128* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s41* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s41* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s41* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s41* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_decl_stmt
name|s41_with_align
name|g41
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|s41_with_align
name|g41_2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|caller41
parameter_list|()
block|{
comment|// CHECK: define i32 @caller41()
comment|// CHECK: %[[a:.*]] = load i128* bitcast (%struct.s41* @g41 to i128*), align 1
comment|// CHECK: %[[b:.*]] = load i128* bitcast (%struct.s41* @g41_2 to i128*), align 1
comment|// CHECK: call i32 @f41(i32 3, i128 %[[a]], i128 %[[b]])
return|return
name|f41
argument_list|(
literal|3
argument_list|,
name|g41
argument_list|,
name|g41_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// passing aligned structs on stack
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f41_stack
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|int
name|i8
parameter_list|,
name|int
name|i9
parameter_list|,
name|s41_with_align
name|s1
parameter_list|,
name|s41_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f41_stack(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, i32 %i8, i32 %i9, i128 %s1.coerce, i128 %s2.coerce)
comment|// CHECK: %s1 = alloca %struct.s41, align 16
comment|// CHECK: %s2 = alloca %struct.s41, align 16
comment|// CHECK: store i128 %s1.coerce, i128* %{{.*}}, align 1
comment|// CHECK: store i128 %s2.coerce, i128* %{{.*}}, align 1
comment|// CHECK: getelementptr inbounds %struct.s41* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s41* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s41* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s41* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|i8
operator|+
name|i9
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller41_stack
parameter_list|()
block|{
comment|// CHECK: define i32 @caller41_stack()
comment|// CHECK: %[[a:.*]] = load i128* bitcast (%struct.s41* @g41 to i128*), align 1
comment|// CHECK: %[[b:.*]] = load i128* bitcast (%struct.s41* @g41_2 to i128*), align 1
comment|// CHECK: call i32 @f41_stack(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i128 %[[a]], i128 %[[b]])
return|return
name|f41_stack
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
name|g41
argument_list|,
name|g41_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// structs with size> 16 bytes, without alignment attribute
end_comment

begin_struct
struct|struct
name|s42
block|{
name|int
name|i
decl_stmt|;
name|short
name|s
decl_stmt|;
name|int
name|i2
decl_stmt|;
name|short
name|s2
decl_stmt|;
name|int
name|i3
decl_stmt|;
name|short
name|s3
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s42
name|s42_no_align
typedef|;
end_typedef

begin_comment
comment|// passing structs in registers
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f42
parameter_list|(
name|int
name|i
parameter_list|,
name|s42_no_align
name|s1
parameter_list|,
name|s42_no_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f42(i32 %i, %struct.s42* %s1, %struct.s42* %s2)
comment|// CHECK: getelementptr inbounds %struct.s42* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s42* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s42* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s42* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_decl_stmt
name|s42_no_align
name|g42
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|s42_no_align
name|g42_2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|caller42
parameter_list|()
block|{
comment|// CHECK: define i32 @caller42()
comment|// CHECK: %[[a:.*]] = alloca %struct.s42, align 4
comment|// CHECK: %[[b:.*]] = alloca %struct.s42, align 4
comment|// CHECK: %[[c:.*]] = bitcast %struct.s42* %[[a]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: %[[d:.*]] = bitcast %struct.s42* %[[b]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: call i32 @f42(i32 3, %struct.s42* %[[a]], %struct.s42* %[[b]])
return|return
name|f42
argument_list|(
literal|3
argument_list|,
name|g42
argument_list|,
name|g42_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// passing structs on stack
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f42_stack
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|int
name|i8
parameter_list|,
name|int
name|i9
parameter_list|,
name|s42_no_align
name|s1
parameter_list|,
name|s42_no_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f42_stack(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, i32 %i8, i32 %i9, %struct.s42* %s1, %struct.s42* %s2)
comment|// CHECK: getelementptr inbounds %struct.s42* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s42* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s42* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s42* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|i8
operator|+
name|i9
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller42_stack
parameter_list|()
block|{
comment|// CHECK: define i32 @caller42_stack()
comment|// CHECK: %[[a:.*]] = alloca %struct.s42, align 4
comment|// CHECK: %[[b:.*]] = alloca %struct.s42, align 4
comment|// CHECK: %[[c:.*]] = bitcast %struct.s42* %[[a]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: %[[d:.*]] = bitcast %struct.s42* %[[b]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: call i32 @f42_stack(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, %struct.s42* %[[a]], %struct.s42* %[[b]])
return|return
name|f42_stack
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
name|g42
argument_list|,
name|g42_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// structs with size> 16 bytes, with alignment attribute
end_comment

begin_struct
struct|struct
name|s43
block|{
name|int
name|i
decl_stmt|;
name|short
name|s
decl_stmt|;
name|int
name|i2
decl_stmt|;
name|short
name|s2
decl_stmt|;
name|int
name|i3
decl_stmt|;
name|short
name|s3
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|s43
name|s43_with_align
typedef|;
end_typedef

begin_comment
comment|// passing aligned structs in registers
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f43
parameter_list|(
name|int
name|i
parameter_list|,
name|s43_with_align
name|s1
parameter_list|,
name|s43_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f43(i32 %i, %struct.s43* %s1, %struct.s43* %s2)
comment|// CHECK: getelementptr inbounds %struct.s43* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s43* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s43* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s43* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_decl_stmt
name|s43_with_align
name|g43
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|s43_with_align
name|g43_2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|caller43
parameter_list|()
block|{
comment|// CHECK: define i32 @caller43()
comment|// CHECK: %[[a:.*]] = alloca %struct.s43, align 16
comment|// CHECK: %[[b:.*]] = alloca %struct.s43, align 16
comment|// CHECK: %[[c:.*]] = bitcast %struct.s43* %[[a]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: %[[d:.*]] = bitcast %struct.s43* %[[b]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: call i32 @f43(i32 3, %struct.s43* %[[a]], %struct.s43* %[[b]])
return|return
name|f43
argument_list|(
literal|3
argument_list|,
name|g43
argument_list|,
name|g43_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// passing aligned structs on stack
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f43_stack
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|int
name|i8
parameter_list|,
name|int
name|i9
parameter_list|,
name|s43_with_align
name|s1
parameter_list|,
name|s43_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f43_stack(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, i32 %i8, i32 %i9, %struct.s43* %s1, %struct.s43* %s2)
comment|// CHECK: getelementptr inbounds %struct.s43* %s1, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s43* %s2, i32 0, i32 0
comment|// CHECK: getelementptr inbounds %struct.s43* %s1, i32 0, i32 1
comment|// CHECK: getelementptr inbounds %struct.s43* %s2, i32 0, i32 1
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|i8
operator|+
name|i9
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller43_stack
parameter_list|()
block|{
comment|// CHECK: define i32 @caller43_stack()
comment|// CHECK: %[[a:.*]] = alloca %struct.s43, align 16
comment|// CHECK: %[[b:.*]] = alloca %struct.s43, align 16
comment|// CHECK: %[[c:.*]] = bitcast %struct.s43* %[[a]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: %[[d:.*]] = bitcast %struct.s43* %[[b]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
comment|// CHECK: call i32 @f43_stack(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, %struct.s43* %[[a]], %struct.s43* %[[b]])
return|return
name|f43_stack
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
name|g43
argument_list|,
name|g43_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// rdar://13668927
end_comment

begin_comment
comment|// We should not split argument s1 between registers and stack.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f40_split
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|s40_no_align
name|s1
parameter_list|,
name|s40_no_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f40_split(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, [1 x i32], [2 x i64] %s1.coerce, [2 x i64] %s2.coerce)
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller40_split
parameter_list|()
block|{
comment|// CHECK: define i32 @caller40_split()
comment|// CHECK: call i32 @f40_split(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, [1 x i32] undef, [2 x i64] %{{.*}} [2 x i64] %{{.*}})
return|return
name|f40_split
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
name|g40
argument_list|,
name|g40_2
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|f41_split
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|i2
parameter_list|,
name|int
name|i3
parameter_list|,
name|int
name|i4
parameter_list|,
name|int
name|i5
parameter_list|,
name|int
name|i6
parameter_list|,
name|int
name|i7
parameter_list|,
name|s41_with_align
name|s1
parameter_list|,
name|s41_with_align
name|s2
parameter_list|)
block|{
comment|// CHECK: define i32 @f41_split(i32 %i, i32 %i2, i32 %i3, i32 %i4, i32 %i5, i32 %i6, i32 %i7, [1 x i32], i128 %s1.coerce, i128 %s2.coerce)
return|return
name|s1
operator|.
name|i
operator|+
name|s2
operator|.
name|i
operator|+
name|i
operator|+
name|i2
operator|+
name|i3
operator|+
name|i4
operator|+
name|i5
operator|+
name|i6
operator|+
name|i7
operator|+
name|s1
operator|.
name|s
operator|+
name|s2
operator|.
name|s
return|;
block|}
end_function

begin_function
name|int
name|caller41_split
parameter_list|()
block|{
comment|// CHECK: define i32 @caller41_split()
comment|// CHECK: call i32 @f41_split(i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, [1 x i32] undef, i128 %{{.*}}, i128 %{{.*}})
return|return
name|f41_split
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
name|g41
argument_list|,
name|g41_2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Handle homogeneous aggregates properly in variadic functions.
end_comment

begin_struct
struct|struct
name|HFA
block|{
name|float
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|float
name|test_hfa
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK-LABEL: define float @test_hfa(i32 %n, ...)
comment|// CHECK: [[THELIST:%.*]] = alloca i8*
comment|// CHECK: [[CURLIST:%.*]] = load i8** [[THELIST]]
comment|// HFA is not indirect, so occupies its full 16 bytes on the stack.
comment|// CHECK: [[NEXTLIST:%.*]] = getelementptr i8* [[CURLIST]], i32 16
comment|// CHECK: store i8* [[NEXTLIST]], i8** [[THELIST]]
comment|// CHECK: bitcast i8* [[CURLIST]] to %struct.HFA*
name|__builtin_va_list
name|thelist
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|thelist
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|struct
name|HFA
name|h
init|=
name|__builtin_va_arg
argument_list|(
name|thelist
argument_list|,
expr|struct
name|HFA
argument_list|)
decl_stmt|;
return|return
name|h
operator|.
name|d
return|;
block|}
end_function

begin_function
name|float
name|test_hfa_call
parameter_list|(
name|struct
name|HFA
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: define float @test_hfa_call(%struct.HFA* %a)
comment|// CHECK: call float (i32, ...)* @test_hfa(i32 1, [2 x double] {{.*}})
name|test_hfa
argument_list|(
literal|1
argument_list|,
operator|*
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|TooBigHFA
block|{
name|float
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|float
name|test_toobig_hfa
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK-LABEL: define float @test_toobig_hfa(i32 %n, ...)
comment|// CHECK: [[THELIST:%.*]] = alloca i8*
comment|// CHECK: [[CURLIST:%.*]] = load i8** [[THELIST]]
comment|// TooBigHFA is not actually an HFA, so gets passed indirectly. Only 8 bytes
comment|// of stack consumed.
comment|// CHECK: [[NEXTLIST:%.*]] = getelementptr i8* [[CURLIST]], i32 8
comment|// CHECK: store i8* [[NEXTLIST]], i8** [[THELIST]]
comment|// CHECK: [[HFAPTRPTR:%.*]] = bitcast i8* [[CURLIST]] to i8**
comment|// CHECK: [[HFAPTR:%.*]] = load i8** [[HFAPTRPTR]]
comment|// CHECK: bitcast i8* [[HFAPTR]] to %struct.TooBigHFA*
name|__builtin_va_list
name|thelist
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|thelist
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|struct
name|TooBigHFA
name|h
init|=
name|__builtin_va_arg
argument_list|(
name|thelist
argument_list|,
expr|struct
name|TooBigHFA
argument_list|)
decl_stmt|;
return|return
name|h
operator|.
name|d
return|;
block|}
end_function

begin_struct
struct|struct
name|HVA
block|{
name|int32x4_t
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int32x4_t
name|test_hva
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK-LABEL: define<4 x i32> @test_hva(i32 %n, ...)
comment|// CHECK: [[THELIST:%.*]] = alloca i8*
comment|// CHECK: [[CURLIST:%.*]] = load i8** [[THELIST]]
comment|// HVA is not indirect, so occupies its full 16 bytes on the stack. but it
comment|// must be properly aligned.
comment|// CHECK: [[ALIGN0:%.*]] = getelementptr i8* [[CURLIST]], i32 15
comment|// CHECK: [[ALIGN1:%.*]] = ptrtoint i8* [[ALIGN0]] to i64
comment|// CHECK: [[ALIGN2:%.*]] = and i64 [[ALIGN1]], -16
comment|// CHECK: [[ALIGNED_LIST:%.*]] = inttoptr i64 [[ALIGN2]] to i8*
comment|// CHECK: [[NEXTLIST:%.*]] = getelementptr i8* [[ALIGNED_LIST]], i32 32
comment|// CHECK: store i8* [[NEXTLIST]], i8** [[THELIST]]
comment|// CHECK: bitcast i8* [[ALIGNED_LIST]] to %struct.HVA*
name|__builtin_va_list
name|thelist
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|thelist
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|struct
name|HVA
name|h
init|=
name|__builtin_va_arg
argument_list|(
name|thelist
argument_list|,
expr|struct
name|HVA
argument_list|)
decl_stmt|;
return|return
name|h
operator|.
name|b
return|;
block|}
end_function

begin_struct
struct|struct
name|TooBigHVA
block|{
name|int32x4_t
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int32x4_t
name|test_toobig_hva
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK-LABEL: define<4 x i32> @test_toobig_hva(i32 %n, ...)
comment|// CHECK: [[THELIST:%.*]] = alloca i8*
comment|// CHECK: [[CURLIST:%.*]] = load i8** [[THELIST]]
comment|// TooBigHVA is not actually an HVA, so gets passed indirectly. Only 8 bytes
comment|// of stack consumed.
comment|// CHECK: [[NEXTLIST:%.*]] = getelementptr i8* [[CURLIST]], i32 8
comment|// CHECK: store i8* [[NEXTLIST]], i8** [[THELIST]]
comment|// CHECK: [[HVAPTRPTR:%.*]] = bitcast i8* [[CURLIST]] to i8**
comment|// CHECK: [[HVAPTR:%.*]] = load i8** [[HVAPTRPTR]]
comment|// CHECK: bitcast i8* [[HVAPTR]] to %struct.TooBigHVA*
name|__builtin_va_list
name|thelist
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|thelist
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|struct
name|TooBigHVA
name|h
init|=
name|__builtin_va_arg
argument_list|(
name|thelist
argument_list|,
expr|struct
name|TooBigHVA
argument_list|)
decl_stmt|;
return|return
name|h
operator|.
name|d
return|;
block|}
end_function

end_unit

