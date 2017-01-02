begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|call_me
parameter_list|(
name|int
name|argc
parameter_list|)
block|{
name|printf
argument_list|(
literal|"At the start, argc: %d.\n"
argument_list|,
name|argc
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
name|printf
argument_list|(
literal|"Less than 2.\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Greater than or equal to 2.\n"
argument_list|)
expr_stmt|;
block|}
end_function

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
name|call_me
argument_list|(
name|argc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Back out in main.\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

