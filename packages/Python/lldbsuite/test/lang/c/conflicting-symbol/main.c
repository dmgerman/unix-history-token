begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"One/One.h"
end_include

begin_include
include|#
directive|include
file|"Two/Two.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|one
argument_list|()
expr_stmt|;
name|two
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"main\n"
argument_list|)
expr_stmt|;
comment|// break here
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

