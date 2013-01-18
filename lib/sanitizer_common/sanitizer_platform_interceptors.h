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

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|SI_NOT_WINDOWS
value|1
end_define

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
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ANDROID
argument_list|)
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
value|SI_LINUX_NOT_ANDROID
end_define

begin_define
define|#
directive|define
name|SANITIZER_INTERCEPT_SCANF
value|1
end_define

end_unit

