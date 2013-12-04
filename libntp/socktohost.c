begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * socktoa - return a numeric host name from a sockaddr_storage structure  */
end_comment

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
name|socktohost
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
name|getnameinfo
argument_list|(
operator|&
name|sock
operator|->
name|sa
argument_list|,
name|SOCKLEN
argument_list|(
name|sock
argument_list|)
argument_list|,
name|buffer
argument_list|,
name|LIB_BUFLENGTH
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|stoa
argument_list|(
name|sock
argument_list|)
return|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

