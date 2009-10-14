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
name|LLVM_TRANSFORMS_UTILS_BASICBLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_BASICBLOCK_H
end_define

begin_comment
comment|// FIXME: Move to this file: BasicBlock::removePredecessor, BB::splitBasicBlock
end_comment

begin_include
include|#
directive|include
file|"llvm/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CFG.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Instruction
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|AliasAnalysis
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
parameter_list|)
function_decl|;
comment|/// DeleteDeadPHIs - Examine each PHI in the given block and delete it if it
comment|/// is dead. Also recursively delete any operands that become dead as
comment|/// a result. This includes tracing the def-use list from the PHI to see if
comment|/// it is ultimately unused or if it reaches an unused cycle.
name|void
name|DeleteDeadPHIs
parameter_list|(
name|BasicBlock
modifier|*
name|BB
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
name|Pass
modifier|*
name|P
init|=
literal|0
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
comment|// instruction specified by I.  The original instruction is deleted and BI is
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
comment|// instruction specified by To.
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
comment|/// CopyPrecedingStopPoint - If I is immediately preceded by a StopPoint,
comment|/// make a copy of the stoppoint before InsertPos (presumably before copying
comment|/// or moving I).
name|void
name|CopyPrecedingStopPoint
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|BasicBlock
operator|::
name|iterator
name|InsertPos
argument_list|)
decl_stmt|;
comment|/// FindAvailableLoadedValue - Scan the ScanBB block backwards (starting at the
comment|/// instruction before ScanFrom) checking to see if we have the value at the
comment|/// memory address *Ptr locally available within a small number of instructions.
comment|/// If the value is available, return it.
comment|///
comment|/// If not, return the iterator for the last validated instruction that the
comment|/// value would be live through.  If we scanned the entire block and didn't find
comment|/// something that invalidates *Ptr or provides it, ScanFrom would be left at
comment|/// begin() and this returns null.  ScanFrom could also be left
comment|///
comment|/// MaxInstsToScan specifies the maximum instructions to scan in the block.  If
comment|/// it is set to 0, it will scan the whole block. You can also optionally
comment|/// specify an alias analysis implementation, which makes this more precise.
name|Value
modifier|*
name|FindAvailableLoadedValue
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|BasicBlock
operator|*
name|ScanBB
argument_list|,
name|BasicBlock
operator|::
name|iterator
operator|&
name|ScanFrom
argument_list|,
name|unsigned
name|MaxInstsToScan
operator|=
literal|6
argument_list|,
name|AliasAnalysis
operator|*
name|AA
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// FindFunctionBackedges - Analyze the specified function to find all of the
comment|/// loop backedges in the function and return them.  This is a relatively cheap
comment|/// (compared to computing dominators and loop info) analysis.
comment|///
comment|/// The output is added to Result, as pairs of<from,to> edge info.
name|void
name|FindFunctionBackedges
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|BasicBlock
operator|*
argument_list|,
specifier|const
name|BasicBlock
operator|*
operator|>
expr|>
operator|&
name|Result
argument_list|)
decl_stmt|;
comment|// RemoveSuccessor - Change the specified terminator instruction such that its
comment|// successor #SuccNum no longer exists.  Because this reduces the outgoing
comment|// degree of the current basic block, the actual terminator instruction itself
comment|// may have to be changed.  In the case where the last successor of the block is
comment|// deleted, a return instruction is inserted in its place which can cause a
comment|// suprising change in program behavior if it is not expected.
comment|//
name|void
name|RemoveSuccessor
parameter_list|(
name|TerminatorInst
modifier|*
name|TI
parameter_list|,
name|unsigned
name|SuccNum
parameter_list|)
function_decl|;
comment|/// isCriticalEdge - Return true if the specified edge is a critical edge.
comment|/// Critical edges are edges from a block with multiple successors to a block
comment|/// with multiple predecessors.
comment|///
name|bool
name|isCriticalEdge
parameter_list|(
specifier|const
name|TerminatorInst
modifier|*
name|TI
parameter_list|,
name|unsigned
name|SuccNum
parameter_list|,
name|bool
name|AllowIdenticalEdges
init|=
name|false
parameter_list|)
function_decl|;
comment|/// SplitCriticalEdge - If this edge is a critical edge, insert a new node to
comment|/// split the critical edge.  This will update DominatorTree and
comment|/// DominatorFrontier information if it is available, thus calling this pass
comment|/// will not invalidate either of them. This returns true if the edge was split,
comment|/// false otherwise.
comment|///
comment|/// If MergeIdenticalEdges is true (not the default), *all* edges from TI to the
comment|/// specified successor will be merged into the same critical edge block.
comment|/// This is most commonly interesting with switch instructions, which may
comment|/// have many edges to any one destination.  This ensures that all edges to that
comment|/// dest go to one block instead of each going to a different block, but isn't
comment|/// the standard definition of a "critical edge".
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
name|Pass
modifier|*
name|P
init|=
literal|0
parameter_list|,
name|bool
name|MergeIdenticalEdges
init|=
name|false
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
name|Pass
modifier|*
name|P
init|=
literal|0
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
name|P
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
name|Pass
modifier|*
name|P
init|=
literal|0
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
name|P
argument_list|)
expr_stmt|;
return|return
name|MadeChange
return|;
block|}
comment|/// SplitCriticalEdge - If an edge from Src to Dst is critical, split the edge
comment|/// and return true, otherwise return false.  This method requires that there be
comment|/// an edge between the two blocks.  If P is specified, it updates the analyses
comment|/// described above.
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
name|Pass
modifier|*
name|P
init|=
literal|0
parameter_list|,
name|bool
name|MergeIdenticalEdges
init|=
name|false
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
name|P
argument_list|,
name|MergeIdenticalEdges
argument_list|)
return|;
operator|++
name|i
expr_stmt|;
block|}
block|}
comment|/// SplitEdge -  Split the edge connecting specified block. Pass P must
comment|/// not be NULL.
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
name|Pass
modifier|*
name|P
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
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// SplitBlockPredecessors - This method transforms BB by introducing a new
comment|/// basic block into the function, and moving some of the predecessors of BB to
comment|/// be predecessors of the new block.  The new predecessors are indicated by the
comment|/// Preds array, which has NumPreds elements in it.  The new block is given a
comment|/// suffix of 'Suffix'.  This function returns the new block.
comment|///
comment|/// This currently updates the LLVM IR, AliasAnalysis, DominatorTree,
comment|/// DominanceFrontier, LoopInfo, and LCCSA but no other analyses.
comment|/// In particular, it does not preserve LoopSimplify (because it's
comment|/// complicated to handle the case where one of the edges being split
comment|/// is an exit of a loop with other exits).
comment|///
name|BasicBlock
modifier|*
name|SplitBlockPredecessors
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|BasicBlock
modifier|*
specifier|const
modifier|*
name|Preds
parameter_list|,
name|unsigned
name|NumPreds
parameter_list|,
specifier|const
name|char
modifier|*
name|Suffix
parameter_list|,
name|Pass
modifier|*
name|P
init|=
literal|0
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

