begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RefactoringCallbacks.h - Structural query framework ----*- C++ -*-===//
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
comment|//  Provides callbacks to make common kinds of refactorings easy.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  The general idea is to construct a matcher expression that describes a
end_comment

begin_comment
comment|//  subtree match on the AST and then replace the corresponding source code
end_comment

begin_comment
comment|//  either by some specific text or some other AST node.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Example:
end_comment

begin_comment
comment|//  int main(int argc, char **argv) {
end_comment

begin_comment
comment|//    ClangTool Tool(argc, argv);
end_comment

begin_comment
comment|//    MatchFinder Finder;
end_comment

begin_comment
comment|//    ReplaceStmtWithText Callback("integer", "42");
end_comment

begin_comment
comment|//    Finder.AddMatcher(id("integer", expression(integerLiteral())), Callback);
end_comment

begin_comment
comment|//    return Tool.run(newFrontendActionFactory(&Finder));
end_comment

begin_comment
comment|//  }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This will replace all integer literals with "42".
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
name|LLVM_CLANG_TOOLING_REFACTORING_CALLBACKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTORING_CALLBACKS_H
end_define

begin_include
include|#
directive|include
file|"clang/ASTMatchers/ASTMatchFinder.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Refactoring.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
comment|/// \brief Base class for RefactoringCallbacks.
comment|///
comment|/// Collects \c tooling::Replacements while running.
name|class
name|RefactoringCallback
range|:
name|public
name|ast_matchers
operator|::
name|MatchFinder
operator|::
name|MatchCallback
block|{
name|public
operator|:
name|RefactoringCallback
argument_list|()
block|;
name|Replacements
operator|&
name|getReplacements
argument_list|()
block|;
name|protected
operator|:
name|Replacements
name|Replace
block|; }
decl_stmt|;
comment|/// \brief Replace the text of the statement bound to \c FromId with the text in
comment|/// \c ToText.
name|class
name|ReplaceStmtWithText
range|:
name|public
name|RefactoringCallback
block|{
name|public
operator|:
name|ReplaceStmtWithText
argument_list|(
argument|StringRef FromId
argument_list|,
argument|StringRef ToText
argument_list|)
block|;
name|void
name|run
argument_list|(
argument|const ast_matchers::MatchFinder::MatchResult&Result
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|FromId
block|;
name|std
operator|::
name|string
name|ToText
block|; }
decl_stmt|;
comment|/// \brief Replace the text of the statement bound to \c FromId with the text of
comment|/// the statement bound to \c ToId.
name|class
name|ReplaceStmtWithStmt
range|:
name|public
name|RefactoringCallback
block|{
name|public
operator|:
name|ReplaceStmtWithStmt
argument_list|(
argument|StringRef FromId
argument_list|,
argument|StringRef ToId
argument_list|)
block|;
name|void
name|run
argument_list|(
argument|const ast_matchers::MatchFinder::MatchResult&Result
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|FromId
block|;
name|std
operator|::
name|string
name|ToId
block|; }
decl_stmt|;
comment|/// \brief Replace an if-statement bound to \c Id with the outdented text of its
comment|/// body, choosing the consequent or the alternative based on whether
comment|/// \c PickTrueBranch is true.
name|class
name|ReplaceIfStmtWithItsBody
range|:
name|public
name|RefactoringCallback
block|{
name|public
operator|:
name|ReplaceIfStmtWithItsBody
argument_list|(
argument|StringRef Id
argument_list|,
argument|bool PickTrueBranch
argument_list|)
block|;
name|void
name|run
argument_list|(
argument|const ast_matchers::MatchFinder::MatchResult&Result
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|Id
block|;
specifier|const
name|bool
name|PickTrueBranch
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
comment|// LLVM_CLANG_TOOLING_REFACTORING_CALLBACKS_H
end_comment

end_unit

