begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CustomCompilationDatabase.h --------------------------------------===//
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
comment|//  This file contains a hook to supply a custom \c CompilationDatabase
end_comment

begin_comment
comment|//  implementation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  The mechanism can be used by IDEs or non-public code bases to integrate with
end_comment

begin_comment
comment|//  their build system. Currently we support statically linking in an
end_comment

begin_comment
comment|//  implementation of \c findCompilationDatabaseForDirectory and enabling it
end_comment

begin_comment
comment|//  with -DUSE_CUSTOM_COMPILATION_DATABASE when compiling the Tooling library.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  FIXME: The strategy forward is to provide a plugin system that can load
end_comment

begin_comment
comment|//  custom compilation databases and make enabling that a build option.
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
name|LLVM_CLANG_TOOLING_CUSTOM_COMPILATION_DATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_CUSTOM_COMPILATION_DATABASE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
name|class
name|CompilationDatabase
decl_stmt|;
comment|/// \brief Returns a CompilationDatabase for the given \c Directory.
comment|///
comment|/// \c Directory can be any directory within a project. This methods will
comment|/// then try to find compilation database files in \c Directory or any of its
comment|/// parents. If a compilation database cannot be found or loaded, returns NULL.
name|clang
operator|::
name|tooling
operator|::
name|CompilationDatabase
operator|*
name|findCompilationDatabaseForDirectory
argument_list|(
argument|llvm::StringRef Directory
argument_list|)
expr_stmt|;
block|}
comment|// namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_CUSTOM_COMPILATION_DATABASE_H
end_comment

end_unit

