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
comment|/// The order of matches is guaranteed to be equivalent to doing a pre-order
comment|/// traversal on the AST, and applying the matchers in the order in which they
comment|/// were added to the MatchFinder.
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
comment|/// \brief Called at the end of each translation unit.
comment|///
comment|/// Optionally override to do per translation unit tasks.
name|virtual
name|void
name|onEndOfTranslationUnit
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
comment|/// \brief Adds a matcher to execute when running over the AST.
comment|///
comment|/// This is similar to \c addMatcher(), but it uses the dynamic interface. It
comment|/// is more flexible, but the lost type information enables a caller to pass
comment|/// a matcher that cannot match anything.
comment|///
comment|/// \returns \c true if the matcher is a valid top-level matcher, \c false
comment|///   otherwise.
name|bool
name|addDynamicMatcher
argument_list|(
specifier|const
name|internal
operator|::
name|DynTypedMatcher
operator|&
name|NodeMatch
argument_list|,
name|MatchCallback
operator|*
name|Action
argument_list|)
decl_stmt|;
comment|/// \brief Creates a clang ASTConsumer that finds all matches.
name|clang
operator|::
name|ASTConsumer
operator|*
name|newASTConsumer
argument_list|()
expr_stmt|;
comment|/// \brief Calls the registered callbacks on all matches on the given \p Node.
comment|///
comment|/// Note that there can be multiple matches on a single node, for
comment|/// example when using decl(forEachDescendant(stmt())).
comment|///
comment|/// @{
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|match
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTContext&Context
argument_list|)
block|{
name|match
argument_list|(
name|clang
operator|::
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Context
argument_list|)
block|;   }
name|void
name|match
argument_list|(
specifier|const
name|clang
operator|::
name|ast_type_traits
operator|::
name|DynTypedNode
operator|&
name|Node
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|)
expr_stmt|;
comment|/// @}
comment|/// \brief Finds all matches in the given AST.
name|void
name|matchAST
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
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
name|internal
operator|::
name|DynTypedMatcher
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
comment|/// \brief Returns the results of matching \p Matcher on \p Node.
comment|///
comment|/// Collects the \c BoundNodes of all callback invocations when matching
comment|/// \p Matcher on \p Node and returns the collected results.
comment|///
comment|/// Multiple results occur when using matchers like \c forEachDescendant,
comment|/// which generate a result for each sub-match.
comment|///
comment|/// \see selectFirst
comment|/// @{
name|template
operator|<
name|typename
name|MatcherT
operator|,
name|typename
name|NodeT
operator|>
name|SmallVector
operator|<
name|BoundNodes
operator|,
literal|1
operator|>
name|match
argument_list|(
argument|MatcherT Matcher
argument_list|,
argument|const NodeT&Node
argument_list|,
argument|ASTContext&Context
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|MatcherT
operator|>
name|SmallVector
operator|<
name|BoundNodes
operator|,
literal|1
operator|>
name|match
argument_list|(
argument|MatcherT Matcher
argument_list|,
argument|const ast_type_traits::DynTypedNode&Node
argument_list|,
argument|ASTContext&Context
argument_list|)
expr_stmt|;
comment|/// @}
comment|/// \brief Returns the first result of type \c NodeT bound to \p BoundTo.
comment|///
comment|/// Returns \c NULL if there is no match, or if the matching node cannot be
comment|/// casted to \c NodeT.
comment|///
comment|/// This is useful in combanation with \c match():
comment|/// \code
comment|///   Decl *D = selectFirst<Decl>("id", match(Matcher.bind("id"),
comment|///                                           Node, Context));
comment|/// \endcode
name|template
operator|<
name|typename
name|NodeT
operator|>
name|NodeT
operator|*
name|selectFirst
argument_list|(
argument|StringRef BoundTo
argument_list|,
argument|const SmallVectorImpl<BoundNodes>&Results
argument_list|)
block|{
for|for
control|(
name|SmallVectorImpl
operator|<
name|BoundNodes
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|Results
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Results
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
if|if
condition|(
name|NodeT
modifier|*
name|Node
init|=
name|I
operator|->
name|getNodeAs
operator|<
name|NodeT
operator|>
operator|(
name|BoundTo
operator|)
condition|)
return|return
name|Node
return|;
block|}
return|return
name|NULL
return|;
block|}
name|namespace
name|internal
block|{
name|class
name|CollectMatchesCallback
range|:
name|public
name|MatchFinder
operator|::
name|MatchCallback
block|{
name|public
operator|:
name|virtual
name|void
name|run
argument_list|(
argument|const MatchFinder::MatchResult&Result
argument_list|)
block|{
name|Nodes
operator|.
name|push_back
argument_list|(
name|Result
operator|.
name|Nodes
argument_list|)
block|;   }
name|SmallVector
operator|<
name|BoundNodes
block|,
literal|1
operator|>
name|Nodes
block|; }
decl_stmt|;
block|}
name|template
operator|<
name|typename
name|MatcherT
operator|>
name|SmallVector
operator|<
name|BoundNodes
operator|,
literal|1
operator|>
name|match
argument_list|(
argument|MatcherT Matcher
argument_list|,
argument|const ast_type_traits::DynTypedNode&Node
argument_list|,
argument|ASTContext&Context
argument_list|)
block|{
name|internal
operator|::
name|CollectMatchesCallback
name|Callback
block|;
name|MatchFinder
name|Finder
block|;
name|Finder
operator|.
name|addMatcher
argument_list|(
name|Matcher
argument_list|,
operator|&
name|Callback
argument_list|)
block|;
name|Finder
operator|.
name|match
argument_list|(
name|Node
argument_list|,
name|Context
argument_list|)
block|;
return|return
name|Callback
operator|.
name|Nodes
return|;
block|}
name|template
operator|<
name|typename
name|MatcherT
operator|,
name|typename
name|NodeT
operator|>
name|SmallVector
operator|<
name|BoundNodes
operator|,
literal|1
operator|>
name|match
argument_list|(
argument|MatcherT Matcher
argument_list|,
argument|const NodeT&Node
argument_list|,
argument|ASTContext&Context
argument_list|)
block|{
return|return
name|match
argument_list|(
name|Matcher
argument_list|,
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Context
argument_list|)
return|;
block|}
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

