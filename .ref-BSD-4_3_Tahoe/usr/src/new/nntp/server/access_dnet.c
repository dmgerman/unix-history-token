begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<syslog.h>
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
file|"../common/conf.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DECNET
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)access_dnet.c	1.4	(Berkeley) 10/22/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * dnet_netnames -- return the network, subnet, and host names of  * our peer process for the DECnet domain.  Since DECnet doesn't  * have subnets, we always return "subnet_name"'s first char as '\0';  *  *	Parameters:	"sock" is the socket connect to our peer.  *			"sap" is a pointer to the result of  *			a getpeername() call.  *			"net_name", "subnet_name", and "host_name"  *			are filled in by this routine with the  *			corresponding ASCII names of our peer.  *	Returns:	Nothing.  *	Side effects:	None.  */
end_comment

begin_macro
name|dnet_netnames
argument_list|(
argument|sock
argument_list|,
argument|sap
argument_list|,
argument|net_name
argument_list|,
argument|subnet_name
argument_list|,
argument|host_name
argument_list|)
end_macro

begin_decl_stmt
name|int
name|sock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|sap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|net_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|subnet_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|host_name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|struct
name|linger
name|l
decl_stmt|;
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
name|cp
operator|=
name|getenv
argument_list|(
literal|"NETWORK"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|net_name
argument_list|,
name|cp
condition|?
name|cp
else|:
literal|"DECnet"
argument_list|)
expr_stmt|;
name|cp
operator|=
name|getenv
argument_list|(
literal|"REMNODE"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|host_name
argument_list|,
name|cp
condition|?
name|cp
else|:
literal|"unknown"
argument_list|)
expr_stmt|;
operator|*
name|subnet_name
operator|=
literal|'\0'
expr_stmt|;
comment|/* 	 * Give decnet a chance to flush its buffers before the  	 * link is killed. 	 */
name|l
operator|.
name|l_onoff
operator|=
literal|1
expr_stmt|;
comment|/* on */
name|l
operator|.
name|l_linger
operator|=
literal|15
expr_stmt|;
comment|/* seconds */
if|if
condition|(
name|setsockopt
argument_list|(
name|sock
argument_list|,
name|SOL_SOCKET
argument_list|,
name|SO_LINGER
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|l
argument_list|,
sizeof|sizeof
argument_list|(
name|l
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|LOG
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"access_dnet: setsockopt SOL_SOCKET SO_LINGER: %m"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

