begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|open
argument_list|(
literal|"."
argument_list|,
name|O_RDONLY
operator||
name|O_DIRECTORY
argument_list|)
operator|==
operator|-
literal|1
return|;
block|}
end_function

end_unit

