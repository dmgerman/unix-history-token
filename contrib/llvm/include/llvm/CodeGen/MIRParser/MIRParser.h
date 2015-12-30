begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MIRParser.h - MIR serialization format parser ------------*- C++ -*-===//
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
file|"llvm/CodeGen/MachineFunctionInitializer.h"
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
name|MIRParserImpl
decl_stmt|;
name|class
name|SMDiagnostic
decl_stmt|;
comment|/// This class initializes machine functions by applying the state loaded from
comment|/// a MIR file.
name|class
name|MIRParser
range|:
name|public
name|MachineFunctionInitializer
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|MIRParserImpl
operator|>
name|Impl
block|;
name|public
operator|:
name|MIRParser
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MIRParserImpl
operator|>
name|Impl
argument_list|)
block|;
name|MIRParser
argument_list|(
specifier|const
name|MIRParser
operator|&
argument_list|)
operator|=
name|delete
block|;
operator|~
name|MIRParser
argument_list|()
name|override
block|;
comment|/// Parse the optional LLVM IR module that's embedded in the MIR file.
comment|///
comment|/// A new, empty module is created if the LLVM IR isn't present.
comment|/// Returns null if a parsing error occurred.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseLLVMModule
argument_list|()
block|;
comment|/// Initialize the machine function to the state that's described in the MIR
comment|/// file.
comment|///
comment|/// Return true if error occurred.
name|bool
name|initializeMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// This function is the main interface to the MIR serialization format parser.
comment|///
comment|/// It reads in a MIR file and returns a MIR parser that can parse the embedded
comment|/// LLVM IR module and initialize the machine functions by parsing the machine
comment|/// function's state.
comment|///
comment|/// \param Filename - The name of the file to parse.
comment|/// \param Error - Error result info.
comment|/// \param Context - Context which will be used for the parsed LLVM IR module.
name|std
operator|::
name|unique_ptr
operator|<
name|MIRParser
operator|>
name|createMIRParserFromFile
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
comment|/// It returns a MIR parser that works with the given memory buffer and that can
comment|/// parse the embedded LLVM IR module and initialize the machine functions by
comment|/// parsing the machine function's state.
comment|///
comment|/// \param Contents - The MemoryBuffer containing the machine level IR.
comment|/// \param Context - Context which will be used for the parsed LLVM IR module.
name|std
operator|::
name|unique_ptr
operator|<
name|MIRParser
operator|>
name|createMIRParser
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Contents
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

begin_comment
comment|// LLVM_CODEGEN_MIRPARSER_MIRPARSER_H
end_comment

end_unit

