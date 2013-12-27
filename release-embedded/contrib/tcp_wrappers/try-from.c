begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * This program can be called via a remote shell command to find out if the   * hostname and address are properly recognized, if username lookup works,   * and (SysV only) if the TLI on top of IP heuristics work.   *    * Example: "rsh host /some/where/try-from".   *    * Diagnostics are reported through syslog(3) and redirected to stderr.   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
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
literal|"@(#) try-from.c 1.2 94/12/28 17:42:55"
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

begin_ifdef
ifdef|#
directive|ifdef
name|TLI
end_ifdef

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
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
comment|/*      * Simplify the process name, just like tcpd would.      */
if|if
condition|(
operator|(
name|cp
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
operator|)
operator|!=
literal|0
condition|)
name|argv
index|[
literal|0
index|]
operator|=
name|cp
operator|+
literal|1
expr_stmt|;
comment|/*      * Turn on the "IP-underneath-TLI" detection heuristics.      */
ifdef|#
directive|ifdef
name|TLI
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|I_FIND
argument_list|,
literal|"timod"
argument_list|)
operator|==
literal|0
condition|)
name|ioctl
argument_list|(
literal|0
argument_list|,
name|I_PUSH
argument_list|,
literal|"timod"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TLI */
comment|/*      * Look up the endpoint information.      */
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
operator|(
name|void
operator|)
name|fromhost
argument_list|(
operator|&
name|request
argument_list|)
expr_stmt|;
comment|/*      * Show some results. Name and address information is looked up when we      * ask for it.      */
define|#
directive|define
name|EXPAND
parameter_list|(
name|str
parameter_list|)
value|percent_x(buf, sizeof(buf), str,&request)
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"client address  (%%a): %a"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"client hostname (%%n): %n"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"client username (%%u): %u"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"client info     (%%c): %c"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"server address  (%%A): %A"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"server hostname (%%N): %N"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"server process  (%%d): %d"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|EXPAND
argument_list|(
literal|"server info     (%%s): %s"
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

