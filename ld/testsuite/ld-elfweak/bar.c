begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|foobar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|printf
argument_list|(
literal|"strong foo\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foobar
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

