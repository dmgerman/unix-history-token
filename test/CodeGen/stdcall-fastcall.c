begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | FileCheck %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|f1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f2
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
name|f3
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|f4
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define x86_fastcallcc void @f4()
name|f1
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_fastcallcc void @f1()
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f5
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define x86_stdcallcc void @f5()
name|f2
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_stdcallcc void @f2()
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
name|f6
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define x86_thiscallcc void @f6()
name|f3
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_thiscallcc void @f3()
block|}
end_decl_stmt

begin_comment
comment|// PR5280
end_comment

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
operator|*
name|pf1
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
operator|*
name|pf2
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
operator|*
name|pf3
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
operator|*
name|pf4
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f4
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
operator|*
name|pf5
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f5
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
operator|*
name|pf6
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f6
expr_stmt|;
end_expr_stmt

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

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f7
argument_list|(
name|foo
argument_list|)
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_block
block|{}
end_block

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
comment|// CHECK: call x86_stdcallcc void (...)* bitcast
block|}
end_function

end_unit

