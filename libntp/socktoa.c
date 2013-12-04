begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * socktoa - return a numeric host name from a sockaddr_storage structure  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
specifier|const
name|sockaddr_u
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
name|NULL
operator|==
name|sock
condition|)
name|strncpy
argument_list|(
name|buffer
argument_list|,
literal|"(null)"
argument_list|,
name|LIB_BUFLENGTH
argument_list|)
expr_stmt|;
else|else
block|{
switch|switch
condition|(
name|AF
argument_list|(
name|sock
argument_list|)
condition|)
block|{
case|case
name|AF_INET
case|:
case|case
name|AF_UNSPEC
case|:
name|inet_ntop
argument_list|(
name|AF_INET
argument_list|,
name|PSOCK_ADDR4
argument_list|(
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
name|PSOCK_ADDR6
argument_list|(
name|sock
argument_list|)
argument_list|,
name|buffer
argument_list|,
name|LIB_BUFLENGTH
argument_list|)
expr_stmt|;
break|break;
default|default:
name|snprintf
argument_list|(
name|buffer
argument_list|,
name|LIB_BUFLENGTH
argument_list|,
literal|"(socktoa unknown family %d)"
argument_list|,
name|AF
argument_list|(
name|sock
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|buffer
return|;
block|}
end_function

end_unit

