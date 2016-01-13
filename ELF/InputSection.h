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
file|"lld/Core/LLVM.h"
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
name|elf2
block|{
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
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Rel
name|Elf_Rel
expr_stmt|;
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Rela
name|Elf_Rela
expr_stmt|;
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Shdr
name|Elf_Shdr
expr_stmt|;
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
name|Elf_Sym
expr_stmt|;
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|uintX_t
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
block|}
enum|;
name|Kind
name|SectionKind
decl_stmt|;
name|InputSectionBase
argument_list|(
argument|ObjectFile<ELFT> *File
argument_list|,
argument|const Elf_Shdr *Header
argument_list|,
argument|Kind SectionKind
argument_list|)
empty_stmt|;
name|OutputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|OutSec
operator|=
name|nullptr
expr_stmt|;
comment|// Used for garbage collection.
comment|// Live bit makes sense only when Config->GcSections is true.
name|bool
name|isLive
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Config
operator|->
name|GcSections
operator|||
name|Live
return|;
block|}
name|bool
name|Live
init|=
name|false
decl_stmt|;
comment|// Returns the size of this section (even if this is a common or BSS.)
name|size_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Header
operator|->
name|sh_size
return|;
block|}
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
comment|// The writer sets and uses the addresses.
name|uintX_t
name|getAlign
parameter_list|()
block|{
comment|// The ELF spec states that a value of 0 means the section has no alignment
comment|// constraits.
return|return
name|std
operator|::
name|max
operator|<
name|uintX_t
operator|>
operator|(
name|Header
operator|->
name|sh_addralign
operator|,
literal|1
operator|)
return|;
block|}
name|uintX_t
name|getOffset
parameter_list|(
specifier|const
name|Elf_Sym
modifier|&
name|Sym
parameter_list|)
function_decl|;
comment|// Translate an offset in the input section to an offset in the output
comment|// section.
name|uintX_t
name|getOffset
parameter_list|(
name|uintX_t
name|Offset
parameter_list|)
function_decl|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|getSectionData
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns a section that Rel is pointing to. Used by the garbage collector.
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|getRelocTarget
argument_list|(
specifier|const
name|Elf_Rel
operator|&
name|Rel
argument_list|)
expr_stmt|;
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|getRelocTarget
argument_list|(
specifier|const
name|Elf_Rela
operator|&
name|Rel
argument_list|)
expr_stmt|;
name|template
operator|<
name|bool
name|isRela
operator|>
name|using
name|RelIteratorRange
operator|=
name|llvm
operator|::
name|iterator_range
operator|<
specifier|const
name|llvm
operator|::
name|object
operator|::
name|Elf_Rel_Impl
operator|<
name|ELFT
operator|,
name|isRela
operator|>
operator|*
operator|>
expr_stmt|;
name|template
operator|<
name|bool
name|isRela
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
argument_list|,
name|RelIteratorRange
operator|<
name|isRela
operator|>
name|Rels
argument_list|)
expr_stmt|;
name|private
label|:
name|template
operator|<
name|bool
name|isRela
operator|>
name|uint8_t
operator|*
name|findMipsPairedReloc
argument_list|(
argument|uint8_t *Buf
argument_list|,
argument|uint32_t SymIndex
argument_list|,
argument|uint32_t Type
argument_list|,
argument|RelIteratorRange<isRela> Rels
argument_list|)
expr_stmt|;
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
argument_list|(
name|nullptr
argument_list|,
name|nullptr
argument_list|,
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|::
name|Regular
argument_list|)
expr_stmt|;
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
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Shdr
name|Elf_Shdr
expr_stmt|;
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|uintX_t
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
comment|// For each piece of data, we maintain the offsets in the input section and
comment|// in the output section. The latter may be -1 if it is not assigned yet.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uintX_t
operator|,
name|uintX_t
operator|>>
name|Offsets
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|pair
operator|<
name|uintX_t
operator|,
name|uintX_t
operator|>
operator|*
operator|,
name|uintX_t
operator|>
name|getRangeAndSize
argument_list|(
argument|uintX_t Offset
argument_list|)
expr_stmt|;
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
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|uintX_t
name|uintX_t
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
name|Elf_Sym
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Shdr
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

begin_comment
comment|// Translate an offset in the input section to an offset in the output
end_comment

begin_comment
comment|// section.
end_comment

begin_function_decl
name|uintX_t
name|getOffset
parameter_list|(
name|uintX_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

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
name|EHInputSection
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
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Shdr
name|Elf_Shdr
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|uintX_t
name|uintX_t
expr_stmt|;
end_typedef

begin_expr_stmt
name|EHInputSection
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

begin_comment
comment|// Translate an offset in the input section to an offset in the output
end_comment

begin_comment
comment|// section.
end_comment

begin_function_decl
name|uintX_t
name|getOffset
parameter_list|(
name|uintX_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

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
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Shdr
name|Elf_Shdr
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Rela
name|Elf_Rela
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Rel
name|Elf_Rel
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
name|Elf_Sym
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|uintX_t
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
name|SmallVector
operator|<
specifier|const
name|Elf_Shdr
operator|*
operator|,
literal|1
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
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Shdr
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
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace elf2
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

