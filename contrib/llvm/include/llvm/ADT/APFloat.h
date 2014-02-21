begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/Support/APFloat.h - Arbitrary Precision Floating Point -*- C++ -*-==//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief
end_comment

begin_comment
comment|/// This file declares a class to represent arbitrary precision floating point
end_comment

begin_comment
comment|/// values and provide a variety of arithmetic operations on them.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_APFLOAT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_APFLOAT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|fltSemantics
struct_decl|;
name|class
name|APSInt
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|/// Enum that represents what fraction of the LSB truncated bits of an fp number
comment|/// represent.
comment|///
comment|/// This essentially combines the roles of guard and sticky bits.
enum|enum
name|lostFraction
block|{
comment|// Example of truncated bits:
name|lfExactlyZero
block|,
comment|// 000000
name|lfLessThanHalf
block|,
comment|// 0xxxxx  x's not all zero
name|lfExactlyHalf
block|,
comment|// 100000
name|lfMoreThanHalf
comment|// 1xxxxx  x's not all zero
block|}
enum|;
comment|/// \brief A self-contained host- and target-independent arbitrary-precision
comment|/// floating-point software implementation.
comment|///
comment|/// APFloat uses bignum integer arithmetic as provided by static functions in
comment|/// the APInt class.  The library will work with bignum integers whose parts are
comment|/// any unsigned type at least 16 bits wide, but 64 bits is recommended.
comment|///
comment|/// Written for clarity rather than speed, in particular with a view to use in
comment|/// the front-end of a cross compiler so that target arithmetic can be correctly
comment|/// performed on the host.  Performance should nonetheless be reasonable,
comment|/// particularly for its intended use.  It may be useful as a base
comment|/// implementation for a run-time library during development of a faster
comment|/// target-specific one.
comment|///
comment|/// All 5 rounding modes in the IEEE-754R draft are handled correctly for all
comment|/// implemented operations.  Currently implemented operations are add, subtract,
comment|/// multiply, divide, fused-multiply-add, conversion-to-float,
comment|/// conversion-to-integer and conversion-from-integer.  New rounding modes
comment|/// (e.g. away from zero) can be added with three or four lines of code.
comment|///
comment|/// Four formats are built-in: IEEE single precision, double precision,
comment|/// quadruple precision, and x87 80-bit extended double (when operating with
comment|/// full extended precision).  Adding a new format that obeys IEEE semantics
comment|/// only requires adding two lines of code: a declaration and definition of the
comment|/// format.
comment|///
comment|/// All operations return the status of that operation as an exception bit-mask,
comment|/// so multiple operations can be done consecutively with their results or-ed
comment|/// together.  The returned status can be useful for compiler diagnostics; e.g.,
comment|/// inexact, underflow and overflow can be easily diagnosed on constant folding,
comment|/// and compiler optimizers can determine what exceptions would be raised by
comment|/// folding operations and optimize, or perhaps not optimize, accordingly.
comment|///
comment|/// At present, underflow tininess is detected after rounding; it should be
comment|/// straight forward to add support for the before-rounding case too.
comment|///
comment|/// The library reads hexadecimal floating point numbers as per C99, and
comment|/// correctly rounds if necessary according to the specified rounding mode.
comment|/// Syntax is required to have been validated by the caller.  It also converts
comment|/// floating point numbers to hexadecimal text as per the C99 %a and %A
comment|/// conversions.  The output precision (or alternatively the natural minimal
comment|/// precision) can be specified; if the requested precision is less than the
comment|/// natural precision the output is correctly rounded for the specified rounding
comment|/// mode.
comment|///
comment|/// It also reads decimal floating point numbers and correctly rounds according
comment|/// to the specified rounding mode.
comment|///
comment|/// Conversion to decimal text is not currently implemented.
comment|///
comment|/// Non-zero finite numbers are represented internally as a sign bit, a 16-bit
comment|/// signed exponent, and the significand as an array of integer parts.  After
comment|/// normalization of a number of precision P the exponent is within the range of
comment|/// the format, and if the number is not denormal the P-th bit of the
comment|/// significand is set as an explicit integer bit.  For denormals the most
comment|/// significant bit is shifted right so that the exponent is maintained at the
comment|/// format's minimum, so that the smallest denormal has just the least
comment|/// significant bit of the significand set.  The sign of zeroes and infinities
comment|/// is significant; the exponent and significand of such numbers is not stored,
comment|/// but has a known implicit (deterministic) value: 0 for the significands, 0
comment|/// for zero exponent, all 1 bits for infinity exponent.  For NaNs the sign and
comment|/// significand are deterministic, although not really meaningful, and preserved
comment|/// in non-conversion operations.  The exponent is implicitly all 1 bits.
comment|///
comment|/// APFloat does not provide any exception handling beyond default exception
comment|/// handling. We represent Signaling NaNs via IEEE-754R 2008 6.2.1 should clause
comment|/// by encoding Signaling NaNs with the first bit of its trailing significand as
comment|/// 0.
comment|///
comment|/// TODO
comment|/// ====
comment|///
comment|/// Some features that may or may not be worth adding:
comment|///
comment|/// Binary to decimal conversion (hard).
comment|///
comment|/// Optional ability to detect underflow tininess before rounding.
comment|///
comment|/// New formats: x87 in single and double precision mode (IEEE apart from
comment|/// extended exponent range) (hard).
comment|///
comment|/// New operations: sqrt, IEEE remainder, C90 fmod, nexttoward.
comment|///
name|class
name|APFloat
block|{
name|public
label|:
comment|/// A signed type to represent a floating point numbers unbiased exponent.
typedef|typedef
name|signed
name|short
name|ExponentType
typedef|;
comment|/// \name Floating Point Semantics.
comment|/// @{
specifier|static
specifier|const
name|fltSemantics
name|IEEEhalf
decl_stmt|;
specifier|static
specifier|const
name|fltSemantics
name|IEEEsingle
decl_stmt|;
specifier|static
specifier|const
name|fltSemantics
name|IEEEdouble
decl_stmt|;
specifier|static
specifier|const
name|fltSemantics
name|IEEEquad
decl_stmt|;
specifier|static
specifier|const
name|fltSemantics
name|PPCDoubleDouble
decl_stmt|;
specifier|static
specifier|const
name|fltSemantics
name|x87DoubleExtended
decl_stmt|;
comment|/// A Pseudo fltsemantic used to construct APFloats that cannot conflict with
comment|/// anything real.
specifier|static
specifier|const
name|fltSemantics
name|Bogus
decl_stmt|;
comment|/// @}
specifier|static
name|unsigned
name|int
name|semanticsPrecision
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
parameter_list|)
function_decl|;
comment|/// IEEE-754R 5.11: Floating Point Comparison Relations.
enum|enum
name|cmpResult
block|{
name|cmpLessThan
block|,
name|cmpEqual
block|,
name|cmpGreaterThan
block|,
name|cmpUnordered
block|}
enum|;
comment|/// IEEE-754R 4.3: Rounding-direction attributes.
enum|enum
name|roundingMode
block|{
name|rmNearestTiesToEven
block|,
name|rmTowardPositive
block|,
name|rmTowardNegative
block|,
name|rmTowardZero
block|,
name|rmNearestTiesToAway
block|}
enum|;
comment|/// IEEE-754R 7: Default exception handling.
comment|///
comment|/// opUnderflow or opOverflow are always returned or-ed with opInexact.
enum|enum
name|opStatus
block|{
name|opOK
init|=
literal|0x00
block|,
name|opInvalidOp
init|=
literal|0x01
block|,
name|opDivByZero
init|=
literal|0x02
block|,
name|opOverflow
init|=
literal|0x04
block|,
name|opUnderflow
init|=
literal|0x08
block|,
name|opInexact
init|=
literal|0x10
block|}
enum|;
comment|/// Category of internally-represented number.
enum|enum
name|fltCategory
block|{
name|fcInfinity
block|,
name|fcNaN
block|,
name|fcNormal
block|,
name|fcZero
block|}
enum|;
comment|/// Convenience enum used to construct an uninitialized APFloat.
enum|enum
name|uninitializedTag
block|{
name|uninitialized
block|}
enum|;
comment|/// \name Constructors
comment|/// @{
name|APFloat
argument_list|(
specifier|const
name|fltSemantics
operator|&
argument_list|)
expr_stmt|;
comment|// Default construct to 0.0
name|APFloat
argument_list|(
specifier|const
name|fltSemantics
operator|&
argument_list|,
name|StringRef
argument_list|)
expr_stmt|;
name|APFloat
argument_list|(
specifier|const
name|fltSemantics
operator|&
argument_list|,
name|integerPart
argument_list|)
expr_stmt|;
name|APFloat
argument_list|(
specifier|const
name|fltSemantics
operator|&
argument_list|,
name|uninitializedTag
argument_list|)
expr_stmt|;
name|APFloat
argument_list|(
specifier|const
name|fltSemantics
operator|&
argument_list|,
specifier|const
name|APInt
operator|&
argument_list|)
expr_stmt|;
name|explicit
name|APFloat
parameter_list|(
name|double
name|d
parameter_list|)
function_decl|;
name|explicit
name|APFloat
parameter_list|(
name|float
name|f
parameter_list|)
function_decl|;
name|APFloat
argument_list|(
specifier|const
name|APFloat
operator|&
argument_list|)
expr_stmt|;
operator|~
name|APFloat
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// \brief Returns whether this instance allocated memory.
name|bool
name|needsCleanup
argument_list|()
specifier|const
block|{
return|return
name|partCount
argument_list|()
operator|>
literal|1
return|;
block|}
comment|/// \name Convenience "constructors"
comment|/// @{
comment|/// Factory for Positive and Negative Zero.
comment|///
comment|/// \param Negative True iff the number should be negative.
specifier|static
name|APFloat
name|getZero
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|)
block|{
name|APFloat
name|Val
argument_list|(
name|Sem
argument_list|,
name|uninitialized
argument_list|)
decl_stmt|;
name|Val
operator|.
name|makeZero
argument_list|(
name|Negative
argument_list|)
expr_stmt|;
return|return
name|Val
return|;
block|}
comment|/// Factory for Positive and Negative Infinity.
comment|///
comment|/// \param Negative True iff the number should be negative.
specifier|static
name|APFloat
name|getInf
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|)
block|{
name|APFloat
name|Val
argument_list|(
name|Sem
argument_list|,
name|uninitialized
argument_list|)
decl_stmt|;
name|Val
operator|.
name|makeInf
argument_list|(
name|Negative
argument_list|)
expr_stmt|;
return|return
name|Val
return|;
block|}
comment|/// Factory for QNaN values.
comment|///
comment|/// \param Negative - True iff the NaN generated should be negative.
comment|/// \param type - The unspecified fill bits for creating the NaN, 0 by
comment|/// default.  The value is truncated as necessary.
specifier|static
name|APFloat
name|getNaN
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|,
name|unsigned
name|type
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
name|type
condition|)
block|{
name|APInt
name|fill
argument_list|(
literal|64
argument_list|,
name|type
argument_list|)
decl_stmt|;
return|return
name|getQNaN
argument_list|(
name|Sem
argument_list|,
name|Negative
argument_list|,
operator|&
name|fill
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|getQNaN
argument_list|(
name|Sem
argument_list|,
name|Negative
argument_list|,
literal|0
argument_list|)
return|;
block|}
block|}
comment|/// Factory for QNaN values.
specifier|static
name|APFloat
name|getQNaN
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|,
specifier|const
name|APInt
modifier|*
name|payload
init|=
literal|0
parameter_list|)
block|{
return|return
name|makeNaN
argument_list|(
name|Sem
argument_list|,
name|false
argument_list|,
name|Negative
argument_list|,
name|payload
argument_list|)
return|;
block|}
comment|/// Factory for SNaN values.
specifier|static
name|APFloat
name|getSNaN
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|,
specifier|const
name|APInt
modifier|*
name|payload
init|=
literal|0
parameter_list|)
block|{
return|return
name|makeNaN
argument_list|(
name|Sem
argument_list|,
name|true
argument_list|,
name|Negative
argument_list|,
name|payload
argument_list|)
return|;
block|}
comment|/// Returns the largest finite number in the given semantics.
comment|///
comment|/// \param Negative - True iff the number should be negative
specifier|static
name|APFloat
name|getLargest
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Returns the smallest (by magnitude) finite number in the given semantics.
comment|/// Might be denormalized, which implies a relative loss of precision.
comment|///
comment|/// \param Negative - True iff the number should be negative
specifier|static
name|APFloat
name|getSmallest
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Returns the smallest (by magnitude) normalized finite number in the given
comment|/// semantics.
comment|///
comment|/// \param Negative - True iff the number should be negative
specifier|static
name|APFloat
name|getSmallestNormalized
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|Negative
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Returns a float which is bitcasted from an all one value int.
comment|///
comment|/// \param BitWidth - Select float type
comment|/// \param isIEEE   - If 128 bit number, select between PPC and IEEE
specifier|static
name|APFloat
name|getAllOnesValue
parameter_list|(
name|unsigned
name|BitWidth
parameter_list|,
name|bool
name|isIEEE
init|=
name|false
parameter_list|)
function_decl|;
comment|/// @}
comment|/// Used to insert APFloat objects, or objects that contain APFloat objects,
comment|/// into FoldingSets.
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|NID
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Used by the Bitcode serializer to emit APInts to Bitcode.
name|void
name|Emit
argument_list|(
name|Serializer
operator|&
name|S
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Used by the Bitcode deserializer to deserialize APInts.
specifier|static
name|APFloat
name|ReadVal
parameter_list|(
name|Deserializer
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// \name Arithmetic
comment|/// @{
name|opStatus
name|add
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|subtract
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|multiply
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|divide
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
comment|/// IEEE remainder.
name|opStatus
name|remainder
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
comment|/// C fmod, or llvm frem.
name|opStatus
name|mod
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|fusedMultiplyAdd
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|roundToIntegral
parameter_list|(
name|roundingMode
parameter_list|)
function_decl|;
comment|/// IEEE-754R 5.3.1: nextUp/nextDown.
name|opStatus
name|next
parameter_list|(
name|bool
name|nextDown
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Sign operations.
comment|/// @{
name|void
name|changeSign
parameter_list|()
function_decl|;
name|void
name|clearSign
parameter_list|()
function_decl|;
name|void
name|copySign
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Conversions
comment|/// @{
name|opStatus
name|convert
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
parameter_list|,
name|roundingMode
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
name|opStatus
name|convertToInteger
argument_list|(
name|integerPart
operator|*
argument_list|,
name|unsigned
name|int
argument_list|,
name|bool
argument_list|,
name|roundingMode
argument_list|,
name|bool
operator|*
argument_list|)
decl|const
decl_stmt|;
name|opStatus
name|convertToInteger
argument_list|(
name|APSInt
operator|&
argument_list|,
name|roundingMode
argument_list|,
name|bool
operator|*
argument_list|)
decl|const
decl_stmt|;
name|opStatus
name|convertFromAPInt
parameter_list|(
specifier|const
name|APInt
modifier|&
parameter_list|,
name|bool
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|convertFromSignExtendedInteger
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|bool
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|convertFromZeroExtendedInteger
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|bool
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|convertFromString
parameter_list|(
name|StringRef
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|APInt
name|bitcastToAPInt
argument_list|()
specifier|const
expr_stmt|;
name|double
name|convertToDouble
argument_list|()
specifier|const
expr_stmt|;
name|float
name|convertToFloat
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// The definition of equality is not straightforward for floating point, so
comment|/// we won't use operator==.  Use one of the following, or write whatever it
comment|/// is you really mean.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|APFloat
operator|&
operator|)
specifier|const
name|LLVM_DELETED_FUNCTION
expr_stmt|;
comment|/// IEEE comparison with another floating point number (NaNs compare
comment|/// unordered, 0==-0).
name|cmpResult
name|compare
argument_list|(
specifier|const
name|APFloat
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// Bitwise comparison for equality (QNaNs compare equal, 0!=-0).
name|bool
name|bitwiseIsEqual
argument_list|(
specifier|const
name|APFloat
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// Write out a hexadecimal representation of the floating point value to DST,
comment|/// which must be of sufficient size, in the C99 form [-]0xh.hhhhp[+-]d.
comment|/// Return the number of characters written, excluding the terminating NUL.
name|unsigned
name|int
name|convertToHexString
argument_list|(
name|char
operator|*
name|dst
argument_list|,
name|unsigned
name|int
name|hexDigits
argument_list|,
name|bool
name|upperCase
argument_list|,
name|roundingMode
argument_list|)
decl|const
decl_stmt|;
comment|/// \name IEEE-754R 5.7.2 General operations.
comment|/// @{
comment|/// IEEE-754R isSignMinus: Returns true if and only if the current value is
comment|/// negative.
comment|///
comment|/// This applies to zeros and NaNs as well.
name|bool
name|isNegative
argument_list|()
specifier|const
block|{
return|return
name|sign
return|;
block|}
comment|/// IEEE-754R isNormal: Returns true if and only if the current value is normal.
comment|///
comment|/// This implies that the current value of the float is not zero, subnormal,
comment|/// infinite, or NaN following the definition of normality from IEEE-754R.
name|bool
name|isNormal
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isDenormal
argument_list|()
operator|&&
name|isFiniteNonZero
argument_list|()
return|;
block|}
comment|/// Returns true if and only if the current value is zero, subnormal, or
comment|/// normal.
comment|///
comment|/// This means that the value is not infinite or NaN.
name|bool
name|isFinite
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isNaN
argument_list|()
operator|&&
operator|!
name|isInfinity
argument_list|()
return|;
block|}
comment|/// Returns true if and only if the float is plus or minus zero.
name|bool
name|isZero
argument_list|()
specifier|const
block|{
return|return
name|category
operator|==
name|fcZero
return|;
block|}
comment|/// IEEE-754R isSubnormal(): Returns true if and only if the float is a
comment|/// denormal.
name|bool
name|isDenormal
argument_list|()
specifier|const
expr_stmt|;
comment|/// IEEE-754R isInfinite(): Returns true if and only if the float is infinity.
name|bool
name|isInfinity
argument_list|()
specifier|const
block|{
return|return
name|category
operator|==
name|fcInfinity
return|;
block|}
comment|/// Returns true if and only if the float is a quiet or signaling NaN.
name|bool
name|isNaN
argument_list|()
specifier|const
block|{
return|return
name|category
operator|==
name|fcNaN
return|;
block|}
comment|/// Returns true if and only if the float is a signaling NaN.
name|bool
name|isSignaling
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// \name Simple Queries
comment|/// @{
name|fltCategory
name|getCategory
argument_list|()
specifier|const
block|{
return|return
name|category
return|;
block|}
specifier|const
name|fltSemantics
operator|&
name|getSemantics
argument_list|()
specifier|const
block|{
return|return
operator|*
name|semantics
return|;
block|}
name|bool
name|isNonZero
argument_list|()
specifier|const
block|{
return|return
name|category
operator|!=
name|fcZero
return|;
block|}
name|bool
name|isFiniteNonZero
argument_list|()
specifier|const
block|{
return|return
name|isFinite
argument_list|()
operator|&&
operator|!
name|isZero
argument_list|()
return|;
block|}
name|bool
name|isPosZero
argument_list|()
specifier|const
block|{
return|return
name|isZero
argument_list|()
operator|&&
operator|!
name|isNegative
argument_list|()
return|;
block|}
name|bool
name|isNegZero
argument_list|()
specifier|const
block|{
return|return
name|isZero
argument_list|()
operator|&&
name|isNegative
argument_list|()
return|;
block|}
comment|/// Returns true if and only if the number has the smallest possible non-zero
comment|/// magnitude in the current semantics.
name|bool
name|isSmallest
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns true if and only if the number has the largest possible finite
comment|/// magnitude in the current semantics.
name|bool
name|isLargest
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
name|APFloat
modifier|&
name|operator
init|=
operator|(
specifier|const
name|APFloat
operator|&
operator|)
decl_stmt|;
comment|/// \brief Overload to compute a hash code for an APFloat value.
comment|///
comment|/// Note that the use of hash codes for floating point values is in general
comment|/// frought with peril. Equality is hard to define for these values. For
comment|/// example, should negative and positive zero hash to different codes? Are
comment|/// they equal or not? This hash value implementation specifically
comment|/// emphasizes producing different codes for different inputs in order to
comment|/// be used in canonicalization and memoization. As such, equality is
comment|/// bitwiseIsEqual, and 0 != -0.
name|friend
name|hash_code
name|hash_value
parameter_list|(
specifier|const
name|APFloat
modifier|&
name|Arg
parameter_list|)
function_decl|;
comment|/// Converts this value into a decimal string.
comment|///
comment|/// \param FormatPrecision The maximum number of digits of
comment|///   precision to output.  If there are fewer digits available,
comment|///   zero padding will not be used unless the value is
comment|///   integral and small enough to be expressed in
comment|///   FormatPrecision digits.  0 means to use the natural
comment|///   precision of the number.
comment|/// \param FormatMaxPadding The maximum number of zeros to
comment|///   consider inserting before falling back to scientific
comment|///   notation.  0 means to always use scientific notation.
comment|///
comment|/// Number       Precision    MaxPadding      Result
comment|/// ------       ---------    ----------      ------
comment|/// 1.01E+4              5             2       10100
comment|/// 1.01E+4              4             2       1.01E+4
comment|/// 1.01E+4              5             1       1.01E+4
comment|/// 1.01E-2              5             2       0.0101
comment|/// 1.01E-2              4             2       0.0101
comment|/// 1.01E-2              4             1       1.01E-2
name|void
name|toString
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Str
argument_list|,
name|unsigned
name|FormatPrecision
operator|=
literal|0
argument_list|,
name|unsigned
name|FormatMaxPadding
operator|=
literal|3
argument_list|)
decl|const
decl_stmt|;
comment|/// If this value has an exact multiplicative inverse, store it in inv and
comment|/// return true.
name|bool
name|getExactInverse
argument_list|(
name|APFloat
operator|*
name|inv
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// \name Simple Queries
comment|/// @{
name|integerPart
modifier|*
name|significandParts
parameter_list|()
function_decl|;
specifier|const
name|integerPart
operator|*
name|significandParts
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|int
name|partCount
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// \name Significand operations.
comment|/// @{
name|integerPart
name|addSignificand
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
name|integerPart
name|subtractSignificand
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|integerPart
parameter_list|)
function_decl|;
name|lostFraction
name|addOrSubtractSignificand
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|bool
name|subtract
parameter_list|)
function_decl|;
name|lostFraction
name|multiplySignificand
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
specifier|const
name|APFloat
modifier|*
parameter_list|)
function_decl|;
name|lostFraction
name|divideSignificand
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
name|void
name|incrementSignificand
parameter_list|()
function_decl|;
name|void
name|initialize
parameter_list|(
specifier|const
name|fltSemantics
modifier|*
parameter_list|)
function_decl|;
name|void
name|shiftSignificandLeft
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
name|lostFraction
name|shiftSignificandRight
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
name|unsigned
name|int
name|significandLSB
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|int
name|significandMSB
argument_list|()
specifier|const
expr_stmt|;
name|void
name|zeroSignificand
parameter_list|()
function_decl|;
comment|/// Return true if the significand excluding the integral bit is all ones.
name|bool
name|isSignificandAllOnes
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if the significand excluding the integral bit is all zeros.
name|bool
name|isSignificandAllZeros
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// \name Arithmetic on special values.
comment|/// @{
name|opStatus
name|addOrSubtractSpecials
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|bool
name|subtract
parameter_list|)
function_decl|;
name|opStatus
name|divideSpecials
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
name|opStatus
name|multiplySpecials
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
name|opStatus
name|modSpecials
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Special value setters.
comment|/// @{
name|void
name|makeLargest
parameter_list|(
name|bool
name|Neg
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|makeSmallest
parameter_list|(
name|bool
name|Neg
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|makeNaN
parameter_list|(
name|bool
name|SNaN
init|=
name|false
parameter_list|,
name|bool
name|Neg
init|=
name|false
parameter_list|,
specifier|const
name|APInt
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|APFloat
name|makeNaN
parameter_list|(
specifier|const
name|fltSemantics
modifier|&
name|Sem
parameter_list|,
name|bool
name|SNaN
parameter_list|,
name|bool
name|Negative
parameter_list|,
specifier|const
name|APInt
modifier|*
name|fill
parameter_list|)
function_decl|;
name|void
name|makeInf
parameter_list|(
name|bool
name|Neg
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|makeZero
parameter_list|(
name|bool
name|Neg
init|=
name|false
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Miscellany
comment|/// @{
name|bool
name|convertFromStringSpecials
parameter_list|(
name|StringRef
name|str
parameter_list|)
function_decl|;
name|opStatus
name|normalize
parameter_list|(
name|roundingMode
parameter_list|,
name|lostFraction
parameter_list|)
function_decl|;
name|opStatus
name|addOrSubtract
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|,
name|roundingMode
parameter_list|,
name|bool
name|subtract
parameter_list|)
function_decl|;
name|cmpResult
name|compareAbsoluteValue
argument_list|(
specifier|const
name|APFloat
operator|&
argument_list|)
decl|const
decl_stmt|;
name|opStatus
name|handleOverflow
parameter_list|(
name|roundingMode
parameter_list|)
function_decl|;
name|bool
name|roundAwayFromZero
argument_list|(
name|roundingMode
argument_list|,
name|lostFraction
argument_list|,
name|unsigned
name|int
argument_list|)
decl|const
decl_stmt|;
name|opStatus
name|convertToSignExtendedInteger
argument_list|(
name|integerPart
operator|*
argument_list|,
name|unsigned
name|int
argument_list|,
name|bool
argument_list|,
name|roundingMode
argument_list|,
name|bool
operator|*
argument_list|)
decl|const
decl_stmt|;
name|opStatus
name|convertFromUnsignedParts
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|convertFromHexadecimalString
parameter_list|(
name|StringRef
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|opStatus
name|convertFromDecimalString
parameter_list|(
name|StringRef
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
name|char
modifier|*
name|convertNormalToHexString
argument_list|(
name|char
operator|*
argument_list|,
name|unsigned
name|int
argument_list|,
name|bool
argument_list|,
name|roundingMode
argument_list|)
decl|const
decl_stmt|;
name|opStatus
name|roundSignificandWithExponent
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|roundingMode
parameter_list|)
function_decl|;
comment|/// @}
name|APInt
name|convertHalfAPFloatToAPInt
argument_list|()
specifier|const
expr_stmt|;
name|APInt
name|convertFloatAPFloatToAPInt
argument_list|()
specifier|const
expr_stmt|;
name|APInt
name|convertDoubleAPFloatToAPInt
argument_list|()
specifier|const
expr_stmt|;
name|APInt
name|convertQuadrupleAPFloatToAPInt
argument_list|()
specifier|const
expr_stmt|;
name|APInt
name|convertF80LongDoubleAPFloatToAPInt
argument_list|()
specifier|const
expr_stmt|;
name|APInt
name|convertPPCDoubleDoubleAPFloatToAPInt
argument_list|()
specifier|const
decl_stmt|;
name|void
name|initFromAPInt
parameter_list|(
specifier|const
name|fltSemantics
modifier|*
name|Sem
parameter_list|,
specifier|const
name|APInt
modifier|&
name|api
parameter_list|)
function_decl|;
name|void
name|initFromHalfAPInt
parameter_list|(
specifier|const
name|APInt
modifier|&
name|api
parameter_list|)
function_decl|;
name|void
name|initFromFloatAPInt
parameter_list|(
specifier|const
name|APInt
modifier|&
name|api
parameter_list|)
function_decl|;
name|void
name|initFromDoubleAPInt
parameter_list|(
specifier|const
name|APInt
modifier|&
name|api
parameter_list|)
function_decl|;
name|void
name|initFromQuadrupleAPInt
parameter_list|(
specifier|const
name|APInt
modifier|&
name|api
parameter_list|)
function_decl|;
name|void
name|initFromF80LongDoubleAPInt
parameter_list|(
specifier|const
name|APInt
modifier|&
name|api
parameter_list|)
function_decl|;
name|void
name|initFromPPCDoubleDoubleAPInt
parameter_list|(
specifier|const
name|APInt
modifier|&
name|api
parameter_list|)
function_decl|;
name|void
name|assign
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
name|void
name|copySignificand
parameter_list|(
specifier|const
name|APFloat
modifier|&
parameter_list|)
function_decl|;
name|void
name|freeSignificand
parameter_list|()
function_decl|;
comment|/// The semantics that this value obeys.
specifier|const
name|fltSemantics
modifier|*
name|semantics
decl_stmt|;
comment|/// A binary fraction with an explicit integer bit.
comment|///
comment|/// The significand must be at least one bit wider than the target precision.
union|union
name|Significand
block|{
name|integerPart
name|part
decl_stmt|;
name|integerPart
modifier|*
name|parts
decl_stmt|;
block|}
name|significand
union|;
comment|/// The signed unbiased exponent of the value.
name|ExponentType
name|exponent
decl_stmt|;
comment|/// What kind of floating point number this is.
comment|///
comment|/// Only 2 bits are required, but VisualStudio incorrectly sign extends it.
comment|/// Using the extra bit keeps it from failing under VisualStudio.
name|fltCategory
name|category
range|:
literal|3
decl_stmt|;
comment|/// Sign bit of the number.
name|unsigned
name|int
name|sign
range|:
literal|1
decl_stmt|;
block|}
empty_stmt|;
comment|/// See friend declaration above.
comment|///
comment|/// This additional declaration is required in order to compile LLVM with IBM
comment|/// xlC compiler.
name|hash_code
name|hash_value
parameter_list|(
specifier|const
name|APFloat
modifier|&
name|Arg
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_APFLOAT_H
end_comment

end_unit

