begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/divtf3.c - Quad-precision division --------------------*- C -*-===//
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
comment|// This file implements quad-precision soft-float division
end_comment

begin_comment
comment|// with the IEEE-754 default rounding (to nearest, ties to even).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For simplicity, this implementation currently flushes denormals to zero.
end_comment

begin_comment
comment|// It should be a fairly straightforward exercise to implement gradual
end_comment

begin_comment
comment|// underflow with correct rounding.
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
name|QUAD_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRT_HAS_128BIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CRT_LDBL_128BIT
argument_list|)
end_if

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__divtf3
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
name|quotientSign
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
comment|// NaN / anything = qNaN
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
comment|// anything / NaN = qNaN
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
comment|// infinity / infinity = NaN
if|if
condition|(
name|bAbs
operator|==
name|infRep
condition|)
return|return
name|fromRep
argument_list|(
name|qnanRep
argument_list|)
return|;
comment|// infinity / anything else = +/- infinity
else|else
return|return
name|fromRep
argument_list|(
name|aAbs
operator||
name|quotientSign
argument_list|)
return|;
block|}
comment|// anything else / infinity = +/- 0
if|if
condition|(
name|bAbs
operator|==
name|infRep
condition|)
return|return
name|fromRep
argument_list|(
name|quotientSign
argument_list|)
return|;
if|if
condition|(
operator|!
name|aAbs
condition|)
block|{
comment|// zero / zero = NaN
if|if
condition|(
operator|!
name|bAbs
condition|)
return|return
name|fromRep
argument_list|(
name|qnanRep
argument_list|)
return|;
comment|// zero / anything else = +/- zero
else|else
return|return
name|fromRep
argument_list|(
name|quotientSign
argument_list|)
return|;
block|}
comment|// anything else / zero = +/- infinity
if|if
condition|(
operator|!
name|bAbs
condition|)
return|return
name|fromRep
argument_list|(
name|infRep
operator||
name|quotientSign
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
operator|-=
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
name|int
name|quotientExponent
init|=
name|aExponent
operator|-
name|bExponent
operator|+
name|scale
decl_stmt|;
comment|// Align the significand of b as a Q63 fixed-point number in the range
comment|// [1, 2.0) and get a Q64 approximate reciprocal using a small minimax
comment|// polynomial approximation: reciprocal = 3/4 + 1/sqrt(2) - b/2.  This
comment|// is accurate to about 3.5 binary digits.
specifier|const
name|uint64_t
name|q63b
init|=
name|bSignificand
operator|>>
literal|49
decl_stmt|;
name|uint64_t
name|recip64
init|=
name|UINT64_C
argument_list|(
literal|0x7504f333F9DE6484
argument_list|)
operator|-
name|q63b
decl_stmt|;
comment|// 0x7504f333F9DE6484 / 2^64 + 1 = 3/4 + 1/sqrt(2)
comment|// Now refine the reciprocal estimate using a Newton-Raphson iteration:
comment|//
comment|//     x1 = x0 * (2 - x0 * b)
comment|//
comment|// This doubles the number of correct binary digits in the approximation
comment|// with each iteration.
name|uint64_t
name|correction64
decl_stmt|;
name|correction64
operator|=
operator|-
operator|(
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|q63b
operator|>>
literal|64
operator|)
expr_stmt|;
name|recip64
operator|=
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|correction64
operator|>>
literal|63
expr_stmt|;
name|correction64
operator|=
operator|-
operator|(
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|q63b
operator|>>
literal|64
operator|)
expr_stmt|;
name|recip64
operator|=
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|correction64
operator|>>
literal|63
expr_stmt|;
name|correction64
operator|=
operator|-
operator|(
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|q63b
operator|>>
literal|64
operator|)
expr_stmt|;
name|recip64
operator|=
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|correction64
operator|>>
literal|63
expr_stmt|;
name|correction64
operator|=
operator|-
operator|(
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|q63b
operator|>>
literal|64
operator|)
expr_stmt|;
name|recip64
operator|=
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|correction64
operator|>>
literal|63
expr_stmt|;
name|correction64
operator|=
operator|-
operator|(
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|q63b
operator|>>
literal|64
operator|)
expr_stmt|;
name|recip64
operator|=
operator|(
name|rep_t
operator|)
name|recip64
operator|*
name|correction64
operator|>>
literal|63
expr_stmt|;
comment|// recip64 might have overflowed to exactly zero in the preceeding
comment|// computation if the high word of b is exactly 1.0.  This would sabotage
comment|// the full-width final stage of the computation that follows, so we adjust
comment|// recip64 downward by one bit.
name|recip64
operator|--
expr_stmt|;
comment|// We need to perform one more iteration to get us to 112 binary digits;
comment|// The last iteration needs to happen with extra precision.
specifier|const
name|uint64_t
name|q127blo
init|=
name|bSignificand
operator|<<
literal|15
decl_stmt|;
name|rep_t
name|correction
decl_stmt|,
name|reciprocal
decl_stmt|;
comment|// NOTE: This operation is equivalent to __multi3, which is not implemented
comment|//       in some architechure
name|rep_t
name|r64q63
decl_stmt|,
name|r64q127
decl_stmt|,
name|r64cH
decl_stmt|,
name|r64cL
decl_stmt|,
name|dummy
decl_stmt|;
name|wideMultiply
argument_list|(
operator|(
name|rep_t
operator|)
name|recip64
argument_list|,
operator|(
name|rep_t
operator|)
name|q63b
argument_list|,
operator|&
name|dummy
argument_list|,
operator|&
name|r64q63
argument_list|)
expr_stmt|;
name|wideMultiply
argument_list|(
operator|(
name|rep_t
operator|)
name|recip64
argument_list|,
operator|(
name|rep_t
operator|)
name|q127blo
argument_list|,
operator|&
name|dummy
argument_list|,
operator|&
name|r64q127
argument_list|)
expr_stmt|;
name|correction
operator|=
operator|-
operator|(
name|r64q63
operator|+
operator|(
name|r64q127
operator|>>
literal|64
operator|)
operator|)
expr_stmt|;
name|uint64_t
name|cHi
init|=
name|correction
operator|>>
literal|64
decl_stmt|;
name|uint64_t
name|cLo
init|=
name|correction
decl_stmt|;
name|wideMultiply
argument_list|(
operator|(
name|rep_t
operator|)
name|recip64
argument_list|,
operator|(
name|rep_t
operator|)
name|cHi
argument_list|,
operator|&
name|dummy
argument_list|,
operator|&
name|r64cH
argument_list|)
expr_stmt|;
name|wideMultiply
argument_list|(
operator|(
name|rep_t
operator|)
name|recip64
argument_list|,
operator|(
name|rep_t
operator|)
name|cLo
argument_list|,
operator|&
name|dummy
argument_list|,
operator|&
name|r64cL
argument_list|)
expr_stmt|;
name|reciprocal
operator|=
name|r64cH
operator|+
operator|(
name|r64cL
operator|>>
literal|64
operator|)
expr_stmt|;
comment|// We already adjusted the 64-bit estimate, now we need to adjust the final
comment|// 128-bit reciprocal estimate downward to ensure that it is strictly smaller
comment|// than the infinitely precise exact reciprocal.  Because the computation
comment|// of the Newton-Raphson step is truncating at every step, this adjustment
comment|// is small; most of the work is already done.
name|reciprocal
operator|-=
literal|2
expr_stmt|;
comment|// The numerical reciprocal is accurate to within 2^-112, lies in the
comment|// interval [0.5, 1.0), and is strictly smaller than the true reciprocal
comment|// of b.  Multiplying a by this reciprocal thus gives a numerical q = a/b
comment|// in Q127 with the following properties:
comment|//
comment|//    1. q< a/b
comment|//    2. q is in the interval [0.5, 2.0)
comment|//    3. the error in q is bounded away from 2^-113 (actually, we have a
comment|//       couple of bits to spare, but this is all we need).
comment|// We need a 128 x 128 multiply high to compute q, which isn't a basic
comment|// operation in C, so we need to be a little bit fussy.
name|rep_t
name|quotient
decl_stmt|,
name|quotientLo
decl_stmt|;
name|wideMultiply
argument_list|(
name|aSignificand
operator|<<
literal|2
argument_list|,
name|reciprocal
argument_list|,
operator|&
name|quotient
argument_list|,
operator|&
name|quotientLo
argument_list|)
expr_stmt|;
comment|// Two cases: quotient is in [0.5, 1.0) or quotient is in [1.0, 2.0).
comment|// In either case, we are going to compute a residual of the form
comment|//
comment|//     r = a - q*b
comment|//
comment|// We know from the construction of q that r satisfies:
comment|//
comment|//     0<= r< ulp(q)*b
comment|//
comment|// if r is greater than 1/2 ulp(q)*b, then q rounds up.  Otherwise, we
comment|// already have the correct result.  The exact halfway case cannot occur.
comment|// We also take this time to right shift quotient if it falls in the [1,2)
comment|// range and adjust the exponent accordingly.
name|rep_t
name|residual
decl_stmt|;
name|rep_t
name|qb
decl_stmt|;
if|if
condition|(
name|quotient
operator|<
operator|(
name|implicitBit
operator|<<
literal|1
operator|)
condition|)
block|{
name|wideMultiply
argument_list|(
name|quotient
argument_list|,
name|bSignificand
argument_list|,
operator|&
name|dummy
argument_list|,
operator|&
name|qb
argument_list|)
expr_stmt|;
name|residual
operator|=
operator|(
name|aSignificand
operator|<<
literal|113
operator|)
operator|-
name|qb
expr_stmt|;
name|quotientExponent
operator|--
expr_stmt|;
block|}
else|else
block|{
name|quotient
operator|>>=
literal|1
expr_stmt|;
name|wideMultiply
argument_list|(
name|quotient
argument_list|,
name|bSignificand
argument_list|,
operator|&
name|dummy
argument_list|,
operator|&
name|qb
argument_list|)
expr_stmt|;
name|residual
operator|=
operator|(
name|aSignificand
operator|<<
literal|112
operator|)
operator|-
name|qb
expr_stmt|;
block|}
specifier|const
name|int
name|writtenExponent
init|=
name|quotientExponent
operator|+
name|exponentBias
decl_stmt|;
if|if
condition|(
name|writtenExponent
operator|>=
name|maxExponent
condition|)
block|{
comment|// If we have overflowed the exponent, return infinity.
return|return
name|fromRep
argument_list|(
name|infRep
operator||
name|quotientSign
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|writtenExponent
operator|<
literal|1
condition|)
block|{
comment|// Flush denormals to zero.  In the future, it would be nice to add
comment|// code to round them correctly.
return|return
name|fromRep
argument_list|(
name|quotientSign
argument_list|)
return|;
block|}
else|else
block|{
specifier|const
name|bool
name|round
init|=
operator|(
name|residual
operator|<<
literal|1
operator|)
operator|>=
name|bSignificand
decl_stmt|;
comment|// Clear the implicit bit
name|rep_t
name|absResult
init|=
name|quotient
operator|&
name|significandMask
decl_stmt|;
comment|// Insert the exponent
name|absResult
operator||=
operator|(
name|rep_t
operator|)
name|writtenExponent
operator|<<
name|significandBits
expr_stmt|;
comment|// Round
name|absResult
operator|+=
name|round
expr_stmt|;
comment|// Insert the sign and return
specifier|const
name|long
name|double
name|result
init|=
name|fromRep
argument_list|(
name|absResult
operator||
name|quotientSign
argument_list|)
decl_stmt|;
return|return
name|result
return|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

