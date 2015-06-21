begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 %s -emit-llvm -mdisable-tail-calls -o - | FileCheck %s -check-prefix=CHECK -check-prefix=DISABLE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 %s -emit-llvm -o - | FileCheck %s -check-prefix=CHECK -check-prefix=ENABLE
end_comment

begin_comment
comment|// CHECK: define i32 @f1() [[ATTR:#[0-9]+]] {
end_comment

begin_function
name|int
name|f1
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// DISABLE: attributes [[ATTR]] = { {{.*}} "disable-tail-calls"="true" {{.*}} }
end_comment

begin_comment
comment|// ENABLE: attributes [[ATTR]] = { {{.*}} "disable-tail-calls"="false" {{.*}} }
end_comment

end_unit

