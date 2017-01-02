begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopUnrollPass.h -----------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_SCALAR_LOOPUNROLLPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPUNROLLPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopPassManager.h"
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
name|struct
name|LoopUnrollPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopUnrollPass
operator|>
block|{
name|Optional
operator|<
name|unsigned
operator|>
name|ProvidedCount
block|;
name|Optional
operator|<
name|unsigned
operator|>
name|ProvidedThreshold
block|;
name|Optional
operator|<
name|bool
operator|>
name|ProvidedAllowPartial
block|;
name|Optional
operator|<
name|bool
operator|>
name|ProvidedRuntime
block|;
name|Optional
operator|<
name|bool
operator|>
name|ProvidedUpperBound
block|;
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
comment|// LLVM_TRANSFORMS_SCALAR_LOOPUNROLLPASS_H
end_comment

end_unit

