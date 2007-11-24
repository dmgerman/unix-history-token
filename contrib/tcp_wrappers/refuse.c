begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * refuse() reports a refused connection, and takes the consequences: in   * case of a datagram-oriented service, the unread datagram is taken from   * the input queue (or inetd would see the same datagram again and again);   * the program is terminated.   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   *   * $FreeBSD$   */
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
literal|"@(#) refuse.c 1.5 94/12/28 17:42:39"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System libraries. */
end_comment

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
comment|/* refuse - refuse request */
end_comment

begin_function
name|void
name|refuse
parameter_list|(
name|request
parameter_list|)
name|struct
name|request_info
modifier|*
name|request
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|INET6
name|syslog
argument_list|(
name|deny_severity
argument_list|,
literal|"refused connect from %s (%s)"
argument_list|,
name|eval_client
argument_list|(
name|request
argument_list|)
argument_list|,
name|eval_hostaddr
argument_list|(
name|request
operator|->
name|client
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|syslog
argument_list|(
name|deny_severity
argument_list|,
literal|"refused connect from %s"
argument_list|,
name|eval_client
argument_list|(
name|request
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|clean_exit
argument_list|(
name|request
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit

