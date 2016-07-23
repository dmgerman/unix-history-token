begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_function
name|int
name|main_func
parameter_list|(
name|int
name|input
parameter_list|)
block|{
return|return
name|printf
argument_list|(
literal|"Set B breakpoint here: %d.\n"
argument_list|,
name|input
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|a_func
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|main_func
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Set a breakpoint here:\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

