begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/type_traits.h - Simplfied type traits -------*- C++ -*-===//
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
comment|// This file provides useful additions to the standard type_traits library.
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
name|LLVM_SUPPORT_TYPE_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TYPE_TRAITS_H
end_define

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEFINED_HAS_FEATURE
end_define

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// isPodLike - This is a type trait that is used to determine whether a given
comment|/// type can be copied around with memcpy instead of running ctors etc.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
block|{
if|#
directive|if
name|__has_feature
argument_list|(
name|is_trivially_copyable
argument_list|)
comment|// If the compiler supports the is_trivially_copyable trait use it, as it
comment|// matches the definition of isPodLike closely.
specifier|static
specifier|const
name|bool
name|value
operator|=
name|__is_trivially_copyable
argument_list|(
name|T
argument_list|)
block|;
else|#
directive|else
comment|// If we don't know anything else, we can (at least) assume that all non-class
comment|// types are PODs.
specifier|static
specifier|const
name|bool
name|value
operator|=
operator|!
name|std
operator|::
name|is_class
operator|<
name|T
operator|>
operator|::
name|value
block|;
endif|#
directive|endif
block|}
expr_stmt|;
comment|// std::pair's are pod-like if their elements are.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
expr|struct
name|isPodLike
operator|<
name|std
operator|::
name|pair
operator|<
name|T
operator|,
name|U
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|isPodLike
operator|<
name|T
operator|>
operator|::
name|value
operator|&&
name|isPodLike
operator|<
name|U
operator|>
operator|::
name|value
block|; }
expr_stmt|;
comment|/// \brief Metafunction that determines whether the given type is either an
comment|/// integral type or an enumeration type.
comment|///
comment|/// Note that this accepts potentially more integral types than is_integral
comment|/// because it is based on merely being convertible implicitly to an integral
comment|/// type.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|is_integral_or_enum
block|{
typedef|typedef
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
name|UnderlyingT
expr_stmt|;
name|public
operator|:
specifier|static
specifier|const
name|bool
name|value
operator|=
operator|!
name|std
operator|::
name|is_class
operator|<
name|UnderlyingT
operator|>
operator|::
name|value
operator|&&
comment|// Filter conversion operators.
operator|!
name|std
operator|::
name|is_pointer
operator|<
name|UnderlyingT
operator|>
operator|::
name|value
operator|&&
operator|!
name|std
operator|::
name|is_floating_point
operator|<
name|UnderlyingT
operator|>
operator|::
name|value
operator|&&
name|std
operator|::
name|is_convertible
operator|<
name|UnderlyingT
operator|,
name|unsigned
name|long
name|long
operator|>
operator|::
name|value
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief If T is a pointer, just return it. If it is not, return T&.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Enable
operator|=
name|void
operator|>
expr|struct
name|add_lvalue_reference_if_not_pointer
block|{
typedef|typedef
name|T
modifier|&
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|add_lvalue_reference_if_not_pointer
operator|<
name|T
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_pointer
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
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
comment|/// \brief If T is a pointer to X, return a pointer to const X. If it is not,
end_comment

begin_comment
comment|/// return const T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Enable
operator|=
name|void
operator|>
expr|struct
name|add_const_past_pointer
block|{
typedef|typedef
specifier|const
name|T
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|add_const_past_pointer
operator|<
name|T
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_pointer
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
block|{
typedef|typedef
specifier|const
name|typename
name|std
operator|::
name|remove_pointer
operator|<
name|T
operator|>
operator|::
name|type
operator|*
name|type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|LLVM_DEFINED_HAS_FEATURE
end_ifdef

begin_undef
undef|#
directive|undef
name|__has_feature
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

