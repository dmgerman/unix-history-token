begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InputSection.h -------------------------------------------*- C++ -*-===//
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
name|LLD_ELF_INPUT_SECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_INPUT_SECTION_H
end_define

begin_include
include|#
directive|include
file|"Config.h"
end_include

begin_include
include|#
directive|include
file|"Relocations.h"
end_include

begin_include
include|#
directive|include
file|"Thunks.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/CachedHashString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/TinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Threading.h"
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
name|class
name|DefinedCommon
decl_stmt|;
name|class
name|SymbolBody
decl_stmt|;
struct_decl|struct
name|SectionPiece
struct_decl|;
name|class
name|DefinedRegular
decl_stmt|;
name|class
name|SyntheticSection
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|EhFrameSection
expr_stmt|;
name|class
name|MergeSyntheticSection
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ObjectFile
expr_stmt|;
name|class
name|OutputSection
decl_stmt|;
comment|// This is the base class of all sections that lld handles. Some are sections in
comment|// input files, some are sections in the produced output file and some exist
comment|// just as a convenience for implementing special ways of combining some
comment|// sections.
name|class
name|SectionBase
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|Regular
block|,
name|EHFrame
block|,
name|Merge
block|,
name|Synthetic
block|,
name|Output
block|}
enum|;
name|Kind
name|kind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Kind
operator|)
name|SectionKind
return|;
block|}
name|StringRef
name|Name
decl_stmt|;
name|unsigned
name|SectionKind
range|:
literal|3
decl_stmt|;
comment|// The next two bit fields are only used by InputSectionBase, but we
comment|// put them here so the struct packs better.
comment|// The garbage collector sets sections' Live bits.
comment|// If GC is disabled, all sections are considered live by default.
name|unsigned
name|Live
range|:
literal|1
decl_stmt|;
comment|// for garbage collection
name|unsigned
name|Assigned
range|:
literal|1
decl_stmt|;
comment|// for linker script
name|uint32_t
name|Alignment
decl_stmt|;
comment|// These corresponds to the fields in Elf_Shdr.
name|uint64_t
name|Flags
decl_stmt|;
name|uint64_t
name|Entsize
decl_stmt|;
name|uint32_t
name|Type
decl_stmt|;
name|uint32_t
name|Link
decl_stmt|;
name|uint32_t
name|Info
decl_stmt|;
name|OutputSection
modifier|*
name|getOutputSection
parameter_list|()
function_decl|;
specifier|const
name|OutputSection
operator|*
name|getOutputSection
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|SectionBase
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getOutputSection
argument_list|()
return|;
block|}
comment|// Translate an offset in the input section to an offset in the output
comment|// section.
name|uint64_t
name|getOffset
argument_list|(
name|uint64_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getOffset
argument_list|(
specifier|const
name|DefinedRegular
operator|&
name|Sym
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|SectionBase
argument_list|(
argument|Kind SectionKind
argument_list|,
argument|StringRef Name
argument_list|,
argument|uint64_t Flags
argument_list|,
argument|uint64_t Entsize
argument_list|,
argument|uint64_t Alignment
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uint32_t Info
argument_list|,
argument|uint32_t Link
argument_list|)
block|:
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|SectionKind
argument_list|(
name|SectionKind
argument_list|)
operator|,
name|Alignment
argument_list|(
name|Alignment
argument_list|)
operator|,
name|Flags
argument_list|(
name|Flags
argument_list|)
operator|,
name|Entsize
argument_list|(
name|Entsize
argument_list|)
operator|,
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Link
argument_list|(
name|Link
argument_list|)
operator|,
name|Info
argument_list|(
argument|Info
argument_list|)
block|{
name|Live
operator|=
name|false
block|;
name|Assigned
operator|=
name|false
block|;   }
block|}
empty_stmt|;
comment|// This corresponds to a section of an input file.
name|class
name|InputSectionBase
range|:
name|public
name|SectionBase
block|{
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|SectionBase
operator|*
name|S
argument_list|)
block|;
comment|// The file this section is from.
name|InputFile
operator|*
name|File
block|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
block|;
name|uint64_t
name|getOffsetInFile
argument_list|()
specifier|const
block|;
specifier|static
name|InputSectionBase
name|Discarded
block|;
name|InputSectionBase
argument_list|()
operator|:
name|SectionBase
argument_list|(
name|Regular
argument_list|,
literal|""
argument_list|,
comment|/*Flags*/
literal|0
argument_list|,
comment|/*Entsize*/
literal|0
argument_list|,
comment|/*Alignment*/
literal|0
argument_list|,
comment|/*Type*/
literal|0
argument_list|,
comment|/*Info*/
literal|0
argument_list|,
comment|/*Link*/
literal|0
argument_list|)
block|,
name|Repl
argument_list|(
argument|this
argument_list|)
block|{
name|Live
operator|=
name|false
block|;
name|Assigned
operator|=
name|false
block|;
name|NumRelocations
operator|=
literal|0
block|;
name|AreRelocsRela
operator|=
name|false
block|;   }
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSectionBase
argument_list|(
argument|ObjectFile<ELFT> *File
argument_list|,
argument|const typename ELFT::Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|,
argument|Kind SectionKind
argument_list|)
block|;
name|InputSectionBase
argument_list|(
argument|InputFile *File
argument_list|,
argument|uint64_t Flags
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uint64_t Entsize
argument_list|,
argument|uint32_t Link
argument_list|,
argument|uint32_t Info
argument_list|,
argument|uint32_t Alignment
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|StringRef Name
argument_list|,
argument|Kind SectionKind
argument_list|)
block|;
name|OutputSection
operator|*
name|OutSec
operator|=
name|nullptr
block|;
comment|// Relocations that refer to this section.
specifier|const
name|void
operator|*
name|FirstRelocation
operator|=
name|nullptr
block|;
name|unsigned
name|NumRelocations
operator|:
literal|31
block|;
name|unsigned
name|AreRelocsRela
operator|:
literal|1
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|ArrayRef
operator|<
name|typename
name|ELFT
operator|::
name|Rel
operator|>
name|rels
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|AreRelocsRela
argument_list|)
block|;
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
argument|static_cast<const typename ELFT::Rel *>(FirstRelocation)
argument_list|,
argument|NumRelocations
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|ELFT
operator|>
name|ArrayRef
operator|<
name|typename
name|ELFT
operator|::
name|Rela
operator|>
name|relas
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|AreRelocsRela
argument_list|)
block|;
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
argument|static_cast<const typename ELFT::Rela *>(FirstRelocation)
argument_list|,
argument|NumRelocations
argument_list|)
return|;
block|}
comment|// This pointer points to the "real" instance of this instance.
comment|// Usually Repl == this. However, if ICF merges two sections,
comment|// Repl pointer of one section points to another section. So,
comment|// if you need to get a pointer to this instance, do not use
comment|// this but instead this->Repl.
name|InputSectionBase
operator|*
name|Repl
block|;
comment|// InputSections that are dependent on us (reverse dependency for GC)
name|llvm
operator|::
name|TinyPtrVector
operator|<
name|InputSectionBase
operator|*
operator|>
name|DependentSections
block|;
comment|// Returns the size of this section (even if this is a common or BSS.)
name|size_t
name|getSize
argument_list|()
specifier|const
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|getFile
argument_list|()
specifier|const
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
name|getObj
argument_list|()
specifier|const
block|{
return|return
name|getFile
operator|<
name|ELFT
operator|>
operator|(
operator|)
operator|->
name|getObj
argument_list|()
return|;
block|}
name|InputSectionBase
operator|*
name|getLinkOrderDep
argument_list|()
specifier|const
block|;
name|void
name|uncompress
argument_list|()
block|;
comment|// Returns a source location string. Used to construct an error message.
name|template
operator|<
name|class
name|ELFT
operator|>
name|std
operator|::
name|string
name|getLocation
argument_list|(
argument|uint64_t Offset
argument_list|)
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|std
operator|::
name|string
name|getSrcMsg
argument_list|(
argument|uint64_t Offset
argument_list|)
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|std
operator|::
name|string
name|getObjMsg
argument_list|(
argument|uint64_t Offset
argument_list|)
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|relocate
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|,
name|uint8_t
operator|*
name|BufEnd
argument_list|)
block|;
name|void
name|relocateAlloc
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|,
name|uint8_t
operator|*
name|BufEnd
argument_list|)
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|relocateNonAlloc
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|,
name|uint8_t
operator|*
name|BufEnd
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|Relocation
operator|>
name|Relocations
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|llvm
operator|::
name|ArrayRef
operator|<
name|T
operator|>
name|getDataAs
argument_list|()
specifier|const
block|{
name|size_t
name|S
operator|=
name|Data
operator|.
name|size
argument_list|()
block|;
name|assert
argument_list|(
name|S
operator|%
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
literal|0
argument_list|)
block|;
return|return
name|llvm
operator|::
name|makeArrayRef
operator|<
name|T
operator|>
operator|(
operator|(
specifier|const
name|T
operator|*
operator|)
name|Data
operator|.
name|data
argument_list|()
expr|,
name|S
operator|/
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
return|;
block|}
expr|}
block|;
comment|// SectionPiece represents a piece of splittable section contents.
comment|// We allocate a lot of these and binary search on them. This means that they
comment|// have to be as compact as possible, which is why we don't store the size (can
comment|// be found by looking at the next one) and put the hash in a side table.
block|struct
name|SectionPiece
block|{
name|SectionPiece
argument_list|(
argument|size_t Off
argument_list|,
argument|bool Live = false
argument_list|)
operator|:
name|InputOff
argument_list|(
name|Off
argument_list|)
block|,
name|OutputOff
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|Live
argument_list|(
argument|Live || !Config->GcSections
argument_list|)
block|{}
name|size_t
name|InputOff
block|;
name|ssize_t
name|OutputOff
operator|:
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|ssize_t
argument_list|)
operator|-
literal|1
block|;
name|size_t
name|Live
operator|:
literal|1
block|; }
block|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|SectionPiece
argument_list|)
operator|==
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|size_t
argument_list|)
argument_list|,
literal|"SectionPiece is too big"
argument_list|)
block|;
comment|// This corresponds to a SHF_MERGE section of an input file.
name|class
name|MergeInputSection
operator|:
name|public
name|InputSectionBase
block|{
name|public
operator|:
name|template
operator|<
name|class
name|ELFT
operator|>
name|MergeInputSection
argument_list|(
argument|ObjectFile<ELFT> *F
argument_list|,
argument|const typename ELFT::Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|SectionBase
operator|*
name|S
argument_list|)
block|;
name|void
name|splitIntoPieces
argument_list|()
block|;
comment|// Mark the piece at a given offset live. Used by GC.
name|void
name|markLiveAt
argument_list|(
argument|uint64_t Offset
argument_list|)
block|{
name|assert
argument_list|(
name|this
operator|->
name|Flags
operator|&
name|llvm
operator|::
name|ELF
operator|::
name|SHF_ALLOC
argument_list|)
block|;
name|LiveOffsets
operator|.
name|insert
argument_list|(
name|Offset
argument_list|)
block|;   }
comment|// Translate an offset in the input section to an offset
comment|// in the output section.
name|uint64_t
name|getOffset
argument_list|(
argument|uint64_t Offset
argument_list|)
specifier|const
block|;
comment|// Splittable sections are handled as a sequence of data
comment|// rather than a single large blob of data.
name|std
operator|::
name|vector
operator|<
name|SectionPiece
operator|>
name|Pieces
block|;
comment|// Returns I'th piece's data. This function is very hot when
comment|// string merging is enabled, so we want to inline.
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|llvm
operator|::
name|CachedHashStringRef
name|getData
argument_list|(
argument|size_t I
argument_list|)
specifier|const
block|{
name|size_t
name|Begin
operator|=
name|Pieces
index|[
name|I
index|]
operator|.
name|InputOff
block|;
name|size_t
name|End
block|;
if|if
condition|(
name|Pieces
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|==
name|I
condition|)
name|End
operator|=
name|this
operator|->
name|Data
operator|.
name|size
argument_list|()
expr_stmt|;
else|else
name|End
operator|=
name|Pieces
index|[
name|I
operator|+
literal|1
index|]
operator|.
name|InputOff
expr_stmt|;
name|StringRef
name|S
operator|=
block|{
operator|(
specifier|const
name|char
operator|*
operator|)
operator|(
name|this
operator|->
name|Data
operator|.
name|data
argument_list|()
operator|+
name|Begin
operator|)
block|,
name|End
operator|-
name|Begin
block|}
block|;
return|return
block|{
name|S
block|,
name|Hashes
index|[
name|I
index|]
block|}
return|;
block|}
comment|// Returns the SectionPiece at a given input section offset.
name|SectionPiece
operator|*
name|getSectionPiece
argument_list|(
argument|uint64_t Offset
argument_list|)
block|;
specifier|const
name|SectionPiece
operator|*
name|getSectionPiece
argument_list|(
argument|uint64_t Offset
argument_list|)
specifier|const
block|;
comment|// MergeInputSections are aggregated to a synthetic input sections,
comment|// and then added to an OutputSection. This pointer points to a
comment|// synthetic MergeSyntheticSection which this section belongs to.
name|MergeSyntheticSection
operator|*
name|MergeSec
operator|=
name|nullptr
block|;
name|private
operator|:
name|void
name|splitStrings
argument_list|(
argument|ArrayRef<uint8_t> A
argument_list|,
argument|size_t Size
argument_list|)
block|;
name|void
name|splitNonStrings
argument_list|(
argument|ArrayRef<uint8_t> A
argument_list|,
argument|size_t Size
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Hashes
block|;
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
name|uint64_t
block|,
name|uint64_t
operator|>
name|OffsetMap
block|;
name|mutable
name|llvm
operator|::
name|once_flag
name|InitOffsetMap
block|;
name|llvm
operator|::
name|DenseSet
operator|<
name|uint64_t
operator|>
name|LiveOffsets
block|; }
decl_stmt|;
name|struct
name|EhSectionPiece
range|:
name|public
name|SectionPiece
block|{
name|EhSectionPiece
argument_list|(
argument|size_t Off
argument_list|,
argument|InputSectionBase *ID
argument_list|,
argument|uint32_t Size
argument_list|,
argument|unsigned FirstRelocation
argument_list|)
operator|:
name|SectionPiece
argument_list|(
name|Off
argument_list|,
name|false
argument_list|)
block|,
name|ID
argument_list|(
name|ID
argument_list|)
block|,
name|Size
argument_list|(
name|Size
argument_list|)
block|,
name|FirstRelocation
argument_list|(
argument|FirstRelocation
argument_list|)
block|{}
name|InputSectionBase
operator|*
name|ID
block|;
name|uint32_t
name|Size
block|;
name|uint32_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|data
argument_list|()
block|{
return|return
block|{
name|ID
operator|->
name|Data
operator|.
name|data
argument_list|()
operator|+
name|this
operator|->
name|InputOff
block|,
name|Size
block|}
return|;
block|}
name|unsigned
name|FirstRelocation
block|; }
decl_stmt|;
comment|// This corresponds to a .eh_frame section of an input file.
name|class
name|EhInputSection
range|:
name|public
name|InputSectionBase
block|{
name|public
operator|:
name|template
operator|<
name|class
name|ELFT
operator|>
name|EhInputSection
argument_list|(
argument|ObjectFile<ELFT> *F
argument_list|,
argument|const typename ELFT::Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|SectionBase
operator|*
name|S
argument_list|)
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|split
argument_list|()
block|;
name|template
operator|<
name|class
name|ELFT
block|,
name|class
name|RelTy
operator|>
name|void
name|split
argument_list|(
name|ArrayRef
operator|<
name|RelTy
operator|>
name|Rels
argument_list|)
block|;
comment|// Splittable sections are handled as a sequence of data
comment|// rather than a single large blob of data.
name|std
operator|::
name|vector
operator|<
name|EhSectionPiece
operator|>
name|Pieces
block|;
name|SyntheticSection
operator|*
name|EHSec
operator|=
name|nullptr
block|; }
decl_stmt|;
comment|// This is a section that is added directly to an output section
comment|// instead of needing special combination via a synthetic section. This
comment|// includes all input sections with the exceptions of SHF_MERGE and
comment|// .eh_frame. It also includes the synthetic sections themselves.
name|class
name|InputSection
range|:
name|public
name|InputSectionBase
block|{
name|public
operator|:
name|InputSection
argument_list|(
argument|uint64_t Flags
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uint32_t Alignment
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|StringRef Name
argument_list|,
argument|Kind K = Regular
argument_list|)
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSection
argument_list|(
argument|ObjectFile<ELFT> *F
argument_list|,
argument|const typename ELFT::Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|)
block|;
comment|// Write this section to a mmap'ed file, assuming Buf is pointing to
comment|// beginning of the output section.
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
block|;
comment|// The offset from beginning of the output sections this section was assigned
comment|// to. The writer sets a value.
name|uint64_t
name|OutSecOff
operator|=
literal|0
block|;
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|SectionBase
operator|*
name|S
argument_list|)
block|;
name|InputSectionBase
operator|*
name|getRelocatedSection
argument_list|()
block|;
name|template
operator|<
name|class
name|ELFT
block|,
name|class
name|RelTy
operator|>
name|void
name|relocateNonAlloc
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
name|RelTy
operator|>
name|Rels
argument_list|)
block|;
comment|// Used by ICF.
name|uint32_t
name|Class
index|[
literal|2
index|]
operator|=
block|{
literal|0
block|,
literal|0
block|}
block|;
comment|// Called by ICF to merge two input sections.
name|void
name|replace
argument_list|(
name|InputSection
operator|*
name|Other
argument_list|)
block|;
name|private
operator|:
name|template
operator|<
name|class
name|ELFT
block|,
name|class
name|RelTy
operator|>
name|void
name|copyRelocations
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
name|RelTy
operator|>
name|Rels
argument_list|)
block|;
name|void
name|copyShtGroup
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
block|; }
decl_stmt|;
comment|// The list of all input sections.
extern|extern std::vector<InputSectionBase *> InputSections;
block|}
comment|// namespace elf
name|std
operator|::
name|string
name|toString
argument_list|(
specifier|const
name|elf
operator|::
name|InputSectionBase
operator|*
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

