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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_COFF_SYMBOLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_SYMBOLS_H
end_define

begin_include
include|#
directive|include
file|"Chunks.h"
end_include

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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Archive.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/COFF.h"
end_include

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
block|{
name|using
name|llvm
operator|::
name|object
operator|::
name|Archive
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|COFFSymbolRef
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|coff_import_header
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|coff_symbol_generic
expr_stmt|;
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
name|ObjectFile
decl_stmt|;
name|class
name|SymbolBody
decl_stmt|;
comment|// A real symbol object, SymbolBody, is usually accessed indirectly
comment|// through a Symbol. There's always one Symbol for each symbol name.
comment|// The resolver updates SymbolBody pointers as it resolves symbols.
struct|struct
name|Symbol
block|{
name|explicit
name|Symbol
argument_list|(
name|SymbolBody
operator|*
name|P
argument_list|)
operator|:
name|Body
argument_list|(
argument|P
argument_list|)
block|{}
name|SymbolBody
operator|*
name|Body
expr_stmt|;
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
comment|// The order of these is significant. We start with the regular defined
comment|// symbols as those are the most prevelant and the zero tag is the cheapest
comment|// to set. Among the defined kinds, the lower the kind is preferred over
comment|// the higher kind when testing wether one symbol should take precedence
comment|// over another.
name|DefinedRegularKind
init|=
literal|0
block|,
name|DefinedCommonKind
block|,
name|DefinedLocalImportKind
block|,
name|DefinedImportThunkKind
block|,
name|DefinedImportDataKind
block|,
name|DefinedAbsoluteKind
block|,
name|DefinedRelativeKind
block|,
name|DefinedBitcodeKind
block|,
name|UndefinedKind
block|,
name|LazyKind
block|,
name|LastDefinedCOFFKind
init|=
name|DefinedCommonKind
block|,
name|LastDefinedKind
init|=
name|DefinedBitcodeKind
block|,   }
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
comment|// Returns true if this is an external symbol.
name|bool
name|isExternal
parameter_list|()
block|{
return|return
name|IsExternal
return|;
block|}
comment|// Returns the symbol name.
name|StringRef
name|getName
parameter_list|()
function_decl|;
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
name|int
name|compare
parameter_list|(
name|SymbolBody
modifier|*
name|Other
parameter_list|)
function_decl|;
comment|// Returns a name of this symbol including source file name.
comment|// Used only for debugging and logging.
name|std
operator|::
name|string
name|getDebugName
argument_list|()
expr_stmt|;
name|protected
label|:
name|explicit
name|SymbolBody
argument_list|(
argument|Kind K
argument_list|,
argument|StringRef N =
literal|""
argument_list|)
block|:
name|SymbolKind
argument_list|(
name|K
argument_list|)
operator|,
name|IsExternal
argument_list|(
name|true
argument_list|)
operator|,
name|IsCOMDAT
argument_list|(
name|false
argument_list|)
operator|,
name|IsReplaceable
argument_list|(
name|false
argument_list|)
operator|,
name|Name
argument_list|(
argument|N
argument_list|)
block|{}
specifier|const
name|unsigned
name|SymbolKind
operator|:
literal|8
expr_stmt|;
name|unsigned
name|IsExternal
range|:
literal|1
decl_stmt|;
comment|// This bit is used by the \c DefinedRegular subclass.
name|unsigned
name|IsCOMDAT
range|:
literal|1
decl_stmt|;
comment|// This bit is used by the \c DefinedBitcode subclass.
name|unsigned
name|IsReplaceable
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
comment|// The base class for any defined symbols, including absolute symbols,
comment|// etc.
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
argument|StringRef N =
literal|""
argument_list|)
operator|:
name|SymbolBody
argument_list|(
argument|K
argument_list|,
argument|N
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
operator|<=
name|LastDefinedKind
return|;
block|}
comment|// Returns the RVA (relative virtual address) of this symbol. The
comment|// writer sets and uses RVAs.
name|uint64_t
name|getRVA
argument_list|()
block|;
comment|// Returns the RVA relative to the beginning of the output section.
comment|// Used to implement SECREL relocation type.
name|uint64_t
name|getSecrel
argument_list|()
block|;
comment|// Returns the output section index.
comment|// Used to implement SECTION relocation type.
name|uint64_t
name|getSectionIndex
argument_list|()
block|;
comment|// Returns true if this symbol points to an executable (e.g. .text) section.
comment|// Used to implement ARM relocations.
name|bool
name|isExecutable
argument_list|()
block|; }
decl_stmt|;
comment|// Symbols defined via a COFF object file.
name|class
name|DefinedCOFF
range|:
name|public
name|Defined
block|{
name|friend
name|SymbolBody
block|;
name|public
operator|:
name|DefinedCOFF
argument_list|(
argument|Kind K
argument_list|,
argument|ObjectFile *F
argument_list|,
argument|COFFSymbolRef S
argument_list|)
operator|:
name|Defined
argument_list|(
name|K
argument_list|)
block|,
name|File
argument_list|(
name|F
argument_list|)
block|,
name|Sym
argument_list|(
argument|S.getGeneric()
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
operator|<=
name|LastDefinedCOFFKind
return|;
block|}
name|int
name|getFileIndex
argument_list|()
block|{
return|return
name|File
operator|->
name|Index
return|;
block|}
name|COFFSymbolRef
name|getCOFFSymbol
argument_list|()
block|;
name|protected
operator|:
name|ObjectFile
operator|*
name|File
block|;
specifier|const
name|coff_symbol_generic
operator|*
name|Sym
block|; }
decl_stmt|;
comment|// Regular defined symbols read from object file symbol tables.
name|class
name|DefinedRegular
range|:
name|public
name|DefinedCOFF
block|{
name|public
operator|:
name|DefinedRegular
argument_list|(
argument|ObjectFile *F
argument_list|,
argument|COFFSymbolRef S
argument_list|,
argument|SectionChunk *C
argument_list|)
operator|:
name|DefinedCOFF
argument_list|(
name|DefinedRegularKind
argument_list|,
name|F
argument_list|,
name|S
argument_list|)
block|,
name|Data
argument_list|(
argument|&C->Repl
argument_list|)
block|{
name|IsExternal
operator|=
name|S
operator|.
name|isExternal
argument_list|()
block|;
name|IsCOMDAT
operator|=
name|C
operator|->
name|isCOMDAT
argument_list|()
block|;   }
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
name|DefinedRegularKind
return|;
block|}
name|uint64_t
name|getRVA
argument_list|()
block|{
return|return
operator|(
operator|*
name|Data
operator|)
operator|->
name|getRVA
argument_list|()
operator|+
name|Sym
operator|->
name|Value
return|;
block|}
name|bool
name|isCOMDAT
argument_list|()
block|{
return|return
name|IsCOMDAT
return|;
block|}
name|SectionChunk
operator|*
name|getChunk
argument_list|()
block|{
return|return
operator|*
name|Data
return|;
block|}
name|uint32_t
name|getValue
argument_list|()
block|{
return|return
name|Sym
operator|->
name|Value
return|;
block|}
name|private
operator|:
name|SectionChunk
operator|*
operator|*
name|Data
block|; }
decl_stmt|;
name|class
name|DefinedCommon
range|:
name|public
name|DefinedCOFF
block|{
name|public
operator|:
name|DefinedCommon
argument_list|(
argument|ObjectFile *F
argument_list|,
argument|COFFSymbolRef S
argument_list|,
argument|CommonChunk *C
argument_list|)
operator|:
name|DefinedCOFF
argument_list|(
name|DefinedCommonKind
argument_list|,
name|F
argument_list|,
name|S
argument_list|)
block|,
name|Data
argument_list|(
argument|C
argument_list|)
block|{
name|IsExternal
operator|=
name|S
operator|.
name|isExternal
argument_list|()
block|;   }
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
name|DefinedCommonKind
return|;
block|}
name|uint64_t
name|getRVA
argument_list|()
block|{
return|return
name|Data
operator|->
name|getRVA
argument_list|()
return|;
block|}
name|private
operator|:
name|friend
name|SymbolBody
block|;
name|uint64_t
name|getSize
argument_list|()
block|{
return|return
name|Sym
operator|->
name|Value
return|;
block|}
name|CommonChunk
operator|*
name|Data
block|; }
decl_stmt|;
comment|// Absolute symbols.
name|class
name|DefinedAbsolute
range|:
name|public
name|Defined
block|{
name|public
operator|:
name|DefinedAbsolute
argument_list|(
argument|StringRef N
argument_list|,
argument|COFFSymbolRef S
argument_list|)
operator|:
name|Defined
argument_list|(
name|DefinedAbsoluteKind
argument_list|,
name|N
argument_list|)
block|,
name|VA
argument_list|(
argument|S.getValue()
argument_list|)
block|{
name|IsExternal
operator|=
name|S
operator|.
name|isExternal
argument_list|()
block|;   }
name|DefinedAbsolute
argument_list|(
argument|StringRef N
argument_list|,
argument|uint64_t V
argument_list|)
operator|:
name|Defined
argument_list|(
name|DefinedAbsoluteKind
argument_list|,
name|N
argument_list|)
block|,
name|VA
argument_list|(
argument|V
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
name|DefinedAbsoluteKind
return|;
block|}
name|uint64_t
name|getRVA
argument_list|()
block|{
return|return
name|VA
operator|-
name|Config
operator|->
name|ImageBase
return|;
block|}
name|void
name|setVA
argument_list|(
argument|uint64_t V
argument_list|)
block|{
name|VA
operator|=
name|V
block|; }
name|private
operator|:
name|uint64_t
name|VA
block|; }
decl_stmt|;
comment|// This is a kind of absolute symbol but relative to the image base.
comment|// Unlike absolute symbols, relocations referring this kind of symbols
comment|// are subject of the base relocation. This type is used rarely --
comment|// mainly for __ImageBase.
name|class
name|DefinedRelative
range|:
name|public
name|Defined
block|{
name|public
operator|:
name|explicit
name|DefinedRelative
argument_list|(
argument|StringRef Name
argument_list|,
argument|uint64_t V =
literal|0
argument_list|)
operator|:
name|Defined
argument_list|(
name|DefinedRelativeKind
argument_list|,
name|Name
argument_list|)
block|,
name|RVA
argument_list|(
argument|V
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
name|DefinedRelativeKind
return|;
block|}
name|uint64_t
name|getRVA
argument_list|()
block|{
return|return
name|RVA
return|;
block|}
name|void
name|setRVA
argument_list|(
argument|uint64_t V
argument_list|)
block|{
name|RVA
operator|=
name|V
block|; }
name|private
operator|:
name|uint64_t
name|RVA
block|; }
decl_stmt|;
comment|// This class represents a symbol defined in an archive file. It is
comment|// created from an archive file header, and it knows how to load an
comment|// object file from an archive to replace itself with a defined
comment|// symbol. If the resolver finds both Undefined and Lazy for
comment|// the same name, it will ask the Lazy to load a file.
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
argument|const Archive::Symbol S
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
name|int
name|getFileIndex
argument_list|()
block|{
return|return
name|File
operator|->
name|Index
return|;
block|}
name|private
operator|:
name|ArchiveFile
operator|*
name|File
block|;
specifier|const
name|Archive
operator|::
name|Symbol
name|Sym
block|; }
decl_stmt|;
comment|// Undefined symbols.
name|class
name|Undefined
range|:
name|public
name|SymbolBody
block|{
name|public
operator|:
name|explicit
name|Undefined
argument_list|(
argument|StringRef N
argument_list|)
operator|:
name|SymbolBody
argument_list|(
argument|UndefinedKind
argument_list|,
argument|N
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
name|UndefinedKind
return|;
block|}
comment|// An undefined symbol can have a fallback symbol which gives an
comment|// undefined symbol a second chance if it would remain undefined.
comment|// If it remains undefined, it'll be replaced with whatever the
comment|// Alias pointer points to.
name|SymbolBody
operator|*
name|WeakAlias
operator|=
name|nullptr
block|;
comment|// If this symbol is external weak, try to resolve it to a defined
comment|// symbol by searching the chain of fallback symbols. Returns the symbol if
comment|// successful, otherwise returns null.
name|Defined
operator|*
name|getWeakAlias
argument_list|()
block|; }
decl_stmt|;
comment|// Windows-specific classes.
comment|// This class represents a symbol imported from a DLL. This has two
comment|// names for internal use and external use. The former is used for
comment|// name resolution, and the latter is used for the import descriptor
comment|// table in an output. The former has "__imp_" prefix.
name|class
name|DefinedImportData
range|:
name|public
name|Defined
block|{
name|public
operator|:
name|DefinedImportData
argument_list|(
argument|StringRef D
argument_list|,
argument|StringRef N
argument_list|,
argument|StringRef E
argument_list|,
argument|const coff_import_header *H
argument_list|)
operator|:
name|Defined
argument_list|(
name|DefinedImportDataKind
argument_list|,
name|N
argument_list|)
block|,
name|DLLName
argument_list|(
name|D
argument_list|)
block|,
name|ExternalName
argument_list|(
name|E
argument_list|)
block|,
name|Hdr
argument_list|(
argument|H
argument_list|)
block|{   }
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
name|DefinedImportDataKind
return|;
block|}
name|uint64_t
name|getRVA
argument_list|()
block|{
return|return
name|Location
operator|->
name|getRVA
argument_list|()
return|;
block|}
name|StringRef
name|getDLLName
argument_list|()
block|{
return|return
name|DLLName
return|;
block|}
name|StringRef
name|getExternalName
argument_list|()
block|{
return|return
name|ExternalName
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|Chunk *AddressTable
argument_list|)
block|{
name|Location
operator|=
name|AddressTable
block|; }
name|uint16_t
name|getOrdinal
argument_list|()
block|{
return|return
name|Hdr
operator|->
name|OrdinalHint
return|;
block|}
name|private
operator|:
name|StringRef
name|DLLName
block|;
name|StringRef
name|ExternalName
block|;
specifier|const
name|coff_import_header
operator|*
name|Hdr
block|;
name|Chunk
operator|*
name|Location
operator|=
name|nullptr
block|; }
decl_stmt|;
comment|// This class represents a symbol for a jump table entry which jumps
comment|// to a function in a DLL. Linker are supposed to create such symbols
comment|// without "__imp_" prefix for all function symbols exported from
comment|// DLLs, so that you can call DLL functions as regular functions with
comment|// a regular name. A function pointer is given as a DefinedImportData.
name|class
name|DefinedImportThunk
range|:
name|public
name|Defined
block|{
name|public
operator|:
name|DefinedImportThunk
argument_list|(
argument|StringRef Name
argument_list|,
argument|DefinedImportData *S
argument_list|,
argument|uint16_t Machine
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
name|DefinedImportThunkKind
return|;
block|}
name|uint64_t
name|getRVA
argument_list|()
block|{
return|return
name|Data
operator|->
name|getRVA
argument_list|()
return|;
block|}
name|Chunk
operator|*
name|getChunk
argument_list|()
block|{
return|return
name|Data
operator|.
name|get
argument_list|()
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|Chunk
operator|>
name|Data
block|; }
decl_stmt|;
comment|// If you have a symbol "__imp_foo" in your object file, a symbol name
comment|// "foo" becomes automatically available as a pointer to "__imp_foo".
comment|// This class is for such automatically-created symbols.
comment|// Yes, this is an odd feature. We didn't intend to implement that.
comment|// This is here just for compatibility with MSVC.
name|class
name|DefinedLocalImport
range|:
name|public
name|Defined
block|{
name|public
operator|:
name|DefinedLocalImport
argument_list|(
argument|StringRef N
argument_list|,
argument|Defined *S
argument_list|)
operator|:
name|Defined
argument_list|(
name|DefinedLocalImportKind
argument_list|,
name|N
argument_list|)
block|,
name|Data
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
name|DefinedLocalImportKind
return|;
block|}
name|uint64_t
name|getRVA
argument_list|()
block|{
return|return
name|Data
operator|.
name|getRVA
argument_list|()
return|;
block|}
name|Chunk
operator|*
name|getChunk
argument_list|()
block|{
return|return
operator|&
name|Data
return|;
block|}
name|private
operator|:
name|LocalImportChunk
name|Data
block|; }
decl_stmt|;
name|class
name|DefinedBitcode
range|:
name|public
name|Defined
block|{
name|friend
name|SymbolBody
block|;
name|public
operator|:
name|DefinedBitcode
argument_list|(
argument|BitcodeFile *F
argument_list|,
argument|StringRef N
argument_list|,
argument|bool IsReplaceable
argument_list|)
operator|:
name|Defined
argument_list|(
name|DefinedBitcodeKind
argument_list|,
name|N
argument_list|)
block|,
name|File
argument_list|(
argument|F
argument_list|)
block|{
name|this
operator|->
name|IsReplaceable
operator|=
name|IsReplaceable
block|;   }
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
name|DefinedBitcodeKind
return|;
block|}
name|private
operator|:
name|BitcodeFile
operator|*
name|File
block|; }
decl_stmt|;
specifier|inline
name|uint64_t
name|Defined
operator|::
name|getRVA
argument_list|()
block|{
switch|switch
condition|(
name|kind
argument_list|()
condition|)
block|{
case|case
name|DefinedAbsoluteKind
case|:
return|return
name|cast
operator|<
name|DefinedAbsolute
operator|>
operator|(
name|this
operator|)
operator|->
name|getRVA
argument_list|()
return|;
case|case
name|DefinedRelativeKind
case|:
return|return
name|cast
operator|<
name|DefinedRelative
operator|>
operator|(
name|this
operator|)
operator|->
name|getRVA
argument_list|()
return|;
case|case
name|DefinedImportDataKind
case|:
return|return
name|cast
operator|<
name|DefinedImportData
operator|>
operator|(
name|this
operator|)
operator|->
name|getRVA
argument_list|()
return|;
case|case
name|DefinedImportThunkKind
case|:
return|return
name|cast
operator|<
name|DefinedImportThunk
operator|>
operator|(
name|this
operator|)
operator|->
name|getRVA
argument_list|()
return|;
case|case
name|DefinedLocalImportKind
case|:
return|return
name|cast
operator|<
name|DefinedLocalImport
operator|>
operator|(
name|this
operator|)
operator|->
name|getRVA
argument_list|()
return|;
case|case
name|DefinedCommonKind
case|:
return|return
name|cast
operator|<
name|DefinedCommon
operator|>
operator|(
name|this
operator|)
operator|->
name|getRVA
argument_list|()
return|;
case|case
name|DefinedRegularKind
case|:
return|return
name|cast
operator|<
name|DefinedRegular
operator|>
operator|(
name|this
operator|)
operator|->
name|getRVA
argument_list|()
return|;
case|case
name|DefinedBitcodeKind
case|:
name|llvm_unreachable
argument_list|(
literal|"There is no address for a bitcode symbol."
argument_list|)
expr_stmt|;
case|case
name|LazyKind
case|:
case|case
name|UndefinedKind
case|:
name|llvm_unreachable
argument_list|(
literal|"Cannot get the address for an undefined symbol."
argument_list|)
expr_stmt|;
block|}
name|llvm_unreachable
argument_list|(
literal|"unknown symbol kind"
argument_list|)
expr_stmt|;
block|}
block|}
comment|// namespace coff
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

