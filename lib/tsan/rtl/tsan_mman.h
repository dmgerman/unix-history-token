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
comment|// Descriptor of user's memory block.
struct|struct
name|MBlock
block|{
name|uptr
name|size
decl_stmt|;
block|}
struct|;
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
comment|// Given the pointer p into a valid allocated block,
comment|// returns the descriptor of the block.
name|MBlock
modifier|*
name|user_mblock
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|void
modifier|*
name|p
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
comment|// This must be the last.
name|MBlockTypeCount
block|, }
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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|InternalScopedBuf
block|{
name|public
operator|:
name|explicit
name|InternalScopedBuf
argument_list|(
argument|uptr cnt
argument_list|)
block|{
name|cnt_
operator|=
name|cnt
block|;
name|ptr_
operator|=
operator|(
name|T
operator|*
operator|)
name|internal_alloc
argument_list|(
name|MBlockScopedBuf
argument_list|,
name|cnt
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;   }
operator|~
name|InternalScopedBuf
argument_list|()
block|{
name|internal_free
argument_list|(
name|ptr_
argument_list|)
block|;   }
name|operator
name|T
operator|*
operator|(
operator|)
block|{
return|return
name|ptr_
return|;
block|}
name|T
operator|&
name|operator
index|[]
operator|(
name|uptr
name|i
operator|)
block|{
return|return
name|ptr_
index|[
name|i
index|]
return|;
block|}
name|T
operator|*
name|Ptr
argument_list|()
block|{
return|return
name|ptr_
return|;
block|}
name|uptr
name|Count
argument_list|()
block|{
return|return
name|cnt_
return|;
block|}
name|uptr
name|Size
argument_list|()
block|{
return|return
name|cnt_
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
return|;
block|}
name|private
operator|:
name|T
operator|*
name|ptr_
block|;
name|uptr
name|cnt_
block|;
name|InternalScopedBuf
argument_list|(
specifier|const
name|InternalScopedBuf
operator|&
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|InternalScopedBuf
operator|&
operator|)
block|; }
expr_stmt|;
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

