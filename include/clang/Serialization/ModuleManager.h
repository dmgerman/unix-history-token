begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ModuleManager.cpp - Module Manager ---------------------*- C++ -*-===//
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
comment|//  This file defines the ModuleManager class, which manages a set of loaded
end_comment

begin_comment
comment|//  modules for the ASTReader.
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
name|LLVM_CLANG_SERIALIZATION_MODULE_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_MODULE_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GlobalModuleIndex
decl_stmt|;
name|class
name|ModuleMap
decl_stmt|;
name|namespace
name|serialization
block|{
comment|/// \brief Manages the set of modules loaded by an AST reader.
name|class
name|ModuleManager
block|{
comment|/// \brief The chain of AST files. The first entry is the one named by the
comment|/// user, the last one is the one that doesn't depend on anything further.
name|SmallVector
operator|<
name|ModuleFile
operator|*
operator|,
literal|2
operator|>
name|Chain
expr_stmt|;
comment|/// \brief All loaded modules, indexed by name.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
name|ModuleFile
operator|*
operator|>
name|Modules
expr_stmt|;
comment|/// \brief FileManager that handles translating between filenames and
comment|/// FileEntry *.
name|FileManager
modifier|&
name|FileMgr
decl_stmt|;
comment|/// \brief A lookup of in-memory (virtual file) buffers
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
name|InMemoryBuffers
expr_stmt|;
comment|/// \brief The visitation order.
name|SmallVector
operator|<
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|VisitOrder
expr_stmt|;
comment|/// \brief The list of module files that both we and the global module index
comment|/// know about.
comment|///
comment|/// Either the global index or the module manager may have modules that the
comment|/// other does not know about, because the global index can be out-of-date
comment|/// (in which case the module manager could have modules it does not) and
comment|/// this particular translation unit might not have loaded all of the modules
comment|/// known to the global index.
name|SmallVector
operator|<
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|ModulesInCommonWithGlobalIndex
expr_stmt|;
comment|/// \brief The global module index, if one is attached.
comment|///
comment|/// The global module index will actually be owned by the ASTReader; this is
comment|/// just an non-owning pointer.
name|GlobalModuleIndex
modifier|*
name|GlobalIndex
decl_stmt|;
comment|/// \brief State used by the "visit" operation to avoid malloc traffic in
comment|/// calls to visit().
struct|struct
name|VisitState
block|{
name|explicit
name|VisitState
argument_list|(
argument|unsigned N
argument_list|)
block|:
name|VisitNumber
argument_list|(
name|N
argument_list|,
literal|0
argument_list|)
operator|,
name|NextVisitNumber
argument_list|(
literal|1
argument_list|)
operator|,
name|NextState
argument_list|(
literal|0
argument_list|)
block|{
name|Stack
operator|.
name|reserve
argument_list|(
name|N
argument_list|)
block|;     }
operator|~
name|VisitState
argument_list|()
block|{
name|delete
name|NextState
block|;     }
comment|/// \brief The stack used when marking the imports of a particular module
comment|/// as not-to-be-visited.
name|SmallVector
operator|<
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|Stack
expr_stmt|;
comment|/// \brief The visit number of each module file, which indicates when
comment|/// this module file was last visited.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|VisitNumber
expr_stmt|;
comment|/// \brief The next visit number to use to mark visited module files.
name|unsigned
name|NextVisitNumber
decl_stmt|;
comment|/// \brief The next visit state.
name|VisitState
modifier|*
name|NextState
decl_stmt|;
block|}
struct|;
comment|/// \brief The first visit() state in the chain.
name|VisitState
modifier|*
name|FirstVisitState
decl_stmt|;
name|VisitState
modifier|*
name|allocateVisitState
parameter_list|()
function_decl|;
name|void
name|returnVisitState
parameter_list|(
name|VisitState
modifier|*
name|State
parameter_list|)
function_decl|;
name|public
label|:
typedef|typedef
name|SmallVectorImpl
operator|<
name|ModuleFile
operator|*
operator|>
operator|::
name|iterator
name|ModuleIterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|ModuleFile
operator|*
operator|>
operator|::
name|const_iterator
name|ModuleConstIterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|ModuleFile
operator|*
operator|>
operator|::
name|reverse_iterator
name|ModuleReverseIterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|StringRef
operator|>
name|ModuleOffset
expr_stmt|;
name|explicit
name|ModuleManager
parameter_list|(
name|FileManager
modifier|&
name|FileMgr
parameter_list|)
function_decl|;
operator|~
name|ModuleManager
argument_list|()
expr_stmt|;
comment|/// \brief Forward iterator to traverse all loaded modules.  This is reverse
comment|/// source-order.
name|ModuleIterator
name|begin
parameter_list|()
block|{
return|return
name|Chain
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Forward iterator end-point to traverse all loaded modules
name|ModuleIterator
name|end
parameter_list|()
block|{
return|return
name|Chain
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Const forward iterator to traverse all loaded modules.  This is
comment|/// in reverse source-order.
name|ModuleConstIterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Chain
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Const forward iterator end-point to traverse all loaded modules
name|ModuleConstIterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Chain
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Reverse iterator to traverse all loaded modules.  This is in
comment|/// source order.
name|ModuleReverseIterator
name|rbegin
parameter_list|()
block|{
return|return
name|Chain
operator|.
name|rbegin
argument_list|()
return|;
block|}
comment|/// \brief Reverse iterator end-point to traverse all loaded modules.
name|ModuleReverseIterator
name|rend
parameter_list|()
block|{
return|return
name|Chain
operator|.
name|rend
argument_list|()
return|;
block|}
comment|/// \brief Returns the primary module associated with the manager, that is,
comment|/// the first module loaded
name|ModuleFile
modifier|&
name|getPrimaryModule
parameter_list|()
block|{
return|return
operator|*
name|Chain
index|[
literal|0
index|]
return|;
block|}
comment|/// \brief Returns the primary module associated with the manager, that is,
comment|/// the first module loaded.
name|ModuleFile
operator|&
name|getPrimaryModule
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Chain
index|[
literal|0
index|]
return|;
block|}
comment|/// \brief Returns the module associated with the given index
name|ModuleFile
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
block|{
return|return
operator|*
name|Chain
index|[
name|Index
index|]
return|;
block|}
comment|/// \brief Returns the module associated with the given name
name|ModuleFile
modifier|*
name|lookup
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \brief Returns the module associated with the given module file.
name|ModuleFile
modifier|*
name|lookup
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
function_decl|;
comment|/// \brief Returns the in-memory (virtual file) buffer with the given name
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|lookupBuffer
argument_list|(
argument|StringRef Name
argument_list|)
expr_stmt|;
comment|/// \brief Number of modules loaded
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Chain
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief The result of attempting to add a new module.
enum|enum
name|AddModuleResult
block|{
comment|/// \brief The module file had already been loaded.
name|AlreadyLoaded
block|,
comment|/// \brief The module file was just loaded in response to this call.
name|NewlyLoaded
block|,
comment|/// \brief The module file is missing.
name|Missing
block|,
comment|/// \brief The module file is out-of-date.
name|OutOfDate
block|}
enum|;
comment|/// \brief Attempts to create a new module and add it to the list of known
comment|/// modules.
comment|///
comment|/// \param FileName The file name of the module to be loaded.
comment|///
comment|/// \param Type The kind of module being loaded.
comment|///
comment|/// \param ImportLoc The location at which the module is imported.
comment|///
comment|/// \param ImportedBy The module that is importing this module, or NULL if
comment|/// this module is imported directly by the user.
comment|///
comment|/// \param Generation The generation in which this module was loaded.
comment|///
comment|/// \param ExpectedSize The expected size of the module file, used for
comment|/// validation. This will be zero if unknown.
comment|///
comment|/// \param ExpectedModTime The expected modification time of the module
comment|/// file, used for validation. This will be zero if unknown.
comment|///
comment|/// \param Module A pointer to the module file if the module was successfully
comment|/// loaded.
comment|///
comment|/// \param ErrorStr Will be set to a non-empty string if any errors occurred
comment|/// while trying to load the module.
comment|///
comment|/// \return A pointer to the module that corresponds to this file name,
comment|/// and a value indicating whether the module was loaded.
name|AddModuleResult
name|addModule
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|ModuleKind
name|Type
argument_list|,
name|SourceLocation
name|ImportLoc
argument_list|,
name|ModuleFile
operator|*
name|ImportedBy
argument_list|,
name|unsigned
name|Generation
argument_list|,
name|off_t
name|ExpectedSize
argument_list|,
name|time_t
name|ExpectedModTime
argument_list|,
name|ModuleFile
operator|*
operator|&
name|Module
argument_list|,
name|std
operator|::
name|string
operator|&
name|ErrorStr
argument_list|)
decl_stmt|;
comment|/// \brief Remove the given set of modules.
name|void
name|removeModules
parameter_list|(
name|ModuleIterator
name|first
parameter_list|,
name|ModuleIterator
name|last
parameter_list|,
name|ModuleMap
modifier|*
name|modMap
parameter_list|)
function_decl|;
comment|/// \brief Add an in-memory buffer the list of known buffers
name|void
name|addInMemoryBuffer
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|)
decl_stmt|;
comment|/// \brief Set the global module index.
name|void
name|setGlobalIndex
parameter_list|(
name|GlobalModuleIndex
modifier|*
name|Index
parameter_list|)
function_decl|;
comment|/// \brief Notification from the AST reader that the given module file
comment|/// has been "accepted", and will not (can not) be unloaded.
name|void
name|moduleFileAccepted
parameter_list|(
name|ModuleFile
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// \brief Visit each of the modules.
comment|///
comment|/// This routine visits each of the modules, starting with the
comment|/// "root" modules that no other loaded modules depend on, and
comment|/// proceeding to the leaf modules, visiting each module only once
comment|/// during the traversal.
comment|///
comment|/// This traversal is intended to support various "lookup"
comment|/// operations that can find data in any of the loaded modules.
comment|///
comment|/// \param Visitor A visitor function that will be invoked with each
comment|/// module and the given user data pointer. The return value must be
comment|/// convertible to bool; when false, the visitation continues to
comment|/// modules that the current module depends on. When true, the
comment|/// visitation skips any modules that the current module depends on.
comment|///
comment|/// \param UserData User data associated with the visitor object, which
comment|/// will be passed along to the visitor.
comment|///
comment|/// \param ModuleFilesHit If non-NULL, contains the set of module files
comment|/// that we know we need to visit because the global module index told us to.
comment|/// Any module that is known to both the global module index and the module
comment|/// manager that is *not* in this set can be skipped.
name|void
name|visit
argument_list|(
name|bool
argument_list|(
operator|*
name|Visitor
argument_list|)
argument_list|(
name|ModuleFile
operator|&
name|M
argument_list|,
name|void
operator|*
name|UserData
argument_list|)
argument_list|,
name|void
operator|*
name|UserData
argument_list|,
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|ModuleFile
operator|*
argument_list|,
literal|4
operator|>
operator|*
name|ModuleFilesHit
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// \brief Visit each of the modules with a depth-first traversal.
comment|///
comment|/// This routine visits each of the modules known to the module
comment|/// manager using a depth-first search, starting with the first
comment|/// loaded module. The traversal invokes the callback both before
comment|/// traversing the children (preorder traversal) and after
comment|/// traversing the children (postorder traversal).
comment|///
comment|/// \param Visitor A visitor function that will be invoked with each
comment|/// module and given a \c Preorder flag that indicates whether we're
comment|/// visiting the module before or after visiting its children.  The
comment|/// visitor may return true at any time to abort the depth-first
comment|/// visitation.
comment|///
comment|/// \param UserData User data ssociated with the visitor object,
comment|/// which will be passed along to the user.
name|void
name|visitDepthFirst
parameter_list|(
name|bool
function_decl|(
modifier|*
name|Visitor
function_decl|)
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
name|bool
name|Preorder
parameter_list|,
name|void
modifier|*
name|UserData
parameter_list|)
parameter_list|,
name|void
modifier|*
name|UserData
parameter_list|)
function_decl|;
comment|/// \brief Attempt to resolve the given module file name to a file entry.
comment|///
comment|/// \param FileName The name of the module file.
comment|///
comment|/// \param ExpectedSize The size that the module file is expected to have.
comment|/// If the actual size differs, the resolver should return \c true.
comment|///
comment|/// \param ExpectedModTime The modification time that the module file is
comment|/// expected to have. If the actual modification time differs, the resolver
comment|/// should return \c true.
comment|///
comment|/// \param File Will be set to the file if there is one, or null
comment|/// otherwise.
comment|///
comment|/// \returns True if a file exists but does not meet the size/
comment|/// modification time criteria, false if the file is either available and
comment|/// suitable, or is missing.
name|bool
name|lookupModuleFile
parameter_list|(
name|StringRef
name|FileName
parameter_list|,
name|off_t
name|ExpectedSize
parameter_list|,
name|time_t
name|ExpectedModTime
parameter_list|,
specifier|const
name|FileEntry
modifier|*
modifier|&
name|File
parameter_list|)
function_decl|;
comment|/// \brief View the graphviz representation of the module graph.
name|void
name|viewGraph
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::serialization
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

