begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/muldf3.c - Double-precision multiplication ------------*- C -*-===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
comment|// This file implements double-precision soft-float multiplication
end_comment

begin_comment
comment|// with the IEEE-754 default rounding (to nearest, ties to even).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|DOUBLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_macro
name|ARM_EABI_FNALIAS
argument_list|(
argument|dmul
argument_list|,
argument|muldf3
argument_list|)
end_macro

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__muldf3
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
specifier|const
name|unsigned
name|int
name|aExponent
init|=
name|toRep
argument_list|(
name|a
argument_list|)
operator|>>
name|significandBits
operator|&
name|maxExponent
decl_stmt|;
specifier|const
name|unsigned
name|int
name|bExponent
init|=
name|toRep
argument_list|(
name|b
argument_list|)
operator|>>
name|significandBits
operator|&
name|maxExponent
decl_stmt|;
specifier|const
name|rep_t
name|productSign
init|=
operator|(
name|toRep
argument_list|(
name|a
argument_list|)
operator|^
name|toRep
argument_list|(
name|b
argument_list|)
operator|)
operator|&
name|signBit
decl_stmt|;
name|rep_t
name|aSignificand
init|=
name|toRep
argument_list|(
name|a
argument_list|)
operator|&
name|significandMask
decl_stmt|;
name|rep_t
name|bSignificand
init|=
name|toRep
argument_list|(
name|b
argument_list|)
operator|&
name|significandMask
decl_stmt|;
name|int
name|scale
init|=
literal|0
decl_stmt|;
comment|// Detect if a or b is zero, denormal, infinity, or NaN.
if|if
condition|(
name|aExponent
operator|-
literal|1U
operator|>=
name|maxExponent
operator|-
literal|1U
operator|||
name|bExponent
operator|-
literal|1U
operator|>=
name|maxExponent
operator|-
literal|1U
condition|)
block|{
specifier|const
name|rep_t
name|aAbs
init|=
name|toRep
argument_list|(
name|a
argument_list|)
operator|&
name|absMask
decl_stmt|;
specifier|const
name|rep_t
name|bAbs
init|=
name|toRep
argument_list|(
name|b
argument_list|)
operator|&
name|absMask
decl_stmt|;
comment|// NaN * anything = qNaN
if|if
condition|(
name|aAbs
operator|>
name|infRep
condition|)
return|return
name|fromRep
argument_list|(
name|toRep
argument_list|(
name|a
argument_list|)
operator||
name|quietBit
argument_list|)
return|;
comment|// anything * NaN = qNaN
if|if
condition|(
name|bAbs
operator|>
name|infRep
condition|)
return|return
name|fromRep
argument_list|(
name|toRep
argument_list|(
name|b
argument_list|)
operator||
name|quietBit
argument_list|)
return|;
if|if
condition|(
name|aAbs
operator|==
name|infRep
condition|)
block|{
comment|// infinity * non-zero = +/- infinity
if|if
condition|(
name|bAbs
condition|)
return|return
name|fromRep
argument_list|(
name|aAbs
operator||
name|productSign
argument_list|)
return|;
comment|// infinity * zero = NaN
else|else
return|return
name|fromRep
argument_list|(
name|qnanRep
argument_list|)
return|;
block|}
if|if
condition|(
name|bAbs
operator|==
name|infRep
condition|)
block|{
comment|// non-zero * infinity = +/- infinity
if|if
condition|(
name|aAbs
condition|)
return|return
name|fromRep
argument_list|(
name|bAbs
operator||
name|productSign
argument_list|)
return|;
comment|// zero * infinity = NaN
else|else
return|return
name|fromRep
argument_list|(
name|qnanRep
argument_list|)
return|;
block|}
comment|// zero * anything = +/- zero
if|if
condition|(
operator|!
name|aAbs
condition|)
return|return
name|fromRep
argument_list|(
name|productSign
argument_list|)
return|;
comment|// anything * zero = +/- zero
if|if
condition|(
operator|!
name|bAbs
condition|)
return|return
name|fromRep
argument_list|(
name|productSign
argument_list|)
return|;
comment|// one or both of a or b is denormal, the other (if applicable) is a
comment|// normal number.  Renormalize one or both of a and b, and set scale to
comment|// include the necessary exponent adjustment.
if|if
condition|(
name|aAbs
operator|<
name|implicitBit
condition|)
name|scale
operator|+=
name|normalize
argument_list|(
operator|&
name|aSignificand
argument_list|)
expr_stmt|;
if|if
condition|(
name|bAbs
operator|<
name|implicitBit
condition|)
name|scale
operator|+=
name|normalize
argument_list|(
operator|&
name|bSignificand
argument_list|)
expr_stmt|;
block|}
comment|// Or in the implicit significand bit.  (If we fell through from the
comment|// denormal path it was already set by normalize( ), but setting it twice
comment|// won't hurt anything.)
name|aSignificand
operator||=
name|implicitBit
expr_stmt|;
name|bSignificand
operator||=
name|implicitBit
expr_stmt|;
comment|// Get the significand of a*b.  Before multiplying the significands, shift
comment|// one of them left to left-align it in the field.  Thus, the product will
comment|// have (exponentBits + 2) integral digits, all but two of which must be
comment|// zero.  Normalizing this result is just a conditional left-shift by one
comment|// and bumping the exponent accordingly.
name|rep_t
name|productHi
decl_stmt|,
name|productLo
decl_stmt|;
name|wideMultiply
argument_list|(
name|aSignificand
argument_list|,
name|bSignificand
operator|<<
name|exponentBits
argument_list|,
operator|&
name|productHi
argument_list|,
operator|&
name|productLo
argument_list|)
expr_stmt|;
name|int
name|productExponent
init|=
name|aExponent
operator|+
name|bExponent
operator|-
name|exponentBias
operator|+
name|scale
decl_stmt|;
comment|// Normalize the significand, adjust exponent if needed.
if|if
condition|(
name|productHi
operator|&
name|implicitBit
condition|)
name|productExponent
operator|++
expr_stmt|;
else|else
name|wideLeftShift
argument_list|(
operator|&
name|productHi
argument_list|,
operator|&
name|productLo
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// If we have overflowed the type, return +/- infinity.
if|if
condition|(
name|productExponent
operator|>=
name|maxExponent
condition|)
return|return
name|fromRep
argument_list|(
name|infRep
operator||
name|productSign
argument_list|)
return|;
if|if
condition|(
name|productExponent
operator|<=
literal|0
condition|)
block|{
comment|// Result is denormal before rounding
comment|//
comment|// If the result is so small that it just underflows to zero, return
comment|// a zero of the appropriate sign.  Mathematically there is no need to
comment|// handle this case separately, but we make it a special case to
comment|// simplify the shift logic.
specifier|const
name|unsigned
name|int
name|shift
init|=
literal|1U
operator|-
operator|(
name|unsigned
name|int
operator|)
name|productExponent
decl_stmt|;
if|if
condition|(
name|shift
operator|>=
name|typeWidth
condition|)
return|return
name|fromRep
argument_list|(
name|productSign
argument_list|)
return|;
comment|// Otherwise, shift the significand of the result so that the round
comment|// bit is the high bit of productLo.
name|wideRightShiftWithSticky
argument_list|(
operator|&
name|productHi
argument_list|,
operator|&
name|productLo
argument_list|,
name|shift
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Result is normal before rounding; insert the exponent.
name|productHi
operator|&=
name|significandMask
expr_stmt|;
name|productHi
operator||=
operator|(
name|rep_t
operator|)
name|productExponent
operator|<<
name|significandBits
expr_stmt|;
block|}
comment|// Insert the sign of the result:
name|productHi
operator||=
name|productSign
expr_stmt|;
comment|// Final rounding.  The final result may overflow to infinity, or underflow
comment|// to zero, but those are the correct results in those cases.  We use the
comment|// default IEEE-754 round-to-nearest, ties-to-even rounding mode.
if|if
condition|(
name|productLo
operator|>
name|signBit
condition|)
name|productHi
operator|++
expr_stmt|;
if|if
condition|(
name|productLo
operator|==
name|signBit
condition|)
name|productHi
operator|+=
name|productHi
operator|&
literal|1
expr_stmt|;
return|return
name|fromRep
argument_list|(
name|productHi
argument_list|)
return|;
block|}
end_function

end_unit

