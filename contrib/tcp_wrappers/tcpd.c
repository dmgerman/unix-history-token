begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * General front end for stream and datagram IP services. This program logs   * the remote host name and then invokes the real daemon. For example,   * install as /usr/etc/{tftpd,fingerd,telnetd,ftpd,rlogind,rshd,rexecd},   * after saving the real daemons in the directory specified with the   * REAL_DAEMON_DIR macro. This arrangement requires that the network daemons   * are started by inetd or something similar. Connections and diagnostics   * are logged through syslog(3).   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   *   * $FreeBSD$   */
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
literal|"@(#) tcpd.c 1.10 96/02/11 17:01:32"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
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

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHNAMELEN
value|BUFSIZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Local stuff. */
end_comment

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_decl_stmt
name|int
name|allow_severity
init|=
name|SEVERITY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* run-time adjustable */
end_comment

begin_decl_stmt
name|int
name|deny_severity
init|=
name|LOG_WARNING
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ditto */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|struct
name|request_info
name|request
decl_stmt|;
name|char
name|path
index|[
name|MAXPATHNAMELEN
index|]
decl_stmt|;
comment|/* Attempt to prevent the creation of world-writable files. */
ifdef|#
directive|ifdef
name|DAEMON_UMASK
name|umask
argument_list|(
name|DAEMON_UMASK
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*      * If argv[0] is an absolute path name, ignore REAL_DAEMON_DIR, and strip      * argv[0] to its basename.      */
if|if
condition|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|==
literal|'/'
condition|)
block|{
name|strcpy
argument_list|(
name|path
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|argv
index|[
literal|0
index|]
operator|=
name|strrchr
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'/'
argument_list|)
operator|+
literal|1
expr_stmt|;
block|}
else|else
block|{
name|sprintf
argument_list|(
name|path
argument_list|,
literal|"%s/%s"
argument_list|,
name|REAL_DAEMON_DIR
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
comment|/*      * Open a channel to the syslog daemon. Older versions of openlog()      * require only two arguments.      */
ifdef|#
directive|ifdef
name|LOG_MAIL
operator|(
name|void
operator|)
name|openlog
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
name|LOG_PID
argument_list|,
name|FACILITY
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|openlog
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
name|LOG_PID
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*      * Find out the endpoint addresses of this conversation. Host name      * lookups and double checks will be done on demand.      */
name|request_init
argument_list|(
operator|&
name|request
argument_list|,
name|RQ_DAEMON
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|RQ_FILE
argument_list|,
name|STDIN_FILENO
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fromhost
argument_list|(
operator|&
name|request
argument_list|)
expr_stmt|;
comment|/*      * Optionally look up and double check the remote host name. Sites      * concerned with security may choose to refuse connections from hosts      * that pretend to have someone elses host name.      */
ifdef|#
directive|ifdef
name|PARANOID
if|if
condition|(
name|STR_EQ
argument_list|(
name|eval_hostname
argument_list|(
name|request
operator|.
name|client
argument_list|)
argument_list|,
name|paranoid
argument_list|)
condition|)
name|refuse
argument_list|(
operator|&
name|request
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*      * The BSD rlogin and rsh daemons that came out after 4.3 BSD disallow      * socket options at the IP level. They do so for a good reason.      * Unfortunately, we cannot use this with SunOS 4.1.x because the      * getsockopt() system call can panic the system.      */
ifdef|#
directive|ifdef
name|KILL_IP_OPTIONS
name|fix_options
argument_list|(
operator|&
name|request
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*      * Check whether this host can access the service in argv[0]. The      * access-control code invokes optional shell commands as specified in      * the access-control tables.      */
ifdef|#
directive|ifdef
name|HOSTS_ACCESS
if|if
condition|(
operator|!
name|hosts_access
argument_list|(
operator|&
name|request
argument_list|)
condition|)
name|refuse
argument_list|(
operator|&
name|request
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Report request and invoke the real daemon program. */
ifdef|#
directive|ifdef
name|INET6
name|syslog
argument_list|(
name|allow_severity
argument_list|,
literal|"connect from %s (%s)"
argument_list|,
name|eval_client
argument_list|(
operator|&
name|request
argument_list|)
argument_list|,
name|eval_hostaddr
argument_list|(
name|request
operator|.
name|client
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|syslog
argument_list|(
name|allow_severity
argument_list|,
literal|"connect from %s"
argument_list|,
name|eval_client
argument_list|(
operator|&
name|request
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|closelog
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|execv
argument_list|(
name|path
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"error: cannot execute %s: %m"
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|clean_exit
argument_list|(
operator|&
name|request
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit

