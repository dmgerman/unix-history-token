begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* termdep.h -- System things that terminal.c depends on.    $Id: termdep.h,v 1.3 1996/10/02 22:23:52 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 96 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_TERMDEP_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_TERMDEP_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_FCNTL_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SYS_FCNTL_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_FILE_H
argument_list|)
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

begin_comment
comment|/* HAVE_SYS_FILE_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRINGS_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termios.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_TTOLD_H
argument_list|)
end_if

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRCHR
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|strchr
end_undef

begin_undef
undef|#
directive|undef
name|strrchr
end_undef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRCHR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TERMDEP_H_ */
end_comment

end_unit

