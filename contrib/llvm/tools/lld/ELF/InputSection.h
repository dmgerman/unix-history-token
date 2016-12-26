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
name|ELFT
operator|>
name|bool
name|isDiscarded
argument_list|(
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
expr_stmt|;
name|class
name|SymbolBody
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ICF
expr_stmt|;
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
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|OutputSectionBase
expr_stmt|;
comment|// This corresponds to a section of an input file.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|InputSectionBase
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
specifier|const
name|Elf_Shdr
modifier|*
name|Header
decl_stmt|;
comment|// The file this section is from.
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|File
expr_stmt|;
comment|// If a section is compressed, this vector has uncompressed section data.
name|SmallVector
operator|<
name|char
operator|,
literal|0
operator|>
name|Uncompressed
expr_stmt|;
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
name|MipsReginfo
block|,
name|MipsOptions
block|}
enum|;
name|Kind
name|SectionKind
decl_stmt|;
name|InputSectionBase
argument_list|()
operator|:
name|Repl
argument_list|(
argument|this
argument_list|)
block|{}
name|InputSectionBase
argument_list|(
argument|ObjectFile<ELFT> *File
argument_list|,
argument|const Elf_Shdr *Header
argument_list|,
argument|Kind SectionKind
argument_list|)
expr_stmt|;
name|OutputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|OutSec
operator|=
name|nullptr
expr_stmt|;
name|uint32_t
name|Alignment
decl_stmt|;
comment|// Used for garbage collection.
name|bool
name|Live
decl_stmt|;
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
specifier|static
name|InputSectionBase
operator|<
name|ELFT
operator|>
name|Discarded
expr_stmt|;
name|StringRef
name|getSectionName
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|Elf_Shdr
operator|*
name|getSectionHdr
argument_list|()
specifier|const
block|{
return|return
name|Header
return|;
block|}
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
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|getSectionData
argument_list|()
specifier|const
expr_stmt|;
name|void
name|uncompress
parameter_list|()
function_decl|;
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
name|std
operator|::
name|vector
operator|<
name|Relocation
operator|<
name|ELFT
operator|>>
name|Relocations
expr_stmt|;
name|bool
name|Compressed
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSectionBase
operator|<
name|ELFT
operator|>
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|::
name|Discarded
expr_stmt|;
comment|// SectionPiece represents a piece of splittable section contents.
struct|struct
name|SectionPiece
block|{
name|SectionPiece
argument_list|(
argument|size_t Off
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|)
block|:
name|InputOff
argument_list|(
name|Off
argument_list|)
operator|,
name|Data
argument_list|(
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
name|Data
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|Size
argument_list|(
name|Data
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|Live
argument_list|(
argument|!Config->GcSections
argument_list|)
block|{}
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|data
argument_list|()
block|{
return|return
block|{
name|Data
block|,
name|Size
block|}
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|size_t
name|InputOff
decl_stmt|;
name|size_t
name|OutputOff
init|=
operator|-
literal|1
decl_stmt|;
name|private
label|:
comment|// We use bitfields because SplitInputSection is accessed by
comment|// std::upper_bound very often.
comment|// We want to save bits to make it cache friendly.
specifier|const
name|uint8_t
modifier|*
name|Data
decl_stmt|;
name|uint32_t
name|Size
range|:
literal|31
decl_stmt|;
name|public
label|:
name|uint32_t
name|Live
range|:
literal|1
decl_stmt|;
block|}
struct|;
comment|// Usually sections are copied to the output as atomic chunks of data,
comment|// but some special types of sections are split into small pieces of data
comment|// and each piece is copied to a different place in the output.
comment|// This class represents such special sections.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SplitInputSection
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
name|Shdr
name|Elf_Shdr
expr_stmt|;
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
name|public
label|:
name|SplitInputSection
argument_list|(
argument|ObjectFile<ELFT> *File
argument_list|,
argument|const Elf_Shdr *Header
argument_list|,
argument|typename InputSectionBase<ELFT>::Kind SectionKind
argument_list|)
empty_stmt|;
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
comment|// Returns the SectionPiece at a given input section offset.
name|SectionPiece
modifier|*
name|getSectionPiece
parameter_list|(
name|uintX_t
name|Offset
parameter_list|)
function_decl|;
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This corresponds to a SHF_MERGE section of an input file.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MergeInputSection
operator|:
name|public
name|SplitInputSection
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
end_expr_stmt

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
name|Shdr
name|Elf_Shdr
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|MergeInputSection
argument_list|(
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|F
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|Header
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|splitIntoPieces
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Mark the piece at a given offset live. Used by GC.
end_comment

begin_function
name|void
name|markLiveAt
parameter_list|(
name|uintX_t
name|Offset
parameter_list|)
block|{
name|LiveOffsets
operator|.
name|insert
argument_list|(
name|Offset
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Translate an offset in the input section to an offset
end_comment

begin_comment
comment|// in the output section.
end_comment

begin_decl_stmt
name|uintX_t
name|getOffset
argument_list|(
name|uintX_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|finalizePieces
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
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
name|llvm
operator|::
name|DenseSet
operator|<
name|uintX_t
operator|>
name|LiveOffsets
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
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
name|SplitInputSection
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

begin_expr_stmt
name|EhInputSection
argument_list|(
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|F
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|Header
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|split
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Translate an offset in the input section to an offset in the output
end_comment

begin_comment
comment|// section.
end_comment

begin_decl_stmt
name|uintX_t
name|getOffset
argument_list|(
name|uintX_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Relocation section that refer to this one.
end_comment

begin_decl_stmt
specifier|const
name|Elf_Shdr
modifier|*
name|RelocSection
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

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
name|friend
name|ICF
operator|<
name|ELFT
operator|>
block|;
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

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|InputSection
argument_list|(
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|F
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|Header
argument_list|)
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
comment|// Relocation sections that refer to this one.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|TinyPtrVector
operator|<
specifier|const
name|Elf_Shdr
operator|*
operator|>
name|RelocSections
expr_stmt|;
end_expr_stmt

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

begin_decl_stmt
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|// Used by ICF.
end_comment

begin_decl_stmt
name|uint64_t
name|GroupId
init|=
literal|0
decl_stmt|;
end_decl_stmt

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

begin_comment
unit|};
comment|// MIPS .reginfo section provides information on the registers used by the code
end_comment

begin_comment
comment|// in the object file. Linker should collect this information and write a single
end_comment

begin_comment
comment|// .reginfo section in the output file. The output section contains a union of
end_comment

begin_comment
comment|// used registers masks taken from input .reginfo sections and final value
end_comment

begin_comment
comment|// of the `_gp` symbol.  For details: Chapter 4 / "Register Information" at
end_comment

begin_comment
comment|// ftp://www.linux-mips.org/pub/linux/mips/doc/ABI/mipsabi.pdf
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsReginfoInputSection
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
name|Shdr
name|Elf_Shdr
expr_stmt|;
name|public
operator|:
name|MipsReginfoInputSection
argument_list|(
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|F
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|Hdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_RegInfo
operator|<
name|ELFT
operator|>
operator|*
name|Reginfo
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
name|MipsOptionsInputSection
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
name|Shdr
name|Elf_Shdr
expr_stmt|;
name|public
operator|:
name|MipsOptionsInputSection
argument_list|(
name|ObjectFile
operator|<
name|ELFT
operator|>
operator|*
name|F
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|Hdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_RegInfo
operator|<
name|ELFT
operator|>
operator|*
name|Reginfo
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace elf
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

