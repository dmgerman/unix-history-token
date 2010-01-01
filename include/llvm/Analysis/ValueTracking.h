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
file|"llvm/System/DataTypes.h"
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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
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
name|TargetData
decl_stmt|;
comment|/// ComputeMaskedBits - Determine which of the bits specified in Mask are
comment|/// known to be either zero or one and return them in the KnownZero/KnownOne
comment|/// bit sets.  This code only analyzes bits in Mask, in order to short-circuit
comment|/// processing.
comment|///
comment|/// This function is defined on values with integer type, values with pointer
comment|/// type (but only if TD is non-null), and vectors of integers.  In the case
comment|/// where V is a vector, the mask, known zero, and known one values are the
comment|/// same width as the vector element, and the bit is set only if it is true
comment|/// for all of the elements in the vector.
name|void
name|ComputeMaskedBits
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
name|APInt
modifier|&
name|KnownZero
parameter_list|,
name|APInt
modifier|&
name|KnownOne
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// MaskedValueIsZero - Return true if 'V& Mask' is known to be zero.  We use
comment|/// this predicate to simplify operations downstream.  Mask is known to be
comment|/// zero for bits that V cannot have.
comment|///
comment|/// This function is defined on values with integer type, values with pointer
comment|/// type (but only if TD is non-null), and vectors of integers.  In the case
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
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
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
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
name|unsigned
name|Depth
init|=
literal|0
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
comment|/// DecomposeGEPExpression - If V is a symbolic pointer expression, decompose
comment|/// it into a base pointer with a constant offset and a number of scaled
comment|/// symbolic offsets.
comment|///
comment|/// The scaled symbolic offsets (represented by pairs of a Value* and a scale
comment|/// in the VarIndices vector) are Value*'s that are known to be scaled by the
comment|/// specified amount, but which may have other unrepresented high bits. As
comment|/// such, the gep cannot necessarily be reconstructed from its decomposed
comment|/// form.
comment|///
comment|/// When TargetData is around, this function is capable of analyzing
comment|/// everything that Value::getUnderlyingObject() can look through.  When not,
comment|/// it just looks through pointer casts.
comment|///
specifier|const
name|Value
modifier|*
name|DecomposeGEPExpression
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
name|int64_t
operator|&
name|BaseOffs
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|int64_t
operator|>
expr|>
operator|&
name|VarIndices
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
argument_list|)
decl_stmt|;
comment|/// FindScalarValue - Given an aggregrate and an sequence of indices, see if
comment|/// the scalar value indexed is already around as a register, for example if
comment|/// it were inserted directly into the aggregrate.
comment|///
comment|/// If InsertBefore is not null, this function will duplicate (modified)
comment|/// insertvalues when a part of a nested struct is extracted.
name|Value
modifier|*
name|FindInsertedValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|idx_begin
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|idx_end
parameter_list|,
name|Instruction
modifier|*
name|InsertBefore
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// This is a convenience wrapper for finding values indexed by a single index
comment|/// only.
specifier|inline
name|Value
modifier|*
name|FindInsertedValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|unsigned
name|Idx
parameter_list|,
name|Instruction
modifier|*
name|InsertBefore
init|=
literal|0
parameter_list|)
block|{
specifier|const
name|unsigned
name|Idxs
index|[
literal|1
index|]
init|=
block|{
name|Idx
block|}
decl_stmt|;
return|return
name|FindInsertedValue
argument_list|(
name|V
argument_list|,
operator|&
name|Idxs
index|[
literal|0
index|]
argument_list|,
operator|&
name|Idxs
index|[
literal|1
index|]
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
comment|/// GetConstantStringInfo - This function computes the length of a
comment|/// null-terminated C string pointed to by V.  If successful, it returns true
comment|/// and returns the string in Str.  If unsuccessful, it returns false.  If
comment|/// StopAtNul is set to true (the default), the returned string is truncated
comment|/// by a nul character in the global.  If StopAtNul is false, the nul
comment|/// character is included in the result string.
name|bool
name|GetConstantStringInfo
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|std
operator|::
name|string
operator|&
name|Str
argument_list|,
name|uint64_t
name|Offset
operator|=
literal|0
argument_list|,
name|bool
name|StopAtNul
operator|=
name|true
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

