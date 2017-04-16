begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -Wno-incompatible-library-redeclaration -verify %s
end_comment

begin_comment
comment|// Various tests to make the the analyzer is robust against custom
end_comment

begin_comment
comment|// redeclarations of memory routines.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// You wouldn't expect to see much of this in normal code, but, for example,
end_comment

begin_comment
comment|// CMake tests can generate these.
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function_decl
name|char
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|kmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|valloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|kfree
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|testCustomArgumentlessAllocation
parameter_list|()
block|{
name|alloca
argument_list|()
expr_stmt|;
comment|// no-crash
name|malloc
argument_list|()
expr_stmt|;
comment|// no-crash
name|realloc
argument_list|()
expr_stmt|;
comment|// no-crash
name|kmalloc
argument_list|()
expr_stmt|;
comment|// no-crash
name|valloc
argument_list|()
expr_stmt|;
comment|// no-crash
name|calloc
argument_list|()
expr_stmt|;
comment|// no-crash
name|free
argument_list|()
expr_stmt|;
comment|// no-crash
name|kfree
argument_list|()
expr_stmt|;
comment|// no-crash
block|}
end_function

end_unit

