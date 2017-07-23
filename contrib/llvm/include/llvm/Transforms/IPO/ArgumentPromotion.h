begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ArgumentPromotion.h - Promote by-reference arguments -----*- C++ -*-===//
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
name|LLVM_TRANSFORMS_IPO_ARGUMENTPROMOTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_ARGUMENTPROMOTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/CGSCCPassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LazyCallGraph.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Argument promotion pass.
comment|///
comment|/// This pass walks the functions in each SCC and for each one tries to
comment|/// transform it and all of its callers to replace indirect arguments with
comment|/// direct (by-value) arguments.
name|class
name|ArgumentPromotionPass
range|:
name|public
name|PassInfoMixin
operator|<
name|ArgumentPromotionPass
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
argument_list|,
name|CGSCCAnalysisManager
operator|&
name|AM
argument_list|,
name|LazyCallGraph
operator|&
name|CG
argument_list|,
name|CGSCCUpdateResult
operator|&
name|UR
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

