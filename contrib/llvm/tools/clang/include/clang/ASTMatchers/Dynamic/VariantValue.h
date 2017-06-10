begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- VariantValue.h - Polymorphic value type -*- C++ -*-===/
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
comment|/// \brief Polymorphic value type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Supports all the types required for dynamic Matcher construction.
end_comment

begin_comment
comment|///  Used by the registry to construct matchers in a generic way.
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
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_VARIANTVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_VARIANTVALUE_H
end_define

begin_include
include|#
directive|include
file|"clang/ASTMatchers/ASTMatchers.h"
end_include

begin_include
include|#
directive|include
file|"clang/ASTMatchers/ASTMatchersInternal.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|namespace
name|dynamic
block|{
comment|/// \brief Kind identifier.
comment|///
comment|/// It supports all types that VariantValue can contain.
name|class
name|ArgKind
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|AK_Matcher
block|,
name|AK_Boolean
block|,
name|AK_Double
block|,
name|AK_Unsigned
block|,
name|AK_String
block|}
enum|;
comment|/// \brief Constructor for non-matcher types.
name|ArgKind
argument_list|(
argument|Kind K
argument_list|)
block|:
name|K
argument_list|(
argument|K
argument_list|)
block|{
name|assert
argument_list|(
name|K
operator|!=
name|AK_Matcher
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Constructor for matcher types.
name|ArgKind
argument_list|(
argument|ast_type_traits::ASTNodeKind MatcherKind
argument_list|)
block|:
name|K
argument_list|(
name|AK_Matcher
argument_list|)
operator|,
name|MatcherKind
argument_list|(
argument|MatcherKind
argument_list|)
block|{}
name|Kind
name|getArgKind
argument_list|()
specifier|const
block|{
return|return
name|K
return|;
block|}
name|ast_type_traits
operator|::
name|ASTNodeKind
name|getMatcherKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|K
operator|==
name|AK_Matcher
argument_list|)
block|;
return|return
name|MatcherKind
return|;
block|}
comment|/// \brief Determines if this type can be converted to \p To.
comment|///
comment|/// \param To the requested destination type.
comment|///
comment|/// \param Specificity value corresponding to the "specificity" of the
comment|///   conversion.
name|bool
name|isConvertibleTo
argument_list|(
name|ArgKind
name|To
argument_list|,
name|unsigned
operator|*
name|Specificity
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ArgKind
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|K
operator|==
name|AK_Matcher
operator|&&
name|Other
operator|.
name|K
operator|==
name|AK_Matcher
condition|)
return|return
name|MatcherKind
operator|<
name|Other
operator|.
name|MatcherKind
return|;
return|return
name|K
operator|<
name|Other
operator|.
name|K
return|;
block|}
comment|/// \brief String representation of the type.
name|std
operator|::
name|string
name|asString
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Kind
name|K
decl_stmt|;
name|ast_type_traits
operator|::
name|ASTNodeKind
name|MatcherKind
expr_stmt|;
block|}
empty_stmt|;
name|using
name|ast_matchers
operator|::
name|internal
operator|::
name|DynTypedMatcher
expr_stmt|;
comment|/// \brief A variant matcher object.
comment|///
comment|/// The purpose of this object is to abstract simple and polymorphic matchers
comment|/// into a single object type.
comment|/// Polymorphic matchers might be implemented as a list of all the possible
comment|/// overloads of the matcher. \c VariantMatcher knows how to select the
comment|/// appropriate overload when needed.
comment|/// To get a real matcher object out of a \c VariantMatcher you can do:
comment|///  - getSingleMatcher() which returns a matcher, only if it is not ambiguous
comment|///    to decide which matcher to return. Eg. it contains only a single
comment|///    matcher, or a polymorphic one with only one overload.
comment|///  - hasTypedMatcher<T>()/getTypedMatcher<T>(): These calls will determine if
comment|///    the underlying matcher(s) can unambiguously return a Matcher<T>.
name|class
name|VariantMatcher
block|{
comment|/// \brief Methods that depend on T from hasTypedMatcher/getTypedMatcher.
name|class
name|MatcherOps
block|{
name|public
label|:
name|MatcherOps
argument_list|(
argument|ast_type_traits::ASTNodeKind NodeKind
argument_list|)
block|:
name|NodeKind
argument_list|(
argument|NodeKind
argument_list|)
block|{}
name|bool
name|canConstructFrom
argument_list|(
specifier|const
name|DynTypedMatcher
operator|&
name|Matcher
argument_list|,
name|bool
operator|&
name|IsExactMatch
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Convert \p Matcher the destination type and return it as a new
comment|/// DynTypedMatcher.
name|virtual
name|DynTypedMatcher
name|convertMatcher
argument_list|(
specifier|const
name|DynTypedMatcher
operator|&
name|Matcher
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// \brief Constructs a variadic typed matcher from \p InnerMatchers.
comment|/// Will try to convert each inner matcher to the destination type and
comment|/// return llvm::None if it fails to do so.
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|constructVariadicOperator
argument_list|(
argument|DynTypedMatcher::VariadicOperator Op
argument_list|,
argument|ArrayRef<VariantMatcher> InnerMatchers
argument_list|)
specifier|const
expr_stmt|;
name|protected
label|:
operator|~
name|MatcherOps
argument_list|()
operator|=
expr|default
expr_stmt|;
name|private
label|:
name|ast_type_traits
operator|::
name|ASTNodeKind
name|NodeKind
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Payload interface to be specialized by each matcher type.
comment|///
comment|/// It follows a similar interface as VariantMatcher itself.
name|class
name|Payload
block|{
name|public
label|:
name|virtual
operator|~
name|Payload
argument_list|()
expr_stmt|;
name|virtual
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|getSingleMatcher
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|getTypeAsString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|getTypedMatcher
argument_list|(
argument|const MatcherOps&Ops
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|isConvertibleTo
argument_list|(
name|ast_type_traits
operator|::
name|ASTNodeKind
name|Kind
argument_list|,
name|unsigned
operator|*
name|Specificity
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|public
label|:
comment|/// \brief A null matcher.
name|VariantMatcher
argument_list|()
expr_stmt|;
comment|/// \brief Clones the provided matcher.
specifier|static
name|VariantMatcher
name|SingleMatcher
parameter_list|(
specifier|const
name|DynTypedMatcher
modifier|&
name|Matcher
parameter_list|)
function_decl|;
comment|/// \brief Clones the provided matchers.
comment|///
comment|/// They should be the result of a polymorphic matcher.
specifier|static
name|VariantMatcher
name|PolymorphicMatcher
argument_list|(
name|std
operator|::
name|vector
operator|<
name|DynTypedMatcher
operator|>
name|Matchers
argument_list|)
decl_stmt|;
comment|/// \brief Creates a 'variadic' operator matcher.
comment|///
comment|/// It will bind to the appropriate type on getTypedMatcher<T>().
specifier|static
name|VariantMatcher
name|VariadicOperatorMatcher
argument_list|(
name|DynTypedMatcher
operator|::
name|VariadicOperator
name|Op
argument_list|,
name|std
operator|::
name|vector
operator|<
name|VariantMatcher
operator|>
name|Args
argument_list|)
decl_stmt|;
comment|/// \brief Makes the matcher the "null" matcher.
name|void
name|reset
parameter_list|()
function_decl|;
comment|/// \brief Whether the matcher is null.
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Value
return|;
block|}
comment|/// \brief Return a single matcher, if there is no ambiguity.
comment|///
comment|/// \returns the matcher, if there is only one matcher. An empty Optional, if
comment|/// the underlying matcher is a polymorphic matcher with more than one
comment|/// representation.
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|getSingleMatcher
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines if the contained matcher can be converted to
comment|///   \c Matcher<T>.
comment|///
comment|/// For the Single case, it returns true if it can be converted to
comment|/// \c Matcher<T>.
comment|/// For the Polymorphic case, it returns true if one, and only one, of the
comment|/// overloads can be converted to \c Matcher<T>. If there are more than one
comment|/// that can, the result would be ambiguous and false is returned.
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|hasTypedMatcher
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|Value
condition|)
return|return
name|false
return|;
return|return
name|Value
operator|->
name|getTypedMatcher
argument_list|(
name|TypedMatcherOps
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
operator|.
name|hasValue
argument_list|()
return|;
block|}
comment|/// \brief Determines if the contained matcher can be converted to \p Kind.
comment|///
comment|/// \param Kind the requested destination type.
comment|///
comment|/// \param Specificity value corresponding to the "specificity" of the
comment|///   conversion.
name|bool
name|isConvertibleTo
argument_list|(
name|ast_type_traits
operator|::
name|ASTNodeKind
name|Kind
argument_list|,
name|unsigned
operator|*
name|Specificity
argument_list|)
decl|const
block|{
if|if
condition|(
name|Value
condition|)
return|return
name|Value
operator|->
name|isConvertibleTo
argument_list|(
name|Kind
argument_list|,
name|Specificity
argument_list|)
return|;
return|return
name|false
return|;
block|}
comment|/// \brief Return this matcher as a \c Matcher<T>.
comment|///
comment|/// Handles the different types (Single, Polymorphic) accordingly.
comment|/// Asserts that \c hasTypedMatcher<T>() is true.
name|template
operator|<
name|class
name|T
operator|>
name|ast_matchers
operator|::
name|internal
operator|::
name|Matcher
operator|<
name|T
operator|>
name|getTypedMatcher
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasTypedMatcher
operator|<
name|T
operator|>
operator|(
operator|)
operator|&&
literal|"hasTypedMatcher<T>() == false"
argument_list|)
block|;
return|return
name|Value
operator|->
name|getTypedMatcher
argument_list|(
name|TypedMatcherOps
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
operator|->
name|template
name|convertTo
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief String representation of the type of the value.
comment|///
comment|/// If the underlying matcher is a polymorphic one, the string will show all
comment|/// the types.
name|std
operator|::
name|string
name|getTypeAsString
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|explicit
name|VariantMatcher
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|Payload
operator|>
name|Value
argument_list|)
range|:
name|Value
argument_list|(
argument|std::move(Value)
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|TypedMatcherOps
decl_stmt|;
name|class
name|SinglePayload
decl_stmt|;
name|class
name|PolymorphicPayload
decl_stmt|;
name|class
name|VariadicOpPayload
decl_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
specifier|const
name|Payload
operator|>
name|Value
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|VariantMatcher
operator|::
name|TypedMatcherOps
name|final
operator|:
name|VariantMatcher
operator|::
name|MatcherOps
block|{
name|TypedMatcherOps
argument_list|()
operator|:
name|MatcherOps
argument_list|(
argument|ast_type_traits::ASTNodeKind::getFromNodeKind<T>()
argument_list|)
block|{}
typedef|typedef
name|ast_matchers
operator|::
name|internal
operator|::
name|Matcher
operator|<
name|T
operator|>
name|MatcherT
expr_stmt|;
name|DynTypedMatcher
name|convertMatcher
argument_list|(
argument|const DynTypedMatcher&Matcher
argument_list|)
specifier|const
name|override
block|{
return|return
name|DynTypedMatcher
argument_list|(
name|Matcher
operator|.
name|convertTo
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Variant value class.
comment|///
comment|/// Basically, a tagged union with value type semantics.
comment|/// It is used by the registry as the return value and argument type for the
comment|/// matcher factory methods.
comment|/// It can be constructed from any of the supported types. It supports
comment|/// copy/assignment.
comment|///
comment|/// Supported types:
comment|///  - \c bool
comment|//   - \c double
comment|///  - \c unsigned
comment|///  - \c llvm::StringRef
comment|///  - \c VariantMatcher (\c DynTypedMatcher / \c Matcher<T>)
name|class
name|VariantValue
block|{
name|public
label|:
name|VariantValue
argument_list|()
operator|:
name|Type
argument_list|(
argument|VT_Nothing
argument_list|)
block|{}
name|VariantValue
argument_list|(
specifier|const
name|VariantValue
operator|&
name|Other
argument_list|)
expr_stmt|;
operator|~
name|VariantValue
argument_list|()
expr_stmt|;
name|VariantValue
modifier|&
name|operator
init|=
operator|(
specifier|const
name|VariantValue
operator|&
name|Other
operator|)
decl_stmt|;
comment|/// \brief Specific constructors for each supported type.
name|VariantValue
argument_list|(
argument|bool Boolean
argument_list|)
empty_stmt|;
name|VariantValue
argument_list|(
argument|double Double
argument_list|)
empty_stmt|;
name|VariantValue
argument_list|(
argument|unsigned Unsigned
argument_list|)
empty_stmt|;
name|VariantValue
argument_list|(
argument|StringRef String
argument_list|)
empty_stmt|;
name|VariantValue
argument_list|(
specifier|const
name|VariantMatcher
operator|&
name|Matchers
argument_list|)
expr_stmt|;
comment|/// \brief Constructs an \c unsigned value (disambiguation from bool).
name|VariantValue
argument_list|(
argument|int Signed
argument_list|)
block|:
name|VariantValue
argument_list|(
argument|static_cast<unsigned>(Signed)
argument_list|)
block|{}
comment|/// \brief Returns true iff this is not an empty value.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|hasValue
argument_list|()
return|;
block|}
name|bool
name|hasValue
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|!=
name|VT_Nothing
return|;
block|}
comment|/// \brief Boolean value functions.
name|bool
name|isBoolean
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|getBoolean
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBoolean
parameter_list|(
name|bool
name|Boolean
parameter_list|)
function_decl|;
comment|/// \brief Double value functions.
name|bool
name|isDouble
argument_list|()
specifier|const
expr_stmt|;
name|double
name|getDouble
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDouble
parameter_list|(
name|double
name|Double
parameter_list|)
function_decl|;
comment|/// \brief Unsigned value functions.
name|bool
name|isUnsigned
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getUnsigned
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUnsigned
parameter_list|(
name|unsigned
name|Unsigned
parameter_list|)
function_decl|;
comment|/// \brief String value functions.
name|bool
name|isString
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getString
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setString
parameter_list|(
name|StringRef
name|String
parameter_list|)
function_decl|;
comment|/// \brief Matcher value functions.
name|bool
name|isMatcher
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|VariantMatcher
operator|&
name|getMatcher
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMatcher
parameter_list|(
specifier|const
name|VariantMatcher
modifier|&
name|Matcher
parameter_list|)
function_decl|;
comment|/// \brief Determines if the contained value can be converted to \p Kind.
comment|///
comment|/// \param Kind the requested destination type.
comment|///
comment|/// \param Specificity value corresponding to the "specificity" of the
comment|///   conversion.
name|bool
name|isConvertibleTo
argument_list|(
name|ArgKind
name|Kind
argument_list|,
name|unsigned
operator|*
name|Specificity
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Determines if the contained value can be converted to any kind
comment|/// in \p Kinds.
comment|///
comment|/// \param Kinds the requested destination types.
comment|///
comment|/// \param Specificity value corresponding to the "specificity" of the
comment|///   conversion. It is the maximum specificity of all the possible
comment|///   conversions.
name|bool
name|isConvertibleTo
argument_list|(
name|ArrayRef
operator|<
name|ArgKind
operator|>
name|Kinds
argument_list|,
name|unsigned
operator|*
name|Specificity
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief String representation of the type of the value.
name|std
operator|::
name|string
name|getTypeAsString
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|reset
parameter_list|()
function_decl|;
comment|/// \brief All supported value types.
enum|enum
name|ValueType
block|{
name|VT_Nothing
block|,
name|VT_Boolean
block|,
name|VT_Double
block|,
name|VT_Unsigned
block|,
name|VT_String
block|,
name|VT_Matcher
block|}
enum|;
comment|/// \brief All supported value types.
union|union
name|AllValues
block|{
name|unsigned
name|Unsigned
decl_stmt|;
name|double
name|Double
decl_stmt|;
name|bool
name|Boolean
decl_stmt|;
name|std
operator|::
name|string
operator|*
name|String
expr_stmt|;
name|VariantMatcher
modifier|*
name|Matcher
decl_stmt|;
block|}
union|;
name|ValueType
name|Type
decl_stmt|;
name|AllValues
name|Value
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace dynamic
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
comment|// LLVM_CLANG_AST_MATCHERS_DYNAMIC_VARIANT_VALUE_H
end_comment

end_unit

