begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/APInt.h - For Arbitrary Precision Integer -----*- C++ -*--===//
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
comment|// This file implements a class to represent arbitrary precision integral
end_comment

begin_comment
comment|// constant values and operations on them.
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
name|LLVM_APINT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_APINT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
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
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Serializer
decl_stmt|;
name|class
name|Deserializer
decl_stmt|;
name|class
name|FoldingSetNodeID
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|// An unsigned host type used as a single part of a multi-part
comment|// bignum.
typedef|typedef
name|uint64_t
name|integerPart
typedef|;
specifier|const
name|unsigned
name|int
name|host_char_bit
init|=
literal|8
decl_stmt|;
specifier|const
name|unsigned
name|int
name|integerPartWidth
init|=
name|host_char_bit
operator|*
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
sizeof|sizeof
argument_list|(
name|integerPart
argument_list|)
operator|)
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                              APInt Class
comment|//===----------------------------------------------------------------------===//
comment|/// APInt - This class represents arbitrary precision constant integral values.
comment|/// It is a functional replacement for common case unsigned integer type like
comment|/// "unsigned", "unsigned long" or "uint64_t", but also allows non-byte-width
comment|/// integer sizes and large integer value types such as 3-bits, 15-bits, or more
comment|/// than 64-bits of precision. APInt provides a variety of arithmetic operators
comment|/// and methods to manipulate integer values of any bit-width. It supports both
comment|/// the typical integer arithmetic and comparison operations as well as bitwise
comment|/// manipulation.
comment|///
comment|/// The class has several invariants worth noting:
comment|///   * All bit, byte, and word positions are zero-based.
comment|///   * Once the bit width is set, it doesn't change except by the Truncate,
comment|///     SignExtend, or ZeroExtend operations.
comment|///   * All binary operators must be on APInt instances of the same bit width.
comment|///     Attempting to use these operators on instances with different bit
comment|///     widths will yield an assertion.
comment|///   * The value is stored canonically as an unsigned value. For operations
comment|///     where it makes a difference, there are both signed and unsigned variants
comment|///     of the operation. For example, sdiv and udiv. However, because the bit
comment|///     widths must be the same, operations such as Mul and Add produce the same
comment|///     results regardless of whether the values are interpreted as signed or
comment|///     not.
comment|///   * In general, the class tries to follow the style of computation that LLVM
comment|///     uses in its IR. This simplifies its use for LLVM.
comment|///
comment|/// @brief Class for arbitrary precision integers.
name|class
name|APInt
block|{
name|unsigned
name|BitWidth
decl_stmt|;
comment|///< The number of bits in this APInt.
comment|/// This union is used to store the integer value. When the
comment|/// integer bit-width<= 64, it uses VAL, otherwise it uses pVal.
union|union
block|{
name|uint64_t
name|VAL
decl_stmt|;
comment|///< Used to store the<= 64 bits integer value.
name|uint64_t
modifier|*
name|pVal
decl_stmt|;
comment|///< Used to store the>64 bits integer value.
block|}
union|;
comment|/// This enum is used to hold the constants we needed for APInt.
enum|enum
block|{
comment|/// Bits in a word
name|APINT_BITS_PER_WORD
init|=
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|)
operator|*
name|CHAR_BIT
block|,
comment|/// Byte size of a word
name|APINT_WORD_SIZE
init|=
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|)
block|}
enum|;
comment|/// This constructor is used only internally for speed of construction of
comment|/// temporaries. It is unsafe for general use so it is not public.
comment|/// @brief Fast internal constructor
name|APInt
argument_list|(
argument|uint64_t* val
argument_list|,
argument|unsigned bits
argument_list|)
block|:
name|BitWidth
argument_list|(
name|bits
argument_list|)
operator|,
name|pVal
argument_list|(
argument|val
argument_list|)
block|{ }
comment|/// @returns true if the number of bits<= 64, false otherwise.
comment|/// @brief Determine if this APInt just has one word to store value.
name|bool
name|isSingleWord
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|<=
name|APINT_BITS_PER_WORD
return|;
block|}
comment|/// @returns the word position for the specified bit position.
comment|/// @brief Determine which word a bit is in.
specifier|static
name|unsigned
name|whichWord
parameter_list|(
name|unsigned
name|bitPosition
parameter_list|)
block|{
return|return
name|bitPosition
operator|/
name|APINT_BITS_PER_WORD
return|;
block|}
comment|/// @returns the bit position in a word for the specified bit position
comment|/// in the APInt.
comment|/// @brief Determine which bit in a word a bit is in.
specifier|static
name|unsigned
name|whichBit
parameter_list|(
name|unsigned
name|bitPosition
parameter_list|)
block|{
return|return
name|bitPosition
operator|%
name|APINT_BITS_PER_WORD
return|;
block|}
comment|/// This method generates and returns a uint64_t (word) mask for a single
comment|/// bit at a specific bit position. This is used to mask the bit in the
comment|/// corresponding word.
comment|/// @returns a uint64_t with only bit at "whichBit(bitPosition)" set
comment|/// @brief Get a single bit mask.
specifier|static
name|uint64_t
name|maskBit
parameter_list|(
name|unsigned
name|bitPosition
parameter_list|)
block|{
return|return
literal|1ULL
operator|<<
name|whichBit
argument_list|(
name|bitPosition
argument_list|)
return|;
block|}
comment|/// This method is used internally to clear the to "N" bits in the high order
comment|/// word that are not used by the APInt. This is needed after the most
comment|/// significant word is assigned a value to ensure that those bits are
comment|/// zero'd out.
comment|/// @brief Clear unused high order bits
name|APInt
modifier|&
name|clearUnusedBits
parameter_list|()
block|{
comment|// Compute how many bits are used in the final word
name|unsigned
name|wordBits
init|=
name|BitWidth
operator|%
name|APINT_BITS_PER_WORD
decl_stmt|;
if|if
condition|(
name|wordBits
operator|==
literal|0
condition|)
comment|// If all bits are used, we want to leave the value alone. This also
comment|// avoids the undefined behavior of>> when the shift is the same size as
comment|// the word size (64).
return|return
operator|*
name|this
return|;
comment|// Mask out the high bits.
name|uint64_t
name|mask
init|=
operator|~
name|uint64_t
argument_list|(
literal|0ULL
argument_list|)
operator|>>
operator|(
name|APINT_BITS_PER_WORD
operator|-
name|wordBits
operator|)
decl_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|VAL
operator|&=
name|mask
expr_stmt|;
else|else
name|pVal
index|[
name|getNumWords
argument_list|()
operator|-
literal|1
index|]
operator|&=
name|mask
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// @returns the corresponding word for the specified bit position.
comment|/// @brief Get the word corresponding to a bit position
name|uint64_t
name|getWord
argument_list|(
name|unsigned
name|bitPosition
argument_list|)
decl|const
block|{
return|return
name|isSingleWord
argument_list|()
condition|?
name|VAL
else|:
name|pVal
index|[
name|whichWord
argument_list|(
name|bitPosition
argument_list|)
index|]
return|;
block|}
comment|/// This is used by the constructors that take string arguments.
comment|/// @brief Convert a char array into an APInt
name|void
name|fromString
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
specifier|const
name|StringRef
modifier|&
name|str
parameter_list|,
name|uint8_t
name|radix
parameter_list|)
function_decl|;
comment|/// This is used by the toString method to divide by the radix. It simply
comment|/// provides a more convenient form of divide for internal use since KnuthDiv
comment|/// has specific constraints on its inputs. If those constraints are not met
comment|/// then it provides a simpler form of divide.
comment|/// @brief An internal division function for dividing APInts.
specifier|static
name|void
name|divide
parameter_list|(
specifier|const
name|APInt
name|LHS
parameter_list|,
name|unsigned
name|lhsWords
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|,
name|unsigned
name|rhsWords
parameter_list|,
name|APInt
modifier|*
name|Quotient
parameter_list|,
name|APInt
modifier|*
name|Remainder
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for inline constructor
name|void
name|initSlowCase
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
name|uint64_t
name|val
parameter_list|,
name|bool
name|isSigned
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for inline copy constructor
name|void
name|initSlowCase
parameter_list|(
specifier|const
name|APInt
modifier|&
name|that
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for shl
name|APInt
name|shlSlowCase
argument_list|(
name|unsigned
name|shiftAmt
argument_list|)
decl|const
decl_stmt|;
comment|/// out-of-line slow case for operator&
name|APInt
name|AndSlowCase
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// out-of-line slow case for operator|
name|APInt
name|OrSlowCase
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// out-of-line slow case for operator^
name|APInt
name|XorSlowCase
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// out-of-line slow case for operator=
name|APInt
modifier|&
name|AssignSlowCase
parameter_list|(
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for operator==
name|bool
name|EqualSlowCase
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// out-of-line slow case for operator==
name|bool
name|EqualSlowCase
argument_list|(
name|uint64_t
name|Val
argument_list|)
decl|const
decl_stmt|;
comment|/// out-of-line slow case for countLeadingZeros
name|unsigned
name|countLeadingZerosSlowCase
argument_list|()
specifier|const
expr_stmt|;
comment|/// out-of-line slow case for countTrailingOnes
name|unsigned
name|countTrailingOnesSlowCase
argument_list|()
specifier|const
expr_stmt|;
comment|/// out-of-line slow case for countPopulation
name|unsigned
name|countPopulationSlowCase
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
comment|/// @name Constructors
comment|/// @{
comment|/// If isSigned is true then val is treated as if it were a signed value
comment|/// (i.e. as an int64_t) and the appropriate sign extension to the bit width
comment|/// will be done. Otherwise, no sign extension occurs (high order bits beyond
comment|/// the range of val are zero filled).
comment|/// @param numBits the bit width of the constructed APInt
comment|/// @param val the initial value of the APInt
comment|/// @param isSigned how to treat signedness of val
comment|/// @brief Create a new APInt of numBits width, initialized as val.
name|APInt
argument_list|(
argument|unsigned numBits
argument_list|,
argument|uint64_t val
argument_list|,
argument|bool isSigned = false
argument_list|)
block|:
name|BitWidth
argument_list|(
name|numBits
argument_list|)
operator|,
name|VAL
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
name|BitWidth
operator|&&
literal|"bitwidth too small"
argument_list|)
block|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|VAL
operator|=
name|val
expr_stmt|;
else|else
name|initSlowCase
argument_list|(
name|numBits
argument_list|,
name|val
argument_list|,
name|isSigned
argument_list|)
expr_stmt|;
name|clearUnusedBits
argument_list|()
expr_stmt|;
block|}
comment|/// Note that numWords can be smaller or larger than the corresponding bit
comment|/// width but any extraneous bits will be dropped.
comment|/// @param numBits the bit width of the constructed APInt
comment|/// @param numWords the number of words in bigVal
comment|/// @param bigVal a sequence of words to form the initial value of the APInt
comment|/// @brief Construct an APInt of numBits width, initialized as bigVal[].
name|APInt
argument_list|(
argument|unsigned numBits
argument_list|,
argument|unsigned numWords
argument_list|,
argument|const uint64_t bigVal[]
argument_list|)
empty_stmt|;
comment|/// This constructor interprets the string \arg str in the given radix. The
comment|/// interpretation stops when the first character that is not suitable for the
comment|/// radix is encountered, or the end of the string. Acceptable radix values
comment|/// are 2, 8, 10 and 16. It is an error for the value implied by the string to
comment|/// require more bits than numBits.
comment|///
comment|/// @param numBits the bit width of the constructed APInt
comment|/// @param str the string to be interpreted
comment|/// @param radix the radix to use for the conversion
comment|/// @brief Construct an APInt from a string representation.
name|APInt
argument_list|(
argument|unsigned numBits
argument_list|,
argument|const StringRef&str
argument_list|,
argument|uint8_t radix
argument_list|)
empty_stmt|;
comment|/// Simply makes *this a copy of that.
comment|/// @brief Copy Constructor.
name|APInt
argument_list|(
specifier|const
name|APInt
operator|&
name|that
argument_list|)
operator|:
name|BitWidth
argument_list|(
name|that
operator|.
name|BitWidth
argument_list|)
operator|,
name|VAL
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
name|BitWidth
operator|&&
literal|"bitwidth too small"
argument_list|)
block|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|VAL
operator|=
name|that
operator|.
name|VAL
expr_stmt|;
else|else
name|initSlowCase
argument_list|(
name|that
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Destructor.
operator|~
name|APInt
argument_list|()
block|{
if|if
condition|(
operator|!
name|isSingleWord
argument_list|()
condition|)
name|delete
index|[]
name|pVal
decl_stmt|;
block|}
comment|/// Default constructor that creates an uninitialized APInt.  This is useful
comment|///  for object deserialization (pair this with the static method Read).
name|explicit
name|APInt
argument_list|()
operator|:
name|BitWidth
argument_list|(
literal|1
argument_list|)
block|{}
comment|/// Profile - Used to insert APInt objects, or objects that contain APInt
comment|///  objects, into FoldingSets.
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID& id
argument_list|)
specifier|const
expr_stmt|;
comment|/// @brief Used by the Bitcode serializer to emit APInts to Bitcode.
name|void
name|Emit
argument_list|(
name|Serializer
operator|&
name|S
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Used by the Bitcode deserializer to deserialize APInts.
name|void
name|Read
parameter_list|(
name|Deserializer
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Value Tests
comment|/// @{
comment|/// This tests the high bit of this APInt to determine if it is set.
comment|/// @returns true if this APInt is negative, false otherwise
comment|/// @brief Determine sign of this APInt.
name|bool
name|isNegative
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|)
index|[
name|BitWidth
operator|-
literal|1
index|]
return|;
block|}
comment|/// This tests the high bit of the APInt to determine if it is unset.
comment|/// @brief Determine if this APInt Value is non-negative (>= 0)
name|bool
name|isNonNegative
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isNegative
argument_list|()
return|;
block|}
comment|/// This tests if the value of this APInt is positive (> 0). Note
comment|/// that 0 is not a positive value.
comment|/// @returns true if this APInt is positive.
comment|/// @brief Determine if this APInt Value is positive.
name|bool
name|isStrictlyPositive
argument_list|()
specifier|const
block|{
return|return
name|isNonNegative
argument_list|()
operator|&&
operator|(
operator|*
name|this
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// This checks to see if the value has all bits of the APInt are set or not.
comment|/// @brief Determine if all bits are set
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|{
return|return
name|countPopulation
argument_list|()
operator|==
name|BitWidth
return|;
block|}
comment|/// This checks to see if the value of this APInt is the maximum unsigned
comment|/// value for the APInt's bit width.
comment|/// @brief Determine if this is the largest unsigned value.
name|bool
name|isMaxValue
argument_list|()
specifier|const
block|{
return|return
name|countPopulation
argument_list|()
operator|==
name|BitWidth
return|;
block|}
comment|/// This checks to see if the value of this APInt is the maximum signed
comment|/// value for the APInt's bit width.
comment|/// @brief Determine if this is the largest signed value.
name|bool
name|isMaxSignedValue
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|==
literal|1
operator|?
name|VAL
operator|==
literal|0
operator|:
operator|!
name|isNegative
argument_list|()
operator|&&
name|countPopulation
argument_list|()
operator|==
name|BitWidth
operator|-
literal|1
return|;
block|}
comment|/// This checks to see if the value of this APInt is the minimum unsigned
comment|/// value for the APInt's bit width.
comment|/// @brief Determine if this is the smallest unsigned value.
name|bool
name|isMinValue
argument_list|()
specifier|const
block|{
return|return
name|countPopulation
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/// This checks to see if the value of this APInt is the minimum signed
comment|/// value for the APInt's bit width.
comment|/// @brief Determine if this is the smallest signed value.
name|bool
name|isMinSignedValue
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|==
literal|1
operator|?
name|VAL
operator|==
literal|1
operator|:
name|isNegative
argument_list|()
operator|&&
name|countPopulation
argument_list|()
operator|==
literal|1
return|;
block|}
comment|/// @brief Check if this APInt has an N-bits unsigned integer value.
name|bool
name|isIntN
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|&&
literal|"N == 0 ???"
argument_list|)
expr_stmt|;
if|if
condition|(
name|N
operator|>=
name|getBitWidth
argument_list|()
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|VAL
operator|==
operator|(
name|VAL
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
name|APInt
name|Tmp
argument_list|(
name|N
argument_list|,
name|getNumWords
argument_list|()
argument_list|,
name|pVal
argument_list|)
decl_stmt|;
name|Tmp
operator|.
name|zext
argument_list|(
name|getBitWidth
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Tmp
operator|==
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|/// @brief Check if this APInt has an N-bits signed integer value.
name|bool
name|isSignedIntN
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|&&
literal|"N == 0 ???"
argument_list|)
expr_stmt|;
return|return
name|getMinSignedBits
argument_list|()
operator|<=
name|N
return|;
block|}
comment|/// @returns true if the argument APInt value is a power of two> 0.
name|bool
name|isPowerOf2
argument_list|()
specifier|const
expr_stmt|;
comment|/// isSignBit - Return true if this is the value returned by getSignBit.
name|bool
name|isSignBit
argument_list|()
specifier|const
block|{
return|return
name|isMinSignedValue
argument_list|()
return|;
block|}
comment|/// This converts the APInt to a boolean value as a test against zero.
comment|/// @brief Boolean conversion function.
name|bool
name|getBoolValue
argument_list|()
specifier|const
block|{
return|return
operator|*
name|this
operator|!=
literal|0
return|;
block|}
comment|/// getLimitedValue - If this value is smaller than the specified limit,
comment|/// return it, otherwise return the limit value.  This causes the value
comment|/// to saturate to the limit.
name|uint64_t
name|getLimitedValue
argument_list|(
name|uint64_t
name|Limit
operator|=
operator|~
literal|0ULL
argument_list|)
decl|const
block|{
return|return
operator|(
name|getActiveBits
argument_list|()
operator|>
literal|64
operator|||
name|getZExtValue
argument_list|()
operator|>
name|Limit
operator|)
condition|?
name|Limit
else|:
name|getZExtValue
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Value Generators
comment|/// @{
comment|/// @brief Gets maximum unsigned value of APInt for specific bit width.
specifier|static
name|APInt
name|getMaxValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
operator|.
name|set
argument_list|()
return|;
block|}
comment|/// @brief Gets maximum signed value of APInt for a specific bit width.
specifier|static
name|APInt
name|getSignedMaxValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
operator|.
name|set
argument_list|()
operator|.
name|clear
argument_list|(
name|numBits
operator|-
literal|1
argument_list|)
return|;
block|}
comment|/// @brief Gets minimum unsigned value of APInt for a specific bit width.
specifier|static
name|APInt
name|getMinValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// @brief Gets minimum signed value of APInt for a specific bit width.
specifier|static
name|APInt
name|getSignedMinValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
operator|.
name|set
argument_list|(
name|numBits
operator|-
literal|1
argument_list|)
return|;
block|}
comment|/// getSignBit - This is just a wrapper function of getSignedMinValue(), and
comment|/// it helps code readability when we want to get a SignBit.
comment|/// @brief Get the SignBit for a specific bit width.
specifier|static
name|APInt
name|getSignBit
parameter_list|(
name|unsigned
name|BitWidth
parameter_list|)
block|{
return|return
name|getSignedMinValue
argument_list|(
name|BitWidth
argument_list|)
return|;
block|}
comment|/// @returns the all-ones value for an APInt of the specified bit-width.
comment|/// @brief Get the all-ones value.
specifier|static
name|APInt
name|getAllOnesValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
operator|.
name|set
argument_list|()
return|;
block|}
comment|/// @returns the '0' value for an APInt of the specified bit-width.
comment|/// @brief Get the '0' value.
specifier|static
name|APInt
name|getNullValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// Get an APInt with the same BitWidth as this APInt, just zero mask
comment|/// the low bits and right shift to the least significant bit.
comment|/// @returns the high "numBits" bits of this APInt.
name|APInt
name|getHiBits
argument_list|(
name|unsigned
name|numBits
argument_list|)
decl|const
decl_stmt|;
comment|/// Get an APInt with the same BitWidth as this APInt, just zero mask
comment|/// the high bits.
comment|/// @returns the low "numBits" bits of this APInt.
name|APInt
name|getLoBits
argument_list|(
name|unsigned
name|numBits
argument_list|)
decl|const
decl_stmt|;
comment|/// Constructs an APInt value that has a contiguous range of bits set. The
comment|/// bits from loBit (inclusive) to hiBit (exclusive) will be set. All other
comment|/// bits will be zero. For example, with parameters(32, 0, 16) you would get
comment|/// 0x0000FFFF. If hiBit is less than loBit then the set bits "wrap". For
comment|/// example, with parameters (32, 28, 4), you would get 0xF000000F.
comment|/// @param numBits the intended bit width of the result
comment|/// @param loBit the index of the lowest bit set.
comment|/// @param hiBit the index of the highest bit set.
comment|/// @returns An APInt value with the requested bits set.
comment|/// @brief Get a value with a block of bits set.
specifier|static
name|APInt
name|getBitsSet
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
name|unsigned
name|loBit
parameter_list|,
name|unsigned
name|hiBit
parameter_list|)
block|{
name|assert
argument_list|(
name|hiBit
operator|<=
name|numBits
operator|&&
literal|"hiBit out of range"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|loBit
operator|<
name|numBits
operator|&&
literal|"loBit out of range"
argument_list|)
expr_stmt|;
if|if
condition|(
name|hiBit
operator|<
name|loBit
condition|)
return|return
name|getLowBitsSet
argument_list|(
name|numBits
argument_list|,
name|hiBit
argument_list|)
operator||
name|getHighBitsSet
argument_list|(
name|numBits
argument_list|,
name|numBits
operator|-
name|loBit
argument_list|)
return|;
return|return
name|getLowBitsSet
argument_list|(
name|numBits
argument_list|,
name|hiBit
operator|-
name|loBit
argument_list|)
operator|.
name|shl
argument_list|(
name|loBit
argument_list|)
return|;
block|}
comment|/// Constructs an APInt value that has the top hiBitsSet bits set.
comment|/// @param numBits the bitwidth of the result
comment|/// @param hiBitsSet the number of high-order bits set in the result.
comment|/// @brief Get a value with high bits set
specifier|static
name|APInt
name|getHighBitsSet
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
name|unsigned
name|hiBitsSet
parameter_list|)
block|{
name|assert
argument_list|(
name|hiBitsSet
operator|<=
name|numBits
operator|&&
literal|"Too many bits to set!"
argument_list|)
expr_stmt|;
comment|// Handle a degenerate case, to avoid shifting by word size
if|if
condition|(
name|hiBitsSet
operator|==
literal|0
condition|)
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
return|;
name|unsigned
name|shiftAmt
init|=
name|numBits
operator|-
name|hiBitsSet
decl_stmt|;
comment|// For small values, return quickly
if|if
condition|(
name|numBits
operator|<=
name|APINT_BITS_PER_WORD
condition|)
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
operator|~
literal|0ULL
operator|<<
name|shiftAmt
argument_list|)
return|;
return|return
operator|(
operator|~
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
operator|)
operator|.
name|shl
argument_list|(
name|shiftAmt
argument_list|)
return|;
block|}
comment|/// Constructs an APInt value that has the bottom loBitsSet bits set.
comment|/// @param numBits the bitwidth of the result
comment|/// @param loBitsSet the number of low-order bits set in the result.
comment|/// @brief Get a value with low bits set
specifier|static
name|APInt
name|getLowBitsSet
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
name|unsigned
name|loBitsSet
parameter_list|)
block|{
name|assert
argument_list|(
name|loBitsSet
operator|<=
name|numBits
operator|&&
literal|"Too many bits to set!"
argument_list|)
expr_stmt|;
comment|// Handle a degenerate case, to avoid shifting by word size
if|if
condition|(
name|loBitsSet
operator|==
literal|0
condition|)
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
return|;
if|if
condition|(
name|loBitsSet
operator|==
name|APINT_BITS_PER_WORD
condition|)
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
operator|-
literal|1ULL
argument_list|)
return|;
comment|// For small values, return quickly.
if|if
condition|(
name|numBits
operator|<
name|APINT_BITS_PER_WORD
condition|)
return|return
name|APInt
argument_list|(
name|numBits
argument_list|,
operator|(
literal|1ULL
operator|<<
name|loBitsSet
operator|)
operator|-
literal|1
argument_list|)
return|;
return|return
operator|(
operator|~
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
operator|)
operator|.
name|lshr
argument_list|(
name|numBits
operator|-
name|loBitsSet
argument_list|)
return|;
block|}
comment|/// The hash value is computed as the sum of the words and the bit width.
comment|/// @returns A hash value computed from the sum of the APInt words.
comment|/// @brief Get a hash value based on this APInt
name|uint64_t
name|getHashValue
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function returns a pointer to the internal storage of the APInt.
comment|/// This is useful for writing out the APInt in binary form without any
comment|/// conversions.
specifier|const
name|uint64_t
operator|*
name|getRawData
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
operator|&
name|VAL
return|;
return|return
operator|&
name|pVal
index|[
literal|0
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Unary Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// @returns a new APInt value representing *this incremented by one
end_comment

begin_comment
comment|/// @brief Postfix increment operator.
end_comment

begin_expr_stmt
specifier|const
name|APInt
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|APInt
name|API
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|API
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @returns *this incremented by one
end_comment

begin_comment
comment|/// @brief Prefix increment operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @returns a new APInt representing *this decremented by one.
end_comment

begin_comment
comment|/// @brief Postfix decrement operator.
end_comment

begin_expr_stmt
specifier|const
name|APInt
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|APInt
name|API
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|--
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|API
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @returns *this decremented by one.
end_comment

begin_comment
comment|/// @brief Prefix decrement operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|--
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Performs a bitwise complement operation on this APInt.
end_comment

begin_comment
comment|/// @returns an APInt that is the bitwise complement of *this
end_comment

begin_comment
comment|/// @brief Unary bitwise complement operator.
end_comment

begin_expr_stmt
name|APInt
name|operator
operator|~
operator|(
operator|)
specifier|const
block|{
name|APInt
name|Result
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|Result
operator|.
name|flip
argument_list|()
block|;
return|return
name|Result
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Negates *this using two's complement logic.
end_comment

begin_comment
comment|/// @returns An APInt value representing the negation of *this.
end_comment

begin_comment
comment|/// @brief Unary negation operator
end_comment

begin_expr_stmt
name|APInt
name|operator
operator|-
operator|(
operator|)
specifier|const
block|{
return|return
name|APInt
argument_list|(
name|BitWidth
argument_list|,
literal|0
argument_list|)
operator|-
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Performs logical negation operation on this APInt.
end_comment

begin_comment
comment|/// @returns true if *this is zero, false otherwise.
end_comment

begin_comment
comment|/// @brief Logical negation operator.
end_comment

begin_expr_stmt
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Assignment Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// @returns *this after assignment of RHS.
end_comment

begin_comment
comment|/// @brief Copy assignment operator.
end_comment

begin_decl_stmt
name|APInt
modifier|&
name|operator
init|=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
block|{
comment|// If the bitwidths are the same, we can avoid mucking with memory
if|if
condition|(
name|isSingleWord
argument_list|()
operator|&&
name|RHS
operator|.
name|isSingleWord
argument_list|()
condition|)
block|{
name|VAL
operator|=
name|RHS
operator|.
name|VAL
expr_stmt|;
name|BitWidth
operator|=
name|RHS
operator|.
name|BitWidth
expr_stmt|;
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
return|return
name|AssignSlowCase
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// The RHS value is assigned to *this. If the significant bits in RHS exceed
end_comment

begin_comment
comment|/// the bit width, the excess bits are truncated. If the bit width is larger
end_comment

begin_comment
comment|/// than 64, the value is zero filled in the unspecified high order bits.
end_comment

begin_comment
comment|/// @returns *this after assignment of RHS value.
end_comment

begin_comment
comment|/// @brief Assignment operator.
end_comment

begin_decl_stmt
name|APInt
modifier|&
name|operator
init|=
operator|(
name|uint64_t
name|RHS
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Performs a bitwise AND operation on this APInt and RHS. The result is
end_comment

begin_comment
comment|/// assigned to *this.
end_comment

begin_comment
comment|/// @returns *this after ANDing with RHS.
end_comment

begin_comment
comment|/// @brief Bitwise AND assignment operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Performs a bitwise OR operation on this APInt and RHS. The result is
end_comment

begin_comment
comment|/// assigned *this;
end_comment

begin_comment
comment|/// @returns *this after ORing with RHS.
end_comment

begin_comment
comment|/// @brief Bitwise OR assignment operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator||=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Performs a bitwise XOR operation on this APInt and RHS. The result is
end_comment

begin_comment
comment|/// assigned to *this.
end_comment

begin_comment
comment|/// @returns *this after XORing with RHS.
end_comment

begin_comment
comment|/// @brief Bitwise XOR assignment operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|^=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Multiplies this APInt by RHS and assigns the result to *this.
end_comment

begin_comment
comment|/// @returns *this
end_comment

begin_comment
comment|/// @brief Multiplication assignment operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Adds RHS to *this and assigns the result to *this.
end_comment

begin_comment
comment|/// @returns *this
end_comment

begin_comment
comment|/// @brief Addition assignment operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Subtracts RHS from *this and assigns the result to *this.
end_comment

begin_comment
comment|/// @returns *this
end_comment

begin_comment
comment|/// @brief Subtraction assignment operator.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Shifts *this left by shiftAmt and assigns the result to *this.
end_comment

begin_comment
comment|/// @returns *this after shifting left by shiftAmt
end_comment

begin_comment
comment|/// @brief Left-shift assignment function.
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|<<=
operator|(
name|unsigned
name|shiftAmt
operator|)
block|{
operator|*
name|this
operator|=
name|shl
argument_list|(
name|shiftAmt
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Binary Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Performs a bitwise AND operation on *this and RHS.
end_comment

begin_comment
comment|/// @returns An APInt value representing the bitwise AND of *this and RHS.
end_comment

begin_comment
comment|/// @brief Bitwise AND operator.
end_comment

begin_decl_stmt
name|APInt
name|operator
modifier|&
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|BitWidth
operator|==
name|RHS
operator|.
name|BitWidth
operator|&&
literal|"Bit widths must be the same"
argument_list|)
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|APInt
argument_list|(
name|getBitWidth
argument_list|()
argument_list|,
name|VAL
operator|&
name|RHS
operator|.
name|VAL
argument_list|)
return|;
return|return
name|AndSlowCase
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|APInt
name|And
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|operator
operator|&
operator|(
name|RHS
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Performs a bitwise OR operation on *this and RHS.
end_comment

begin_comment
comment|/// @returns An APInt value representing the bitwise OR of *this and RHS.
end_comment

begin_comment
comment|/// @brief Bitwise OR operator.
end_comment

begin_expr_stmt
name|APInt
name|operator
operator||
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|BitWidth
operator|==
name|RHS
operator|.
name|BitWidth
operator|&&
literal|"Bit widths must be the same"
argument_list|)
block|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|APInt
argument_list|(
name|getBitWidth
argument_list|()
argument_list|,
name|VAL
operator||
name|RHS
operator|.
name|VAL
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|OrSlowCase
argument_list|(
name|RHS
argument_list|)
return|;
end_return

begin_macro
unit|}   APInt
name|Or
argument_list|(
argument|const APInt& RHS
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|this
operator|->
name|operator
operator||
operator|(
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Performs a bitwise XOR operation on *this and RHS.
end_comment

begin_comment
comment|/// @returns An APInt value representing the bitwise XOR of *this and RHS.
end_comment

begin_comment
comment|/// @brief Bitwise XOR operator.
end_comment

begin_decl_stmt
name|APInt
name|operator
modifier|^
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|BitWidth
operator|==
name|RHS
operator|.
name|BitWidth
operator|&&
literal|"Bit widths must be the same"
argument_list|)
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|APInt
argument_list|(
name|BitWidth
argument_list|,
name|VAL
operator|^
name|RHS
operator|.
name|VAL
argument_list|)
return|;
return|return
name|XorSlowCase
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|APInt
name|Xor
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|operator
operator|^
operator|(
name|RHS
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Multiplies this APInt by RHS and returns the result.
end_comment

begin_comment
comment|/// @brief Multiplication operator.
end_comment

begin_decl_stmt
name|APInt
name|operator
modifier|*
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Adds RHS to this APInt and returns the result.
end_comment

begin_comment
comment|/// @brief Addition operator.
end_comment

begin_expr_stmt
name|APInt
name|operator
operator|+
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|APInt
name|operator
operator|+
operator|(
name|uint64_t
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|)
operator|+
name|APInt
argument_list|(
name|BitWidth
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Subtracts RHS from this APInt and returns the result.
end_comment

begin_comment
comment|/// @brief Subtraction operator.
end_comment

begin_expr_stmt
name|APInt
name|operator
operator|-
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|APInt
name|operator
operator|-
operator|(
name|uint64_t
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|)
operator|-
name|APInt
argument_list|(
name|BitWidth
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|APInt
name|operator
operator|<<
operator|(
name|unsigned
name|Bits
operator|)
specifier|const
block|{
return|return
name|shl
argument_list|(
name|Bits
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|APInt
name|operator
operator|<<
operator|(
specifier|const
name|APInt
operator|&
name|Bits
operator|)
specifier|const
block|{
return|return
name|shl
argument_list|(
name|Bits
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Arithmetic right-shift this APInt by shiftAmt.
end_comment

begin_comment
comment|/// @brief Arithmetic right-shift function.
end_comment

begin_decl_stmt
name|APInt
name|ashr
argument_list|(
name|unsigned
name|shiftAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Logical right-shift this APInt by shiftAmt.
end_comment

begin_comment
comment|/// @brief Logical right-shift function.
end_comment

begin_decl_stmt
name|APInt
name|lshr
argument_list|(
name|unsigned
name|shiftAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Left-shift this APInt by shiftAmt.
end_comment

begin_comment
comment|/// @brief Left-shift function.
end_comment

begin_decl_stmt
name|APInt
name|shl
argument_list|(
name|unsigned
name|shiftAmt
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|shiftAmt
operator|<=
name|BitWidth
operator|&&
literal|"Invalid shift amount"
argument_list|)
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
if|if
condition|(
name|shiftAmt
operator|==
name|BitWidth
condition|)
return|return
name|APInt
argument_list|(
name|BitWidth
argument_list|,
literal|0
argument_list|)
return|;
comment|// avoid undefined shift results
return|return
name|APInt
argument_list|(
name|BitWidth
argument_list|,
name|VAL
operator|<<
name|shiftAmt
argument_list|)
return|;
block|}
return|return
name|shlSlowCase
argument_list|(
name|shiftAmt
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Rotate left by rotateAmt.
end_comment

begin_decl_stmt
name|APInt
name|rotl
argument_list|(
name|unsigned
name|rotateAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Rotate right by rotateAmt.
end_comment

begin_decl_stmt
name|APInt
name|rotr
argument_list|(
name|unsigned
name|rotateAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Arithmetic right-shift this APInt by shiftAmt.
end_comment

begin_comment
comment|/// @brief Arithmetic right-shift function.
end_comment

begin_decl_stmt
name|APInt
name|ashr
argument_list|(
specifier|const
name|APInt
operator|&
name|shiftAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Logical right-shift this APInt by shiftAmt.
end_comment

begin_comment
comment|/// @brief Logical right-shift function.
end_comment

begin_decl_stmt
name|APInt
name|lshr
argument_list|(
specifier|const
name|APInt
operator|&
name|shiftAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Left-shift this APInt by shiftAmt.
end_comment

begin_comment
comment|/// @brief Left-shift function.
end_comment

begin_decl_stmt
name|APInt
name|shl
argument_list|(
specifier|const
name|APInt
operator|&
name|shiftAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Rotate left by rotateAmt.
end_comment

begin_decl_stmt
name|APInt
name|rotl
argument_list|(
specifier|const
name|APInt
operator|&
name|rotateAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Rotate right by rotateAmt.
end_comment

begin_decl_stmt
name|APInt
name|rotr
argument_list|(
specifier|const
name|APInt
operator|&
name|rotateAmt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Perform an unsigned divide operation on this APInt by RHS. Both this and
end_comment

begin_comment
comment|/// RHS are treated as unsigned quantities for purposes of this division.
end_comment

begin_comment
comment|/// @returns a new APInt value containing the division result
end_comment

begin_comment
comment|/// @brief Unsigned division operation.
end_comment

begin_decl_stmt
name|APInt
name|udiv
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Signed divide this APInt by APInt RHS.
end_comment

begin_comment
comment|/// @brief Signed division function for APInt.
end_comment

begin_decl_stmt
name|APInt
name|sdiv
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
if|if
condition|(
name|isNegative
argument_list|()
condition|)
if|if
condition|(
name|RHS
operator|.
name|isNegative
argument_list|()
condition|)
return|return
operator|(
operator|-
operator|(
operator|*
name|this
operator|)
operator|)
operator|.
name|udiv
argument_list|(
operator|-
name|RHS
argument_list|)
return|;
else|else
return|return
operator|-
operator|(
operator|(
operator|-
operator|(
operator|*
name|this
operator|)
operator|)
operator|.
name|udiv
argument_list|(
name|RHS
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|RHS
operator|.
name|isNegative
argument_list|()
condition|)
return|return
operator|-
operator|(
name|this
operator|->
name|udiv
argument_list|(
operator|-
name|RHS
argument_list|)
operator|)
return|;
return|return
name|this
operator|->
name|udiv
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Perform an unsigned remainder operation on this APInt with RHS being the
end_comment

begin_comment
comment|/// divisor. Both this and RHS are treated as unsigned quantities for purposes
end_comment

begin_comment
comment|/// of this operation. Note that this is a true remainder operation and not
end_comment

begin_comment
comment|/// a modulo operation because the sign follows the sign of the dividend
end_comment

begin_comment
comment|/// which is *this.
end_comment

begin_comment
comment|/// @returns a new APInt value containing the remainder result
end_comment

begin_comment
comment|/// @brief Unsigned remainder operation.
end_comment

begin_decl_stmt
name|APInt
name|urem
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Signed remainder operation on APInt.
end_comment

begin_comment
comment|/// @brief Function for signed remainder operation.
end_comment

begin_decl_stmt
name|APInt
name|srem
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
if|if
condition|(
name|isNegative
argument_list|()
condition|)
if|if
condition|(
name|RHS
operator|.
name|isNegative
argument_list|()
condition|)
return|return
operator|-
operator|(
operator|(
operator|-
operator|(
operator|*
name|this
operator|)
operator|)
operator|.
name|urem
argument_list|(
operator|-
name|RHS
argument_list|)
operator|)
return|;
else|else
return|return
operator|-
operator|(
operator|(
operator|-
operator|(
operator|*
name|this
operator|)
operator|)
operator|.
name|urem
argument_list|(
name|RHS
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|RHS
operator|.
name|isNegative
argument_list|()
condition|)
return|return
name|this
operator|->
name|urem
argument_list|(
operator|-
name|RHS
argument_list|)
return|;
return|return
name|this
operator|->
name|urem
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Sometimes it is convenient to divide two APInt values and obtain both the
end_comment

begin_comment
comment|/// quotient and remainder. This function does both operations in the same
end_comment

begin_comment
comment|/// computation making it a little more efficient. The pair of input arguments
end_comment

begin_comment
comment|/// may overlap with the pair of output arguments. It is safe to call
end_comment

begin_comment
comment|/// udivrem(X, Y, X, Y), for example.
end_comment

begin_comment
comment|/// @brief Dual division/remainder interface.
end_comment

begin_function_decl
specifier|static
name|void
name|udivrem
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|,
name|APInt
modifier|&
name|Quotient
parameter_list|,
name|APInt
modifier|&
name|Remainder
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|sdivrem
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|,
name|APInt
modifier|&
name|Quotient
parameter_list|,
name|APInt
modifier|&
name|Remainder
parameter_list|)
block|{
if|if
condition|(
name|LHS
operator|.
name|isNegative
argument_list|()
condition|)
block|{
if|if
condition|(
name|RHS
operator|.
name|isNegative
argument_list|()
condition|)
name|APInt
operator|::
name|udivrem
argument_list|(
operator|-
name|LHS
argument_list|,
operator|-
name|RHS
argument_list|,
name|Quotient
argument_list|,
name|Remainder
argument_list|)
expr_stmt|;
else|else
name|APInt
operator|::
name|udivrem
argument_list|(
operator|-
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Quotient
argument_list|,
name|Remainder
argument_list|)
expr_stmt|;
name|Quotient
operator|=
operator|-
name|Quotient
expr_stmt|;
name|Remainder
operator|=
operator|-
name|Remainder
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|RHS
operator|.
name|isNegative
argument_list|()
condition|)
block|{
name|APInt
operator|::
name|udivrem
argument_list|(
name|LHS
argument_list|,
operator|-
name|RHS
argument_list|,
name|Quotient
argument_list|,
name|Remainder
argument_list|)
expr_stmt|;
name|Quotient
operator|=
operator|-
name|Quotient
expr_stmt|;
block|}
else|else
block|{
name|APInt
operator|::
name|udivrem
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Quotient
argument_list|,
name|Remainder
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// @returns the bit value at bitPosition
end_comment

begin_comment
comment|/// @brief Array-indexing support.
end_comment

begin_decl_stmt
name|bool
name|operator
index|[]
argument_list|(
name|unsigned
name|bitPosition
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Comparison Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Compares this APInt with RHS for the validity of the equality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|/// @brief Equality operator.
end_comment

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|BitWidth
operator|==
name|RHS
operator|.
name|BitWidth
operator|&&
literal|"Comparison requires equal bit widths"
argument_list|)
block|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|VAL
operator|==
name|RHS
operator|.
name|VAL
return|;
end_expr_stmt

begin_return
return|return
name|EqualSlowCase
argument_list|(
name|RHS
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Compares this APInt with a uint64_t for the validity of the equality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|/// @returns true if *this == Val
end_comment

begin_comment
comment|/// @brief Equality operator.
end_comment

begin_expr_stmt
unit|bool
name|operator
operator|==
operator|(
name|uint64_t
name|Val
operator|)
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|VAL
operator|==
name|Val
return|;
end_expr_stmt

begin_return
return|return
name|EqualSlowCase
argument_list|(
name|Val
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Compares this APInt with RHS for the validity of the equality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|/// @returns true if *this == Val
end_comment

begin_comment
comment|/// @brief Equality comparison.
end_comment

begin_macro
unit|bool
name|eq
argument_list|(
argument|const APInt&RHS
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|)
operator|==
name|RHS
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Compares this APInt with RHS for the validity of the inequality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|/// @returns true if *this != Val
end_comment

begin_comment
comment|/// @brief Inequality operator.
end_comment

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|(
operator|*
name|this
operator|)
operator|==
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Compares this APInt with a uint64_t for the validity of the inequality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|/// @returns true if *this != Val
end_comment

begin_comment
comment|/// @brief Inequality operator.
end_comment

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
name|uint64_t
name|Val
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|(
operator|*
name|this
operator|)
operator|==
name|Val
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Compares this APInt with RHS for the validity of the inequality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|/// @returns true if *this != Val
end_comment

begin_comment
comment|/// @brief Inequality comparison
end_comment

begin_decl_stmt
name|bool
name|ne
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|!
operator|(
operator|(
operator|*
name|this
operator|)
operator|==
name|RHS
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// the validity of the less-than relationship.
end_comment

begin_comment
comment|/// @returns true if *this< RHS when both are considered unsigned.
end_comment

begin_comment
comment|/// @brief Unsigned less than comparison
end_comment

begin_decl_stmt
name|bool
name|ult
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for
end_comment

begin_comment
comment|/// validity of the less-than relationship.
end_comment

begin_comment
comment|/// @returns true if *this< RHS when both are considered signed.
end_comment

begin_comment
comment|/// @brief Signed less than comparison
end_comment

begin_decl_stmt
name|bool
name|slt
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// validity of the less-or-equal relationship.
end_comment

begin_comment
comment|/// @returns true if *this<= RHS when both are considered unsigned.
end_comment

begin_comment
comment|/// @brief Unsigned less or equal comparison
end_comment

begin_decl_stmt
name|bool
name|ule
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
name|ult
argument_list|(
name|RHS
argument_list|)
operator|||
name|eq
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for
end_comment

begin_comment
comment|/// validity of the less-or-equal relationship.
end_comment

begin_comment
comment|/// @returns true if *this<= RHS when both are considered signed.
end_comment

begin_comment
comment|/// @brief Signed less or equal comparison
end_comment

begin_decl_stmt
name|bool
name|sle
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
name|slt
argument_list|(
name|RHS
argument_list|)
operator|||
name|eq
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// the validity of the greater-than relationship.
end_comment

begin_comment
comment|/// @returns true if *this> RHS when both are considered unsigned.
end_comment

begin_comment
comment|/// @brief Unsigned greather than comparison
end_comment

begin_decl_stmt
name|bool
name|ugt
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|!
name|ult
argument_list|(
name|RHS
argument_list|)
operator|&&
operator|!
name|eq
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for
end_comment

begin_comment
comment|/// the validity of the greater-than relationship.
end_comment

begin_comment
comment|/// @returns true if *this> RHS when both are considered signed.
end_comment

begin_comment
comment|/// @brief Signed greather than comparison
end_comment

begin_decl_stmt
name|bool
name|sgt
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|!
name|slt
argument_list|(
name|RHS
argument_list|)
operator|&&
operator|!
name|eq
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// validity of the greater-or-equal relationship.
end_comment

begin_comment
comment|/// @returns true if *this>= RHS when both are considered unsigned.
end_comment

begin_comment
comment|/// @brief Unsigned greater or equal comparison
end_comment

begin_decl_stmt
name|bool
name|uge
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|!
name|ult
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for
end_comment

begin_comment
comment|/// validity of the greater-or-equal relationship.
end_comment

begin_comment
comment|/// @returns true if *this>= RHS when both are considered signed.
end_comment

begin_comment
comment|/// @brief Signed greather or equal comparison
end_comment

begin_decl_stmt
name|bool
name|sge
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|!
name|slt
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// This operation tests if there are any pairs of corresponding bits
end_comment

begin_comment
comment|/// between this APInt and RHS that are both set.
end_comment

begin_decl_stmt
name|bool
name|intersects
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|(
operator|*
name|this
operator|&
name|RHS
operator|)
operator|!=
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Resizing Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Truncate the APInt to a specified width. It is an error to specify a width
end_comment

begin_comment
comment|/// that is greater than or equal to the current width.
end_comment

begin_comment
comment|/// @brief Truncate to new width.
end_comment

begin_function_decl
name|APInt
modifier|&
name|trunc
parameter_list|(
name|unsigned
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// This operation sign extends the APInt to a new width. If the high order
end_comment

begin_comment
comment|/// bit is set, the fill on the left will be done with 1 bits, otherwise zero.
end_comment

begin_comment
comment|/// It is an error to specify a width that is less than or equal to the
end_comment

begin_comment
comment|/// current width.
end_comment

begin_comment
comment|/// @brief Sign extend to a new width.
end_comment

begin_function_decl
name|APInt
modifier|&
name|sext
parameter_list|(
name|unsigned
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// This operation zero extends the APInt to a new width. The high order bits
end_comment

begin_comment
comment|/// are filled with 0 bits.  It is an error to specify a width that is less
end_comment

begin_comment
comment|/// than or equal to the current width.
end_comment

begin_comment
comment|/// @brief Zero extend to a new width.
end_comment

begin_function_decl
name|APInt
modifier|&
name|zext
parameter_list|(
name|unsigned
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Make this APInt have the bit width given by \p width. The value is sign
end_comment

begin_comment
comment|/// extended, truncated, or left alone to make it that width.
end_comment

begin_comment
comment|/// @brief Sign extend or truncate to width
end_comment

begin_function_decl
name|APInt
modifier|&
name|sextOrTrunc
parameter_list|(
name|unsigned
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Make this APInt have the bit width given by \p width. The value is zero
end_comment

begin_comment
comment|/// extended, truncated, or left alone to make it that width.
end_comment

begin_comment
comment|/// @brief Zero extend or truncate to width
end_comment

begin_function_decl
name|APInt
modifier|&
name|zextOrTrunc
parameter_list|(
name|unsigned
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Bit Manipulation Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// @brief Set every bit to 1.
end_comment

begin_function
name|APInt
modifier|&
name|set
parameter_list|()
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|VAL
operator|=
operator|-
literal|1ULL
expr_stmt|;
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
comment|// Set all the bits in all the words.
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|getNumWords
argument_list|()
condition|;
operator|++
name|i
control|)
name|pVal
index|[
name|i
index|]
operator|=
operator|-
literal|1ULL
expr_stmt|;
comment|// Clear the unused ones
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// Set the given bit to 1 whose position is given as "bitPosition".
end_comment

begin_comment
comment|/// @brief Set a given bit to 1.
end_comment

begin_function_decl
name|APInt
modifier|&
name|set
parameter_list|(
name|unsigned
name|bitPosition
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Set every bit to 0.
end_comment

begin_function
name|APInt
modifier|&
name|clear
parameter_list|()
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|VAL
operator|=
literal|0
expr_stmt|;
else|else
name|memset
argument_list|(
name|pVal
argument_list|,
literal|0
argument_list|,
name|getNumWords
argument_list|()
operator|*
name|APINT_WORD_SIZE
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function

begin_comment
comment|/// Set the given bit to 0 whose position is given as "bitPosition".
end_comment

begin_comment
comment|/// @brief Set a given bit to 0.
end_comment

begin_function_decl
name|APInt
modifier|&
name|clear
parameter_list|(
name|unsigned
name|bitPosition
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Toggle every bit to its opposite value.
end_comment

begin_function
name|APInt
modifier|&
name|flip
parameter_list|()
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|VAL
operator|^=
operator|-
literal|1ULL
expr_stmt|;
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|getNumWords
argument_list|()
condition|;
operator|++
name|i
control|)
name|pVal
index|[
name|i
index|]
operator|^=
operator|-
literal|1ULL
expr_stmt|;
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// Toggle a given bit to its opposite value whose position is given
end_comment

begin_comment
comment|/// as "bitPosition".
end_comment

begin_comment
comment|/// @brief Toggles a given bit to its opposite value.
end_comment

begin_function_decl
name|APInt
modifier|&
name|flip
parameter_list|(
name|unsigned
name|bitPosition
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Value Characterization Functions
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// @returns the total number of bits.
end_comment

begin_expr_stmt
name|unsigned
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Here one word's bitwidth equals to that of uint64_t.
end_comment

begin_comment
comment|/// @returns the number of words to hold the integer value of this APInt.
end_comment

begin_comment
comment|/// @brief Get the number of words.
end_comment

begin_expr_stmt
name|unsigned
name|getNumWords
argument_list|()
specifier|const
block|{
return|return
name|getNumWords
argument_list|(
name|BitWidth
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Here one word's bitwidth equals to that of uint64_t.
end_comment

begin_comment
comment|/// @returns the number of words to hold the integer value with a
end_comment

begin_comment
comment|/// given bit width.
end_comment

begin_comment
comment|/// @brief Get the number of words.
end_comment

begin_function
specifier|static
name|unsigned
name|getNumWords
parameter_list|(
name|unsigned
name|BitWidth
parameter_list|)
block|{
return|return
operator|(
name|BitWidth
operator|+
name|APINT_BITS_PER_WORD
operator|-
literal|1
operator|)
operator|/
name|APINT_BITS_PER_WORD
return|;
block|}
end_function

begin_comment
comment|/// This function returns the number of active bits which is defined as the
end_comment

begin_comment
comment|/// bit width minus the number of leading zeros. This is used in several
end_comment

begin_comment
comment|/// computations to see how "wide" the value is.
end_comment

begin_comment
comment|/// @brief Compute the number of active bits in the value
end_comment

begin_expr_stmt
name|unsigned
name|getActiveBits
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|-
name|countLeadingZeros
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// This function returns the number of active words in the value of this
end_comment

begin_comment
comment|/// APInt. This is used in conjunction with getActiveData to extract the raw
end_comment

begin_comment
comment|/// value of the APInt.
end_comment

begin_expr_stmt
name|unsigned
name|getActiveWords
argument_list|()
specifier|const
block|{
return|return
name|whichWord
argument_list|(
name|getActiveBits
argument_list|()
operator|-
literal|1
argument_list|)
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Computes the minimum bit width for this APInt while considering it to be
end_comment

begin_comment
comment|/// a signed (and probably negative) value. If the value is not negative,
end_comment

begin_comment
comment|/// this function returns the same value as getActiveBits()+1. Otherwise, it
end_comment

begin_comment
comment|/// returns the smallest bit width that will retain the negative value. For
end_comment

begin_comment
comment|/// example, -1 can be written as 0b1 or 0xFFFFFFFFFF. 0b1 is shorter and so
end_comment

begin_comment
comment|/// for -1, this function will always return 1.
end_comment

begin_comment
comment|/// @brief Get the minimum bit size for this signed APInt
end_comment

begin_expr_stmt
name|unsigned
name|getMinSignedBits
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isNegative
argument_list|()
condition|)
return|return
name|BitWidth
operator|-
name|countLeadingOnes
argument_list|()
operator|+
literal|1
return|;
end_expr_stmt

begin_return
return|return
name|getActiveBits
argument_list|()
operator|+
literal|1
return|;
end_return

begin_comment
unit|}
comment|/// This method attempts to return the value of this APInt as a zero extended
end_comment

begin_comment
comment|/// uint64_t. The bitwidth must be<= 64 or the value must fit within a
end_comment

begin_comment
comment|/// uint64_t. Otherwise an assertion will result.
end_comment

begin_comment
comment|/// @brief Get zero extended value
end_comment

begin_macro
unit|uint64_t
name|getZExtValue
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|VAL
return|;
name|assert
argument_list|(
name|getActiveBits
argument_list|()
operator|<=
literal|64
operator|&&
literal|"Too many bits for uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|pVal
index|[
literal|0
index|]
return|;
end_return

begin_comment
unit|}
comment|/// This method attempts to return the value of this APInt as a sign extended
end_comment

begin_comment
comment|/// int64_t. The bit width must be<= 64 or the value must fit within an
end_comment

begin_comment
comment|/// int64_t. Otherwise an assertion will result.
end_comment

begin_comment
comment|/// @brief Get sign extended value
end_comment

begin_macro
unit|int64_t
name|getSExtValue
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|int64_t
argument_list|(
name|VAL
operator|<<
operator|(
name|APINT_BITS_PER_WORD
operator|-
name|BitWidth
operator|)
argument_list|)
operator|>>
operator|(
name|APINT_BITS_PER_WORD
operator|-
name|BitWidth
operator|)
return|;
name|assert
argument_list|(
name|getMinSignedBits
argument_list|()
operator|<=
literal|64
operator|&&
literal|"Too many bits for int64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|int64_t
argument_list|(
name|pVal
index|[
literal|0
index|]
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// This method determines how many bits are required to hold the APInt
end_comment

begin_comment
comment|/// equivalent of the string given by \arg str.
end_comment

begin_comment
comment|/// @brief Get bits required for string value.
end_comment

begin_function_decl
unit|static
name|unsigned
name|getBitsNeeded
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|str
parameter_list|,
name|uint8_t
name|radix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// countLeadingZeros - This function is an APInt version of the
end_comment

begin_comment
comment|/// countLeadingZeros_{32,64} functions in MathExtras.h. It counts the number
end_comment

begin_comment
comment|/// of zeros from the most significant bit to the first one bit.
end_comment

begin_comment
comment|/// @returns BitWidth if the value is zero.
end_comment

begin_comment
comment|/// @returns the number of zeros from the most significant bit to the first
end_comment

begin_comment
comment|/// one bits.
end_comment

begin_expr_stmt
name|unsigned
name|countLeadingZeros
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|unsigned
name|unusedBits
init|=
name|APINT_BITS_PER_WORD
operator|-
name|BitWidth
decl_stmt|;
return|return
name|CountLeadingZeros_64
argument_list|(
name|VAL
argument_list|)
operator|-
name|unusedBits
return|;
block|}
end_expr_stmt

begin_return
return|return
name|countLeadingZerosSlowCase
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// countLeadingOnes - This function is an APInt version of the
end_comment

begin_comment
comment|/// countLeadingOnes_{32,64} functions in MathExtras.h. It counts the number
end_comment

begin_comment
comment|/// of ones from the most significant bit to the first zero bit.
end_comment

begin_comment
comment|/// @returns 0 if the high order bit is not set
end_comment

begin_comment
comment|/// @returns the number of 1 bits from the most significant to the least
end_comment

begin_comment
comment|/// @brief Count the number of leading one bits.
end_comment

begin_macro
unit|unsigned
name|countLeadingOnes
argument_list|()
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// countTrailingZeros - This function is an APInt version of the
end_comment

begin_comment
comment|/// countTrailingZeros_{32,64} functions in MathExtras.h. It counts
end_comment

begin_comment
comment|/// the number of zeros from the least significant bit to the first set bit.
end_comment

begin_comment
comment|/// @returns BitWidth if the value is zero.
end_comment

begin_comment
comment|/// @returns the number of zeros from the least significant bit to the first
end_comment

begin_comment
comment|/// one bit.
end_comment

begin_comment
comment|/// @brief Count the number of trailing zero bits.
end_comment

begin_expr_stmt
name|unsigned
name|countTrailingZeros
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// countTrailingOnes - This function is an APInt version of the
end_comment

begin_comment
comment|/// countTrailingOnes_{32,64} functions in MathExtras.h. It counts
end_comment

begin_comment
comment|/// the number of ones from the least significant bit to the first zero bit.
end_comment

begin_comment
comment|/// @returns BitWidth if the value is all ones.
end_comment

begin_comment
comment|/// @returns the number of ones from the least significant bit to the first
end_comment

begin_comment
comment|/// zero bit.
end_comment

begin_comment
comment|/// @brief Count the number of trailing one bits.
end_comment

begin_expr_stmt
name|unsigned
name|countTrailingOnes
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|CountTrailingOnes_64
argument_list|(
name|VAL
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|countTrailingOnesSlowCase
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// countPopulation - This function is an APInt version of the
end_comment

begin_comment
comment|/// countPopulation_{32,64} functions in MathExtras.h. It counts the number
end_comment

begin_comment
comment|/// of 1 bits in the APInt value.
end_comment

begin_comment
comment|/// @returns 0 if the value is zero.
end_comment

begin_comment
comment|/// @returns the number of set bits.
end_comment

begin_comment
comment|/// @brief Count the number of bits set.
end_comment

begin_macro
unit|unsigned
name|countPopulation
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|CountPopulation_64
argument_list|(
name|VAL
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|countPopulationSlowCase
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// @}
end_comment

begin_comment
comment|/// @name Conversion Functions
end_comment

begin_comment
comment|/// @{
end_comment

begin_macro
unit|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool isSigned
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// toString - Converts an APInt to a string and append it to Str.  Str is
end_comment

begin_comment
comment|/// commonly a SmallString.
end_comment

begin_decl_stmt
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
name|Radix
argument_list|,
name|bool
name|Signed
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Considers the APInt to be unsigned and converts it into a string in the
end_comment

begin_comment
comment|/// radix given. The radix can be 2, 8, 10 or 16.
end_comment

begin_decl_stmt
name|void
name|toStringUnsigned
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Str
argument_list|,
name|unsigned
name|Radix
operator|=
literal|10
argument_list|)
decl|const
block|{
name|toString
argument_list|(
name|Str
argument_list|,
name|Radix
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Considers the APInt to be signed and converts it into a string in the
end_comment

begin_comment
comment|/// radix given. The radix can be 2, 8, 10 or 16.
end_comment

begin_decl_stmt
name|void
name|toStringSigned
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Str
argument_list|,
name|unsigned
name|Radix
operator|=
literal|10
argument_list|)
decl|const
block|{
name|toString
argument_list|(
name|Str
argument_list|,
name|Radix
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// toString - This returns the APInt as a std::string.  Note that this is an
end_comment

begin_comment
comment|/// inefficient method.  It is better to pass in a SmallVector/SmallString
end_comment

begin_comment
comment|/// to the methods above to avoid thrashing the heap for the string.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|toString
argument_list|(
argument|unsigned Radix
argument_list|,
argument|bool Signed
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @returns a byte-swapped representation of this APInt Value.
end_comment

begin_expr_stmt
name|APInt
name|byteSwap
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Converts this APInt to a double value.
end_comment

begin_decl_stmt
name|double
name|roundToDouble
argument_list|(
name|bool
name|isSigned
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Converts this unsigned APInt to a double value.
end_comment

begin_expr_stmt
name|double
name|roundToDouble
argument_list|()
specifier|const
block|{
return|return
name|roundToDouble
argument_list|(
name|false
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Converts this signed APInt to a double value.
end_comment

begin_expr_stmt
name|double
name|signedRoundToDouble
argument_list|()
specifier|const
block|{
return|return
name|roundToDouble
argument_list|(
name|true
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// The conversion does not do a translation from integer to double, it just
end_comment

begin_comment
comment|/// re-interprets the bits as a double. Note that it is valid to do this on
end_comment

begin_comment
comment|/// any bit width. Exactly 64 bits will be translated.
end_comment

begin_comment
comment|/// @brief Converts APInt bits to a double
end_comment

begin_expr_stmt
name|double
name|bitsToDouble
argument_list|()
specifier|const
block|{
expr|union
block|{
name|uint64_t
name|I
block|;
name|double
name|D
block|;     }
name|T
block|;
name|T
operator|.
name|I
operator|=
operator|(
name|isSingleWord
argument_list|()
condition|?
name|VAL
else|:
name|pVal
index|[
literal|0
index|]
operator|)
block|;
return|return
name|T
operator|.
name|D
return|;
block|}
end_expr_stmt

begin_comment
comment|/// The conversion does not do a translation from integer to float, it just
end_comment

begin_comment
comment|/// re-interprets the bits as a float. Note that it is valid to do this on
end_comment

begin_comment
comment|/// any bit width. Exactly 32 bits will be translated.
end_comment

begin_comment
comment|/// @brief Converts APInt bits to a double
end_comment

begin_expr_stmt
name|float
name|bitsToFloat
argument_list|()
specifier|const
block|{
expr|union
block|{
name|unsigned
name|I
block|;
name|float
name|F
block|;     }
name|T
block|;
name|T
operator|.
name|I
operator|=
name|unsigned
argument_list|(
operator|(
name|isSingleWord
argument_list|()
condition|?
name|VAL
else|:
name|pVal
index|[
literal|0
index|]
operator|)
argument_list|)
block|;
return|return
name|T
operator|.
name|F
return|;
block|}
end_expr_stmt

begin_comment
comment|/// The conversion does not do a translation from double to integer, it just
end_comment

begin_comment
comment|/// re-interprets the bits of the double. Note that it is valid to do this on
end_comment

begin_comment
comment|/// any bit width but bits from V may get truncated.
end_comment

begin_comment
comment|/// @brief Converts a double to APInt bits.
end_comment

begin_function
name|APInt
modifier|&
name|doubleToBits
parameter_list|(
name|double
name|V
parameter_list|)
block|{
union|union
block|{
name|uint64_t
name|I
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
name|V
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|VAL
operator|=
name|T
operator|.
name|I
expr_stmt|;
else|else
name|pVal
index|[
literal|0
index|]
operator|=
name|T
operator|.
name|I
expr_stmt|;
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// The conversion does not do a translation from float to integer, it just
end_comment

begin_comment
comment|/// re-interprets the bits of the float. Note that it is valid to do this on
end_comment

begin_comment
comment|/// any bit width but bits from V may get truncated.
end_comment

begin_comment
comment|/// @brief Converts a float to APInt bits.
end_comment

begin_function
name|APInt
modifier|&
name|floatToBits
parameter_list|(
name|float
name|V
parameter_list|)
block|{
union|union
block|{
name|unsigned
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
name|V
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|VAL
operator|=
name|T
operator|.
name|I
expr_stmt|;
else|else
name|pVal
index|[
literal|0
index|]
operator|=
name|T
operator|.
name|I
expr_stmt|;
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Mathematics Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// @returns the floor log base 2 of this APInt.
end_comment

begin_expr_stmt
name|unsigned
name|logBase2
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|-
literal|1
operator|-
name|countLeadingZeros
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @returns the ceil log base 2 of this APInt.
end_comment

begin_expr_stmt
name|unsigned
name|ceilLogBase2
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|-
operator|(
operator|*
name|this
operator|-
literal|1
operator|)
operator|.
name|countLeadingZeros
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @returns the log base 2 of this APInt if its an exact power of two, -1
end_comment

begin_comment
comment|/// otherwise
end_comment

begin_expr_stmt
name|int32_t
name|exactLogBase2
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isPowerOf2
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
end_expr_stmt

begin_return
return|return
name|logBase2
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// @brief Compute the square root
end_comment

begin_macro
unit|APInt
name|sqrt
argument_list|()
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If *this is< 0 then return -(*this), otherwise *this;
end_comment

begin_comment
comment|/// @brief Get the absolute value;
end_comment

begin_expr_stmt
name|APInt
name|abs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isNegative
argument_list|()
condition|)
return|return
operator|-
operator|(
operator|*
name|this
operator|)
return|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// @returns the multiplicative inverse for a given modulo.
end_comment

begin_macro
unit|APInt
name|multiplicativeInverse
argument_list|(
argument|const APInt& modulo
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Support for division by constant
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Calculate the magic number for signed division by a constant.
end_comment

begin_struct_decl
struct_decl|struct
name|ms
struct_decl|;
end_struct_decl

begin_expr_stmt
name|ms
name|magic
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Calculate the magic number for unsigned division by a constant.
end_comment

begin_struct_decl
struct_decl|struct
name|mu
struct_decl|;
end_struct_decl

begin_expr_stmt
name|mu
name|magicu
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Building-block Operations for APInt and APFloat
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|// These building block operations operate on a representation of
end_comment

begin_comment
comment|// arbitrary precision, two's-complement, bignum integer values.
end_comment

begin_comment
comment|// They should be sufficient to implement APInt and APFloat bignum
end_comment

begin_comment
comment|// requirements.  Inputs are generally a pointer to the base of an
end_comment

begin_comment
comment|// array of integer parts, representing an unsigned bignum, and a
end_comment

begin_comment
comment|// count of how many parts there are.
end_comment

begin_comment
comment|/// Sets the least significant part of a bignum to the input value,
end_comment

begin_comment
comment|/// and zeroes out higher parts.  */
end_comment

begin_function_decl
specifier|static
name|void
name|tcSet
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|integerPart
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Assign one bignum to another.
end_comment

begin_function_decl
specifier|static
name|void
name|tcAssign
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns true if a bignum is zero, false otherwise.
end_comment

begin_function_decl
specifier|static
name|bool
name|tcIsZero
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Extract the given bit of a bignum; returns 0 or 1.  Zero-based.
end_comment

begin_function_decl
specifier|static
name|int
name|tcExtractBit
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Copy the bit vector of width srcBITS from SRC, starting at bit
end_comment

begin_comment
comment|/// srcLSB, to DST, of dstCOUNT parts, such that the bit srcLSB
end_comment

begin_comment
comment|/// becomes the least significant bit of DST.  All high bits above
end_comment

begin_comment
comment|/// srcBITS in DST are zero-filled.
end_comment

begin_function_decl
specifier|static
name|void
name|tcExtract
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
name|dstCount
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
name|srcBits
parameter_list|,
name|unsigned
name|int
name|srcLSB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set the given bit of a bignum.  Zero-based.
end_comment

begin_function_decl
specifier|static
name|void
name|tcSetBit
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the bit number of the least or most significant set bit
end_comment

begin_comment
comment|/// of a number.  If the input number has no bits set -1U is
end_comment

begin_comment
comment|/// returned.
end_comment

begin_function_decl
specifier|static
name|unsigned
name|int
name|tcLSB
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|unsigned
name|int
name|tcMSB
parameter_list|(
specifier|const
name|integerPart
modifier|*
name|parts
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Negate a bignum in-place.
end_comment

begin_function_decl
specifier|static
name|void
name|tcNegate
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST += RHS + CARRY where CARRY is zero or one.  Returns the
end_comment

begin_comment
comment|/// carry flag.
end_comment

begin_function_decl
specifier|static
name|integerPart
name|tcAdd
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|integerPart
name|carry
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST -= RHS + CARRY where CARRY is zero or one.  Returns the
end_comment

begin_comment
comment|/// carry flag.
end_comment

begin_function_decl
specifier|static
name|integerPart
name|tcSubtract
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|integerPart
name|carry
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///  DST += SRC * MULTIPLIER + PART   if add is true
end_comment

begin_comment
comment|///  DST  = SRC * MULTIPLIER + PART   if add is false
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  Requires 0<= DSTPARTS<= SRCPARTS + 1.  If DST overlaps SRC
end_comment

begin_comment
comment|///  they must start at the same point, i.e. DST == SRC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  If DSTPARTS == SRC_PARTS + 1 no overflow occurs and zero is
end_comment

begin_comment
comment|///  returned.  Otherwise DST is filled with the least significant
end_comment

begin_comment
comment|///  DSTPARTS parts of the result, and if all of the omitted higher
end_comment

begin_comment
comment|///  parts were zero return zero, otherwise overflow occurred and
end_comment

begin_comment
comment|///  return one.
end_comment

begin_function_decl
specifier|static
name|int
name|tcMultiplyPart
parameter_list|(
name|integerPart
modifier|*
name|dst
parameter_list|,
specifier|const
name|integerPart
modifier|*
name|src
parameter_list|,
name|integerPart
name|multiplier
parameter_list|,
name|integerPart
name|carry
parameter_list|,
name|unsigned
name|int
name|srcParts
parameter_list|,
name|unsigned
name|int
name|dstParts
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST = LHS * RHS, where DST has the same width as the operands
end_comment

begin_comment
comment|/// and is filled with the least significant parts of the result.
end_comment

begin_comment
comment|/// Returns one if overflow occurred, otherwise zero.  DST must be
end_comment

begin_comment
comment|/// disjoint from both operands.
end_comment

begin_function_decl
specifier|static
name|int
name|tcMultiply
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST = LHS * RHS, where DST has width the sum of the widths of
end_comment

begin_comment
comment|/// the operands.  No overflow occurs.  DST must be disjoint from
end_comment

begin_comment
comment|/// both operands. Returns the number of parts required to hold the
end_comment

begin_comment
comment|/// result.
end_comment

begin_function_decl
specifier|static
name|unsigned
name|int
name|tcFullMultiply
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// If RHS is zero LHS and REMAINDER are left unchanged, return one.
end_comment

begin_comment
comment|/// Otherwise set LHS to LHS / RHS with the fractional part
end_comment

begin_comment
comment|/// discarded, set REMAINDER to the remainder, return zero.  i.e.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  OLD_LHS = RHS * LHS + REMAINDER
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  SCRATCH is a bignum of the same size as the operands and result
end_comment

begin_comment
comment|///  for use by the routine; its contents need not be initialized
end_comment

begin_comment
comment|///  and are destroyed.  LHS, REMAINDER and SCRATCH must be
end_comment

begin_comment
comment|///  distinct.
end_comment

begin_function_decl
specifier|static
name|int
name|tcDivide
parameter_list|(
name|integerPart
modifier|*
name|lhs
parameter_list|,
specifier|const
name|integerPart
modifier|*
name|rhs
parameter_list|,
name|integerPart
modifier|*
name|remainder
parameter_list|,
name|integerPart
modifier|*
name|scratch
parameter_list|,
name|unsigned
name|int
name|parts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Shift a bignum left COUNT bits.  Shifted in bits are zero.
end_comment

begin_comment
comment|/// There are no restrictions on COUNT.
end_comment

begin_function_decl
specifier|static
name|void
name|tcShiftLeft
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
name|parts
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Shift a bignum right COUNT bits.  Shifted in bits are zero.
end_comment

begin_comment
comment|/// There are no restrictions on COUNT.
end_comment

begin_function_decl
specifier|static
name|void
name|tcShiftRight
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
name|parts
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// The obvious AND, OR and XOR and complement operations.
end_comment

begin_function_decl
specifier|static
name|void
name|tcAnd
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|tcOr
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|tcXor
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|tcComplement
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Comparison (unsigned) of two bignums.
end_comment

begin_function_decl
specifier|static
name|int
name|tcCompare
parameter_list|(
specifier|const
name|integerPart
modifier|*
parameter_list|,
specifier|const
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Increment a bignum in-place.  Return the carry flag.
end_comment

begin_function_decl
specifier|static
name|integerPart
name|tcIncrement
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set the least significant BITS and clear the rest.
end_comment

begin_function_decl
specifier|static
name|void
name|tcSetLeastSignificantBits
parameter_list|(
name|integerPart
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief debug method
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};
comment|/// Magic data for optimising signed division by a constant.
end_comment

begin_expr_stmt
unit|struct
name|APInt
operator|::
name|ms
block|{
name|APInt
name|m
block|;
comment|///< magic number
name|unsigned
name|s
block|;
comment|///< shift amount
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Magic data for optimising unsigned division by a constant.
end_comment

begin_expr_stmt
unit|struct
name|APInt
operator|::
name|mu
block|{
name|APInt
name|m
block|;
comment|///< magic number
name|bool
name|a
block|;
comment|///< add indicator
name|unsigned
name|s
block|;
comment|///< shift amount
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|uint64_t
name|V1
operator|,
specifier|const
name|APInt
operator|&
name|V2
operator|)
block|{
return|return
name|V2
operator|==
name|V1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|uint64_t
name|V1
operator|,
specifier|const
name|APInt
operator|&
name|V2
operator|)
block|{
return|return
name|V2
operator|!=
name|V1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
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
name|APInt
operator|&
name|I
operator|)
block|{
name|I
operator|.
name|print
argument_list|(
name|OS
argument_list|,
name|true
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|namespace
name|APIntOps
block|{
comment|/// @brief Determine the smaller of two APInts considered to be signed.
specifier|inline
name|APInt
name|smin
parameter_list|(
specifier|const
name|APInt
modifier|&
name|A
parameter_list|,
specifier|const
name|APInt
modifier|&
name|B
parameter_list|)
block|{
return|return
name|A
operator|.
name|slt
argument_list|(
name|B
argument_list|)
condition|?
name|A
else|:
name|B
return|;
block|}
comment|/// @brief Determine the larger of two APInts considered to be signed.
specifier|inline
name|APInt
name|smax
parameter_list|(
specifier|const
name|APInt
modifier|&
name|A
parameter_list|,
specifier|const
name|APInt
modifier|&
name|B
parameter_list|)
block|{
return|return
name|A
operator|.
name|sgt
argument_list|(
name|B
argument_list|)
condition|?
name|A
else|:
name|B
return|;
block|}
comment|/// @brief Determine the smaller of two APInts considered to be signed.
specifier|inline
name|APInt
name|umin
parameter_list|(
specifier|const
name|APInt
modifier|&
name|A
parameter_list|,
specifier|const
name|APInt
modifier|&
name|B
parameter_list|)
block|{
return|return
name|A
operator|.
name|ult
argument_list|(
name|B
argument_list|)
condition|?
name|A
else|:
name|B
return|;
block|}
comment|/// @brief Determine the larger of two APInts considered to be unsigned.
specifier|inline
name|APInt
name|umax
parameter_list|(
specifier|const
name|APInt
modifier|&
name|A
parameter_list|,
specifier|const
name|APInt
modifier|&
name|B
parameter_list|)
block|{
return|return
name|A
operator|.
name|ugt
argument_list|(
name|B
argument_list|)
condition|?
name|A
else|:
name|B
return|;
block|}
comment|/// @brief Check if the specified APInt has a N-bits unsigned integer value.
specifier|inline
name|bool
name|isIntN
parameter_list|(
name|unsigned
name|N
parameter_list|,
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|APIVal
operator|.
name|isIntN
argument_list|(
name|N
argument_list|)
return|;
block|}
comment|/// @brief Check if the specified APInt has a N-bits signed integer value.
specifier|inline
name|bool
name|isSignedIntN
parameter_list|(
name|unsigned
name|N
parameter_list|,
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|APIVal
operator|.
name|isSignedIntN
argument_list|(
name|N
argument_list|)
return|;
block|}
comment|/// @returns true if the argument APInt value is a sequence of ones
comment|/// starting at the least significant bit with the remainder zero.
specifier|inline
name|bool
name|isMask
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|numBits
operator|<=
name|APIVal
operator|.
name|getBitWidth
argument_list|()
operator|&&
name|APIVal
operator|==
name|APInt
operator|::
name|getLowBitsSet
argument_list|(
name|APIVal
operator|.
name|getBitWidth
argument_list|()
argument_list|,
name|numBits
argument_list|)
return|;
block|}
comment|/// @returns true if the argument APInt value contains a sequence of ones
comment|/// with the remainder zero.
specifier|inline
name|bool
name|isShiftedMask
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|isMask
argument_list|(
name|numBits
argument_list|,
operator|(
name|APIVal
operator|-
name|APInt
argument_list|(
name|numBits
argument_list|,
literal|1
argument_list|)
operator|)
operator||
name|APIVal
argument_list|)
return|;
block|}
comment|/// @returns a byte-swapped representation of the specified APInt Value.
specifier|inline
name|APInt
name|byteSwap
parameter_list|(
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|APIVal
operator|.
name|byteSwap
argument_list|()
return|;
block|}
comment|/// @returns the floor log base 2 of the specified APInt value.
specifier|inline
name|unsigned
name|logBase2
parameter_list|(
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|APIVal
operator|.
name|logBase2
argument_list|()
return|;
block|}
comment|/// GreatestCommonDivisor - This function returns the greatest common
comment|/// divisor of the two APInt values using Euclid's algorithm.
comment|/// @returns the greatest common divisor of Val1 and Val2
comment|/// @brief Compute GCD of two APInt values.
name|APInt
name|GreatestCommonDivisor
parameter_list|(
specifier|const
name|APInt
modifier|&
name|Val1
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Val2
parameter_list|)
function_decl|;
comment|/// Treats the APInt as an unsigned value for conversion purposes.
comment|/// @brief Converts the given APInt to a double value.
specifier|inline
name|double
name|RoundAPIntToDouble
parameter_list|(
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|APIVal
operator|.
name|roundToDouble
argument_list|()
return|;
block|}
comment|/// Treats the APInt as a signed value for conversion purposes.
comment|/// @brief Converts the given APInt to a double value.
specifier|inline
name|double
name|RoundSignedAPIntToDouble
parameter_list|(
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|APIVal
operator|.
name|signedRoundToDouble
argument_list|()
return|;
block|}
comment|/// @brief Converts the given APInt to a float vlalue.
specifier|inline
name|float
name|RoundAPIntToFloat
parameter_list|(
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|float
argument_list|(
name|RoundAPIntToDouble
argument_list|(
name|APIVal
argument_list|)
argument_list|)
return|;
block|}
comment|/// Treast the APInt as a signed value for conversion purposes.
comment|/// @brief Converts the given APInt to a float value.
specifier|inline
name|float
name|RoundSignedAPIntToFloat
parameter_list|(
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
name|float
argument_list|(
name|APIVal
operator|.
name|signedRoundToDouble
argument_list|()
argument_list|)
return|;
block|}
comment|/// RoundDoubleToAPInt - This function convert a double value to an APInt value.
comment|/// @brief Converts the given double value into a APInt.
name|APInt
name|RoundDoubleToAPInt
parameter_list|(
name|double
name|Double
parameter_list|,
name|unsigned
name|width
parameter_list|)
function_decl|;
comment|/// RoundFloatToAPInt - Converts a float value into an APInt value.
comment|/// @brief Converts a float value into a APInt.
specifier|inline
name|APInt
name|RoundFloatToAPInt
parameter_list|(
name|float
name|Float
parameter_list|,
name|unsigned
name|width
parameter_list|)
block|{
return|return
name|RoundDoubleToAPInt
argument_list|(
name|double
argument_list|(
name|Float
argument_list|)
argument_list|,
name|width
argument_list|)
return|;
block|}
comment|/// Arithmetic right-shift the APInt by shiftAmt.
comment|/// @brief Arithmetic right-shift function.
specifier|inline
name|APInt
name|ashr
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
name|unsigned
name|shiftAmt
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|ashr
argument_list|(
name|shiftAmt
argument_list|)
return|;
block|}
comment|/// Logical right-shift the APInt by shiftAmt.
comment|/// @brief Logical right-shift function.
specifier|inline
name|APInt
name|lshr
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
name|unsigned
name|shiftAmt
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|lshr
argument_list|(
name|shiftAmt
argument_list|)
return|;
block|}
comment|/// Left-shift the APInt by shiftAmt.
comment|/// @brief Left-shift function.
specifier|inline
name|APInt
name|shl
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
name|unsigned
name|shiftAmt
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|shl
argument_list|(
name|shiftAmt
argument_list|)
return|;
block|}
comment|/// Signed divide APInt LHS by APInt RHS.
comment|/// @brief Signed division function for APInt.
specifier|inline
name|APInt
name|sdiv
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|sdiv
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// Unsigned divide APInt LHS by APInt RHS.
comment|/// @brief Unsigned division function for APInt.
specifier|inline
name|APInt
name|udiv
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|udiv
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// Signed remainder operation on APInt.
comment|/// @brief Function for signed remainder operation.
specifier|inline
name|APInt
name|srem
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|srem
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// Unsigned remainder operation on APInt.
comment|/// @brief Function for unsigned remainder operation.
specifier|inline
name|APInt
name|urem
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|urem
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// Performs multiplication on APInt values.
comment|/// @brief Function for multiplication operation.
specifier|inline
name|APInt
name|mul
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|*
name|RHS
return|;
block|}
comment|/// Performs addition on APInt values.
comment|/// @brief Function for addition operation.
specifier|inline
name|APInt
name|add
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|+
name|RHS
return|;
block|}
comment|/// Performs subtraction on APInt values.
comment|/// @brief Function for subtraction operation.
specifier|inline
name|APInt
name|sub
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|-
name|RHS
return|;
block|}
comment|/// Performs bitwise AND operation on APInt LHS and
comment|/// APInt RHS.
comment|/// @brief Bitwise AND function for APInt.
specifier|inline
name|APInt
name|And
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|&
name|RHS
return|;
block|}
comment|/// Performs bitwise OR operation on APInt LHS and APInt RHS.
comment|/// @brief Bitwise OR function for APInt.
specifier|inline
name|APInt
name|Or
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator||
name|RHS
return|;
block|}
comment|/// Performs bitwise XOR operation on APInt.
comment|/// @brief Bitwise XOR function for APInt.
specifier|inline
name|APInt
name|Xor
parameter_list|(
specifier|const
name|APInt
modifier|&
name|LHS
parameter_list|,
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|^
name|RHS
return|;
block|}
comment|/// Performs a bitwise complement operation on APInt.
comment|/// @brief Bitwise complement function.
specifier|inline
name|APInt
name|Not
parameter_list|(
specifier|const
name|APInt
modifier|&
name|APIVal
parameter_list|)
block|{
return|return
operator|~
name|APIVal
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End of APIntOps namespace
end_comment

begin_comment
unit|}
comment|// End of llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

