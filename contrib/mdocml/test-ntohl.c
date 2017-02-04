begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|htonl
argument_list|(
name|ntohl
argument_list|(
literal|0x3a7d0cdb
argument_list|)
argument_list|)
operator|!=
literal|0x3a7d0cdb
return|;
block|}
end_function

end_unit

