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
name|LLVMContext
decl_stmt|;
comment|/// If the given file holds a bitcode image, return a Module
comment|/// for it which does lazy deserialization of function bodies.  Otherwise,
comment|/// attempt to parse it as LLVM Assembly and return a fully populated
comment|/// Module.
name|Module
modifier|*
name|getLazyIRFileModule
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|SMDiagnostic
operator|&
name|Err
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|)
decl_stmt|;
comment|/// If the given MemoryBuffer holds a bitcode image, return a Module
comment|/// for it.  Otherwise, attempt to parse it as LLVM Assembly and return
comment|/// a Module for it. This function *never* takes ownership of Buffer.
name|Module
modifier|*
name|ParseIR
parameter_list|(
name|MemoryBuffer
modifier|*
name|Buffer
parameter_list|,
name|SMDiagnostic
modifier|&
name|Err
parameter_list|,
name|LLVMContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// If the given file holds a bitcode image, return a Module for it.
comment|/// Otherwise, attempt to parse it as LLVM Assembly and return a Module
comment|/// for it.
name|Module
modifier|*
name|ParseIRFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|SMDiagnostic
operator|&
name|Err
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

