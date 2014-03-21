begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyldMachO.h - Run-time dynamic linker for MC-JIT ---*- C++ -*-=//
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
comment|// MachO support for MC-JIT runtime dynamic linker.
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
name|LLVM_RUNTIME_DYLD_MACHO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIME_DYLD_MACHO_H
end_define

begin_include
include|#
directive|include
file|"RuntimeDyldImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/MachO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|namespace
name|llvm
operator|::
name|object
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RuntimeDyldMachO
range|:
name|public
name|RuntimeDyldImpl
block|{
name|bool
name|resolveI386Relocation
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|uint64_t FinalAddress
argument_list|,
argument|uint64_t Value
argument_list|,
argument|bool isPCRel
argument_list|,
argument|unsigned Type
argument_list|,
argument|unsigned Size
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|bool
name|resolveX86_64Relocation
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|uint64_t FinalAddress
argument_list|,
argument|uint64_t Value
argument_list|,
argument|bool isPCRel
argument_list|,
argument|unsigned Type
argument_list|,
argument|unsigned Size
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|bool
name|resolveARMRelocation
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|uint64_t FinalAddress
argument_list|,
argument|uint64_t Value
argument_list|,
argument|bool isPCRel
argument_list|,
argument|unsigned Type
argument_list|,
argument|unsigned Size
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
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
argument|bool isPCRel
argument_list|,
argument|unsigned Size
argument_list|)
block|;
name|unsigned
name|getMaxStubSize
argument_list|()
block|{
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
name|x86_64
condition|)
return|return
literal|8
return|;
comment|// GOT entry
else|else
return|return
literal|0
return|;
block|}
name|unsigned
name|getStubAlignment
argument_list|()
block|{
return|return
literal|1
return|;
block|}
expr|struct
name|EHFrameRelatedSections
block|{
name|EHFrameRelatedSections
argument_list|()
operator|:
name|EHFrameSID
argument_list|(
name|RTDYLD_INVALID_SECTION_ID
argument_list|)
block|,
name|TextSID
argument_list|(
name|RTDYLD_INVALID_SECTION_ID
argument_list|)
block|,
name|ExceptTabSID
argument_list|(
argument|RTDYLD_INVALID_SECTION_ID
argument_list|)
block|{}
name|EHFrameRelatedSections
argument_list|(
argument|SID EH
argument_list|,
argument|SID T
argument_list|,
argument|SID Ex
argument_list|)
operator|:
name|EHFrameSID
argument_list|(
name|EH
argument_list|)
block|,
name|TextSID
argument_list|(
name|T
argument_list|)
block|,
name|ExceptTabSID
argument_list|(
argument|Ex
argument_list|)
block|{}
name|SID
name|EHFrameSID
block|;
name|SID
name|TextSID
block|;
name|SID
name|ExceptTabSID
block|;   }
block|;
comment|// When a module is loaded we save the SectionID of the EH frame section
comment|// in a table until we receive a request to register all unregistered
comment|// EH frame sections with the memory manager.
name|SmallVector
operator|<
name|EHFrameRelatedSections
block|,
literal|2
operator|>
name|UnregisteredEHFrameSections
block|;
name|public
operator|:
name|RuntimeDyldMachO
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
name|virtual
name|void
name|resolveRelocation
argument_list|(
argument|const RelocationEntry&RE
argument_list|,
argument|uint64_t Value
argument_list|)
block|;
name|virtual
name|void
name|processRelocationRef
argument_list|(
argument|unsigned SectionID
argument_list|,
argument|RelocationRef RelI
argument_list|,
argument|ObjectImage&Obj
argument_list|,
argument|ObjSectionToIDMap&ObjSectionToID
argument_list|,
argument|const SymbolTableMap&Symbols
argument_list|,
argument|StubMap&Stubs
argument_list|)
block|;
name|virtual
name|bool
name|isCompatibleFormat
argument_list|(
argument|const ObjectBuffer *Buffer
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|registerEHFrames
argument_list|()
block|;
name|virtual
name|void
name|finalizeLoad
argument_list|(
name|ObjSectionToIDMap
operator|&
name|SectionMap
argument_list|)
block|; }
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

