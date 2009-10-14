begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|test_main
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

