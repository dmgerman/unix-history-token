begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_platform_interceptors.h -----------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines macro telling whether sanitizer tools can/should intercept
end_comment

begin_comment
comment|// given library functions on a given platform.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_PLATFORM_INTERCEPTORS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_PLATFORM_INTERCEPTORS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_if
if|#
directive|if
operator|!
name|SANITIZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|SI_NOT_WINDOWS
value|1
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform_limits_posix.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SI_NOT_WINDOWS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
operator|!
name|SANITIZER_ANDROID
end_if

begin_define
define|#
directive|define
name|SI_LINUX_NOT_ANDROID
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SI_LINUX_NOT_ANDROID
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_LINUX
end_if

begin_define
define|#
directive|define
name|SI_LINUX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SI_LINUX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_MAC
end_if

begin_define
define|#
directive|define
name|SI_MAC
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SI_MAC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_IOS
end_if

begin_define
define|#
directive|define
name|SI_IOS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SI_IOS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STRCMP
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STRCASECMP
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_READ
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PREAD
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_WRITE
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PWRITE
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PREAD64
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PWRITE64
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_READV
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_WRITEV
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PREADV
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PWRITEV
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PREADV64
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PWRITEV64
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PRCTL
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_LOCALTIME_AND_FRIENDS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STRPTIME
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SCANF
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_ISOC99_SCANF
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_FREXP
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_FREXPF_FREXPL
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETPWNAM_AND_FRIENDS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETPWNAM_R_AND_FRIENDS
define|\
value|SI_MAC || SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_CLOCK_GETTIME
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETITIMER
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_TIME
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GLOB
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_WAIT
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_INET
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PTHREAD_GETSCHEDPARAM
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETADDRINFO
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETNAMEINFO
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETSOCKNAME
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETHOSTBYNAME
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETHOSTBYNAME_R
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETSOCKOPT
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_ACCEPT
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_ACCEPT4
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_MODF
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_RECVMSG
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETPEERNAME
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_IOCTL
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_INET_ATON
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SYSINFO
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_READDIR
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_READDIR64
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PTRACE
value|SI_LINUX_NOT_ANDROID&& \   (defined(__i386) || defined (__x86_64))
end_define

begin_comment
comment|// NOLINT
end_comment

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SETLOCALE
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETCWD
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GET_CURRENT_DIR_NAME
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STRTOIMAX
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_MBSTOWCS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_MBSNRTOWCS
value|SI_MAC || SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_WCSTOMBS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_WCSNRTOMBS
value|SI_MAC || SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_TCGETATTR
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_REALPATH
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_CANONICALIZE_FILE_NAME
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_CONFSTR
value|SI_MAC || SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SCHED_GETAFFINITY
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STRERROR
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STRERROR_R
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SCANDIR
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SCANDIR64
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETGROUPS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_POLL
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PPOLL
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_WORDEXP
value|SI_MAC || SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SIGWAIT
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SIGWAITINFO
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SIGTIMEDWAIT
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SIGSETOPS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SIGPENDING
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SIGPROCMASK
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_BACKTRACE
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETMNTENT
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETMNTENT_R
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STATFS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STATFS64
define|\
value|(SI_MAC&& !SI_IOS) || SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STATVFS
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_STATVFS64
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_INITGROUPS
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_ETHER
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_ETHER_R
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SHMCTL
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_RANDOM_R
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PTHREAD_ATTR_GET
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PTHREAD_ATTR_GETINHERITSCHED
define|\
value|SI_MAC || SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PTHREAD_ATTR_GETAFFINITY_NP
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_TMPNAM
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_TMPNAM_R
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_TEMPNAM
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SINCOS
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_REMQUO
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_LGAMMA
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_LGAMMA_R
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_DRAND48_R
value|SI_LINUX_NOT_ANDROID
end_define

begin_comment
comment|// FIXME: getline seems to be available on OSX 10.7
end_comment

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_GETLINE
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT__EXIT
value|SI_LINUX
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PHTREAD_MUTEX
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PTHREAD_COND
value|SI_NOT_WINDOWS
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP
value|SI_LINUX_NOT_ANDROID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
end_comment

end_unit

