begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/ConstantRange.h - Represent a range --------*- C++ -*-===//
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
comment|// Represent a range of possible values that may occur when the program is run
end_comment

begin_comment
comment|// for an integral value.  This keeps track of a lower and upper bound for the
end_comment

begin_comment
comment|// constant, which MAY wrap around the end of the numeric range.  To do this, it
end_comment

begin_comment
comment|// keeps track of a [lower, upper) bound, which specifies an interval just like
end_comment

begin_comment
comment|// STL iterators.  When used with boolean values, the following are important
end_comment

begin_comment
comment|// ranges: :
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  [F, F) = {}     = Empty set
end_comment

begin_comment
comment|//  [T, F) = {T}
end_comment

begin_comment
comment|//  [F, T) = {F}
end_comment

begin_comment
comment|//  [T, T) = {F, T} = Full set
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The other integral ranges use min/max values for special range values. For
end_comment

begin_comment
comment|// example, for 8-bit types, it uses:
end_comment

begin_comment
comment|// [0, 0)     = {}       = Empty set
end_comment

begin_comment
comment|// [255, 255) = {0..255} = Full Set
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that ConstantRange can be used to represent either signed or
end_comment

begin_comment
comment|// unsigned ranges.
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
name|LLVM_SUPPORT_CONSTANT_RANGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CONSTANT_RANGE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ConstantRange - This class represents an range of values.
comment|///
name|class
name|ConstantRange
block|{
name|APInt
name|Lower
decl_stmt|,
name|Upper
decl_stmt|;
specifier|static
name|ConstantRange
name|intersect1Wrapped
parameter_list|(
specifier|const
name|ConstantRange
modifier|&
name|LHS
parameter_list|,
specifier|const
name|ConstantRange
modifier|&
name|RHS
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Initialize a full (the default) or empty set for the specified bit width.
comment|///
name|explicit
name|ConstantRange
parameter_list|(
name|uint32_t
name|BitWidth
parameter_list|,
name|bool
name|isFullSet
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Initialize a range to hold the single specified value.
comment|///
name|ConstantRange
argument_list|(
specifier|const
name|APInt
operator|&
name|Value
argument_list|)
expr_stmt|;
comment|/// @brief Initialize a range of values explicitly. This will assert out if
comment|/// Lower==Upper and Lower != Min or Max value for its type. It will also
comment|/// assert out if the two APInt's are not the same bit width.
name|ConstantRange
argument_list|(
specifier|const
name|APInt
operator|&
name|Lower
argument_list|,
specifier|const
name|APInt
operator|&
name|Upper
argument_list|)
expr_stmt|;
comment|/// makeICmpRegion - Produce the smallest range that contains all values that
comment|/// might satisfy the comparison specified by Pred when compared to any value
comment|/// contained within Other.
comment|///
comment|/// Solves for range X in 'for all x in X, there exists a y in Y such that
comment|/// icmp op x, y is true'. Every value that might make the comparison true
comment|/// is included in the resulting range.
specifier|static
name|ConstantRange
name|makeICmpRegion
parameter_list|(
name|unsigned
name|Pred
parameter_list|,
specifier|const
name|ConstantRange
modifier|&
name|Other
parameter_list|)
function_decl|;
comment|/// getLower - Return the lower value for this range...
comment|///
specifier|const
name|APInt
operator|&
name|getLower
argument_list|()
specifier|const
block|{
return|return
name|Lower
return|;
block|}
comment|/// getUpper - Return the upper value for this range...
comment|///
specifier|const
name|APInt
operator|&
name|getUpper
argument_list|()
specifier|const
block|{
return|return
name|Upper
return|;
block|}
comment|/// getBitWidth - get the bit width of this ConstantRange
comment|///
name|uint32_t
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|Lower
operator|.
name|getBitWidth
argument_list|()
return|;
block|}
comment|/// isFullSet - Return true if this set contains all of the elements possible
comment|/// for this data-type
comment|///
name|bool
name|isFullSet
argument_list|()
specifier|const
expr_stmt|;
comment|/// isEmptySet - Return true if this set contains no members.
comment|///
name|bool
name|isEmptySet
argument_list|()
specifier|const
expr_stmt|;
comment|/// isWrappedSet - Return true if this set wraps around the top of the range,
comment|/// for example: [100, 8)
comment|///
name|bool
name|isWrappedSet
argument_list|()
specifier|const
expr_stmt|;
comment|/// contains - Return true if the specified value is in the set.
comment|///
name|bool
name|contains
argument_list|(
specifier|const
name|APInt
operator|&
name|Val
argument_list|)
decl|const
decl_stmt|;
comment|/// contains - Return true if the other range is a subset of this one.
comment|///
name|bool
name|contains
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|CR
argument_list|)
decl|const
decl_stmt|;
comment|/// getSingleElement - If this set contains a single element, return it,
comment|/// otherwise return null.
comment|///
specifier|const
name|APInt
operator|*
name|getSingleElement
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Upper
operator|==
name|Lower
operator|+
literal|1
condition|)
return|return
operator|&
name|Lower
return|;
return|return
literal|0
return|;
block|}
comment|/// isSingleElement - Return true if this set contains exactly one member.
comment|///
name|bool
name|isSingleElement
argument_list|()
specifier|const
block|{
return|return
name|getSingleElement
argument_list|()
operator|!=
literal|0
return|;
block|}
comment|/// getSetSize - Return the number of elements in this set.
comment|///
name|APInt
name|getSetSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// getUnsignedMax - Return the largest unsigned value contained in the
comment|/// ConstantRange.
comment|///
name|APInt
name|getUnsignedMax
argument_list|()
specifier|const
expr_stmt|;
comment|/// getUnsignedMin - Return the smallest unsigned value contained in the
comment|/// ConstantRange.
comment|///
name|APInt
name|getUnsignedMin
argument_list|()
specifier|const
expr_stmt|;
comment|/// getSignedMax - Return the largest signed value contained in the
comment|/// ConstantRange.
comment|///
name|APInt
name|getSignedMax
argument_list|()
specifier|const
expr_stmt|;
comment|/// getSignedMin - Return the smallest signed value contained in the
comment|/// ConstantRange.
comment|///
name|APInt
name|getSignedMin
argument_list|()
specifier|const
expr_stmt|;
comment|/// operator== - Return true if this range is equal to another range.
comment|///
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ConstantRange
operator|&
name|CR
operator|)
specifier|const
block|{
return|return
name|Lower
operator|==
name|CR
operator|.
name|Lower
operator|&&
name|Upper
operator|==
name|CR
operator|.
name|Upper
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ConstantRange
operator|&
name|CR
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|CR
operator|)
return|;
block|}
comment|/// subtract - Subtract the specified constant from the endpoints of this
comment|/// constant range.
name|ConstantRange
name|subtract
argument_list|(
specifier|const
name|APInt
operator|&
name|CI
argument_list|)
decl|const
decl_stmt|;
comment|/// intersectWith - Return the range that results from the intersection of
comment|/// this range with another range.  The resultant range is guaranteed to
comment|/// include all elements contained in both input ranges, and to have the
comment|/// smallest possible set size that does so.  Because there may be two
comment|/// intersections with the same set size, A.intersectWith(B) might not
comment|/// be equal to B.intersectWith(A).
comment|///
name|ConstantRange
name|intersectWith
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|CR
argument_list|)
decl|const
decl_stmt|;
comment|/// unionWith - Return the range that results from the union of this range
comment|/// with another range.  The resultant range is guaranteed to include the
comment|/// elements of both sets, but may contain more.  For example, [3, 9) union
comment|/// [12,15) is [3, 15), which includes 9, 10, and 11, which were not included
comment|/// in either set before.
comment|///
name|ConstantRange
name|unionWith
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|CR
argument_list|)
decl|const
decl_stmt|;
comment|/// zeroExtend - Return a new range in the specified integer type, which must
comment|/// be strictly larger than the current type.  The returned range will
comment|/// correspond to the possible range of values if the source range had been
comment|/// zero extended to BitWidth.
name|ConstantRange
name|zeroExtend
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// signExtend - Return a new range in the specified integer type, which must
comment|/// be strictly larger than the current type.  The returned range will
comment|/// correspond to the possible range of values if the source range had been
comment|/// sign extended to BitWidth.
name|ConstantRange
name|signExtend
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// truncate - Return a new range in the specified integer type, which must be
comment|/// strictly smaller than the current type.  The returned range will
comment|/// correspond to the possible range of values if the source range had been
comment|/// truncated to the specified type.
name|ConstantRange
name|truncate
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// zextOrTrunc - make this range have the bit width given by \p BitWidth. The
comment|/// value is zero extended, truncated, or left alone to make it that width.
name|ConstantRange
name|zextOrTrunc
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// sextOrTrunc - make this range have the bit width given by \p BitWidth. The
comment|/// value is sign extended, truncated, or left alone to make it that width.
name|ConstantRange
name|sextOrTrunc
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// add - Return a new range representing the possible values resulting
comment|/// from an addition of a value in this range and a value in Other.
name|ConstantRange
name|add
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// multiply - Return a new range representing the possible values resulting
comment|/// from a multiplication of a value in this range and a value in Other.
comment|/// TODO: This isn't fully implemented yet.
name|ConstantRange
name|multiply
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// smax - Return a new range representing the possible values resulting
comment|/// from a signed maximum of a value in this range and a value in Other.
name|ConstantRange
name|smax
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// umax - Return a new range representing the possible values resulting
comment|/// from an unsigned maximum of a value in this range and a value in Other.
name|ConstantRange
name|umax
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// udiv - Return a new range representing the possible values resulting
comment|/// from an unsigned division of a value in this range and a value in Other.
comment|/// TODO: This isn't fully implemented yet.
name|ConstantRange
name|udiv
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// shl - Return a new range representing the possible values resulting
comment|/// from a left shift of a value in this range by the Amount value.
name|ConstantRange
name|shl
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Amount
argument_list|)
decl|const
decl_stmt|;
comment|/// ashr - Return a new range representing the possible values resulting from
comment|/// an arithmetic right shift of a value in this range by the Amount value.
name|ConstantRange
name|ashr
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Amount
argument_list|)
decl|const
decl_stmt|;
comment|/// shr - Return a new range representing the possible values resulting
comment|/// from a logical right shift of a value in this range by the Amount value.
name|ConstantRange
name|lshr
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Amount
argument_list|)
decl|const
decl_stmt|;
comment|/// print - Print out the bounds to a stream...
comment|///
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Allow printing from a debugger easily...
comment|///
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|ConstantRange
operator|&
name|CR
operator|)
block|{
name|CR
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

