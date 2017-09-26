begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/divsf3.c - Single-precision division ------------------*- C -*-===//
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
comment|// This file implements single-precision soft-float division
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
name|SINGLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__divsf3
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
comment|// Align the significand of b as a Q31 fixed-point number in the range
comment|// [1, 2.0) and get a Q32 approximate reciprocal using a small minimax
comment|// polynomial approximation: reciprocal = 3/4 + 1/sqrt(2) - b/2.  This
comment|// is accurate to about 3.5 binary digits.
name|uint32_t
name|q31b
init|=
name|bSignificand
operator|<<
literal|8
decl_stmt|;
name|uint32_t
name|reciprocal
init|=
name|UINT32_C
argument_list|(
literal|0x7504f333
argument_list|)
operator|-
name|q31b
decl_stmt|;
comment|// Now refine the reciprocal estimate using a Newton-Raphson iteration:
comment|//
comment|//     x1 = x0 * (2 - x0 * b)
comment|//
comment|// This doubles the number of correct binary digits in the approximation
comment|// with each iteration, so after three iterations, we have about 28 binary
comment|// digits of accuracy.
name|uint32_t
name|correction
decl_stmt|;
name|correction
operator|=
operator|-
operator|(
operator|(
name|uint64_t
operator|)
name|reciprocal
operator|*
name|q31b
operator|>>
literal|32
operator|)
expr_stmt|;
name|reciprocal
operator|=
operator|(
name|uint64_t
operator|)
name|reciprocal
operator|*
name|correction
operator|>>
literal|31
expr_stmt|;
name|correction
operator|=
operator|-
operator|(
operator|(
name|uint64_t
operator|)
name|reciprocal
operator|*
name|q31b
operator|>>
literal|32
operator|)
expr_stmt|;
name|reciprocal
operator|=
operator|(
name|uint64_t
operator|)
name|reciprocal
operator|*
name|correction
operator|>>
literal|31
expr_stmt|;
name|correction
operator|=
operator|-
operator|(
operator|(
name|uint64_t
operator|)
name|reciprocal
operator|*
name|q31b
operator|>>
literal|32
operator|)
expr_stmt|;
name|reciprocal
operator|=
operator|(
name|uint64_t
operator|)
name|reciprocal
operator|*
name|correction
operator|>>
literal|31
expr_stmt|;
comment|// Exhaustive testing shows that the error in reciprocal after three steps
comment|// is in the interval [-0x1.f58108p-31, 0x1.d0e48cp-29], in line with our
comment|// expectations.  We bump the reciprocal by a tiny value to force the error
comment|// to be strictly positive (in the range [0x1.4fdfp-37,0x1.287246p-29], to
comment|// be specific).  This also causes 1/1 to give a sensible approximation
comment|// instead of zero (due to overflow).
name|reciprocal
operator|-=
literal|2
expr_stmt|;
comment|// The numerical reciprocal is accurate to within 2^-28, lies in the
comment|// interval [0x1.000000eep-1, 0x1.fffffffcp-1], and is strictly smaller
comment|// than the true reciprocal of b.  Multiplying a by this reciprocal thus
comment|// gives a numerical q = a/b in Q24 with the following properties:
comment|//
comment|//    1. q< a/b
comment|//    2. q is in the interval [0x1.000000eep-1, 0x1.fffffffcp0)
comment|//    3. the error in q is at most 2^-24 + 2^-27 -- the 2^24 term comes
comment|//       from the fact that we truncate the product, and the 2^27 term
comment|//       is the error in the reciprocal of b scaled by the maximum
comment|//       possible value of a.  As a consequence of this error bound,
comment|//       either q or nextafter(q) is the correctly rounded
name|rep_t
name|quotient
init|=
operator|(
name|uint64_t
operator|)
name|reciprocal
operator|*
operator|(
name|aSignificand
operator|<<
literal|1
operator|)
operator|>>
literal|32
decl_stmt|;
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
name|residual
operator|=
operator|(
name|aSignificand
operator|<<
literal|24
operator|)
operator|-
name|quotient
operator|*
name|bSignificand
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
name|residual
operator|=
operator|(
name|aSignificand
operator|<<
literal|23
operator|)
operator|-
name|quotient
operator|*
name|bSignificand
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
operator|>
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
return|return
name|fromRep
argument_list|(
name|absResult
operator||
name|quotientSign
argument_list|)
return|;
block|}
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_function
name|AEABI_RTABI
name|fp_t
name|__aeabi_fdiv
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__divsf3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

