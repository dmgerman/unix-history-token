begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Analysis/CFG.h - BasicBlock Analyses --------------------*- C++ -*-===//
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
comment|// This family of functions performs analyses on basic blocks, and instructions
end_comment

begin_comment
comment|// contained within basic blocks.
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
name|LLVM_ANALYSIS_CFG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CFG_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
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
name|BasicBlock
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|TerminatorInst
decl_stmt|;
comment|/// Analyze the specified function to find all of the loop backedges in the
comment|/// function and return them.  This is a relatively cheap (compared to
comment|/// computing dominators and loop info) analysis.
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
comment|/// Search for the specified successor of basic block BB and return its position
comment|/// in the terminator instruction's list of successors.  It is an error to call
comment|/// this with a block that is not a successor.
name|unsigned
name|GetSuccessorNumber
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|BasicBlock
modifier|*
name|Succ
parameter_list|)
function_decl|;
comment|/// Return true if the specified edge is a critical edge. Critical edges are
comment|/// edges from a block with multiple successors to a block with multiple
comment|/// predecessors.
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
comment|/// \brief Determine whether instruction 'To' is reachable from 'From',
comment|/// returning true if uncertain.
comment|///
comment|/// Determine whether there is a path from From to To within a single function.
comment|/// Returns false only if we can prove that once 'From' has been executed then
comment|/// 'To' can not be executed. Conservatively returns true.
comment|///
comment|/// This function is linear with respect to the number of blocks in the CFG,
comment|/// walking down successors from From to reach To, with a fixed threshold.
comment|/// Using DT or LI allows us to answer more quickly. LI reduces the cost of
comment|/// an entire loop of any number of blocsk to be the same as the cost of a
comment|/// single block. DT reduces the cost by allowing the search to terminate when
comment|/// we find a block that dominates the block containing 'To'. DT is most useful
comment|/// on branchy code but not loops, and LI is most useful on code with loops but
comment|/// does not help on branchy code outside loops.
name|bool
name|isPotentiallyReachable
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|From
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|To
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|,
specifier|const
name|LoopInfo
modifier|*
name|LI
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Determine whether block 'To' is reachable from 'From', returning
comment|/// true if uncertain.
comment|///
comment|/// Determine whether there is a path from From to To within a single function.
comment|/// Returns false only if we can prove that once 'From' has been reached then
comment|/// 'To' can not be executed. Conservatively returns true.
name|bool
name|isPotentiallyReachable
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|From
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|To
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|,
specifier|const
name|LoopInfo
modifier|*
name|LI
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

