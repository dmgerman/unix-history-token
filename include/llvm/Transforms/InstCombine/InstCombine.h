begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstCombine.h - InstCombine pass -------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file provides the primary interface to the instcombine pass. This pass
end_comment

begin_comment
comment|/// is suitable for use in the new pass manager. For a pass that works with the
end_comment

begin_comment
comment|/// legacy pass manager, please look for \c createInstructionCombiningPass() in
end_comment

begin_comment
comment|/// Scalar.h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_INSTCOMBINE_INSTCOMBINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_INSTCOMBINE_INSTCOMBINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/InstCombine/InstCombineWorklist.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|InstCombinePass
range|:
name|public
name|PassInfoMixin
operator|<
name|InstCombinePass
operator|>
block|{
name|InstCombineWorklist
name|Worklist
block|;
name|bool
name|ExpensiveCombines
block|;
name|public
operator|:
specifier|static
name|StringRef
name|name
argument_list|()
block|{
return|return
literal|"InstCombinePass"
return|;
block|}
name|explicit
name|InstCombinePass
argument_list|(
argument|bool ExpensiveCombines = true
argument_list|)
operator|:
name|ExpensiveCombines
argument_list|(
argument|ExpensiveCombines
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief The legacy pass manager's instcombine pass.
comment|///
comment|/// This is a basic whole-function wrapper around the instcombine utility. It
comment|/// will try to combine all instructions in the function.
name|class
name|InstructionCombiningPass
range|:
name|public
name|FunctionPass
block|{
name|InstCombineWorklist
name|Worklist
block|;
specifier|const
name|bool
name|ExpensiveCombines
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|InstructionCombiningPass
argument_list|(
argument|bool ExpensiveCombines = true
argument_list|)
operator|:
name|FunctionPass
argument_list|(
name|ID
argument_list|)
block|,
name|ExpensiveCombines
argument_list|(
argument|ExpensiveCombines
argument_list|)
block|{
name|initializeInstructionCombiningPassPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

