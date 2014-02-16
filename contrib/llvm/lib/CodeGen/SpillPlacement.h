begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SpillPlacement.h - Optimal Spill Code Placement --------*- C++ -*--===//
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
comment|// This analysis computes the optimal spill code placement between basic blocks.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The runOnMachineFunction() method only precomputes some profiling information
end_comment

begin_comment
comment|// about the CFG. The real work is done by prepare(), addConstraints(), and
end_comment

begin_comment
comment|// finish() which are called by the register allocator.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Given a variable that is live across multiple basic blocks, and given
end_comment

begin_comment
comment|// constraints on the basic blocks where the variable is live, determine which
end_comment

begin_comment
comment|// edge bundles should have the variable in a register and which edge bundles
end_comment

begin_comment
comment|// should have the variable in a stack slot.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The returned bit vector can be used to place optimal spill code at basic
end_comment

begin_comment
comment|// block entries and exits. Spill code placement inside a basic block is not
end_comment

begin_comment
comment|// considered.
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
name|LLVM_CODEGEN_SPILLPLACEMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SPILLPLACEMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BlockFrequency.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitVector
decl_stmt|;
name|class
name|EdgeBundles
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|SpillPlacement
range|:
name|public
name|MachineFunctionPass
block|{   struct
name|Node
block|;
specifier|const
name|MachineFunction
operator|*
name|MF
block|;
specifier|const
name|EdgeBundles
operator|*
name|bundles
block|;
specifier|const
name|MachineLoopInfo
operator|*
name|loops
block|;
name|Node
operator|*
name|nodes
block|;
comment|// Nodes that are active in the current computation. Owned by the prepare()
comment|// caller.
name|BitVector
operator|*
name|ActiveNodes
block|;
comment|// Nodes with active links. Populated by scanActiveBundles.
name|SmallVector
operator|<
name|unsigned
block|,
literal|8
operator|>
name|Linked
block|;
comment|// Nodes that went positive during the last call to scanActiveBundles or
comment|// iterate.
name|SmallVector
operator|<
name|unsigned
block|,
literal|8
operator|>
name|RecentPositive
block|;
comment|// Block frequencies are computed once. Indexed by block number.
name|SmallVector
operator|<
name|BlockFrequency
block|,
literal|4
operator|>
name|BlockFrequencies
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid.
name|SpillPlacement
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
name|ID
argument_list|)
block|,
name|nodes
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|SpillPlacement
argument_list|()
block|{
name|releaseMemory
argument_list|()
block|; }
comment|/// BorderConstraint - A basic block has separate constraints for entry and
comment|/// exit.
expr|enum
name|BorderConstraint
block|{
name|DontCare
block|,
comment|///< Block doesn't care / variable not live.
name|PrefReg
block|,
comment|///< Block entry/exit prefers a register.
name|PrefSpill
block|,
comment|///< Block entry/exit prefers a stack slot.
name|PrefBoth
block|,
comment|///< Block entry prefers both register and stack.
name|MustSpill
comment|///< A register is impossible, variable must be spilled.
block|}
block|;
comment|/// BlockConstraint - Entry and exit constraints for a basic block.
block|struct
name|BlockConstraint
block|{
name|unsigned
name|Number
block|;
comment|///< Basic block number (from MBB::getNumber()).
name|BorderConstraint
name|Entry
operator|:
literal|8
block|;
comment|///< Constraint on block entry.
name|BorderConstraint
name|Exit
operator|:
literal|8
block|;
comment|///< Constraint on block exit.
comment|/// True when this block changes the value of the live range. This means
comment|/// the block has a non-PHI def.  When this is false, a live-in value on
comment|/// the stack can be live-out on the stack without inserting a spill.
name|bool
name|ChangesValue
block|;   }
block|;
comment|/// prepare - Reset state and prepare for a new spill placement computation.
comment|/// @param RegBundles Bit vector to receive the edge bundles where the
comment|///                   variable should be kept in a register. Each bit
comment|///                   corresponds to an edge bundle, a set bit means the
comment|///                   variable should be kept in a register through the
comment|///                   bundle. A clear bit means the variable should be
comment|///                   spilled. This vector is retained.
name|void
name|prepare
argument_list|(
name|BitVector
operator|&
name|RegBundles
argument_list|)
block|;
comment|/// addConstraints - Add constraints and biases. This method may be called
comment|/// more than once to accumulate constraints.
comment|/// @param LiveBlocks Constraints for blocks that have the variable live in or
comment|///                   live out.
name|void
name|addConstraints
argument_list|(
name|ArrayRef
operator|<
name|BlockConstraint
operator|>
name|LiveBlocks
argument_list|)
block|;
comment|/// addPrefSpill - Add PrefSpill constraints to all blocks listed.  This is
comment|/// equivalent to calling addConstraint with identical BlockConstraints with
comment|/// Entry = Exit = PrefSpill, and ChangesValue = false.
comment|///
comment|/// @param Blocks Array of block numbers that prefer to spill in and out.
comment|/// @param Strong When true, double the negative bias for these blocks.
name|void
name|addPrefSpill
argument_list|(
argument|ArrayRef<unsigned> Blocks
argument_list|,
argument|bool Strong
argument_list|)
block|;
comment|/// addLinks - Add transparent blocks with the given numbers.
name|void
name|addLinks
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Links
argument_list|)
block|;
comment|/// scanActiveBundles - Perform an initial scan of all bundles activated by
comment|/// addConstraints and addLinks, updating their state. Add all the bundles
comment|/// that now prefer a register to RecentPositive.
comment|/// Prepare internal data structures for iterate.
comment|/// Return true is there are any positive nodes.
name|bool
name|scanActiveBundles
argument_list|()
block|;
comment|/// iterate - Update the network iteratively until convergence, or new bundles
comment|/// are found.
name|void
name|iterate
argument_list|()
block|;
comment|/// getRecentPositive - Return an array of bundles that became positive during
comment|/// the previous call to scanActiveBundles or iterate.
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getRecentPositive
argument_list|()
block|{
return|return
name|RecentPositive
return|;
block|}
comment|/// finish - Compute the optimal spill code placement given the
comment|/// constraints. No MustSpill constraints will be violated, and the smallest
comment|/// possible number of PrefX constraints will be violated, weighted by
comment|/// expected execution frequencies.
comment|/// The selected bundles are returned in the bitvector passed to prepare().
comment|/// @return True if a perfect solution was found, allowing the variable to be
comment|///         in a register through all relevant bundles.
name|bool
name|finish
argument_list|()
block|;
comment|/// getBlockFrequency - Return the estimated block execution frequency per
comment|/// function invocation.
name|BlockFrequency
name|getBlockFrequency
argument_list|(
argument|unsigned Number
argument_list|)
specifier|const
block|{
return|return
name|BlockFrequencies
index|[
name|Number
index|]
return|;
block|}
name|private
operator|:
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
argument_list|)
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
name|void
name|activate
argument_list|(
name|unsigned
argument_list|)
block|; }
decl_stmt|;
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

