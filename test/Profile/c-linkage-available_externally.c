begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure instrementation data from available_externally functions doesn't
end_comment

begin_comment
comment|// get thrown out.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -triple x86_64-apple-macosx10.9 -main-file-name c-linkage-available_externally.c %s -o - -emit-llvm -fprofile-instr-generate | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @__llvm_profile_counters_foo = linkonce_odr hidden global [1 x i64] zeroinitializer, section "__DATA,__llvm_prf_cnts", align 8
end_comment

begin_comment
comment|// CHECK: @__llvm_profile_name_foo = linkonce_odr hidden constant [3 x i8] c"foo", section "__DATA,__llvm_prf_names", align 1
end_comment

begin_comment
comment|// CHECK: @__llvm_profile_data_foo = linkonce_odr hidden constant { i32, i32, i64, i8*, i64* } { i32 3, i32 1, i64 {{[0-9]+}}, i8* getelementptr inbounds ([3 x i8]* @__llvm_profile_name_foo, i32 0, i32 0), i64* getelementptr inbounds ([1 x i64]* @__llvm_profile_counters_foo, i32 0, i32 0) }, section "__DATA,__llvm_prf_data", align 8
end_comment

begin_function
specifier|inline
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|foo
argument_list|()
return|;
block|}
end_function

end_unit

