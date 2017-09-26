begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopSink.h - Loop Sink Pass ------------------------------*- C++ -*-===//
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
comment|// This file provides the interface for the Loop Sink pass.
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
name|LLVM_TRANSFORMS_SCALAR_LOOPSINK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPSINK_H
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
comment|/// A pass that does profile-guided sinking of instructions into loops.
comment|///
comment|/// This is a function pass as it shouldn't be composed into any kind of
comment|/// unified loop pass pipeline. The goal of it is to sink code into loops that
comment|/// is loop invariant but only required within the loop body when doing so
comment|/// reduces the global expected dynamic frequency with which it executes.
comment|/// A classic example is an extremely cold branch within a loop body.
comment|///
comment|/// We do this as a separate pass so that during normal optimization all
comment|/// invariant operations can be held outside the loop body to simplify
comment|/// fundamental analyses and transforms of the loop.
name|class
name|LoopSinkPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopSinkPass
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|FAM
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
comment|// LLVM_TRANSFORMS_SCALAR_LOOPSINK_H
end_comment

end_unit

