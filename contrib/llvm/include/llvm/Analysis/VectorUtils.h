begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/VectorUtils.h - Vector utilities -----------*- C++ -*-===//
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
comment|// This file defines some vectorizer utilities.
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
name|LLVM_ANALYSIS_VECTORUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_VECTORUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
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
name|DemandedBits
decl_stmt|;
name|class
name|GetElementPtrInst
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|TargetTransformInfo
decl_stmt|;
name|class
name|Type
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
comment|/// \brief Identify if the intrinsic is trivially vectorizable.
comment|/// This method returns true if the intrinsic's argument types are all
comment|/// scalars for the scalar form of the intrinsic and all vectors for
comment|/// the vector form of the intrinsic.
name|bool
name|isTriviallyVectorizable
argument_list|(
name|Intrinsic
operator|::
name|ID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief Identifies if the intrinsic has a scalar operand. It checks for
comment|/// ctlz,cttz and powi special intrinsics whose argument is scalar.
name|bool
name|hasVectorInstrinsicScalarOpd
argument_list|(
name|Intrinsic
operator|::
name|ID
name|ID
argument_list|,
name|unsigned
name|ScalarOpdIdx
argument_list|)
decl_stmt|;
comment|/// \brief Returns intrinsic ID for call.
comment|/// For the input call instruction it finds mapping intrinsic and returns
comment|/// its intrinsic ID, in case it does not found it return not_intrinsic.
name|Intrinsic
operator|::
name|ID
name|getVectorIntrinsicIDForCall
argument_list|(
specifier|const
name|CallInst
operator|*
name|CI
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
expr_stmt|;
comment|/// \brief Find the operand of the GEP that should be checked for consecutive
comment|/// stores. This ignores trailing indices that have no effect on the final
comment|/// pointer.
name|unsigned
name|getGEPInductionOperand
parameter_list|(
specifier|const
name|GetElementPtrInst
modifier|*
name|Gep
parameter_list|)
function_decl|;
comment|/// \brief If the argument is a GEP, then returns the operand identified by
comment|/// getGEPInductionOperand. However, if there is some other non-loop-invariant
comment|/// operand, it returns that instead.
name|Value
modifier|*
name|stripGetElementPtr
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
parameter_list|,
name|Loop
modifier|*
name|Lp
parameter_list|)
function_decl|;
comment|/// \brief If a value has only one user that is a CastInst, return it.
name|Value
modifier|*
name|getUniqueCastUse
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|,
name|Loop
modifier|*
name|Lp
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// \brief Get the stride of a pointer access in a loop. Looks for symbolic
comment|/// strides "a[i*stride]". Returns the symbolic stride, or null otherwise.
name|Value
modifier|*
name|getStrideFromPointer
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
parameter_list|,
name|Loop
modifier|*
name|Lp
parameter_list|)
function_decl|;
comment|/// \brief Given a vector and an element number, see if the scalar value is
comment|/// already around as a register, for example if it were inserted then extracted
comment|/// from the vector.
name|Value
modifier|*
name|findScalarElement
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|EltNo
parameter_list|)
function_decl|;
comment|/// \brief Get splat value if the input is a splat vector or return nullptr.
comment|/// The value may be extracted from a splat constants vector or from
comment|/// a sequence of instructions that broadcast a single value into a vector.
specifier|const
name|Value
modifier|*
name|getSplatValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// \brief Compute a map of integer instructions to their minimum legal type
comment|/// size.
comment|///
comment|/// C semantics force sub-int-sized values (e.g. i8, i16) to be promoted to int
comment|/// type (e.g. i32) whenever arithmetic is performed on them.
comment|///
comment|/// For targets with native i8 or i16 operations, usually InstCombine can shrink
comment|/// the arithmetic type down again. However InstCombine refuses to create
comment|/// illegal types, so for targets without i8 or i16 registers, the lengthening
comment|/// and shrinking remains.
comment|///
comment|/// Most SIMD ISAs (e.g. NEON) however support vectors of i8 or i16 even when
comment|/// their scalar equivalents do not, so during vectorization it is important to
comment|/// remove these lengthens and truncates when deciding the profitability of
comment|/// vectorization.
comment|///
comment|/// This function analyzes the given range of instructions and determines the
comment|/// minimum type size each can be converted to. It attempts to remove or
comment|/// minimize type size changes across each def-use chain, so for example in the
comment|/// following code:
comment|///
comment|///   %1 = load i8, i8*
comment|///   %2 = add i8 %1, 2
comment|///   %3 = load i16, i16*
comment|///   %4 = zext i8 %2 to i32
comment|///   %5 = zext i16 %3 to i32
comment|///   %6 = add i32 %4, %5
comment|///   %7 = trunc i32 %6 to i16
comment|///
comment|/// Instruction %6 must be done at least in i16, so computeMinimumValueSizes
comment|/// will return: {%1: 16, %2: 16, %3: 16, %4: 16, %5: 16, %6: 16, %7: 16}.
comment|///
comment|/// If the optional TargetTransformInfo is provided, this function tries harder
comment|/// to do less work by only looking at illegal types.
name|MapVector
operator|<
name|Instruction
operator|*
operator|,
name|uint64_t
operator|>
name|computeMinimumValueSizes
argument_list|(
name|ArrayRef
operator|<
name|BasicBlock
operator|*
operator|>
name|Blocks
argument_list|,
name|DemandedBits
operator|&
name|DB
argument_list|,
specifier|const
name|TargetTransformInfo
operator|*
name|TTI
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// Specifically, let Kinds = [MD_tbaa, MD_alias_scope, MD_noalias, MD_fpmath,
comment|/// MD_nontemporal].  For K in Kinds, we get the MDNode for K from each of the
comment|/// elements of VL, compute their "intersection" (i.e., the most generic
comment|/// metadata value that covers all of the individual values), and set I's
comment|/// metadata for M equal to the intersection value.
comment|///
comment|/// This function always sets a (possibly null) value for each K in Kinds.
name|Instruction
modifier|*
name|propagateMetadata
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|)
decl_stmt|;
comment|/// \brief Create an interleave shuffle mask.
comment|///
comment|/// This function creates a shuffle mask for interleaving \p NumVecs vectors of
comment|/// vectorization factor \p VF into a single wide vector. The mask is of the
comment|/// form:
comment|///
comment|///<0, VF, VF * 2, ..., VF * (NumVecs - 1), 1, VF + 1, VF * 2 + 1, ...>
comment|///
comment|/// For example, the mask for VF = 4 and NumVecs = 2 is:
comment|///
comment|///<0, 4, 1, 5, 2, 6, 3, 7>.
name|Constant
modifier|*
name|createInterleaveMask
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|unsigned
name|VF
argument_list|,
name|unsigned
name|NumVecs
argument_list|)
decl_stmt|;
comment|/// \brief Create a stride shuffle mask.
comment|///
comment|/// This function creates a shuffle mask whose elements begin at \p Start and
comment|/// are incremented by \p Stride. The mask can be used to deinterleave an
comment|/// interleaved vector into separate vectors of vectorization factor \p VF. The
comment|/// mask is of the form:
comment|///
comment|///<Start, Start + Stride, ..., Start + Stride * (VF - 1)>
comment|///
comment|/// For example, the mask for Start = 0, Stride = 2, and VF = 4 is:
comment|///
comment|///<0, 2, 4, 6>
name|Constant
modifier|*
name|createStrideMask
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|unsigned
name|Start
argument_list|,
name|unsigned
name|Stride
argument_list|,
name|unsigned
name|VF
argument_list|)
decl_stmt|;
comment|/// \brief Create a sequential shuffle mask.
comment|///
comment|/// This function creates shuffle mask whose elements are sequential and begin
comment|/// at \p Start.  The mask contains \p NumInts integers and is padded with \p
comment|/// NumUndefs undef values. The mask is of the form:
comment|///
comment|///<Start, Start + 1, ... Start + NumInts - 1, undef_1, ... undef_NumUndefs>
comment|///
comment|/// For example, the mask for Start = 0, NumInsts = 4, and NumUndefs = 4 is:
comment|///
comment|///<0, 1, 2, 3, undef, undef, undef, undef>
name|Constant
modifier|*
name|createSequentialMask
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|unsigned
name|Start
argument_list|,
name|unsigned
name|NumInts
argument_list|,
name|unsigned
name|NumUndefs
argument_list|)
decl_stmt|;
comment|/// \brief Concatenate a list of vectors.
comment|///
comment|/// This function generates code that concatenate the vectors in \p Vecs into a
comment|/// single large vector. The number of vectors should be greater than one, and
comment|/// their element types should be the same. The number of elements in the
comment|/// vectors should also be the same; however, if the last vector has fewer
comment|/// elements, it will be padded with undefs.
name|Value
modifier|*
name|concatenateVectors
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Vecs
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

