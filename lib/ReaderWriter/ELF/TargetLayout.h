begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/TargetLayout.h --------------------------------===//
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
name|LLD_READER_WRITER_ELF_DEFAULT_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_DEFAULT_LAYOUT_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"HeaderChunks.h"
end_include

begin_include
include|#
directive|include
file|"SectionChunks.h"
end_include

begin_include
include|#
directive|include
file|"SegmentChunks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief The TargetLayout class is used by the Writer to arrange
comment|///        sections and segments in the order determined by the target ELF
comment|///        format. The writer creates a single instance of the TargetLayout
comment|///        class
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|TargetLayout
block|{
name|public
operator|:
typedef|typedef
name|uint32_t
name|SectionOrder
typedef|;
typedef|typedef
name|uint32_t
name|SegmentType
typedef|;
comment|// The order in which the sections appear in the output file
comment|// If its determined, that the layout needs to change
comment|// just changing the order of enumerations would essentially
comment|// change the layout in the output file
comment|// Change the enumerations so that Target can override and stick
comment|// a section anywhere it wants to
enum|enum
name|DefaultSectionOrder
block|{
name|ORDER_NOT_DEFINED
init|=
literal|0
block|,
name|ORDER_INTERP
init|=
literal|10
block|,
name|ORDER_RO_NOTE
init|=
literal|15
block|,
name|ORDER_HASH
init|=
literal|30
block|,
name|ORDER_DYNAMIC_SYMBOLS
init|=
literal|40
block|,
name|ORDER_DYNAMIC_STRINGS
init|=
literal|50
block|,
name|ORDER_DYNAMIC_RELOCS
init|=
literal|52
block|,
name|ORDER_DYNAMIC_PLT_RELOCS
init|=
literal|54
block|,
name|ORDER_INIT
init|=
literal|60
block|,
name|ORDER_PLT
init|=
literal|70
block|,
name|ORDER_TEXT
init|=
literal|80
block|,
name|ORDER_FINI
init|=
literal|90
block|,
name|ORDER_REL
init|=
literal|95
block|,
name|ORDER_RODATA
init|=
literal|100
block|,
name|ORDER_EH_FRAME
init|=
literal|110
block|,
name|ORDER_EH_FRAMEHDR
init|=
literal|120
block|,
name|ORDER_TDATA
init|=
literal|124
block|,
name|ORDER_TBSS
init|=
literal|128
block|,
name|ORDER_CTORS
init|=
literal|130
block|,
name|ORDER_DTORS
init|=
literal|140
block|,
name|ORDER_INIT_ARRAY
init|=
literal|150
block|,
name|ORDER_FINI_ARRAY
init|=
literal|160
block|,
name|ORDER_DYNAMIC
init|=
literal|170
block|,
name|ORDER_GOT
init|=
literal|180
block|,
name|ORDER_GOT_PLT
init|=
literal|190
block|,
name|ORDER_DATA
init|=
literal|200
block|,
name|ORDER_RW_NOTE
init|=
literal|205
block|,
name|ORDER_BSS
init|=
literal|210
block|,
name|ORDER_NOALLOC
init|=
literal|215
block|,
name|ORDER_OTHER
init|=
literal|220
block|,
name|ORDER_SECTION_STRINGS
init|=
literal|230
block|,
name|ORDER_SYMBOL_TABLE
init|=
literal|240
block|,
name|ORDER_STRING_TABLE
init|=
literal|250
block|,
name|ORDER_SECTION_HEADERS
init|=
literal|260
block|}
enum|;
name|public
label|:
comment|// The Key used for creating Sections
comment|// The sections are created using
comment|// SectionName, contentPermissions
struct|struct
name|SectionKey
block|{
name|SectionKey
argument_list|(
argument|StringRef name
argument_list|,
argument|DefinedAtom::ContentPermissions perm
argument_list|,
argument|StringRef path
argument_list|)
block|:
name|_name
argument_list|(
name|name
argument_list|)
operator|,
name|_perm
argument_list|(
name|perm
argument_list|)
operator|,
name|_path
argument_list|(
argument|path
argument_list|)
block|{}
comment|// Data members
name|StringRef
name|_name
expr_stmt|;
name|DefinedAtom
operator|::
name|ContentPermissions
name|_perm
expr_stmt|;
name|StringRef
name|_path
decl_stmt|;
block|}
struct|;
struct|struct
name|SectionKeyHash
block|{
name|int64_t
name|operator
argument_list|()
operator|(
specifier|const
name|SectionKey
operator|&
name|k
operator|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|hash_combine
argument_list|(
name|k
operator|.
name|_name
argument_list|,
name|k
operator|.
name|_perm
argument_list|,
name|k
operator|.
name|_path
argument_list|)
return|;
block|}
block|}
struct|;
struct|struct
name|SectionKeyEq
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|SectionKey
operator|&
name|lhs
operator|,
specifier|const
name|SectionKey
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|lhs
operator|.
name|_name
operator|==
name|rhs
operator|.
name|_name
operator|)
operator|&&
operator|(
name|lhs
operator|.
name|_perm
operator|==
name|rhs
operator|.
name|_perm
operator|)
operator|&&
operator|(
name|lhs
operator|.
name|_path
operator|==
name|rhs
operator|.
name|_path
operator|)
operator|)
return|;
block|}
block|}
struct|;
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
operator|>
operator|::
name|iterator
name|ChunkIter
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|Segment
operator|<
name|ELFT
operator|>
operator|*
operator|>
operator|::
name|iterator
name|SegmentIter
expr_stmt|;
comment|// Properties used during segment creation
struct|struct
name|SegmentKey
block|{
name|SegmentKey
argument_list|(
argument|StringRef name
argument_list|,
argument|int64_t type
argument_list|,
argument|uint64_t flags
argument_list|,
argument|bool segFlags
argument_list|)
block|:
name|_name
argument_list|(
name|name
argument_list|)
operator|,
name|_type
argument_list|(
name|type
argument_list|)
operator|,
name|_flags
argument_list|(
name|flags
argument_list|)
operator|,
name|_segmentFlags
argument_list|(
argument|segFlags&& flags !=
literal|0
argument_list|)
block|{}
name|StringRef
name|_name
operator|=
literal|""
expr_stmt|;
name|int64_t
name|_type
init|=
literal|0
decl_stmt|;
name|uint64_t
name|_flags
init|=
literal|0
decl_stmt|;
name|bool
name|_segmentFlags
init|=
name|false
decl_stmt|;
block|}
struct|;
struct|struct
name|SegmentKeyHash
block|{
name|int64_t
name|operator
argument_list|()
operator|(
specifier|const
name|SegmentKey
operator|&
name|k
operator|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|hash_combine
argument_list|(
name|k
operator|.
name|_name
argument_list|,
name|k
operator|.
name|_type
argument_list|,
name|k
operator|.
name|_flags
argument_list|)
return|;
block|}
block|}
struct|;
struct|struct
name|SegmentKeyEq
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|SegmentKey
operator|&
name|lhs
operator|,
specifier|const
name|SegmentKey
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|lhs
operator|.
name|_name
operator|==
name|rhs
operator|.
name|_name
operator|)
operator|&&
operator|(
name|lhs
operator|.
name|_type
operator|==
name|rhs
operator|.
name|_type
operator|)
operator|&&
operator|(
name|lhs
operator|.
name|_flags
operator|==
name|rhs
operator|.
name|_flags
operator|)
operator|)
return|;
block|}
block|}
struct|;
comment|// Output Sections contain the map of Section names to a vector of sections,
comment|// that have been merged to form a single section
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|OutputSection
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|OutputSectionMapT
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|OutputSection
operator|<
name|ELFT
operator|>
operator|*
operator|>
operator|::
name|iterator
name|OutputSectionIter
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|SectionKey
operator|,
name|AtomSection
operator|<
name|ELFT
operator|>
operator|*
operator|,
name|SectionKeyHash
operator|,
name|SectionKeyEq
operator|>
name|SectionMapT
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|SegmentKey
operator|,
name|Segment
operator|<
name|ELFT
operator|>
operator|*
operator|,
name|SegmentKeyHash
operator|,
name|SegmentKeyEq
operator|>
name|SegmentMapT
expr_stmt|;
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
name|AbsoluteAtomIterT
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|Atom
operator|*
operator|>
name|AtomSetT
expr_stmt|;
name|TargetLayout
argument_list|(
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|_ctx
argument_list|(
name|ctx
argument_list|)
operator|,
name|_linkerScriptSema
argument_list|(
argument|ctx.linkerScriptSema()
argument_list|)
block|{}
name|virtual
operator|~
name|TargetLayout
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief Return the section order for a input section
name|virtual
name|SectionOrder
name|getSectionOrder
parameter_list|(
name|StringRef
name|name
parameter_list|,
name|int32_t
name|contentType
parameter_list|,
name|int32_t
name|contentPermissions
parameter_list|)
function_decl|;
comment|/// \brief Return the name of the input section by decoding the input
comment|/// sectionChoice.
name|virtual
name|StringRef
name|getInputSectionName
argument_list|(
specifier|const
name|DefinedAtom
operator|*
name|da
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the name of the output section from the input section.
name|virtual
name|StringRef
name|getOutputSectionName
argument_list|(
name|StringRef
name|archivePath
argument_list|,
name|StringRef
name|memberPath
argument_list|,
name|StringRef
name|inputSectionName
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Gets or creates a section.
name|AtomSection
operator|<
name|ELFT
operator|>
operator|*
name|getSection
argument_list|(
argument|StringRef name
argument_list|,
argument|int32_t contentType
argument_list|,
argument|DefinedAtom::ContentPermissions contentPermissions
argument_list|,
argument|const DefinedAtom *da
argument_list|)
expr_stmt|;
comment|/// \brief Gets the segment for a output section
name|virtual
name|SegmentType
name|getSegmentType
argument_list|(
specifier|const
name|Section
operator|<
name|ELFT
operator|>
operator|*
name|section
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns true/false depending on whether the section has a Output
comment|//         segment or not
specifier|static
name|bool
name|hasOutputSegment
argument_list|(
name|Section
operator|<
name|ELFT
operator|>
operator|*
name|section
argument_list|)
decl_stmt|;
comment|/// \brief Append the Atom to the layout and create appropriate sections.
comment|/// \returns A reference to the atom layout or an error. The atom layout will
comment|/// be updated as linking progresses.
name|virtual
name|ErrorOr
operator|<
specifier|const
name|AtomLayout
operator|*
operator|>
name|addAtom
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|)
expr_stmt|;
comment|/// \brief Find an output Section given a section name.
name|OutputSection
operator|<
name|ELFT
operator|>
operator|*
name|findOutputSection
argument_list|(
argument|StringRef name
argument_list|)
block|{
name|auto
name|iter
operator|=
name|_outputSectionMap
operator|.
name|find
argument_list|(
name|name
argument_list|)
block|;
if|if
condition|(
name|iter
operator|==
name|_outputSectionMap
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|iter
operator|->
name|second
return|;
block|}
comment|/// \brief find a absolute atom given a name
name|AtomLayout
modifier|*
name|findAbsoluteAtom
parameter_list|(
name|StringRef
name|name
parameter_list|)
block|{
name|auto
name|iter
init|=
name|std
operator|::
name|find_if
argument_list|(
name|_absoluteAtoms
operator|.
name|begin
argument_list|()
argument_list|,
name|_absoluteAtoms
operator|.
name|end
argument_list|()
argument_list|,
index|[
operator|=
index|]
operator|(
specifier|const
name|AtomLayout
operator|*
name|a
operator|)
block|{
return|return
name|a
operator|->
name|_atom
operator|->
name|name
argument_list|()
operator|==
name|name
return|;
block|}
block|)
function|;
if|if
condition|(
name|iter
operator|==
name|_absoluteAtoms
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
operator|*
name|iter
return|;
block|}
end_decl_stmt

begin_comment
comment|// Output sections with the same name into a OutputSection
end_comment

begin_function_decl
name|void
name|createOutputSections
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Query for segments based on output and input sections
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|SegmentKey
operator|>
name|getSegmentsForSection
argument_list|(
argument|const OutputSection<ELFT> *os
argument_list|,
argument|const Section<ELFT> *sec
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Sort the sections by their order as defined by the layout,
end_comment

begin_comment
comment|/// preparing all sections to be assigned to a segment.
end_comment

begin_function_decl
name|virtual
name|void
name|sortInputSections
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add extra chunks to a segment just before including the input
end_comment

begin_comment
comment|/// section given by<archivePath, memberPath, sectionName>. This
end_comment

begin_comment
comment|/// is used to add linker script expressions before each section.
end_comment

begin_decl_stmt
name|virtual
name|void
name|addExtraChunksToSegment
argument_list|(
name|Segment
operator|<
name|ELFT
operator|>
operator|*
name|segment
argument_list|,
name|StringRef
name|archivePath
argument_list|,
name|StringRef
name|memberPath
argument_list|,
name|StringRef
name|sectionName
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief associates a section to a segment
end_comment

begin_function_decl
name|virtual
name|void
name|assignSectionsToSegments
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief associates a virtual address to the segment, section, and the atom
end_comment

begin_function_decl
name|virtual
name|void
name|assignVirtualAddress
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assignFileOffsetsForMiscSections
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|range
operator|<
name|AbsoluteAtomIterT
operator|>
name|absoluteAtoms
argument_list|()
block|{
return|return
name|_absoluteAtoms
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|addSection
argument_list|(
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
name|c
argument_list|)
block|{
name|_sections
operator|.
name|push_back
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
name|finalize
parameter_list|()
block|{
name|ScopedTask
name|task
argument_list|(
name|getDefaultDomain
argument_list|()
argument_list|,
literal|"Finalize layout"
argument_list|)
decl_stmt|;
for|for
control|(
name|auto
operator|&
name|si
operator|:
name|_sections
control|)
name|si
operator|->
name|finalize
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|doPreFlight
parameter_list|()
block|{
for|for
control|(
name|auto
operator|&
name|si
operator|:
name|_sections
control|)
name|si
operator|->
name|doPreFlight
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief find the Atom in the current layout
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|AtomLayout
modifier|*
name|findAtomLayoutByName
argument_list|(
name|StringRef
name|name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setHeader
argument_list|(
name|ELFHeader
operator|<
name|ELFT
operator|>
operator|*
name|elfHeader
argument_list|)
block|{
name|_elfHeader
operator|=
name|elfHeader
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setProgramHeader
argument_list|(
name|ProgramHeader
operator|<
name|ELFT
operator|>
operator|*
name|p
argument_list|)
block|{
name|_programHeader
operator|=
name|p
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|range
operator|<
name|OutputSectionIter
operator|>
name|outputSections
argument_list|()
block|{
return|return
name|_outputSections
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|range
operator|<
name|ChunkIter
operator|>
name|sections
argument_list|()
block|{
return|return
name|_sections
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|range
operator|<
name|SegmentIter
operator|>
name|segments
argument_list|()
block|{
return|return
name|_segments
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ELFHeader
operator|<
name|ELFT
operator|>
operator|*
name|getHeader
argument_list|()
block|{
return|return
name|_elfHeader
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasDynamicRelocationTable
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|!
name|_dynamicRelocationTable
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasPLTRelocationTable
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|!
name|_pltRelocationTable
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get or create the dynamic relocation table. All relocations in this
end_comment

begin_comment
comment|/// table are processed at startup.
end_comment

begin_expr_stmt
name|RelocationTable
operator|<
name|ELFT
operator|>
operator|*
name|getDynamicRelocationTable
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get or create the PLT relocation table. Referenced by DT_JMPREL.
end_comment

begin_expr_stmt
name|RelocationTable
operator|<
name|ELFT
operator|>
operator|*
name|getPLTRelocationTable
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint64_t
name|getTLSSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|isReferencedByDefinedAtom
argument_list|(
specifier|const
name|Atom
operator|*
name|a
argument_list|)
decl|const
block|{
return|return
name|_referencedDynAtoms
operator|.
name|count
argument_list|(
name|a
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|isCopied
argument_list|(
specifier|const
name|SharedLibraryAtom
operator|*
name|sla
argument_list|)
decl|const
block|{
return|return
name|_copiedDynSymNames
operator|.
name|count
argument_list|(
name|sla
operator|->
name|name
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// \brief TargetLayouts may use these functions to reorder the input sections
end_comment

begin_comment
comment|/// in a order defined by their ABI.
end_comment

begin_function
name|virtual
name|void
name|finalizeOutputSectionLayout
parameter_list|()
block|{}
end_function

begin_comment
comment|/// \brief Allocate a new section.
end_comment

begin_expr_stmt
name|virtual
name|AtomSection
operator|<
name|ELFT
operator|>
operator|*
name|createSection
argument_list|(
argument|StringRef name
argument_list|,
argument|int32_t contentType
argument_list|,
argument|DefinedAtom::ContentPermissions contentPermissions
argument_list|,
argument|SectionOrder sectionOrder
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Create a new relocation table.
end_comment

begin_expr_stmt
name|virtual
name|unique_bump_ptr
operator|<
name|RelocationTable
operator|<
name|ELFT
operator|>>
name|createRelocationTable
argument_list|(
argument|StringRef name
argument_list|,
argument|int32_t order
argument_list|)
block|{
return|return
name|unique_bump_ptr
operator|<
name|RelocationTable
operator|<
name|ELFT
operator|>>
operator|(
name|new
argument_list|(
argument|_allocator
argument_list|)
name|RelocationTable
operator|<
name|ELFT
operator|>
operator|(
name|_ctx
operator|,
name|name
operator|,
name|order
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|virtual
name|uint64_t
name|getLookupSectionFlags
argument_list|(
specifier|const
name|OutputSection
operator|<
name|ELFT
operator|>
operator|*
name|os
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Sort segements stored in the _segments
end_comment

begin_function_decl
name|virtual
name|void
name|sortSegments
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
name|_allocator
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|SectionMapT
name|_sectionMap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OutputSectionMapT
name|_outputSectionMap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SegmentMapT
name|_segmentMap
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|_sections
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|Segment
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|_segments
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|OutputSection
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|_outputSections
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ELFHeader
operator|<
name|ELFT
operator|>
operator|*
name|_elfHeader
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ProgramHeader
operator|<
name|ELFT
operator|>
operator|*
name|_programHeader
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|unique_bump_ptr
operator|<
name|RelocationTable
operator|<
name|ELFT
operator|>>
name|_dynamicRelocationTable
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|unique_bump_ptr
operator|<
name|RelocationTable
operator|<
name|ELFT
operator|>>
name|_pltRelocationTable
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|AtomLayout
operator|*
operator|>
name|_absoluteAtoms
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|AtomSetT
name|_referencedDynAtoms
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|_copiedDynSymNames
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ELFLinkingContext
modifier|&
name|_ctx
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|script
operator|::
name|Sema
operator|&
name|_linkerScriptSema
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
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

end_unit

