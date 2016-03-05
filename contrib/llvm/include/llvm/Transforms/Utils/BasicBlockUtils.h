begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Transform/Utils/BasicBlockUtils.h - BasicBlock Utils ----*- C++ -*-===//
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
comment|// This family of functions perform manipulations on basic blocks, and
end_comment

begin_comment
comment|// instructions contained within basic blocks.
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
name|LLVM_TRANSFORMS_UTILS_BASICBLOCKUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_BASICBLOCKUTILS_H
end_define

begin_comment
comment|// FIXME: Move to this file: BasicBlock::removePredecessor, BB::splitBasicBlock
end_comment

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CFG.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryDependenceAnalysis
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|ReturnInst
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TerminatorInst
decl_stmt|;
comment|/// DeleteDeadBlock - Delete the specified block, which must have no
comment|/// predecessors.
name|void
name|DeleteDeadBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// FoldSingleEntryPHINodes - We know that BB has one predecessor.  If there are
comment|/// any single-entry PHI nodes in it, fold them away.  This handles the case
comment|/// when all entries to the PHI nodes in a block are guaranteed equal, such as
comment|/// when the block has exactly one predecessor.
name|void
name|FoldSingleEntryPHINodes
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|MemoryDependenceAnalysis
modifier|*
name|MemDep
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// DeleteDeadPHIs - Examine each PHI in the given block and delete it if it
comment|/// is dead. Also recursively delete any operands that become dead as
comment|/// a result. This includes tracing the def-use list from the PHI to see if
comment|/// it is ultimately unused or if it reaches an unused cycle. Return true
comment|/// if any PHIs were deleted.
name|bool
name|DeleteDeadPHIs
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// MergeBlockIntoPredecessor - Attempts to merge a block into its predecessor,
comment|/// if possible.  The return value indicates success or failure.
name|bool
name|MergeBlockIntoPredecessor
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|,
name|LoopInfo
modifier|*
name|LI
init|=
name|nullptr
parameter_list|,
name|MemoryDependenceAnalysis
modifier|*
name|MemDep
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|// ReplaceInstWithValue - Replace all uses of an instruction (specified by BI)
comment|// with a value, then remove and delete the original instruction.
comment|//
name|void
name|ReplaceInstWithValue
argument_list|(
name|BasicBlock
operator|::
name|InstListType
operator|&
name|BIL
argument_list|,
name|BasicBlock
operator|::
name|iterator
operator|&
name|BI
argument_list|,
name|Value
operator|*
name|V
argument_list|)
decl_stmt|;
comment|// ReplaceInstWithInst - Replace the instruction specified by BI with the
comment|// instruction specified by I. Copies DebugLoc from BI to I, if I doesn't
comment|// already have a DebugLoc. The original instruction is deleted and BI is
comment|// updated to point to the new instruction.
comment|//
name|void
name|ReplaceInstWithInst
argument_list|(
name|BasicBlock
operator|::
name|InstListType
operator|&
name|BIL
argument_list|,
name|BasicBlock
operator|::
name|iterator
operator|&
name|BI
argument_list|,
name|Instruction
operator|*
name|I
argument_list|)
decl_stmt|;
comment|// ReplaceInstWithInst - Replace the instruction specified by From with the
comment|// instruction specified by To. Copies DebugLoc from BI to I, if I doesn't
comment|// already have a DebugLoc.
comment|//
name|void
name|ReplaceInstWithInst
parameter_list|(
name|Instruction
modifier|*
name|From
parameter_list|,
name|Instruction
modifier|*
name|To
parameter_list|)
function_decl|;
comment|/// \brief Option class for critical edge splitting.
comment|///
comment|/// This provides a builder interface for overriding the default options used
comment|/// during critical edge splitting.
struct|struct
name|CriticalEdgeSplittingOptions
block|{
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
name|LoopInfo
modifier|*
name|LI
decl_stmt|;
name|bool
name|MergeIdenticalEdges
decl_stmt|;
name|bool
name|DontDeleteUselessPHIs
decl_stmt|;
name|bool
name|PreserveLCSSA
decl_stmt|;
name|CriticalEdgeSplittingOptions
argument_list|(
name|DominatorTree
operator|*
name|DT
operator|=
name|nullptr
argument_list|,
name|LoopInfo
operator|*
name|LI
operator|=
name|nullptr
argument_list|)
operator|:
name|DT
argument_list|(
name|DT
argument_list|)
operator|,
name|LI
argument_list|(
name|LI
argument_list|)
operator|,
name|MergeIdenticalEdges
argument_list|(
name|false
argument_list|)
operator|,
name|DontDeleteUselessPHIs
argument_list|(
name|false
argument_list|)
operator|,
name|PreserveLCSSA
argument_list|(
argument|false
argument_list|)
block|{}
name|CriticalEdgeSplittingOptions
operator|&
name|setMergeIdenticalEdges
argument_list|()
block|{
name|MergeIdenticalEdges
operator|=
name|true
block|;
return|return
operator|*
name|this
return|;
block|}
name|CriticalEdgeSplittingOptions
modifier|&
name|setDontDeleteUselessPHIs
parameter_list|()
block|{
name|DontDeleteUselessPHIs
operator|=
name|true
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|CriticalEdgeSplittingOptions
modifier|&
name|setPreserveLCSSA
parameter_list|()
block|{
name|PreserveLCSSA
operator|=
name|true
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
block|}
struct|;
comment|/// SplitCriticalEdge - If this edge is a critical edge, insert a new node to
comment|/// split the critical edge.  This will update the analyses passed in through
comment|/// the option struct. This returns the new block if the edge was split, null
comment|/// otherwise.
comment|///
comment|/// If MergeIdenticalEdges in the options struct is true (not the default),
comment|/// *all* edges from TI to the specified successor will be merged into the same
comment|/// critical edge block. This is most commonly interesting with switch
comment|/// instructions, which may have many edges to any one destination.  This
comment|/// ensures that all edges to that dest go to one block instead of each going
comment|/// to a different block, but isn't the standard definition of a "critical
comment|/// edge".
comment|///
comment|/// It is invalid to call this function on a critical edge that starts at an
comment|/// IndirectBrInst.  Splitting these edges will almost always create an invalid
comment|/// program because the address of the new block won't be the one that is jumped
comment|/// to.
comment|///
name|BasicBlock
modifier|*
name|SplitCriticalEdge
parameter_list|(
name|TerminatorInst
modifier|*
name|TI
parameter_list|,
name|unsigned
name|SuccNum
parameter_list|,
specifier|const
name|CriticalEdgeSplittingOptions
modifier|&
name|Options
init|=
name|CriticalEdgeSplittingOptions
argument_list|()
parameter_list|)
function_decl|;
specifier|inline
name|BasicBlock
modifier|*
name|SplitCriticalEdge
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|succ_iterator
name|SI
parameter_list|,
specifier|const
name|CriticalEdgeSplittingOptions
modifier|&
name|Options
init|=
name|CriticalEdgeSplittingOptions
argument_list|()
parameter_list|)
block|{
return|return
name|SplitCriticalEdge
argument_list|(
name|BB
operator|->
name|getTerminator
argument_list|()
argument_list|,
name|SI
operator|.
name|getSuccessorIndex
argument_list|()
argument_list|,
name|Options
argument_list|)
return|;
block|}
comment|/// SplitCriticalEdge - If the edge from *PI to BB is not critical, return
comment|/// false.  Otherwise, split all edges between the two blocks and return true.
comment|/// This updates all of the same analyses as the other SplitCriticalEdge
comment|/// function.  If P is specified, it updates the analyses
comment|/// described above.
specifier|inline
name|bool
name|SplitCriticalEdge
parameter_list|(
name|BasicBlock
modifier|*
name|Succ
parameter_list|,
name|pred_iterator
name|PI
parameter_list|,
specifier|const
name|CriticalEdgeSplittingOptions
modifier|&
name|Options
init|=
name|CriticalEdgeSplittingOptions
argument_list|()
parameter_list|)
block|{
name|bool
name|MadeChange
init|=
name|false
decl_stmt|;
name|TerminatorInst
modifier|*
name|TI
init|=
operator|(
operator|*
name|PI
operator|)
operator|->
name|getTerminator
argument_list|()
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|TI
operator|->
name|getNumSuccessors
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|TI
operator|->
name|getSuccessor
argument_list|(
name|i
argument_list|)
operator|==
name|Succ
condition|)
name|MadeChange
operator||=
operator|!
operator|!
name|SplitCriticalEdge
argument_list|(
name|TI
argument_list|,
name|i
argument_list|,
name|Options
argument_list|)
expr_stmt|;
return|return
name|MadeChange
return|;
block|}
comment|/// SplitCriticalEdge - If an edge from Src to Dst is critical, split the edge
comment|/// and return true, otherwise return false.  This method requires that there be
comment|/// an edge between the two blocks.  It updates the analyses
comment|/// passed in the options struct
specifier|inline
name|BasicBlock
modifier|*
name|SplitCriticalEdge
parameter_list|(
name|BasicBlock
modifier|*
name|Src
parameter_list|,
name|BasicBlock
modifier|*
name|Dst
parameter_list|,
specifier|const
name|CriticalEdgeSplittingOptions
modifier|&
name|Options
init|=
name|CriticalEdgeSplittingOptions
argument_list|()
parameter_list|)
block|{
name|TerminatorInst
modifier|*
name|TI
init|=
name|Src
operator|->
name|getTerminator
argument_list|()
decl_stmt|;
name|unsigned
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|assert
argument_list|(
name|i
operator|!=
name|TI
operator|->
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Edge doesn't exist!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|TI
operator|->
name|getSuccessor
argument_list|(
name|i
argument_list|)
operator|==
name|Dst
condition|)
return|return
name|SplitCriticalEdge
argument_list|(
name|TI
argument_list|,
name|i
argument_list|,
name|Options
argument_list|)
return|;
operator|++
name|i
expr_stmt|;
block|}
block|}
comment|// SplitAllCriticalEdges - Loop over all of the edges in the CFG,
comment|// breaking critical edges as they are found.
comment|// Returns the number of broken edges.
name|unsigned
name|SplitAllCriticalEdges
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
specifier|const
name|CriticalEdgeSplittingOptions
modifier|&
name|Options
init|=
name|CriticalEdgeSplittingOptions
argument_list|()
parameter_list|)
function_decl|;
comment|/// SplitEdge -  Split the edge connecting specified block.
name|BasicBlock
modifier|*
name|SplitEdge
parameter_list|(
name|BasicBlock
modifier|*
name|From
parameter_list|,
name|BasicBlock
modifier|*
name|To
parameter_list|,
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|,
name|LoopInfo
modifier|*
name|LI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// SplitBlock - Split the specified block at the specified instruction - every
comment|/// thing before SplitPt stays in Old and everything starting with SplitPt moves
comment|/// to a new block.  The two blocks are joined by an unconditional branch and
comment|/// the loop info is updated.
comment|///
name|BasicBlock
modifier|*
name|SplitBlock
parameter_list|(
name|BasicBlock
modifier|*
name|Old
parameter_list|,
name|Instruction
modifier|*
name|SplitPt
parameter_list|,
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|,
name|LoopInfo
modifier|*
name|LI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// SplitBlockPredecessors - This method introduces at least one new basic block
comment|/// into the function and moves some of the predecessors of BB to be
comment|/// predecessors of the new block. The new predecessors are indicated by the
comment|/// Preds array. The new block is given a suffix of 'Suffix'. Returns new basic
comment|/// block to which predecessors from Preds are now pointing.
comment|///
comment|/// If BB is a landingpad block then additional basicblock might be introduced.
comment|/// It will have Suffix+".split_lp". See SplitLandingPadPredecessors for more
comment|/// details on this case.
comment|///
comment|/// This currently updates the LLVM IR, DominatorTree, LoopInfo, and LCCSA but
comment|/// no other analyses. In particular, it does not preserve LoopSimplify
comment|/// (because it's complicated to handle the case where one of the edges being
comment|/// split is an exit of a loop with other exits).
comment|///
name|BasicBlock
modifier|*
name|SplitBlockPredecessors
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|ArrayRef
operator|<
name|BasicBlock
operator|*
operator|>
name|Preds
argument_list|,
specifier|const
name|char
operator|*
name|Suffix
argument_list|,
name|DominatorTree
operator|*
name|DT
operator|=
name|nullptr
argument_list|,
name|LoopInfo
operator|*
name|LI
operator|=
name|nullptr
argument_list|,
name|bool
name|PreserveLCSSA
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// SplitLandingPadPredecessors - This method transforms the landing pad,
comment|/// OrigBB, by introducing two new basic blocks into the function. One of those
comment|/// new basic blocks gets the predecessors listed in Preds. The other basic
comment|/// block gets the remaining predecessors of OrigBB. The landingpad instruction
comment|/// OrigBB is clone into both of the new basic blocks. The new blocks are given
comment|/// the suffixes 'Suffix1' and 'Suffix2', and are returned in the NewBBs vector.
comment|///
comment|/// This currently updates the LLVM IR, DominatorTree, LoopInfo, and LCCSA but
comment|/// no other analyses. In particular, it does not preserve LoopSimplify
comment|/// (because it's complicated to handle the case where one of the edges being
comment|/// split is an exit of a loop with other exits).
comment|///
name|void
name|SplitLandingPadPredecessors
argument_list|(
name|BasicBlock
operator|*
name|OrigBB
argument_list|,
name|ArrayRef
operator|<
name|BasicBlock
operator|*
operator|>
name|Preds
argument_list|,
specifier|const
name|char
operator|*
name|Suffix
argument_list|,
specifier|const
name|char
operator|*
name|Suffix2
argument_list|,
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|NewBBs
argument_list|,
name|DominatorTree
operator|*
name|DT
operator|=
name|nullptr
argument_list|,
name|LoopInfo
operator|*
name|LI
operator|=
name|nullptr
argument_list|,
name|bool
name|PreserveLCSSA
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// FoldReturnIntoUncondBranch - This method duplicates the specified return
comment|/// instruction into a predecessor which ends in an unconditional branch. If
comment|/// the return instruction returns a value defined by a PHI, propagate the
comment|/// right value into the return. It returns the new return instruction in the
comment|/// predecessor.
name|ReturnInst
modifier|*
name|FoldReturnIntoUncondBranch
parameter_list|(
name|ReturnInst
modifier|*
name|RI
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|BasicBlock
modifier|*
name|Pred
parameter_list|)
function_decl|;
comment|/// SplitBlockAndInsertIfThen - Split the containing block at the
comment|/// specified instruction - everything before and including SplitBefore stays
comment|/// in the old basic block, and everything after SplitBefore is moved to a
comment|/// new block. The two blocks are connected by a conditional branch
comment|/// (with value of Cmp being the condition).
comment|/// Before:
comment|///   Head
comment|///   SplitBefore
comment|///   Tail
comment|/// After:
comment|///   Head
comment|///   if (Cond)
comment|///     ThenBlock
comment|///   SplitBefore
comment|///   Tail
comment|///
comment|/// If Unreachable is true, then ThenBlock ends with
comment|/// UnreachableInst, otherwise it branches to Tail.
comment|/// Returns the NewBasicBlock's terminator.
comment|///
comment|/// Updates DT if given.
name|TerminatorInst
modifier|*
name|SplitBlockAndInsertIfThen
parameter_list|(
name|Value
modifier|*
name|Cond
parameter_list|,
name|Instruction
modifier|*
name|SplitBefore
parameter_list|,
name|bool
name|Unreachable
parameter_list|,
name|MDNode
modifier|*
name|BranchWeights
init|=
name|nullptr
parameter_list|,
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// SplitBlockAndInsertIfThenElse is similar to SplitBlockAndInsertIfThen,
comment|/// but also creates the ElseBlock.
comment|/// Before:
comment|///   Head
comment|///   SplitBefore
comment|///   Tail
comment|/// After:
comment|///   Head
comment|///   if (Cond)
comment|///     ThenBlock
comment|///   else
comment|///     ElseBlock
comment|///   SplitBefore
comment|///   Tail
name|void
name|SplitBlockAndInsertIfThenElse
parameter_list|(
name|Value
modifier|*
name|Cond
parameter_list|,
name|Instruction
modifier|*
name|SplitBefore
parameter_list|,
name|TerminatorInst
modifier|*
modifier|*
name|ThenTerm
parameter_list|,
name|TerminatorInst
modifier|*
modifier|*
name|ElseTerm
parameter_list|,
name|MDNode
modifier|*
name|BranchWeights
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|///
comment|/// GetIfCondition - Check whether BB is the merge point of a if-region.
comment|/// If so, return the boolean condition that determines which entry into
comment|/// BB will be taken.  Also, return by references the block that will be
comment|/// entered from if the condition is true, and the block that will be
comment|/// entered if the condition is false.
name|Value
modifier|*
name|GetIfCondition
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|BasicBlock
modifier|*
modifier|&
name|IfTrue
parameter_list|,
name|BasicBlock
modifier|*
modifier|&
name|IfFalse
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

