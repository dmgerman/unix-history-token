begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- LoopLoadElimination.h ---------------------------------*- C++ -*-===//
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
comment|/// This header defines the LoopLoadEliminationPass object. This pass forwards
end_comment

begin_comment
comment|/// loaded values around loop backedges to allow their use in subsequent
end_comment

begin_comment
comment|/// iterations.
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
name|LLVM_TRANSFORMS_SCALAR_LOOPLOADELIMINATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPLOADELIMINATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Pass to forward loads in a loop around the backedge to subsequent
comment|/// iterations.
name|struct
name|LoopLoadEliminationPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopLoadEliminationPass
operator|>
block|{
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_LOOPLOADELIMINATION_H
end_comment

end_unit

