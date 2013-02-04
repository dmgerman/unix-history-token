begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/extendsfdf2.c - single -> double conversion -----------*- C -*-===//
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
comment|// This file implements a fairly generic conversion from a narrower to a wider
end_comment

begin_comment
comment|// IEEE-754 floating-point type.  The constants and types defined following the
end_comment

begin_comment
comment|// includes below parameterize the conversion.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This routine can be trivially adapted to support conversions from
end_comment

begin_comment
comment|// half-precision or to quad-precision. It does not support types that don't
end_comment

begin_comment
comment|// use the usual IEEE-754 interchange formats; specifically, some work would be
end_comment

begin_comment
comment|// needed to adapt it to (for example) the Intel 80-bit format or PowerPC
end_comment

begin_comment
comment|// double-double format.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note please, however, that this implementation is only intended to support
end_comment

begin_comment
comment|// *widening* operations; if you need to convert to a *narrower* floating-point
end_comment

begin_comment
comment|// type (e.g. double -> float), then this routine will not do what you want it
end_comment

begin_comment
comment|// to.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It also requires that integer types at least as large as both formats
end_comment

begin_comment
comment|// are available on the target platform; this may pose a problem when trying
end_comment

begin_comment
comment|// to add support for quad on some 32-bit systems, for example.  You also may
end_comment

begin_comment
comment|// run into trouble finding an appropriate CLZ function for wide source types;
end_comment

begin_comment
comment|// you will likely need to roll your own on some platforms.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Finally, the following assumptions are made:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1. floating-point types and integer types have the same endianness on the
end_comment

begin_comment
comment|//    target platform
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 2. quiet NaNs, if supported, are indicated by the leading bit of the
end_comment

begin_comment
comment|//    significand field being set
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_typedef
typedef|typedef
name|float
name|src_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|src_rep_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SRC_REP_C
value|UINT32_C
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|srcSigBits
init|=
literal|23
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|src_rep_t_clz
value|__builtin_clz
end_define

begin_typedef
typedef|typedef
name|double
name|dst_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|dst_rep_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_REP_C
value|UINT64_C
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|dstSigBits
init|=
literal|52
decl_stmt|;
end_decl_stmt

begin_comment
comment|// End of specialization parameters.  Two helper routines for conversion to and
end_comment

begin_comment
comment|// from the representation of floating-point data as integer values follow.
end_comment

begin_function
specifier|static
specifier|inline
name|src_rep_t
name|srcToRep
parameter_list|(
name|src_t
name|x
parameter_list|)
block|{
specifier|const
union|union
block|{
name|src_t
name|f
decl_stmt|;
name|src_rep_t
name|i
decl_stmt|;
block|}
name|rep
init|=
block|{
operator|.
name|f
operator|=
name|x
block|}
union|;
return|return
name|rep
operator|.
name|i
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|dst_t
name|dstFromRep
parameter_list|(
name|dst_rep_t
name|x
parameter_list|)
block|{
specifier|const
union|union
block|{
name|dst_t
name|f
decl_stmt|;
name|dst_rep_t
name|i
decl_stmt|;
block|}
name|rep
init|=
block|{
operator|.
name|i
operator|=
name|x
block|}
union|;
return|return
name|rep
operator|.
name|f
return|;
block|}
end_function

begin_comment
comment|// End helper routines.  Conversion implementation follows.
end_comment

begin_macro
name|ARM_EABI_FNALIAS
argument_list|(
argument|f2d
argument_list|,
argument|extendsfdf2
argument_list|)
end_macro

begin_function
name|dst_t
name|__extendsfdf2
parameter_list|(
name|src_t
name|a
parameter_list|)
block|{
comment|// Various constants whose values follow from the type parameters.
comment|// Any reasonable optimizer will fold and propagate all of these.
specifier|const
name|int
name|srcBits
init|=
sizeof|sizeof
argument_list|(
name|src_t
argument_list|)
operator|*
name|CHAR_BIT
decl_stmt|;
specifier|const
name|int
name|srcExpBits
init|=
name|srcBits
operator|-
name|srcSigBits
operator|-
literal|1
decl_stmt|;
specifier|const
name|int
name|srcInfExp
init|=
operator|(
literal|1
operator|<<
name|srcExpBits
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|int
name|srcExpBias
init|=
name|srcInfExp
operator|>>
literal|1
decl_stmt|;
specifier|const
name|src_rep_t
name|srcMinNormal
init|=
name|SRC_REP_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|srcSigBits
decl_stmt|;
specifier|const
name|src_rep_t
name|srcInfinity
init|=
operator|(
name|src_rep_t
operator|)
name|srcInfExp
operator|<<
name|srcSigBits
decl_stmt|;
specifier|const
name|src_rep_t
name|srcSignMask
init|=
name|SRC_REP_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|srcSigBits
operator|+
name|srcExpBits
operator|)
decl_stmt|;
specifier|const
name|src_rep_t
name|srcAbsMask
init|=
name|srcSignMask
operator|-
literal|1
decl_stmt|;
specifier|const
name|src_rep_t
name|srcQNaN
init|=
name|SRC_REP_C
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|srcSigBits
operator|-
literal|1
operator|)
decl_stmt|;
specifier|const
name|src_rep_t
name|srcNaNCode
init|=
name|srcQNaN
operator|-
literal|1
decl_stmt|;
specifier|const
name|int
name|dstBits
init|=
sizeof|sizeof
argument_list|(
name|dst_t
argument_list|)
operator|*
name|CHAR_BIT
decl_stmt|;
specifier|const
name|int
name|dstExpBits
init|=
name|dstBits
operator|-
name|dstSigBits
operator|-
literal|1
decl_stmt|;
specifier|const
name|int
name|dstInfExp
init|=
operator|(
literal|1
operator|<<
name|dstExpBits
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|int
name|dstExpBias
init|=
name|dstInfExp
operator|>>
literal|1
decl_stmt|;
specifier|const
name|dst_rep_t
name|dstMinNormal
init|=
name|DST_REP_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|dstSigBits
decl_stmt|;
comment|// Break a into a sign and representation of the absolute value
specifier|const
name|src_rep_t
name|aRep
init|=
name|srcToRep
argument_list|(
name|a
argument_list|)
decl_stmt|;
specifier|const
name|src_rep_t
name|aAbs
init|=
name|aRep
operator|&
name|srcAbsMask
decl_stmt|;
specifier|const
name|src_rep_t
name|sign
init|=
name|aRep
operator|&
name|srcSignMask
decl_stmt|;
name|dst_rep_t
name|absResult
decl_stmt|;
if|if
condition|(
name|aAbs
operator|-
name|srcMinNormal
operator|<
name|srcInfinity
operator|-
name|srcMinNormal
condition|)
block|{
comment|// a is a normal number.
comment|// Extend to the destination type by shifting the significand and
comment|// exponent into the proper position and rebiasing the exponent.
name|absResult
operator|=
operator|(
name|dst_rep_t
operator|)
name|aAbs
operator|<<
operator|(
name|dstSigBits
operator|-
name|srcSigBits
operator|)
expr_stmt|;
name|absResult
operator|+=
call|(
name|dst_rep_t
call|)
argument_list|(
name|dstExpBias
operator|-
name|srcExpBias
argument_list|)
operator|<<
name|dstSigBits
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|aAbs
operator|>=
name|srcInfinity
condition|)
block|{
comment|// a is NaN or infinity.
comment|// Conjure the result by beginning with infinity, then setting the qNaN
comment|// bit (if needed) and right-aligning the rest of the trailing NaN
comment|// payload field.
name|absResult
operator|=
operator|(
name|dst_rep_t
operator|)
name|dstInfExp
operator|<<
name|dstSigBits
expr_stmt|;
name|absResult
operator||=
call|(
name|dst_rep_t
call|)
argument_list|(
name|aAbs
operator|&
name|srcQNaN
argument_list|)
operator|<<
operator|(
name|dstSigBits
operator|-
name|srcSigBits
operator|)
expr_stmt|;
name|absResult
operator||=
name|aAbs
operator|&
name|srcNaNCode
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|aAbs
condition|)
block|{
comment|// a is denormal.
comment|// renormalize the significand and clear the leading bit, then insert
comment|// the correct adjusted exponent in the destination type.
specifier|const
name|int
name|scale
init|=
name|src_rep_t_clz
argument_list|(
name|aAbs
argument_list|)
operator|-
name|src_rep_t_clz
argument_list|(
name|srcMinNormal
argument_list|)
decl_stmt|;
name|absResult
operator|=
operator|(
name|dst_rep_t
operator|)
name|aAbs
operator|<<
operator|(
name|dstSigBits
operator|-
name|srcSigBits
operator|+
name|scale
operator|)
expr_stmt|;
name|absResult
operator|^=
name|dstMinNormal
expr_stmt|;
specifier|const
name|int
name|resultExponent
init|=
name|dstExpBias
operator|-
name|srcExpBias
operator|-
name|scale
operator|+
literal|1
decl_stmt|;
name|absResult
operator||=
operator|(
name|dst_rep_t
operator|)
name|resultExponent
operator|<<
name|dstSigBits
expr_stmt|;
block|}
else|else
block|{
comment|// a is zero.
name|absResult
operator|=
literal|0
expr_stmt|;
block|}
comment|// Apply the signbit to (dst_t)abs(a).
specifier|const
name|dst_rep_t
name|result
init|=
name|absResult
operator||
operator|(
name|dst_rep_t
operator|)
name|sign
operator|<<
operator|(
name|dstBits
operator|-
name|srcBits
operator|)
decl_stmt|;
return|return
name|dstFromRep
argument_list|(
name|result
argument_list|)
return|;
block|}
end_function

end_unit

