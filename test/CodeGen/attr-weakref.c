begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple i386-linux-gnu -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// CHECK: declare extern_weak void @test1_f()
end_comment

begin_function_decl
name|void
name|test1_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|test1_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test1_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test1_h
parameter_list|(
name|void
parameter_list|)
block|{
name|test1_g
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test2_f()
end_comment

begin_function
name|void
name|test2_f
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function_decl
specifier|static
name|void
name|test2_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test2_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test2_h
parameter_list|(
name|void
parameter_list|)
block|{
name|test2_g
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare void @test3_f()
end_comment

begin_function_decl
name|void
name|test3_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|test3_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test3_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test3_foo
parameter_list|(
name|void
parameter_list|)
block|{
name|test3_f
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test3_h
parameter_list|(
name|void
parameter_list|)
block|{
name|test3_g
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test4_f()
end_comment

begin_function_decl
name|void
name|test4_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|test4_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test4_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test4_h
parameter_list|(
name|void
parameter_list|)
block|{
name|test4_g
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test4_f
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: declare void @test5_f()
end_comment

begin_function_decl
name|void
name|test5_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|test5_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test5_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test5_h
parameter_list|(
name|void
parameter_list|)
block|{
name|test5_g
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test5_foo
parameter_list|(
name|void
parameter_list|)
block|{
name|test5_f
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare extern_weak void @test6_f()
end_comment

begin_function_decl
name|void
name|test6_f
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|void
name|test6_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test6_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test6_h
parameter_list|(
name|void
parameter_list|)
block|{
name|test6_g
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test6_foo
parameter_list|(
name|void
parameter_list|)
block|{
name|test6_f
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare extern_weak void @test8_f()
end_comment

begin_function_decl
specifier|static
name|void
name|test8_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test8_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test8_h
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|test8_g
condition|)
name|test8_g
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare extern_weak void @test7_f()
end_comment

begin_function_decl
name|void
name|test7_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|test7_g
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weakref
parameter_list|(
function_decl|"test7_f"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|void
modifier|*
specifier|const
name|test7_zed
init|=
operator|(
name|void
operator|*
operator|)
operator|&
name|test7_g
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|test7_h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|test7_zed
return|;
block|}
end_function

end_unit

