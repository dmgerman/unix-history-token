begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MCJITMemoryManager.h - Definition for the Memory Manager ---C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_EXECUTIONENGINE_MCJITMEMORYMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_EXECUTIONENGINE_MCJITMEMORYMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITMemoryManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// The MCJIT memory manager is a layer between the standard JITMemoryManager
comment|// and the RuntimeDyld interface that maps objects, by name, onto their
comment|// matching LLVM IR counterparts in the module(s) being compiled.
name|class
name|MCJITMemoryManager
range|:
name|public
name|RTDyldMemoryManager
block|{
name|JITMemoryManager
operator|*
name|JMM
block|;
comment|// FIXME: Multiple modules.
name|Module
operator|*
name|M
block|;
name|public
operator|:
name|MCJITMemoryManager
argument_list|(
name|JITMemoryManager
operator|*
name|jmm
argument_list|)
operator|:
name|JMM
argument_list|(
argument|jmm
argument_list|)
block|{}
comment|// Allocate ActualSize bytes, or more, for the named function. Return
comment|// a pointer to the allocated memory and update Size to reflect how much
comment|// memory was acutally allocated.
name|uint8_t
operator|*
name|startFunctionBody
argument_list|(
argument|const char *Name
argument_list|,
argument|uintptr_t&Size
argument_list|)
block|{
comment|// FIXME: This should really reference the MCAsmInfo to get the global
comment|//        prefix.
if|if
condition|(
name|Name
index|[
literal|0
index|]
operator|==
literal|'_'
condition|)
operator|++
name|Name
expr_stmt|;
name|Function
operator|*
name|F
operator|=
name|M
operator|->
name|getFunction
argument_list|(
name|Name
argument_list|)
block|;
name|assert
argument_list|(
name|F
operator|&&
literal|"No matching function in JIT IR Module!"
argument_list|)
block|;
return|return
name|JMM
operator|->
name|startFunctionBody
argument_list|(
name|F
argument_list|,
name|Size
argument_list|)
return|;
block|}
comment|// Mark the end of the function, including how much of the allocated
comment|// memory was actually used.
name|void
name|endFunctionBody
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|,
name|uint8_t
modifier|*
name|FunctionStart
parameter_list|,
name|uint8_t
modifier|*
name|FunctionEnd
parameter_list|)
block|{
comment|// FIXME: This should really reference the MCAsmInfo to get the global
comment|//        prefix.
if|if
condition|(
name|Name
index|[
literal|0
index|]
operator|==
literal|'_'
condition|)
operator|++
name|Name
expr_stmt|;
name|Function
modifier|*
name|F
init|=
name|M
operator|->
name|getFunction
argument_list|(
name|Name
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|F
operator|&&
literal|"No matching function in JIT IR Module!"
argument_list|)
expr_stmt|;
name|JMM
operator|->
name|endFunctionBody
argument_list|(
name|F
argument_list|,
name|FunctionStart
argument_list|,
name|FunctionEnd
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

