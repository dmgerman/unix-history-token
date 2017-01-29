begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -triple x86_64-pc-windows-msvc19.0.0 -fopenmp -fms-compatibility -x c++ -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_extern
extern|extern
literal|"C"
block|{
name|void
name|__cpuid
parameter_list|(
name|int
index|[
literal|4
index|]
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// CHECK-LABEL: @main
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|__try
block|{
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{   }
return|return
literal|0
return|;
block|}
end_function

end_unit

