begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the value profiling instrinsics emitted by instrumentation.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-avoid-direct-call.c %s -o - -emit-llvm -fprofile-instrument=clang -mllvm -enable-value-profiling | FileCheck %s
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-NOT: call void @__llvm_profile_instrument_target
name|foo
argument_list|(
literal|21
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

