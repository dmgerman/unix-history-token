begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -ffp-contract=fast -triple=powerpc-apple-darwin10 -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: powerpc-registered-target
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
comment|// CHECK: fmadds
name|float
name|x
init|=
name|a
operator|*
name|b
decl_stmt|;
name|float
name|y
init|=
name|x
operator|+
name|c
decl_stmt|;
return|return
name|y
return|;
block|}
end_function

end_unit

