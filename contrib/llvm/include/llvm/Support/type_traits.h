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
file|"llvm/Support/Compiler.h"
end_include

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
comment|// std::is_trivially_copyable is available in libc++ with clang, libstdc++
comment|// that comes with GCC 5.
if|#
directive|if
operator|(
name|__has_feature
argument_list|(
name|is_trivially_copyable
argument_list|)
operator|&&
name|defined
argument_list|(
name|_LIBCPP_VERSION
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|5
operator|)
comment|// If the compiler supports the is_trivially_copyable trait use it, as it
comment|// matches the definition of isPodLike closely.
specifier|static
specifier|const
name|bool
name|value
operator|=
name|std
operator|::
name|is_trivially_copyable
operator|<
name|T
operator|>
operator|::
name|value
block|;
elif|#
directive|elif
name|__has_feature
argument_list|(
name|is_trivially_copyable
argument_list|)
comment|// Use the internal name if the compiler supports is_trivially_copyable but we
comment|// don't know if the standard library does. This is the case for clang in
comment|// conjunction with libstdc++ from GCC 4.x.
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
operator|>>
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
comment|/// integral type or an enumeration type, including enum classes.
comment|///
comment|/// Note that this accepts potentially more integral types than is_integral
comment|/// because it is based on being implicitly convertible to an integral type.
comment|/// Also note that enum classes aren't implicitly convertible to integral types,
comment|/// the value may therefore need to be explicitly converted before being used.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|is_integral_or_enum
block|{
name|using
name|UnderlyingT
operator|=
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
block|;
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
operator|(
name|std
operator|::
name|is_enum
operator|<
name|UnderlyingT
operator|>
operator|::
name|value
operator|||
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
operator|)
block|; }
expr_stmt|;
comment|/// \brief If T is a pointer, just return it. If it is not, return T&.
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
name|using
name|type
operator|=
name|T
operator|&
block|; }
expr_stmt|;
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
name|using
name|type
operator|=
name|T
block|; }
expr_stmt|;
comment|/// \brief If T is a pointer to X, return a pointer to const X. If it is not,
comment|/// return const T.
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
name|using
name|type
operator|=
specifier|const
name|T
block|; }
expr_stmt|;
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
name|using
name|type
operator|=
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
block|; }
expr_stmt|;
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
name|const_pointer_or_const_ref
block|{
name|using
name|type
operator|=
specifier|const
name|T
operator|&
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|const_pointer_or_const_ref
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
name|using
name|type
operator|=
name|typename
name|add_const_past_pointer
operator|<
name|T
operator|>
operator|::
name|type
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_comment
comment|// If the compiler supports detecting whether a class is final, define
end_comment

begin_comment
comment|// an LLVM_IS_FINAL macro. If it cannot be defined properly, this
end_comment

begin_comment
comment|// macro will be left undefined.
end_comment

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201402L
end_if

begin_define
define|#
directive|define
name|LLVM_IS_FINAL
parameter_list|(
name|Ty
parameter_list|)
value|std::is_final<Ty>()
end_define

begin_elif
elif|#
directive|elif
name|__has_feature
argument_list|(
name|is_final
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|7
operator|,
literal|0
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_IS_FINAL
parameter_list|(
name|Ty
parameter_list|)
value|__is_final(Ty)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
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

begin_comment
comment|// LLVM_SUPPORT_TYPE_TRAITS_H
end_comment

end_unit

