begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ModuleMap.h - Describe the layout of modules -----------*- C++ -*-===//
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
comment|// This file defines the ModuleMap interface, which describes the layout of a
end_comment

begin_comment
comment|// module as it relates to headers.
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
name|LLVM_CLANG_LEX_MODULEMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_MODULEMAP_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Module.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
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
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|DiagnosticConsumer
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|ModuleMapParser
decl_stmt|;
comment|/// \brief A mechanism to observe the actions of the module map parser as it
comment|/// reads module map files.
name|class
name|ModuleMapCallbacks
block|{
name|public
label|:
name|virtual
operator|~
name|ModuleMapCallbacks
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief Called when a module map file has been read.
comment|///
comment|/// \param FileStart A SourceLocation referring to the start of the file's
comment|/// contents.
comment|/// \param File The file itself.
comment|/// \param IsSystem Whether this is a module map from a system include path.
name|virtual
name|void
name|moduleMapFileRead
parameter_list|(
name|SourceLocation
name|FileStart
parameter_list|,
specifier|const
name|FileEntry
modifier|&
name|File
parameter_list|,
name|bool
name|IsSystem
parameter_list|)
block|{}
comment|/// \brief Called when a header is added during module map parsing.
comment|///
comment|/// \param Filename The header file itself.
name|virtual
name|void
name|moduleMapAddHeader
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
block|{}
comment|/// \brief Called when an umbrella header is added during module map parsing.
comment|///
comment|/// \param FileMgr FileManager instance
comment|/// \param Header The umbrella header to collect.
name|virtual
name|void
name|moduleMapAddUmbrellaHeader
parameter_list|(
name|FileManager
modifier|*
name|FileMgr
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|Header
parameter_list|)
block|{}
block|}
empty_stmt|;
name|class
name|ModuleMap
block|{
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
specifier|const
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
specifier|const
name|TargetInfo
modifier|*
name|Target
decl_stmt|;
name|HeaderSearch
modifier|&
name|HeaderInfo
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleMapCallbacks
operator|>
operator|,
literal|1
operator|>
name|Callbacks
expr_stmt|;
comment|/// \brief The directory used for Clang-supplied, builtin include headers,
comment|/// such as "stdint.h".
specifier|const
name|DirectoryEntry
modifier|*
name|BuiltinIncludeDir
decl_stmt|;
comment|/// \brief Language options used to parse the module map itself.
comment|///
comment|/// These are always simple C language options.
name|LangOptions
name|MMapLangOpts
decl_stmt|;
comment|// The module that the main source file is associated with (the module
comment|// named LangOpts::CurrentModule, if we've loaded it).
name|Module
modifier|*
name|SourceModule
decl_stmt|;
comment|/// \brief The top-level modules that are known.
name|llvm
operator|::
name|StringMap
operator|<
name|Module
operator|*
operator|>
name|Modules
expr_stmt|;
comment|/// \brief The number of modules we have created in total.
name|unsigned
name|NumCreatedModules
decl_stmt|;
name|public
label|:
comment|/// \brief Flags describing the role of a module header.
enum|enum
name|ModuleHeaderRole
block|{
comment|/// \brief This header is normally included in the module.
name|NormalHeader
init|=
literal|0x0
block|,
comment|/// \brief This header is included but private.
name|PrivateHeader
init|=
literal|0x1
block|,
comment|/// \brief This header is part of the module (for layering purposes) but
comment|/// should be textually included.
name|TextualHeader
init|=
literal|0x2
block|,
comment|// Caution: Adding an enumerator needs other changes.
comment|// Adjust the number of bits for KnownHeader::Storage.
comment|// Adjust the bitfield HeaderFileInfo::HeaderRole size.
comment|// Adjust the HeaderFileInfoTrait::ReadData streaming.
comment|// Adjust the HeaderFileInfoTrait::EmitData streaming.
comment|// Adjust ModuleMap::addHeader.
block|}
enum|;
comment|/// \brief A header that is known to reside within a given module,
comment|/// whether it was included or excluded.
name|class
name|KnownHeader
block|{
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Module
operator|*
operator|,
literal|2
operator|,
name|ModuleHeaderRole
operator|>
name|Storage
expr_stmt|;
name|public
label|:
name|KnownHeader
argument_list|()
operator|:
name|Storage
argument_list|(
argument|nullptr
argument_list|,
argument|NormalHeader
argument_list|)
block|{ }
name|KnownHeader
argument_list|(
argument|Module *M
argument_list|,
argument|ModuleHeaderRole Role
argument_list|)
operator|:
name|Storage
argument_list|(
argument|M
argument_list|,
argument|Role
argument_list|)
block|{ }
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|KnownHeader
operator|&
name|A
operator|,
specifier|const
name|KnownHeader
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|Storage
operator|==
name|B
operator|.
name|Storage
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|KnownHeader
operator|&
name|A
operator|,
specifier|const
name|KnownHeader
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|Storage
operator|!=
name|B
operator|.
name|Storage
return|;
block|}
comment|/// \brief Retrieve the module the header is stored in.
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief The role of this header within the module.
name|ModuleHeaderRole
name|getRole
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Whether this header is available in the module.
name|bool
name|isAvailable
argument_list|()
specifier|const
block|{
return|return
name|getModule
argument_list|()
operator|->
name|isAvailable
argument_list|()
return|;
block|}
comment|/// \brief Whether this header is accessible from the specified module.
name|bool
name|isAccessibleFrom
argument_list|(
name|Module
operator|*
name|M
argument_list|)
decl|const
block|{
return|return
operator|!
operator|(
name|getRole
argument_list|()
operator|&
name|PrivateHeader
operator|)
operator|||
operator|(
name|M
operator|&&
name|M
operator|->
name|getTopLevelModule
argument_list|()
operator|==
name|getModule
argument_list|()
operator|->
name|getTopLevelModule
argument_list|()
operator|)
return|;
block|}
comment|// \brief Whether this known header is valid (i.e., it has an
comment|// associated module).
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|getPointer
argument_list|()
operator|!=
name|nullptr
return|;
block|}
block|}
empty_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
literal|1
operator|>
name|AdditionalModMapsSet
expr_stmt|;
name|private
label|:
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
name|SmallVector
operator|<
name|KnownHeader
operator|,
literal|1
operator|>>
name|HeadersMap
expr_stmt|;
comment|/// \brief Mapping from each header to the module that owns the contents of
comment|/// that header.
name|HeadersMap
name|Headers
decl_stmt|;
comment|/// \brief Mapping from directories with umbrella headers to the module
comment|/// that is generated from the umbrella header.
comment|///
comment|/// This mapping is used to map headers that haven't explicitly been named
comment|/// in the module map over to the module that includes them via its umbrella
comment|/// header.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|,
name|Module
operator|*
operator|>
name|UmbrellaDirs
expr_stmt|;
comment|/// \brief The set of attributes that can be attached to a module.
struct|struct
name|Attributes
block|{
name|Attributes
argument_list|()
operator|:
name|IsSystem
argument_list|()
operator|,
name|IsExternC
argument_list|()
operator|,
name|IsExhaustive
argument_list|()
operator|,
name|NoUndeclaredIncludes
argument_list|()
block|{}
comment|/// \brief Whether this is a system module.
name|unsigned
name|IsSystem
operator|:
literal|1
expr_stmt|;
comment|/// \brief Whether this is an extern "C" module.
name|unsigned
name|IsExternC
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is an exhaustive set of configuration macros.
name|unsigned
name|IsExhaustive
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
block|}
struct|;
comment|/// \brief A directory for which framework modules can be inferred.
struct|struct
name|InferredDirectory
block|{
name|InferredDirectory
argument_list|()
operator|:
name|InferModules
argument_list|()
block|{}
comment|/// \brief Whether to infer modules from this directory.
name|unsigned
name|InferModules
operator|:
literal|1
expr_stmt|;
comment|/// \brief The attributes to use for inferred modules.
name|Attributes
name|Attrs
decl_stmt|;
comment|/// \brief If \c InferModules is non-zero, the module map file that allowed
comment|/// inferred modules.  Otherwise, nullptr.
specifier|const
name|FileEntry
modifier|*
name|ModuleMapFile
decl_stmt|;
comment|/// \brief The names of modules that cannot be inferred within this
comment|/// directory.
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|2
operator|>
name|ExcludedModules
expr_stmt|;
block|}
struct|;
comment|/// \brief A mapping from directories to information about inferring
comment|/// framework modules from within those directories.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|,
name|InferredDirectory
operator|>
name|InferredDirectories
expr_stmt|;
comment|/// A mapping from an inferred module to the module map that allowed the
comment|/// inference.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Module
operator|*
operator|,
specifier|const
name|FileEntry
operator|*
operator|>
name|InferredModuleAllowedBy
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Module
operator|*
operator|,
name|AdditionalModMapsSet
operator|>
name|AdditionalModMaps
expr_stmt|;
comment|/// \brief Describes whether we haved parsed a particular file as a module
comment|/// map.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
name|bool
operator|>
name|ParsedModuleMap
expr_stmt|;
name|friend
name|class
name|ModuleMapParser
decl_stmt|;
comment|/// \brief Resolve the given export declaration into an actual export
comment|/// declaration.
comment|///
comment|/// \param Mod The module in which we're resolving the export declaration.
comment|///
comment|/// \param Unresolved The export declaration to resolve.
comment|///
comment|/// \param Complain Whether this routine should complain about unresolvable
comment|/// exports.
comment|///
comment|/// \returns The resolved export declaration, which will have a NULL pointer
comment|/// if the export could not be resolved.
name|Module
operator|::
name|ExportDecl
name|resolveExport
argument_list|(
argument|Module *Mod
argument_list|,
argument|const Module::UnresolvedExportDecl&Unresolved
argument_list|,
argument|bool Complain
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Resolve the given module id to an actual module.
comment|///
comment|/// \param Id The module-id to resolve.
comment|///
comment|/// \param Mod The module in which we're resolving the module-id.
comment|///
comment|/// \param Complain Whether this routine should complain about unresolvable
comment|/// module-ids.
comment|///
comment|/// \returns The resolved module, or null if the module-id could not be
comment|/// resolved.
name|Module
modifier|*
name|resolveModuleId
argument_list|(
specifier|const
name|ModuleId
operator|&
name|Id
argument_list|,
name|Module
operator|*
name|Mod
argument_list|,
name|bool
name|Complain
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Looks up the modules that \p File corresponds to.
comment|///
comment|/// If \p File represents a builtin header within Clang's builtin include
comment|/// directory, this also loads all of the module maps to see if it will get
comment|/// associated with a specific module (e.g. in /usr/include).
name|HeadersMap
operator|::
name|iterator
name|findKnownHeader
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|)
expr_stmt|;
comment|/// \brief Searches for a module whose umbrella directory contains \p File.
comment|///
comment|/// \param File The header to search for.
comment|///
comment|/// \param IntermediateDirs On success, contains the set of directories
comment|/// searched before finding \p File.
name|KnownHeader
name|findHeaderInUmbrellaDirs
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|>
operator|&
name|IntermediateDirs
argument_list|)
decl_stmt|;
comment|/// \brief Given that \p File is not in the Headers map, look it up within
comment|/// umbrella directories and find or create a module for it.
name|KnownHeader
name|findOrCreateModuleForHeaderInUmbrellaDir
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
function_decl|;
comment|/// \brief A convenience method to determine if \p File is (possibly nested)
comment|/// in an umbrella directory.
name|bool
name|isHeaderInUmbrellaDirs
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|,
literal|2
operator|>
name|IntermediateDirs
expr_stmt|;
return|return
name|static_cast
operator|<
name|bool
operator|>
operator|(
name|findHeaderInUmbrellaDirs
argument_list|(
name|File
argument_list|,
name|IntermediateDirs
argument_list|)
operator|)
return|;
block|}
name|Module
modifier|*
name|inferFrameworkModule
parameter_list|(
specifier|const
name|DirectoryEntry
modifier|*
name|FrameworkDir
parameter_list|,
name|Attributes
name|Attrs
parameter_list|,
name|Module
modifier|*
name|Parent
parameter_list|)
function_decl|;
name|public
label|:
comment|/// \brief Construct a new module map.
comment|///
comment|/// \param SourceMgr The source manager used to find module files and headers.
comment|/// This source manager should be shared with the header-search mechanism,
comment|/// since they will refer to the same headers.
comment|///
comment|/// \param Diags A diagnostic engine used for diagnostics.
comment|///
comment|/// \param LangOpts Language options for this translation unit.
comment|///
comment|/// \param Target The target for this translation unit.
name|ModuleMap
argument_list|(
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
specifier|const
name|TargetInfo
operator|*
name|Target
argument_list|,
name|HeaderSearch
operator|&
name|HeaderInfo
argument_list|)
expr_stmt|;
comment|/// \brief Destroy the module map.
comment|///
operator|~
name|ModuleMap
argument_list|()
expr_stmt|;
comment|/// \brief Set the target information.
name|void
name|setTarget
parameter_list|(
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|)
function_decl|;
comment|/// \brief Set the directory that contains Clang-supplied include
comment|/// files, such as our stdarg.h or tgmath.h.
name|void
name|setBuiltinIncludeDir
parameter_list|(
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
parameter_list|)
block|{
name|BuiltinIncludeDir
operator|=
name|Dir
expr_stmt|;
block|}
comment|/// \brief Get the directory that contains Clang-supplied include files.
specifier|const
name|DirectoryEntry
operator|*
name|getBuiltinDir
argument_list|()
specifier|const
block|{
return|return
name|BuiltinIncludeDir
return|;
block|}
comment|/// \brief Is this a compiler builtin header?
specifier|static
name|bool
name|isBuiltinHeader
parameter_list|(
name|StringRef
name|FileName
parameter_list|)
function_decl|;
comment|/// \brief Add a module map callback.
name|void
name|addModuleMapCallbacks
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleMapCallbacks
operator|>
name|Callback
argument_list|)
block|{
name|Callbacks
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Callback
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the module that owns the given header file, if any.
comment|///
comment|/// \param File The header file that is likely to be included.
comment|///
comment|/// \param AllowTextual If \c true and \p File is a textual header, return
comment|/// its owning module. Otherwise, no KnownHeader will be returned if the
comment|/// file is only known as a textual header.
comment|///
comment|/// \returns The module KnownHeader, which provides the module that owns the
comment|/// given header file.  The KnownHeader is default constructed to indicate
comment|/// that no module owns this header file.
name|KnownHeader
name|findModuleForHeader
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|bool
name|AllowTextual
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Retrieve all the modules that contain the given header file. This
comment|/// may not include umbrella modules, nor information from external sources,
comment|/// if they have not yet been inferred / loaded.
comment|///
comment|/// Typically, \ref findModuleForHeader should be used instead, as it picks
comment|/// the preferred module for the header.
name|ArrayRef
operator|<
name|KnownHeader
operator|>
name|findAllModulesForHeader
argument_list|(
argument|const FileEntry *File
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Reports errors if a module must not include a specific file.
comment|///
comment|/// \param RequestingModule The module including a file.
comment|///
comment|/// \param RequestingModuleIsModuleInterface \c true if the inclusion is in
comment|///        the interface of RequestingModule, \c false if it's in the
comment|///        implementation of RequestingModule. Value is ignored and
comment|///        meaningless if RequestingModule is nullptr.
comment|///
comment|/// \param FilenameLoc The location of the inclusion's filename.
comment|///
comment|/// \param Filename The included filename as written.
comment|///
comment|/// \param File The included file.
name|void
name|diagnoseHeaderInclusion
parameter_list|(
name|Module
modifier|*
name|RequestingModule
parameter_list|,
name|bool
name|RequestingModuleIsModuleInterface
parameter_list|,
name|SourceLocation
name|FilenameLoc
parameter_list|,
name|StringRef
name|Filename
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
function_decl|;
comment|/// \brief Determine whether the given header is part of a module
comment|/// marked 'unavailable'.
name|bool
name|isHeaderInUnavailableModule
argument_list|(
specifier|const
name|FileEntry
operator|*
name|Header
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Determine whether the given header is unavailable as part
comment|/// of the specified module.
name|bool
name|isHeaderUnavailableInModule
argument_list|(
specifier|const
name|FileEntry
operator|*
name|Header
argument_list|,
specifier|const
name|Module
operator|*
name|RequestingModule
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve a module with the given name.
comment|///
comment|/// \param Name The name of the module to look up.
comment|///
comment|/// \returns The named module, if known; otherwise, returns null.
name|Module
modifier|*
name|findModule
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve a module with the given name using lexical name lookup,
comment|/// starting at the given context.
comment|///
comment|/// \param Name The name of the module to look up.
comment|///
comment|/// \param Context The module context, from which we will perform lexical
comment|/// name lookup.
comment|///
comment|/// \returns The named module, if known; otherwise, returns null.
name|Module
modifier|*
name|lookupModuleUnqualified
argument_list|(
name|StringRef
name|Name
argument_list|,
name|Module
operator|*
name|Context
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve a module with the given name within the given context,
comment|/// using direct (qualified) name lookup.
comment|///
comment|/// \param Name The name of the module to look up.
comment|///
comment|/// \param Context The module for which we will look for a submodule. If
comment|/// null, we will look for a top-level module.
comment|///
comment|/// \returns The named submodule, if known; otherwose, returns null.
name|Module
modifier|*
name|lookupModuleQualified
argument_list|(
name|StringRef
name|Name
argument_list|,
name|Module
operator|*
name|Context
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Find a new module or submodule, or create it if it does not already
comment|/// exist.
comment|///
comment|/// \param Name The name of the module to find or create.
comment|///
comment|/// \param Parent The module that will act as the parent of this submodule,
comment|/// or NULL to indicate that this is a top-level module.
comment|///
comment|/// \param IsFramework Whether this is a framework module.
comment|///
comment|/// \param IsExplicit Whether this is an explicit submodule.
comment|///
comment|/// \returns The found or newly-created module, along with a boolean value
comment|/// that will be true if the module is newly-created.
name|std
operator|::
name|pair
operator|<
name|Module
operator|*
operator|,
name|bool
operator|>
name|findOrCreateModule
argument_list|(
argument|StringRef Name
argument_list|,
argument|Module *Parent
argument_list|,
argument|bool IsFramework
argument_list|,
argument|bool IsExplicit
argument_list|)
expr_stmt|;
comment|/// \brief Create a new module for a C++ Modules TS module interface unit.
comment|/// The module must not already exist, and will be configured for the current
comment|/// compilation.
comment|///
comment|/// Note that this also sets the current module to the newly-created module.
comment|///
comment|/// \returns The newly-created module.
name|Module
modifier|*
name|createModuleForInterfaceUnit
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \brief Infer the contents of a framework module map from the given
comment|/// framework directory.
name|Module
modifier|*
name|inferFrameworkModule
parameter_list|(
specifier|const
name|DirectoryEntry
modifier|*
name|FrameworkDir
parameter_list|,
name|bool
name|IsSystem
parameter_list|,
name|Module
modifier|*
name|Parent
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the module map file containing the definition of the given
comment|/// module.
comment|///
comment|/// \param Module The module whose module map file will be returned, if known.
comment|///
comment|/// \returns The file entry for the module map file containing the given
comment|/// module, or NULL if the module definition was inferred.
specifier|const
name|FileEntry
modifier|*
name|getContainingModuleMapFile
argument_list|(
specifier|const
name|Module
operator|*
name|Module
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the module map file that (along with the module name) uniquely
comment|/// identifies this module.
comment|///
comment|/// The particular module that \c Name refers to may depend on how the module
comment|/// was found in header search. However, the combination of \c Name and
comment|/// this module map will be globally unique for top-level modules. In the case
comment|/// of inferred modules, returns the module map that allowed the inference
comment|/// (e.g. contained 'module *'). Otherwise, returns
comment|/// getContainingModuleMapFile().
specifier|const
name|FileEntry
modifier|*
name|getModuleMapFileForUniquing
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|)
decl|const
decl_stmt|;
name|void
name|setInferredModuleAllowedBy
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|ModuleMap
parameter_list|)
function_decl|;
comment|/// \brief Get any module map files other than getModuleMapFileForUniquing(M)
comment|/// that define submodules of a top-level module \p M. This is cheaper than
comment|/// getting the module map file for each submodule individually, since the
comment|/// expected number of results is very small.
name|AdditionalModMapsSet
modifier|*
name|getAdditionalModuleMapFiles
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
block|{
name|auto
name|I
init|=
name|AdditionalModMaps
operator|.
name|find
argument_list|(
name|M
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|AdditionalModMaps
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
operator|&
name|I
operator|->
name|second
return|;
block|}
name|void
name|addAdditionalModuleMapFile
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|ModuleMap
parameter_list|)
block|{
name|AdditionalModMaps
index|[
name|M
index|]
operator|.
name|insert
argument_list|(
name|ModuleMap
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Resolve all of the unresolved exports in the given module.
comment|///
comment|/// \param Mod The module whose exports should be resolved.
comment|///
comment|/// \param Complain Whether to emit diagnostics for failures.
comment|///
comment|/// \returns true if any errors were encountered while resolving exports,
comment|/// false otherwise.
name|bool
name|resolveExports
parameter_list|(
name|Module
modifier|*
name|Mod
parameter_list|,
name|bool
name|Complain
parameter_list|)
function_decl|;
comment|/// \brief Resolve all of the unresolved uses in the given module.
comment|///
comment|/// \param Mod The module whose uses should be resolved.
comment|///
comment|/// \param Complain Whether to emit diagnostics for failures.
comment|///
comment|/// \returns true if any errors were encountered while resolving uses,
comment|/// false otherwise.
name|bool
name|resolveUses
parameter_list|(
name|Module
modifier|*
name|Mod
parameter_list|,
name|bool
name|Complain
parameter_list|)
function_decl|;
comment|/// \brief Resolve all of the unresolved conflicts in the given module.
comment|///
comment|/// \param Mod The module whose conflicts should be resolved.
comment|///
comment|/// \param Complain Whether to emit diagnostics for failures.
comment|///
comment|/// \returns true if any errors were encountered while resolving conflicts,
comment|/// false otherwise.
name|bool
name|resolveConflicts
parameter_list|(
name|Module
modifier|*
name|Mod
parameter_list|,
name|bool
name|Complain
parameter_list|)
function_decl|;
comment|/// \brief Sets the umbrella header of the given module to the given
comment|/// header.
name|void
name|setUmbrellaHeader
parameter_list|(
name|Module
modifier|*
name|Mod
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|UmbrellaHeader
parameter_list|,
name|Twine
name|NameAsWritten
parameter_list|)
function_decl|;
comment|/// \brief Sets the umbrella directory of the given module to the given
comment|/// directory.
name|void
name|setUmbrellaDir
parameter_list|(
name|Module
modifier|*
name|Mod
parameter_list|,
specifier|const
name|DirectoryEntry
modifier|*
name|UmbrellaDir
parameter_list|,
name|Twine
name|NameAsWritten
parameter_list|)
function_decl|;
comment|/// \brief Adds this header to the given module.
comment|/// \param Role The role of the header wrt the module.
name|void
name|addHeader
argument_list|(
name|Module
operator|*
name|Mod
argument_list|,
name|Module
operator|::
name|Header
name|Header
argument_list|,
name|ModuleHeaderRole
name|Role
argument_list|,
name|bool
name|Imported
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Marks this header as being excluded from the given module.
name|void
name|excludeHeader
argument_list|(
name|Module
operator|*
name|Mod
argument_list|,
name|Module
operator|::
name|Header
name|Header
argument_list|)
decl_stmt|;
comment|/// \brief Parse the given module map file, and record any modules we
comment|/// encounter.
comment|///
comment|/// \param File The file to be parsed.
comment|///
comment|/// \param IsSystem Whether this module map file is in a system header
comment|/// directory, and therefore should be considered a system module.
comment|///
comment|/// \param HomeDir The directory in which relative paths within this module
comment|///        map file will be resolved.
comment|///
comment|/// \param ID The FileID of the file to process, if we've already entered it.
comment|///
comment|/// \param Offset [inout] On input the offset at which to start parsing. On
comment|///        output, the offset at which the module map terminated.
comment|///
comment|/// \param ExternModuleLoc The location of the "extern module" declaration
comment|///        that caused us to load this module map file, if any.
comment|///
comment|/// \returns true if an error occurred, false otherwise.
name|bool
name|parseModuleMapFile
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|bool
name|IsSystem
parameter_list|,
specifier|const
name|DirectoryEntry
modifier|*
name|HomeDir
parameter_list|,
name|FileID
name|ID
init|=
name|FileID
argument_list|()
parameter_list|,
name|unsigned
modifier|*
name|Offset
init|=
name|nullptr
parameter_list|,
name|SourceLocation
name|ExternModuleLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Dump the contents of the module map, for debugging purposes.
name|void
name|dump
parameter_list|()
function_decl|;
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|Module
operator|*
operator|>
operator|::
name|const_iterator
name|module_iterator
expr_stmt|;
name|module_iterator
name|module_begin
argument_list|()
specifier|const
block|{
return|return
name|Modules
operator|.
name|begin
argument_list|()
return|;
block|}
name|module_iterator
name|module_end
argument_list|()
specifier|const
block|{
return|return
name|Modules
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LEX_MODULEMAP_H
end_comment

end_unit

