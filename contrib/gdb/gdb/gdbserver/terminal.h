begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Terminal interface definitions for the GDB remote server.    Copyright 2002, Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
comment|/* Autoconf will have defined HAVE_TERMIOS_H, HAVE_TERMIO_H,    and HAVE_SGTTY_H for us as appropriate.  */
end_comment

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

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_TERMIOS_H */
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
comment|/* ! HAVE_TERMIO_H; default to SGTTY.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SGTTY
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TERMINAL_H) */
end_comment

end_unit

