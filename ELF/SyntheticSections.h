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
name|class
name|SyntheticSection
operator|:
name|public
name|InputSection
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
name|public
operator|:
name|SyntheticSection
argument_list|(
argument|uintX_t Flags
argument_list|,
argument|uint32_t Type
argument_list|,
argument|uintX_t Addralign
argument_list|,
argument|StringRef Name
argument_list|)
operator|:
name|InputSection
operator|<
name|ELFT
operator|>
operator|(
name|Flags
operator|,
name|Type
operator|,
name|Addralign
operator|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
operator|)
operator|,
name|Name
operator|,
name|InputSectionData
operator|::
name|Synthetic
operator|)
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
expr_stmt|;
name|virtual
name|void
name|writeTo
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|size_t
name|getSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|finalize
parameter_list|()
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
name|uintX_t
name|getVA
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|OutSec
operator|?
name|this
operator|->
name|OutSec
operator|->
name|Addr
operator|+
name|this
operator|->
name|OutSecOff
operator|:
literal|0
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|InputSectionData
modifier|*
name|D
parameter_list|)
block|{
return|return
name|D
operator|->
name|kind
argument_list|()
operator|==
name|InputSectionData
operator|::
name|Synthetic
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|GotSection
name|final
operator|:
name|public
name|SyntheticSection
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
name|public
operator|:
name|GotSection
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
name|finalize
argument_list|()
name|override
expr_stmt|;
name|bool
name|empty
argument_list|()
specifier|const
name|override
expr_stmt|;
name|void
name|addEntry
parameter_list|(
name|SymbolBody
modifier|&
name|Sym
parameter_list|)
function_decl|;
name|bool
name|addDynTlsEntry
parameter_list|(
name|SymbolBody
modifier|&
name|Sym
parameter_list|)
function_decl|;
name|bool
name|addTlsIndex
parameter_list|()
function_decl|;
name|uintX_t
name|getGlobalDynAddr
argument_list|(
specifier|const
name|SymbolBody
operator|&
name|B
argument_list|)
decl|const
decl_stmt|;
name|uintX_t
name|getGlobalDynOffset
argument_list|(
specifier|const
name|SymbolBody
operator|&
name|B
argument_list|)
decl|const
decl_stmt|;
name|uintX_t
name|getTlsIndexVA
parameter_list|()
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
init|=
name|false
decl_stmt|;
name|private
label|:
name|size_t
name|NumEntries
init|=
literal|0
decl_stmt|;
name|uint32_t
name|TlsIndexOff
init|=
operator|-
literal|1
decl_stmt|;
name|uintX_t
name|Size
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// .note.gnu.build-id section.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|BuildIdSection
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
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
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|HashSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint8_t
modifier|*
name|HashBuf
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
name|MipsGotSection
name|final
operator|:
name|public
name|SyntheticSection
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
name|public
operator|:
name|MipsGotSection
argument_list|()
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

begin_expr_stmt
name|void
name|finalize
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|addEntry
parameter_list|(
name|SymbolBody
modifier|&
name|Sym
parameter_list|,
name|uintX_t
name|Addend
parameter_list|,
name|RelExpr
name|Expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|addDynTlsEntry
parameter_list|(
name|SymbolBody
modifier|&
name|Sym
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|addTlsIndex
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|uintX_t
name|getPageEntryOffset
argument_list|(
specifier|const
name|SymbolBody
operator|&
name|B
argument_list|,
name|uintX_t
name|Addend
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintX_t
name|getBodyEntryOffset
argument_list|(
specifier|const
name|SymbolBody
operator|&
name|B
argument_list|,
name|uintX_t
name|Addend
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintX_t
name|getGlobalDynOffset
argument_list|(
specifier|const
name|SymbolBody
operator|&
name|B
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns the symbol which corresponds to the first entry of the global part
end_comment

begin_comment
comment|// of GOT on MIPS platform. It is required to fill up MIPS-specific dynamic
end_comment

begin_comment
comment|// table properties.
end_comment

begin_comment
comment|// Returns nullptr if the global part is empty.
end_comment

begin_expr_stmt
specifier|const
name|SymbolBody
operator|*
name|getFirstGlobalEntry
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns the number of entries in the local part of GOT including
end_comment

begin_comment
comment|// the number of reserved entries.
end_comment

begin_expr_stmt
name|unsigned
name|getLocalEntriesNum
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns offset of TLS part of the MIPS GOT table. This part goes
end_comment

begin_comment
comment|// after 'local' and 'global' entries.
end_comment

begin_expr_stmt
name|uintX_t
name|getTlsOffset
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|getTlsIndexOff
argument_list|()
specifier|const
block|{
return|return
name|TlsIndexOff
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uintX_t
name|getGp
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// MIPS GOT consists of three parts: local, global and tls. Each part
end_comment

begin_comment
comment|// contains different types of entries. Here is a layout of GOT:
end_comment

begin_comment
comment|// - Header entries                |
end_comment

begin_comment
comment|// - Page entries                  |   Local part
end_comment

begin_comment
comment|// - Local entries (16-bit access) |
end_comment

begin_comment
comment|// - Local entries (32-bit access) |
end_comment

begin_comment
comment|// - Normal global entries         ||  Global part
end_comment

begin_comment
comment|// - Reloc-only global entries     ||
end_comment

begin_comment
comment|// - TLS entries                   ||| TLS part
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Header:
end_comment

begin_comment
comment|//   Two entries hold predefined value 0x0 and 0x80000000.
end_comment

begin_comment
comment|// Page entries:
end_comment

begin_comment
comment|//   These entries created by R_MIPS_GOT_PAGE relocation and R_MIPS_GOT16
end_comment

begin_comment
comment|//   relocation against local symbols. They are initialized by higher 16-bit
end_comment

begin_comment
comment|//   of the corresponding symbol's value. So each 64kb of address space
end_comment

begin_comment
comment|//   requires a single GOT entry.
end_comment

begin_comment
comment|// Local entries (16-bit access):
end_comment

begin_comment
comment|//   These entries created by GOT relocations against global non-preemptible
end_comment

begin_comment
comment|//   symbols so dynamic linker is not necessary to resolve the symbol's
end_comment

begin_comment
comment|//   values. "16-bit access" means that corresponding relocations address
end_comment

begin_comment
comment|//   GOT using 16-bit index. Each unique Symbol-Addend pair has its own
end_comment

begin_comment
comment|//   GOT entry.
end_comment

begin_comment
comment|// Local entries (32-bit access):
end_comment

begin_comment
comment|//   These entries are the same as above but created by relocations which
end_comment

begin_comment
comment|//   address GOT using 32-bit index (R_MIPS_GOT_HI16/LO16 etc).
end_comment

begin_comment
comment|// Normal global entries:
end_comment

begin_comment
comment|//   These entries created by GOT relocations against preemptible global
end_comment

begin_comment
comment|//   symbols. They need to be initialized by dynamic linker and they ordered
end_comment

begin_comment
comment|//   exactly as the corresponding entries in the dynamic symbols table.
end_comment

begin_comment
comment|// Reloc-only global entries:
end_comment

begin_comment
comment|//   These entries created for symbols that are referenced by dynamic
end_comment

begin_comment
comment|//   relocations R_MIPS_REL32. These entries are not accessed with gp-relative
end_comment

begin_comment
comment|//   addressing, but MIPS ABI requires that these entries be present in GOT.
end_comment

begin_comment
comment|// TLS entries:
end_comment

begin_comment
comment|//   Entries created by TLS relocations.
end_comment

begin_comment
comment|// Number of "Header" entries.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|HeaderEntriesNum
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Number of allocated "Page" entries.
end_comment

begin_decl_stmt
name|uint32_t
name|PageEntriesNum
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Map output sections referenced by MIPS GOT relocations
end_comment

begin_comment
comment|// to the first index of "Page" entries allocated for this section.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallMapVector
operator|<
specifier|const
name|OutputSectionBase
operator|*
operator|,
name|size_t
operator|,
literal|16
operator|>
name|PageIndexMap
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|SymbolBody
operator|*
operator|,
name|uintX_t
operator|>
name|GotEntry
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|GotEntry
operator|>
name|GotEntries
expr_stmt|;
end_typedef

begin_comment
comment|// Map from Symbol-Addend pair to the GOT index.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|// Local entries (16-bit access).
end_comment

begin_decl_stmt
name|GotEntries
name|LocalEntries
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Local entries (32-bit access).
end_comment

begin_decl_stmt
name|GotEntries
name|LocalEntries32
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Normal and reloc-only global entries.
end_comment

begin_decl_stmt
name|GotEntries
name|GlobalEntries
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TLS entries.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|TlsIndexOff
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintX_t
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
name|GotPltSection
name|final
operator|:
name|public
name|SyntheticSection
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
name|public
operator|:
name|GotPltSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|addEntry
parameter_list|(
name|SymbolBody
modifier|&
name|Sym
parameter_list|)
function_decl|;
end_function_decl

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
block|{
return|return
name|Entries
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
specifier|const
name|SymbolBody
operator|*
operator|>
name|Entries
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// The IgotPltSection is a Got associated with the IpltSection for GNU Ifunc
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

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|IgotPltSection
name|final
operator|:
name|public
name|SyntheticSection
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
name|public
operator|:
name|IgotPltSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|addEntry
parameter_list|(
name|SymbolBody
modifier|&
name|Sym
parameter_list|)
function_decl|;
end_function_decl

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
block|{
return|return
name|Entries
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
specifier|const
name|SymbolBody
operator|*
operator|>
name|Entries
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
name|StringTableSection
name|final
operator|:
name|public
name|SyntheticSection
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
name|uint
name|uintX_t
expr_stmt|;
name|StringTableSection
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool Dynamic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|unsigned
name|addString
parameter_list|(
name|StringRef
name|S
parameter_list|,
name|bool
name|HashIt
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

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

begin_expr_stmt
name|bool
name|isDynamic
argument_list|()
specifier|const
block|{
return|return
name|Dynamic
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|bool
name|Dynamic
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ELF string tables start with a NUL byte, so 1.
end_comment

begin_decl_stmt
name|uintX_t
name|Size
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|StringRef
operator|,
name|unsigned
operator|>
name|StringMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Strings
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
name|DynamicReloc
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
name|public
operator|:
name|DynamicReloc
argument_list|(
argument|uint32_t Type
argument_list|,
argument|const InputSectionBase<ELFT> *InputSec
argument_list|,
argument|uintX_t OffsetInSec
argument_list|,
argument|bool UseSymVA
argument_list|,
argument|SymbolBody *Sym
argument_list|,
argument|uintX_t Addend
argument_list|)
operator|:
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
name|DynamicReloc
argument_list|(
argument|uint32_t Type
argument_list|,
argument|const OutputSectionBase *OutputSec
argument_list|,
argument|uintX_t OffsetInSec
argument_list|,
argument|bool UseSymVA
argument_list|,
argument|SymbolBody *Sym
argument_list|,
argument|uintX_t Addend
argument_list|)
operator|:
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
name|OutputSec
argument_list|(
name|OutputSec
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
name|uintX_t
name|getOffset
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uintX_t
name|getAddend
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|getSymIndex
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|OutputSectionBase
operator|*
name|getOutputSec
argument_list|()
specifier|const
block|{
return|return
name|OutputSec
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|getInputSec
argument_list|()
specifier|const
block|{
return|return
name|InputSec
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|Type
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|SymbolBody
modifier|*
name|Sym
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|InputSec
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|OutputSectionBase
modifier|*
name|OutputSec
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintX_t
name|OffsetInSec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|UseSymVA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintX_t
name|Addend
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
name|DynamicSection
name|final
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
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

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
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
name|OutputSectionBase
modifier|*
name|OutSec
decl_stmt|;
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|InSec
expr_stmt|;
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
argument|OutputSectionBase *OutSec
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
argument|InputSection<ELFT> *Sec
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
comment|// finalize() fills this vector with the section contents. finalize()
end_comment

begin_comment
comment|// cannot directly create final section contents because when the
end_comment

begin_comment
comment|// function is called, symbol or section addresses are not fixed yet.
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
name|finalize
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
name|uintX_t
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
operator|<
name|ELFT
operator|>
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

begin_decl_stmt
name|void
name|addReloc
argument_list|(
specifier|const
name|DynamicReloc
operator|<
name|ELFT
operator|>
operator|&
name|Reloc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|unsigned
name|getRelocOffset
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|void
name|finalize
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
operator|<
name|ELFT
operator|>>
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
name|SyntheticSection
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
name|Sym
name|Elf_Sym
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|SymRange
name|Elf_Sym_Range
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

begin_expr_stmt
name|SymbolTableSection
argument_list|(
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|&
name|StrTabSec
argument_list|)
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
name|getNumSymbols
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|Elf_Sym
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|addGlobal
parameter_list|(
name|SymbolBody
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addLocal
parameter_list|(
name|SymbolBody
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|&
name|getStrTabSec
argument_list|()
specifier|const
block|{
return|return
name|StrTabSec
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
name|size_t
name|getSymbolIndex
parameter_list|(
name|SymbolBody
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
specifier|static
specifier|const
name|OutputSectionBase
modifier|*
name|getOutputSection
parameter_list|(
name|SymbolBody
modifier|*
name|Sym
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|writeLocalSymbols
parameter_list|(
name|uint8_t
modifier|*
modifier|&
name|Buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writeGlobalSymbols
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// A vector of symbols and their string table offsets.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|SymbolTableEntry
operator|>
name|Symbols
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|&
name|StrTabSec
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|NumLocals
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Outputs GNU Hash section. For detailed explanation see:
end_comment

begin_comment
comment|// https://blogs.oracle.com/ali/entry/gnu_hash_elf_sections
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|GnuHashTableSection
name|final
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Off
name|Elf_Off
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ELFT
operator|::
name|Word
name|Elf_Word
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
name|GnuHashTableSection
argument_list|()
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
name|this
operator|->
name|Size
return|;
block|}
end_expr_stmt

begin_comment
comment|// Adds symbols to the hash table.
end_comment

begin_comment
comment|// Sorts the input to satisfy GNU hash section requirements.
end_comment

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
specifier|static
name|unsigned
name|calcNBuckets
parameter_list|(
name|unsigned
name|NumHashed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|unsigned
name|calcMaskWords
parameter_list|(
name|unsigned
name|NumHashed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writeHeader
parameter_list|(
name|uint8_t
modifier|*
modifier|&
name|Buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writeBloomFilter
parameter_list|(
name|uint8_t
modifier|*
modifier|&
name|Buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writeHashTable
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|SymbolData
block|{
name|SymbolBody
modifier|*
name|Body
decl_stmt|;
name|size_t
name|STName
decl_stmt|;
name|uint32_t
name|Hash
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|SymbolData
operator|>
name|Symbols
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|MaskWords
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|NBuckets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|Shift2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintX_t
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
name|HashTableSection
name|final
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|Word
name|Elf_Word
expr_stmt|;
name|public
operator|:
name|HashTableSection
argument_list|()
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
name|this
operator|->
name|Size
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|size_t
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
name|PltSection
name|final
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|PltSection
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
name|addEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
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
name|std
operator|::
name|pair
operator|<
specifier|const
name|SymbolBody
operator|*
operator|,
name|unsigned
operator|>>
name|Entries
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// The IpltSection is a variant of Plt for recording entries for GNU Ifunc
end_comment

begin_comment
comment|// symbols that will be subject to a Target->IRelativeRel
end_comment

begin_comment
comment|// The IpltSection immediately follows the Plt section in the Output Section
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|IpltSection
name|final
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|IpltSection
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
name|addEntry
argument_list|(
name|SymbolBody
operator|&
name|Sym
argument_list|)
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
name|std
operator|::
name|pair
operator|<
specifier|const
name|SymbolBody
operator|*
operator|,
name|unsigned
operator|>>
name|Entries
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
name|GdbIndexSection
name|final
operator|:
name|public
name|SyntheticSection
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
specifier|const
name|unsigned
name|OffsetTypeSize
operator|=
literal|4
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|CuListOffset
init|=
literal|6
operator|*
name|OffsetTypeSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|CompilationUnitSize
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|AddressEntrySize
init|=
literal|16
operator|+
name|OffsetTypeSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|SymTabEntrySize
init|=
literal|2
operator|*
name|OffsetTypeSize
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|GdbIndexSection
argument_list|()
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
name|bool
name|empty
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Pairs of [CU Offset, CU length].
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
name|uintX_t
operator|,
name|uintX_t
operator|>>
name|CompilationUnits
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|StringTableBuilder
name|StringPool
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|GdbHashTab
name|SymbolTable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The CU vector portion of the constant pool.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|uint8_t
operator|>>>
name|CuVectors
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|AddressEntry
operator|<
name|ELFT
operator|>>
name|AddressArea
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|parseDebugSections
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|readDwarf
argument_list|(
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|I
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|CuTypesOffset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|SymTabOffset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|ConstantPoolOffset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|StringPoolOffset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|CuVectorsSize
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|size_t
operator|>
name|CuVectorsOffset
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|Finalized
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
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
name|public
operator|:
name|EhFrameHeader
argument_list|()
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

begin_function_decl
name|void
name|addFde
parameter_list|(
name|uint32_t
name|Pc
parameter_list|,
name|uint32_t
name|FdeVA
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_struct
struct|struct
name|FdeData
block|{
name|uint32_t
name|Pc
decl_stmt|;
name|uint32_t
name|FdeVA
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|FdeData
operator|>
name|Fdes
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
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
operator|<
name|ELFT
operator|>
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
name|finalize
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
operator|<
name|ELFT
operator|>
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
name|finalize
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
operator|<
name|ELFT
operator|>
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

begin_decl_stmt
name|void
name|addSymbol
argument_list|(
name|SharedSymbol
operator|<
name|ELFT
operator|>
operator|*
name|SS
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|finalize
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
operator|<
name|ELFT
operator|>
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
operator|<
name|ELFT
operator|>
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
operator|<
name|ELFT
operator|>
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

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsRldMapSection
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
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
expr|sizeof
operator|(
name|typename
name|ELFT
operator|::
name|uint
operator|)
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
name|override
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
name|ARMExidxSentinelSection
operator|:
name|public
name|SyntheticSection
operator|<
name|ELFT
operator|>
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
operator|*
name|createCommonSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|createInterpSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|MergeInputSection
operator|<
name|ELFT
operator|>
operator|*
name|createCommentSection
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Linker generated sections which can be used as inputs.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|In
block|{
specifier|static
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|ARMAttributes
block|;
specifier|static
name|BuildIdSection
operator|<
name|ELFT
operator|>
operator|*
name|BuildId
block|;
specifier|static
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|Common
block|;
specifier|static
name|DynamicSection
operator|<
name|ELFT
operator|>
operator|*
name|Dynamic
block|;
specifier|static
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|*
name|DynStrTab
block|;
specifier|static
name|SymbolTableSection
operator|<
name|ELFT
operator|>
operator|*
name|DynSymTab
block|;
specifier|static
name|EhFrameHeader
operator|<
name|ELFT
operator|>
operator|*
name|EhFrameHdr
block|;
specifier|static
name|GnuHashTableSection
operator|<
name|ELFT
operator|>
operator|*
name|GnuHashTab
block|;
specifier|static
name|GdbIndexSection
operator|<
name|ELFT
operator|>
operator|*
name|GdbIndex
block|;
specifier|static
name|GotSection
operator|<
name|ELFT
operator|>
operator|*
name|Got
block|;
specifier|static
name|MipsGotSection
operator|<
name|ELFT
operator|>
operator|*
name|MipsGot
block|;
specifier|static
name|GotPltSection
operator|<
name|ELFT
operator|>
operator|*
name|GotPlt
block|;
specifier|static
name|IgotPltSection
operator|<
name|ELFT
operator|>
operator|*
name|IgotPlt
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
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|Interp
block|;
specifier|static
name|MipsRldMapSection
operator|<
name|ELFT
operator|>
operator|*
name|MipsRldMap
block|;
specifier|static
name|PltSection
operator|<
name|ELFT
operator|>
operator|*
name|Plt
block|;
specifier|static
name|IpltSection
operator|<
name|ELFT
operator|>
operator|*
name|Iplt
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
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|*
name|ShStrTab
block|;
specifier|static
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|*
name|StrTab
block|;
specifier|static
name|SymbolTableSection
operator|<
name|ELFT
operator|>
operator|*
name|SymTab
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|ARMAttributes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|BuildIdSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|BuildId
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|Common
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|DynamicSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|Dynamic
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|DynStrTab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|SymbolTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|DynSymTab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|GdbIndexSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|GdbIndex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|GnuHashTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|GnuHashTab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|GotSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|Got
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|MipsGotSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|MipsGot
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|GotPltSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|GotPlt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|IgotPltSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|IgotPlt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|Interp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|MipsRldMapSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|MipsRldMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|PltSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|Plt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|IpltSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|Iplt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|ShStrTab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|StringTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|StrTab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|SymbolTableSection
operator|<
name|ELFT
operator|>
operator|*
name|In
operator|<
name|ELFT
operator|>
operator|::
name|SymTab
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
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

