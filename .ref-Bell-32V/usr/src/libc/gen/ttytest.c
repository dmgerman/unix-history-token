begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"\nttyname(fd)=%s\n"
argument_list|,
name|ttyname
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nttyname=%s\n"
argument_list|,
name|ttyname
argument_list|(
name|stdin
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

