begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=x86_64-apple-darwin10 | FileCheck %s
end_comment

begin_comment
comment|// This file tests the clang extension which allows initializing the components
end_comment

begin_comment
comment|// of a complex number individually using an initialization list.  (There is a
end_comment

begin_comment
comment|// extensive description and test in test/Sema/complex-init-list.c.)
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|x
init|=
block|{
literal|1.0f
block|,
literal|1.0f
operator|/
literal|0.0f
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @x = global { float, float } { float 1.000000e+00, float 0x7FF0000000000000 }, align 4
end_comment

begin_function
specifier|_Complex
name|float
name|f
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
block|{
specifier|_Complex
name|float
name|z
init|=
block|{
name|x
block|,
name|y
block|}
decl_stmt|;
return|return
name|z
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @f
end_comment

begin_comment
comment|// CHECK: alloca { float, float }
end_comment

begin_comment
comment|// CHECK: alloca { float, float }
end_comment

begin_function
specifier|_Complex
name|float
name|f2
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
block|{
return|return
operator|(
specifier|_Complex
name|float
operator|)
block|{
name|x
block|,
name|y
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @f2
end_comment

begin_comment
comment|// CHECK: alloca { float, float }
end_comment

begin_comment
comment|// CHECK: alloca { float, float }
end_comment

end_unit

