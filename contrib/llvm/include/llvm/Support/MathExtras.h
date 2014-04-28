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
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<cstring>
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

begin_include
include|#
directive|include
file|<limits>
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
comment|/// \brief Count number of 0's from the least significant bit to the most
comment|///   stopping at the first 1.
comment|///
comment|/// Only unsigned integral types are allowed.
comment|///
comment|/// \param ZB the behavior on an input of 0. Only ZB_Width and ZB_Undefined are
comment|///   valid arguments.
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
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
operator|,
name|std
operator|::
name|size_t
operator|>
operator|::
name|type
name|countTrailingZeros
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
block|{
operator|(
name|void
operator|)
name|ZB
block|;
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
end_decl_stmt

begin_comment
comment|// Disable signed.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
operator|,
name|std
operator|::
name|size_t
operator|>
operator|::
name|type
name|countTrailingZeros
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|4
operator|||
name|_MSC_VER
end_if

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|std
operator|::
name|size_t
name|countTrailingZeros
operator|<
name|uint32_t
operator|>
operator|(
name|uint32_t
name|Val
operator|,
name|ZeroBehavior
name|ZB
operator|)
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
end_expr_stmt

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_ctz
argument_list|)
operator|||
name|__GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_return
return|return
name|__builtin_ctz
argument_list|(
name|Val
argument_list|)
return|;
end_return

begin_elif
elif|#
directive|elif
name|_MSC_VER
end_elif

begin_decl_stmt
name|unsigned
name|long
name|Index
decl_stmt|;
end_decl_stmt

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

begin_if
unit|}
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
unit|template
operator|<
operator|>
specifier|inline
name|std
operator|::
name|size_t
name|countTrailingZeros
operator|<
name|uint64_t
operator|>
operator|(
name|uint64_t
name|Val
operator|,
name|ZeroBehavior
name|ZB
operator|)
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
end_expr_stmt

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_ctzll
argument_list|)
operator|||
name|__GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_return
return|return
name|__builtin_ctzll
argument_list|(
name|Val
argument_list|)
return|;
end_return

begin_elif
elif|#
directive|elif
name|_MSC_VER
end_elif

begin_decl_stmt
name|unsigned
name|long
name|Index
decl_stmt|;
end_decl_stmt

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

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|typename
name|enable_if_c
operator|<
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
operator|,
name|std
operator|::
name|size_t
operator|>
operator|::
name|type
name|countLeadingZeros
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
block|{
operator|(
name|void
operator|)
name|ZB
block|;
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
expr_stmt|;
end_expr_stmt

begin_for
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
end_for

begin_return
return|return
name|ZeroBits
return|;
end_return

begin_comment
unit|}
comment|// Disable signed.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
operator|,
name|std
operator|::
name|size_t
operator|>
operator|::
name|type
name|countLeadingZeros
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Width
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|4
operator|||
name|_MSC_VER
end_if

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|std
operator|::
name|size_t
name|countLeadingZeros
operator|<
name|uint32_t
operator|>
operator|(
name|uint32_t
name|Val
operator|,
name|ZeroBehavior
name|ZB
operator|)
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
end_expr_stmt

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_clz
argument_list|)
operator|||
name|__GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_return
return|return
name|__builtin_clz
argument_list|(
name|Val
argument_list|)
return|;
end_return

begin_elif
elif|#
directive|elif
name|_MSC_VER
end_elif

begin_decl_stmt
name|unsigned
name|long
name|Index
decl_stmt|;
end_decl_stmt

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

begin_if
unit|}
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
unit|template
operator|<
operator|>
specifier|inline
name|std
operator|::
name|size_t
name|countLeadingZeros
operator|<
name|uint64_t
operator|>
operator|(
name|uint64_t
name|Val
operator|,
name|ZeroBehavior
name|ZB
operator|)
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
end_expr_stmt

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_clzll
argument_list|)
operator|||
name|__GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_return
return|return
name|__builtin_clzll
argument_list|(
name|Val
argument_list|)
return|;
end_return

begin_elif
elif|#
directive|elif
name|_MSC_VER
end_elif

begin_decl_stmt
name|unsigned
name|long
name|Index
decl_stmt|;
end_decl_stmt

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

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
unit|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
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
operator|,
name|T
operator|>
operator|::
name|type
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
comment|// Disable signed.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
operator|,
name|T
operator|>
operator|::
name|type
name|findFirstSet
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Max
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
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
name|typename
name|enable_if_c
operator|<
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
operator|,
name|T
operator|>
operator|::
name|type
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
comment|// Disable signed.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
operator|&&
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
operator|,
name|T
operator|>
operator|::
name|type
name|findLastSet
argument_list|(
argument|T Val
argument_list|,
argument|ZeroBehavior ZB = ZB_Max
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Macro compressed bit reversal table for 256 bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// http://graphics.stanford.edu/~seander/bithacks.html#BitReverseTable
end_comment

begin_decl_stmt
specifier|static
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
comment|/// Hi_32 - This function returns the high 32 bits of a 64 bit value.
end_comment

begin_function
unit|inline
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
comment|/// Lo_32 - This function returns the low 32 bits of a 64 bit value.
end_comment

begin_function
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
comment|/// isInt - Checks if an integer fits into the given bit width.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
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
comment|/// isShiftedInt<N,S> - Checks if a signed integer is an N bit number shifted
end_comment

begin_comment
comment|///                     left by S.
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
specifier|inline
name|bool
name|isShiftedInt
argument_list|(
argument|int64_t x
argument_list|)
block|{
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
literal|1
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
comment|/// isUInt - Checks if an unsigned integer fits into the given bit width.
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
specifier|inline
name|bool
name|isUInt
argument_list|(
argument|uint64_t x
argument_list|)
block|{
return|return
name|N
operator|>=
literal|64
operator|||
name|x
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

begin_comment
comment|// Template specializations to get better code for common cases.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
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
comment|/// isShiftedUInt<N,S> - Checks if a unsigned integer is an N bit number shifted
end_comment

begin_comment
comment|///                     left by S.
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
specifier|inline
name|bool
name|isShiftedUInt
argument_list|(
argument|uint64_t x
argument_list|)
block|{
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
literal|1
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
comment|/// isUIntN - Checks if an unsigned integer fits into the given (dynamic)
end_comment

begin_comment
comment|/// bit width.
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
name|x
operator|==
operator|(
name|x
operator|&
operator|(
operator|~
literal|0ULL
operator|>>
operator|(
literal|64
operator|-
name|N
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// isIntN - Checks if an signed integer fits into the given (dynamic)
end_comment

begin_comment
comment|/// bit width.
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
end_function

begin_comment
comment|/// isMask_32 - This function returns true if the argument is a sequence of ones
end_comment

begin_comment
comment|/// starting at the least significant bit with the remainder zero (32 bit
end_comment

begin_comment
comment|/// version).   Ex. isMask_32(0x0000FFFFU) == true.
end_comment

begin_function
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
comment|/// isMask_64 - This function returns true if the argument is a sequence of ones
end_comment

begin_comment
comment|/// starting at the least significant bit with the remainder zero (64 bit
end_comment

begin_comment
comment|/// version).
end_comment

begin_function
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
comment|/// isShiftedMask_32 - This function returns true if the argument contains a
end_comment

begin_comment
comment|/// sequence of ones with the remainder zero (32 bit version.)
end_comment

begin_comment
comment|/// Ex. isShiftedMask_32(0x0000FF00U) == true.
end_comment

begin_function
specifier|inline
name|bool
name|isShiftedMask_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
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
comment|/// isShiftedMask_64 - This function returns true if the argument contains a
end_comment

begin_comment
comment|/// sequence of ones with the remainder zero (64 bit version.)
end_comment

begin_function
specifier|inline
name|bool
name|isShiftedMask_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
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
comment|/// isPowerOf2_32 - This function returns true if the argument is a power of
end_comment

begin_comment
comment|/// two> 0. Ex. isPowerOf2_32(0x00100000U) == true (32 bit edition.)
end_comment

begin_function
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
comment|/// isPowerOf2_64 - This function returns true if the argument is a power of two
end_comment

begin_comment
comment|///> 0 (64 bit edition.)
end_comment

begin_function
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
comment|/// ByteSwap_16 - This function returns a byte-swapped representation of the
end_comment

begin_comment
comment|/// 16-bit argument, Value.
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
comment|/// ByteSwap_32 - This function returns a byte-swapped representation of the
end_comment

begin_comment
comment|/// 32-bit argument, Value.
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
comment|/// ByteSwap_64 - This function returns a byte-swapped representation of the
end_comment

begin_comment
comment|/// 64-bit argument, Value.
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
comment|/// CountLeadingOnes_32 - this function performs the operation of
end_comment

begin_comment
comment|/// counting the number of ones from the most significant bit to the first zero
end_comment

begin_comment
comment|/// bit.  Ex. CountLeadingOnes_32(0xFF0FFF00) == 8.
end_comment

begin_comment
comment|/// Returns 32 if the word is all ones.
end_comment

begin_function
specifier|inline
name|unsigned
name|CountLeadingOnes_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
name|countLeadingZeros
argument_list|(
operator|~
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// CountLeadingOnes_64 - This function performs the operation
end_comment

begin_comment
comment|/// of counting the number of ones from the most significant bit to the first
end_comment

begin_comment
comment|/// zero bit (64 bit edition.)
end_comment

begin_comment
comment|/// Returns 64 if the word is all ones.
end_comment

begin_function
specifier|inline
name|unsigned
name|CountLeadingOnes_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|countLeadingZeros
argument_list|(
operator|~
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// CountTrailingOnes_32 - this function performs the operation of
end_comment

begin_comment
comment|/// counting the number of ones from the least significant bit to the first zero
end_comment

begin_comment
comment|/// bit.  Ex. CountTrailingOnes_32(0x00FF00FF) == 8.
end_comment

begin_comment
comment|/// Returns 32 if the word is all ones.
end_comment

begin_function
specifier|inline
name|unsigned
name|CountTrailingOnes_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
return|return
name|countTrailingZeros
argument_list|(
operator|~
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// CountTrailingOnes_64 - This function performs the operation
end_comment

begin_comment
comment|/// of counting the number of ones from the least significant bit to the first
end_comment

begin_comment
comment|/// zero bit (64 bit edition.)
end_comment

begin_comment
comment|/// Returns 64 if the word is all ones.
end_comment

begin_function
specifier|inline
name|unsigned
name|CountTrailingOnes_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
name|countTrailingZeros
argument_list|(
operator|~
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// CountPopulation_32 - this function counts the number of set bits in a value.
end_comment

begin_comment
comment|/// Ex. CountPopulation(0xF000F000) = 8
end_comment

begin_comment
comment|/// Returns 0 if the word is zero.
end_comment

begin_function
specifier|inline
name|unsigned
name|CountPopulation_32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
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
init|=
name|Value
operator|-
operator|(
operator|(
name|Value
operator|>>
literal|1
operator|)
operator|&
literal|0x55555555
operator|)
decl_stmt|;
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
expr_stmt|;
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
end_function

begin_comment
comment|/// CountPopulation_64 - this function counts the number of set bits in a value,
end_comment

begin_comment
comment|/// (64 bit edition.)
end_comment

begin_function
specifier|inline
name|unsigned
name|CountPopulation_64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
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
init|=
name|Value
operator|-
operator|(
operator|(
name|Value
operator|>>
literal|1
operator|)
operator|&
literal|0x5555555555555555ULL
operator|)
decl_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
end_function

begin_comment
comment|/// Log2_32 - This function returns the floor log base 2 of the specified value,
end_comment

begin_comment
comment|/// -1 if the value is zero. (32 bit edition.)
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
comment|/// Log2_64 - This function returns the floor log base 2 of the specified value,
end_comment

begin_comment
comment|/// -1 if the value is zero. (64 bit edition.)
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
comment|/// Log2_32_Ceil - This function returns the ceil log base 2 of the specified
end_comment

begin_comment
comment|/// value, 32 if the value is zero. (32 bit edition).
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
comment|/// Log2_64_Ceil - This function returns the ceil log base 2 of the specified
end_comment

begin_comment
comment|/// value, 64 if the value is zero. (64 bit edition.)
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
comment|/// GreatestCommonDivisor64 - Return the greatest common divisor of the two
end_comment

begin_comment
comment|/// values using Euclid's algorithm.
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
comment|/// BitsToDouble - This function takes a 64-bit integer and returns the bit
end_comment

begin_comment
comment|/// equivalent double.
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
union|union
block|{
name|uint64_t
name|L
decl_stmt|;
name|double
name|D
decl_stmt|;
block|}
name|T
union|;
name|T
operator|.
name|L
operator|=
name|Bits
expr_stmt|;
return|return
name|T
operator|.
name|D
return|;
block|}
end_function

begin_comment
comment|/// BitsToFloat - This function takes a 32-bit integer and returns the bit
end_comment

begin_comment
comment|/// equivalent float.
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
union|union
block|{
name|uint32_t
name|I
decl_stmt|;
name|float
name|F
decl_stmt|;
block|}
name|T
union|;
name|T
operator|.
name|I
operator|=
name|Bits
expr_stmt|;
return|return
name|T
operator|.
name|F
return|;
block|}
end_function

begin_comment
comment|/// DoubleToBits - This function takes a double and returns the bit
end_comment

begin_comment
comment|/// equivalent 64-bit integer.  Note that copying doubles around
end_comment

begin_comment
comment|/// changes the bits of NaNs on some hosts, notably x86, so this
end_comment

begin_comment
comment|/// routine cannot be used if these bits are needed.
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
union|union
block|{
name|uint64_t
name|L
decl_stmt|;
name|double
name|D
decl_stmt|;
block|}
name|T
union|;
name|T
operator|.
name|D
operator|=
name|Double
expr_stmt|;
return|return
name|T
operator|.
name|L
return|;
block|}
end_function

begin_comment
comment|/// FloatToBits - This function takes a float and returns the bit
end_comment

begin_comment
comment|/// equivalent 32-bit integer.  Note that copying floats around
end_comment

begin_comment
comment|/// changes the bits of NaNs on some hosts, notably x86, so this
end_comment

begin_comment
comment|/// routine cannot be used if these bits are needed.
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
union|union
block|{
name|uint32_t
name|I
decl_stmt|;
name|float
name|F
decl_stmt|;
block|}
name|T
union|;
name|T
operator|.
name|F
operator|=
name|Float
expr_stmt|;
return|return
name|T
operator|.
name|I
return|;
block|}
end_function

begin_comment
comment|/// Platform-independent wrappers for the C99 isnan() function.
end_comment

begin_function_decl
name|int
name|IsNAN
parameter_list|(
name|float
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|IsNAN
parameter_list|(
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Platform-independent wrappers for the C99 isinf() function.
end_comment

begin_function_decl
name|int
name|IsInf
parameter_list|(
name|float
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|IsInf
parameter_list|(
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// MinAlign - A and B are either alignments or offsets.  Return the minimum
end_comment

begin_comment
comment|/// alignment that may be assumed after adding the two together.
end_comment

begin_function
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
comment|/// NextPowerOf2 - Returns the next power of two (in 64-bits)
end_comment

begin_comment
comment|/// that is strictly greater than A.  Returns zero on overflow.
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
comment|/// Returns the next integer (mod 2**64) that is greater than or equal to
end_comment

begin_comment
comment|/// \p Value and is a multiple of \p Align. \p Align must be non-zero.
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
comment|///   RoundUpToAlignment(5, 8) = 8
end_comment

begin_comment
comment|///   RoundUpToAlignment(17, 8) = 24
end_comment

begin_comment
comment|///   RoundUpToAlignment(~0LL, 8) = 0
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_function
specifier|inline
name|uint64_t
name|RoundUpToAlignment
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|uint64_t
name|Align
parameter_list|)
block|{
return|return
operator|(
operator|(
name|Value
operator|+
name|Align
operator|-
literal|1
operator|)
operator|/
name|Align
operator|)
operator|*
name|Align
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
name|RoundUpToAlignment
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
comment|/// abs64 - absolute value of a 64-bit int.  Not all environments support
end_comment

begin_comment
comment|/// "abs" on whatever their name for the 64-bit int type is.  The absolute
end_comment

begin_comment
comment|/// value of the largest negative number is undefined, as with "abs".
end_comment

begin_function
specifier|inline
name|int64_t
name|abs64
parameter_list|(
name|int64_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|<
literal|0
operator|)
condition|?
operator|-
name|x
else|:
name|x
return|;
block|}
end_function

begin_comment
comment|/// SignExtend32 - Sign extend B-bit number x to 32-bit int.
end_comment

begin_comment
comment|/// Usage int32_t r = SignExtend32<5>(x);
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|B
operator|>
specifier|inline
name|int32_t
name|SignExtend32
argument_list|(
argument|uint32_t x
argument_list|)
block|{
return|return
name|int32_t
argument_list|(
name|x
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
comment|/// \brief Sign extend number in the bottom B bits of X to a 32-bit int.
end_comment

begin_comment
comment|/// Requires 0< B<= 32.
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
comment|/// SignExtend64 - Sign extend B-bit number x to 64-bit int.
end_comment

begin_comment
comment|/// Usage int64_t r = SignExtend64<5>(x);
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|B
operator|>
specifier|inline
name|int64_t
name|SignExtend64
argument_list|(
argument|uint64_t x
argument_list|)
block|{
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
comment|/// \brief Sign extend number in the bottom B bits of X to a 64-bit int.
end_comment

begin_comment
comment|/// Requires 0< B<= 64.
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|// Visual Studio defines the HUGE_VAL class of macros using purposeful
end_comment

begin_comment
comment|// constant arithmetic overflow, which it then warns on when encountered.
end_comment

begin_decl_stmt
specifier|const
name|float
name|huge_valf
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|float
operator|>
operator|::
name|infinity
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|const
name|float
name|huge_valf
init|=
name|HUGE_VALF
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

