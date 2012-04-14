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
comment|// CHECK:   load i32* @alias
end_comment

end_unit

