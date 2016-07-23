begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.10.0 -emit-llvm -Oz -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define i32 @foo2(i32 %a) local_unnamed_addr [[ATTRS2:#[0-9]+]] {
end_comment

begin_comment
comment|// CHECK: define i32 @foo1(i32 %a) local_unnamed_addr [[ATTRS1:#[0-9]+]] {
end_comment

begin_function_decl
name|int
name|foo1
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|foo2
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|foo1
argument_list|(
name|a
operator|+
literal|2
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(optnone)
argument_list|)
end_macro

begin_function
name|int
name|foo1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK: attributes [[ATTRS2]] = { {{.*}}optsize{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[ATTRS1]] = { {{.*}}optnone{{.*}} }
end_comment

end_unit

