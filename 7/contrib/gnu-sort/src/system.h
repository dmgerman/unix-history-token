begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system-dependent definitions for fileutils, textutils, and sh-utils packages.    Copyright (C) 1989, 1991-2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_comment
comment|/* Include sys/types.h before this file.  */
end_comment

begin_if
if|#
directive|if
literal|2
operator|<=
name|__GLIBC__
operator|&&
literal|2
operator|<=
name|__GLIBC_MINOR__
end_if

begin_if
if|#
directive|if
operator|!
name|defined
name|_SYS_TYPES_H
end_if

begin_expr_stmt
name|you
name|must
name|include
operator|<
name|sys
operator|/
name|types
operator|.
name|h
operator|>
name|before
name|including
name|this
name|file
endif|#
directive|endif
endif|#
directive|endif
include|#
directive|include
file|<sys/stat.h>
if|#
directive|if
operator|!
name|defined
name|HAVE_MKFIFO
define|#
directive|define
name|mkfifo
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
value|(mknod ((path), (mode) | S_IFIFO, 0))
endif|#
directive|endif
if|#
directive|if
name|HAVE_SYS_PARAM_H
include|#
directive|include
file|<sys/param.h>
endif|#
directive|endif
comment|/*<unistd.h> should be included before any preprocessor test    of _POSIX_VERSION.  */
if|#
directive|if
name|HAVE_UNISTD_H
include|#
directive|include
file|<unistd.h>
endif|#
directive|endif
ifndef|#
directive|ifndef
name|STDIN_FILENO
define|#
directive|define
name|STDIN_FILENO
value|0
endif|#
directive|endif
ifndef|#
directive|ifndef
name|STDOUT_FILENO
define|#
directive|define
name|STDOUT_FILENO
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|STDERR_FILENO
define|#
directive|define
name|STDERR_FILENO
value|2
endif|#
directive|endif
comment|/* limits.h must come before pathmax.h because limits.h on some systems    undefs PATH_MAX, whereas pathmax.h sets PATH_MAX.  */
include|#
directive|include
file|<limits.h>
include|#
directive|include
file|"pathmax.h"
include|#
directive|include
file|"localedir.h"
if|#
directive|if
name|TIME_WITH_SYS_TIME
include|#
directive|include
file|<sys/time.h>
include|#
directive|include
file|<time.h>
else|#
directive|else
if|#
directive|if
name|HAVE_SYS_TIME_H
include|#
directive|include
file|<sys/time.h>
else|#
directive|else
include|#
directive|include
file|<time.h>
endif|#
directive|endif
endif|#
directive|endif
comment|/* Since major is a function on SVR4, we can't use `ifndef major'.  */
if|#
directive|if
name|MAJOR_IN_MKDEV
include|#
directive|include
file|<sys/mkdev.h>
define|#
directive|define
name|HAVE_MAJOR
endif|#
directive|endif
if|#
directive|if
name|MAJOR_IN_SYSMACROS
include|#
directive|include
file|<sys/sysmacros.h>
define|#
directive|define
name|HAVE_MAJOR
endif|#
directive|endif
ifdef|#
directive|ifdef
name|major
comment|/* Might be defined in sys/types.h.  */
define|#
directive|define
name|HAVE_MAJOR
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_MAJOR
define|#
directive|define
name|major
parameter_list|(
name|dev
parameter_list|)
value|(((dev)>> 8)& 0xff)
define|#
directive|define
name|minor
parameter_list|(
name|dev
parameter_list|)
value|((dev)& 0xff)
define|#
directive|define
name|makedev
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
value|(((maj)<< 8) | (min))
endif|#
directive|endif
undef|#
directive|undef
name|HAVE_MAJOR
if|#
directive|if
operator|!
name|defined
name|makedev
operator|&&
name|defined
name|mkdev
define|#
directive|define
name|makedev
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
value|mkdev (maj, min)
endif|#
directive|endif
if|#
directive|if
name|HAVE_UTIME_H
include|#
directive|include
file|<utime.h>
endif|#
directive|endif
comment|/* Some systems (even some that do have<utime.h>) don't declare this    structure anywhere.  */
ifndef|#
directive|ifndef
name|HAVE_STRUCT_UTIMBUF
expr|struct
name|utimbuf
block|{
name|long
name|actime
block|;
name|long
name|modtime
block|; }
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't use bcopy!  Use memmove if source and destination may overlap,    memcpy otherwise.  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_MEMRCHR
end_if

begin_function_decl
name|void
modifier|*
name|memrchr
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
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

begin_comment
comment|/* Some systems don't define the following symbols.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSYS
end_ifndef

begin_define
define|#
directive|define
name|ENOSYS
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EISDIR
end_ifndef

begin_define
define|#
directive|define
name|EISDIR
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

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

begin_comment
comment|/* Exit statuses for programs like 'env' that exec other programs.    EXIT_FAILURE might not be 1, so use EXIT_FAIL in such programs.  */
end_comment

begin_enum
enum|enum
block|{
name|EXIT_FAIL
init|=
literal|1
block|,
name|EXIT_CANNOT_INVOKE
init|=
literal|126
block|,
name|EXIT_ENOENT
init|=
literal|127
block|}
enum|;
end_enum

begin_include
include|#
directive|include
file|"exitfail.h"
end_include

begin_comment
comment|/* Set exit_failure to STATUS if that's not the default already.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|initialize_exit_failure
parameter_list|(
name|int
name|status
parameter_list|)
block|{
if|if
condition|(
name|status
operator|!=
name|EXIT_FAILURE
condition|)
name|exit_failure
operator|=
name|status
expr_stmt|;
block|}
end_function

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
name|SEEK_SET
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

begin_if
if|#
directive|if
operator|!
name|defined
name|O_DIRECT
end_if

begin_define
define|#
directive|define
name|O_DIRECT
value|0
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
name|O_DSYNC
end_if

begin_define
define|#
directive|define
name|O_DSYNC
value|0
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
name|O_NDELAY
end_if

begin_define
define|#
directive|define
name|O_NDELAY
value|0
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
name|O_NONBLOCK
end_if

begin_define
define|#
directive|define
name|O_NONBLOCK
value|O_NDELAY
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
name|O_NOCTTY
end_if

begin_define
define|#
directive|define
name|O_NOCTTY
value|0
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
name|O_NOFOLLOW
end_if

begin_define
define|#
directive|define
name|O_NOFOLLOW
value|0
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
name|O_RSYNC
end_if

begin_define
define|#
directive|define
name|O_RSYNC
value|0
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
name|O_SYNC
end_if

begin_define
define|#
directive|define
name|O_SYNC
value|0
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
name|_POSIX_SOURCE
operator|||
operator|!
name|defined
name|BSIZE
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
value|((statbuf).st_size / ST_NBLOCKSIZE + ((statbuf).st_size % ST_NBLOCKSIZE != 0))
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
comment|/* Some systems, like Sequents, return st_blksize of 0 on pipes.    Also, when running `rsh hpux11-system cat any-file', cat would    determine that the output stream had an st_blksize of 2147421096.    So here we arbitrarily limit the `optimal' block size to 4MB.    If anyone knows of a system for which the legitimate value for    st_blksize can exceed 4MB, please report it as a bug in this code.  */
end_comment

begin_define
define|#
directive|define
name|ST_BLKSIZE
parameter_list|(
name|statbuf
parameter_list|)
value|((0< (statbuf).st_blksize \&& (statbuf).st_blksize<= (1<< 22))
comment|/* 4MB */
value|\ 			      ? (statbuf).st_blksize : DEV_BSIZE)
end_define

begin_if
if|#
directive|if
name|defined
name|hpux
operator|||
name|defined
name|__hpux__
operator|||
name|defined
name|__hpux
end_if

begin_comment
comment|/* HP-UX counts st_blocks in 1024-byte units.    This loses when mixing HP-UX and BSD file systems with NFS.  */
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
name|_AIX
operator|&&
name|defined
name|_I386
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
name|_CRAY
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
value|((statbuf).st_blocks)
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

begin_comment
comment|/* Redirection and wildcarding when done by the utility itself.    Generally a noop, but used in particular for native VMS. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|initialize_main
end_ifndef

begin_define
define|#
directive|define
name|initialize_main
parameter_list|(
name|ac
parameter_list|,
name|av
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"stat-macros.h"
end_include

begin_include
include|#
directive|include
file|"timespec.h"
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|__DJGPP__
end_ifdef

begin_comment
comment|/* We need the declaration of setmode.  */
end_comment

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_comment
comment|/* We need the declaration of __djgpp_set_ctrl_c.  */
end_comment

begin_include
include|#
directive|include
file|<sys/exceptn.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ULONG_MAX
operator|<
name|ULLONG_MAX
end_if

begin_define
define|#
directive|define
name|LONGEST_MODIFIER
value|"ll"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONGEST_MODIFIER
value|"l"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PRI_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|PRIdMAX
end_undef

begin_undef
undef|#
directive|undef
name|PRIoMAX
end_undef

begin_undef
undef|#
directive|undef
name|PRIuMAX
end_undef

begin_undef
undef|#
directive|undef
name|PRIxMAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIdMAX
end_ifndef

begin_define
define|#
directive|define
name|PRIdMAX
value|LONGEST_MODIFIER "d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIoMAX
end_ifndef

begin_define
define|#
directive|define
name|PRIoMAX
value|LONGEST_MODIFIER "o"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIuMAX
end_ifndef

begin_define
define|#
directive|define
name|PRIuMAX
value|LONGEST_MODIFIER "u"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIxMAX
end_ifndef

begin_define
define|#
directive|define
name|PRIxMAX
value|LONGEST_MODIFIER "x"
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

begin_comment
comment|/* Jim Meyering writes:     "... Some ctype macros are valid only for character codes that    isascii says are ASCII (SGI's IRIX-4.0.5 is one such system --when    using /bin/cc or gcc but without giving an ansi option).  So, all    ctype uses should be through macros like ISPRINT...  If    STDC_HEADERS is defined, then autoconf has verified that the ctype    macros don't need to be guarded with references to isascii. ...    Defining isascii to 1 should let any compiler worth its salt    eliminate the&& through constant folding."     Bruno Haible adds:     "... Furthermore, isupper(c) etc. have an undefined result if c is    outside the range -1<= c<= 255. One is tempted to write isupper(c)    with c being of type `char', but this is wrong if c is an 8-bit    character>= 128 which gets sign-extended to a negative value.    The macro ISUPPER protects against this as well."  */
end_comment

begin_if
if|#
directive|if
name|STDC_HEADERS
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|isascii
argument_list|)
operator|&&
operator|!
name|HAVE_ISASCII
operator|)
end_if

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
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
value|(IN_CTYPE_DOMAIN (c)&& isblank (c))
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
value|(IN_CTYPE_DOMAIN (c)&& isgraph (c))
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
value|(IN_CTYPE_DOMAIN (c)&& isprint (c)&& !isspace (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is defined in<sys/euc.h> on at least Solaris2.6 systems.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISPRINT
end_undef

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isprint (c))
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalnum (c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalpha (c))
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& iscntrl (c))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& islower (c))
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& ispunct (c))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isspace (c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isupper (c))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isxdigit (c))
end_define

begin_define
define|#
directive|define
name|ISDIGIT_LOCALE
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isdigit (c))
end_define

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|Ch
parameter_list|)
value|tolower (Ch)
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|toupper (Ch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|Ch
parameter_list|)
value|(ISUPPER (Ch) ? tolower (Ch) : (Ch))
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|(ISLOWER (Ch) ? toupper (Ch) : (Ch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISDIGIT differs from ISDIGIT_LOCALE, as follows:    - Its arg may be any int or unsigned int; it need not be an unsigned char.    - It's guaranteed to evaluate its argument exactly once.    - It's typically faster.    POSIX says that only '0' through '9' are digits.  Prefer ISDIGIT to    ISDIGIT_LOCALE unless it's important to use the locale's definition    of `digit' even when the host does not conform to POSIX.  */
end_comment

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|((unsigned int) (c) - '0'<= 9)
end_define

begin_comment
comment|/* Convert a possibly-signed character to an unsigned character.  This is    a bit safer than casting to unsigned char, since it catches some type    errors that the cast doesn't.  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|char
name|to_uchar
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|ch
return|;
block|}
end_function

begin_comment
comment|/* Take care of NLS matters.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_LOCALE_H
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|Category
parameter_list|,
name|Locale
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gettext.h"
end_include

begin_if
if|#
directive|if
operator|!
name|ENABLE_NLS
end_if

begin_undef
undef|#
directive|undef
name|textdomain
end_undef

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_undef
undef|#
directive|undef
name|bindtextdomain
end_undef

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|msgid
parameter_list|)
value|msgid
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOCALE
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp ((a), (b)) == 0)
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_FREE
end_if

begin_function_decl
name|void
name|free
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
operator|!
name|HAVE_DECL_MALLOC
end_if

begin_function_decl
name|char
modifier|*
name|malloc
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
operator|!
name|HAVE_DECL_MEMCHR
end_if

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

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_REALLOC
end_if

begin_function_decl
name|char
modifier|*
name|realloc
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
operator|!
name|HAVE_DECL_STPCPY
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|stpcpy
end_ifndef

begin_function_decl
name|char
modifier|*
name|stpcpy
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

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STRNDUP
end_if

begin_function_decl
name|char
modifier|*
name|strndup
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
operator|!
name|HAVE_DECL_STRSTR
end_if

begin_function_decl
name|char
modifier|*
name|strstr
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
operator|!
name|HAVE_DECL_GETENV
end_if

begin_function_decl
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

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_LSEEK
end_if

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
comment|/* This is needed on some AIX systems.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STRTOUL
end_if

begin_function_decl
name|unsigned
name|long
name|strtoul
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
operator|!
name|HAVE_DECL_GETLOGIN
end_if

begin_function_decl
name|char
modifier|*
name|getlogin
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
operator|!
name|HAVE_DECL_TTYNAME
end_if

begin_function_decl
name|char
modifier|*
name|ttyname
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
operator|!
name|HAVE_DECL_GETEUID
end_if

begin_function_decl
name|uid_t
name|geteuid
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
operator|!
name|HAVE_DECL_GETPWUID
end_if

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
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
operator|!
name|HAVE_DECL_GETGRGID
end_if

begin_function_decl
name|struct
name|group
modifier|*
name|getgrgid
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
operator|!
name|HAVE_DECL_GETUID
end_if

begin_function_decl
name|uid_t
name|getuid
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
file|"xalloc.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
name|HAVE_MEMPCPY
operator|&&
operator|!
name|defined
name|mempcpy
end_if

begin_comment
comment|/* Be CAREFUL that there are no side effects in N.  */
end_comment

begin_define
define|#
directive|define
name|mempcpy
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|((void *) ((char *) memcpy (D, S, N) + (N)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include automatically-generated macros for unlocked I/O.  */
end_comment

begin_include
include|#
directive|include
file|"unlocked-io.h"
end_include

begin_define
define|#
directive|define
name|SAME_INODE
parameter_list|(
name|Stat_buf_1
parameter_list|,
name|Stat_buf_2
parameter_list|)
define|\
value|((Stat_buf_1).st_ino == (Stat_buf_2).st_ino \&& (Stat_buf_1).st_dev == (Stat_buf_2).st_dev)
end_define

begin_define
define|#
directive|define
name|DOT_OR_DOTDOT
parameter_list|(
name|Basename
parameter_list|)
define|\
value|(Basename[0] == '.'&& (Basename[1] == '\0' \ 			  || (Basename[1] == '.'&& Basename[2] == '\0')))
end_define

begin_comment
comment|/* A wrapper for readdir so that callers don't see entries for `.' or `..'.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|dirent
specifier|const
modifier|*
name|readdir_ignoring_dot_and_dotdot
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{
name|struct
name|dirent
specifier|const
modifier|*
name|dp
init|=
name|readdir
argument_list|(
name|dirp
argument_list|)
decl_stmt|;
if|if
condition|(
name|dp
operator|==
name|NULL
operator|||
operator|!
name|DOT_OR_DOTDOT
argument_list|(
name|dp
operator|->
name|d_name
argument_list|)
condition|)
return|return
name|dp
return|;
block|}
block|}
end_function

begin_if
if|#
directive|if
name|SETVBUF_REVERSED
end_if

begin_define
define|#
directive|define
name|SETVBUF
parameter_list|(
name|Stream
parameter_list|,
name|Buffer
parameter_list|,
name|Type
parameter_list|,
name|Size
parameter_list|)
define|\
value|setvbuf (Stream, Type, Buffer, Size)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SETVBUF
parameter_list|(
name|Stream
parameter_list|,
name|Buffer
parameter_list|,
name|Type
parameter_list|,
name|Size
parameter_list|)
define|\
value|setvbuf (Stream, Buffer, Type, Size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Factor out some of the common --help and --version processing code.  */
end_comment

begin_comment
comment|/* These enum values cannot possibly conflict with the option values    ordinarily used by commands, including CHAR_MAX + 1, etc.  Avoid    CHAR_MIN - 1, as it may equal -1, the getopt end-of-options value.  */
end_comment

begin_enum
enum|enum
block|{
name|GETOPT_HELP_CHAR
init|=
operator|(
name|CHAR_MIN
operator|-
literal|2
operator|)
block|,
name|GETOPT_VERSION_CHAR
init|=
operator|(
name|CHAR_MIN
operator|-
literal|3
operator|)
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|GETOPT_HELP_OPTION_DECL
define|\
value|"help", no_argument, 0, GETOPT_HELP_CHAR
end_define

begin_define
define|#
directive|define
name|GETOPT_VERSION_OPTION_DECL
define|\
value|"version", no_argument, 0, GETOPT_VERSION_CHAR
end_define

begin_define
define|#
directive|define
name|case_GETOPT_HELP_CHAR
define|\
value|case GETOPT_HELP_CHAR:			\     usage (EXIT_SUCCESS);			\     break;
end_define

begin_define
define|#
directive|define
name|HELP_OPTION_DESCRIPTION
define|\
value|_("      --help     display this help and exit\n")
end_define

begin_define
define|#
directive|define
name|VERSION_OPTION_DESCRIPTION
define|\
value|_("      --version  output version information and exit\n")
end_define

begin_include
include|#
directive|include
file|"closeout.h"
end_include

begin_include
include|#
directive|include
file|"version-etc.h"
end_include

begin_define
define|#
directive|define
name|case_GETOPT_VERSION_CHAR
parameter_list|(
name|Program_name
parameter_list|,
name|Authors
parameter_list|)
define|\
value|case GETOPT_VERSION_CHAR:						\     version_etc (stdout, Program_name, GNU_PACKAGE, VERSION, Authors,	\                  (char *) NULL);					\     exit (EXIT_SUCCESS);						\     break;
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The extra casts work around common compiler bugs.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_comment
comment|/* The outer cast is needed to work around a bug in Cray C 5.0.3.0.    It is necessary at least when t == time_t.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (TYPE_SIGNED (t) \ 			      ? ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1) : (t) 0))
end_define

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - TYPE_MINIMUM (t)))
end_define

begin_comment
comment|/* Upper bound on the string length of an integer converted to string.    302 / 1000 is ceil (log10 (2.0)).  Subtract 1 for the sign bit;    add 1 for integer division truncation; add 1 more for a minus sign.  */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_BOUND
parameter_list|(
name|t
parameter_list|)
value|((sizeof (t) * CHAR_BIT - 1) * 302 / 1000 + 2)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_MIN
end_ifndef

begin_define
define|#
directive|define
name|CHAR_MIN
value|TYPE_MINIMUM (char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|CHAR_MAX
value|TYPE_MAXIMUM (char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCHAR_MIN
end_ifndef

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-1 - SCHAR_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|SCHAR_MAX
value|(CHAR_MAX == UCHAR_MAX ? CHAR_MAX / 2 : CHAR_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|UCHAR_MAX
value|TYPE_MAXIMUM (unsigned char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHRT_MIN
end_ifndef

begin_define
define|#
directive|define
name|SHRT_MIN
value|TYPE_MINIMUM (short int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHRT_MAX
end_ifndef

begin_define
define|#
directive|define
name|SHRT_MAX
value|TYPE_MAXIMUM (short int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|TYPE_MAXIMUM (int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MIN
end_ifndef

begin_define
define|#
directive|define
name|INT_MIN
value|TYPE_MINIMUM (int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTMAX_MAX
end_ifndef

begin_define
define|#
directive|define
name|INTMAX_MAX
value|TYPE_MAXIMUM (intmax_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTMAX_MIN
end_ifndef

begin_define
define|#
directive|define
name|INTMAX_MIN
value|TYPE_MINIMUM (intmax_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT_MAX
value|TYPE_MAXIMUM (unsigned int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_MAX
value|TYPE_MAXIMUM (long int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULONG_MAX
value|TYPE_MAXIMUM (unsigned long int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_MAX
value|TYPE_MAXIMUM (size_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SSIZE_MAX
value|TYPE_MAXIMUM (ssize_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINTMAX_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINTMAX_MAX
value|TYPE_MAXIMUM (uintmax_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OFF_T_MIN
end_ifndef

begin_define
define|#
directive|define
name|OFF_T_MIN
value|TYPE_MINIMUM (off_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OFF_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|OFF_T_MAX
value|TYPE_MAXIMUM (off_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|UID_T_MAX
value|TYPE_MAXIMUM (uid_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|GID_T_MAX
value|TYPE_MAXIMUM (gid_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PID_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|PID_T_MAX
value|TYPE_MAXIMUM (pid_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use this to suppress gcc's `...may be used before initialized' warnings. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|IF_LINT
parameter_list|(
name|Code
parameter_list|)
value|Code
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IF_LINT
parameter_list|(
name|Code
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|8
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_NORETURN
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_NORETURN
value|__attribute__ ((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED
value|__attribute__ ((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|strdupa
end_if

begin_define
define|#
directive|define
name|ASSIGN_STRDUPA
parameter_list|(
name|DEST
parameter_list|,
name|S
parameter_list|)
define|\
value|do { DEST = strdupa (S); } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSIGN_STRDUPA
parameter_list|(
name|DEST
parameter_list|,
name|S
parameter_list|)
define|\
value|do						\     {						\       const char *s_ = (S);			\       size_t len_ = strlen (s_) + 1;		\       char *tmp_dest_ = alloca (len_);		\       DEST = memcpy (tmp_dest_, (s_), len_);	\     }						\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|EOVERFLOW
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_FSEEKO
operator|&&
operator|!
name|defined
name|fseeko
end_if

begin_define
define|#
directive|define
name|fseeko
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|,
name|w
parameter_list|)
value|((o) == (long int) (o)		\ 			  ? fseek (s, o, w)		\ 			  : (errno = EOVERFLOW, -1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compute the greatest common divisor of U and V using Euclid's    algorithm.  U and V must be nonzero.  */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|gcd
parameter_list|(
name|size_t
name|u
parameter_list|,
name|size_t
name|v
parameter_list|)
block|{
do|do
block|{
name|size_t
name|t
init|=
name|u
operator|%
name|v
decl_stmt|;
name|u
operator|=
name|v
expr_stmt|;
name|v
operator|=
name|t
expr_stmt|;
block|}
do|while
condition|(
name|v
condition|)
do|;
return|return
name|u
return|;
block|}
end_function

begin_comment
comment|/* Compute the least common multiple of U and V.  U and V must be    nonzero.  There is no overflow checking, so callers should not    specify outlandish sizes.  */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|lcm
parameter_list|(
name|size_t
name|u
parameter_list|,
name|size_t
name|v
parameter_list|)
block|{
return|return
name|u
operator|*
operator|(
name|v
operator|/
name|gcd
argument_list|(
name|u
argument_list|,
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Return PTR, aligned upward to the next multiple of ALIGNMENT.    ALIGNMENT must be nonzero.  The caller must arrange for ((char *)    PTR) through ((char *) PTR + ALIGNMENT - 1) to be addressable    locations.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|ptr_align
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|alignment
parameter_list|)
block|{
name|char
modifier|*
name|p0
init|=
name|ptr
decl_stmt|;
name|char
modifier|*
name|p1
init|=
name|p0
operator|+
name|alignment
operator|-
literal|1
decl_stmt|;
return|return
name|p1
operator|-
operator|(
name|size_t
operator|)
name|p1
operator|%
name|alignment
return|;
block|}
end_function

end_unit

