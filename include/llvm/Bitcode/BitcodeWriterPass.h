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
name|class
name|PreservedAnalyses
decl_stmt|;
comment|/// \brief Create and return a pass that writes the module to the specified
comment|/// ostream. Note that this pass is designed for use with the legacy pass
comment|/// manager.
name|ModulePass
modifier|*
name|createBitcodeWriterPass
parameter_list|(
name|raw_ostream
modifier|&
name|Str
parameter_list|)
function_decl|;
comment|/// \brief Pass for writing a module of IR out to a bitcode file.
comment|///
comment|/// Note that this is intended for use with the new pass manager. To construct
comment|/// a pass for the legacy pass manager, use the function above.
name|class
name|BitcodeWriterPass
block|{
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|public
label|:
comment|/// \brief Construct a bitcode writer pass around a particular output stream.
name|explicit
name|BitcodeWriterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
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
argument_list|)
expr_stmt|;
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"BitcodeWriterPass"
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

