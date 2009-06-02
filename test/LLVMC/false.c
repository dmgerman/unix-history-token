begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that we can compile .c files as C++ and vice versa
end_comment

begin_comment
comment|// RUN: llvmc -x c++ %s -x c %p/test_data/false.cpp -x lisp -x whatnot -x none %p/test_data/false2.cpp -o %t
end_comment

begin_comment
comment|// RUN: ./%t | grep hello
end_comment

begin_include
include|#
directive|include
file|<iostream>
end_include

begin_extern
extern|extern
literal|"C"
name|void
name|test
parameter_list|()
function_decl|;
end_extern

begin_extern
extern|extern std::string test2(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|std
operator|::
name|cout
operator|<<
literal|"h"
expr_stmt|;
name|test
argument_list|()
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|test2
argument_list|()
operator|<<
literal|'\n'
expr_stmt|;
block|}
end_function

end_unit

