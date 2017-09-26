begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LegacyPassManager.h - Legacy Container for Passes --------*- C++ -*-===//
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
comment|// This file defines the legacy PassManager class.  This class is used to hold,
end_comment

begin_comment
comment|// maintain, and optimize execution of Passes.  The PassManager class ensures
end_comment

begin_comment
comment|// that analysis results are available before a pass runs, and that Pass's are
end_comment

begin_comment
comment|// destroyed when the PassManager is destroyed.
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
name|LLVM_IR_LEGACYPASSMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_LEGACYPASSMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Pass
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|namespace
name|legacy
block|{
name|class
name|PassManagerImpl
decl_stmt|;
name|class
name|FunctionPassManagerImpl
decl_stmt|;
comment|/// PassManagerBase - An abstract interface to allow code to add passes to
comment|/// a pass manager without having to hard-code what kind of pass manager
comment|/// it is.
name|class
name|PassManagerBase
block|{
name|public
label|:
name|virtual
operator|~
name|PassManagerBase
argument_list|()
expr_stmt|;
comment|/// Add a pass to the queue of passes to run.  This passes ownership of
comment|/// the Pass to the PassManager.  When the PassManager is destroyed, the pass
comment|/// will be destroyed as well, so there is no need to delete the pass.  This
comment|/// may even destroy the pass right away if it is found to be redundant. This
comment|/// implies that all passes MUST be allocated with 'new'.
name|virtual
name|void
name|add
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// PassManager manages ModulePassManagers
name|class
name|PassManager
range|:
name|public
name|PassManagerBase
block|{
name|public
operator|:
name|PassManager
argument_list|()
block|;
operator|~
name|PassManager
argument_list|()
name|override
block|;
name|void
name|add
argument_list|(
argument|Pass *P
argument_list|)
name|override
block|;
comment|/// run - Execute all of the passes scheduled for execution.  Keep track of
comment|/// whether any of the passes modifies the module, and if so, return true.
name|bool
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
comment|/// PassManagerImpl_New is the actual class. PassManager is just the
comment|/// wraper to publish simple pass manager interface
name|PassManagerImpl
operator|*
name|PM
block|; }
decl_stmt|;
comment|/// FunctionPassManager manages FunctionPasses and BasicBlockPassManagers.
name|class
name|FunctionPassManager
range|:
name|public
name|PassManagerBase
block|{
name|public
operator|:
comment|/// FunctionPassManager ctor - This initializes the pass manager.  It needs,
comment|/// but does not take ownership of, the specified Module.
name|explicit
name|FunctionPassManager
argument_list|(
name|Module
operator|*
name|M
argument_list|)
block|;
operator|~
name|FunctionPassManager
argument_list|()
name|override
block|;
name|void
name|add
argument_list|(
argument|Pass *P
argument_list|)
name|override
block|;
comment|/// run - Execute all of the passes scheduled for execution.  Keep
comment|/// track of whether any of the passes modifies the function, and if
comment|/// so, return true.
comment|///
name|bool
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
comment|/// doInitialization - Run all of the initializers for the function passes.
comment|///
name|bool
name|doInitialization
argument_list|()
block|;
comment|/// doFinalization - Run all of the finalizers for the function passes.
comment|///
name|bool
name|doFinalization
argument_list|()
block|;
name|private
operator|:
name|FunctionPassManagerImpl
operator|*
name|FPM
block|;
name|Module
operator|*
name|M
block|; }
decl_stmt|;
block|}
comment|// End legacy namespace
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_STDCXX_CONVERSION_FUNCTIONS
argument_list|(
argument|legacy::PassManagerBase
argument_list|,
argument|LLVMPassManagerRef
argument_list|)
comment|/// If -time-passes has been specified, report the timings immediately and then
comment|/// reset the timers to zero.
name|void
name|reportAndResetTimings
parameter_list|()
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

