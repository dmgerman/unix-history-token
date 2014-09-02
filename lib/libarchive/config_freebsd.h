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
name|HAVE_ACL_IS_TRIVIAL_NP
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
name|HAVE_ACL_SET_LINK_NP
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
name|HAVE_LIBCRYPTO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENSSL_EVP_H
value|1
end_define

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
name|HAVE_OPENSSL_SHA256_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENSSL_SHA384_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENSSL_SHA512_INIT
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
name|HAVE_SHA384
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA512
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_LIBMD
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
name|HAVE_MD5INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RIPEMD_H
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
name|HAVE_SHA1_INIT
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
name|HAVE_SHA256_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA512
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA512_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SHA512_INIT
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
name|HAVE_CHROOT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CTIME_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CTYPE_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_EXTATTR_NAMESPACE_USER
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
name|HAVE_DLFCN_H
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
name|HAVE_FDOPENDIR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FORK
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
name|HAVE_FSTATAT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FSTATFS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FSTATVFS
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
name|HAVE_FUTIMESAT
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
name|HAVE_GETGRGID_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETGRNAM_R
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
name|HAVE_GETPWNAM_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETPWUID_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETVFSBYNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GMTIME_R
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
name|HAVE_INTMAX_T
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
name|HAVE_LIBZ
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
name|HAVE_LOCALE_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LOCALTIME_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LONG_LONG_INT
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
name|HAVE_MBRTOWC
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
name|HAVE_MKNOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NL_LANGINFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_OPENAT
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
name|HAVE_POSIX_SPAWNP
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
name|HAVE_READDIR_R
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
name|HAVE_READLINKAT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REGEX_H
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
name|HAVE_SETLOCALE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGACTION
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
name|HAVE_SPAWN_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STATFS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STATVFS
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
name|HAVE_STRERROR_R
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

begin_define
define|#
directive|define
name|HAVE_STRUCT_STATFS_F_NAMEMAX
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
name|HAVE_STRUCT_STAT_ST_BLKSIZE
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
name|HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_GMTOFF
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
name|HAVE_SYS_MOUNT_H
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
name|HAVE_SYS_POLL_H
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
name|HAVE_SYS_STATVFS_H
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
name|HAVE_SYS_UTSNAME_H
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
name|HAVE_TIMEGM
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
name|HAVE_TZSET
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
name|HAVE_UNSETENV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_LONG_LONG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_LONG_LONG_INT
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
name|HAVE_VPRINTF
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
name|HAVE_WCHAR_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCRTOMB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCSCMP
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
name|HAVE_WCTYPE_H
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

begin_comment
comment|/* FreeBSD defines for archive_hash.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_MD5_OPENSSL
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_RMD160_OPENSSL
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA1_OPENSSL
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA256_OPENSSL
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA384_OPENSSL
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA512_OPENSSL
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_MD5_LIBMD
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA1_LIBMD
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA256_LIBMD
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_SHA512_LIBMD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

