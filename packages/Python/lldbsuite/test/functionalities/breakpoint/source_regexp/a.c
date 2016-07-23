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
specifier|static
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
literal|"Set B breakpoint here: %d"
argument_list|,
name|input
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|a_func
parameter_list|(
name|int
name|input
parameter_list|)
block|{
name|input
operator|+=
literal|1
expr_stmt|;
comment|// Set A breakpoint here;
return|return
name|main_func
argument_list|(
name|input
argument_list|)
return|;
block|}
end_function

end_unit

