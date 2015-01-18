begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|4
argument|) )
argument_list|)
name|float
name|float4
typedef|;
end_typedef

begin_comment
comment|// CHECK: @test
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|float4
name|va
decl_stmt|;
name|va
operator|.
name|hi
index|[
literal|0
index|]
operator|=
literal|3.0
expr_stmt|;
comment|// CHECK:  [[VA:%.*]] = alloca<4 x float>
comment|// CHECK:  [[CONV:%.*]] = bitcast<4 x float>* [[VA]] to float*
comment|// CHECK:  [[ADD:%.*]] = getelementptr inbounds float* [[CONV]], i64 2
comment|// CHECK:  [[ARRIDX:%.*]] = getelementptr inbounds float* [[ADD]], i64 0
comment|// CHECK:   store float 3.000000e+00, float* [[ARRIDX]]
block|}
end_function

end_unit

