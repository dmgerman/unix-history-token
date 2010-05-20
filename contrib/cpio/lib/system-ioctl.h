begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System dependent definitions for GNU tar's use of ioctl macros.     Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2003,    2004, 2005, 2006 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This is a real challenge to properly get MTIO* symbols :-(.  ISC uses<sys/gentape.h>.  SCO and BSDi uses<sys/tape.h>; BSDi also requires<sys/tprintf.h> and<sys/device.h> for defining tp_dev and tpr_t.  It    seems that the rest use<sys/mtio.h>, which itself requires other files,    depending on systems.  Pyramid defines _IOW in<sgtty.h>, for example.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_GENTAPE_H
end_if

begin_include
include|#
directive|include
file|<sys/gentape.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TAPE_H
end_if

begin_if
if|#
directive|if
name|HAVE_SYS_DEVICE_H
end_if

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_BUF_H
end_if

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_TPRINTF_H
end_if

begin_include
include|#
directive|include
file|<sys/tprintf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/tape.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_MTIO_H
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SGTTY_H
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

begin_if
if|#
directive|if
name|HAVE_SYS_IO_TRIOCTL_H
end_if

begin_include
include|#
directive|include
file|<sys/io/trioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/mtio.h>
end_include

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

end_unit

