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
file|"clang/Serialization/Module.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
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
name|namespace
name|serialization
block|{
comment|/// \brief Manages the set of modules loaded by an AST reader.
name|class
name|ModuleManager
block|{
comment|/// \brief The chain of AST files. The first entry is the one named by the
comment|/// user, the last one is the one that doesn't depend on anything further.
name|llvm
operator|::
name|SmallVector
operator|<
name|Module
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
name|Module
operator|*
operator|>
name|Modules
expr_stmt|;
comment|/// \brief FileManager that handles translating between filenames and
comment|/// FileEntry *.
name|FileManager
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
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|Module
operator|*
operator|,
literal|2
operator|>
operator|::
name|iterator
name|ModuleIterator
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|Module
operator|*
operator|,
literal|2
operator|>
operator|::
name|const_iterator
name|ModuleConstIterator
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|Module
operator|*
operator|,
literal|2
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
name|ModuleManager
argument_list|(
specifier|const
name|FileSystemOptions
operator|&
name|FSO
argument_list|)
expr_stmt|;
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
name|Module
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
name|Module
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
name|Module
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
name|Module
modifier|*
name|lookup
parameter_list|(
name|StringRef
name|Name
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
comment|/// \brief Attempts to create a new module and add it to the list of known
comment|/// modules.
comment|///
comment|/// \param FileName The file name of the module to be loaded.
comment|///
comment|/// \param Type The kind of module being loaded.
comment|///
comment|/// \param ImportedBy The module that is importing this module, or NULL if
comment|/// this module is imported directly by the user.
comment|///
comment|/// \param ErrorStr Will be set to a non-empty string if any errors occurred
comment|/// while trying to load the module.
comment|///
comment|/// \return A pointer to the module that corresponds to this file name,
comment|/// and a boolean indicating whether the module was newly added.
name|std
operator|::
name|pair
operator|<
name|Module
operator|*
operator|,
name|bool
operator|>
name|addModule
argument_list|(
argument|StringRef FileName
argument_list|,
argument|ModuleKind Type
argument_list|,
argument|Module *ImportedBy
argument_list|,
argument|std::string&ErrorStr
argument_list|)
expr_stmt|;
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
name|void
name|visit
parameter_list|(
name|bool
function_decl|(
modifier|*
name|Visitor
function_decl|)
parameter_list|(
name|Module
modifier|&
name|M
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
name|Module
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

