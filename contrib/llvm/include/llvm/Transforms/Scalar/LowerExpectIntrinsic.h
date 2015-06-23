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
name|class
name|LowerExpectIntrinsicPass
block|{
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"LowerExpectIntrinsicPass"
return|;
block|}
comment|/// \brief Run the pass over the function.
comment|///
comment|/// This will lower all of th expect intrinsic calls in this function into
comment|/// branch weight metadata. That metadata will subsequently feed the analysis
comment|/// of the probabilities and frequencies of the CFG. After running this pass,
comment|/// no more expect intrinsics remain, allowing the rest of the optimizer to
comment|/// ignore them.
name|PreservedAnalyses
name|run
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
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

