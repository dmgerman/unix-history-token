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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file implements a class to represent arbitrary precision
end_comment

begin_comment
comment|/// integral constant values and operations on them.
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
name|LLVM_ADT_APINT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_APINT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

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
name|FoldingSetNodeID
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|hash_code
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|APInt
decl_stmt|;
specifier|inline
name|APInt
name|operator
operator|-
operator|(
name|APInt
operator|)
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                              APInt Class
comment|//===----------------------------------------------------------------------===//
comment|/// \brief Class for arbitrary precision integers.
comment|///
comment|/// APInt is a functional replacement for common case unsigned integer type like
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
name|class
name|LLVM_NODISCARD
name|APInt
block|{
name|public
label|:
typedef|typedef
name|uint64_t
name|WordType
typedef|;
comment|/// This enum is used to hold the constants we needed for APInt.
enum_decl|enum :
name|unsigned
block|{
comment|/// Byte size of a word.
name|APINT_WORD_SIZE
init|=
sizeof|sizeof
argument_list|(
name|WordType
argument_list|)
block|,
comment|/// Bits in a word.
name|APINT_BITS_PER_WORD
init|=
name|APINT_WORD_SIZE
operator|*
name|CHAR_BIT
block|}
enum_decl|;
specifier|static
specifier|const
name|WordType
name|WORD_MAX
init|=
operator|~
name|WordType
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|private
label|:
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
name|U
union|;
name|unsigned
name|BitWidth
decl_stmt|;
comment|///< The number of bits in this APInt.
name|friend
struct_decl|struct
name|DenseMapAPIntKeyInfo
struct_decl|;
name|friend
name|class
name|APSInt
decl_stmt|;
comment|/// \brief Fast internal constructor
comment|///
comment|/// This constructor is used only internally for speed of construction of
comment|/// temporaries. It is unsafe for general use so it is not public.
name|APInt
argument_list|(
argument|uint64_t *val
argument_list|,
argument|unsigned bits
argument_list|)
block|:
name|BitWidth
argument_list|(
argument|bits
argument_list|)
block|{
name|U
operator|.
name|pVal
operator|=
name|val
expr_stmt|;
block|}
comment|/// \brief Determine if this APInt just has one word to store value.
comment|///
comment|/// \returns true if the number of bits<= 64, false otherwise.
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
comment|/// \brief Determine which word a bit is in.
comment|///
comment|/// \returns the word position for the specified bit position.
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
comment|/// \brief Determine which bit in a word a bit is in.
comment|///
comment|/// \returns the bit position in a word for the specified bit position
comment|/// in the APInt.
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
comment|/// \brief Get a single bit mask.
comment|///
comment|/// \returns a uint64_t with only bit at "whichBit(bitPosition)" set
comment|/// This method generates and returns a uint64_t (word) mask for a single
comment|/// bit at a specific bit position. This is used to mask the bit in the
comment|/// corresponding word.
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
comment|/// \brief Clear unused high order bits
comment|///
comment|/// This method is used internally to clear the top "N" bits in the high order
comment|/// word that are not used by the APInt. This is needed after the most
comment|/// significant word is assigned a value to ensure that those bits are
comment|/// zero'd out.
name|APInt
modifier|&
name|clearUnusedBits
parameter_list|()
block|{
comment|// Compute how many bits are used in the final word
name|unsigned
name|WordBits
init|=
operator|(
operator|(
name|BitWidth
operator|-
literal|1
operator|)
operator|%
name|APINT_BITS_PER_WORD
operator|)
operator|+
literal|1
decl_stmt|;
comment|// Mask out the high bits.
name|uint64_t
name|mask
init|=
name|WORD_MAX
operator|>>
operator|(
name|APINT_BITS_PER_WORD
operator|-
name|WordBits
operator|)
decl_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|U
operator|.
name|VAL
operator|&=
name|mask
expr_stmt|;
else|else
name|U
operator|.
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
comment|/// \brief Get the word corresponding to a bit position
comment|/// \returns the corresponding word for the specified bit position.
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
name|U
operator|.
name|VAL
else|:
name|U
operator|.
name|pVal
index|[
name|whichWord
argument_list|(
name|bitPosition
argument_list|)
index|]
return|;
block|}
comment|/// \brief Convert a char array into an APInt
comment|///
comment|/// \param radix 2, 8, 10, 16, or 36
comment|/// Converts a string into a number.  The string must be non-empty
comment|/// and well-formed as a number of the given base. The bit-width
comment|/// must be sufficient to hold the result.
comment|///
comment|/// This is used by the constructors that take string arguments.
comment|///
comment|/// StringRef::getAsInteger is superficially similar but (1) does
comment|/// not assume that the string is well-formed and (2) grows the
comment|/// result to hold the input.
name|void
name|fromString
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
name|StringRef
name|str
parameter_list|,
name|uint8_t
name|radix
parameter_list|)
function_decl|;
comment|/// \brief An internal division function for dividing APInts.
comment|///
comment|/// This is used by the toString method to divide by the radix. It simply
comment|/// provides a more convenient form of divide for internal use since KnuthDiv
comment|/// has specific constraints on its inputs. If those constraints are not met
comment|/// then it provides a simpler form of divide.
specifier|static
name|void
name|divide
parameter_list|(
specifier|const
name|APInt
modifier|&
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
name|uint64_t
name|val
parameter_list|,
name|bool
name|isSigned
parameter_list|)
function_decl|;
comment|/// shared code between two array constructors
name|void
name|initFromArray
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|array
argument_list|)
decl_stmt|;
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
name|void
name|shlSlowCase
parameter_list|(
name|unsigned
name|ShiftAmt
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for lshr.
name|void
name|lshrSlowCase
parameter_list|(
name|unsigned
name|ShiftAmt
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for ashr.
name|void
name|ashrSlowCase
parameter_list|(
name|unsigned
name|ShiftAmt
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for operator=
name|void
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
name|LLVM_READONLY
decl_stmt|;
comment|/// out-of-line slow case for countLeadingZeros
name|unsigned
name|countLeadingZerosSlowCase
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
comment|/// out-of-line slow case for countTrailingOnes
name|unsigned
name|countTrailingOnesSlowCase
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
comment|/// out-of-line slow case for countPopulation
name|unsigned
name|countPopulationSlowCase
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
comment|/// out-of-line slow case for intersects.
name|bool
name|intersectsSlowCase
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
name|LLVM_READONLY
decl_stmt|;
comment|/// out-of-line slow case for isSubsetOf.
name|bool
name|isSubsetOfSlowCase
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
name|LLVM_READONLY
decl_stmt|;
comment|/// out-of-line slow case for setBits.
name|void
name|setBitsSlowCase
parameter_list|(
name|unsigned
name|loBit
parameter_list|,
name|unsigned
name|hiBit
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for flipAllBits.
name|void
name|flipAllBitsSlowCase
parameter_list|()
function_decl|;
comment|/// out-of-line slow case for operator&=.
name|void
name|AndAssignSlowCase
parameter_list|(
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for operator|=.
name|void
name|OrAssignSlowCase
parameter_list|(
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
function_decl|;
comment|/// out-of-line slow case for operator^=.
name|void
name|XorAssignSlowCase
parameter_list|(
specifier|const
name|APInt
modifier|&
name|RHS
parameter_list|)
function_decl|;
comment|/// Unsigned comparison. Returns -1, 0, or 1 if this APInt is less than, equal
comment|/// to, or greater than RHS.
name|int
name|compare
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
name|LLVM_READONLY
decl_stmt|;
comment|/// Signed comparison. Returns -1, 0, or 1 if this APInt is less than, equal
comment|/// to, or greater than RHS.
name|int
name|compareSigned
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
name|LLVM_READONLY
decl_stmt|;
name|public
label|:
comment|/// \name Constructors
comment|/// @{
comment|/// \brief Create a new APInt of numBits width, initialized as val.
comment|///
comment|/// If isSigned is true then val is treated as if it were a signed value
comment|/// (i.e. as an int64_t) and the appropriate sign extension to the bit width
comment|/// will be done. Otherwise, no sign extension occurs (high order bits beyond
comment|/// the range of val are zero filled).
comment|///
comment|/// \param numBits the bit width of the constructed APInt
comment|/// \param val the initial value of the APInt
comment|/// \param isSigned how to treat signedness of val
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
argument|numBits
argument_list|)
block|{
name|assert
argument_list|(
name|BitWidth
operator|&&
literal|"bitwidth too small"
argument_list|)
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|U
operator|.
name|VAL
operator|=
name|val
expr_stmt|;
name|clearUnusedBits
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|initSlowCase
argument_list|(
name|val
argument_list|,
name|isSigned
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// \brief Construct an APInt of numBits width, initialized as bigVal[].
comment|///
comment|/// Note that bigVal.size() can be smaller or larger than the corresponding
comment|/// bit width but any extraneous bits will be dropped.
comment|///
comment|/// \param numBits the bit width of the constructed APInt
comment|/// \param bigVal a sequence of words to form the initial value of the APInt
name|APInt
argument_list|(
argument|unsigned numBits
argument_list|,
argument|ArrayRef<uint64_t> bigVal
argument_list|)
empty_stmt|;
comment|/// Equivalent to APInt(numBits, ArrayRef<uint64_t>(bigVal, numWords)), but
comment|/// deprecated because this constructor is prone to ambiguity with the
comment|/// APInt(unsigned, uint64_t, bool) constructor.
comment|///
comment|/// If this overload is ever deleted, care should be taken to prevent calls
comment|/// from being incorrectly captured by the APInt(unsigned, uint64_t, bool)
comment|/// constructor.
name|APInt
argument_list|(
argument|unsigned numBits
argument_list|,
argument|unsigned numWords
argument_list|,
argument|const uint64_t bigVal[]
argument_list|)
empty_stmt|;
comment|/// \brief Construct an APInt from a string representation.
comment|///
comment|/// This constructor interprets the string \p str in the given radix. The
comment|/// interpretation stops when the first character that is not suitable for the
comment|/// radix is encountered, or the end of the string. Acceptable radix values
comment|/// are 2, 8, 10, 16, and 36. It is an error for the value implied by the
comment|/// string to require more bits than numBits.
comment|///
comment|/// \param numBits the bit width of the constructed APInt
comment|/// \param str the string to be interpreted
comment|/// \param radix the radix to use for the conversion
name|APInt
argument_list|(
argument|unsigned numBits
argument_list|,
argument|StringRef str
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
argument|that.BitWidth
argument_list|)
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|U
operator|.
name|VAL
operator|=
name|that
operator|.
name|U
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
comment|/// \brief Move Constructor.
name|APInt
argument_list|(
name|APInt
operator|&&
name|that
argument_list|)
operator|:
name|BitWidth
argument_list|(
argument|that.BitWidth
argument_list|)
block|{
name|memcpy
argument_list|(
operator|&
name|U
argument_list|,
operator|&
name|that
operator|.
name|U
argument_list|,
sizeof|sizeof
argument_list|(
name|U
argument_list|)
argument_list|)
block|;
name|that
operator|.
name|BitWidth
operator|=
literal|0
block|;   }
comment|/// \brief Destructor.
operator|~
name|APInt
argument_list|()
block|{
if|if
condition|(
name|needsCleanup
argument_list|()
condition|)
name|delete
index|[]
name|U
operator|.
name|pVal
decl_stmt|;
block|}
comment|/// \brief Default constructor that creates an uninteresting APInt
comment|/// representing a 1-bit zero value.
comment|///
comment|/// This is useful for object deserialization (pair this with the static
comment|///  method Read).
name|explicit
name|APInt
argument_list|()
operator|:
name|BitWidth
argument_list|(
literal|1
argument_list|)
block|{
name|U
operator|.
name|VAL
operator|=
literal|0
block|; }
comment|/// \brief Returns whether this instance allocated memory.
name|bool
name|needsCleanup
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isSingleWord
argument_list|()
return|;
block|}
comment|/// Used to insert APInt objects, or objects that contain APInt objects, into
comment|///  FoldingSets.
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|id
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// \name Value Tests
comment|/// @{
comment|/// \brief Determine sign of this APInt.
comment|///
comment|/// This tests the high bit of this APInt to determine if it is set.
comment|///
comment|/// \returns true if this APInt is negative, false otherwise
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
comment|/// \brief Determine if this APInt Value is non-negative (>= 0)
comment|///
comment|/// This tests the high bit of the APInt to determine if it is unset.
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
comment|/// \brief Determine if sign bit of this APInt is set.
comment|///
comment|/// This tests the high bit of this APInt to determine if it is set.
comment|///
comment|/// \returns true if this APInt has its sign bit set, false otherwise.
name|bool
name|isSignBitSet
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
comment|/// \brief Determine if sign bit of this APInt is clear.
comment|///
comment|/// This tests the high bit of this APInt to determine if it is clear.
comment|///
comment|/// \returns true if this APInt has its sign bit clear, false otherwise.
name|bool
name|isSignBitClear
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isSignBitSet
argument_list|()
return|;
block|}
comment|/// \brief Determine if this APInt Value is positive.
comment|///
comment|/// This tests if the value of this APInt is positive (> 0). Note
comment|/// that 0 is not a positive value.
comment|///
comment|/// \returns true if this APInt is positive.
name|bool
name|isStrictlyPositive
argument_list|()
specifier|const
block|{
return|return
name|isNonNegative
argument_list|()
operator|&&
operator|!
name|isNullValue
argument_list|()
return|;
block|}
comment|/// \brief Determine if all bits are set
comment|///
comment|/// This checks to see if the value has all bits of the APInt are set or not.
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|U
operator|.
name|VAL
operator|==
name|WORD_MAX
operator|>>
operator|(
name|APINT_BITS_PER_WORD
operator|-
name|BitWidth
operator|)
return|;
return|return
name|countPopulationSlowCase
argument_list|()
operator|==
name|BitWidth
return|;
block|}
comment|/// \brief Determine if all bits are clear
comment|///
comment|/// This checks to see if the value has all bits of the APInt are clear or
comment|/// not.
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|*
name|this
return|;
block|}
comment|/// \brief Determine if this is the largest unsigned value.
comment|///
comment|/// This checks to see if the value of this APInt is the maximum unsigned
comment|/// value for the APInt's bit width.
name|bool
name|isMaxValue
argument_list|()
specifier|const
block|{
return|return
name|isAllOnesValue
argument_list|()
return|;
block|}
comment|/// \brief Determine if this is the largest signed value.
comment|///
comment|/// This checks to see if the value of this APInt is the maximum signed
comment|/// value for the APInt's bit width.
name|bool
name|isMaxSignedValue
argument_list|()
specifier|const
block|{
return|return
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
comment|/// \brief Determine if this is the smallest unsigned value.
comment|///
comment|/// This checks to see if the value of this APInt is the minimum unsigned
comment|/// value for the APInt's bit width.
name|bool
name|isMinValue
argument_list|()
specifier|const
block|{
return|return
name|isNullValue
argument_list|()
return|;
block|}
comment|/// \brief Determine if this is the smallest signed value.
comment|///
comment|/// This checks to see if the value of this APInt is the minimum signed
comment|/// value for the APInt's bit width.
name|bool
name|isMinSignedValue
argument_list|()
specifier|const
block|{
return|return
name|isNegative
argument_list|()
operator|&&
name|isPowerOf2
argument_list|()
return|;
block|}
comment|/// \brief Check if this APInt has an N-bits unsigned integer value.
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
return|return
name|getActiveBits
argument_list|()
operator|<=
name|N
return|;
block|}
comment|/// \brief Check if this APInt has an N-bits signed integer value.
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
comment|/// \brief Check if this APInt's value is a power of two greater than zero.
comment|///
comment|/// \returns true if the argument APInt value is a power of two> 0.
name|bool
name|isPowerOf2
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|isPowerOf2_64
argument_list|(
name|U
operator|.
name|VAL
argument_list|)
return|;
return|return
name|countPopulationSlowCase
argument_list|()
operator|==
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Check if the APInt's value is returned by getSignMask.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if this is the value returned by getSignMask.
end_comment

begin_expr_stmt
name|bool
name|isSignMask
argument_list|()
specifier|const
block|{
return|return
name|isMinSignedValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Convert APInt to a boolean value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This converts the APInt to a boolean value as a test against zero.
end_comment

begin_expr_stmt
name|bool
name|getBoolValue
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|!
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// If this value is smaller than the specified limit, return it, otherwise
end_comment

begin_comment
comment|/// return the limit value.  This causes the value to saturate to the limit.
end_comment

begin_decl_stmt
name|uint64_t
name|getLimitedValue
argument_list|(
name|uint64_t
name|Limit
operator|=
name|UINT64_MAX
argument_list|)
decl|const
block|{
return|return
name|ugt
argument_list|(
name|Limit
argument_list|)
condition|?
name|Limit
else|:
name|getZExtValue
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Check if the APInt consists of a repeated bit pattern.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// e.g. 0x01010101 satisfies isSplat(8).
end_comment

begin_comment
comment|/// \param SplatSizeInBits The size of the pattern in bits. Must divide bit
end_comment

begin_comment
comment|/// width without remainder.
end_comment

begin_decl_stmt
name|bool
name|isSplat
argument_list|(
name|unsigned
name|SplatSizeInBits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \returns true if this APInt value is a sequence of \param numBits ones
end_comment

begin_comment
comment|/// starting at the least significant bit with the remainder zero.
end_comment

begin_decl_stmt
name|bool
name|isMask
argument_list|(
name|unsigned
name|numBits
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|numBits
operator|!=
literal|0
operator|&&
literal|"numBits must be non-zero"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|numBits
operator|<=
name|BitWidth
operator|&&
literal|"numBits out of range"
argument_list|)
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|U
operator|.
name|VAL
operator|==
operator|(
name|WORD_MAX
operator|>>
operator|(
name|APINT_BITS_PER_WORD
operator|-
name|numBits
operator|)
operator|)
return|;
name|unsigned
name|Ones
init|=
name|countTrailingOnesSlowCase
argument_list|()
decl_stmt|;
return|return
operator|(
name|numBits
operator|==
name|Ones
operator|)
operator|&&
operator|(
operator|(
name|Ones
operator|+
name|countLeadingZerosSlowCase
argument_list|()
operator|)
operator|==
name|BitWidth
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \returns true if this APInt is a non-empty sequence of ones starting at
end_comment

begin_comment
comment|/// the least significant bit with the remainder zero.
end_comment

begin_comment
comment|/// Ex. isMask(0x0000FFFFU) == true.
end_comment

begin_expr_stmt
name|bool
name|isMask
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|isMask_64
argument_list|(
name|U
operator|.
name|VAL
argument_list|)
return|;
name|unsigned
name|Ones
operator|=
name|countTrailingOnesSlowCase
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|Ones
operator|>
literal|0
operator|)
operator|&&
operator|(
operator|(
name|Ones
operator|+
name|countLeadingZerosSlowCase
argument_list|()
operator|)
operator|==
name|BitWidth
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Return true if this APInt value contains a sequence of ones with
end_comment

begin_comment
comment|/// the remainder zero.
end_comment

begin_macro
unit|bool
name|isShiftedMask
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
name|isShiftedMask_64
argument_list|(
name|U
operator|.
name|VAL
argument_list|)
return|;
name|unsigned
name|Ones
operator|=
name|countPopulationSlowCase
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|LeadZ
init|=
name|countLeadingZerosSlowCase
argument_list|()
decl_stmt|;
end_decl_stmt

begin_return
return|return
operator|(
name|Ones
operator|+
name|LeadZ
operator|+
name|countTrailingZeros
argument_list|()
operator|)
operator|==
name|BitWidth
return|;
end_return

begin_comment
unit|}
comment|/// @}
end_comment

begin_comment
comment|/// \name Value Generators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Gets maximum unsigned value of APInt for specific bit width.
end_comment

begin_function
unit|static
name|APInt
name|getMaxValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
return|return
name|getAllOnesValue
argument_list|(
name|numBits
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Gets maximum signed value of APInt for a specific bit width.
end_comment

begin_function
specifier|static
name|APInt
name|getSignedMaxValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
name|APInt
name|API
init|=
name|getAllOnesValue
argument_list|(
name|numBits
argument_list|)
decl_stmt|;
name|API
operator|.
name|clearBit
argument_list|(
name|numBits
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|API
return|;
block|}
end_function

begin_comment
comment|/// \brief Gets minimum unsigned value of APInt for a specific bit width.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Gets minimum signed value of APInt for a specific bit width.
end_comment

begin_function
specifier|static
name|APInt
name|getSignedMinValue
parameter_list|(
name|unsigned
name|numBits
parameter_list|)
block|{
name|APInt
name|API
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|API
operator|.
name|setBit
argument_list|(
name|numBits
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|API
return|;
block|}
end_function

begin_comment
comment|/// \brief Get the SignMask for a specific bit width.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is just a wrapper function of getSignedMinValue(), and it helps code
end_comment

begin_comment
comment|/// readability when we want to get a SignMask.
end_comment

begin_function
specifier|static
name|APInt
name|getSignMask
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
end_function

begin_comment
comment|/// \brief Get the all-ones value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the all-ones value for an APInt of the specified bit-width.
end_comment

begin_function
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
name|WORD_MAX
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Get the '0' value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the '0' value for an APInt of the specified bit-width.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Compute an APInt containing numBits highbits from this APInt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get an APInt with the same BitWidth as this APInt, just zero mask
end_comment

begin_comment
comment|/// the low bits and right shift to the least significant bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the high "numBits" bits of this APInt.
end_comment

begin_decl_stmt
name|APInt
name|getHiBits
argument_list|(
name|unsigned
name|numBits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Compute an APInt containing numBits lowbits from this APInt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get an APInt with the same BitWidth as this APInt, just zero mask
end_comment

begin_comment
comment|/// the high bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the low "numBits" bits of this APInt.
end_comment

begin_decl_stmt
name|APInt
name|getLoBits
argument_list|(
name|unsigned
name|numBits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return an APInt with exactly one bit set in the result.
end_comment

begin_function
specifier|static
name|APInt
name|getOneBitSet
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
name|unsigned
name|BitNo
parameter_list|)
block|{
name|APInt
name|Res
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|Res
operator|.
name|setBit
argument_list|(
name|BitNo
argument_list|)
expr_stmt|;
return|return
name|Res
return|;
block|}
end_function

begin_comment
comment|/// \brief Get a value with a block of bits set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Constructs an APInt value that has a contiguous range of bits set. The
end_comment

begin_comment
comment|/// bits from loBit (inclusive) to hiBit (exclusive) will be set. All other
end_comment

begin_comment
comment|/// bits will be zero. For example, with parameters(32, 0, 16) you would get
end_comment

begin_comment
comment|/// 0x0000FFFF. If hiBit is less than loBit then the set bits "wrap". For
end_comment

begin_comment
comment|/// example, with parameters (32, 28, 4), you would get 0xF000000F.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param numBits the intended bit width of the result
end_comment

begin_comment
comment|/// \param loBit the index of the lowest bit set.
end_comment

begin_comment
comment|/// \param hiBit the index of the highest bit set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns An APInt value with the requested bits set.
end_comment

begin_function
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
name|APInt
name|Res
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|Res
operator|.
name|setBits
argument_list|(
name|loBit
argument_list|,
name|hiBit
argument_list|)
expr_stmt|;
return|return
name|Res
return|;
block|}
end_function

begin_comment
comment|/// \brief Get a value with upper bits starting at loBit set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Constructs an APInt value that has a contiguous range of bits set. The
end_comment

begin_comment
comment|/// bits from loBit (inclusive) to numBits (exclusive) will be set. All other
end_comment

begin_comment
comment|/// bits will be zero. For example, with parameters(32, 12) you would get
end_comment

begin_comment
comment|/// 0xFFFFF000.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param numBits the intended bit width of the result
end_comment

begin_comment
comment|/// \param loBit the index of the lowest bit to set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns An APInt value with the requested bits set.
end_comment

begin_function
specifier|static
name|APInt
name|getBitsSetFrom
parameter_list|(
name|unsigned
name|numBits
parameter_list|,
name|unsigned
name|loBit
parameter_list|)
block|{
name|APInt
name|Res
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|Res
operator|.
name|setBitsFrom
argument_list|(
name|loBit
argument_list|)
expr_stmt|;
return|return
name|Res
return|;
block|}
end_function

begin_comment
comment|/// \brief Get a value with high bits set
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Constructs an APInt value that has the top hiBitsSet bits set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param numBits the bitwidth of the result
end_comment

begin_comment
comment|/// \param hiBitsSet the number of high-order bits set in the result.
end_comment

begin_function
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
name|APInt
name|Res
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|Res
operator|.
name|setHighBits
argument_list|(
name|hiBitsSet
argument_list|)
expr_stmt|;
return|return
name|Res
return|;
block|}
end_function

begin_comment
comment|/// \brief Get a value with low bits set
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Constructs an APInt value that has the bottom loBitsSet bits set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param numBits the bitwidth of the result
end_comment

begin_comment
comment|/// \param loBitsSet the number of low-order bits set in the result.
end_comment

begin_function
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
name|APInt
name|Res
argument_list|(
name|numBits
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|Res
operator|.
name|setLowBits
argument_list|(
name|loBitsSet
argument_list|)
expr_stmt|;
return|return
name|Res
return|;
block|}
end_function

begin_comment
comment|/// \brief Return a value containing V broadcasted over NewLen bits.
end_comment

begin_function_decl
specifier|static
name|APInt
name|getSplat
parameter_list|(
name|unsigned
name|NewLen
parameter_list|,
specifier|const
name|APInt
modifier|&
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine if two APInts have the same value, after zero-extending
end_comment

begin_comment
comment|/// one of them (if needed!) to ensure that the bit-widths match.
end_comment

begin_function
specifier|static
name|bool
name|isSameValue
parameter_list|(
specifier|const
name|APInt
modifier|&
name|I1
parameter_list|,
specifier|const
name|APInt
modifier|&
name|I2
parameter_list|)
block|{
if|if
condition|(
name|I1
operator|.
name|getBitWidth
argument_list|()
operator|==
name|I2
operator|.
name|getBitWidth
argument_list|()
condition|)
return|return
name|I1
operator|==
name|I2
return|;
if|if
condition|(
name|I1
operator|.
name|getBitWidth
argument_list|()
operator|>
name|I2
operator|.
name|getBitWidth
argument_list|()
condition|)
return|return
name|I1
operator|==
name|I2
operator|.
name|zext
argument_list|(
name|I1
operator|.
name|getBitWidth
argument_list|()
argument_list|)
return|;
return|return
name|I1
operator|.
name|zext
argument_list|(
name|I2
operator|.
name|getBitWidth
argument_list|()
argument_list|)
operator|==
name|I2
return|;
block|}
end_function

begin_comment
comment|/// \brief Overload to compute a hash_code for an APInt value.
end_comment

begin_function_decl
name|friend
name|hash_code
name|hash_value
parameter_list|(
specifier|const
name|APInt
modifier|&
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// This function returns a pointer to the internal storage of the APInt.
end_comment

begin_comment
comment|/// This is useful for writing out the APInt in binary form without any
end_comment

begin_comment
comment|/// conversions.
end_comment

begin_expr_stmt
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
name|U
operator|.
name|VAL
return|;
end_expr_stmt

begin_return
return|return
operator|&
name|U
operator|.
name|pVal
index|[
literal|0
index|]
return|;
end_return

begin_comment
unit|}
comment|/// @}
end_comment

begin_comment
comment|/// \name Unary Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Postfix increment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Increments *this by 1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a new APInt value representing the original value of *this.
end_comment

begin_expr_stmt
unit|const
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
comment|/// \brief Prefix increment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this incremented by one
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
comment|/// \brief Postfix decrement operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Decrements *this by 1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a new APInt value representing the original value of *this.
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
comment|/// \brief Prefix decrement operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this decremented by one.
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
comment|/// \brief Logical negation operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performs logical negation operation on this APInt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this is zero, false otherwise.
end_comment

begin_expr_stmt
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
return|return
name|U
operator|.
name|VAL
operator|==
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|countLeadingZerosSlowCase
argument_list|()
operator|==
name|BitWidth
return|;
end_return

begin_comment
unit|}
comment|/// @}
end_comment

begin_comment
comment|/// \name Assignment Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Copy assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this after assignment of RHS.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|=
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
name|U
operator|.
name|VAL
operator|=
name|RHS
operator|.
name|U
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
name|AssignSlowCase
argument_list|(
name|RHS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// @brief Move assignment operator.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|=
operator|(
name|APInt
operator|&&
name|that
operator|)
block|{
name|assert
argument_list|(
name|this
operator|!=
operator|&
name|that
operator|&&
literal|"Self-move not supported"
argument_list|)
block|;
if|if
condition|(
operator|!
name|isSingleWord
argument_list|()
condition|)
name|delete
index|[]
name|U
operator|.
name|pVal
decl_stmt|;
comment|// Use memcpy so that type based alias analysis sees both VAL and pVal
comment|// as modified.
name|memcpy
argument_list|(
operator|&
name|U
argument_list|,
operator|&
name|that
operator|.
name|U
argument_list|,
sizeof|sizeof
argument_list|(
name|U
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BitWidth
operator|=
name|that
operator|.
name|BitWidth
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|that
operator|.
name|BitWidth
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Assignment operator.
end_comment

begin_comment
comment|///
end_comment

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
comment|///
end_comment

begin_comment
comment|/// \returns *this after assignment of RHS value.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|=
operator|(
name|uint64_t
name|RHS
operator|)
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|U
operator|.
name|VAL
operator|=
name|RHS
expr_stmt|;
name|clearUnusedBits
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|U
operator|.
name|pVal
index|[
literal|0
index|]
operator|=
name|RHS
expr_stmt|;
name|memset
argument_list|(
name|U
operator|.
name|pVal
operator|+
literal|1
argument_list|,
literal|0
argument_list|,
operator|(
name|getNumWords
argument_list|()
operator|-
literal|1
operator|)
operator|*
name|APINT_WORD_SIZE
argument_list|)
expr_stmt|;
block|}
end_else

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Bitwise AND assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performs a bitwise AND operation on this APInt and RHS. The result is
end_comment

begin_comment
comment|/// assigned to *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this after ANDing with RHS.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
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
name|U
operator|.
name|VAL
operator|&=
name|RHS
operator|.
name|U
operator|.
name|VAL
expr_stmt|;
else|else
name|AndAssignSlowCase
argument_list|(
name|RHS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Bitwise AND assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performs a bitwise AND operation on this APInt and RHS. RHS is
end_comment

begin_comment
comment|/// logically zero-extended or truncated to match the bit-width of
end_comment

begin_comment
comment|/// the LHS.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|&=
operator|(
name|uint64_t
name|RHS
operator|)
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|U
operator|.
name|VAL
operator|&=
name|RHS
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|U
operator|.
name|pVal
index|[
literal|0
index|]
operator|&=
name|RHS
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|memset
argument_list|(
name|U
operator|.
name|pVal
operator|+
literal|1
argument_list|,
literal|0
argument_list|,
operator|(
name|getNumWords
argument_list|()
operator|-
literal|1
operator|)
operator|*
name|APINT_WORD_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Bitwise OR assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performs a bitwise OR operation on this APInt and RHS. The result is
end_comment

begin_comment
comment|/// assigned *this;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this after ORing with RHS.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator||=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
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
name|U
operator|.
name|VAL
operator||=
name|RHS
operator|.
name|U
operator|.
name|VAL
expr_stmt|;
else|else
name|OrAssignSlowCase
argument_list|(
name|RHS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Bitwise OR assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performs a bitwise OR operation on this APInt and RHS. RHS is
end_comment

begin_comment
comment|/// logically zero-extended or truncated to match the bit-width of
end_comment

begin_comment
comment|/// the LHS.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator||=
operator|(
name|uint64_t
name|RHS
operator|)
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|U
operator|.
name|VAL
operator||=
name|RHS
expr_stmt|;
name|clearUnusedBits
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|U
operator|.
name|pVal
index|[
literal|0
index|]
operator||=
name|RHS
expr_stmt|;
block|}
end_else

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Bitwise XOR assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performs a bitwise XOR operation on this APInt and RHS. The result is
end_comment

begin_comment
comment|/// assigned to *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this after XORing with RHS.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|^=
operator|(
specifier|const
name|APInt
operator|&
name|RHS
operator|)
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
name|U
operator|.
name|VAL
operator|^=
name|RHS
operator|.
name|U
operator|.
name|VAL
expr_stmt|;
else|else
name|XorAssignSlowCase
argument_list|(
name|RHS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Bitwise XOR assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performs a bitwise XOR operation on this APInt and RHS. RHS is
end_comment

begin_comment
comment|/// logically zero-extended or truncated to match the bit-width of
end_comment

begin_comment
comment|/// the LHS.
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|^=
operator|(
name|uint64_t
name|RHS
operator|)
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|U
operator|.
name|VAL
operator|^=
name|RHS
expr_stmt|;
name|clearUnusedBits
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|U
operator|.
name|pVal
index|[
literal|0
index|]
operator|^=
name|RHS
expr_stmt|;
block|}
end_else

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Multiplication assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Multiplies this APInt by RHS and assigns the result to *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this
end_comment

begin_expr_stmt
unit|APInt
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
comment|/// \brief Addition assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Adds RHS to *this and assigns the result to *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this
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

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|+=
operator|(
name|uint64_t
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Subtraction assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Subtracts RHS from *this and assigns the result to *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this
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

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|-=
operator|(
name|uint64_t
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Left-shift assignment function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Shifts *this left by shiftAmt and assigns the result to *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this after shifting left by ShiftAmt
end_comment

begin_expr_stmt
name|APInt
operator|&
name|operator
operator|<<=
operator|(
name|unsigned
name|ShiftAmt
operator|)
block|{
name|assert
argument_list|(
name|ShiftAmt
operator|<=
name|BitWidth
operator|&&
literal|"Invalid shift amount"
argument_list|)
block|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
if|if
condition|(
name|ShiftAmt
operator|==
name|BitWidth
condition|)
name|U
operator|.
name|VAL
operator|=
literal|0
expr_stmt|;
else|else
name|U
operator|.
name|VAL
operator|<<=
name|ShiftAmt
expr_stmt|;
return|return
name|clearUnusedBits
argument_list|()
return|;
block|}
name|shlSlowCase
argument_list|(
name|ShiftAmt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// \brief Left-shift assignment function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Shifts *this left by shiftAmt and assigns the result to *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns *this after shifting left by ShiftAmt
end_comment

begin_expr_stmt
unit|APInt
operator|&
name|operator
operator|<<=
operator|(
specifier|const
name|APInt
operator|&
name|ShiftAmt
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Binary Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Multiplication operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Multiplies this APInt by RHS and returns the result.
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
comment|/// \brief Left logical shift operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Shifts this APInt left by \p Bits and returns the result.
end_comment

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

begin_comment
comment|/// \brief Left logical shift operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Shifts this APInt left by \p Bits and returns the result.
end_comment

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
comment|/// \brief Arithmetic right-shift function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Arithmetic right-shift this APInt by shiftAmt.
end_comment

begin_decl_stmt
name|APInt
name|ashr
argument_list|(
name|unsigned
name|ShiftAmt
argument_list|)
decl|const
block|{
name|APInt
name|R
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|R
operator|.
name|ashrInPlace
argument_list|(
name|ShiftAmt
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Arithmetic right-shift this APInt by ShiftAmt in place.
end_comment

begin_function
name|void
name|ashrInPlace
parameter_list|(
name|unsigned
name|ShiftAmt
parameter_list|)
block|{
name|assert
argument_list|(
name|ShiftAmt
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
name|int64_t
name|SExtVAL
init|=
name|SignExtend64
argument_list|(
name|U
operator|.
name|VAL
argument_list|,
name|BitWidth
argument_list|)
decl_stmt|;
if|if
condition|(
name|ShiftAmt
operator|==
name|BitWidth
condition|)
name|U
operator|.
name|VAL
operator|=
name|SExtVAL
operator|>>
operator|(
name|APINT_BITS_PER_WORD
operator|-
literal|1
operator|)
expr_stmt|;
comment|// Fill with sign bit.
else|else
name|U
operator|.
name|VAL
operator|=
name|SExtVAL
operator|>>
name|ShiftAmt
expr_stmt|;
name|clearUnusedBits
argument_list|()
expr_stmt|;
return|return;
block|}
name|ashrSlowCase
argument_list|(
name|ShiftAmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Logical right-shift function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Logical right-shift this APInt by shiftAmt.
end_comment

begin_decl_stmt
name|APInt
name|lshr
argument_list|(
name|unsigned
name|shiftAmt
argument_list|)
decl|const
block|{
name|APInt
name|R
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|R
operator|.
name|lshrInPlace
argument_list|(
name|shiftAmt
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Logical right-shift this APInt by ShiftAmt in place.
end_comment

begin_function
name|void
name|lshrInPlace
parameter_list|(
name|unsigned
name|ShiftAmt
parameter_list|)
block|{
name|assert
argument_list|(
name|ShiftAmt
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
name|ShiftAmt
operator|==
name|BitWidth
condition|)
name|U
operator|.
name|VAL
operator|=
literal|0
expr_stmt|;
else|else
name|U
operator|.
name|VAL
operator|>>=
name|ShiftAmt
expr_stmt|;
return|return;
block|}
name|lshrSlowCase
argument_list|(
name|ShiftAmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Left-shift function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Left-shift this APInt by shiftAmt.
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
name|APInt
name|R
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|R
operator|<<=
name|shiftAmt
expr_stmt|;
return|return
name|R
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Rotate left by rotateAmt.
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
comment|/// \brief Rotate right by rotateAmt.
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
comment|/// \brief Arithmetic right-shift function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Arithmetic right-shift this APInt by shiftAmt.
end_comment

begin_decl_stmt
name|APInt
name|ashr
argument_list|(
specifier|const
name|APInt
operator|&
name|ShiftAmt
argument_list|)
decl|const
block|{
name|APInt
name|R
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|R
operator|.
name|ashrInPlace
argument_list|(
name|ShiftAmt
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Arithmetic right-shift this APInt by shiftAmt in place.
end_comment

begin_function_decl
name|void
name|ashrInPlace
parameter_list|(
specifier|const
name|APInt
modifier|&
name|shiftAmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Logical right-shift function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Logical right-shift this APInt by shiftAmt.
end_comment

begin_decl_stmt
name|APInt
name|lshr
argument_list|(
specifier|const
name|APInt
operator|&
name|ShiftAmt
argument_list|)
decl|const
block|{
name|APInt
name|R
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|R
operator|.
name|lshrInPlace
argument_list|(
name|ShiftAmt
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Logical right-shift this APInt by ShiftAmt in place.
end_comment

begin_function_decl
name|void
name|lshrInPlace
parameter_list|(
specifier|const
name|APInt
modifier|&
name|ShiftAmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Left-shift function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Left-shift this APInt by shiftAmt.
end_comment

begin_decl_stmt
name|APInt
name|shl
argument_list|(
specifier|const
name|APInt
operator|&
name|ShiftAmt
argument_list|)
decl|const
block|{
name|APInt
name|R
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|R
operator|<<=
name|ShiftAmt
expr_stmt|;
return|return
name|R
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Rotate left by rotateAmt.
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
comment|/// \brief Rotate right by rotateAmt.
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
comment|/// \brief Unsigned division operation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Perform an unsigned divide operation on this APInt by RHS. Both this and
end_comment

begin_comment
comment|/// RHS are treated as unsigned quantities for purposes of this division.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a new APInt value containing the division result
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
comment|/// \brief Signed division function for APInt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signed divide this APInt by APInt RHS.
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Unsigned remainder operation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Perform an unsigned remainder operation on this APInt with RHS being the
end_comment

begin_comment
comment|/// divisor. Both this and RHS are treated as unsigned quantities for purposes
end_comment

begin_comment
comment|/// of this operation. Note that this is a true remainder operation and not a
end_comment

begin_comment
comment|/// modulo operation because the sign follows the sign of the dividend which
end_comment

begin_comment
comment|/// is *this.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a new APInt value containing the remainder result
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
comment|/// \brief Function for signed remainder operation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signed remainder operation on APInt.
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Dual division/remainder interface.
end_comment

begin_comment
comment|///
end_comment

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

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|// Operations that return overflow indicators.
end_comment

begin_decl_stmt
name|APInt
name|sadd_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|uadd_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|ssub_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|usub_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|sdiv_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|smul_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|umul_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|RHS
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|sshl_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|Amt
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|APInt
name|ushl_ov
argument_list|(
specifier|const
name|APInt
operator|&
name|Amt
argument_list|,
name|bool
operator|&
name|Overflow
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Array-indexing support.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the bit value at bitPosition
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
block|{
name|assert
argument_list|(
name|bitPosition
operator|<
name|getBitWidth
argument_list|()
operator|&&
literal|"Bit position out of bounds!"
argument_list|)
expr_stmt|;
return|return
operator|(
name|maskBit
argument_list|(
name|bitPosition
argument_list|)
operator|&
operator|(
name|isSingleWord
argument_list|()
condition|?
name|U
operator|.
name|VAL
else|:
name|U
operator|.
name|pVal
index|[
name|whichWord
argument_list|(
name|bitPosition
argument_list|)
index|]
operator|)
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
comment|/// \name Comparison Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Equality operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compares this APInt with RHS for the validity of the equality
end_comment

begin_comment
comment|/// relationship.
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
name|U
operator|.
name|VAL
operator|==
name|RHS
operator|.
name|U
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
comment|/// \brief Equality operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compares this APInt with a uint64_t for the validity of the equality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this == Val
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
return|return
operator|(
name|isSingleWord
argument_list|()
operator|||
name|getActiveBits
argument_list|()
operator|<=
literal|64
operator|)
operator|&&
name|getZExtValue
argument_list|()
operator|==
name|Val
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Equality comparison.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compares this APInt with RHS for the validity of the equality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this == Val
end_comment

begin_decl_stmt
name|bool
name|eq
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
operator|)
operator|==
name|RHS
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Inequality operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compares this APInt with RHS for the validity of the inequality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this != Val
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
comment|/// \brief Inequality operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compares this APInt with a uint64_t for the validity of the inequality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this != Val
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
comment|/// \brief Inequality comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Compares this APInt with RHS for the validity of the inequality
end_comment

begin_comment
comment|/// relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this != Val
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
comment|/// \brief Unsigned less than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// the validity of the less-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this< RHS when both are considered unsigned.
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
block|{
return|return
name|compare
argument_list|(
name|RHS
argument_list|)
operator|<
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Unsigned less than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as an unsigned quantity and compares it with RHS for
end_comment

begin_comment
comment|/// the validity of the less-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this< RHS when considered unsigned.
end_comment

begin_decl_stmt
name|bool
name|ult
argument_list|(
name|uint64_t
name|RHS
argument_list|)
decl|const
block|{
comment|// Only need to check active bits if not a single word.
return|return
operator|(
name|isSingleWord
argument_list|()
operator|||
name|getActiveBits
argument_list|()
operator|<=
literal|64
operator|)
operator|&&
name|getZExtValue
argument_list|()
operator|<
name|RHS
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Signed less than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for
end_comment

begin_comment
comment|/// validity of the less-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this< RHS when both are considered signed.
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
block|{
return|return
name|compareSigned
argument_list|(
name|RHS
argument_list|)
operator|<
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Signed less than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as a signed quantity and compares it with RHS for
end_comment

begin_comment
comment|/// the validity of the less-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this< RHS when considered signed.
end_comment

begin_decl_stmt
name|bool
name|slt
argument_list|(
name|int64_t
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|(
operator|!
name|isSingleWord
argument_list|()
operator|&&
name|getMinSignedBits
argument_list|()
operator|>
literal|64
operator|)
condition|?
name|isNegative
argument_list|()
else|:
name|getSExtValue
argument_list|()
operator|<
name|RHS
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Unsigned less or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// validity of the less-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this<= RHS when both are considered unsigned.
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
name|compare
argument_list|(
name|RHS
argument_list|)
operator|<=
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Unsigned less or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as an unsigned quantity and compares it with RHS for
end_comment

begin_comment
comment|/// the validity of the less-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this<= RHS when considered unsigned.
end_comment

begin_decl_stmt
name|bool
name|ule
argument_list|(
name|uint64_t
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|!
name|ugt
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Signed less or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for
end_comment

begin_comment
comment|/// validity of the less-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this<= RHS when both are considered signed.
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
name|compareSigned
argument_list|(
name|RHS
argument_list|)
operator|<=
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Signed less or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as a signed quantity and compares it with RHS for the
end_comment

begin_comment
comment|/// validity of the less-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this<= RHS when considered signed.
end_comment

begin_decl_stmt
name|bool
name|sle
argument_list|(
name|uint64_t
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|!
name|sgt
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Unsigned greather than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// the validity of the greater-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this> RHS when both are considered unsigned.
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
name|ule
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Unsigned greater than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as an unsigned quantity and compares it with RHS for
end_comment

begin_comment
comment|/// the validity of the greater-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this> RHS when considered unsigned.
end_comment

begin_decl_stmt
name|bool
name|ugt
argument_list|(
name|uint64_t
name|RHS
argument_list|)
decl|const
block|{
comment|// Only need to check active bits if not a single word.
return|return
operator|(
operator|!
name|isSingleWord
argument_list|()
operator|&&
name|getActiveBits
argument_list|()
operator|>
literal|64
operator|)
operator|||
name|getZExtValue
argument_list|()
operator|>
name|RHS
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Signed greather than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for the
end_comment

begin_comment
comment|/// validity of the greater-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this> RHS when both are considered signed.
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
name|sle
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Signed greater than comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as a signed quantity and compares it with RHS for
end_comment

begin_comment
comment|/// the validity of the greater-than relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this> RHS when considered signed.
end_comment

begin_decl_stmt
name|bool
name|sgt
argument_list|(
name|int64_t
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|(
operator|!
name|isSingleWord
argument_list|()
operator|&&
name|getMinSignedBits
argument_list|()
operator|>
literal|64
operator|)
condition|?
operator|!
name|isNegative
argument_list|()
else|:
name|getSExtValue
argument_list|()
operator|>
name|RHS
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Unsigned greater or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as unsigned quantities and compares them for
end_comment

begin_comment
comment|/// validity of the greater-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this>= RHS when both are considered unsigned.
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
comment|/// \brief Unsigned greater or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as an unsigned quantity and compares it with RHS for
end_comment

begin_comment
comment|/// the validity of the greater-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this>= RHS when considered unsigned.
end_comment

begin_decl_stmt
name|bool
name|uge
argument_list|(
name|uint64_t
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
comment|/// \brief Signed greather or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this and RHS as signed quantities and compares them for
end_comment

begin_comment
comment|/// validity of the greater-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this>= RHS when both are considered signed.
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
comment|/// \brief Signed greater or equal comparison
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regards both *this as a signed quantity and compares it with RHS for
end_comment

begin_comment
comment|/// the validity of the greater-or-equal relationship.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if *this>= RHS when considered signed.
end_comment

begin_decl_stmt
name|bool
name|sge
argument_list|(
name|int64_t
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
operator|(
name|U
operator|.
name|VAL
operator|&
name|RHS
operator|.
name|U
operator|.
name|VAL
operator|)
operator|!=
literal|0
return|;
return|return
name|intersectsSlowCase
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// This operation checks that all bits set in this APInt are also set in RHS.
end_comment

begin_decl_stmt
name|bool
name|isSubsetOf
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
operator|(
name|U
operator|.
name|VAL
operator|&
operator|~
name|RHS
operator|.
name|U
operator|.
name|VAL
operator|)
operator|==
literal|0
return|;
return|return
name|isSubsetOfSlowCase
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Resizing Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Truncate to new width.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Truncate the APInt to a specified width. It is an error to specify a width
end_comment

begin_comment
comment|/// that is greater than or equal to the current width.
end_comment

begin_decl_stmt
name|APInt
name|trunc
argument_list|(
name|unsigned
name|width
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Sign extend to a new width.
end_comment

begin_comment
comment|///
end_comment

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

begin_decl_stmt
name|APInt
name|sext
argument_list|(
name|unsigned
name|width
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Zero extend to a new width.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operation zero extends the APInt to a new width. The high order bits
end_comment

begin_comment
comment|/// are filled with 0 bits.  It is an error to specify a width that is less
end_comment

begin_comment
comment|/// than or equal to the current width.
end_comment

begin_decl_stmt
name|APInt
name|zext
argument_list|(
name|unsigned
name|width
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Sign extend or truncate to width
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Make this APInt have the bit width given by \p width. The value is sign
end_comment

begin_comment
comment|/// extended, truncated, or left alone to make it that width.
end_comment

begin_decl_stmt
name|APInt
name|sextOrTrunc
argument_list|(
name|unsigned
name|width
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Zero extend or truncate to width
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Make this APInt have the bit width given by \p width. The value is zero
end_comment

begin_comment
comment|/// extended, truncated, or left alone to make it that width.
end_comment

begin_decl_stmt
name|APInt
name|zextOrTrunc
argument_list|(
name|unsigned
name|width
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Sign extend or truncate to width
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Make this APInt have the bit width given by \p width. The value is sign
end_comment

begin_comment
comment|/// extended, or left alone to make it that width.
end_comment

begin_decl_stmt
name|APInt
name|sextOrSelf
argument_list|(
name|unsigned
name|width
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Zero extend or truncate to width
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Make this APInt have the bit width given by \p width. The value is zero
end_comment

begin_comment
comment|/// extended, or left alone to make it that width.
end_comment

begin_decl_stmt
name|APInt
name|zextOrSelf
argument_list|(
name|unsigned
name|width
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Bit Manipulation Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Set every bit to 1.
end_comment

begin_function
name|void
name|setAllBits
parameter_list|()
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|U
operator|.
name|VAL
operator|=
name|WORD_MAX
expr_stmt|;
else|else
comment|// Set all the bits in all the words.
name|memset
argument_list|(
name|U
operator|.
name|pVal
argument_list|,
operator|-
literal|1
argument_list|,
name|getNumWords
argument_list|()
operator|*
name|APINT_WORD_SIZE
argument_list|)
expr_stmt|;
comment|// Clear the unused ones
name|clearUnusedBits
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Set a given bit to 1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set the given bit to 1 whose position is given as "bitPosition".
end_comment

begin_function
name|void
name|setBit
parameter_list|(
name|unsigned
name|BitPosition
parameter_list|)
block|{
name|assert
argument_list|(
name|BitPosition
operator|<=
name|BitWidth
operator|&&
literal|"BitPosition out of range"
argument_list|)
expr_stmt|;
name|WordType
name|Mask
init|=
name|maskBit
argument_list|(
name|BitPosition
argument_list|)
decl_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|U
operator|.
name|VAL
operator||=
name|Mask
expr_stmt|;
else|else
name|U
operator|.
name|pVal
index|[
name|whichWord
argument_list|(
name|BitPosition
argument_list|)
index|]
operator||=
name|Mask
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Set the sign bit to 1.
end_comment

begin_function
name|void
name|setSignBit
parameter_list|()
block|{
name|setBit
argument_list|(
name|BitWidth
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Set the bits from loBit (inclusive) to hiBit (exclusive) to 1.
end_comment

begin_function
name|void
name|setBits
parameter_list|(
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
name|BitWidth
operator|&&
literal|"hiBit out of range"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|loBit
operator|<=
name|BitWidth
operator|&&
literal|"loBit out of range"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|loBit
operator|<=
name|hiBit
operator|&&
literal|"loBit greater than hiBit"
argument_list|)
expr_stmt|;
if|if
condition|(
name|loBit
operator|==
name|hiBit
condition|)
return|return;
if|if
condition|(
name|loBit
operator|<
name|APINT_BITS_PER_WORD
operator|&&
name|hiBit
operator|<=
name|APINT_BITS_PER_WORD
condition|)
block|{
name|uint64_t
name|mask
init|=
name|WORD_MAX
operator|>>
operator|(
name|APINT_BITS_PER_WORD
operator|-
operator|(
name|hiBit
operator|-
name|loBit
operator|)
operator|)
decl_stmt|;
name|mask
operator|<<=
name|loBit
expr_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|U
operator|.
name|VAL
operator||=
name|mask
expr_stmt|;
else|else
name|U
operator|.
name|pVal
index|[
literal|0
index|]
operator||=
name|mask
expr_stmt|;
block|}
else|else
block|{
name|setBitsSlowCase
argument_list|(
name|loBit
argument_list|,
name|hiBit
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// Set the top bits starting from loBit.
end_comment

begin_function
name|void
name|setBitsFrom
parameter_list|(
name|unsigned
name|loBit
parameter_list|)
block|{
return|return
name|setBits
argument_list|(
name|loBit
argument_list|,
name|BitWidth
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Set the bottom loBits bits.
end_comment

begin_function
name|void
name|setLowBits
parameter_list|(
name|unsigned
name|loBits
parameter_list|)
block|{
return|return
name|setBits
argument_list|(
literal|0
argument_list|,
name|loBits
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Set the top hiBits bits.
end_comment

begin_function
name|void
name|setHighBits
parameter_list|(
name|unsigned
name|hiBits
parameter_list|)
block|{
return|return
name|setBits
argument_list|(
name|BitWidth
operator|-
name|hiBits
argument_list|,
name|BitWidth
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Set every bit to 0.
end_comment

begin_function
name|void
name|clearAllBits
parameter_list|()
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|U
operator|.
name|VAL
operator|=
literal|0
expr_stmt|;
else|else
name|memset
argument_list|(
name|U
operator|.
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
block|}
end_function

begin_comment
comment|/// \brief Set a given bit to 0.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set the given bit to 0 whose position is given as "bitPosition".
end_comment

begin_function
name|void
name|clearBit
parameter_list|(
name|unsigned
name|BitPosition
parameter_list|)
block|{
name|assert
argument_list|(
name|BitPosition
operator|<=
name|BitWidth
operator|&&
literal|"BitPosition out of range"
argument_list|)
expr_stmt|;
name|WordType
name|Mask
init|=
operator|~
name|maskBit
argument_list|(
name|BitPosition
argument_list|)
decl_stmt|;
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
name|U
operator|.
name|VAL
operator|&=
name|Mask
expr_stmt|;
else|else
name|U
operator|.
name|pVal
index|[
name|whichWord
argument_list|(
name|BitPosition
argument_list|)
index|]
operator|&=
name|Mask
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Set the sign bit to 0.
end_comment

begin_function
name|void
name|clearSignBit
parameter_list|()
block|{
name|clearBit
argument_list|(
name|BitWidth
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Toggle every bit to its opposite value.
end_comment

begin_function
name|void
name|flipAllBits
parameter_list|()
block|{
if|if
condition|(
name|isSingleWord
argument_list|()
condition|)
block|{
name|U
operator|.
name|VAL
operator|^=
name|WORD_MAX
expr_stmt|;
name|clearUnusedBits
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|flipAllBitsSlowCase
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// \brief Toggles a given bit to its opposite value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Toggle a given bit to its opposite value whose position is given
end_comment

begin_comment
comment|/// as "bitPosition".
end_comment

begin_function_decl
name|void
name|flipBit
parameter_list|(
name|unsigned
name|bitPosition
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Insert the bits from a smaller APInt starting at bitPosition.
end_comment

begin_function_decl
name|void
name|insertBits
parameter_list|(
specifier|const
name|APInt
modifier|&
name|SubBits
parameter_list|,
name|unsigned
name|bitPosition
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return an APInt with the extracted bits [bitPosition,bitPosition+numBits).
end_comment

begin_decl_stmt
name|APInt
name|extractBits
argument_list|(
name|unsigned
name|numBits
argument_list|,
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
comment|/// \name Value Characterization Functions
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Return the number of bits in the APInt.
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
comment|/// \brief Get the number of words.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Here one word's bitwidth equals to that of uint64_t.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the number of words to hold the integer value of this APInt.
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
comment|/// \brief Get the number of words.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// *NOTE* Here one word's bitwidth equals to that of uint64_t.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the number of words to hold the integer value with a given bit
end_comment

begin_comment
comment|/// width.
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
operator|(
name|uint64_t
operator|)
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
comment|/// \brief Compute the number of active bits in the value
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function returns the number of active bits which is defined as the
end_comment

begin_comment
comment|/// bit width minus the number of leading zeros. This is used in several
end_comment

begin_comment
comment|/// computations to see how "wide" the value is.
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
comment|/// \brief Compute the number of active words in the value of this APInt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used in conjunction with getActiveData to extract the raw value of
end_comment

begin_comment
comment|/// the APInt.
end_comment

begin_expr_stmt
name|unsigned
name|getActiveWords
argument_list|()
specifier|const
block|{
name|unsigned
name|numActiveBits
operator|=
name|getActiveBits
argument_list|()
block|;
return|return
name|numActiveBits
condition|?
name|whichWord
argument_list|(
name|numActiveBits
operator|-
literal|1
argument_list|)
operator|+
literal|1
else|:
literal|1
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the minimum bit size for this signed APInt
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computes the minimum bit width for this APInt while considering it to be a
end_comment

begin_comment
comment|/// signed (and probably negative) value. If the value is not negative, this
end_comment

begin_comment
comment|/// function returns the same value as getActiveBits()+1. Otherwise, it
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
comment|/// \brief Get zero extended value
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method attempts to return the value of this APInt as a zero extended
end_comment

begin_comment
comment|/// uint64_t. The bitwidth must be<= 64 or the value must fit within a
end_comment

begin_comment
comment|/// uint64_t. Otherwise an assertion will result.
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
name|U
operator|.
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
name|U
operator|.
name|pVal
index|[
literal|0
index|]
return|;
end_return

begin_comment
unit|}
comment|/// \brief Get sign extended value
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method attempts to return the value of this APInt as a sign extended
end_comment

begin_comment
comment|/// int64_t. The bit width must be<= 64 or the value must fit within an
end_comment

begin_comment
comment|/// int64_t. Otherwise an assertion will result.
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
name|SignExtend64
argument_list|(
name|U
operator|.
name|VAL
argument_list|,
name|BitWidth
argument_list|)
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
name|U
operator|.
name|pVal
index|[
literal|0
index|]
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Get bits required for string value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method determines how many bits are required to hold the APInt
end_comment

begin_comment
comment|/// equivalent of the string given by \p str.
end_comment

begin_function_decl
unit|static
name|unsigned
name|getBitsNeeded
parameter_list|(
name|StringRef
name|str
parameter_list|,
name|uint8_t
name|radix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The APInt version of the countLeadingZeros functions in
end_comment

begin_comment
comment|///   MathExtras.h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It counts the number of zeros from the most significant bit to the first
end_comment

begin_comment
comment|/// one bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns BitWidth if the value is zero, otherwise returns the number of
end_comment

begin_comment
comment|///   zeros from the most significant bit to the first one bits.
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
name|llvm
operator|::
name|countLeadingZeros
argument_list|(
name|U
operator|.
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
comment|/// \brief Count the number of leading one bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function is an APInt version of the countLeadingOnes
end_comment

begin_comment
comment|/// functions in MathExtras.h. It counts the number of ones from the most
end_comment

begin_comment
comment|/// significant bit to the first zero bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns 0 if the high order bit is not set, otherwise returns the number
end_comment

begin_comment
comment|/// of 1 bits from the most significant to the least
end_comment

begin_macro
unit|unsigned
name|countLeadingOnes
argument_list|()
end_macro

begin_expr_stmt
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Computes the number of leading bits of this APInt that are equal to its
end_comment

begin_comment
comment|/// sign bit.
end_comment

begin_expr_stmt
name|unsigned
name|getNumSignBits
argument_list|()
specifier|const
block|{
return|return
name|isNegative
argument_list|()
operator|?
name|countLeadingOnes
argument_list|()
operator|:
name|countLeadingZeros
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Count the number of trailing zero bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function is an APInt version of the countTrailingZeros
end_comment

begin_comment
comment|/// functions in MathExtras.h. It counts the number of zeros from the least
end_comment

begin_comment
comment|/// significant bit to the first set bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns BitWidth if the value is zero, otherwise returns the number of
end_comment

begin_comment
comment|/// zeros from the least significant bit to the first one bit.
end_comment

begin_expr_stmt
name|unsigned
name|countTrailingZeros
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Count the number of trailing one bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function is an APInt version of the countTrailingOnes
end_comment

begin_comment
comment|/// functions in MathExtras.h. It counts the number of ones from the least
end_comment

begin_comment
comment|/// significant bit to the first zero bit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns BitWidth if the value is all ones, otherwise returns the number
end_comment

begin_comment
comment|/// of ones from the least significant bit to the first zero bit.
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
name|llvm
operator|::
name|countTrailingOnes
argument_list|(
name|U
operator|.
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
comment|/// \brief Count the number of bits set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function is an APInt version of the countPopulation functions
end_comment

begin_comment
comment|/// in MathExtras.h. It counts the number of 1 bits in the APInt value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns 0 if the value is zero, otherwise returns the number of set bits.
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
name|llvm
operator|::
name|countPopulation
argument_list|(
name|U
operator|.
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
comment|/// \name Conversion Functions
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
comment|/// Converts an APInt to a string and append it to Str.  Str is commonly a
end_comment

begin_comment
comment|/// SmallString.
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
argument_list|,
name|bool
name|formatAsCLiteral
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Considers the APInt to be unsigned and converts it into a string in the
end_comment

begin_comment
comment|/// radix given. The radix can be 2, 8, 10 16, or 36.
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
comment|/// radix given. The radix can be 2, 8, 10, 16, or 36.
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
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the APInt as a std::string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this is an inefficient method.  It is better to pass in a
end_comment

begin_comment
comment|/// SmallVector/SmallString to the methods above to avoid thrashing the heap
end_comment

begin_comment
comment|/// for the string.
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
comment|/// \returns a byte-swapped representation of this APInt Value.
end_comment

begin_expr_stmt
name|APInt
name|byteSwap
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \returns the value with the bit representation reversed of this APInt
end_comment

begin_comment
comment|/// Value.
end_comment

begin_expr_stmt
name|APInt
name|reverseBits
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Converts this APInt to a double value.
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
comment|/// \brief Converts this unsigned APInt to a double value.
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
comment|/// \brief Converts this signed APInt to a double value.
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
comment|/// \brief Converts APInt bits to a double
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The conversion does not do a translation from integer to double, it just
end_comment

begin_comment
comment|/// re-interprets the bits as a double. Note that it is valid to do this on
end_comment

begin_comment
comment|/// any bit width. Exactly 64 bits will be translated.
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
name|U
operator|.
name|VAL
else|:
name|U
operator|.
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
comment|/// \brief Converts APInt bits to a double
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The conversion does not do a translation from integer to float, it just
end_comment

begin_comment
comment|/// re-interprets the bits as a float. Note that it is valid to do this on
end_comment

begin_comment
comment|/// any bit width. Exactly 32 bits will be translated.
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
name|U
operator|.
name|VAL
else|:
name|U
operator|.
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
comment|/// \brief Converts a double to APInt bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The conversion does not do a translation from double to integer, it just
end_comment

begin_comment
comment|/// re-interprets the bits of the double.
end_comment

begin_function
specifier|static
name|APInt
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
return|return
name|APInt
argument_list|(
sizeof|sizeof
name|T
operator|*
name|CHAR_BIT
argument_list|,
name|T
operator|.
name|I
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a float to APInt bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The conversion does not do a translation from float to integer, it just
end_comment

begin_comment
comment|/// re-interprets the bits of the float.
end_comment

begin_function
specifier|static
name|APInt
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
return|return
name|APInt
argument_list|(
sizeof|sizeof
name|T
operator|*
name|CHAR_BIT
argument_list|,
name|T
operator|.
name|I
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Mathematics Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \returns the floor log base 2 of this APInt.
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
comment|/// \returns the ceil log base 2 of this APInt.
end_comment

begin_expr_stmt
name|unsigned
name|ceilLogBase2
argument_list|()
specifier|const
block|{
name|APInt
name|temp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|--
name|temp
block|;
return|return
name|BitWidth
operator|-
name|temp
operator|.
name|countLeadingZeros
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns the nearest log base 2 of this APInt. Ties round up.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: When we have a BitWidth of 1, we define:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   log2(0) = UINT32_MAX
end_comment

begin_comment
comment|///   log2(1) = 0
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// to get around any mathematical concerns resulting from
end_comment

begin_comment
comment|/// referencing 2 in a space where 2 does no exist.
end_comment

begin_expr_stmt
name|unsigned
name|nearestLogBase2
argument_list|()
specifier|const
block|{
comment|// Special case when we have a bitwidth of 1. If VAL is 1, then we
comment|// get 0. If VAL is 0, we get WORD_MAX which gets truncated to
comment|// UINT32_MAX.
if|if
condition|(
name|BitWidth
operator|==
literal|1
condition|)
return|return
name|U
operator|.
name|VAL
operator|-
literal|1
return|;
end_expr_stmt

begin_comment
comment|// Handle the zero case.
end_comment

begin_if
if|if
condition|(
name|isNullValue
argument_list|()
condition|)
return|return
name|UINT32_MAX
return|;
end_if

begin_comment
comment|// The non-zero case is handled by computing:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   nearestLogBase2(x) = logBase2(x) + x[logBase2(x)-1].
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// where x[i] is referring to the value of the ith bit of x.
end_comment

begin_decl_stmt
name|unsigned
name|lg
init|=
name|logBase2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_return
return|return
name|lg
operator|+
name|unsigned
argument_list|(
operator|(
operator|*
name|this
operator|)
index|[
name|lg
operator|-
literal|1
index|]
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \returns the log base 2 of this APInt if its an exact power of two, -1
end_comment

begin_comment
comment|/// otherwise
end_comment

begin_macro
unit|int32_t
name|exactLogBase2
argument_list|()
end_macro

begin_expr_stmt
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
comment|/// \brief Compute the square root
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
comment|/// \brief Get the absolute value;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If *this is< 0 then return -(*this), otherwise *this;
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
comment|/// \returns the multiplicative inverse for a given modulo.
end_comment

begin_macro
unit|APInt
name|multiplicativeInverse
argument_list|(
argument|const APInt&modulo
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
comment|/// \name Support for division by constant
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

begin_decl_stmt
name|mu
name|magicu
argument_list|(
name|unsigned
name|LeadingZeros
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Building-block Operations for APInt and APFloat
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|// These building block operations operate on a representation of arbitrary
end_comment

begin_comment
comment|// precision, two's-complement, bignum integer values. They should be
end_comment

begin_comment
comment|// sufficient to implement APInt and APFloat bignum requirements. Inputs are
end_comment

begin_comment
comment|// generally a pointer to the base of an array of integer parts, representing
end_comment

begin_comment
comment|// an unsigned bignum, and a count of how many parts there are.
end_comment

begin_comment
comment|/// Sets the least significant part of a bignum to the input value, and zeroes
end_comment

begin_comment
comment|/// out higher parts.
end_comment

begin_function_decl
specifier|static
name|void
name|tcSet
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|WordType
parameter_list|,
name|unsigned
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
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
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
name|WordType
modifier|*
parameter_list|,
name|unsigned
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
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Copy the bit vector of width srcBITS from SRC, starting at bit srcLSB, to
end_comment

begin_comment
comment|/// DST, of dstCOUNT parts, such that the bit srcLSB becomes the least
end_comment

begin_comment
comment|/// significant bit of DST.  All high bits above srcBITS in DST are
end_comment

begin_comment
comment|/// zero-filled.
end_comment

begin_function_decl
specifier|static
name|void
name|tcExtract
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|dstCount
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|srcBits
parameter_list|,
name|unsigned
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
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Clear the given bit of a bignum.  Zero-based.
end_comment

begin_function_decl
specifier|static
name|void
name|tcClearBit
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the bit number of the least or most significant set bit of a
end_comment

begin_comment
comment|/// number.  If the input number has no bits set -1U is returned.
end_comment

begin_function_decl
specifier|static
name|unsigned
name|tcLSB
parameter_list|(
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|unsigned
name|tcMSB
parameter_list|(
specifier|const
name|WordType
modifier|*
name|parts
parameter_list|,
name|unsigned
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
name|WordType
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST += RHS + CARRY where CARRY is zero or one.  Returns the carry flag.
end_comment

begin_function_decl
specifier|static
name|WordType
name|tcAdd
parameter_list|(
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|WordType
name|carry
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST += RHS.  Returns the carry flag.
end_comment

begin_function_decl
specifier|static
name|WordType
name|tcAddPart
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|WordType
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST -= RHS + CARRY where CARRY is zero or one. Returns the carry flag.
end_comment

begin_function_decl
specifier|static
name|WordType
name|tcSubtract
parameter_list|(
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|WordType
name|carry
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST -= RHS.  Returns the carry flag.
end_comment

begin_function_decl
specifier|static
name|WordType
name|tcSubtractPart
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|WordType
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST += SRC * MULTIPLIER + PART   if add is true
end_comment

begin_comment
comment|/// DST  = SRC * MULTIPLIER + PART   if add is false
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Requires 0<= DSTPARTS<= SRCPARTS + 1.  If DST overlaps SRC they must
end_comment

begin_comment
comment|/// start at the same point, i.e. DST == SRC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If DSTPARTS == SRC_PARTS + 1 no overflow occurs and zero is returned.
end_comment

begin_comment
comment|/// Otherwise DST is filled with the least significant DSTPARTS parts of the
end_comment

begin_comment
comment|/// result, and if all of the omitted higher parts were zero return zero,
end_comment

begin_comment
comment|/// otherwise overflow occurred and return one.
end_comment

begin_function_decl
specifier|static
name|int
name|tcMultiplyPart
parameter_list|(
name|WordType
modifier|*
name|dst
parameter_list|,
specifier|const
name|WordType
modifier|*
name|src
parameter_list|,
name|WordType
name|multiplier
parameter_list|,
name|WordType
name|carry
parameter_list|,
name|unsigned
name|srcParts
parameter_list|,
name|unsigned
name|dstParts
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST = LHS * RHS, where DST has the same width as the operands and is
end_comment

begin_comment
comment|/// filled with the least significant parts of the result.  Returns one if
end_comment

begin_comment
comment|/// overflow occurred, otherwise zero.  DST must be disjoint from both
end_comment

begin_comment
comment|/// operands.
end_comment

begin_function_decl
specifier|static
name|int
name|tcMultiply
parameter_list|(
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DST = LHS * RHS, where DST has width the sum of the widths of the
end_comment

begin_comment
comment|/// operands.  No overflow occurs.  DST must be disjoint from both
end_comment

begin_comment
comment|/// operands. Returns the number of parts required to hold the result.
end_comment

begin_function_decl
specifier|static
name|unsigned
name|tcFullMultiply
parameter_list|(
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
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
comment|/// Otherwise set LHS to LHS / RHS with the fractional part discarded, set
end_comment

begin_comment
comment|/// REMAINDER to the remainder, return zero.  i.e.
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
comment|/// SCRATCH is a bignum of the same size as the operands and result for use by
end_comment

begin_comment
comment|/// the routine; its contents need not be initialized and are destroyed.  LHS,
end_comment

begin_comment
comment|/// REMAINDER and SCRATCH must be distinct.
end_comment

begin_function_decl
specifier|static
name|int
name|tcDivide
parameter_list|(
name|WordType
modifier|*
name|lhs
parameter_list|,
specifier|const
name|WordType
modifier|*
name|rhs
parameter_list|,
name|WordType
modifier|*
name|remainder
parameter_list|,
name|WordType
modifier|*
name|scratch
parameter_list|,
name|unsigned
name|parts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Shift a bignum left Count bits. Shifted in bits are zero. There are no
end_comment

begin_comment
comment|/// restrictions on Count.
end_comment

begin_function_decl
specifier|static
name|void
name|tcShiftLeft
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|Words
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Shift a bignum right Count bits.  Shifted in bits are zero.  There are no
end_comment

begin_comment
comment|/// restrictions on Count.
end_comment

begin_function_decl
specifier|static
name|void
name|tcShiftRight
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|unsigned
name|Words
parameter_list|,
name|unsigned
name|Count
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
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|tcOr
parameter_list|(
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|tcXor
parameter_list|(
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|tcComplement
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|unsigned
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
name|WordType
modifier|*
parameter_list|,
specifier|const
name|WordType
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Increment a bignum in-place.  Return the carry flag.
end_comment

begin_function
specifier|static
name|WordType
name|tcIncrement
parameter_list|(
name|WordType
modifier|*
name|dst
parameter_list|,
name|unsigned
name|parts
parameter_list|)
block|{
return|return
name|tcAddPart
argument_list|(
name|dst
argument_list|,
literal|1
argument_list|,
name|parts
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Decrement a bignum in-place.  Return the borrow flag.
end_comment

begin_function
specifier|static
name|WordType
name|tcDecrement
parameter_list|(
name|WordType
modifier|*
name|dst
parameter_list|,
name|unsigned
name|parts
parameter_list|)
block|{
return|return
name|tcSubtractPart
argument_list|(
name|dst
argument_list|,
literal|1
argument_list|,
name|parts
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Set the least significant BITS and clear the rest.
end_comment

begin_function_decl
specifier|static
name|void
name|tcSetLeastSignificantBits
parameter_list|(
name|WordType
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief debug method
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

begin_comment
comment|/// \brief Unary bitwise complement operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns an APInt that is the bitwise complement of \p v.
end_comment

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|~
operator|(
name|APInt
name|v
operator|)
block|{
name|v
operator|.
name|flipAllBits
argument_list|()
block|;
return|return
name|v
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|APInt
name|operator
function|&(
name|APInt
name|a
function|, const
name|APInt
function|&b
end_function

begin_block
unit|)
block|{
name|a
operator|&=
name|b
expr_stmt|;
return|return
name|a
return|;
block|}
end_block

begin_decl_stmt
specifier|inline
name|APInt
name|operator
modifier|&
argument_list|(
specifier|const
name|APInt
operator|&
name|a
argument_list|,
name|APInt
operator|&&
name|b
argument_list|)
block|{
name|b
operator|&=
name|a
expr_stmt|;
return|return
name|std
operator|::
name|move
argument_list|(
name|b
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
specifier|inline
name|APInt
name|operator
function|&(
name|APInt
name|a
function|,
name|uint64_t
function|RHS
end_function

begin_block
unit|)
block|{
name|a
operator|&=
name|RHS
expr_stmt|;
return|return
name|a
return|;
block|}
end_block

begin_function
specifier|inline
name|APInt
name|operator
function|&(
name|uint64_t
name|LHS
function|,
name|APInt
function|b
end_function

begin_block
unit|)
block|{
name|b
operator|&=
name|LHS
expr_stmt|;
return|return
name|b
return|;
block|}
end_block

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator||
operator|(
name|APInt
name|a
operator|,
specifier|const
name|APInt
operator|&
name|b
operator|)
block|{
name|a
operator||=
name|b
block|;
return|return
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator||
operator|(
specifier|const
name|APInt
operator|&
name|a
operator|,
name|APInt
operator|&&
name|b
operator|)
block|{
name|b
operator||=
name|a
block|;
return|return
name|std
operator|::
name|move
argument_list|(
name|b
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator||
operator|(
name|APInt
name|a
operator|,
name|uint64_t
name|RHS
operator|)
block|{
name|a
operator||=
name|RHS
block|;
return|return
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator||
operator|(
name|uint64_t
name|LHS
operator|,
name|APInt
name|b
operator|)
block|{
name|b
operator||=
name|LHS
block|;
return|return
name|b
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|APInt
name|operator
modifier|^
parameter_list|(
name|APInt
name|a
parameter_list|,
specifier|const
name|APInt
modifier|&
name|b
parameter_list|)
block|{
name|a
operator|^=
name|b
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_decl_stmt
specifier|inline
name|APInt
name|operator
modifier|^
argument_list|(
specifier|const
name|APInt
operator|&
name|a
argument_list|,
name|APInt
operator|&&
name|b
argument_list|)
block|{
name|b
operator|^=
name|a
expr_stmt|;
return|return
name|std
operator|::
name|move
argument_list|(
name|b
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
specifier|inline
name|APInt
name|operator
modifier|^
parameter_list|(
name|APInt
name|a
parameter_list|,
name|uint64_t
name|RHS
parameter_list|)
block|{
name|a
operator|^=
name|RHS
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|inline
name|APInt
name|operator
modifier|^
parameter_list|(
name|uint64_t
name|LHS
parameter_list|,
name|APInt
name|b
parameter_list|)
block|{
name|b
operator|^=
name|LHS
expr_stmt|;
return|return
name|b
return|;
block|}
end_function

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

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|-
operator|(
name|APInt
name|v
operator|)
block|{
name|v
operator|.
name|flipAllBits
argument_list|()
block|;
operator|++
name|v
block|;
return|return
name|v
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|+
operator|(
name|APInt
name|a
operator|,
specifier|const
name|APInt
operator|&
name|b
operator|)
block|{
name|a
operator|+=
name|b
block|;
return|return
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|+
operator|(
specifier|const
name|APInt
operator|&
name|a
operator|,
name|APInt
operator|&&
name|b
operator|)
block|{
name|b
operator|+=
name|a
block|;
return|return
name|std
operator|::
name|move
argument_list|(
name|b
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|+
operator|(
name|APInt
name|a
operator|,
name|uint64_t
name|RHS
operator|)
block|{
name|a
operator|+=
name|RHS
block|;
return|return
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|+
operator|(
name|uint64_t
name|LHS
operator|,
name|APInt
name|b
operator|)
block|{
name|b
operator|+=
name|LHS
block|;
return|return
name|b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|-
operator|(
name|APInt
name|a
operator|,
specifier|const
name|APInt
operator|&
name|b
operator|)
block|{
name|a
operator|-=
name|b
block|;
return|return
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|-
operator|(
specifier|const
name|APInt
operator|&
name|a
operator|,
name|APInt
operator|&&
name|b
operator|)
block|{
name|b
operator|=
operator|-
name|std
operator|::
name|move
argument_list|(
name|b
argument_list|)
block|;
name|b
operator|+=
name|a
block|;
return|return
name|std
operator|::
name|move
argument_list|(
name|b
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|-
operator|(
name|APInt
name|a
operator|,
name|uint64_t
name|RHS
operator|)
block|{
name|a
operator|-=
name|RHS
block|;
return|return
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|APInt
name|operator
operator|-
operator|(
name|uint64_t
name|LHS
operator|,
name|APInt
name|b
operator|)
block|{
name|b
operator|=
operator|-
name|std
operator|::
name|move
argument_list|(
name|b
argument_list|)
block|;
name|b
operator|+=
name|LHS
block|;
return|return
name|b
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|namespace
name|APIntOps
block|{
comment|/// \brief Determine the smaller of two APInts considered to be signed.
specifier|inline
specifier|const
name|APInt
modifier|&
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
comment|/// \brief Determine the larger of two APInts considered to be signed.
specifier|inline
specifier|const
name|APInt
modifier|&
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
comment|/// \brief Determine the smaller of two APInts considered to be signed.
specifier|inline
specifier|const
name|APInt
modifier|&
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
comment|/// \brief Determine the larger of two APInts considered to be unsigned.
specifier|inline
specifier|const
name|APInt
modifier|&
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
comment|/// \brief Compute GCD of two unsigned APInt values.
comment|///
comment|/// This function returns the greatest common divisor of the two APInt values
comment|/// using Stein's algorithm.
comment|///
comment|/// \returns the greatest common divisor of A and B.
name|APInt
name|GreatestCommonDivisor
parameter_list|(
name|APInt
name|A
parameter_list|,
name|APInt
name|B
parameter_list|)
function_decl|;
comment|/// \brief Converts the given APInt to a double value.
comment|///
comment|/// Treats the APInt as an unsigned value for conversion purposes.
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
comment|/// \brief Converts the given APInt to a double value.
comment|///
comment|/// Treats the APInt as a signed value for conversion purposes.
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
comment|/// \brief Converts the given APInt to a float vlalue.
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
comment|/// \brief Converts the given APInt to a float value.
comment|///
comment|/// Treast the APInt as a signed value for conversion purposes.
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
comment|/// \brief Converts the given double value into a APInt.
comment|///
comment|/// This function convert a double value to an APInt value.
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
comment|/// \brief Converts a float value into a APInt.
comment|///
comment|/// Converts a float value into an APInt value.
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
block|}
end_decl_stmt

begin_comment
comment|// End of APIntOps namespace
end_comment

begin_comment
comment|// See friend declaration above. This additional declaration is required in
end_comment

begin_comment
comment|// order to compile LLVM with IBM xlC compiler.
end_comment

begin_function_decl
name|hash_code
name|hash_value
parameter_list|(
specifier|const
name|APInt
modifier|&
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// End of llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

