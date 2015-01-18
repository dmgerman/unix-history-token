begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Refactoring.h - Framework for clang refactoring tools --*- C++ -*-===//
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
comment|//  Interfaces supporting refactorings that span multiple translation units.
end_comment

begin_comment
comment|//  While single translation unit refactorings are supported via the Rewriter,
end_comment

begin_comment
comment|//  when refactoring multiple translation units changes must be stored in a
end_comment

begin_comment
comment|//  SourceManager independent form, duplicate changes need to be removed, and
end_comment

begin_comment
comment|//  all changes must be applied at once at the end of the refactoring so that
end_comment

begin_comment
comment|//  the code is always parseable.
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
name|LLVM_CLANG_TOOLING_REFACTORING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTORING_H
end_define

begin_include
include|#
directive|include
file|"clang/Tooling/Core/Replacement.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Tooling.h"
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
name|Rewriter
decl_stmt|;
name|namespace
name|tooling
block|{
comment|/// \brief A tool to run refactorings.
comment|///
comment|/// This is a refactoring specific version of \see ClangTool. FrontendActions
comment|/// passed to run() and runAndSave() should add replacements to
comment|/// getReplacements().
name|class
name|RefactoringTool
range|:
name|public
name|ClangTool
block|{
name|public
operator|:
comment|/// \see ClangTool::ClangTool.
name|RefactoringTool
argument_list|(
specifier|const
name|CompilationDatabase
operator|&
name|Compilations
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|SourcePaths
argument_list|)
block|;
comment|/// \brief Returns the set of replacements to which replacements should
comment|/// be added during the run of the tool.
name|Replacements
operator|&
name|getReplacements
argument_list|()
block|;
comment|/// \brief Call run(), apply all generated replacements, and immediately save
comment|/// the results to disk.
comment|///
comment|/// \returns 0 upon success. Non-zero upon failure.
name|int
name|runAndSave
argument_list|(
name|FrontendActionFactory
operator|*
name|ActionFactory
argument_list|)
block|;
comment|/// \brief Apply all stored replacements to the given Rewriter.
comment|///
comment|/// Replacement applications happen independently of the success of other
comment|/// applications.
comment|///
comment|/// \returns true if all replacements apply. false otherwise.
name|bool
name|applyAllReplacements
argument_list|(
name|Rewriter
operator|&
name|Rewrite
argument_list|)
block|;
name|private
operator|:
comment|/// \brief Write all refactored files to disk.
name|int
name|saveRewrittenFiles
argument_list|(
name|Rewriter
operator|&
name|Rewrite
argument_list|)
block|;
name|private
operator|:
name|Replacements
name|Replace
block|; }
decl_stmt|;
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
comment|// LLVM_CLANG_TOOLING_REFACTORING_H
end_comment

end_unit

