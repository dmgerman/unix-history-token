begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * socktoa - return a numeric host name from a sockaddr_storage structure  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDNTOP
end_ifdef

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"lib_strbuf.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_function
name|char
modifier|*
name|socktoa
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|sock
parameter_list|)
block|{
specifier|register
name|char
modifier|*
name|buffer
decl_stmt|;
name|LIB_GETBUF
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|sock
operator|==
name|NULL
condition|)
name|printf
argument_list|(
literal|"null"
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|sock
operator|->
name|ss_family
condition|)
block|{
case|case
name|AF_INET
case|:
name|inet_ntop
argument_list|(
name|AF_INET
argument_list|,
operator|&
name|GET_INADDR
argument_list|(
operator|*
name|sock
argument_list|)
argument_list|,
name|buffer
argument_list|,
name|LIB_BUFLENGTH
argument_list|)
expr_stmt|;
break|break;
case|case
name|AF_INET6
case|:
name|inet_ntop
argument_list|(
name|AF_INET6
argument_list|,
operator|&
name|GET_INADDR6
argument_list|(
operator|*
name|sock
argument_list|)
argument_list|,
name|buffer
argument_list|,
name|LIB_BUFLENGTH
argument_list|)
expr_stmt|;
block|}
return|return
name|buffer
return|;
block|}
end_function

end_unit

