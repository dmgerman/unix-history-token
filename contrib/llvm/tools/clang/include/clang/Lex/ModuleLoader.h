begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ModuleLoader.h - Module Loader Interface ---------------*- C++ -*-===//
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
comment|//  This file defines the ModuleLoader interface, which is responsible for
end_comment

begin_comment
comment|//  loading named modules.
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
name|LLVM_CLANG_LEX_MODULELOADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_MODULELOADER_H
end_define

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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GlobalModuleIndex
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|Module
decl_stmt|;
comment|/// \brief A sequence of identifier/location pairs used to describe a particular
comment|/// module or submodule, e.g., std.vector.
typedef|typedef
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SourceLocation
operator|>
expr|>
name|ModuleIdPath
expr_stmt|;
comment|/// \brief Describes the result of attempting to load a module.
name|class
name|ModuleLoadResult
block|{
name|public
label|:
enum|enum
name|LoadResultKind
block|{
comment|// We either succeeded or failed to load the named module.
name|Normal
block|,
comment|// The module exists, but does not actually contain the named submodule.
comment|// This should only happen if the named submodule was inferred from an
comment|// umbrella directory, but not actually part of the umbrella header.
name|MissingExpected
block|,
comment|// The module exists but cannot be imported due to a configuration mismatch.
name|ConfigMismatch
block|}
enum|;
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Module
operator|*
operator|,
literal|2
operator|,
name|LoadResultKind
operator|>
name|Storage
expr_stmt|;
name|ModuleLoadResult
argument_list|()
operator|:
name|Storage
argument_list|()
block|{ }
name|ModuleLoadResult
argument_list|(
name|Module
operator|*
name|M
argument_list|)
operator|:
name|Storage
argument_list|(
argument|M
argument_list|,
argument|Normal
argument_list|)
block|{}
name|ModuleLoadResult
argument_list|(
argument|LoadResultKind Kind
argument_list|)
operator|:
name|Storage
argument_list|(
argument|nullptr
argument_list|,
argument|Kind
argument_list|)
block|{}
name|operator
name|Module
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Storage
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Determines whether the module, which failed to load, was
comment|/// actually a submodule that we expected to see (based on implying the
comment|/// submodule from header structure), but didn't materialize in the actual
comment|/// module.
name|bool
name|isMissingExpected
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|getInt
argument_list|()
operator|==
name|MissingExpected
return|;
block|}
comment|/// \brief Determines whether the module failed to load due to a configuration
comment|/// mismatch with an explicitly-named .pcm file from the command line.
name|bool
name|isConfigMismatch
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|getInt
argument_list|()
operator|==
name|ConfigMismatch
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Abstract interface for a module loader.
comment|///
comment|/// This abstract interface describes a module loader, which is responsible
comment|/// for resolving a module name (e.g., "std") to an actual module file, and
comment|/// then loading that module.
name|class
name|ModuleLoader
block|{
comment|// Building a module if true.
name|bool
name|BuildingModule
decl_stmt|;
name|public
label|:
name|explicit
name|ModuleLoader
argument_list|(
argument|bool BuildingModule = false
argument_list|)
block|:
name|BuildingModule
argument_list|(
name|BuildingModule
argument_list|)
operator|,
name|HadFatalFailure
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|ModuleLoader
argument_list|()
expr_stmt|;
comment|/// \brief Returns true if this instance is building a module.
name|bool
name|buildingModule
argument_list|()
specifier|const
block|{
return|return
name|BuildingModule
return|;
block|}
comment|/// \brief Flag indicating whether this instance is building a module.
name|void
name|setBuildingModule
parameter_list|(
name|bool
name|BuildingModuleFlag
parameter_list|)
block|{
name|BuildingModule
operator|=
name|BuildingModuleFlag
expr_stmt|;
block|}
comment|/// \brief Attempt to load the given module.
comment|///
comment|/// This routine attempts to load the module described by the given
comment|/// parameters.
comment|///
comment|/// \param ImportLoc The location of the 'import' keyword.
comment|///
comment|/// \param Path The identifiers (and their locations) of the module
comment|/// "path", e.g., "std.vector" would be split into "std" and "vector".
comment|///
comment|/// \param Visibility The visibility provided for the names in the loaded
comment|/// module.
comment|///
comment|/// \param IsInclusionDirective Indicates that this module is being loaded
comment|/// implicitly, due to the presence of an inclusion directive. Otherwise,
comment|/// it is being loaded due to an import declaration.
comment|///
comment|/// \returns If successful, returns the loaded module. Otherwise, returns
comment|/// NULL to indicate that the module could not be loaded.
name|virtual
name|ModuleLoadResult
name|loadModule
argument_list|(
name|SourceLocation
name|ImportLoc
argument_list|,
name|ModuleIdPath
name|Path
argument_list|,
name|Module
operator|::
name|NameVisibilityKind
name|Visibility
argument_list|,
name|bool
name|IsInclusionDirective
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Attempt to load the given module from the specified source buffer. Does
comment|/// not make any submodule visible; for that, use loadModule or
comment|/// makeModuleVisible.
comment|///
comment|/// \param Loc The location at which the module was loaded.
comment|/// \param ModuleName The name of the module to build.
comment|/// \param Source The source of the module: a (preprocessed) module map.
name|virtual
name|void
name|loadModuleFromSource
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|ModuleName
parameter_list|,
name|StringRef
name|Source
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Make the given module visible.
name|virtual
name|void
name|makeModuleVisible
argument_list|(
name|Module
operator|*
name|Mod
argument_list|,
name|Module
operator|::
name|NameVisibilityKind
name|Visibility
argument_list|,
name|SourceLocation
name|ImportLoc
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief Load, create, or return global module.
comment|/// This function returns an existing global module index, if one
comment|/// had already been loaded or created, or loads one if it
comment|/// exists, or creates one if it doesn't exist.
comment|/// Also, importantly, if the index doesn't cover all the modules
comment|/// in the module map, it will be update to do so here, because
comment|/// of its use in searching for needed module imports and
comment|/// associated fixit messages.
comment|/// \param TriggerLoc The location for what triggered the load.
comment|/// \returns Returns null if load failed.
name|virtual
name|GlobalModuleIndex
modifier|*
name|loadGlobalModuleIndex
parameter_list|(
name|SourceLocation
name|TriggerLoc
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Check global module index for missing imports.
comment|/// \param Name The symbol name to look for.
comment|/// \param TriggerLoc The location for what triggered the load.
comment|/// \returns Returns true if any modules with that symbol found.
name|virtual
name|bool
name|lookupMissingImports
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|SourceLocation
name|TriggerLoc
parameter_list|)
init|=
literal|0
function_decl|;
name|bool
name|HadFatalFailure
decl_stmt|;
block|}
empty_stmt|;
comment|/// A module loader that doesn't know how to load modules.
name|class
name|TrivialModuleLoader
range|:
name|public
name|ModuleLoader
block|{
name|public
operator|:
name|ModuleLoadResult
name|loadModule
argument_list|(
argument|SourceLocation ImportLoc
argument_list|,
argument|ModuleIdPath Path
argument_list|,
argument|Module::NameVisibilityKind Visibility
argument_list|,
argument|bool IsInclusionDirective
argument_list|)
name|override
block|{
return|return
name|ModuleLoadResult
argument_list|()
return|;
block|}
name|void
name|loadModuleFromSource
argument_list|(
argument|SourceLocation ImportLoc
argument_list|,
argument|StringRef ModuleName
argument_list|,
argument|StringRef Source
argument_list|)
name|override
block|{}
name|void
name|makeModuleVisible
argument_list|(
argument|Module *Mod
argument_list|,
argument|Module::NameVisibilityKind Visibility
argument_list|,
argument|SourceLocation ImportLoc
argument_list|)
name|override
block|{}
name|GlobalModuleIndex
operator|*
name|loadGlobalModuleIndex
argument_list|(
argument|SourceLocation TriggerLoc
argument_list|)
name|override
block|{
return|return
name|nullptr
return|;
block|}
name|bool
name|lookupMissingImports
argument_list|(
argument|StringRef Name
argument_list|,
argument|SourceLocation TriggerLoc
argument_list|)
name|override
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;    }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

