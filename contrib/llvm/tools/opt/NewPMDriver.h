begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NewPMDriver.h - Function to drive opt with the new PM ----*- C++ -*-===//
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
comment|/// A single function which is called to drive the opt behavior for the new
end_comment

begin_comment
comment|/// PassManager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is only in a separate TU with a header to avoid including all of the
end_comment

begin_comment
comment|/// old pass manager headers and the new pass manager headers into the same
end_comment

begin_comment
comment|/// file. Eventually all of the routines here will get folded back into
end_comment

begin_comment
comment|/// opt.cpp.
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
name|LLVM_TOOLS_OPT_NEWPMDRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_OPT_NEWPMDRIVER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|tool_output_file
decl_stmt|;
name|namespace
name|opt_tool
block|{
enum|enum
name|OutputKind
block|{
name|OK_NoOutput
block|,
name|OK_OutputAssembly
block|,
name|OK_OutputBitcode
block|,
name|OK_OutputThinLTOBitcode
block|, }
enum|;
enum|enum
name|VerifierKind
block|{
name|VK_NoVerifier
block|,
name|VK_VerifyInAndOut
block|,
name|VK_VerifyEachPass
block|}
enum|;
block|}
comment|/// \brief Driver function to run the new pass manager over a module.
comment|///
comment|/// This function only exists factored away from opt.cpp in order to prevent
comment|/// inclusion of the new pass manager headers and the old headers into the same
comment|/// file. It's interface is consequentially somewhat ad-hoc, but will go away
comment|/// when the transition finishes.
comment|///
comment|/// ThinLTOLinkOut is only used when OK is OK_OutputThinLTOBitcode, and can be
comment|/// nullptr.
name|bool
name|runPassPipeline
argument_list|(
name|StringRef
name|Arg0
argument_list|,
name|Module
operator|&
name|M
argument_list|,
name|TargetMachine
operator|*
name|TM
argument_list|,
name|tool_output_file
operator|*
name|Out
argument_list|,
name|tool_output_file
operator|*
name|ThinLinkOut
argument_list|,
name|StringRef
name|PassPipeline
argument_list|,
name|opt_tool
operator|::
name|OutputKind
name|OK
argument_list|,
name|opt_tool
operator|::
name|VerifierKind
name|VK
argument_list|,
name|bool
name|ShouldPreserveAssemblyUseListOrder
argument_list|,
name|bool
name|ShouldPreserveBitcodeUseListOrder
argument_list|,
name|bool
name|EmitSummaryIndex
argument_list|,
name|bool
name|EmitModuleHash
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

