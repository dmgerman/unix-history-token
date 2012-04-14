begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
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

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed, aligned(
literal|4
argument|))
argument_list|)
name|struct1
block|{
name|float4
name|position
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|x
init|=
name|__alignof
argument_list|(
expr|struct
name|struct1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|float4
name|f
parameter_list|(
name|struct
name|struct1
modifier|*
name|x
parameter_list|)
block|{
return|return
name|x
operator|->
name|position
return|;
block|}
end_function

begin_function
name|void
name|func
parameter_list|(
name|struct
name|struct1
modifier|*
name|p
parameter_list|,
name|float
modifier|*
name|a
parameter_list|,
name|float
modifier|*
name|b
parameter_list|,
name|float
name|c
parameter_list|)
block|{
name|p
operator|->
name|position
operator|.
name|x
operator|=
name|c
expr_stmt|;
operator|*
name|a
operator|=
name|p
operator|->
name|position
operator|.
name|y
expr_stmt|;
operator|*
name|b
operator|=
name|p
operator|->
name|position
index|[
literal|0
index|]
expr_stmt|;
name|p
operator|->
name|position
index|[
literal|2
index|]
operator|=
name|c
expr_stmt|;
comment|// FIXME: We should be able to come up with a more aggressive alignment
comment|// estimate.
comment|// CHECK: @func
comment|// CHECK: load<4 x float>* {{%.*}}, align 1
comment|// CHECK: store<4 x float> {{%.*}},<4 x float>* {{%.*}}, align 1
comment|// CHECK: load<4 x float>* {{%.*}}, align 1
comment|// CHECK: load<4 x float>* {{%.*}}, align 1
comment|// CHECK: load<4 x float>* {{%.*}}, align 1
comment|// CHECK: store<4 x float> {{%.*}},<4 x float>* {{%.*}}, align 1
comment|// CHECK: ret void
block|}
end_function

end_unit

