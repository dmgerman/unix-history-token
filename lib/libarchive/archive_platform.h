begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2006 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_comment
comment|/* Most POSIX platforms use the 'configure' script to build config.h */
end_comment

begin_include
include|#
directive|include
file|"../config.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_comment
comment|/* Building as part of FreeBSD system requires a pre-built config.h. */
end_comment

begin_include
include|#
directive|include
file|"config_freebsd.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Warn if the library hasn't been (automatically or manually) configured. */
end_comment

begin_error
error|#
directive|error
error|Oops: No config.h and no pre-built configuration in archive_platform.h.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The config files define a lot of feature macros.  The following  * uses those macros to select/define replacements and include key  * headers as required.  */
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

begin_comment
comment|/* Try to get standard C99-style integer type definitions. */
end_comment

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

begin_elif
elif|#
directive|elif
name|HAVE_STDINT_H
end_elif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If this platform has<sys/acl.h>, acl_create(), acl_init(),  * acl_set_file(), and ACL_USER, we assume it has the rest of the  * POSIX.1e draft functions used in archive_read_extract.c.  */
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
operator|&&
name|HAVE_ACL_USER
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
value|((void)(n))
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
value|((void)(n))
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
value|((void)(n))
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

