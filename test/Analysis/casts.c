begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=region --verify %s
end_comment

begin_comment
comment|// Test if the 'storage' region gets properly initialized after it is cast to
end_comment

begin_comment
comment|// 'struct sockaddr *'.
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_function
name|void
name|f
parameter_list|(
name|int
name|sock
parameter_list|)
block|{
name|struct
name|sockaddr_storage
name|storage
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|sockaddr
init|=
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|storage
decl_stmt|;
name|socklen_t
name|addrlen
init|=
sizeof|sizeof
argument_list|(
name|storage
argument_list|)
decl_stmt|;
name|getsockname
argument_list|(
name|sock
argument_list|,
name|sockaddr
argument_list|,
operator|&
name|addrlen
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|sockaddr
operator|->
name|sa_family
condition|)
block|{
comment|// no-warning
default|default:
empty_stmt|;
block|}
block|}
end_function

end_unit

