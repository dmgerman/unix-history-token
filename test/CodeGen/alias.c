begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-pc-linux-gnu -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@g0 = common global i32 0' %t
end_comment

begin_comment
comment|// RUN: grep '@f1 = alias void ()\* @f0' %t
end_comment

begin_comment
comment|// RUN: grep '@g1 = alias i32\* @g0' %t
end_comment

begin_comment
comment|// RUN: grep 'define void @f0() nounwind {' %t
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function_decl
specifier|extern
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f0"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|g0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g1
name|__attribute
argument_list|(
operator|(
name|alias
argument_list|(
literal|"g0"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Make sure that aliases cause referenced values to be emitted.
end_comment

begin_comment
comment|// PR3200
end_comment

begin_comment
comment|// RUN: grep 'define internal i32 @foo1()' %t
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|foo1
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"foo1"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// RUN: grep '@bar1 = internal global i32 42' %t
end_comment

begin_decl_stmt
specifier|static
name|int
name|bar1
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"bar1"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|test6
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test7
parameter_list|()
block|{
name|test6
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// test6 is emitted as extern.
end_comment

begin_comment
comment|// test6 changes to alias.
end_comment

begin_function_decl
name|int
name|test6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"test7"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

end_unit

