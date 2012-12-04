begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTMatchFinder.h - Structural query framework ----------*- C++ -*-===//
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
comment|//  Provides a way to construct an ASTConsumer that runs given matchers
end_comment

begin_comment
comment|//  over the AST and invokes a given callback on every match.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  The general idea is to construct a matcher expression that describes a
end_comment

begin_comment
comment|//  subtree match on the AST. Next, a callback that is executed every time the
end_comment

begin_comment
comment|//  expression matches is registered, and the matcher is run over the AST of
end_comment

begin_comment
comment|//  some code. Matched subexpressions can be bound to string IDs and easily
end_comment

begin_comment
comment|//  be accessed from the registered callback. The callback can than use the
end_comment

begin_comment
comment|//  AST nodes that the subexpressions matched on to output information about
end_comment

begin_comment
comment|//  the match or construct changes that can be applied to the code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Example:
end_comment

begin_comment
comment|//  class HandleMatch : public MatchFinder::MatchCallback {
end_comment

begin_comment
comment|//  public:
end_comment

begin_comment
comment|//    virtual void Run(const MatchFinder::MatchResult&Result) {
end_comment

begin_comment
comment|//      const CXXRecordDecl *Class =
end_comment

begin_comment
comment|//          Result.Nodes.GetDeclAs<CXXRecordDecl>("id");
end_comment

begin_comment
comment|//      ...
end_comment

begin_comment
comment|//    }
end_comment

begin_comment
comment|//  };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  int main(int argc, char **argv) {
end_comment

begin_comment
comment|//    ClangTool Tool(argc, argv);
end_comment

begin_comment
comment|//    MatchFinder finder;
end_comment

begin_comment
comment|//    finder.AddMatcher(Id("id", record(hasName("::a_namespace::AClass"))),
end_comment

begin_comment
comment|//                      new HandleMatch);
end_comment

begin_comment
comment|//    return Tool.Run(newFrontendActionFactory(&finder));
end_comment

begin_comment
comment|//  }
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
name|LLVM_CLANG_AST_MATCHERS_AST_MATCH_FINDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_MATCHERS_AST_MATCH_FINDER_H
end_define

begin_include
include|#
directive|include
file|"clang/ASTMatchers/ASTMatchers.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ast_matchers
block|{
comment|/// \brief A class to allow finding matches over the Clang AST.
comment|///
comment|/// After creation, you can add multiple matchers to the MatchFinder via
comment|/// calls to addMatcher(...).
comment|///
comment|/// Once all matchers are added, newASTConsumer() returns an ASTConsumer
comment|/// that will trigger the callbacks specified via addMatcher(...) when a match
comment|/// is found.
comment|///
comment|/// See ASTMatchers.h for more information about how to create matchers.
comment|///
comment|/// Not intended to be subclassed.
name|class
name|MatchFinder
block|{
name|public
label|:
comment|/// \brief Contains all information for a given match.
comment|///
comment|/// Every time a match is found, the MatchFinder will invoke the registered
comment|/// MatchCallback with a MatchResult containing information about the match.
struct|struct
name|MatchResult
block|{
name|MatchResult
argument_list|(
specifier|const
name|BoundNodes
operator|&
name|Nodes
argument_list|,
name|clang
operator|::
name|ASTContext
operator|*
name|Context
argument_list|)
expr_stmt|;
comment|/// \brief Contains the nodes bound on the current match.
comment|///
comment|/// This allows user code to easily extract matched AST nodes.
specifier|const
name|BoundNodes
name|Nodes
decl_stmt|;
comment|/// \brief Utilities for interpreting the matched AST structures.
comment|/// @{
name|clang
operator|::
name|ASTContext
operator|*
specifier|const
name|Context
expr_stmt|;
name|clang
operator|::
name|SourceManager
operator|*
specifier|const
name|SourceManager
expr_stmt|;
comment|/// @}
block|}
struct|;
comment|/// \brief Called when the Match registered for it was successfully found
comment|/// in the AST.
name|class
name|MatchCallback
block|{
name|public
label|:
name|virtual
operator|~
name|MatchCallback
argument_list|()
expr_stmt|;
comment|/// \brief Called on every match by the \c MatchFinder.
name|virtual
name|void
name|run
parameter_list|(
specifier|const
name|MatchResult
modifier|&
name|Result
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Called at the start of each translation unit.
comment|///
comment|/// Optionally override to do per translation unit tasks.
name|virtual
name|void
name|onStartOfTranslationUnit
parameter_list|()
block|{}
block|}
empty_stmt|;
comment|/// \brief Called when parsing is finished. Intended for testing only.
name|class
name|ParsingDoneTestCallback
block|{
name|public
label|:
name|virtual
operator|~
name|ParsingDoneTestCallback
argument_list|()
expr_stmt|;
name|virtual
name|void
name|run
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|MatchFinder
argument_list|()
expr_stmt|;
operator|~
name|MatchFinder
argument_list|()
expr_stmt|;
comment|/// \brief Adds a matcher to execute when running over the AST.
comment|///
comment|/// Calls 'Action' with the BoundNodes on every match.
comment|/// Adding more than one 'NodeMatch' allows finding different matches in a
comment|/// single pass over the AST.
comment|///
comment|/// Does not take ownership of 'Action'.
comment|/// @{
name|void
name|addMatcher
parameter_list|(
specifier|const
name|DeclarationMatcher
modifier|&
name|NodeMatch
parameter_list|,
name|MatchCallback
modifier|*
name|Action
parameter_list|)
function_decl|;
name|void
name|addMatcher
parameter_list|(
specifier|const
name|TypeMatcher
modifier|&
name|NodeMatch
parameter_list|,
name|MatchCallback
modifier|*
name|Action
parameter_list|)
function_decl|;
name|void
name|addMatcher
parameter_list|(
specifier|const
name|StatementMatcher
modifier|&
name|NodeMatch
parameter_list|,
name|MatchCallback
modifier|*
name|Action
parameter_list|)
function_decl|;
name|void
name|addMatcher
parameter_list|(
specifier|const
name|NestedNameSpecifierMatcher
modifier|&
name|NodeMatch
parameter_list|,
name|MatchCallback
modifier|*
name|Action
parameter_list|)
function_decl|;
name|void
name|addMatcher
parameter_list|(
specifier|const
name|NestedNameSpecifierLocMatcher
modifier|&
name|NodeMatch
parameter_list|,
name|MatchCallback
modifier|*
name|Action
parameter_list|)
function_decl|;
name|void
name|addMatcher
parameter_list|(
specifier|const
name|TypeLocMatcher
modifier|&
name|NodeMatch
parameter_list|,
name|MatchCallback
modifier|*
name|Action
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \brief Creates a clang ASTConsumer that finds all matches.
name|clang
operator|::
name|ASTConsumer
operator|*
name|newASTConsumer
argument_list|()
expr_stmt|;
comment|/// \brief Finds all matches on the given \c Node.
comment|///
comment|/// @{
name|void
name|findAll
parameter_list|(
specifier|const
name|Decl
modifier|&
name|Node
parameter_list|,
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
name|void
name|findAll
parameter_list|(
specifier|const
name|Stmt
modifier|&
name|Node
parameter_list|,
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \brief Registers a callback to notify the end of parsing.
comment|///
comment|/// The provided closure is called after parsing is done, before the AST is
comment|/// traversed. Useful for benchmarking.
comment|/// Each call to FindAll(...) will call the closure once.
name|void
name|registerTestCallbackAfterParsing
parameter_list|(
name|ParsingDoneTestCallback
modifier|*
name|ParsingDone
parameter_list|)
function_decl|;
name|private
label|:
comment|/// \brief For each \c DynTypedMatcher a \c MatchCallback that will be called
comment|/// when it matches.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|internal
operator|::
name|DynTypedMatcher
operator|*
operator|,
name|MatchCallback
operator|*
operator|>
expr|>
name|MatcherCallbackPairs
expr_stmt|;
comment|/// \brief Called when parsing is done.
name|ParsingDoneTestCallback
modifier|*
name|ParsingDone
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace ast_matchers
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
comment|// LLVM_CLANG_AST_MATCHERS_AST_MATCH_FINDER_H
end_comment

end_unit

