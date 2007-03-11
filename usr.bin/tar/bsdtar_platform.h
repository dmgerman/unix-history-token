begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"../config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

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
comment|/* !__FreeBSD__ */
end_comment

begin_comment
comment|/* Warn if bsdtar hasn't been (automatically or manually) configured. */
end_comment

begin_error
error|#
directive|error
error|Oops: No config.h and no built-in configuration in bsdtar_platform.h.
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBARCHIVE
end_ifdef

begin_comment
comment|/* If we're using the platform libarchive, include system headers. */
end_comment

begin_include
include|#
directive|include
file|<archive.h>
end_include

begin_include
include|#
directive|include
file|<archive_entry.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Otherwise, include user headers. */
end_comment

begin_include
include|#
directive|include
file|"archive.h"
end_include

begin_include
include|#
directive|include
file|"archive_entry.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Does this platform have complete-looking POSIX-style ACL support,  * including some variant of the acl_get_perm() function (which was  * omitted from the POSIX.1e draft)?  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_ACL_H
operator|&&
name|HAVE_ACL_PERMSET_T
operator|&&
name|HAVE_ACL_USER
end_if

begin_if
if|#
directive|if
name|HAVE_ACL_GET_PERM
operator|||
name|HAVE_ACL_GET_PERM_NP
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBACL
end_ifdef

begin_include
include|#
directive|include
file|<acl/libacl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_ACL_GET_PERM
end_if

begin_define
define|#
directive|define
name|ACL_GET_PERM
value|acl_get_perm
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_ACL_GET_PERM_NP
end_if

begin_define
define|#
directive|define
name|ACL_GET_PERM
value|acl_get_perm_np
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
comment|/*  * Include "dirent.h" (or it's equivalent on several different platforms).  *  * This is slightly modified from the GNU autoconf recipe.  * In particular, FreeBSD includes d_namlen in it's dirent structure,  * so my configure script includes an explicit test for the d_namlen  * field.  */
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

begin_if
if|#
directive|if
name|HAVE_DIRENT_D_NAMLEN
end_if

begin_define
define|#
directive|define
name|DIRENT_NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|(dirent)->d_namlen
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIRENT_NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|strlen((dirent)->d_name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_define
define|#
directive|define
name|DIRENT_NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|(dirent)->d_namlen
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We need to be able to display a filesize using printf().  The type  * and format string here must be compatible with one another and  * large enough for any file.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_UINTMAX_T
end_if

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

begin_if
if|#
directive|if
name|HAVE_UNSIGNED_LONG_LONG
end_if

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_TYPE
value|unsigned long
end_define

begin_define
define|#
directive|define
name|BSDTAR_FILESIZE_PRINTF
value|"%lu"
end_define

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
name|HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC
end_if

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

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
end_if

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_ctim.tv_nsec
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_mtim.tv_nsec
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(0)
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
comment|/* !BSDTAR_PLATFORM_H_INCLUDED */
end_comment

end_unit

