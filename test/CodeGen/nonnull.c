begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define void @foo(i32* nonnull %x)
end_comment

begin_decl_stmt
name|void
name|foo
argument_list|(
name|int
operator|*
name|__attribute__
argument_list|(
argument|(nonnull)
argument_list|)
name|x
argument_list|)
block|{
operator|*
name|x
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK: define void @bar(i32* nonnull %x)
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function|__attribute__
parameter_list|(
function|(nonnull
parameter_list|(
function|1
end_function

begin_block
unit|)))
block|{
operator|*
name|x
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|// CHECK: define void @bar2(i32* %x, i32* nonnull %y)
end_comment

begin_function
name|void
name|bar2
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|int
modifier|*
name|y
parameter_list|)
function|__attribute__
parameter_list|(
function|(nonnull
parameter_list|(
function|2
end_function

begin_block
unit|)))
block|{
operator|*
name|x
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: define nonnull i32* @bar3()
end_comment

begin_function
name|int
modifier|*
name|bar3
parameter_list|()
function|__attribute__
parameter_list|(
function|(returns_nonnull
end_function

begin_block
unit|))
block|{
return|return
operator|&
name|a
return|;
block|}
end_block

end_unit

