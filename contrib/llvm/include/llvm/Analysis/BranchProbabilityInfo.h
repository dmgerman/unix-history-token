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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CFG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

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
file|"llvm/Support/BranchProbability.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LoopInfo
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Analysis providing branch probability information.
comment|///
comment|/// This is a function analysis which provides information on the relative
comment|/// probabilities of each "edge" in the function's CFG where such an edge is
comment|/// defined by a pair (PredBlock and an index in the successors). The
comment|/// probability of an edge from one block is always relative to the
comment|/// probabilities of other edges from the block. The probabilites of all edges
comment|/// from a block sum to exactly one (100%).
comment|/// We use a pair (PredBlock and an index in the successors) to uniquely
comment|/// identify an edge, since we can have multiple edges from Src to Dst.
comment|/// As an example, we can have a switch which jumps to Dst with value 0 and
comment|/// value 10.
name|class
name|BranchProbabilityInfo
block|{
name|public
label|:
name|BranchProbabilityInfo
argument_list|()
block|{}
name|BranchProbabilityInfo
argument_list|(
argument|const Function&F
argument_list|,
argument|const LoopInfo&LI
argument_list|,
argument|const TargetLibraryInfo *TLI = nullptr
argument_list|)
block|{
name|calculate
argument_list|(
name|F
argument_list|,
name|LI
argument_list|,
name|TLI
argument_list|)
expr_stmt|;
block|}
name|BranchProbabilityInfo
argument_list|(
name|BranchProbabilityInfo
operator|&&
name|Arg
argument_list|)
operator|:
name|Probs
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|Probs
argument_list|)
argument_list|)
operator|,
name|LastF
argument_list|(
name|Arg
operator|.
name|LastF
argument_list|)
operator|,
name|PostDominatedByUnreachable
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|PostDominatedByUnreachable
argument_list|)
argument_list|)
operator|,
name|PostDominatedByColdCall
argument_list|(
argument|std::move(Arg.PostDominatedByColdCall)
argument_list|)
block|{}
name|BranchProbabilityInfo
operator|&
name|operator
operator|=
operator|(
name|BranchProbabilityInfo
operator|&&
name|RHS
operator|)
block|{
name|releaseMemory
argument_list|()
block|;
name|Probs
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|Probs
argument_list|)
block|;
name|PostDominatedByColdCall
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|PostDominatedByColdCall
argument_list|)
block|;
name|PostDominatedByUnreachable
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|PostDominatedByUnreachable
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|releaseMemory
parameter_list|()
function_decl|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get an edge's probability, relative to other out-edges of the Src.
comment|///
comment|/// This routine provides access to the fractional probability between zero
comment|/// (0%) and one (100%) of this edge executing, relative to other edges
comment|/// leaving the 'Src' block. The returned probability is never zero, and can
comment|/// only be one if the source block has only one successor.
name|BranchProbability
name|getEdgeProbability
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|Src
argument_list|,
name|unsigned
name|IndexInSuccessors
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the probability of going from Src to Dst.
comment|///
comment|/// It returns the sum of all probabilities for edges from Src to Dst.
name|BranchProbability
name|getEdgeProbability
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|Src
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|Dst
argument_list|)
decl|const
decl_stmt|;
name|BranchProbability
name|getEdgeProbability
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|Src
argument_list|,
name|succ_const_iterator
name|Dst
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Test if an edge is hot relative to other out-edges of the Src.
comment|///
comment|/// Check whether this edge out of the source block is 'hot'. We define hot
comment|/// as having a relative probability>= 80%.
name|bool
name|isEdgeHot
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|Src
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|Dst
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve the hot successor of a block if one exists.
comment|///
comment|/// Given a basic block, look through its successors and if one exists for
comment|/// which \see isEdgeHot would return true, return that successor block.
specifier|const
name|BasicBlock
modifier|*
name|getHotSucc
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Print an edge's probability.
comment|///
comment|/// Retrieves an edge's probability similarly to \see getEdgeProbability, but
comment|/// then prints that probability to the provided stream. That stream is then
comment|/// returned.
name|raw_ostream
modifier|&
name|printEdgeProbability
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|Src
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|Dst
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Set the raw edge probability for the given edge.
comment|///
comment|/// This allows a pass to explicitly set the edge probability for an edge. It
comment|/// can be used when updating the CFG to update and preserve the branch
comment|/// probability information. Read the implementation of how these edge
comment|/// probabilities are calculated carefully before using!
name|void
name|setEdgeProbability
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|Src
parameter_list|,
name|unsigned
name|IndexInSuccessors
parameter_list|,
name|BranchProbability
name|Prob
parameter_list|)
function_decl|;
specifier|static
name|BranchProbability
name|getBranchProbStackProtector
parameter_list|(
name|bool
name|IsLikely
parameter_list|)
block|{
specifier|static
specifier|const
name|BranchProbability
name|LikelyProb
argument_list|(
operator|(
literal|1u
operator|<<
literal|20
operator|)
operator|-
literal|1
argument_list|,
literal|1u
operator|<<
literal|20
argument_list|)
decl_stmt|;
return|return
name|IsLikely
condition|?
name|LikelyProb
else|:
name|LikelyProb
operator|.
name|getCompl
argument_list|()
return|;
block|}
name|void
name|calculate
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
specifier|const
name|LoopInfo
modifier|&
name|LI
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Forget analysis results for the given basic block.
name|void
name|eraseBlock
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|operator
init|=
operator|(
specifier|const
name|BranchProbabilityInfo
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|BranchProbabilityInfo
argument_list|(
specifier|const
name|BranchProbabilityInfo
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|// We need to store CallbackVH's in order to correctly handle basic block
comment|// removal.
name|class
name|BasicBlockCallbackVH
name|final
range|:
name|public
name|CallbackVH
block|{
name|BranchProbabilityInfo
operator|*
name|BPI
block|;
name|void
name|deleted
argument_list|()
name|override
block|{
name|assert
argument_list|(
name|BPI
operator|!=
name|nullptr
argument_list|)
block|;
name|BPI
operator|->
name|eraseBlock
argument_list|(
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|getValPtr
argument_list|()
operator|)
argument_list|)
block|;
name|BPI
operator|->
name|Handles
operator|.
name|erase
argument_list|(
operator|*
name|this
argument_list|)
block|;     }
name|public
operator|:
name|BasicBlockCallbackVH
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
name|BranchProbabilityInfo
operator|*
name|BPI
operator|=
name|nullptr
argument_list|)
operator|:
name|CallbackVH
argument_list|(
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|V
operator|)
argument_list|)
block|,
name|BPI
argument_list|(
argument|BPI
argument_list|)
block|{}
block|}
decl_stmt|;
name|DenseSet
operator|<
name|BasicBlockCallbackVH
operator|,
name|DenseMapInfo
operator|<
name|Value
operator|*
operator|>>
name|Handles
expr_stmt|;
comment|// Since we allow duplicate edges from one basic block to another, we use
comment|// a pair (PredBlock and an index in the successors) to specify an edge.
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|Edge
expr_stmt|;
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
init|=
literal|16
decl_stmt|;
name|DenseMap
operator|<
name|Edge
operator|,
name|BranchProbability
operator|>
name|Probs
expr_stmt|;
comment|/// \brief Track the last function we run over for printing.
specifier|const
name|Function
modifier|*
name|LastF
decl_stmt|;
comment|/// \brief Track the set of blocks directly succeeded by a returning block.
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
literal|16
operator|>
name|PostDominatedByUnreachable
expr_stmt|;
comment|/// \brief Track the set of blocks that always lead to a cold call.
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
literal|16
operator|>
name|PostDominatedByColdCall
expr_stmt|;
name|void
name|updatePostDominatedByUnreachable
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|void
name|updatePostDominatedByColdCall
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcUnreachableHeuristics
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcMetadataWeights
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcColdCallHeuristics
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcPointerHeuristics
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcLoopBranchHeuristics
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|,
specifier|const
name|LoopInfo
modifier|&
name|LI
parameter_list|)
function_decl|;
name|bool
name|calcZeroHeuristics
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
parameter_list|)
function_decl|;
name|bool
name|calcFloatingPointHeuristics
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcInvokeHeuristics
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Analysis pass which computes \c BranchProbabilityInfo.
name|class
name|BranchProbabilityAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|BranchProbabilityAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|BranchProbabilityAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// \brief Provide the result typedef for this analysis pass.
typedef|typedef
name|BranchProbabilityInfo
name|Result
typedef|;
comment|/// \brief Run the analysis pass over a function and produce BPI.
name|BranchProbabilityInfo
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Printer pass for the \c BranchProbabilityAnalysis results.
end_comment

begin_decl_stmt
name|class
name|BranchProbabilityPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|BranchProbabilityPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|BranchProbabilityPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Legacy analysis pass which computes \c BranchProbabilityInfo.
end_comment

begin_decl_stmt
name|class
name|BranchProbabilityInfoWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|BranchProbabilityInfo
name|BPI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|BranchProbabilityInfoWrapperPass
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeBranchProbabilityInfoWrapperPassPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|BranchProbabilityInfo
operator|&
name|getBPI
argument_list|()
block|{
return|return
name|BPI
return|;
block|}
specifier|const
name|BranchProbabilityInfo
operator|&
name|getBPI
argument_list|()
specifier|const
block|{
return|return
name|BPI
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M = nullptr
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

