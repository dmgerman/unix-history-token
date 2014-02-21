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
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
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
file|<string>
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
name|class
name|ModuleMap
block|{
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diags
expr_stmt|;
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
comment|// The module that we are building; related to \c LangOptions::CurrentModule.
name|Module
modifier|*
name|CompilingModule
decl_stmt|;
name|public
label|:
comment|// The module that the .cc source file is associated with.
name|Module
modifier|*
name|SourceModule
decl_stmt|;
name|std
operator|::
name|string
name|SourceModuleName
expr_stmt|;
name|private
label|:
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
name|public
label|:
comment|/// \brief Describes the role of a module header.
enum|enum
name|ModuleHeaderRole
block|{
comment|/// \brief This header is normally included in the module.
name|NormalHeader
block|,
comment|/// \brief This header is included but private.
name|PrivateHeader
block|,
comment|/// \brief This header is explicitly excluded from the module.
name|ExcludedHeader
comment|// Caution: Adding an enumerator needs other changes.
comment|// Adjust the number of bits for KnownHeader::Storage.
comment|// Adjust the bitfield HeaderFileInfo::HeaderRole size.
comment|// Adjust the HeaderFileInfoTrait::ReadData streaming.
comment|// Adjust the HeaderFileInfoTrait::EmitData streaming.
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
literal|0
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
name|getRole
argument_list|()
operator|!=
name|ExcludedHeader
operator|&&
name|getModule
argument_list|()
operator|->
name|isAvailable
argument_list|()
return|;
block|}
comment|// \brief Whether this known header is valid (i.e., it has an
comment|// associated module).
name|LLVM_EXPLICIT
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
literal|0
return|;
block|}
block|}
empty_stmt|;
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
operator|>
expr|>
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
comment|/// \brief A directory for which framework modules can be inferred.
struct|struct
name|InferredDirectory
block|{
name|InferredDirectory
argument_list|()
operator|:
name|InferModules
argument_list|()
operator|,
name|InferSystemModules
argument_list|()
block|{ }
comment|/// \brief Whether to infer modules from this directory.
name|unsigned
name|InferModules
operator|:
literal|1
expr_stmt|;
comment|/// \brief Whether the modules we infer are [system] modules.
name|unsigned
name|InferSystemModules
range|:
literal|1
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
name|public
label|:
comment|/// \brief Construct a new module map.
comment|///
comment|/// \param SourceMgr The source manager used to find module files and headers.
comment|/// This source manager should be shared with the header-search mechanism,
comment|/// since they will refer to the same headers.
comment|///
comment|/// \param DC A diagnostic consumer that will be cloned for use in generating
comment|/// diagnostics.
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
name|DiagnosticConsumer
operator|&
name|DC
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
comment|/// \brief Retrieve the module that owns the given header file, if any.
comment|///
comment|/// \param File The header file that is likely to be included.
comment|///
comment|/// \param RequestingModule Specifies the module the header is intended to be
comment|/// used from.  Used to disambiguate if a header is present in multiple
comment|/// modules.
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
name|Module
modifier|*
name|RequestingModule
init|=
name|NULL
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
comment|/// \brief Determine whether we can infer a framework module a framework
comment|/// with the given name in the given
comment|///
comment|/// \param ParentDir The directory that is the parent of the framework
comment|/// directory.
comment|///
comment|/// \param Name The name of the module.
comment|///
comment|/// \param IsSystem Will be set to 'true' if the inferred module must be a
comment|/// system module.
comment|///
comment|/// \returns true if we are allowed to infer a framework module, and false
comment|/// otherwise.
name|bool
name|canInferFrameworkModule
argument_list|(
specifier|const
name|DirectoryEntry
operator|*
name|ParentDir
argument_list|,
name|StringRef
name|Name
argument_list|,
name|bool
operator|&
name|IsSystem
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Infer the contents of a framework module map from the given
comment|/// framework directory.
name|Module
modifier|*
name|inferFrameworkModule
parameter_list|(
name|StringRef
name|ModuleName
parameter_list|,
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
name|Module
operator|*
name|Module
argument_list|)
decl|const
decl_stmt|;
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
comment|/// \brief Infers the (sub)module based on the given source location and
comment|/// source manager.
comment|///
comment|/// \param Loc The location within the source that we are querying, along
comment|/// with its source manager.
comment|///
comment|/// \returns The module that owns this source location, or null if no
comment|/// module owns this source location.
name|Module
modifier|*
name|inferModuleFromLocation
parameter_list|(
name|FullSourceLoc
name|Loc
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
parameter_list|)
function_decl|;
comment|/// \brief Adds this header to the given module.
comment|/// \param Role The role of the header wrt the module.
name|void
name|addHeader
parameter_list|(
name|Module
modifier|*
name|Mod
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|Header
parameter_list|,
name|ModuleHeaderRole
name|Role
parameter_list|)
function_decl|;
comment|/// \brief Parse the given module map file, and record any modules we
comment|/// encounter.
comment|///
comment|/// \param File The file to be parsed.
comment|///
comment|/// \param IsSystem Whether this module map file is in a system header
comment|/// directory, and therefore should be considered a system module.
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

