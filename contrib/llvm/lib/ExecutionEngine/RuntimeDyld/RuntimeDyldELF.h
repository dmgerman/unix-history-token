begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyldELF.h - Run-time dynamic linker for MC-JIT ---*- C++ -*-===//
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
comment|// ELF support for MC-JIT runtime dynamic linker.
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
name|LLVM_LIB_EXECUTIONENGINE_RUNTIMEDYLD_RUNTIMEDYLDELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_EXECUTIONENGINE_RUNTIMEDYLD_RUNTIMEDYLDELF_H
end_define

begin_include
include|#
directive|include
file|"RuntimeDyldImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|ELFObjectFileBase
decl_stmt|;
block|}
name|class
name|RuntimeDyldELF
range|:
name|public
name|RuntimeDyldImpl
block|{
name|void
name|resolveRelocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|,
argument|uint64_t SymOffset =
literal|0
argument_list|,
argument|SID SectionID =
literal|0
argument_list|)
block|;
name|void
name|resolveX86_64Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|,
argument|uint64_t SymOffset
argument_list|)
block|;
name|void
name|resolveX86Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint32_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int32_t Addend
argument_list|)
block|;
name|void
name|resolveAArch64Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|bool
name|resolveAArch64ShortBranch
argument_list|(
argument|unsigned SectionID
argument_list|,
argument|relocation_iterator RelI
argument_list|,
argument|const RelocationValueRef&Value
argument_list|)
block|;
name|void
name|resolveAArch64Branch
argument_list|(
argument|unsigned SectionID
argument_list|,
argument|const RelocationValueRef&Value
argument_list|,
argument|relocation_iterator RelI
argument_list|,
argument|StubMap&Stubs
argument_list|)
block|;
name|void
name|resolveARMRelocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint32_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int32_t Addend
argument_list|)
block|;
name|void
name|resolvePPC32Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|void
name|resolvePPC64Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|void
name|resolveSystemZRelocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|unsigned
name|getMaxStubSize
argument_list|()
name|override
block|{
if|if
condition|(
name|Arch
operator|==
name|Triple
operator|::
name|aarch64
operator|||
name|Arch
operator|==
name|Triple
operator|::
name|aarch64_be
condition|)
return|return
literal|20
return|;
comment|// movz; movk; movk; movk; br
if|if
condition|(
name|Arch
operator|==
name|Triple
operator|::
name|arm
operator|||
name|Arch
operator|==
name|Triple
operator|::
name|thumb
condition|)
return|return
literal|8
return|;
comment|// 32-bit instruction and 32-bit address
elseif|else
if|if
condition|(
name|IsMipsO32ABI
condition|)
return|return
literal|16
return|;
elseif|else
if|if
condition|(
name|Arch
operator|==
name|Triple
operator|::
name|ppc64
operator|||
name|Arch
operator|==
name|Triple
operator|::
name|ppc64le
condition|)
return|return
literal|44
return|;
elseif|else
if|if
condition|(
name|Arch
operator|==
name|Triple
operator|::
name|x86_64
condition|)
return|return
literal|6
return|;
comment|// 2-byte jmp instruction + 32-bit relative address
elseif|else
if|if
condition|(
name|Arch
operator|==
name|Triple
operator|::
name|systemz
condition|)
return|return
literal|16
return|;
else|else
return|return
literal|0
return|;
block|}
name|unsigned
name|getStubAlignment
parameter_list|()
function|override
block|{
if|if
condition|(
name|Arch
operator|==
name|Triple
operator|::
name|systemz
condition|)
return|return
literal|8
return|;
else|else
return|return
literal|1
return|;
block|}
name|void
name|setMipsABI
argument_list|(
specifier|const
name|ObjectFile
operator|&
name|Obj
argument_list|)
name|override
decl_stmt|;
name|Error
name|findPPC64TOCSection
parameter_list|(
specifier|const
name|ELFObjectFileBase
modifier|&
name|Obj
parameter_list|,
name|ObjSectionToIDMap
modifier|&
name|LocalSections
parameter_list|,
name|RelocationValueRef
modifier|&
name|Rel
parameter_list|)
function_decl|;
name|Error
name|findOPDEntrySection
parameter_list|(
specifier|const
name|ELFObjectFileBase
modifier|&
name|Obj
parameter_list|,
name|ObjSectionToIDMap
modifier|&
name|LocalSections
parameter_list|,
name|RelocationValueRef
modifier|&
name|Rel
parameter_list|)
function_decl|;
name|protected
label|:
name|size_t
name|getGOTEntrySize
argument_list|()
name|override
expr_stmt|;
name|private
label|:
name|SectionEntry
modifier|&
name|getSection
parameter_list|(
name|unsigned
name|SectionID
parameter_list|)
block|{
return|return
name|Sections
index|[
name|SectionID
index|]
return|;
block|}
comment|// Allocate no GOT entries for use in the given section.
name|uint64_t
name|allocateGOTEntries
parameter_list|(
name|unsigned
name|no
parameter_list|)
function_decl|;
comment|// Find GOT entry corresponding to relocation or create new one.
name|uint64_t
name|findOrAllocGOTEntry
parameter_list|(
specifier|const
name|RelocationValueRef
modifier|&
name|Value
parameter_list|,
name|unsigned
name|GOTRelType
parameter_list|)
function_decl|;
comment|// Resolve the relvative address of GOTOffset in Section ID and place
comment|// it at the given Offset
name|void
name|resolveGOTOffsetRelocation
parameter_list|(
name|unsigned
name|SectionID
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|GOTOffset
parameter_list|,
name|uint32_t
name|Type
parameter_list|)
function_decl|;
comment|// For a GOT entry referenced from SectionID, compute a relocation entry
comment|// that will place the final resolved value in the GOT slot
name|RelocationEntry
name|computeGOTOffsetRE
parameter_list|(
name|uint64_t
name|GOTOffset
parameter_list|,
name|uint64_t
name|SymbolOffset
parameter_list|,
name|unsigned
name|Type
parameter_list|)
function_decl|;
comment|// Compute the address in memory where we can find the placeholder
name|void
modifier|*
name|computePlaceholderAddress
argument_list|(
name|unsigned
name|SectionID
argument_list|,
name|uint64_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
comment|// Split out common case for createing the RelocationEntry for when the relocation requires
comment|// no particular advanced processing.
name|void
name|processSimpleRelocation
parameter_list|(
name|unsigned
name|SectionID
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|unsigned
name|RelType
parameter_list|,
name|RelocationValueRef
name|Value
parameter_list|)
function_decl|;
comment|// Return matching *LO16 relocation (Mips specific)
name|uint32_t
name|getMatchingLoRelocation
argument_list|(
name|uint32_t
name|RelType
argument_list|,
name|bool
name|IsLocal
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|// The tentative ID for the GOT section
name|unsigned
name|GOTSectionID
decl_stmt|;
comment|// Records the current number of allocated slots in the GOT
comment|// (This would be equivalent to GOTEntries.size() were it not for relocations
comment|// that consume more than one slot)
name|unsigned
name|CurrentGOTIndex
decl_stmt|;
name|protected
label|:
comment|// A map from section to a GOT section that has entries for section's GOT
comment|// relocations. (Mips64 specific)
name|DenseMap
operator|<
name|SID
operator|,
name|SID
operator|>
name|SectionToGOTMap
expr_stmt|;
name|private
label|:
comment|// A map to avoid duplicate got entries (Mips64 specific)
name|StringMap
operator|<
name|uint64_t
operator|>
name|GOTSymbolOffsets
expr_stmt|;
comment|// *HI16 relocations will be added for resolving when we find matching
comment|// *LO16 part. (Mips specific)
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|RelocationValueRef
operator|,
name|RelocationEntry
operator|>
operator|,
literal|8
operator|>
name|PendingRelocs
expr_stmt|;
comment|// When a module is loaded we save the SectionID of the EH frame section
comment|// in a table until we receive a request to register all unregistered
comment|// EH frame sections with the memory manager.
name|SmallVector
operator|<
name|SID
operator|,
literal|2
operator|>
name|UnregisteredEHFrameSections
expr_stmt|;
name|SmallVector
operator|<
name|SID
operator|,
literal|2
operator|>
name|RegisteredEHFrameSections
expr_stmt|;
comment|// Map between GOT relocation value and corresponding GOT offset
name|std
operator|::
name|map
operator|<
name|RelocationValueRef
operator|,
name|uint64_t
operator|>
name|GOTOffsetMap
expr_stmt|;
name|bool
name|relocationNeedsGot
argument_list|(
specifier|const
name|RelocationRef
operator|&
name|R
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|relocationNeedsStub
argument_list|(
specifier|const
name|RelocationRef
operator|&
name|R
argument_list|)
decl|const
name|override
decl_stmt|;
name|public
label|:
name|RuntimeDyldELF
argument_list|(
name|RuntimeDyld
operator|::
name|MemoryManager
operator|&
name|MemMgr
argument_list|,
name|JITSymbolResolver
operator|&
name|Resolver
argument_list|)
expr_stmt|;
operator|~
name|RuntimeDyldELF
argument_list|()
name|override
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyldELF
operator|>
name|create
argument_list|(
argument|Triple::ArchType Arch
argument_list|,
argument|RuntimeDyld::MemoryManager&MemMgr
argument_list|,
argument|JITSymbolResolver&Resolver
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyld
operator|::
name|LoadedObjectInfo
operator|>
name|loadObject
argument_list|(
argument|const object::ObjectFile&O
argument_list|)
name|override
expr_stmt|;
name|void
name|resolveRelocation
argument_list|(
specifier|const
name|RelocationEntry
operator|&
name|RE
argument_list|,
name|uint64_t
name|Value
argument_list|)
name|override
decl_stmt|;
name|Expected
operator|<
name|relocation_iterator
operator|>
name|processRelocationRef
argument_list|(
argument|unsigned SectionID
argument_list|,
argument|relocation_iterator RelI
argument_list|,
argument|const ObjectFile&Obj
argument_list|,
argument|ObjSectionToIDMap&ObjSectionToID
argument_list|,
argument|StubMap&Stubs
argument_list|)
name|override
expr_stmt|;
name|bool
name|isCompatibleFile
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|Obj
argument_list|)
decl|const
name|override
decl_stmt|;
name|void
name|registerEHFrames
argument_list|()
name|override
expr_stmt|;
name|void
name|deregisterEHFrames
argument_list|()
name|override
expr_stmt|;
name|Error
name|finalizeLoad
argument_list|(
specifier|const
name|ObjectFile
operator|&
name|Obj
argument_list|,
name|ObjSectionToIDMap
operator|&
name|SectionMap
argument_list|)
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

