begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -mrtd -triple i386-unknown-freebsd9.0 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|baz
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: define x86_stdcallcc void @foo(i32 %arg) nounwind
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
comment|// CHECK: call x86_stdcallcc i32 (...)* @bar(i32
name|bar
argument_list|(
name|arg
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_stdcallcc void @baz(i32
name|baz
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare x86_stdcallcc i32 @bar(...)
end_comment

begin_comment
comment|// CHECK: declare x86_stdcallcc void @baz(i32)
end_comment

end_unit

