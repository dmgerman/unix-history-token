begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Terminal interface definitions for GDB, the GNU Debugger.    Copyright 1986, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GO32__
argument_list|)
end_if

begin_comment
comment|/* Define a common set of macros -- BSD based -- and redefine whatever    the system offers to make it look like that.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|NO_JOB_CONTROL
end_ifdef

begin_undef
undef|#
directive|undef
name|TIOCGPGRP
end_undef

begin_undef
undef|#
directive|undef
name|TIOCGPGRP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no termio */
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
comment|/* no termio */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not go32 */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TERMINAL_H) */
end_comment

end_unit

