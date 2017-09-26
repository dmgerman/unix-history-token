begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- ExpandReductions.h - Expand experimental reduction intrinsics --===//
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
name|LLVM_CODEGEN_EXPANDREDUCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_EXPANDREDUCTIONS_H
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
name|class
name|ExpandReductionsPass
range|:
name|public
name|PassInfoMixin
operator|<
name|ExpandReductionsPass
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
comment|// LLVM_CODEGEN_EXPANDREDUCTIONS_H
end_comment

end_unit

