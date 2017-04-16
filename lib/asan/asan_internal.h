begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_internal.h -----------------------------------------*- C++ -*-===//
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
comment|// ASan-private header which defines various general utilities.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"asan_flags.h"
end_include

begin_include
include|#
directive|include
file|"asan_interface_internal.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_libc.h"
end_include

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
operator|||
name|defined
argument_list|(
name|__SANITIZE_ADDRESS__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"The AddressSanitizer run-time should not be"
end_error

begin_expr_stmt
literal|" instrumented by AddressSanitizer"
endif|#
directive|endif
comment|// Build-time configuration options.
comment|// If set, asan will intercept C++ exception api call(s).
ifndef|#
directive|ifndef
name|ASAN_HAS_EXCEPTIONS
define|#
directive|define
name|ASAN_HAS_EXCEPTIONS
value|1
endif|#
directive|endif
comment|// If set, values like allocator chunk size, as well as defaults for some flags
comment|// will be changed towards less memory overhead.
ifndef|#
directive|ifndef
name|ASAN_LOW_MEMORY
if|#
directive|if
name|SANITIZER_IOS
operator|||
name|SANITIZER_ANDROID
define|#
directive|define
name|ASAN_LOW_MEMORY
value|1
else|#
directive|else
define|#
directive|define
name|ASAN_LOW_MEMORY
value|0
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|ASAN_DYNAMIC
ifdef|#
directive|ifdef
name|PIC
define|#
directive|define
name|ASAN_DYNAMIC
value|1
else|#
directive|else
define|#
directive|define
name|ASAN_DYNAMIC
value|0
endif|#
directive|endif
endif|#
directive|endif
comment|// All internal functions in asan reside inside the __asan namespace
comment|// to avoid namespace collisions with the user programs.
comment|// Separate namespace also makes it simpler to distinguish the asan run-time
comment|// functions from the instrumented user code in a profile.
name|namespace
name|__asan
block|{
name|class
name|AsanThread
block|;
name|using
name|__sanitizer
operator|::
name|StackTrace
block|;
name|void
name|AsanInitFromRtl
argument_list|()
block|;
comment|// asan_win.cc
name|void
name|InitializePlatformExceptionHandlers
argument_list|()
block|;
comment|// Returns whether an address is a valid allocated system heap block.
comment|// 'addr' must point to the beginning of the block.
name|bool
name|IsSystemHeapAddress
argument_list|(
argument|uptr addr
argument_list|)
block|;
comment|// asan_rtl.cc
name|void
name|NORETURN
name|ShowStatsAndAbort
argument_list|()
block|;
comment|// asan_malloc_linux.cc / asan_malloc_mac.cc
name|void
name|ReplaceSystemMalloc
argument_list|()
block|;
comment|// asan_linux.cc / asan_mac.cc / asan_win.cc
name|void
operator|*
name|AsanDoesNotSupportStaticLinkage
argument_list|()
block|;
name|void
name|AsanCheckDynamicRTPrereqs
argument_list|()
block|;
name|void
name|AsanCheckIncompatibleRT
argument_list|()
block|;
comment|// Support function for __asan_(un)register_image_globals. Searches for the
comment|// loaded image containing `needle' and then enumerates all global metadata
comment|// structures declared in that image, applying `op' (e.g.,
comment|// __asan_(un)register_globals) to them.
typedef|typedef
name|void
function_decl|(
modifier|*
name|globals_op_fptr
function_decl|)
parameter_list|(
name|__asan_global
modifier|*
parameter_list|,
name|uptr
parameter_list|)
function_decl|;
name|void
name|AsanApplyToGlobals
argument_list|(
argument|globals_op_fptr op
argument_list|,
argument|const void *needle
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|AsanOnDeadlySignal
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
name|siginfo
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReadContextStack
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|uptr
modifier|*
name|stack
parameter_list|,
name|uptr
modifier|*
name|ssize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StopInitOrderChecking
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Wrapper for TLS/TSD.
end_comment

begin_function_decl
name|void
name|AsanTSDInit
parameter_list|(
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|(
name|void
modifier|*
name|tsd
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|AsanTSDGet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsanTSDSet
parameter_list|(
name|void
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PlatformTSDDtor
parameter_list|(
name|void
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AppendToErrorMessageBuffer
parameter_list|(
specifier|const
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|AsanDlSymNext
parameter_list|(
specifier|const
name|char
modifier|*
name|sym
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReserveShadowMemoryRange
parameter_list|(
name|uptr
name|beg
parameter_list|,
name|uptr
name|end
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Add convenient macro for interface functions that may be represented as
end_comment

begin_comment
comment|// weak hooks.
end_comment

begin_define
define|#
directive|define
name|ASAN_MALLOC_HOOK
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|do {                                                                \     if (&__sanitizer_malloc_hook) __sanitizer_malloc_hook(ptr, size); \     RunMallocHooks(ptr, size);                                        \   } while (false)
end_define

begin_define
define|#
directive|define
name|ASAN_FREE_HOOK
parameter_list|(
name|ptr
parameter_list|)
define|\
value|do {                                                      \     if (&__sanitizer_free_hook) __sanitizer_free_hook(ptr); \     RunFreeHooks(ptr);                                      \   } while (false)
end_define

begin_define
define|#
directive|define
name|ASAN_ON_ERROR
parameter_list|()
define|\
value|if (&__asan_on_error) __asan_on_error()
end_define

begin_decl_stmt
specifier|extern
name|int
name|asan_inited
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Used to avoid infinite recursion in __asan_init().
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|asan_init_is_running
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|death_callback
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// These magic values are written to shadow for better error reporting.
end_comment

begin_decl_stmt
specifier|const
name|int
name|kAsanHeapLeftRedzoneMagic
init|=
literal|0xfa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanHeapFreeMagic
init|=
literal|0xfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanStackLeftRedzoneMagic
init|=
literal|0xf1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanStackMidRedzoneMagic
init|=
literal|0xf2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanStackRightRedzoneMagic
init|=
literal|0xf3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanStackAfterReturnMagic
init|=
literal|0xf5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanInitializationOrderMagic
init|=
literal|0xf6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanUserPoisonedMemoryMagic
init|=
literal|0xf7
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanContiguousContainerOOBMagic
init|=
literal|0xfc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanStackUseAfterScopeMagic
init|=
literal|0xf8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanGlobalRedzoneMagic
init|=
literal|0xf9
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanInternalHeapMagic
init|=
literal|0xfe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanArrayCookieMagic
init|=
literal|0xac
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanIntraObjectRedzone
init|=
literal|0xbb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanAllocaLeftMagic
init|=
literal|0xca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kAsanAllocaRightMagic
init|=
literal|0xcb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uptr
name|kCurrentStackFrameMagic
init|=
literal|0x41B58AB3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uptr
name|kRetiredStackFrameMagic
init|=
literal|0x45E0360E
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_INTERNAL_H
end_comment

end_unit

