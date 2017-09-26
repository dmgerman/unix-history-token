begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IteratedDominanceFrontier.h - Calculate IDF --------------*- C++ -*-===//
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
comment|/// \brief Compute iterated dominance frontiers using a linear time algorithm.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The algorithm used here is based on:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Sreedhar and Gao. A linear time algorithm for placing phi-nodes.
end_comment

begin_comment
comment|///   In Proceedings of the 22nd ACM SIGPLAN-SIGACT Symposium on Principles of
end_comment

begin_comment
comment|///   Programming Languages
end_comment

begin_comment
comment|///   POPL '95. ACM, New York, NY, 62-73.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It has been modified to not explicitly use the DJ graph data structure and
end_comment

begin_comment
comment|/// to directly compute pruned SSA using per-variable liveness information.
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
name|LLVM_ANALYSIS_IDF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_IDF_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Determine the iterated dominance frontier, given a set of defining
comment|/// blocks, and optionally, a set of live-in blocks.
comment|///
comment|/// In turn, the results can be used to place phi nodes.
comment|///
comment|/// This algorithm is a linear time computation of Iterated Dominance Frontiers,
comment|/// pruned using the live-in set.
comment|/// By default, liveness is not used to prune the IDF computation.
comment|/// The template parameters should be either BasicBlock* or Inverse<BasicBlock
comment|/// *>, depending on if you want the forward or reverse IDF.
name|template
operator|<
name|class
name|NodeTy
operator|,
name|bool
name|IsPostDom
operator|>
name|class
name|IDFCalculator
block|{
name|public
operator|:
name|IDFCalculator
argument_list|(
name|DominatorTreeBase
operator|<
name|BasicBlock
argument_list|,
name|IsPostDom
operator|>
operator|&
name|DT
argument_list|)
operator|:
name|DT
argument_list|(
name|DT
argument_list|)
block|,
name|useLiveIn
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Give the IDF calculator the set of blocks in which the value is
comment|/// defined.  This is equivalent to the set of starting blocks it should be
comment|/// calculating the IDF for (though later gets pruned based on liveness).
comment|///
comment|/// Note: This set *must* live for the entire lifetime of the IDF calculator.
name|void
name|setDefiningBlocks
argument_list|(
argument|const SmallPtrSetImpl<BasicBlock *>&Blocks
argument_list|)
block|{
name|DefBlocks
operator|=
operator|&
name|Blocks
block|;   }
comment|/// \brief Give the IDF calculator the set of blocks in which the value is
comment|/// live on entry to the block.   This is used to prune the IDF calculation to
comment|/// not include blocks where any phi insertion would be dead.
comment|///
comment|/// Note: This set *must* live for the entire lifetime of the IDF calculator.
name|void
name|setLiveInBlocks
argument_list|(
argument|const SmallPtrSetImpl<BasicBlock *>&Blocks
argument_list|)
block|{
name|LiveInBlocks
operator|=
operator|&
name|Blocks
block|;
name|useLiveIn
operator|=
name|true
block|;   }
comment|/// \brief Reset the live-in block set to be empty, and tell the IDF
comment|/// calculator to not use liveness anymore.
name|void
name|resetLiveInBlocks
argument_list|()
block|{
name|LiveInBlocks
operator|=
name|nullptr
block|;
name|useLiveIn
operator|=
name|false
block|;   }
comment|/// \brief Calculate iterated dominance frontiers
comment|///
comment|/// This uses the linear-time phi algorithm based on DJ-graphs mentioned in
comment|/// the file-level comment.  It performs DF->IDF pruning using the live-in
comment|/// set, to avoid computing the IDF for blocks where an inserted PHI node
comment|/// would be dead.
name|void
name|calculate
argument_list|(
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|IDFBlocks
argument_list|)
block|;
name|private
operator|:
name|DominatorTreeBase
operator|<
name|BasicBlock
block|,
name|IsPostDom
operator|>
operator|&
name|DT
block|;
name|bool
name|useLiveIn
block|;
specifier|const
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|*
name|LiveInBlocks
block|;
specifier|const
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|*
name|DefBlocks
block|; }
expr_stmt|;
typedef|typedef
name|IDFCalculator
operator|<
name|BasicBlock
operator|*
operator|,
name|false
operator|>
name|ForwardIDFCalculator
expr_stmt|;
typedef|typedef
name|IDFCalculator
operator|<
name|Inverse
operator|<
name|BasicBlock
operator|*
operator|>
operator|,
name|true
operator|>
name|ReverseIDFCalculator
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

