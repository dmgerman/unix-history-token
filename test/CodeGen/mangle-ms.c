begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=x86_64-pc-win32 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define void @"\01?f@@$$J0YAXP6AX@Z@Z"
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(overloadable)
argument_list|)
end_macro

begin_function
name|void
name|f
parameter_list|(
name|void
function_decl|(
modifier|*
name|x
function_decl|)
parameter_list|()
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
function_decl|(
modifier|*
name|x
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @g
end_comment

begin_function
name|void
name|g
parameter_list|(
name|void
function_decl|(
modifier|*
name|x
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @"\01?g@@$$J0YAXP6AX@Z@Z"
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(overloadable)
argument_list|)
end_macro

begin_function
name|void
name|g
parameter_list|(
name|void
function_decl|(
modifier|*
name|x
function_decl|)
parameter_list|()
parameter_list|)
block|{}
end_function

end_unit

