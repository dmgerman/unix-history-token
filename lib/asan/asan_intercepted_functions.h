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

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_expr_stmt
name|using
name|__sanitizer
operator|::
name|uptr
expr_stmt|;
end_expr_stmt

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
name|defined
argument_list|(
name|_WIN32
argument_list|)
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
name|ASAN_INTERCEPT_STRCASECMP_AND_STRNCASECMP
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
name|ASAN_INTERCEPT_STRCASECMP_AND_STRNCASECMP
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
name|defined
argument_list|(
name|__linux__
argument_list|)
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
name|defined
argument_list|(
name|__APPLE__
argument_list|)
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
name|defined
argument_list|(
name|ANDROID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
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

begin_comment
comment|// On Darwin siglongjmp tailcalls longjmp, so we don't want to intercept it
end_comment

begin_comment
comment|// there.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
name|MAC_INTERPOSE_FUNCTIONS
operator|)
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
name|defined
argument_list|(
name|_WIN32
argument_list|)
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

begin_define
define|#
directive|define
name|DECLARE_FUNCTION_AND_WRAPPER
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ret_type func(__VA_ARGS__); \   ret_type WRAP(func)(__VA_ARGS__)
end_define

begin_comment
comment|// Use extern declarations of intercepted functions on Mac and Windows
end_comment

begin_comment
comment|// to avoid including system headers.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_DLL
argument_list|)
operator|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
comment|// signal.h
if|#
directive|if
name|ASAN_INTERCEPT_SIGNAL_AND_SIGACTION
struct_decl|struct
name|sigaction
struct_decl|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|sigaction
argument_list|,
argument|int sig
argument_list|,
argument|const struct sigaction *act
argument_list|,
argument|struct sigaction *oldact
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void*
argument_list|,
argument|signal
argument_list|,
argument|int signum
argument_list|,
argument|void *handler
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|// setjmp.h
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|longjmp
argument_list|,
argument|void *env
argument_list|,
argument|int value
argument_list|)
empty_stmt|;
if|#
directive|if
name|ASAN_INTERCEPT__LONGJMP
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|_longjmp
argument_list|,
argument|void *env
argument_list|,
argument|int value
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|ASAN_INTERCEPT_SIGLONGJMP
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|siglongjmp
argument_list|,
argument|void *env
argument_list|,
argument|int value
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|ASAN_INTERCEPT___CXA_THROW
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|void
argument_list|,
name|__cxa_throw
argument_list|,
name|void
operator|*
name|a
argument_list|,
name|void
operator|*
name|b
argument_list|,
name|void
operator|*
name|c
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// string.h / strings.h
name|DECLARE_FUNCTION_AND_WRAPPER
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
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void*
argument_list|,
argument|memmove
argument_list|,
argument|void *to
argument_list|,
argument|const void *from
argument_list|,
argument|uptr size
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
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
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
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
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|char*
argument_list|,
argument|strchr
argument_list|,
argument|const char *str
argument_list|,
argument|int c
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|char
operator|*
argument_list|,
name|strcat
argument_list|,
comment|/* NOLINT */
name|char
operator|*
name|to
argument_list|,
specifier|const
name|char
operator|*
name|from
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|char*
argument_list|,
argument|strncat
argument_list|,
argument|char *to
argument_list|,
argument|const char* from
argument_list|,
argument|uptr size
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|char
operator|*
argument_list|,
name|strcpy
argument_list|,
comment|/* NOLINT */
name|char
operator|*
name|to
argument_list|,
specifier|const
name|char
operator|*
name|from
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|char*
argument_list|,
argument|strncpy
argument_list|,
argument|char *to
argument_list|,
argument|const char* from
argument_list|,
argument|uptr size
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|strcmp
argument_list|,
specifier|const
name|char
operator|*
name|s1
argument_list|,
specifier|const
name|char
operator|*
name|s2
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|strncmp
argument_list|,
argument|const char *s1
argument_list|,
argument|const char* s2
argument_list|,
argument|uptr size
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|uptr
argument_list|,
name|strlen
argument_list|,
specifier|const
name|char
operator|*
name|s
argument_list|)
expr_stmt|;
if|#
directive|if
name|ASAN_INTERCEPT_STRCASECMP_AND_STRNCASECMP
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|strcasecmp
argument_list|,
specifier|const
name|char
operator|*
name|s1
argument_list|,
specifier|const
name|char
operator|*
name|s2
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|strncasecmp
argument_list|,
argument|const char *s1
argument_list|,
argument|const char *s2
argument_list|,
argument|uptr n
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|ASAN_INTERCEPT_STRDUP
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|char
operator|*
argument_list|,
name|strdup
argument_list|,
specifier|const
name|char
operator|*
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|ASAN_INTERCEPT_STRNLEN
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|uptr
argument_list|,
argument|strnlen
argument_list|,
argument|const char *s
argument_list|,
argument|uptr maxlen
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|ASAN_INTERCEPT_INDEX
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|char*
argument_list|,
argument|index
argument_list|,
argument|const char *string
argument_list|,
argument|int c
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|// stdlib.h
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|atoi
argument_list|,
specifier|const
name|char
operator|*
name|nptr
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|long
argument_list|,
name|atol
argument_list|,
specifier|const
name|char
operator|*
name|nptr
argument_list|)
expr_stmt|;
comment|// NOLINT
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|long
argument_list|,
argument|strtol
argument_list|,
argument|const char *nptr
argument_list|,
argument|char **endptr
argument_list|,
argument|int base
argument_list|)
empty_stmt|;
comment|// NOLINT
if|#
directive|if
name|ASAN_INTERCEPT_ATOLL_AND_STRTOLL
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|long long
argument_list|,
argument|atoll
argument_list|,
argument|const char *nptr
argument_list|)
empty_stmt|;
comment|// NOLINT
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|long long
argument_list|,
argument|strtoll
argument_list|,
argument|const char *nptr
argument_list|,
argument|char **endptr
argument_list|,
argument|int base
argument_list|)
empty_stmt|;
comment|// NOLINT
endif|#
directive|endif
comment|// unistd.h
if|#
directive|if
name|SANITIZER_INTERCEPT_READ
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|SSIZE_T
argument_list|,
argument|read
argument_list|,
argument|int fd
argument_list|,
argument|void *buf
argument_list|,
argument|SIZE_T count
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|SANITIZER_INTERCEPT_PREAD
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|SSIZE_T
argument_list|,
argument|pread
argument_list|,
argument|int fd
argument_list|,
argument|void *buf
argument_list|,
argument|SIZE_T count
argument_list|,
argument|OFF_T offset
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|SANITIZER_INTERCEPT_PREAD64
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|SSIZE_T
argument_list|,
argument|pread64
argument_list|,
argument|int fd
argument_list|,
argument|void *buf
argument_list|,
argument|SIZE_T count
argument_list|,
argument|OFF64_T offset
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|SANITIZER_INTERCEPT_WRITE
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|SSIZE_T
argument_list|,
argument|write
argument_list|,
argument|int fd
argument_list|,
argument|void *ptr
argument_list|,
argument|SIZE_T count
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|SANITIZER_INTERCEPT_PWRITE
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|SSIZE_T
argument_list|,
argument|pwrite
argument_list|,
argument|int fd
argument_list|,
argument|void *ptr
argument_list|,
argument|SIZE_T count
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|#
directive|if
name|ASAN_INTERCEPT_MLOCKX
comment|// mlock/munlock
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|mlock
argument_list|,
argument|const void *addr
argument_list|,
argument|SIZE_T len
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|munlock
argument_list|,
argument|const void *addr
argument_list|,
argument|SIZE_T len
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|mlockall
argument_list|,
argument|int flags
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|munlockall
argument_list|,
name|void
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Windows threads.
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
name|void
modifier|*
name|__stdcall
name|CreateThread
parameter_list|(
name|void
modifier|*
name|sec
parameter_list|,
name|uptr
name|st
parameter_list|,
name|void
modifier|*
name|start
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|DWORD
name|fl
parameter_list|,
name|DWORD
modifier|*
name|id
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// Posix threads.
if|#
directive|if
name|ASAN_INTERCEPT_PTHREAD_CREATE
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|pthread_create
argument_list|,
name|void
operator|*
name|thread
argument_list|,
name|void
operator|*
name|attr
argument_list|,
name|void
operator|*
call|(
modifier|*
name|start_routine
call|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|void
operator|*
name|arg
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
typedef|typedef
name|void
modifier|*
name|pthread_workqueue_t
typedef|;
typedef|typedef
name|void
modifier|*
name|pthread_workitem_handle_t
typedef|;
typedef|typedef
name|void
modifier|*
name|dispatch_group_t
typedef|;
typedef|typedef
name|void
modifier|*
name|dispatch_queue_t
typedef|;
typedef|typedef
name|void
modifier|*
name|dispatch_source_t
typedef|;
typedef|typedef
name|u64
name|dispatch_time_t
typedef|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|dispatch_function_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|worker_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
typedef|typedef
name|void
modifier|*
name|CFStringRef
typedef|;
typedef|typedef
name|void
modifier|*
name|CFAllocatorRef
typedef|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_async_f
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void *ctxt
argument_list|,
argument|dispatch_function_t func
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_sync_f
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void *ctxt
argument_list|,
argument|dispatch_function_t func
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_after_f
argument_list|,
argument|dispatch_time_t when
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void *ctxt
argument_list|,
argument|dispatch_function_t func
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_barrier_async_f
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void *ctxt
argument_list|,
argument|dispatch_function_t func
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_group_async_f
argument_list|,
argument|dispatch_group_t group
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void *ctxt
argument_list|,
argument|dispatch_function_t func
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|void
argument_list|,
name|__CFInitialize
argument_list|,
name|void
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|CFStringRef
argument_list|,
argument|CFStringCreateCopy
argument_list|,
argument|CFAllocatorRef alloc
argument_list|,
argument|CFStringRef str
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|void
argument_list|,
name|free
argument_list|,
name|void
operator|*
name|ptr
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|vscanf
argument_list|,
argument|const char *format
argument_list|,
argument|va_list ap
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|vsscanf
argument_list|,
argument|const char *str
argument_list|,
argument|const char *format
argument_list|,
argument|va_list ap
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|int
argument_list|,
argument|vfscanf
argument_list|,
argument|void *stream
argument_list|,
argument|const char *format
argument_list|,
argument|va_list ap
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|scanf
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|fscanf
argument_list|,
name|void
operator|*
name|stream
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
expr_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
name|int
argument_list|,
name|sscanf
argument_list|,
comment|// NOLINT
specifier|const
name|char
operator|*
name|str
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
expr_stmt|;
if|#
directive|if
name|MAC_INTERPOSE_FUNCTIONS
operator|&&
operator|!
name|defined
argument_list|(
name|MISSING_BLOCKS_SUPPORT
argument_list|)
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_group_async
argument_list|,
argument|dispatch_group_t dg
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void (^work)(void)
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_async
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void (^work)(void)
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_after
argument_list|,
argument|dispatch_queue_t dq
argument_list|,
argument|void (^work)(void)
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_source_set_event_handler
argument_list|,
argument|dispatch_source_t ds
argument_list|,
argument|void (^work)(void)
argument_list|)
empty_stmt|;
name|DECLARE_FUNCTION_AND_WRAPPER
argument_list|(
argument|void
argument_list|,
argument|dispatch_source_set_cancel_handler
argument_list|,
argument|dispatch_source_t ds
argument_list|,
argument|void (^work)(void)
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|// MAC_INTERPOSE_FUNCTIONS
endif|#
directive|endif
comment|// __APPLE__
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

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

