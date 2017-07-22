begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/PointerEmbeddedInt.h ----------------------------*- C++ -*-===//
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
name|LLVM_ADT_POINTEREMBEDDEDINT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_POINTEREMBEDDEDINT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PointerLikeTypeTraits.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Utility to embed an integer into a pointer-like type. This is specifically
comment|/// intended to allow embedding integers where fewer bits are required than
comment|/// exist in a pointer, and the integer can participate in abstractions along
comment|/// side other pointer-like types. For example it can be placed into a \c
comment|/// PointerSumType or \c PointerUnion.
comment|///
comment|/// Note that much like pointers, an integer value of zero has special utility
comment|/// due to boolean conversions. For example, a non-null value can be tested for
comment|/// in the above abstractions without testing the particular active member.
comment|/// Also, the default constructed value zero initializes the integer.
name|template
operator|<
name|typename
name|IntT
operator|,
name|int
name|Bits
operator|=
sizeof|sizeof
argument_list|(
name|IntT
argument_list|)
operator|*
name|CHAR_BIT
operator|>
name|class
name|PointerEmbeddedInt
block|{
name|uintptr_t
name|Value
operator|=
literal|0
block|;
comment|// Note: This '<' is correct; using '<=' would result in some shifts
comment|// overflowing their storage types.
name|static_assert
argument_list|(
name|Bits
operator|<
sizeof|sizeof
argument_list|(
name|uintptr_t
argument_list|)
operator|*
name|CHAR_BIT
argument_list|,
literal|"Cannot embed more bits than we have in a pointer!"
argument_list|)
block|;    enum
operator|:
name|uintptr_t
block|{
comment|// We shift as many zeros into the value as we can while preserving the
comment|// number of bits desired for the integer.
name|Shift
operator|=
sizeof|sizeof
argument_list|(
name|uintptr_t
argument_list|)
operator|*
name|CHAR_BIT
operator|-
name|Bits
block|,
comment|// We also want to be able to mask out the preserved bits for asserts.
name|Mask
operator|=
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
operator|-
literal|1
operator|)
operator|<<
name|Bits
block|}
block|;    struct
name|RawValueTag
block|{
name|explicit
name|RawValueTag
argument_list|()
operator|=
expr|default
block|;   }
block|;
name|friend
name|class
name|PointerLikeTypeTraits
operator|<
name|PointerEmbeddedInt
operator|>
block|;
name|explicit
name|PointerEmbeddedInt
argument_list|(
argument|uintptr_t Value
argument_list|,
argument|RawValueTag
argument_list|)
operator|:
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
name|public
operator|:
name|PointerEmbeddedInt
argument_list|()
operator|=
expr|default
block|;
name|PointerEmbeddedInt
argument_list|(
argument|IntT I
argument_list|)
block|{
operator|*
name|this
operator|=
name|I
block|; }
name|PointerEmbeddedInt
operator|&
name|operator
operator|=
operator|(
name|IntT
name|I
operator|)
block|{
name|assert
argument_list|(
operator|(
name|std
operator|::
name|is_signed
operator|<
name|IntT
operator|>
operator|::
name|value
operator|?
name|isInt
operator|<
name|Bits
operator|>
operator|(
name|I
operator|)
operator|:
name|isUInt
operator|<
name|Bits
operator|>
operator|(
name|I
operator|)
operator|)
operator|&&
literal|"Integer has bits outside those preserved!"
argument_list|)
block|;
name|Value
operator|=
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|I
operator|)
operator|<<
name|Shift
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Note that this implicit conversion additionally allows all of the basic
comment|// comparison operators to work transparently, etc.
name|operator
name|IntT
argument_list|()
specifier|const
block|{
if|if
condition|(
name|std
operator|::
name|is_signed
operator|<
name|IntT
operator|>
operator|::
name|value
condition|)
return|return
name|static_cast
operator|<
name|IntT
operator|>
operator|(
name|static_cast
operator|<
name|intptr_t
operator|>
operator|(
name|Value
operator|)
operator|>>
name|Shift
operator|)
return|;
return|return
name|static_cast
operator|<
name|IntT
operator|>
operator|(
name|Value
operator|>>
name|Shift
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Provide pointer like traits to support use with pointer unions and sum
end_comment

begin_comment
comment|// types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IntT
operator|,
name|int
name|Bits
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|PointerEmbeddedInt
operator|<
name|IntT
operator|,
name|Bits
operator|>>
block|{
name|using
name|T
operator|=
name|PointerEmbeddedInt
operator|<
name|IntT
block|,
name|Bits
operator|>
block|;
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|const T&P
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|P
operator|.
name|Value
operator|)
return|;
block|}
specifier|static
specifier|inline
name|T
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|T
argument_list|(
argument|reinterpret_cast<uintptr_t>(P)
argument_list|,
argument|typename T::RawValueTag()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|T
name|getFromVoidPointer
parameter_list|(
specifier|const
name|void
modifier|*
name|P
parameter_list|)
block|{
return|return
name|T
argument_list|(
argument|reinterpret_cast<uintptr_t>(P)
argument_list|,
argument|typename T::RawValueTag()
argument_list|)
return|;
block|}
end_function

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
name|T
operator|::
name|Shift
block|}
enum|;
end_enum

begin_comment
unit|};
comment|// Teach DenseMap how to use PointerEmbeddedInt objects as keys if the Int type
end_comment

begin_comment
comment|// itself can be a key.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IntT
operator|,
name|int
name|Bits
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|PointerEmbeddedInt
operator|<
name|IntT
operator|,
name|Bits
operator|>>
block|{
name|using
name|T
operator|=
name|PointerEmbeddedInt
operator|<
name|IntT
block|,
name|Bits
operator|>
block|;
name|using
name|IntInfo
operator|=
name|DenseMapInfo
operator|<
name|IntT
operator|>
block|;
specifier|static
specifier|inline
name|T
name|getEmptyKey
argument_list|()
block|{
return|return
name|IntInfo
operator|::
name|getEmptyKey
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|T
name|getTombstoneKey
argument_list|()
block|{
return|return
name|IntInfo
operator|::
name|getTombstoneKey
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|T
modifier|&
name|Arg
parameter_list|)
block|{
return|return
name|IntInfo
operator|::
name|getHashValue
argument_list|(
name|Arg
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|T
modifier|&
name|LHS
parameter_list|,
specifier|const
name|T
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_POINTEREMBEDDEDINT_H
end_comment

end_unit

