begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * shell_cmd() takes a shell command after %<character> substitutions. The   * command is executed by a /bin/sh child process, with standard input,   * standard output and standard error connected to /dev/null.   *    * Diagnostics are reported through syslog(3).   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
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
literal|"@(#) shell_cmd.c 1.5 94/12/28 17:42:44"
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
file|<signal.h>
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

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

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
name|do_child
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* shell_cmd - execute shell command */
end_comment

begin_function
name|void
name|shell_cmd
parameter_list|(
name|command
parameter_list|)
name|char
modifier|*
name|command
decl_stmt|;
block|{
name|int
name|child_pid
decl_stmt|;
name|int
name|wait_pid
decl_stmt|;
comment|/*      * Most of the work is done within the child process, to minimize the      * risk of damage to the parent.      */
switch|switch
condition|(
name|child_pid
operator|=
name|fork
argument_list|()
condition|)
block|{
case|case
operator|-
literal|1
case|:
comment|/* error */
name|tcpd_warn
argument_list|(
literal|"cannot fork: %m"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|00
case|:
comment|/* child */
name|do_child
argument_list|(
name|command
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
default|default:
comment|/* parent */
while|while
condition|(
operator|(
name|wait_pid
operator|=
name|wait
argument_list|(
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
operator|)
operator|!=
operator|-
literal|1
operator|&&
name|wait_pid
operator|!=
name|child_pid
condition|)
comment|/* void */
empty_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* do_child - exec command with { stdin, stdout, stderr } to /dev/null */
end_comment

begin_function
specifier|static
name|void
name|do_child
parameter_list|(
name|command
parameter_list|)
name|char
modifier|*
name|command
decl_stmt|;
block|{
name|char
modifier|*
name|error
decl_stmt|;
name|int
name|tmp_fd
decl_stmt|;
comment|/*      * Systems with POSIX sessions may send a SIGHUP to grandchildren if the      * child exits first. This is sick, sessions were invented for terminals.      */
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Set up new stdin, stdout, stderr, and exec the shell command. */
for|for
control|(
name|tmp_fd
operator|=
literal|0
init|;
name|tmp_fd
operator|<
literal|3
condition|;
name|tmp_fd
operator|++
control|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|tmp_fd
argument_list|)
expr_stmt|;
if|if
condition|(
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
literal|2
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|error
operator|=
literal|"open /dev/null: %m"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dup
argument_list|(
literal|0
argument_list|)
operator|!=
literal|1
operator|||
name|dup
argument_list|(
literal|0
argument_list|)
operator|!=
literal|2
condition|)
block|{
name|error
operator|=
literal|"dup: %m"
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|execl
argument_list|(
literal|"/bin/sh"
argument_list|,
literal|"sh"
argument_list|,
literal|"-c"
argument_list|,
name|command
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|error
operator|=
literal|"execl /bin/sh: %m"
expr_stmt|;
block|}
comment|/* Something went wrong. We MUST terminate the child process. */
name|tcpd_warn
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

