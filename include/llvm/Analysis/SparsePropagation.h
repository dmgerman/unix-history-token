begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SparsePropagation.h - Sparse Conditional Property Propagation ------===//
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
comment|// This file implements an abstract sparse conditional propagation algorithm,
end_comment

begin_comment
comment|// modeled after SCCP, but with a customizable lattice function.
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
name|LLVM_ANALYSIS_SPARSE_PROPAGATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_SPARSE_PROPAGATION_H
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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Argument
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|PHINode
decl_stmt|;
name|class
name|TerminatorInst
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|SparseSolver
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// AbstractLatticeFunction - This class is implemented by the dataflow instance
comment|/// to specify what the lattice values are and how they handle merges etc.
comment|/// This gives the client the power to compute lattice values from instructions,
comment|/// constants, etc.  The requirement is that lattice values must all fit into
comment|/// a void*.  If a void* is not sufficient, the implementation should use this
comment|/// pointer to be a pointer into a uniquing set or something.
comment|///
name|class
name|AbstractLatticeFunction
block|{
name|public
label|:
typedef|typedef
name|void
modifier|*
name|LatticeVal
typedef|;
name|private
label|:
name|LatticeVal
name|UndefVal
decl_stmt|,
name|OverdefinedVal
decl_stmt|,
name|UntrackedVal
decl_stmt|;
name|public
label|:
name|AbstractLatticeFunction
argument_list|(
argument|LatticeVal undefVal
argument_list|,
argument|LatticeVal overdefinedVal
argument_list|,
argument|LatticeVal untrackedVal
argument_list|)
block|{
name|UndefVal
operator|=
name|undefVal
expr_stmt|;
name|OverdefinedVal
operator|=
name|overdefinedVal
expr_stmt|;
name|UntrackedVal
operator|=
name|untrackedVal
expr_stmt|;
block|}
name|virtual
operator|~
name|AbstractLatticeFunction
argument_list|()
expr_stmt|;
name|LatticeVal
name|getUndefVal
argument_list|()
specifier|const
block|{
return|return
name|UndefVal
return|;
block|}
name|LatticeVal
name|getOverdefinedVal
argument_list|()
specifier|const
block|{
return|return
name|OverdefinedVal
return|;
block|}
name|LatticeVal
name|getUntrackedVal
argument_list|()
specifier|const
block|{
return|return
name|UntrackedVal
return|;
block|}
comment|/// IsUntrackedValue - If the specified Value is something that is obviously
comment|/// uninteresting to the analysis (and would always return UntrackedVal),
comment|/// this function can return true to avoid pointless work.
name|virtual
name|bool
name|IsUntrackedValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// ComputeConstant - Given a constant value, compute and return a lattice
comment|/// value corresponding to the specified constant.
name|virtual
name|LatticeVal
name|ComputeConstant
parameter_list|(
name|Constant
modifier|*
name|C
parameter_list|)
block|{
return|return
name|getOverdefinedVal
argument_list|()
return|;
comment|// always safe
block|}
comment|/// IsSpecialCasedPHI - Given a PHI node, determine whether this PHI node is
comment|/// one that the we want to handle through ComputeInstructionState.
name|virtual
name|bool
name|IsSpecialCasedPHI
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// GetConstant - If the specified lattice value is representable as an LLVM
comment|/// constant value, return it.  Otherwise return null.  The returned value
comment|/// must be in the same LLVM type as Val.
name|virtual
name|Constant
modifier|*
name|GetConstant
parameter_list|(
name|LatticeVal
name|LV
parameter_list|,
name|Value
modifier|*
name|Val
parameter_list|,
name|SparseSolver
modifier|&
name|SS
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// ComputeArgument - Given a formal argument value, compute and return a
comment|/// lattice value corresponding to the specified argument.
name|virtual
name|LatticeVal
name|ComputeArgument
parameter_list|(
name|Argument
modifier|*
name|I
parameter_list|)
block|{
return|return
name|getOverdefinedVal
argument_list|()
return|;
comment|// always safe
block|}
comment|/// MergeValues - Compute and return the merge of the two specified lattice
comment|/// values.  Merging should only move one direction down the lattice to
comment|/// guarantee convergence (toward overdefined).
name|virtual
name|LatticeVal
name|MergeValues
parameter_list|(
name|LatticeVal
name|X
parameter_list|,
name|LatticeVal
name|Y
parameter_list|)
block|{
return|return
name|getOverdefinedVal
argument_list|()
return|;
comment|// always safe, never useful.
block|}
comment|/// ComputeInstructionState - Given an instruction and a vector of its operand
comment|/// values, compute the result value of the instruction.
name|virtual
name|LatticeVal
name|ComputeInstructionState
parameter_list|(
name|Instruction
modifier|&
name|I
parameter_list|,
name|SparseSolver
modifier|&
name|SS
parameter_list|)
block|{
return|return
name|getOverdefinedVal
argument_list|()
return|;
comment|// always safe, never useful.
block|}
comment|/// PrintValue - Render the specified lattice value to the specified stream.
name|virtual
name|void
name|PrintValue
parameter_list|(
name|LatticeVal
name|V
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// SparseSolver - This class is a general purpose solver for Sparse Conditional
comment|/// Propagation with a programmable lattice function.
comment|///
name|class
name|SparseSolver
block|{
typedef|typedef
name|AbstractLatticeFunction
operator|::
name|LatticeVal
name|LatticeVal
expr_stmt|;
comment|/// LatticeFunc - This is the object that knows the lattice and how to do
comment|/// compute transfer functions.
name|AbstractLatticeFunction
modifier|*
name|LatticeFunc
decl_stmt|;
name|LLVMContext
modifier|*
name|Context
decl_stmt|;
name|DenseMap
operator|<
name|Value
operator|*
operator|,
name|LatticeVal
operator|>
name|ValueState
expr_stmt|;
comment|// The state each value is in.
name|SmallPtrSet
operator|<
name|BasicBlock
operator|*
operator|,
literal|16
operator|>
name|BBExecutable
expr_stmt|;
comment|// The bbs that are executable.
name|std
operator|::
name|vector
operator|<
name|Instruction
operator|*
operator|>
name|InstWorkList
expr_stmt|;
comment|// Worklist of insts to process.
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
name|BBWorkList
expr_stmt|;
comment|// The BasicBlock work list
comment|/// KnownFeasibleEdges - Entries in this set are edges which have already had
comment|/// PHI nodes retriggered.
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
name|std
operator|::
name|set
operator|<
name|Edge
operator|>
name|KnownFeasibleEdges
expr_stmt|;
name|SparseSolver
argument_list|(
specifier|const
name|SparseSolver
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|SparseSolver
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|explicit
name|SparseSolver
argument_list|(
name|AbstractLatticeFunction
operator|*
name|Lattice
argument_list|,
name|LLVMContext
operator|*
name|C
argument_list|)
operator|:
name|LatticeFunc
argument_list|(
name|Lattice
argument_list|)
operator|,
name|Context
argument_list|(
argument|C
argument_list|)
block|{}
operator|~
name|SparseSolver
argument_list|()
block|{
name|delete
name|LatticeFunc
block|;   }
comment|/// Solve - Solve for constants and executable blocks.
comment|///
name|void
name|Solve
argument_list|(
name|Function
operator|&
name|F
argument_list|)
expr_stmt|;
name|void
name|Print
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// getLatticeState - Return the LatticeVal object that corresponds to the
comment|/// value.  If an value is not in the map, it is returned as untracked,
comment|/// unlike the getOrInitValueState method.
name|LatticeVal
name|getLatticeState
argument_list|(
name|Value
operator|*
name|V
argument_list|)
decl|const
block|{
name|DenseMap
operator|<
name|Value
operator|*
operator|,
name|LatticeVal
operator|>
operator|::
name|iterator
name|I
operator|=
name|ValueState
operator|.
name|find
argument_list|(
name|V
argument_list|)
expr_stmt|;
return|return
name|I
operator|!=
name|ValueState
operator|.
name|end
argument_list|()
condition|?
name|I
operator|->
name|second
else|:
name|LatticeFunc
operator|->
name|getUntrackedVal
argument_list|()
return|;
block|}
comment|/// getOrInitValueState - Return the LatticeVal object that corresponds to the
comment|/// value, initializing the value's state if it hasn't been entered into the
comment|/// map yet.   This function is necessary because not all values should start
comment|/// out in the underdefined state... Arguments should be overdefined, and
comment|/// constants should be marked as constants.
comment|///
name|LatticeVal
name|getOrInitValueState
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// isEdgeFeasible - Return true if the control flow edge from the 'From'
comment|/// basic block to the 'To' basic block is currently feasible.  If
comment|/// AggressiveUndef is true, then this treats values with unknown lattice
comment|/// values as undefined.  This is generally only useful when solving the
comment|/// lattice, not when querying it.
name|bool
name|isEdgeFeasible
parameter_list|(
name|BasicBlock
modifier|*
name|From
parameter_list|,
name|BasicBlock
modifier|*
name|To
parameter_list|,
name|bool
name|AggressiveUndef
init|=
name|false
parameter_list|)
function_decl|;
comment|/// isBlockExecutable - Return true if there are any known feasible
comment|/// edges into the basic block.  This is generally only useful when
comment|/// querying the lattice.
name|bool
name|isBlockExecutable
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|BBExecutable
operator|.
name|count
argument_list|(
name|BB
argument_list|)
return|;
block|}
name|private
label|:
comment|/// UpdateState - When the state for some instruction is potentially updated,
comment|/// this function notices and adds I to the worklist if needed.
name|void
name|UpdateState
parameter_list|(
name|Instruction
modifier|&
name|Inst
parameter_list|,
name|LatticeVal
name|V
parameter_list|)
function_decl|;
comment|/// MarkBlockExecutable - This method can be used by clients to mark all of
comment|/// the blocks that are known to be intrinsically live in the processed unit.
name|void
name|MarkBlockExecutable
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// markEdgeExecutable - Mark a basic block as executable, adding it to the BB
comment|/// work list if it is not already executable.
name|void
name|markEdgeExecutable
parameter_list|(
name|BasicBlock
modifier|*
name|Source
parameter_list|,
name|BasicBlock
modifier|*
name|Dest
parameter_list|)
function_decl|;
comment|/// getFeasibleSuccessors - Return a vector of booleans to indicate which
comment|/// successors are reachable from a given terminator instruction.
name|void
name|getFeasibleSuccessors
argument_list|(
name|TerminatorInst
operator|&
name|TI
argument_list|,
name|SmallVectorImpl
operator|<
name|bool
operator|>
operator|&
name|Succs
argument_list|,
name|bool
name|AggressiveUndef
argument_list|)
decl_stmt|;
name|void
name|visitInst
parameter_list|(
name|Instruction
modifier|&
name|I
parameter_list|)
function_decl|;
name|void
name|visitPHINode
parameter_list|(
name|PHINode
modifier|&
name|I
parameter_list|)
function_decl|;
name|void
name|visitTerminatorInst
parameter_list|(
name|TerminatorInst
modifier|&
name|TI
parameter_list|)
function_decl|;
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

begin_comment
comment|// LLVM_ANALYSIS_SPARSE_PROPAGATION_H
end_comment

end_unit

