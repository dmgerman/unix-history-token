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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
end_comment

end_unit

