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

begin_comment
comment|/* FreeBSD-specific definitions. */
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

begin_comment
comment|/*  * Note that SUSv3 says that inttypes.h includes stdint.h.  * Since inttypes.h predates stdint.h, it's safest to always  * use inttypes.h instead of stdint.h.  */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/* For int64_t, etc. */
end_comment

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
name|HAVE_POSIX_ACL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_CHFLAGS
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
name|HAVE_STRERROR_R
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_FILE_FORMAT
value|EFTYPE
end_define

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_PROGRAMMER
value|EINVAL
end_define

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_MISC
value|(-1)
end_define

begin_comment
comment|/* Fetch/set high-resolution time data through a struct stat pointer. */
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

begin_comment
comment|/*  * Older versions of inttypes.h don't have INT64_MAX, etc.  Since  * SUSv3 requires them to be macros when they are defined, we can  * easily test for and define them here if necessary.  Someday, we  * won't have to worry about non-C99-compliant systems.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT64_MAX
end_ifndef

begin_comment
comment|/* XXX Is this really necessary? XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|INT64_MAX
value|0x7fffffffffffffffLL
end_define

begin_define
define|#
directive|define
name|UINT64_MAX
value|0xffffffffffffffffULL
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __alpha__ */
end_comment

begin_define
define|#
directive|define
name|INT64_MAX
value|0x7fffffffffffffffL
end_define

begin_define
define|#
directive|define
name|UINT64_MAX
value|0xffffffffffffffffUL
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
comment|/* ! INT64_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __FreeBSD__ */
end_comment

begin_comment
comment|/* No non-FreeBSD platform will have __FBSDID, so just define it here. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

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

begin_comment
comment|/* Linux */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LINUX
end_ifdef

begin_define
define|#
directive|define
name|_FILE_OFFSET_BITS
value|64
end_define

begin_comment
comment|/* Needed for 64-bit file size handling. */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_FILE_FORMAT
value|EILSEQ
end_define

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_PROGRAMMER
value|EINVAL
end_define

begin_define
define|#
directive|define
name|ARCHIVE_ERRNO_MISC
value|(-1)
end_define

begin_define
define|#
directive|define
name|HAVE_EXT2FS_EXT2_FS_H
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
name|HAVE_STRERROR_R
value|1
end_define

begin_define
define|#
directive|define
name|STRERROR_R_CHAR_P
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRUCT_STAT_TIMESPEC
end_ifdef

begin_comment
comment|/* Fetch the nanosecond portion of the timestamp from a struct stat pointer. */
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
comment|/* High-res timestamps aren't available, so just use stubs here. */
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

begin_comment
comment|/*  * XXX TODO: Use autoconf to handle non-FreeBSD platforms.  *  * #if !defined(__FreeBSD__)  *    #include "config.h"  * #endif  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ARCHIVE_H_INCLUDED */
end_comment

end_unit

