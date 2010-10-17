begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test function.  This is built into a shared library, and references a  * versioned symbol foo that is in test.so.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|int
name|show_foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|show_xyzzy
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%d"
argument_list|,
name|show_foo
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

