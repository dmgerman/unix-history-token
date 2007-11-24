begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* A default configuration for FreeBSD, used if there is no config.h. */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* __FreeBSD_version */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"bsdtar"
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
name|HAVE_ACL_GET_PERM
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_GET_PERM_NP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_PERMSET_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_USER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|HAVE_ATTR_XATTR_H
end_undef

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
name|HAVE_DIRENT_D_NAMLEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_D_MD_ORDER
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_EXT2FS_EXT2_FS_H
end_undef

begin_define
define|#
directive|define
name|HAVE_FCHDIR
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
name|HAVE_FNMATCH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FNMATCH_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FNM_LEADING_DIR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT_LONG
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETXATTR
end_undef

begin_define
define|#
directive|define
name|HAVE_GRP_H
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
name|HAVE_LANGINFO_H
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_LGETXATTR
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_LIBACL
end_undef

begin_define
define|#
directive|define
name|HAVE_LIBARCHIVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBBZ2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBZ
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_LINUX_EXT2_FS_H
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_LINUX_FS_H
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_LISTXATTR
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_LLISTXATTR
end_undef

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|450002
end_if

begin_comment
comment|/* nl_langinfo introduced */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_LANGINFO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDARG_H
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
name|HAVE_STRFTIME
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

begin_undef
undef|#
directive|undef
name|HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
end_undef

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
name|HAVE_SYS_PARAM_H
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
name|HAVE_TIME_H
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
name|HAVE_UINTMAX_T
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
name|HAVE_UNSIGNED_LONG_LONG
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ZLIB_H
value|1
end_define

begin_undef
undef|#
directive|undef
name|MAJOR_IN_MKDEV
end_undef

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

end_unit

