begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SyntheticSection.h ---------------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// Synthetic sections represent chunks of linker-created data. If you
end_comment

begin_comment
comment|// need to create a chunk of data that to be included in some section
end_comment

begin_comment
comment|// in the result, you probably want to create that as a synthetic section.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Synthetic sections are designed as input sections as opposed to
end_comment

begin_comment
comment|// output sections because we want to allow them to be manipulated
end_comment

begin_comment
comment|// using linker scripts just like other input sections from regular
end_comment

begin_comment
comment|// files.
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
name|LLD_ELF_SYNTHETIC_SECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_SYNTHETIC_SECTION_H
end_define

begin_include
include|#
directive|include
file|"EhFrame.h"
end_include

begin_include
include|#
directive|include
file|"GdbIndex.h"
end_include

begin_include
include|#
directive|include
file|"InputSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/StringTableBuilder.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|SyntheticSection
range|:
name|public
name|InputSection
block|{
name|public
operator|:
name|SyntheticSection
argument_list|(
argument|uint64_t Flags
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uint32_t Alignment
argument_list|,
argument|StringRef Name
argument_list|)
operator|:
name|InputSection
argument_list|(
argument|Flags
argument_list|,
argument|Type
argument_list|,
argument|Alignment
argument_list|,
argument|{}
argument_list|,
argument|Name
argument_list|,
argument|InputSectionBase::Synthetic
argument_list|)
block|{
name|this
operator|->
name|Live
operator|=
name|true
block|;   }
name|virtual
operator|~
name|SyntheticSection
argument_list|()
operator|=
expr|default
block|;
name|virtual
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|getSize
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|finalizeContents
argument_list|()
block|{}
comment|// If the section has the SHF_ALLOC flag and the size may be changed if
comment|// thunks are added, update the section size.
name|virtual
name|void
name|updateAllocSize
argument_list|()
block|{}
comment|// If any additional finalization of contents are needed post thunk creation.
name|virtual
name|void
name|postThunkContents
argument_list|()
block|{}
name|virtual
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|uint64_t
name|getVA
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const InputSectionBase *D
argument_list|)
block|{
return|return
name|D
operator|->
name|kind
argument_list|()
operator|==
name|InputSectionBase
operator|::
name|Synthetic
return|;
block|}
expr|}
block|;  struct
name|CieRecord
block|{
name|EhSectionPiece
operator|*
name|Piece
operator|=
name|nullptr
block|;
name|std
operator|::
name|vector
operator|<
name|EhSectionPiece
operator|*
operator|>
name|FdePieces
block|; }
block|;
comment|// Section for .eh_frame.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|EhFrameSection
name|final
operator|:
name|public
name|SyntheticSection
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
name|void
name|updateAlignment
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
if|if
condition|(
name|Val
operator|>
name|this
operator|->
name|Alignment
condition|)
name|this
operator|->
name|Alignment
operator|=
name|Val
expr_stmt|;
block|}
name|public
label|:
name|EhFrameSection
argument_list|()
expr_stmt|;
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
name|void
name|finalizeContents
argument_list|()
name|override
expr_stmt|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|{
return|return
name|Sections
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
name|void
name|addSection
parameter_list|(
name|InputSectionBase
modifier|*
name|S
parameter_list|)
function_decl|;
name|size_t
name|NumFdes
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|EhInputSection
operator|*
operator|>
name|Sections
expr_stmt|;
name|private
label|:
name|uint64_t
name|Size
init|=
literal|0
decl_stmt|;
name|template
operator|<
name|class
name|RelTy
operator|>
name|void
name|addSectionAux
argument_list|(
name|EhInputSection
operator|*
name|S
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
name|template
operator|<
name|class
name|RelTy
operator|>
name|CieRecord
operator|*
name|addCie
argument_list|(
name|EhSectionPiece
operator|&
name|Piece
argument_list|,
name|ArrayRef
operator|<
name|RelTy
operator|>
name|Rels
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|RelTy
operator|>
name|bool
name|isFdeLive
argument_list|(
name|EhSectionPiece
operator|&
name|Piece
argument_list|,
name|ArrayRef
operator|<
name|RelTy
operator|>
name|Rels
argument_list|)
expr_stmt|;
name|uint64_t
name|getFdePc
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|,
name|size_t
name|Off
parameter_list|,
name|uint8_t
name|Enc
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|CieRecord
operator|*
operator|>
name|Cies
expr_stmt|;
comment|// CIE records are uniquified by their contents and personality functions.
name|llvm
operator|::
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|,
name|SymbolBody
operator|*
operator|>
operator|,
name|CieRecord
operator|>
name|CieMap
expr_stmt|;
block|}
empty_stmt|;
name|class
name|GotSection
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|GotSection
argument_list|()
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
name|void
name|finalizeContents
argument_list|()
name|override
block|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|void
name|addEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
block|;
name|bool
name|addDynTlsEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
block|;
name|bool
name|addTlsIndex
argument_list|()
block|;
name|uint64_t
name|getGlobalDynAddr
argument_list|(
argument|const SymbolBody&B
argument_list|)
specifier|const
block|;
name|uint64_t
name|getGlobalDynOffset
argument_list|(
argument|const SymbolBody&B
argument_list|)
specifier|const
block|;
name|uint64_t
name|getTlsIndexVA
argument_list|()
block|{
return|return
name|this
operator|->
name|getVA
argument_list|()
operator|+
name|TlsIndexOff
return|;
block|}
name|uint32_t
name|getTlsIndexOff
argument_list|()
specifier|const
block|{
return|return
name|TlsIndexOff
return|;
block|}
comment|// Flag to force GOT to be in output if we have relocations
comment|// that relies on its address.
name|bool
name|HasGotOffRel
operator|=
name|false
block|;
name|protected
operator|:
name|size_t
name|NumEntries
operator|=
literal|0
block|;
name|uint32_t
name|TlsIndexOff
operator|=
operator|-
literal|1
block|;
name|uint64_t
name|Size
operator|=
literal|0
block|; }
decl_stmt|;
comment|// .note.gnu.build-id section.
name|class
name|BuildIdSection
range|:
name|public
name|SyntheticSection
block|{
comment|// First 16 bytes are a header.
specifier|static
specifier|const
name|unsigned
name|HeaderSize
operator|=
literal|16
block|;
name|public
operator|:
name|BuildIdSection
argument_list|()
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|HeaderSize
operator|+
name|HashSize
return|;
block|}
name|void
name|writeBuildId
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Buf
argument_list|)
block|;
name|private
operator|:
name|void
name|computeHash
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Buf
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|uint8_t
operator|*
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
argument_list|)
operator|>
name|Hash
argument_list|)
block|;
name|size_t
name|HashSize
block|;
name|uint8_t
operator|*
name|HashBuf
block|; }
decl_stmt|;
comment|// BssSection is used to reserve space for copy relocations and common symbols.
comment|// We create three instances of this class for .bss, .bss.rel.ro and "COMMON",
comment|// that are used for writable symbols, read-only symbols and common symbols,
comment|// respectively.
name|class
name|BssSection
name|final
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|BssSection
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *
argument_list|)
name|override
block|{}
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSize
argument_list|()
operator|==
literal|0
return|;
block|}
name|size_t
name|reserveSpace
argument_list|(
argument|uint64_t Size
argument_list|,
argument|uint32_t Alignment
argument_list|)
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
name|private
operator|:
name|uint64_t
name|Size
operator|=
literal|0
block|; }
decl_stmt|;
name|class
name|MipsGotSection
name|final
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|MipsGotSection
argument_list|()
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
name|void
name|updateAllocSize
argument_list|()
name|override
block|;
name|void
name|finalizeContents
argument_list|()
name|override
block|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|;
name|void
name|addEntry
argument_list|(
argument|SymbolBody&Sym
argument_list|,
argument|int64_t Addend
argument_list|,
argument|RelExpr Expr
argument_list|)
block|;
name|bool
name|addDynTlsEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
block|;
name|bool
name|addTlsIndex
argument_list|()
block|;
name|uint64_t
name|getPageEntryOffset
argument_list|(
argument|const SymbolBody&B
argument_list|,
argument|int64_t Addend
argument_list|)
specifier|const
block|;
name|uint64_t
name|getBodyEntryOffset
argument_list|(
argument|const SymbolBody&B
argument_list|,
argument|int64_t Addend
argument_list|)
specifier|const
block|;
name|uint64_t
name|getGlobalDynOffset
argument_list|(
argument|const SymbolBody&B
argument_list|)
specifier|const
block|;
comment|// Returns the symbol which corresponds to the first entry of the global part
comment|// of GOT on MIPS platform. It is required to fill up MIPS-specific dynamic
comment|// table properties.
comment|// Returns nullptr if the global part is empty.
specifier|const
name|SymbolBody
operator|*
name|getFirstGlobalEntry
argument_list|()
specifier|const
block|;
comment|// Returns the number of entries in the local part of GOT including
comment|// the number of reserved entries.
name|unsigned
name|getLocalEntriesNum
argument_list|()
specifier|const
block|;
comment|// Returns offset of TLS part of the MIPS GOT table. This part goes
comment|// after 'local' and 'global' entries.
name|uint64_t
name|getTlsOffset
argument_list|()
specifier|const
block|;
name|uint32_t
name|getTlsIndexOff
argument_list|()
specifier|const
block|{
return|return
name|TlsIndexOff
return|;
block|}
name|uint64_t
name|getGp
argument_list|()
specifier|const
block|;
name|private
operator|:
comment|// MIPS GOT consists of three parts: local, global and tls. Each part
comment|// contains different types of entries. Here is a layout of GOT:
comment|// - Header entries                |
comment|// - Page entries                  |   Local part
comment|// - Local entries (16-bit access) |
comment|// - Local entries (32-bit access) |
comment|// - Normal global entries         ||  Global part
comment|// - Reloc-only global entries     ||
comment|// - TLS entries                   ||| TLS part
comment|//
comment|// Header:
comment|//   Two entries hold predefined value 0x0 and 0x80000000.
comment|// Page entries:
comment|//   These entries created by R_MIPS_GOT_PAGE relocation and R_MIPS_GOT16
comment|//   relocation against local symbols. They are initialized by higher 16-bit
comment|//   of the corresponding symbol's value. So each 64kb of address space
comment|//   requires a single GOT entry.
comment|// Local entries (16-bit access):
comment|//   These entries created by GOT relocations against global non-preemptible
comment|//   symbols so dynamic linker is not necessary to resolve the symbol's
comment|//   values. "16-bit access" means that corresponding relocations address
comment|//   GOT using 16-bit index. Each unique Symbol-Addend pair has its own
comment|//   GOT entry.
comment|// Local entries (32-bit access):
comment|//   These entries are the same as above but created by relocations which
comment|//   address GOT using 32-bit index (R_MIPS_GOT_HI16/LO16 etc).
comment|// Normal global entries:
comment|//   These entries created by GOT relocations against preemptible global
comment|//   symbols. They need to be initialized by dynamic linker and they ordered
comment|//   exactly as the corresponding entries in the dynamic symbols table.
comment|// Reloc-only global entries:
comment|//   These entries created for symbols that are referenced by dynamic
comment|//   relocations R_MIPS_REL32. These entries are not accessed with gp-relative
comment|//   addressing, but MIPS ABI requires that these entries be present in GOT.
comment|// TLS entries:
comment|//   Entries created by TLS relocations.
comment|// Number of "Header" entries.
specifier|static
specifier|const
name|unsigned
name|HeaderEntriesNum
operator|=
literal|2
block|;
comment|// Number of allocated "Page" entries.
name|uint32_t
name|PageEntriesNum
operator|=
literal|0
block|;
comment|// Map output sections referenced by MIPS GOT relocations
comment|// to the first index of "Page" entries allocated for this section.
name|llvm
operator|::
name|SmallMapVector
operator|<
specifier|const
name|OutputSection
operator|*
block|,
name|size_t
block|,
literal|16
operator|>
name|PageIndexMap
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|SymbolBody
operator|*
operator|,
name|uint64_t
operator|>
name|GotEntry
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|GotEntry
operator|>
name|GotEntries
expr_stmt|;
comment|// Map from Symbol-Addend pair to the GOT index.
name|llvm
operator|::
name|DenseMap
operator|<
name|GotEntry
operator|,
name|size_t
operator|>
name|EntryIndexMap
expr_stmt|;
comment|// Local entries (16-bit access).
name|GotEntries
name|LocalEntries
decl_stmt|;
comment|// Local entries (32-bit access).
name|GotEntries
name|LocalEntries32
decl_stmt|;
comment|// Normal and reloc-only global entries.
name|GotEntries
name|GlobalEntries
decl_stmt|;
comment|// TLS entries.
name|std
operator|::
name|vector
operator|<
specifier|const
name|SymbolBody
operator|*
operator|>
name|TlsEntries
expr_stmt|;
name|uint32_t
name|TlsIndexOff
init|=
operator|-
literal|1
decl_stmt|;
name|uint64_t
name|Size
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|GotPltSection
name|final
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|GotPltSection
argument_list|()
block|;
name|void
name|addEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|{
return|return
name|Entries
operator|.
name|empty
argument_list|()
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
specifier|const
name|SymbolBody
operator|*
operator|>
name|Entries
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The IgotPltSection is a Got associated with the PltSection for GNU Ifunc
end_comment

begin_comment
comment|// Symbols that will be relocated by Target->IRelativeRel.
end_comment

begin_comment
comment|// On most Targets the IgotPltSection will immediately follow the GotPltSection
end_comment

begin_comment
comment|// on ARM the IgotPltSection will immediately follow the GotSection.
end_comment

begin_decl_stmt
name|class
name|IgotPltSection
name|final
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|IgotPltSection
argument_list|()
block|;
name|void
name|addEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|{
return|return
name|Entries
operator|.
name|empty
argument_list|()
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
specifier|const
name|SymbolBody
operator|*
operator|>
name|Entries
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|StringTableSection
name|final
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|StringTableSection
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool Dynamic
argument_list|)
block|;
name|unsigned
name|addString
argument_list|(
argument|StringRef S
argument_list|,
argument|bool HashIt = true
argument_list|)
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
name|bool
name|isDynamic
argument_list|()
specifier|const
block|{
return|return
name|Dynamic
return|;
block|}
name|private
operator|:
specifier|const
name|bool
name|Dynamic
block|;
name|uint64_t
name|Size
operator|=
literal|0
block|;
name|llvm
operator|::
name|DenseMap
operator|<
name|StringRef
block|,
name|unsigned
operator|>
name|StringMap
block|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Strings
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DynamicReloc
block|{
name|public
label|:
name|DynamicReloc
argument_list|(
argument|uint32_t Type
argument_list|,
argument|const InputSectionBase *InputSec
argument_list|,
argument|uint64_t OffsetInSec
argument_list|,
argument|bool UseSymVA
argument_list|,
argument|SymbolBody *Sym
argument_list|,
argument|int64_t Addend
argument_list|)
block|:
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Sym
argument_list|(
name|Sym
argument_list|)
operator|,
name|InputSec
argument_list|(
name|InputSec
argument_list|)
operator|,
name|OffsetInSec
argument_list|(
name|OffsetInSec
argument_list|)
operator|,
name|UseSymVA
argument_list|(
name|UseSymVA
argument_list|)
operator|,
name|Addend
argument_list|(
argument|Addend
argument_list|)
block|{}
name|uint64_t
name|getOffset
argument_list|()
specifier|const
expr_stmt|;
name|int64_t
name|getAddend
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getSymIndex
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|InputSectionBase
operator|*
name|getInputSec
argument_list|()
specifier|const
block|{
return|return
name|InputSec
return|;
block|}
name|uint32_t
name|Type
decl_stmt|;
name|private
label|:
name|SymbolBody
modifier|*
name|Sym
decl_stmt|;
specifier|const
name|InputSectionBase
modifier|*
name|InputSec
init|=
name|nullptr
decl_stmt|;
name|uint64_t
name|OffsetInSec
decl_stmt|;
name|bool
name|UseSymVA
decl_stmt|;
name|int64_t
name|Addend
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DynamicSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Dyn
name|Elf_Dyn
expr_stmt|;
end_expr_stmt

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
name|Rela
name|Elf_Rela
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

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Sym
name|Elf_Sym
expr_stmt|;
end_typedef

begin_comment
comment|// The .dynamic section contains information for the dynamic linker.
end_comment

begin_comment
comment|// The section consists of fixed size entries, which consist of
end_comment

begin_comment
comment|// type and value fields. Value are one of plain integers, symbol
end_comment

begin_comment
comment|// addresses, or section addresses. This struct represents the entry.
end_comment

begin_struct
struct|struct
name|Entry
block|{
name|int32_t
name|Tag
decl_stmt|;
union|union
block|{
name|OutputSection
modifier|*
name|OutSec
decl_stmt|;
name|InputSection
modifier|*
name|InSec
decl_stmt|;
name|uint64_t
name|Val
decl_stmt|;
specifier|const
name|SymbolBody
modifier|*
name|Sym
decl_stmt|;
block|}
union|;
enum|enum
name|KindT
block|{
name|SecAddr
block|,
name|SecSize
block|,
name|SymAddr
block|,
name|PlainInt
block|,
name|InSecAddr
block|}
name|Kind
enum|;
name|Entry
argument_list|(
argument|int32_t Tag
argument_list|,
argument|OutputSection *OutSec
argument_list|,
argument|KindT Kind = SecAddr
argument_list|)
block|:
name|Tag
argument_list|(
name|Tag
argument_list|)
operator|,
name|OutSec
argument_list|(
name|OutSec
argument_list|)
operator|,
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{}
name|Entry
argument_list|(
argument|int32_t Tag
argument_list|,
argument|InputSection *Sec
argument_list|)
operator|:
name|Tag
argument_list|(
name|Tag
argument_list|)
operator|,
name|InSec
argument_list|(
name|Sec
argument_list|)
operator|,
name|Kind
argument_list|(
argument|InSecAddr
argument_list|)
block|{}
name|Entry
argument_list|(
argument|int32_t Tag
argument_list|,
argument|uint64_t Val
argument_list|)
operator|:
name|Tag
argument_list|(
name|Tag
argument_list|)
operator|,
name|Val
argument_list|(
name|Val
argument_list|)
operator|,
name|Kind
argument_list|(
argument|PlainInt
argument_list|)
block|{}
name|Entry
argument_list|(
argument|int32_t Tag
argument_list|,
argument|const SymbolBody *Sym
argument_list|)
operator|:
name|Tag
argument_list|(
name|Tag
argument_list|)
operator|,
name|Sym
argument_list|(
name|Sym
argument_list|)
operator|,
name|Kind
argument_list|(
argument|SymAddr
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_comment
comment|// finalizeContents() fills this vector with the section contents.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|Entries
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|DynamicSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|finalizeContents
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|addEntries
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|add
parameter_list|(
name|Entry
name|E
parameter_list|)
block|{
name|Entries
operator|.
name|push_back
argument_list|(
name|E
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|uint64_t
name|Size
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|RelocationSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Rel
name|Elf_Rel
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Rela
name|Elf_Rela
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_macro
name|RelocationSection
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool Sort
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|addReloc
parameter_list|(
specifier|const
name|DynamicReloc
modifier|&
name|Reloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|getRelocOffset
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|void
name|finalizeContents
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|{
return|return
name|Relocs
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Relocs
operator|.
name|size
argument_list|()
operator|*
name|this
operator|->
name|Entsize
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|size_t
name|getRelativeRelocCount
argument_list|()
specifier|const
block|{
return|return
name|NumRelativeRelocs
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|Sort
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|NumRelativeRelocs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|DynamicReloc
operator|>
name|Relocs
expr_stmt|;
end_expr_stmt

begin_struct
unit|};
struct|struct
name|SymbolTableEntry
block|{
name|SymbolBody
modifier|*
name|Symbol
decl_stmt|;
name|size_t
name|StrTabOffset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|class
name|SymbolTableBaseSection
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|SymbolTableBaseSection
argument_list|(
name|StringTableSection
operator|&
name|StrTabSec
argument_list|)
block|;
name|void
name|finalizeContents
argument_list|()
name|override
block|;
name|void
name|postThunkContents
argument_list|()
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|getNumSymbols
argument_list|()
operator|*
name|Entsize
return|;
block|}
name|void
name|addSymbol
argument_list|(
name|SymbolBody
operator|*
name|Body
argument_list|)
block|;
name|unsigned
name|getNumSymbols
argument_list|()
specifier|const
block|{
return|return
name|Symbols
operator|.
name|size
argument_list|()
operator|+
literal|1
return|;
block|}
name|size_t
name|getSymbolIndex
argument_list|(
name|SymbolBody
operator|*
name|Body
argument_list|)
block|;
name|ArrayRef
operator|<
name|SymbolTableEntry
operator|>
name|getSymbols
argument_list|()
specifier|const
block|{
return|return
name|Symbols
return|;
block|}
name|protected
operator|:
comment|// A vector of symbols and their string table offsets.
name|std
operator|::
name|vector
operator|<
name|SymbolTableEntry
operator|>
name|Symbols
block|;
name|StringTableSection
operator|&
name|StrTabSec
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SymbolTableSection
name|final
operator|:
name|public
name|SymbolTableBaseSection
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Sym
name|Elf_Sym
expr_stmt|;
name|public
operator|:
name|SymbolTableSection
argument_list|(
name|StringTableSection
operator|&
name|StrTabSec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Outputs GNU Hash section. For detailed explanation see:
end_comment

begin_comment
comment|// https://blogs.oracle.com/ali/entry/gnu_hash_elf_sections
end_comment

begin_decl_stmt
name|class
name|GnuHashTableSection
name|final
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|GnuHashTableSection
argument_list|()
block|;
name|void
name|finalizeContents
argument_list|()
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
comment|// Adds symbols to the hash table.
comment|// Sorts the input to satisfy GNU hash section requirements.
name|void
name|addSymbols
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SymbolTableEntry
operator|>
operator|&
name|Symbols
argument_list|)
block|;
name|private
operator|:
name|size_t
name|getShift2
argument_list|()
specifier|const
block|{
return|return
name|Config
operator|->
name|Is64
operator|?
literal|6
operator|:
literal|5
return|;
block|}
name|void
name|writeBloomFilter
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
block|;
name|void
name|writeHashTable
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
block|;    struct
name|Entry
block|{
name|SymbolBody
operator|*
name|Body
block|;
name|size_t
name|StrTabOffset
block|;
name|uint32_t
name|Hash
block|;   }
block|;
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|Symbols
block|;
name|size_t
name|MaskWords
block|;
name|size_t
name|NBuckets
operator|=
literal|0
block|;
name|size_t
name|Size
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|HashTableSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|HashTableSection
argument_list|()
block|;
name|void
name|finalizeContents
argument_list|()
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
name|private
operator|:
name|size_t
name|Size
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// The PltSection is used for both the Plt and Iplt. The former always has a
end_comment

begin_comment
comment|// header as its first entry that is used at run-time to resolve lazy binding.
end_comment

begin_comment
comment|// The latter is used for GNU Ifunc symbols, that will be subject to a
end_comment

begin_comment
comment|// Target->IRelativeRel.
end_comment

begin_decl_stmt
name|class
name|PltSection
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|PltSection
argument_list|(
argument|size_t HeaderSize
argument_list|)
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|{
return|return
name|Entries
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|addSymbols
argument_list|()
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|addEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
block|;
name|private
operator|:
name|void
name|writeHeader
argument_list|(
argument|uint8_t *Buf
argument_list|)
block|{}
block|;
name|void
name|addHeaderSymbols
argument_list|()
block|{}
block|;
name|unsigned
name|getPltRelocOff
argument_list|()
specifier|const
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|SymbolBody
operator|*
block|,
name|unsigned
operator|>>
name|Entries
block|;
comment|// Iplt always has HeaderSize of 0, the Plt HeaderSize is always non-zero
name|size_t
name|HeaderSize
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|GdbIndexSection
name|final
range|:
name|public
name|SyntheticSection
block|{
specifier|const
name|unsigned
name|OffsetTypeSize
operator|=
literal|4
block|;
specifier|const
name|unsigned
name|CuListOffset
operator|=
literal|6
operator|*
name|OffsetTypeSize
block|;
specifier|const
name|unsigned
name|CompilationUnitSize
operator|=
literal|16
block|;
specifier|const
name|unsigned
name|AddressEntrySize
operator|=
literal|16
operator|+
name|OffsetTypeSize
block|;
specifier|const
name|unsigned
name|SymTabEntrySize
operator|=
literal|2
operator|*
name|OffsetTypeSize
block|;
name|public
operator|:
name|GdbIndexSection
argument_list|()
block|;
name|void
name|finalizeContents
argument_list|()
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|;
comment|// Pairs of [CU Offset, CU length].
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
block|,
name|uint64_t
operator|>>
name|CompilationUnits
block|;
name|llvm
operator|::
name|StringTableBuilder
name|StringPool
block|;
name|GdbHashTab
name|SymbolTable
block|;
comment|// The CU vector portion of the constant pool.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|set
operator|<
name|uint32_t
operator|>>
name|CuVectors
block|;
name|std
operator|::
name|vector
operator|<
name|AddressEntry
operator|>
name|AddressArea
block|;
name|private
operator|:
name|void
name|readDwarf
argument_list|(
name|InputSection
operator|*
name|Sec
argument_list|)
block|;
name|uint32_t
name|CuTypesOffset
block|;
name|uint32_t
name|SymTabOffset
block|;
name|uint32_t
name|ConstantPoolOffset
block|;
name|uint32_t
name|StringPoolOffset
block|;
name|size_t
name|CuVectorsSize
operator|=
literal|0
block|;
name|std
operator|::
name|vector
operator|<
name|size_t
operator|>
name|CuVectorsOffset
block|;
name|bool
name|Finalized
operator|=
name|false
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// --eh-frame-hdr option tells linker to construct a header for all the
end_comment

begin_comment
comment|// .eh_frame sections. This header is placed to a section named .eh_frame_hdr
end_comment

begin_comment
comment|// and also to a PT_GNU_EH_FRAME segment.
end_comment

begin_comment
comment|// At runtime the unwinder then can find all the PT_GNU_EH_FRAME segments by
end_comment

begin_comment
comment|// calling dl_iterate_phdr.
end_comment

begin_comment
comment|// This section contains a lookup table for quick binary search of FDEs.
end_comment

begin_comment
comment|// Detailed info about internals can be found in Ian Lance Taylor's blog:
end_comment

begin_comment
comment|// http://www.airs.com/blog/archives/460 (".eh_frame")
end_comment

begin_comment
comment|// http://www.airs.com/blog/archives/462 (".eh_frame_hdr")
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|EhFrameHeader
name|final
operator|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|EhFrameHeader
argument_list|()
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|;
name|void
name|addFde
argument_list|(
argument|uint32_t Pc
argument_list|,
argument|uint32_t FdeVA
argument_list|)
block|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
expr|struct
name|FdeData
block|{
name|uint32_t
name|Pc
block|;
name|uint32_t
name|FdeVA
block|;   }
block|;
name|std
operator|::
name|vector
operator|<
name|FdeData
operator|>
name|Fdes
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// For more information about .gnu.version and .gnu.version_r see:
end_comment

begin_comment
comment|// https://www.akkadia.org/drepper/symbol-versioning
end_comment

begin_comment
comment|// The .gnu.version_d section which has a section type of SHT_GNU_verdef shall
end_comment

begin_comment
comment|// contain symbol version definitions. The number of entries in this section
end_comment

begin_comment
comment|// shall be contained in the DT_VERDEFNUM entry of the .dynamic section.
end_comment

begin_comment
comment|// The section shall contain an array of Elf_Verdef structures, optionally
end_comment

begin_comment
comment|// followed by an array of Elf_Verdaux structures.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|VersionDefinitionSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Verdef
name|Elf_Verdef
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Verdaux
name|Elf_Verdaux
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|VersionDefinitionSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|finalizeContents
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|writeOne
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|,
name|uint32_t
name|Index
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|size_t
name|NameOff
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|unsigned
name|FileDefNameOff
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// The .gnu.version section specifies the required version of each symbol in the
end_comment

begin_comment
comment|// dynamic symbol table. It contains one Elf_Versym for each dynamic symbol
end_comment

begin_comment
comment|// table entry. An Elf_Versym is just a 16-bit integer that refers to a version
end_comment

begin_comment
comment|// identifier defined in the either .gnu.version_r or .gnu.version_d section.
end_comment

begin_comment
comment|// The values 0 and 1 are reserved. All other values are used for versions in
end_comment

begin_comment
comment|// the own object or in any of the dependencies.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|VersionTableSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Versym
name|Elf_Versym
expr_stmt|;
name|public
operator|:
name|VersionTableSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|finalizeContents
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// The .gnu.version_r section defines the version identifiers used by
end_comment

begin_comment
comment|// .gnu.version. It contains a linked list of Elf_Verneed data structures. Each
end_comment

begin_comment
comment|// Elf_Verneed specifies the version requirements for a single DSO, and contains
end_comment

begin_comment
comment|// a reference to a linked list of Elf_Vernaux data structures which define the
end_comment

begin_comment
comment|// mapping from version identifiers to version names.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|VersionNeedSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Verneed
name|Elf_Verneed
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Vernaux
name|Elf_Vernaux
expr_stmt|;
end_typedef

begin_comment
comment|// A vector of shared files that need Elf_Verneed data structures and the
end_comment

begin_comment
comment|// string table offsets of their sonames.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|SharedFile
operator|<
name|ELFT
operator|>
operator|*
operator|,
name|size_t
operator|>>
name|Needed
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The next available version identifier.
end_comment

begin_decl_stmt
name|unsigned
name|NextIndex
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|VersionNeedSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|addSymbol
parameter_list|(
name|SharedSymbol
modifier|*
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|void
name|finalizeContents
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|size_t
name|getNeedNum
argument_list|()
specifier|const
block|{
return|return
name|Needed
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// MergeSyntheticSection is a class that allows us to put mergeable sections
end_comment

begin_comment
comment|// with different attributes in a single output sections. To do that
end_comment

begin_comment
comment|// we put them into MergeSyntheticSection synthetic input sections which are
end_comment

begin_comment
comment|// attached to regular output sections.
end_comment

begin_decl_stmt
name|class
name|MergeSyntheticSection
name|final
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|MergeSyntheticSection
argument_list|(
argument|StringRef Name
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uint64_t Flags
argument_list|,
argument|uint32_t Alignment
argument_list|)
block|;
name|void
name|addSection
argument_list|(
name|MergeInputSection
operator|*
name|MS
argument_list|)
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|void
name|finalizeContents
argument_list|()
name|override
block|;
name|bool
name|shouldTailMerge
argument_list|()
specifier|const
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|void
name|finalizeTailMerge
argument_list|()
block|;
name|void
name|finalizeNoTailMerge
argument_list|()
block|;
name|bool
name|Finalized
operator|=
name|false
block|;
name|llvm
operator|::
name|StringTableBuilder
name|Builder
block|;
name|std
operator|::
name|vector
operator|<
name|MergeInputSection
operator|*
operator|>
name|Sections
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// .MIPS.abiflags section.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsAbiFlagsSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_ABIFlags
operator|<
name|ELFT
operator|>
name|Elf_Mips_ABIFlags
expr_stmt|;
name|public
operator|:
specifier|static
name|MipsAbiFlagsSection
operator|*
name|create
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
name|MipsAbiFlagsSection
argument_list|(
argument|Elf_Mips_ABIFlags Flags
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
sizeof|sizeof
argument_list|(
name|Elf_Mips_ABIFlags
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|Elf_Mips_ABIFlags
name|Flags
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// .MIPS.options section.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsOptionsSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_Options
operator|<
name|ELFT
operator|>
name|Elf_Mips_Options
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_RegInfo
operator|<
name|ELFT
operator|>
name|Elf_Mips_RegInfo
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_function_decl
specifier|static
name|MipsOptionsSection
modifier|*
name|create
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|MipsOptionsSection
argument_list|(
argument|Elf_Mips_RegInfo Reginfo
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
sizeof|sizeof
argument_list|(
name|Elf_Mips_Options
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|Elf_Mips_RegInfo
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|Elf_Mips_RegInfo
name|Reginfo
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// MIPS .reginfo section.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsReginfoSection
name|final
operator|:
name|public
name|SyntheticSection
block|{
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_RegInfo
operator|<
name|ELFT
operator|>
name|Elf_Mips_RegInfo
expr_stmt|;
name|public
operator|:
specifier|static
name|MipsReginfoSection
operator|*
name|create
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
name|MipsReginfoSection
argument_list|(
argument|Elf_Mips_RegInfo Reginfo
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
sizeof|sizeof
argument_list|(
name|Elf_Mips_RegInfo
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|Elf_Mips_RegInfo
name|Reginfo
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// This is a MIPS specific section to hold a space within the data segment
end_comment

begin_comment
comment|// of executable file which is pointed to by the DT_MIPS_RLD_MAP entry.
end_comment

begin_comment
comment|// See "Dynamic section" in Chapter 5 in the following document:
end_comment

begin_comment
comment|// ftp://www.linux-mips.org/pub/linux/mips/doc/ABI/mipsabi.pdf
end_comment

begin_decl_stmt
name|class
name|MipsRldMapSection
range|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|MipsRldMapSection
argument_list|()
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Config
operator|->
name|Wordsize
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|{}
expr|}
block|;
name|class
name|ARMExidxSentinelSection
operator|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
name|ARMExidxSentinelSection
argument_list|()
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
literal|8
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|; }
block|;
comment|// A container for one or more linker generated thunks. Instances of these
comment|// thunks including ARM interworking and Mips LA25 PI to non-PI thunks.
name|class
name|ThunkSection
operator|:
name|public
name|SyntheticSection
block|{
name|public
operator|:
comment|// ThunkSection in OS, with desired OutSecOff of Off
name|ThunkSection
argument_list|(
argument|OutputSection *OS
argument_list|,
argument|uint64_t Off
argument_list|)
block|;
comment|// Add a newly created Thunk to this container:
comment|// Thunk is given offset from start of this InputSection
comment|// Thunk defines a symbol in this InputSection that can be used as target
comment|// of a relocation
name|void
name|addThunk
argument_list|(
name|Thunk
operator|*
name|T
argument_list|)
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Size
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
block|;
name|InputSection
operator|*
name|getTargetInputSection
argument_list|()
specifier|const
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
specifier|const
name|Thunk
operator|*
operator|>
name|Thunks
block|;
name|size_t
name|Size
operator|=
literal|0
block|; }
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSection
operator|*
name|createCommonSection
argument_list|()
block|;
name|InputSection
operator|*
name|createInterpSection
argument_list|()
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|MergeInputSection
operator|*
name|createCommentSection
argument_list|()
block|;
name|SymbolBody
operator|*
name|addSyntheticLocal
argument_list|(
argument|StringRef Name
argument_list|,
argument|uint8_t Type
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint64_t Size
argument_list|,
argument|InputSectionBase *Section
argument_list|)
block|;
comment|// Linker generated sections which can be used as inputs.
block|struct
name|InX
block|{
specifier|static
name|InputSection
operator|*
name|ARMAttributes
block|;
specifier|static
name|BssSection
operator|*
name|Bss
block|;
specifier|static
name|BssSection
operator|*
name|BssRelRo
block|;
specifier|static
name|BuildIdSection
operator|*
name|BuildId
block|;
specifier|static
name|InputSection
operator|*
name|Common
block|;
specifier|static
name|SyntheticSection
operator|*
name|Dynamic
block|;
specifier|static
name|StringTableSection
operator|*
name|DynStrTab
block|;
specifier|static
name|SymbolTableBaseSection
operator|*
name|DynSymTab
block|;
specifier|static
name|GnuHashTableSection
operator|*
name|GnuHashTab
block|;
specifier|static
name|InputSection
operator|*
name|Interp
block|;
specifier|static
name|GdbIndexSection
operator|*
name|GdbIndex
block|;
specifier|static
name|GotSection
operator|*
name|Got
block|;
specifier|static
name|GotPltSection
operator|*
name|GotPlt
block|;
specifier|static
name|IgotPltSection
operator|*
name|IgotPlt
block|;
specifier|static
name|MipsGotSection
operator|*
name|MipsGot
block|;
specifier|static
name|MipsRldMapSection
operator|*
name|MipsRldMap
block|;
specifier|static
name|PltSection
operator|*
name|Plt
block|;
specifier|static
name|PltSection
operator|*
name|Iplt
block|;
specifier|static
name|StringTableSection
operator|*
name|ShStrTab
block|;
specifier|static
name|StringTableSection
operator|*
name|StrTab
block|;
specifier|static
name|SymbolTableBaseSection
operator|*
name|SymTab
block|; }
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|In
operator|:
name|public
name|InX
block|{
specifier|static
name|EhFrameHeader
operator|<
name|ELFT
operator|>
operator|*
name|EhFrameHdr
block|;
specifier|static
name|EhFrameSection
operator|<
name|ELFT
operator|>
operator|*
name|EhFrame
block|;
specifier|static
name|HashTableSection
operator|<
name|ELFT
operator|>
operator|*
name|HashTab
block|;
specifier|static
name|RelocationSection
operator|<
name|ELFT
operator|>
operator|*
name|RelaDyn
block|;
specifier|static
name|RelocationSection
operator|<
name|ELFT
operator|>
operator|*
name|RelaPlt
block|;
specifier|static
name|RelocationSection
operator|<
name|ELFT
operator|>
operator|*
name|RelaIplt
block|;
specifier|static
name|VersionDefinitionSection
operator|<
name|ELFT
operator|>
operator|*
name|VerDef
block|;
specifier|static
name|VersionTableSection
operator|<
name|ELFT
operator|>
operator|*
name|VerSym
block|;
specifier|static
name|VersionNeedSection
operator|<
name|ELFT
operator|>
operator|*
name|VerNeed
block|; }
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|EhFrameHeader
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|EhFrameHdr
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|EhFrameSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|EhFrame
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|HashTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|HashTab
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|RelocationSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|RelaDyn
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|RelocationSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|RelaPlt
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|RelocationSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|RelaIplt
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|VersionDefinitionSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|VerDef
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|VersionTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|VerSym
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|VersionNeedSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|VerNeed
block|; }
end_decl_stmt

begin_comment
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

