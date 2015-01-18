begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -mrtd -triple i386-unknown-unknown -std=c89 -emit-llvm -o - %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: mrtd.c:10:3: warning: function with no prototype cannot use the stdcall calling convention
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
comment|// CHECK: define x86_stdcallcc void @foo(i32 %arg) [[NUW:#[0-9]+]]
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
comment|// CHECK: call x86_stdcallcc i32 bitcast (i32 (...)* @bar to i32 (i32)*)(
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

begin_function
name|void
name|qux
parameter_list|(
name|int
name|arg
parameter_list|,
modifier|...
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @qux(i32 %arg, ...)
end_comment

begin_function
name|void
name|quux
parameter_list|(
name|int
name|a1
parameter_list|,
name|int
name|a2
parameter_list|,
name|int
name|a3
parameter_list|)
block|{
name|qux
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define x86_stdcallcc void @quux
end_comment

begin_comment
comment|// CHECK: call void (i32, ...)* @qux
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { nounwind{{.*}} }
end_comment

end_unit

