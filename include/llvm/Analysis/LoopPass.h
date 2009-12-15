begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopPass.h - LoopPass class ----------------------------------------===//
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
comment|// This file defines LoopPass class. All loop optimization
end_comment

begin_comment
comment|// and transformation passes are derived from LoopPass.
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
name|LLVM_LOOP_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LOOP_PASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassManagers.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LPPassManager
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|PMStack
decl_stmt|;
name|class
name|LoopPass
range|:
name|public
name|Pass
block|{
name|public
operator|:
name|explicit
name|LoopPass
argument_list|(
argument|intptr_t pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|pid
argument_list|)
block|{}
name|explicit
name|LoopPass
argument_list|(
name|void
operator|*
name|pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|pid
argument_list|)
block|{}
comment|// runOnLoop - This method should be implemented by the subclass to perform
comment|// whatever action is necessary for the specified Loop.
name|virtual
name|bool
name|runOnLoop
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|LPPassManager
operator|&
name|LPM
argument_list|)
operator|=
literal|0
block|;
comment|// Initialization and finalization hooks.
name|virtual
name|bool
name|doInitialization
argument_list|(
argument|Loop *L
argument_list|,
argument|LPPassManager&LPM
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Finalization hook does not supply Loop because at this time
comment|// loop nest is completely different.
name|virtual
name|bool
name|doFinalization
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|// Check if this pass is suitable for the current LPPassManager, if
comment|// available. This pass P is not suitable for a LPPassManager if P
comment|// is not preserving higher level analysis info used by other
comment|// LPPassManager passes. In such case, pop LPPassManager from the
comment|// stack. This will force assignPassManager() to create new
comment|// LPPassManger as expected.
name|void
name|preparePassManager
argument_list|(
name|PMStack
operator|&
name|PMS
argument_list|)
block|;
comment|/// Assign pass manager to manage this pass
name|virtual
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType PMT = PMT_LoopPassManager
argument_list|)
block|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|virtual
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
block|{
return|return
name|PMT_LoopPassManager
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// SimpleAnalysis - Provides simple interface to update analysis info
comment|/// maintained by various passes. Note, if required this interface can
comment|/// be extracted into a separate abstract class but it would require
comment|/// additional use of multiple inheritance in Pass class hierarchy, something
comment|/// we are trying to avoid.
comment|/// Each loop pass can override these simple analysis hooks to update
comment|/// desired analysis information.
comment|/// cloneBasicBlockAnalysis - Clone analysis info associated with basic block.
name|virtual
name|void
name|cloneBasicBlockAnalysis
argument_list|(
argument|BasicBlock *F
argument_list|,
argument|BasicBlock *T
argument_list|,
argument|Loop *L
argument_list|)
block|{}
comment|/// deleteAnalysisValue - Delete analysis info associated with value V.
name|virtual
name|void
name|deleteAnalysisValue
argument_list|(
argument|Value *V
argument_list|,
argument|Loop *L
argument_list|)
block|{}
expr|}
block|;
name|class
name|LPPassManager
operator|:
name|public
name|FunctionPass
block|,
name|public
name|PMDataManager
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|explicit
name|LPPassManager
argument_list|(
argument|int Depth
argument_list|)
block|;
comment|/// run - Execute all of the passes scheduled for execution.  Keep track of
comment|/// whether any of the passes modifies the module, and if so, return true.
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
comment|/// Pass Manager itself does not invalidate any analysis info.
comment|// LPPassManager needs LoopInfo.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&Info
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Loop Pass Manager"
return|;
block|}
comment|/// Print passes managed by this manager
name|void
name|dumpPassStructure
argument_list|(
argument|unsigned Offset
argument_list|)
block|;
name|Pass
operator|*
name|getContainedPass
argument_list|(
argument|unsigned N
argument_list|)
block|{
name|assert
argument_list|(
name|N
operator|<
name|PassVector
operator|.
name|size
argument_list|()
operator|&&
literal|"Pass number out of range!"
argument_list|)
block|;
name|Pass
operator|*
name|FP
operator|=
name|static_cast
operator|<
name|Pass
operator|*
operator|>
operator|(
name|PassVector
index|[
name|N
index|]
operator|)
block|;
return|return
name|FP
return|;
block|}
name|virtual
name|PassManagerType
name|getPassManagerType
argument_list|()
specifier|const
block|{
return|return
name|PMT_LoopPassManager
return|;
block|}
name|public
operator|:
comment|// Delete loop from the loop queue and loop nest (LoopInfo).
name|void
name|deleteLoopFromQueue
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|// Insert loop into the loop queue and add it as a child of the
comment|// given parent.
name|void
name|insertLoop
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|Loop
operator|*
name|ParentLoop
argument_list|)
block|;
comment|// Insert a loop into the loop queue.
name|void
name|insertLoopIntoQueue
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|// Reoptimize this loop. LPPassManager will re-insert this loop into the
comment|// queue. This allows LoopPass to change loop nest for the loop. This
comment|// utility may send LPPassManager into infinite loops so use caution.
name|void
name|redoLoop
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|//===--------------------------------------------------------------------===//
comment|/// SimpleAnalysis - Provides simple interface to update analysis info
comment|/// maintained by various passes. Note, if required this interface can
comment|/// be extracted into a separate abstract class but it would require
comment|/// additional use of multiple inheritance in Pass class hierarchy, something
comment|/// we are trying to avoid.
comment|/// cloneBasicBlockSimpleAnalysis - Invoke cloneBasicBlockAnalysis hook for
comment|/// all passes that implement simple analysis interface.
name|void
name|cloneBasicBlockSimpleAnalysis
argument_list|(
name|BasicBlock
operator|*
name|From
argument_list|,
name|BasicBlock
operator|*
name|To
argument_list|,
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// deleteSimpleAnalysisValue - Invoke deleteAnalysisValue hook for all passes
comment|/// that implement simple analysis interface.
name|void
name|deleteSimpleAnalysisValue
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|Loop
operator|*
name|L
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|deque
operator|<
name|Loop
operator|*
operator|>
name|LQ
block|;
name|bool
name|skipThisLoop
block|;
name|bool
name|redoThisLoop
block|;
name|LoopInfo
operator|*
name|LI
block|;
name|Loop
operator|*
name|CurrentLoop
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

