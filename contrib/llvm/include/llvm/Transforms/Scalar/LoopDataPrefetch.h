begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- LoopDataPrefetch.h - Loop Data Prefetching Pass ---*- C++ -*-===//
end_comment

begin_comment
comment|//
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
comment|/// This file provides the interface for LLVM's Loop Data Prefetching Pass.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_SCALAR_LOOPDATAPREFETCH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPDATAPREFETCH_H
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// An optimization pass inserting data prefetches in loops.
name|class
name|LoopDataPrefetchPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopDataPrefetchPass
operator|>
block|{
name|public
operator|:
name|LoopDataPrefetchPass
argument_list|()
operator|=
expr|default
block|;
comment|/// \brief Run the pass over the function.
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
comment|// LLVM_TRANSFORMS_SCALAR_LOOPDATAPREFETCH_H
end_comment

end_unit

