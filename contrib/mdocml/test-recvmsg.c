begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|recvmsg
argument_list|(
operator|-
literal|1
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
end_function

end_unit

