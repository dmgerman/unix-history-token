begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tty
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

