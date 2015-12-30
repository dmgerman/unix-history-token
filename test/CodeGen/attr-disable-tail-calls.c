begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 %s -emit-llvm -mdisable-tail-calls -o - | FileCheck %s -check-prefix=DISABLE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 %s -emit-llvm -o - | FileCheck %s -check-prefix=ENABLE
end_comment

begin_comment
comment|// DISABLE: define i32 @f1() [[ATTRTRUE:#[0-9]+]] {
end_comment

begin_comment
comment|// DISABLE: define i32 @f2() [[ATTRTRUE]] {
end_comment

begin_comment
comment|// ENABLE: define i32 @f1() [[ATTRFALSE:#[0-9]+]] {
end_comment

begin_comment
comment|// ENABLE: define i32 @f2() [[ATTRTRUE:#[0-9]+]] {
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

begin_function
name|int
name|f2
parameter_list|()
function|__attribute__
parameter_list|(
function|(disable_tail_calls
end_function

begin_block
unit|))
block|{
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|// DISABLE: attributes [[ATTRTRUE]] = { {{.*}}"disable-tail-calls"="true"{{.*}} }
end_comment

begin_comment
comment|// ENABLE: attributes [[ATTRFALSE]] = { {{.*}}"disable-tail-calls"="false"{{.*}} }
end_comment

begin_comment
comment|// ENABLE: attributes [[ATTRTRUE]] = { {{.*}}"disable-tail-calls"="true"{{.*}} }
end_comment

end_unit

