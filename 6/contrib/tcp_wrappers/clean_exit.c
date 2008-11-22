begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * clean_exit() cleans up and terminates the program. It should be called   * instead of exit() when for some reason the real network daemon will not or   * cannot be run. Reason: in the case of a datagram-oriented service we must   * discard the not-yet received data from the client. Otherwise, inetd will   * see the same datagram again and again, and go into a loop.   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
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
literal|"@(#) clean_exit.c 1.4 94/12/28 17:42:19"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_comment
comment|/* clean_exit - clean up and exit */
end_comment

begin_function
name|void
name|clean_exit
parameter_list|(
name|request
parameter_list|)
name|struct
name|request_info
modifier|*
name|request
decl_stmt|;
block|{
comment|/*      * In case of unconnected protocols we must eat up the not-yet received      * data or inetd will loop.      */
if|if
condition|(
name|request
operator|->
name|sink
condition|)
name|request
operator|->
name|sink
argument_list|(
name|request
operator|->
name|fd
argument_list|)
expr_stmt|;
comment|/*      * Be kind to the inetd. We already reported the problem via the syslogd,      * and there is no need for additional garbage in the logfile.      */
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

