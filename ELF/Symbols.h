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
comment|// File-scope symbols in ELF objects are the only exception of SymbolBody
end_comment

begin_comment
comment|// instantiation. We will never create SymbolBodies for them for performance
end_comment

begin_comment
comment|// reason. They are often represented as nullptrs. This is fine for symbol
end_comment

begin_comment
comment|// resolution because the symbol table naturally cares only about
end_comment

begin_comment
comment|// externally-visible symbols. For relocations, you have to deal with both
end_comment

begin_comment
comment|// local and non-local functions, and we have two different functions
end_comment

begin_comment
comment|// where we need them.
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

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf2
block|{
name|class
name|ArchiveFile
decl_stmt|;
name|class
name|InputFile
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
comment|// Initializes global objects defined in this file.
comment|// Called at the beginning of main().
name|void
name|initSymbols
parameter_list|()
function_decl|;
comment|// A real symbol object, SymbolBody, is usually accessed indirectly
comment|// through a Symbol. There's always one Symbol for each symbol name.
comment|// The resolver updates SymbolBody pointers as it resolves symbols.
struct|struct
name|Symbol
block|{
name|SymbolBody
modifier|*
name|Body
decl_stmt|;
block|}
struct|;
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
name|DefinedElfLast
init|=
name|SharedKind
block|,
name|DefinedCommonKind
block|,
name|DefinedSyntheticKind
block|,
name|DefinedLast
init|=
name|DefinedSyntheticKind
block|,
name|UndefinedElfKind
block|,
name|UndefinedKind
block|,
name|LazyKind
block|}
enum|;
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
name|isWeak
argument_list|()
specifier|const
block|{
return|return
name|IsWeak
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
operator|||
name|SymbolKind
operator|==
name|UndefinedElfKind
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
name|LazyKind
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
name|isUsedInRegularObj
argument_list|()
specifier|const
block|{
return|return
name|IsUsedInRegularObj
return|;
block|}
name|bool
name|isUsedInDynamicReloc
argument_list|()
specifier|const
block|{
return|return
name|IsUsedInDynamicReloc
return|;
block|}
name|void
name|setUsedInDynamicReloc
parameter_list|()
block|{
name|IsUsedInDynamicReloc
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|isTls
argument_list|()
specifier|const
block|{
return|return
name|IsTls
return|;
block|}
comment|// Returns the symbol name.
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
name|Visibility
return|;
block|}
name|unsigned
name|DynamicSymbolTableIndex
init|=
literal|0
decl_stmt|;
name|uint32_t
name|GlobalDynIndex
init|=
operator|-
literal|1
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
name|bool
name|hasGlobalDynIndex
parameter_list|()
block|{
return|return
name|GlobalDynIndex
operator|!=
name|uint32_t
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
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
name|isInGotPlt
argument_list|()
specifier|const
block|{
return|return
name|GotPltIndex
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
comment|// A SymbolBody has a backreference to a Symbol. Originally they are
comment|// doubly-linked. A backreference will never change. But the pointer
comment|// in the Symbol may be mutated by the resolver. If you have a
comment|// pointer P to a SymbolBody and are not sure whether the resolver
comment|// has chosen the object among other objects having the same name,
comment|// you can access P->Backref->Body to get the resolver's result.
name|void
name|setBackref
parameter_list|(
name|Symbol
modifier|*
name|P
parameter_list|)
block|{
name|Backref
operator|=
name|P
expr_stmt|;
block|}
name|SymbolBody
modifier|*
name|repl
parameter_list|()
block|{
return|return
name|Backref
condition|?
name|Backref
operator|->
name|Body
else|:
name|this
return|;
block|}
comment|// Decides which symbol should "win" in the symbol table, this or
comment|// the Other. Returns 1 if this wins, -1 if the Other wins, or 0 if
comment|// they are duplicate (conflicting) symbols.
name|template
operator|<
name|class
name|ELFT
operator|>
name|int
name|compare
argument_list|(
name|SymbolBody
operator|*
name|Other
argument_list|)
expr_stmt|;
name|protected
label|:
name|SymbolBody
argument_list|(
argument|Kind K
argument_list|,
argument|StringRef Name
argument_list|,
argument|bool IsWeak
argument_list|,
argument|uint8_t Visibility
argument_list|,
argument|bool IsTls
argument_list|)
block|:
name|SymbolKind
argument_list|(
name|K
argument_list|)
operator|,
name|IsWeak
argument_list|(
name|IsWeak
argument_list|)
operator|,
name|Visibility
argument_list|(
name|Visibility
argument_list|)
operator|,
name|IsTls
argument_list|(
name|IsTls
argument_list|)
operator|,
name|Name
argument_list|(
argument|Name
argument_list|)
block|{
name|IsUsedInRegularObj
operator|=
name|K
operator|!=
name|SharedKind
operator|&&
name|K
operator|!=
name|LazyKind
block|;
name|IsUsedInDynamicReloc
operator|=
literal|0
block|;   }
specifier|const
name|unsigned
name|SymbolKind
operator|:
literal|8
expr_stmt|;
name|unsigned
name|IsWeak
range|:
literal|1
decl_stmt|;
name|unsigned
name|Visibility
range|:
literal|2
decl_stmt|;
comment|// True if the symbol was used for linking and thus need to be
comment|// added to the output file's symbol table. It is usually true,
comment|// but if it is a shared symbol that were not referenced by anyone,
comment|// it can be false.
name|unsigned
name|IsUsedInRegularObj
range|:
literal|1
decl_stmt|;
comment|// If true, the symbol is added to .dynsym symbol table.
name|unsigned
name|IsUsedInDynamicReloc
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsTls
range|:
literal|1
decl_stmt|;
name|StringRef
name|Name
decl_stmt|;
name|Symbol
modifier|*
name|Backref
init|=
name|nullptr
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
argument|StringRef Name
argument_list|,
argument|bool IsWeak
argument_list|,
argument|uint8_t Visibility
argument_list|,
argument|bool IsTls
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
comment|// Any defined symbol from an ELF file.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DefinedElf
operator|:
name|public
name|Defined
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
name|Elf_Sym
name|Elf_Sym
expr_stmt|;
name|public
operator|:
name|DefinedElf
argument_list|(
argument|Kind K
argument_list|,
argument|StringRef N
argument_list|,
argument|const Elf_Sym&Sym
argument_list|)
operator|:
name|Defined
argument_list|(
name|K
argument_list|,
name|N
argument_list|,
name|Sym
operator|.
name|getBinding
argument_list|()
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STB_WEAK
argument_list|,
name|Sym
operator|.
name|getVisibility
argument_list|()
argument_list|,
name|Sym
operator|.
name|getType
argument_list|()
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_TLS
argument_list|)
block|,
name|Sym
argument_list|(
argument|Sym
argument_list|)
block|{}
specifier|const
name|Elf_Sym
operator|&
name|Sym
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
operator|<=
name|DefinedElfLast
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
argument|bool IsWeak
argument_list|,
argument|uint8_t Visibility
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
name|OffsetInBSS
block|;
comment|// The maximum alignment we have seen for this symbol.
name|uint64_t
name|MaxAlignment
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
name|DefinedElf
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
name|Elf_Sym
name|Elf_Sym
expr_stmt|;
name|public
operator|:
name|DefinedRegular
argument_list|(
argument|StringRef N
argument_list|,
argument|const Elf_Sym&Sym
argument_list|,
argument|InputSectionBase<ELFT> *Section
argument_list|)
operator|:
name|DefinedElf
operator|<
name|ELFT
operator|>
operator|(
name|SymbolBody
operator|::
name|DefinedRegularKind
block|,
name|N
block|,
name|Sym
operator|)
block|,
name|Section
argument_list|(
argument|Section
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
comment|// If this is null, the symbol is absolute.
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|Section
block|; }
decl_stmt|;
comment|// DefinedSynthetic is a class to represent linker-generated ELF symbols.
comment|// The difference from the regular symbol is that DefinedSynthetic symbols
comment|// don't belong to any input files or sections. Thus, its constructor
comment|// takes an output section to calculate output VA, etc.
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
name|DefinedSynthetic
argument_list|(
argument|StringRef N
argument_list|,
argument|uintX_t Value
argument_list|,
argument|OutputSectionBase<ELFT>&Section
argument_list|)
empty_stmt|;
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
name|uintX_t
name|Value
decl_stmt|;
specifier|const
name|OutputSectionBase
operator|<
name|ELFT
operator|>
operator|&
name|Section
expr_stmt|;
block|}
empty_stmt|;
comment|// Undefined symbol.
name|class
name|Undefined
range|:
name|public
name|SymbolBody
block|{
typedef|typedef
name|SymbolBody
operator|::
name|Kind
name|Kind
expr_stmt|;
name|bool
name|CanKeepUndefined
decl_stmt|;
name|protected
label|:
name|Undefined
argument_list|(
argument|Kind K
argument_list|,
argument|StringRef N
argument_list|,
argument|bool IsWeak
argument_list|,
argument|uint8_t Visibility
argument_list|,
argument|bool IsTls
argument_list|)
empty_stmt|;
name|public
label|:
name|Undefined
argument_list|(
argument|StringRef N
argument_list|,
argument|bool IsWeak
argument_list|,
argument|uint8_t Visibility
argument_list|,
argument|bool CanKeepUndefined
argument_list|)
empty_stmt|;
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
name|isUndefined
argument_list|()
return|;
block|}
name|bool
name|canKeepUndefined
argument_list|()
specifier|const
block|{
return|return
name|CanKeepUndefined
return|;
block|}
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
name|UndefinedElf
operator|:
name|public
name|Undefined
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
name|Elf_Sym
name|Elf_Sym
expr_stmt|;
name|public
operator|:
name|UndefinedElf
argument_list|(
argument|StringRef N
argument_list|,
argument|const Elf_Sym&Sym
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|Elf_Sym
modifier|&
name|Sym
decl_stmt|;
end_decl_stmt

begin_function
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
name|UndefinedElfKind
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SharedSymbol
operator|:
name|public
name|DefinedElf
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
name|Elf_Sym
name|Elf_Sym
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

begin_label
name|public
label|:
end_label

begin_function
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
end_function

begin_macro
name|SharedSymbol
argument_list|(
argument|SharedFile<ELFT> *F
argument_list|,
argument|StringRef Name
argument_list|,
argument|const Elf_Sym&Sym
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|DefinedElf
operator|<
name|ELFT
operator|>
operator|(
name|SymbolBody
operator|::
name|SharedKind
operator|,
name|Name
operator|,
name|Sym
operator|)
operator|,
name|File
argument_list|(
argument|F
argument_list|)
block|{}
name|SharedFile
operator|<
name|ELFT
operator|>
operator|*
name|File
expr_stmt|;
end_expr_stmt

begin_comment
comment|// True if the linker has to generate a copy relocation for this shared
end_comment

begin_comment
comment|// symbol. OffsetInBSS is significant only when NeedsCopy is true.
end_comment

begin_decl_stmt
name|bool
name|NeedsCopy
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintX_t
name|OffsetInBSS
init|=
literal|0
decl_stmt|;
end_decl_stmt

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
name|Lazy
argument_list|(
argument|ArchiveFile *F
argument_list|,
argument|const llvm::object::Archive::Symbol S
argument_list|)
operator|:
name|SymbolBody
argument_list|(
name|LazyKind
argument_list|,
name|S
operator|.
name|getName
argument_list|()
argument_list|,
name|false
argument_list|,
name|llvm
operator|::
name|ELF
operator|::
name|STV_DEFAULT
argument_list|,
name|false
argument_list|)
block|,
name|File
argument_list|(
name|F
argument_list|)
block|,
name|Sym
argument_list|(
argument|S
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
name|LazyKind
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
name|getMember
argument_list|()
block|;
name|void
name|setWeak
argument_list|()
block|{
name|IsWeak
operator|=
name|true
block|; }
name|void
name|setUsedInRegularObj
argument_list|()
block|{
name|IsUsedInRegularObj
operator|=
name|true
block|; }
name|private
operator|:
name|ArchiveFile
operator|*
name|File
block|;
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
comment|// Some linker-generated symbols need to be created as
end_comment

begin_comment
comment|// DefinedRegular symbols, so they need Elf_Sym symbols.
end_comment

begin_comment
comment|// Here we allocate such Elf_Sym symbols statically.
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
comment|// Used to represent an undefined symbol which we don't want
comment|// to add to the output file's symbol table.
specifier|static
name|Elf_Sym
name|IgnoreUndef
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The content for _end and end symbols.
end_comment

begin_decl_stmt
specifier|static
name|Elf_Sym
name|End
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The content for _gp symbol for MIPS target.
end_comment

begin_decl_stmt
specifier|static
name|Elf_Sym
name|MipsGp
decl_stmt|;
end_decl_stmt

begin_comment
comment|// __rel_iplt_start/__rel_iplt_end for signaling
end_comment

begin_comment
comment|// where R_[*]_IRELATIVE relocations do live.
end_comment

begin_decl_stmt
specifier|static
name|Elf_Sym
name|RelaIpltStart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Elf_Sym
name|RelaIpltEnd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|typename
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|IgnoreUndef
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|typename
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
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
name|typename
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|MipsGp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|typename
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|RelaIpltStart
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|typename
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
name|ElfSym
operator|<
name|ELFT
operator|>
operator|::
name|RelaIpltEnd
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
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

