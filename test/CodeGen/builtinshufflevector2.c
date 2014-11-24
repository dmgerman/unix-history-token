begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|float
name|float4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
end_typedef

begin_comment
comment|// CHECK-LABEL: define void @clang_shufflevector_v_v(
end_comment

begin_function
name|void
name|clang_shufflevector_v_v
parameter_list|(
name|float4
modifier|*
name|A
parameter_list|,
name|float4
name|x
parameter_list|,
name|uint4
name|mask
parameter_list|)
block|{
comment|// CHECK: [[MASK:%.*]] = and<4 x i32> {{%.*}},<i32 3, i32 3, i32 3, i32 3>
comment|// CHECK: [[I:%.*]] = extractelement<4 x i32> [[MASK]], i{{[0-9]+}} 0
comment|// CHECK: [[E:%.*]] = extractelement<4 x float> [[X:%.*]], i{{[0-9]+}} [[I]]
comment|//
comment|// Here is where ToT Clang code generation makes a mistake.
comment|// It uses [[I]] as the insertion index instead of 0.
comment|// Similarly on the remaining insertelement.
comment|// CHECK: [[V:%[a-zA-Z0-9._]+]] = insertelement<4 x float> undef, float [[E]], i{{[0-9]+}} 0
comment|// CHECK: [[I:%.*]] = extractelement<4 x i32> [[MASK]], i{{[0-9]+}} 1
comment|// CHECK: [[E:%.*]] = extractelement<4 x float> [[X]], i{{[0-9]+}} [[I]]
comment|// CHECK: [[V2:%.*]] = insertelement<4 x float> [[V]], float [[E]], i{{[0-9]+}} 1
comment|// CHECK: [[I:%.*]] = extractelement<4 x i32> [[MASK]], i{{[0-9]+}} 2
comment|// CHECK: [[E:%.*]] = extractelement<4 x float> [[X]], i{{[0-9]+}} [[I]]
comment|// CHECK: [[V3:%.*]] = insertelement<4 x float> [[V2]], float [[E]], i{{[0-9]+}} 2
comment|// CHECK: [[I:%.*]] = extractelement<4 x i32> [[MASK]], i{{[0-9]+}} 3
comment|// CHECK: [[E:%.*]] = extractelement<4 x float> [[X]], i{{[0-9]+}} [[I]]
comment|// CHECK: [[V4:%.*]] = insertelement<4 x float> [[V3]], float [[E]], i{{[0-9]+}} 3
comment|// CHECK: store<4 x float> [[V4]],<4 x float>* {{%.*}},
operator|*
name|A
operator|=
name|__builtin_shufflevector
argument_list|(
name|x
argument_list|,
name|mask
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @clang_shufflevector_v_v_c(
end_comment

begin_function
name|void
name|clang_shufflevector_v_v_c
parameter_list|(
name|float4
modifier|*
name|A
parameter_list|,
name|float4
name|x
parameter_list|,
name|float4
name|y
parameter_list|)
block|{
comment|// CHECK: [[V:%.*]] = shufflevector<4 x float> {{%.*}},<4 x float> {{%.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
comment|// CHECK: store<4 x float> [[V]],<4 x float>* {{%.*}}
operator|*
name|A
operator|=
name|__builtin_shufflevector
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @clang_shufflevector_v_v_undef(
end_comment

begin_function
name|void
name|clang_shufflevector_v_v_undef
parameter_list|(
name|float4
modifier|*
name|A
parameter_list|,
name|float4
name|x
parameter_list|,
name|float4
name|y
parameter_list|)
block|{
comment|// CHECK: [[V:%.*]] = shufflevector<4 x float> {{%.*}},<4 x float> {{%.*}},<4 x i32><i32 0, i32 4, i32 undef, i32 5>
comment|// CHECK: store<4 x float> [[V]],<4 x float>* {{%.*}}
operator|*
name|A
operator|=
name|__builtin_shufflevector
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
operator|-
literal|1
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

