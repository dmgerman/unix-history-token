begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTMatchersInternal.h - Structural query framework -----*- C++ -*-===//
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
comment|//  Implements the base layer of the matcher framework.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Matchers are methods that return a Matcher<T> which provides a method
end_comment

begin_comment
comment|//  Matches(...) which is a predicate on an AST node. The Matches method's
end_comment

begin_comment
comment|//  parameters define the context of the match, which allows matchers to recurse
end_comment

begin_comment
comment|//  or store the current node as bound to a specific string, so that it can be
end_comment

begin_comment
comment|//  retrieved later.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  In general, matchers have two parts:
end_comment

begin_comment
comment|//  1. A function Matcher<T> MatcherName(<arguments>) which returns a Matcher<T>
end_comment

begin_comment
comment|//     based on the arguments and optionally on template type deduction based
end_comment

begin_comment
comment|//     on the arguments. Matcher<T>s form an implicit reverse hierarchy
end_comment

begin_comment
comment|//     to clang's AST class hierarchy, meaning that you can use a Matcher<Base>
end_comment

begin_comment
comment|//     everywhere a Matcher<Derived> is required.
end_comment

begin_comment
comment|//  2. An implementation of a class derived from MatcherInterface<T>.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  The matcher functions are defined in ASTMatchers.h. To make it possible
end_comment

begin_comment
comment|//  to implement both the matcher function and the implementation of the matcher
end_comment

begin_comment
comment|//  interface in one place, ASTMatcherMacros.h defines macros that allow
end_comment

begin_comment
comment|//  implementing a matcher in a single place.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file contains the base classes needed to construct the actual matchers.
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
name|LLVM_CLANG_AST_MATCHERS_AST_MATCHERS_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_MATCHERS_AST_MATCHERS_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/VariadicFunction.h"
end_include

begin_include
include|#
directive|include
file|<map>
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
name|ast_matchers
block|{
comment|/// FIXME: Move into the llvm support library.
name|template
operator|<
name|bool
operator|>
expr|struct
name|CompileAssert
block|{}
expr_stmt|;
define|#
directive|define
name|TOOLING_COMPILE_ASSERT
parameter_list|(
name|Expr
parameter_list|,
name|Msg
parameter_list|)
define|\
value|typedef CompileAssert<(bool(Expr))> Msg[bool(Expr) ? 1 : -1]
name|class
name|BoundNodes
decl_stmt|;
name|namespace
name|internal
block|{
name|class
name|BoundNodesTreeBuilder
decl_stmt|;
comment|/// \brief A tree of bound nodes in match results.
comment|///
comment|/// If a match can contain multiple matches on the same node with different
comment|/// matching subexpressions, BoundNodesTree contains a branch for each of
comment|/// those matching subexpressions.
comment|///
comment|/// BoundNodesTree's are created during the matching process; when a match
comment|/// is found, we iterate over the tree and create a BoundNodes object containing
comment|/// the union of all bound nodes on the path from the root to a each leaf.
name|class
name|BoundNodesTree
block|{
name|public
label|:
comment|/// \brief A visitor interface to visit all BoundNodes results for a
comment|/// BoundNodesTree.
name|class
name|Visitor
block|{
name|public
label|:
name|virtual
operator|~
name|Visitor
argument_list|()
block|{}
comment|/// \brief Called multiple times during a single call to VisitMatches(...).
comment|///
comment|/// 'BoundNodesView' contains the bound nodes for a single match.
name|virtual
name|void
name|visitMatch
argument_list|(
specifier|const
name|BoundNodes
operator|&
name|BoundNodesView
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|BoundNodesTree
argument_list|()
expr_stmt|;
comment|/// \brief Create a BoundNodesTree from pre-filled maps of bindings.
name|BoundNodesTree
argument_list|(
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
specifier|const
name|Decl
operator|*
operator|>
operator|&
name|DeclBindings
argument_list|,
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
specifier|const
name|Stmt
operator|*
operator|>
operator|&
name|StmtBindings
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|BoundNodesTree
operator|>
name|RecursiveBindings
argument_list|)
expr_stmt|;
comment|/// \brief Adds all bound nodes to bound_nodes_builder.
name|void
name|copyTo
argument_list|(
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Visits all matches that this BoundNodesTree represents.
comment|///
comment|/// The ownership of 'ResultVisitor' remains at the caller.
name|void
name|visitMatches
parameter_list|(
name|Visitor
modifier|*
name|ResultVisitor
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|visitMatchesRecursively
argument_list|(
name|Visitor
operator|*
name|ResultVistior
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
specifier|const
name|Decl
operator|*
operator|>
name|DeclBindings
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
specifier|const
name|Stmt
operator|*
operator|>
name|StmtBindings
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|copyBindingsTo
argument_list|(
argument|const T& bindings
argument_list|,
argument|BoundNodesTreeBuilder* Builder
argument_list|)
specifier|const
expr_stmt|;
comment|// FIXME: Find out whether we want to use different data structures here -
comment|// first benchmarks indicate that it doesn't matter though.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
specifier|const
name|Decl
operator|*
operator|>
name|DeclBindings
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
specifier|const
name|Stmt
operator|*
operator|>
name|StmtBindings
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BoundNodesTree
operator|>
name|RecursiveBindings
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Creates BoundNodesTree objects.
comment|///
comment|/// The tree builder is used during the matching process to insert the bound
comment|/// nodes from the Id matcher.
name|class
name|BoundNodesTreeBuilder
block|{
name|public
label|:
name|BoundNodesTreeBuilder
argument_list|()
expr_stmt|;
comment|/// \brief Add a binding from an id to a node.
comment|///
comment|/// FIXME: Add overloads for all AST base types.
comment|/// @{
name|void
name|setBinding
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Id
argument_list|,
specifier|const
name|Decl
operator|*
name|Node
argument_list|)
decl_stmt|;
name|void
name|setBinding
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Id
argument_list|,
specifier|const
name|Stmt
operator|*
name|Node
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// \brief Adds a branch in the tree.
name|void
name|addMatch
parameter_list|(
specifier|const
name|BoundNodesTree
modifier|&
name|Bindings
parameter_list|)
function_decl|;
comment|/// \brief Returns a BoundNodes object containing all current bindings.
name|BoundNodesTree
name|build
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|BoundNodesTreeBuilder
argument_list|(
specifier|const
name|BoundNodesTreeBuilder
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|BoundNodesTreeBuilder
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
specifier|const
name|Decl
operator|*
operator|>
name|DeclBindings
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
specifier|const
name|Stmt
operator|*
operator|>
name|StmtBindings
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BoundNodesTree
operator|>
name|RecursiveBindings
expr_stmt|;
block|}
empty_stmt|;
name|class
name|ASTMatchFinder
decl_stmt|;
comment|/// \brief Generic interface for matchers on an AST node of type T.
comment|///
comment|/// Implement this if your matcher may need to inspect the children or
comment|/// descendants of the node or bind matched nodes to names. If you are
comment|/// writing a simple matcher that only inspects properties of the
comment|/// current node and doesn't care about its children or descendants,
comment|/// implement SingleNodeMatcherInterface instead.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MatcherInterface
operator|:
name|public
name|llvm
operator|::
name|RefCountedBaseVPTR
block|{
name|public
operator|:
name|virtual
operator|~
name|MatcherInterface
argument_list|()
block|{}
comment|/// \brief Returns true if 'Node' can be matched.
comment|///
comment|/// May bind 'Node' to an ID via 'Builder', or recurse into
comment|/// the AST via 'Finder'.
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
operator|=
literal|0
block|; }
expr_stmt|;
comment|/// \brief Interface for matchers that only evaluate properties on a single node.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SingleNodeMatcherInterface
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
comment|/// \brief Returns true if the matcher matches the provided node.
comment|///
comment|/// A subclass must implement this instead of Matches().
name|virtual
name|bool
name|matchesNode
argument_list|(
argument|const T&Node
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|private
operator|:
comment|/// Implements MatcherInterface::Matches.
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *
comment|/* Finder */
argument_list|,
argument|BoundNodesTreeBuilder *
comment|/*  Builder */
argument_list|)
specifier|const
block|{
return|return
name|matchesNode
argument_list|(
name|Node
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Wrapper of a MatcherInterface<T> *that allows copying.
comment|///
comment|/// A Matcher<Base> can be used anywhere a Matcher<Derived> is
comment|/// required. This establishes an is-a relationship which is reverse
comment|/// to the AST hierarchy. In other words, Matcher<T> is contravariant
comment|/// with respect to T. The relationship is built via a type conversion
comment|/// operator rather than a type hierarchy to be able to templatize the
comment|/// type hierarchy instead of spelling it out.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Matcher
block|{
name|public
operator|:
comment|/// \brief Takes ownership of the provided implementation pointer.
name|explicit
name|Matcher
argument_list|(
name|MatcherInterface
operator|<
name|T
operator|>
operator|*
name|Implementation
argument_list|)
operator|:
name|Implementation
argument_list|(
argument|Implementation
argument_list|)
block|{}
comment|/// \brief Forwards the call to the underlying MatcherInterface<T> pointer.
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|Implementation
operator|->
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
comment|/// \brief Implicitly converts this object to a Matcher<Derived>.
comment|///
comment|/// Requires Derived to be derived from T.
name|template
operator|<
name|typename
name|Derived
operator|>
name|operator
name|Matcher
operator|<
name|Derived
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|Derived
operator|>
operator|(
name|new
name|ImplicitCastMatcher
operator|<
name|Derived
operator|>
operator|(
operator|*
name|this
operator|)
operator|)
return|;
block|}
comment|/// \brief Returns an ID that uniquely identifies the matcher.
name|uint64_t
name|getID
argument_list|()
specifier|const
block|{
comment|/// FIXME: Document the requirements this imposes on matcher
comment|/// implementations (no new() implementation_ during a Matches()).
return|return
name|reinterpret_cast
operator|<
name|uint64_t
operator|>
operator|(
name|Implementation
operator|.
name|getPtr
argument_list|()
operator|)
return|;
block|}
name|private
operator|:
comment|/// \brief Allows conversion from Matcher<T> to Matcher<Derived> if Derived
comment|/// is derived from T.
name|template
operator|<
name|typename
name|Derived
operator|>
name|class
name|ImplicitCastMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|Derived
operator|>
block|{
name|public
operator|:
name|explicit
name|ImplicitCastMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|From
argument_list|)
operator|:
name|From
argument_list|(
argument|From
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const Derived&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|From
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|From
block|;   }
block|;
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|MatcherInterface
operator|<
name|T
operator|>
expr|>
name|Implementation
block|; }
block|;
comment|// class Matcher
comment|/// \brief A convenient helper for creating a Matcher<T> without specifying
comment|/// the template type argument.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|makeMatcher
argument_list|(
argument|MatcherInterface<T> *Implementation
argument_list|)
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|Implementation
operator|)
return|;
block|}
comment|/// \brief Matches declarations for QualType and CallExpr.
comment|///
comment|/// Type argument DeclMatcherT is required by PolymorphicMatcherWithParam1 but
comment|/// not actually used.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|DeclMatcherT
operator|>
name|class
name|HasDeclarationMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|llvm
operator|::
name|is_same
operator|<
name|DeclMatcherT
operator|,
name|Matcher
operator|<
name|Decl
operator|>
expr|>
operator|::
name|value
operator|)
argument_list|,
name|instantiated_with_wrong_types
argument_list|)
block|;
name|public
operator|:
name|explicit
name|HasDeclarationMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|Decl
operator|>
operator|&
name|InnerMatcher
argument_list|)
operator|:
name|InnerMatcher
argument_list|(
argument|InnerMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|matchesSpecialized
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
name|private
operator|:
comment|/// \brief Extracts the CXXRecordDecl of a QualType and returns whether the
comment|/// inner matcher matches on it.
name|bool
name|matchesSpecialized
argument_list|(
argument|const QualType&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
comment|/// FIXME: Add other ways to convert...
if|if
condition|(
name|Node
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|false
return|;
name|CXXRecordDecl
operator|*
name|NodeAsRecordDecl
operator|=
name|Node
operator|->
name|getAsCXXRecordDecl
argument_list|()
block|;
return|return
name|NodeAsRecordDecl
operator|!=
name|NULL
operator|&&
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
name|NodeAsRecordDecl
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
comment|/// \brief Extracts the Decl of the callee of a CallExpr and returns whether
comment|/// the inner matcher matches on it.
name|bool
name|matchesSpecialized
argument_list|(
argument|const CallExpr&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
specifier|const
name|Decl
operator|*
name|NodeAsDecl
operator|=
name|Node
operator|.
name|getCalleeDecl
argument_list|()
block|;
return|return
name|NodeAsDecl
operator|!=
name|NULL
operator|&&
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
name|NodeAsDecl
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
comment|/// \brief Extracts the Decl of the constructor call and returns whether the
comment|/// inner matcher matches on it.
name|bool
name|matchesSpecialized
argument_list|(
argument|const CXXConstructExpr&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
specifier|const
name|Decl
operator|*
name|NodeAsDecl
operator|=
name|Node
operator|.
name|getConstructor
argument_list|()
block|;
return|return
name|NodeAsDecl
operator|!=
name|NULL
operator|&&
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
name|NodeAsDecl
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
specifier|const
name|Matcher
operator|<
name|Decl
operator|>
name|InnerMatcher
block|; }
expr_stmt|;
comment|/// \brief IsBaseType<T>::value is true if T is a "base" type in the AST
comment|/// node class hierarchies (i.e. if T is Decl, Stmt, or QualType).
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IsBaseType
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
operator|(
name|llvm
operator|::
name|is_same
operator|<
name|T
operator|,
name|Decl
operator|>
operator|::
name|value
operator|||
name|llvm
operator|::
name|is_same
operator|<
name|T
operator|,
name|Stmt
operator|>
operator|::
name|value
operator|||
name|llvm
operator|::
name|is_same
operator|<
name|T
operator|,
name|QualType
operator|>
operator|::
name|value
operator|||
name|llvm
operator|::
name|is_same
operator|<
name|T
operator|,
name|CXXCtorInitializer
operator|>
operator|::
name|value
operator|)
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|bool
name|IsBaseType
operator|<
name|T
operator|>
operator|::
name|value
expr_stmt|;
comment|/// \brief Interface that can match any AST base node type and contains default
comment|/// implementations returning false.
name|class
name|UntypedBaseMatcher
range|:
name|public
name|llvm
operator|::
name|RefCountedBaseVPTR
block|{
name|public
operator|:
name|virtual
operator|~
name|UntypedBaseMatcher
argument_list|()
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const Decl&DeclNode
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|matches
argument_list|(
argument|const QualType&TypeNode
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|matches
argument_list|(
argument|const Stmt&StmtNode
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|matches
argument_list|(
argument|const CXXCtorInitializer&CtorInitNode
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Returns a unique ID for the matcher.
name|virtual
name|uint64_t
name|getID
argument_list|()
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
comment|/// \brief An UntypedBaseMatcher that overwrites the Matches(...) method for
comment|/// node type T. T must be an AST base type.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypedBaseMatcher
operator|:
name|public
name|UntypedBaseMatcher
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
name|IsBaseType
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
name|typed_base_matcher_can_only_be_used_with_base_type
argument_list|)
block|;
name|public
operator|:
name|explicit
name|TypedBaseMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher
argument_list|)
operator|:
name|InnerMatcher
argument_list|(
argument|InnerMatcher
argument_list|)
block|{}
name|using
name|UntypedBaseMatcher
operator|::
name|matches
block|;
comment|/// \brief Implements UntypedBaseMatcher::Matches.
comment|///
comment|/// Since T is guaranteed to be a "base" AST node type, this method is
comment|/// guaranteed to override one of the matches() methods from
comment|/// UntypedBaseMatcher.
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|InnerMatcher
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
comment|/// \brief Implements UntypedBaseMatcher::getID.
name|virtual
name|uint64_t
name|getID
argument_list|()
specifier|const
block|{
return|return
name|InnerMatcher
operator|.
name|getID
argument_list|()
return|;
block|}
name|private
operator|:
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher
block|; }
expr_stmt|;
comment|/// \brief Interface that allows matchers to traverse the AST.
comment|/// FIXME: Find a better name.
comment|///
comment|/// This provides two entry methods for each base node type in the AST:
comment|/// - matchesChildOf:
comment|///   Matches a matcher on every child node of the given node. Returns true
comment|///   if at least one child node could be matched.
comment|/// - matchesDescendantOf:
comment|///   Matches a matcher on all descendant nodes of the given node. Returns true
comment|///   if at least one descendant matched.
name|class
name|ASTMatchFinder
block|{
name|public
label|:
comment|/// \brief Defines how we descend a level in the AST when we pass
comment|/// through expressions.
enum|enum
name|TraversalKind
block|{
comment|/// Will traverse any child nodes.
name|TK_AsIs
block|,
comment|/// Will not traverse implicit casts and parentheses.
name|TK_IgnoreImplicitCastsAndParentheses
block|}
enum|;
comment|/// \brief Defines how bindings are processed on recursive matches.
enum|enum
name|BindKind
block|{
comment|/// Stop at the first match and only bind the first match.
name|BK_First
block|,
comment|/// Create results for all combinations of bindings that match.
name|BK_All
block|}
enum|;
name|virtual
operator|~
name|ASTMatchFinder
argument_list|()
block|{}
comment|/// \brief Returns true if the given class is directly or indirectly derived
comment|/// from a base type matching \c base.
comment|///
comment|/// A class is considered to be also derived from itself.
name|virtual
name|bool
name|classIsDerivedFrom
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Declaration
argument_list|,
specifier|const
name|Matcher
operator|<
name|NamedDecl
operator|>
operator|&
name|Base
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|// FIXME: Implement for other base nodes.
name|virtual
name|bool
name|matchesChildOf
parameter_list|(
specifier|const
name|Decl
modifier|&
name|DeclNode
parameter_list|,
specifier|const
name|UntypedBaseMatcher
modifier|&
name|BaseMatcher
parameter_list|,
name|BoundNodesTreeBuilder
modifier|*
name|Builder
parameter_list|,
name|TraversalKind
name|Traverse
parameter_list|,
name|BindKind
name|Bind
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|matchesChildOf
parameter_list|(
specifier|const
name|Stmt
modifier|&
name|StmtNode
parameter_list|,
specifier|const
name|UntypedBaseMatcher
modifier|&
name|BaseMatcher
parameter_list|,
name|BoundNodesTreeBuilder
modifier|*
name|Builder
parameter_list|,
name|TraversalKind
name|Traverse
parameter_list|,
name|BindKind
name|Bind
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|matchesDescendantOf
parameter_list|(
specifier|const
name|Decl
modifier|&
name|DeclNode
parameter_list|,
specifier|const
name|UntypedBaseMatcher
modifier|&
name|BaseMatcher
parameter_list|,
name|BoundNodesTreeBuilder
modifier|*
name|Builder
parameter_list|,
name|BindKind
name|Bind
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|matchesDescendantOf
parameter_list|(
specifier|const
name|Stmt
modifier|&
name|StmtNode
parameter_list|,
specifier|const
name|UntypedBaseMatcher
modifier|&
name|BaseMatcher
parameter_list|,
name|BoundNodesTreeBuilder
modifier|*
name|Builder
parameter_list|,
name|BindKind
name|Bind
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Converts a \c Matcher<T> to a matcher of desired type \c To by
comment|/// "adapting" a \c To into a \c T.
comment|///
comment|/// The \c ArgumentAdapterT argument specifies how the adaptation is done.
comment|///
comment|/// For example:
comment|///   \c ArgumentAdaptingMatcher<HasMatcher, T>(InnerMatcher);
comment|/// Given that \c InnerMatcher is of type \c Matcher<T>, this returns a matcher
comment|/// that is convertible into any matcher of type \c To by constructing
comment|/// \c HasMatcher<To, T>(InnerMatcher).
comment|///
comment|/// If a matcher does not need knowledge about the inner type, prefer to use
comment|/// PolymorphicMatcherWithParam1.
name|template
operator|<
name|template
operator|<
name|typename
name|ToArg
operator|,
name|typename
name|FromArg
operator|>
name|class
name|ArgumentAdapterT
operator|,
name|typename
name|T
operator|>
name|class
name|ArgumentAdaptingMatcher
block|{
name|public
operator|:
name|explicit
name|ArgumentAdaptingMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher
argument_list|)
operator|:
name|InnerMatcher
argument_list|(
argument|InnerMatcher
argument_list|)
block|{}
name|template
operator|<
name|typename
name|To
operator|>
name|operator
name|Matcher
operator|<
name|To
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|To
operator|>
operator|(
name|new
name|ArgumentAdapterT
operator|<
name|To
operator|,
name|T
operator|>
operator|(
name|InnerMatcher
operator|)
operator|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher
block|; }
expr_stmt|;
comment|/// \brief A PolymorphicMatcherWithParamN<MatcherT, P1, ..., PN> object can be
comment|/// created from N parameters p1, ..., pN (of type P1, ..., PN) and
comment|/// used as a Matcher<T> where a MatcherT<T, P1, ..., PN>(p1, ..., pN)
comment|/// can be constructed.
comment|///
comment|/// For example:
comment|/// - PolymorphicMatcherWithParam0<IsDefinitionMatcher>()
comment|///   creates an object that can be used as a Matcher<T> for any type T
comment|///   where an IsDefinitionMatcher<T>() can be constructed.
comment|/// - PolymorphicMatcherWithParam1<ValueEqualsMatcher, int>(42)
comment|///   creates an object that can be used as a Matcher<T> for any type T
comment|///   where a ValueEqualsMatcher<T, int>(42) can be constructed.
name|template
operator|<
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MatcherT
operator|>
name|class
name|PolymorphicMatcherWithParam0
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|MatcherT
operator|<
name|T
operator|>
operator|(
operator|)
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|P1
operator|>
name|class
name|MatcherT
block|,
name|typename
name|P1
operator|>
name|class
name|PolymorphicMatcherWithParam1
block|{
name|public
operator|:
name|explicit
name|PolymorphicMatcherWithParam1
argument_list|(
specifier|const
name|P1
operator|&
name|Param1
argument_list|)
operator|:
name|Param1
argument_list|(
argument|Param1
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|MatcherT
operator|<
name|T
operator|,
name|P1
operator|>
operator|(
name|Param1
operator|)
operator|)
return|;
block|}
name|private
operator|:
specifier|const
name|P1
name|Param1
block|; }
block|;
name|template
operator|<
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|P1
block|,
name|typename
name|P2
operator|>
name|class
name|MatcherT
block|,
name|typename
name|P1
block|,
name|typename
name|P2
operator|>
name|class
name|PolymorphicMatcherWithParam2
block|{
name|public
operator|:
name|PolymorphicMatcherWithParam2
argument_list|(
specifier|const
name|P1
operator|&
name|Param1
argument_list|,
specifier|const
name|P2
operator|&
name|Param2
argument_list|)
operator|:
name|Param1
argument_list|(
name|Param1
argument_list|)
block|,
name|Param2
argument_list|(
argument|Param2
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|MatcherT
operator|<
name|T
operator|,
name|P1
operator|,
name|P2
operator|>
operator|(
name|Param1
operator|,
name|Param2
operator|)
operator|)
return|;
block|}
name|private
operator|:
specifier|const
name|P1
name|Param1
block|;
specifier|const
name|P2
name|Param2
block|; }
block|;
comment|/// \brief Matches any instance of the given NodeType.
comment|///
comment|/// This is useful when a matcher syntactically requires a child matcher,
comment|/// but the context doesn't care. See for example: anything().
comment|///
comment|/// FIXME: Alternatively we could also create a IsAMatcher or something
comment|/// that checks that a dyn_cast is possible. This is purely needed for the
comment|/// difference between calling for example:
comment|///   record()
comment|/// and
comment|///   record(SomeMatcher)
comment|/// In the second case we need the correct type we were dyn_cast'ed to in order
comment|/// to get the right type for the inner matcher. In the first case we don't need
comment|/// that, but we use the type conversion anyway and insert a TrueMatcher.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TrueMatcher
operator|:
name|public
name|SingleNodeMatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|virtual
name|bool
name|matchesNode
argument_list|(
argument|const T&Node
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief Provides a MatcherInterface<T> for a Matcher<To> that matches if T is
comment|/// dyn_cast'able into To and the given Matcher<To> matches on the dyn_cast'ed
comment|/// node.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|To
operator|>
name|class
name|DynCastMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|explicit
name|DynCastMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|To
operator|>
operator|&
name|InnerMatcher
argument_list|)
operator|:
name|InnerMatcher
argument_list|(
argument|InnerMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
specifier|const
name|To
operator|*
name|InnerMatchValue
operator|=
name|llvm
operator|::
name|dyn_cast
operator|<
name|To
operator|>
operator|(
operator|&
name|Node
operator|)
block|;
return|return
name|InnerMatchValue
operator|!=
name|NULL
operator|&&
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
name|InnerMatchValue
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|To
operator|>
name|InnerMatcher
block|; }
block|;
comment|/// \brief Matcher<T> that wraps an inner Matcher<T> and binds the matched node
comment|/// to an ID if the inner matcher matches on the node.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|IdMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
comment|/// \brief Creates an IdMatcher that binds to 'ID' if 'InnerMatcher' matches
comment|/// the node.
name|IdMatcher
argument_list|(
argument|StringRef ID
argument_list|,
argument|const Matcher<T>&InnerMatcher
argument_list|)
operator|:
name|ID
argument_list|(
name|ID
argument_list|)
block|,
name|InnerMatcher
argument_list|(
argument|InnerMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
name|bool
name|Result
operator|=
name|InnerMatcher
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
block|;
if|if
condition|(
name|Result
condition|)
block|{
name|Builder
operator|->
name|setBinding
argument_list|(
name|ID
argument_list|,
operator|&
name|Node
argument_list|)
expr_stmt|;
block|}
return|return
name|Result
return|;
block|}
name|private
operator|:
specifier|const
name|std
operator|::
name|string
name|ID
block|;
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher
block|; }
block|;
comment|/// \brief A Matcher that allows binding the node it matches to an id.
comment|///
comment|/// BindableMatcher provides a \a bind() method that allows binding the
comment|/// matched node to an id if the match was successful.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|BindableMatcher
operator|:
name|public
name|Matcher
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|BindableMatcher
argument_list|(
name|MatcherInterface
operator|<
name|T
operator|>
operator|*
name|Implementation
argument_list|)
operator|:
name|Matcher
operator|<
name|T
operator|>
operator|(
name|Implementation
operator|)
block|{}
comment|/// \brief Returns a matcher that will bind the matched node on a match.
comment|///
comment|/// The returned matcher is equivalent to this matcher, but will
comment|/// bind the matched node on a match.
name|Matcher
operator|<
name|T
operator|>
name|bind
argument_list|(
argument|StringRef ID
argument_list|)
specifier|const
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|Stmt
operator|,
name|T
operator|>
operator|::
name|value
operator|||
name|llvm
operator|::
name|is_base_of
operator|<
name|Decl
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|trying_to_bind_unsupported_node_type__only_decl_and_stmt_supported
argument_list|)
block|;
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|IdMatcher
operator|<
name|T
operator|>
operator|(
name|ID
operator|,
operator|*
name|this
operator|)
operator|)
return|;
block|}
expr|}
block|;
comment|/// \brief Matches nodes of type T that have child nodes of type ChildT for
comment|/// which a specified child matcher matches.
comment|///
comment|/// ChildT must be an AST base type.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|ChildT
operator|>
name|class
name|HasMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
name|IsBaseType
operator|<
name|ChildT
operator|>
operator|::
name|value
argument_list|,
name|has_only_accepts_base_type_matcher
argument_list|)
block|;
name|public
operator|:
name|explicit
name|HasMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|ChildT
operator|>
operator|&
name|ChildMatcher
argument_list|)
operator|:
name|ChildMatcher
argument_list|(
argument|ChildMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|Finder
operator|->
name|matchesChildOf
argument_list|(
name|Node
argument_list|,
name|ChildMatcher
argument_list|,
name|Builder
argument_list|,
name|ASTMatchFinder
operator|::
name|TK_IgnoreImplicitCastsAndParentheses
argument_list|,
name|ASTMatchFinder
operator|::
name|BK_First
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|TypedBaseMatcher
operator|<
name|ChildT
operator|>
name|ChildMatcher
block|; }
block|;
comment|/// \brief Matches nodes of type T that have child nodes of type ChildT for
comment|/// which a specified child matcher matches. ChildT must be an AST base
comment|/// type.
comment|/// As opposed to the HasMatcher, the ForEachMatcher will produce a match
comment|/// for each child that matches.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|ChildT
operator|>
name|class
name|ForEachMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
name|IsBaseType
operator|<
name|ChildT
operator|>
operator|::
name|value
argument_list|,
name|for_each_only_accepts_base_type_matcher
argument_list|)
block|;
name|public
operator|:
name|explicit
name|ForEachMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|ChildT
operator|>
operator|&
name|ChildMatcher
argument_list|)
operator|:
name|ChildMatcher
argument_list|(
argument|ChildMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T& Node
argument_list|,
argument|ASTMatchFinder* Finder
argument_list|,
argument|BoundNodesTreeBuilder* Builder
argument_list|)
specifier|const
block|{
return|return
name|Finder
operator|->
name|matchesChildOf
argument_list|(
name|Node
argument_list|,
name|ChildMatcher
argument_list|,
name|Builder
argument_list|,
name|ASTMatchFinder
operator|::
name|TK_IgnoreImplicitCastsAndParentheses
argument_list|,
name|ASTMatchFinder
operator|::
name|BK_All
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|TypedBaseMatcher
operator|<
name|ChildT
operator|>
name|ChildMatcher
block|; }
block|;
comment|/// \brief Matches nodes of type T if the given Matcher<T> does not match.
comment|///
comment|/// Type argument MatcherT is required by PolymorphicMatcherWithParam1
comment|/// but not actually used. It will always be instantiated with a type
comment|/// convertible to Matcher<T>.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|MatcherT
operator|>
name|class
name|NotMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|explicit
name|NotMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher
argument_list|)
operator|:
name|InnerMatcher
argument_list|(
argument|InnerMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
operator|!
name|InnerMatcher
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher
block|; }
block|;
comment|/// \brief Matches nodes of type T for which both provided matchers match.
comment|///
comment|/// Type arguments MatcherT1 and MatcherT2 are required by
comment|/// PolymorphicMatcherWithParam2 but not actually used. They will
comment|/// always be instantiated with types convertible to Matcher<T>.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|MatcherT1
block|,
name|typename
name|MatcherT2
operator|>
name|class
name|AllOfMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|AllOfMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher1
argument_list|,
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher2
argument_list|)
operator|:
name|InnerMatcher1
argument_list|(
name|InnerMatcher1
argument_list|)
block|,
name|InnerMatcher2
argument_list|(
argument|InnerMatcher2
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|InnerMatcher1
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
operator|&&
name|InnerMatcher2
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher1
block|;
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher2
block|; }
block|;
comment|/// \brief Matches nodes of type T for which at least one of the two provided
comment|/// matchers matches.
comment|///
comment|/// Type arguments MatcherT1 and MatcherT2 are
comment|/// required by PolymorphicMatcherWithParam2 but not actually
comment|/// used. They will always be instantiated with types convertible to
comment|/// Matcher<T>.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|MatcherT1
block|,
name|typename
name|MatcherT2
operator|>
name|class
name|AnyOfMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|AnyOfMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher1
argument_list|,
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher2
argument_list|)
operator|:
name|InnerMatcher1
argument_list|(
name|InnerMatcher1
argument_list|)
block|,
name|InnertMatcher2
argument_list|(
argument|InnerMatcher2
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|InnerMatcher1
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
operator|||
name|InnertMatcher2
operator|.
name|matches
argument_list|(
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher1
block|;
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnertMatcher2
block|; }
block|;
comment|/// \brief Creates a Matcher<T> that matches if
comment|/// T is dyn_cast'able into InnerT and all inner matchers match.
comment|///
comment|/// Returns BindableMatcher, as matchers that use dyn_cast have
comment|/// the same object both to match on and to run submatchers on,
comment|/// so there is no ambiguity with what gets bound.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|InnerT
operator|>
name|BindableMatcher
operator|<
name|T
operator|>
name|makeDynCastAllOfComposite
argument_list|(
argument|ArrayRef<const Matcher<InnerT> *> InnerMatchers
argument_list|)
block|{
if|if
condition|(
name|InnerMatchers
operator|.
name|empty
argument_list|()
condition|)
block|{
name|Matcher
operator|<
name|InnerT
operator|>
name|InnerMatcher
operator|=
name|makeMatcher
argument_list|(
argument|new TrueMatcher<InnerT>
argument_list|)
expr_stmt|;
return|return
name|BindableMatcher
operator|<
name|T
operator|>
operator|(
name|new
name|DynCastMatcher
operator|<
name|T
operator|,
name|InnerT
operator|>
operator|(
name|InnerMatcher
operator|)
operator|)
return|;
block|}
name|Matcher
operator|<
name|InnerT
operator|>
name|InnerMatcher
operator|=
operator|*
name|InnerMatchers
operator|.
name|back
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|InnerMatchers
operator|.
name|size
argument_list|()
operator|-
literal|2
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|InnerMatcher
operator|=
name|makeMatcher
argument_list|(
argument|new AllOfMatcher<InnerT
argument_list|,
argument|Matcher<InnerT>
argument_list|,
argument|Matcher<InnerT>>(             *InnerMatchers[i], InnerMatcher)
argument_list|)
expr_stmt|;
block|}
return|return
name|BindableMatcher
operator|<
name|T
operator|>
operator|(
name|new
name|DynCastMatcher
operator|<
name|T
operator|,
name|InnerT
operator|>
operator|(
name|InnerMatcher
operator|)
operator|)
return|;
block|}
comment|/// \brief Matches nodes of type T that have at least one descendant node of
comment|/// type DescendantT for which the given inner matcher matches.
comment|///
comment|/// DescendantT must be an AST base type.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|DescendantT
operator|>
name|class
name|HasDescendantMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
name|IsBaseType
operator|<
name|DescendantT
operator|>
operator|::
name|value
argument_list|,
name|has_descendant_only_accepts_base_type_matcher
argument_list|)
block|;
name|public
operator|:
name|explicit
name|HasDescendantMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|DescendantT
operator|>
operator|&
name|DescendantMatcher
argument_list|)
operator|:
name|DescendantMatcher
argument_list|(
argument|DescendantMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
return|return
name|Finder
operator|->
name|matchesDescendantOf
argument_list|(
name|Node
argument_list|,
name|DescendantMatcher
argument_list|,
name|Builder
argument_list|,
name|ASTMatchFinder
operator|::
name|BK_First
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|TypedBaseMatcher
operator|<
name|DescendantT
operator|>
name|DescendantMatcher
block|; }
block|;
comment|/// \brief Matches nodes of type T that have at least one descendant node of
comment|/// type DescendantT for which the given inner matcher matches.
comment|///
comment|/// DescendantT must be an AST base type.
comment|/// As opposed to HasDescendantMatcher, ForEachDescendantMatcher will match
comment|/// for each descendant node that matches instead of only for the first.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|DescendantT
operator|>
name|class
name|ForEachDescendantMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
name|IsBaseType
operator|<
name|DescendantT
operator|>
operator|::
name|value
argument_list|,
name|for_each_descendant_only_accepts_base_type_matcher
argument_list|)
block|;
name|public
operator|:
name|explicit
name|ForEachDescendantMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|DescendantT
operator|>
operator|&
name|DescendantMatcher
argument_list|)
operator|:
name|DescendantMatcher
argument_list|(
argument|DescendantMatcher
argument_list|)
block|{}
name|virtual
name|bool
name|matches
argument_list|(
argument|const T& Node
argument_list|,
argument|ASTMatchFinder* Finder
argument_list|,
argument|BoundNodesTreeBuilder* Builder
argument_list|)
specifier|const
block|{
return|return
name|Finder
operator|->
name|matchesDescendantOf
argument_list|(
name|Node
argument_list|,
name|DescendantMatcher
argument_list|,
name|Builder
argument_list|,
name|ASTMatchFinder
operator|::
name|BK_All
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|TypedBaseMatcher
operator|<
name|DescendantT
operator|>
name|DescendantMatcher
block|; }
block|;
comment|/// \brief Matches on nodes that have a getValue() method if getValue() equals
comment|/// the value the ValueEqualsMatcher was constructed with.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|ValueT
operator|>
name|class
name|ValueEqualsMatcher
operator|:
name|public
name|SingleNodeMatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|CharacterLiteral
operator|,
name|T
operator|>
operator|::
name|value
operator|||
name|llvm
operator|::
name|is_base_of
operator|<
name|CXXBoolLiteralExpr
operator|,
name|T
operator|>
operator|::
name|value
operator|||
name|llvm
operator|::
name|is_base_of
operator|<
name|FloatingLiteral
operator|,
name|T
operator|>
operator|::
name|value
operator|||
name|llvm
operator|::
name|is_base_of
operator|<
name|IntegerLiteral
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|the_node_must_have_a_getValue_method
argument_list|)
block|;
name|public
operator|:
name|explicit
name|ValueEqualsMatcher
argument_list|(
specifier|const
name|ValueT
operator|&
name|ExpectedValue
argument_list|)
operator|:
name|ExpectedValue
argument_list|(
argument|ExpectedValue
argument_list|)
block|{}
name|virtual
name|bool
name|matchesNode
argument_list|(
argument|const T&Node
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|.
name|getValue
argument_list|()
operator|==
name|ExpectedValue
return|;
block|}
name|private
operator|:
specifier|const
name|ValueT
name|ExpectedValue
block|; }
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|IsDefinitionMatcher
operator|:
name|public
name|SingleNodeMatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|TagDecl
operator|,
name|T
operator|>
operator|::
name|value
operator|)
operator|||
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|VarDecl
operator|,
name|T
operator|>
operator|::
name|value
operator|)
operator|||
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|FunctionDecl
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|is_definition_requires_isThisDeclarationADefinition_method
argument_list|)
block|;
name|public
operator|:
name|virtual
name|bool
name|matchesNode
argument_list|(
argument|const T&Node
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|.
name|isThisDeclarationADefinition
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief Matches on template instantiations for FunctionDecl, VarDecl or
comment|/// CXXRecordDecl nodes.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|IsTemplateInstantiationMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|FunctionDecl
operator|,
name|T
operator|>
operator|::
name|value
operator|)
operator|||
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|VarDecl
operator|,
name|T
operator|>
operator|::
name|value
operator|)
operator|||
operator|(
name|llvm
operator|::
name|is_base_of
operator|<
name|CXXRecordDecl
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|requires_getTemplateSpecializationKind_method
argument_list|)
block|;
name|public
operator|:
name|virtual
name|bool
name|matches
argument_list|(
argument|const T& Node
argument_list|,
argument|ASTMatchFinder* Finder
argument_list|,
argument|BoundNodesTreeBuilder* Builder
argument_list|)
specifier|const
block|{
return|return
operator|(
name|Node
operator|.
name|getTemplateSpecializationKind
argument_list|()
operator|==
name|TSK_ImplicitInstantiation
operator|||
name|Node
operator|.
name|getTemplateSpecializationKind
argument_list|()
operator|==
name|TSK_ExplicitInstantiationDefinition
operator|)
return|;
block|}
expr|}
block|;
name|class
name|IsArrowMatcher
operator|:
name|public
name|SingleNodeMatcherInterface
operator|<
name|MemberExpr
operator|>
block|{
name|public
operator|:
name|virtual
name|bool
name|matchesNode
argument_list|(
argument|const MemberExpr&Node
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|.
name|isArrow
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|IsConstQualifiedMatcher
operator|:
name|public
name|SingleNodeMatcherInterface
operator|<
name|QualType
operator|>
block|{
name|public
operator|:
name|virtual
name|bool
name|matchesNode
argument_list|(
argument|const QualType& Node
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|.
name|isConstQualified
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief A VariadicDynCastAllOfMatcher<SourceT, TargetT> object is a
comment|/// variadic functor that takes a number of Matcher<TargetT> and returns a
comment|/// Matcher<SourceT> that matches TargetT nodes that are matched by all of the
comment|/// given matchers, if SourceT can be dynamically casted into TargetT.
comment|///
comment|/// For example:
comment|///   const VariadicDynCastAllOfMatcher<
comment|///       Decl, CXXRecordDecl> record;
comment|/// Creates a functor record(...) that creates a Matcher<Decl> given
comment|/// a variable number of arguments of type Matcher<CXXRecordDecl>.
comment|/// The returned matcher matches if the given Decl can by dynamically
comment|/// casted to CXXRecordDecl and all given matchers match.
name|template
operator|<
name|typename
name|SourceT
block|,
name|typename
name|TargetT
operator|>
name|class
name|VariadicDynCastAllOfMatcher
operator|:
name|public
name|llvm
operator|::
name|VariadicFunction
operator|<
name|BindableMatcher
operator|<
name|SourceT
operator|>
block|,
name|Matcher
operator|<
name|TargetT
operator|>
block|,
name|makeDynCastAllOfComposite
operator|<
name|SourceT
block|,
name|TargetT
operator|>
expr|>
block|{
name|public
operator|:
name|VariadicDynCastAllOfMatcher
argument_list|()
block|{}
block|}
block|;  }
comment|// end namespace internal
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
comment|// LLVM_CLANG_AST_MATCHERS_AST_MATCHERS_INTERNAL_H
end_comment

end_unit

