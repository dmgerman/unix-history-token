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
file|"llvm/ADT/SmallPtrSet.h"
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
name|raw_ostream
decl_stmt|;
comment|/// \brief Analysis pass providing branch probability information.
comment|///
comment|/// This is a function analysis pass which provides information on the relative
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
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
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
block|;
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M =
literal|0
argument_list|)
specifier|const
block|;
comment|/// \brief Get an edge's probability, relative to other out-edges of the Src.
comment|///
comment|/// This routine provides access to the fractional probability between zero
comment|/// (0%) and one (100%) of this edge executing, relative to other edges
comment|/// leaving the 'Src' block. The returned probability is never zero, and can
comment|/// only be one if the source block has only one successor.
name|BranchProbability
name|getEdgeProbability
argument_list|(
argument|const BasicBlock *Src
argument_list|,
argument|unsigned IndexInSuccessors
argument_list|)
specifier|const
block|;
comment|/// \brief Get the probability of going from Src to Dst.
comment|///
comment|/// It returns the sum of all probabilities for edges from Src to Dst.
name|BranchProbability
name|getEdgeProbability
argument_list|(
argument|const BasicBlock *Src
argument_list|,
argument|const BasicBlock *Dst
argument_list|)
specifier|const
block|;
comment|/// \brief Test if an edge is hot relative to other out-edges of the Src.
comment|///
comment|/// Check whether this edge out of the source block is 'hot'. We define hot
comment|/// as having a relative probability>= 80%.
name|bool
name|isEdgeHot
argument_list|(
argument|const BasicBlock *Src
argument_list|,
argument|const BasicBlock *Dst
argument_list|)
specifier|const
block|;
comment|/// \brief Retrieve the hot successor of a block if one exists.
comment|///
comment|/// Given a basic block, look through its successors and if one exists for
comment|/// which \see isEdgeHot would return true, return that successor block.
name|BasicBlock
operator|*
name|getHotSucc
argument_list|(
argument|BasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// \brief Print an edge's probability.
comment|///
comment|/// Retrieves an edge's probability similarly to \see getEdgeProbability, but
comment|/// then prints that probability to the provided stream. That stream is then
comment|/// returned.
name|raw_ostream
operator|&
name|printEdgeProbability
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const BasicBlock *Src
argument_list|,
argument|const BasicBlock *Dst
argument_list|)
specifier|const
block|;
comment|/// \brief Get the raw edge weight calculated for the edge.
comment|///
comment|/// This returns the raw edge weight. It is guaranteed to fall between 1 and
comment|/// UINT32_MAX. Note that the raw edge weight is not meaningful in isolation.
comment|/// This interface should be very carefully, and primarily by routines that
comment|/// are updating the analysis by later calling setEdgeWeight.
name|uint32_t
name|getEdgeWeight
argument_list|(
argument|const BasicBlock *Src
argument_list|,
argument|unsigned IndexInSuccessors
argument_list|)
specifier|const
block|;
comment|/// \brief Get the raw edge weight calculated for the block pair.
comment|///
comment|/// This returns the sum of all raw edge weights from Src to Dst.
comment|/// It is guaranteed to fall between 1 and UINT32_MAX.
name|uint32_t
name|getEdgeWeight
argument_list|(
argument|const BasicBlock *Src
argument_list|,
argument|const BasicBlock *Dst
argument_list|)
specifier|const
block|;
comment|/// \brief Set the raw edge weight for a given edge.
comment|///
comment|/// This allows a pass to explicitly set the edge weight for an edge. It can
comment|/// be used when updating the CFG to update and preserve the branch
comment|/// probability information. Read the implementation of how these edge
comment|/// weights are calculated carefully before using!
name|void
name|setEdgeWeight
argument_list|(
argument|const BasicBlock *Src
argument_list|,
argument|unsigned IndexInSuccessors
argument_list|,
argument|uint32_t Weight
argument_list|)
block|;
name|private
operator|:
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
operator|=
literal|16
decl_stmt|;
name|DenseMap
operator|<
name|Edge
operator|,
name|uint32_t
operator|>
name|Weights
expr_stmt|;
comment|/// \brief Handle to the LoopInfo analysis.
name|LoopInfo
modifier|*
name|LI
decl_stmt|;
comment|/// \brief Track the last function we run over for printing.
name|Function
modifier|*
name|LastF
decl_stmt|;
comment|/// \brief Track the set of blocks directly succeeded by a returning block.
name|SmallPtrSet
operator|<
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
name|BasicBlock
operator|*
operator|,
literal|16
operator|>
name|PostDominatedByColdCall
expr_stmt|;
comment|/// \brief Get sum of the block successors' weights.
name|uint32_t
name|getSumForBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|bool
name|calcUnreachableHeuristics
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcMetadataWeights
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcColdCallHeuristics
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcPointerHeuristics
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcLoopBranchHeuristics
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcZeroHeuristics
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcFloatingPointHeuristics
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|calcInvokeHeuristics
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
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

