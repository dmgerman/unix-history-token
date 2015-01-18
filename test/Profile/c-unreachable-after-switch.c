begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -triple x86_64-apple-macosx10.10 -main-file-name c-unreachable-after-switch.c %s -o - -emit-llvm -fprofile-instr-generate | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @[[C:__llvm_profile_counters_foo]] = hidden global [3 x i64] zeroinitializer
end_comment

begin_comment
comment|// CHECK-LABEL: @foo()
end_comment

begin_comment
comment|// CHECK: store {{.*}} @[[C]], i64 0, i64 0
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK: store {{.*}} @[[C]], i64 0, i64 2
switch|switch
condition|(
literal|0
condition|)
block|{
default|default:
return|return;
block|}
comment|// We shouldn't emit the unreachable counter. This used to crash in GlobalDCE.
comment|// CHECK-NOT: store {{.*}} @[[SWC]], i64 0, i64 1}
block|}
end_function

end_unit

