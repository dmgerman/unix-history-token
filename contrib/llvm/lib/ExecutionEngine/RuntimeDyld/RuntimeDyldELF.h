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
name|LLVM_RUNTIME_DYLD_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIME_DYLD_ELF_H
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
block|{
comment|// Helper for extensive error checking in debug builds.
name|std
operator|::
name|error_code
name|Check
argument_list|(
argument|std::error_code Err
argument_list|)
block|{
if|if
condition|(
name|Err
condition|)
block|{
name|report_fatal_error
argument_list|(
name|Err
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|Err
return|;
block|}
block|}
comment|// end anonymous namespace
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
name|resolveMIPSRelocation
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
name|arm64
operator|||
name|Arch
operator|==
name|Triple
operator|::
name|aarch64_be
operator|||
name|Arch
operator|==
name|Triple
operator|::
name|arm64_be
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
name|Arch
operator|==
name|Triple
operator|::
name|mipsel
operator|||
name|Arch
operator|==
name|Triple
operator|::
name|mips
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
name|findPPC64TOCSection
parameter_list|(
name|ObjectImage
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
name|void
name|findOPDEntrySection
parameter_list|(
name|ObjectImage
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
name|uint64_t
name|findGOTEntry
parameter_list|(
name|uint64_t
name|LoadAddr
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
name|size_t
name|getGOTEntrySize
parameter_list|()
function_decl|;
name|void
name|updateGOTEntries
argument_list|(
name|StringRef
name|Name
argument_list|,
name|uint64_t
name|Addr
argument_list|)
name|override
decl_stmt|;
comment|// Relocation entries for symbols whose position-independent offset is
comment|// updated in a global offset table.
typedef|typedef
name|SmallVector
operator|<
name|RelocationValueRef
operator|,
literal|2
operator|>
name|GOTRelocations
expr_stmt|;
name|GOTRelocations
name|GOTEntries
decl_stmt|;
comment|// List of entries requiring finalization.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|SID
operator|,
name|GOTRelocations
operator|>
operator|,
literal|8
operator|>
name|GOTs
expr_stmt|;
comment|// Allocated tables.
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
name|public
label|:
name|RuntimeDyldELF
argument_list|(
name|RTDyldMemoryManager
operator|*
name|mm
argument_list|)
operator|:
name|RuntimeDyldImpl
argument_list|(
argument|mm
argument_list|)
block|{}
name|void
name|resolveRelocation
argument_list|(
argument|const RelocationEntry&RE
argument_list|,
argument|uint64_t Value
argument_list|)
name|override
expr_stmt|;
name|relocation_iterator
name|processRelocationRef
argument_list|(
name|unsigned
name|SectionID
argument_list|,
name|relocation_iterator
name|RelI
argument_list|,
name|ObjectImage
operator|&
name|Obj
argument_list|,
name|ObjSectionToIDMap
operator|&
name|ObjSectionToID
argument_list|,
specifier|const
name|SymbolTableMap
operator|&
name|Symbols
argument_list|,
name|StubMap
operator|&
name|Stubs
argument_list|)
name|override
decl_stmt|;
name|bool
name|isCompatibleFormat
argument_list|(
specifier|const
name|ObjectBuffer
operator|*
name|Buffer
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|isCompatibleFile
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Buffer
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
name|void
name|finalizeLoad
argument_list|(
name|ObjectImage
operator|&
name|ObjImg
argument_list|,
name|ObjSectionToIDMap
operator|&
name|SectionMap
argument_list|)
name|override
decl_stmt|;
name|virtual
operator|~
name|RuntimeDyldELF
argument_list|()
expr_stmt|;
specifier|static
name|ObjectImage
modifier|*
name|createObjectImage
parameter_list|(
name|ObjectBuffer
modifier|*
name|InputBuffer
parameter_list|)
function_decl|;
specifier|static
name|ObjectImage
modifier|*
name|createObjectImageFromFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|Obj
argument_list|)
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

