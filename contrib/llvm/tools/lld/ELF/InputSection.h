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
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DefinedRegular
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ObjectFile
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|OutputSection
expr_stmt|;
name|class
name|OutputSectionBase
decl_stmt|;
comment|// We need non-template input section class to store symbol layout
comment|// in linker script parser structures, where we do not have ELFT
comment|// template parameter. For each scripted output section symbol we
comment|// store pointer to preceding InputSectionData object or nullptr,
comment|// if symbol should be placed at the very beginning of the output
comment|// section
name|class
name|InputSectionData
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
block|, }
enum|;
comment|// The garbage collector sets sections' Live bits.
comment|// If GC is disabled, all sections are considered live by default.
name|InputSectionData
argument_list|(
argument|Kind SectionKind
argument_list|,
argument|StringRef Name
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|bool Live
argument_list|)
block|:
name|SectionKind
argument_list|(
name|SectionKind
argument_list|)
operator|,
name|Live
argument_list|(
name|Live
argument_list|)
operator|,
name|Assigned
argument_list|(
name|false
argument_list|)
operator|,
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|Data
argument_list|(
argument|Data
argument_list|)
block|{}
name|private
operator|:
name|unsigned
name|SectionKind
operator|:
literal|3
expr_stmt|;
name|public
label|:
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
name|StringRef
name|Name
decl_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
expr_stmt|;
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
operator|,
name|S
operator|/
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|Relocation
operator|>
name|Relocations
expr_stmt|;
block|}
empty_stmt|;
comment|// This corresponds to a section of an input file.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|InputSectionBase
operator|:
name|public
name|InputSectionData
block|{
name|protected
operator|:
typedef|typedef
name|typename
name|ELFT
operator|::
name|Chdr
name|Elf_Chdr
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|Rel
name|Elf_Rel
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|Rela
name|Elf_Rela
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|Shdr
name|Elf_Shdr
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|Sym
name|Elf_Sym
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
comment|// The file this section is from.
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|File
expr_stmt|;
name|public
label|:
comment|// These corresponds to the fields in Elf_Shdr.
name|uintX_t
name|Flags
decl_stmt|;
name|uintX_t
name|Offset
init|=
literal|0
decl_stmt|;
name|uintX_t
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
name|InputSectionBase
argument_list|()
operator|:
name|InputSectionData
argument_list|(
name|Regular
argument_list|,
literal|""
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
operator|)
argument_list|,
name|false
argument_list|)
operator|,
name|Repl
argument_list|(
argument|this
argument_list|)
block|{
name|NumRelocations
operator|=
literal|0
block|;
name|AreRelocsRela
operator|=
name|false
block|;   }
name|InputSectionBase
argument_list|(
argument|ObjectFile<ELFT> *File
argument_list|,
argument|const Elf_Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|,
argument|Kind SectionKind
argument_list|)
expr_stmt|;
name|InputSectionBase
argument_list|(
argument|ObjectFile<ELFT> *File
argument_list|,
argument|uintX_t Flags
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uintX_t Entsize
argument_list|,
argument|uint32_t Link
argument_list|,
argument|uint32_t Info
argument_list|,
argument|uintX_t Addralign
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|StringRef Name
argument_list|,
argument|Kind SectionKind
argument_list|)
empty_stmt|;
name|OutputSectionBase
modifier|*
name|OutSec
init|=
name|nullptr
decl_stmt|;
comment|// Relocations that refer to this section.
specifier|const
name|Elf_Rel
modifier|*
name|FirstRelocation
init|=
name|nullptr
decl_stmt|;
name|unsigned
name|NumRelocations
range|:
literal|31
decl_stmt|;
name|unsigned
name|AreRelocsRela
range|:
literal|1
decl_stmt|;
name|ArrayRef
operator|<
name|Elf_Rel
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
name|FirstRelocation
argument_list|,
name|NumRelocations
argument_list|)
return|;
block|}
name|ArrayRef
operator|<
name|Elf_Rela
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
name|static_cast
operator|<
specifier|const
name|Elf_Rela
operator|*
operator|>
operator|(
name|FirstRelocation
operator|)
argument_list|,
name|NumRelocations
argument_list|)
return|;
block|}
comment|// This pointer points to the "real" instance of this instance.
comment|// Usually Repl == this. However, if ICF merges two sections,
comment|// Repl pointer of one section points to another section. So,
comment|// if you need to get a pointer to this instance, do not use
comment|// this but instead this->Repl.
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|Repl
expr_stmt|;
comment|// Returns the size of this section (even if this is a common or BSS.)
name|size_t
name|getSize
argument_list|()
specifier|const
expr_stmt|;
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|getFile
argument_list|()
specifier|const
block|{
return|return
name|File
return|;
block|}
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
name|File
operator|->
name|getObj
argument_list|()
return|;
block|}
name|uintX_t
name|getOffset
argument_list|(
specifier|const
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|&
name|Sym
argument_list|)
decl|const
decl_stmt|;
name|InputSectionBase
operator|*
name|getLinkOrderDep
argument_list|()
specifier|const
expr_stmt|;
comment|// Translate an offset in the input section to an offset in the output
comment|// section.
name|uintX_t
name|getOffset
argument_list|(
name|uintX_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
name|void
name|uncompress
parameter_list|()
function_decl|;
comment|// Returns a source location string. Used to construct an error message.
name|std
operator|::
name|string
name|getLocation
argument_list|(
argument|uintX_t Offset
argument_list|)
expr_stmt|;
name|void
name|relocate
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|,
name|uint8_t
modifier|*
name|BufEnd
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|// SectionPiece represents a piece of splittable section contents.
comment|// We allocate a lot of these and binary search on them. This means that they
comment|// have to be as compact as possible, which is why we don't store the size (can
comment|// be found by looking at the next one) and put the hash in a side table.
struct|struct
name|SectionPiece
block|{
name|SectionPiece
argument_list|(
argument|size_t Off
argument_list|,
argument|bool Live = false
argument_list|)
block|:
name|InputOff
argument_list|(
name|Off
argument_list|)
operator|,
name|OutputOff
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|Live
argument_list|(
argument|Live || !Config->GcSections
argument_list|)
block|{}
name|size_t
name|InputOff
expr_stmt|;
name|ssize_t
name|OutputOff
range|:
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|ssize_t
argument_list|)
operator|-
literal|1
decl_stmt|;
name|size_t
name|Live
range|:
literal|1
decl_stmt|;
block|}
struct|;
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
expr_stmt|;
comment|// This corresponds to a SHF_MERGE section of an input file.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MergeInputSection
operator|:
name|public
name|InputSectionBase
operator|<
name|ELFT
operator|>
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|Sym
name|Elf_Sym
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|Shdr
name|Elf_Shdr
expr_stmt|;
name|public
label|:
name|MergeInputSection
argument_list|(
argument|ObjectFile<ELFT> *F
argument_list|,
argument|const Elf_Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|)
empty_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|InputSectionData
modifier|*
name|S
parameter_list|)
function_decl|;
name|void
name|splitIntoPieces
parameter_list|()
function_decl|;
comment|// Mark the piece at a given offset live. Used by GC.
name|void
name|markLiveAt
parameter_list|(
name|uintX_t
name|Offset
parameter_list|)
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
expr_stmt|;
name|LiveOffsets
operator|.
name|insert
argument_list|(
name|Offset
argument_list|)
expr_stmt|;
block|}
comment|// Translate an offset in the input section to an offset
comment|// in the output section.
name|uintX_t
name|getOffset
argument_list|(
name|uintX_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
comment|// Splittable sections are handled as a sequence of data
comment|// rather than a single large blob of data.
name|std
operator|::
name|vector
operator|<
name|SectionPiece
operator|>
name|Pieces
expr_stmt|;
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
expr_stmt|;
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
end_decl_stmt

begin_comment
comment|// Returns the SectionPiece at a given input section offset.
end_comment

begin_function_decl
name|SectionPiece
modifier|*
name|getSectionPiece
parameter_list|(
name|uintX_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|SectionPiece
modifier|*
name|getSectionPiece
argument_list|(
name|uintX_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|void
name|splitStrings
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|A
argument_list|,
name|size_t
name|Size
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|splitNonStrings
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|A
argument_list|,
name|size_t
name|Size
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Hashes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
name|uintX_t
operator|,
name|uintX_t
operator|>
name|OffsetMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mutable
name|std
operator|::
name|once_flag
name|InitOffsetMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseSet
operator|<
name|uintX_t
operator|>
name|LiveOffsets
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
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
argument|InputSectionData *ID
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
name|InputSectionData
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
end_decl_stmt

begin_comment
comment|// This corresponds to a .eh_frame section of an input file.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|EhInputSection
operator|:
name|public
name|InputSectionBase
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|ELFT
operator|::
name|Shdr
name|Elf_Shdr
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
end_typedef

begin_macro
name|EhInputSection
argument_list|(
argument|ObjectFile<ELFT> *F
argument_list|,
argument|const Elf_Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|InputSectionData
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|split
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Splittable sections are handled as a sequence of data
end_comment

begin_comment
comment|// rather than a single large blob of data.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|EhSectionPiece
operator|>
name|Pieces
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// This corresponds to a non SHF_MERGE section of an input file.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|InputSection
operator|:
name|public
name|InputSectionBase
operator|<
name|ELFT
operator|>
block|{
typedef|typedef
name|InputSectionBase
operator|<
name|ELFT
operator|>
name|Base
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Shdr
name|Elf_Shdr
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Rela
name|Elf_Rela
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Rel
name|Elf_Rel
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Sym
name|Elf_Sym
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|InputSectionData
operator|::
name|Kind
name|Kind
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|InputSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
name|InputSection
argument_list|(
argument|uintX_t Flags
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uintX_t Addralign
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|StringRef Name
argument_list|,
argument|Kind K = InputSectionData::Regular
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|InputSection
argument_list|(
argument|ObjectFile<ELFT> *F
argument_list|,
argument|const Elf_Shdr *Header
argument_list|,
argument|StringRef Name
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|static
name|InputSection
operator|<
name|ELFT
operator|>
name|Discarded
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Write this section to a mmap'ed file, assuming Buf is pointing to
end_comment

begin_comment
comment|// beginning of the output section.
end_comment

begin_function_decl
name|void
name|writeTo
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// The offset from beginning of the output sections this section was assigned
end_comment

begin_comment
comment|// to. The writer sets a value.
end_comment

begin_decl_stmt
name|uint64_t
name|OutSecOff
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// InputSection that is dependent on us (reverse dependency for GC)
end_comment

begin_expr_stmt
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|DependentSection
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|InputSectionData
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|getRelocatedSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Register thunk related to the symbol. When the section is written
end_comment

begin_comment
comment|// to a mmap'ed file, target is requested to write an actual thunk code.
end_comment

begin_comment
comment|// Now thunks is supported for MIPS and ARM target only.
end_comment

begin_decl_stmt
name|void
name|addThunk
argument_list|(
specifier|const
name|Thunk
operator|<
name|ELFT
operator|>
operator|*
name|T
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The offset of synthetic thunk code from beginning of this section.
end_comment

begin_expr_stmt
name|uint64_t
name|getThunkOff
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Size of chunk with thunks code.
end_comment

begin_expr_stmt
name|uint64_t
name|getThunksSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Used by ICF.
end_comment

begin_decl_stmt
name|uint32_t
name|Class
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Called by ICF to merge two input sections.
end_comment

begin_decl_stmt
name|void
name|replace
argument_list|(
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|Other
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|TinyPtrVector
operator|<
specifier|const
name|Thunk
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|Thunks
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSection
operator|<
name|ELFT
operator|>
name|InputSection
operator|<
name|ELFT
operator|>
operator|::
name|Discarded
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace elf
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|ELFT
operator|>
name|std
operator|::
name|string
name|toString
argument_list|(
specifier|const
name|elf
operator|::
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

