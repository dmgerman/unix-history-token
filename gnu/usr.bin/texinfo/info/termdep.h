begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* termdep.h -- System things that terminal.c depends on. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

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
name|HAVE_TERMIO_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_TERMIO_H */
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
name|HAVE_RINDEX
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|index
end_undef

begin_undef
undef|#
directive|undef
name|rindex
end_undef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

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
name|HAVE_BCOPY
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|source
parameter_list|,
name|dest
parameter_list|,
name|count
parameter_list|)
value|memcpy(dest, source, count)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* eof */
end_comment

end_unit

