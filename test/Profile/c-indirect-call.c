begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the value profiling instrinsics emitted by instrumentation.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-indirect-call.c %s -o - -emit-llvm -fprofile-instrument=clang -mllvm -enable-value-profiling | FileCheck --check-prefix=NOEXT %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-ibm-linux -main-file-name c-indirect-call.c %s -o - -emit-llvm -fprofile-instrument=clang -mllvm -enable-value-profiling | FileCheck --check-prefix=EXT %s
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|foo
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
comment|// NOEXT:  [[REG1:%[0-9]+]] = load void ()*, void ()** @foo, align 8
comment|// NOEXT-NEXT:  [[REG2:%[0-9]+]] = ptrtoint void ()* [[REG1]] to i64
comment|// NOEXT-NEXT:  call void @__llvm_profile_instrument_target(i64 [[REG2]], i8* bitcast ({{.*}}* @__profd_main to i8*), i32 0)
comment|// NOEXT-NEXT:  call void [[REG1]]()
comment|// EXT:  [[REG1:%[0-9]+]] = load void ()*, void ()** @foo, align 8
comment|// EXT-NEXT:  [[REG2:%[0-9]+]] = ptrtoint void ()* [[REG1]] to i64
comment|// EXT-NEXT:  call void @__llvm_profile_instrument_target(i64 [[REG2]], i8* bitcast ({{.*}}* @__profd_main to i8*), i32 zeroext 0)
comment|// EXT-NEXT:  call void [[REG1]]()
name|foo
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// NOEXT: declare void @__llvm_profile_instrument_target(i64, i8*, i32)
end_comment

begin_comment
comment|// EXT: declare void @__llvm_profile_instrument_target(i64, i8*, i32 zeroext)
end_comment

end_unit

