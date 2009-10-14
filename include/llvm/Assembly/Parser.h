begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Assembly/Parser.h - Parser for VM assembly files ---*- C++ -*-===//
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
comment|//  These classes are implemented by the lib/AsmParser library.
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
name|LLVM_ASSEMBLY_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ASSEMBLY_PARSER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|SMDiagnostic
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// This function is the main interface to the LLVM Assembly Parser. It parses
comment|/// an ASCII file that (presumably) contains LLVM Assembly code. It returns a
comment|/// Module (intermediate representation) with the corresponding features. Note
comment|/// that this does not verify that the generated Module is valid, so you should
comment|/// run the verifier after parsing the file to check that it is okay.
comment|/// @brief Parse LLVM Assembly from a file
name|Module
modifier|*
name|ParseAssemblyFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
comment|///< The name of the file to parse
name|SMDiagnostic
operator|&
name|Error
argument_list|,
comment|///< Error result info.
name|LLVMContext
operator|&
name|Context
comment|///< Context in which to allocate globals info.
argument_list|)
decl_stmt|;
comment|/// The function is a secondary interface to the LLVM Assembly Parser. It parses
comment|/// an ASCII string that (presumably) contains LLVM Assembly code. It returns a
comment|/// Module (intermediate representation) with the corresponding features. Note
comment|/// that this does not verify that the generated Module is valid, so you should
comment|/// run the verifier after parsing the file to check that it is okay.
comment|/// @brief Parse LLVM Assembly from a string
name|Module
modifier|*
name|ParseAssemblyString
parameter_list|(
specifier|const
name|char
modifier|*
name|AsmString
parameter_list|,
comment|///< The string containing assembly
name|Module
modifier|*
name|M
parameter_list|,
comment|///< A module to add the assembly too.
name|SMDiagnostic
modifier|&
name|Error
parameter_list|,
comment|///< Error result info.
name|LLVMContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// This function is the low-level interface to the LLVM Assembly Parser.
comment|/// ParseAssemblyFile and ParseAssemblyString are wrappers around this function.
comment|/// @brief Parse LLVM Assembly from a MemoryBuffer. This function *always*
comment|/// takes ownership of the MemoryBuffer.
name|Module
modifier|*
name|ParseAssembly
parameter_list|(
name|MemoryBuffer
modifier|*
name|F
parameter_list|,
comment|///< The MemoryBuffer containing assembly
name|Module
modifier|*
name|M
parameter_list|,
comment|///< A module to add the assembly too.
name|SMDiagnostic
modifier|&
name|Err
parameter_list|,
comment|///< Error result info.
name|LLVMContext
modifier|&
name|Context
parameter_list|)
function_decl|;
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

