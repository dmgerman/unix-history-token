begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system-dependent definitions for fileutils programs.    Copyright (C) 1989, 1990, 1991 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Include sys/types.h before this file.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

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
name|defined
argument_list|(
name|MKFIFO_MISSING
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

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

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
file|<sys/time.h>
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
comment|/* !_POSIX_VERSION */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|||
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_LIMITS_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_VERSION&& !STDC_HEADERS&& !HAVE_LIMITS_H */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PATH_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_PC_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|pathconf ("/", _PC_PATH_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_PC_PATH_MAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MAXPATHLEN */
end_comment

begin_define
define|#
directive|define
name|PATH_MAX
value|_POSIX_PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PC_PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !PATH_MAX */
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|major
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
name|maj
parameter_list|,
name|min
parameter_list|)
value|(((maj)<< 8) | (min))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* major */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VERSION
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

begin_comment
comment|/* not _POSIX_VERSION */
end_comment

begin_struct
struct|struct
name|utimbuf
block|{
name|long
name|actime
decl_stmt|;
name|long
name|modtime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
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
name|STDC_HEADERS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

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

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
value|memcpy ((to), (from), (len))
end_define

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (USG or STDC_HEADERS) */
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
comment|/* USG or STDC_HEADERS */
end_comment

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

begin_comment
comment|/* not STDC_HEADERS */
end_comment

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

begin_comment
comment|/* STDC_HEADERS */
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

begin_comment
comment|/* not (USG or _POSIX_VERSION) */
end_comment

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
comment|/* USG or _POSIX_VERSION */
end_comment

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
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|R_OK
value|4
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
name|DIRENT
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
file|<dirent.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|direct
end_ifdef

begin_undef
undef|#
directive|undef
name|direct
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|direct
value|dirent
end_define

begin_define
define|#
directive|define
name|NLENGTH
parameter_list|(
name|direct
parameter_list|)
value|(strlen((direct)->d_name))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (DIRENT or _POSIX_VERSION) */
end_comment

begin_define
define|#
directive|define
name|NLENGTH
parameter_list|(
name|direct
parameter_list|)
value|((direct)->d_namlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSNDIR
end_ifdef

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
comment|/* not SYSNDIR */
end_comment

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSNDIR */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not USG */
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
comment|/* USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIRENT or _POSIX_VERSION */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VOID_CLOSEDIR
end_ifdef

begin_comment
comment|/* Fake a return value. */
end_comment

begin_define
define|#
directive|define
name|CLOSEDIR
parameter_list|(
name|d
parameter_list|)
value|(closedir (d), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLOSEDIR
parameter_list|(
name|d
parameter_list|)
value|closedir (d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extract or fake data from a `struct stat'.    ST_BLKSIZE: Optimal I/O blocksize for the file, in bytes.    ST_NBLOCKS: Number of 512-byte blocks in the file    (including indirect blocks). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ST_BLOCKS_MISSING
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|BSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ST_BLKSIZE
parameter_list|(
name|statbuf
parameter_list|)
value|1024
end_define

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
value|(((statbuf).st_size + 512 - 1) / 512)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_POSIX_SOURCE&& BSIZE */
end_comment

begin_define
define|#
directive|define
name|ST_BLKSIZE
parameter_list|(
name|statbuf
parameter_list|)
value|BSIZE
end_define

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
value|(st_blocks ((statbuf).st_size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE&& BSIZE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ST_BLOCKS_MISSING */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux__
argument_list|)
end_if

begin_comment
comment|/* HP-UX, perhaps uniquely, counts st_blocks in 1024-byte units.    This loses when mixing HP-UX and 4BSD filesystems, though. */
end_comment

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
value|((statbuf).st_blocks * 2)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !hpux */
end_comment

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
value|((statbuf).st_blocks)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !hpux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ST_BLOCKS_MISSING */
end_comment

begin_comment
comment|/* Convert B 512-byte blocks to kilobytes if K is nonzero,    otherwise return it unchanged. */
end_comment

begin_define
define|#
directive|define
name|convert_blocks
parameter_list|(
name|b
parameter_list|,
name|k
parameter_list|)
value|((k) ? ((b) + 1) / 2 : (b))
end_define

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
name|SIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|_AIX
end_ifndef

begin_comment
comment|/* AIX alloca decl has to be the first thing in the file, bletch! */
end_comment

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

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

