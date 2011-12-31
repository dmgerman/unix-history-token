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

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for __WORDSIZE
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|// for _exit
end_comment

begin_comment
comment|// If __WORDSIZE was undefined by the platform, define it in terms of the
end_comment

begin_comment
comment|// compiler built-in __LP64__.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__WORDSIZE
end_ifndef

begin_if
if|#
directive|if
name|__LP64__
end_if

begin_define
define|#
directive|define
name|__WORDSIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__WORDSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ANDROID
end_ifdef

begin_include
include|#
directive|include
file|<sys/atomics.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__has_feature
argument_list|)
operator|&&
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
comment|// If set, sysinfo/sysinfo.h will be used to iterate over /proc/maps.
ifndef|#
directive|ifndef
name|ASAN_USE_SYSINFO
define|#
directive|define
name|ASAN_USE_SYSINFO
value|1
endif|#
directive|endif
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
name|CheckFailed
argument_list|(
argument|const char *cond
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|;
name|void
name|ShowStatsAndAbort
argument_list|()
block|;
comment|// asan_globals.cc
name|bool
name|DescribeAddrIfGlobal
argument_list|(
argument|uintptr_t addr
argument_list|)
block|;
comment|// asan_malloc_linux.cc / asan_malloc_mac.cc
name|void
name|ReplaceSystemMalloc
argument_list|()
block|;
name|void
name|OutOfMemoryMessageAndDie
argument_list|(
argument|const char *mem_type
argument_list|,
argument|size_t size
argument_list|)
block|;
comment|// asan_linux.cc / asan_mac.cc
name|void
operator|*
name|AsanDoesNotSupportStaticLinkage
argument_list|()
block|;
name|int
name|AsanOpenReadonly
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
block|;
name|void
operator|*
name|AsanMmapFixedNoReserve
argument_list|(
argument|uintptr_t fixed_addr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|void
operator|*
name|AsanMmapFixedReserve
argument_list|(
argument|uintptr_t fixed_addr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|void
operator|*
name|AsanMprotect
argument_list|(
argument|uintptr_t fixed_addr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|void
operator|*
name|AsanMmapSomewhereOrDie
argument_list|(
argument|size_t size
argument_list|,
argument|const char *where
argument_list|)
block|;
name|void
name|AsanUnmapOrDie
argument_list|(
argument|void *ptr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|ssize_t
name|AsanRead
argument_list|(
argument|int fd
argument_list|,
argument|void *buf
argument_list|,
argument|size_t count
argument_list|)
block|;
name|ssize_t
name|AsanWrite
argument_list|(
argument|int fd
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t count
argument_list|)
block|;
name|int
name|AsanClose
argument_list|(
argument|int fd
argument_list|)
block|;
comment|// asan_printf.cc
name|void
name|RawWrite
argument_list|(
specifier|const
name|char
operator|*
name|buffer
argument_list|)
block|;
name|int
name|SNPrint
argument_list|(
argument|char *buffer
argument_list|,
argument|size_t length
argument_list|,
argument|const char *format
argument_list|,
argument|...
argument_list|)
block|;
name|void
name|Printf
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
name|Report
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
block|;
comment|// Don't use std::min and std::max, to minimize dependency on libstdc++.
name|template
operator|<
name|class
name|T
operator|>
name|T
name|Min
argument_list|(
argument|T a
argument_list|,
argument|T b
argument_list|)
block|{
return|return
name|a
operator|<
name|b
operator|?
name|a
operator|:
name|b
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|T
name|Max
argument_list|(
argument|T a
argument_list|,
argument|T b
argument_list|)
block|{
return|return
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
return|;
block|}
end_expr_stmt

begin_comment
comment|// asan_poisoning.cc
end_comment

begin_comment
comment|// Poisons the shadow memory for "size" bytes starting from "addr".
end_comment

begin_function_decl
name|void
name|PoisonShadow
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Poisons the shadow memory for "redzone_size" bytes starting from
end_comment

begin_comment
comment|// "addr + size".
end_comment

begin_function_decl
name|void
name|PoisonShadowPartialRightRedzone
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|uintptr_t
name|size
parameter_list|,
name|uintptr_t
name|redzone_size
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|size_t
name|FLAG_quarantine_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|FLAG_demangle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_symbolize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|FLAG_v
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|FLAG_redzone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|FLAG_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_poison_shadow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|FLAG_report_globals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|FLAG_malloc_context_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_replace_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_replace_intrin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_replace_cfallocator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_fast_unwind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_use_fake_stack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|FLAG_max_malloc_fill_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|FLAG_exitcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|FLAG_allow_user_poisoning
decl_stmt|;
end_decl_stmt

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

begin_enum
enum|enum
name|LinkerInitialized
block|{
name|LINKER_INITIALIZED
init|=
literal|0
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_DIE
end_ifndef

begin_define
define|#
directive|define
name|ASAN_DIE
value|_exit(FLAG_exitcode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_DIE
end_comment

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|cond
parameter_list|)
value|do { if (!(cond)) { \   CheckFailed(#cond, __FILE__, __LINE__); \ }}while(0)
end_define

begin_define
define|#
directive|define
name|RAW_CHECK_MSG
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
value|do { \   if (!(expr)) { \     RawWrite(msg); \     ASAN_DIE; \   } \ } while (0)
end_define

begin_define
define|#
directive|define
name|RAW_CHECK
parameter_list|(
name|expr
parameter_list|)
value|RAW_CHECK_MSG(expr, #expr)
end_define

begin_define
define|#
directive|define
name|UNIMPLEMENTED
parameter_list|()
value|CHECK("unimplemented"&& 0)
end_define

begin_define
define|#
directive|define
name|ASAN_ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a)/sizeof((a)[0]))
end_define

begin_decl_stmt
specifier|const
name|size_t
name|kWordSize
init|=
name|__WORDSIZE
operator|/
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_t
name|kWordSizeInBits
init|=
literal|8
operator|*
name|kWordSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_t
name|kPageSizeBits
init|=
literal|12
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_t
name|kPageSize
init|=
literal|1UL
operator|<<
name|kPageSizeBits
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
value|(uintptr_t)__builtin_return_address(0)
end_define

begin_define
define|#
directive|define
name|GET_CURRENT_FRAME
parameter_list|()
value|(uintptr_t)__builtin_frame_address(0)
end_define

begin_define
define|#
directive|define
name|GET_BP_PC_SP
define|\
value|uintptr_t bp = GET_CURRENT_FRAME();              \   uintptr_t pc = GET_CALLER_PC();                  \   uintptr_t local_stack;                           \   uintptr_t sp = (uintptr_t)&local_stack;
end_define

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
name|kAsanHeapRightRedzoneMagic
init|=
literal|0xfb
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
name|kAsanStackPartialRedzoneMagic
init|=
literal|0xf4
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
name|kAsanUserPoisonedMemoryMagic
init|=
literal|0xf7
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
specifier|static
specifier|const
name|uintptr_t
name|kCurrentStackFrameMagic
init|=
literal|0x41B58AB3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uintptr_t
name|kRetiredStackFrameMagic
init|=
literal|0x45E0360E
decl_stmt|;
end_decl_stmt

begin_comment
comment|// --------------------------- Bit twiddling ------- {{{1
end_comment

begin_function
specifier|inline
name|bool
name|IsPowerOfTwo
parameter_list|(
name|size_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|&
operator|(
name|x
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
return|;
block|}
end_function

begin_function
specifier|inline
name|size_t
name|RoundUpTo
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|boundary
parameter_list|)
block|{
name|CHECK
argument_list|(
name|IsPowerOfTwo
argument_list|(
name|boundary
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|size
operator|+
name|boundary
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|boundary
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|// -------------------------- LowLevelAllocator ----- {{{1
end_comment

begin_comment
comment|// A simple low-level memory allocator for internal use.
end_comment

begin_decl_stmt
name|class
name|LowLevelAllocator
block|{
name|public
label|:
name|explicit
name|LowLevelAllocator
parameter_list|(
name|LinkerInitialized
parameter_list|)
block|{}
comment|// 'size' must be a power of two.
comment|// Requires an external lock.
name|void
modifier|*
name|Allocate
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
name|private
label|:
name|char
modifier|*
name|allocated_end_
decl_stmt|;
name|char
modifier|*
name|allocated_current_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// -------------------------- Atomic ---------------- {{{1
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|AtomicInc
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ANDROID
return|return
name|__atomic_inc
argument_list|(
name|a
argument_list|)
operator|+
literal|1
return|;
else|#
directive|else
return|return
name|__sync_add_and_fetch
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|AtomicDec
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ANDROID
return|return
name|__atomic_dec
argument_list|(
name|a
argument_list|)
operator|-
literal|1
return|;
else|#
directive|else
return|return
name|__sync_add_and_fetch
argument_list|(
name|a
argument_list|,
operator|-
literal|1
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

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

