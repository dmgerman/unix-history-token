begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ThinLTOBitcodeWriter.h - Bitcode writing pass for ThinLTO ----------===//
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
comment|//
end_comment

begin_comment
comment|// This pass prepares a module containing type metadata for ThinLTO by splitting
end_comment

begin_comment
comment|// it into regular and thin LTO parts if possible, and writing both parts to
end_comment

begin_comment
comment|// a multi-module bitcode file. Modules that do not contain type metadata are
end_comment

begin_comment
comment|// written unmodified as a single module.
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
name|LLVM_TRANSFORMS_IPO_THINLTOBITCODEWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_THINLTOBITCODEWRITER_H
end_define

begin_include
include|#
directive|include
file|<llvm/IR/PassManager.h>
end_include

begin_include
include|#
directive|include
file|<llvm/Support/raw_ostream.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ThinLTOBitcodeWriterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|ThinLTOBitcodeWriterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|raw_ostream
operator|*
name|ThinLinkOS
block|;
name|public
operator|:
comment|// Writes bitcode to OS. Also write thin link file to ThinLinkOS, if
comment|// it's not nullptr.
name|ThinLTOBitcodeWriterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|raw_ostream
operator|*
name|ThinLinkOS
argument_list|)
operator|:
name|OS
argument_list|(
name|OS
argument_list|)
block|,
name|ThinLinkOS
argument_list|(
argument|ThinLinkOS
argument_list|)
block|{}
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
block|; }
decl_stmt|;
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

