begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* portnm.c    Get the port name of stdin.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_if
if|#
directive|if
name|HAVE_TCP
end_if

begin_if
if|#
directive|if
name|HAVE_SYS_TYPES_TCP_H
end_if

begin_include
include|#
directive|include
file|<sys/types.tcp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ttyname
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the port name of standard input.  I assume that Unix systems    generally support ttyname.  If they don't, this function can just    return NULL.  It uses getsockname to see whether standard input is    a TCP connection.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|zsysdep_port_name
parameter_list|(
name|ftcp_port
parameter_list|)
name|boolean
modifier|*
name|ftcp_port
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|z
decl_stmt|;
operator|*
name|ftcp_port
operator|=
name|FALSE
expr_stmt|;
if|#
directive|if
name|HAVE_TCP
block|{
name|size_t
name|clen
decl_stmt|;
name|struct
name|sockaddr
name|s
decl_stmt|;
name|clen
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|getsockname
argument_list|(
literal|0
argument_list|,
operator|&
name|s
argument_list|,
operator|&
name|clen
argument_list|)
operator|==
literal|0
condition|)
operator|*
name|ftcp_port
operator|=
name|TRUE
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* HAVE_TCP */
name|z
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|z
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
if|if
condition|(
name|strncmp
argument_list|(
name|z
argument_list|,
name|_PATH_DEV
argument_list|,
sizeof|sizeof
name|_PATH_DEV
operator|-
literal|1
argument_list|)
operator|==
literal|0
condition|)
return|return
name|z
operator|+
sizeof|sizeof
name|_PATH_DEV
operator|-
literal|1
return|;
else|else
return|return
name|z
return|;
block|}
end_function

end_unit

