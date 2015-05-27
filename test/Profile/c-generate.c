begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that the -fprofile-instr-generate= form works.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -main-file-name c-generate.c %s -o - -emit-llvm -fprofile-instr-generate=c-generate-test.profraw | FileCheck %s
end_comment

begin_comment
comment|// CHECK: private constant [24 x i8] c"c-generate-test.profraw\00"
end_comment

begin_comment
comment|// CHECK: call void @__llvm_profile_override_default_filename(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @0, i32 0, i32 0))
end_comment

begin_comment
comment|// CHECK: declare void @__llvm_profile_override_default_filename(i8*)
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

