begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple i386-linux-gnu -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// CHECK: @test1_f = extern_weak global i32
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test1_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|test1_g
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"test1_f"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test1_h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test1_g
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test2_f = common global i32 0, align 4
end_comment

begin_decl_stmt
name|int
name|test2_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|test2_g
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"test2_f"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test2_h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test2_g
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test3_f = external global i32
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test3_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|test3_g
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"test3_f"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test3_foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test3_f
return|;
block|}
end_function

begin_function
name|int
name|test3_h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test3_g
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test4_f = common global i32 0, align 4
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test4_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|test4_g
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"test4_f"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test4_h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test4_g
return|;
block|}
end_function

begin_decl_stmt
name|int
name|test4_f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @test5_f = external global i32
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test5_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|test5_g
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"test5_f"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test5_h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test5_g
return|;
block|}
end_function

begin_function
name|int
name|test5_foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test5_f
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test6_f = extern_weak global i32
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test6_f
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|test6_g
name|__attribute__
argument_list|(
operator|(
name|weakref
argument_list|(
literal|"test6_f"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test6_h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test6_g
return|;
block|}
end_function

begin_function
name|int
name|test6_foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test6_f
return|;
block|}
end_function

end_unit

