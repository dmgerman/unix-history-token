begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|global_var
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Set a breakpoint here: %d.\n"
argument_list|,
name|global_var
argument_list|)
expr_stmt|;
name|global_var
operator|=
literal|20
expr_stmt|;
name|printf
argument_list|(
literal|"We should have stopped on the previous line: %d.\n"
argument_list|,
name|global_var
argument_list|)
expr_stmt|;
name|global_var
operator|=
literal|30
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

