begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_intercepted_functions.h ----------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ASan-private header containing prototypes for wrapper functions and wrappers
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_INTERCEPTED_FUNCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INTERCEPTED_FUNCTIONS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_platform_interceptors.h"
end_include

begin_comment
comment|// Use macro to describe if specific function should be
end_comment

begin_comment
comment|// intercepted on a given platform.
end_comment

begin_if
if|#
directive|if
operator|!
name|SANITIZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_ATOLL_AND_STRTOLL
value|1
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT__LONGJMP
value|1
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_STRDUP
value|1
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_PTHREAD_CREATE
value|1
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_MLOCKX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_ATOLL_AND_STRTOLL
value|0
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT__LONGJMP
value|0
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_STRDUP
value|0
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_PTHREAD_CREATE
value|0
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_MLOCKX
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
name|ASAN_USE_ALIAS_ATTRIBUTE_FOR_INDEX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_USE_ALIAS_ATTRIBUTE_FOR_INDEX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|SANITIZER_MAC
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_STRNLEN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_STRNLEN
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
name|ASAN_INTERCEPT_SWAPCONTEXT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_SWAPCONTEXT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|SANITIZER_ANDROID
operator|&&
operator|!
name|SANITIZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_SIGNAL_AND_SIGACTION
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_SIGNAL_AND_SIGACTION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|SANITIZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_SIGLONGJMP
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_SIGLONGJMP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ASAN_HAS_EXCEPTIONS
operator|&&
operator|!
name|SANITIZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT___CXA_THROW
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT___CXA_THROW
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|SANITIZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT___CXA_ATEXIT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT___CXA_ATEXIT
value|0
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
comment|// ASAN_INTERCEPTED_FUNCTIONS_H
end_comment

end_unit

