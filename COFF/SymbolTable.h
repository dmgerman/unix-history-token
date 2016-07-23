begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolTable.h --------------------------------------------*- C++ -*-===//
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
name|LLD_COFF_SYMBOL_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_SYMBOL_TABLE_H
end_define

begin_include
include|#
directive|include
file|"InputFiles.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|//<future> depends on<eh.h> for __uncaught_exception.
end_comment

begin_include
include|#
directive|include
file|<eh.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<future>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|LTOCodeGenerator
struct_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
block|{
name|class
name|Chunk
decl_stmt|;
name|class
name|Defined
decl_stmt|;
name|class
name|Lazy
decl_stmt|;
name|class
name|SymbolBody
decl_stmt|;
struct_decl|struct
name|Symbol
struct_decl|;
comment|// SymbolTable is a bucket of all known symbols, including defined,
comment|// undefined, or lazy symbols (the last one is symbols in archive
comment|// files whose archive members are not yet loaded).
comment|//
comment|// We put all symbols of all files to a SymbolTable, and the
comment|// SymbolTable selects the "best" symbols if there are name
comment|// conflicts. For example, obviously, a defined symbol is better than
comment|// an undefined symbol. Or, if there's a conflict between a lazy and a
comment|// undefined, it'll read an archive member to read a real definition
comment|// to replace the lazy symbol. The logic is implemented in resolve().
name|class
name|SymbolTable
block|{
name|public
label|:
name|void
name|addFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>
name|File
argument_list|)
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>>
operator|&
name|getFiles
argument_list|()
block|{
return|return
name|Files
return|;
block|}
name|void
name|step
parameter_list|()
function_decl|;
name|void
name|run
parameter_list|()
function_decl|;
name|bool
name|queueEmpty
parameter_list|()
function_decl|;
comment|// Print an error message on undefined symbols. If Resolve is true, try to
comment|// resolve any undefined symbols and update the symbol table accordingly.
name|void
name|reportRemainingUndefines
parameter_list|(
name|bool
name|Resolve
parameter_list|)
function_decl|;
comment|// Returns a list of chunks of selected symbols.
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|*
operator|>
name|getChunks
argument_list|()
expr_stmt|;
comment|// Returns a symbol for a given name. Returns a nullptr if not found.
name|Symbol
modifier|*
name|find
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|Symbol
modifier|*
name|findUnderscore
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|// Occasionally we have to resolve an undefined symbol to its
comment|// mangled symbol. This function tries to find a mangled name
comment|// for U from the symbol table, and if found, set the symbol as
comment|// a weak alias for U.
name|void
name|mangleMaybe
parameter_list|(
name|Undefined
modifier|*
name|U
parameter_list|)
function_decl|;
name|StringRef
name|findMangle
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|// Print a layout map to OS.
name|void
name|printMap
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
comment|// Build a set of COFF objects representing the combined contents of
comment|// BitcodeFiles and add them to the symbol table. Called after all files are
comment|// added and before the writer writes results to a file.
name|void
name|addCombinedLTOObjects
parameter_list|()
function_decl|;
comment|// The writer needs to handle DLL import libraries specially in
comment|// order to create the import descriptor table.
name|std
operator|::
name|vector
operator|<
name|ImportFile
operator|*
operator|>
name|ImportFiles
expr_stmt|;
comment|// The writer needs to infer the machine type from the object files.
name|std
operator|::
name|vector
operator|<
name|ObjectFile
operator|*
operator|>
name|ObjectFiles
expr_stmt|;
comment|// Creates an Undefined symbol for a given name.
name|Undefined
modifier|*
name|addUndefined
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|DefinedRelative
modifier|*
name|addRelative
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint64_t
name|VA
parameter_list|)
function_decl|;
name|DefinedAbsolute
modifier|*
name|addAbsolute
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint64_t
name|VA
parameter_list|)
function_decl|;
comment|// A list of chunks which to be added to .rdata.
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|*
operator|>
name|LocalImportChunks
expr_stmt|;
name|private
label|:
name|void
name|readArchives
parameter_list|()
function_decl|;
name|void
name|readObjects
parameter_list|()
function_decl|;
name|void
name|addSymbol
parameter_list|(
name|SymbolBody
modifier|*
name|New
parameter_list|)
function_decl|;
name|void
name|addLazy
argument_list|(
name|Lazy
operator|*
name|New
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|*
operator|>
operator|*
name|Accum
argument_list|)
decl_stmt|;
name|Symbol
modifier|*
name|insert
parameter_list|(
name|SymbolBody
modifier|*
name|New
parameter_list|)
function_decl|;
name|StringRef
name|findByPrefix
parameter_list|(
name|StringRef
name|Prefix
parameter_list|)
function_decl|;
name|void
name|addMemberFile
parameter_list|(
name|Lazy
modifier|*
name|Body
parameter_list|)
function_decl|;
name|void
name|addCombinedLTOObject
parameter_list|(
name|ObjectFile
modifier|*
name|Obj
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|ObjectFile
operator|*
operator|>
name|createLTOObjects
argument_list|(
name|llvm
operator|::
name|LTOCodeGenerator
operator|*
name|CG
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|StringRef
operator|,
name|Symbol
operator|*
operator|>
name|Symtab
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>>
name|Files
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|future
operator|<
name|ArchiveFile
operator|*
operator|>>
name|ArchiveQueue
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|future
operator|<
name|InputFile
operator|*
operator|>>
name|ObjectQueue
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BitcodeFile
operator|*
operator|>
name|BitcodeFiles
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SmallString
operator|<
literal|0
operator|>>
name|Objs
expr_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
expr_stmt|;
block|}
empty_stmt|;
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

