begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/BitmaskEnum.h ----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_BITMASKENUM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_BITMASKENUM_H
end_define

begin_include
include|#
directive|include
file|<cassert>
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

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_comment
comment|/// LLVM_MARK_AS_BITMASK_ENUM lets you opt in an individual enum type so you can
end_comment

begin_comment
comment|/// perform bitwise operations on it without putting static_cast everywhere.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   enum MyEnum {
end_comment

begin_comment
comment|///     E1 = 1, E2 = 2, E3 = 4, E4 = 8,
end_comment

begin_comment
comment|///     LLVM_MARK_AS_BITMASK_ENUM(/* LargestValue = */ E4)
end_comment

begin_comment
comment|///   };
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   void Foo() {
end_comment

begin_comment
comment|///     MyEnum A = (E1 | E2)& E3 ^ ~E4; // Look, ma: No static_cast!
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Normally when you do a bitwise operation on an enum value, you get back an
end_comment

begin_comment
comment|/// instance of the underlying type (e.g. int).  But using this macro, bitwise
end_comment

begin_comment
comment|/// ops on your enum will return you back instances of the enum.  This is
end_comment

begin_comment
comment|/// particularly useful for enums which represent a combination of flags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The parameter to LLVM_MARK_AS_BITMASK_ENUM should be the largest individual
end_comment

begin_comment
comment|/// value in your enum.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// All of the enum's values must be non-negative.
end_comment

begin_define
define|#
directive|define
name|LLVM_MARK_AS_BITMASK_ENUM
parameter_list|(
name|LargestValue
parameter_list|)
define|\
value|LLVM_BITMASK_LARGEST_ENUMERATOR = LargestValue
end_define

begin_comment
comment|/// LLVM_ENABLE_BITMASK_ENUMS_IN_NAMESPACE() pulls the operator overloads used
end_comment

begin_comment
comment|/// by LLVM_MARK_AS_BITMASK_ENUM into the current namespace.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Suppose you have an enum foo::bar::MyEnum.  Before using
end_comment

begin_comment
comment|/// LLVM_MARK_AS_BITMASK_ENUM on MyEnum, you must put
end_comment

begin_comment
comment|/// LLVM_ENABLE_BITMASK_ENUMS_IN_NAMESPACE() somewhere inside namespace foo or
end_comment

begin_comment
comment|/// namespace foo::bar.  This allows the relevant operator overloads to be found
end_comment

begin_comment
comment|/// by ADL.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// You don't need to use this macro in namespace llvm; it's done at the bottom
end_comment

begin_comment
comment|/// of this file.
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_BITMASK_ENUMS_IN_NAMESPACE
parameter_list|()
define|\
value|using ::llvm::BitmaskEnumDetail::operator~;                                  \   using ::llvm::BitmaskEnumDetail::operator|;                                  \   using ::llvm::BitmaskEnumDetail::operator&;                                  \   using ::llvm::BitmaskEnumDetail::operator^;                                  \   using ::llvm::BitmaskEnumDetail::operator|=;                                 \   using ::llvm::BitmaskEnumDetail::operator&=;                                 \
comment|/* Force a semicolon at the end of this macro. */
value|\   using ::llvm::BitmaskEnumDetail::operator^=
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Traits class to determine whether an enum has a
comment|/// LLVM_BITMASK_LARGEST_ENUMERATOR enumerator.
name|template
operator|<
name|typename
name|E
operator|,
name|typename
name|Enable
operator|=
name|void
operator|>
expr|struct
name|is_bitmask_enum
operator|:
name|std
operator|::
name|false_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|E
operator|>
expr|struct
name|is_bitmask_enum
operator|<
name|E
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
sizeof|sizeof
argument_list|(
name|E
operator|::
name|LLVM_BITMASK_LARGEST_ENUMERATOR
argument_list|)
operator|>=
literal|0
operator|>
operator|::
name|type
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
name|namespace
name|BitmaskEnumDetail
block|{
comment|/// Get a bitmask with 1s in all places up to the high-order bit of E's largest
comment|/// value.
name|template
operator|<
name|typename
name|E
operator|>
name|typename
name|std
operator|::
name|underlying_type
operator|<
name|E
operator|>
operator|::
name|type
name|Mask
argument_list|()
block|{
comment|// On overflow, NextPowerOf2 returns zero with the type uint64_t, so
comment|// subtracting 1 gives us the mask with all bits set, like we want.
return|return
name|NextPowerOf2
argument_list|(
argument|static_cast<typename std::underlying_type<E>::type>(              E::LLVM_BITMASK_LARGEST_ENUMERATOR)
argument_list|)
operator|-
literal|1
return|;
block|}
comment|/// Check that Val is in range for E, and return Val cast to E's underlying
comment|/// type.
name|template
operator|<
name|typename
name|E
operator|>
name|typename
name|std
operator|::
name|underlying_type
operator|<
name|E
operator|>
operator|::
name|type
name|Underlying
argument_list|(
argument|E Val
argument_list|)
block|{
name|auto
name|U
operator|=
name|static_cast
operator|<
name|typename
name|std
operator|::
name|underlying_type
operator|<
name|E
operator|>
operator|::
name|type
operator|>
operator|(
name|Val
operator|)
block|;
name|assert
argument_list|(
name|U
operator|>=
literal|0
operator|&&
literal|"Negative enum values are not allowed."
argument_list|)
block|;
name|assert
argument_list|(
name|U
operator|<=
name|Mask
operator|<
name|E
operator|>
operator|(
operator|)
operator|&&
literal|"Enum value too large (or largest val too small?)"
argument_list|)
block|;
return|return
name|U
return|;
block|}
name|template
operator|<
name|typename
name|E
operator|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_bitmask_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
name|E
name|operator
operator|~
operator|(
name|E
name|Val
operator|)
block|{
return|return
name|static_cast
operator|<
name|E
operator|>
operator|(
operator|~
name|Underlying
argument_list|(
name|Val
argument_list|)
operator|&
name|Mask
operator|<
name|E
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|E
operator|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_bitmask_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
name|E
name|operator
operator||
operator|(
name|E
name|LHS
operator|,
name|E
name|RHS
operator|)
block|{
return|return
name|static_cast
operator|<
name|E
operator|>
operator|(
name|Underlying
argument_list|(
name|LHS
argument_list|)
operator||
name|Underlying
argument_list|(
name|RHS
argument_list|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|E
operator|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_bitmask_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
name|E
name|operator
operator|&
operator|(
name|E
name|LHS
operator|,
name|E
name|RHS
operator|)
block|{
return|return
name|static_cast
operator|<
name|E
operator|>
operator|(
name|Underlying
argument_list|(
name|LHS
argument_list|)
operator|&
name|Underlying
argument_list|(
name|RHS
argument_list|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|E
operator|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_bitmask_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
name|E
name|operator
lambda|^
parameter_list|(
name|E
name|LHS
parameter_list|,
name|E
name|RHS
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|E
operator|>
operator|(
name|Underlying
argument_list|(
name|LHS
argument_list|)
operator|^
name|Underlying
argument_list|(
name|RHS
argument_list|)
operator|)
return|;
block|}
comment|// |=,&=, and ^= return a reference to LHS, to match the behavior of the
comment|// operators on builtin types.
name|template
operator|<
name|typename
name|E
operator|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_bitmask_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
name|E
operator|&
name|operator
operator||=
operator|(
name|E
operator|&
name|LHS
operator|,
name|E
name|RHS
operator|)
block|{
name|LHS
operator|=
name|LHS
operator||
name|RHS
block|;
return|return
name|LHS
return|;
block|}
name|template
operator|<
name|typename
name|E
operator|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_bitmask_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
name|E
operator|&
name|operator
operator|&=
operator|(
name|E
operator|&
name|LHS
operator|,
name|E
name|RHS
operator|)
block|{
name|LHS
operator|=
name|LHS
operator|&
name|RHS
block|;
return|return
name|LHS
return|;
block|}
name|template
operator|<
name|typename
name|E
operator|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|is_bitmask_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
name|E
operator|&
name|operator
operator|^=
operator|(
name|E
operator|&
name|LHS
operator|,
name|E
name|RHS
operator|)
block|{
name|LHS
operator|=
name|LHS
operator|^
name|RHS
block|;
return|return
name|LHS
return|;
block|}
block|}
comment|// namespace BitmaskEnumDetail
comment|// Enable bitmask enums in namespace ::llvm and all nested namespaces.
name|LLVM_ENABLE_BITMASK_ENUMS_IN_NAMESPACE
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

