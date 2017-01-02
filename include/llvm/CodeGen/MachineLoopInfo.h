begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/MachineLoopInfo.h - Natural Loop Calculator -*- C++ -*-===//
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
comment|// This file defines the MachineLoopInfo class that is used to identify natural
end_comment

begin_comment
comment|// loops and determine the loop depth of various nodes of the CFG.  Note that
end_comment

begin_comment
comment|// natural loops may actually be several loops that share the same header node.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This analysis calculates the nesting structure of loops in a function.  For
end_comment

begin_comment
comment|// each natural loop identified, this analysis identifies natural loops
end_comment

begin_comment
comment|// contained entirely within the loop and the basic blocks the make up the loop.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It can calculate on the fly various bits of information, for example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  * whether there is a preheader for the loop
end_comment

begin_comment
comment|//  * the number of back edges to the header
end_comment

begin_comment
comment|//  * whether or not a particular block branches out of the loop
end_comment

begin_comment
comment|//  * the successor blocks of the loop
end_comment

begin_comment
comment|//  * the loop depth
end_comment

begin_comment
comment|//  * the trip count
end_comment

begin_comment
comment|//  * etc...
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
name|LLVM_CODEGEN_MACHINELOOPINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINELOOPINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Implementation in LoopInfoImpl.h
name|class
name|MachineLoop
decl_stmt|;
extern|extern template class LoopBase<MachineBasicBlock
operator|,
extern|MachineLoop>;
name|class
name|MachineLoop
range|:
name|public
name|LoopBase
operator|<
name|MachineBasicBlock
decl_stmt|,
name|MachineLoop
decl|>
block|{
name|public
label|:
name|MachineLoop
argument_list|()
expr_stmt|;
comment|/// Return the "top" block in the loop, which is the first block in the linear
comment|/// layout, ignoring any parts of the loop not contiguous with the part that
comment|/// contains the header.
name|MachineBasicBlock
modifier|*
name|getTopBlock
parameter_list|()
function_decl|;
comment|/// Return the "bottom" block in the loop, which is the last block in the
comment|/// linear layout, ignoring any parts of the loop not contiguous with the part
comment|/// that contains the header.
name|MachineBasicBlock
modifier|*
name|getBottomBlock
parameter_list|()
function_decl|;
comment|/// \brief Find the block that contains the loop control variable and the
comment|/// loop test. This will return the latch block if it's one of the exiting
comment|/// blocks. Otherwise, return the exiting block. Return 'null' when
comment|/// multiple exiting blocks are present.
name|MachineBasicBlock
modifier|*
name|findLoopControlBlock
parameter_list|()
function_decl|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|LoopInfoBase
operator|<
name|MachineBasicBlock
operator|,
name|MachineLoop
operator|>
expr_stmt|;
name|explicit
name|MachineLoop
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
operator|:
name|LoopBase
operator|<
name|MachineBasicBlock
operator|,
name|MachineLoop
operator|>
operator|(
name|MBB
operator|)
block|{}
block|}
empty_stmt|;
comment|// Implementation in LoopInfoImpl.h
extern|extern template class LoopInfoBase<MachineBasicBlock
operator|,
extern|MachineLoop>;
name|class
name|MachineLoopInfo
range|:
name|public
name|MachineFunctionPass
block|{
name|LoopInfoBase
operator|<
name|MachineBasicBlock
block|,
name|MachineLoop
operator|>
name|LI
block|;
name|friend
name|class
name|LoopBase
operator|<
name|MachineBasicBlock
block|,
name|MachineLoop
operator|>
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|MachineLoopInfo
operator|&
operator|)
operator|=
name|delete
block|;
name|MachineLoopInfo
argument_list|(
specifier|const
name|MachineLoopInfo
operator|&
argument_list|)
operator|=
name|delete
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|MachineLoopInfo
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeMachineLoopInfoPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|LoopInfoBase
operator|<
name|MachineBasicBlock
block|,
name|MachineLoop
operator|>
operator|&
name|getBase
argument_list|()
block|{
return|return
name|LI
return|;
block|}
comment|/// \brief Find the block that either is the loop preheader, or could
comment|/// speculatively be used as the preheader. This is e.g. useful to place
comment|/// loop setup code. Code that cannot be speculated should not be placed
comment|/// here. SpeculativePreheader is controlling whether it also tries to
comment|/// find the speculative preheader if the regular preheader is not present.
name|MachineBasicBlock
operator|*
name|findLoopPreheader
argument_list|(
argument|MachineLoop *L
argument_list|,
argument|bool SpeculativePreheader = false
argument_list|)
specifier|const
block|;
comment|/// The iterator interface to the top-level loops in the current function.
typedef|typedef
name|LoopInfoBase
operator|<
name|MachineBasicBlock
operator|,
name|MachineLoop
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
specifier|inline
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|LI
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|LI
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|LI
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Return the innermost loop that BB lives in. If a basic block is in no loop
comment|/// (for example the entry node), null is returned.
specifier|inline
name|MachineLoop
operator|*
name|getLoopFor
argument_list|(
argument|const MachineBasicBlock *BB
argument_list|)
specifier|const
block|{
return|return
name|LI
operator|.
name|getLoopFor
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// Same as getLoopFor.
specifier|inline
specifier|const
name|MachineLoop
operator|*
name|operator
index|[]
operator|(
specifier|const
name|MachineBasicBlock
operator|*
name|BB
operator|)
specifier|const
block|{
return|return
name|LI
operator|.
name|getLoopFor
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// Return the loop nesting level of the specified block.
specifier|inline
name|unsigned
name|getLoopDepth
argument_list|(
argument|const MachineBasicBlock *BB
argument_list|)
specifier|const
block|{
return|return
name|LI
operator|.
name|getLoopDepth
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// True if the block is a loop header node.
specifier|inline
name|bool
name|isLoopHeader
argument_list|(
argument|const MachineBasicBlock *BB
argument_list|)
specifier|const
block|{
return|return
name|LI
operator|.
name|isLoopHeader
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// Calculate the natural loop information.
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&F
argument_list|)
name|override
decl_stmt|;
name|void
name|releaseMemory
parameter_list|()
function|override
block|{
name|LI
operator|.
name|releaseMemory
argument_list|()
expr_stmt|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// This removes the specified top-level loop from this loop info object. The
comment|/// loop is not deleted, as it will presumably be inserted into another loop.
specifier|inline
name|MachineLoop
modifier|*
name|removeLoop
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
return|return
name|LI
operator|.
name|removeLoop
argument_list|(
name|I
argument_list|)
return|;
block|}
comment|/// Change the top-level loop that contains BB to the specified loop. This
comment|/// should be used by transformations that restructure the loop hierarchy
comment|/// tree.
specifier|inline
name|void
name|changeLoopFor
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|,
name|MachineLoop
modifier|*
name|L
parameter_list|)
block|{
name|LI
operator|.
name|changeLoopFor
argument_list|(
name|BB
argument_list|,
name|L
argument_list|)
expr_stmt|;
block|}
comment|/// Replace the specified loop in the top-level loops list with the indicated
comment|/// loop.
specifier|inline
name|void
name|changeTopLevelLoop
parameter_list|(
name|MachineLoop
modifier|*
name|OldLoop
parameter_list|,
name|MachineLoop
modifier|*
name|NewLoop
parameter_list|)
block|{
name|LI
operator|.
name|changeTopLevelLoop
argument_list|(
name|OldLoop
argument_list|,
name|NewLoop
argument_list|)
expr_stmt|;
block|}
comment|/// This adds the specified loop to the collection of top-level loops.
specifier|inline
name|void
name|addTopLevelLoop
parameter_list|(
name|MachineLoop
modifier|*
name|New
parameter_list|)
block|{
name|LI
operator|.
name|addTopLevelLoop
argument_list|(
name|New
argument_list|)
expr_stmt|;
block|}
comment|/// This method completely removes BB from all data structures, including all
comment|/// of the Loop objects it is nested in and our mapping from
comment|/// MachineBasicBlocks to loops.
name|void
name|removeBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|LI
operator|.
name|removeBlock
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Allow clients to walk the list of nested loops...
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|MachineLoop
operator|*
operator|>
block|{
typedef|typedef
specifier|const
name|MachineLoop
modifier|*
name|NodeRef
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|MachineLoopInfo
operator|::
name|iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
specifier|const
name|MachineLoop
modifier|*
name|L
parameter_list|)
block|{
return|return
name|L
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|MachineLoop
operator|*
operator|>
block|{
typedef|typedef
name|MachineLoop
modifier|*
name|NodeRef
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|MachineLoopInfo
operator|::
name|iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
name|MachineLoop
modifier|*
name|L
parameter_list|)
block|{
return|return
name|L
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

