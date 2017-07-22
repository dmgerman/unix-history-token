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
name|LLVM_ANALYSIS_LOOPPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LegacyPassManagers.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<deque>
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
name|char
operator|&
name|pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|PT_Loop
argument_list|,
argument|pid
argument_list|)
block|{}
comment|/// getPrinterPass - Get a pass to print the function corresponding
comment|/// to a Loop.
name|Pass
operator|*
name|createPrinterPass
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const std::string&Banner
argument_list|)
specifier|const
name|override
block|;
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
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doInitialization
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doFinalization
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
argument|PMStack&PMS
argument_list|)
name|override
block|;
comment|/// Assign pass manager to manage this pass
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType PMT
argument_list|)
name|override
block|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
name|override
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
comment|/// Delete analysis info associated with Loop L.
comment|/// Called to notify a Pass that a loop has been deleted and any
comment|/// associated analysis values can be deleted.
name|virtual
name|void
name|deleteAnalysisLoop
argument_list|(
argument|Loop *L
argument_list|)
block|{}
name|protected
operator|:
comment|/// Optional passes call this function to check whether the pass should be
comment|/// skipped. This is the case when Attribute::OptimizeNone is set or when
comment|/// optimization bisect is over the limit.
name|bool
name|skipLoop
argument_list|(
argument|const Loop *L
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|class
name|LPPassManager
range|:
name|public
name|FunctionPass
decl_stmt|,
name|public
name|PMDataManager
block|{
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
name|explicit
name|LPPassManager
parameter_list|()
function_decl|;
comment|/// run - Execute all of the passes scheduled for execution.  Keep track of
comment|/// whether any of the passes modifies the module, and if so, return true.
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
name|override
decl_stmt|;
comment|/// Pass Manager itself does not invalidate any analysis info.
comment|// LPPassManager needs LoopInfo.
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|Info
argument_list|)
decl|const
name|override
decl_stmt|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Loop Pass Manager"
return|;
block|}
name|PMDataManager
modifier|*
name|getAsPMDataManager
parameter_list|()
function|override
block|{
return|return
name|this
return|;
block|}
name|Pass
modifier|*
name|getAsPass
parameter_list|()
function|override
block|{
return|return
name|this
return|;
block|}
comment|/// Print passes managed by this manager
name|void
name|dumpPassStructure
argument_list|(
name|unsigned
name|Offset
argument_list|)
name|override
decl_stmt|;
name|LoopPass
modifier|*
name|getContainedPass
parameter_list|(
name|unsigned
name|N
parameter_list|)
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
expr_stmt|;
name|LoopPass
modifier|*
name|LP
init|=
name|static_cast
operator|<
name|LoopPass
operator|*
operator|>
operator|(
name|PassVector
index|[
name|N
index|]
operator|)
decl_stmt|;
return|return
name|LP
return|;
block|}
name|PassManagerType
name|getPassManagerType
argument_list|()
specifier|const
name|override
block|{
return|return
name|PMT_LoopPassManager
return|;
block|}
name|public
label|:
comment|// Add a new loop into the loop queue.
name|void
name|addLoop
parameter_list|(
name|Loop
modifier|&
name|L
parameter_list|)
function_decl|;
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
parameter_list|(
name|BasicBlock
modifier|*
name|From
parameter_list|,
name|BasicBlock
modifier|*
name|To
parameter_list|,
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// deleteSimpleAnalysisValue - Invoke deleteAnalysisValue hook for all passes
comment|/// that implement simple analysis interface.
name|void
name|deleteSimpleAnalysisValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// Invoke deleteAnalysisLoop hook for all passes that implement simple
comment|/// analysis interface.
name|void
name|deleteSimpleAnalysisLoop
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
name|private
label|:
name|std
operator|::
name|deque
operator|<
name|Loop
operator|*
operator|>
name|LQ
expr_stmt|;
name|LoopInfo
modifier|*
name|LI
decl_stmt|;
name|Loop
modifier|*
name|CurrentLoop
decl_stmt|;
block|}
empty_stmt|;
comment|// This pass is required by the LCSSA transformation. It is used inside
comment|// LPPassManager to check if current pass preserves LCSSA form, and if it does
comment|// pass manager calls lcssa verification for the current loop.
name|struct
name|LCSSAVerificationPass
range|:
name|public
name|FunctionPass
block|{
specifier|static
name|char
name|ID
block|;
name|LCSSAVerificationPass
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeLCSSAVerificationPassPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|{
return|return
name|false
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
expr|}
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

