begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/MathExtras.h - Useful math functions -------*- C++ -*-===//
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
comment|// This file contains some functions that are useful for math stuff.
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
name|LLVM_SUPPORT_MATHEXTRAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MATHEXTRAS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SwapByteOrder.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
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
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ANDROID_NDK__
end_ifdef

begin_include
include|#
directive|include
file|<android/api-level.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief The behavior an operation has on an input of 0.
enum|enum
name|ZeroBehavior
block|{
comment|/// \brief The returned value is undefined.
name|ZB_Undefined
block|,
comment|/// \brief The returned value is numeric_limits<T>::max()
name|ZB_Max
block|,
comment|/// \brief The returned value is numeric_limits<T>::digits
name|ZB_Width
block|}
enum|;
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|T
operator|,
name|std
operator|::
name|size_t
name|SizeOfT
operator|>
expr|struct
name|TrailingZerosCounter
block|{
specifier|static
name|std
operator|::
name|size_t
name|count
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior
argument_list|)
block|{
if|if
condition|(
operator|!
name|Val
condition|)
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|digits
return|;
if|if
condition|(
name|Val
operator|&
literal|0x1
condition|)
return|return
literal|0
return|;
comment|// Bisection method.
name|std
operator|::
name|size_t
name|ZeroBits
operator|=
literal|0
expr_stmt|;
name|T
name|Shift
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|digits
operator|>>
literal|1
decl_stmt|;
name|T
name|Mask
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
operator|>>
name|Shift
decl_stmt|;
while|while
condition|(
name|Shift
condition|)
block|{
if|if
condition|(
operator|(
name|Val
operator|&
name|Mask
operator|)
operator|==
literal|0
condition|)
block|{
name|Val
operator|>>=
name|Shift
expr_stmt|;
name|ZeroBits
operator||=
name|Shift
expr_stmt|;
block|}
name|Shift
operator|>>=
literal|1
expr_stmt|;
name|Mask
operator|>>=
name|Shift
expr_stmt|;
block|}
return|return
name|ZeroBits
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|4
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|TrailingZerosCounter
operator|<
name|T
operator|,
literal|4
operator|>
block|{
specifier|static
name|std
operator|::
name|size_t
name|count
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB
argument_list|)
block|{
if|if
condition|(
name|ZB
operator|!=
name|ZB_Undefined
operator|&&
name|Val
operator|==
literal|0
condition|)
return|return
literal|32
return|;
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_ctz
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
return|return
name|__builtin_ctz
argument_list|(
name|Val
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
name|unsigned
name|long
name|Index
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_BitScanForward
argument_list|(
operator|&
name|Index
argument_list|,
name|Val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Index
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
end_if

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|TrailingZerosCounter
operator|<
name|T
operator|,
literal|8
operator|>
block|{
specifier|static
name|std
operator|::
name|size_t
name|count
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB
argument_list|)
block|{
if|if
condition|(
name|ZB
operator|!=
name|ZB_Undefined
operator|&&
name|Val
operator|==
literal|0
condition|)
return|return
literal|64
return|;
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_ctzll
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
return|return
name|__builtin_ctzll
argument_list|(
name|Val
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
name|unsigned
name|long
name|Index
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_BitScanForward64
argument_list|(
operator|&
name|Index
argument_list|,
name|Val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Index
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// namespace detail
end_comment

begin_comment
comment|/// \brief Count number of 0's from the least significant bit to the most
end_comment

begin_comment
comment|///   stopping at the first 1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Only unsigned integral types are allowed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ZB the behavior on an input of 0. Only ZB_Width and ZB_Undefined are
end_comment

begin_comment
comment|///   valid arguments.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|size_t
name|countTrailingZeros
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
argument_list|,
literal|"Only unsigned integral types are allowed."
argument_list|)
block|;
return|return
name|llvm
operator|::
name|detail
operator|::
name|TrailingZerosCounter
operator|<
name|T
operator|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
operator|::
name|count
argument_list|(
name|Val
argument_list|,
name|ZB
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|T
operator|,
name|std
operator|::
name|size_t
name|SizeOfT
operator|>
expr|struct
name|LeadingZerosCounter
block|{
specifier|static
name|std
operator|::
name|size_t
name|count
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior
argument_list|)
block|{
if|if
condition|(
operator|!
name|Val
condition|)
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|digits
return|;
comment|// Bisection method.
name|std
operator|::
name|size_t
name|ZeroBits
operator|=
literal|0
block|;
for|for
control|(
name|T
name|Shift
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|digits
operator|>>
literal|1
init|;
name|Shift
condition|;
name|Shift
operator|>>=
literal|1
control|)
block|{
name|T
name|Tmp
init|=
name|Val
operator|>>
name|Shift
decl_stmt|;
if|if
condition|(
name|Tmp
condition|)
name|Val
operator|=
name|Tmp
expr_stmt|;
else|else
name|ZeroBits
operator||=
name|Shift
expr_stmt|;
block|}
return|return
name|ZeroBits
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|4
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|LeadingZerosCounter
operator|<
name|T
operator|,
literal|4
operator|>
block|{
specifier|static
name|std
operator|::
name|size_t
name|count
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB
argument_list|)
block|{
if|if
condition|(
name|ZB
operator|!=
name|ZB_Undefined
operator|&&
name|Val
operator|==
literal|0
condition|)
return|return
literal|32
return|;
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_clz
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
return|return
name|__builtin_clz
argument_list|(
name|Val
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
name|unsigned
name|long
name|Index
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_BitScanReverse
argument_list|(
operator|&
name|Index
argument_list|,
name|Val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Index
operator|^
literal|31
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
end_if

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|LeadingZerosCounter
operator|<
name|T
operator|,
literal|8
operator|>
block|{
specifier|static
name|std
operator|::
name|size_t
name|count
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB
argument_list|)
block|{
if|if
condition|(
name|ZB
operator|!=
name|ZB_Undefined
operator|&&
name|Val
operator|==
literal|0
condition|)
return|return
literal|64
return|;
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_clzll
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
return|return
name|__builtin_clzll
argument_list|(
name|Val
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
name|unsigned
name|long
name|Index
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_BitScanReverse64
argument_list|(
operator|&
name|Index
argument_list|,
name|Val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Index
operator|^
literal|63
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// namespace detail
end_comment

begin_comment
comment|/// \brief Count number of 0's from the most significant bit to the least
end_comment

begin_comment
comment|///   stopping at the first 1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Only unsigned integral types are allowed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ZB the behavior on an input of 0. Only ZB_Width and ZB_Undefined are
end_comment

begin_comment
comment|///   valid arguments.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|size_t
name|countLeadingZeros
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
argument_list|,
literal|"Only unsigned integral types are allowed."
argument_list|)
block|;
return|return
name|llvm
operator|::
name|detail
operator|::
name|LeadingZerosCounter
operator|<
name|T
operator|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
operator|::
name|count
argument_list|(
name|Val
argument_list|,
name|ZB
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the index of the first set bit starting from the least
end_comment

begin_comment
comment|///   significant bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Only unsigned integral types are allowed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ZB the behavior on an input of 0. Only ZB_Max and ZB_Undefined are
end_comment

begin_comment
comment|///   valid arguments.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|findFirstSet
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Max
argument_list|)
block|{
if|if
condition|(
name|ZB
operator|==
name|ZB_Max
operator|&&
name|Val
operator|==
literal|0
condition|)
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|countTrailingZeros
argument_list|(
name|Val
argument_list|,
name|ZB_Undefined
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Create a bitmask with the N right-most bits set to 1, and all other
end_comment

begin_comment
comment|/// bits set to 0.  Only unsigned types are allowed.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|T
name|maskTrailingOnes
argument_list|(
argument|unsigned N
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_unsigned
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"Invalid type!"
argument_list|)
block|;
specifier|const
name|unsigned
name|Bits
operator|=
name|CHAR_BIT
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
block|;
name|assert
argument_list|(
name|N
operator|<=
name|Bits
operator|&&
literal|"Invalid bit index"
argument_list|)
block|;
return|return
name|N
operator|==
literal|0
condition|?
literal|0
else|:
operator|(
name|T
argument_list|(
operator|-
literal|1
argument_list|)
operator|>>
operator|(
name|Bits
operator|-
name|N
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Create a bitmask with the N left-most bits set to 1, and all other
end_comment

begin_comment
comment|/// bits set to 0.  Only unsigned types are allowed.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|maskLeadingOnes
argument_list|(
argument|unsigned N
argument_list|)
block|{
return|return
operator|~
name|maskTrailingOnes
operator|<
name|T
operator|>
operator|(
name|CHAR_BIT
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|-
name|N
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Create a bitmask with the N right-most bits set to 0, and all other
end_comment

begin_comment
comment|/// bits set to 1.  Only unsigned types are allowed.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|maskTrailingZeros
argument_list|(
argument|unsigned N
argument_list|)
block|{
return|return
name|maskLeadingOnes
operator|<
name|T
operator|>
operator|(
name|CHAR_BIT
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|-
name|N
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Create a bitmask with the N left-most bits set to 0, and all other
end_comment

begin_comment
comment|/// bits set to 1.  Only unsigned types are allowed.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|maskLeadingZeros
argument_list|(
argument|unsigned N
argument_list|)
block|{
return|return
name|maskTrailingOnes
operator|<
name|T
operator|>
operator|(
name|CHAR_BIT
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|-
name|N
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the index of the last set bit starting from the least
end_comment

begin_comment
comment|///   significant bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Only unsigned integral types are allowed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ZB the behavior on an input of 0. Only ZB_Max and ZB_Undefined are
end_comment

begin_comment
comment|///   valid arguments.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|findLastSet
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Max
argument_list|)
block|{
if|if
condition|(
name|ZB
operator|==
name|ZB_Max
operator|&&
name|Val
operator|==
literal|0
condition|)
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
return|;
end_expr_stmt

begin_comment
comment|// Use ^ instead of - because both gcc and llvm can remove the associated ^
end_comment

begin_comment
comment|// in the __builtin_clz intrinsic on x86.
end_comment

begin_return
return|return
name|countLeadingZeros
argument_list|(
name|Val
argument_list|,
name|ZB_Undefined
argument_list|)
operator|^
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|digits
operator|-
literal|1
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Macro compressed bit reversal table for 256 bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// http://graphics.stanford.edu/~seander/bithacks.html#BitReverseTable
end_comment

begin_decl_stmt
unit|static
specifier|const
name|unsigned
name|char
name|BitReverseTable256
index|[
literal|256
index|]
init|=
block|{
define|#
directive|define
name|R2
parameter_list|(
name|n
parameter_list|)
value|n, n + 2 * 64, n + 1 * 64, n + 3 * 64
define|#
directive|define
name|R4
parameter_list|(
name|n
parameter_list|)
value|R2(n), R2(n + 2 * 16), R2(n + 1 * 16), R2(n + 3 * 16)
define|#
directive|define
name|R6
parameter_list|(
name|n
parameter_list|)
value|R4(n), R4(n + 2 * 4), R4(n + 1 * 4), R4(n + 3 * 4)
name|R6
argument_list|(
literal|0
argument_list|)
block|,
name|R6
argument_list|(
literal|2
argument_list|)
block|,
name|R6
argument_list|(
literal|1
argument_list|)
block|,
name|R6
argument_list|(
literal|3
argument_list|)
undef|#
directive|undef
name|R2
undef|#
directive|undef
name|R4
undef|#
directive|undef
name|R6
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Reverse the bits in \p Val.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|reverseBits
argument_list|(
argument|T Val
argument_list|)
block|{
name|unsigned
name|char
name|in
index|[
sizeof|sizeof
argument_list|(
name|Val
argument_list|)
index|]
block|;
name|unsigned
name|char
name|out
index|[
sizeof|sizeof
argument_list|(
name|Val
argument_list|)
index|]
block|;
name|std
operator|::
name|memcpy
argument_list|(
name|in
argument_list|,
operator|&
name|Val
argument_list|,
sizeof|sizeof
argument_list|(
name|Val
argument_list|)
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|Val
argument_list|)
condition|;
operator|++
name|i
control|)
name|out
index|[
operator|(
sizeof|sizeof
argument_list|(
name|Val
argument_list|)
operator|-
name|i
operator|)
operator|-
literal|1
index|]
operator|=
name|BitReverseTable256
index|[
name|in
index|[
name|i
index|]
index|]
expr_stmt|;
name|std
operator|::
name|memcpy
argument_list|(
operator|&
name|Val
argument_list|,
name|out
argument_list|,
sizeof|sizeof
argument_list|(
name|Val
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Val
return|;
end_return

begin_comment
unit|}
comment|// NOTE: The following support functions use the _32/_64 extensions instead of
end_comment

begin_comment
comment|// type overloading so that signed and unsigned integers can be used without
end_comment

begin_comment
comment|// ambiguity.
end_comment

begin_comment
comment|/// Return the high 32 bits of a 64 bit value.
end_comment

begin_function
unit|constexpr
specifier|inline
name|uint32_t
name|Hi_32
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|Value
operator|>>
literal|32
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Return the low 32 bits of a 64 bit value.
end_comment

begin_function
name|constexpr
specifier|inline
name|uint32_t
name|Lo_32
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|Value
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Make a 64-bit integer from a high / low pair of 32-bit integers.
end_comment

begin_function
name|constexpr
specifier|inline
name|uint64_t
name|Make_64
parameter_list|(
name|uint32_t
name|High
parameter_list|,
name|uint32_t
name|Low
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uint64_t
operator|)
name|High
operator|<<
literal|32
operator|)
operator||
operator|(
name|uint64_t
operator|)
name|Low
return|;
block|}
end_function

begin_comment
comment|/// Checks if an integer fits into the given bit width.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
name|constexpr
specifier|inline
name|bool
name|isInt
argument_list|(
argument|int64_t x
argument_list|)
block|{
return|return
name|N
operator|>=
literal|64
operator|||
operator|(
operator|-
operator|(
name|INT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|N
operator|-
literal|1
operator|)
operator|)
operator|<=
name|x
operator|&&
name|x
operator|<
operator|(
name|INT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|N
operator|-
literal|1
operator|)
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Template specializations to get better code for common cases.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|constexpr
specifier|inline
name|bool
name|isInt
operator|<
literal|8
operator|>
operator|(
name|int64_t
name|x
operator|)
block|{
return|return
name|static_cast
operator|<
name|int8_t
operator|>
operator|(
name|x
operator|)
operator|==
name|x
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|constexpr
specifier|inline
name|bool
name|isInt
operator|<
literal|16
operator|>
operator|(
name|int64_t
name|x
operator|)
block|{
return|return
name|static_cast
operator|<
name|int16_t
operator|>
operator|(
name|x
operator|)
operator|==
name|x
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|constexpr
specifier|inline
name|bool
name|isInt
operator|<
literal|32
operator|>
operator|(
name|int64_t
name|x
operator|)
block|{
return|return
name|static_cast
operator|<
name|int32_t
operator|>
operator|(
name|x
operator|)
operator|==
name|x
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Checks if a signed integer is an N bit number shifted left by S.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|,
name|unsigned
name|S
operator|>
name|constexpr
specifier|inline
name|bool
name|isShiftedInt
argument_list|(
argument|int64_t x
argument_list|)
block|{
name|static_assert
argument_list|(
name|N
operator|>
literal|0
argument_list|,
literal|"isShiftedInt<0> doesn't make sense (refers to a 0-bit number."
argument_list|)
block|;
name|static_assert
argument_list|(
name|N
operator|+
name|S
operator|<=
literal|64
argument_list|,
literal|"isShiftedInt<N, S> with N + S> 64 is too wide."
argument_list|)
block|;
return|return
name|isInt
operator|<
name|N
operator|+
name|S
operator|>
operator|(
name|x
operator|)
operator|&&
operator|(
name|x
operator|%
operator|(
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|S
operator|)
operator|==
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Checks if an unsigned integer fits into the given bit width.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is written as two functions rather than as simply
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   return N>= 64 || X< (UINT64_C(1)<< N);
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// to keep MSVC from (incorrectly) warning on isUInt<64> that we're shifting
end_comment

begin_comment
comment|/// left too many places.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
name|constexpr
specifier|inline
name|typename
name|std
operator|::
name|enable_if
operator|<
operator|(
name|N
operator|<
literal|64
operator|)
operator|,
name|bool
operator|>
operator|::
name|type
name|isUInt
argument_list|(
argument|uint64_t X
argument_list|)
block|{
name|static_assert
argument_list|(
name|N
operator|>
literal|0
argument_list|,
literal|"isUInt<0> doesn't make sense"
argument_list|)
block|;
return|return
name|X
operator|<
operator|(
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|N
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
name|constexpr
specifier|inline
name|typename
name|std
operator|::
name|enable_if
operator|<
name|N
operator|>=
literal|64
operator|,
name|bool
operator|>
operator|::
name|type
name|isUInt
argument_list|(
argument|uint64_t X
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|// Template specializations to get better code for common cases.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|constexpr
specifier|inline
name|bool
name|isUInt
operator|<
literal|8
operator|>
operator|(
name|uint64_t
name|x
operator|)
block|{
return|return
name|static_cast
operator|<
name|uint8_t
operator|>
operator|(
name|x
operator|)
operator|==
name|x
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|constexpr
specifier|inline
name|bool
name|isUInt
operator|<
literal|16
operator|>
operator|(
name|uint64_t
name|x
operator|)
block|{
return|return
name|static_cast
operator|<
name|uint16_t
operator|>
operator|(
name|x
operator|)
operator|==
name|x
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|constexpr
specifier|inline
name|bool
name|isUInt
operator|<
literal|32
operator|>
operator|(
name|uint64_t
name|x
operator|)
block|{
return|return
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|x
operator|)
operator|==
name|x
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Checks if a unsigned integer is an N bit number shifted left by S.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|,
name|unsigned
name|S
operator|>
name|constexpr
specifier|inline
name|bool
name|isShiftedUInt
argument_list|(
argument|uint64_t x
argument_list|)
block|{
name|static_assert
argument_list|(
name|N
operator|>
literal|0
argument_list|,
literal|"isShiftedUInt<0> doesn't make sense (refers to a 0-bit number)"
argument_list|)
block|;
name|static_assert
argument_list|(
name|N
operator|+
name|S
operator|<=
literal|64
argument_list|,
literal|"isShiftedUInt<N, S> with N + S> 64 is too wide."
argument_list|)
block|;
comment|// Per the two static_asserts above, S must be strictly less than 64.  So
comment|// 1<< S is not undefined behavior.
return|return
name|isUInt
operator|<
name|N
operator|+
name|S
operator|>
operator|(
name|x
operator|)
operator|&&
operator|(
name|x
operator|%
operator|(
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|S
operator|)
operator|==
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Gets the maximum value for a N-bit unsigned integer.
end_comment

begin_function
specifier|inline
name|uint64_t
name|maxUIntN
parameter_list|(
name|uint64_t
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|N
operator|>
literal|0
operator|&&
name|N
operator|<=
literal|64
operator|&&
literal|"integer width out of range"
argument_list|)
expr_stmt|;
comment|// uint64_t(1)<< 64 is undefined behavior, so we can't do
comment|//   (uint64_t(1)<< N) - 1
comment|// without checking first that N != 64.  But this works and doesn't have a
comment|// branch.
return|return
name|UINT64_MAX
operator|>>
operator|(
literal|64
operator|-
name|N
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Gets the minimum value for a N-bit signed integer.
end_comment

begin_function
specifier|inline
name|int64_t
name|minIntN
parameter_list|(
name|int64_t
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|N
operator|>
literal|0
operator|&&
name|N
operator|<=
literal|64
operator|&&
literal|"integer width out of range"
argument_list|)
expr_stmt|;
return|return
operator|-
operator|(
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|N
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Gets the maximum value for a N-bit signed integer.
end_comment

begin_function
specifier|inline
name|int64_t
name|maxIntN
parameter_list|(
name|int64_t
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|N
operator|>
literal|0
operator|&&
name|N
operator|<=
literal|64
operator|&&
literal|"integer width out of range"
argument_list|)
expr_stmt|;
comment|// This relies on two's complement wraparound when N == 64, so we convert to
comment|// int64_t only at the very end to avoid UB.
return|return
operator|(
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|N
operator|-
literal|1
operator|)
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/// Checks if an unsigned integer fits into the given (dynamic) bit width.
end_comment

begin_function
specifier|inline
name|bool
name|isUIntN
parameter_list|(
name|unsigned
name|N
parameter_list|,
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|N
operator|>=
literal|64
operator|||
name|x
operator|<=
name|maxUIntN
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Checks if an signed integer fits into the given (dynamic) bit width.
end_comment

begin_function
specifier|inline
name|bool
name|isIntN
parameter_list|(
name|unsigned
name|N
parameter_list|,
name|int64_t
name|x
parameter_list|)
block|{
return|return
name|N
operator|>=
literal|64
operator|||
operator|(
name|minIntN
argument_list|(
name|N
argument_list|)
operator|<=
name|x
operator|&&
name|x
operator|<=
name|maxIntN
argument_list|(
name|N
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Return true if the argument is a non-empty sequence of ones starting at the
end_comment

begin_comment
comment|/// least significant bit with the remainder zero (32 bit version).
end_comment

begin_comment
comment|/// Ex. isMask_32(0x0000FFFFU) == true.
end_comment

begin_function
name|constexpr
specifier|inline
name|bool
name|isMask_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
name|Value
operator|&&
operator|(
operator|(
name|Value
operator|+
literal|1
operator|)
operator|&
name|Value
operator|)
operator|==
literal|0
return|;
block|}
end_function

begin_comment
comment|/// Return true if the argument is a non-empty sequence of ones starting at the
end_comment

begin_comment
comment|/// least significant bit with the remainder zero (64 bit version).
end_comment

begin_function
name|constexpr
specifier|inline
name|bool
name|isMask_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|Value
operator|&&
operator|(
operator|(
name|Value
operator|+
literal|1
operator|)
operator|&
name|Value
operator|)
operator|==
literal|0
return|;
block|}
end_function

begin_comment
comment|/// Return true if the argument contains a non-empty sequence of ones with the
end_comment

begin_comment
comment|/// remainder zero (32 bit version.) Ex. isShiftedMask_32(0x0000FF00U) == true.
end_comment

begin_function
name|constexpr
specifier|inline
name|bool
name|isShiftedMask_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
name|Value
operator|&&
name|isMask_32
argument_list|(
operator|(
name|Value
operator|-
literal|1
operator|)
operator||
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return true if the argument contains a non-empty sequence of ones with the
end_comment

begin_comment
comment|/// remainder zero (64 bit version.)
end_comment

begin_function
name|constexpr
specifier|inline
name|bool
name|isShiftedMask_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|Value
operator|&&
name|isMask_64
argument_list|(
operator|(
name|Value
operator|-
literal|1
operator|)
operator||
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return true if the argument is a power of two> 0.
end_comment

begin_comment
comment|/// Ex. isPowerOf2_32(0x00100000U) == true (32 bit edition.)
end_comment

begin_function
name|constexpr
specifier|inline
name|bool
name|isPowerOf2_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
name|Value
operator|&&
operator|!
operator|(
name|Value
operator|&
operator|(
name|Value
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Return true if the argument is a power of two> 0 (64 bit edition.)
end_comment

begin_function
name|constexpr
specifier|inline
name|bool
name|isPowerOf2_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|Value
operator|&&
operator|!
operator|(
name|Value
operator|&
operator|(
name|Value
operator|-
name|int64_t
argument_list|(
literal|1L
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Return a byte-swapped representation of the 16-bit argument.
end_comment

begin_function
specifier|inline
name|uint16_t
name|ByteSwap_16
parameter_list|(
name|uint16_t
name|Value
parameter_list|)
block|{
return|return
name|sys
operator|::
name|SwapByteOrder_16
argument_list|(
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return a byte-swapped representation of the 32-bit argument.
end_comment

begin_function
specifier|inline
name|uint32_t
name|ByteSwap_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
name|sys
operator|::
name|SwapByteOrder_32
argument_list|(
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return a byte-swapped representation of the 64-bit argument.
end_comment

begin_function
specifier|inline
name|uint64_t
name|ByteSwap_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|sys
operator|::
name|SwapByteOrder_64
argument_list|(
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Count the number of ones from the most significant bit to the first
end_comment

begin_comment
comment|/// zero bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Ex. countLeadingOnes(0xFF0FFF00) == 8.
end_comment

begin_comment
comment|/// Only unsigned integral types are allowed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ZB the behavior on an input of all ones. Only ZB_Width and
end_comment

begin_comment
comment|/// ZB_Undefined are valid arguments.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|size_t
name|countLeadingOnes
argument_list|(
argument|T Value
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
argument_list|,
literal|"Only unsigned integral types are allowed."
argument_list|)
block|;
return|return
name|countLeadingZeros
argument_list|(
operator|~
name|Value
argument_list|,
name|ZB
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Count the number of ones from the least significant bit to the first
end_comment

begin_comment
comment|/// zero bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Ex. countTrailingOnes(0x00FF00FF) == 8.
end_comment

begin_comment
comment|/// Only unsigned integral types are allowed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ZB the behavior on an input of all ones. Only ZB_Width and
end_comment

begin_comment
comment|/// ZB_Undefined are valid arguments.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|size_t
name|countTrailingOnes
argument_list|(
argument|T Value
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
argument_list|,
literal|"Only unsigned integral types are allowed."
argument_list|)
block|;
return|return
name|countTrailingZeros
argument_list|(
operator|~
name|Value
argument_list|,
name|ZB
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|T
operator|,
name|std
operator|::
name|size_t
name|SizeOfT
operator|>
expr|struct
name|PopulationCounter
block|{
specifier|static
name|unsigned
name|count
argument_list|(
argument|T Value
argument_list|)
block|{
comment|// Generic version, forward to 32 bits.
name|static_assert
argument_list|(
name|SizeOfT
operator|<=
literal|4
argument_list|,
literal|"Not implemented!"
argument_list|)
block|;
if|#
directive|if
name|__GNUC__
operator|>=
literal|4
return|return
name|__builtin_popcount
argument_list|(
name|Value
argument_list|)
return|;
else|#
directive|else
name|uint32_t
name|v
operator|=
name|Value
block|;
name|v
operator|=
name|v
operator|-
operator|(
operator|(
name|v
operator|>>
literal|1
operator|)
operator|&
literal|0x55555555
operator|)
block|;
name|v
operator|=
operator|(
name|v
operator|&
literal|0x33333333
operator|)
operator|+
operator|(
operator|(
name|v
operator|>>
literal|2
operator|)
operator|&
literal|0x33333333
operator|)
block|;
return|return
operator|(
operator|(
name|v
operator|+
operator|(
name|v
operator|>>
literal|4
operator|)
operator|&
literal|0xF0F0F0F
operator|)
operator|*
literal|0x1010101
operator|)
operator|>>
literal|24
return|;
endif|#
directive|endif
block|}
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
expr|struct
name|PopulationCounter
operator|<
name|T
operator|,
literal|8
operator|>
block|{
specifier|static
name|unsigned
name|count
argument_list|(
argument|T Value
argument_list|)
block|{
if|#
directive|if
name|__GNUC__
operator|>=
literal|4
return|return
name|__builtin_popcountll
argument_list|(
name|Value
argument_list|)
return|;
else|#
directive|else
name|uint64_t
name|v
operator|=
name|Value
block|;
name|v
operator|=
name|v
operator|-
operator|(
operator|(
name|v
operator|>>
literal|1
operator|)
operator|&
literal|0x5555555555555555ULL
operator|)
block|;
name|v
operator|=
operator|(
name|v
operator|&
literal|0x3333333333333333ULL
operator|)
operator|+
operator|(
operator|(
name|v
operator|>>
literal|2
operator|)
operator|&
literal|0x3333333333333333ULL
operator|)
block|;
name|v
operator|=
operator|(
name|v
operator|+
operator|(
name|v
operator|>>
literal|4
operator|)
operator|)
operator|&
literal|0x0F0F0F0F0F0F0F0FULL
block|;
return|return
name|unsigned
argument_list|(
call|(
name|uint64_t
call|)
argument_list|(
name|v
operator|*
literal|0x0101010101010101ULL
argument_list|)
operator|>>
literal|56
argument_list|)
return|;
endif|#
directive|endif
block|}
end_expr_stmt

begin_comment
unit|}; }
comment|// namespace detail
end_comment

begin_comment
comment|/// \brief Count the number of set bits in a value.
end_comment

begin_comment
comment|/// Ex. countPopulation(0xF000F000) = 8
end_comment

begin_comment
comment|/// Returns 0 if the word is zero.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|unsigned
name|countPopulation
argument_list|(
argument|T Value
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
argument_list|,
literal|"Only unsigned integral types are allowed."
argument_list|)
block|;
return|return
name|detail
operator|::
name|PopulationCounter
operator|<
name|T
operator|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
operator|::
name|count
argument_list|(
name|Value
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return the log base 2 of the specified value.
end_comment

begin_function
specifier|inline
name|double
name|Log2
parameter_list|(
name|double
name|Value
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__ANDROID_API__
argument_list|)
operator|&&
name|__ANDROID_API__
operator|<
literal|18
return|return
name|__builtin_log
argument_list|(
name|Value
argument_list|)
operator|/
name|__builtin_log
argument_list|(
literal|2.0
argument_list|)
return|;
else|#
directive|else
return|return
name|log2
argument_list|(
name|Value
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/// Return the floor log base 2 of the specified value, -1 if the value is zero.
end_comment

begin_comment
comment|/// (32 bit edition.)
end_comment

begin_comment
comment|/// Ex. Log2_32(32) == 5, Log2_32(1) == 0, Log2_32(0) == -1, Log2_32(6) == 2
end_comment

begin_function
specifier|inline
name|unsigned
name|Log2_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
literal|31
operator|-
name|countLeadingZeros
argument_list|(
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return the floor log base 2 of the specified value, -1 if the value is zero.
end_comment

begin_comment
comment|/// (64 bit edition.)
end_comment

begin_function
specifier|inline
name|unsigned
name|Log2_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
literal|63
operator|-
name|countLeadingZeros
argument_list|(
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return the ceil log base 2 of the specified value, 32 if the value is zero.
end_comment

begin_comment
comment|/// (32 bit edition).
end_comment

begin_comment
comment|/// Ex. Log2_32_Ceil(32) == 5, Log2_32_Ceil(1) == 0, Log2_32_Ceil(6) == 3
end_comment

begin_function
specifier|inline
name|unsigned
name|Log2_32_Ceil
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
literal|32
operator|-
name|countLeadingZeros
argument_list|(
name|Value
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return the ceil log base 2 of the specified value, 64 if the value is zero.
end_comment

begin_comment
comment|/// (64 bit edition.)
end_comment

begin_function
specifier|inline
name|unsigned
name|Log2_64_Ceil
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
literal|64
operator|-
name|countLeadingZeros
argument_list|(
name|Value
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Return the greatest common divisor of the values using Euclid's algorithm.
end_comment

begin_function
specifier|inline
name|uint64_t
name|GreatestCommonDivisor64
parameter_list|(
name|uint64_t
name|A
parameter_list|,
name|uint64_t
name|B
parameter_list|)
block|{
while|while
condition|(
name|B
condition|)
block|{
name|uint64_t
name|T
init|=
name|B
decl_stmt|;
name|B
operator|=
name|A
operator|%
name|B
expr_stmt|;
name|A
operator|=
name|T
expr_stmt|;
block|}
return|return
name|A
return|;
block|}
end_function

begin_comment
comment|/// This function takes a 64-bit integer and returns the bit equivalent double.
end_comment

begin_function
specifier|inline
name|double
name|BitsToDouble
parameter_list|(
name|uint64_t
name|Bits
parameter_list|)
block|{
name|double
name|D
decl_stmt|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|,
literal|"Unexpected type sizes"
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|D
argument_list|,
operator|&
name|Bits
argument_list|,
sizeof|sizeof
argument_list|(
name|Bits
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|D
return|;
block|}
end_function

begin_comment
comment|/// This function takes a 32-bit integer and returns the bit equivalent float.
end_comment

begin_function
specifier|inline
name|float
name|BitsToFloat
parameter_list|(
name|uint32_t
name|Bits
parameter_list|)
block|{
name|float
name|F
decl_stmt|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|,
literal|"Unexpected type sizes"
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|F
argument_list|,
operator|&
name|Bits
argument_list|,
sizeof|sizeof
argument_list|(
name|Bits
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|F
return|;
block|}
end_function

begin_comment
comment|/// This function takes a double and returns the bit equivalent 64-bit integer.
end_comment

begin_comment
comment|/// Note that copying doubles around changes the bits of NaNs on some hosts,
end_comment

begin_comment
comment|/// notably x86, so this routine cannot be used if these bits are needed.
end_comment

begin_function
specifier|inline
name|uint64_t
name|DoubleToBits
parameter_list|(
name|double
name|Double
parameter_list|)
block|{
name|uint64_t
name|Bits
decl_stmt|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|,
literal|"Unexpected type sizes"
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|Bits
argument_list|,
operator|&
name|Double
argument_list|,
sizeof|sizeof
argument_list|(
name|Double
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Bits
return|;
block|}
end_function

begin_comment
comment|/// This function takes a float and returns the bit equivalent 32-bit integer.
end_comment

begin_comment
comment|/// Note that copying floats around changes the bits of NaNs on some hosts,
end_comment

begin_comment
comment|/// notably x86, so this routine cannot be used if these bits are needed.
end_comment

begin_function
specifier|inline
name|uint32_t
name|FloatToBits
parameter_list|(
name|float
name|Float
parameter_list|)
block|{
name|uint32_t
name|Bits
decl_stmt|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|,
literal|"Unexpected type sizes"
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|Bits
argument_list|,
operator|&
name|Float
argument_list|,
sizeof|sizeof
argument_list|(
name|Float
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Bits
return|;
block|}
end_function

begin_comment
comment|/// A and B are either alignments or offsets. Return the minimum alignment that
end_comment

begin_comment
comment|/// may be assumed after adding the two together.
end_comment

begin_function
name|constexpr
specifier|inline
name|uint64_t
name|MinAlign
parameter_list|(
name|uint64_t
name|A
parameter_list|,
name|uint64_t
name|B
parameter_list|)
block|{
comment|// The largest power of 2 that divides both A and B.
comment|//
comment|// Replace "-Value" by "1+~Value" in the following commented code to avoid
comment|// MSVC warning C4146
comment|//    return (A | B)& -(A | B);
return|return
operator|(
name|A
operator||
name|B
operator|)
operator|&
operator|(
literal|1
operator|+
operator|~
operator|(
name|A
operator||
name|B
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Aligns \c Addr to \c Alignment bytes, rounding up.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Alignment should be a power of two.  This method rounds up, so
end_comment

begin_comment
comment|/// alignAddr(7, 4) == 8 and alignAddr(8, 4) == 8.
end_comment

begin_function
specifier|inline
name|uintptr_t
name|alignAddr
parameter_list|(
specifier|const
name|void
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Alignment
parameter_list|)
block|{
name|assert
argument_list|(
name|Alignment
operator|&&
name|isPowerOf2_64
argument_list|(
operator|(
name|uint64_t
operator|)
name|Alignment
argument_list|)
operator|&&
literal|"Alignment is not a power of two!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Addr
operator|+
name|Alignment
operator|-
literal|1
operator|>=
operator|(
name|uintptr_t
operator|)
name|Addr
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
operator|(
name|uintptr_t
operator|)
name|Addr
operator|+
name|Alignment
operator|-
literal|1
operator|)
operator|&
operator|~
call|(
name|uintptr_t
call|)
argument_list|(
name|Alignment
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns the necessary adjustment for aligning \c Ptr to \c Alignment
end_comment

begin_comment
comment|/// bytes, rounding up.
end_comment

begin_function
specifier|inline
name|size_t
name|alignmentAdjustment
parameter_list|(
specifier|const
name|void
modifier|*
name|Ptr
parameter_list|,
name|size_t
name|Alignment
parameter_list|)
block|{
return|return
name|alignAddr
argument_list|(
name|Ptr
argument_list|,
name|Alignment
argument_list|)
operator|-
operator|(
name|uintptr_t
operator|)
name|Ptr
return|;
block|}
end_function

begin_comment
comment|/// Returns the next power of two (in 64-bits) that is strictly greater than A.
end_comment

begin_comment
comment|/// Returns zero on overflow.
end_comment

begin_function
specifier|inline
name|uint64_t
name|NextPowerOf2
parameter_list|(
name|uint64_t
name|A
parameter_list|)
block|{
name|A
operator||=
operator|(
name|A
operator|>>
literal|1
operator|)
expr_stmt|;
name|A
operator||=
operator|(
name|A
operator|>>
literal|2
operator|)
expr_stmt|;
name|A
operator||=
operator|(
name|A
operator|>>
literal|4
operator|)
expr_stmt|;
name|A
operator||=
operator|(
name|A
operator|>>
literal|8
operator|)
expr_stmt|;
name|A
operator||=
operator|(
name|A
operator|>>
literal|16
operator|)
expr_stmt|;
name|A
operator||=
operator|(
name|A
operator|>>
literal|32
operator|)
expr_stmt|;
return|return
name|A
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|/// Returns the power of two which is less than or equal to the given value.
end_comment

begin_comment
comment|/// Essentially, it is a floor operation across the domain of powers of two.
end_comment

begin_function
specifier|inline
name|uint64_t
name|PowerOf2Floor
parameter_list|(
name|uint64_t
name|A
parameter_list|)
block|{
if|if
condition|(
operator|!
name|A
condition|)
return|return
literal|0
return|;
return|return
literal|1ull
operator|<<
operator|(
literal|63
operator|-
name|countLeadingZeros
argument_list|(
name|A
argument_list|,
name|ZB_Undefined
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Returns the power of two which is greater than or equal to the given value.
end_comment

begin_comment
comment|/// Essentially, it is a ceil operation across the domain of powers of two.
end_comment

begin_function
specifier|inline
name|uint64_t
name|PowerOf2Ceil
parameter_list|(
name|uint64_t
name|A
parameter_list|)
block|{
if|if
condition|(
operator|!
name|A
condition|)
return|return
literal|0
return|;
return|return
name|NextPowerOf2
argument_list|(
name|A
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Returns the next integer (mod 2**64) that is greater than or equal to
end_comment

begin_comment
comment|/// \p Value and is a multiple of \p Align. \p Align must be non-zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If non-zero \p Skew is specified, the return value will be a minimal
end_comment

begin_comment
comment|/// integer that is greater than or equal to \p Value and equal to
end_comment

begin_comment
comment|/// \p Align * N + \p Skew for some integer N. If \p Skew is larger than
end_comment

begin_comment
comment|/// \p Align, its value is adjusted to '\p Skew mod \p Align'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Examples:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   alignTo(5, 8) = 8
end_comment

begin_comment
comment|///   alignTo(17, 8) = 24
end_comment

begin_comment
comment|///   alignTo(~0LL, 8) = 0
end_comment

begin_comment
comment|///   alignTo(321, 255) = 510
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   alignTo(5, 8, 7) = 7
end_comment

begin_comment
comment|///   alignTo(17, 8, 1) = 17
end_comment

begin_comment
comment|///   alignTo(~0LL, 8, 3) = 3
end_comment

begin_comment
comment|///   alignTo(321, 255, 42) = 552
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_function
specifier|inline
name|uint64_t
name|alignTo
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|uint64_t
name|Align
parameter_list|,
name|uint64_t
name|Skew
init|=
literal|0
parameter_list|)
block|{
name|assert
argument_list|(
name|Align
operator|!=
literal|0u
operator|&&
literal|"Align can't be 0."
argument_list|)
expr_stmt|;
name|Skew
operator|%=
name|Align
expr_stmt|;
return|return
operator|(
name|Value
operator|+
name|Align
operator|-
literal|1
operator|-
name|Skew
operator|)
operator|/
name|Align
operator|*
name|Align
operator|+
name|Skew
return|;
block|}
end_function

begin_comment
comment|/// Returns the next integer (mod 2**64) that is greater than or equal to
end_comment

begin_comment
comment|/// \p Value and is a multiple of \c Align. \c Align must be non-zero.
end_comment

begin_expr_stmt
name|template
operator|<
name|uint64_t
name|Align
operator|>
name|constexpr
specifier|inline
name|uint64_t
name|alignTo
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|static_assert
argument_list|(
name|Align
operator|!=
literal|0u
argument_list|,
literal|"Align must be non-zero"
argument_list|)
block|;
return|return
operator|(
name|Value
operator|+
name|Align
operator|-
literal|1
operator|)
operator|/
name|Align
operator|*
name|Align
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \c alignTo for contexts where a constant expression is required.
end_comment

begin_comment
comment|/// \sa alignTo
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \todo FIXME: remove when \c constexpr becomes really \c constexpr
end_comment

begin_expr_stmt
name|template
operator|<
name|uint64_t
name|Align
operator|>
expr|struct
name|AlignTo
block|{
name|static_assert
argument_list|(
name|Align
operator|!=
literal|0u
argument_list|,
literal|"Align must be non-zero"
argument_list|)
block|;
name|template
operator|<
name|uint64_t
name|Value
operator|>
expr|struct
name|from_value
block|{
specifier|static
specifier|const
name|uint64_t
name|value
operator|=
operator|(
name|Value
operator|+
name|Align
operator|-
literal|1
operator|)
operator|/
name|Align
operator|*
name|Align
block|;   }
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns the largest uint64_t less than or equal to \p Value and is
end_comment

begin_comment
comment|/// \p Skew mod \p Align. \p Align must be non-zero
end_comment

begin_function
specifier|inline
name|uint64_t
name|alignDown
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|uint64_t
name|Align
parameter_list|,
name|uint64_t
name|Skew
init|=
literal|0
parameter_list|)
block|{
name|assert
argument_list|(
name|Align
operator|!=
literal|0u
operator|&&
literal|"Align can't be 0."
argument_list|)
expr_stmt|;
name|Skew
operator|%=
name|Align
expr_stmt|;
return|return
operator|(
name|Value
operator|-
name|Skew
operator|)
operator|/
name|Align
operator|*
name|Align
operator|+
name|Skew
return|;
block|}
end_function

begin_comment
comment|/// Returns the offset to the next integer (mod 2**64) that is greater than
end_comment

begin_comment
comment|/// or equal to \p Value and is a multiple of \p Align. \p Align must be
end_comment

begin_comment
comment|/// non-zero.
end_comment

begin_function
specifier|inline
name|uint64_t
name|OffsetToAlignment
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|uint64_t
name|Align
parameter_list|)
block|{
return|return
name|alignTo
argument_list|(
name|Value
argument_list|,
name|Align
argument_list|)
operator|-
name|Value
return|;
block|}
end_function

begin_comment
comment|/// Sign-extend the number in the bottom B bits of X to a 32-bit integer.
end_comment

begin_comment
comment|/// Requires 0< B<= 32.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|B
operator|>
name|constexpr
specifier|inline
name|int32_t
name|SignExtend32
argument_list|(
argument|uint32_t X
argument_list|)
block|{
name|static_assert
argument_list|(
name|B
operator|>
literal|0
argument_list|,
literal|"Bit width can't be 0."
argument_list|)
block|;
name|static_assert
argument_list|(
name|B
operator|<=
literal|32
argument_list|,
literal|"Bit width out of range."
argument_list|)
block|;
return|return
name|int32_t
argument_list|(
name|X
operator|<<
operator|(
literal|32
operator|-
name|B
operator|)
argument_list|)
operator|>>
operator|(
literal|32
operator|-
name|B
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Sign-extend the number in the bottom B bits of X to a 32-bit integer.
end_comment

begin_comment
comment|/// Requires 0< B< 32.
end_comment

begin_function
specifier|inline
name|int32_t
name|SignExtend32
parameter_list|(
name|uint32_t
name|X
parameter_list|,
name|unsigned
name|B
parameter_list|)
block|{
name|assert
argument_list|(
name|B
operator|>
literal|0
operator|&&
literal|"Bit width can't be 0."
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|B
operator|<=
literal|32
operator|&&
literal|"Bit width out of range."
argument_list|)
expr_stmt|;
return|return
name|int32_t
argument_list|(
name|X
operator|<<
operator|(
literal|32
operator|-
name|B
operator|)
argument_list|)
operator|>>
operator|(
literal|32
operator|-
name|B
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Sign-extend the number in the bottom B bits of X to a 64-bit integer.
end_comment

begin_comment
comment|/// Requires 0< B< 64.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|B
operator|>
name|constexpr
specifier|inline
name|int64_t
name|SignExtend64
argument_list|(
argument|uint64_t x
argument_list|)
block|{
name|static_assert
argument_list|(
name|B
operator|>
literal|0
argument_list|,
literal|"Bit width can't be 0."
argument_list|)
block|;
name|static_assert
argument_list|(
name|B
operator|<=
literal|64
argument_list|,
literal|"Bit width out of range."
argument_list|)
block|;
return|return
name|int64_t
argument_list|(
name|x
operator|<<
operator|(
literal|64
operator|-
name|B
operator|)
argument_list|)
operator|>>
operator|(
literal|64
operator|-
name|B
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Sign-extend the number in the bottom B bits of X to a 64-bit integer.
end_comment

begin_comment
comment|/// Requires 0< B< 64.
end_comment

begin_function
specifier|inline
name|int64_t
name|SignExtend64
parameter_list|(
name|uint64_t
name|X
parameter_list|,
name|unsigned
name|B
parameter_list|)
block|{
name|assert
argument_list|(
name|B
operator|>
literal|0
operator|&&
literal|"Bit width can't be 0."
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|B
operator|<=
literal|64
operator|&&
literal|"Bit width out of range."
argument_list|)
expr_stmt|;
return|return
name|int64_t
argument_list|(
name|X
operator|<<
operator|(
literal|64
operator|-
name|B
operator|)
argument_list|)
operator|>>
operator|(
literal|64
operator|-
name|B
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Subtract two unsigned integers, X and Y, of type T and return the absolute
end_comment

begin_comment
comment|/// value of the result.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_unsigned
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|T
operator|>
operator|::
name|type
name|AbsoluteDifference
argument_list|(
argument|T X
argument_list|,
argument|T Y
argument_list|)
block|{
return|return
name|std
operator|::
name|max
argument_list|(
name|X
argument_list|,
name|Y
argument_list|)
operator|-
name|std
operator|::
name|min
argument_list|(
name|X
argument_list|,
name|Y
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Add two unsigned integers, X and Y, of type T.  Clamp the result to the
end_comment

begin_comment
comment|/// maximum representable value of T on overflow.  ResultOverflowed indicates if
end_comment

begin_comment
comment|/// the result is larger than the maximum representable value of type T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_unsigned
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|T
operator|>
operator|::
name|type
name|SaturatingAdd
argument_list|(
argument|T X
argument_list|,
argument|T Y
argument_list|,
argument|bool *ResultOverflowed = nullptr
argument_list|)
block|{
name|bool
name|Dummy
block|;
name|bool
operator|&
name|Overflowed
operator|=
name|ResultOverflowed
condition|?
operator|*
name|ResultOverflowed
else|:
name|Dummy
block|;
comment|// Hacker's Delight, p. 29
name|T
name|Z
operator|=
name|X
operator|+
name|Y
block|;
name|Overflowed
operator|=
operator|(
name|Z
operator|<
name|X
operator|||
name|Z
operator|<
name|Y
operator|)
block|;
if|if
condition|(
name|Overflowed
condition|)
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
return|;
else|else
return|return
name|Z
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Multiply two unsigned integers, X and Y, of type T.  Clamp the result to the
end_comment

begin_comment
comment|/// maximum representable value of T on overflow.  ResultOverflowed indicates if
end_comment

begin_comment
comment|/// the result is larger than the maximum representable value of type T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_unsigned
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|T
operator|>
operator|::
name|type
name|SaturatingMultiply
argument_list|(
argument|T X
argument_list|,
argument|T Y
argument_list|,
argument|bool *ResultOverflowed = nullptr
argument_list|)
block|{
name|bool
name|Dummy
block|;
name|bool
operator|&
name|Overflowed
operator|=
name|ResultOverflowed
condition|?
operator|*
name|ResultOverflowed
else|:
name|Dummy
block|;
comment|// Hacker's Delight, p. 30 has a different algorithm, but we don't use that
comment|// because it fails for uint16_t (where multiplication can have undefined
comment|// behavior due to promotion to int), and requires a division in addition
comment|// to the multiplication.
name|Overflowed
operator|=
name|false
block|;
comment|// Log2(Z) would be either Log2Z or Log2Z + 1.
comment|// Special case: if X or Y is 0, Log2_64 gives -1, and Log2Z
comment|// will necessarily be less than Log2Max as desired.
name|int
name|Log2Z
operator|=
name|Log2_64
argument_list|(
name|X
argument_list|)
operator|+
name|Log2_64
argument_list|(
name|Y
argument_list|)
block|;
specifier|const
name|T
name|Max
operator|=
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
block|;
name|int
name|Log2Max
operator|=
name|Log2_64
argument_list|(
name|Max
argument_list|)
block|;
if|if
condition|(
name|Log2Z
operator|<
name|Log2Max
condition|)
block|{
return|return
name|X
operator|*
name|Y
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|Log2Z
operator|>
name|Log2Max
condition|)
block|{
name|Overflowed
operator|=
name|true
expr_stmt|;
return|return
name|Max
return|;
block|}
end_if

begin_comment
comment|// We're going to use the top bit, and maybe overflow one
end_comment

begin_comment
comment|// bit past it. Multiply all but the bottom bit then add
end_comment

begin_comment
comment|// that on at the end.
end_comment

begin_decl_stmt
name|T
name|Z
init|=
operator|(
name|X
operator|>>
literal|1
operator|)
operator|*
name|Y
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|Z
operator|&
operator|~
operator|(
name|Max
operator|>>
literal|1
operator|)
condition|)
block|{
name|Overflowed
operator|=
name|true
expr_stmt|;
return|return
name|Max
return|;
block|}
end_if

begin_expr_stmt
name|Z
operator|<<=
literal|1
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|X
operator|&
literal|1
condition|)
return|return
name|SaturatingAdd
argument_list|(
name|Z
argument_list|,
name|Y
argument_list|,
name|ResultOverflowed
argument_list|)
return|;
end_if

begin_return
return|return
name|Z
return|;
end_return

begin_comment
unit|}
comment|/// Multiply two unsigned integers, X and Y, and add the unsigned integer, A to
end_comment

begin_comment
comment|/// the product. Clamp the result to the maximum representable value of T on
end_comment

begin_comment
comment|/// overflow. ResultOverflowed indicates if the result is larger than the
end_comment

begin_comment
comment|/// maximum representable value of type T.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_unsigned
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|T
operator|>
operator|::
name|type
name|SaturatingMultiplyAdd
argument_list|(
argument|T X
argument_list|,
argument|T Y
argument_list|,
argument|T A
argument_list|,
argument|bool *ResultOverflowed = nullptr
argument_list|)
block|{
name|bool
name|Dummy
block|;
name|bool
operator|&
name|Overflowed
operator|=
name|ResultOverflowed
condition|?
operator|*
name|ResultOverflowed
else|:
name|Dummy
block|;
name|T
name|Product
operator|=
name|SaturatingMultiply
argument_list|(
name|X
argument_list|,
name|Y
argument_list|,
operator|&
name|Overflowed
argument_list|)
block|;
if|if
condition|(
name|Overflowed
condition|)
return|return
name|Product
return|;
end_expr_stmt

begin_return
return|return
name|SaturatingAdd
argument_list|(
name|A
argument_list|,
name|Product
argument_list|,
operator|&
name|Overflowed
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Use this rather than HUGE_VALF; the latter causes warnings on MSVC.
end_comment

begin_decl_stmt
unit|extern
specifier|const
name|float
name|huge_valf
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

