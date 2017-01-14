begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopStrengthReduce.h - Loop Strength Reduce Pass -------*- C++ -*-===//
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
comment|// This transformation analyzes and transforms the induction variables (and
end_comment

begin_comment
comment|// computations derived from them) into forms suitable for efficient execution
end_comment

begin_comment
comment|// on the target.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass performs a strength reduction on array references inside loops that
end_comment

begin_comment
comment|// have as one or more of their components the loop induction variable, it
end_comment

begin_comment
comment|// rewrites expressions to take advantage of scaled-index addressing modes
end_comment

begin_comment
comment|// available on the target, and it performs a variety of other optimizations
end_comment

begin_comment
comment|// related to loop induction variables.
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
name|LLVM_TRANSFORMS_SCALAR_LOOPSTRENGTHREDUCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPSTRENGTHREDUCE_H
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
comment|/// Performs Loop Strength Reduce Pass.
name|class
name|LoopStrengthReducePass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopStrengthReducePass
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
comment|// LLVM_TRANSFORMS_SCALAR_LOOPSTRENGTHREDUCE_H
end_comment

end_unit

