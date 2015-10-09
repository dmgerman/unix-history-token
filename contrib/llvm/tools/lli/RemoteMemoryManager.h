begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RemoteMemoryManager.h - LLI MCJIT recording memory manager ------===//
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
comment|// This memory manager allocates local storage and keeps a record of each
end_comment

begin_comment
comment|// allocation. Iterators are provided for all data and code allocations.
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
name|LLVM_TOOLS_LLI_REMOTEMEMORYMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLI_REMOTEMEMORYMANAGER_H
end_define

begin_include
include|#
directive|include
file|"RemoteTarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RTDyldMemoryManager.h"
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

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RemoteMemoryManager
range|:
name|public
name|RTDyldMemoryManager
block|{
name|public
operator|:
comment|// Notice that this structure takes ownership of the memory allocated.
expr|struct
name|Allocation
block|{
name|Allocation
argument_list|()
block|{}
name|Allocation
argument_list|(
argument|sys::MemoryBlock mb
argument_list|,
argument|unsigned a
argument_list|,
argument|bool code
argument_list|)
operator|:
name|MB
argument_list|(
name|mb
argument_list|)
block|,
name|Alignment
argument_list|(
name|a
argument_list|)
block|,
name|IsCode
argument_list|(
argument|code
argument_list|)
block|{}
name|sys
operator|::
name|MemoryBlock
name|MB
block|;
name|unsigned
name|Alignment
block|;
name|bool
name|IsCode
block|;   }
block|;
name|private
operator|:
comment|// This vector contains Allocation objects for all sections which we have
comment|// allocated.  This vector effectively owns the memory associated with the
comment|// allocations.
name|SmallVector
operator|<
name|Allocation
block|,
literal|2
operator|>
name|AllocatedSections
block|;
comment|// This vector contains pointers to Allocation objects for any sections we
comment|// have allocated locally but have not yet remapped for the remote target.
comment|// When we receive notification of a completed module load, we will map
comment|// these sections into the remote target.
name|SmallVector
operator|<
name|Allocation
block|,
literal|2
operator|>
name|UnmappedSections
block|;
comment|// This map tracks the sections we have remapped for the remote target
comment|// but have not yet copied to the target.
name|DenseMap
operator|<
name|uint64_t
block|,
name|Allocation
operator|>
name|MappedSections
block|;
comment|// FIXME: This is part of a work around to keep sections near one another
comment|// when MCJIT performs relocations after code emission but before
comment|// the generated code is moved to the remote target.
name|sys
operator|::
name|MemoryBlock
name|Near
block|;
name|sys
operator|::
name|MemoryBlock
name|allocateSection
argument_list|(
argument|uintptr_t Size
argument_list|)
block|;
name|RemoteTarget
operator|*
name|Target
block|;
name|public
operator|:
name|RemoteMemoryManager
argument_list|()
operator|:
name|Target
argument_list|(
argument|nullptr
argument_list|)
block|{}
operator|~
name|RemoteMemoryManager
argument_list|()
name|override
block|;
name|uint8_t
operator|*
name|allocateCodeSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|StringRef SectionName
argument_list|)
name|override
block|;
name|uint8_t
operator|*
name|allocateDataSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|StringRef SectionName
argument_list|,
argument|bool IsReadOnly
argument_list|)
name|override
block|;
comment|// For now, remote symbol resolution is not support in lli.  The MCJIT
comment|// interface does support this, but clients must provide their own
comment|// mechanism for finding remote symbol addresses.  MCJIT will resolve
comment|// symbols from Modules it contains.
name|uint64_t
name|getSymbolAddress
argument_list|(
argument|const std::string&Name
argument_list|)
name|override
block|{
return|return
literal|0
return|;
block|}
name|void
name|notifyObjectLoaded
argument_list|(
argument|ExecutionEngine *EE
argument_list|,
argument|const object::ObjectFile&Obj
argument_list|)
name|override
block|;
name|bool
name|finalizeMemory
argument_list|(
argument|std::string *ErrMsg
argument_list|)
name|override
block|;
comment|// For now, remote EH frame registration isn't supported.  Remote symbol
comment|// resolution is a prerequisite to supporting remote EH frame registration.
name|void
name|registerEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|{}
name|void
name|deregisterEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|{}
comment|// This is a non-interface function used by lli
name|void
name|setRemoteTarget
argument_list|(
argument|RemoteTarget *T
argument_list|)
block|{
name|Target
operator|=
name|T
block|; }
block|}
decl_stmt|;
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

