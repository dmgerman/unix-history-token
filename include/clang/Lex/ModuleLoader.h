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
name|LLVM_CLANG_LEX_MODULE_LOADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_MODULE_LOADER_H
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
name|Storage
expr_stmt|;
name|public
label|:
name|ModuleLoadResult
argument_list|()
operator|:
name|Storage
argument_list|()
block|{ }
name|ModuleLoadResult
argument_list|(
argument|Module *module
argument_list|,
argument|bool missingExpected
argument_list|)
operator|:
name|Storage
argument_list|(
argument|module
argument_list|,
argument|missingExpected
argument_list|)
block|{ }
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
name|public
label|:
name|ModuleLoader
argument_list|()
operator|:
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
argument_list|,
name|bool
name|Complain
argument_list|)
init|=
literal|0
decl_stmt|;
name|bool
name|HadFatalFailure
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

