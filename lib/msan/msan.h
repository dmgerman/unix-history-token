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

begin_define
define|#
directive|define
name|MEM_TO_SHADOW
parameter_list|(
name|mem
parameter_list|)
value|(((uptr)mem)& ~0x400000000000ULL)
end_define

begin_define
define|#
directive|define
name|MEM_TO_ORIGIN
parameter_list|(
name|mem
parameter_list|)
value|(MEM_TO_SHADOW(mem) + 0x200000000000ULL)
end_define

begin_define
define|#
directive|define
name|MEM_IS_APP
parameter_list|(
name|mem
parameter_list|)
value|((uptr)mem>=         0x600000000000ULL)
end_define

begin_define
define|#
directive|define
name|MEM_IS_SHADOW
parameter_list|(
name|mem
parameter_list|)
value|((uptr)mem>=         0x200000000000ULL&& \                             (uptr)mem<=         0x400000000000ULL)
end_define

begin_struct_decl
struct_decl|struct
name|link_map
struct_decl|;
end_struct_decl

begin_comment
comment|// Opaque type returned by dlopen().
end_comment

begin_decl_stmt
specifier|const
name|int
name|kMsanParamTlsSizeInWords
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|kMsanRetvalTlsSizeInWords
init|=
literal|100
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
name|prot1
parameter_list|,
name|bool
name|prot2
parameter_list|,
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
name|EnterLoader
parameter_list|()
function_decl|;
name|void
name|ExitLoader
parameter_list|()
function_decl|;
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
name|StackTrace
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
name|fast
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
name|ReportAtExitStatistics
parameter_list|()
function_decl|;
name|void
name|UnpoisonMappedDSO
parameter_list|(
name|struct
name|link_map
modifier|*
name|map
parameter_list|)
function_decl|;
define|#
directive|define
name|GET_MALLOC_STACK_TRACE
define|\
value|StackTrace stack;                                                \   stack.size = 0;                                                  \   if (__msan_get_track_origins()&& msan_inited)                   \     GetStackTrace(&stack, common_flags()->malloc_context_size,     \         StackTrace::GetCurrentPc(), GET_CURRENT_FRAME(),           \         common_flags()->fast_unwind_on_malloc)
block|}
end_decl_stmt

begin_comment
comment|// namespace __msan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MSAN_H
end_comment

end_unit

