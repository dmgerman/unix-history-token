begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LowerExpectIntrinsic.h - LowerExpectIntrinsic pass -------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// The header file for the LowerExpectIntrinsic pass as used by the new pass
end_comment

begin_comment
comment|/// manager.
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
name|LLVM_TRANSFORMS_SCALAR_LOWEREXPECTINTRINSIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOWEREXPECTINTRINSIC_H
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
name|struct
name|LowerExpectIntrinsicPass
range|:
name|PassInfoMixin
operator|<
name|LowerExpectIntrinsicPass
operator|>
block|{
comment|/// \brief Run the pass over the function.
comment|///
comment|/// This will lower all of th expect intrinsic calls in this function into
comment|/// branch weight metadata. That metadata will subsequently feed the analysis
comment|/// of the probabilities and frequencies of the CFG. After running this pass,
comment|/// no more expect intrinsics remain, allowing the rest of the optimizer to
comment|/// ignore them.
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
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

