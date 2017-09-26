begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Transforms/SampleProfile.h - SamplePGO pass--------------*- C++ -*-===//
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
comment|/// This file provides the interface for the sampled PGO loader pass.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_SAMPLEPROFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SAMPLEPROFILE_H
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
comment|/// The sample profiler data loader pass.
name|class
name|SampleProfileLoaderPass
range|:
name|public
name|PassInfoMixin
operator|<
name|SampleProfileLoaderPass
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|;
name|SampleProfileLoaderPass
argument_list|(
argument|std::string File =
literal|""
argument_list|)
operator|:
name|ProfileFileName
argument_list|(
argument|File
argument_list|)
block|{}
name|private
operator|:
name|std
operator|::
name|string
name|ProfileFileName
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

