begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/SectionChunks.h -------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_READER_WRITER_ELF_SECTION_CHUNKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_SECTION_CHUNKS_H
end_define

begin_include
include|#
directive|include
file|"Chunk.h"
end_include

begin_include
include|#
directive|include
file|"TargetHandler.h"
end_include

begin_include
include|#
directive|include
file|"Writer.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/DefinedAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/range.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/AtomLayout.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/ELFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileOutputBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|template
operator|<
name|class
operator|>
name|class
name|OutputSection
expr_stmt|;
name|using
name|namespace
name|llvm
operator|::
name|ELF
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|Segment
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|TargetLayout
expr_stmt|;
comment|/// \brief An ELF section.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|Section
operator|:
name|public
name|Chunk
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|Section
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|StringRef chunkName
argument_list|,
argument|typename Chunk<ELFT>::Kind k = Chunk<ELFT>::Kind::ELFSection
argument_list|)
block|;
comment|/// \brief Modify the section contents before assigning virtual addresses
comment|//  or assigning file offsets
comment|/// \brief Finalize the section contents before writing
comment|/// \brief Does this section have an output segment.
name|virtual
name|bool
name|hasOutputSegment
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return if the section is a loadable section that occupies memory
name|virtual
name|bool
name|isLoadableSection
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Assign file offsets starting at offset.
name|virtual
name|void
name|assignFileOffsets
argument_list|(
argument|uint64_t offset
argument_list|)
block|{}
comment|/// \brief Assign virtual addresses starting at addr.
name|virtual
name|void
name|assignVirtualAddress
argument_list|(
argument|uint64_t addr
argument_list|)
block|{}
name|uint64_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|_flags
return|;
block|}
name|uint64_t
name|getEntSize
argument_list|()
specifier|const
block|{
return|return
name|_entSize
return|;
block|}
name|uint32_t
name|getType
argument_list|()
specifier|const
block|{
return|return
name|_type
return|;
block|}
name|uint32_t
name|getLink
argument_list|()
specifier|const
block|{
return|return
name|_link
return|;
block|}
name|uint32_t
name|getInfo
argument_list|()
specifier|const
block|{
return|return
name|_info
return|;
block|}
name|typename
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|::
name|SegmentType
name|getSegmentType
argument_list|()
specifier|const
block|{
return|return
name|_segmentType
return|;
block|}
comment|/// \brief Return the type of content that the section contains
name|int
name|getContentType
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief convert the segment type to a String for diagnostics and printing
comment|/// purposes
name|virtual
name|StringRef
name|segmentKindToStr
argument_list|()
specifier|const
block|;
comment|/// \brief Records the segmentType, that this section belongs to
name|void
name|setSegmentType
argument_list|(
argument|const typename TargetLayout<ELFT>::SegmentType segmentType
argument_list|)
block|{
name|this
operator|->
name|_segmentType
operator|=
name|segmentType
block|;   }
name|virtual
specifier|const
name|AtomLayout
operator|*
name|findAtomLayoutByName
argument_list|(
argument|StringRef
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
specifier|const
name|OutputSection
operator|<
name|ELFT
operator|>
operator|*
name|getOutputSection
argument_list|()
specifier|const
block|{
return|return
name|_outputSection
return|;
block|}
name|void
name|setOutputSection
argument_list|(
argument|OutputSection<ELFT> *os
argument_list|,
argument|bool isFirst = false
argument_list|)
block|{
name|_outputSection
operator|=
name|os
block|;
name|_isFirstSectionInOutputSection
operator|=
name|isFirst
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Chunk<ELFT> *c
argument_list|)
block|{
return|return
name|c
operator|->
name|kind
argument_list|()
operator|==
name|Chunk
operator|<
name|ELFT
operator|>
operator|::
name|Kind
operator|::
name|ELFSection
operator|||
name|c
operator|->
name|kind
argument_list|()
operator|==
name|Chunk
operator|<
name|ELFT
operator|>
operator|::
name|Kind
operator|::
name|AtomSection
return|;
block|}
name|uint64_t
name|alignment
argument_list|()
specifier|const
name|override
block|{
return|return
name|_isFirstSectionInOutputSection
operator|?
name|_outputSection
operator|->
name|alignment
argument_list|()
operator|:
name|this
operator|->
name|_alignment
return|;
block|}
name|virtual
name|StringRef
name|inputSectionName
argument_list|()
specifier|const
block|{
return|return
name|_inputSectionName
return|;
block|}
name|virtual
name|StringRef
name|outputSectionName
argument_list|()
specifier|const
block|{
return|return
name|_outputSectionName
return|;
block|}
name|virtual
name|void
name|setOutputSectionName
argument_list|(
argument|StringRef outputSectionName
argument_list|)
block|{
name|_outputSectionName
operator|=
name|outputSectionName
block|;   }
name|void
name|setArchiveNameOrPath
argument_list|(
argument|StringRef name
argument_list|)
block|{
name|_archivePath
operator|=
name|name
block|; }
name|void
name|setMemberNameOrPath
argument_list|(
argument|StringRef name
argument_list|)
block|{
name|_memberPath
operator|=
name|name
block|; }
name|StringRef
name|archivePath
argument_list|()
block|{
return|return
name|_archivePath
return|;
block|}
name|StringRef
name|memberPath
argument_list|()
block|{
return|return
name|_memberPath
return|;
block|}
name|protected
operator|:
comment|/// \brief OutputSection this Section is a member of, or nullptr.
name|OutputSection
operator|<
name|ELFT
operator|>
operator|*
name|_outputSection
operator|=
name|nullptr
block|;
comment|/// \brief ELF SHF_* flags.
name|uint64_t
name|_flags
operator|=
literal|0
block|;
comment|/// \brief The size of each entity.
name|uint64_t
name|_entSize
operator|=
literal|0
block|;
comment|/// \brief ELF SHT_* type.
name|uint32_t
name|_type
operator|=
literal|0
block|;
comment|/// \brief sh_link field.
name|uint32_t
name|_link
operator|=
literal|0
block|;
comment|/// \brief the sh_info field.
name|uint32_t
name|_info
operator|=
literal|0
block|;
comment|/// \brief Is this the first section in the output section.
name|bool
name|_isFirstSectionInOutputSection
operator|=
name|false
block|;
comment|/// \brief the output ELF segment type of this section.
name|typename
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|::
name|SegmentType
name|_segmentType
operator|=
name|SHT_NULL
block|;
comment|/// \brief Input section name.
name|StringRef
name|_inputSectionName
block|;
comment|/// \brief Output section name.
name|StringRef
name|_outputSectionName
block|;
name|StringRef
name|_archivePath
block|;
name|StringRef
name|_memberPath
block|; }
expr_stmt|;
comment|/// \brief A section containing atoms.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|AtomSection
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|AtomSection
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|int32_t contentType
argument_list|,
argument|int32_t permissions
argument_list|,
argument|int32_t order
argument_list|)
block|;
comment|/// Align the offset to the required modulus defined by the atom alignment
name|uint64_t
name|alignOffset
argument_list|(
argument|uint64_t offset
argument_list|,
argument|DefinedAtom::Alignment&atomAlign
argument_list|)
block|;
comment|/// Return if the section is a loadable section that occupies memory
name|bool
name|isLoadableSection
argument_list|()
specifier|const
name|override
block|{
return|return
name|_isLoadedInMemory
return|;
block|}
comment|// \brief Append an atom to a Section. The atom gets pushed into a vector
comment|// contains the atom, the atom file offset, the atom virtual address
comment|// the atom file offset is aligned appropriately as set by the Reader
name|virtual
specifier|const
name|AtomLayout
operator|*
name|appendAtom
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|)
block|;
comment|/// \brief Set the virtual address of each Atom in the Section. This
comment|/// routine gets called after the linker fixes up the virtual address
comment|/// of the section
name|void
name|assignVirtualAddress
argument_list|(
argument|uint64_t addr
argument_list|)
name|override
block|;
comment|/// \brief Set the file offset of each Atom in the section. This routine
comment|/// gets called after the linker fixes up the section offset
name|void
name|assignFileOffsets
argument_list|(
argument|uint64_t offset
argument_list|)
name|override
block|;
comment|/// \brief Find the Atom address given a name, this is needed to properly
comment|///  apply relocation. The section class calls this to find the atom address
comment|///  to fix the relocation
specifier|const
name|AtomLayout
operator|*
name|findAtomLayoutByName
argument_list|(
argument|StringRef name
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Return the raw flags, we need this to sort segments
name|int64_t
name|atomflags
argument_list|()
specifier|const
block|{
return|return
name|_contentPermissions
return|;
block|}
comment|/// Atom Iterators
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|AtomLayout
operator|*
operator|>
operator|::
name|iterator
name|atom_iter
expr_stmt|;
name|range
operator|<
name|atom_iter
operator|>
name|atoms
argument_list|()
block|{
return|return
name|_atoms
return|;
block|}
name|void
name|write
argument_list|(
argument|ELFWriter *writer
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|llvm::FileOutputBuffer&buffer
argument_list|)
name|override
expr_stmt|;
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
name|c
argument_list|)
block|{
return|return
name|c
operator|->
name|kind
argument_list|()
operator|==
name|Chunk
operator|<
name|ELFT
operator|>
operator|::
name|Kind
operator|::
name|AtomSection
return|;
block|}
name|protected
label|:
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
expr_stmt|;
name|int32_t
name|_contentType
decl_stmt|;
name|int32_t
name|_contentPermissions
decl_stmt|;
name|bool
name|_isLoadedInMemory
init|=
name|true
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|AtomLayout
operator|*
operator|>
name|_atoms
expr_stmt|;
name|mutable
name|std
operator|::
name|mutex
name|_outputMutex
expr_stmt|;
name|std
operator|::
name|string
name|formatError
argument_list|(
argument|const std::string&errorStr
argument_list|,
argument|const AtomLayout&atom
argument_list|,
argument|const Reference&ref
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief A OutputSection represents a set of sections grouped by the same
comment|/// name. The output file that gets written by the linker has sections grouped
comment|/// by similar names
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|OutputSection
block|{
name|public
operator|:
comment|// Iterators
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|Section
operator|<
name|ELFT
operator|>
operator|*
operator|>
operator|::
name|iterator
name|SectionIter
expr_stmt|;
name|OutputSection
argument_list|(
argument|StringRef name
argument_list|)
operator|:
name|_name
argument_list|(
argument|name
argument_list|)
block|{}
comment|// Appends a section into the list of sections that are part of this Output
comment|// Section
name|void
name|appendSection
argument_list|(
name|Section
operator|<
name|ELFT
operator|>
operator|*
name|c
argument_list|)
expr_stmt|;
comment|// Set the OutputSection is associated with a segment
name|void
name|setHasSegment
parameter_list|()
block|{
name|_hasSegment
operator|=
name|true
expr_stmt|;
block|}
comment|/// Sets the ordinal
name|void
name|setOrdinal
parameter_list|(
name|uint64_t
name|ordinal
parameter_list|)
block|{
name|_ordinal
operator|=
name|ordinal
expr_stmt|;
block|}
comment|/// Sets the Memory size
name|void
name|setMemSize
parameter_list|(
name|uint64_t
name|memsz
parameter_list|)
block|{
name|_memSize
operator|=
name|memsz
expr_stmt|;
block|}
comment|/// Sets the size fo the output Section.
name|void
name|setSize
parameter_list|(
name|uint64_t
name|fsiz
parameter_list|)
block|{
name|_size
operator|=
name|fsiz
expr_stmt|;
block|}
comment|// The offset of the first section contained in the output section is
comment|// contained here.
name|void
name|setFileOffset
parameter_list|(
name|uint64_t
name|foffset
parameter_list|)
block|{
name|_fileOffset
operator|=
name|foffset
expr_stmt|;
block|}
comment|// Sets the starting address of the section
name|void
name|setAddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
name|_virtualAddr
operator|=
name|addr
expr_stmt|;
block|}
comment|// Is the section loadable?
name|bool
name|isLoadableSection
argument_list|()
specifier|const
block|{
return|return
name|_isLoadableSection
return|;
block|}
comment|// Set section Loadable
name|void
name|setLoadableSection
parameter_list|(
name|bool
name|isLoadable
parameter_list|)
block|{
name|_isLoadableSection
operator|=
name|isLoadable
expr_stmt|;
block|}
name|void
name|setLink
parameter_list|(
name|uint64_t
name|link
parameter_list|)
block|{
name|_link
operator|=
name|link
expr_stmt|;
block|}
name|void
name|setInfo
parameter_list|(
name|uint64_t
name|info
parameter_list|)
block|{
name|_shInfo
operator|=
name|info
expr_stmt|;
block|}
name|void
name|setFlag
parameter_list|(
name|uint64_t
name|flags
parameter_list|)
block|{
name|_flags
operator|=
name|flags
expr_stmt|;
block|}
name|void
name|setType
parameter_list|(
name|int64_t
name|type
parameter_list|)
block|{
name|_type
operator|=
name|type
expr_stmt|;
block|}
name|range
operator|<
name|SectionIter
operator|>
name|sections
argument_list|()
block|{
return|return
name|_sections
return|;
block|}
comment|// The below functions returns the properties of the OutputSection.
name|bool
name|hasSegment
argument_list|()
specifier|const
block|{
return|return
name|_hasSegment
return|;
block|}
name|StringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
return|;
block|}
name|int64_t
name|shinfo
argument_list|()
specifier|const
block|{
return|return
name|_shInfo
return|;
block|}
name|uint64_t
name|alignment
argument_list|()
specifier|const
block|{
return|return
name|_alignment
return|;
block|}
name|int64_t
name|link
argument_list|()
specifier|const
block|{
return|return
name|_link
return|;
block|}
name|int64_t
name|type
argument_list|()
specifier|const
block|{
return|return
name|_type
return|;
block|}
name|uint64_t
name|virtualAddr
argument_list|()
specifier|const
block|{
return|return
name|_virtualAddr
return|;
block|}
name|int64_t
name|ordinal
argument_list|()
specifier|const
block|{
return|return
name|_ordinal
return|;
block|}
name|int64_t
name|kind
argument_list|()
specifier|const
block|{
return|return
name|_kind
return|;
block|}
name|uint64_t
name|fileSize
argument_list|()
specifier|const
block|{
return|return
name|_size
return|;
block|}
name|int64_t
name|entsize
argument_list|()
specifier|const
block|{
return|return
name|_entSize
return|;
block|}
name|uint64_t
name|fileOffset
argument_list|()
specifier|const
block|{
return|return
name|_fileOffset
return|;
block|}
name|uint64_t
name|flags
argument_list|()
specifier|const
block|{
return|return
name|_flags
return|;
block|}
name|uint64_t
name|memSize
argument_list|()
specifier|const
block|{
return|return
name|_memSize
return|;
block|}
name|private
label|:
name|StringRef
name|_name
decl_stmt|;
name|bool
name|_hasSegment
init|=
name|false
decl_stmt|;
name|uint64_t
name|_ordinal
init|=
literal|0
decl_stmt|;
name|uint64_t
name|_flags
init|=
literal|0
decl_stmt|;
name|uint64_t
name|_size
init|=
literal|0
decl_stmt|;
name|uint64_t
name|_memSize
init|=
literal|0
decl_stmt|;
name|uint64_t
name|_fileOffset
init|=
literal|0
decl_stmt|;
name|uint64_t
name|_virtualAddr
init|=
literal|0
decl_stmt|;
name|int64_t
name|_shInfo
init|=
literal|0
decl_stmt|;
name|int64_t
name|_entSize
init|=
literal|0
decl_stmt|;
name|int64_t
name|_link
init|=
literal|0
decl_stmt|;
name|uint64_t
name|_alignment
init|=
literal|1
decl_stmt|;
name|int64_t
name|_kind
init|=
literal|0
decl_stmt|;
name|int64_t
name|_type
init|=
literal|0
decl_stmt|;
name|bool
name|_isLoadableSection
init|=
name|false
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Section
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|_sections
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief The class represents the ELF String Table
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|StringTable
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|StringTable
argument_list|(
argument|const ELFLinkingContext&
argument_list|,
argument|const char *str
argument_list|,
argument|int32_t order
argument_list|,
argument|bool dynamic = false
argument_list|)
block|;
name|uint64_t
name|addString
argument_list|(
argument|StringRef symname
argument_list|)
block|;
name|void
name|write
argument_list|(
argument|ELFWriter *writer
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|llvm::FileOutputBuffer&buffer
argument_list|)
name|override
block|;
name|void
name|setNumEntries
argument_list|(
argument|int64_t numEntries
argument_list|)
block|{
name|_stringMap
operator|.
name|resize
argument_list|(
name|numEntries
argument_list|)
block|; }
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|_strings
block|;    struct
name|StringRefMappingInfo
block|{
specifier|static
name|StringRef
name|getEmptyKey
argument_list|()
block|{
return|return
name|StringRef
argument_list|()
return|;
block|}
specifier|static
name|StringRef
name|getTombstoneKey
argument_list|()
block|{
return|return
name|StringRef
argument_list|(
literal|" "
argument_list|,
literal|1
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|StringRef const val
argument_list|)
block|{
return|return
name|llvm
operator|::
name|HashString
argument_list|(
name|val
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isEqual
parameter_list|(
name|StringRef
specifier|const
name|lhs
parameter_list|,
name|StringRef
specifier|const
name|rhs
parameter_list|)
block|{
return|return
name|lhs
operator|.
name|equals
argument_list|(
name|rhs
argument_list|)
return|;
block|}
end_function

begin_typedef
unit|};
typedef|typedef
name|typename
name|llvm
operator|::
name|DenseMap
operator|<
name|StringRef
operator|,
name|uint64_t
operator|,
name|StringRefMappingInfo
operator|>
name|StringMapT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|StringMapT
operator|::
name|iterator
name|StringMapTIter
expr_stmt|;
end_typedef

begin_decl_stmt
name|StringMapT
name|_stringMap
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief The SymbolTable class represents the symbol table in a ELF file
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SymbolTable
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFDataTypeTypedefHelper
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Addr
name|Elf_Addr
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Sym_Impl
operator|<
name|ELFT
operator|>
name|Elf_Sym
expr_stmt|;
end_typedef

begin_macro
name|SymbolTable
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|const char *str
argument_list|,
argument|int32_t order
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief set the number of entries that would exist in the symbol
end_comment

begin_comment
comment|/// table for the current link
end_comment

begin_decl_stmt
name|void
name|setNumEntries
argument_list|(
name|int64_t
name|numEntries
argument_list|)
decl|const
block|{
if|if
condition|(
name|_stringSection
condition|)
name|_stringSection
operator|->
name|setNumEntries
argument_list|(
name|numEntries
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief return number of entries
end_comment

begin_expr_stmt
name|std
operator|::
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|_symbolTable
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|addSymbol
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|,
name|int32_t
name|sectionIndex
parameter_list|,
name|uint64_t
name|addr
init|=
literal|0
parameter_list|,
specifier|const
name|AtomLayout
modifier|*
name|layout
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the symbol table index for an Atom. If it's not in the symbol
end_comment

begin_comment
comment|/// table, return STN_UNDEF.
end_comment

begin_decl_stmt
name|uint32_t
name|getSymbolTableIndex
argument_list|(
specifier|const
name|Atom
operator|*
name|a
argument_list|)
decl|const
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|_symbolTable
operator|.
name|size
argument_list|()
init|;
name|i
operator|<
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|_symbolTable
index|[
name|i
index|]
operator|.
name|_atom
operator|==
name|a
condition|)
return|return
name|i
return|;
return|return
name|STN_UNDEF
return|;
block|}
end_decl_stmt

begin_function
name|void
name|finalize
parameter_list|()
function|override
block|{
name|finalize
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|virtual
name|void
name|sortSymbols
parameter_list|()
block|{
name|std
operator|::
name|stable_sort
argument_list|(
name|_symbolTable
operator|.
name|begin
argument_list|()
argument_list|,
name|_symbolTable
operator|.
name|end
argument_list|()
argument_list|,
index|[]
operator|(
specifier|const
name|SymbolEntry
operator|&
name|A
operator|,
specifier|const
name|SymbolEntry
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|_symbol
operator|.
name|getBinding
argument_list|()
operator|<
name|B
operator|.
name|_symbol
operator|.
name|getBinding
argument_list|()
return|;
block|}
block|)
function|;
end_function

begin_function_decl
unit|}    virtual
name|void
name|addAbsoluteAtom
parameter_list|(
name|Elf_Sym
modifier|&
name|sym
parameter_list|,
specifier|const
name|AbsoluteAtom
modifier|*
name|aa
parameter_list|,
name|int64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|addDefinedAtom
parameter_list|(
name|Elf_Sym
modifier|&
name|sym
parameter_list|,
specifier|const
name|DefinedAtom
modifier|*
name|da
parameter_list|,
name|int64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|addUndefinedAtom
parameter_list|(
name|Elf_Sym
modifier|&
name|sym
parameter_list|,
specifier|const
name|UndefinedAtom
modifier|*
name|ua
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|addSharedLibAtom
parameter_list|(
name|Elf_Sym
modifier|&
name|sym
parameter_list|,
specifier|const
name|SharedLibraryAtom
modifier|*
name|sla
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|finalize
parameter_list|(
name|bool
name|sort
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|write
argument_list|(
name|ELFWriter
operator|*
name|writer
argument_list|,
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|layout
argument_list|,
name|llvm
operator|::
name|FileOutputBuffer
operator|&
name|buffer
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setStringSection
argument_list|(
name|StringTable
operator|<
name|ELFT
operator|>
operator|*
name|s
argument_list|)
block|{
name|_stringSection
operator|=
name|s
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|StringTable
operator|<
name|ELFT
operator|>
operator|*
name|getStringTable
argument_list|()
specifier|const
block|{
return|return
name|_stringSection
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_struct
struct|struct
name|SymbolEntry
block|{
name|SymbolEntry
argument_list|(
specifier|const
name|Atom
operator|*
name|a
argument_list|,
specifier|const
name|Elf_Sym
operator|&
name|sym
argument_list|,
specifier|const
name|AtomLayout
operator|*
name|layout
argument_list|)
operator|:
name|_atom
argument_list|(
name|a
argument_list|)
operator|,
name|_atomLayout
argument_list|(
name|layout
argument_list|)
operator|,
name|_symbol
argument_list|(
argument|sym
argument_list|)
block|{}
specifier|const
name|Atom
operator|*
name|_atom
expr_stmt|;
specifier|const
name|AtomLayout
modifier|*
name|_atomLayout
decl_stmt|;
name|Elf_Sym
name|_symbol
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
name|_symbolAllocate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|StringTable
operator|<
name|ELFT
operator|>
operator|*
name|_stringSection
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|SymbolEntry
operator|>
name|_symbolTable
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|HashSection
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DynamicSymbolTable
operator|:
name|public
name|SymbolTable
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|DynamicSymbolTable
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|const char *str
argument_list|,
argument|int32_t order
argument_list|)
block|;
comment|// Set the dynamic hash table for symbols to be added into
name|void
name|setHashTable
argument_list|(
argument|HashSection<ELFT> *hashTable
argument_list|)
block|{
name|_hashTable
operator|=
name|hashTable
block|; }
comment|// Add all the dynamic symbos to the hash table
name|void
name|addSymbolsToHashTable
argument_list|()
block|;
name|void
name|finalize
argument_list|()
name|override
block|;
name|protected
operator|:
name|HashSection
operator|<
name|ELFT
operator|>
operator|*
name|_hashTable
operator|=
name|nullptr
block|;
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|_layout
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|RelocationTable
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Rel_Impl
operator|<
name|ELFT
operator|,
name|false
operator|>
name|Elf_Rel
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Rel_Impl
operator|<
name|ELFT
operator|,
name|true
operator|>
name|Elf_Rela
expr_stmt|;
end_typedef

begin_macro
name|RelocationTable
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|StringRef str
argument_list|,
argument|int32_t order
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \returns the index of the relocation added.
end_comment

begin_function_decl
name|uint32_t
name|addRelocation
parameter_list|(
specifier|const
name|DefinedAtom
modifier|&
name|da
parameter_list|,
specifier|const
name|Reference
modifier|&
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|getRelocationIndex
parameter_list|(
specifier|const
name|Reference
modifier|&
name|r
parameter_list|,
name|uint32_t
modifier|&
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|setSymbolTable
argument_list|(
specifier|const
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|symbolTable
argument_list|)
block|{
name|_symbolTable
operator|=
name|symbolTable
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Check if any relocation modifies a read-only section.
end_comment

begin_expr_stmt
name|bool
name|canModifyReadonlySection
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|finalize
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|write
argument_list|(
name|ELFWriter
operator|*
name|writer
argument_list|,
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|layout
argument_list|,
name|llvm
operator|::
name|FileOutputBuffer
operator|&
name|buffer
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
specifier|const
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|_symbolTable
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_function_decl
name|virtual
name|void
name|writeRela
parameter_list|(
name|ELFWriter
modifier|*
name|writer
parameter_list|,
name|Elf_Rela
modifier|&
name|r
parameter_list|,
specifier|const
name|DefinedAtom
modifier|&
name|atom
parameter_list|,
specifier|const
name|Reference
modifier|&
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|writeRel
parameter_list|(
name|ELFWriter
modifier|*
name|writer
parameter_list|,
name|Elf_Rel
modifier|&
name|r
parameter_list|,
specifier|const
name|DefinedAtom
modifier|&
name|atom
parameter_list|,
specifier|const
name|Reference
modifier|&
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|getSymbolIndex
parameter_list|(
specifier|const
name|Atom
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|DefinedAtom
operator|*
operator|,
specifier|const
name|Reference
operator|*
operator|>>
name|_relocs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|HashSection
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DynamicTable
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Dyn_Impl
operator|<
name|ELFT
operator|>
name|Elf_Dyn
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Elf_Dyn
operator|>
name|EntriesT
expr_stmt|;
end_typedef

begin_macro
name|DynamicTable
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|StringRef str
argument_list|,
argument|int32_t order
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|range
operator|<
name|typename
name|EntriesT
operator|::
name|iterator
operator|>
name|entries
argument_list|()
block|{
return|return
name|_entries
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns the index of the entry.
end_comment

begin_expr_stmt
name|std
operator|::
name|size_t
name|addEntry
argument_list|(
argument|int64_t tag
argument_list|,
argument|uint64_t val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|write
argument_list|(
name|ELFWriter
operator|*
name|writer
argument_list|,
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|layout
argument_list|,
name|llvm
operator|::
name|FileOutputBuffer
operator|&
name|buffer
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|void
name|createDefaultEntries
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|void
name|doPreFlight
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Dynamic table tag for .got.plt section referencing.
end_comment

begin_comment
comment|/// Usually but not always targets use DT_PLTGOT for that.
end_comment

begin_function
name|virtual
name|int64_t
name|getGotPltTag
parameter_list|()
block|{
return|return
name|DT_PLTGOT
return|;
block|}
end_function

begin_expr_stmt
name|void
name|finalize
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|setSymbolTable
argument_list|(
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|dynsym
argument_list|)
block|{
name|_dynamicSymbolTable
operator|=
name|dynsym
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|getSymbolTable
argument_list|()
specifier|const
block|{
return|return
name|_dynamicSymbolTable
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setHashTable
argument_list|(
name|HashSection
operator|<
name|ELFT
operator|>
operator|*
name|hsh
argument_list|)
block|{
name|_hashTable
operator|=
name|hsh
expr_stmt|;
block|}
end_decl_stmt

begin_function_decl
name|virtual
name|void
name|updateDynamicTable
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|EntriesT
name|_entries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return a virtual address (maybe adjusted) for the atom layout
end_comment

begin_comment
comment|/// Some targets like microMIPS and ARM Thumb use the last bit
end_comment

begin_comment
comment|/// of a symbol's value to mark 'compressed' code. This function allows
end_comment

begin_comment
comment|/// to adjust a virtal address before using it in the dynamic table tag.
end_comment

begin_decl_stmt
name|virtual
name|uint64_t
name|getAtomVirtualAddress
argument_list|(
specifier|const
name|AtomLayout
operator|*
name|al
argument_list|)
decl|const
block|{
return|return
name|al
operator|->
name|_virtualAddr
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_hash
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_strtab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_symtab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_rela
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_relasz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_relaent
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_strsz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_syment
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_pltrelsz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_pltgot
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_pltrel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_jmprel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_init_array
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_init_arraysz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_fini_array
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_fini_arraysz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_textrel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|size_t
name|_dt_fini
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|_layout
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|_dynamicSymbolTable
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HashSection
operator|<
name|ELFT
operator|>
operator|*
name|_hashTable
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|const
name|AtomLayout
modifier|*
name|getInitAtomLayout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|AtomLayout
modifier|*
name|getFiniAtomLayout
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|InterpSection
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|InterpSection
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|StringRef str
argument_list|,
argument|int32_t order
argument_list|,
argument|StringRef interp
argument_list|)
block|;
name|void
name|write
argument_list|(
argument|ELFWriter *writer
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|llvm::FileOutputBuffer&buffer
argument_list|)
name|override
block|;
name|private
operator|:
name|StringRef
name|_interp
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The hash table in the dynamic linker is organized into
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     [ nbuckets              ]
end_comment

begin_comment
comment|///     [ nchains               ]
end_comment

begin_comment
comment|///     [ buckets[0]            ]
end_comment

begin_comment
comment|///     .........................
end_comment

begin_comment
comment|///     [ buckets[nbuckets-1]   ]
end_comment

begin_comment
comment|///     [ chains[0]             ]
end_comment

begin_comment
comment|///     .........................
end_comment

begin_comment
comment|///     [ chains[nchains - 1]   ]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// nbuckets - total number of hash buckets
end_comment

begin_comment
comment|/// nchains is equal to the number of dynamic symbols.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The symbol is searched by the dynamic linker using the below approach.
end_comment

begin_comment
comment|///  * Calculate the hash of the symbol that needs to be searched
end_comment

begin_comment
comment|///  * Take the value from the buckets[hash % nbuckets] as the index of symbol
end_comment

begin_comment
comment|///  * Compare the symbol's name, if true return, if false, look through the
end_comment

begin_comment
comment|///  * array since there was a collision
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|HashSection
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{   struct
name|SymbolTableEntry
block|{
name|StringRef
name|_name
block|;
name|uint32_t
name|_index
block|;   }
block|;
name|public
operator|:
name|HashSection
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|StringRef name
argument_list|,
argument|int32_t order
argument_list|)
block|;
comment|/// \brief add the dynamic symbol into the table so that the
comment|/// hash could be calculated
name|void
name|addSymbol
argument_list|(
argument|StringRef name
argument_list|,
argument|uint32_t index
argument_list|)
block|;
comment|/// \brief Set the dynamic symbol table
name|void
name|setSymbolTable
argument_list|(
specifier|const
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|symbolTable
argument_list|)
block|;
comment|// The size of the section has to be determined so that fileoffsets
comment|// may be properly assigned. Let's calculate the buckets and the chains
comment|// and fill the chains and the buckets hash table used by the dynamic
comment|// linker and update the filesize and memory size accordingly
name|void
name|doPreFlight
argument_list|()
name|override
block|;
name|void
name|finalize
argument_list|()
name|override
block|;
name|void
name|write
argument_list|(
argument|ELFWriter *writer
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|llvm::FileOutputBuffer&buffer
argument_list|)
name|override
block|;
name|private
operator|:
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFDataTypeTypedefHelper
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Word
name|Elf_Word
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SymbolTableEntry
operator|>
name|_entries
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|Elf_Word
operator|>
name|_buckets
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|Elf_Word
operator|>
name|_chains
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|_symbolTable
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|EHFrameHeader
operator|:
name|public
name|Section
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|EHFrameHeader
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|StringRef name
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|int32_t order
argument_list|)
block|;
name|void
name|doPreFlight
argument_list|()
name|override
block|;
name|void
name|finalize
argument_list|()
name|override
block|;
name|void
name|write
argument_list|(
argument|ELFWriter *writer
argument_list|,
argument|TargetLayout<ELFT>&layout
argument_list|,
argument|llvm::FileOutputBuffer&buffer
argument_list|)
name|override
block|;
name|private
operator|:
name|int32_t
name|_ehFrameOffset
operator|=
literal|0
block|;
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|_layout
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace elf
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_SECTION_CHUNKS_H
end_comment

end_unit

