begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system-dependent definitions for fileutils, textutils, and sh-utils packages.    Copyright (C) 1989, 1991-2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Include sys/types.h before this file.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

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

begin_comment
comment|/*<unistd.h> should be included before any preprocessor test    of _POSIX_VERSION.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

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
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIMITS_H
end_if

begin_comment
comment|/* limits.h must come before pathmax.h because limits.h on some systems    undefs PATH_MAX, whereas pathmax.h sets PATH_MAX.  */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pathmax.h"
end_include

begin_if
if|#
directive|if
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Since major is a function on SVR4, we can't use `ifndef major'.  */
end_comment

begin_if
if|#
directive|if
name|MAJOR_IN_MKDEV
end_if

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

begin_if
if|#
directive|if
name|MAJOR_IN_SYSMACROS
end_if

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

begin_undef
undef|#
directive|undef
name|HAVE_MAJOR
end_undef

begin_if
if|#
directive|if
name|HAVE_UTIME_H
end_if

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems (even some that do have<utime.h>) don't declare this    structure anywhere.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_UTIMBUF
end_ifndef

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
comment|/* Don't use bcopy!  Use memmove if source and destination may overlap,    memcpy otherwise.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

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

begin_if
if|#
directive|if
name|HAVE_STDBOOL_H
end_if

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
init|=
literal|0
block|,
name|true
init|=
literal|1
block|}
name|bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following test is to work around the gross typo in    systems like Sony NEWS-OS Release 4.0C, whereby EXIT_FAILURE    is defined to 0, not 1.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|EXIT_FAILURE
end_if

begin_undef
undef|#
directive|undef
name|EXIT_FAILURE
end_undef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
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

begin_comment
comment|/* For systems that distinguish between text and binary I/O.    O_BINARY is usually declared in fcntl.h  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|O_BINARY
operator|&&
name|defined
name|_O_BINARY
end_if

begin_comment
comment|/* For MSC-compatible compilers.  */
end_comment

begin_define
define|#
directive|define
name|O_BINARY
value|_O_BINARY
end_define

begin_define
define|#
directive|define
name|O_TEXT
value|_O_TEXT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__BEOS__
end_ifdef

begin_comment
comment|/* BeOS 5 has O_BINARY and O_TEXT, but they have no effect.  */
end_comment

begin_undef
undef|#
directive|undef
name|O_BINARY
end_undef

begin_undef
undef|#
directive|undef
name|O_TEXT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|O_BINARY
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__DJGPP__
end_ifndef

begin_define
define|#
directive|define
name|setmode
value|_setmode
end_define

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|_fp
parameter_list|)
value|_fileno (_fp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DJGPP */
end_comment

begin_define
define|#
directive|define
name|SET_MODE
parameter_list|(
name|_f
parameter_list|,
name|_m
parameter_list|)
value|setmode (_f, _m)
end_define

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|_f
parameter_list|)
value|do {if (!isatty(_f)) setmode (_f, O_BINARY);} while (0)
end_define

begin_define
define|#
directive|define
name|SET_BINARY2
parameter_list|(
name|_f1
parameter_list|,
name|_f2
parameter_list|)
define|\
value|do {					\     if (!isatty (_f1))			\       {					\         setmode (_f1, O_BINARY);	\ 	if (!isatty (_f2))		\ 	  setmode (_f2, O_BINARY);	\       }					\   } while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_MODE
parameter_list|(
name|_f
parameter_list|,
name|_m
parameter_list|)
value|(void)0
end_define

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
name|SET_BINARY2
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_define
define|#
directive|define
name|O_TEXT
value|0
end_define

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
name|HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

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
comment|/* not HAVE_DIRENT_H */
end_comment

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_define
define|#
directive|define
name|NLENGTH
parameter_list|(
name|direct
parameter_list|)
value|((direct)->d_namlen)
end_define

begin_if
if|#
directive|if
name|HAVE_SYS_NDIR_H
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_NDIR_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_DIR_H
end_if

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
comment|/* HAVE_SYS_DIR_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_NDIR_H
end_if

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
comment|/* HAVE_NDIR_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_DIRENT_H */
end_comment

begin_if
if|#
directive|if
name|CLOSEDIR_VOID
end_if

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
comment|/* Get or fake the disk device blocksize.    Usually defined by sys/param.h (if at all).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|DEV_BSIZE
operator|&&
name|defined
name|BSIZE
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
name|DEV_BSIZE
operator|&&
name|defined
name|BBSIZE
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
comment|/* Extract or fake data from a `struct stat'.    ST_BLKSIZE: Preferred I/O blocksize for the file, in bytes.    ST_NBLOCKS: Number of blocks in the file, including indirect blocks.    ST_NBLOCKSIZE: Size of blocks used when calculating ST_NBLOCKS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_STAT_ST_BLOCKS
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

begin_comment
comment|/* fileblocks.c uses BSIZE.  */
end_comment

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
define|\
value|(S_ISREG ((statbuf).st_mode) \    || S_ISDIR ((statbuf).st_mode) \    ? (statbuf).st_size / ST_NBLOCKSIZE + ((statbuf).st_size % ST_NBLOCKSIZE != 0) : 0)
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
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
define|\
value|(S_ISREG ((statbuf).st_mode) \    || S_ISDIR ((statbuf).st_mode) \    ? st_blocks ((statbuf).st_size) : 0)
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
comment|/* HAVE_STRUCT_STAT_ST_BLOCKS */
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
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_comment
comment|/* HP-UX counts st_blocks in 1024-byte units.    This loses when mixing HP-UX and BSD filesystems with NFS.  */
end_comment

begin_define
define|#
directive|define
name|ST_NBLOCKSIZE
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !hpux */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|_I386
argument_list|)
end_if

begin_comment
comment|/* AIX PS/2 counts st_blocks in 4K units.  */
end_comment

begin_define
define|#
directive|define
name|ST_NBLOCKSIZE
value|(4 * 1024)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not AIX PS/2 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_CRAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
define|\
value|(S_ISREG ((statbuf).st_mode) \    || S_ISDIR ((statbuf).st_mode) \    ? (statbuf).st_blocks * ST_BLKSIZE(statbuf)/ST_NBLOCKSIZE : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not AIX PS/2 */
end_comment

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
comment|/* HAVE_STRUCT_STAT_ST_BLOCKS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ST_NBLOCKS
end_ifndef

begin_define
define|#
directive|define
name|ST_NBLOCKS
parameter_list|(
name|statbuf
parameter_list|)
define|\
value|(S_ISREG ((statbuf).st_mode) \    || S_ISDIR ((statbuf).st_mode) \    ? (statbuf).st_blocks : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ST_NBLOCKSIZE
end_ifndef

begin_define
define|#
directive|define
name|ST_NBLOCKSIZE
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sys2.h"
end_include

end_unit

