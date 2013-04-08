begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: define void @g() [[NUW:#[0-9]+]]
comment|// CHECK-NOT: call void @f() nounwind
name|f
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NOT: declare void @f() [[NUW]]
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { nounwind{{.*}} }
end_comment

end_unit

