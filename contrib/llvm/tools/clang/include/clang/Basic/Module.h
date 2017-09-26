begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Module.h - Describe a module ---------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::Module class, which describes a module in the
end_comment

begin_comment
comment|/// source code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_MODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_MODULE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|LangOptions
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
comment|/// \brief Describes the name of a module.
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|SourceLocation
operator|>
operator|,
literal|2
operator|>
name|ModuleId
expr_stmt|;
comment|/// The signature of a module, which is a hash of the AST content.
name|struct
name|ASTFileSignature
range|:
name|std
operator|::
name|array
operator|<
name|uint32_t
decl_stmt|, 5>
block|{
name|ASTFileSignature
argument_list|(
name|std
operator|::
name|array
operator|<
name|uint32_t
argument_list|,
literal|5
operator|>
name|S
operator|=
block|{
block|{
literal|0
block|}
block|}
argument_list|)
operator|:
name|std
operator|::
name|array
operator|<
name|uint32_t
operator|,
literal|5
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|S
argument_list|)
operator|)
block|{}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|*
name|this
operator|!=
name|std
operator|::
name|array
operator|<
name|uint32_t
operator|,
literal|5
operator|>
operator|(
block|{
block|{
literal|0
block|}
block|}
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Describes a module or submodule.
name|class
name|Module
block|{
name|public
label|:
comment|/// \brief The name of this module.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// \brief The location of the module definition.
name|SourceLocation
name|DefinitionLoc
decl_stmt|;
enum|enum
name|ModuleKind
block|{
comment|/// \brief This is a module that was defined by a module map and built out
comment|/// of header files.
name|ModuleMapModule
block|,
comment|/// \brief This is a C++ Modules TS module interface unit.
name|ModuleInterfaceUnit
block|}
enum|;
comment|/// \brief The kind of this module.
name|ModuleKind
name|Kind
init|=
name|ModuleMapModule
decl_stmt|;
comment|/// \brief The parent of this module. This will be NULL for the top-level
comment|/// module.
name|Module
modifier|*
name|Parent
decl_stmt|;
comment|/// \brief The build directory of this module. This is the directory in
comment|/// which the module is notionally built, and relative to which its headers
comment|/// are found.
specifier|const
name|DirectoryEntry
modifier|*
name|Directory
decl_stmt|;
comment|/// \brief The presumed file name for the module map defining this module.
comment|/// Only non-empty when building from preprocessed source.
name|std
operator|::
name|string
name|PresumedModuleMapFile
expr_stmt|;
comment|/// \brief The umbrella header or directory.
name|llvm
operator|::
name|PointerUnion
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|,
specifier|const
name|FileEntry
operator|*
operator|>
name|Umbrella
expr_stmt|;
comment|/// \brief The module signature.
name|ASTFileSignature
name|Signature
decl_stmt|;
comment|/// \brief The name of the umbrella entry, as written in the module map.
name|std
operator|::
name|string
name|UmbrellaAsWritten
expr_stmt|;
name|private
label|:
comment|/// \brief The submodules of this module, indexed by name.
name|std
operator|::
name|vector
operator|<
name|Module
operator|*
operator|>
name|SubModules
expr_stmt|;
comment|/// \brief A mapping from the submodule name to the index into the
comment|/// \c SubModules vector at which that submodule resides.
name|llvm
operator|::
name|StringMap
operator|<
name|unsigned
operator|>
name|SubModuleIndex
expr_stmt|;
comment|/// \brief The AST file if this is a top-level module which has a
comment|/// corresponding serialized AST file, or null otherwise.
specifier|const
name|FileEntry
modifier|*
name|ASTFile
decl_stmt|;
comment|/// \brief The top-level headers associated with this module.
name|llvm
operator|::
name|SmallSetVector
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
literal|2
operator|>
name|TopHeaders
expr_stmt|;
comment|/// \brief top-level header filenames that aren't resolved to FileEntries yet.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|TopHeaderNames
expr_stmt|;
comment|/// \brief Cache of modules visible to lookup in this module.
name|mutable
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|Module
operator|*
operator|>
name|VisibleModulesCache
expr_stmt|;
comment|/// The ID used when referencing this module within a VisibleModuleSet.
name|unsigned
name|VisibilityID
decl_stmt|;
name|public
label|:
enum|enum
name|HeaderKind
block|{
name|HK_Normal
block|,
name|HK_Textual
block|,
name|HK_Private
block|,
name|HK_PrivateTextual
block|,
name|HK_Excluded
block|}
enum|;
specifier|static
specifier|const
name|int
name|NumHeaderKinds
init|=
name|HK_Excluded
operator|+
literal|1
decl_stmt|;
comment|/// \brief Information about a header directive as found in the module map
comment|/// file.
struct|struct
name|Header
block|{
name|std
operator|::
name|string
name|NameAsWritten
expr_stmt|;
specifier|const
name|FileEntry
modifier|*
name|Entry
decl_stmt|;
name|explicit
name|operator
name|bool
parameter_list|()
block|{
return|return
name|Entry
return|;
block|}
block|}
struct|;
comment|/// \brief Information about a directory name as found in the module map
comment|/// file.
struct|struct
name|DirectoryName
block|{
name|std
operator|::
name|string
name|NameAsWritten
expr_stmt|;
specifier|const
name|DirectoryEntry
modifier|*
name|Entry
decl_stmt|;
name|explicit
name|operator
name|bool
parameter_list|()
block|{
return|return
name|Entry
return|;
block|}
block|}
struct|;
comment|/// \brief The headers that are part of this module.
name|SmallVector
operator|<
name|Header
operator|,
literal|2
operator|>
name|Headers
index|[
literal|5
index|]
expr_stmt|;
comment|/// \brief Stored information about a header directive that was found in the
comment|/// module map file but has not been resolved to a file.
struct|struct
name|UnresolvedHeaderDirective
block|{
name|HeaderKind
name|Kind
init|=
name|HK_Normal
decl_stmt|;
name|SourceLocation
name|FileNameLoc
decl_stmt|;
name|std
operator|::
name|string
name|FileName
expr_stmt|;
name|bool
name|IsUmbrella
init|=
name|false
decl_stmt|;
name|bool
name|HasBuiltinHeader
init|=
name|false
decl_stmt|;
name|Optional
operator|<
name|off_t
operator|>
name|Size
expr_stmt|;
name|Optional
operator|<
name|time_t
operator|>
name|ModTime
expr_stmt|;
block|}
struct|;
comment|/// Headers that are mentioned in the module map file but that we have not
comment|/// yet attempted to resolve to a file on the file system.
name|SmallVector
operator|<
name|UnresolvedHeaderDirective
operator|,
literal|1
operator|>
name|UnresolvedHeaders
expr_stmt|;
comment|/// \brief Headers that are mentioned in the module map file but could not be
comment|/// found on the file system.
name|SmallVector
operator|<
name|UnresolvedHeaderDirective
operator|,
literal|1
operator|>
name|MissingHeaders
expr_stmt|;
comment|/// \brief An individual requirement: a feature name and a flag indicating
comment|/// the required state of that feature.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|bool
operator|>
name|Requirement
expr_stmt|;
comment|/// \brief The set of language features required to use this module.
comment|///
comment|/// If any of these requirements are not available, the \c IsAvailable bit
comment|/// will be false to indicate that this (sub)module is not available.
name|SmallVector
operator|<
name|Requirement
operator|,
literal|2
operator|>
name|Requirements
expr_stmt|;
comment|/// \brief Whether this module is missing a feature from \c Requirements.
name|unsigned
name|IsMissingRequirement
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether we tried and failed to load a module file for this module.
name|unsigned
name|HasIncompatibleModuleFile
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this module is available in the current translation unit.
comment|///
comment|/// If the module is missing headers or does not meet all requirements then
comment|/// this bit will be 0.
name|unsigned
name|IsAvailable
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this module was loaded from a module file.
name|unsigned
name|IsFromModuleFile
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is a framework module.
name|unsigned
name|IsFramework
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is an explicit submodule.
name|unsigned
name|IsExplicit
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is a "system" module (which assumes that all
comment|/// headers in it are system headers).
name|unsigned
name|IsSystem
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is an 'extern "C"' module (which implicitly puts all
comment|/// headers in it within an 'extern "C"' block, and allows the module to be
comment|/// imported within such a block).
name|unsigned
name|IsExternC
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is an inferred submodule (module * { ... }).
name|unsigned
name|IsInferred
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether we should infer submodules for this module based on
comment|/// the headers.
comment|///
comment|/// Submodules can only be inferred for modules with an umbrella header.
name|unsigned
name|InferSubmodules
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether, when inferring submodules, the inferred submodules
comment|/// should be explicit.
name|unsigned
name|InferExplicitSubmodules
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether, when inferring submodules, the inferr submodules should
comment|/// export all modules they import (e.g., the equivalent of "export *").
name|unsigned
name|InferExportWildcard
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether the set of configuration macros is exhaustive.
comment|///
comment|/// When the set of configuration macros is exhaustive, meaning
comment|/// that no identifier not in this list should affect how the module is
comment|/// built.
name|unsigned
name|ConfigMacrosExhaustive
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether files in this module can only include non-modular headers
comment|/// and headers from used modules.
name|unsigned
name|NoUndeclaredIncludes
range|:
literal|1
decl_stmt|;
comment|/// \brief Describes the visibility of the various names within a
comment|/// particular module.
enum|enum
name|NameVisibilityKind
block|{
comment|/// \brief All of the names in this module are hidden.
name|Hidden
block|,
comment|/// \brief All of the names in this module are visible.
name|AllVisible
block|}
enum|;
comment|/// \brief The visibility of names within this particular module.
name|NameVisibilityKind
name|NameVisibility
decl_stmt|;
comment|/// \brief The location of the inferred submodule.
name|SourceLocation
name|InferredSubmoduleLoc
decl_stmt|;
comment|/// \brief The set of modules imported by this module, and on which this
comment|/// module depends.
name|llvm
operator|::
name|SmallSetVector
operator|<
name|Module
operator|*
operator|,
literal|2
operator|>
name|Imports
expr_stmt|;
comment|/// \brief Describes an exported module.
comment|///
comment|/// The pointer is the module being re-exported, while the bit will be true
comment|/// to indicate that this is a wildcard export.
typedef|typedef
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Module
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|ExportDecl
expr_stmt|;
comment|/// \brief The set of export declarations.
name|SmallVector
operator|<
name|ExportDecl
operator|,
literal|2
operator|>
name|Exports
expr_stmt|;
comment|/// \brief Describes an exported module that has not yet been resolved
comment|/// (perhaps because the module it refers to has not yet been loaded).
struct|struct
name|UnresolvedExportDecl
block|{
comment|/// \brief The location of the 'export' keyword in the module map file.
name|SourceLocation
name|ExportLoc
decl_stmt|;
comment|/// \brief The name of the module.
name|ModuleId
name|Id
decl_stmt|;
comment|/// \brief Whether this export declaration ends in a wildcard, indicating
comment|/// that all of its submodules should be exported (rather than the named
comment|/// module itself).
name|bool
name|Wildcard
decl_stmt|;
block|}
struct|;
comment|/// \brief The set of export declarations that have yet to be resolved.
name|SmallVector
operator|<
name|UnresolvedExportDecl
operator|,
literal|2
operator|>
name|UnresolvedExports
expr_stmt|;
comment|/// \brief The directly used modules.
name|SmallVector
operator|<
name|Module
operator|*
operator|,
literal|2
operator|>
name|DirectUses
expr_stmt|;
comment|/// \brief The set of use declarations that have yet to be resolved.
name|SmallVector
operator|<
name|ModuleId
operator|,
literal|2
operator|>
name|UnresolvedDirectUses
expr_stmt|;
comment|/// \brief A library or framework to link against when an entity from this
comment|/// module is used.
struct|struct
name|LinkLibrary
block|{
name|LinkLibrary
argument_list|()
operator|:
name|IsFramework
argument_list|(
argument|false
argument_list|)
block|{ }
name|LinkLibrary
argument_list|(
argument|const std::string&Library
argument_list|,
argument|bool IsFramework
argument_list|)
operator|:
name|Library
argument_list|(
name|Library
argument_list|)
operator|,
name|IsFramework
argument_list|(
argument|IsFramework
argument_list|)
block|{ }
comment|/// \brief The library to link against.
comment|///
comment|/// This will typically be a library or framework name, but can also
comment|/// be an absolute path to the library or framework.
name|std
operator|::
name|string
name|Library
expr_stmt|;
comment|/// \brief Whether this is a framework rather than a library.
name|bool
name|IsFramework
decl_stmt|;
block|}
struct|;
comment|/// \brief The set of libraries or frameworks to link against when
comment|/// an entity from this module is used.
name|llvm
operator|::
name|SmallVector
operator|<
name|LinkLibrary
operator|,
literal|2
operator|>
name|LinkLibraries
expr_stmt|;
comment|/// \brief The set of "configuration macros", which are macros that
comment|/// (intentionally) change how this module is built.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ConfigMacros
expr_stmt|;
comment|/// \brief An unresolved conflict with another module.
struct|struct
name|UnresolvedConflict
block|{
comment|/// \brief The (unresolved) module id.
name|ModuleId
name|Id
decl_stmt|;
comment|/// \brief The message provided to the user when there is a conflict.
name|std
operator|::
name|string
name|Message
expr_stmt|;
block|}
struct|;
comment|/// \brief The list of conflicts for which the module-id has not yet been
comment|/// resolved.
name|std
operator|::
name|vector
operator|<
name|UnresolvedConflict
operator|>
name|UnresolvedConflicts
expr_stmt|;
comment|/// \brief A conflict between two modules.
struct|struct
name|Conflict
block|{
comment|/// \brief The module that this module conflicts with.
name|Module
modifier|*
name|Other
decl_stmt|;
comment|/// \brief The message provided to the user when there is a conflict.
name|std
operator|::
name|string
name|Message
expr_stmt|;
block|}
struct|;
comment|/// \brief The list of conflicts.
name|std
operator|::
name|vector
operator|<
name|Conflict
operator|>
name|Conflicts
expr_stmt|;
comment|/// \brief Construct a new module or submodule.
name|Module
argument_list|(
argument|StringRef Name
argument_list|,
argument|SourceLocation DefinitionLoc
argument_list|,
argument|Module *Parent
argument_list|,
argument|bool IsFramework
argument_list|,
argument|bool IsExplicit
argument_list|,
argument|unsigned VisibilityID
argument_list|)
empty_stmt|;
operator|~
name|Module
argument_list|()
expr_stmt|;
comment|/// \brief Determine whether this module is available for use within the
comment|/// current translation unit.
name|bool
name|isAvailable
argument_list|()
specifier|const
block|{
return|return
name|IsAvailable
return|;
block|}
comment|/// \brief Determine whether this module is available for use within the
comment|/// current translation unit.
comment|///
comment|/// \param LangOpts The language options used for the current
comment|/// translation unit.
comment|///
comment|/// \param Target The target options used for the current translation unit.
comment|///
comment|/// \param Req If this module is unavailable, this parameter
comment|/// will be set to one of the requirements that is not met for use of
comment|/// this module.
name|bool
name|isAvailable
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
specifier|const
name|TargetInfo
operator|&
name|Target
argument_list|,
name|Requirement
operator|&
name|Req
argument_list|,
name|UnresolvedHeaderDirective
operator|&
name|MissingHeader
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Determine whether this module is a submodule.
name|bool
name|isSubModule
argument_list|()
specifier|const
block|{
return|return
name|Parent
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Determine whether this module is a submodule of the given other
comment|/// module.
name|bool
name|isSubModuleOf
argument_list|(
specifier|const
name|Module
operator|*
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Determine whether this module is a part of a framework,
comment|/// either because it is a framework module or because it is a submodule
comment|/// of a framework module.
name|bool
name|isPartOfFramework
argument_list|()
specifier|const
block|{
for|for
control|(
specifier|const
name|Module
modifier|*
name|Mod
init|=
name|this
init|;
name|Mod
condition|;
name|Mod
operator|=
name|Mod
operator|->
name|Parent
control|)
if|if
condition|(
name|Mod
operator|->
name|IsFramework
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// \brief Determine whether this module is a subframework of another
comment|/// framework.
name|bool
name|isSubFramework
argument_list|()
specifier|const
block|{
return|return
name|IsFramework
operator|&&
name|Parent
operator|&&
name|Parent
operator|->
name|isPartOfFramework
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the full name of this module, including the path from
comment|/// its top-level module.
comment|/// \param AllowStringLiterals If \c true, components that might not be
comment|///        lexically valid as identifiers will be emitted as string literals.
name|std
operator|::
name|string
name|getFullModuleName
argument_list|(
argument|bool AllowStringLiterals = false
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Whether the full name of this module is equal to joining
comment|/// \p nameParts with "."s.
comment|///
comment|/// This is more efficient than getFullModuleName().
name|bool
name|fullModuleNameIs
argument_list|(
name|ArrayRef
operator|<
name|StringRef
operator|>
name|nameParts
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve the top-level module for this (sub)module, which may
comment|/// be this module.
name|Module
modifier|*
name|getTopLevelModule
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Module
operator|*
operator|>
operator|(
name|const_cast
operator|<
specifier|const
name|Module
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTopLevelModule
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the top-level module for this (sub)module, which may
comment|/// be this module.
specifier|const
name|Module
operator|*
name|getTopLevelModule
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the name of the top-level module.
comment|///
name|StringRef
name|getTopLevelModuleName
argument_list|()
specifier|const
block|{
return|return
name|getTopLevelModule
argument_list|()
operator|->
name|Name
return|;
block|}
comment|/// \brief The serialized AST file for this module, if one was created.
specifier|const
name|FileEntry
operator|*
name|getASTFile
argument_list|()
specifier|const
block|{
return|return
name|getTopLevelModule
argument_list|()
operator|->
name|ASTFile
return|;
block|}
comment|/// \brief Set the serialized AST file for the top-level module of this module.
name|void
name|setASTFile
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|File
operator|==
name|nullptr
operator|||
name|getASTFile
argument_list|()
operator|==
name|nullptr
operator|||
name|getASTFile
argument_list|()
operator|==
name|File
operator|)
operator|&&
literal|"file path changed"
argument_list|)
expr_stmt|;
name|getTopLevelModule
argument_list|()
operator|->
name|ASTFile
operator|=
name|File
expr_stmt|;
block|}
comment|/// \brief Retrieve the directory for which this module serves as the
comment|/// umbrella.
name|DirectoryName
name|getUmbrellaDir
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the header that serves as the umbrella header for this
comment|/// module.
name|Header
name|getUmbrellaHeader
argument_list|()
specifier|const
block|{
if|if
condition|(
name|auto
operator|*
name|E
operator|=
name|Umbrella
operator|.
name|dyn_cast
operator|<
specifier|const
name|FileEntry
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|Header
block|{
name|UmbrellaAsWritten
block|,
name|E
block|}
return|;
return|return
name|Header
block|{}
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this module has an umbrella directory that is
end_comment

begin_comment
comment|/// not based on an umbrella header.
end_comment

begin_expr_stmt
name|bool
name|hasUmbrellaDir
argument_list|()
specifier|const
block|{
return|return
name|Umbrella
operator|&&
name|Umbrella
operator|.
name|is
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Add a top-level header associated with this module.
end_comment

begin_function
name|void
name|addTopHeader
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
name|assert
argument_list|(
name|File
argument_list|)
expr_stmt|;
name|TopHeaders
operator|.
name|insert
argument_list|(
name|File
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Add a top-level header filename associated with this module.
end_comment

begin_function
name|void
name|addTopHeaderFilename
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
block|{
name|TopHeaderNames
operator|.
name|push_back
argument_list|(
name|Filename
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief The top-level headers associated with this module.
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
specifier|const
name|FileEntry
operator|*
operator|>
name|getTopHeaders
argument_list|(
name|FileManager
operator|&
name|FileMgr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this module has declared its intention to
end_comment

begin_comment
comment|/// directly use another module.
end_comment

begin_decl_stmt
name|bool
name|directlyUses
argument_list|(
specifier|const
name|Module
operator|*
name|Requested
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Add the given feature requirement to the list of features
end_comment

begin_comment
comment|/// required by this module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Feature The feature that is required by this module (and
end_comment

begin_comment
comment|/// its submodules).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param RequiredState The required state of this feature: \c true
end_comment

begin_comment
comment|/// if it must be present, \c false if it must be absent.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param LangOpts The set of language options that will be used to
end_comment

begin_comment
comment|/// evaluate the availability of this feature.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Target The target options that will be used to evaluate the
end_comment

begin_comment
comment|/// availability of this feature.
end_comment

begin_function_decl
name|void
name|addRequirement
parameter_list|(
name|StringRef
name|Feature
parameter_list|,
name|bool
name|RequiredState
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Mark this module and all of its submodules as unavailable.
end_comment

begin_function_decl
name|void
name|markUnavailable
parameter_list|(
name|bool
name|MissingRequirement
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Find the submodule with the given name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The submodule if found, or NULL otherwise.
end_comment

begin_decl_stmt
name|Module
modifier|*
name|findSubmodule
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether the specified module would be visible to
end_comment

begin_comment
comment|/// a lookup at the end of this module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: This may return incorrect results for (submodules of) the
end_comment

begin_comment
comment|/// module currently being built, if it's queried before we see all
end_comment

begin_comment
comment|/// of its imports.
end_comment

begin_decl_stmt
name|bool
name|isModuleVisible
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|)
decl|const
block|{
if|if
condition|(
name|VisibleModulesCache
operator|.
name|empty
argument_list|()
condition|)
name|buildVisibleModulesCache
argument_list|()
expr_stmt|;
return|return
name|VisibleModulesCache
operator|.
name|count
argument_list|(
name|M
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getVisibilityID
argument_list|()
specifier|const
block|{
return|return
name|VisibilityID
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Module
operator|*
operator|>
operator|::
name|iterator
name|submodule_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Module
operator|*
operator|>
operator|::
name|const_iterator
name|submodule_const_iterator
expr_stmt|;
end_typedef

begin_function
name|submodule_iterator
name|submodule_begin
parameter_list|()
block|{
return|return
name|SubModules
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|submodule_const_iterator
name|submodule_begin
argument_list|()
specifier|const
block|{
return|return
name|SubModules
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|submodule_iterator
name|submodule_end
parameter_list|()
block|{
return|return
name|SubModules
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|submodule_const_iterator
name|submodule_end
argument_list|()
specifier|const
block|{
return|return
name|SubModules
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|iterator_range
operator|<
name|submodule_iterator
operator|>
name|submodules
argument_list|()
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|submodule_begin
argument_list|()
argument_list|,
name|submodule_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|iterator_range
operator|<
name|submodule_const_iterator
operator|>
name|submodules
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|submodule_begin
argument_list|()
argument_list|,
name|submodule_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Appends this module's list of exported modules to \p Exported.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides a subset of immediately imported modules (the ones that are
end_comment

begin_comment
comment|/// directly exported), not the complete set of exported modules.
end_comment

begin_decl_stmt
name|void
name|getExportedModules
argument_list|(
name|SmallVectorImpl
operator|<
name|Module
operator|*
operator|>
operator|&
name|Exported
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|StringRef
name|getModuleInputBufferName
parameter_list|()
block|{
return|return
literal|"<module-includes>"
return|;
block|}
end_function

begin_comment
comment|/// \brief Print the module map for this module to the given stream.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|Indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Dump the contents of this module to the given output stream.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|void
name|buildVisibleModulesCache
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief A set of visible modules.
end_comment

begin_decl_stmt
name|class
name|VisibleModuleSet
block|{
name|public
label|:
name|VisibleModuleSet
argument_list|()
operator|:
name|Generation
argument_list|(
literal|0
argument_list|)
block|{}
name|VisibleModuleSet
argument_list|(
name|VisibleModuleSet
operator|&&
name|O
argument_list|)
operator|:
name|ImportLocs
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|O
operator|.
name|ImportLocs
argument_list|)
argument_list|)
operator|,
name|Generation
argument_list|(
argument|O.Generation ?
literal|1
argument|:
literal|0
argument_list|)
block|{
name|O
operator|.
name|ImportLocs
operator|.
name|clear
argument_list|()
block|;
operator|++
name|O
operator|.
name|Generation
block|;   }
comment|/// Move from another visible modules set. Guaranteed to leave the source
comment|/// empty and bump the generation on both.
name|VisibleModuleSet
operator|&
name|operator
operator|=
operator|(
name|VisibleModuleSet
operator|&&
name|O
operator|)
block|{
name|ImportLocs
operator|=
name|std
operator|::
name|move
argument_list|(
name|O
operator|.
name|ImportLocs
argument_list|)
block|;
name|O
operator|.
name|ImportLocs
operator|.
name|clear
argument_list|()
block|;
operator|++
name|O
operator|.
name|Generation
block|;
operator|++
name|Generation
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Get the current visibility generation. Incremented each time the
comment|/// set of visible modules changes in any way.
name|unsigned
name|getGeneration
argument_list|()
specifier|const
block|{
return|return
name|Generation
return|;
block|}
comment|/// \brief Determine whether a module is visible.
name|bool
name|isVisible
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|)
decl|const
block|{
return|return
name|getImportLoc
argument_list|(
name|M
argument_list|)
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Get the location at which the import of a module was triggered.
name|SourceLocation
name|getImportLoc
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|)
decl|const
block|{
return|return
name|M
operator|->
name|getVisibilityID
argument_list|()
operator|<
name|ImportLocs
operator|.
name|size
argument_list|()
condition|?
name|ImportLocs
index|[
name|M
operator|->
name|getVisibilityID
argument_list|()
index|]
else|:
name|SourceLocation
argument_list|()
return|;
block|}
comment|/// \brief A callback to call when a module is made visible (directly or
comment|/// indirectly) by a call to \ref setVisible.
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|Module
operator|*
name|M
argument_list|)
operator|>
name|VisibleCallback
expr_stmt|;
comment|/// \brief A callback to call when a module conflict is found. \p Path
comment|/// consists of a sequence of modules from the conflicting module to the one
comment|/// made visible, where each was exported by the next.
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
argument|ArrayRef<Module *> Path
argument_list|,
argument|Module *Conflict
argument_list|,
argument|StringRef Message
argument_list|)
operator|>
name|ConflictCallback
expr_stmt|;
comment|/// \brief Make a specific module visible.
name|void
name|setVisible
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|VisibleCallback
name|Vis
operator|=
index|[]
operator|(
name|Module
operator|*
operator|)
block|{}
argument_list|,
name|ConflictCallback
name|Cb
operator|=
index|[]
operator|(
name|ArrayRef
operator|<
name|Module
operator|*
operator|>
operator|,
name|Module
operator|*
operator|,
name|StringRef
operator|)
block|{}
argument_list|)
decl_stmt|;
name|private
label|:
comment|/// Import locations for each visible module. Indexed by the module's
comment|/// VisibilityID.
name|std
operator|::
name|vector
operator|<
name|SourceLocation
operator|>
name|ImportLocs
expr_stmt|;
comment|/// Visibility generation, bumped every time the visibility state changes.
name|unsigned
name|Generation
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_MODULE_H
end_comment

end_unit

