begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Routines to report various classes of problems. Each report is decorated   * with the current context (file name and line number), if available.   *    * tcpd_warn() reports a problem and proceeds.   *    * tcpd_jump() reports a problem and jumps.   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
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
literal|"@(#) diag.c 1.1 94/12/28 17:42:20"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System libraries */
end_comment

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* Local stuff */
end_comment

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_include
include|#
directive|include
file|"mystdarg.h"
end_include

begin_decl_stmt
name|struct
name|tcpd_context
name|tcpd_context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|tcpd_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tcpd_diag - centralize error reporter */
end_comment

begin_function
specifier|static
name|void
name|tcpd_diag
parameter_list|(
name|severity
parameter_list|,
name|tag
parameter_list|,
name|format
parameter_list|,
name|ap
parameter_list|)
name|int
name|severity
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
name|char
modifier|*
name|format
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
name|char
name|fmt
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
name|tcpd_context
operator|.
name|file
condition|)
name|sprintf
argument_list|(
name|fmt
argument_list|,
literal|"%s: %s, line %d: %s"
argument_list|,
name|tag
argument_list|,
name|tcpd_context
operator|.
name|file
argument_list|,
name|tcpd_context
operator|.
name|line
argument_list|,
name|format
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|fmt
argument_list|,
literal|"%s: %s"
argument_list|,
name|tag
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|vsyslog
argument_list|(
name|severity
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* tcpd_warn - report problem of some sort and proceed */
end_comment

begin_function
name|void
name|VARARGS
parameter_list|(
name|tcpd_warn
parameter_list|,
name|char
modifier|*
parameter_list|,
name|format
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|VASTART
argument_list|(
name|ap
argument_list|,
name|char
operator|*
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|tcpd_diag
argument_list|(
name|LOG_ERR
argument_list|,
literal|"warning"
argument_list|,
name|format
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|VAEND
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* tcpd_jump - report serious problem and jump */
end_comment

begin_function
name|void
name|VARARGS
parameter_list|(
name|tcpd_jump
parameter_list|,
name|char
modifier|*
parameter_list|,
name|format
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|VASTART
argument_list|(
name|ap
argument_list|,
name|char
operator|*
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|tcpd_diag
argument_list|(
name|LOG_ERR
argument_list|,
literal|"error"
argument_list|,
name|format
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|VAEND
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|longjmp
argument_list|(
name|tcpd_buf
argument_list|,
name|AC_ERROR
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

