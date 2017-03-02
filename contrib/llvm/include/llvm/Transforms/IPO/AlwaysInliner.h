begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AlwaysInliner.h - Pass to inline "always_inline" functions --------===//
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
comment|/// Provides passes to inlining "always_inline" functions.
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
name|LLVM_TRANSFORMS_IPO_ALWAYSINLINER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_ALWAYSINLINER_H
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
comment|/// Inlines functions marked as "always_inline".
comment|///
comment|/// Note that this does not inline call sites marked as always_inline and does
comment|/// not delete the functions even when all users are inlined. The normal
comment|/// inliner should be used to handle call site inlining, this pass's goal is to
comment|/// be the simplest possible pass to remove always_inline function definitions'
comment|/// uses by inlining them. The \c GlobalDCE pass can be used to remove these
comment|/// functions once all users are gone.
name|struct
name|AlwaysInlinerPass
range|:
name|PassInfoMixin
operator|<
name|AlwaysInlinerPass
operator|>
block|{
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
argument_list|)
block|; }
decl_stmt|;
comment|/// Create a legacy pass manager instance of a pass to inline and remove
comment|/// functions marked as "always_inline".
name|Pass
modifier|*
name|createAlwaysInlinerLegacyPass
parameter_list|(
name|bool
name|InsertLifetime
init|=
name|true
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_IPO_ALWAYSINLINER_H
end_comment

end_unit

