begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|0xabcd
argument_list|,
literal|1024
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"write"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

