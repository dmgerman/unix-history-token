begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ns.h ------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
name|void
name|test_lookup_at_global_scope
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_lookup_at_file_scope
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_lookup_before_using_directive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_lookup_after_using_directive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|func
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|namespace
name|A
block|{
name|int
name|foo
parameter_list|()
function_decl|;
name|int
name|func
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
specifier|inline
name|int
name|func
parameter_list|()
block|{
name|printf
argument_list|(
literal|"A::func()\n"
argument_list|)
expr_stmt|;
return|return
literal|3
return|;
block|}
specifier|inline
name|int
name|func2
parameter_list|()
block|{
name|printf
argument_list|(
literal|"A::func2()\n"
argument_list|)
expr_stmt|;
return|return
literal|3
return|;
block|}
name|void
name|test_lookup_at_ns_scope
parameter_list|()
function_decl|;
name|namespace
name|B
block|{
name|int
name|func
parameter_list|()
function_decl|;
name|void
name|test_lookup_at_nested_ns_scope
parameter_list|()
function_decl|;
name|void
name|test_lookup_at_nested_ns_scope_after_using
parameter_list|()
function_decl|;
block|}
block|}
end_decl_stmt

end_unit

