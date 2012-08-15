begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @b = external thread_local global
end_comment

begin_comment
comment|// CHECK: @d.e = internal thread_local global
end_comment

begin_comment
comment|// CHECK: @d.f = internal thread_local global
end_comment

begin_comment
comment|// CHECK: @f.a = internal thread_local(initialexec) global
end_comment

begin_comment
comment|// CHECK: @a = thread_local global
end_comment

begin_comment
comment|// CHECK: @g = thread_local global
end_comment

begin_comment
comment|// CHECK: @h = thread_local(localdynamic) global
end_comment

begin_comment
comment|// CHECK: @i = thread_local(initialexec) global
end_comment

begin_comment
comment|// CHECK: @j = thread_local(localexec) global
end_comment

begin_decl_stmt
name|__thread
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__thread
name|int
name|b
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|c
parameter_list|()
block|{
return|return
operator|*
operator|&
name|b
return|;
block|}
end_function

begin_function
name|int
name|d
parameter_list|()
block|{
name|__thread
specifier|static
name|int
name|e
decl_stmt|;
name|__thread
specifier|static
expr|union
block|{
name|float
name|a
block|;
name|int
name|b
block|;}
name|f
operator|=
block|{
operator|.
name|b
operator|=
literal|1
block|}
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|__thread
name|int
name|g
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"global-dynamic"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|h
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"local-dynamic"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|i
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"initial-exec"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|j
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"local-exec"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f
parameter_list|()
block|{
name|__thread
specifier|static
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"initial-exec"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
return|return
name|a
operator|++
return|;
block|}
end_function

end_unit

