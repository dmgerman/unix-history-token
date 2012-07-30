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
file|"sanitizer_common/sanitizer_libc.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"This operating system is not supported by AddressSanitizer"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
name|void
modifier|*
name|_ReturnAddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_extern

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_ReturnAddress
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(_WIN32)
end_comment

begin_define
define|#
directive|define
name|ASAN_DEFAULT_FAILURE_EXITCODE
value|1
end_define

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
name|ASAN_LINUX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_LINUX
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
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASAN_MAC
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_MAC
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
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASAN_WINDOWS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_WINDOWS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASAN_POSIX
value|(ASAN_LINUX || ASAN_MAC)
end_define

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
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
comment|// If set, asan will install its own SEGV signal handler.
ifndef|#
directive|ifndef
name|ASAN_NEEDS_SEGV
define|#
directive|define
name|ASAN_NEEDS_SEGV
value|1
endif|#
directive|endif
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
comment|// If set, asan uses the values of SHADOW_SCALE and SHADOW_OFFSET
comment|// provided by the instrumented objects. Otherwise constants are used.
ifndef|#
directive|ifndef
name|ASAN_FLEXIBLE_MAPPING_AND_OFFSET
define|#
directive|define
name|ASAN_FLEXIBLE_MAPPING_AND_OFFSET
value|0
endif|#
directive|endif
comment|// If set, values like allocator chunk size, as well as defaults for some flags
comment|// will be changed towards less memory overhead.
ifndef|#
directive|ifndef
name|ASAN_LOW_MEMORY
define|#
directive|define
name|ASAN_LOW_MEMORY
value|0
endif|#
directive|endif
comment|// All internal functions in asan reside inside the __asan namespace
comment|// to avoid namespace collisions with the user programs.
comment|// Seperate namespace also makes it simpler to distinguish the asan run-time
comment|// functions from the instrumented user code in a profile.
name|namespace
name|__asan
block|{
name|class
name|AsanThread
block|; struct
name|AsanStackTrace
block|;
comment|// asan_rtl.cc
name|void
name|NORETURN
name|ShowStatsAndAbort
argument_list|()
block|;
comment|// asan_globals.cc
name|bool
name|DescribeAddrIfGlobal
argument_list|(
argument|uptr addr
argument_list|)
block|;
name|void
name|ReplaceOperatorsNewAndDelete
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
name|bool
name|AsanInterceptsSignal
argument_list|(
argument|int signum
argument_list|)
block|;
name|void
name|SetAlternateSignalStack
argument_list|()
block|;
name|void
name|UnsetAlternateSignalStack
argument_list|()
block|;
name|void
name|InstallSignalHandlers
argument_list|()
block|;
name|void
name|AsanPlatformThreadInit
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
name|AppendToErrorMessageBuffer
argument_list|(
specifier|const
name|char
operator|*
name|buffer
argument_list|)
block|;
comment|// asan_printf.cc
name|void
name|AsanPrintf
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
block|;
name|void
name|AsanReport
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
block|;
comment|// asan_poisoning.cc
comment|// Poisons the shadow memory for "size" bytes starting from "addr".
name|void
name|PoisonShadow
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr size
argument_list|,
argument|u8 value
argument_list|)
block|;
comment|// Poisons the shadow memory for "redzone_size" bytes starting from
comment|// "addr + size".
name|void
name|PoisonShadowPartialRightRedzone
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr size
argument_list|,
argument|uptr redzone_size
argument_list|,
argument|u8 value
argument_list|)
block|;
comment|// Platfrom-specific options.
ifdef|#
directive|ifdef
name|__APPLE__
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
comment|// __APPLE__
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
block|;  enum
name|LinkerInitialized
block|{
name|LINKER_INITIALIZED
operator|=
literal|0
block|}
block|;
define|#
directive|define
name|ASAN_ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a)/sizeof((a)[0]))
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
value|(uptr)__builtin_return_address(0)
define|#
directive|define
name|GET_CURRENT_FRAME
parameter_list|()
value|(uptr)__builtin_frame_address(0)
else|#
directive|else
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
value|(uptr)_ReturnAddress()
comment|// CaptureStackBackTrace doesn't need to know BP on Windows.
comment|// FIXME: This macro is still used when printing error reports though it's not
comment|// clear if the BP value is needed in the ASan reports on Windows.
define|#
directive|define
name|GET_CURRENT_FRAME
parameter_list|()
value|(uptr)0xDEADBEEF
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_WIN32
ifndef|#
directive|ifndef
name|ASAN_USE_EXTERNAL_SYMBOLIZER
define|#
directive|define
name|ASAN_USE_EXTERNAL_SYMBOLIZER
value|__asan_WinSymbolize
name|bool
name|__asan_WinSymbolize
argument_list|(
argument|const void *addr
argument_list|,
argument|char *out_buffer
argument_list|,
argument|int buffer_size
argument_list|)
block|;
endif|#
directive|endif
endif|#
directive|endif
comment|// _WIN32
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
name|kAsanUserPoisonedMemoryMagic
operator|=
literal|0xf7
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
block|;
comment|// -------------------------- LowLevelAllocator ----- {{{1
comment|// A simple low-level memory allocator for internal use.
name|class
name|LowLevelAllocator
block|{
name|public
operator|:
name|explicit
name|LowLevelAllocator
argument_list|(
argument|LinkerInitialized
argument_list|)
block|{}
comment|// 'size' must be a power of two.
comment|// Requires an external lock.
name|void
operator|*
name|Allocate
argument_list|(
argument|uptr size
argument_list|)
block|;
name|private
operator|:
name|char
operator|*
name|allocated_end_
block|;
name|char
operator|*
name|allocated_current_
block|; }
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

