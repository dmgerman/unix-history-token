begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 %s -emit-llvm -fms-compatibility -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define void @t3() nounwind noinline naked {
end_comment

begin_macro
name|__declspec
argument_list|(
argument|naked
argument_list|)
end_macro

begin_function
name|void
name|t3
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define void @t22() nounwind
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|nothrow
parameter_list|)
function_decl|t22
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|t22
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define void @t2() nounwind noinline {
end_comment

begin_macro
name|__declspec
argument_list|(
argument|noinline
argument_list|)
end_macro

begin_function
name|void
name|t2
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: call void @f20_t()
end_comment

begin_comment
comment|// CHECK: noreturn
end_comment

begin_macro
name|__declspec
argument_list|(
argument|noreturn
argument_list|)
end_macro

begin_function_decl
name|void
name|f20_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f20
parameter_list|(
name|void
parameter_list|)
block|{
name|f20_t
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

