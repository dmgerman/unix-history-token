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
file|"llvm/ADT/ArrayRef.h"
end_include

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

begin_include
include|#
directive|include
file|"llvm/IR/InstrTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryDependenceResults
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
comment|/// Delete the specified block, which must have no predecessors.
name|void
name|DeleteDeadBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// We know that BB has one predecessor. If there are any single-entry PHI nodes
comment|/// in it, fold them away. This handles the case when all entries to the PHI
comment|/// nodes in a block are guaranteed equal, such as when the block has exactly
comment|/// one predecessor.
name|void
name|FoldSingleEntryPHINodes
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|MemoryDependenceResults
modifier|*
name|MemDep
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Examine each PHI in the given block and delete it if it is dead. Also
comment|/// recursively delete any operands that become dead as a result. This includes
comment|/// tracing the def-use list from the PHI to see if it is ultimately unused or
comment|/// if it reaches an unused cycle. Return true if any PHIs were deleted.
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
comment|/// Attempts to merge a block into its predecessor, if possible. The return
comment|/// value indicates success or failure.
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
name|MemoryDependenceResults
modifier|*
name|MemDep
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Replace all uses of an instruction (specified by BI) with a value, then
comment|/// remove and delete the original instruction.
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
comment|/// Replace the instruction specified by BI with the instruction specified by I.
comment|/// Copies DebugLoc from BI to I, if I doesn't already have a DebugLoc. The
comment|/// original instruction is deleted and BI is updated to point to the new
comment|/// instruction.
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
comment|/// Replace the instruction specified by From with the instruction specified by
comment|/// To. Copies DebugLoc from BI to I, if I doesn't already have a DebugLoc.
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
comment|/// Option class for critical edge splitting.
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
init|=
name|false
decl_stmt|;
name|bool
name|DontDeleteUselessPHIs
init|=
name|false
decl_stmt|;
name|bool
name|PreserveLCSSA
init|=
name|false
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
argument|LI
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
comment|/// If this edge is a critical edge, insert a new node to split the critical
comment|/// edge. This will update the analyses passed in through the option struct.
comment|/// This returns the new block if the edge was split, null otherwise.
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
comment|/// If the edge from *PI to BB is not critical, return false. Otherwise, split
comment|/// all edges between the two blocks and return true. This updates all of the
comment|/// same analyses as the other SplitCriticalEdge function. If P is specified, it
comment|/// updates the analyses described above.
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
comment|/// If an edge from Src to Dst is critical, split the edge and return true,
comment|/// otherwise return false. This method requires that there be an edge between
comment|/// the two blocks. It updates the analyses passed in the options struct
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
name|true
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
comment|/// Loop over all of the edges in the CFG, breaking critical edges as they are
comment|/// found. Returns the number of broken edges.
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
comment|/// Split the edge connecting specified block.
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
comment|/// Split the specified block at the specified instruction - everything before
comment|/// SplitPt stays in Old and everything starting with SplitPt moves to a new
comment|/// block. The two blocks are joined by an unconditional branch and the loop
comment|/// info is updated.
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
comment|/// This method introduces at least one new basic block into the function and
comment|/// moves some of the predecessors of BB to be predecessors of the new block.
comment|/// The new predecessors are indicated by the Preds array. The new block is
comment|/// given a suffix of 'Suffix'. Returns new basic block to which predecessors
comment|/// from Preds are now pointing.
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
comment|/// This method transforms the landing pad, OrigBB, by introducing two new basic
comment|/// blocks into the function. One of those new basic blocks gets the
comment|/// predecessors listed in Preds. The other basic block gets the remaining
comment|/// predecessors of OrigBB. The landingpad instruction OrigBB is clone into both
comment|/// of the new basic blocks. The new blocks are given the suffixes 'Suffix1' and
comment|/// 'Suffix2', and are returned in the NewBBs vector.
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
comment|/// This method duplicates the specified return instruction into a predecessor
comment|/// which ends in an unconditional branch. If the return instruction returns a
comment|/// value defined by a PHI, propagate the right value into the return. It
comment|/// returns the new return instruction in the predecessor.
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
comment|/// Split the containing block at the specified instruction - everything before
comment|/// SplitBefore stays in the old basic block, and the rest of the instructions
comment|/// in the BB are moved to a new block. The two blocks are connected by a
comment|/// conditional branch (with value of Cmp being the condition).
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
comment|/// Updates DT and LI if given.
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
parameter_list|,
name|LoopInfo
modifier|*
name|LI
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
comment|/// Check whether BB is the merge point of a if-region.
comment|/// If so, return the boolean condition that determines which entry into
comment|/// BB will be taken.  Also, return by references the block that will be
comment|/// entered from if the condition is true, and the block that will be
comment|/// entered if the condition is false.
comment|///
comment|/// This does no checking to see if the true/false blocks have large or unsavory
comment|/// instructions in them.
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
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_BASICBLOCKUTILS_H
end_comment

end_unit

