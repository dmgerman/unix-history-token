begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System dependent declarations.  Requires sys/types.h.    Copyright (C) 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
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

begin_ifndef
ifndef|#
directive|ifndef
name|index
end_ifndef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|rindex
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|bcmp
end_ifndef

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcmp ((s1), (s2), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bzero
end_ifndef

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset ((s), 0, (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VERSION
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|long
name|off_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Since major is a function on SVR4, we can't use `ifndef major'.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAJOR_IN_MKDEV
end_ifdef

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_define
define|#
directive|define
name|HAVE_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAJOR_IN_SYSMACROS
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_define
define|#
directive|define
name|HAVE_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|major
end_ifdef

begin_comment
comment|/* Might be defined in sys/types.h.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MAJOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MAJOR
end_ifndef

begin_define
define|#
directive|define
name|major
parameter_list|(
name|dev
parameter_list|)
value|(((dev)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|dev
parameter_list|)
value|((dev)& 0xff)
end_define

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|ma
parameter_list|,
name|mi
parameter_list|)
value|(((ma)<< 8) | (mi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|HAVE_MAJOR
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|||
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_FCNTL_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

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
name|__EMX__
end_ifdef

begin_comment
comment|/* gcc on OS/2.  */
end_comment

begin_define
define|#
directive|define
name|EPERM
value|EACCES
end_define

begin_define
define|#
directive|define
name|ENXIO
value|EIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTIME_H
end_ifdef

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|utimbuf
block|{
name|time_t
name|actime
decl_stmt|;
name|time_t
name|modtime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__MSDOS__
end_ifndef

begin_define
define|#
directive|define
name|CONSOLE
value|"/dev/tty"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CONSOLE
value|"con"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On most systems symlink() always creates links with rwxrwxrwx    protection modes, but on some (HP/UX 8.07; I think maybe DEC's OSF    on MIPS too) symlink() uses the value of umask, so links' protection modes    aren't always rwxrwxrwx.  There doesn't seem to be any way to change    the modes of a link (no system call like, say, lchmod() ), it seems    the only way to set the modes right is to set umask before calling    symlink(). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYMLINK_USES_UMASK
end_ifndef

begin_define
define|#
directive|define
name|UMASKED_SYMLINK
parameter_list|(
name|name1
parameter_list|,
name|name2
parameter_list|,
name|mode
parameter_list|)
value|symlink(name1,name2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMASKED_SYMLINK
parameter_list|(
name|name1
parameter_list|,
name|name2
parameter_list|,
name|mode
parameter_list|)
value|umasked_symlink(name1,name2,mode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMLINK_USES_UMASK */
end_comment

end_unit

