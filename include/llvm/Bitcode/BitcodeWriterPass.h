begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BitcodeWriterPass.h - Bitcode writing pass --------------*- C++ -*-===//
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
comment|/// This file provides a bitcode writing pass.
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
name|LLVM_BITCODE_BITCODEWRITERPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_BITCODEWRITERPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|Module
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Create and return a pass that writes the module to the specified
comment|/// ostream. Note that this pass is designed for use with the legacy pass
comment|/// manager.
comment|///
comment|/// If \c ShouldPreserveUseListOrder, encode use-list order so it can be
comment|/// reproduced when deserialized.
comment|///
comment|/// If \c EmitSummaryIndex, emit the summary index (currently for use in ThinLTO
comment|/// optimization).
comment|///
comment|/// If \c EmitModuleHash, compute and emit the module hash in the bitcode
comment|/// (currently for use in ThinLTO incremental build).
name|ModulePass
modifier|*
name|createBitcodeWriterPass
parameter_list|(
name|raw_ostream
modifier|&
name|Str
parameter_list|,
name|bool
name|ShouldPreserveUseListOrder
init|=
name|false
parameter_list|,
name|bool
name|EmitSummaryIndex
init|=
name|false
parameter_list|,
name|bool
name|EmitModuleHash
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Pass for writing a module of IR out to a bitcode file.
comment|///
comment|/// Note that this is intended for use with the new pass manager. To construct
comment|/// a pass for the legacy pass manager, use the function above.
name|class
name|BitcodeWriterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|BitcodeWriterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|bool
name|ShouldPreserveUseListOrder
block|;
name|bool
name|EmitSummaryIndex
block|;
name|bool
name|EmitModuleHash
block|;
name|public
operator|:
comment|/// \brief Construct a bitcode writer pass around a particular output stream.
comment|///
comment|/// If \c ShouldPreserveUseListOrder, encode use-list order so it can be
comment|/// reproduced when deserialized.
comment|///
comment|/// If \c EmitSummaryIndex, emit the summary index (currently
comment|/// for use in ThinLTO optimization).
name|explicit
name|BitcodeWriterPass
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool ShouldPreserveUseListOrder = false
argument_list|,
argument|bool EmitSummaryIndex = false
argument_list|,
argument|bool EmitModuleHash = false
argument_list|)
operator|:
name|OS
argument_list|(
name|OS
argument_list|)
block|,
name|ShouldPreserveUseListOrder
argument_list|(
name|ShouldPreserveUseListOrder
argument_list|)
block|,
name|EmitSummaryIndex
argument_list|(
name|EmitSummaryIndex
argument_list|)
block|,
name|EmitModuleHash
argument_list|(
argument|EmitModuleHash
argument_list|)
block|{}
comment|/// \brief Run the bitcode writer pass, and output the module to the selected
comment|/// output stream.
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

