begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unixproc.c -     Unix implementation of run_process().       Written by James Clark (jjc@jclark.com). */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUBDOC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_include
include|#
directive|include
file|"entity.h"
end_include

begin_include
include|#
directive|include
file|"appl.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX
end_ifndef

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0377) == 0177)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0377) != 0&& ((s)& 0377 != 0177))
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0377) == 0)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 8)& 0377)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|s
parameter_list|)
value|((s)& 0177)
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 8)& 0377)
end_define

begin_define
define|#
directive|define
name|_SC_OPEN_MAX
value|0
end_define

begin_define
define|#
directive|define
name|sysconf
parameter_list|(
name|name
parameter_list|)
value|(20)
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not POSIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VFORK
end_ifndef

begin_define
define|#
directive|define
name|vfork
parameter_list|()
value|fork()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_VFORK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_VFORK_H
end_ifdef

begin_include
include|#
directive|include
file|<vfork.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_VFORK_H */
end_comment

begin_function
name|int
name|run_process
parameter_list|(
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|pid_t
name|pid
decl_stmt|;
name|int
name|status
decl_stmt|;
name|int
name|ret
decl_stmt|;
comment|/* Can't trust Unix implementations to support fflush(NULL). */
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|pid
operator|=
name|vfork
argument_list|()
expr_stmt|;
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
block|{
comment|/* child */
name|int
name|i
decl_stmt|;
name|int
name|open_max
init|=
operator|(
name|int
operator|)
name|sysconf
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|3
init|;
name|i
operator|<
name|open_max
condition|;
name|i
operator|++
control|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|execvp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|appl_error
argument_list|(
name|E_EXEC
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|127
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pid
operator|<
literal|0
condition|)
block|{
name|appl_error
argument_list|(
name|E_FORK
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/* parent */
while|while
condition|(
operator|(
name|ret
operator|=
name|wait
argument_list|(
operator|&
name|status
argument_list|)
operator|)
operator|!=
name|pid
condition|)
if|if
condition|(
name|ret
operator|<
literal|0
condition|)
block|{
name|appl_error
argument_list|(
name|E_WAIT
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|WIFSIGNALED
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|appl_error
argument_list|(
name|E_SIGNAL
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|WTERMSIG
argument_list|(
name|status
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/* Must have exited normally. */
return|return
name|WEXITSTATUS
argument_list|(
name|status
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUPPORT_SUBDOC */
end_comment

begin_comment
comment|/* Local Variables: c-indent-level: 5 c-continued-statement-offset: 5 c-brace-offset: -5 c-argdecl-indent: 0 c-label-offset: -5 End: */
end_comment

end_unit

