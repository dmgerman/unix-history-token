begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Trevor Drake  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_PLATFORM_H_ANDROID_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_PLATFORM_H_ANDROID_INCLUDED
end_define

begin_include
include|#
directive|include
file|<android/api-level.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__ANDROID_API__
end_ifdef

begin_if
if|#
directive|if
name|__ANDROID_API__
operator|>
literal|20
end_if

begin_define
define|#
directive|define
name|HAVE_FSTATVFS
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
name|HAVE_TIMEGM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_XATTR_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LINUX_FIEMAP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_STATVFS_H
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
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_INTMAX_MIN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_INTMAX_MAX
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
name|HAVE_DECL_UINTMAX_MAX
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
name|HAVE_DIRFD
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
name|HAVE_FGETXATTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FLISTXATTR
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
name|HAVE_FSETXATTR
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
name|HAVE_FTRUNCATE
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
name|HAVE_GETXATTR
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
name|HAVE_LCHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LGETXATTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBLZMA
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
name|HAVE_LINUX_FS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LINUX_MAGIC_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LINUX_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LISTXATTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LLISTXATTR
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
name|HAVE_LSETXATTR
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
name|HAVE_PTHREAD_H
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
name|HAVE_STATFS
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
name|HAVE_STRUCT_STAT_ST_BLKSIZE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_MTIME_NSEC
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
name|HAVE_SYS_STATFS_H
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
name|HAVE_SYS_VFS_H
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
name|HAVE_UTIMENSAT
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
name|HAVE_ARC4RANDOM_BUF
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
name|LSTAT_FOLLOWS_SLASHED_SYMLINK
value|1
end_define

begin_define
define|#
directive|define
name|SIZEOF_WCHAR_T
value|4
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
name|STRERROR_R_CHAR_P
value|1
end_define

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

