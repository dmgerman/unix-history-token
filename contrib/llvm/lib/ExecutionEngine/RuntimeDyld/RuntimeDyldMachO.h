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
file|"ObjectImageCommon.h"
end_include

begin_include
include|#
directive|include
file|"RuntimeDyldImpl.h"
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

begin_define
define|#
directive|define
name|DEBUG_TYPE
value|"dyld"
end_define

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
name|protected
operator|:
expr|struct
name|SectionOffsetPair
block|{
name|unsigned
name|SectionID
block|;
name|uint64_t
name|Offset
block|;   }
block|;    struct
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
comment|/// Extract the addend encoded in the instruction.
name|uint64_t
name|decodeAddend
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|unsigned NumBytes
argument_list|,
argument|uint32_t RelType
argument_list|)
specifier|const
block|;
comment|/// Construct a RelocationValueRef representing the relocation target.
comment|/// For Symbols in known sections, this will return a RelocationValueRef
comment|/// representing a (SectionID, Offset) pair.
comment|/// For Symbols whose section is not known, this will return a
comment|/// (SymbolName, Offset) pair, where the Offset is taken from the instruction
comment|/// immediate (held in RE.Addend).
comment|/// In both cases the Addend field is *NOT* fixed up to be PC-relative. That
comment|/// should be done by the caller where appropriate by calling makePCRel on
comment|/// the RelocationValueRef.
name|RelocationValueRef
name|getRelocationValueRef
argument_list|(
name|ObjectImage
operator|&
name|ObjImg
argument_list|,
specifier|const
name|relocation_iterator
operator|&
name|RI
argument_list|,
specifier|const
name|RelocationEntry
operator|&
name|RE
argument_list|,
name|ObjSectionToIDMap
operator|&
name|ObjSectionToID
argument_list|,
specifier|const
name|SymbolTableMap
operator|&
name|Symbols
argument_list|)
block|;
comment|/// Make the RelocationValueRef addend PC-relative.
name|void
name|makeValueAddendPCRel
argument_list|(
name|RelocationValueRef
operator|&
name|Value
argument_list|,
name|ObjectImage
operator|&
name|ObjImg
argument_list|,
specifier|const
name|relocation_iterator
operator|&
name|RI
argument_list|)
block|;
comment|/// Dump information about the relocation entry (RE) and resolved value.
name|void
name|dumpRelocationToResolve
argument_list|(
argument|const RelocationEntry&RE
argument_list|,
argument|uint64_t Value
argument_list|)
specifier|const
block|;
name|public
operator|:
comment|/// Create an ObjectImage from the given ObjectBuffer.
specifier|static
name|ObjectImage
operator|*
name|createObjectImage
argument_list|(
argument|ObjectBuffer *InputBuffer
argument_list|)
block|{
return|return
name|new
name|ObjectImageCommon
argument_list|(
name|InputBuffer
argument_list|)
return|;
block|}
comment|/// Create an ObjectImage from the given ObjectFile.
specifier|static
name|ObjectImage
operator|*
name|createObjectImageFromFile
argument_list|(
argument|std::unique_ptr<object::ObjectFile> InputObject
argument_list|)
block|{
return|return
name|new
name|ObjectImageCommon
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|InputObject
argument_list|)
argument_list|)
return|;
block|}
comment|/// Create a RuntimeDyldMachO instance for the given target architecture.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyldMachO
operator|>
name|create
argument_list|(
argument|Triple::ArchType Arch
argument_list|,
argument|RTDyldMemoryManager *mm
argument_list|)
block|;
comment|/// Write the least significant 'Size' bytes in 'Value' out at the address
comment|/// pointed to by Addr. Check for overflow.
name|bool
name|writeBytesUnaligned
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t Value
argument_list|,
argument|unsigned Size
argument_list|)
block|;
name|SectionEntry
operator|&
name|getSection
argument_list|(
argument|unsigned SectionID
argument_list|)
block|{
return|return
name|Sections
index|[
name|SectionID
index|]
return|;
block|}
name|bool
name|isCompatibleFormat
argument_list|(
argument|const ObjectBuffer *Buffer
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isCompatibleFile
argument_list|(
argument|const object::ObjectFile *Obj
argument_list|)
specifier|const
name|override
block|;
name|void
name|registerEHFrames
argument_list|()
name|override
block|; }
decl_stmt|;
comment|/// RuntimeDyldMachOTarget - Templated base class for generic MachO linker
comment|/// algorithms and data structures.
comment|///
comment|/// Concrete, target specific sub-classes can be accessed via the impl()
comment|/// methods. (i.e. the RuntimeDyldMachO hierarchy uses the Curiously
comment|/// Recurring Template Idiom). Concrete subclasses for each target
comment|/// can be found in ./Targets.
name|template
operator|<
name|typename
name|Impl
operator|>
name|class
name|RuntimeDyldMachOCRTPBase
operator|:
name|public
name|RuntimeDyldMachO
block|{
name|private
operator|:
name|Impl
operator|&
name|impl
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|Impl
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
specifier|const
name|Impl
operator|&
name|impl
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|Impl
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
name|protected
operator|:
comment|/// Parse the given relocation, which must be a non-scattered, and
comment|/// return a RelocationEntry representing the information. The 'Addend' field
comment|/// will contain the unmodified instruction immediate.
name|RelocationEntry
name|getBasicRelocationEntry
argument_list|(
argument|unsigned SectionID
argument_list|,
argument|ObjectImage&ObjImg
argument_list|,
argument|const relocation_iterator&RI
argument_list|)
specifier|const
block|{
specifier|const
name|MachOObjectFile
operator|&
name|Obj
operator|=
name|static_cast
operator|<
specifier|const
name|MachOObjectFile
operator|&
operator|>
operator|(
operator|*
name|ObjImg
operator|.
name|getObjectFile
argument_list|()
operator|)
block|;
name|MachO
operator|::
name|any_relocation_info
name|RelInfo
operator|=
name|Obj
operator|.
name|getRelocation
argument_list|(
name|RI
operator|->
name|getRawDataRefImpl
argument_list|()
argument_list|)
block|;
specifier|const
name|SectionEntry
operator|&
name|Section
operator|=
name|Sections
index|[
name|SectionID
index|]
block|;
name|bool
name|IsPCRel
operator|=
name|Obj
operator|.
name|getAnyRelocationPCRel
argument_list|(
name|RelInfo
argument_list|)
block|;
name|unsigned
name|Size
operator|=
name|Obj
operator|.
name|getAnyRelocationLength
argument_list|(
name|RelInfo
argument_list|)
block|;
name|uint64_t
name|Offset
block|;
name|RI
operator|->
name|getOffset
argument_list|(
name|Offset
argument_list|)
block|;
name|uint8_t
operator|*
name|LocalAddress
operator|=
name|Section
operator|.
name|Address
operator|+
name|Offset
block|;
name|unsigned
name|NumBytes
operator|=
literal|1
operator|<<
name|Size
block|;
name|uint32_t
name|RelType
operator|=
name|Obj
operator|.
name|getAnyRelocationType
argument_list|(
name|RelInfo
argument_list|)
block|;
name|uint64_t
name|Addend
operator|=
name|impl
argument_list|()
operator|.
name|decodeAddend
argument_list|(
name|LocalAddress
argument_list|,
name|NumBytes
argument_list|,
name|RelType
argument_list|)
block|;
return|return
name|RelocationEntry
argument_list|(
name|SectionID
argument_list|,
name|Offset
argument_list|,
name|RelType
argument_list|,
name|Addend
argument_list|,
name|IsPCRel
argument_list|,
name|Size
argument_list|)
return|;
block|}
name|public
operator|:
name|RuntimeDyldMachOCRTPBase
argument_list|(
name|RTDyldMemoryManager
operator|*
name|mm
argument_list|)
operator|:
name|RuntimeDyldMachO
argument_list|(
argument|mm
argument_list|)
block|{}
name|void
name|finalizeLoad
argument_list|(
argument|ObjectImage&ObjImg
argument_list|,
argument|ObjSectionToIDMap&SectionMap
argument_list|)
block|{
name|unsigned
name|EHFrameSID
operator|=
name|RTDYLD_INVALID_SECTION_ID
block|;
name|unsigned
name|TextSID
operator|=
name|RTDYLD_INVALID_SECTION_ID
block|;
name|unsigned
name|ExceptTabSID
operator|=
name|RTDYLD_INVALID_SECTION_ID
block|;
name|ObjSectionToIDMap
operator|::
name|iterator
name|i
block|,
name|e
block|;
for|for
control|(
name|i
operator|=
name|SectionMap
operator|.
name|begin
argument_list|()
operator|,
name|e
operator|=
name|SectionMap
operator|.
name|end
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|SectionRef
modifier|&
name|Section
init|=
name|i
operator|->
name|first
decl_stmt|;
name|StringRef
name|Name
decl_stmt|;
name|Section
operator|.
name|getName
argument_list|(
name|Name
argument_list|)
expr_stmt|;
if|if
condition|(
name|Name
operator|==
literal|"__eh_frame"
condition|)
name|EHFrameSID
operator|=
name|i
operator|->
name|second
expr_stmt|;
elseif|else
if|if
condition|(
name|Name
operator|==
literal|"__text"
condition|)
name|TextSID
operator|=
name|i
operator|->
name|second
expr_stmt|;
elseif|else
if|if
condition|(
name|Name
operator|==
literal|"__gcc_except_tab"
condition|)
name|ExceptTabSID
operator|=
name|i
operator|->
name|second
expr_stmt|;
else|else
name|impl
argument_list|()
operator|.
name|finalizeSection
argument_list|(
name|ObjImg
argument_list|,
name|i
operator|->
name|second
argument_list|,
name|Section
argument_list|)
expr_stmt|;
block|}
name|UnregisteredEHFrameSections
operator|.
name|push_back
argument_list|(
name|EHFrameRelatedSections
argument_list|(
name|EHFrameSID
argument_list|,
name|TextSID
argument_list|,
name|ExceptTabSID
argument_list|)
argument_list|)
expr_stmt|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

