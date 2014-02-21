begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTMatchersMacros.h - Structural query framework -------*- C++ -*-===//
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
comment|//  Defines macros that enable us to define new matchers in a single place.
end_comment

begin_comment
comment|//  Since a matcher is a function which returns a Matcher<T> object, where
end_comment

begin_comment
comment|//  T is the type of the actual implementation of the matcher, the macros allow
end_comment

begin_comment
comment|//  us to write matchers like functions and take care of the definition of the
end_comment

begin_comment
comment|//  class boilerplate.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Note that when you define a matcher with an AST_MATCHER* macro, only the
end_comment

begin_comment
comment|//  function which creates the matcher goes into the current namespace - the
end_comment

begin_comment
comment|//  class that implements the actual matcher, which gets returned by the
end_comment

begin_comment
comment|//  generator function, is put into the 'internal' namespace. This allows us
end_comment

begin_comment
comment|//  to only have the functions (which is all the user cares about) in the
end_comment

begin_comment
comment|//  'ast_matchers' namespace and hide the boilerplate.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  To define a matcher in user code, always put it into the clang::ast_matchers
end_comment

begin_comment
comment|//  namespace and refer to the internal types via the 'internal::':
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  namespace clang {
end_comment

begin_comment
comment|//  namespace ast_matchers {
end_comment

begin_comment
comment|//  AST_MATCHER_P(MemberExpr, Member,
end_comment

begin_comment
comment|//                internal::Matcher<ValueDecl>, InnerMatcher) {
end_comment

begin_comment
comment|//    return InnerMatcher.matches(*Node.getMemberDecl(), Finder, Builder);
end_comment

begin_comment
comment|//  }
end_comment

begin_comment
comment|//  } // end namespace ast_matchers
end_comment

begin_comment
comment|//  } // end namespace clang
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
name|LLVM_CLANG_AST_MATCHERS_AST_MATCHERS_MACROS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_MATCHERS_AST_MATCHERS_MACROS_H
end_define

begin_comment
comment|/// \brief AST_MATCHER(Type, DefineMatcher) { ... }
end_comment

begin_comment
comment|/// defines a zero parameter function named DefineMatcher() that returns a
end_comment

begin_comment
comment|/// Matcher<Type> object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The code between the curly braces has access to the following variables:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Node:                  the AST node being matched; its type is Type.
end_comment

begin_comment
comment|///   Finder:                an ASTMatchFinder*.
end_comment

begin_comment
comment|///   Builder:               a BoundNodesTreeBuilder*.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The code should return true if 'Node' matches.
end_comment

begin_define
define|#
directive|define
name|AST_MATCHER
parameter_list|(
name|Type
parameter_list|,
name|DefineMatcher
parameter_list|)
define|\
value|namespace internal {                                                         \   class matcher_##DefineMatcher##Matcher : public MatcherInterface<Type> {     \   public:                                                                      \     explicit matcher_##DefineMatcher##Matcher() {}                             \     virtual bool matches(const Type&Node, ASTMatchFinder *Finder,             \                          BoundNodesTreeBuilder *Builder) const;                \   };                                                                           \   }                                                                            \   inline internal::Matcher<Type> DefineMatcher() {                             \     return internal::makeMatcher(                                              \         new internal::matcher_##DefineMatcher##Matcher());                     \   }                                                                            \   inline bool internal::matcher_##DefineMatcher##Matcher::matches(             \       const Type&Node, ASTMatchFinder *Finder,                                \       BoundNodesTreeBuilder *Builder) const
end_define

begin_comment
comment|/// \brief AST_MATCHER_P(Type, DefineMatcher, ParamType, Param) { ... }
end_comment

begin_comment
comment|/// defines a single-parameter function named DefineMatcher() that returns a
end_comment

begin_comment
comment|/// Matcher<Type> object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The code between the curly braces has access to the following variables:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Node:                  the AST node being matched; its type is Type.
end_comment

begin_comment
comment|///   Param:                 the parameter passed to the function; its type
end_comment

begin_comment
comment|///                          is ParamType.
end_comment

begin_comment
comment|///   Finder:                an ASTMatchFinder*.
end_comment

begin_comment
comment|///   Builder:               a BoundNodesTreeBuilder*.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The code should return true if 'Node' matches.
end_comment

begin_define
define|#
directive|define
name|AST_MATCHER_P
parameter_list|(
name|Type
parameter_list|,
name|DefineMatcher
parameter_list|,
name|ParamType
parameter_list|,
name|Param
parameter_list|)
define|\
value|AST_MATCHER_P_OVERLOAD(Type, DefineMatcher, ParamType, Param, 0)
end_define

begin_define
define|#
directive|define
name|AST_MATCHER_P_OVERLOAD
parameter_list|(
name|Type
parameter_list|,
name|DefineMatcher
parameter_list|,
name|ParamType
parameter_list|,
name|Param
parameter_list|,          \
name|OverloadId
parameter_list|)
define|\
value|namespace internal {                                                         \   class matcher_##DefineMatcher##OverloadId##Matcher                           \       : public MatcherInterface<Type> {                                        \   public:                                                                      \     explicit matcher_##DefineMatcher##OverloadId##Matcher(                     \         const ParamType&A##Param)                                             \         : Param(A##Param) {}                                                   \     virtual bool matches(const Type&Node, ASTMatchFinder *Finder,             \                          BoundNodesTreeBuilder *Builder) const;                \                                                                                \   private:                                                                     \     const ParamType Param;                                                     \   };                                                                           \   }                                                                            \   inline internal::Matcher<Type> DefineMatcher(const ParamType&Param) {       \     return internal::makeMatcher(                                              \         new internal::matcher_##DefineMatcher##OverloadId##Matcher(Param));    \   }                                                                            \   typedef internal::Matcher<Type>(&DefineMatcher##_Type##OverloadId)(          \       const ParamType&Param);                                                 \   inline bool internal::matcher_##DefineMatcher##OverloadId##Matcher::matches( \       const Type&Node, ASTMatchFinder *Finder,                                \       BoundNodesTreeBuilder *Builder) const
end_define

begin_comment
comment|/// \brief AST_MATCHER_P2(
end_comment

begin_comment
comment|///     Type, DefineMatcher, ParamType1, Param1, ParamType2, Param2) { ... }
end_comment

begin_comment
comment|/// defines a two-parameter function named DefineMatcher() that returns a
end_comment

begin_comment
comment|/// Matcher<Type> object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The code between the curly braces has access to the following variables:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Node:                  the AST node being matched; its type is Type.
end_comment

begin_comment
comment|///   Param1, Param2:        the parameters passed to the function; their types
end_comment

begin_comment
comment|///                          are ParamType1 and ParamType2.
end_comment

begin_comment
comment|///   Finder:                an ASTMatchFinder*.
end_comment

begin_comment
comment|///   Builder:               a BoundNodesTreeBuilder*.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The code should return true if 'Node' matches.
end_comment

begin_define
define|#
directive|define
name|AST_MATCHER_P2
parameter_list|(
name|Type
parameter_list|,
name|DefineMatcher
parameter_list|,
name|ParamType1
parameter_list|,
name|Param1
parameter_list|,
name|ParamType2
parameter_list|,    \
name|Param2
parameter_list|)
define|\
value|AST_MATCHER_P2_OVERLOAD(Type, DefineMatcher, ParamType1, Param1, ParamType2, \                           Param2, 0)
end_define

begin_define
define|#
directive|define
name|AST_MATCHER_P2_OVERLOAD
parameter_list|(
name|Type
parameter_list|,
name|DefineMatcher
parameter_list|,
name|ParamType1
parameter_list|,
name|Param1
parameter_list|,       \
name|ParamType2
parameter_list|,
name|Param2
parameter_list|,
name|OverloadId
parameter_list|)
define|\
value|namespace internal {                                                         \   class matcher_##DefineMatcher##OverloadId##Matcher                           \       : public MatcherInterface<Type> {                                        \   public:                                                                      \     matcher_##DefineMatcher##OverloadId##Matcher(const ParamType1&A##Param1,  \                                                  const ParamType2&A##Param2)  \         : Param1(A##Param1), Param2(A##Param2) {}                              \     virtual bool matches(const Type&Node, ASTMatchFinder *Finder,             \                          BoundNodesTreeBuilder *Builder) const;                \                                                                                \   private:                                                                     \     const ParamType1 Param1;                                                   \     const ParamType2 Param2;                                                   \   };                                                                           \   }                                                                            \   inline internal::Matcher<Type> DefineMatcher(const ParamType1&Param1,       \                                                const ParamType2&Param2) {     \     return internal::makeMatcher(                                              \         new internal::matcher_##DefineMatcher##OverloadId##Matcher(Param1,     \                                                                    Param2));   \   }                                                                            \   typedef internal::Matcher<Type>(&DefineMatcher##_Type##OverloadId)(          \       const ParamType1&Param1, const ParamType2&Param2);                     \   inline bool internal::matcher_##DefineMatcher##OverloadId##Matcher::matches( \       const Type&Node, ASTMatchFinder *Finder,                                \       BoundNodesTreeBuilder *Builder) const
end_define

begin_comment
comment|/// \brief Construct a type-list to be passed to the AST_POLYMORPHIC_MATCHER*
end_comment

begin_comment
comment|///   macros.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// You can't pass something like \c TypeList<Foo, Bar> to a macro, because it
end_comment

begin_comment
comment|/// will look at that as two arguments. However, you can pass
end_comment

begin_comment
comment|/// \c void(TypeList<Foo, Bar>), which works thanks to the parenthesis.
end_comment

begin_comment
comment|/// The \c PolymorphicMatcherWithParam* classes will unpack the function type to
end_comment

begin_comment
comment|/// extract the TypeList object.
end_comment

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_SUPPORTED_TYPES_1
parameter_list|(
name|t1
parameter_list|)
value|void(internal::TypeList<t1>)
end_define

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_SUPPORTED_TYPES_2
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|)
define|\
value|void(internal::TypeList<t1, t2>)
end_define

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_SUPPORTED_TYPES_3
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|)
define|\
value|void(internal::TypeList<t1, t2, t3>)
end_define

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_SUPPORTED_TYPES_4
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|)
define|\
value|void(internal::TypeList<t1, t2, t3, t4>)
end_define

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_SUPPORTED_TYPES_5
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|)
define|\
value|void(internal::TypeList<t1, t2, t3, internal::TypeList<t4, t5>>)
end_define

begin_comment
comment|/// \brief AST_POLYMORPHIC_MATCHER(DefineMatcher) { ... }
end_comment

begin_comment
comment|/// defines a single-parameter function named DefineMatcher() that is
end_comment

begin_comment
comment|/// polymorphic in the return type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The variables are the same as for AST_MATCHER, but NodeType will be deduced
end_comment

begin_comment
comment|/// from the calling context.
end_comment

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_MATCHER
parameter_list|(
name|DefineMatcher
parameter_list|,
name|ReturnTypesF
parameter_list|)
define|\
value|namespace internal {                                                         \   template<typename NodeType>                                                 \   class matcher_##DefineMatcher##Matcher : public MatcherInterface<NodeType> { \   public:                                                                      \     virtual bool matches(const NodeType&Node, ASTMatchFinder *Finder,         \                          BoundNodesTreeBuilder *Builder) const;                \   };                                                                           \   }                                                                            \   inline internal::PolymorphicMatcherWithParam0<                               \       internal::matcher_##DefineMatcher##Matcher, ReturnTypesF>                \   DefineMatcher() {                                                            \     return internal::PolymorphicMatcherWithParam0<                             \         internal::matcher_##DefineMatcher##Matcher, ReturnTypesF>();           \   }                                                                            \   template<typename NodeType>                                                 \   bool internal::matcher_##DefineMatcher##Matcher<NodeType>::matches(          \       const NodeType&Node, ASTMatchFinder *Finder,                            \       BoundNodesTreeBuilder *Builder) const
end_define

begin_comment
comment|/// \brief AST_POLYMORPHIC_MATCHER_P(DefineMatcher, ParamType, Param) { ... }
end_comment

begin_comment
comment|/// defines a single-parameter function named DefineMatcher() that is
end_comment

begin_comment
comment|/// polymorphic in the return type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The variables are the same as for
end_comment

begin_comment
comment|/// AST_MATCHER_P, with the addition of NodeType, which specifies the node type
end_comment

begin_comment
comment|/// of the matcher Matcher<NodeType> returned by the function matcher().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: Pull out common code with above macro?
end_comment

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_MATCHER_P
parameter_list|(
name|DefineMatcher
parameter_list|,
name|ReturnTypesF
parameter_list|,
name|ParamType
parameter_list|,      \
name|Param
parameter_list|)
define|\
value|AST_POLYMORPHIC_MATCHER_P_OVERLOAD(DefineMatcher, ReturnTypesF, ParamType,   \                                      Param, 0)
end_define

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_MATCHER_P_OVERLOAD
parameter_list|(
name|DefineMatcher
parameter_list|,
name|ReturnTypesF
parameter_list|,        \
name|ParamType
parameter_list|,
name|Param
parameter_list|,
name|OverloadId
parameter_list|)
define|\
value|namespace internal {                                                         \   template<typename NodeType, typename ParamT>                                \   class matcher_##DefineMatcher##OverloadId##Matcher                           \       : public MatcherInterface<NodeType> {                                    \   public:                                                                      \     explicit matcher_##DefineMatcher##OverloadId##Matcher(                     \         const ParamType&A##Param)                                             \         : Param(A##Param) {}                                                   \     virtual bool matches(const NodeType&Node, ASTMatchFinder *Finder,         \                          BoundNodesTreeBuilder *Builder) const;                \                                                                                \   private:                                                                     \     const ParamType Param;                                                     \   };                                                                           \   }                                                                            \   inline internal::PolymorphicMatcherWithParam1<                               \       internal::matcher_##DefineMatcher##OverloadId##Matcher, ParamType,       \       ReturnTypesF> DefineMatcher(const ParamType&Param) {                    \     return internal::PolymorphicMatcherWithParam1<                             \         internal::matcher_##DefineMatcher##OverloadId##Matcher, ParamType,     \         ReturnTypesF>(Param);                                                  \   }                                                                            \   typedef internal::PolymorphicMatcherWithParam1<                              \       internal::matcher_##DefineMatcher##OverloadId##Matcher, ParamType,       \       ReturnTypesF>(&DefineMatcher##_Type##OverloadId)(                        \       const ParamType&Param);                                                 \   template<typename NodeType, typename ParamT>                                \   bool internal::matcher_##DefineMatcher##OverloadId##Matcher<                 \       NodeType, ParamT>::matches(const NodeType&Node, ASTMatchFinder *Finder, \                                  BoundNodesTreeBuilder *Builder) const
end_define

begin_comment
comment|/// \brief AST_POLYMORPHIC_MATCHER_P2(
end_comment

begin_comment
comment|///     DefineMatcher, ParamType1, Param1, ParamType2, Param2) { ... }
end_comment

begin_comment
comment|/// defines a two-parameter function named matcher() that is polymorphic in
end_comment

begin_comment
comment|/// the return type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The variables are the same as for AST_MATCHER_P2, with the
end_comment

begin_comment
comment|/// addition of NodeType, which specifies the node type of the matcher
end_comment

begin_comment
comment|/// Matcher<NodeType> returned by the function DefineMatcher().
end_comment

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_MATCHER_P2
parameter_list|(
name|DefineMatcher
parameter_list|,
name|ReturnTypesF
parameter_list|,
name|ParamType1
parameter_list|,    \
name|Param1
parameter_list|,
name|ParamType2
parameter_list|,
name|Param2
parameter_list|)
define|\
value|AST_POLYMORPHIC_MATCHER_P2_OVERLOAD(DefineMatcher, ReturnTypesF, ParamType1, \                                       Param1, ParamType2, Param2, 0)
end_define

begin_define
define|#
directive|define
name|AST_POLYMORPHIC_MATCHER_P2_OVERLOAD
parameter_list|(
name|DefineMatcher
parameter_list|,
name|ReturnTypesF
parameter_list|,       \
name|ParamType1
parameter_list|,
name|Param1
parameter_list|,
name|ParamType2
parameter_list|,    \
name|Param2
parameter_list|,
name|OverloadId
parameter_list|)
define|\
value|namespace internal {                                                         \   template<typename NodeType, typename ParamT1, typename ParamT2>             \   class matcher_##DefineMatcher##OverloadId##Matcher                           \       : public MatcherInterface<NodeType> {                                    \   public:                                                                      \     matcher_##DefineMatcher##OverloadId##Matcher(const ParamType1&A##Param1,  \                                                  const ParamType2&A##Param2)  \         : Param1(A##Param1), Param2(A##Param2) {}                              \     virtual bool matches(const NodeType&Node, ASTMatchFinder *Finder,         \                          BoundNodesTreeBuilder *Builder) const;                \                                                                                \   private:                                                                     \     const ParamType1 Param1;                                                   \     const ParamType2 Param2;                                                   \   };                                                                           \   }                                                                            \   inline internal::PolymorphicMatcherWithParam2<                               \       internal::matcher_##DefineMatcher##OverloadId##Matcher, ParamType1,      \       ParamType2, ReturnTypesF> DefineMatcher(const ParamType1&Param1,        \                                               const ParamType2&Param2) {      \     return internal::PolymorphicMatcherWithParam2<                             \         internal::matcher_##DefineMatcher##OverloadId##Matcher, ParamType1,    \         ParamType2, ReturnTypesF>(Param1, Param2);                             \   }                                                                            \   typedef internal::PolymorphicMatcherWithParam2<                              \       internal::matcher_##DefineMatcher##OverloadId##Matcher, ParamType1,      \       ParamType2, ReturnTypesF>(&DefineMatcher##_Type##OverloadId)(            \       const ParamType1&Param1, const ParamType2&Param2);                     \   template<typename NodeType, typename ParamT1, typename ParamT2>             \   bool internal::matcher_##DefineMatcher##OverloadId##Matcher<                 \       NodeType, ParamT1, ParamT2>::matches(                                    \       const NodeType&Node, ASTMatchFinder *Finder,                            \       BoundNodesTreeBuilder *Builder) const
end_define

begin_comment
comment|/// \brief Creates a variadic matcher for both a specific \c Type as well as
end_comment

begin_comment
comment|/// the corresponding \c TypeLoc.
end_comment

begin_define
define|#
directive|define
name|AST_TYPE_MATCHER
parameter_list|(
name|NodeType
parameter_list|,
name|MatcherName
parameter_list|)
define|\
value|const internal::VariadicDynCastAllOfMatcher<Type, NodeType> MatcherName
end_define

begin_comment
comment|// FIXME: add a matcher for TypeLoc derived classes using its custom casting
end_comment

begin_comment
comment|// API (no longer dyn_cast) if/when we need such matching
end_comment

begin_comment
comment|/// \brief AST_TYPE_TRAVERSE_MATCHER(MatcherName, FunctionName) defines
end_comment

begin_comment
comment|/// the matcher \c MatcherName that can be used to traverse from one \c Type
end_comment

begin_comment
comment|/// to another.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For a specific \c SpecificType, the traversal is done using
end_comment

begin_comment
comment|/// \c SpecificType::FunctionName. The existence of such a function determines
end_comment

begin_comment
comment|/// whether a corresponding matcher can be used on \c SpecificType.
end_comment

begin_define
define|#
directive|define
name|AST_TYPE_TRAVERSE_MATCHER
parameter_list|(
name|MatcherName
parameter_list|,
name|FunctionName
parameter_list|,
name|ReturnTypesF
parameter_list|)
define|\
value|namespace internal {                                                         \   template<typename T> struct TypeMatcher##MatcherName##Getter {              \     static QualType (T::*value())() const { return&T::FunctionName; }         \   };                                                                           \   }                                                                            \   const internal::TypeTraversePolymorphicMatcher<                              \       QualType, internal::TypeMatcher##MatcherName##Getter,                    \       internal::TypeTraverseMatcher, ReturnTypesF>::Func MatcherName
end_define

begin_comment
comment|/// \brief AST_TYPELOC_TRAVERSE_MATCHER(MatcherName, FunctionName) works
end_comment

begin_comment
comment|/// identical to \c AST_TYPE_TRAVERSE_MATCHER but operates on \c TypeLocs.
end_comment

begin_define
define|#
directive|define
name|AST_TYPELOC_TRAVERSE_MATCHER
parameter_list|(
name|MatcherName
parameter_list|,
name|FunctionName
parameter_list|,
name|ReturnTypesF
parameter_list|)
define|\
value|namespace internal {                                                         \   template<typename T> struct TypeLocMatcher##MatcherName##Getter {           \     static TypeLoc (T::*value())() const { return&T::FunctionName##Loc; }     \   };                                                                           \   }                                                                            \   const internal::TypeTraversePolymorphicMatcher<                              \       TypeLoc, internal::TypeLocMatcher##MatcherName##Getter,                  \       internal::TypeLocTraverseMatcher, ReturnTypesF>::Func MatcherName##Loc;  \   AST_TYPE_TRAVERSE_MATCHER(MatcherName, FunctionName##Type, ReturnTypesF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_MATCHERS_AST_MATCHERS_MACROS_H
end_comment

end_unit

