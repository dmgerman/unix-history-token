begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|MyUnion
typedef|;
end_typedef

begin_function_decl
name|void
name|unionf
parameter_list|(
name|MyUnion
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|uniontest
parameter_list|(
name|float
name|a
parameter_list|)
block|{
name|f
argument_list|(
operator|(
name|MyUnion
operator|)
literal|1.0f
argument_list|)
expr_stmt|;
comment|// CHECK: store float 1.000000e+00
block|}
end_function

end_unit

