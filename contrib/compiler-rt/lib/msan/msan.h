begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan.h --------------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Private MSan header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSAN_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flags.h"
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
file|"msan_interface_internal.h"
end_include

begin_include
include|#
directive|include
file|"msan_flags.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MSAN_REPLACE_OPERATORS_NEW_AND_DELETE
end_ifndef

begin_define
define|#
directive|define
name|MSAN_REPLACE_OPERATORS_NEW_AND_DELETE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C/C++ on FreeBSD 0000 0000 0000 - 00ff ffff ffff: Low memory: main binary, MAP_32BIT mappings and modules 0100 0000 0000 - 0fff ffff ffff: Bad1 1000 0000 0000 - 30ff ffff ffff: Shadow 3100 0000 0000 - 37ff ffff ffff: Bad2 3800 0000 0000 - 58ff ffff ffff: Origins 5900 0000 0000 - 5fff ffff ffff: Bad3 6000 0000 0000 - 7fff ffff ffff: High memory: heap, modules and main thread stack  C/C++ on Linux/PIE 0000 0000 0000 - 1fff ffff ffff: Bad1 2000 0000 0000 - 3fff ffff ffff: Shadow 4000 0000 0000 - 5fff ffff ffff: Origins 6000 0000 0000 - 7fff ffff ffff: Main memory  C/C++ on Mips 0000 0000 0000 - 009f ffff ffff: Bad1 00a0 0000 0000 - 00bf ffff ffff: Shadow 00c0 0000 0000 - 00df ffff ffff: Origins 00e0 0000 0000 - 00ff ffff ffff: Main memory */
end_comment

begin_if
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
name|defined
argument_list|(
name|__mips64
argument_list|)
end_if

begin_decl_stmt
specifier|const
name|uptr
name|kLowMemBeg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kLowMemSize
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kHighMemBeg
init|=
literal|0x00e000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kHighMemSize
init|=
literal|0x002000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kShadowBeg
init|=
literal|0x00a000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kShadowSize
init|=
literal|0x002000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kOriginsBeg
init|=
literal|0x00c000000000
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MEM_TO_SHADOW
parameter_list|(
name|mem
parameter_list|)
value|(((uptr)(mem))& ~0x4000000000ULL)
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_FREEBSD
operator|&&
name|SANITIZER_WORDSIZE
operator|==
literal|64
end_elif

begin_decl_stmt
specifier|const
name|uptr
name|kLowMemBeg
init|=
literal|0x000000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kLowMemSize
init|=
literal|0x010000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kHighMemBeg
init|=
literal|0x600000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kHighMemSize
init|=
literal|0x200000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kShadowBeg
init|=
literal|0x100000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kShadowSize
init|=
literal|0x210000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kOriginsBeg
init|=
literal|0x380000000000
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Maps low and high app ranges to contiguous space with zero base:
end_comment

begin_comment
comment|//   Low:  0000 0000 0000 - 00ff ffff ffff  ->  2000 0000 0000 - 20ff ffff ffff
end_comment

begin_comment
comment|//   High: 6000 0000 0000 - 7fff ffff ffff  ->  0000 0000 0000 - 1fff ffff ffff
end_comment

begin_define
define|#
directive|define
name|LINEARIZE_MEM
parameter_list|(
name|mem
parameter_list|)
define|\
value|(((uptr)(mem)& ~0xc00000000000ULL) ^ 0x200000000000ULL)
end_define

begin_define
define|#
directive|define
name|MEM_TO_SHADOW
parameter_list|(
name|mem
parameter_list|)
value|(LINEARIZE_MEM((mem)) + 0x100000000000ULL)
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_LINUX
operator|&&
name|SANITIZER_WORDSIZE
operator|==
literal|64
end_elif

begin_decl_stmt
specifier|const
name|uptr
name|kLowMemBeg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kLowMemSize
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kHighMemBeg
init|=
literal|0x600000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kHighMemSize
init|=
literal|0x200000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kShadowBeg
init|=
literal|0x200000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kShadowSize
init|=
literal|0x200000000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kOriginsBeg
init|=
literal|0x400000000000
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MEM_TO_SHADOW
parameter_list|(
name|mem
parameter_list|)
value|(((uptr)(mem))& ~0x400000000000ULL)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported platform"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|uptr
name|kBad1Beg
init|=
name|kLowMemBeg
operator|+
name|kLowMemSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kBad1Size
init|=
name|kShadowBeg
operator|-
name|kBad1Beg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kBad2Beg
init|=
name|kShadowBeg
operator|+
name|kShadowSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kBad2Size
init|=
name|kOriginsBeg
operator|-
name|kBad2Beg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kOriginsSize
init|=
name|kShadowSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kBad3Beg
init|=
name|kOriginsBeg
operator|+
name|kOriginsSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uptr
name|kBad3Size
init|=
name|kHighMemBeg
operator|-
name|kBad3Beg
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SHADOW_TO_ORIGIN
parameter_list|(
name|shadow
parameter_list|)
define|\
value|(((uptr)(shadow)) + (kOriginsBeg - kShadowBeg))
end_define

begin_define
define|#
directive|define
name|MEM_TO_ORIGIN
parameter_list|(
name|mem
parameter_list|)
value|(SHADOW_TO_ORIGIN(MEM_TO_SHADOW((mem))))
end_define

begin_define
define|#
directive|define
name|MEM_IS_APP
parameter_list|(
name|mem
parameter_list|)
define|\
value|((kLowMemSize> 0&& (uptr)(mem)< kLowMemSize) || \     (uptr)(mem)>= kHighMemBeg)
end_define

begin_define
define|#
directive|define
name|MEM_IS_SHADOW
parameter_list|(
name|mem
parameter_list|)
define|\
value|((uptr)(mem)>= kShadowBeg&& (uptr)(mem)< kShadowBeg + kShadowSize)
end_define

begin_define
define|#
directive|define
name|MEM_IS_ORIGIN
parameter_list|(
name|mem
parameter_list|)
define|\
value|((uptr)(mem)>= kOriginsBeg&& (uptr)(mem)< kOriginsBeg + kOriginsSize)
end_define

begin_comment
comment|// These constants must be kept in sync with the ones in MemorySanitizer.cc.
end_comment

begin_decl_stmt
specifier|const
name|int
name|kMsanParamTlsSize
init|=
literal|800
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kMsanRetvalTlsSize
init|=
literal|800
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|__msan
block|{
specifier|extern
name|int
name|msan_inited
decl_stmt|;
specifier|extern
name|bool
name|msan_init_is_running
decl_stmt|;
specifier|extern
name|int
name|msan_report_count
decl_stmt|;
name|bool
name|ProtectRange
parameter_list|(
name|uptr
name|beg
parameter_list|,
name|uptr
name|end
parameter_list|)
function_decl|;
name|bool
name|InitShadow
parameter_list|(
name|bool
name|map_shadow
parameter_list|,
name|bool
name|init_origins
parameter_list|)
function_decl|;
name|char
modifier|*
name|GetProcSelfMaps
parameter_list|()
function_decl|;
name|void
name|InitializeInterceptors
parameter_list|()
function_decl|;
name|void
name|MsanAllocatorThreadFinish
parameter_list|()
function_decl|;
name|void
modifier|*
name|MsanReallocate
parameter_list|(
name|StackTrace
modifier|*
name|stack
parameter_list|,
name|void
modifier|*
name|oldp
parameter_list|,
name|uptr
name|size
parameter_list|,
name|uptr
name|alignment
parameter_list|,
name|bool
name|zeroise
parameter_list|)
function_decl|;
name|void
name|MsanDeallocate
parameter_list|(
name|StackTrace
modifier|*
name|stack
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|void
name|InstallTrapHandler
parameter_list|()
function_decl|;
name|void
name|InstallAtExitHandler
parameter_list|()
function_decl|;
name|void
name|ReplaceOperatorsNewAndDelete
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetStackOriginDescr
parameter_list|(
name|u32
name|id
parameter_list|,
name|uptr
modifier|*
name|pc
parameter_list|)
function_decl|;
name|void
name|EnterSymbolizer
parameter_list|()
function_decl|;
name|void
name|ExitSymbolizer
parameter_list|()
function_decl|;
name|bool
name|IsInSymbolizer
parameter_list|()
function_decl|;
struct|struct
name|SymbolizerScope
block|{
name|SymbolizerScope
argument_list|()
block|{
name|EnterSymbolizer
argument_list|()
expr_stmt|;
block|}
operator|~
name|SymbolizerScope
argument_list|()
block|{
name|ExitSymbolizer
argument_list|()
block|; }
block|}
struct|;
name|void
name|MsanDie
parameter_list|()
function_decl|;
name|void
name|PrintWarning
parameter_list|(
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|)
function_decl|;
name|void
name|PrintWarningWithOrigin
parameter_list|(
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|,
name|u32
name|origin
parameter_list|)
function_decl|;
name|void
name|GetStackTrace
parameter_list|(
name|BufferedStackTrace
modifier|*
name|stack
parameter_list|,
name|uptr
name|max_s
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|,
name|bool
name|request_fast_unwind
parameter_list|)
function_decl|;
name|void
name|ReportUMR
parameter_list|(
name|StackTrace
modifier|*
name|stack
parameter_list|,
name|u32
name|origin
parameter_list|)
function_decl|;
name|void
name|ReportExpectedUMRNotFound
parameter_list|(
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
name|void
name|ReportStats
parameter_list|()
function_decl|;
name|void
name|ReportAtExitStatistics
parameter_list|()
function_decl|;
name|void
name|DescribeMemoryRange
parameter_list|(
specifier|const
name|void
modifier|*
name|x
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|void
name|ReportUMRInsideAddressRange
parameter_list|(
specifier|const
name|char
modifier|*
name|what
parameter_list|,
specifier|const
name|void
modifier|*
name|start
parameter_list|,
name|uptr
name|size
parameter_list|,
name|uptr
name|offset
parameter_list|)
function_decl|;
comment|// Unpoison first n function arguments.
name|void
name|UnpoisonParam
parameter_list|(
name|uptr
name|n
parameter_list|)
function_decl|;
name|void
name|UnpoisonThreadLocalState
parameter_list|()
function_decl|;
name|u32
name|GetOriginIfPoisoned
parameter_list|(
name|uptr
name|a
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|void
name|SetOriginIfPoisoned
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|src_shadow
parameter_list|,
name|uptr
name|size
parameter_list|,
name|u32
name|src_origin
parameter_list|)
function_decl|;
name|void
name|CopyOrigin
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
name|void
name|MovePoison
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
name|void
name|CopyPoison
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
comment|// Returns a "chained" origin id, pointing to the given stack trace followed by
comment|// the previous origin id.
name|u32
name|ChainOrigin
parameter_list|(
name|u32
name|id
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
define|#
directive|define
name|GET_MALLOC_STACK_TRACE
define|\
value|BufferedStackTrace stack;                                                    \   if (__msan_get_track_origins()&& msan_inited)                               \   GetStackTrace(&stack, common_flags()->malloc_context_size,                   \                 StackTrace::GetCurrentPc(), GET_CURRENT_FRAME(),               \                 common_flags()->fast_unwind_on_malloc)
define|#
directive|define
name|GET_STORE_STACK_TRACE_PC_BP
parameter_list|(
name|pc
parameter_list|,
name|bp
parameter_list|)
define|\
value|BufferedStackTrace stack;                                                    \   if (__msan_get_track_origins()> 1&& msan_inited)                           \   GetStackTrace(&stack, flags()->store_context_size, pc, bp,                   \                 common_flags()->fast_unwind_on_malloc)
define|#
directive|define
name|GET_FATAL_STACK_TRACE_PC_BP
parameter_list|(
name|pc
parameter_list|,
name|bp
parameter_list|)
define|\
value|BufferedStackTrace stack;                                                    \   if (msan_inited)                                                             \   GetStackTrace(&stack, kStackTraceMax, pc, bp,                                \                 common_flags()->fast_unwind_on_fatal)
define|#
directive|define
name|GET_STORE_STACK_TRACE
define|\
value|GET_STORE_STACK_TRACE_PC_BP(StackTrace::GetCurrentPc(), GET_CURRENT_FRAME())
name|class
name|ScopedThreadLocalStateBackup
block|{
name|public
label|:
name|ScopedThreadLocalStateBackup
argument_list|()
block|{
name|Backup
argument_list|()
expr_stmt|;
block|}
operator|~
name|ScopedThreadLocalStateBackup
argument_list|()
block|{
name|Restore
argument_list|()
block|; }
name|void
name|Backup
argument_list|()
expr_stmt|;
name|void
name|Restore
parameter_list|()
function_decl|;
name|private
label|:
name|u64
name|va_arg_overflow_size_tls
decl_stmt|;
block|}
empty_stmt|;
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
name|void
name|MsanTSDInit
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
name|void
modifier|*
name|MsanTSDGet
parameter_list|()
function_decl|;
name|void
name|MsanTSDSet
parameter_list|(
name|void
modifier|*
name|tsd
parameter_list|)
function_decl|;
name|void
name|MsanTSDDtor
parameter_list|(
name|void
modifier|*
name|tsd
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __msan
end_comment

begin_define
define|#
directive|define
name|MSAN_MALLOC_HOOK
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|if (&__sanitizer_malloc_hook) __sanitizer_malloc_hook(ptr, size)
end_define

begin_define
define|#
directive|define
name|MSAN_FREE_HOOK
parameter_list|(
name|ptr
parameter_list|)
define|\
value|if (&__sanitizer_free_hook) __sanitizer_free_hook(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MSAN_H
end_comment

end_unit

