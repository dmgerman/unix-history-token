begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This header is the first thing included in any of the libarchive  * source files.  As far as possible, platform-specific issues should  * be dealt with here and not within individual source files.  I'm  * actively trying to minimize #if blocks within the main source,  * since they obfuscate the code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_PLATFORM_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_PLATFORM_H_INCLUDED
end_define

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* A default configuration for FreeBSD, used if there is no config.h. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_if
if|#
directive|if
name|__FreeBSD__
operator|>
literal|4
end_if

begin_define
define|#
directive|define
name|HAVE_ACL_CREATE_ENTRY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_SET_FD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_SET_FD_NP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_SET_FILE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_BZLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CHFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EFTYPE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EILSEQ
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHDIR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHMOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MALLOC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKDIR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKFIFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_RDEV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_ACL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ZLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__FreeBSD__ */
end_comment

begin_comment
comment|/* Warn if the library hasn't been (automatically or manually) configured. */
end_comment

begin_error
error|#
directive|error
error|Oops: No config.h and no built-in configuration in archive_platform.h.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__FreeBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_CONFIG_H */
end_comment

begin_comment
comment|/* No non-FreeBSD platform will have __FBSDID, so just define it here. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* For __FBSDID */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|a
parameter_list|)
end_define

begin_comment
comment|/* null */
end_comment

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

begin_comment
comment|/* FreeBSD 4 and earlier lack intmax_t/uintmax_t */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|<
literal|5
end_if

begin_define
define|#
directive|define
name|intmax_t
value|int64_t
end_define

begin_define
define|#
directive|define
name|uintmax_t
value|uint64_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If this platform has<sys/acl.h>, acl_create(), acl_init(), and  * acl_set_file(), we assume it has the rest of the POSIX.1e draft  * functions used in archive_read_extract.c.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_ACL_H
operator|&&
name|HAVE_ACL_CREATE_ENTRY
operator|&&
name|HAVE_ACL_INIT
operator|&&
name|HAVE_ACL_SET_FILE
end_if

begin_define
define|#
directive|define
name|HAVE_POSIX_ACL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If we can't restore metadata using a file descriptor, then  * for compatibility's sake, close files before trying to restore metadata.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FCHMOD
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_FUTIMES
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_ACL_SET_FD
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_ACL_SET_FD_NP
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_FCHOWN
argument_list|)
end_if

begin_define
define|#
directive|define
name|CAN_RESTORE_METADATA_FD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set up defaults for internal error codes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_ERRNO_FILE_FORMAT
end_ifndef

begin_if
if|#
directive|if
name|HAVE_EFTYPE
end_if

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_FILE_FORMAT
value|EFTYPE
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_EILSEQ
end_if

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_FILE_FORMAT
value|EILSEQ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_FILE_FORMAT
value|EINVAL
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_ERRNO_PROGRAMMER
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_PROGRAMMER
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_ERRNO_MISC
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_MISC
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Select the best way to set/get hi-res timestamps. */
end_comment

begin_if
if|#
directive|if
name|HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC
end_if

begin_comment
comment|/* FreeBSD uses "timespec" members. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_STAT_ATIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_atimespec.tv_nsec
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_ctimespec.tv_nsec
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_mtimespec.tv_nsec
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_ATIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
value|(st)->st_atimespec.tv_nsec = (n)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_CTIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
value|(st)->st_ctimespec.tv_nsec = (n)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_MTIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
value|(st)->st_mtimespec.tv_nsec = (n)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
end_if

begin_comment
comment|/* Linux uses "tim" members. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_STAT_ATIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
value|(pstat)->st_atim.tv_nsec
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
value|(pstat)->st_ctim.tv_nsec
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
value|(pstat)->st_mtim.tv_nsec
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_ATIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
value|(st)->st_atim.tv_nsec = (n)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_CTIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
value|(st)->st_ctim.tv_nsec = (n)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_MTIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
value|(st)->st_mtim.tv_nsec = (n)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If we can't find a better way, just use stubs. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_STAT_ATIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_ATIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_CTIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_SET_MTIME_NANOS
parameter_list|(
name|st
parameter_list|,
name|n
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ARCHIVE_H_INCLUDED */
end_comment

end_unit

