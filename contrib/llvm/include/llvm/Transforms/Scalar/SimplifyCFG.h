begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SimplifyCFG.h - Simplify and canonicalize the CFG --------*- C++ -*-===//
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
comment|/// This file provides the interface for the pass responsible for both
end_comment

begin_comment
comment|/// simplifying and canonicalizing the CFG.
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
name|LLVM_TRANSFORMS_SCALAR_SIMPLIFYCFG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_SIMPLIFYCFG_H
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
comment|/// \brief A pass to simplify and canonicalize the CFG of a function.
comment|///
comment|/// This pass iteratively simplifies the entire CFG of a function, removing
comment|/// unnecessary control flows and bringing it into the canonical form expected
comment|/// by the rest of the mid-level optimizer.
name|class
name|SimplifyCFGPass
block|{
name|int
name|BonusInstThreshold
decl_stmt|;
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"SimplifyCFGPass"
return|;
block|}
comment|/// \brief Construct a pass with the default thresholds.
name|SimplifyCFGPass
argument_list|()
expr_stmt|;
comment|/// \brief Construct a pass with a specific bonus threshold.
name|SimplifyCFGPass
argument_list|(
argument|int BonusInstThreshold
argument_list|)
empty_stmt|;
comment|/// \brief Run the pass over the function.
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AnalysisManager
operator|<
name|Function
operator|>
operator|*
name|AM
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

