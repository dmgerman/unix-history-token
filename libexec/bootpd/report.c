begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * report() - calls syslog  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

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
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"report.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_NDELAY
end_ifndef

begin_define
define|#
directive|define
name|LOG_NDELAY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_define
define|#
directive|define
name|LOG_DAEMON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_BOOTP
end_ifndef

begin_define
define|#
directive|define
name|LOG_BOOTP
value|LOG_DAEMON
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is initialized so you get stderr until you call  *	report_init()  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|stderr_only
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|report_init
parameter_list|(
name|nolog
parameter_list|)
name|int
name|nolog
decl_stmt|;
block|{
name|stderr_only
operator|=
name|nolog
expr_stmt|;
ifdef|#
directive|ifdef
name|SYSLOG
if|if
condition|(
operator|!
name|stderr_only
condition|)
block|{
name|openlog
argument_list|(
name|progname
argument_list|,
name|LOG_PID
operator||
name|LOG_NDELAY
argument_list|,
name|LOG_BOOTP
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * This routine reports errors and such via stderr and syslog() if  * appopriate.  It just helps avoid a lot of "#ifdef SYSLOG" constructs  * from being scattered throughout the code.  *  * The syntax is identical to syslog(3), but %m is not considered special  * for output to stderr (i.e. you'll see "%m" in the output. . .).  Also,  * control strings should normally end with \n since newlines aren't  * automatically generated for stderr output (whereas syslog strips out all  * newlines and adds its own at the end).  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|levelnames
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|LOG_SALERT
literal|"level(0): "
block|,
literal|"alert(1): "
block|,
literal|"alert(2): "
block|,
literal|"emerg(3): "
block|,
literal|"error(4): "
block|,
literal|"crit(5):  "
block|,
literal|"warn(6):  "
block|,
literal|"note(7):  "
block|,
literal|"info(8):  "
block|,
literal|"debug(9): "
block|,
literal|"level(?): "
else|#
directive|else
literal|"emerg(0): "
block|,
literal|"alert(1): "
block|,
literal|"crit(2):  "
block|,
literal|"error(3): "
block|,
literal|"warn(4):  "
block|,
literal|"note(5):  "
block|,
literal|"info(6):  "
block|,
literal|"debug(7): "
block|,
literal|"level(?): "
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|numlevels
init|=
sizeof|sizeof
argument_list|(
name|levelnames
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|levelnames
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print a log message using syslog(3) and/or stderr.  * The message passed in should not include a newline.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|void
name|report
parameter_list|(
name|int
name|priority
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
comment|/*VARARGS2*/
function|void report
parameter_list|(
name|priority
parameter_list|,
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|int
name|priority
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
specifier|static
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|priority
operator|<
literal|0
operator|)
operator|||
operator|(
name|priority
operator|>=
name|numlevels
operator|)
condition|)
block|{
name|priority
operator|=
name|numlevels
operator|-
literal|1
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
comment|/* 	 * Print the message 	 */
if|if
condition|(
name|stderr_only
operator|||
operator|(
name|debug
operator|>
literal|2
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s %s\n"
argument_list|,
name|progname
argument_list|,
name|levelnames
index|[
name|priority
index|]
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|SYSLOG
if|if
condition|(
operator|!
name|stderr_only
condition|)
name|syslog
argument_list|(
operator|(
name|priority
operator||
name|LOG_BOOTP
operator|)
argument_list|,
literal|"%s"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * Return pointer to static string which gives full filesystem error message.  */
end_comment

begin_function
name|char
modifier|*
name|get_errmsg
parameter_list|()
block|{
specifier|extern
name|int
name|errno
decl_stmt|;
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
return|return
name|strerror
argument_list|(
name|errno
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Local Variables:  * tab-width: 4  * c-indent-level: 4  * c-argdecl-indent: 4  * c-continued-statement-offset: 4  * c-continued-brace-offset: -4  * c-label-offset: -4  * c-brace-offset: 0  * End:  */
end_comment

end_unit

