begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* FreeBSD 5.0 and later have ACL and extattr support. */
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
name|HAVE_ACL_CREATE_ENTRY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_GET_LINK_NP
value|1
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

begin_define
define|#
directive|define
name|HAVE_ACL_USER
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EXTATTR_GET_FILE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EXTATTR_LIST_FILE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EXTATTR_SET_FD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EXTATTR_SET_FILE
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
name|HAVE_SYS_EXTATTR_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|HAVE_OPENSSL_MD5_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENSSL_RIPEMD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENSSL_SHA_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA384
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA512
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_BSDXML_H
value|1
end_define

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
name|HAVE_CHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_INT64_MAX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_INT64_MIN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_SIZE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_SSIZE_MAX
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
name|HAVE_DECL_UINT32_MAX
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_UINT64_MAX
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
name|HAVE_FCNTL
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
name|HAVE_FSEEKO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FSTAT
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
name|HAVE_FUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETPID
value|1
end_define

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
name|HAVE_LINK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LSTAT
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
name|HAVE_MD5
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MD5_H
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
name|HAVE_MKNOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PIPE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POLL_H
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
name|HAVE_READLINK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RMD160
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA256
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA256_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
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
name|HAVE_STRUCT_STAT_ST_BLKSIZE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BIRTHTIME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_FLAGS
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
name|HAVE_SYMLINK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_CDEFS_H
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
name|HAVE_SYS_SELECT_H
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

begin_undef
undef|#
directive|undef
name|HAVE_SYS_UTIME_H
end_undef

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEGM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TZSET
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
name|HAVE_UNSETENV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UTIME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VFORK
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
name|HAVE_WCSCPY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCSLEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCTOMB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WMEMCMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WMEMCPY
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
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* FreeBSD 4 and earlier lack intmax_t/uintmax_t */
end_comment

begin_if
if|#
directive|if
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

end_unit

