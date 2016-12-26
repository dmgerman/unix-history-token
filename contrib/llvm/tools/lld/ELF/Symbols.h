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

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
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
name|class
name|SymbolBody
decl_stmt|;
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
name|DefinedBitcodeKind
block|,
name|DefinedSyntheticKind
block|,
name|DefinedLast
init|=
name|DefinedSyntheticKind
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
expr_stmt|;
name|void
name|setName
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
name|uint32_t
name|getNameOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isLocal
argument_list|()
argument_list|)
block|;
return|return
name|NameOffset
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
name|unsigned
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
name|template
operator|<
name|class
name|ELFT
operator|>
name|bool
name|hasThunk
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
name|getVA
argument_list|(
argument|typename ELFT::uint Addend =
literal|0
argument_list|)
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
name|getGotOffset
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
name|getGotVA
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
name|getGotPltOffset
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
name|getGotPltVA
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
name|getThunkVA
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
comment|// The file from which this symbol was created.
name|InputFile
modifier|*
name|File
init|=
name|nullptr
decl_stmt|;
name|protected
label|:
name|SymbolBody
argument_list|(
argument|Kind K
argument_list|,
argument|StringRef Name
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|)
empty_stmt|;
name|SymbolBody
argument_list|(
argument|Kind K
argument_list|,
argument|uint32_t NameOffset
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
comment|// True if the linker has to generate a copy relocation for this shared
comment|// symbol or if the symbol should point to its plt entry.
name|unsigned
name|NeedsCopyOrPltAddr
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
struct|struct
name|Str
block|{
specifier|const
name|char
modifier|*
name|S
decl_stmt|;
name|size_t
name|Len
decl_stmt|;
block|}
struct|;
union|union
block|{
name|Str
name|Name
decl_stmt|;
name|uint32_t
name|NameOffset
decl_stmt|;
block|}
union|;
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
argument|StringRef Name
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|)
block|;
name|Defined
argument_list|(
argument|Kind K
argument_list|,
argument|uint32_t NameOffset
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
comment|// The defined symbol in LLVM bitcode files.
name|class
name|DefinedBitcode
operator|:
name|public
name|Defined
block|{
name|public
operator|:
name|DefinedBitcode
argument_list|(
argument|StringRef Name
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|,
argument|BitcodeFile *F
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|SymbolBody
operator|*
name|S
argument_list|)
block|;
name|BitcodeFile
operator|*
name|file
argument_list|()
block|{
return|return
operator|(
name|BitcodeFile
operator|*
operator|)
name|this
operator|->
name|File
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
argument|uint64_t Alignment
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
name|OffsetInBss
block|;
comment|// The maximum alignment we have seen for this symbol.
name|uint64_t
name|Alignment
block|;
name|uint64_t
name|Size
block|; }
block|;
comment|// Regular defined symbols read from object file symbol tables.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DefinedRegular
operator|:
name|public
name|Defined
block|{
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
name|public
operator|:
name|DefinedRegular
argument_list|(
argument|StringRef Name
argument_list|,
argument|const Elf_Sym&Sym
argument_list|,
argument|InputSectionBase<ELFT> *Section
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
name|Sym
operator|.
name|st_other
argument_list|,
name|Sym
operator|.
name|getType
argument_list|()
argument_list|)
block|,
name|Value
argument_list|(
name|Sym
operator|.
name|st_value
argument_list|)
block|,
name|Size
argument_list|(
name|Sym
operator|.
name|st_size
argument_list|)
block|,
name|Section
argument_list|(
argument|Section ? Section->Repl : NullInputSection
argument_list|)
block|{
if|if
condition|(
name|Section
condition|)
name|this
operator|->
name|File
operator|=
name|Section
operator|->
name|getFile
argument_list|()
expr_stmt|;
block|}
name|DefinedRegular
argument_list|(
specifier|const
name|Elf_Sym
operator|&
name|Sym
argument_list|,
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|Section
argument_list|)
operator|:
name|Defined
argument_list|(
name|SymbolBody
operator|::
name|DefinedRegularKind
argument_list|,
name|Sym
operator|.
name|st_name
argument_list|,
name|Sym
operator|.
name|st_other
argument_list|,
name|Sym
operator|.
name|getType
argument_list|()
argument_list|)
block|,
name|Value
argument_list|(
name|Sym
operator|.
name|st_value
argument_list|)
block|,
name|Size
argument_list|(
name|Sym
operator|.
name|st_size
argument_list|)
block|,
name|Section
argument_list|(
argument|Section ? Section->Repl : NullInputSection
argument_list|)
block|{
name|assert
argument_list|(
name|isLocal
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|Section
condition|)
name|this
operator|->
name|File
operator|=
name|Section
operator|->
name|getFile
argument_list|()
expr_stmt|;
block|}
name|DefinedRegular
argument_list|(
argument|StringRef Name
argument_list|,
argument|uint8_t StOther
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
name|StOther
argument_list|,
name|llvm
operator|::
name|ELF
operator|::
name|STT_NOTYPE
argument_list|)
block|,
name|Value
argument_list|(
literal|0
argument_list|)
block|,
name|Size
argument_list|(
literal|0
argument_list|)
block|,
name|Section
argument_list|(
argument|NullInputSection
argument_list|)
block|{}
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
name|uintX_t
name|Value
block|;
name|uintX_t
name|Size
block|;
comment|// The input section this symbol belongs to. Notice that this is
comment|// a reference to a pointer. We are using two levels of indirections
comment|// because of ICF. If ICF decides two sections need to be merged, it
comment|// manipulates this Section pointers so that they point to the same
comment|// section. This is a bit tricky, so be careful to not be confused.
comment|// If this is null, the symbol is an absolute symbol.
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
operator|&
name|Section
block|;
comment|// If non-null the symbol has a Thunk that may be used as an alternative
comment|// destination for callers of this Symbol.
name|Thunk
operator|<
name|ELFT
operator|>
operator|*
name|ThunkData
operator|=
name|nullptr
block|;
name|private
operator|:
specifier|static
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|NullInputSection
block|; }
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|::
name|NullInputSection
expr_stmt|;
comment|// DefinedSynthetic is a class to represent linker-generated ELF symbols.
comment|// The difference from the regular symbol is that DefinedSynthetic symbols
comment|// don't belong to any input files or sections. Thus, its constructor
comment|// takes an output section to calculate output VA, etc.
comment|// If Section is null, this symbol is relative to the image base.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DefinedSynthetic
operator|:
name|public
name|Defined
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
name|DefinedSynthetic
argument_list|(
argument|StringRef N
argument_list|,
argument|uintX_t Value
argument_list|,
argument|OutputSectionBase<ELFT> *Section
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|SymbolBody
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|SymbolBody
operator|::
name|DefinedSyntheticKind
return|;
block|}
comment|// Special value designates that the symbol 'points'
comment|// to the end of the section.
specifier|static
specifier|const
name|uintX_t
name|SectionEnd
init|=
name|uintX_t
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
name|uintX_t
name|Value
decl_stmt|;
specifier|const
name|OutputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|Section
expr_stmt|;
block|}
empty_stmt|;
name|class
name|Undefined
range|:
name|public
name|SymbolBody
block|{
name|public
operator|:
name|Undefined
argument_list|(
argument|StringRef Name
argument_list|,
argument|uint8_t StOther
argument_list|,
argument|uint8_t Type
argument_list|,
argument|InputFile *F
argument_list|)
block|;
name|Undefined
argument_list|(
argument|uint32_t NameOffset
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
name|InputFile
operator|*
name|file
argument_list|()
block|{
return|return
name|this
operator|->
name|File
return|;
block|}
expr|}
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SharedSymbol
operator|:
name|public
name|Defined
block|{
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
name|Verdef
name|Elf_Verdef
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
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|SymbolBody
modifier|*
name|S
parameter_list|)
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
argument|SharedFile<ELFT> *F
argument_list|,
argument|StringRef Name
argument_list|,
argument|const Elf_Sym&Sym
argument_list|,
argument|const Elf_Verdef *Verdef
argument_list|)
block|:
name|Defined
argument_list|(
name|SymbolBody
operator|::
name|SharedKind
argument_list|,
name|Name
argument_list|,
name|Sym
operator|.
name|st_other
argument_list|,
name|Sym
operator|.
name|getType
argument_list|()
argument_list|)
operator|,
name|Sym
argument_list|(
name|Sym
argument_list|)
operator|,
name|Verdef
argument_list|(
argument|Verdef
argument_list|)
block|{
comment|// IFuncs defined in DSOs are treated as functions by the static linker.
if|if
condition|(
name|isGnuIFunc
argument_list|()
condition|)
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
name|F
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|SharedFile
operator|<
name|ELFT
operator|>
operator|*
name|file
argument_list|()
block|{
return|return
operator|(
name|SharedFile
operator|<
name|ELFT
operator|>
operator|*
operator|)
name|this
operator|->
name|File
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|const
name|Elf_Sym
modifier|&
name|Sym
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This field is a pointer to the symbol's version definition.
end_comment

begin_decl_stmt
specifier|const
name|Elf_Verdef
modifier|*
name|Verdef
decl_stmt|;
end_decl_stmt

begin_comment
comment|// OffsetInBss is significant only when needsCopy() is true.
end_comment

begin_decl_stmt
name|uintX_t
name|OffsetInBss
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If non-null the symbol has a Thunk that may be used as an alternative
end_comment

begin_comment
comment|// destination for callers of this Symbol.
end_comment

begin_expr_stmt
name|Thunk
operator|<
name|ELFT
operator|>
operator|*
name|ThunkData
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|needsCopy
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|NeedsCopyOrPltAddr
operator|&&
operator|!
name|this
operator|->
name|isFunc
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// This class represents a symbol defined in an archive file. It is
end_comment

begin_comment
comment|// created from an archive file header, and it knows how to load an
end_comment

begin_comment
comment|// object file from an archive to replace itself with a defined
end_comment

begin_comment
comment|// symbol. If the resolver finds both Undefined and Lazy for
end_comment

begin_comment
comment|// the same name, it will ask the Lazy to load a file.
end_comment

begin_decl_stmt
name|class
name|Lazy
range|:
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
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>
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
argument|llvm::ELF::STV_DEFAULT
argument_list|,
argument|Type
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// LazyArchive symbols represents symbols in archive files.
end_comment

begin_decl_stmt
name|class
name|LazyArchive
range|:
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
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|// LazyObject symbols represents symbols in object files between
end_comment

begin_comment
comment|// --start-lib and --end-lib options.
end_comment

begin_decl_stmt
name|class
name|LazyObject
range|:
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
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>
name|fetch
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Some linker-generated symbols need to be created as
end_comment

begin_comment
comment|// DefinedRegular symbols.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|ElfSym
block|{
comment|// The content for _etext and etext symbols.
specifier|static
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|Etext
block|;
specifier|static
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|Etext2
block|;
comment|// The content for _edata and edata symbols.
specifier|static
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|Edata
block|;
specifier|static
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|Edata2
block|;
comment|// The content for _end and end symbols.
specifier|static
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|End
block|;
specifier|static
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|End2
block|;
comment|// The content for _gp_disp symbol for MIPS target.
specifier|static
name|SymbolBody
operator|*
name|MipsGpDisp
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Etext
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Etext2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Edata
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Edata2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|End
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|DefinedRegular
operator|<
name|ELFT
operator|>
operator|*
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|End2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|SymbolBody
operator|*
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|MipsGpDisp
expr_stmt|;
end_expr_stmt

begin_comment
comment|// A real symbol object, SymbolBody, is usually stored within a Symbol. There's
end_comment

begin_comment
comment|// always one Symbol for each symbol name. The resolver updates the SymbolBody
end_comment

begin_comment
comment|// stored in the Body field of this object as it resolves symbols. Symbol also
end_comment

begin_comment
comment|// holds computed properties of symbol names.
end_comment

begin_struct
struct|struct
name|Symbol
block|{
comment|// Symbol binding. This is on the Symbol to track changes during resolution.
comment|// In particular:
comment|// An undefined weak is still weak when it resolves to a shared library.
comment|// An undefined weak will not fetch archive members, but we have to remember
comment|// it is weak.
name|uint8_t
name|Binding
decl_stmt|;
comment|// Version definition index.
name|uint16_t
name|VersionId
decl_stmt|;
comment|// Symbol visibility. This is the computed minimum visibility of all
comment|// observed non-DSO symbols.
name|unsigned
name|Visibility
range|:
literal|2
decl_stmt|;
comment|// True if the symbol was used for linking and thus need to be added to the
comment|// output file's symbol table. This is true for all symbols except for
comment|// unreferenced DSO symbols and bitcode symbols that are unreferenced except
comment|// by other bitcode objects.
name|unsigned
name|IsUsedInRegularObj
range|:
literal|1
decl_stmt|;
comment|// If this flag is true and the symbol has protected or default visibility, it
comment|// will appear in .dynsym. This flag is set by interposable DSO symbols in
comment|// executables, by most symbols in DSOs and executables built with
comment|// --export-dynamic, and by dynamic lists.
name|unsigned
name|ExportDynamic
range|:
literal|1
decl_stmt|;
comment|// True if this symbol is specified by --trace-symbol option.
name|unsigned
name|Traced
range|:
literal|1
decl_stmt|;
name|bool
name|includeInDynsym
argument_list|()
specifier|const
expr_stmt|;
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
comment|// large and aligned enough to store any derived class of SymbolBody. We
comment|// assume that the size and alignment of ELF64LE symbols is sufficient for any
comment|// ELFT, and we verify this with the static_asserts in replaceBody.
name|llvm
operator|::
name|AlignedCharArrayUnion
operator|<
name|DefinedBitcode
operator|,
name|DefinedCommon
operator|,
name|DefinedRegular
operator|<
name|llvm
operator|::
name|object
operator|::
name|ELF64LE
operator|>
operator|,
name|DefinedSynthetic
operator|<
name|llvm
operator|::
name|object
operator|::
name|ELF64LE
operator|>
operator|,
name|Undefined
operator|,
name|SharedSymbol
operator|<
name|llvm
operator|::
name|object
operator|::
name|ELF64LE
operator|>
operator|,
name|LazyArchive
operator|,
name|LazyObject
operator|>
name|Body
expr_stmt|;
name|SymbolBody
modifier|*
name|body
parameter_list|()
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
block|}
struct|;
end_struct

begin_function_decl
name|void
name|printTraceSymbol
parameter_list|(
name|Symbol
modifier|*
name|Sym
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
name|llvm
operator|::
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
operator|<=
name|llvm
operator|::
name|AlignOf
operator|<
name|decltype
argument_list|(
name|S
operator|->
name|Body
argument_list|)
operator|>
operator|::
name|Alignment
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
end_expr_stmt

begin_expr_stmt
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

