begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/ValueTracking.h - Walk computations --------*- C++ -*-===//
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
comment|// This file contains routines that help analyze properties that chains of
end_comment

begin_comment
comment|// computations have.
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
name|LLVM_ANALYSIS_VALUETRACKING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_VALUETRACKING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
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
name|Value
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|APInt
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|AssumptionCache
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
comment|/// Determine which bits of V are known to be either zero or one and return
comment|/// them in the KnownZero/KnownOne bit sets.
comment|///
comment|/// This function is defined on values with integer type, values with pointer
comment|/// type, and vectors of integers.  In the case
comment|/// where V is a vector, the known zero and known one values are the
comment|/// same width as the vector element, and the bit is set only if it is true
comment|/// for all of the elements in the vector.
name|void
name|computeKnownBits
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|APInt
modifier|&
name|KnownZero
parameter_list|,
name|APInt
modifier|&
name|KnownOne
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Compute known bits from the range metadata.
comment|/// \p KnownZero the set of bits that are known to be zero
name|void
name|computeKnownBitsFromRangeMetadata
parameter_list|(
specifier|const
name|MDNode
modifier|&
name|Ranges
parameter_list|,
name|APInt
modifier|&
name|KnownZero
parameter_list|)
function_decl|;
comment|/// Returns true if LHS and RHS have no common bits set.
name|bool
name|haveNoCommonBitsSet
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// ComputeSignBit - Determine whether the sign bit is known to be zero or
comment|/// one.  Convenience wrapper around computeKnownBits.
name|void
name|ComputeSignBit
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|bool
modifier|&
name|KnownZero
parameter_list|,
name|bool
modifier|&
name|KnownOne
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// isKnownToBeAPowerOfTwo - Return true if the given value is known to have
comment|/// exactly one bit set when defined. For vectors return true if every
comment|/// element is known to be a power of two when defined.  Supports values with
comment|/// integer or pointer type and vectors of integers.  If 'OrZero' is set then
comment|/// returns true if the given value is either a power of two or zero.
name|bool
name|isKnownToBeAPowerOfTwo
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|bool
name|OrZero
init|=
name|false
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// isKnownNonZero - Return true if the given value is known to be non-zero
comment|/// when defined.  For vectors return true if every element is known to be
comment|/// non-zero when defined.  Supports values with integer or pointer type and
comment|/// vectors of integers.
name|bool
name|isKnownNonZero
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// MaskedValueIsZero - Return true if 'V& Mask' is known to be zero.  We use
comment|/// this predicate to simplify operations downstream.  Mask is known to be
comment|/// zero for bits that V cannot have.
comment|///
comment|/// This function is defined on values with integer type, values with pointer
comment|/// type, and vectors of integers.  In the case
comment|/// where V is a vector, the mask, known zero, and known one values are the
comment|/// same width as the vector element, and the bit is set only if it is true
comment|/// for all of the elements in the vector.
name|bool
name|MaskedValueIsZero
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Mask
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// ComputeNumSignBits - Return the number of times the sign bit of the
comment|/// register is replicated into the other bits.  We know that at least 1 bit
comment|/// is always equal to the sign bit (itself), but other cases can give us
comment|/// information.  For example, immediately after an "ashr X, 2", we know that
comment|/// the top 3 bits are all equal to each other, so we return 3.
comment|///
comment|/// 'Op' must have a scalar integer type.
comment|///
name|unsigned
name|ComputeNumSignBits
parameter_list|(
name|Value
modifier|*
name|Op
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// ComputeMultiple - This function computes the integer multiple of Base that
comment|/// equals V.  If successful, it returns true and returns the multiple in
comment|/// Multiple.  If unsuccessful, it returns false.  Also, if V can be
comment|/// simplified to an integer, then the simplified V is returned in Val.  Look
comment|/// through sext only if LookThroughSExt=true.
name|bool
name|ComputeMultiple
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|Base
parameter_list|,
name|Value
modifier|*
modifier|&
name|Multiple
parameter_list|,
name|bool
name|LookThroughSExt
init|=
name|false
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// CannotBeNegativeZero - Return true if we can prove that the specified FP
comment|/// value is never equal to -0.0.
comment|///
name|bool
name|CannotBeNegativeZero
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// CannotBeOrderedLessThanZero - Return true if we can prove that the
comment|/// specified FP value is either a NaN or never less than 0.0.
comment|///
name|bool
name|CannotBeOrderedLessThanZero
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// isBytewiseValue - If the specified value can be set by repeating the same
comment|/// byte in memory, return the i8 value that it is represented with.  This is
comment|/// true for all i8 values obviously, but is also true for i32 0, i32 -1,
comment|/// i16 0xF0F0, double 0.0 etc.  If the value can't be handled with a repeated
comment|/// byte store (e.g. i16 0x1234), return null.
name|Value
modifier|*
name|isBytewiseValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// FindInsertedValue - Given an aggregrate and an sequence of indices, see if
comment|/// the scalar value indexed is already around as a register, for example if
comment|/// it were inserted directly into the aggregrate.
comment|///
comment|/// If InsertBefore is not null, this function will duplicate (modified)
comment|/// insertvalues when a part of a nested struct is extracted.
name|Value
modifier|*
name|FindInsertedValue
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|idx_range
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// GetPointerBaseWithConstantOffset - Analyze the specified pointer to see if
comment|/// it can be expressed as a base pointer plus a constant offset.  Return the
comment|/// base and offset to the caller.
name|Value
modifier|*
name|GetPointerBaseWithConstantOffset
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|,
name|int64_t
modifier|&
name|Offset
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
specifier|static
specifier|inline
specifier|const
name|Value
modifier|*
name|GetPointerBaseWithConstantOffset
parameter_list|(
specifier|const
name|Value
modifier|*
name|Ptr
parameter_list|,
name|int64_t
modifier|&
name|Offset
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
block|{
return|return
name|GetPointerBaseWithConstantOffset
argument_list|(
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|Ptr
operator|)
argument_list|,
name|Offset
argument_list|,
name|DL
argument_list|)
return|;
block|}
comment|/// getConstantStringInfo - This function computes the length of a
comment|/// null-terminated C string pointed to by V.  If successful, it returns true
comment|/// and returns the string in Str.  If unsuccessful, it returns false.  This
comment|/// does not include the trailing nul character by default.  If TrimAtNul is
comment|/// set to false, then this returns any trailing nul characters as well as any
comment|/// other characters that come after it.
name|bool
name|getConstantStringInfo
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|StringRef
modifier|&
name|Str
parameter_list|,
name|uint64_t
name|Offset
init|=
literal|0
parameter_list|,
name|bool
name|TrimAtNul
init|=
name|true
parameter_list|)
function_decl|;
comment|/// GetStringLength - If we can compute the length of the string pointed to by
comment|/// the specified pointer, return 'len+1'.  If we can't, return 0.
name|uint64_t
name|GetStringLength
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// GetUnderlyingObject - This method strips off any GEP address adjustments
comment|/// and pointer casts from the specified value, returning the original object
comment|/// being addressed.  Note that the returned value has pointer type if the
comment|/// specified value does.  If the MaxLookup value is non-zero, it limits the
comment|/// number of instructions to be stripped off.
name|Value
modifier|*
name|GetUnderlyingObject
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|unsigned
name|MaxLookup
init|=
literal|6
parameter_list|)
function_decl|;
specifier|static
specifier|inline
specifier|const
name|Value
modifier|*
name|GetUnderlyingObject
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|unsigned
name|MaxLookup
init|=
literal|6
parameter_list|)
block|{
return|return
name|GetUnderlyingObject
argument_list|(
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|V
operator|)
argument_list|,
name|DL
argument_list|,
name|MaxLookup
argument_list|)
return|;
block|}
comment|/// \brief This method is similar to GetUnderlyingObject except that it can
comment|/// look through phi and select instructions and return multiple objects.
comment|///
comment|/// If LoopInfo is passed, loop phis are further analyzed.  If a pointer
comment|/// accesses different objects in each iteration, we don't look through the
comment|/// phi node. E.g. consider this loop nest:
comment|///
comment|///   int **A;
comment|///   for (i)
comment|///     for (j) {
comment|///        A[i][j] = A[i-1][j] * B[j]
comment|///     }
comment|///
comment|/// This is transformed by Load-PRE to stash away A[i] for the next iteration
comment|/// of the outer loop:
comment|///
comment|///   Curr = A[0];          // Prev_0
comment|///   for (i: 1..N) {
comment|///     Prev = Curr;        // Prev = PHI (Prev_0, Curr)
comment|///     Curr = A[i];
comment|///     for (j: 0..N) {
comment|///        Curr[j] = Prev[j] * B[j]
comment|///     }
comment|///   }
comment|///
comment|/// Since A[i] and A[i-1] are independent pointers, getUnderlyingObjects
comment|/// should not assume that Curr and Prev share the same underlying object thus
comment|/// it shouldn't look through the phi above.
name|void
name|GetUnderlyingObjects
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|SmallVectorImpl
operator|<
name|Value
operator|*
operator|>
operator|&
name|Objects
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|LoopInfo
operator|*
name|LI
operator|=
name|nullptr
argument_list|,
name|unsigned
name|MaxLookup
operator|=
literal|6
argument_list|)
decl_stmt|;
comment|/// onlyUsedByLifetimeMarkers - Return true if the only users of this pointer
comment|/// are lifetime markers.
name|bool
name|onlyUsedByLifetimeMarkers
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// isDereferenceablePointer - Return true if this is always a dereferenceable
comment|/// pointer. If the context instruction is specified perform context-sensitive
comment|/// analysis and return true if the pointer is dereferenceable at the
comment|/// specified instruction.
name|bool
name|isDereferenceablePointer
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CtxI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// isSafeToSpeculativelyExecute - Return true if the instruction does not
comment|/// have any effects besides calculating the result and does not have
comment|/// undefined behavior.
comment|///
comment|/// This method never returns true for an instruction that returns true for
comment|/// mayHaveSideEffects; however, this method also does some other checks in
comment|/// addition. It checks for undefined behavior, like dividing by zero or
comment|/// loading from an invalid pointer (but not for undefined results, like a
comment|/// shift with a shift amount larger than the width of the result). It checks
comment|/// for malloc and alloca because speculatively executing them might cause a
comment|/// memory leak. It also returns false for instructions related to control
comment|/// flow, specifically terminators and PHI nodes.
comment|///
comment|/// If the CtxI is specified this method performs context-sensitive analysis
comment|/// and returns true if it is safe to execute the instruction immediately
comment|/// before the CtxI.
comment|///
comment|/// If the CtxI is NOT specified this method only looks at the instruction
comment|/// itself and its operands, so if this method returns true, it is safe to
comment|/// move the instruction as long as the correct dominance relationships for
comment|/// the operands and users hold.
comment|///
comment|/// This method can return true for instructions that read memory;
comment|/// for such instructions, moving them may change the resulting value.
name|bool
name|isSafeToSpeculativelyExecute
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CtxI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// isKnownNonNull - Return true if this pointer couldn't possibly be null by
comment|/// its definition.  This returns true for allocas, non-extern-weak globals
comment|/// and byval arguments.
name|bool
name|isKnownNonNull
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// isKnownNonNullAt - Return true if this pointer couldn't possibly be null.
comment|/// If the context instruction is specified perform context-sensitive analysis
comment|/// and return true if the pointer couldn't possibly be null at the specified
comment|/// instruction.
name|bool
name|isKnownNonNullAt
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CtxI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Return true if it is valid to use the assumptions provided by an
comment|/// assume intrinsic, I, at the point in the control-flow identified by the
comment|/// context instruction, CxtI.
name|bool
name|isValidAssumeForContext
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
name|enum
name|class
name|OverflowResult
block|{
name|AlwaysOverflows
operator|,
name|MayOverflow
operator|,
name|NeverOverflows
block|}
empty_stmt|;
name|OverflowResult
name|computeOverflowForUnsignedMul
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
parameter_list|)
function_decl|;
name|OverflowResult
name|computeOverflowForUnsignedAdd
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
parameter_list|)
function_decl|;
comment|/// \brief Specific patterns of select instructions we can match.
enum|enum
name|SelectPatternFlavor
block|{
name|SPF_UNKNOWN
init|=
literal|0
block|,
name|SPF_SMIN
block|,
comment|// Signed minimum
name|SPF_UMIN
block|,
comment|// Unsigned minimum
name|SPF_SMAX
block|,
comment|// Signed maximum
name|SPF_UMAX
block|,
comment|// Unsigned maximum
name|SPF_ABS
block|,
comment|// Absolute value
name|SPF_NABS
comment|// Negated absolute value
block|}
enum|;
comment|/// Pattern match integer [SU]MIN, [SU]MAX and ABS idioms, returning the kind
comment|/// and providing the out parameter results if we successfully match.
comment|///
comment|/// If CastOp is not nullptr, also match MIN/MAX idioms where the type does
comment|/// not match that of the original select. If this is the case, the cast
comment|/// operation (one of Trunc,SExt,Zext) that must be done to transform the
comment|/// type of LHS and RHS into the type of V is returned in CastOp.
comment|///
comment|/// For example:
comment|///   %1 = icmp slt i32 %a, i32 4
comment|///   %2 = sext i32 %a to i64
comment|///   %3 = select i1 %1, i64 %2, i64 4
comment|///
comment|/// -> LHS = %a, RHS = i32 4, *CastOp = Instruction::SExt
comment|///
name|SelectPatternFlavor
name|matchSelectPattern
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|Value
operator|*
operator|&
name|LHS
argument_list|,
name|Value
operator|*
operator|&
name|RHS
argument_list|,
name|Instruction
operator|::
name|CastOps
operator|*
name|CastOp
operator|=
name|nullptr
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

