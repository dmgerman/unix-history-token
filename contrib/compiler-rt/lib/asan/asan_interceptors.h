begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_interceptors.h -------------------------------------*- C++ -*-===//
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
comment|// ASan-private header for asan_interceptors.cc
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_INTERCEPTORS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INTERCEPTORS_H
end_define

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_include
include|#
directive|include
file|"interception/interception.h"
end_include

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
name|ASAN_INTERCEPT_FORK
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
name|ASAN_INTERCEPT_FORK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_FREEBSD
operator|||
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
name|SANITIZER_LINUX
operator|&&
operator|!
name|SANITIZER_ANDROID
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT___LONGJMP_CHK
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT___LONGJMP_CHK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Android bug: https://code.google.com/p/android/issues/detail?id=61799
end_comment

begin_if
if|#
directive|if
name|ASAN_HAS_EXCEPTIONS
operator|&&
operator|!
name|SANITIZER_WINDOWS
operator|&&
expr|\
operator|!
operator|(
name|SANITIZER_ANDROID
operator|&&
name|defined
argument_list|(
name|__i386
argument_list|)
operator|)
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
name|ASAN_INTERCEPT___STRDUP
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_INTERCEPT___STRDUP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|DECLARE_REAL
argument_list|(
argument|int
argument_list|,
argument|memcmp
argument_list|,
argument|const void *a1
argument_list|,
argument|const void *a2
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|void*
argument_list|,
argument|memcpy
argument_list|,
argument|void *to
argument_list|,
argument|const void *from
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|void*
argument_list|,
argument|memset
argument_list|,
argument|void *block
argument_list|,
argument|int c
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|char*
argument_list|,
argument|strchr
argument_list|,
argument|const char *str
argument_list|,
argument|int c
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|SIZE_T
argument_list|,
argument|strlen
argument_list|,
argument|const char *s
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|char*
argument_list|,
argument|strncpy
argument_list|,
argument|char *to
argument_list|,
argument|const char *from
argument_list|,
argument|uptr size
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|uptr
argument_list|,
argument|strnlen
argument_list|,
argument|const char *s
argument_list|,
argument|uptr maxlen
argument_list|)
end_macro

begin_macro
name|DECLARE_REAL
argument_list|(
argument|char*
argument_list|,
argument|strstr
argument_list|,
argument|const char *s1
argument_list|,
argument|const char *s2
argument_list|)
end_macro

begin_struct_decl
struct_decl|struct
name|sigaction
struct_decl|;
end_struct_decl

begin_macro
name|DECLARE_REAL
argument_list|(
argument|int
argument_list|,
argument|sigaction
argument_list|,
argument|int signum
argument_list|,
argument|const struct sigaction *act
argument_list|,
argument|struct sigaction *oldact
argument_list|)
end_macro

begin_if
if|#
directive|if
operator|!
name|SANITIZER_MAC
end_if

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_FUNC
parameter_list|(
name|name
parameter_list|)
define|\
value|do {                                                                   \     if ((!INTERCEPT_FUNCTION(name) || !REAL(name)))                      \       VReport(1, "AddressSanitizer: failed to intercept '" #name "'\n"); \   } while (0)
end_define

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_FUNC_VER
parameter_list|(
name|name
parameter_list|,
name|ver
parameter_list|)
define|\
value|do {                                                                         \     if ((!INTERCEPT_FUNCTION_VER(name, ver) || !REAL(name)))                   \       VReport(                                                                 \           1, "AddressSanitizer: failed to intercept '" #name "@@" #ver "'\n"); \   } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// OS X interceptors don't need to be initialized with INTERCEPT_FUNCTION.
end_comment

begin_define
define|#
directive|define
name|ASAN_INTERCEPT_FUNC
parameter_list|(
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_MAC
end_comment

begin_decl_stmt
name|namespace
name|__asan
block|{
name|void
name|InitializeAsanInterceptors
parameter_list|()
function_decl|;
name|void
name|InitializePlatformInterceptors
parameter_list|()
function_decl|;
define|#
directive|define
name|ENSURE_ASAN_INITED
parameter_list|()
value|do { \   CHECK(!asan_init_is_running); \   if (UNLIKELY(!asan_inited)) { \     AsanInitFromRtl(); \   } \ } while (0)
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_INTERCEPTORS_H
end_comment

end_unit

