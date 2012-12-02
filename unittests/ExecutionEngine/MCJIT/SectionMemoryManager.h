begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SectionMemoryManager.h - Memory allocator for MCJIT -----*- C++ -*-===//
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
comment|// This file contains the declaration of a section-based memory manager used by
end_comment

begin_comment
comment|// the MCJIT execution engine.
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
name|LLVM_EXECUTION_ENGINE_SECTION_MEMORY_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTION_ENGINE_SECTION_MEMORY_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITMemoryManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Section-based memory manager for MCJIT
name|class
name|SectionMemoryManager
range|:
name|public
name|JITMemoryManager
block|{
name|public
operator|:
name|SectionMemoryManager
argument_list|()
block|{ }
operator|~
name|SectionMemoryManager
argument_list|()
block|;
name|virtual
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
block|;
name|virtual
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
block|;
name|virtual
name|void
operator|*
name|getPointerToNamedFunction
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool AbortOnFailure = true
argument_list|)
block|;
comment|// Invalidate instruction cache for code sections. Some platforms with
comment|// separate data cache and instruction cache require explicit cache flush,
comment|// otherwise JIT code manipulations (like resolved relocations) will get to
comment|// the data cache but not to the instruction cache.
name|virtual
name|void
name|invalidateInstructionCache
argument_list|()
block|;
name|private
operator|:
name|SmallVector
operator|<
name|sys
operator|::
name|MemoryBlock
block|,
literal|16
operator|>
name|AllocatedDataMem
block|;
name|SmallVector
operator|<
name|sys
operator|::
name|MemoryBlock
block|,
literal|16
operator|>
name|AllocatedCodeMem
block|;
name|SmallVector
operator|<
name|sys
operator|::
name|MemoryBlock
block|,
literal|16
operator|>
name|FreeCodeMem
block|;
name|public
operator|:
comment|///
comment|/// Functions below are not used by MCJIT, but must be implemented because
comment|/// they are declared as pure virtuals in the base class.
comment|///
name|virtual
name|void
name|setMemoryWritable
argument_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
name|virtual
name|void
name|setMemoryExecutable
argument_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
name|virtual
name|void
name|setPoisonMemory
argument_list|(
argument|bool poison
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
name|virtual
name|void
name|AllocateGOT
argument_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
name|virtual
name|uint8_t
operator|*
name|getGOTBase
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|uint8_t
operator|*
name|startFunctionBody
argument_list|(
argument|const Function *F
argument_list|,
argument|uintptr_t&ActualSize
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|uint8_t
operator|*
name|allocateStub
argument_list|(
argument|const GlobalValue* F
argument_list|,
argument|unsigned StubSize
argument_list|,
argument|unsigned Alignment
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|endFunctionBody
argument_list|(
argument|const Function *F
argument_list|,
argument|uint8_t *FunctionStart
argument_list|,
argument|uint8_t *FunctionEnd
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
name|virtual
name|uint8_t
operator|*
name|allocateSpace
argument_list|(
argument|intptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|uint8_t
operator|*
name|allocateGlobal
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|deallocateFunctionBody
argument_list|(
argument|void *Body
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
name|virtual
name|uint8_t
operator|*
name|startExceptionTable
argument_list|(
argument|const Function *F
argument_list|,
argument|uintptr_t&ActualSize
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|endExceptionTable
argument_list|(
argument|const Function *F
argument_list|,
argument|uint8_t *TableStart
argument_list|,
argument|uint8_t *TableEnd
argument_list|,
argument|uint8_t *FrameRegister
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
name|virtual
name|void
name|deallocateExceptionTable
argument_list|(
argument|void *ET
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Unexpected call!"
argument_list|)
block|;   }
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTION_ENGINE_SECTION_MEMORY_MANAGER_H
end_comment

end_unit

