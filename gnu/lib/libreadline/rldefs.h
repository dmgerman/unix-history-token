begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rldefs.h -- an attempt to isolate some of the system-specific defines    for readline.  This should be included after any files that define    system-specific constants like _POSIX_VERSION or USG. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1989 Free Software Foundation, Inc.     This file contains the Readline Library (the Library), a set of    routines for providing Emacs style line input to programs that ask    for it.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RLDEFS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RLDEFS_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PRAGMA_ALLOCA
argument_list|)
end_if

begin_include
include|#
directive|include
file|"memalloc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEW_TTY_DRIVER
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_SIGNALS
end_define

begin_comment
comment|/* #define USE_XON_XOFF */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termcap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_comment
comment|/* Some USG machines have BSD signal handling (sigblock, sigsetmask, etc.) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_BSD_SIGNALS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System V machines use termio. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|Xenix
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|DGUX
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|NEW_TTY_DRIVER
end_undef

begin_define
define|#
directive|define
name|TERMIO_TTY_DRIVER
end_define

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
comment|/* USG || hpux || Xenix || sgi || DUGX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_VERSION */
end_comment

begin_comment
comment|/* Posix systems use termios and the Posix signal functions. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TERMIOS_MISSING
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|NEW_TTY_DRIVER
end_undef

begin_define
define|#
directive|define
name|TERMIOS_TTY_DRIVER
end_define

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
comment|/* !TERMIOS_MISSING */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_SIGNALS
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|O_NDELAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|O_NDELAY
value|O_NONBLOCK
end_define

begin_comment
comment|/* Posix-style non-blocking i/o */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* O_NDELAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_comment
comment|/* System V.3 machines have the old 4.1 BSD `reliable' signal interface. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_BSD_SIGNALS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USGr3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XENIX_22
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_USG_SIGHOLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_USG_SIGHOLD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_USG_SIGHOLD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USGr3&& !XENIX_22 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_BSD_SIGNALS&& !HAVE_POSIX_SIGNALS */
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
comment|/* !NEW_TTY_DRIVER&& !_POSIX_VDISABLE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|||
name|defined
argument_list|(
name|USGr3
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_DIRENT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_DIRENT_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SHELL&& (_POSIX_VERSION || USGr3) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DIRENT_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|direct
argument_list|)
end_if

begin_define
define|#
directive|define
name|direct
value|dirent
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !direct */
end_comment

begin_define
define|#
directive|define
name|D_NAMLEN
parameter_list|(
name|d
parameter_list|)
value|strlen ((d)->d_name)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_DIRENT_H */
end_comment

begin_define
define|#
directive|define
name|D_NAMLEN
parameter_list|(
name|d
parameter_list|)
value|((d)->d_namlen)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Xenix
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !Xenix (but USG...) */
end_comment

begin_include
include|#
directive|include
file|"ndir.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !Xenix */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USG */
end_comment

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_DIRENT_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Linux
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

begin_include
include|#
directive|include
file|<sys/ptem.h>
end_include

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
comment|/* USG&& TIOCGWINSZ&& !Linux */
end_comment

begin_comment
comment|/* Posix macro to check file in statbuf for directory-ness.    This requires that<sys/stat.h> be included before this test. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)&S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Decide which flavor of the header file describing the C library    string functions to include and include it. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_STRING_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRING_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG || NeXT */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_STRING_H */
end_comment

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
comment|/* !HAVE_STRING_H */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|strchr
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !strchr&& !__STDC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VARARGS_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_VARARGS_H */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|emacs_mode
argument_list|)
end_if

begin_define
define|#
directive|define
name|no_mode
value|-1
end_define

begin_define
define|#
directive|define
name|vi_mode
value|0
end_define

begin_define
define|#
directive|define
name|emacs_mode
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If you cast map[key].function to type (Keymap) on a Cray,    the compiler takes the value of map[key].function and    divides it by 4 to convert between pointer types (pointers    to functions and pointers to structs are different sizes).    This is not what is wanted. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|FUNCTION_TO_KEYMAP
parameter_list|(
name|map
parameter_list|,
name|key
parameter_list|)
value|(Keymap)((int)map[key].function)
end_define

begin_define
define|#
directive|define
name|KEYMAP_TO_FUNCTION
parameter_list|(
name|data
parameter_list|)
value|(Function *)((int)(data))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FUNCTION_TO_KEYMAP
parameter_list|(
name|map
parameter_list|,
name|key
parameter_list|)
value|(Keymap)(map[key].function)
end_define

begin_define
define|#
directive|define
name|KEYMAP_TO_FUNCTION
parameter_list|(
name|data
parameter_list|)
value|(Function *)(data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Possible values for _rl_bell_preference. */
end_comment

begin_define
define|#
directive|define
name|NO_BELL
value|0
end_define

begin_define
define|#
directive|define
name|AUDIBLE_BELL
value|1
end_define

begin_define
define|#
directive|define
name|VISIBLE_BELL
value|2
end_define

begin_comment
comment|/* CONFIGURATION SECTION */
end_comment

begin_include
include|#
directive|include
file|"rlconf.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RLDEFS_H */
end_comment

end_unit

