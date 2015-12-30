begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=i386-pc-solaris2.11 -w -emit-llvm %s -o - | FileCheck %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fake
name|real
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|name
name|alias
end_pragma

begin_function_decl
specifier|extern
name|int
name|fake
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|name
decl_stmt|;
end_decl_stmt

begin_comment
comment|// __PRAGMA_REDEFINE_EXTNAME should be defined.  This will fail if it isn't...
end_comment

begin_function
name|int
name|fish
parameter_list|()
block|{
return|return
name|fake
argument_list|()
operator|+
name|__PRAGMA_REDEFINE_EXTNAME
operator|+
name|name
return|;
block|}
end_function

begin_comment
comment|// Check that the call to fake() is emitted as a call to real()
end_comment

begin_comment
comment|// CHECK:   call i32 @real()
end_comment

begin_comment
comment|// Check that this also works with variables names
end_comment

begin_comment
comment|// CHECK:   load i32, i32* @alias
end_comment

begin_comment
comment|// This is a case when redefenition is deferred *and* we have a local of the
end_comment

begin_comment
comment|// same name. PR23923.
end_comment

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|foo
name|bar
end_pragma

begin_function
name|int
name|f
parameter_list|()
block|{
name|int
name|foo
init|=
literal|0
decl_stmt|;
return|return
name|foo
return|;
block|}
end_function

begin_function
specifier|extern
name|int
name|foo
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i32 @bar()
end_comment

begin_comment
comment|// Check that pragma redefine_extname applies to external declarations only.
end_comment

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|foo_static
name|bar_static
end_pragma

begin_function
specifier|static
name|int
name|foo_static
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|baz
parameter_list|()
block|{
return|return
name|foo_static
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK-NOT: call i32 @bar_static()
end_comment

end_unit

