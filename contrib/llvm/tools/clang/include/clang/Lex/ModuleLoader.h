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
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
comment|/// \brief An opaque key that is used to describe the module and can be
comment|/// interpreted by the module loader itself.
typedef|typedef
name|void
modifier|*
name|ModuleKey
typedef|;
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
comment|/// \param ModuleName The name of the module to be loaded.
comment|/// \param ModuleNameLoc The location of the module name.
comment|///
comment|/// \returns If successful, a non-NULL module key describing this module.
comment|/// Otherwise, returns NULL to indicate that the module could not be
comment|/// loaded.
name|virtual
name|ModuleKey
name|loadModule
parameter_list|(
name|SourceLocation
name|ImportLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|ModuleName
parameter_list|,
name|SourceLocation
name|ModuleNameLoc
parameter_list|)
init|=
literal|0
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

