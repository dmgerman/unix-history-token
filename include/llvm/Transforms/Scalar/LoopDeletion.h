begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopDeletion.h - Loop Deletion -------------------------------------===//
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
comment|// This file provides the interface for the Loop Deletion Pass.
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
name|LLVM_TRANSFORMS_SCALAR_LOOPDELETION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPDELETION_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Scalar/LoopPassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LoopDeletionPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopDeletionPass
operator|>
block|{
name|public
operator|:
name|LoopDeletionPass
argument_list|()
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Loop
operator|&
name|L
argument_list|,
name|LoopAnalysisManager
operator|&
name|AM
argument_list|,
name|LoopStandardAnalysisResults
operator|&
name|AR
argument_list|,
name|LPMUpdater
operator|&
name|U
argument_list|)
block|;
name|bool
name|runImpl
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|,
name|ScalarEvolution
operator|&
name|SE
argument_list|,
name|LoopInfo
operator|&
name|loopInfo
argument_list|)
block|;
name|private
operator|:
name|bool
name|isLoopDead
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|ScalarEvolution
operator|&
name|SE
argument_list|,
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|exitingBlocks
argument_list|,
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|exitBlocks
argument_list|,
name|bool
operator|&
name|Changed
argument_list|,
name|BasicBlock
operator|*
name|Preheader
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_LOOPDELETION_H
end_comment

end_unit

