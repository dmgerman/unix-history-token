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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not having a config.h of some sort is a serious problem. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Include "dirent.h" (or its equivalent on several different platforms).  *  * This is slightly modified from the GNU autoconf recipe.  * In particular, FreeBSD includes d_namlen in its dirent structure,  * so my configure script includes an explicit test for the d_namlen  * field.  */
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

begin_elif
elif|#
directive|elif
name|HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
end_elif

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

begin_elif
elif|#
directive|elif
name|HAVE_STRUCT_STAT_ST_MTIME_N
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_ctime_n
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_mtime_n
end_define

begin_elif
elif|#
directive|elif
name|HAVE_STRUCT_STAT_ST_UMTIME
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_uctime * 1000
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_umtime * 1000
end_define

begin_elif
elif|#
directive|elif
name|HAVE_STRUCT_STAT_ST_MTIME_USEC
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_STAT_CTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_ctime_usec * 1000
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STAT_MTIME_NANOS
parameter_list|(
name|st
parameter_list|)
value|(st)->st_mtime_usec * 1000
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

begin_comment
comment|/* How to mark functions that don't return. */
end_comment

begin_comment
comment|/* This facilitates use of some newer static code analysis tools. */
end_comment

begin_undef
undef|#
directive|undef
name|__LA_DEAD
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>
literal|2
operator|||
expr|\
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|5
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|__LA_DEAD
value|__attribute__((__noreturn__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__LA_DEAD
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
name|_WIN32
argument_list|)
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
file|"bsdtar_windows.h"
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
comment|/* !BSDTAR_PLATFORM_H_INCLUDED */
end_comment

end_unit

