begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/Resolver.h - Resolves Atom References -------------------------===//
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
name|LLD_CORE_RESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_RESOLVER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/ArchiveLibraryFile.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/SharedLibraryFile.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Simple.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/SymbolTable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_include
include|#
directive|include
file|<unordered_set>
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
name|class
name|Atom
decl_stmt|;
name|class
name|LinkingContext
decl_stmt|;
comment|/// \brief The Resolver is responsible for merging all input object files
comment|/// and producing a merged graph.
name|class
name|Resolver
block|{
name|public
label|:
name|Resolver
argument_list|(
name|LinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|_ctx
argument_list|(
name|ctx
argument_list|)
operator|,
name|_result
argument_list|(
argument|new MergedFile()
argument_list|)
block|{}
comment|// InputFiles::Handler methods
name|void
name|doDefinedAtom
argument_list|(
name|OwningAtomPtr
operator|<
name|DefinedAtom
operator|>
name|atom
argument_list|)
expr_stmt|;
name|bool
name|doUndefinedAtom
argument_list|(
name|OwningAtomPtr
operator|<
name|UndefinedAtom
operator|>
name|atom
argument_list|)
decl_stmt|;
name|void
name|doSharedLibraryAtom
argument_list|(
name|OwningAtomPtr
operator|<
name|SharedLibraryAtom
operator|>
name|atom
argument_list|)
decl_stmt|;
name|void
name|doAbsoluteAtom
argument_list|(
name|OwningAtomPtr
operator|<
name|AbsoluteAtom
operator|>
name|atom
argument_list|)
decl_stmt|;
comment|// Handle files, this adds atoms from the current file thats
comment|// being processed by the resolver
name|llvm
operator|::
name|Expected
operator|<
name|bool
operator|>
name|handleFile
argument_list|(
name|File
operator|&
argument_list|)
expr_stmt|;
comment|// Handle an archive library file.
name|llvm
operator|::
name|Expected
operator|<
name|bool
operator|>
name|handleArchiveFile
argument_list|(
name|File
operator|&
argument_list|)
expr_stmt|;
comment|// Handle a shared library file.
name|llvm
operator|::
name|Error
name|handleSharedLibrary
argument_list|(
name|File
operator|&
argument_list|)
expr_stmt|;
comment|/// @brief do work of merging and resolving and return list
name|bool
name|resolve
parameter_list|()
function_decl|;
name|std
operator|::
name|unique_ptr
operator|<
name|SimpleFile
operator|>
name|resultFile
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|_result
argument_list|)
return|;
block|}
name|private
label|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|llvm
operator|::
name|Expected
operator|<
name|bool
operator|>
operator|(
name|StringRef
operator|)
operator|>
name|UndefCallback
expr_stmt|;
name|bool
name|undefinesAdded
parameter_list|(
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|File
modifier|*
name|getFile
parameter_list|(
name|int
modifier|&
name|index
parameter_list|)
function_decl|;
comment|/// \brief The main function that iterates over the files to resolve
name|bool
name|resolveUndefines
parameter_list|()
function_decl|;
name|void
name|updateReferences
parameter_list|()
function_decl|;
name|void
name|deadStripOptimize
parameter_list|()
function_decl|;
name|bool
name|checkUndefines
parameter_list|()
function_decl|;
name|void
name|removeCoalescedAwayAtoms
parameter_list|()
function_decl|;
name|llvm
operator|::
name|Expected
operator|<
name|bool
operator|>
name|forEachUndefines
argument_list|(
argument|File&file
argument_list|,
argument|UndefCallback callback
argument_list|)
expr_stmt|;
name|void
name|markLive
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|)
function_decl|;
name|class
name|MergedFile
range|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|MergedFile
argument_list|()
operator|:
name|SimpleFile
argument_list|(
literal|"<linker-internal>"
argument_list|,
argument|kindResolverMergedObject
argument_list|)
block|{}
name|void
name|addAtoms
argument_list|(
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|OwningAtomPtr
operator|<
name|Atom
operator|>>
name|atoms
argument_list|)
block|;   }
decl_stmt|;
name|LinkingContext
modifier|&
name|_ctx
decl_stmt|;
name|SymbolTable
name|_symbolTable
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|OwningAtomPtr
operator|<
name|Atom
operator|>>
name|_atoms
expr_stmt|;
name|std
operator|::
name|set
operator|<
specifier|const
name|Atom
operator|*
operator|>
name|_deadStripRoots
expr_stmt|;
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|Atom
operator|*
operator|>
name|_liveAtoms
expr_stmt|;
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|Atom
operator|*
operator|>
name|_deadAtoms
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MergedFile
operator|>
name|_result
expr_stmt|;
name|std
operator|::
name|unordered_multimap
operator|<
specifier|const
name|Atom
operator|*
operator|,
specifier|const
name|Atom
operator|*
operator|>
name|_reverseRef
expr_stmt|;
comment|// --start-group and --end-group
name|std
operator|::
name|vector
operator|<
name|File
operator|*
operator|>
name|_files
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|File
operator|*
operator|,
name|bool
operator|>
name|_newUndefinesAdded
expr_stmt|;
comment|// List of undefined symbols.
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|_undefines
expr_stmt|;
comment|// Start position in _undefines for each archive/shared library file.
comment|// Symbols from index 0 to the start position are already searched before.
comment|// Searching them again would never succeed. When we look for undefined
comment|// symbols from an archive/shared library file, start from its start
comment|// position to save time.
name|std
operator|::
name|map
operator|<
name|File
operator|*
operator|,
name|size_t
operator|>
name|_undefineIndex
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_RESOLVER_H
end_comment

end_unit

