begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PredIteratorCache.h - pred_iterator Cache ----------------*- C++ -*-===//
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
comment|// This file defines the PredIteratorCache class.
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
name|LLVM_IR_PREDITERATORCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_PREDITERATORCACHE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CFG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PredIteratorCache - This class is an extremely trivial cache for
comment|/// predecessor iterator queries.  This is useful for code that repeatedly
comment|/// wants the predecessor list for the same blocks.
name|class
name|PredIteratorCache
block|{
comment|/// BlockToPredsMap - Pointer to null-terminated list.
name|mutable
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|BasicBlock
operator|*
operator|*
operator|>
name|BlockToPredsMap
expr_stmt|;
name|mutable
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|BlockToPredCountMap
expr_stmt|;
comment|/// Memory - This is the space that holds cached preds.
name|BumpPtrAllocator
name|Memory
decl_stmt|;
name|private
label|:
comment|/// GetPreds - Get a cached list for the null-terminated predecessor list of
comment|/// the specified block.  This can be used in a loop like this:
comment|///   for (BasicBlock **PI = PredCache->GetPreds(BB); *PI; ++PI)
comment|///      use(*PI);
comment|/// instead of:
comment|/// for (pred_iterator PI = pred_begin(BB), E = pred_end(BB); PI != E; ++PI)
name|BasicBlock
modifier|*
modifier|*
name|GetPreds
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|BasicBlock
modifier|*
modifier|*
modifier|&
name|Entry
init|=
name|BlockToPredsMap
index|[
name|BB
index|]
decl_stmt|;
if|if
condition|(
name|Entry
condition|)
return|return
name|Entry
return|;
name|SmallVector
operator|<
name|BasicBlock
operator|*
operator|,
literal|32
operator|>
name|PredCache
argument_list|(
name|pred_begin
argument_list|(
name|BB
argument_list|)
argument_list|,
name|pred_end
argument_list|(
name|BB
argument_list|)
argument_list|)
expr_stmt|;
name|PredCache
operator|.
name|push_back
argument_list|(
name|nullptr
argument_list|)
expr_stmt|;
comment|// null terminator.
name|BlockToPredCountMap
index|[
name|BB
index|]
operator|=
name|PredCache
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
name|Entry
operator|=
name|Memory
operator|.
name|Allocate
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|PredCache
operator|.
name|size
argument_list|()
operator|)
expr_stmt|;
name|std
operator|::
name|copy
argument_list|(
name|PredCache
operator|.
name|begin
argument_list|()
argument_list|,
name|PredCache
operator|.
name|end
argument_list|()
argument_list|,
name|Entry
argument_list|)
expr_stmt|;
return|return
name|Entry
return|;
block|}
name|unsigned
name|GetNumPreds
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|auto
name|Result
init|=
name|BlockToPredCountMap
operator|.
name|find
argument_list|(
name|BB
argument_list|)
decl_stmt|;
if|if
condition|(
name|Result
operator|!=
name|BlockToPredCountMap
operator|.
name|end
argument_list|()
condition|)
return|return
name|Result
operator|->
name|second
return|;
return|return
name|BlockToPredCountMap
index|[
name|BB
index|]
operator|=
name|std
operator|::
name|distance
argument_list|(
name|pred_begin
argument_list|(
name|BB
argument_list|)
argument_list|,
name|pred_end
argument_list|(
name|BB
argument_list|)
argument_list|)
return|;
block|}
name|public
label|:
name|size_t
name|size
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|GetNumPreds
argument_list|(
name|BB
argument_list|)
return|;
block|}
name|ArrayRef
operator|<
name|BasicBlock
operator|*
operator|>
name|get
argument_list|(
argument|BasicBlock *BB
argument_list|)
block|{
return|return
name|makeArrayRef
argument_list|(
name|GetPreds
argument_list|(
name|BB
argument_list|)
argument_list|,
name|GetNumPreds
argument_list|(
name|BB
argument_list|)
argument_list|)
return|;
block|}
comment|/// clear - Remove all information.
name|void
name|clear
parameter_list|()
block|{
name|BlockToPredsMap
operator|.
name|clear
argument_list|()
expr_stmt|;
name|BlockToPredCountMap
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Memory
operator|.
name|Reset
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

