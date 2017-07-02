begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- USRLocFinder.h - Clang refactoring library -----------------------===//
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
comment|/// \brief Provides functionality for finding all instances of a USR in a given
end_comment

begin_comment
comment|/// AST.
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
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_LOC_FINDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_LOC_FINDER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/AST.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Core/Replacement.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Refactoring/AtomicChange.h"
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
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
comment|/// Create atomic changes for renaming all symbol references which are
comment|/// identified by the USRs set to a given new name.
comment|///
comment|/// \param USRs The set containing USRs of a particular old symbol.
comment|/// \param NewName The new name to replace old symbol name.
comment|/// \param TranslationUnitDecl The translation unit declaration.
comment|///
comment|/// \return Atomic changes for renaming.
name|std
operator|::
name|vector
operator|<
name|tooling
operator|::
name|AtomicChange
operator|>
name|createRenameAtomicChanges
argument_list|(
argument|llvm::ArrayRef<std::string> USRs
argument_list|,
argument|llvm::StringRef NewName
argument_list|,
argument|Decl *TranslationUnitDecl
argument_list|)
expr_stmt|;
comment|// FIXME: make this an AST matcher. Wouldn't that be awesome??? I agree!
name|std
operator|::
name|vector
operator|<
name|SourceLocation
operator|>
name|getLocationsOfUSRs
argument_list|(
argument|const std::vector<std::string>&USRs
argument_list|,
argument|llvm::StringRef PrevName
argument_list|,
argument|Decl *Decl
argument_list|)
expr_stmt|;
block|}
comment|// end namespace tooling
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
comment|// LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_LOC_FINDER_H
end_comment

end_unit

