begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system-dependent definitions for textutils programs.    Copyright (C) 1989, 1990, 1991 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Include sys/types.h before this file.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|STAT_MACROS_BROKEN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISBLK
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISBLK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISCHR
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISCHR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISDIR
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISFIFO
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISFIFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISLNK
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISLNK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISMPB
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISMPB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISMPC
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISMPC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISNWK
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISNWK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISREG
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISSOCK
end_ifdef

begin_undef
undef|#
directive|undef
name|S_ISSOCK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STAT_MACROS_BROKEN.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_comment
comment|/* Doesn't have POSIX.1 stat stuff. */
end_comment

begin_define
define|#
directive|define
name|mode_t
value|unsigned short
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
name|S_ISBLK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFBLK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFBLK)
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
name|S_ISCHR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFCHR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFCHR)
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
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
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
name|S_ISREG
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
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
name|S_ISFIFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFIFO)
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
name|S_ISLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFLNK)
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
name|S_ISSOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFSOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFSOCK)
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
name|S_ISMPB
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFMPB
argument_list|)
end_if

begin_comment
comment|/* V7 */
end_comment

begin_define
define|#
directive|define
name|S_ISMPB
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPB)
end_define

begin_define
define|#
directive|define
name|S_ISMPC
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPC)
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
name|S_ISNWK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFNWK
argument_list|)
end_if

begin_comment
comment|/* HP/UX */
end_comment

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFNWK)
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
name|HAVE_MKFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|mkfifo
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
value|(mknod ((path), (mode) | S_IFIFO, 0))
end_define

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
name|_POSIX_VERSION
end_ifndef

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
operator|||
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_MEMORY_H
argument_list|)
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

begin_comment
comment|/* Don't define bcopy; we need one that can handle overlaps.  */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FCNTL_H
argument_list|)
operator|||
name|defined
argument_list|(
name|_POSIX_VERSION
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SEEK_SET
argument_list|)
end_if

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
name|_POSIX_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get or fake the disk device blocksize.    Usually defined by sys/param.h (if at all).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEV_BSIZE
argument_list|)
operator|&&
name|defined
argument_list|(
name|BSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEV_BSIZE
value|BSIZE
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
name|DEV_BSIZE
argument_list|)
operator|&&
name|defined
argument_list|(
name|BBSIZE
argument_list|)
end_if

begin_comment
comment|/* SGI */
end_comment

begin_define
define|#
directive|define
name|DEV_BSIZE
value|BBSIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_BSIZE
end_ifndef

begin_define
define|#
directive|define
name|DEV_BSIZE
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extract or fake data from a `struct stat'.    ST_BLKSIZE: Optimal I/O blocksize for the file, in bytes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ST_BLKSIZE
end_ifndef

begin_define
define|#
directive|define
name|ST_BLKSIZE
parameter_list|(
name|statbuf
parameter_list|)
value|DEV_BSIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_ST_BLKSIZE */
end_comment

begin_comment
comment|/* Some systems, like Sequents, return st_blksize of 0 on pipes. */
end_comment

begin_define
define|#
directive|define
name|ST_BLKSIZE
parameter_list|(
name|statbuf
parameter_list|)
value|((statbuf).st_blksize> 0 \ 			       ? (statbuf).st_blksize : DEV_BSIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ST_BLKSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_define
define|#
directive|define
name|lstat
value|stat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RETSIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|isascii
end_ifndef

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isblank
end_ifdef

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isblank (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isgraph
end_ifdef

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isgraph (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isprint (c)&& !isspace (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isprint (c))
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isdigit (c))
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isalnum (c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isalpha (c))
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& iscntrl (c))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& islower (c))
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& ispunct (c))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isspace (c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isupper (c))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isxdigit (c))
end_define

end_unit

