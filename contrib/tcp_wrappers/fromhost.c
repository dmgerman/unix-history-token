begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * On socket-only systems, fromhost() is nothing but an alias for the   * socket-specific sock_host() function.   *    * On systems with sockets and TLI, fromhost() determines the type of API   * (sockets, TLI), then invokes the appropriate API-specific routines.   *    * Diagnostics are reported through syslog(3).   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
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
literal|"@(#) fromhost.c 1.17 94/12/28 17:42:23"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TLI
argument_list|)
operator|||
name|defined
argument_list|(
name|PTX
argument_list|)
operator|||
name|defined
argument_list|(
name|TLI_SEQUENT
argument_list|)
end_if

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
file|<stropts.h>
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
comment|/* fromhost - find out what network API we should use */
end_comment

begin_function
name|void
name|fromhost
parameter_list|(
name|request
parameter_list|)
name|struct
name|request_info
modifier|*
name|request
decl_stmt|;
block|{
comment|/*      * On systems with streams support the IP network protocol family may be      * accessible via more than one programming interface: Berkeley sockets      * and the Transport Level Interface (TLI).      *       * Thus, we must first find out what programming interface to use: sockets      * or TLI. On some systems, sockets are not part of the streams system,      * so if request->fd is not a stream we simply assume sockets.      */
if|if
condition|(
name|ioctl
argument_list|(
name|request
operator|->
name|fd
argument_list|,
name|I_FIND
argument_list|,
literal|"timod"
argument_list|)
operator|>
literal|0
condition|)
block|{
name|tli_host
argument_list|(
name|request
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sock_host
argument_list|(
name|request
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLI || PTX || TLI_SEQUENT */
end_comment

end_unit

