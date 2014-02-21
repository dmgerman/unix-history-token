begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- GlobalModuleIndex.h - Global Module Index --------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
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
comment|// This file defines the GlobalModuleIndex class, which manages a global index
end_comment

begin_comment
comment|// containing all of the identifiers known to the various modules within a given
end_comment

begin_comment
comment|// subdirectory of the module cache. It is used to improve the performance of
end_comment

begin_comment
comment|// queries such as "do any modules know about this identifier?"
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
name|LLVM_CLANG_SERIALIZATION_GLOBAL_MODULE_INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_GLOBAL_MODULE_INDEX_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitstreamCursor
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DirectoryEntry
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|IdentifierIterator
decl_stmt|;
name|namespace
name|serialization
block|{
name|class
name|ModuleFile
decl_stmt|;
block|}
name|using
name|llvm
operator|::
name|SmallVector
expr_stmt|;
name|using
name|llvm
operator|::
name|SmallVectorImpl
expr_stmt|;
name|using
name|llvm
operator|::
name|StringRef
expr_stmt|;
name|using
name|serialization
operator|::
name|ModuleFile
expr_stmt|;
comment|/// \brief A global index for a set of module files, providing information about
comment|/// the identifiers within those module files.
comment|///
comment|/// The global index is an aid for name lookup into modules, offering a central
comment|/// place where one can look for identifiers determine which
comment|/// module files contain any information about that identifier. This
comment|/// allows the client to restrict the search to only those module files known
comment|/// to have a information about that identifier, improving performance. Moreover,
comment|/// the global module index may know about module files that have not been
comment|/// imported, and can be queried to determine which modules the current
comment|/// translation could or should load to fix a problem.
name|class
name|GlobalModuleIndex
block|{
comment|/// \brief Buffer containing the index file, which is lazily accessed so long
comment|/// as the global module index is live.
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
expr_stmt|;
comment|/// \brief The hash table.
comment|///
comment|/// This pointer actually points to a IdentifierIndexTable object,
comment|/// but that type is only accessible within the implementation of
comment|/// GlobalModuleIndex.
name|void
modifier|*
name|IdentifierIndex
decl_stmt|;
comment|/// \brief Information about a given module file.
struct|struct
name|ModuleInfo
block|{
name|ModuleInfo
argument_list|()
operator|:
name|File
argument_list|()
operator|,
name|Size
argument_list|()
operator|,
name|ModTime
argument_list|()
block|{ }
comment|/// \brief The module file, once it has been resolved.
name|ModuleFile
operator|*
name|File
expr_stmt|;
comment|/// \brief The module file name.
name|std
operator|::
name|string
name|FileName
expr_stmt|;
comment|/// \brief Size of the module file at the time the global index was built.
name|off_t
name|Size
decl_stmt|;
comment|/// \brief Modification time of the module file at the time the global
comment|/// index was built.
name|time_t
name|ModTime
decl_stmt|;
comment|/// \brief The module IDs on which this module directly depends.
comment|/// FIXME: We don't really need a vector here.
name|llvm
operator|::
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|Dependencies
expr_stmt|;
block|}
struct|;
comment|/// \brief A mapping from module IDs to information about each module.
comment|///
comment|/// This vector may have gaps, if module files have been removed or have
comment|/// been updated since the index was built. A gap is indicated by an empty
comment|/// file name.
name|llvm
operator|::
name|SmallVector
operator|<
name|ModuleInfo
operator|,
literal|16
operator|>
name|Modules
expr_stmt|;
comment|/// \brief Lazily-populated mapping from module files to their
comment|/// corresponding index into the \c Modules vector.
name|llvm
operator|::
name|DenseMap
operator|<
name|ModuleFile
operator|*
operator|,
name|unsigned
operator|>
name|ModulesByFile
expr_stmt|;
comment|/// \brief The set of modules that have not yet been resolved.
comment|///
comment|/// The string is just the name of the module itself, which maps to the
comment|/// module ID.
name|llvm
operator|::
name|StringMap
operator|<
name|unsigned
operator|>
name|UnresolvedModules
expr_stmt|;
comment|/// \brief The number of identifier lookups we performed.
name|unsigned
name|NumIdentifierLookups
decl_stmt|;
comment|/// \brief The number of identifier lookup hits, where we recognize the
comment|/// identifier.
name|unsigned
name|NumIdentifierLookupHits
decl_stmt|;
comment|/// \brief Internal constructor. Use \c readIndex() to read an index.
name|explicit
name|GlobalModuleIndex
argument_list|(
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|,
name|llvm
operator|::
name|BitstreamCursor
name|Cursor
argument_list|)
decl_stmt|;
name|GlobalModuleIndex
argument_list|(
argument|const GlobalModuleIndex&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|GlobalModuleIndex
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GlobalModuleIndex
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
operator|~
name|GlobalModuleIndex
argument_list|()
expr_stmt|;
comment|/// \brief An error code returned when trying to read an index.
enum|enum
name|ErrorCode
block|{
comment|/// \brief No error occurred.
name|EC_None
block|,
comment|/// \brief No index was found.
name|EC_NotFound
block|,
comment|/// \brief Some other process is currently building the index; it is not
comment|/// available yet.
name|EC_Building
block|,
comment|/// \brief There was an unspecified I/O error reading or writing the index.
name|EC_IOError
block|}
enum|;
comment|/// \brief Read a global index file for the given directory.
comment|///
comment|/// \param Path The path to the specific module cache where the module files
comment|/// for the intended configuration reside.
comment|///
comment|/// \returns A pair containing the global module index (if it exists) and
comment|/// the error code.
specifier|static
name|std
operator|::
name|pair
operator|<
name|GlobalModuleIndex
operator|*
operator|,
name|ErrorCode
operator|>
name|readIndex
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
comment|/// \brief Returns an iterator for identifiers stored in the index table.
comment|///
comment|/// The caller accepts ownership of the returned object.
name|IdentifierIterator
operator|*
name|createIdentifierIterator
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the set of modules that have up-to-date indexes.
comment|///
comment|/// \param ModuleFiles Will be populated with the set of module files that
comment|/// have been indexed.
name|void
name|getKnownModules
argument_list|(
name|SmallVectorImpl
operator|<
name|ModuleFile
operator|*
operator|>
operator|&
name|ModuleFiles
argument_list|)
decl_stmt|;
comment|/// \brief Retrieve the set of module files on which the given module file
comment|/// directly depends.
name|void
name|getModuleDependencies
argument_list|(
name|ModuleFile
operator|*
name|File
argument_list|,
name|SmallVectorImpl
operator|<
name|ModuleFile
operator|*
operator|>
operator|&
name|Dependencies
argument_list|)
decl_stmt|;
comment|/// \brief A set of module files in which we found a result.
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|HitSet
expr_stmt|;
comment|/// \brief Look for all of the module files with information about the given
comment|/// identifier, e.g., a global function, variable, or type with that name.
comment|///
comment|/// \param Name The identifier to look for.
comment|///
comment|/// \param Hits Will be populated with the set of module files that have
comment|/// information about this name.
comment|///
comment|/// \returns true if the identifier is known to the index, false otherwise.
name|bool
name|lookupIdentifier
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|HitSet
modifier|&
name|Hits
parameter_list|)
function_decl|;
comment|/// \brief Note that the given module file has been loaded.
comment|///
comment|/// \returns false if the global module index has information about this
comment|/// module file, and true otherwise.
name|bool
name|loadedModuleFile
parameter_list|(
name|ModuleFile
modifier|*
name|File
parameter_list|)
function_decl|;
comment|/// \brief Print statistics to standard error.
name|void
name|printStats
parameter_list|()
function_decl|;
comment|/// \brief Write a global index into the given
comment|///
comment|/// \param FileMgr The file manager to use to load module files.
comment|///
comment|/// \param Path The path to the directory containing module files, into
comment|/// which the global index will be written.
specifier|static
name|ErrorCode
name|writeIndex
parameter_list|(
name|FileManager
modifier|&
name|FileMgr
parameter_list|,
name|StringRef
name|Path
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

