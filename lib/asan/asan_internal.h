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

begin_define
define|#
directive|define
name|ASAN_DEFAULT_FAILURE_EXITCODE
value|1
end_define

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
name|SANITIZER_WORDSIZE
operator|==
literal|32
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
block|;  struct
name|SignalContext
block|{
name|void
operator|*
name|context
block|;
name|uptr
name|addr
block|;
name|uptr
name|pc
block|;
name|uptr
name|sp
block|;
name|uptr
name|bp
block|;
name|SignalContext
argument_list|(
argument|void *context
argument_list|,
argument|uptr addr
argument_list|,
argument|uptr pc
argument_list|,
argument|uptr sp
argument_list|,
argument|uptr bp
argument_list|)
operator|:
name|context
argument_list|(
name|context
argument_list|)
block|,
name|addr
argument_list|(
name|addr
argument_list|)
block|,
name|pc
argument_list|(
name|pc
argument_list|)
block|,
name|sp
argument_list|(
name|sp
argument_list|)
block|,
name|bp
argument_list|(
argument|bp
argument_list|)
block|{   }
comment|// Creates signal context in a platform-specific manner.
specifier|static
name|SignalContext
name|Create
argument_list|(
name|void
operator|*
name|siginfo
argument_list|,
name|void
operator|*
name|context
argument_list|)
block|; }
block|;
name|void
name|AsanInitFromRtl
argument_list|()
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
name|void
name|GetPcSpBp
argument_list|(
name|void
operator|*
name|context
argument_list|,
name|uptr
operator|*
name|pc
argument_list|,
name|uptr
operator|*
name|sp
argument_list|,
name|uptr
operator|*
name|bp
argument_list|)
block|;
name|void
name|AsanOnSIGSEGV
argument_list|(
name|int
argument_list|,
name|void
operator|*
name|siginfo
argument_list|,
name|void
operator|*
name|context
argument_list|)
block|;
name|void
name|MaybeReexec
argument_list|()
block|;
name|void
name|ReadContextStack
argument_list|(
name|void
operator|*
name|context
argument_list|,
name|uptr
operator|*
name|stack
argument_list|,
name|uptr
operator|*
name|ssize
argument_list|)
block|;
name|void
name|AsanPlatformThreadInit
argument_list|()
block|;
name|void
name|StopInitOrderChecking
argument_list|()
block|;
comment|// Wrapper for TLS/TSD.
name|void
name|AsanTSDInit
argument_list|(
name|void
argument_list|(
operator|*
name|destructor
argument_list|)
argument_list|(
name|void
operator|*
name|tsd
argument_list|)
argument_list|)
block|;
name|void
operator|*
name|AsanTSDGet
argument_list|()
block|;
name|void
name|AsanTSDSet
argument_list|(
name|void
operator|*
name|tsd
argument_list|)
block|;
name|void
name|PlatformTSDDtor
argument_list|(
name|void
operator|*
name|tsd
argument_list|)
block|;
name|void
name|AppendToErrorMessageBuffer
argument_list|(
specifier|const
name|char
operator|*
name|buffer
argument_list|)
block|;
name|void
operator|*
name|AsanDlSymNext
argument_list|(
specifier|const
name|char
operator|*
name|sym
argument_list|)
block|;
name|void
name|ReserveShadowMemoryRange
argument_list|(
argument|uptr beg
argument_list|,
argument|uptr end
argument_list|)
block|;
comment|// Platform-specific options.
if|#
directive|if
name|SANITIZER_MAC
name|bool
name|PlatformHasDifferentMemcpyAndMemmove
argument_list|()
block|;
define|#
directive|define
name|PLATFORM_HAS_DIFFERENT_MEMCPY_AND_MEMMOVE
define|\
value|(PlatformHasDifferentMemcpyAndMemmove())
else|#
directive|else
define|#
directive|define
name|PLATFORM_HAS_DIFFERENT_MEMCPY_AND_MEMMOVE
value|true
endif|#
directive|endif
comment|// SANITIZER_MAC
comment|// Add convenient macro for interface functions that may be represented as
comment|// weak hooks.
define|#
directive|define
name|ASAN_MALLOC_HOOK
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|if (&__sanitizer_malloc_hook) __sanitizer_malloc_hook(ptr, size)
define|#
directive|define
name|ASAN_FREE_HOOK
parameter_list|(
name|ptr
parameter_list|)
define|\
value|if (&__sanitizer_free_hook) __sanitizer_free_hook(ptr)
define|#
directive|define
name|ASAN_ON_ERROR
parameter_list|()
define|\
value|if (&__asan_on_error) __asan_on_error()
specifier|extern
name|int
name|asan_inited
block|;
comment|// Used to avoid infinite recursion in __asan_init().
specifier|extern
name|bool
name|asan_init_is_running
block|;
specifier|extern
name|void
argument_list|(
operator|*
name|death_callback
argument_list|)
argument_list|(
name|void
argument_list|)
block|;
comment|// These magic values are written to shadow for better error reporting.
specifier|const
name|int
name|kAsanHeapLeftRedzoneMagic
operator|=
literal|0xfa
block|;
specifier|const
name|int
name|kAsanHeapRightRedzoneMagic
operator|=
literal|0xfb
block|;
specifier|const
name|int
name|kAsanHeapFreeMagic
operator|=
literal|0xfd
block|;
specifier|const
name|int
name|kAsanStackLeftRedzoneMagic
operator|=
literal|0xf1
block|;
specifier|const
name|int
name|kAsanStackMidRedzoneMagic
operator|=
literal|0xf2
block|;
specifier|const
name|int
name|kAsanStackRightRedzoneMagic
operator|=
literal|0xf3
block|;
specifier|const
name|int
name|kAsanStackPartialRedzoneMagic
operator|=
literal|0xf4
block|;
specifier|const
name|int
name|kAsanStackAfterReturnMagic
operator|=
literal|0xf5
block|;
specifier|const
name|int
name|kAsanInitializationOrderMagic
operator|=
literal|0xf6
block|;
specifier|const
name|int
name|kAsanUserPoisonedMemoryMagic
operator|=
literal|0xf7
block|;
specifier|const
name|int
name|kAsanContiguousContainerOOBMagic
operator|=
literal|0xfc
block|;
specifier|const
name|int
name|kAsanStackUseAfterScopeMagic
operator|=
literal|0xf8
block|;
specifier|const
name|int
name|kAsanGlobalRedzoneMagic
operator|=
literal|0xf9
block|;
specifier|const
name|int
name|kAsanInternalHeapMagic
operator|=
literal|0xfe
block|;
specifier|const
name|int
name|kAsanArrayCookieMagic
operator|=
literal|0xac
block|;
specifier|const
name|int
name|kAsanIntraObjectRedzone
operator|=
literal|0xbb
block|;
specifier|const
name|int
name|kAsanAllocaLeftMagic
operator|=
literal|0xca
block|;
specifier|const
name|int
name|kAsanAllocaRightMagic
operator|=
literal|0xcb
block|;
specifier|static
specifier|const
name|uptr
name|kCurrentStackFrameMagic
operator|=
literal|0x41B58AB3
block|;
specifier|static
specifier|const
name|uptr
name|kRetiredStackFrameMagic
operator|=
literal|0x45E0360E
block|;  }
end_expr_stmt

begin_comment
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

