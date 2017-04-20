begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -triple=aarch64-apple-ios -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_function
name|float
name|fma_test1
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|)
block|{
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|ON
comment|// CHECK-LABEL: fma_test1:
comment|// CHECK: fmadd
name|float
name|x
init|=
name|a
operator|*
name|b
operator|+
name|c
decl_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function
name|float
name|fma_test2
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: fma_test2:
comment|// CHECK: fmul
comment|// CHECK: fadd
name|float
name|x
init|=
name|a
operator|*
name|b
operator|+
name|c
decl_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

