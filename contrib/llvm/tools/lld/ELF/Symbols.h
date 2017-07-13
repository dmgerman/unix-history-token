begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Symbols.h ------------------------------------------------*- C++ -*-===//
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
comment|// All symbols are handled as SymbolBodies regardless of their types.
end_comment

begin_comment
comment|// This file defines various types of SymbolBodies.
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
name|LLD_ELF_SYMBOLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_SYMBOLS_H
end_define

begin_include
include|#
directive|include
file|"InputSection.h"
end_include

begin_include
include|#
directive|include
file|"Strings.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Archive.h"
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
name|class
name|ArchiveFile
decl_stmt|;
name|class
name|BitcodeFile
decl_stmt|;
name|class
name|InputFile
decl_stmt|;
name|class
name|LazyObjectFile
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
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SharedFile
expr_stmt|;
struct_decl|struct
name|Symbol
struct_decl|;
comment|// The base class for real symbol classes.
name|class
name|SymbolBody
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|DefinedFirst
block|,
name|DefinedRegularKind
init|=
name|DefinedFirst
block|,
name|SharedKind
block|,
name|DefinedCommonKind
block|,
name|DefinedLast
init|=
name|DefinedCommonKind
block|,
name|UndefinedKind
block|,
name|LazyArchiveKind
block|,
name|LazyObjectKind
block|,   }
enum|;
name|SymbolBody
argument_list|(
argument|Kind K
argument_list|)
block|:
name|SymbolKind
argument_list|(
argument|K
argument_list|)
block|{}
name|Symbol
modifier|*
name|symbol
parameter_list|()
function_decl|;
specifier|const
name|Symbol
operator|*
name|symbol
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|SymbolBody
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|symbol
argument_list|()
return|;
block|}
name|Kind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Kind
operator|>
operator|(
name|SymbolKind
operator|)
return|;
block|}
name|bool
name|isUndefined
argument_list|()
specifier|const
block|{
return|return
name|SymbolKind
operator|==
name|UndefinedKind
return|;
block|}
name|bool
name|isDefined
argument_list|()
specifier|const
block|{
return|return
name|SymbolKind
operator|<=
name|DefinedLast
return|;
block|}
name|bool
name|isCommon
argument_list|()
specifier|const
block|{
return|return
name|SymbolKind
operator|==
name|DefinedCommonKind
return|;
block|}
name|bool
name|isLazy
argument_list|()
specifier|const
block|{
return|return
name|SymbolKind
operator|==
name|LazyArchiveKind
operator|||
name|SymbolKind
operator|==
name|LazyObjectKind
return|;
block|}
name|bool
name|isShared
argument_list|()
specifier|const
block|{
return|return
name|SymbolKind
operator|==
name|SharedKind
return|;
block|}
name|bool
name|isInCurrentDSO
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isUndefined
argument_list|()
operator|&&
operator|!
name|isShared
argument_list|()
operator|&&
operator|!
name|isLazy
argument_list|()
return|;
block|}
name|bool
name|isLocal
argument_list|()
specifier|const
block|{
return|return
name|IsLocal
return|;
block|}
name|bool
name|isPreemptible
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|uint8_t
name|getVisibility
argument_list|()
specifier|const
block|{
return|return
name|StOther
operator|&
literal|0x3
return|;
block|}
name|void
name|parseSymbolVersion
parameter_list|()
function_decl|;
name|void
name|copy
parameter_list|(
name|SymbolBody
modifier|*
name|Other
parameter_list|)
function_decl|;
name|bool
name|isInGot
argument_list|()
specifier|const
block|{
return|return
name|GotIndex
operator|!=
operator|-
literal|1U
return|;
block|}
name|bool
name|isInPlt
argument_list|()
specifier|const
block|{
return|return
name|PltIndex
operator|!=
operator|-
literal|1U
return|;
block|}
name|uint64_t
name|getVA
argument_list|(
name|int64_t
name|Addend
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getGotOffset
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getGotVA
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getGotPltOffset
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getGotPltVA
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getPltVA
argument_list|()
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|typename
name|ELFT
operator|::
name|uint
name|getSize
argument_list|()
specifier|const
expr_stmt|;
name|OutputSection
operator|*
name|getOutputSection
argument_list|()
specifier|const
expr_stmt|;
comment|// The file from which this symbol was created.
name|InputFile
modifier|*
name|File
init|=
name|nullptr
decl_stmt|;
name|uint32_t
name|DynsymIndex
init|=
literal|0
decl_stmt|;
name|uint32_t
name|GotIndex
init|=
operator|-
literal|1
decl_stmt|;
name|uint32_t
name|GotPltIndex
init|=
operator|-
literal|1
decl_stmt|;
name|uint32_t
name|PltIndex
init|=
operator|-
literal|1
decl_stmt|;
name|uint32_t
name|GlobalDynIndex
init|=
operator|-
literal|1
decl_stmt|;
name|protected
label|:
name|SymbolBody
argument_list|(
argument|Kind K
argument_list|,
argument|StringRefZ Name
argument_list|,
argument|bool IsLocal
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|)
empty_stmt|;
specifier|const
name|unsigned
name|SymbolKind
range|:
literal|8
decl_stmt|;
name|public
label|:
comment|// True if the linker has to generate a copy relocation.
comment|// For SharedSymbol only.
name|unsigned
name|NeedsCopy
range|:
literal|1
decl_stmt|;
comment|// True the symbol should point to its PLT entry.
comment|// For SharedSymbol only.
name|unsigned
name|NeedsPltAddr
range|:
literal|1
decl_stmt|;
comment|// True if this is a local symbol.
name|unsigned
name|IsLocal
range|:
literal|1
decl_stmt|;
comment|// True if this symbol has an entry in the global part of MIPS GOT.
name|unsigned
name|IsInGlobalMipsGot
range|:
literal|1
decl_stmt|;
comment|// True if this symbol is referenced by 32-bit GOT relocations.
name|unsigned
name|Is32BitMipsGot
range|:
literal|1
decl_stmt|;
comment|// True if this symbol is in the Iplt sub-section of the Plt.
name|unsigned
name|IsInIplt
range|:
literal|1
decl_stmt|;
comment|// True if this symbol is in the Igot sub-section of the .got.plt or .got.
name|unsigned
name|IsInIgot
range|:
literal|1
decl_stmt|;
comment|// The following fields have the same meaning as the ELF symbol attributes.
name|uint8_t
name|Type
decl_stmt|;
comment|// symbol type
name|uint8_t
name|StOther
decl_stmt|;
comment|// st_other field value
comment|// The Type field may also have this value. It means that we have not yet seen
comment|// a non-Lazy symbol with this name, so we don't know what its type is. The
comment|// Type field is normally set to this value for Lazy symbols unless we saw a
comment|// weak undefined symbol first, in which case we need to remember the original
comment|// symbol's type in order to check for TLS mismatches.
enum|enum
block|{
name|UnknownType
init|=
literal|255
block|}
enum|;
name|bool
name|isSection
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_SECTION
return|;
block|}
name|bool
name|isTls
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_TLS
return|;
block|}
name|bool
name|isFunc
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_FUNC
return|;
block|}
name|bool
name|isGnuIFunc
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_GNU_IFUNC
return|;
block|}
name|bool
name|isObject
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_OBJECT
return|;
block|}
name|bool
name|isFile
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_FILE
return|;
block|}
name|protected
label|:
name|StringRefZ
name|Name
decl_stmt|;
block|}
empty_stmt|;
comment|// The base class for any defined symbols.
name|class
name|Defined
range|:
name|public
name|SymbolBody
block|{
name|public
operator|:
name|Defined
argument_list|(
argument|Kind K
argument_list|,
argument|StringRefZ Name
argument_list|,
argument|bool IsLocal
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|isDefined
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|DefinedCommon
operator|:
name|public
name|Defined
block|{
name|public
operator|:
name|DefinedCommon
argument_list|(
argument|StringRef N
argument_list|,
argument|uint64_t Size
argument_list|,
argument|uint32_t Alignment
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|,
argument|InputFile *File
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|SymbolBody
operator|::
name|DefinedCommonKind
return|;
block|}
comment|// The output offset of this common symbol in the output bss. Computed by the
comment|// writer.
name|uint64_t
name|Offset
block|;
comment|// The maximum alignment we have seen for this symbol.
name|uint32_t
name|Alignment
block|;
name|uint64_t
name|Size
block|; }
block|;
comment|// Regular defined symbols read from object file symbol tables.
name|class
name|DefinedRegular
operator|:
name|public
name|Defined
block|{
name|public
operator|:
name|DefinedRegular
argument_list|(
argument|StringRefZ Name
argument_list|,
argument|bool IsLocal
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint64_t Size
argument_list|,
argument|SectionBase *Section
argument_list|,
argument|InputFile *File
argument_list|)
operator|:
name|Defined
argument_list|(
name|SymbolBody
operator|::
name|DefinedRegularKind
argument_list|,
name|Name
argument_list|,
name|IsLocal
argument_list|,
name|StOther
argument_list|,
name|Type
argument_list|)
block|,
name|Value
argument_list|(
name|Value
argument_list|)
block|,
name|Size
argument_list|(
name|Size
argument_list|)
block|,
name|Section
argument_list|(
argument|Section
argument_list|)
block|{
name|this
operator|->
name|File
operator|=
name|File
block|;   }
comment|// Return true if the symbol is a PIC function.
name|template
operator|<
name|class
name|ELFT
operator|>
name|bool
name|isMipsPIC
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|SymbolBody
operator|::
name|DefinedRegularKind
return|;
block|}
name|uint64_t
name|Value
block|;
name|uint64_t
name|Size
block|;
name|SectionBase
operator|*
name|Section
block|; }
block|;
name|class
name|Undefined
operator|:
name|public
name|SymbolBody
block|{
name|public
operator|:
name|Undefined
argument_list|(
argument|StringRefZ Name
argument_list|,
argument|bool IsLocal
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|,
argument|InputFile *F
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|UndefinedKind
return|;
block|}
expr|}
block|;
name|class
name|SharedSymbol
operator|:
name|public
name|Defined
block|{
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|SymbolBody
operator|::
name|SharedKind
return|;
block|}
name|SharedSymbol
argument_list|(
argument|InputFile *File
argument_list|,
argument|StringRef Name
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|,
argument|const void *ElfSym
argument_list|,
argument|const void *Verdef
argument_list|)
operator|:
name|Defined
argument_list|(
name|SymbolBody
operator|::
name|SharedKind
argument_list|,
name|Name
argument_list|,
comment|/*IsLocal=*/
name|false
argument_list|,
name|StOther
argument_list|,
name|Type
argument_list|)
block|,
name|Verdef
argument_list|(
name|Verdef
argument_list|)
block|,
name|ElfSym
argument_list|(
argument|ElfSym
argument_list|)
block|{
comment|// IFuncs defined in DSOs are treated as functions by the static linker.
if|if
condition|(
name|isGnuIFunc
argument_list|()
condition|)
name|this
operator|->
name|Type
operator|=
name|llvm
operator|::
name|ELF
operator|::
name|STT_FUNC
expr_stmt|;
name|this
operator|->
name|File
operator|=
name|File
block|;   }
name|template
operator|<
name|class
name|ELFT
operator|>
name|uint64_t
name|getShndx
argument_list|()
specifier|const
block|{
return|return
name|getSym
operator|<
name|ELFT
operator|>
operator|(
operator|)
operator|.
name|st_shndx
return|;
block|}
name|template
operator|<
name|class
name|ELFT
operator|>
name|uint64_t
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|getSym
operator|<
name|ELFT
operator|>
operator|(
operator|)
operator|.
name|st_value
return|;
block|}
name|template
operator|<
name|class
name|ELFT
operator|>
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|getSym
operator|<
name|ELFT
operator|>
operator|(
operator|)
operator|.
name|st_size
return|;
block|}
name|template
operator|<
name|class
name|ELFT
operator|>
name|uint32_t
name|getAlignment
argument_list|()
specifier|const
block|;
comment|// This field is a pointer to the symbol's version definition.
specifier|const
name|void
operator|*
name|Verdef
block|;
comment|// CopyRelSec and CopyRelSecOff are significant only when NeedsCopy is true.
name|InputSection
operator|*
name|CopyRelSec
block|;
name|uint64_t
name|CopyRelSecOff
block|;
name|private
operator|:
name|template
operator|<
name|class
name|ELFT
operator|>
specifier|const
name|typename
name|ELFT
operator|::
name|Sym
operator|&
name|getSym
argument_list|()
specifier|const
block|{
return|return
operator|*
operator|(
specifier|const
name|typename
name|ELFT
operator|::
name|Sym
operator|*
operator|)
name|ElfSym
return|;
block|}
specifier|const
name|void
operator|*
name|ElfSym
block|; }
block|;
comment|// This class represents a symbol defined in an archive file. It is
comment|// created from an archive file header, and it knows how to load an
comment|// object file from an archive to replace itself with a defined
comment|// symbol. If the resolver finds both Undefined and Lazy for
comment|// the same name, it will ask the Lazy to load a file.
name|class
name|Lazy
operator|:
name|public
name|SymbolBody
block|{
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|isLazy
argument_list|()
return|;
block|}
comment|// Returns an object file for this symbol, or a nullptr if the file
comment|// was already returned.
name|InputFile
operator|*
name|fetch
argument_list|()
block|;
name|protected
operator|:
name|Lazy
argument_list|(
argument|SymbolBody::Kind K
argument_list|,
argument|StringRef Name
argument_list|,
argument|uint8_t Type
argument_list|)
operator|:
name|SymbolBody
argument_list|(
argument|K
argument_list|,
argument|Name
argument_list|,
comment|/*IsLocal=*/
argument|false
argument_list|,
argument|llvm::ELF::STV_DEFAULT
argument_list|,
argument|Type
argument_list|)
block|{}
block|}
block|;
comment|// LazyArchive symbols represents symbols in archive files.
name|class
name|LazyArchive
operator|:
name|public
name|Lazy
block|{
name|public
operator|:
name|LazyArchive
argument_list|(
argument|ArchiveFile&File
argument_list|,
argument|const llvm::object::Archive::Symbol S
argument_list|,
argument|uint8_t Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|LazyArchiveKind
return|;
block|}
name|ArchiveFile
operator|*
name|file
argument_list|()
block|{
return|return
operator|(
name|ArchiveFile
operator|*
operator|)
name|this
operator|->
name|File
return|;
block|}
name|InputFile
operator|*
name|fetch
argument_list|()
block|;
name|private
operator|:
specifier|const
name|llvm
operator|::
name|object
operator|::
name|Archive
operator|::
name|Symbol
name|Sym
block|; }
block|;
comment|// LazyObject symbols represents symbols in object files between
comment|// --start-lib and --end-lib options.
name|class
name|LazyObject
operator|:
name|public
name|Lazy
block|{
name|public
operator|:
name|LazyObject
argument_list|(
argument|StringRef Name
argument_list|,
argument|LazyObjectFile&File
argument_list|,
argument|uint8_t Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SymbolBody *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|LazyObjectKind
return|;
block|}
name|LazyObjectFile
operator|*
name|file
argument_list|()
block|{
return|return
operator|(
name|LazyObjectFile
operator|*
operator|)
name|this
operator|->
name|File
return|;
block|}
name|InputFile
operator|*
name|fetch
argument_list|()
block|; }
block|;
comment|// Some linker-generated symbols need to be created as
comment|// DefinedRegular symbols.
block|struct
name|ElfSym
block|{
comment|// __bss_start
specifier|static
name|DefinedRegular
operator|*
name|Bss
block|;
comment|// etext and _etext
specifier|static
name|DefinedRegular
operator|*
name|Etext1
block|;
specifier|static
name|DefinedRegular
operator|*
name|Etext2
block|;
comment|// edata and _edata
specifier|static
name|DefinedRegular
operator|*
name|Edata1
block|;
specifier|static
name|DefinedRegular
operator|*
name|Edata2
block|;
comment|// end and _end
specifier|static
name|DefinedRegular
operator|*
name|End1
block|;
specifier|static
name|DefinedRegular
operator|*
name|End2
block|;
comment|// The _GLOBAL_OFFSET_TABLE_ symbol is defined by target convention to
comment|// be at some offset from the base of the .got section, usually 0 or
comment|// the end of the .got.
specifier|static
name|DefinedRegular
operator|*
name|GlobalOffsetTable
block|;
comment|// _gp, _gp_disp and __gnu_local_gp symbols. Only for MIPS.
specifier|static
name|DefinedRegular
operator|*
name|MipsGp
block|;
specifier|static
name|DefinedRegular
operator|*
name|MipsGpDisp
block|;
specifier|static
name|DefinedRegular
operator|*
name|MipsLocalGp
block|; }
block|;
comment|// A real symbol object, SymbolBody, is usually stored within a Symbol. There's
comment|// always one Symbol for each symbol name. The resolver updates the SymbolBody
comment|// stored in the Body field of this object as it resolves symbols. Symbol also
comment|// holds computed properties of symbol names.
block|struct
name|Symbol
block|{
comment|// Symbol binding. This is on the Symbol to track changes during resolution.
comment|// In particular:
comment|// An undefined weak is still weak when it resolves to a shared library.
comment|// An undefined weak will not fetch archive members, but we have to remember
comment|// it is weak.
name|uint8_t
name|Binding
block|;
comment|// Version definition index.
name|uint16_t
name|VersionId
block|;
comment|// Symbol visibility. This is the computed minimum visibility of all
comment|// observed non-DSO symbols.
name|unsigned
name|Visibility
operator|:
literal|2
block|;
comment|// True if the symbol was used for linking and thus need to be added to the
comment|// output file's symbol table. This is true for all symbols except for
comment|// unreferenced DSO symbols and bitcode symbols that are unreferenced except
comment|// by other bitcode objects.
name|unsigned
name|IsUsedInRegularObj
operator|:
literal|1
block|;
comment|// If this flag is true and the symbol has protected or default visibility, it
comment|// will appear in .dynsym. This flag is set by interposable DSO symbols in
comment|// executables, by most symbols in DSOs and executables built with
comment|// --export-dynamic, and by dynamic lists.
name|unsigned
name|ExportDynamic
operator|:
literal|1
block|;
comment|// True if this symbol is specified by --trace-symbol option.
name|unsigned
name|Traced
operator|:
literal|1
block|;
comment|// This symbol version was found in a version script.
name|unsigned
name|InVersionScript
operator|:
literal|1
block|;
name|bool
name|includeInDynsym
argument_list|()
specifier|const
block|;
name|uint8_t
name|computeBinding
argument_list|()
specifier|const
block|;
name|bool
name|isWeak
argument_list|()
specifier|const
block|{
return|return
name|Binding
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STB_WEAK
return|;
block|}
comment|// This field is used to store the Symbol's SymbolBody. This instantiation of
comment|// AlignedCharArrayUnion gives us a struct with a char array field that is
comment|// large and aligned enough to store any derived class of SymbolBody.
name|llvm
operator|::
name|AlignedCharArrayUnion
operator|<
name|DefinedCommon
block|,
name|DefinedRegular
block|,
name|Undefined
block|,
name|SharedSymbol
block|,
name|LazyArchive
block|,
name|LazyObject
operator|>
name|Body
block|;
name|SymbolBody
operator|*
name|body
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|SymbolBody
operator|*
operator|>
operator|(
name|Body
operator|.
name|buffer
operator|)
return|;
block|}
specifier|const
name|SymbolBody
operator|*
name|body
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Symbol
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|body
argument_list|()
return|;
block|}
expr|}
block|;
name|void
name|printTraceSymbol
argument_list|(
name|Symbol
operator|*
name|Sym
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
block|,
name|typename
operator|...
name|ArgT
operator|>
name|void
name|replaceBody
argument_list|(
argument|Symbol *S
argument_list|,
argument|ArgT&&... Arg
argument_list|)
block|{
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|S
operator|->
name|Body
argument_list|)
argument_list|,
literal|"Body too small"
argument_list|)
block|;
name|static_assert
argument_list|(
name|alignof
argument_list|(
name|T
argument_list|)
operator|<=
name|alignof
argument_list|(
name|decltype
argument_list|(
name|S
operator|->
name|Body
argument_list|)
argument_list|)
argument_list|,
literal|"Body not aligned enough"
argument_list|)
block|;
name|assert
argument_list|(
name|static_cast
operator|<
name|SymbolBody
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|nullptr
operator|)
operator|)
operator|==
name|nullptr
operator|&&
literal|"Not a SymbolBody"
argument_list|)
block|;
name|new
argument_list|(
argument|S->Body.buffer
argument_list|)
name|T
argument_list|(
name|std
operator|::
name|forward
operator|<
name|ArgT
operator|>
operator|(
name|Arg
operator|)
operator|...
argument_list|)
block|;
comment|// Print out a log message if --trace-symbol was specified.
comment|// This is for debugging.
if|if
condition|(
name|S
operator|->
name|Traced
condition|)
name|printTraceSymbol
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|Symbol
operator|*
name|SymbolBody
operator|::
name|symbol
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|isLocal
argument_list|()
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|Symbol
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|this
operator|)
operator|-
name|offsetof
argument_list|(
name|Symbol
argument_list|,
name|Body
argument_list|)
operator|)
return|;
block|}
expr|}
comment|// namespace elf
name|std
operator|::
name|string
name|toString
argument_list|(
specifier|const
name|elf
operator|::
name|SymbolBody
operator|&
name|B
argument_list|)
block|; }
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

