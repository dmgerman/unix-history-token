begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions file for GNU Emacs running on AT&T's System V Release 4    Copyright (C) 1987, 1990 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This file written by James Van Artsdalen of Dell Computer Corporation.  * james@bigtex.cactus.org.  */
end_comment

begin_comment
comment|/* Use the SysVr3 file for at least base configuration. */
end_comment

begin_include
include|#
directive|include
file|"s-usg5-3.h"
end_include

begin_comment
comment|/* We do have multiple jobs.  Handle ^Z. */
end_comment

begin_undef
undef|#
directive|undef
name|NOMULTIPLEJOBS
end_undef

begin_comment
comment|/* If compiled by GNU C, we must have gnulib */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|GNULIB
value|/usr/local/lib/gcc-gnulib
end_define

begin_define
define|#
directive|define
name|LIBS_DEBUG
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GNULIB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|START_FILES
value|pre-crt0.o /usr/ccs/lib/crt1.o /usr/ccs/lib/crti.o /usr/ccs/lib/values-Xt.o
end_define

begin_define
define|#
directive|define
name|LIB_STANDARD
value|GNULIB -lsocket -lnsl -lelf -lc /usr/ucblib/libucb.a /usr/ccs/lib/crtn.o
end_define

begin_define
define|#
directive|define
name|DATA_SEG_BITS
value|0x08000000
end_define

begin_comment
comment|/* No<sioctl.h> */
end_comment

begin_define
define|#
directive|define
name|NO_SIOCTL_H
end_define

begin_comment
comment|/* Undump with ELF */
end_comment

begin_undef
undef|#
directive|undef
name|COFF
end_undef

begin_define
define|#
directive|define
name|UNEXEC
value|unexelf.o
end_define

begin_comment
comment|/* Get FIONREAD from<sys/filio.h>.  Get<sys/ttold.h> to get struct  * tchars. But get<termio.h> first to make sure ttold.h doesn't  * interfere.  And don't try to use SIGIO yet.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|emacs
end_ifdef

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttold.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_undef
undef|#
directive|undef
name|SIGIO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* libc has this stuff, but not utimes. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RENAME
end_define

begin_define
define|#
directive|define
name|HAVE_SELECT
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
end_define

begin_define
define|#
directive|define
name|HAVE_CLOSEDIR
end_define

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
end_define

begin_define
define|#
directive|define
name|HAVE_DUP2
end_define

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_comment
comment|/*<sys/stat.h> *defines* stat(2) as a static function.  If "static"  * is blank, then many files will have a public definition for stat(2).  */
end_comment

begin_undef
undef|#
directive|undef
name|static
end_undef

begin_comment
comment|/* We need bss_end from emacs.c for undumping */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USG_SHARED_LIBRARIES
end_ifndef

begin_define
define|#
directive|define
name|USG_SHARED_LIBRARIES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We can support this */
end_comment

begin_define
define|#
directive|define
name|CLASH_DETECTION
end_define

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_TYPE
value|long
end_define

begin_comment
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_comment
comment|/* This is totally uncalibrated. */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_CVT
parameter_list|(
name|x
parameter_list|)
value|((int) ((double) (x)) * 100.0 / FSCALE)
end_define

begin_define
define|#
directive|define
name|FSCALE
value|256.0
end_define

begin_define
define|#
directive|define
name|HAVE_PTYS
end_define

begin_define
define|#
directive|define
name|HAVE_SETSID
end_define

begin_comment
comment|/* It is possible to receive SIGCHLD when there are no children    waiting, because a previous waitsys(2) cleaned up the carcass of child    without clearing the SIGCHLD pending info.  So, use a non-blocking    wait3 instead, which maps to waitpid(2) in SysVr4. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT_HEADER
end_define

begin_define
define|#
directive|define
name|WAITTYPE
value|int
end_define

begin_define
define|#
directive|define
name|wait3
parameter_list|(
name|status
parameter_list|,
name|options
parameter_list|,
name|rusage
parameter_list|)
define|\
value|waitpid((pid_t) -1, (status), (options))
end_define

begin_define
define|#
directive|define
name|WRETCODE
parameter_list|(
name|w
parameter_list|)
value|(w>> 8)
end_define

begin_comment
comment|/* TIOCGPGRP is broken in SysVr4, so we can't send signals to PTY    subprocesses the usual way.  But TIOCSIGNAL does work for PTYs, and    this is all we need.  */
end_comment

begin_define
define|#
directive|define
name|TIOCSIGSEND
value|TIOCSIGNAL
end_define

begin_comment
comment|/* This change means that we don't loop through allocate_pty too many    times in the (rare) event of a failure. */
end_comment

begin_undef
undef|#
directive|undef
name|FIRST_PTY_LETTER
end_undef

begin_define
define|#
directive|define
name|FIRST_PTY_LETTER
value|'z'
end_define

begin_comment
comment|/* This sets the name of the master side of the PTY. */
end_comment

begin_define
define|#
directive|define
name|PTY_NAME_SPRINTF
value|strcpy (pty_name, "/dev/ptmx");
end_define

begin_comment
comment|/* This sets the name of the slave side of the PTY.  On SysVr4,    grantpt(3) forks a subprocess, so keep sigchld_handler() from    intercepting that death.  If any child but grantpt's should die    within, it should be caught after sigrelse(2). */
end_comment

begin_define
define|#
directive|define
name|PTY_TTY_NAME_SPRINTF
define|\
value|{						\     char *ptsname(), *ptyname;			\ 						\     sighold(SIGCLD);				\     if (grantpt(fd) == -1)			\       fatal("could not grant slave pty");	\     sigrelse(SIGCLD);				\     if (unlockpt(fd) == -1)			\       fatal("could not unlock slave pty");	\     if (!(ptyname = ptsname(fd)))		\       fatal ("could not enable slave pty");	\     strncpy(pty_name, ptyname, sizeof(pty_name)); \     pty_name[sizeof(pty_name) - 1] = 0;		\   }
end_define

begin_comment
comment|/* Push various streams modules onto a PTY channel. */
end_comment

begin_define
define|#
directive|define
name|SETUP_SLAVE_PTY
define|\
value|if (ioctl (xforkin, I_PUSH, "ptem") == -1)	\     fatal ("ioctl I_PUSH ptem", errno);		\   if (ioctl (xforkin, I_PUSH, "ldterm") == -1)	\     fatal ("ioctl I_PUSH ldterm", errno);	\   if (ioctl (xforkin, I_PUSH, "ttcompat") == -1) \     fatal ("ioctl I_PUSH ttcompat", errno);
end_define

end_unit

