begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_mman.h ---------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_MMAN_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_MMAN_H
end_define

begin_include
include|#
directive|include
file|"tsan_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
specifier|const
name|uptr
name|kDefaultAlignment
init|=
literal|16
decl_stmt|;
name|void
name|InitializeAllocator
parameter_list|()
function_decl|;
name|void
name|AllocatorThreadStart
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|)
function_decl|;
name|void
name|AllocatorThreadFinish
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|)
function_decl|;
name|void
name|AllocatorPrintStats
parameter_list|()
function_decl|;
comment|// For user allocations.
name|void
modifier|*
name|user_alloc
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|sz
parameter_list|,
name|uptr
name|align
init|=
name|kDefaultAlignment
parameter_list|,
name|bool
name|signal
init|=
name|true
parameter_list|)
function_decl|;
comment|// Does not accept NULL.
name|void
name|user_free
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|bool
name|signal
init|=
name|true
parameter_list|)
function_decl|;
name|void
modifier|*
name|user_realloc
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|uptr
name|sz
parameter_list|)
function_decl|;
name|void
modifier|*
name|user_alloc_aligned
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|sz
parameter_list|,
name|uptr
name|align
parameter_list|)
function_decl|;
name|uptr
name|user_alloc_usable_size
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|// Invoking malloc/free hooks that may be installed by the user.
name|void
name|invoke_malloc_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|void
name|invoke_free_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
enum|enum
name|MBlockType
block|{
name|MBlockScopedBuf
block|,
name|MBlockString
block|,
name|MBlockStackTrace
block|,
name|MBlockShadowStack
block|,
name|MBlockSync
block|,
name|MBlockClock
block|,
name|MBlockThreadContex
block|,
name|MBlockDeadInfo
block|,
name|MBlockRacyStacks
block|,
name|MBlockRacyAddresses
block|,
name|MBlockAtExit
block|,
name|MBlockFlag
block|,
name|MBlockReport
block|,
name|MBlockReportMop
block|,
name|MBlockReportThread
block|,
name|MBlockReportMutex
block|,
name|MBlockReportLoc
block|,
name|MBlockReportStack
block|,
name|MBlockSuppression
block|,
name|MBlockExpectRace
block|,
name|MBlockSignal
block|,
name|MBlockJmpBuf
block|,
comment|// This must be the last.
name|MBlockTypeCount
block|}
enum|;
comment|// For internal data structures.
name|void
modifier|*
name|internal_alloc
parameter_list|(
name|MBlockType
name|typ
parameter_list|,
name|uptr
name|sz
parameter_list|)
function_decl|;
name|void
name|internal_free
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|DestroyAndFree
argument_list|(
argument|T *&p
argument_list|)
block|{
name|p
operator|->
expr|~
name|T
argument_list|()
block|;
name|internal_free
argument_list|(
name|p
argument_list|)
block|;
name|p
operator|=
literal|0
block|; }
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_MMAN_H
end_comment

end_unit

