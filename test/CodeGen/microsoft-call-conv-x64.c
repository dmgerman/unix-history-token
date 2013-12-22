begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-win32 -emit-llvm< %s | FileCheck %s
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

begin_function
name|void
name|__fastcall
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @f4()
name|f1
argument_list|()
expr_stmt|;
comment|// CHECK: call void @f1()
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
comment|// CHECK-LABEL: define void @f5()
name|f2
argument_list|()
expr_stmt|;
comment|// CHECK: call void @f2()
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
comment|// CHECK: call void @f4()
comment|// CHECK: call void @f5()
name|pf1
argument_list|()
expr_stmt|;
name|pf2
argument_list|()
expr_stmt|;
name|pf4
argument_list|()
expr_stmt|;
name|pf5
argument_list|()
expr_stmt|;
comment|// CHECK: call void %{{.*}}()
comment|// CHECK: call void %{{.*}}()
comment|// CHECK: call void %{{.*}}()
comment|// CHECK: call void %{{.*}}()
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
comment|// CHECK: call void @f7(i32 0)
block|}
end_function

end_unit

