begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure instrumentation data from available_externally functions doesn't
end_comment

begin_comment
comment|// get thrown out and are emitted with the expected linkage.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -triple x86_64-apple-macosx10.9 -main-file-name c-linkage-available_externally.c %s -o - -emit-llvm -fprofile-instrument=clang | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @__profc_foo = linkonce_odr hidden global [1 x i64] zeroinitializer, section "__DATA,__llvm_prf_cnts", align 8
end_comment

begin_comment
comment|// CHECK: @__profd_foo = linkonce_odr hidden global {{.*}} i64* getelementptr inbounds ([1 x i64], [1 x i64]* @__profc_foo, i32 0, i32 0){{.*}}, section "__DATA,__llvm_prf_data,regular,live_support", align 8
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

