begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ConstantRange.h - Represent a range ----------------------*- C++ -*-===//
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
name|LLVM_IR_CONSTANTRANGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_CONSTANTRANGE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstrTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MDNode
decl_stmt|;
comment|/// This class represents a range of values.
name|class
name|ConstantRange
block|{
name|APInt
name|Lower
decl_stmt|,
name|Upper
decl_stmt|;
name|public
label|:
comment|/// Initialize a full (the default) or empty set for the specified bit width.
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
name|ConstantRange
argument_list|(
argument|APInt Value
argument_list|)
empty_stmt|;
comment|/// @brief Initialize a range of values explicitly. This will assert out if
comment|/// Lower==Upper and Lower != Min or Max value for its type. It will also
comment|/// assert out if the two APInt's are not the same bit width.
name|ConstantRange
argument_list|(
argument|APInt Lower
argument_list|,
argument|APInt Upper
argument_list|)
empty_stmt|;
comment|/// Produce the smallest range such that all values that may satisfy the given
comment|/// predicate with any value contained within Other is contained in the
comment|/// returned range.  Formally, this returns a superset of
comment|/// 'union over all y in Other . { x : icmp op x y is true }'.  If the exact
comment|/// answer is not representable as a ConstantRange, the return value will be a
comment|/// proper superset of the above.
comment|///
comment|/// Example: Pred = ult and Other = i8 [2, 5) returns Result = [0, 4)
specifier|static
name|ConstantRange
name|makeAllowedICmpRegion
argument_list|(
name|CmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl_stmt|;
comment|/// Produce the largest range such that all values in the returned range
comment|/// satisfy the given predicate with all values contained within Other.
comment|/// Formally, this returns a subset of
comment|/// 'intersection over all y in Other . { x : icmp op x y is true }'.  If the
comment|/// exact answer is not representable as a ConstantRange, the return value
comment|/// will be a proper subset of the above.
comment|///
comment|/// Example: Pred = ult and Other = i8 [2, 5) returns [0, 2)
specifier|static
name|ConstantRange
name|makeSatisfyingICmpRegion
argument_list|(
name|CmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl_stmt|;
comment|/// Produce the exact range such that all values in the returned range satisfy
comment|/// the given predicate with any value contained within Other. Formally, this
comment|/// returns the exact answer when the superset of 'union over all y in Other
comment|/// is exactly same as the subset of intersection over all y in Other.
comment|/// { x : icmp op x y is true}'.
comment|///
comment|/// Example: Pred = ult and Other = i8 3 returns [0, 3)
specifier|static
name|ConstantRange
name|makeExactICmpRegion
argument_list|(
name|CmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
specifier|const
name|APInt
operator|&
name|Other
argument_list|)
decl_stmt|;
comment|/// Return the largest range containing all X such that "X BinOpC Y" is
comment|/// guaranteed not to wrap (overflow) for all Y in Other.
comment|///
comment|/// NB! The returned set does *not* contain **all** possible values of X for
comment|/// which "X BinOpC Y" does not wrap -- some viable values of X may be
comment|/// missing, so you cannot use this to contrain X's range.  E.g. in the last
comment|/// example, "(-2) + 1" is both nsw and nuw (so the "X" could be -2), but (-2)
comment|/// is not in the set returned.
comment|///
comment|/// Examples:
comment|///  typedef OverflowingBinaryOperator OBO;
comment|///  #define MGNR makeGuaranteedNoWrapRegion
comment|///  MGNR(Add, [i8 1, 2), OBO::NoSignedWrap) == [-128, 127)
comment|///  MGNR(Add, [i8 1, 2), OBO::NoUnsignedWrap) == [0, -1)
comment|///  MGNR(Add, [i8 0, 1), OBO::NoUnsignedWrap) == Full Set
comment|///  MGNR(Add, [i8 1, 2), OBO::NoUnsignedWrap | OBO::NoSignedWrap)
comment|///    == [0,INT_MAX)
comment|///  MGNR(Add, [i8 -1, 6), OBO::NoSignedWrap) == [INT_MIN+1, INT_MAX-4)
specifier|static
name|ConstantRange
name|makeGuaranteedNoWrapRegion
argument_list|(
name|Instruction
operator|::
name|BinaryOps
name|BinOp
argument_list|,
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|,
name|unsigned
name|NoWrapKind
argument_list|)
decl_stmt|;
comment|/// Set up \p Pred and \p RHS such that
comment|/// ConstantRange::makeExactICmpRegion(Pred, RHS) == *this.  Return true if
comment|/// successful.
name|bool
name|getEquivalentICmp
argument_list|(
name|CmpInst
operator|::
name|Predicate
operator|&
name|Pred
argument_list|,
name|APInt
operator|&
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the lower value for this range.
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
comment|/// Return the upper value for this range.
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
comment|/// Get the bit width of this ConstantRange.
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
comment|/// Return true if this set contains all of the elements possible
comment|/// for this data-type.
name|bool
name|isFullSet
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this set contains no members.
name|bool
name|isEmptySet
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this set wraps around the top of the range.
comment|/// For example: [100, 8).
name|bool
name|isWrappedSet
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this set wraps around the INT_MIN of
comment|/// its bitwidth. For example: i8 [120, 140).
name|bool
name|isSignWrappedSet
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if the specified value is in the set.
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
comment|/// Return true if the other range is a subset of this one.
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
comment|/// If this set contains a single element, return it, otherwise return null.
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
name|nullptr
return|;
block|}
comment|/// If this set contains all but a single element, return it, otherwise return
comment|/// null.
specifier|const
name|APInt
operator|*
name|getSingleMissingElement
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Lower
operator|==
name|Upper
operator|+
literal|1
condition|)
return|return
operator|&
name|Upper
return|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return true if this set contains exactly one member.
end_comment

begin_expr_stmt
name|bool
name|isSingleElement
argument_list|()
specifier|const
block|{
return|return
name|getSingleElement
argument_list|()
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return the number of elements in this set.
end_comment

begin_expr_stmt
name|APInt
name|getSetSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Compare set size of this range with the range CR.
end_comment

begin_decl_stmt
name|bool
name|isSizeStrictlySmallerThanOf
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|CR
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the largest unsigned value contained in the ConstantRange.
end_comment

begin_expr_stmt
name|APInt
name|getUnsignedMax
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the smallest unsigned value contained in the ConstantRange.
end_comment

begin_expr_stmt
name|APInt
name|getUnsignedMin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the largest signed value contained in the ConstantRange.
end_comment

begin_expr_stmt
name|APInt
name|getSignedMax
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the smallest signed value contained in the ConstantRange.
end_comment

begin_expr_stmt
name|APInt
name|getSignedMin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return true if this range is equal to another range.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Subtract the specified constant from the endpoints of this constant range.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Subtract the specified range from this range (aka relative complement of
end_comment

begin_comment
comment|/// the sets).
end_comment

begin_decl_stmt
name|ConstantRange
name|difference
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|CR
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the range that results from the intersection of
end_comment

begin_comment
comment|/// this range with another range.  The resultant range is guaranteed to
end_comment

begin_comment
comment|/// include all elements contained in both input ranges, and to have the
end_comment

begin_comment
comment|/// smallest possible set size that does so.  Because there may be two
end_comment

begin_comment
comment|/// intersections with the same set size, A.intersectWith(B) might not
end_comment

begin_comment
comment|/// be equal to B.intersectWith(A).
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return the range that results from the union of this range
end_comment

begin_comment
comment|/// with another range.  The resultant range is guaranteed to include the
end_comment

begin_comment
comment|/// elements of both sets, but may contain more.  For example, [3, 9) union
end_comment

begin_comment
comment|/// [12,15) is [3, 15), which includes 9, 10, and 11, which were not included
end_comment

begin_comment
comment|/// in either set before.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from an application of the specified cast operator to this range. \p
end_comment

begin_comment
comment|/// BitWidth is the target bitwidth of the cast.  For casts which don't
end_comment

begin_comment
comment|/// change bitwidth, it must be the same as the source bitwidth.  For casts
end_comment

begin_comment
comment|/// which do change bitwidth, the bitwidth must be consistent with the
end_comment

begin_comment
comment|/// requested cast and source bitwidth.
end_comment

begin_decl_stmt
name|ConstantRange
name|castOp
argument_list|(
name|Instruction
operator|::
name|CastOps
name|CastOp
argument_list|,
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range in the specified integer type, which must
end_comment

begin_comment
comment|/// be strictly larger than the current type.  The returned range will
end_comment

begin_comment
comment|/// correspond to the possible range of values if the source range had been
end_comment

begin_comment
comment|/// zero extended to BitWidth.
end_comment

begin_decl_stmt
name|ConstantRange
name|zeroExtend
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range in the specified integer type, which must
end_comment

begin_comment
comment|/// be strictly larger than the current type.  The returned range will
end_comment

begin_comment
comment|/// correspond to the possible range of values if the source range had been
end_comment

begin_comment
comment|/// sign extended to BitWidth.
end_comment

begin_decl_stmt
name|ConstantRange
name|signExtend
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range in the specified integer type, which must be
end_comment

begin_comment
comment|/// strictly smaller than the current type.  The returned range will
end_comment

begin_comment
comment|/// correspond to the possible range of values if the source range had been
end_comment

begin_comment
comment|/// truncated to the specified type.
end_comment

begin_decl_stmt
name|ConstantRange
name|truncate
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Make this range have the bit width given by \p BitWidth. The
end_comment

begin_comment
comment|/// value is zero extended, truncated, or left alone to make it that width.
end_comment

begin_decl_stmt
name|ConstantRange
name|zextOrTrunc
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Make this range have the bit width given by \p BitWidth. The
end_comment

begin_comment
comment|/// value is sign extended, truncated, or left alone to make it that width.
end_comment

begin_decl_stmt
name|ConstantRange
name|sextOrTrunc
argument_list|(
name|uint32_t
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from an application of the specified binary operator to an left hand side
end_comment

begin_comment
comment|/// of this range and a right hand side of \p Other.
end_comment

begin_decl_stmt
name|ConstantRange
name|binaryOp
argument_list|(
name|Instruction
operator|::
name|BinaryOps
name|BinOp
argument_list|,
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from an addition of a value in this range and a value in \p Other.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting from a
end_comment

begin_comment
comment|/// known NSW addition of a value in this range and \p Other constant.
end_comment

begin_decl_stmt
name|ConstantRange
name|addWithNoSignedWrap
argument_list|(
specifier|const
name|APInt
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from a subtraction of a value in this range and a value in \p Other.
end_comment

begin_decl_stmt
name|ConstantRange
name|sub
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from a multiplication of a value in this range and a value in \p Other,
end_comment

begin_comment
comment|/// treating both this and \p Other as unsigned ranges.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from a signed maximum of a value in this range and a value in \p Other.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from an unsigned maximum of a value in this range and a value in \p Other.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from a signed minimum of a value in this range and a value in \p Other.
end_comment

begin_decl_stmt
name|ConstantRange
name|smin
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from an unsigned minimum of a value in this range and a value in \p Other.
end_comment

begin_decl_stmt
name|ConstantRange
name|umin
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from an unsigned division of a value in this range and a value in
end_comment

begin_comment
comment|/// \p Other.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from a binary-and of a value in this range by a value in \p Other.
end_comment

begin_decl_stmt
name|ConstantRange
name|binaryAnd
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from a binary-or of a value in this range by a value in \p Other.
end_comment

begin_decl_stmt
name|ConstantRange
name|binaryOr
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting
end_comment

begin_comment
comment|/// from a left shift of a value in this range by a value in \p Other.
end_comment

begin_comment
comment|/// TODO: This isn't fully implemented yet.
end_comment

begin_decl_stmt
name|ConstantRange
name|shl
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range representing the possible values resulting from a
end_comment

begin_comment
comment|/// logical right shift of a value in this range and a value in \p Other.
end_comment

begin_decl_stmt
name|ConstantRange
name|lshr
argument_list|(
specifier|const
name|ConstantRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a new range that is the logical not of the current set.
end_comment

begin_expr_stmt
name|ConstantRange
name|inverse
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Print out the bounds to a stream.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Allow printing from a debugger easily.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
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
comment|/// Parse out a conservative ConstantRange from !range metadata.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// E.g. if RangeMD is !{i32 0, i32 10, i32 15, i32 20} then return [0, 20).
end_comment

begin_function_decl
name|ConstantRange
name|getConstantRangeFromMetadata
parameter_list|(
specifier|const
name|MDNode
modifier|&
name|RangeMD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

