begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* termdep.h -- System things that terminal.c depends on.    $Id: termdep.h,v 1.4 1998/04/13 22:02:57 karl Exp $     Copyright (C) 1993, 96, 97, 98 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_TERMDEP_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_TERMDEP_H
end_define

begin_comment
comment|/* NeXT supplies<termios.h> but it is broken.  Probably Autoconf should    have a separate test, but anyway ... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_TERMIOS_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|GWINSZ_IN_SYS_IOCTL
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIO_H
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
name|defined
argument_list|(
name|HAVE_SYS_PTEM_H
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|M_UNIX
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|M_XENIX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptem.h>
end_include

begin_undef
undef|#
directive|undef
name|TIOCGETC
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* M_XENIX */
end_comment

begin_define
define|#
directive|define
name|tchars
value|tc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_XENIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PTEM_H */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_TERMIO_H */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_TERMIO_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_TERMIOS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TTOLD_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ttold.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TTOLD_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_TERMDEP_H */
end_comment

end_unit

