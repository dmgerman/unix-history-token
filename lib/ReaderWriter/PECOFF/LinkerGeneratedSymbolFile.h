begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/PECOFF/LinkerGeneratedSymbolFile.h ----------------===//
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

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Simple.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/PECOFFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_expr_stmt
name|using
name|llvm
operator|::
name|COFF
operator|::
name|WindowsSubsystem
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|pecoff
block|{
name|bool
name|findDecoratedSymbol
argument_list|(
name|PECOFFLinkingContext
operator|*
name|ctx
argument_list|,
name|std
operator|::
name|string
name|sym
argument_list|,
name|std
operator|::
name|string
operator|&
name|res
argument_list|)
decl_stmt|;
name|namespace
name|impl
block|{
comment|/// The defined atom for dllexported symbols with __imp_ prefix.
name|class
name|ImpPointerAtom
range|:
name|public
name|COFFLinkerInternalAtom
block|{
name|public
operator|:
name|ImpPointerAtom
argument_list|(
argument|const File&file
argument_list|,
argument|StringRef symbolName
argument_list|,
argument|uint64_t ordinal
argument_list|)
operator|:
name|COFFLinkerInternalAtom
argument_list|(
name|file
argument_list|,
comment|/*oridnal*/
literal|0
argument_list|,
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
operator|(
literal|4
operator|)
argument_list|,
name|symbolName
argument_list|)
block|,
name|_ordinal
argument_list|(
argument|ordinal
argument_list|)
block|{}
name|uint64_t
name|ordinal
argument_list|()
specifier|const
name|override
block|{
return|return
name|_ordinal
return|;
block|}
name|Scope
name|scope
argument_list|()
specifier|const
name|override
block|{
return|return
name|scopeGlobal
return|;
block|}
name|ContentType
name|contentType
argument_list|()
specifier|const
name|override
block|{
return|return
name|typeData
return|;
block|}
name|Alignment
name|alignment
argument_list|()
specifier|const
name|override
block|{
return|return
name|Alignment
argument_list|(
literal|4
argument_list|)
return|;
block|}
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
name|override
block|{
return|return
name|permR__
return|;
block|}
name|private
operator|:
name|uint64_t
name|_ordinal
block|; }
decl_stmt|;
name|class
name|ImpSymbolFile
range|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|ImpSymbolFile
argument_list|(
argument|StringRef defsym
argument_list|,
argument|StringRef undefsym
argument_list|,
argument|uint64_t ordinal
argument_list|,
argument|bool is64
argument_list|)
operator|:
name|SimpleFile
argument_list|(
name|defsym
argument_list|)
block|,
name|_undefined
argument_list|(
operator|*
name|this
argument_list|,
name|undefsym
argument_list|)
block|,
name|_defined
argument_list|(
argument|*this
argument_list|,
argument|defsym
argument_list|,
argument|ordinal
argument_list|)
block|{
name|SimpleReference
operator|*
name|ref
block|;
if|if
condition|(
name|is64
condition|)
block|{
name|ref
operator|=
name|new
name|SimpleReference
argument_list|(
name|Reference
operator|::
name|KindNamespace
operator|::
name|COFF
argument_list|,
name|Reference
operator|::
name|KindArch
operator|::
name|x86_64
argument_list|,
name|llvm
operator|::
name|COFF
operator|::
name|IMAGE_REL_AMD64_ADDR32
argument_list|,
literal|0
argument_list|,
operator|&
name|_undefined
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ref
operator|=
name|new
name|SimpleReference
argument_list|(
name|Reference
operator|::
name|KindNamespace
operator|::
name|COFF
argument_list|,
name|Reference
operator|::
name|KindArch
operator|::
name|x86
argument_list|,
name|llvm
operator|::
name|COFF
operator|::
name|IMAGE_REL_I386_DIR32
argument_list|,
literal|0
argument_list|,
operator|&
name|_undefined
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|_defined
operator|.
name|addReference
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|SimpleReference
operator|>
operator|(
name|ref
operator|)
argument_list|)
expr_stmt|;
name|addAtom
argument_list|(
name|_defined
argument_list|)
block|;
name|addAtom
argument_list|(
name|_undefined
argument_list|)
block|;   }
decl_stmt|;
name|private
label|:
name|SimpleUndefinedAtom
name|_undefined
decl_stmt|;
name|ImpPointerAtom
name|_defined
decl_stmt|;
block|}
empty_stmt|;
comment|// A file to make Resolver to resolve a symbol TO instead of a symbol FROM,
comment|// using fallback mechanism for an undefined symbol. One can virtually rename an
comment|// undefined symbol using this file.
name|class
name|SymbolRenameFile
range|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|SymbolRenameFile
argument_list|(
argument|StringRef from
argument_list|,
argument|StringRef to
argument_list|)
operator|:
name|SimpleFile
argument_list|(
literal|"<symbol-rename>"
argument_list|)
block|,
name|_fromSym
argument_list|(
name|from
argument_list|)
block|,
name|_toSym
argument_list|(
name|to
argument_list|)
block|,
name|_from
argument_list|(
operator|*
name|this
argument_list|,
name|_fromSym
argument_list|,
operator|&
name|_to
argument_list|)
block|,
name|_to
argument_list|(
argument|*this
argument_list|,
argument|_toSym
argument_list|)
block|{
name|addAtom
argument_list|(
name|_from
argument_list|)
block|;   }
block|;
name|private
operator|:
name|std
operator|::
name|string
name|_fromSym
block|;
name|std
operator|::
name|string
name|_toSym
block|;
name|COFFUndefinedAtom
name|_from
block|;
name|COFFUndefinedAtom
name|_to
block|; }
decl_stmt|;
block|}
comment|// namespace impl
comment|// A virtual file containing absolute symbol __ImageBase. __ImageBase (or
comment|// ___ImageBase on x86) is a linker-generated symbol whose address is the same
comment|// as the image base address.
name|class
name|LinkerGeneratedSymbolFile
range|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|LinkerGeneratedSymbolFile
argument_list|(
specifier|const
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|SimpleFile
argument_list|(
literal|"<linker-internal-file>"
argument_list|)
block|,
name|_imageBaseAtom
argument_list|(
argument|*this
argument_list|,
argument|ctx.decorateSymbol(
literal|"__ImageBase"
argument|)
argument_list|,
argument|Atom::scopeGlobal
argument_list|,
argument|ctx.getBaseAddress()
argument_list|)
block|{
name|addAtom
argument_list|(
name|_imageBaseAtom
argument_list|)
block|;   }
block|;
name|private
operator|:
name|SimpleAbsoluteAtom
name|_imageBaseAtom
block|; }
decl_stmt|;
comment|// A LocallyImporteSymbolFile is an archive file containing __imp_
comment|// symbols for local use.
comment|//
comment|// For each defined symbol, linker creates an implicit defined symbol
comment|// by appending "__imp_" prefix to the original name. The content of
comment|// the implicit symbol is a pointer to the original symbol
comment|// content. This feature allows one to compile and link the following
comment|// code without error, although _imp__hello is not defined in the
comment|// code. (the leading "_" in this example is automatically appended,
comment|// assuming it's x86.)
comment|//
comment|//   void hello() { printf("Hello\n"); }
comment|//   extern void (*_imp__hello)();
comment|//   int main() {
comment|//      _imp__hello();
comment|//      return 0;
comment|//   }
comment|//
comment|// This odd feature is for the compatibility with MSVC link.exe.
name|class
name|LocallyImportedSymbolFile
range|:
name|public
name|SimpleArchiveLibraryFile
block|{
name|public
operator|:
name|LocallyImportedSymbolFile
argument_list|(
specifier|const
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|SimpleArchiveLibraryFile
argument_list|(
literal|"__imp_"
argument_list|)
block|,
name|_is64
argument_list|(
name|ctx
operator|.
name|is64Bit
argument_list|()
argument_list|)
block|,
name|_ordinal
argument_list|(
literal|0
argument_list|)
block|{}
name|File
operator|*
name|find
argument_list|(
argument|StringRef sym
argument_list|,
argument|bool dataSymbolOnly
argument_list|)
name|override
block|{
name|std
operator|::
name|string
name|prefix
operator|=
literal|"__imp_"
block|;
if|if
condition|(
operator|!
name|sym
operator|.
name|startswith
argument_list|(
name|prefix
argument_list|)
condition|)
return|return
name|nullptr
return|;
name|StringRef
name|undef
operator|=
name|sym
operator|.
name|substr
argument_list|(
name|prefix
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|_alloc
argument_list|)
name|impl
operator|::
name|ImpSymbolFile
argument_list|(
name|sym
argument_list|,
name|undef
argument_list|,
name|_ordinal
operator|++
argument_list|,
name|_is64
argument_list|)
return|;
block|}
name|private
label|:
name|bool
name|_is64
decl_stmt|;
name|uint64_t
name|_ordinal
decl_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A ExportedSymbolRenameFile is a virtual archive file for dllexported symbols.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// One usually has to specify the exact symbol name to resolve it. That's true
end_comment

begin_comment
comment|// in most cases for PE/COFF, except the one described below.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DLLExported symbols can be specified using a module definition file. In a
end_comment

begin_comment
comment|// file, one can write an EXPORT directive followed by symbol names. Such
end_comment

begin_comment
comment|// symbols may not be fully decorated.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If a symbol FOO is specified to be dllexported by a module definition file,
end_comment

begin_comment
comment|// linker has to search not only for /FOO/ but also for /FOO@[0-9]+/ for stdcall
end_comment

begin_comment
comment|// and for /\?FOO@@.+/ for C++. This ambiguous matching semantics does not fit
end_comment

begin_comment
comment|// well with Resolver.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We could probably modify Resolver to resolve ambiguous symbols, but I think
end_comment

begin_comment
comment|// we don't want to do that because it'd be rarely used, and only this Windows
end_comment

begin_comment
comment|// specific feature would use it. It's probably not a good idea to make the core
end_comment

begin_comment
comment|// linker to be able to deal with it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// So, instead of tweaking Resolver, we chose to do some hack here. An
end_comment

begin_comment
comment|// ExportedSymbolRenameFile maintains a set containing all possibly defined
end_comment

begin_comment
comment|// symbol names. That set would be a union of (1) all the defined symbols that
end_comment

begin_comment
comment|// are already parsed and read and (2) all the defined symbols in archive files
end_comment

begin_comment
comment|// that are not yet be parsed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If Resolver asks this file to return an atom for a dllexported symbol, find()
end_comment

begin_comment
comment|// looks up the set, doing ambiguous matching. If there's a symbol with @
end_comment

begin_comment
comment|// prefix, it returns an atom to rename the dllexported symbol, hoping that
end_comment

begin_comment
comment|// Resolver will find the new symbol with atsign from an archive file at the
end_comment

begin_comment
comment|// next visit.
end_comment

begin_decl_stmt
name|class
name|ExportedSymbolRenameFile
range|:
name|public
name|SimpleArchiveLibraryFile
block|{
name|public
operator|:
name|ExportedSymbolRenameFile
argument_list|(
specifier|const
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|SimpleArchiveLibraryFile
argument_list|(
literal|"<export>"
argument_list|)
block|,
name|_ctx
argument_list|(
argument|const_cast<PECOFFLinkingContext *>(&ctx)
argument_list|)
block|{
for|for
control|(
name|PECOFFLinkingContext
operator|::
name|ExportDesc
operator|&
name|desc
operator|:
name|_ctx
operator|->
name|getDllExports
argument_list|()
control|)
name|_exportedSyms
operator|.
name|insert
argument_list|(
name|desc
operator|.
name|name
argument_list|)
expr_stmt|;
block|}
name|File
operator|*
name|find
argument_list|(
argument|StringRef sym
argument_list|,
argument|bool dataSymbolOnly
argument_list|)
name|override
block|{
typedef|typedef
name|PECOFFLinkingContext
operator|::
name|ExportDesc
name|ExportDesc
expr_stmt|;
if|if
condition|(
name|_exportedSyms
operator|.
name|count
argument_list|(
name|sym
argument_list|)
operator|==
literal|0
condition|)
return|return
name|nullptr
return|;
name|std
operator|::
name|string
name|replace
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|!
name|findDecoratedSymbol
argument_list|(
name|_ctx
argument_list|,
name|sym
operator|.
name|str
argument_list|()
argument_list|,
name|replace
argument_list|)
condition|)
return|return
name|nullptr
return|;
end_if

begin_for
for|for
control|(
name|ExportDesc
modifier|&
name|exp
range|:
name|_ctx
operator|->
name|getDllExports
argument_list|()
control|)
if|if
condition|(
name|exp
operator|.
name|name
operator|==
name|sym
condition|)
name|exp
operator|.
name|mangledName
operator|=
name|replace
expr_stmt|;
end_for

begin_if
if|if
condition|(
name|_ctx
operator|->
name|deadStrip
argument_list|()
condition|)
name|_ctx
operator|->
name|addDeadStripRoot
argument_list|(
name|_ctx
operator|->
name|allocate
argument_list|(
name|replace
argument_list|)
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
name|new
argument_list|(
argument|_alloc
argument_list|)
name|impl
operator|::
name|SymbolRenameFile
argument_list|(
name|sym
argument_list|,
name|replace
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  private:
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|_exportedSyms
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|PECOFFLinkingContext
modifier|*
name|_ctx
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Windows has not only one but many entry point functions. The
end_comment

begin_comment
comment|// appropriate one is automatically selected based on the subsystem
end_comment

begin_comment
comment|// setting and the user-supplied entry point function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// http://msdn.microsoft.com/en-us/library/f9t8842e.aspx
end_comment

begin_decl_stmt
name|class
name|EntryPointFile
range|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|EntryPointFile
argument_list|(
specifier|const
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|SimpleFile
argument_list|(
literal|"<entry>"
argument_list|)
block|,
name|_ctx
argument_list|(
name|const_cast
operator|<
name|PECOFFLinkingContext
operator|*
operator|>
operator|(
operator|&
name|ctx
operator|)
argument_list|)
block|,
name|_firstTime
argument_list|(
argument|true
argument_list|)
block|{}
specifier|const
name|atom_collection
operator|<
name|UndefinedAtom
operator|>
operator|&
name|undefined
argument_list|()
specifier|const
name|override
block|{
return|return
name|const_cast
operator|<
name|EntryPointFile
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getUndefinedAtoms
argument_list|()
return|;
block|}
name|private
operator|:
specifier|const
name|atom_collection
operator|<
name|UndefinedAtom
operator|>
operator|&
name|getUndefinedAtoms
argument_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|lock
argument_list|(
name|_mutex
argument_list|)
block|;
if|if
condition|(
operator|!
name|_firstTime
condition|)
return|return
name|_undefinedAtoms
return|;
name|_firstTime
operator|=
name|false
block|;
if|if
condition|(
name|_ctx
operator|->
name|hasEntry
argument_list|()
condition|)
block|{
name|StringRef
name|entrySym
init|=
name|_ctx
operator|->
name|allocate
argument_list|(
name|getEntry
argument_list|()
argument_list|)
decl_stmt|;
name|_undefinedAtoms
operator|.
name|_atoms
operator|.
name|push_back
argument_list|(
name|new
argument_list|(
argument|_alloc
argument_list|)
name|SimpleUndefinedAtom
argument_list|(
operator|*
name|this
argument_list|,
name|entrySym
argument_list|)
argument_list|)
expr_stmt|;
name|_ctx
operator|->
name|setHasEntry
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|_ctx
operator|->
name|setEntrySymbolName
argument_list|(
name|entrySym
argument_list|)
expr_stmt|;
if|if
condition|(
name|_ctx
operator|->
name|deadStrip
argument_list|()
condition|)
name|_ctx
operator|->
name|addDeadStripRoot
argument_list|(
name|entrySym
argument_list|)
expr_stmt|;
block|}
return|return
name|_undefinedAtoms
return|;
block|}
end_decl_stmt

begin_comment
comment|// Returns the entry point function name.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getEntry
argument_list|()
specifier|const
block|{
name|StringRef
name|opt
operator|=
name|_ctx
operator|->
name|getEntrySymbolName
argument_list|()
block|;
if|if
condition|(
operator|!
name|opt
operator|.
name|empty
argument_list|()
condition|)
block|{
name|std
operator|::
name|string
name|mangled
expr_stmt|;
if|if
condition|(
name|findDecoratedSymbol
argument_list|(
name|_ctx
argument_list|,
name|opt
argument_list|,
name|mangled
argument_list|)
condition|)
return|return
name|mangled
return|;
return|return
name|_ctx
operator|->
name|decorateSymbol
argument_list|(
name|opt
argument_list|)
return|;
block|}
end_expr_stmt

begin_return
return|return
name|_ctx
operator|->
name|decorateSymbol
argument_list|(
name|getDefaultEntry
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    std
operator|::
name|string
name|getDefaultEntry
argument_list|()
specifier|const
block|{
specifier|const
name|std
operator|::
name|string
name|wWinMainCRTStartup
operator|=
literal|"wWinMainCRTStartup"
block|;
specifier|const
name|std
operator|::
name|string
name|WinMainCRTStartup
operator|=
literal|"WinMainCRTStartup"
block|;
specifier|const
name|std
operator|::
name|string
name|wmainCRTStartup
operator|=
literal|"wmainCRTStartup"
block|;
specifier|const
name|std
operator|::
name|string
name|mainCRTStartup
operator|=
literal|"mainCRTStartup"
block|;
if|if
condition|(
name|_ctx
operator|->
name|isDll
argument_list|()
condition|)
block|{
if|if
condition|(
name|_ctx
operator|->
name|getMachineType
argument_list|()
operator|==
name|llvm
operator|::
name|COFF
operator|::
name|IMAGE_FILE_MACHINE_I386
condition|)
return|return
literal|"_DllMainCRTStartup@12"
return|;
return|return
literal|"_DllMainCRTStartup"
return|;
block|}
comment|// Returns true if a given name exists in an input object file.
name|auto
name|defined
operator|=
index|[
operator|&
index|]
operator|(
name|StringRef
name|name
operator|)
operator|->
name|bool
block|{
name|StringRef
name|sym
operator|=
name|_ctx
operator|->
name|decorateSymbol
argument_list|(
name|name
argument_list|)
block|;
if|if
condition|(
name|_ctx
operator|->
name|definedSymbols
argument_list|()
operator|.
name|count
argument_list|(
name|sym
argument_list|)
condition|)
return|return
name|true
return|;
name|std
operator|::
name|string
name|ignore
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|findDecoratedSymbol
argument_list|(
name|_ctx
argument_list|,
name|sym
argument_list|,
name|ignore
argument_list|)
return|;
end_return

begin_switch
unit|};
switch|switch
condition|(
name|_ctx
operator|->
name|getSubsystem
argument_list|()
condition|)
block|{
case|case
name|WindowsSubsystem
operator|::
name|IMAGE_SUBSYSTEM_UNKNOWN
case|:
block|{
if|if
condition|(
name|defined
argument_list|(
literal|"wWinMain"
argument_list|)
condition|)
return|return
name|wWinMainCRTStartup
return|;
if|if
condition|(
name|defined
argument_list|(
literal|"WinMain"
argument_list|)
condition|)
return|return
name|WinMainCRTStartup
return|;
if|if
condition|(
name|defined
argument_list|(
literal|"wmain"
argument_list|)
condition|)
return|return
name|wmainCRTStartup
return|;
if|if
condition|(
operator|!
name|defined
argument_list|(
literal|"main"
argument_list|)
condition|)
name|llvm
operator|::
name|errs
argument_list|()
operator|<<
literal|"Cannot infer subsystem; assuming /subsystem:console\n"
expr_stmt|;
return|return
name|mainCRTStartup
return|;
block|}
case|case
name|WindowsSubsystem
operator|::
name|IMAGE_SUBSYSTEM_WINDOWS_GUI
case|:
if|if
condition|(
name|defined
argument_list|(
literal|"WinMain"
argument_list|)
condition|)
return|return
name|WinMainCRTStartup
return|;
return|return
name|wWinMainCRTStartup
return|;
case|case
name|WindowsSubsystem
operator|::
name|IMAGE_SUBSYSTEM_WINDOWS_CUI
case|:
if|if
condition|(
name|defined
argument_list|(
literal|"wmain"
argument_list|)
condition|)
return|return
name|wmainCRTStartup
return|;
return|return
name|mainCRTStartup
return|;
default|default:
return|return
name|mainCRTStartup
return|;
block|}
end_switch

begin_expr_stmt
unit|}    PECOFFLinkingContext
operator|*
name|_ctx
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|atom_collection_vector
operator|<
name|UndefinedAtom
operator|>
name|_undefinedAtoms
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|mutex
name|_mutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|_firstTime
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace pecoff
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

end_unit

