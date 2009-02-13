begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * The Dynix/PTX TLI implementation is not quite compatible with System V   * Release 4. Some important functions are not present so we are limited to   * IP-based services.   *    * Diagnostics are reported through syslog(3).   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#) ptx.c 1.3 94/12/28 17:42:38"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PTX
end_ifdef

begin_comment
comment|/* System libraries. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/tiuser.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<stropts.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_comment
comment|/* Local stuff. */
end_comment

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_comment
comment|/* Forward declarations. */
end_comment

begin_function_decl
specifier|static
name|void
name|ptx_sink
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tli_host - determine TLI endpoint info, PTX version */
end_comment

begin_function
name|void
name|tli_host
parameter_list|(
name|request
parameter_list|)
name|struct
name|request_info
modifier|*
name|request
decl_stmt|;
block|{
specifier|static
name|struct
name|sockaddr_in
name|client
decl_stmt|;
specifier|static
name|struct
name|sockaddr_in
name|server
decl_stmt|;
comment|/*      * getpeerinaddr() was suggested by someone at Sequent. It seems to work      * with connection-oriented (TCP) services such as rlogind and telnetd,      * but it returns 0.0.0.0 with datagram (UDP) services. No problem: UDP      * needs special treatment anyway, in case we must refuse service.      */
if|if
condition|(
name|getpeerinaddr
argument_list|(
name|request
operator|->
name|fd
argument_list|,
operator|&
name|client
argument_list|,
sizeof|sizeof
argument_list|(
name|client
argument_list|)
argument_list|)
operator|==
literal|0
operator|&&
name|client
operator|.
name|sin_addr
operator|.
name|s_addr
operator|!=
literal|0
condition|)
block|{
name|request
operator|->
name|client
operator|->
name|sin
operator|=
operator|&
name|client
expr_stmt|;
if|if
condition|(
name|getmyinaddr
argument_list|(
name|request
operator|->
name|fd
argument_list|,
operator|&
name|server
argument_list|,
sizeof|sizeof
argument_list|(
name|server
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|request
operator|->
name|server
operator|->
name|sin
operator|=
operator|&
name|server
expr_stmt|;
block|}
else|else
block|{
name|tcpd_warn
argument_list|(
literal|"warning: getmyinaddr: %m"
argument_list|)
expr_stmt|;
block|}
name|sock_methods
argument_list|(
name|request
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 	 * Another suggestion was to temporarily switch to the socket 	 * interface, identify the endpoint addresses with socket calls, then 	 * to switch back to TLI. This seems to works OK with UDP services, 	 * which is exactly what we should be looking at right now. 	 */
define|#
directive|define
name|SWAP_MODULE
parameter_list|(
name|f
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
value|(ioctl(f, I_POP, old), ioctl(f, I_PUSH, new))
if|if
condition|(
name|SWAP_MODULE
argument_list|(
name|request
operator|->
name|fd
argument_list|,
literal|"timod"
argument_list|,
literal|"sockmod"
argument_list|)
operator|!=
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"replace timod by sockmod: %m"
argument_list|)
expr_stmt|;
name|sock_host
argument_list|(
name|request
argument_list|)
expr_stmt|;
if|if
condition|(
name|SWAP_MODULE
argument_list|(
name|request
operator|->
name|fd
argument_list|,
literal|"sockmod"
argument_list|,
literal|"timod"
argument_list|)
operator|!=
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"replace sockmod by timod: %m"
argument_list|)
expr_stmt|;
if|if
condition|(
name|request
operator|->
name|sink
operator|!=
literal|0
condition|)
name|request
operator|->
name|sink
operator|=
name|ptx_sink
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* ptx_sink - absorb unreceived IP datagram */
end_comment

begin_function
specifier|static
name|void
name|ptx_sink
parameter_list|(
name|fd
parameter_list|)
name|int
name|fd
decl_stmt|;
block|{
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|int
name|size
init|=
sizeof|sizeof
argument_list|(
name|sa
argument_list|)
decl_stmt|;
comment|/*      * Eat up the not-yet received datagram. Where needed, switch to the      * socket programming interface.      */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_FIND
argument_list|,
literal|"timod"
argument_list|)
operator|!=
literal|0
condition|)
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_POP
argument_list|,
literal|"timod"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_FIND
argument_list|,
literal|"sockmod"
argument_list|)
operator|==
literal|0
condition|)
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_PUSH
argument_list|,
literal|"sockmod"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|recvfrom
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|sa
argument_list|,
operator|&
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PTX */
end_comment

end_unit

