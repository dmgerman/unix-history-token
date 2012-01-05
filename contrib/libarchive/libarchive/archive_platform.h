begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* !!ONLY FOR USE INTERNALLY TO LIBARCHIVE!! */
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
comment|/* archive.h and archive_entry.h require this. */
end_comment

begin_define
define|#
directive|define
name|__LIBARCHIVE_BUILD
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLATFORM_CONFIG_H
argument_list|)
end_if

begin_comment
comment|/* Use hand-built config.h in environments that need it. */
end_comment

begin_include
include|#
directive|include
include|PLATFORM_CONFIG_H
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_elif

begin_comment
comment|/* Most POSIX platforms use the 'configure' script to build config.h */
end_comment

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
comment|/* It should be possible to get rid of this by extending the feature-test  * macros to cover Windows API functions, probably along with non-trivial  * refactoring of code to find structures that sit more cleanly on top of  * either Windows or Posix APIs. */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"archive_windows.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The config files define a lot of feature macros.  The following  * uses those macros to select/define replacements and include key  * headers as required.  */
end_comment

begin_comment
comment|/* Get a real definition for __FBSDID if we can */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_CDEFS_H
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If not, define it so as to avoid dangling semicolons. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FBSDID
end_ifndef

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|a
parameter_list|)
value|struct _undefined_hack
end_define

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

begin_comment
comment|/* Borland warns about its own constants!  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_if
if|#
directive|if
name|HAVE_DECL_UINT64_MAX
end_if

begin_undef
undef|#
directive|undef
name|UINT64_MAX
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_DECL_UINT64_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_UINT64_MIN
end_if

begin_undef
undef|#
directive|undef
name|UINT64_MIN
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_DECL_UINT64_MIN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_INT64_MAX
end_if

begin_undef
undef|#
directive|undef
name|INT64_MAX
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_DECL_INT64_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_INT64_MIN
end_if

begin_undef
undef|#
directive|undef
name|INT64_MIN
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_DECL_INT64_MIN
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
comment|/* Some platforms lack the standard *_MAX definitions. */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_SIZE_MAX
end_if

begin_define
define|#
directive|define
name|SIZE_MAX
value|(~(size_t)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_SSIZE_MAX
end_if

begin_define
define|#
directive|define
name|SSIZE_MAX
value|((ssize_t)(SIZE_MAX>> 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_UINT32_MAX
end_if

begin_define
define|#
directive|define
name|UINT32_MAX
value|(~(uint32_t)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_UINT64_MAX
end_if

begin_define
define|#
directive|define
name|UINT64_MAX
value|(~(uint64_t)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_INT64_MAX
end_if

begin_define
define|#
directive|define
name|INT64_MAX
value|((int64_t)(UINT64_MAX>> 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_INT64_MIN
end_if

begin_define
define|#
directive|define
name|INT64_MIN
value|((int64_t)(~INT64_MAX))
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ARCHIVE_PLATFORM_H_INCLUDED */
end_comment

end_unit

