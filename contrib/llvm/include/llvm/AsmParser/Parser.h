begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Parser.h - Parser for LLVM IR text assembly files -------*- C++ -*-===//
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
name|LLVM_ASMPARSER_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ASMPARSER_PARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|SMDiagnostic
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
comment|/// @param Filename The name of the file to parse
comment|/// @param Error Error result info.
comment|/// @param Context Context in which to allocate globals info.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseAssemblyFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|SMDiagnostic&Error
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// The function is a secondary interface to the LLVM Assembly Parser. It parses
comment|/// an ASCII string that (presumably) contains LLVM Assembly code. It returns a
comment|/// Module (intermediate representation) with the corresponding features. Note
comment|/// that this does not verify that the generated Module is valid, so you should
comment|/// run the verifier after parsing the file to check that it is okay.
comment|/// @brief Parse LLVM Assembly from a string
comment|/// @param AsmString The string containing assembly
comment|/// @param Error Error result info.
comment|/// @param Context Context in which to allocate globals info.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseAssemblyString
argument_list|(
argument|StringRef AsmString
argument_list|,
argument|SMDiagnostic&Error
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// parseAssemblyFile and parseAssemblyString are wrappers around this function.
comment|/// @brief Parse LLVM Assembly from a MemoryBuffer.
comment|/// @param F The MemoryBuffer containing assembly
comment|/// @param Err Error result info.
comment|/// @param Context Context in which to allocate globals info.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseAssembly
argument_list|(
argument|MemoryBufferRef F
argument_list|,
argument|SMDiagnostic&Err
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// This function is the low-level interface to the LLVM Assembly Parser.
comment|/// This is kept as an independent function instead of being inlined into
comment|/// parseAssembly for the convenience of interactive users that want to add
comment|/// recently parsed bits to an existing module.
comment|///
comment|/// @param F The MemoryBuffer containing assembly
comment|/// @param M The module to add data to.
comment|/// @param Err Error result info.
comment|/// @return true on error.
name|bool
name|parseAssemblyInto
parameter_list|(
name|MemoryBufferRef
name|F
parameter_list|,
name|Module
modifier|&
name|M
parameter_list|,
name|SMDiagnostic
modifier|&
name|Err
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

