begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * hosts_ctl() combines common applications of the host access control   * library routines. It bundles its arguments then calls the hosts_access()   * access control checker. The host name and user name arguments should be   * empty strings, STRING_UNKNOWN or real data. If a match is found, the   * optional shell command is executed.   *    * Restriction: this interface does not pass enough information to support   * selective remote username lookups or selective hostname double checks.   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
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
literal|"@(#) hosts_ctl.c 1.4 94/12/28 17:42:27"
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

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_comment
comment|/* hosts_ctl - limited interface to the hosts_access() routine */
end_comment

begin_function
name|int
name|hosts_ctl
parameter_list|(
name|daemon
parameter_list|,
name|name
parameter_list|,
name|addr
parameter_list|,
name|user
parameter_list|)
name|char
modifier|*
name|daemon
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|addr
decl_stmt|;
name|char
modifier|*
name|user
decl_stmt|;
block|{
name|struct
name|request_info
name|request
decl_stmt|;
return|return
operator|(
name|hosts_access
argument_list|(
name|request_init
argument_list|(
operator|&
name|request
argument_list|,
name|RQ_DAEMON
argument_list|,
name|daemon
argument_list|,
name|RQ_CLIENT_NAME
argument_list|,
name|name
argument_list|,
name|RQ_CLIENT_ADDR
argument_list|,
name|addr
argument_list|,
name|RQ_USER
argument_list|,
name|user
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

