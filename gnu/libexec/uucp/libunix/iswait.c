begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* iswait.c    Wait for a process to finish.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"uudefs.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_WAIT_H
end_if

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
comment|/* We use a typedef wait_status for wait (waitpid, wait4) to put    results into.  We define the POSIX examination functions we need if    they are not already defined (if they aren't defined, I assume that    we have a standard wait status).  */
end_comment

begin_if
if|#
directive|if
name|HAVE_UNION_WAIT
end_if

begin_typedef
typedef|typedef
name|union
name|wait
name|wait_status
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|u
parameter_list|)
value|((u).w_termsig == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|u
parameter_list|)
value|((u).w_retcode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|u
parameter_list|)
value|((u).w_termsig)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_UNION_WAIT */
end_comment

begin_typedef
typedef|typedef
name|int
name|wait_status
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|i
parameter_list|)
value|(((i)& 0xff) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 8)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x7f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_UNION_WAIT */
end_comment

begin_comment
comment|/* Wait for a particular process to finish.  The ipid argument should    be pid_t, but then we couldn't have a prototype.  If the zreport    argument is not NULL, then a wait error will be logged, and if the    exit status is non-zero it will be logged with zreport as the    header of the log message.  If the zreport argument is NULL, no    errors will be logged.  This function returns the exit status if    the process exited normally, or -1 on error or if the process was    killed by a signal (I don't just always return the exit status    because then the calling code would have to prepared to handle    union wait status vs. int status, and none of the callers care    which signal killed the program anyhow).     This functions keeps waiting until the process finished, even if it    is interrupted by a signal.  I think this is right for all uses.    The controversial one would be when called from uuxqt to wait for a    requested process.  Hitting uuxqt with SIGKILL will approximate the    actions taken if we return from here with an error anyhow.  If we    do get a signal, we call ulog with a NULL argument to get it in the    log file at about the right time.  */
end_comment

begin_function
name|int
name|ixswait
parameter_list|(
name|ipid
parameter_list|,
name|zreport
parameter_list|)
name|unsigned
name|long
name|ipid
decl_stmt|;
specifier|const
name|char
modifier|*
name|zreport
decl_stmt|;
block|{
name|wait_status
name|istat
decl_stmt|;
if|#
directive|if
name|HAVE_WAITPID
while|while
condition|(
name|waitpid
argument_list|(
operator|(
name|pid_t
operator|)
name|ipid
argument_list|,
operator|(
name|pointer
operator|)
operator|&
name|istat
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EINTR
condition|)
block|{
if|if
condition|(
name|zreport
operator|!=
name|NULL
condition|)
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"waitpid: %s"
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
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* ! HAVE_WAITPID */
if|#
directive|if
name|HAVE_WAIT4
while|while
condition|(
name|wait4
argument_list|(
operator|(
name|pid_t
operator|)
name|ipid
argument_list|,
operator|(
name|pointer
operator|)
operator|&
name|istat
argument_list|,
literal|0
argument_list|,
operator|(
expr|struct
name|rusage
operator|*
operator|)
name|NULL
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EINTR
condition|)
block|{
if|if
condition|(
name|zreport
operator|!=
name|NULL
condition|)
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"wait4: %s"
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
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* ! HAVE_WAIT4 */
name|pid_t
name|igot
decl_stmt|;
comment|/* We could theoretically get the wrong child here if we're in some      kind of weird pipeline, so we don't give any error messages for      it.  */
while|while
condition|(
operator|(
name|igot
operator|=
name|wait
argument_list|(
operator|(
name|pointer
operator|)
operator|&
name|istat
argument_list|)
operator|)
operator|!=
operator|(
name|pid_t
operator|)
name|ipid
condition|)
block|{
if|if
condition|(
name|igot
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EINTR
condition|)
block|{
if|if
condition|(
name|zreport
operator|!=
name|NULL
condition|)
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"wait: %s"
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
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* ! HAVE_WAIT4 */
endif|#
directive|endif
comment|/* ! HAVE_WAITPID */
name|DEBUG_MESSAGE2
argument_list|(
name|DEBUG_EXECUTE
argument_list|,
literal|"%s %d"
argument_list|,
name|WIFEXITED
argument_list|(
name|istat
argument_list|)
condition|?
literal|"Exit status"
else|:
literal|"Signal"
argument_list|,
name|WIFEXITED
argument_list|(
name|istat
argument_list|)
condition|?
name|WEXITSTATUS
argument_list|(
name|istat
argument_list|)
else|:
name|WTERMSIG
argument_list|(
name|istat
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|WIFEXITED
argument_list|(
name|istat
argument_list|)
operator|&&
name|WEXITSTATUS
argument_list|(
name|istat
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|zreport
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|!
name|WIFEXITED
argument_list|(
name|istat
argument_list|)
condition|)
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"%s: Got signal %d"
argument_list|,
name|zreport
argument_list|,
name|WTERMSIG
argument_list|(
name|istat
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"%s: Exit status %d"
argument_list|,
name|zreport
argument_list|,
name|WEXITSTATUS
argument_list|(
name|istat
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|WIFEXITED
argument_list|(
name|istat
argument_list|)
condition|)
return|return
name|WEXITSTATUS
argument_list|(
name|istat
argument_list|)
return|;
else|else
return|return
operator|-
literal|1
return|;
block|}
end_function

end_unit

