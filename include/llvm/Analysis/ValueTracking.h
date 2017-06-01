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
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
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
name|class
name|AddOperator
decl_stmt|;
name|class
name|AssumptionCache
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|GEPOperator
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
struct_decl|struct
name|KnownBits
struct_decl|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|OptimizationRemarkEmitter
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|namespace
name|Intrinsic
block|{
enum_decl|enum
name|ID
enum_decl|:
name|unsigned
enum_decl|;
block|}
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
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|KnownBits
modifier|&
name|Known
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
parameter_list|,
name|OptimizationRemarkEmitter
modifier|*
name|ORE
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Returns the known bits rather than passing by reference.
name|KnownBits
name|computeKnownBits
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
parameter_list|,
name|OptimizationRemarkEmitter
modifier|*
name|ORE
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Compute known bits from the range metadata.
comment|/// \p KnownZero the set of bits that are known to be zero
comment|/// \p KnownOne the set of bits that are known to be one
name|void
name|computeKnownBitsFromRangeMetadata
parameter_list|(
specifier|const
name|MDNode
modifier|&
name|Ranges
parameter_list|,
name|KnownBits
modifier|&
name|Known
parameter_list|)
function_decl|;
comment|/// Return true if LHS and RHS have no common bits set.
name|bool
name|haveNoCommonBitsSet
parameter_list|(
specifier|const
name|Value
modifier|*
name|LHS
parameter_list|,
specifier|const
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
comment|/// Return true if the given value is known to have exactly one bit set when
comment|/// defined. For vectors return true if every element is known to be a power
comment|/// of two when defined. Supports values with integer or pointer type and
comment|/// vectors of integers. If 'OrZero' is set, then return true if the given
comment|/// value is either a power of two or zero.
name|bool
name|isKnownToBeAPowerOfTwo
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
name|bool
name|isOnlyUsedInZeroEqualityComparison
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|CxtI
parameter_list|)
function_decl|;
comment|/// Return true if the given value is known to be non-zero when defined. For
comment|/// vectors, return true if every element is known to be non-zero when
comment|/// defined. For pointers, if the context instruction and dominator tree are
comment|/// specified, perform context-sensitive analysis and return true if the
comment|/// pointer couldn't possibly be null at the specified instruction.
comment|/// Supports values with integer or pointer type and vectors of integers.
name|bool
name|isKnownNonZero
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
comment|/// Returns true if the give value is known to be non-negative.
name|bool
name|isKnownNonNegative
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
comment|/// Returns true if the given value is known be positive (i.e. non-negative
comment|/// and non-zero).
name|bool
name|isKnownPositive
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
comment|/// Returns true if the given value is known be negative (i.e. non-positive
comment|/// and non-zero).
name|bool
name|isKnownNegative
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
comment|/// Return true if the given values are known to be non-equal when defined.
comment|/// Supports scalar integer types only.
name|bool
name|isKnownNonEqual
parameter_list|(
specifier|const
name|Value
modifier|*
name|V1
parameter_list|,
specifier|const
name|Value
modifier|*
name|V2
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
comment|/// Return true if 'V& Mask' is known to be zero. We use this predicate to
comment|/// simplify operations downstream. Mask is known to be zero for bits that V
comment|/// cannot have.
comment|///
comment|/// This function is defined on values with integer type, values with pointer
comment|/// type, and vectors of integers.  In the case
comment|/// where V is a vector, the mask, known zero, and known one values are the
comment|/// same width as the vector element, and the bit is set only if it is true
comment|/// for all of the elements in the vector.
name|bool
name|MaskedValueIsZero
parameter_list|(
specifier|const
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
comment|/// Return the number of times the sign bit of the register is replicated into
comment|/// the other bits. We know that at least 1 bit is always equal to the sign
comment|/// bit (itself), but other cases can give us information. For example,
comment|/// immediately after an "ashr X, 2", we know that the top 3 bits are all
comment|/// equal to each other, so we return 3. For vectors, return the number of
comment|/// sign bits for the vector element with the mininum number of known sign
comment|/// bits.
name|unsigned
name|ComputeNumSignBits
parameter_list|(
specifier|const
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
comment|/// This function computes the integer multiple of Base that equals V. If
comment|/// successful, it returns true and returns the multiple in Multiple. If
comment|/// unsuccessful, it returns false. Also, if V can be simplified to an
comment|/// integer, then the simplified V is returned in Val. Look through sext only
comment|/// if LookThroughSExt=true.
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
comment|/// Map a call instruction to an intrinsic ID.  Libcalls which have equivalent
comment|/// intrinsics are treated as-if they were intrinsics.
name|Intrinsic
operator|::
name|ID
name|getIntrinsicForCallSite
argument_list|(
argument|ImmutableCallSite ICS
argument_list|,
argument|const TargetLibraryInfo *TLI
argument_list|)
expr_stmt|;
comment|/// Return true if we can prove that the specified FP value is never equal to
comment|/// -0.0.
name|bool
name|CannotBeNegativeZero
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
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Return true if we can prove that the specified FP value is either NaN or
comment|/// never less than -0.0.
comment|///
comment|///      NaN --> true
comment|///       +0 --> true
comment|///       -0 --> true
comment|///   x> +0 --> true
comment|///   x< -0 --> false
comment|///
name|bool
name|CannotBeOrderedLessThanZero
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
parameter_list|)
function_decl|;
comment|/// Return true if we can prove that the specified FP value's sign bit is 0.
comment|///
comment|///      NaN --> true/false (depending on the NaN's sign bit)
comment|///       +0 --> true
comment|///       -0 --> false
comment|///   x> +0 --> true
comment|///   x< -0 --> false
comment|///
name|bool
name|SignBitMustBeZero
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
parameter_list|)
function_decl|;
comment|/// If the specified value can be set by repeating the same byte in memory,
comment|/// return the i8 value that it is represented with. This is true for all i8
comment|/// values obviously, but is also true for i32 0, i32 -1, i16 0xF0F0, double
comment|/// 0.0 etc. If the value can't be handled with a repeated byte store (e.g.
comment|/// i16 0x1234), return null.
name|Value
modifier|*
name|isBytewiseValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Given an aggregrate and an sequence of indices, see if the scalar value
comment|/// indexed is already around as a register, for example if it were inserted
comment|/// directly into the aggregrate.
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
comment|/// Analyze the specified pointer to see if it can be expressed as a base
comment|/// pointer plus a constant offset. Return the base and offset to the caller.
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
comment|/// Returns true if the GEP is based on a pointer to a string (array of
comment|// \p CharSize integers) and is indexing into this string.
name|bool
name|isGEPBasedOnPointerToString
parameter_list|(
specifier|const
name|GEPOperator
modifier|*
name|GEP
parameter_list|,
name|unsigned
name|CharSize
init|=
literal|8
parameter_list|)
function_decl|;
comment|/// Represents offset+length into a ConstantDataArray.
struct|struct
name|ConstantDataArraySlice
block|{
comment|/// ConstantDataArray pointer. nullptr indicates a zeroinitializer (a valid
comment|/// initializer, it just doesn't fit the ConstantDataArray interface).
specifier|const
name|ConstantDataArray
modifier|*
name|Array
decl_stmt|;
comment|/// Slice starts at this Offset.
name|uint64_t
name|Offset
decl_stmt|;
comment|/// Length of the slice.
name|uint64_t
name|Length
decl_stmt|;
comment|/// Moves the Offset and adjusts Length accordingly.
name|void
name|move
parameter_list|(
name|uint64_t
name|Delta
parameter_list|)
block|{
name|assert
argument_list|(
name|Delta
operator|<
name|Length
argument_list|)
expr_stmt|;
name|Offset
operator|+=
name|Delta
expr_stmt|;
name|Length
operator|-=
name|Delta
expr_stmt|;
block|}
comment|/// Convenience accessor for elements in the slice.
name|uint64_t
name|operator
index|[]
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
return|return
name|Array
operator|==
name|nullptr
condition|?
literal|0
else|:
name|Array
operator|->
name|getElementAsInteger
argument_list|(
name|I
operator|+
name|Offset
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// Returns true if the value \p V is a pointer into a ContantDataArray.
comment|/// If successfull \p Index will point to a ConstantDataArray info object
comment|/// with an apropriate offset.
name|bool
name|getConstantDataArrayInfo
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|ConstantDataArraySlice
modifier|&
name|Slice
parameter_list|,
name|unsigned
name|ElementSize
parameter_list|,
name|uint64_t
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// This function computes the length of a null-terminated C string pointed to
comment|/// by V. If successful, it returns true and returns the string in Str. If
comment|/// unsuccessful, it returns false. This does not include the trailing null
comment|/// character by default. If TrimAtNul is set to false, then this returns any
comment|/// trailing null characters as well as any other characters that come after
comment|/// it.
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
comment|/// If we can compute the length of the string pointed to by the specified
comment|/// pointer, return 'len+1'.  If we can't, return 0.
name|uint64_t
name|GetStringLength
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|CharSize
init|=
literal|8
parameter_list|)
function_decl|;
comment|/// This method strips off any GEP address adjustments and pointer casts from
comment|/// the specified value, returning the original object being addressed. Note
comment|/// that the returned value has pointer type if the specified value does. If
comment|/// the MaxLookup value is non-zero, it limits the number of instructions to
comment|/// be stripped off.
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
comment|/// Return true if the only users of this pointer are lifetime markers.
name|bool
name|onlyUsedByLifetimeMarkers
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Return true if the instruction does not have any effects besides
comment|/// calculating the result and does not have undefined behavior.
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
parameter_list|)
function_decl|;
comment|/// Returns true if the result or effects of the given instructions \p I
comment|/// depend on or influence global memory.
comment|/// Memory dependence arises for example if the instruction reads from
comment|/// memory or may produce effects or undefined behaviour. Memory dependent
comment|/// instructions generally cannot be reorderd with respect to other memory
comment|/// dependent instructions or moved into non-dominated basic blocks.
comment|/// Instructions which just compute a value based on the values of their
comment|/// operands are not memory dependent.
name|bool
name|mayBeMemoryDependent
parameter_list|(
specifier|const
name|Instruction
modifier|&
name|I
parameter_list|)
function_decl|;
comment|/// Return true if this pointer couldn't possibly be null by its definition.
comment|/// This returns true for allocas, non-extern-weak globals, and byval
comment|/// arguments.
name|bool
name|isKnownNonNull
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Return true if this pointer couldn't possibly be null. If the context
comment|/// instruction and dominator tree are specified, perform context-sensitive
comment|/// analysis and return true if the pointer couldn't possibly be null at the
comment|/// specified instruction.
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
specifier|const
name|Value
modifier|*
name|LHS
parameter_list|,
specifier|const
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
specifier|const
name|Value
modifier|*
name|LHS
parameter_list|,
specifier|const
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
name|computeOverflowForSignedAdd
parameter_list|(
specifier|const
name|Value
modifier|*
name|LHS
parameter_list|,
specifier|const
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
comment|/// This version also leverages the sign bit of Add if known.
name|OverflowResult
name|computeOverflowForSignedAdd
parameter_list|(
specifier|const
name|AddOperator
modifier|*
name|Add
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
comment|/// Returns true if the arithmetic part of the \p II 's result is
comment|/// used only along the paths control dependent on the computation
comment|/// not overflowing, \p II being an<op>.with.overflow intrinsic.
name|bool
name|isOverflowIntrinsicNoWrap
parameter_list|(
specifier|const
name|IntrinsicInst
modifier|*
name|II
parameter_list|,
specifier|const
name|DominatorTree
modifier|&
name|DT
parameter_list|)
function_decl|;
comment|/// Return true if this function can prove that the instruction I will
comment|/// always transfer execution to one of its successors (including the next
comment|/// instruction that follows within a basic block). E.g. this is not
comment|/// guaranteed for function calls that could loop infinitely.
comment|///
comment|/// In other words, this function returns false for instructions that may
comment|/// transfer execution or fail to transfer execution in a way that is not
comment|/// captured in the CFG nor in the sequence of instructions within a basic
comment|/// block.
comment|///
comment|/// Undefined behavior is assumed not to happen, so e.g. division is
comment|/// guaranteed to transfer execution to the following instruction even
comment|/// though division by zero might cause undefined behavior.
name|bool
name|isGuaranteedToTransferExecutionToSuccessor
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// Return true if this function can prove that the instruction I
comment|/// is executed for every iteration of the loop L.
comment|///
comment|/// Note that this currently only considers the loop header.
name|bool
name|isGuaranteedToExecuteForEveryIteration
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// Return true if this function can prove that I is guaranteed to yield
comment|/// full-poison (all bits poison) if at least one of its operands are
comment|/// full-poison (all bits poison).
comment|///
comment|/// The exact rules for how poison propagates through instructions have
comment|/// not been settled as of 2015-07-10, so this function is conservative
comment|/// and only considers poison to be propagated in uncontroversial
comment|/// cases. There is no attempt to track values that may be only partially
comment|/// poison.
name|bool
name|propagatesFullPoison
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// Return either nullptr or an operand of I such that I will trigger
comment|/// undefined behavior if I is executed and that operand has a full-poison
comment|/// value (all bits poison).
specifier|const
name|Value
modifier|*
name|getGuaranteedNonFullPoisonOp
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// Return true if this function can prove that if PoisonI is executed
comment|/// and yields a full-poison value (all bits poison), then that will
comment|/// trigger undefined behavior.
comment|///
comment|/// Note that this currently only considers the basic block that is
comment|/// the parent of I.
name|bool
name|programUndefinedIfFullPoison
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|PoisonI
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
comment|/// Signed minimum
name|SPF_UMIN
block|,
comment|/// Unsigned minimum
name|SPF_SMAX
block|,
comment|/// Signed maximum
name|SPF_UMAX
block|,
comment|/// Unsigned maximum
name|SPF_FMINNUM
block|,
comment|/// Floating point minnum
name|SPF_FMAXNUM
block|,
comment|/// Floating point maxnum
name|SPF_ABS
block|,
comment|/// Absolute value
name|SPF_NABS
comment|/// Negated absolute value
block|}
enum|;
comment|/// \brief Behavior when a floating point min/max is given one NaN and one
comment|/// non-NaN as input.
enum|enum
name|SelectPatternNaNBehavior
block|{
name|SPNB_NA
init|=
literal|0
block|,
comment|/// NaN behavior not applicable.
name|SPNB_RETURNS_NAN
block|,
comment|/// Given one NaN input, returns the NaN.
name|SPNB_RETURNS_OTHER
block|,
comment|/// Given one NaN input, returns the non-NaN.
name|SPNB_RETURNS_ANY
comment|/// Given one NaN input, can return either (or
comment|/// it has been determined that no operands can
comment|/// be NaN).
block|}
enum|;
struct|struct
name|SelectPatternResult
block|{
name|SelectPatternFlavor
name|Flavor
decl_stmt|;
name|SelectPatternNaNBehavior
name|NaNBehavior
decl_stmt|;
comment|/// Only applicable if Flavor is
comment|/// SPF_FMINNUM or SPF_FMAXNUM.
name|bool
name|Ordered
decl_stmt|;
comment|/// When implementing this min/max pattern as
comment|/// fcmp; select, does the fcmp have to be
comment|/// ordered?
comment|/// \brief Return true if \p SPF is a min or a max pattern.
specifier|static
name|bool
name|isMinOrMax
parameter_list|(
name|SelectPatternFlavor
name|SPF
parameter_list|)
block|{
return|return
operator|!
operator|(
name|SPF
operator|==
name|SPF_UNKNOWN
operator|||
name|SPF
operator|==
name|SPF_ABS
operator|||
name|SPF
operator|==
name|SPF_NABS
operator|)
return|;
block|}
block|}
struct|;
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
name|SelectPatternResult
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
specifier|static
specifier|inline
name|SelectPatternResult
name|matchSelectPattern
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|Value
operator|*
operator|&
name|LHS
argument_list|,
specifier|const
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
block|{
name|Value
modifier|*
name|L
init|=
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|LHS
operator|)
decl_stmt|;
name|Value
modifier|*
name|R
init|=
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|RHS
operator|)
decl_stmt|;
name|auto
name|Result
init|=
name|matchSelectPattern
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
name|L
argument_list|,
name|R
argument_list|)
decl_stmt|;
name|LHS
operator|=
name|L
expr_stmt|;
name|RHS
operator|=
name|R
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// Return true if RHS is known to be implied true by LHS.  Return false if
comment|/// RHS is known to be implied false by LHS.  Otherwise, return None if no
comment|/// implication can be made.
comment|/// A& B must be i1 (boolean) values or a vector of such values. Note that
comment|/// the truth table for implication is the same as<=u on i1 values (but not
comment|///<=s!).  The truth table for both is:
comment|///    | T | F (B)
comment|///  T | T | F
comment|///  F | T | T
comment|/// (A)
name|Optional
operator|<
name|bool
operator|>
name|isImpliedCondition
argument_list|(
argument|const Value *LHS
argument_list|,
argument|const Value *RHS
argument_list|,
argument|const DataLayout&DL
argument_list|,
argument|bool InvertAPred = false
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|,
argument|AssumptionCache *AC = nullptr
argument_list|,
argument|const Instruction *CxtI = nullptr
argument_list|,
argument|const DominatorTree *DT = nullptr
argument_list|)
expr_stmt|;
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

