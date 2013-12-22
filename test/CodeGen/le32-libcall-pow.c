begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fno-math-builtin -fmath-errno -emit-llvm -o - %s -triple le32-unknown-nacl | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fno-math-builtin -emit-llvm -o - %s -triple le32-unknown-nacl | FileCheck %s
end_comment

begin_comment
comment|// le32 (PNaCl) never generates intrinsics for pow calls, with or without
end_comment

begin_comment
comment|// errno, when the -fno-math-builtin flag is passed to -cc1. A separate test
end_comment

begin_comment
comment|// makes sure this flag is indeed passed for le32.
end_comment

begin_function_decl
name|float
name|powf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|pow
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|powl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @test_pow
end_comment

begin_function
name|void
name|test_pow
parameter_list|(
name|float
name|a0
parameter_list|,
name|double
name|a1
parameter_list|,
name|long
name|double
name|a2
parameter_list|)
block|{
comment|// CHECK: call float @powf
name|float
name|l0
init|=
name|powf
argument_list|(
name|a0
argument_list|,
name|a0
argument_list|)
decl_stmt|;
comment|// CHECK: call double @pow
name|double
name|l1
init|=
name|pow
argument_list|(
name|a1
argument_list|,
name|a1
argument_list|)
decl_stmt|;
comment|// CHECK: call double @powl
name|long
name|double
name|l2
init|=
name|powl
argument_list|(
name|a2
argument_list|,
name|a2
argument_list|)
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare float @powf(float, float)
end_comment

begin_comment
comment|// CHECK: declare double @pow(double, double)
end_comment

begin_comment
comment|// CHECK: declare double @powl(double, double)
end_comment

end_unit

