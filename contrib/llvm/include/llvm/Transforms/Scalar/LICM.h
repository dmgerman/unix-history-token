begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LICM.h - Loop Invariant Code Motion Pass -------*- C++ -*-===//
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
comment|// This pass performs loop invariant code motion, attempting to remove as much
end_comment

begin_comment
comment|// code from the body of a loop as possible.  It does this by either hoisting
end_comment

begin_comment
comment|// code into the preheader block, or by sinking code to the exit blocks if it is
end_comment

begin_comment
comment|// safe.  This pass also promotes must-aliased memory locations in the loop to
end_comment

begin_comment
comment|// live in registers, thus hoisting and sinking "invariant" loads and stores.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass uses alias analysis for two purposes:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  1. Moving loop invariant loads and calls out of loops.  If we can determine
end_comment

begin_comment
comment|//     that a load or call inside of a loop never aliases anything stored to,
end_comment

begin_comment
comment|//     we can hoist it or sink it like any other instruction.
end_comment

begin_comment
comment|//  2. Scalar Promotion of Memory - If there is a store instruction inside of
end_comment

begin_comment
comment|//     the loop, we try to move the store to happen AFTER the loop instead of
end_comment

begin_comment
comment|//     inside of the loop.  This can only happen if a few conditions are true:
end_comment

begin_comment
comment|//       A. The pointer stored through is loop invariant
end_comment

begin_comment
comment|//       B. There are no stores or loads in the loop which _may_ alias the
end_comment

begin_comment
comment|//          pointer.  There are no calls in the loop which mod/ref the pointer.
end_comment

begin_comment
comment|//     If these conditions are true, we can promote the loads and stores in the
end_comment

begin_comment
comment|//     loop of the pointer to use a temporary alloca'd variable.  We then use
end_comment

begin_comment
comment|//     the SSAUpdater to construct the appropriate SSA form for the value.
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
name|LLVM_TRANSFORMS_SCALAR_LICM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LICM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
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
comment|/// Performs Loop Invariant Code Motion Pass.
name|class
name|LICMPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LICMPass
operator|>
block|{
name|public
operator|:
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

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_LICM_H
end_comment

end_unit

