begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rltty.h - tty driver-related definitions used by some library files. */
end_comment

begin_comment
comment|/* Copyright (C) 1995 Free Software Foundation, Inc.     This file contains the Readline Library (the Library), a set of    routines for providing Emacs style line input to programs that ask    for it.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RLTTY_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RLTTY_H_
end_define

begin_comment
comment|/* Posix systems use termios and the Posix signal functions. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TERMIOS_TTY_DRIVER
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

begin_comment
comment|/* TERMIOS_TTY_DRIVER */
end_comment

begin_comment
comment|/* System V machines use termio. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TERMIO_TTY_DRIVER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TCOON
argument_list|)
end_if

begin_define
define|#
directive|define
name|TCOON
value|1
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
comment|/* TERMIO_TTY_DRIVER */
end_comment

begin_comment
comment|/* Other (BSD) machines use sgtty. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NEW_TTY_DRIVER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"rlwinsize.h"
end_include

begin_comment
comment|/* Define _POSIX_VDISABLE if we are not using the `new' tty driver and    it is not already defined.  It is used both to determine if a    special character is disabled and to disable certain special    characters.  Posix systems should set to 0, USG systems to -1. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NEW_TTY_DRIVER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_VDISABLE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SVR4_VDISABLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|_SVR4_VDISABLE
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_POSIX_VERSION */
end_comment

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_VERSION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_DISABLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NEW_TTY_DRIVER&& !_POSIX_VDISABLE */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_rl_tty_chars
block|{
name|char
name|t_eof
decl_stmt|;
name|char
name|t_eol
decl_stmt|;
name|char
name|t_eol2
decl_stmt|;
name|char
name|t_erase
decl_stmt|;
name|char
name|t_werase
decl_stmt|;
name|char
name|t_kill
decl_stmt|;
name|char
name|t_reprint
decl_stmt|;
name|char
name|t_intr
decl_stmt|;
name|char
name|t_quit
decl_stmt|;
name|char
name|t_susp
decl_stmt|;
name|char
name|t_dsusp
decl_stmt|;
name|char
name|t_start
decl_stmt|;
name|char
name|t_stop
decl_stmt|;
name|char
name|t_lnext
decl_stmt|;
name|char
name|t_flush
decl_stmt|;
name|char
name|t_status
decl_stmt|;
block|}
name|_RL_TTY_CHARS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RLTTY_H_ */
end_comment

end_unit

