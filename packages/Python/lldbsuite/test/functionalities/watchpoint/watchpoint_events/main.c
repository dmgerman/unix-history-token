begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
name|local_var
init|=
literal|10
decl_stmt|;
name|printf
argument_list|(
literal|"local_var is: %d.\n"
argument_list|,
name|local_var
operator|++
argument_list|)
expr_stmt|;
comment|// Put a breakpoint here.
return|return
name|local_var
return|;
block|}
end_function

end_unit

