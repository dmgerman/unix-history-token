begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/IRReader/IRReader.h - Reader for LLVM IR files ---*- C++ -*-===//
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
comment|// This file defines functions for reading LLVM IR. They support both
end_comment

begin_comment
comment|// Bitcode and Assembly, automatically detecting the input format.
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
name|LLVM_IRREADER_IRREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IRREADER_IRREADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

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
name|SMDiagnostic
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// If the given file holds a bitcode image, return a Module
comment|/// for it which does lazy deserialization of function bodies.  Otherwise,
comment|/// attempt to parse it as LLVM Assembly and return a fully populated
comment|/// Module.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|getLazyIRFileModule
argument_list|(
argument|StringRef Filename
argument_list|,
argument|SMDiagnostic&Err
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// If the given MemoryBuffer holds a bitcode image, return a Module
comment|/// for it.  Otherwise, attempt to parse it as LLVM Assembly and return
comment|/// a Module for it.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseIR
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|SMDiagnostic&Err
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// If the given file holds a bitcode image, return a Module for it.
comment|/// Otherwise, attempt to parse it as LLVM Assembly and return a Module
comment|/// for it.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|parseIRFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|SMDiagnostic&Err
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

