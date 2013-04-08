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
comment|// This file provides a template class that determines if a type is a class or
end_comment

begin_comment
comment|// not. The basic mechanism, based on using the pointer to member function of
end_comment

begin_comment
comment|// a zero argument to a function was "boosted" from the boost type_traits
end_comment

begin_comment
comment|// library. See http://www.boost.org/ for all the gory details.
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
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
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

begin_comment
comment|// This is actually the conforming implementation which works with abstract
end_comment

begin_comment
comment|// classes.  However, enough compilers have trouble with it that most will use
end_comment

begin_comment
comment|// the one in boost/type_traits/object_traits.hpp. This implementation actually
end_comment

begin_comment
comment|// works with VC7.0, but other interactions seem to fail when we use it.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|dont_use
block|{
comment|// These two functions should never be used. They are helpers to
comment|// the is_class template below. They cannot be located inside
comment|// is_class because doing so causes at least GCC to think that
comment|// the value of the "value" enumerator is not constant. Placing
comment|// them out here (for some strange reason) allows the sizeof
comment|// operator against them to magically be constant. This is
comment|// important to make the is_class<T>::value idiom zero cost. it
comment|// evaluates to a constant 1 or 0 depending on whether the
comment|// parameter T is a class or not (respectively).
name|template
operator|<
name|typename
name|T
operator|>
name|char
name|is_class_helper
argument_list|(
name|void
argument_list|(
name|T
operator|::
operator|*
argument_list|)
argument_list|()
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|double
name|is_class_helper
argument_list|(
operator|...
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_class
block|{
comment|// is_class<> metafunction due to Paul Mensonides (leavings@attbi.com). For
comment|// more details:
comment|// http://groups.google.com/groups?hl=en&selm=000001c1cc83%24e154d5e0%247772e50c%40c161550a&rnum=1
name|public
operator|:
specifier|static
specifier|const
name|bool
name|value
operator|=
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|dont_use
operator|::
name|is_class_helper
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
argument_list|)
block|; }
expr_stmt|;
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
name|template
operator|<
name|class
name|T
operator|,
name|T
name|v
operator|>
expr|struct
name|integral_constant
block|{
typedef|typedef
name|T
name|value_type
typedef|;
specifier|static
specifier|const
name|value_type
name|value
operator|=
name|v
expr_stmt|;
typedef|typedef
name|integral_constant
operator|<
name|T
operator|,
name|v
operator|>
name|type
expr_stmt|;
name|operator
name|value_type
parameter_list|()
block|{
return|return
name|value
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|integral_constant
operator|<
name|bool
operator|,
name|true
operator|>
name|true_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|integral_constant
operator|<
name|bool
operator|,
name|false
operator|>
name|false_type
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Metafunction that determines whether the two given types are
end_comment

begin_comment
comment|/// equivalent.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
expr|struct
name|is_same
operator|:
name|public
name|false_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_same
operator|<
name|T
operator|,
name|T
operator|>
operator|:
name|public
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Metafunction that removes const qualification from a type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_const
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_const
operator|<
specifier|const
name|T
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
comment|/// \brief Metafunction that removes volatile qualification from a type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_volatile
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_volatile
operator|<
specifier|volatile
name|T
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
comment|/// \brief Metafunction that removes both const and volatile qualification from
end_comment

begin_comment
comment|/// a type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_cv
block|{
typedef|typedef
name|typename
name|remove_const
operator|<
name|typename
name|remove_volatile
operator|<
name|T
operator|>
operator|::
name|type
operator|>
operator|::
name|type
name|type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Helper to implement is_integral metafunction.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_integral_impl
operator|:
name|false_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|bool
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|char
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|signed
name|char
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|unsigned
name|char
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|wchar_t
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|short
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|unsigned
name|short
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|int
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|unsigned
name|int
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|long
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|unsigned
name|long
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|long
name|long
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|is_integral_impl
operator|<
name|unsigned
name|long
name|long
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Metafunction that determines whether the given type is an integral
end_comment

begin_comment
comment|/// type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_integral
operator|:
name|is_integral_impl
operator|<
name|T
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Metafunction to remove reference from a type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_reference
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_reference
operator|<
name|T
operator|&
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
comment|/// \brief Metafunction that determines whether the given type is a pointer
end_comment

begin_comment
comment|/// type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_pointer
operator|:
name|false_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_pointer
operator|<
name|T
operator|*
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_pointer
operator|<
name|T
operator|*
specifier|const
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_pointer
operator|<
name|T
operator|*
specifier|volatile
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_pointer
operator|<
name|T
operator|*
specifier|const
specifier|volatile
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Metafunction that determines wheather the given type is a reference.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_reference
operator|:
name|false_type
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_reference
operator|<
name|T
operator|&
operator|>
operator|:
name|true_type
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Metafunction that determines whether the given type is either an
end_comment

begin_comment
comment|/// integral type or an enumeration type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this accepts potentially more integral types than we whitelist
end_comment

begin_comment
comment|/// above for is_integral because it is based on merely being convertible
end_comment

begin_comment
comment|/// implicitly to an integral type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|is_integral_or_enum
block|{
comment|// Provide an overload which can be called with anything implicitly
comment|// convertible to an unsigned long long. This should catch integer types and
comment|// enumeration types at least. We blacklist classes with conversion operators
comment|// below.
specifier|static
name|double
name|check_int_convertible
argument_list|(
argument|unsigned long long
argument_list|)
block|;
specifier|static
name|char
name|check_int_convertible
argument_list|(
operator|...
argument_list|)
block|;
typedef|typedef
name|typename
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
name|UnderlyingT
expr_stmt|;
specifier|static
name|UnderlyingT
operator|&
name|nonce_instance
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|value
init|=
operator|(
operator|!
name|is_class
operator|<
name|UnderlyingT
operator|>
operator|::
name|value
operator|&&
operator|!
name|is_pointer
operator|<
name|UnderlyingT
operator|>
operator|::
name|value
operator|&&
operator|!
name|is_same
operator|<
name|UnderlyingT
expr|,
name|float
operator|>
operator|::
name|value
operator|&&
operator|!
name|is_same
operator|<
name|UnderlyingT
expr|,
name|double
operator|>
operator|::
name|value
operator|&&
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|check_int_convertible
argument_list|(
name|nonce_instance
argument_list|)
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// enable_if_c - Enable/disable a template based on a metafunction
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|Cond
operator|,
name|typename
name|T
operator|=
name|void
operator|>
expr|struct
name|enable_if_c
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|enable_if_c
operator|<
name|false
operator|,
name|T
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// enable_if - Enable/disable a template based on a metafunction
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Cond
operator|,
name|typename
name|T
operator|=
name|void
operator|>
expr|struct
name|enable_if
operator|:
name|public
name|enable_if_c
operator|<
name|Cond
operator|::
name|value
operator|,
name|T
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|dont_use
block|{
name|template
operator|<
name|typename
name|Base
operator|>
name|char
name|base_of_helper
argument_list|(
specifier|const
specifier|volatile
name|Base
operator|*
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|Base
operator|>
name|double
name|base_of_helper
argument_list|(
operator|...
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// is_base_of - Metafunction to determine whether one type is a base class of
end_comment

begin_comment
comment|/// (or identical to) another type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Base
operator|,
name|typename
name|Derived
operator|>
expr|struct
name|is_base_of
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|is_class
operator|<
name|Base
operator|>
operator|::
name|value
operator|&&
name|is_class
operator|<
name|Derived
operator|>
operator|::
name|value
operator|&&
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|dont_use
operator|::
name|base_of_helper
operator|<
name|Base
operator|>
operator|(
operator|(
name|Derived
operator|*
operator|)
literal|0
operator|)
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// remove_pointer - Metafunction to turn Foo* into Foo.  Defined in
end_comment

begin_comment
comment|// C++0x [meta.trans.ptr].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_pointer
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_pointer
operator|<
name|T
operator|*
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_pointer
operator|<
name|T
operator|*
specifier|const
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_pointer
operator|<
name|T
operator|*
specifier|volatile
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_pointer
operator|<
name|T
operator|*
specifier|const
specifier|volatile
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
comment|// If T is a pointer, just return it. If it is not, return T&.
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
name|enable_if
operator|<
name|is_pointer
operator|<
name|T
operator|>
expr|>
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
comment|// If T is a pointer to X, return a pointer to const X. If it is not, return
end_comment

begin_comment
comment|// const T.
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
name|enable_if
operator|<
name|is_pointer
operator|<
name|T
operator|>
expr|>
operator|::
name|type
operator|>
block|{
typedef|typedef
specifier|const
name|typename
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

begin_expr_stmt
name|template
operator|<
name|bool
operator|,
name|typename
name|T
operator|,
name|typename
name|F
operator|>
expr|struct
name|conditional
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|F
operator|>
expr|struct
name|conditional
operator|<
name|false
operator|,
name|T
operator|,
name|F
operator|>
block|{
typedef|typedef
name|F
name|type
typedef|;
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

