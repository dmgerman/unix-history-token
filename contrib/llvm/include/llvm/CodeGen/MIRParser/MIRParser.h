begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MIRParser.h - MIR serialization format parser ----------------------===//
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
comment|// This MIR serialization library is currently a work in progress. It can't
end_comment

begin_comment
comment|// serialize machine functions at this time.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares the functions that parse the MIR serialization format
end_comment

begin_comment
comment|// files.
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
name|LLVM_CODEGEN_MIRPARSER_MIRPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MIRPARSER_MIRPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SMDiagnostic
decl_stmt|;
comment|/// This function is the main interface to the MIR serialization format parser.
comment|///
comment|/// It reads a YAML file that has an optional LLVM IR and returns an LLVM
comment|/// module.
comment|/// \param Filename - The name of the file to parse.
comment|/// \param Error - Error result info.
comment|/// \param Context - Context in which to allocate globals info.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseMIRFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|SMDiagnostic&Error
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// This function is another interface to the MIR serialization format parser.
comment|///
comment|/// It parses the optional LLVM IR in the given buffer, and returns an LLVM
comment|/// module.
comment|/// \param Contents - The MemoryBuffer containing the machine level IR.
comment|/// \param Error - Error result info.
comment|/// \param Context - Context in which to allocate globals info.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseMIR
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Contents
argument_list|,
name|SMDiagnostic
operator|&
name|Error
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

