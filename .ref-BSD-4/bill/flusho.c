begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|main
parameter_list|()
block|{
include|#
directive|include
file|<sys/ioctl.h>
name|ioctl
argument_list|(
literal|1
argument_list|,
name|TIOCFLUSH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

