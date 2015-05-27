begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/ScaledNumber.h - Support for scaled numbers -*- C++ -*-===//
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
comment|// This file contains functions (and a class) useful for working with scaled
end_comment

begin_comment
comment|// numbers -- in particular, pairs of integers where one represents digits and
end_comment

begin_comment
comment|// another represents a scale.  The functions are helpers and live in the
end_comment

begin_comment
comment|// namespace ScaledNumbers.  The class ScaledNumber is useful for modelling
end_comment

begin_comment
comment|// certain cost metrics that need simple, integer-like semantics that are easy
end_comment

begin_comment
comment|// to reason about.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These might remind you of soft-floats.  If you want one of those, you're in
end_comment

begin_comment
comment|// the wrong place.  Look at include/llvm/ADT/APFloat.h instead.
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
name|LLVM_SUPPORT_SCALEDNUMBER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SCALEDNUMBER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ScaledNumbers
block|{
comment|/// \brief Maximum scale; same as APFloat for easy debug printing.
specifier|const
name|int32_t
name|MaxScale
init|=
literal|16383
decl_stmt|;
comment|/// \brief Maximum scale; same as APFloat for easy debug printing.
specifier|const
name|int32_t
name|MinScale
init|=
operator|-
literal|16382
decl_stmt|;
comment|/// \brief Get the width of a number.
name|template
operator|<
name|class
name|DigitsT
operator|>
specifier|inline
name|int
name|getWidth
argument_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|DigitsT
argument_list|)
operator|*
literal|8
return|;
block|}
comment|/// \brief Conditionally round up a scaled number.
comment|///
comment|/// Given \c Digits and \c Scale, round up iff \c ShouldRound is \c true.
comment|/// Always returns \c Scale unless there's an overflow, in which case it
comment|/// returns \c 1+Scale.
comment|///
comment|/// \pre adding 1 to \c Scale will not overflow INT16_MAX.
name|template
operator|<
name|class
name|DigitsT
operator|>
specifier|inline
name|std
operator|::
name|pair
operator|<
name|DigitsT
operator|,
name|int16_t
operator|>
name|getRounded
argument_list|(
argument|DigitsT Digits
argument_list|,
argument|int16_t Scale
argument_list|,
argument|bool ShouldRound
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
if|if
condition|(
name|ShouldRound
condition|)
if|if
condition|(
operator|!
operator|++
name|Digits
condition|)
comment|// Overflow.
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|DigitsT
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
operator|-
literal|1
operator|)
argument_list|,
name|Scale
operator|+
literal|1
argument_list|)
return|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
return|;
block|}
comment|/// \brief Convenience helper for 32-bit rounding.
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|int16_t
operator|>
name|getRounded32
argument_list|(
argument|uint32_t Digits
argument_list|,
argument|int16_t Scale
argument_list|,
argument|bool ShouldRound
argument_list|)
block|{
return|return
name|getRounded
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|ShouldRound
argument_list|)
return|;
block|}
comment|/// \brief Convenience helper for 64-bit rounding.
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|getRounded64
argument_list|(
argument|uint64_t Digits
argument_list|,
argument|int16_t Scale
argument_list|,
argument|bool ShouldRound
argument_list|)
block|{
return|return
name|getRounded
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|ShouldRound
argument_list|)
return|;
block|}
comment|/// \brief Adjust a 64-bit scaled number down to the appropriate width.
comment|///
comment|/// \pre Adding 64 to \c Scale will not overflow INT16_MAX.
name|template
operator|<
name|class
name|DigitsT
operator|>
specifier|inline
name|std
operator|::
name|pair
operator|<
name|DigitsT
operator|,
name|int16_t
operator|>
name|getAdjusted
argument_list|(
argument|uint64_t Digits
argument_list|,
argument|int16_t Scale =
literal|0
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
specifier|const
name|int
name|Width
operator|=
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
block|;
if|if
condition|(
name|Width
operator|==
literal|64
operator|||
name|Digits
operator|<=
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|max
argument_list|()
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
return|;
comment|// Shift right and round.
name|int
name|Shift
operator|=
literal|64
operator|-
name|Width
operator|-
name|countLeadingZeros
argument_list|(
name|Digits
argument_list|)
expr_stmt|;
return|return
name|getRounded
operator|<
name|DigitsT
operator|>
operator|(
name|Digits
operator|>>
name|Shift
operator|,
name|Scale
operator|+
name|Shift
operator|,
name|Digits
operator|&
operator|(
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|Shift
operator|-
literal|1
operator|)
operator|)
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Convenience helper for adjusting to 32 bits.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|int16_t
operator|>
name|getAdjusted32
argument_list|(
argument|uint64_t Digits
argument_list|,
argument|int16_t Scale =
literal|0
argument_list|)
block|{
return|return
name|getAdjusted
operator|<
name|uint32_t
operator|>
operator|(
name|Digits
operator|,
name|Scale
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convenience helper for adjusting to 64 bits.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|getAdjusted64
argument_list|(
argument|uint64_t Digits
argument_list|,
argument|int16_t Scale =
literal|0
argument_list|)
block|{
return|return
name|getAdjusted
operator|<
name|uint64_t
operator|>
operator|(
name|Digits
operator|,
name|Scale
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Multiply two 64-bit integers to create a 64-bit scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implemented with four 64-bit integer multiplies.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|multiply64
argument_list|(
argument|uint64_t LHS
argument_list|,
argument|uint64_t RHS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Multiply two 32-bit integers to create a 32-bit scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implemented with one 64-bit integer multiply.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
specifier|inline
name|std
operator|::
name|pair
operator|<
name|DigitsT
operator|,
name|int16_t
operator|>
name|getProduct
argument_list|(
argument|DigitsT LHS
argument_list|,
argument|DigitsT RHS
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
if|if
condition|(
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
operator|<=
literal|32
operator|||
operator|(
name|LHS
operator|<=
name|UINT32_MAX
operator|&&
name|RHS
operator|<=
name|UINT32_MAX
operator|)
condition|)
return|return
name|getAdjusted
operator|<
name|DigitsT
operator|>
operator|(
name|uint64_t
argument_list|(
name|LHS
argument_list|)
operator|*
name|RHS
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|multiply64
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Convenience helper for 32-bit product.
end_comment

begin_expr_stmt
unit|inline
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|int16_t
operator|>
name|getProduct32
argument_list|(
argument|uint32_t LHS
argument_list|,
argument|uint32_t RHS
argument_list|)
block|{
return|return
name|getProduct
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convenience helper for 64-bit product.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|getProduct64
argument_list|(
argument|uint64_t LHS
argument_list|,
argument|uint64_t RHS
argument_list|)
block|{
return|return
name|getProduct
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Divide two 64-bit integers to create a 64-bit scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implemented with long division.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \c Dividend and \c Divisor are non-zero.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|divide64
argument_list|(
argument|uint64_t Dividend
argument_list|,
argument|uint64_t Divisor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Divide two 32-bit integers to create a 32-bit scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implemented with one 64-bit integer divide/remainder pair.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \c Dividend and \c Divisor are non-zero.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|int16_t
operator|>
name|divide32
argument_list|(
argument|uint32_t Dividend
argument_list|,
argument|uint32_t Divisor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Divide two 32-bit numbers to create a 32-bit scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implemented with one 64-bit integer divide/remainder pair.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns \c (DigitsT_MAX, MaxScale) for divide-by-zero (0 for 0/0).
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|std
operator|::
name|pair
operator|<
name|DigitsT
operator|,
name|int16_t
operator|>
name|getQuotient
argument_list|(
argument|DigitsT Dividend
argument_list|,
argument|DigitsT Divisor
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|DigitsT
argument_list|)
operator|==
literal|4
operator|||
sizeof|sizeof
argument_list|(
name|DigitsT
argument_list|)
operator|==
literal|8
argument_list|,
literal|"expected 32-bit or 64-bit digits"
argument_list|)
block|;
comment|// Check for zero.
if|if
condition|(
operator|!
name|Dividend
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|Divisor
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|max
argument_list|()
argument_list|,
name|MaxScale
argument_list|)
return|;
end_if

begin_if
if|if
condition|(
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
operator|==
literal|64
condition|)
return|return
name|divide64
argument_list|(
name|Dividend
argument_list|,
name|Divisor
argument_list|)
return|;
end_if

begin_return
return|return
name|divide32
argument_list|(
name|Dividend
argument_list|,
name|Divisor
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Convenience helper for 32-bit quotient.
end_comment

begin_expr_stmt
unit|inline
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|int16_t
operator|>
name|getQuotient32
argument_list|(
argument|uint32_t Dividend
argument_list|,
argument|uint32_t Divisor
argument_list|)
block|{
return|return
name|getQuotient
argument_list|(
name|Dividend
argument_list|,
name|Divisor
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convenience helper for 64-bit quotient.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|getQuotient64
argument_list|(
argument|uint64_t Dividend
argument_list|,
argument|uint64_t Divisor
argument_list|)
block|{
return|return
name|getQuotient
argument_list|(
name|Dividend
argument_list|,
name|Divisor
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Implementation of getLg() and friends.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns the rounded lg of \c Digits*2^Scale and an int specifying whether
end_comment

begin_comment
comment|/// this was rounded up (1), down (-1), or exact (0).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns \c INT32_MIN when \c Digits is zero.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
specifier|inline
name|std
operator|::
name|pair
operator|<
name|int32_t
operator|,
name|int
operator|>
name|getLgImpl
argument_list|(
argument|DigitsT Digits
argument_list|,
argument|int16_t Scale
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
if|if
condition|(
operator|!
name|Digits
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|INT32_MIN
argument_list|,
literal|0
argument_list|)
return|;
comment|// Get the floor of the lg of Digits.
name|int32_t
name|LocalFloor
operator|=
sizeof|sizeof
argument_list|(
name|Digits
argument_list|)
operator|*
literal|8
operator|-
name|countLeadingZeros
argument_list|(
name|Digits
argument_list|)
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Get the actual floor.
end_comment

begin_decl_stmt
name|int32_t
name|Floor
init|=
name|Scale
operator|+
name|LocalFloor
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|Digits
operator|==
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|LocalFloor
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Floor
argument_list|,
literal|0
argument_list|)
return|;
end_if

begin_comment
comment|// Round based on the next digit.
end_comment

begin_expr_stmt
name|assert
argument_list|(
name|LocalFloor
operator|>=
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|Round
init|=
name|Digits
operator|&
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|LocalFloor
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Floor
operator|+
name|Round
argument_list|,
name|Round
condition|?
literal|1
else|:
operator|-
literal|1
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Get the lg (rounded) of a scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the lg of \c Digits*2^Scale.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns \c INT32_MIN when \c Digits is zero.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|DigitsT
operator|>
name|int32_t
name|getLg
argument_list|(
argument|DigitsT Digits
argument_list|,
argument|int16_t Scale
argument_list|)
block|{
return|return
name|getLgImpl
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
operator|.
name|first
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the lg floor of a scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the floor of the lg of \c Digits*2^Scale.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns \c INT32_MIN when \c Digits is zero.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|int32_t
name|getLgFloor
argument_list|(
argument|DigitsT Digits
argument_list|,
argument|int16_t Scale
argument_list|)
block|{
name|auto
name|Lg
operator|=
name|getLgImpl
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
block|;
return|return
name|Lg
operator|.
name|first
operator|-
operator|(
name|Lg
operator|.
name|second
operator|>
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the lg ceiling of a scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the ceiling of the lg of \c Digits*2^Scale.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns \c INT32_MIN when \c Digits is zero.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|int32_t
name|getLgCeiling
argument_list|(
argument|DigitsT Digits
argument_list|,
argument|int16_t Scale
argument_list|)
block|{
name|auto
name|Lg
operator|=
name|getLgImpl
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
block|;
return|return
name|Lg
operator|.
name|first
operator|+
operator|(
name|Lg
operator|.
name|second
operator|<
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Implementation for comparing scaled numbers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compare two 64-bit numbers with different scales.  Given that the scale of
end_comment

begin_comment
comment|/// \c L is higher than that of \c R by \c ScaleDiff, compare them.  Return -1,
end_comment

begin_comment
comment|/// 1, and 0 for less than, greater than, and equal, respectively.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre 0<= ScaleDiff< 64.
end_comment

begin_function_decl
name|int
name|compareImpl
parameter_list|(
name|uint64_t
name|L
parameter_list|,
name|uint64_t
name|R
parameter_list|,
name|int
name|ScaleDiff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Compare two scaled numbers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compare two scaled numbers.  Returns 0 for equal, -1 for less than, and 1
end_comment

begin_comment
comment|/// for greater than.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|int
name|compare
argument_list|(
argument|DigitsT LDigits
argument_list|,
argument|int16_t LScale
argument_list|,
argument|DigitsT RDigits
argument_list|,
argument|int16_t RScale
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
comment|// Check for zero.
if|if
condition|(
operator|!
name|LDigits
condition|)
return|return
name|RDigits
condition|?
operator|-
literal|1
else|:
literal|0
return|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|RDigits
condition|)
return|return
literal|1
return|;
end_if

begin_comment
comment|// Check for the scale.  Use getLgFloor to be sure that the scale difference
end_comment

begin_comment
comment|// is always lower than 64.
end_comment

begin_decl_stmt
name|int32_t
name|lgL
init|=
name|getLgFloor
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|)
decl_stmt|,
name|lgR
init|=
name|getLgFloor
argument_list|(
name|RDigits
argument_list|,
name|RScale
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|lgL
operator|!=
name|lgR
condition|)
return|return
name|lgL
operator|<
name|lgR
condition|?
operator|-
literal|1
else|:
literal|1
return|;
end_if

begin_comment
comment|// Compare digits.
end_comment

begin_if
if|if
condition|(
name|LScale
operator|<
name|RScale
condition|)
return|return
name|compareImpl
argument_list|(
name|LDigits
argument_list|,
name|RDigits
argument_list|,
name|RScale
operator|-
name|LScale
argument_list|)
return|;
end_if

begin_return
return|return
operator|-
name|compareImpl
argument_list|(
name|RDigits
argument_list|,
name|LDigits
argument_list|,
name|LScale
operator|-
name|RScale
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Match scales of two numbers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Given two scaled numbers, match up their scales.  Change the digits and
end_comment

begin_comment
comment|/// scales in place.  Shift the digits as necessary to form equivalent numbers,
end_comment

begin_comment
comment|/// losing precision only when necessary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the output value of \c LDigits (\c RDigits) is \c 0, the output value of
end_comment

begin_comment
comment|/// \c LScale (\c RScale) is unspecified.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// As a convenience, returns the matching scale.  If the output value of one
end_comment

begin_comment
comment|/// number is zero, returns the scale of the other.  If both are zero, which
end_comment

begin_comment
comment|/// scale is returned is unspecifed.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|DigitsT
operator|>
name|int16_t
name|matchScales
argument_list|(
argument|DigitsT&LDigits
argument_list|,
argument|int16_t&LScale
argument_list|,
argument|DigitsT&RDigits
argument_list|,
argument|int16_t&RScale
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
if|if
condition|(
name|LScale
operator|<
name|RScale
condition|)
comment|// Swap arguments.
return|return
name|matchScales
argument_list|(
name|RDigits
argument_list|,
name|RScale
argument_list|,
name|LDigits
argument_list|,
name|LScale
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|LDigits
condition|)
return|return
name|RScale
return|;
end_if

begin_if
if|if
condition|(
operator|!
name|RDigits
operator|||
name|LScale
operator|==
name|RScale
condition|)
return|return
name|LScale
return|;
end_if

begin_comment
comment|// Now LScale> RScale.  Get the difference.
end_comment

begin_decl_stmt
name|int32_t
name|ScaleDiff
init|=
name|int32_t
argument_list|(
name|LScale
argument_list|)
operator|-
name|RScale
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|ScaleDiff
operator|>=
literal|2
operator|*
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
condition|)
block|{
comment|// Don't bother shifting.  RDigits will get zero-ed out anyway.
name|RDigits
operator|=
literal|0
expr_stmt|;
return|return
name|LScale
return|;
block|}
end_if

begin_comment
comment|// Shift LDigits left as much as possible, then shift RDigits right.
end_comment

begin_decl_stmt
name|int32_t
name|ShiftL
init|=
name|std
operator|::
name|min
operator|<
name|int32_t
operator|>
operator|(
name|countLeadingZeros
argument_list|(
name|LDigits
argument_list|)
expr|,
name|ScaleDiff
operator|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|assert
argument_list|(
name|ShiftL
operator|<
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
operator|&&
literal|"can't shift more than width"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int32_t
name|ShiftR
init|=
name|ScaleDiff
operator|-
name|ShiftL
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|ShiftR
operator|>=
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
condition|)
block|{
comment|// Don't bother shifting.  RDigits will get zero-ed out anyway.
name|RDigits
operator|=
literal|0
expr_stmt|;
return|return
name|LScale
return|;
block|}
end_if

begin_expr_stmt
name|LDigits
operator|<<=
name|ShiftL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RDigits
operator|>>=
name|ShiftR
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LScale
operator|-=
name|ShiftL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RScale
operator|+=
name|ShiftR
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
name|LScale
operator|==
name|RScale
operator|&&
literal|"scales should match"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|LScale
return|;
end_return

begin_comment
unit|}
comment|/// \brief Get the sum of two scaled numbers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the sum of two scaled numbers with as much precision as possible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre Adding 1 to \c LScale (or \c RScale) will not overflow INT16_MAX.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|DigitsT
operator|>
name|std
operator|::
name|pair
operator|<
name|DigitsT
operator|,
name|int16_t
operator|>
name|getSum
argument_list|(
argument|DigitsT LDigits
argument_list|,
argument|int16_t LScale
argument_list|,
argument|DigitsT RDigits
argument_list|,
argument|int16_t RScale
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
comment|// Check inputs up front.  This is only relevent if addition overflows, but
comment|// testing here should catch more bugs.
name|assert
argument_list|(
name|LScale
operator|<
name|INT16_MAX
operator|&&
literal|"scale too large"
argument_list|)
block|;
name|assert
argument_list|(
name|RScale
operator|<
name|INT16_MAX
operator|&&
literal|"scale too large"
argument_list|)
block|;
comment|// Normalize digits to match scales.
name|int16_t
name|Scale
operator|=
name|matchScales
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|,
name|RDigits
argument_list|,
name|RScale
argument_list|)
block|;
comment|// Compute sum.
name|DigitsT
name|Sum
operator|=
name|LDigits
operator|+
name|RDigits
block|;
if|if
condition|(
name|Sum
operator|>=
name|RDigits
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Sum
argument_list|,
name|Scale
argument_list|)
return|;
comment|// Adjust sum after arithmetic overflow.
name|DigitsT
name|HighBit
operator|=
name|DigitsT
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
operator|-
literal|1
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|HighBit
operator||
name|Sum
operator|>>
literal|1
argument_list|,
name|Scale
operator|+
literal|1
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Convenience helper for 32-bit sum.
end_comment

begin_expr_stmt
unit|inline
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|int16_t
operator|>
name|getSum32
argument_list|(
argument|uint32_t LDigits
argument_list|,
argument|int16_t LScale
argument_list|,
argument|uint32_t RDigits
argument_list|,
argument|int16_t RScale
argument_list|)
block|{
return|return
name|getSum
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|,
name|RDigits
argument_list|,
name|RScale
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convenience helper for 64-bit sum.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|getSum64
argument_list|(
argument|uint64_t LDigits
argument_list|,
argument|int16_t LScale
argument_list|,
argument|uint64_t RDigits
argument_list|,
argument|int16_t RScale
argument_list|)
block|{
return|return
name|getSum
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|,
name|RDigits
argument_list|,
name|RScale
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the difference of two scaled numbers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get LHS minus RHS with as much precision as possible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns \c (0, 0) if the RHS is larger than the LHS.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|std
operator|::
name|pair
operator|<
name|DigitsT
operator|,
name|int16_t
operator|>
name|getDifference
argument_list|(
argument|DigitsT LDigits
argument_list|,
argument|int16_t LScale
argument_list|,
argument|DigitsT RDigits
argument_list|,
argument|int16_t RScale
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"expected unsigned"
argument_list|)
block|;
comment|// Normalize digits to match scales.
specifier|const
name|DigitsT
name|SavedRDigits
operator|=
name|RDigits
block|;
specifier|const
name|int16_t
name|SavedRScale
operator|=
name|RScale
block|;
name|matchScales
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|,
name|RDigits
argument_list|,
name|RScale
argument_list|)
block|;
comment|// Compute difference.
if|if
condition|(
name|LDigits
operator|<=
name|RDigits
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|RDigits
operator|||
operator|!
name|SavedRDigits
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|LDigits
operator|-
name|RDigits
argument_list|,
name|LScale
argument_list|)
return|;
end_if

begin_comment
comment|// Check if RDigits just barely lost its last bit.  E.g., for 32-bit:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   1*2^32 - 1*2^0 == 0xffffffff != 1*2^32
end_comment

begin_decl_stmt
specifier|const
specifier|auto
name|RLgFloor
init|=
name|getLgFloor
argument_list|(
name|SavedRDigits
argument_list|,
name|SavedRScale
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|!
name|compare
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|,
name|DigitsT
argument_list|(
literal|1
argument_list|)
argument_list|,
name|RLgFloor
operator|+
name|getWidth
operator|<
name|DigitsT
operator|>
operator|(
operator|)
argument_list|)
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|max
argument_list|()
argument_list|,
name|RLgFloor
argument_list|)
return|;
end_if

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Convenience helper for 32-bit difference.
end_comment

begin_expr_stmt
unit|inline
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|int16_t
operator|>
name|getDifference32
argument_list|(
argument|uint32_t LDigits
argument_list|,
argument|int16_t LScale
argument_list|,
argument|uint32_t RDigits
argument_list|,
argument|int16_t RScale
argument_list|)
block|{
return|return
name|getDifference
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|,
name|RDigits
argument_list|,
name|RScale
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convenience helper for 64-bit difference.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|int16_t
operator|>
name|getDifference64
argument_list|(
argument|uint64_t LDigits
argument_list|,
argument|int16_t LScale
argument_list|,
argument|uint64_t RDigits
argument_list|,
argument|int16_t RScale
argument_list|)
block|{
return|return
name|getDifference
argument_list|(
name|LDigits
argument_list|,
name|LScale
argument_list|,
name|RDigits
argument_list|,
name|RScale
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace ScaledNumbers
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|ScaledNumberBase
block|{
name|public
label|:
specifier|static
specifier|const
name|int
name|DefaultPrecision
init|=
literal|10
decl_stmt|;
specifier|static
name|void
name|dump
parameter_list|(
name|uint64_t
name|D
parameter_list|,
name|int16_t
name|E
parameter_list|,
name|int
name|Width
parameter_list|)
function_decl|;
specifier|static
name|raw_ostream
modifier|&
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|uint64_t
name|D
parameter_list|,
name|int16_t
name|E
parameter_list|,
name|int
name|Width
parameter_list|,
name|unsigned
name|Precision
parameter_list|)
function_decl|;
specifier|static
name|std
operator|::
name|string
name|toString
argument_list|(
argument|uint64_t D
argument_list|,
argument|int16_t E
argument_list|,
argument|int Width
argument_list|,
argument|unsigned Precision
argument_list|)
expr_stmt|;
specifier|static
name|int
name|countLeadingZeros32
parameter_list|(
name|uint32_t
name|N
parameter_list|)
block|{
return|return
name|countLeadingZeros
argument_list|(
name|N
argument_list|)
return|;
block|}
specifier|static
name|int
name|countLeadingZeros64
parameter_list|(
name|uint64_t
name|N
parameter_list|)
block|{
return|return
name|countLeadingZeros
argument_list|(
name|N
argument_list|)
return|;
block|}
specifier|static
name|uint64_t
name|getHalf
parameter_list|(
name|uint64_t
name|N
parameter_list|)
block|{
return|return
operator|(
name|N
operator|>>
literal|1
operator|)
operator|+
operator|(
name|N
operator|&
literal|1
operator|)
return|;
block|}
specifier|static
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|bool
operator|>
name|splitSigned
argument_list|(
argument|int64_t N
argument_list|)
block|{
if|if
condition|(
name|N
operator|>=
literal|0
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|N
argument_list|,
name|false
argument_list|)
return|;
name|uint64_t
name|Unsigned
operator|=
name|N
operator|==
name|INT64_MIN
condition|?
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|63
else|:
name|uint64_t
argument_list|(
operator|-
name|N
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Unsigned
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|int64_t
name|joinSigned
parameter_list|(
name|uint64_t
name|U
parameter_list|,
name|bool
name|IsNeg
parameter_list|)
block|{
if|if
condition|(
name|U
operator|>
name|uint64_t
argument_list|(
name|INT64_MAX
argument_list|)
condition|)
return|return
name|IsNeg
condition|?
name|INT64_MIN
else|:
name|INT64_MAX
return|;
return|return
name|IsNeg
condition|?
operator|-
name|int64_t
argument_list|(
name|U
argument_list|)
else|:
name|int64_t
argument_list|(
name|U
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Simple representation of a scaled number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ScaledNumber is a number represented by digits and a scale.  It uses simple
end_comment

begin_comment
comment|/// saturation arithmetic and every operation is well-defined for every value.
end_comment

begin_comment
comment|/// It's somewhat similar in behaviour to a soft-float, but is *not* a
end_comment

begin_comment
comment|/// replacement for one.  If you're doing numerics, look at \a APFloat instead.
end_comment

begin_comment
comment|/// Nevertheless, we've found these semantics useful for modelling certain cost
end_comment

begin_comment
comment|/// metrics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The number is split into a signed scale and unsigned digits.  The number
end_comment

begin_comment
comment|/// represented is \c getDigits()*2^getScale().  In this way, the digits are
end_comment

begin_comment
comment|/// much like the mantissa in the x87 long double, but there is no canonical
end_comment

begin_comment
comment|/// form so the same number can be represented by many bit representations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ScaledNumber is templated on the underlying integer type for digits, which
end_comment

begin_comment
comment|/// is expected to be unsigned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Unlike APFloat, ScaledNumber does not model architecture floating point
end_comment

begin_comment
comment|/// behaviour -- while this might make it a little faster and easier to reason
end_comment

begin_comment
comment|/// about, it certainly makes it more dangerous for general numerics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ScaledNumber is totally ordered.  However, there is no canonical form, so
end_comment

begin_comment
comment|/// there are multiple representations of most scalars.  E.g.:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     ScaledNumber(8u, 0) == ScaledNumber(4u, 1)
end_comment

begin_comment
comment|///     ScaledNumber(4u, 1) == ScaledNumber(2u, 2)
end_comment

begin_comment
comment|///     ScaledNumber(2u, 2) == ScaledNumber(1u, 3)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ScaledNumber implements most arithmetic operations.  Precision is kept
end_comment

begin_comment
comment|/// where possible.  Uses simple saturation arithmetic, so that operations
end_comment

begin_comment
comment|/// saturate to 0.0 or getLargest() rather than under or overflowing.  It has
end_comment

begin_comment
comment|/// some extra arithmetic for unit inversion.  0.0/0.0 is defined to be 0.0.
end_comment

begin_comment
comment|/// Any other division by 0.0 is defined to be getLargest().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// As a convenience for modifying the exponent, left and right shifting are
end_comment

begin_comment
comment|/// both implemented, and both interpret negative shifts as positive shifts in
end_comment

begin_comment
comment|/// the opposite direction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Scales are limited to the range accepted by x87 long double.  This makes
end_comment

begin_comment
comment|/// it trivial to add functionality to convert to APFloat (this is already
end_comment

begin_comment
comment|/// relied on for the implementation of printing).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Possible (and conflicting) future directions:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  1. Turn this into a wrapper around \a APFloat.
end_comment

begin_comment
comment|///  2. Share the algorithm implementations with \a APFloat.
end_comment

begin_comment
comment|///  3. Allow \a ScaledNumber to represent a signed number.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|class
name|ScaledNumber
operator|:
name|ScaledNumberBase
block|{
name|public
operator|:
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsT
operator|>
operator|::
name|is_signed
argument_list|,
literal|"only unsigned floats supported"
argument_list|)
block|;
typedef|typedef
name|DigitsT
name|DigitsType
typedef|;
name|private
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|numeric_limits
operator|<
name|DigitsType
operator|>
name|DigitsLimits
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|int
name|Width
init|=
sizeof|sizeof
argument_list|(
name|DigitsType
argument_list|)
operator|*
literal|8
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|static_assert
argument_list|(
name|Width
operator|<=
literal|64
argument_list|,
literal|"invalid integer width for digits"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|DigitsType
name|Digits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int16_t
name|Scale
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|ScaledNumber
argument_list|()
operator|:
name|Digits
argument_list|(
literal|0
argument_list|)
operator|,
name|Scale
argument_list|(
literal|0
argument_list|)
block|{}
name|ScaledNumber
argument_list|(
argument|DigitsType Digits
argument_list|,
argument|int16_t Scale
argument_list|)
operator|:
name|Digits
argument_list|(
name|Digits
argument_list|)
operator|,
name|Scale
argument_list|(
argument|Scale
argument_list|)
block|{}
name|private
operator|:
name|ScaledNumber
argument_list|(
specifier|const
name|std
operator|::
name|pair
operator|<
name|uint64_t
argument_list|,
name|int16_t
operator|>
operator|&
name|X
argument_list|)
operator|:
name|Digits
argument_list|(
name|X
operator|.
name|first
argument_list|)
operator|,
name|Scale
argument_list|(
argument|X.second
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ScaledNumber
name|getZero
argument_list|()
block|{
return|return
name|ScaledNumber
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|ScaledNumber
name|getOne
parameter_list|()
block|{
return|return
name|ScaledNumber
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ScaledNumber
name|getLargest
parameter_list|()
block|{
return|return
name|ScaledNumber
argument_list|(
name|DigitsLimits
operator|::
name|max
argument_list|()
argument_list|,
name|ScaledNumbers
operator|::
name|MaxScale
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ScaledNumber
name|get
parameter_list|(
name|uint64_t
name|N
parameter_list|)
block|{
return|return
name|adjustToWidth
argument_list|(
name|N
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ScaledNumber
name|getInverse
parameter_list|(
name|uint64_t
name|N
parameter_list|)
block|{
return|return
name|get
argument_list|(
name|N
argument_list|)
operator|.
name|invert
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|ScaledNumber
name|getFraction
parameter_list|(
name|DigitsType
name|N
parameter_list|,
name|DigitsType
name|D
parameter_list|)
block|{
return|return
name|getQuotient
argument_list|(
name|N
argument_list|,
name|D
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|int16_t
name|getScale
argument_list|()
specifier|const
block|{
return|return
name|Scale
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DigitsType
name|getDigits
argument_list|()
specifier|const
block|{
return|return
name|Digits
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convert to the given integer type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Convert to \c IntT using simple saturating arithmetic, truncating if
end_comment

begin_comment
comment|/// necessary.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|IntT
operator|>
name|IntT
name|toInt
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isZero
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Digits
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isLargest
argument_list|()
specifier|const
block|{
return|return
operator|*
name|this
operator|==
name|getLargest
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isOne
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Scale
operator|>
literal|0
operator|||
name|Scale
operator|<=
operator|-
name|Width
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_return
return|return
name|Digits
operator|==
name|DigitsType
argument_list|(
literal|1
argument_list|)
operator|<<
operator|-
name|Scale
return|;
end_return

begin_comment
unit|}
comment|/// \brief The log base 2, rounded.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the lg of the scalar.  lg 0 is defined to be INT32_MIN.
end_comment

begin_macro
unit|int32_t
name|lg
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|ScaledNumbers
operator|::
name|getLg
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief The log base 2, rounded towards INT32_MIN.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the lg floor.  lg 0 is defined to be INT32_MIN.
end_comment

begin_expr_stmt
name|int32_t
name|lgFloor
argument_list|()
specifier|const
block|{
return|return
name|ScaledNumbers
operator|::
name|getLgFloor
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief The log base 2, rounded towards INT32_MAX.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the lg ceiling.  lg 0 is defined to be INT32_MIN.
end_comment

begin_expr_stmt
name|int32_t
name|lgCeiling
argument_list|()
specifier|const
block|{
return|return
name|ScaledNumbers
operator|::
name|getLgCeiling
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|X
argument_list|)
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|X
argument_list|)
operator|<
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|X
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|>
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|X
argument_list|)
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|X
argument_list|)
operator|<=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|X
argument_list|)
operator|>=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|isZero
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convert to a decimal representation in a string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Convert to a string.  Uses scientific notation for very large/small
end_comment

begin_comment
comment|/// numbers.  Scientific notation is used roughly for numbers outside of the
end_comment

begin_comment
comment|/// range 2^-64 through 2^64.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \c Precision indicates the number of decimal digits of precision to use;
end_comment

begin_comment
comment|/// 0 requests the maximum available.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// As a special case to make debugging easier, if the number is small enough
end_comment

begin_comment
comment|/// to convert without scientific notation and has more than \c Precision
end_comment

begin_comment
comment|/// digits before the decimal place, it's printed accurately to the first
end_comment

begin_comment
comment|/// digit past zero.  E.g., assuming 10 digits of precision:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     98765432198.7654... => 98765432198.8
end_comment

begin_comment
comment|///      8765432198.7654... =>  8765432198.8
end_comment

begin_comment
comment|///       765432198.7654... =>   765432198.8
end_comment

begin_comment
comment|///        65432198.7654... =>    65432198.77
end_comment

begin_comment
comment|///         5432198.7654... =>     5432198.765
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|toString
argument_list|(
argument|unsigned Precision = DefaultPrecision
argument_list|)
block|{
return|return
name|ScaledNumberBase
operator|::
name|toString
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|Width
argument_list|,
name|Precision
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Print a decimal representation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Print a string.  See toString for documentation.
end_comment

begin_decl_stmt
name|raw_ostream
modifier|&
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|Precision
operator|=
name|DefaultPrecision
argument_list|)
decl|const
block|{
return|return
name|ScaledNumberBase
operator|::
name|print
argument_list|(
name|OS
argument_list|,
name|Digits
argument_list|,
name|Scale
argument_list|,
name|Width
argument_list|,
name|Precision
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
block|{
return|return
name|ScaledNumberBase
operator|::
name|dump
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|Width
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ScaledNumber
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
block|{
name|std
operator|::
name|tie
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
operator|=
name|ScaledNumbers
operator|::
name|getSum
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|X
operator|.
name|Digits
argument_list|,
name|X
operator|.
name|Scale
argument_list|)
block|;
comment|// Check for exponent past MaxScale.
if|if
condition|(
name|Scale
operator|>
name|ScaledNumbers
operator|::
name|MaxScale
condition|)
operator|*
name|this
operator|=
name|getLargest
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}   ScaledNumber
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
block|{
name|std
operator|::
name|tie
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|)
operator|=
name|ScaledNumbers
operator|::
name|getDifference
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|X
operator|.
name|Digits
argument_list|,
name|X
operator|.
name|Scale
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ScaledNumber
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ScaledNumber
operator|&
name|operator
operator|/=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ScaledNumber
operator|&
name|operator
operator|<<=
operator|(
name|int16_t
name|Shift
operator|)
block|{
name|shiftLeft
argument_list|(
name|Shift
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ScaledNumber
operator|&
name|operator
operator|>>=
operator|(
name|int16_t
name|Shift
operator|)
block|{
name|shiftRight
argument_list|(
name|Shift
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|shiftLeft
parameter_list|(
name|int32_t
name|Shift
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|shiftRight
parameter_list|(
name|int32_t
name|Shift
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Adjust two floats to have matching exponents.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Adjust \c this and \c X to have matching exponents.  Returns the new \c X
end_comment

begin_comment
comment|/// by value.  Does nothing if \a isZero() for either.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The value that compares smaller will lose precision, and possibly become
end_comment

begin_comment
comment|/// \a isZero().
end_comment

begin_function
name|ScaledNumber
name|matchScales
parameter_list|(
name|ScaledNumber
name|X
parameter_list|)
block|{
name|ScaledNumbers
operator|::
name|matchScales
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|X
operator|.
name|Digits
argument_list|,
name|X
operator|.
name|Scale
argument_list|)
expr_stmt|;
return|return
name|X
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Scale a large number accurately.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Scale N (multiply it by this).  Uses full precision multiplication, even
end_comment

begin_comment
comment|/// if Width is smaller than 64, so information is not lost.
end_comment

begin_decl_stmt
name|uint64_t
name|scale
argument_list|(
name|uint64_t
name|N
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|scaleByInverse
argument_list|(
name|uint64_t
name|N
argument_list|)
decl|const
block|{
comment|// TODO: implement directly, rather than relying on inverse.  Inverse is
comment|// expensive.
return|return
name|inverse
argument_list|()
operator|.
name|scale
argument_list|(
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int64_t
name|scale
argument_list|(
name|int64_t
name|N
argument_list|)
decl|const
block|{
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|bool
operator|>
name|Unsigned
operator|=
name|splitSigned
argument_list|(
name|N
argument_list|)
expr_stmt|;
return|return
name|joinSigned
argument_list|(
name|scale
argument_list|(
name|Unsigned
operator|.
name|first
argument_list|)
argument_list|,
name|Unsigned
operator|.
name|second
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int64_t
name|scaleByInverse
argument_list|(
name|int64_t
name|N
argument_list|)
decl|const
block|{
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|bool
operator|>
name|Unsigned
operator|=
name|splitSigned
argument_list|(
name|N
argument_list|)
expr_stmt|;
return|return
name|joinSigned
argument_list|(
name|scaleByInverse
argument_list|(
name|Unsigned
operator|.
name|first
argument_list|)
argument_list|,
name|Unsigned
operator|.
name|second
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|compare
argument_list|(
specifier|const
name|ScaledNumber
operator|&
name|X
argument_list|)
decl|const
block|{
return|return
name|ScaledNumbers
operator|::
name|compare
argument_list|(
name|Digits
argument_list|,
name|Scale
argument_list|,
name|X
operator|.
name|Digits
argument_list|,
name|X
operator|.
name|Scale
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|compareTo
argument_list|(
name|uint64_t
name|N
argument_list|)
decl|const
block|{
name|ScaledNumber
name|Scaled
init|=
name|get
argument_list|(
name|N
argument_list|)
decl_stmt|;
name|int
name|Compare
init|=
name|compare
argument_list|(
name|Scaled
argument_list|)
decl_stmt|;
if|if
condition|(
name|Width
operator|==
literal|64
operator|||
name|Compare
operator|!=
literal|0
condition|)
return|return
name|Compare
return|;
comment|// Check for precision loss.  We know *this == RoundTrip.
name|uint64_t
name|RoundTrip
init|=
name|Scaled
operator|.
name|template
name|toInt
operator|<
name|uint64_t
operator|>
operator|(
operator|)
decl_stmt|;
return|return
name|N
operator|==
name|RoundTrip
condition|?
literal|0
else|:
name|RoundTrip
operator|<
name|N
condition|?
operator|-
literal|1
else|:
literal|1
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|compareTo
argument_list|(
name|int64_t
name|N
argument_list|)
decl|const
block|{
return|return
name|N
operator|<
literal|0
condition|?
literal|1
else|:
name|compareTo
argument_list|(
name|uint64_t
argument_list|(
name|N
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|ScaledNumber
modifier|&
name|invert
parameter_list|()
block|{
return|return
operator|*
name|this
operator|=
name|ScaledNumber
operator|::
name|get
argument_list|(
literal|1
argument_list|)
operator|/
operator|*
name|this
return|;
block|}
end_function

begin_expr_stmt
name|ScaledNumber
name|inverse
argument_list|()
specifier|const
block|{
return|return
name|ScaledNumber
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|invert
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function
specifier|static
name|ScaledNumber
name|getProduct
parameter_list|(
name|DigitsType
name|LHS
parameter_list|,
name|DigitsType
name|RHS
parameter_list|)
block|{
return|return
name|ScaledNumbers
operator|::
name|getProduct
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ScaledNumber
name|getQuotient
parameter_list|(
name|DigitsType
name|Dividend
parameter_list|,
name|DigitsType
name|Divisor
parameter_list|)
block|{
return|return
name|ScaledNumbers
operator|::
name|getQuotient
argument_list|(
name|Dividend
argument_list|,
name|Divisor
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|countLeadingZerosWidth
parameter_list|(
name|DigitsType
name|Digits
parameter_list|)
block|{
if|if
condition|(
name|Width
operator|==
literal|64
condition|)
return|return
name|countLeadingZeros64
argument_list|(
name|Digits
argument_list|)
return|;
if|if
condition|(
name|Width
operator|==
literal|32
condition|)
return|return
name|countLeadingZeros32
argument_list|(
name|Digits
argument_list|)
return|;
return|return
name|countLeadingZeros32
argument_list|(
name|Digits
argument_list|)
operator|+
name|Width
operator|-
literal|32
return|;
block|}
end_function

begin_comment
comment|/// \brief Adjust a number to width, rounding up if necessary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Should only be called for \c Shift close to zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre Shift>= MinScale&& Shift + 64<= MaxScale.
end_comment

begin_function
specifier|static
name|ScaledNumber
name|adjustToWidth
parameter_list|(
name|uint64_t
name|N
parameter_list|,
name|int32_t
name|Shift
parameter_list|)
block|{
name|assert
argument_list|(
name|Shift
operator|>=
name|ScaledNumbers
operator|::
name|MinScale
operator|&&
literal|"Shift should be close to 0"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Shift
operator|<=
name|ScaledNumbers
operator|::
name|MaxScale
operator|-
literal|64
operator|&&
literal|"Shift should be close to 0"
argument_list|)
expr_stmt|;
name|auto
name|Adjusted
init|=
name|ScaledNumbers
operator|::
name|getAdjusted
operator|<
name|DigitsT
operator|>
operator|(
name|N
expr|,
name|Shift
operator|)
decl_stmt|;
return|return
name|Adjusted
return|;
block|}
end_function

begin_function
specifier|static
name|ScaledNumber
name|getRounded
parameter_list|(
name|ScaledNumber
name|P
parameter_list|,
name|bool
name|Round
parameter_list|)
block|{
comment|// Saturate.
if|if
condition|(
name|P
operator|.
name|isLargest
argument_list|()
condition|)
return|return
name|P
return|;
return|return
name|ScaledNumbers
operator|::
name|getRounded
argument_list|(
name|P
operator|.
name|Digits
argument_list|,
name|P
operator|.
name|Scale
argument_list|,
name|Round
argument_list|)
return|;
block|}
end_function

begin_define
unit|};
define|#
directive|define
name|SCALED_NUMBER_BOP
parameter_list|(
name|op
parameter_list|,
name|base
parameter_list|)
define|\
value|template<class DigitsT>                                                     \   ScaledNumber<DigitsT> operator op(const ScaledNumber<DigitsT>&L,            \                                     const ScaledNumber<DigitsT>&R) {          \     return ScaledNumber<DigitsT>(L) base R;                                    \   }
end_define

begin_macro
name|SCALED_NUMBER_BOP
argument_list|(
argument|+
argument_list|,
argument|+=
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_BOP
argument_list|(
argument|-
argument_list|,
argument|-=
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_BOP
argument_list|(
argument|*
argument_list|,
argument|*=
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_BOP
argument_list|(
argument|/
argument_list|,
argument|/=
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_BOP
argument_list|(
argument|<<
argument_list|,
argument|<<=
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_BOP
argument_list|(
argument|>>
argument_list|,
argument|>>=
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|SCALED_NUMBER_BOP
end_undef

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|&
name|X
operator|)
block|{
return|return
name|X
operator|.
name|print
argument_list|(
name|OS
argument_list|,
literal|10
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|SCALED_NUMBER_COMPARE_TO_TYPE
parameter_list|(
name|op
parameter_list|,
name|T1
parameter_list|,
name|T2
parameter_list|)
define|\
value|template<class DigitsT>                                                     \   bool operator op(const ScaledNumber<DigitsT>&L, T1 R) {                     \     return L.compareTo(T2(R)) op 0;                                            \   }                                                                            \   template<class DigitsT>                                                     \   bool operator op(T1 L, const ScaledNumber<DigitsT>&R) {                     \     return 0 op R.compareTo(T2(L));                                            \   }
end_define

begin_define
define|#
directive|define
name|SCALED_NUMBER_COMPARE_TO
parameter_list|(
name|op
parameter_list|)
define|\
value|SCALED_NUMBER_COMPARE_TO_TYPE(op, uint64_t, uint64_t)                        \   SCALED_NUMBER_COMPARE_TO_TYPE(op, uint32_t, uint64_t)                        \   SCALED_NUMBER_COMPARE_TO_TYPE(op, int64_t, int64_t)                          \   SCALED_NUMBER_COMPARE_TO_TYPE(op, int32_t, int64_t)
end_define

begin_macro
name|SCALED_NUMBER_COMPARE_TO
argument_list|(
argument|<
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_COMPARE_TO
argument_list|(
argument|>
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_COMPARE_TO
argument_list|(
argument|==
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_COMPARE_TO
argument_list|(
argument|!=
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_COMPARE_TO
argument_list|(
argument|<=
argument_list|)
end_macro

begin_macro
name|SCALED_NUMBER_COMPARE_TO
argument_list|(
argument|>=
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|SCALED_NUMBER_COMPARE_TO
end_undef

begin_undef
undef|#
directive|undef
name|SCALED_NUMBER_COMPARE_TO_TYPE
end_undef

begin_expr_stmt
name|template
operator|<
name|class
name|DigitsT
operator|>
name|uint64_t
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|::
name|scale
argument_list|(
argument|uint64_t N
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Width
operator|==
literal|64
operator|||
name|N
operator|<=
name|DigitsLimits
operator|::
name|max
argument_list|()
condition|)
return|return
operator|(
name|get
argument_list|(
name|N
argument_list|)
operator|*
operator|*
name|this
operator|)
operator|.
name|template
name|toInt
operator|<
name|uint64_t
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_comment
comment|// Defer to the 64-bit version.
end_comment

begin_return
return|return
name|ScaledNumber
operator|<
name|uint64_t
operator|>
operator|(
name|Digits
operator|,
name|Scale
operator|)
operator|.
name|scale
argument_list|(
name|N
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|DigitsT
operator|>
name|template
operator|<
name|class
name|IntT
operator|>
name|IntT
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|::
name|toInt
argument_list|()
specifier|const
block|{
typedef|typedef
name|std
operator|::
name|numeric_limits
operator|<
name|IntT
operator|>
name|Limits
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|*
name|this
operator|<
literal|1
condition|)
return|return
literal|0
return|;
end_if

begin_if
if|if
condition|(
operator|*
name|this
operator|>=
name|Limits
operator|::
name|max
argument_list|()
condition|)
return|return
name|Limits
operator|::
name|max
argument_list|()
return|;
end_if

begin_decl_stmt
name|IntT
name|N
init|=
name|Digits
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|Scale
operator|>
literal|0
condition|)
block|{
name|assert
argument_list|(
name|size_t
argument_list|(
name|Scale
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|IntT
argument_list|)
operator|*
literal|8
argument_list|)
expr_stmt|;
return|return
name|N
operator|<<
name|Scale
return|;
block|}
end_if

begin_if
if|if
condition|(
name|Scale
operator|<
literal|0
condition|)
block|{
name|assert
argument_list|(
name|size_t
argument_list|(
operator|-
name|Scale
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|IntT
argument_list|)
operator|*
literal|8
argument_list|)
expr_stmt|;
return|return
name|N
operator|>>
operator|-
name|Scale
return|;
block|}
end_if

begin_return
return|return
name|N
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|DigitsT
operator|>
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|&
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|::
name|operator
operator|*=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
block|{
if|if
condition|(
name|isZero
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|X
operator|.
name|isZero
argument_list|()
condition|)
return|return
operator|*
name|this
operator|=
name|X
return|;
end_if

begin_comment
comment|// Save the exponents.
end_comment

begin_decl_stmt
name|int32_t
name|Scales
init|=
name|int32_t
argument_list|(
name|Scale
argument_list|)
operator|+
name|int32_t
argument_list|(
name|X
operator|.
name|Scale
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Get the raw product.
end_comment

begin_expr_stmt
operator|*
name|this
operator|=
name|getProduct
argument_list|(
name|Digits
argument_list|,
name|X
operator|.
name|Digits
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Combine with exponents.
end_comment

begin_return
return|return
operator|*
name|this
operator|<<=
name|Scales
return|;
end_return

begin_expr_stmt
unit|} template
operator|<
name|class
name|DigitsT
operator|>
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|&
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|::
name|operator
operator|/=
operator|(
specifier|const
name|ScaledNumber
operator|&
name|X
operator|)
block|{
if|if
condition|(
name|isZero
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|X
operator|.
name|isZero
argument_list|()
condition|)
return|return
operator|*
name|this
operator|=
name|getLargest
argument_list|()
return|;
end_if

begin_comment
comment|// Save the exponents.
end_comment

begin_decl_stmt
name|int32_t
name|Scales
init|=
name|int32_t
argument_list|(
name|Scale
argument_list|)
operator|-
name|int32_t
argument_list|(
name|X
operator|.
name|Scale
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Get the raw quotient.
end_comment

begin_expr_stmt
operator|*
name|this
operator|=
name|getQuotient
argument_list|(
name|Digits
argument_list|,
name|X
operator|.
name|Digits
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Combine with exponents.
end_comment

begin_return
return|return
operator|*
name|this
operator|<<=
name|Scales
return|;
end_return

begin_expr_stmt
unit|} template
operator|<
name|class
name|DigitsT
operator|>
name|void
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|::
name|shiftLeft
argument_list|(
argument|int32_t Shift
argument_list|)
block|{
if|if
condition|(
operator|!
name|Shift
operator|||
name|isZero
argument_list|()
condition|)
return|return;
name|assert
argument_list|(
name|Shift
operator|!=
name|INT32_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Shift
operator|<
literal|0
condition|)
block|{
name|shiftRight
argument_list|(
operator|-
name|Shift
argument_list|)
expr_stmt|;
return|return;
block|}
end_if

begin_comment
comment|// Shift as much as we can in the exponent.
end_comment

begin_decl_stmt
name|int32_t
name|ScaleShift
init|=
name|std
operator|::
name|min
argument_list|(
name|Shift
argument_list|,
name|ScaledNumbers
operator|::
name|MaxScale
operator|-
name|Scale
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Scale
operator|+=
name|ScaleShift
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|ScaleShift
operator|==
name|Shift
condition|)
return|return;
end_if

begin_comment
comment|// Check this late, since it's rare.
end_comment

begin_if
if|if
condition|(
name|isLargest
argument_list|()
condition|)
return|return;
end_if

begin_comment
comment|// Shift the digits themselves.
end_comment

begin_expr_stmt
name|Shift
operator|-=
name|ScaleShift
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Shift
operator|>
name|countLeadingZerosWidth
argument_list|(
name|Digits
argument_list|)
condition|)
block|{
comment|// Saturate.
operator|*
name|this
operator|=
name|getLargest
argument_list|()
expr_stmt|;
return|return;
block|}
end_if

begin_expr_stmt
name|Digits
operator|<<=
name|Shift
expr_stmt|;
end_expr_stmt

begin_return
return|return;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|DigitsT
operator|>
name|void
name|ScaledNumber
operator|<
name|DigitsT
operator|>
operator|::
name|shiftRight
argument_list|(
argument|int32_t Shift
argument_list|)
block|{
if|if
condition|(
operator|!
name|Shift
operator|||
name|isZero
argument_list|()
condition|)
return|return;
name|assert
argument_list|(
name|Shift
operator|!=
name|INT32_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Shift
operator|<
literal|0
condition|)
block|{
name|shiftLeft
argument_list|(
operator|-
name|Shift
argument_list|)
expr_stmt|;
return|return;
block|}
end_if

begin_comment
comment|// Shift as much as we can in the exponent.
end_comment

begin_decl_stmt
name|int32_t
name|ScaleShift
init|=
name|std
operator|::
name|min
argument_list|(
name|Shift
argument_list|,
name|Scale
operator|-
name|ScaledNumbers
operator|::
name|MinScale
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Scale
operator|-=
name|ScaleShift
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|ScaleShift
operator|==
name|Shift
condition|)
return|return;
end_if

begin_comment
comment|// Shift the digits themselves.
end_comment

begin_expr_stmt
name|Shift
operator|-=
name|ScaleShift
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Shift
operator|>=
name|Width
condition|)
block|{
comment|// Saturate.
operator|*
name|this
operator|=
name|getZero
argument_list|()
expr_stmt|;
return|return;
block|}
end_if

begin_expr_stmt
name|Digits
operator|>>=
name|Shift
expr_stmt|;
end_expr_stmt

begin_return
return|return;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
operator|<
name|ScaledNumber
operator|<
name|T
operator|>>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

