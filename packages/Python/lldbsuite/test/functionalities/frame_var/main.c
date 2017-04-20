begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|g_var
init|=
literal|200
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|test_var
init|=
literal|10
decl_stmt|;
name|printf
argument_list|(
literal|"Set a breakpoint here: %d %d.\n"
argument_list|,
name|test_var
argument_list|,
name|g_var
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

