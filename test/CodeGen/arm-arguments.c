begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -target-feature +neon -target-abi apcs-gnu -emit-llvm -w -o - %s | FileCheck -check-prefix=APCS-GNU %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -target-feature +neon -target-abi aapcs -emit-llvm -w -o - %s | FileCheck -check-prefix=AAPCS %s
end_comment

begin_comment
comment|// APCS-GNU-LABEL: define signext i8 @f0()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc signext i8 @f0()
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
comment|// APCS-GNU-LABEL: define i8 @f1()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i8 @f1()
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
comment|// APCS-GNU-LABEL: define i16 @f2()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i16 @f2()
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
comment|// APCS-GNU-LABEL: define i32 @f3()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f3()
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
comment|// APCS-GNU-LABEL: define i32 @f4()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f4()
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
comment|// APCS-GNU-LABEL: define void @f5(
end_comment

begin_comment
comment|// APCS-GNU: struct.s5* noalias sret
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f5()
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
comment|// APCS-GNU-LABEL: define void @f6(
end_comment

begin_comment
comment|// APCS-GNU: struct.s6* noalias sret
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f6()
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
comment|// APCS-GNU-LABEL: define void @f7()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc void @f7()
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
comment|// APCS-GNU-LABEL: define void @f8(
end_comment

begin_comment
comment|// APCS-GNU: struct.s8* noalias sret
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc void @f8()
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
comment|// APCS-GNU-LABEL: define i32 @f9()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f9()
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
comment|// APCS-GNU-LABEL: define i32 @f10()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f10()
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
comment|// APCS-GNU-LABEL: define void @f11(
end_comment

begin_comment
comment|// APCS-GNU: struct.s11* noalias sret
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f11()
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
comment|// APCS-GNU-LABEL: define i32 @f12()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f12()
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
comment|// APCS-GNU-LABEL: define void @f13(
end_comment

begin_comment
comment|// APCS-GNU: struct.s13* noalias sret
end_comment

begin_comment
comment|// FIXME: This should return a float.
end_comment

begin_comment
comment|// AAPCS-FIXME: darm_aapcscc efine float @f13()
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
comment|// APCS-GNU-LABEL: define void @f14(
end_comment

begin_comment
comment|// APCS-GNU: union.u14* noalias sret
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f14()
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
comment|// APCS-GNU-LABEL: define void @f15()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc void @f15()
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
comment|// APCS-GNU-LABEL: define void @f16()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc void @f16()
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
comment|// APCS-GNU-LABEL: define i32 @f17()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f17()
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
comment|// APCS-GNU-LABEL: define i32 @f18()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f18()
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
comment|// APCS-GNU-LABEL: define void @f19(
end_comment

begin_comment
comment|// APCS-GNU: struct.s19* noalias sret
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f19()
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
comment|// APCS-GNU-LABEL: define void @f20(
end_comment

begin_comment
comment|// APCS-GNU: struct.s20* noalias sret
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f20()
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
comment|// APCS-GNU-LABEL: define i8 @f21()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f21()
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
comment|// APCS-GNU-LABEL: define i16 @f22()
end_comment

begin_comment
comment|// APCS-GNU-LABEL: define i32 @f23()
end_comment

begin_comment
comment|// APCS-GNU-LABEL: define i64 @f24()
end_comment

begin_comment
comment|// APCS-GNU-LABEL: define i128 @f25()
end_comment

begin_comment
comment|// APCS-GNU-LABEL: define i64 @f26()
end_comment

begin_comment
comment|// APCS-GNU-LABEL: define i128 @f27()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i16 @f22()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f23()
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f24({{.*}} noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f25({{.*}} noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f26({{.*}} noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f27({{.*}} noalias sret
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
comment|// APCS-GNU-LABEL: define i16 @f28()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i16 @f28()
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
comment|// APCS-GNU-LABEL: define i32 @f29()
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc i32 @f29()
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
comment|// APCS-GNU: define void @f30({{.*}} noalias sret
end_comment

begin_comment
comment|// AAPCS: define arm_aapcscc void @f30({{.*}} noalias sret
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

begin_comment
comment|// PR11905
end_comment

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
comment|// AAPCS: @f31([1 x i32] %s.coerce)
end_comment

begin_comment
comment|// AAPCS: %s = alloca %struct.s31, align 4
end_comment

begin_comment
comment|// AAPCS: alloca [1 x i32]
end_comment

begin_comment
comment|// AAPCS: store [1 x i32] %s.coerce, [1 x i32]*
end_comment

begin_comment
comment|// APCS-GNU: @f31([1 x i32] %s.coerce)
end_comment

begin_comment
comment|// APCS-GNU: %s = alloca %struct.s31, align 4
end_comment

begin_comment
comment|// APCS-GNU: alloca [1 x i32]
end_comment

begin_comment
comment|// APCS-GNU: store [1 x i32] %s.coerce, [1 x i32]*
end_comment

begin_comment
comment|// PR13562
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
comment|// AAPCS: @f32([1 x i64] %s.coerce)
end_comment

begin_comment
comment|// APCS-GNU: @f32([2 x i32] %s.coerce)
end_comment

begin_comment
comment|// PR13350
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
comment|// APCS-GNU-LABEL: define void @f33(%struct.s33* byval align 1 %s)
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc void @f33(%struct.s33* byval align 1 %s)
end_comment

begin_comment
comment|// PR14048
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
comment|// APCS-GNU: @g34(%struct.s34* %s)
end_comment

begin_comment
comment|// APCS-GNU: %[[a:.*]] = alloca { [1 x i32] }
end_comment

begin_comment
comment|// APCS-GNU: %[[gep:.*]] = getelementptr { [1 x i32] }* %[[a]], i32 0, i32 0
end_comment

begin_comment
comment|// APCS-GNU: load [1 x i32]* %[[gep]]
end_comment

begin_comment
comment|// AAPCS: @g34(%struct.s34* %s)
end_comment

begin_comment
comment|// AAPCS: %[[a:.*]] = alloca { [1 x i32] }
end_comment

begin_comment
comment|// AAPCS: %[[gep:.*]] = getelementptr { [1 x i32] }* %[[a]], i32 0, i32 0
end_comment

begin_comment
comment|// AAPCS: load [1 x i32]* %[[gep]]
end_comment

begin_comment
comment|// rdar://12596507
end_comment

begin_struct
struct|struct
name|s35
block|{
name|float
name|v
index|[
literal|18
index|]
decl_stmt|;
comment|//make sure byval is on.
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

begin_expr_stmt
specifier|static
name|__attribute__
argument_list|(
argument|(__always_inline__, __nodebug__)
argument_list|)
name|float32x4_t
name|vaddq_f32
argument_list|(
argument|float32x4_t __a
argument_list|,
argument|float32x4_t __b
argument_list|)
block|{
return|return
name|__a
operator|+
name|__b
return|;
block|}
end_expr_stmt

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

begin_comment
comment|// APCS-GNU-LABEL: define<4 x float> @f35(i32 %i, %struct.s35* byval align 16, %struct.s35* byval align 16)
end_comment

begin_comment
comment|// APCS-GNU: %[[a:.*]] = alloca %struct.s35, align 16
end_comment

begin_comment
comment|// APCS-GNU: %[[b:.*]] = bitcast %struct.s35* %[[a]] to i8*
end_comment

begin_comment
comment|// APCS-GNU: %[[c:.*]] = bitcast %struct.s35* %0 to i8*
end_comment

begin_comment
comment|// APCS-GNU: call void @llvm.memcpy.p0i8.p0i8.i32(i8* %[[b]], i8* %[[c]]
end_comment

begin_comment
comment|// APCS-GNU: %[[d:.*]] = bitcast %struct.s35* %[[a]] to<4 x float>*
end_comment

begin_comment
comment|// APCS-GNU: load<4 x float>* %[[d]], align 16
end_comment

begin_comment
comment|// AAPCS-LABEL: define arm_aapcscc<4 x float> @f35(i32 %i, %struct.s35* byval align 16, %struct.s35* byval align 16)
end_comment

begin_comment
comment|// AAPCS: %[[a:.*]] = alloca %struct.s35, align 16
end_comment

begin_comment
comment|// AAPCS: %[[b:.*]] = bitcast %struct.s35* %[[a]] to i8*
end_comment

begin_comment
comment|// AAPCS: %[[c:.*]] = bitcast %struct.s35* %0 to i8*
end_comment

begin_comment
comment|// AAPCS: call void @llvm.memcpy.p0i8.p0i8.i32(i8* %[[b]], i8* %[[c]]
end_comment

begin_comment
comment|// AAPCS: %[[d:.*]] = bitcast %struct.s35* %[[a]] to<4 x float>*
end_comment

begin_comment
comment|// AAPCS: load<4 x float>* %[[d]], align 16
end_comment

end_unit

