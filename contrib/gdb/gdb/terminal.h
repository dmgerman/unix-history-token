begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Terminal interface definitions for GDB, the GNU Debugger.    Copyright 1986, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TERMINAL_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|TERMINAL_H
value|1
end_define

begin_comment
comment|/* If we're using autoconf, it will define HAVE_TERMIOS_H,    HAVE_TERMIO_H and HAVE_SGTTY_H for us. One day we can rewrite    ser-unix.c and inflow.c to inspect those names instead of    HAVE_TERMIOS, HAVE_TERMIO and the implicit HAVE_SGTTY (when neither    HAVE_TERMIOS or HAVE_TERMIO is set).  Until then, make sure that    nothing has already defined the one of the names, and do the right    thing. */
end_comment

begin_comment
comment|/* nothing works with go32, and the headers aren't complete */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GO32__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TERMIO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SGTTY
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (HAVE_TERMIOS_H) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIO_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (HAVE_TERMIO_H) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SGTTY_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SGTTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (HAVE_SGTTY_H) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (HAVE_TERMIO_H) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (HAVE_TERMIOS_H) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (HAVE_TERMIOS)&& !defined(HAVE_TERMIO)&& !defined(HAVE_SGTTY) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__GO32__) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GO32__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
end_if

begin_comment
comment|/* Define a common set of macros -- BSD based -- and redefine whatever    the system offers to make it look like that.  FIXME: serial.h and    ser-*.c deal with this in a much cleaner fashion; as soon as stuff    is converted to use them, can get rid of this crap.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_undef
undef|#
directive|undef
name|TIOCGETP
end_undef

begin_define
define|#
directive|define
name|TIOCGETP
value|TCGETA
end_define

begin_undef
undef|#
directive|undef
name|TIOCSETN
end_undef

begin_define
define|#
directive|define
name|TIOCSETN
value|TCSETA
end_define

begin_undef
undef|#
directive|undef
name|TIOCSETP
end_undef

begin_define
define|#
directive|define
name|TIOCSETP
value|TCSETAF
end_define

begin_define
define|#
directive|define
name|TERMINAL
value|struct termio
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sgtty */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|TERMINAL
value|struct sgttyb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgtty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|new_tty
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do we have job control?  Can be assumed to always be the same within    a given run of GDB.  In inflow.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|job_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the process group of the caller to its own pid, or do nothing if    we lack job control.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gdb_setpgid
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TERMINAL_H) */
end_comment

end_unit

