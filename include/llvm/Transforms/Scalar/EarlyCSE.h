begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- EarlyCSE.h - Simple and fast CSE pass --------------------*- C++ -*-===//
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
comment|/// This file provides the interface for a simple, fast CSE pass.
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
name|LLVM_TRANSFORMS_SCALAR_EARLYCSE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_EARLYCSE_H
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
comment|/// \brief A simple and fast domtree-based CSE pass.
comment|///
comment|/// This pass does a simple depth-first walk over the dominator tree,
comment|/// eliminating trivially redundant instructions and using instsimplify to
comment|/// canonicalize things as it goes. It is intended to be fast and catch obvious
comment|/// cases so that instcombine and other passes are more effective. It is
comment|/// expected that a later pass of GVN will catch the interesting/hard cases.
name|class
name|EarlyCSEPass
block|{
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"EarlyCSEPass"
return|;
block|}
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

