begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BranchProbabilityInfo.h - Branch Probability Analysis --*- C++ -*-===//
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
comment|// This pass is used to evaluate branch probabilties.
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
name|LLVM_ANALYSIS_BRANCHPROBABILITYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_BRANCHPROBABILITYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/InitializePasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BranchProbability.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|BranchProbabilityInfo
range|:
name|public
name|FunctionPass
block|{
comment|// Default weight value. Used when we don't have information about the edge.
comment|// TODO: DEFAULT_WEIGHT makes sense during static predication, when none of
comment|// the successors have a weight yet. But it doesn't make sense when providing
comment|// weight to an edge that may have siblings with non-zero weights. This can
comment|// be handled various ways, but it's probably fine for an edge with unknown
comment|// weight to just "inherit" the non-zero weight of an adjacent successor.
specifier|static
specifier|const
name|uint32_t
name|DEFAULT_WEIGHT
operator|=
literal|16
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
operator|,
name|BasicBlock
operator|*
operator|>
name|Edge
expr_stmt|;
name|DenseMap
operator|<
name|Edge
block|,
name|uint32_t
operator|>
name|Weights
decl_stmt|;
comment|// Get sum of the block successors' weights.
name|uint32_t
name|getSumForBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
name|BranchProbabilityInfo
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeBranchProbabilityInfoPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|runOnFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|// Returned value is between 1 and UINT32_MAX. Look at
comment|// BranchProbabilityInfo.cpp for details.
name|uint32_t
name|getEdgeWeight
argument_list|(
name|BasicBlock
operator|*
name|Src
argument_list|,
name|BasicBlock
operator|*
name|Dst
argument_list|)
decl|const
decl_stmt|;
comment|// Look at BranchProbabilityInfo.cpp for details. Use it with caution!
name|void
name|setEdgeWeight
parameter_list|(
name|BasicBlock
modifier|*
name|Src
parameter_list|,
name|BasicBlock
modifier|*
name|Dst
parameter_list|,
name|uint32_t
name|Weight
parameter_list|)
function_decl|;
comment|// A 'Hot' edge is an edge which probability is>= 80%.
name|bool
name|isEdgeHot
argument_list|(
name|BasicBlock
operator|*
name|Src
argument_list|,
name|BasicBlock
operator|*
name|Dst
argument_list|)
decl|const
decl_stmt|;
comment|// Return a hot successor for the block BB or null if there isn't one.
name|BasicBlock
modifier|*
name|getHotSucc
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|// Return a probability as a fraction between 0 (0% probability) and
comment|// 1 (100% probability), however the value is never equal to 0, and can be 1
comment|// only iff SRC block has only one successor.
name|BranchProbability
name|getEdgeProbability
argument_list|(
name|BasicBlock
operator|*
name|Src
argument_list|,
name|BasicBlock
operator|*
name|Dst
argument_list|)
decl|const
decl_stmt|;
comment|// Print value between 0 (0% probability) and 1 (100% probability),
comment|// however the value is never equal to 0, and can be 1 only iff SRC block
comment|// has only one successor.
name|raw_ostream
modifier|&
name|printEdgeProbability
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|BasicBlock
operator|*
name|Src
argument_list|,
name|BasicBlock
operator|*
name|Dst
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

