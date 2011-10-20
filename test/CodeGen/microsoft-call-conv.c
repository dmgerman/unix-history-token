begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|__fastcall
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__stdcall
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__thiscall
name|f3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__fastcall
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: define x86_fastcallcc void @f4()
name|f1
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_fastcallcc void @f1()
block|}
end_function

begin_function
name|void
name|__stdcall
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: define x86_stdcallcc void @f5()
name|f2
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_stdcallcc void @f2()
block|}
end_function

begin_function
name|void
name|__thiscall
name|f6
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: define x86_thiscallcc void @f6()
name|f3
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_thiscallcc void @f3()
block|}
end_function

begin_comment
comment|// PR5280
end_comment

begin_function_decl
name|void
function_decl|(
name|__fastcall
modifier|*
name|pf1
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f1
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
name|__stdcall
modifier|*
name|pf2
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f2
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
name|__thiscall
modifier|*
name|pf3
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f3
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
name|__fastcall
modifier|*
name|pf4
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f4
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
name|__stdcall
modifier|*
name|pf5
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f5
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
name|__thiscall
modifier|*
name|pf6
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f6
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|f4
argument_list|()
expr_stmt|;
name|f5
argument_list|()
expr_stmt|;
name|f6
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_fastcallcc void @f4()
comment|// CHECK: call x86_stdcallcc void @f5()
comment|// CHECK: call x86_thiscallcc void @f6()
name|pf1
argument_list|()
expr_stmt|;
name|pf2
argument_list|()
expr_stmt|;
name|pf3
argument_list|()
expr_stmt|;
name|pf4
argument_list|()
expr_stmt|;
name|pf5
argument_list|()
expr_stmt|;
name|pf6
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_fastcallcc void %{{.*}}()
comment|// CHECK: call x86_stdcallcc void %{{.*}}()
comment|// CHECK: call x86_thiscallcc void %{{.*}}()
comment|// CHECK: call x86_fastcallcc void %{{.*}}()
comment|// CHECK: call x86_stdcallcc void %{{.*}}()
comment|// CHECK: call x86_thiscallcc void %{{.*}}()
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PR7117
end_comment

begin_function
name|void
name|__stdcall
name|f7
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{}
end_function

begin_function
name|void
name|f8
parameter_list|(
name|void
parameter_list|)
block|{
name|f7
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_stdcallcc void @f7(i32 0)
block|}
end_function

end_unit

