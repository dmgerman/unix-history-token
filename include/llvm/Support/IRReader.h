begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/Support/IRReader.h - Reader for LLVM IR files ----*- C++ -*-===//
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
comment|// These functions must be defined in a header file in order to avoid
end_comment

begin_comment
comment|// library dependencies, since they reference both Bitcode and Assembly
end_comment

begin_comment
comment|// functions.
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
name|LLVM_SUPPORT_IRREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_IRREADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Assembly/Parser.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/ReaderWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ModuleProvider.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// If the given MemoryBuffer holds a bitcode image, return a ModuleProvider
comment|/// for it which does lazy deserialization of function bodies.  Otherwise,
comment|/// attempt to parse it as LLVM Assembly and return a fully populated
comment|/// ModuleProvider. This function *always* takes ownership of the given
comment|/// MemoryBuffer.
specifier|inline
name|ModuleProvider
modifier|*
name|getIRModuleProvider
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
block|{
if|if
condition|(
name|isBitcode
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|Buffer
operator|->
name|getBufferStart
argument_list|()
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|Buffer
operator|->
name|getBufferEnd
argument_list|()
argument_list|)
condition|)
block|{
name|std
operator|::
name|string
name|ErrMsg
expr_stmt|;
name|ModuleProvider
modifier|*
name|MP
init|=
name|getBitcodeModuleProvider
argument_list|(
name|Buffer
argument_list|,
name|Context
argument_list|,
operator|&
name|ErrMsg
argument_list|)
decl_stmt|;
if|if
condition|(
name|MP
operator|==
literal|0
condition|)
block|{
name|Err
operator|=
name|SMDiagnostic
argument_list|(
name|Buffer
operator|->
name|getBufferIdentifier
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
name|ErrMsg
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|// ParseBitcodeFile does not take ownership of the Buffer in the
comment|// case of an error.
name|delete
name|Buffer
decl_stmt|;
block|}
return|return
name|MP
return|;
block|}
name|Module
modifier|*
name|M
init|=
name|ParseAssembly
argument_list|(
name|Buffer
argument_list|,
literal|0
argument_list|,
name|Err
argument_list|,
name|Context
argument_list|)
decl_stmt|;
if|if
condition|(
name|M
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|new
name|ExistingModuleProvider
argument_list|(
name|M
argument_list|)
return|;
block|}
comment|/// If the given file holds a bitcode image, return a ModuleProvider
comment|/// for it which does lazy deserialization of function bodies.  Otherwise,
comment|/// attempt to parse it as LLVM Assembly and return a fully populated
comment|/// ModuleProvider.
specifier|inline
name|ModuleProvider
modifier|*
name|getIRFileModuleProvider
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
block|{
name|std
operator|::
name|string
name|ErrMsg
expr_stmt|;
name|MemoryBuffer
modifier|*
name|F
init|=
name|MemoryBuffer
operator|::
name|getFileOrSTDIN
argument_list|(
name|Filename
operator|.
name|c_str
argument_list|()
argument_list|,
operator|&
name|ErrMsg
argument_list|)
decl_stmt|;
if|if
condition|(
name|F
operator|==
literal|0
condition|)
block|{
name|Err
operator|=
name|SMDiagnostic
argument_list|(
name|Filename
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|"Could not open input file '"
operator|+
name|Filename
operator|+
literal|"'"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|getIRModuleProvider
argument_list|(
name|F
argument_list|,
name|Err
argument_list|,
name|Context
argument_list|)
return|;
block|}
comment|/// If the given MemoryBuffer holds a bitcode image, return a Module
comment|/// for it.  Otherwise, attempt to parse it as LLVM Assembly and return
comment|/// a Module for it. This function *always* takes ownership of the given
comment|/// MemoryBuffer.
specifier|inline
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
block|{
if|if
condition|(
name|isBitcode
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|Buffer
operator|->
name|getBufferStart
argument_list|()
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|Buffer
operator|->
name|getBufferEnd
argument_list|()
argument_list|)
condition|)
block|{
name|std
operator|::
name|string
name|ErrMsg
expr_stmt|;
name|Module
modifier|*
name|M
init|=
name|ParseBitcodeFile
argument_list|(
name|Buffer
argument_list|,
name|Context
argument_list|,
operator|&
name|ErrMsg
argument_list|)
decl_stmt|;
comment|// ParseBitcodeFile does not take ownership of the Buffer.
name|delete
name|Buffer
decl_stmt|;
if|if
condition|(
name|M
operator|==
literal|0
condition|)
name|Err
operator|=
name|SMDiagnostic
argument_list|(
name|Buffer
operator|->
name|getBufferIdentifier
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
name|ErrMsg
argument_list|,
literal|""
argument_list|)
expr_stmt|;
return|return
name|M
return|;
block|}
return|return
name|ParseAssembly
argument_list|(
name|Buffer
argument_list|,
literal|0
argument_list|,
name|Err
argument_list|,
name|Context
argument_list|)
return|;
block|}
comment|/// If the given file holds a bitcode image, return a Module for it.
comment|/// Otherwise, attempt to parse it as LLVM Assembly and return a Module
comment|/// for it.
specifier|inline
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
block|{
name|std
operator|::
name|string
name|ErrMsg
expr_stmt|;
name|MemoryBuffer
modifier|*
name|F
init|=
name|MemoryBuffer
operator|::
name|getFileOrSTDIN
argument_list|(
name|Filename
operator|.
name|c_str
argument_list|()
argument_list|,
operator|&
name|ErrMsg
argument_list|)
decl_stmt|;
if|if
condition|(
name|F
operator|==
literal|0
condition|)
block|{
name|Err
operator|=
name|SMDiagnostic
argument_list|(
name|Filename
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|"Could not open input file '"
operator|+
name|Filename
operator|+
literal|"'"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|ParseIR
argument_list|(
name|F
argument_list|,
name|Err
argument_list|,
name|Context
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

