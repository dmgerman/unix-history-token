begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fno-math-builtin -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Check that the -fno-math-builtin option for -cc1 is working properly.
end_comment

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

begin_function
name|double
name|foo
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
return|return
name|pow
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: call double @pow
block|}
end_function

end_unit

