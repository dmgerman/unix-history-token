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
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
argument_list|,
name|Module
operator|*
name|m
argument_list|)
operator|:
name|JMM
argument_list|(
name|jmm
condition|?
name|jmm
else|:
name|JITMemoryManager
operator|::
name|CreateDefaultMemManager
argument_list|()
argument_list|)
block|,
name|M
argument_list|(
argument|m
argument_list|)
block|{}
comment|// We own the JMM, so make sure to delete it.
operator|~
name|MCJITMemoryManager
argument_list|()
block|{
name|delete
name|JMM
block|; }
name|uint8_t
operator|*
name|allocateDataSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|)
block|{
return|return
name|JMM
operator|->
name|allocateSpace
argument_list|(
name|Size
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
name|uint8_t
operator|*
name|allocateCodeSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|)
block|{
return|return
name|JMM
operator|->
name|allocateSpace
argument_list|(
name|Size
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
name|virtual
name|void
operator|*
name|getPointerToNamedFunction
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool AbortOnFailure = true
argument_list|)
block|{
return|return
name|JMM
operator|->
name|getPointerToNamedFunction
argument_list|(
name|Name
argument_list|,
name|AbortOnFailure
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

