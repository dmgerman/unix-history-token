begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* detach.c    Detach from the controlling terminal.     Copyright (C) 1992, 1993, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
file|"system.h"
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

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_IOCTL_H
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCNOTTY
end_ifdef

begin_define
define|#
directive|define
name|HAVE_TIOCNOTTY
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_TIOCNOTTY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_FILE_H
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_BROKEN_SETSID
end_if

begin_undef
undef|#
directive|undef
name|HAVE_SETSID
end_undef

begin_define
define|#
directive|define
name|HAVE_SETSID
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Detach from the controlling terminal.  This is called by uucico if    it is calling out to another system, so that it can receive SIGHUP    signals from the port it calls out on.  It is also called by uucico    just before it starts uuxqt, so that uuxqt is completely    independent of the terminal.  */
end_comment

begin_function
name|void
name|usysdep_detach
parameter_list|()
block|{
name|pid_t
name|igrp
decl_stmt|;
comment|/* Make sure that we can open the log file.  We do this now so that,      if we can't, a message will be written to stderr.  After we leave      this routine, stderr will be closed.  */
name|ulog
argument_list|(
name|LOG_NORMAL
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
comment|/* Make sure we are not a process group leader.  */
if|#
directive|if
name|HAVE_BSD_PGRP
name|igrp
operator|=
name|getpgrp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|igrp
operator|=
name|getpgrp
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|igrp
operator|==
name|getpid
argument_list|()
condition|)
block|{
name|boolean
name|fignored
decl_stmt|;
name|pid_t
name|ipid
decl_stmt|;
comment|/* Ignore SIGHUP, since our process group leader is about to 	 die.  */
name|usset_signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|,
name|FALSE
argument_list|,
operator|&
name|fignored
argument_list|)
expr_stmt|;
name|ipid
operator|=
name|ixsfork
argument_list|()
expr_stmt|;
if|if
condition|(
name|ipid
operator|<
literal|0
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"fork: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ipid
operator|!=
literal|0
condition|)
name|_exit
argument_list|(
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
comment|/* We'll always wind up as a child of process number 1, right? 	 Right?  We have to wait for our parent to die before 	 reenabling SIGHUP.  */
while|while
condition|(
name|getppid
argument_list|()
operator|!=
literal|1
condition|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|ipid
operator|=
name|getpid
argument_list|()
expr_stmt|;
name|ulog_id
argument_list|(
name|ipid
argument_list|)
expr_stmt|;
comment|/* Restore SIGHUP catcher if it wasn't being ignored.  */
if|if
condition|(
operator|!
name|fignored
condition|)
name|usset_signal
argument_list|(
name|SIGHUP
argument_list|,
name|ussignal
argument_list|,
name|TRUE
argument_list|,
operator|(
name|boolean
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|DEBUG_MESSAGE2
argument_list|(
name|DEBUG_PORT
argument_list|,
literal|"usysdep_detach: Forked; old PID %ld, new pid %ld"
argument_list|,
operator|(
name|long
operator|)
name|igrp
argument_list|,
operator|(
name|long
operator|)
name|ipid
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|HAVE_SETSID
operator|&&
name|HAVE_TIOCNOTTY
comment|/* Lose the original controlling terminal as well as our process      group.  */
block|{
name|int
name|o
decl_stmt|;
name|o
operator|=
name|open
argument_list|(
operator|(
name|char
operator|*
operator|)
name|_PATH_TTY
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|o
operator|>=
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|o
argument_list|,
name|TIOCNOTTY
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|o
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* ! HAVE_SETSID&& HAVE_TIOCNOTTY */
comment|/* Close stdin, stdout and stderr and reopen them on /dev/null, to      make sure we have no connection at all to the terminal.  */
operator|(
name|void
operator|)
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|open
argument_list|(
operator|(
name|char
operator|*
operator|)
name|_PATH_DEVNULL
argument_list|,
name|O_RDONLY
argument_list|)
operator|!=
literal|0
operator|||
name|open
argument_list|(
operator|(
name|char
operator|*
operator|)
name|_PATH_DEVNULL
argument_list|,
name|O_WRONLY
argument_list|)
operator|!=
literal|1
operator|||
name|open
argument_list|(
operator|(
name|char
operator|*
operator|)
name|_PATH_DEVNULL
argument_list|,
name|O_WRONLY
argument_list|)
operator|!=
literal|2
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"open (%s): %s"
argument_list|,
name|_PATH_DEVNULL
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|HAVE_SETSID
comment|/* Under POSIX the setsid call creates a new session for which we      are the process group leader.  It also detaches us from our      controlling terminal.  */
if|if
condition|(
name|setsid
argument_list|()
operator|<
literal|0
condition|)
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"setsid: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ! HAVE_SETSID */
if|#
directive|if
operator|!
name|HAVE_SETPGRP
error|#
directive|error
error|Cannot detach from controlling terminal
endif|#
directive|endif
comment|/* If we don't have setsid, we must use setpgrp.  On an old System V      system setpgrp will make us the leader of a new process group and      detach the controlling terminal.  On an old BSD system the call      setpgrp (0, 0) will set our process group to 0 so that we can      acquire a new controlling terminal (TIOCNOTTY may or may not have      already done that anyhow).  */
if|#
directive|if
name|HAVE_BSD_PGRP
if|if
condition|(
name|setpgrp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
else|#
directive|else
if|if
condition|(
name|setpgrp
argument_list|()
operator|<
literal|0
condition|)
endif|#
directive|endif
block|{
comment|/* Some systems seem to give EPERM errors inappropriately.  */
if|if
condition|(
name|errno
operator|!=
name|EPERM
condition|)
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"setpgrp: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* ! HAVE_SETSID */
comment|/* At this point we have completely detached from our controlling      terminal.  The next terminal device we open will probably become      our controlling terminal.  */
block|}
end_function

end_unit

