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
name|LLVM_CLANG_AST_MATCHERS_DYNAMIC_VARIANT_VALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_MATCHERS_DYNAMIC_VARIANT_VALUE_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

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
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
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
name|virtual
operator|~
name|MatcherOps
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|canConstructFrom
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
name|virtual
name|void
name|constructFrom
parameter_list|(
specifier|const
name|DynTypedMatcher
modifier|&
name|Matcher
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|constructVariadicOperator
argument_list|(
name|ast_matchers
operator|::
name|internal
operator|::
name|VariadicOperatorFunction
name|Func
argument_list|,
name|ArrayRef
operator|<
name|VariantMatcher
operator|>
name|InnerMatchers
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Payload interface to be specialized by each matcher type.
comment|///
comment|/// It follows a similar interface as VariantMatcher itself.
name|class
name|Payload
range|:
name|public
name|RefCountedBaseVPTR
block|{
name|public
operator|:
name|virtual
operator|~
name|Payload
argument_list|()
block|;
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
block|;
name|virtual
name|std
operator|::
name|string
name|getTypeAsString
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|makeTypedMatcher
argument_list|(
argument|MatcherOps&Ops
argument_list|)
specifier|const
operator|=
literal|0
block|;   }
decl_stmt|;
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
name|ArrayRef
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
name|ast_matchers
operator|::
name|internal
operator|::
name|VariadicOperatorFunction
name|Func
argument_list|,
name|ArrayRef
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
name|TypedMatcherOps
operator|<
name|T
operator|>
name|Ops
block|;
if|if
condition|(
name|Value
condition|)
name|Value
operator|->
name|makeTypedMatcher
argument_list|(
name|Ops
argument_list|)
expr_stmt|;
return|return
name|Ops
operator|.
name|hasMatcher
argument_list|()
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
name|TypedMatcherOps
operator|<
name|T
operator|>
name|Ops
block|;
name|Value
operator|->
name|makeTypedMatcher
argument_list|(
name|Ops
argument_list|)
block|;
name|assert
argument_list|(
name|Ops
operator|.
name|hasMatcher
argument_list|()
operator|&&
literal|"hasTypedMatcher<T>() == false"
argument_list|)
block|;
return|return
name|Ops
operator|.
name|matcher
argument_list|()
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
name|Payload
operator|*
name|Value
argument_list|)
operator|:
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
name|class
name|SinglePayload
expr_stmt|;
name|class
name|PolymorphicPayload
decl_stmt|;
name|class
name|VariadicOpPayload
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypedMatcherOps
operator|:
name|public
name|MatcherOps
block|{
name|public
operator|:
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
name|virtual
name|bool
name|canConstructFrom
argument_list|(
argument|const DynTypedMatcher&Matcher
argument_list|)
specifier|const
block|{
return|return
name|Matcher
operator|.
name|canConvertTo
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
name|virtual
name|void
name|constructFrom
argument_list|(
argument|const DynTypedMatcher& Matcher
argument_list|)
block|{
name|Out
operator|.
name|reset
argument_list|(
argument|new MatcherT(Matcher.convertTo<T>())
argument_list|)
block|;     }
name|virtual
name|void
name|constructVariadicOperator
argument_list|(
argument|ast_matchers::internal::VariadicOperatorFunction Func
argument_list|,
argument|ArrayRef<VariantMatcher> InnerMatchers
argument_list|)
block|{
specifier|const
name|size_t
name|NumArgs
operator|=
name|InnerMatchers
operator|.
name|size
argument_list|()
block|;
name|MatcherT
operator|*
operator|*
name|InnerArgs
operator|=
name|new
name|MatcherT
operator|*
index|[
name|NumArgs
index|]
operator|(
operator|)
block|;
name|bool
name|HasError
operator|=
name|false
block|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|NumArgs
condition|;
operator|++
name|i
control|)
block|{
comment|// Abort if any of the inner matchers can't be converted to
comment|// Matcher<T>.
if|if
condition|(
operator|!
name|InnerMatchers
index|[
name|i
index|]
operator|.
name|hasTypedMatcher
operator|<
name|T
operator|>
operator|(
operator|)
condition|)
block|{
name|HasError
operator|=
name|true
expr_stmt|;
break|break;
block|}
name|InnerArgs
index|[
name|i
index|]
operator|=
name|new
name|MatcherT
argument_list|(
name|InnerMatchers
index|[
name|i
index|]
operator|.
name|getTypedMatcher
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|HasError
condition|)
block|{
name|Out
operator|.
name|reset
argument_list|(
argument|new MatcherT(             new ast_matchers::internal::VariadicOperatorMatcherInterface<T>(                 Func, ArrayRef<const MatcherT *>(InnerArgs, NumArgs)))
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|NumArgs
condition|;
operator|++
name|i
control|)
block|{
name|delete
name|InnerArgs
index|[
name|i
index|]
decl_stmt|;
block|}
name|delete
index|[]
name|InnerArgs
decl_stmt|;
block|}
name|bool
name|hasMatcher
argument_list|()
specifier|const
block|{
return|return
name|Out
operator|.
name|get
argument_list|()
operator|!=
name|NULL
return|;
block|}
specifier|const
name|MatcherT
operator|&
name|matcher
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Out
return|;
block|}
name|private
label|:
name|OwningPtr
operator|<
name|MatcherT
operator|>
name|Out
expr_stmt|;
block|}
empty_stmt|;
name|IntrusiveRefCntPtr
operator|<
specifier|const
name|Payload
operator|>
name|Value
expr_stmt|;
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
comment|///  - \c unsigned
comment|///  - \c std::string
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
argument|unsigned Unsigned
argument_list|)
empty_stmt|;
name|VariantValue
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
expr_stmt|;
name|VariantValue
argument_list|(
specifier|const
name|VariantMatcher
operator|&
name|Matchers
argument_list|)
expr_stmt|;
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
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
decl_stmt|;
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

