begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rlwinsize.h -- an attempt to isolate some of the system-specific defines    for `struct winsize' and TIOCGWINSZ. */
end_comment

begin_comment
comment|/* Copyright (C) 1997 Free Software Foundation, Inc.     This file contains the Readline Library (the Library), a set of    routines for providing Emacs style line input to programs that ask    for it.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RLWINSIZE_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RLWINSIZE_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Try to find the definitions of `struct winsize' and TIOGCWINSZ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GWINSZ_IN_SYS_IOCTL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
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

begin_comment
comment|/* GWINSZ_IN_SYS_IOCTL&& !TIOCGWINSZ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STRUCT_WINSIZE_IN_TERMIOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRUCT_WINSIZE_IN_SYS_IOCTL
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
comment|/* STRUCT_WINSIZE_IN_TERMIOS&& !STRUCT_WINSIZE_IN_SYS_IOCTL */
end_comment

begin_comment
comment|/* Not in either of the standard places, look around. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STRUCT_WINSIZE_IN_TERMIOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRUCT_WINSIZE_IN_SYS_IOCTL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_STREAM_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_STREAM_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_PTEM_H
argument_list|)
end_if

begin_comment
comment|/* SVR4.2, at least, has it here */
end_comment

begin_include
include|#
directive|include
file|<sys/ptem.h>
end_include

begin_define
define|#
directive|define
name|_IO_PTEM_H
end_define

begin_comment
comment|/* work around SVR4.2 1.1.4 bug */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PTEM_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_PTE_H
argument_list|)
end_if

begin_comment
comment|/* ??? */
end_comment

begin_include
include|#
directive|include
file|<sys/pte.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PTE_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !STRUCT_WINSIZE_IN_TERMIOS&& !STRUCT_WINSIZE_IN_SYS_IOCTL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RL_WINSIZE_H */
end_comment

end_unit

