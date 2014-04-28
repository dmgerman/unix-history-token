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
file|"clang/AST/ASTTypeTraits.h"
end_include

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
file|"clang/AST/StmtCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/VariadicFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
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
comment|/// \brief Internal version of BoundNodes. Holds all the bound nodes.
name|class
name|BoundNodesMap
block|{
name|public
label|:
comment|/// \brief Adds \c Node to the map with key \c ID.
comment|///
comment|/// The node's base type should be in NodeBaseType or it will be unaccessible.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|addNode
argument_list|(
argument|StringRef ID
argument_list|,
argument|const T* Node
argument_list|)
block|{
name|NodeMap
index|[
name|ID
index|]
operator|=
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
operator|*
name|Node
argument_list|)
block|;   }
comment|/// \brief Returns the AST node bound to \c ID.
comment|///
comment|/// Returns NULL if there was no node bound to \c ID or if there is a node but
comment|/// it cannot be converted to the specified type.
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|getNodeAs
argument_list|(
argument|StringRef ID
argument_list|)
specifier|const
block|{
name|IDToNodeMap
operator|::
name|const_iterator
name|It
operator|=
name|NodeMap
operator|.
name|find
argument_list|(
name|ID
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|NodeMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
return|return
name|It
operator|->
name|second
operator|.
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
name|ast_type_traits
operator|::
name|DynTypedNode
name|getNode
argument_list|(
argument|StringRef ID
argument_list|)
specifier|const
block|{
name|IDToNodeMap
operator|::
name|const_iterator
name|It
operator|=
name|NodeMap
operator|.
name|find
argument_list|(
name|ID
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|NodeMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|ast_type_traits
operator|::
name|DynTypedNode
argument_list|()
return|;
block|}
return|return
name|It
operator|->
name|second
return|;
block|}
comment|/// \brief Imposes an order on BoundNodesMaps.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|BoundNodesMap
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|NodeMap
operator|<
name|Other
operator|.
name|NodeMap
return|;
block|}
comment|/// \brief A map from IDs to the bound nodes.
comment|///
comment|/// Note that we're using std::map here, as for memoization:
comment|/// - we need a comparison operator
comment|/// - we need an assignment operator
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|ast_type_traits
operator|::
name|DynTypedNode
operator|>
name|IDToNodeMap
expr_stmt|;
specifier|const
name|IDToNodeMap
operator|&
name|getMap
argument_list|()
specifier|const
block|{
return|return
name|NodeMap
return|;
block|}
name|private
label|:
name|IDToNodeMap
name|NodeMap
decl_stmt|;
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
comment|/// \brief Add a binding from an id to a node.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|setBinding
argument_list|(
argument|const std::string&Id
argument_list|,
argument|const T *Node
argument_list|)
block|{
if|if
condition|(
name|Bindings
operator|.
name|empty
argument_list|()
condition|)
name|Bindings
operator|.
name|push_back
argument_list|(
name|BoundNodesMap
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Bindings
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|Bindings
index|[
name|i
index|]
operator|.
name|addNode
argument_list|(
name|Id
argument_list|,
name|Node
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Adds a branch in the tree.
name|void
name|addMatch
parameter_list|(
specifier|const
name|BoundNodesTreeBuilder
modifier|&
name|Bindings
parameter_list|)
function_decl|;
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
name|template
operator|<
name|typename
name|ExcludePredicate
operator|>
name|bool
name|removeBindings
argument_list|(
argument|const ExcludePredicate&Predicate
argument_list|)
block|{
name|Bindings
operator|.
name|erase
argument_list|(
name|std
operator|::
name|remove_if
argument_list|(
name|Bindings
operator|.
name|begin
argument_list|()
argument_list|,
name|Bindings
operator|.
name|end
argument_list|()
argument_list|,
name|Predicate
argument_list|)
argument_list|,
name|Bindings
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
operator|!
name|Bindings
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Imposes an order on BoundNodesTreeBuilders.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|BoundNodesTreeBuilder
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Bindings
operator|<
name|Other
operator|.
name|Bindings
return|;
block|}
name|private
label|:
name|SmallVector
operator|<
name|BoundNodesMap
operator|,
literal|16
operator|>
name|Bindings
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
comment|/// \brief Interface for matchers that only evaluate properties on a single
comment|/// node.
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
comment|/// \brief Implicitly converts \c Other to a Matcher<T>.
comment|///
comment|/// Requires \c T to be derived from \c From.
name|template
operator|<
name|typename
name|From
operator|>
name|Matcher
argument_list|(
argument|const Matcher<From>&Other
argument_list|,
argument|typename llvm::enable_if_c<             llvm::is_base_of<From
argument_list|,
argument|T>::value&&             !llvm::is_same<From
argument_list|,
argument|T>::value>::type* =
literal|0
argument_list|)
operator|:
name|Implementation
argument_list|(
argument|new ImplicitCastMatcher<From>(Other)
argument_list|)
block|{}
comment|/// \brief Implicitly converts \c Matcher<Type> to \c Matcher<QualType>.
comment|///
comment|/// The resulting matcher is not strict, i.e. ignores qualifiers.
name|template
operator|<
name|typename
name|TypeT
operator|>
name|Matcher
argument_list|(
argument|const Matcher<TypeT>&Other
argument_list|,
argument|typename llvm::enable_if_c<             llvm::is_same<T
argument_list|,
argument|QualType>::value&&             llvm::is_same<TypeT
argument_list|,
argument|Type>::value>::type* =
literal|0
argument_list|)
operator|:
name|Implementation
argument_list|(
argument|new TypeToQualType<TypeT>(Other)
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
if|if
condition|(
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
condition|)
return|return
name|true
return|;
comment|// Delete all bindings when a matcher does not match.
comment|// This prevents unexpected exposure of bound nodes in unmatches
comment|// branches of the match tree.
operator|*
name|Builder
operator|=
name|BoundNodesTreeBuilder
argument_list|()
block|;
return|return
name|false
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
comment|/// \brief Allows the conversion of a \c Matcher<Type> to a \c
comment|/// Matcher<QualType>.
comment|///
comment|/// Depending on the constructor argument, the matcher is either strict, i.e.
comment|/// does only matches in the absence of qualifiers, or not, i.e. simply
comment|/// ignores any qualifiers.
name|template
operator|<
name|typename
name|TypeT
operator|>
name|class
name|TypeToQualType
operator|:
name|public
name|MatcherInterface
operator|<
name|QualType
operator|>
block|{
name|public
operator|:
name|TypeToQualType
argument_list|(
specifier|const
name|Matcher
operator|<
name|TypeT
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
argument|const QualType&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
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
return|return
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
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
name|TypeT
operator|>
name|InnerMatcher
block|;   }
expr_stmt|;
name|private
label|:
comment|/// \brief Allows conversion from Matcher<Base> to Matcher<T> if T
comment|/// is derived from Base.
name|template
operator|<
name|typename
name|Base
operator|>
name|class
name|ImplicitCastMatcher
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
name|ImplicitCastMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|Base
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
argument|const T&Node
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
name|Base
operator|>
name|From
block|;   }
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|MatcherInterface
operator|<
name|T
operator|>
expr|>
name|Implementation
expr_stmt|;
block|}
empty_stmt|;
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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|BindableMatcher
expr_stmt|;
comment|/// \brief Matcher that works on a \c DynTypedNode.
comment|///
comment|/// It is constructed from a \c Matcher<T> object and redirects most calls to
comment|/// underlying matcher.
comment|/// It checks whether the \c DynTypedNode is convertible into the type of the
comment|/// underlying matcher and then do the actual match on the actual node, or
comment|/// return false if it is not convertible.
name|class
name|DynTypedMatcher
block|{
name|public
label|:
comment|/// \brief Construct from a \c Matcher<T>. Copies the matcher.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|DynTypedMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|M
argument_list|)
expr_stmt|;
comment|/// \brief Construct from a bindable \c Matcher<T>. Copies the matcher.
comment|///
comment|/// This version enables \c tryBind() on the \c DynTypedMatcher.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|DynTypedMatcher
argument_list|(
specifier|const
name|BindableMatcher
operator|<
name|T
operator|>
operator|&
name|M
argument_list|)
expr_stmt|;
comment|/// \brief Returns true if the matcher matches the given \c DynNode.
name|bool
name|matches
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
name|DynNode
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
block|{
return|return
name|Storage
operator|->
name|matches
argument_list|(
name|DynNode
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
comment|/// \brief Bind the specified \p ID to the matcher.
comment|/// \return A new matcher with the \p ID bound to it if this matcher supports
comment|///   binding. Otherwise, returns an empty \c Optional<>.
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|tryBind
argument_list|(
argument|StringRef ID
argument_list|)
specifier|const
block|{
return|return
name|Storage
operator|->
name|tryBind
argument_list|(
name|ID
argument_list|)
return|;
block|}
comment|/// \brief Returns a unique \p ID for the matcher.
name|uint64_t
name|getID
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|->
name|getID
argument_list|()
return|;
block|}
comment|/// \brief Returns the type this matcher works on.
comment|///
comment|/// \c matches() will always return false unless the node passed is of this
comment|/// or a derived type.
name|ast_type_traits
operator|::
name|ASTNodeKind
name|getSupportedKind
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|->
name|getSupportedKind
argument_list|()
return|;
block|}
comment|/// \brief Returns \c true if the passed \c DynTypedMatcher can be converted
comment|///   to a \c Matcher<T>.
comment|///
comment|/// This method verifies that the underlying matcher in \c Other can process
comment|/// nodes of types T.
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|canConvertTo
argument_list|()
specifier|const
block|{
return|return
name|getSupportedKind
argument_list|()
operator|.
name|isBaseOf
argument_list|(
name|ast_type_traits
operator|::
name|ASTNodeKind
operator|::
name|getFromNodeKind
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Construct a \c Matcher<T> interface around the dynamic matcher.
comment|///
comment|/// This method asserts that \c canConvertTo() is \c true. Callers
comment|/// should call \c canConvertTo() first to make sure that \c this is
comment|/// compatible with T.
name|template
operator|<
name|typename
name|T
operator|>
name|Matcher
operator|<
name|T
operator|>
name|convertTo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|canConvertTo
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
block|;
return|return
name|unconditionalConvertTo
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Same as \c convertTo(), but does not check that the underlying
comment|///   matcher can handle a value of T.
comment|///
comment|/// If it is not compatible, then this matcher will never match anything.
name|template
operator|<
name|typename
name|T
operator|>
name|Matcher
operator|<
name|T
operator|>
name|unconditionalConvertTo
argument_list|()
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|WrappedMatcher
operator|<
name|T
operator|>
operator|(
operator|*
name|this
operator|)
operator|)
return|;
block|}
name|private
label|:
name|class
name|MatcherStorage
range|:
name|public
name|RefCountedBaseVPTR
block|{
name|public
operator|:
name|MatcherStorage
argument_list|(
argument|ast_type_traits::ASTNodeKind SupportedKind
argument_list|,
argument|uint64_t ID
argument_list|)
operator|:
name|SupportedKind
argument_list|(
name|SupportedKind
argument_list|)
block|,
name|ID
argument_list|(
argument|ID
argument_list|)
block|{}
name|virtual
operator|~
name|MatcherStorage
argument_list|()
block|;
name|virtual
name|bool
name|matches
argument_list|(
argument|const ast_type_traits::DynTypedNode DynNode
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|tryBind
argument_list|(
argument|StringRef ID
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|ast_type_traits
operator|::
name|ASTNodeKind
name|getSupportedKind
argument_list|()
specifier|const
block|{
return|return
name|SupportedKind
return|;
block|}
name|uint64_t
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|private
operator|:
specifier|const
name|ast_type_traits
operator|::
name|ASTNodeKind
name|SupportedKind
block|;
specifier|const
name|uint64_t
name|ID
block|;   }
decl_stmt|;
comment|/// \brief Typed implementation of \c MatcherStorage.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypedMatcherStorage
expr_stmt|;
comment|/// \brief Simple MatcherInterface<T> wrapper around a DynTypedMatcher.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|WrappedMatcher
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
specifier|const
name|MatcherStorage
operator|>
name|Storage
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|DynTypedMatcher
operator|::
name|TypedMatcherStorage
operator|:
name|public
name|MatcherStorage
block|{
name|public
operator|:
name|TypedMatcherStorage
argument_list|(
argument|const Matcher<T>&Other
argument_list|,
argument|bool AllowBind
argument_list|)
operator|:
name|MatcherStorage
argument_list|(
name|ast_type_traits
operator|::
name|ASTNodeKind
operator|::
name|getFromNodeKind
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|,
name|Other
operator|.
name|getID
argument_list|()
argument_list|)
block|,
name|InnerMatcher
argument_list|(
name|Other
argument_list|)
block|,
name|AllowBind
argument_list|(
argument|AllowBind
argument_list|)
block|{}
name|bool
name|matches
argument_list|(
argument|const ast_type_traits::DynTypedNode DynNode
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|{
if|if
condition|(
specifier|const
name|T
modifier|*
name|Node
init|=
name|DynNode
operator|.
name|get
operator|<
name|T
operator|>
operator|(
operator|)
condition|)
block|{
return|return
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
return|return
name|false
return|;
block|}
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|tryBind
argument_list|(
argument|StringRef ID
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|{
if|if
condition|(
operator|!
name|AllowBind
condition|)
return|return
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
operator|(
operator|)
return|;
return|return
name|DynTypedMatcher
argument_list|(
name|BindableMatcher
operator|<
name|T
operator|>
operator|(
name|InnerMatcher
operator|)
operator|.
name|bind
argument_list|(
name|ID
argument_list|)
argument_list|)
return|;
block|}
name|private
label|:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher
expr_stmt|;
specifier|const
name|bool
name|AllowBind
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|DynTypedMatcher
operator|::
name|DynTypedMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|M
argument_list|)
operator|:
name|Storage
argument_list|(
argument|new TypedMatcherStorage<T>(M, false)
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|DynTypedMatcher
operator|::
name|DynTypedMatcher
argument_list|(
specifier|const
name|BindableMatcher
operator|<
name|T
operator|>
operator|&
name|M
argument_list|)
operator|:
name|Storage
argument_list|(
argument|new TypedMatcherStorage<T>(M, true)
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|DynTypedMatcher
operator|::
name|WrappedMatcher
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
name|WrappedMatcher
argument_list|(
specifier|const
name|DynTypedMatcher
operator|&
name|Matcher
argument_list|)
operator|:
name|Inner
argument_list|(
argument|Matcher
argument_list|)
block|{}
name|virtual
operator|~
name|WrappedMatcher
argument_list|()
block|{}
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
name|Inner
operator|.
name|matches
argument_list|(
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
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
name|DynTypedMatcher
name|Inner
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Specialization of the conversion functions for QualType.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These specializations provide the Matcher<Type>->Matcher<QualType>
end_comment

begin_comment
comment|/// conversion that the static API does.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|DynTypedMatcher
operator|::
name|canConvertTo
operator|<
name|QualType
operator|>
operator|(
operator|)
specifier|const
block|{
specifier|const
name|ast_type_traits
operator|::
name|ASTNodeKind
name|SourceKind
operator|=
name|getSupportedKind
argument_list|()
block|;
return|return
name|SourceKind
operator|.
name|isSame
argument_list|(
name|ast_type_traits
operator|::
name|ASTNodeKind
operator|::
name|getFromNodeKind
operator|<
name|Type
operator|>
operator|(
operator|)
argument_list|)
operator|||
name|SourceKind
operator|.
name|isSame
argument_list|(
name|ast_type_traits
operator|::
name|ASTNodeKind
operator|::
name|getFromNodeKind
operator|<
name|QualType
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|Matcher
operator|<
name|QualType
operator|>
name|DynTypedMatcher
operator|::
name|convertTo
operator|<
name|QualType
operator|>
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|canConvertTo
operator|<
name|QualType
operator|>
operator|(
operator|)
argument_list|)
block|;
specifier|const
name|ast_type_traits
operator|::
name|ASTNodeKind
name|SourceKind
operator|=
name|getSupportedKind
argument_list|()
block|;
if|if
condition|(
name|SourceKind
operator|.
name|isSame
argument_list|(
name|ast_type_traits
operator|::
name|ASTNodeKind
operator|::
name|getFromNodeKind
operator|<
name|Type
operator|>
operator|(
operator|)
argument_list|)
condition|)
block|{
comment|// We support implicit conversion from Matcher<Type> to Matcher<QualType>
return|return
name|unconditionalConvertTo
operator|<
name|Type
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_return
return|return
name|unconditionalConvertTo
operator|<
name|QualType
operator|>
operator|(
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Finds the first node in a range that matches the given matcher.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|MatcherT
operator|,
name|typename
name|IteratorT
operator|>
name|bool
name|matchesFirstInRange
argument_list|(
argument|const MatcherT&Matcher
argument_list|,
argument|IteratorT Start
argument_list|,
argument|IteratorT End
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
block|{
for|for
control|(
name|IteratorT
name|I
init|=
name|Start
init|;
name|I
operator|!=
name|End
condition|;
operator|++
name|I
control|)
block|{
name|BoundNodesTreeBuilder
name|Result
argument_list|(
operator|*
name|Builder
argument_list|)
decl_stmt|;
if|if
condition|(
name|Matcher
operator|.
name|matches
argument_list|(
operator|*
name|I
argument_list|,
name|Finder
argument_list|,
operator|&
name|Result
argument_list|)
condition|)
block|{
operator|*
name|Builder
operator|=
name|Result
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}   return
name|false
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// \brief Finds the first node in a pointer range that matches the given
end_comment

begin_comment
comment|/// matcher.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|MatcherT
operator|,
name|typename
name|IteratorT
operator|>
name|bool
name|matchesFirstInPointerRange
argument_list|(
argument|const MatcherT&Matcher
argument_list|,
argument|IteratorT Start
argument_list|,
argument|IteratorT End
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
block|{
for|for
control|(
name|IteratorT
name|I
init|=
name|Start
init|;
name|I
operator|!=
name|End
condition|;
operator|++
name|I
control|)
block|{
name|BoundNodesTreeBuilder
name|Result
argument_list|(
operator|*
name|Builder
argument_list|)
decl_stmt|;
if|if
condition|(
name|Matcher
operator|.
name|matches
argument_list|(
operator|*
operator|*
name|I
argument_list|,
name|Finder
argument_list|,
operator|&
name|Result
argument_list|)
condition|)
block|{
operator|*
name|Builder
operator|=
name|Result
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}   return
name|false
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// \brief Metafunction to determine if type T has a member called getDecl.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|has_getDecl
block|{   struct
name|Default
block|{
name|int
name|getDecl
block|; }
block|;   struct
name|Derived
operator|:
name|T
block|,
name|Default
block|{ }
block|;
name|template
operator|<
name|typename
name|C
block|,
name|C
operator|>
expr|struct
name|CheckT
block|;
comment|// If T::getDecl exists, an ambiguity arises and CheckT will
comment|// not be instantiable. This makes f(...) the only available
comment|// overload.
name|template
operator|<
name|typename
name|C
operator|>
specifier|static
name|char
argument_list|(
operator|&
name|f
argument_list|(
argument|CheckT<int Default::*
argument_list|,
argument|&C::getDecl>*
argument_list|)
argument_list|)
index|[
literal|1
index|]
block|;
name|template
operator|<
name|typename
name|C
operator|>
specifier|static
name|char
argument_list|(
operator|&
name|f
argument_list|(
operator|...
argument_list|)
argument_list|)
index|[
literal|2
index|]
block|;
specifier|static
name|bool
specifier|const
name|value
operator|=
sizeof|sizeof
argument_list|(
name|f
operator|<
name|Derived
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|==
literal|2
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Matches overloaded operators with a specific name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type argument ArgT is not used by this matcher but is used by
end_comment

begin_comment
comment|/// PolymorphicMatcherWithParam1 and should be StringRef.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ArgT
operator|>
name|class
name|HasOverloadedOperatorNameMatcher
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
name|is_same
operator|<
name|T
operator|,
name|CXXOperatorCallExpr
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
name|CXXMethodDecl
operator|>
operator|::
name|value
operator|)
argument_list|,
name|unsupported_class_for_matcher
argument_list|)
block|;
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|llvm
operator|::
name|is_same
operator|<
name|ArgT
operator|,
name|StringRef
operator|>
operator|::
name|value
operator|)
argument_list|,
name|argument_type_must_be_StringRef
argument_list|)
block|;
name|public
operator|:
name|explicit
name|HasOverloadedOperatorNameMatcher
argument_list|(
argument|const StringRef Name
argument_list|)
operator|:
name|SingleNodeMatcherInterface
operator|<
name|T
operator|>
operator|(
operator|)
block|,
name|Name
argument_list|(
argument|Name
argument_list|)
block|{}
name|virtual
name|bool
name|matchesNode
argument_list|(
argument|const T&Node
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
name|matchesSpecialized
argument_list|(
name|Node
argument_list|)
return|;
block|}
name|private
operator|:
comment|/// \brief CXXOperatorCallExpr exist only for calls to overloaded operators
comment|/// so this function returns true if the call is to an operator of the given
comment|/// name.
name|bool
name|matchesSpecialized
argument_list|(
argument|const CXXOperatorCallExpr&Node
argument_list|)
specifier|const
block|{
return|return
name|getOperatorSpelling
argument_list|(
name|Node
operator|.
name|getOperator
argument_list|()
argument_list|)
operator|==
name|Name
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true only if CXXMethodDecl represents an overloaded
end_comment

begin_comment
comment|/// operator and has the given operator name.
end_comment

begin_decl_stmt
name|bool
name|matchesSpecialized
argument_list|(
specifier|const
name|CXXMethodDecl
operator|&
name|Node
argument_list|)
decl|const
block|{
return|return
name|Node
operator|.
name|isOverloadedOperator
argument_list|()
operator|&&
name|getOperatorSpelling
argument_list|(
name|Node
operator|.
name|getOverloadedOperator
argument_list|()
argument_list|)
operator|==
name|Name
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|Name
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches declarations for QualType and CallExpr.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type argument DeclMatcherT is required by PolymorphicMatcherWithParam1 but
end_comment

begin_comment
comment|/// not actually used.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
comment|/// \brief If getDecl exists as a member of U, returns whether the inner
comment|/// matcher matches Node.getDecl().
name|template
operator|<
name|typename
name|U
operator|>
name|bool
name|matchesSpecialized
argument_list|(
argument|const U&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|,
argument|typename llvm::enable_if<has_getDecl<U>
argument_list|,
argument|int>::type =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|matchesDecl
argument_list|(
name|Node
operator|.
name|getDecl
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Extracts the CXXRecordDecl or EnumDecl of a QualType and returns
end_comment

begin_comment
comment|/// whether the inner matcher matches on it.
end_comment

begin_decl_stmt
name|bool
name|matchesSpecialized
argument_list|(
specifier|const
name|QualType
operator|&
name|Node
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
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
if|if
condition|(
specifier|const
name|EnumType
modifier|*
name|AsEnum
init|=
name|dyn_cast
operator|<
name|EnumType
operator|>
operator|(
name|Node
operator|.
name|getTypePtr
argument_list|()
operator|)
condition|)
return|return
name|matchesDecl
argument_list|(
name|AsEnum
operator|->
name|getDecl
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
return|return
name|matchesDecl
argument_list|(
name|Node
operator|->
name|getAsCXXRecordDecl
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Gets the TemplateDecl from a TemplateSpecializationType
end_comment

begin_comment
comment|/// and returns whether the inner matches on it.
end_comment

begin_decl_stmt
name|bool
name|matchesSpecialized
argument_list|(
specifier|const
name|TemplateSpecializationType
operator|&
name|Node
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
block|{
return|return
name|matchesDecl
argument_list|(
name|Node
operator|.
name|getTemplateName
argument_list|()
operator|.
name|getAsTemplateDecl
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Extracts the Decl of the callee of a CallExpr and returns whether
end_comment

begin_comment
comment|/// the inner matcher matches on it.
end_comment

begin_decl_stmt
name|bool
name|matchesSpecialized
argument_list|(
specifier|const
name|CallExpr
operator|&
name|Node
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
block|{
return|return
name|matchesDecl
argument_list|(
name|Node
operator|.
name|getCalleeDecl
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Extracts the Decl of the constructor call and returns whether the
end_comment

begin_comment
comment|/// inner matcher matches on it.
end_comment

begin_decl_stmt
name|bool
name|matchesSpecialized
argument_list|(
specifier|const
name|CXXConstructExpr
operator|&
name|Node
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
block|{
return|return
name|matchesDecl
argument_list|(
name|Node
operator|.
name|getConstructor
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Extracts the \c ValueDecl a \c MemberExpr refers to and returns
end_comment

begin_comment
comment|/// whether the inner matcher matches on it.
end_comment

begin_decl_stmt
name|bool
name|matchesSpecialized
argument_list|(
specifier|const
name|MemberExpr
operator|&
name|Node
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
block|{
return|return
name|matchesDecl
argument_list|(
name|Node
operator|.
name|getMemberDecl
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns whether the inner matcher \c Node. Returns false if \c Node
end_comment

begin_comment
comment|/// is \c NULL.
end_comment

begin_decl_stmt
name|bool
name|matchesDecl
argument_list|(
specifier|const
name|Decl
operator|*
name|Node
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|)
decl|const
block|{
return|return
name|Node
operator|!=
name|NULL
operator|&&
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
name|Node
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|Decl
operator|>
name|InnerMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief IsBaseType<T>::value is true if T is a "base" type in the AST
end_comment

begin_comment
comment|/// node class hierarchies.
end_comment

begin_expr_stmt
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
name|Type
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
name|TypeLoc
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
name|NestedNameSpecifier
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
name|NestedNameSpecifierLoc
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Interface that allows matchers to traverse the AST.
end_comment

begin_comment
comment|/// FIXME: Find a better name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides three entry methods for each base node type in the AST:
end_comment

begin_comment
comment|/// - \c matchesChildOf:
end_comment

begin_comment
comment|///   Matches a matcher on every child node of the given node. Returns true
end_comment

begin_comment
comment|///   if at least one child node could be matched.
end_comment

begin_comment
comment|/// - \c matchesDescendantOf:
end_comment

begin_comment
comment|///   Matches a matcher on all descendant nodes of the given node. Returns true
end_comment

begin_comment
comment|///   if at least one descendant matched.
end_comment

begin_comment
comment|/// - \c matchesAncestorOf:
end_comment

begin_comment
comment|///   Matches a matcher on all ancestors of the given node. Returns true if
end_comment

begin_comment
comment|///   at least one ancestor matched.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: Currently we only allow Stmt and Decl nodes to start a traversal.
end_comment

begin_comment
comment|/// In the future, we wan to implement this for all nodes for which it makes
end_comment

begin_comment
comment|/// sense. In the case of matchesAncestorOf, we'll want to implement it for
end_comment

begin_comment
comment|/// all nodes, as all nodes have ancestors.
end_comment

begin_decl_stmt
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
comment|/// \brief Defines which ancestors are considered for a match.
enum|enum
name|AncestorMatchMode
block|{
comment|/// All ancestors.
name|AMM_All
block|,
comment|/// Direct parent only.
name|AMM_ParentOnly
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
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|matchesChildOf
argument_list|(
argument|const T&Node
argument_list|,
argument|const DynTypedMatcher&Matcher
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|,
argument|TraversalKind Traverse
argument_list|,
argument|BindKind Bind
argument_list|)
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
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
operator|||
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
name|NestedNameSpecifier
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
name|NestedNameSpecifierLoc
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
name|TypeLoc
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
name|QualType
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|unsupported_type_for_recursive_matching
argument_list|)
block|;
return|return
name|matchesChildOf
argument_list|(
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Matcher
argument_list|,
name|Builder
argument_list|,
name|Traverse
argument_list|,
name|Bind
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|matchesDescendantOf
argument_list|(
argument|const T&Node
argument_list|,
argument|const DynTypedMatcher&Matcher
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|,
argument|BindKind Bind
argument_list|)
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
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
operator|||
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
name|NestedNameSpecifier
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
name|NestedNameSpecifierLoc
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
name|TypeLoc
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
name|QualType
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|unsupported_type_for_recursive_matching
argument_list|)
block|;
return|return
name|matchesDescendantOf
argument_list|(
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Matcher
argument_list|,
name|Builder
argument_list|,
name|Bind
argument_list|)
return|;
block|}
comment|// FIXME: Implement support for BindKind.
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|matchesAncestorOf
argument_list|(
argument|const T&Node
argument_list|,
argument|const DynTypedMatcher&Matcher
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|,
argument|AncestorMatchMode MatchMode
argument_list|)
block|{
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
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
operator|||
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
operator|)
argument_list|,
name|only_Decl_or_Stmt_allowed_for_recursive_matching
argument_list|)
block|;
return|return
name|matchesAncestorOf
argument_list|(
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Matcher
argument_list|,
name|Builder
argument_list|,
name|MatchMode
argument_list|)
return|;
block|}
name|virtual
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|virtual
name|bool
name|matchesChildOf
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
operator|&
name|Node
argument_list|,
specifier|const
name|DynTypedMatcher
operator|&
name|Matcher
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|,
name|TraversalKind
name|Traverse
argument_list|,
name|BindKind
name|Bind
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|matchesDescendantOf
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
operator|&
name|Node
argument_list|,
specifier|const
name|DynTypedMatcher
operator|&
name|Matcher
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|,
name|BindKind
name|Bind
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|matchesAncestorOf
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
operator|&
name|Node
argument_list|,
specifier|const
name|DynTypedMatcher
operator|&
name|Matcher
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|,
name|AncestorMatchMode
name|MatchMode
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A type-list implementation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A list is declared as a tree of type list nodes, where the leafs are the
end_comment

begin_comment
comment|/// types.
end_comment

begin_comment
comment|/// However, it is used as a "linked list" of types, by using the ::head and
end_comment

begin_comment
comment|/// ::tail typedefs.
end_comment

begin_comment
comment|/// Each node supports up to 4 children (instead of just 2) to reduce the
end_comment

begin_comment
comment|/// nesting required by large lists.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|=
name|void
operator|,
name|typename
name|T2
operator|=
name|void
operator|,
name|typename
name|T3
operator|=
name|void
operator|,
name|typename
name|T4
operator|=
name|void
operator|>
expr|struct
name|TypeList
block|{
comment|/// \brief Implementation detail. Combined with the specializations below,
comment|///   this typedef allows for flattening of nested structures.
typedef|typedef
name|TypeList
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
name|self
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The first type on the list.
end_comment

begin_typedef
typedef|typedef
name|T1
name|head
typedef|;
end_typedef

begin_comment
comment|/// \brief A sub list with the tail. ie everything but the head.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This type is used to do recursion. TypeList<>/EmptyTypeList indicates the
end_comment

begin_comment
comment|/// end of the list.
end_comment

begin_typedef
typedef|typedef
name|typename
name|TypeList
operator|<
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
operator|::
name|self
name|tail
expr_stmt|;
end_typedef

begin_comment
unit|};
comment|/// \brief Template specialization to allow nested lists.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// First element is a typelist. Pop its first element.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Sub1
operator|,
name|typename
name|Sub2
operator|,
name|typename
name|Sub3
operator|,
name|typename
name|Sub4
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|>
expr|struct
name|TypeList
operator|<
name|TypeList
operator|<
name|Sub1
operator|,
name|Sub2
operator|,
name|Sub3
operator|,
name|Sub4
operator|>
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
operator|:
name|public
name|TypeList
operator|<
name|Sub1
operator|,
name|typename
name|TypeList
operator|<
name|Sub2
operator|,
name|Sub3
operator|,
name|Sub4
operator|>
operator|::
name|self
operator|,
name|typename
name|TypeList
operator|<
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
operator|::
name|self
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Template specialization to allow nested lists.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// First element is an empty typelist. Skip it.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|>
expr|struct
name|TypeList
operator|<
name|TypeList
operator|<
operator|>
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
operator|:
name|public
name|TypeList
operator|<
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The empty type list.
end_comment

begin_typedef
typedef|typedef
name|TypeList
operator|<
operator|>
name|EmptyTypeList
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Helper meta-function to determine if some type \c T is present or
end_comment

begin_comment
comment|///   a parent type in the list.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnyTypeList
operator|,
name|typename
name|T
operator|>
expr|struct
name|TypeListContainsSuperOf
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|llvm
operator|::
name|is_base_of
operator|<
name|typename
name|AnyTypeList
operator|::
name|head
block|,
name|T
operator|>
operator|::
name|value
operator|||
name|TypeListContainsSuperOf
operator|<
name|typename
name|AnyTypeList
operator|::
name|tail
block|,
name|T
operator|>
operator|::
name|value
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|TypeListContainsSuperOf
operator|<
name|EmptyTypeList
operator|,
name|T
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|false
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A "type list" that contains all types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Useful for matchers like \c anything and \c unless.
end_comment

begin_typedef
typedef|typedef
name|TypeList
operator|<
name|TypeList
operator|<
name|Decl
operator|,
name|Stmt
operator|,
name|NestedNameSpecifier
operator|,
name|NestedNameSpecifierLoc
operator|>
operator|,
name|TypeList
operator|<
name|QualType
operator|,
name|Type
operator|,
name|TypeLoc
operator|,
name|CXXCtorInitializer
operator|>
expr|>
name|AllNodeBaseTypes
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Helper meta-function to extract the argument out of a function of
end_comment

begin_comment
comment|///   type void(Arg).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See AST_POLYMORPHIC_SUPPORTED_TYPES_* for details.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|ExtractFunctionArgMeta
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|ExtractFunctionArgMeta
operator|<
name|void
argument_list|(
name|T
argument_list|)
operator|>
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Default type lists for ArgumentAdaptingMatcher matchers.
end_comment

begin_typedef
typedef|typedef
name|AllNodeBaseTypes
name|AdaptativeDefaultFromTypes
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TypeList
operator|<
name|TypeList
operator|<
name|Decl
operator|,
name|Stmt
operator|,
name|NestedNameSpecifier
operator|>
operator|,
name|TypeList
operator|<
name|NestedNameSpecifierLoc
operator|,
name|TypeLoc
operator|,
name|QualType
operator|>
expr|>
name|AdaptativeDefaultToTypes
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief All types that are supported by HasDeclarationMatcher above.
end_comment

begin_typedef
typedef|typedef
name|TypeList
operator|<
name|TypeList
operator|<
name|CallExpr
operator|,
name|CXXConstructExpr
operator|,
name|DeclRefExpr
operator|,
name|EnumType
operator|>
operator|,
name|TypeList
operator|<
name|InjectedClassNameType
operator|,
name|LabelStmt
operator|,
name|MemberExpr
operator|>
operator|,
name|TypeList
operator|<
name|QualType
operator|,
name|RecordType
operator|,
name|TagType
operator|>
operator|,
name|TypeList
operator|<
name|TemplateSpecializationType
operator|,
name|TemplateTypeParmType
operator|,
name|TypedefType
operator|,
name|UnresolvedUsingType
operator|>
expr|>
name|HasDeclarationSupportedTypes
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Converts a \c Matcher<T> to a matcher of desired type \c To by
end_comment

begin_comment
comment|/// "adapting" a \c To into a \c T.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The \c ArgumentAdapterT argument specifies how the adaptation is done.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///   \c ArgumentAdaptingMatcher<HasMatcher, T>(InnerMatcher);
end_comment

begin_comment
comment|/// Given that \c InnerMatcher is of type \c Matcher<T>, this returns a matcher
end_comment

begin_comment
comment|/// that is convertible into any matcher of type \c To by constructing
end_comment

begin_comment
comment|/// \c HasMatcher<To, T>(InnerMatcher).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If a matcher does not need knowledge about the inner type, prefer to use
end_comment

begin_comment
comment|/// PolymorphicMatcherWithParam1.
end_comment

begin_expr_stmt
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
name|FromTypes
operator|=
name|AdaptativeDefaultFromTypes
operator|,
name|typename
name|ToTypes
operator|=
name|AdaptativeDefaultToTypes
operator|>
expr|struct
name|ArgumentAdaptingMatcherFunc
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Adaptor
block|{
name|public
operator|:
name|explicit
name|Adaptor
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
typedef|typedef
name|ToTypes
name|ReturnTypes
typedef|;
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|Adaptor
operator|<
name|T
operator|>
name|create
argument_list|(
argument|const Matcher<T>&InnerMatcher
argument_list|)
block|{
return|return
name|Adaptor
operator|<
name|T
operator|>
operator|(
name|InnerMatcher
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Adaptor
operator|<
name|T
operator|>
name|operator
argument_list|()
operator|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|InnerMatcher
operator|)
specifier|const
block|{
return|return
name|create
argument_list|(
name|InnerMatcher
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief A PolymorphicMatcherWithParamN<MatcherT, P1, ..., PN> object can be
end_comment

begin_comment
comment|/// created from N parameters p1, ..., pN (of type P1, ..., PN) and
end_comment

begin_comment
comment|/// used as a Matcher<T> where a MatcherT<T, P1, ..., PN>(p1, ..., pN)
end_comment

begin_comment
comment|/// can be constructed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|/// - PolymorphicMatcherWithParam0<IsDefinitionMatcher>()
end_comment

begin_comment
comment|///   creates an object that can be used as a Matcher<T> for any type T
end_comment

begin_comment
comment|///   where an IsDefinitionMatcher<T>() can be constructed.
end_comment

begin_comment
comment|/// - PolymorphicMatcherWithParam1<ValueEqualsMatcher, int>(42)
end_comment

begin_comment
comment|///   creates an object that can be used as a Matcher<T> for any type T
end_comment

begin_comment
comment|///   where a ValueEqualsMatcher<T, int>(42) can be constructed.
end_comment

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MatcherT
operator|,
name|typename
name|ReturnTypesF
operator|=
name|void
argument_list|(
name|AllNodeBaseTypes
argument_list|)
operator|>
name|class
name|PolymorphicMatcherWithParam0
block|{
name|public
operator|:
typedef|typedef
name|typename
name|ExtractFunctionArgMeta
operator|<
name|ReturnTypesF
operator|>
operator|::
name|type
name|ReturnTypes
expr_stmt|;
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
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|TypeListContainsSuperOf
operator|<
name|ReturnTypes
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|right_polymorphic_conversion
argument_list|)
block|;
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
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|P1
operator|>
name|class
name|MatcherT
operator|,
name|typename
name|P1
operator|,
name|typename
name|ReturnTypesF
operator|=
name|void
argument_list|(
name|AllNodeBaseTypes
argument_list|)
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
typedef|typedef
name|typename
name|ExtractFunctionArgMeta
operator|<
name|ReturnTypesF
operator|>
operator|::
name|type
name|ReturnTypes
expr_stmt|;
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
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|TypeListContainsSuperOf
operator|<
name|ReturnTypes
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|right_polymorphic_conversion
argument_list|)
block|;
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|P1
operator|,
name|typename
name|P2
operator|>
name|class
name|MatcherT
operator|,
name|typename
name|P1
operator|,
name|typename
name|P2
operator|,
name|typename
name|ReturnTypesF
operator|=
name|void
argument_list|(
name|AllNodeBaseTypes
argument_list|)
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
typedef|typedef
name|typename
name|ExtractFunctionArgMeta
operator|<
name|ReturnTypesF
operator|>
operator|::
name|type
name|ReturnTypes
expr_stmt|;
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
name|TOOLING_COMPILE_ASSERT
argument_list|(
operator|(
name|TypeListContainsSuperOf
operator|<
name|ReturnTypes
operator|,
name|T
operator|>
operator|::
name|value
operator|)
argument_list|,
name|right_polymorphic_conversion
argument_list|)
block|;
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
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|P2
name|Param2
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Matches any instance of the given NodeType.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is useful when a matcher syntactically requires a child matcher,
end_comment

begin_comment
comment|/// but the context doesn't care. See for example: anything().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: Alternatively we could also create a IsAMatcher or something
end_comment

begin_comment
comment|/// that checks that a dyn_cast is possible. This is purely needed for the
end_comment

begin_comment
comment|/// difference between calling for example:
end_comment

begin_comment
comment|///   record()
end_comment

begin_comment
comment|/// and
end_comment

begin_comment
comment|///   record(SomeMatcher)
end_comment

begin_comment
comment|/// In the second case we need the correct type we were dyn_cast'ed to in order
end_comment

begin_comment
comment|/// to get the right type for the inner matcher. In the first case we don't need
end_comment

begin_comment
comment|/// that, but we use the type conversion anyway and insert a TrueMatcher.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matcher<T> that wraps an inner Matcher<T> and binds the matched node
end_comment

begin_comment
comment|/// to an ID if the inner matcher matches on the node.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|std
operator|::
name|string
name|ID
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief A Matcher that allows binding the node it matches to an id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// BindableMatcher provides a \a bind() method that allows binding the
end_comment

begin_comment
comment|/// matched node to an id if the match was successful.
end_comment

begin_expr_stmt
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
name|explicit
name|BindableMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|M
argument_list|)
operator|:
name|Matcher
operator|<
name|T
operator|>
operator|(
name|M
operator|)
block|{}
name|explicit
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
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type T that have child nodes of type ChildT for
end_comment

begin_comment
comment|/// which a specified child matcher matches.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ChildT must be an AST base type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
name|Matcher
operator|<
name|ChildT
operator|>
name|ChildMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type T that have child nodes of type ChildT for
end_comment

begin_comment
comment|/// which a specified child matcher matches. ChildT must be an AST base
end_comment

begin_comment
comment|/// type.
end_comment

begin_comment
comment|/// As opposed to the HasMatcher, the ForEachMatcher will produce a match
end_comment

begin_comment
comment|/// for each child that matches.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
name|Matcher
operator|<
name|ChildT
operator|>
name|ChildMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type T if the given Matcher<T> does not match.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type argument MatcherT is required by PolymorphicMatcherWithParam1
end_comment

begin_comment
comment|/// but not actually used. It will always be instantiated with a type
end_comment

begin_comment
comment|/// convertible to Matcher<T>.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
comment|// The 'unless' matcher will always discard the result:
comment|// If the inner matcher doesn't match, unless returns true,
comment|// but the inner matcher cannot have bound anything.
comment|// If the inner matcher matches, the result is false, and
comment|// any possible binding will be discarded.
comment|// We still need to hand in all the bound nodes up to this
comment|// point so the inner matcher can depend on bound nodes,
comment|// and we need to actively discard the bound nodes, otherwise
comment|// the inner matcher will reset the bound nodes if it doesn't
comment|// match, but this would be inversed by 'unless'.
name|BoundNodesTreeBuilder
name|Discard
argument_list|(
operator|*
name|Builder
argument_list|)
block|;
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
operator|&
name|Discard
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
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief VariadicOperatorMatcher related types.
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Function signature for any variadic operator. It takes the inner
end_comment

begin_comment
comment|///   matchers as an array of DynTypedMatcher.
end_comment

begin_typedef
typedef|typedef
name|bool
argument_list|(
argument|*VariadicOperatorFunction
argument_list|)
operator|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
name|DynNode
operator|,
name|ASTMatchFinder
operator|*
name|Finder
operator|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
operator|,
name|ArrayRef
operator|<
name|DynTypedMatcher
operator|>
name|InnerMatchers
operator|)
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief \c MatcherInterface<T> implementation for an variadic operator.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|VariadicOperatorMatcherInterface
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|VariadicOperatorMatcherInterface
argument_list|(
argument|VariadicOperatorFunction Func
argument_list|,
argument|ArrayRef<const Matcher<T> *> InputMatchers
argument_list|)
operator|:
name|Func
argument_list|(
argument|Func
argument_list|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|InputMatchers
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|InnerMatchers
operator|.
name|push_back
argument_list|(
operator|*
name|InputMatchers
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
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
name|Func
argument_list|(
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|,
name|InnerMatchers
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|VariadicOperatorFunction
name|Func
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|DynTypedMatcher
operator|>
name|InnerMatchers
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief "No argument" placeholder to use as template paratemers.
end_comment

begin_struct
struct|struct
name|VariadicOperatorNoArg
block|{}
struct|;
end_struct

begin_comment
comment|/// \brief Polymorphic matcher object that uses a \c VariadicOperatorFunction
end_comment

begin_comment
comment|///   operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Input matchers can have any type (including other polymorphic matcher
end_comment

begin_comment
comment|/// types), and the actual Matcher<T> is generated on demand with an implicit
end_comment

begin_comment
comment|/// coversion operator.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|P1
operator|,
name|typename
name|P2
operator|,
name|typename
name|P3
operator|=
name|VariadicOperatorNoArg
operator|,
name|typename
name|P4
operator|=
name|VariadicOperatorNoArg
operator|,
name|typename
name|P5
operator|=
name|VariadicOperatorNoArg
operator|>
name|class
name|VariadicOperatorMatcher
block|{
name|public
operator|:
name|VariadicOperatorMatcher
argument_list|(
argument|VariadicOperatorFunction Func
argument_list|,
argument|const P1&Param1
argument_list|,
argument|const P2&Param2
argument_list|,
argument|const P3&Param3 = VariadicOperatorNoArg()
argument_list|,
argument|const P4&Param4 = VariadicOperatorNoArg()
argument_list|,
argument|const P5&Param5 = VariadicOperatorNoArg()
argument_list|)
operator|:
name|Func
argument_list|(
name|Func
argument_list|)
block|,
name|Param1
argument_list|(
name|Param1
argument_list|)
block|,
name|Param2
argument_list|(
name|Param2
argument_list|)
block|,
name|Param3
argument_list|(
name|Param3
argument_list|)
block|,
name|Param4
argument_list|(
name|Param4
argument_list|)
block|,
name|Param5
argument_list|(
argument|Param5
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
name|Matcher
operator|<
name|T
operator|>
operator|*
name|Array
index|[
literal|5
index|]
block|;
name|size_t
name|Size
operator|=
literal|0
block|;
name|addMatcher
operator|<
name|T
operator|>
operator|(
name|Param1
operator|,
name|Array
operator|,
name|Size
operator|)
block|;
name|addMatcher
operator|<
name|T
operator|>
operator|(
name|Param2
operator|,
name|Array
operator|,
name|Size
operator|)
block|;
name|addMatcher
operator|<
name|T
operator|>
operator|(
name|Param3
operator|,
name|Array
operator|,
name|Size
operator|)
block|;
name|addMatcher
operator|<
name|T
operator|>
operator|(
name|Param4
operator|,
name|Array
operator|,
name|Size
operator|)
block|;
name|addMatcher
operator|<
name|T
operator|>
operator|(
name|Param5
operator|,
name|Array
operator|,
name|Size
operator|)
block|;
name|Matcher
operator|<
name|T
operator|>
name|Result
argument_list|(
argument|new VariadicOperatorMatcherInterface<T>(         Func, ArrayRef<const Matcher<T> *>(Array, Size))
argument_list|)
block|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|Size
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|delete
name|Array
index|[
name|i
index|]
decl_stmt|;
return|return
name|Result
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|addMatcher
argument_list|(
argument|const Matcher<T>&M
argument_list|,
argument|Matcher<T> **Array
argument_list|,
argument|size_t&Size
argument_list|)
block|{
name|Array
index|[
name|Size
operator|++
index|]
operator|=
name|new
name|Matcher
operator|<
name|T
operator|>
operator|(
name|M
operator|)
block|;   }
comment|/// \brief Overload to ignore \c VariadicOperatorNoArg arguments.
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|addMatcher
argument_list|(
argument|VariadicOperatorNoArg
argument_list|,
argument|Matcher<T> **Array
argument_list|,
argument|size_t&Size
argument_list|)
block|{}
specifier|const
name|VariadicOperatorFunction
name|Func
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|P1
name|Param1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|P2
name|Param2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|P3
name|Param3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|P4
name|Param4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|P5
name|Param5
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Overloaded function object to generate VariadicOperatorMatcher
end_comment

begin_comment
comment|///   objects from arbitrary matchers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It supports 2-5 argument overloaded operator(). More can be added if needed.
end_comment

begin_struct
struct|struct
name|VariadicOperatorMatcherFunc
block|{
name|VariadicOperatorFunction
name|Func
decl_stmt|;
name|template
operator|<
name|typename
name|M1
operator|,
name|typename
name|M2
operator|>
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|>
name|operator
argument_list|()
operator|(
specifier|const
name|M1
operator|&
name|P1
operator|,
specifier|const
name|M2
operator|&
name|P2
operator|)
specifier|const
block|{
return|return
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|>
operator|(
name|Func
operator|,
name|P1
operator|,
name|P2
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|M1
operator|,
name|typename
name|M2
operator|,
name|typename
name|M3
operator|>
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|,
name|M3
operator|>
name|operator
argument_list|()
operator|(
specifier|const
name|M1
operator|&
name|P1
operator|,
specifier|const
name|M2
operator|&
name|P2
operator|,
specifier|const
name|M3
operator|&
name|P3
operator|)
specifier|const
block|{
return|return
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|,
name|M3
operator|>
operator|(
name|Func
operator|,
name|P1
operator|,
name|P2
operator|,
name|P3
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|M1
operator|,
name|typename
name|M2
operator|,
name|typename
name|M3
operator|,
name|typename
name|M4
operator|>
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|,
name|M3
operator|,
name|M4
operator|>
name|operator
argument_list|()
operator|(
specifier|const
name|M1
operator|&
name|P1
operator|,
specifier|const
name|M2
operator|&
name|P2
operator|,
specifier|const
name|M3
operator|&
name|P3
operator|,
specifier|const
name|M4
operator|&
name|P4
operator|)
specifier|const
block|{
return|return
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|,
name|M3
operator|,
name|M4
operator|>
operator|(
name|Func
operator|,
name|P1
operator|,
name|P2
operator|,
name|P3
operator|,
name|P4
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|M1
operator|,
name|typename
name|M2
operator|,
name|typename
name|M3
operator|,
name|typename
name|M4
operator|,
name|typename
name|M5
operator|>
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|,
name|M3
operator|,
name|M4
operator|,
name|M5
operator|>
name|operator
argument_list|()
operator|(
specifier|const
name|M1
operator|&
name|P1
operator|,
specifier|const
name|M2
operator|&
name|P2
operator|,
specifier|const
name|M3
operator|&
name|P3
operator|,
specifier|const
name|M4
operator|&
name|P4
operator|,
specifier|const
name|M5
operator|&
name|P5
operator|)
specifier|const
block|{
return|return
name|VariadicOperatorMatcher
operator|<
name|M1
operator|,
name|M2
operator|,
name|M3
operator|,
name|M4
operator|,
name|M5
operator|>
operator|(
name|Func
operator|,
name|P1
operator|,
name|P2
operator|,
name|P3
operator|,
name|P4
operator|,
name|P5
operator|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \brief Matches nodes for which all provided matchers match.
end_comment

begin_decl_stmt
name|bool
name|AllOfVariadicOperator
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
name|DynNode
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|,
name|ArrayRef
operator|<
name|DynTypedMatcher
operator|>
name|InnerMatchers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Matches nodes for which at least one of the provided matchers
end_comment

begin_comment
comment|/// matches, but doesn't stop at the first match.
end_comment

begin_decl_stmt
name|bool
name|EachOfVariadicOperator
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
name|DynNode
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|,
name|ArrayRef
operator|<
name|DynTypedMatcher
operator|>
name|InnerMatchers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Matches nodes for which at least one of the provided matchers
end_comment

begin_comment
comment|/// matches.
end_comment

begin_decl_stmt
name|bool
name|AnyOfVariadicOperator
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
name|DynNode
argument_list|,
name|ASTMatchFinder
operator|*
name|Finder
argument_list|,
name|BoundNodesTreeBuilder
operator|*
name|Builder
argument_list|,
name|ArrayRef
operator|<
name|DynTypedMatcher
operator|>
name|InnerMatchers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Creates a Matcher<T> that matches if all inner matchers match.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|BindableMatcher
operator|<
name|T
operator|>
name|makeAllOfComposite
argument_list|(
argument|ArrayRef<const Matcher<T> *> InnerMatchers
argument_list|)
block|{
return|return
name|BindableMatcher
operator|<
name|T
operator|>
operator|(
name|new
name|VariadicOperatorMatcherInterface
operator|<
name|T
operator|>
operator|(
name|AllOfVariadicOperator
operator|,
name|InnerMatchers
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Creates a Matcher<T> that matches if
end_comment

begin_comment
comment|/// T is dyn_cast'able into InnerT and all inner matchers match.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns BindableMatcher, as matchers that use dyn_cast have
end_comment

begin_comment
comment|/// the same object both to match on and to run submatchers on,
end_comment

begin_comment
comment|/// so there is no ambiguity with what gets bound.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
return|return
name|BindableMatcher
operator|<
name|T
operator|>
operator|(
name|DynTypedMatcher
argument_list|(
name|makeAllOfComposite
argument_list|(
name|InnerMatchers
argument_list|)
argument_list|)
operator|.
name|unconditionalConvertTo
operator|<
name|T
operator|>
operator|(
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Matches nodes of type T that have at least one descendant node of
end_comment

begin_comment
comment|/// type DescendantT for which the given inner matcher matches.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DescendantT must be an AST base type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
name|Matcher
operator|<
name|DescendantT
operator|>
name|DescendantMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type \c T that have a parent node of type \c ParentT
end_comment

begin_comment
comment|/// for which the given inner matcher matches.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \c ParentT must be an AST base type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ParentT
operator|>
name|class
name|HasParentMatcher
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
name|ParentT
operator|>
operator|::
name|value
argument_list|,
name|has_parent_only_accepts_base_type_matcher
argument_list|)
block|;
name|public
operator|:
name|explicit
name|HasParentMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|ParentT
operator|>
operator|&
name|ParentMatcher
argument_list|)
operator|:
name|ParentMatcher
argument_list|(
argument|ParentMatcher
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
name|matchesAncestorOf
argument_list|(
name|Node
argument_list|,
name|ParentMatcher
argument_list|,
name|Builder
argument_list|,
name|ASTMatchFinder
operator|::
name|AMM_ParentOnly
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|ParentT
operator|>
name|ParentMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type \c T that have at least one ancestor node of
end_comment

begin_comment
comment|/// type \c AncestorT for which the given inner matcher matches.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \c AncestorT must be an AST base type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|AncestorT
operator|>
name|class
name|HasAncestorMatcher
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
name|AncestorT
operator|>
operator|::
name|value
argument_list|,
name|has_ancestor_only_accepts_base_type_matcher
argument_list|)
block|;
name|public
operator|:
name|explicit
name|HasAncestorMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|AncestorT
operator|>
operator|&
name|AncestorMatcher
argument_list|)
operator|:
name|AncestorMatcher
argument_list|(
argument|AncestorMatcher
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
name|matchesAncestorOf
argument_list|(
name|Node
argument_list|,
name|AncestorMatcher
argument_list|,
name|Builder
argument_list|,
name|ASTMatchFinder
operator|::
name|AMM_All
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|AncestorT
operator|>
name|AncestorMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type T that have at least one descendant node of
end_comment

begin_comment
comment|/// type DescendantT for which the given inner matcher matches.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DescendantT must be an AST base type.
end_comment

begin_comment
comment|/// As opposed to HasDescendantMatcher, ForEachDescendantMatcher will match
end_comment

begin_comment
comment|/// for each descendant node that matches instead of only for the first.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
name|Matcher
operator|<
name|DescendantT
operator|>
name|DescendantMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches on nodes that have a getValue() method if getValue() equals
end_comment

begin_comment
comment|/// the value the ValueEqualsMatcher was constructed with.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
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
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief A VariadicDynCastAllOfMatcher<SourceT, TargetT> object is a
end_comment

begin_comment
comment|/// variadic functor that takes a number of Matcher<TargetT> and returns a
end_comment

begin_comment
comment|/// Matcher<SourceT> that matches TargetT nodes that are matched by all of the
end_comment

begin_comment
comment|/// given matchers, if SourceT can be dynamically casted into TargetT.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///   const VariadicDynCastAllOfMatcher<
end_comment

begin_comment
comment|///       Decl, CXXRecordDecl> record;
end_comment

begin_comment
comment|/// Creates a functor record(...) that creates a Matcher<Decl> given
end_comment

begin_comment
comment|/// a variable number of arguments of type Matcher<CXXRecordDecl>.
end_comment

begin_comment
comment|/// The returned matcher matches if the given Decl can by dynamically
end_comment

begin_comment
comment|/// casted to CXXRecordDecl and all given matchers match.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SourceT
operator|,
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
operator|,
name|Matcher
operator|<
name|TargetT
operator|>
operator|,
name|makeDynCastAllOfComposite
operator|<
name|SourceT
operator|,
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A \c VariadicAllOfMatcher<T> object is a variadic functor that takes
end_comment

begin_comment
comment|/// a number of \c Matcher<T> and returns a \c Matcher<T> that matches \c T
end_comment

begin_comment
comment|/// nodes that are matched by all of the given matchers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///   const VariadicAllOfMatcher<NestedNameSpecifier> nestedNameSpecifier;
end_comment

begin_comment
comment|/// Creates a functor nestedNameSpecifier(...) that creates a
end_comment

begin_comment
comment|/// \c Matcher<NestedNameSpecifier> given a variable number of arguments of type
end_comment

begin_comment
comment|/// \c Matcher<NestedNameSpecifier>.
end_comment

begin_comment
comment|/// The returned matcher matches if all given matchers match.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|VariadicAllOfMatcher
operator|:
name|public
name|llvm
operator|::
name|VariadicFunction
operator|<
name|BindableMatcher
operator|<
name|T
operator|>
operator|,
name|Matcher
operator|<
name|T
operator|>
operator|,
name|makeAllOfComposite
operator|<
name|T
operator|>
expr|>
block|{
name|public
operator|:
name|VariadicAllOfMatcher
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Matches nodes of type \c TLoc for which the inner
end_comment

begin_comment
comment|/// \c Matcher<T> matches.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|TLoc
operator|,
name|typename
name|T
operator|>
name|class
name|LocMatcher
operator|:
name|public
name|MatcherInterface
operator|<
name|TLoc
operator|>
block|{
name|public
operator|:
name|explicit
name|LocMatcher
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
argument|const TLoc&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|Node
condition|)
return|return
name|false
return|;
return|return
name|InnerMatcher
operator|.
name|matches
argument_list|(
operator|*
name|extract
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|NestedNameSpecifier
modifier|*
name|extract
argument_list|(
specifier|const
name|NestedNameSpecifierLoc
operator|&
name|Loc
argument_list|)
decl|const
block|{
return|return
name|Loc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|InnerMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches \c TypeLocs based on an inner matcher matching a certain
end_comment

begin_comment
comment|/// \c QualType.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used to implement the \c loc() matcher.
end_comment

begin_decl_stmt
name|class
name|TypeLocTypeMatcher
range|:
name|public
name|MatcherInterface
operator|<
name|TypeLoc
operator|>
block|{
name|public
operator|:
name|explicit
name|TypeLocTypeMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|QualType
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
argument|const TypeLoc&Node
argument_list|,
argument|ASTMatchFinder *Finder
argument_list|,
argument|BoundNodesTreeBuilder *Builder
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|Node
condition|)
return|return
name|false
return|;
return|return
name|InnerMatcher
operator|.
name|matches
argument_list|(
name|Node
operator|.
name|getType
argument_list|()
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|QualType
operator|>
name|InnerMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type \c T for which the inner matcher matches on a
end_comment

begin_comment
comment|/// another node of type \c T that can be reached using a given traverse
end_comment

begin_comment
comment|/// function.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypeTraverseMatcher
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
name|TypeTraverseMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|QualType
operator|>
operator|&
name|InnerMatcher
argument_list|,
name|QualType
argument_list|(
argument|T::*TraverseFunction
argument_list|)
operator|(
operator|)
specifier|const
argument_list|)
operator|:
name|InnerMatcher
argument_list|(
name|InnerMatcher
argument_list|)
block|,
name|TraverseFunction
argument_list|(
argument|TraverseFunction
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
name|QualType
name|NextNode
operator|=
operator|(
name|Node
operator|.*
name|TraverseFunction
operator|)
operator|(
operator|)
block|;
if|if
condition|(
name|NextNode
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|InnerMatcher
operator|.
name|matches
argument_list|(
name|NextNode
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|QualType
operator|>
name|InnerMatcher
expr_stmt|;
end_expr_stmt

begin_macro
name|QualType
argument_list|(
argument|T::*TraverseFunction
argument_list|)
end_macro

begin_expr_stmt
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Matches nodes of type \c T in a ..Loc hierarchy, for which the inner
end_comment

begin_comment
comment|/// matcher matches on a another node of type \c T that can be reached using a
end_comment

begin_comment
comment|/// given traverse function.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypeLocTraverseMatcher
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
name|TypeLocTraverseMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|TypeLoc
operator|>
operator|&
name|InnerMatcher
argument_list|,
name|TypeLoc
argument_list|(
argument|T::*TraverseFunction
argument_list|)
operator|(
operator|)
specifier|const
argument_list|)
operator|:
name|InnerMatcher
argument_list|(
name|InnerMatcher
argument_list|)
block|,
name|TraverseFunction
argument_list|(
argument|TraverseFunction
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
name|TypeLoc
name|NextNode
operator|=
operator|(
name|Node
operator|.*
name|TraverseFunction
operator|)
operator|(
operator|)
block|;
if|if
condition|(
operator|!
name|NextNode
condition|)
return|return
name|false
return|;
return|return
name|InnerMatcher
operator|.
name|matches
argument_list|(
name|NextNode
argument_list|,
name|Finder
argument_list|,
name|Builder
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|TypeLoc
operator|>
name|InnerMatcher
expr_stmt|;
end_expr_stmt

begin_macro
name|TypeLoc
argument_list|(
argument|T::*TraverseFunction
argument_list|)
end_macro

begin_expr_stmt
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Converts a \c Matcher<InnerT> to a \c Matcher<OuterT>, where
end_comment

begin_comment
comment|/// \c OuterT is any type that is supported by \c Getter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code Getter<OuterT>::value() \endcode returns a
end_comment

begin_comment
comment|/// \code InnerTBase (OuterT::*)() \endcode, which is used to adapt a \c OuterT
end_comment

begin_comment
comment|/// object into a \c InnerT
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerTBase
operator|,
name|template
operator|<
name|typename
name|OuterT
operator|>
name|class
name|Getter
operator|,
name|template
operator|<
name|typename
name|OuterT
operator|>
name|class
name|MatcherImpl
operator|,
name|typename
name|ReturnTypesF
operator|>
name|class
name|TypeTraversePolymorphicMatcher
block|{
name|private
operator|:
typedef|typedef
name|TypeTraversePolymorphicMatcher
operator|<
name|InnerTBase
operator|,
name|Getter
operator|,
name|MatcherImpl
operator|,
name|ReturnTypesF
operator|>
name|Self
expr_stmt|;
specifier|static
name|Self
name|create
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|Matcher
operator|<
name|InnerTBase
operator|>
operator|*
operator|>
name|InnerMatchers
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|ExtractFunctionArgMeta
operator|<
name|ReturnTypesF
operator|>
operator|::
name|type
name|ReturnTypes
expr_stmt|;
end_typedef

begin_decl_stmt
name|explicit
name|TypeTraversePolymorphicMatcher
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|Matcher
operator|<
name|InnerTBase
operator|>
operator|*
operator|>
name|InnerMatchers
argument_list|)
range|:
name|InnerMatcher
argument_list|(
argument|makeAllOfComposite(InnerMatchers)
argument_list|)
block|{}
name|template
operator|<
name|typename
name|OuterT
operator|>
name|operator
name|Matcher
operator|<
name|OuterT
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|OuterT
operator|>
operator|(
name|new
name|MatcherImpl
operator|<
name|OuterT
operator|>
operator|(
name|InnerMatcher
expr|,
name|Getter
operator|<
name|OuterT
operator|>
operator|::
name|value
argument_list|()
operator|)
operator|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|struct
name|Func
range|:
name|public
name|llvm
operator|::
name|VariadicFunction
operator|<
name|Self
decl_stmt|,
name|Matcher
decl|<
name|InnerTBase
decl|>
decl_stmt|,
modifier|&
name|Self
decl|::
name|create
decl|>
block|{
name|Func
argument_list|()
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|InnerTBase
operator|>
name|InnerMatcher
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Define the create() method out of line to silence a GCC warning about
end_comment

begin_comment
comment|// the struct "Func" having greater visibility than its base, which comes from
end_comment

begin_comment
comment|// using the flag -fvisibility-inlines-hidden.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerTBase
operator|,
name|template
operator|<
name|typename
name|OuterT
operator|>
name|class
name|Getter
operator|,
name|template
operator|<
name|typename
name|OuterT
operator|>
name|class
name|MatcherImpl
operator|,
name|typename
name|ReturnTypesF
operator|>
name|TypeTraversePolymorphicMatcher
operator|<
name|InnerTBase
operator|,
name|Getter
operator|,
name|MatcherImpl
operator|,
name|ReturnTypesF
operator|>
name|TypeTraversePolymorphicMatcher
operator|<
name|InnerTBase
operator|,
name|Getter
operator|,
name|MatcherImpl
operator|,
name|ReturnTypesF
operator|>
operator|::
name|create
argument_list|(
argument|ArrayRef<const Matcher<InnerTBase> *> InnerMatchers
argument_list|)
block|{
return|return
name|Self
argument_list|(
name|InnerMatchers
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace internal
end_comment

begin_comment
unit|}
comment|// end namespace ast_matchers
end_comment

begin_comment
unit|}
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

