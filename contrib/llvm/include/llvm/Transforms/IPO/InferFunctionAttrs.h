begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InferFunctionAttrs.h - Infer implicit function attributes ---------===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// Interfaces for passes which infer implicit function attributes from the
end_comment

begin_comment
comment|/// name and signature of function declarations.
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
name|LLVM_TRANSFORMS_IPO_INFERFUNCTIONATTRS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_INFERFUNCTIONATTRS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
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
comment|/// A pass which infers function attributes from the names and signatures of
comment|/// function declarations in a module.
name|class
name|InferFunctionAttrsPass
block|{
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"InferFunctionAttrsPass"
return|;
block|}
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|AnalysisManager
operator|<
name|Module
operator|>
operator|*
name|AM
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// Create a legacy pass manager instance of a pass to infer function
comment|/// attributes.
name|Pass
modifier|*
name|createInferFunctionAttrsLegacyPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_IPO_INFERFUNCTIONATTRS_H
end_comment

end_unit

