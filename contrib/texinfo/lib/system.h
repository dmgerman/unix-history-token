begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system.h: system-dependent declarations; include this first.    $Id: system.h,v 1.14 1999/07/17 21:11:34 karl Exp $     Copyright (C) 1997, 98, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TEXINFO_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|TEXINFO_SYSTEM_H
end_define

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_comment
comment|/*<unistd.h> should be included before any preprocessor test    of _POSIX_VERSION.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOCALE
end_ifndef

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|category
parameter_list|,
name|locale
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For gettext (NLS).  */
end_comment

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_define
define|#
directive|define
name|getopt
value|system_getopt
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_undef
undef|#
directive|undef
name|getopt
end_undef

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't use bcopy!  Use memmove if source and destination may overlap,    memcpy otherwise.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_if
if|#
directive|if
operator|!
name|STDC_HEADERS
operator|&&
name|HAVE_MEMORY_H
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_function_decl
name|char
modifier|*
name|memchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|<perror.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRERROR
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRCASECMP
end_ifndef

begin_function_decl
specifier|extern
name|int
name|strcasecmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRNCASECMP
end_ifndef

begin_function_decl
specifier|extern
name|int
name|strncasecmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRCOLL
end_ifndef

begin_function_decl
specifier|extern
name|int
name|strcoll
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

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
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

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

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_comment
comment|/* Since<fcntl.h> is POSIX, prefer that to<sys/fcntl.h>.    This also avoids some useless warnings on (at least) Linux.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_FCNTL_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_SYS_FCNTL_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_FCNTL_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not O_RDONLY */
end_comment

begin_comment
comment|/* MS-DOS and similar non-Posix systems have some peculiarities:     - they distinguish between binary and text files;     - they use both `/' and `\\' as directory separator in file names;     - they can have a drive letter X: prepended to a file name;     - they have a separate root directory on each drive;     - their filesystems are case-insensitive;     - directories in environment variables (like INFOPATH) are separated         by `;' rather than `:';     - text files can have their lines ended either with \n or with \r\n pairs;     These are all parameterized here except the last, which is    handled by the source code as appropriate (mostly, in info/).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_O_BINARY
end_ifdef

begin_define
define|#
directive|define
name|O_BINARY
value|_O_BINARY
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|O_BINARY
value|0
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
comment|/* O_BINARY */
end_comment

begin_if
if|#
directive|if
name|O_BINARY
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__MSDOS__
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__DJGPP__
end_ifdef

begin_define
define|#
directive|define
name|HAVE_LONG_FILENAMES
parameter_list|(
name|dir
parameter_list|)
value|(pathconf (dir, _PC_NAME_MAX)> 12)
end_define

begin_define
define|#
directive|define
name|NULL_DEVICE
value|"/dev/null"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__DJGPP__ */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_FILENAMES
parameter_list|(
name|dir
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|NULL_DEVICE
value|"NUL"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__DJGPP__ */
end_comment

begin_define
define|#
directive|define
name|SET_SCREEN_SIZE_HELPER
value|terminal_prep_terminal()
end_define

begin_define
define|#
directive|define
name|DEFAULT_INFO_PRINT_COMMAND
value|">PRN"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__MSDOS__ */
end_comment

begin_define
define|#
directive|define
name|setmode
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|_setmode(f,m)
end_define

begin_define
define|#
directive|define
name|HAVE_LONG_FILENAMES
parameter_list|(
name|dir
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|NULL_DEVICE
value|"NUL"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__MSDOS__ */
end_comment

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
value|do {if (!isatty(f)) setmode(f,O_BINARY);} while(0)
end_define

begin_define
define|#
directive|define
name|FOPEN_RBIN
value|"rb"
end_define

begin_define
define|#
directive|define
name|FOPEN_WBIN
value|"wb"
end_define

begin_define
define|#
directive|define
name|IS_SLASH
parameter_list|(
name|c
parameter_list|)
value|((c) == '/' || (c) == '\\')
end_define

begin_define
define|#
directive|define
name|HAVE_DRIVE
parameter_list|(
name|n
parameter_list|)
value|((n)[0]&& (n)[1] == ':')
end_define

begin_define
define|#
directive|define
name|IS_ABSOLUTE
parameter_list|(
name|n
parameter_list|)
value|(IS_SLASH((n)[0]) || ((n)[0]&& (n)[1] == ':'))
end_define

begin_define
define|#
directive|define
name|FILENAME_CMP
value|strcasecmp
end_define

begin_define
define|#
directive|define
name|FILENAME_CMPN
value|strncasecmp
end_define

begin_define
define|#
directive|define
name|PATH_SEP
value|";"
end_define

begin_define
define|#
directive|define
name|STRIP_DOT_EXE
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_TMPDIR
value|"c:/"
end_define

begin_define
define|#
directive|define
name|PIPE_USE_FORK
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not O_BINARY */
end_comment

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|FOPEN_RBIN
value|"r"
end_define

begin_define
define|#
directive|define
name|FOPEN_WBIN
value|"w"
end_define

begin_define
define|#
directive|define
name|IS_SLASH
parameter_list|(
name|c
parameter_list|)
value|((c) == '/')
end_define

begin_define
define|#
directive|define
name|HAVE_DRIVE
parameter_list|(
name|n
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|IS_ABSOLUTE
parameter_list|(
name|n
parameter_list|)
value|((n)[0] == '/')
end_define

begin_define
define|#
directive|define
name|FILENAME_CMP
value|strcmp
end_define

begin_define
define|#
directive|define
name|FILENAME_CMPN
value|strncmp
end_define

begin_define
define|#
directive|define
name|HAVE_LONG_FILENAMES
parameter_list|(
name|dir
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|PATH_SEP
value|":"
end_define

begin_define
define|#
directive|define
name|STRIP_DOT_EXE
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_TMPDIR
value|"sys$scratch:"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_TMPDIR
value|"/tmp/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULL_DEVICE
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|PIPE_USE_FORK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not O_BINARY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems don't declare this function in pwd.h. */
end_comment

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Our library routines not included in any system library.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|xstrdup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|substring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* For convenience.  */
end_comment

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp (s1, s2) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEXINFO_SYSTEM_H */
end_comment

end_unit

