begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This header is the first thing included in any of the bsdtar  * source files.  As far as possible, platform-specific issues should  * be dealt with here and not within individual source files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSDTAR_PLATFORM_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|BSDTAR_PLATFORM_H_INCLUDED
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

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_comment
comment|/* For _PATH_DEFTAPE */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHFLAGS
value|1
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

begin_comment
comment|/* nl_langinfo supports D_MD_ORDER (FreeBSD extension) */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_LANGINFO_D_MD_ORDER
value|1
end_define

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
name|HAVE_GETOPT_LONG
value|1
end_define

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
comment|/*  * We need to be able to display a filesize using printf().  The type  * and format string here must be compatible with one another and  * large enough for any file.  */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/* for uintmax_t, if it exists */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UINTMAX_MAX
end_ifdef

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_TYPE
value|uintmax_t
end_define

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_PRINTF
value|"%ju"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_TYPE
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_PRINTF
value|"%llu"
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
name|linux
end_ifdef

begin_define
define|#
directive|define
name|_FILE_OFFSET_BITS
value|64
end_define

begin_comment
comment|/* For a 64-bit off_t */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/* for uintmax_t */
end_comment

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_TYPE
value|uintmax_t
end_define

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_PRINTF
value|"%ju"
end_define

begin_comment
comment|/* XXX get fnmatch GNU extensions (FNM_LEADING_DIR)  * (should probably use AC_FUNC_FNMATCH_GNU once using autoconf...) */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_define
define|#
directive|define
name|_PATH_DEFTAPE
value|"/dev/st0"
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT_LONG
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
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
value|(pstat)->st_mtim.tv_nsec
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
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|pstat
parameter_list|)
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

