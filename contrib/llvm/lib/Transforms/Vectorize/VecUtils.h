begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- VecUtils.h - Vectorization Utilities -------------------------------===//
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
comment|// This family of classes and functions manipulate vectors and chains of
end_comment

begin_comment
comment|// vectors.
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
name|LLVM_TRANSFORMS_VECTORIZE_VECUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_VECTORIZE_VECUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|VectorType
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetTransformInfo
decl_stmt|;
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|Loop
decl_stmt|;
comment|/// Bottom Up SLP vectorization utility class.
struct|struct
name|BoUpSLP
block|{
typedef|typedef
name|SmallVector
operator|<
name|Value
operator|*
operator|,
literal|8
operator|>
name|ValueList
expr_stmt|;
typedef|typedef
name|SmallPtrSet
operator|<
name|Value
operator|*
operator|,
literal|16
operator|>
name|ValueSet
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|StoreInst
operator|*
operator|,
literal|8
operator|>
name|StoreList
expr_stmt|;
specifier|static
specifier|const
name|int
name|max_cost
init|=
literal|1
operator|<<
literal|20
decl_stmt|;
comment|// \brief C'tor.
name|BoUpSLP
argument_list|(
name|BasicBlock
operator|*
name|Bb
argument_list|,
name|ScalarEvolution
operator|*
name|Se
argument_list|,
name|DataLayout
operator|*
name|Dl
argument_list|,
name|TargetTransformInfo
operator|*
name|Tti
argument_list|,
name|AliasAnalysis
operator|*
name|Aa
argument_list|,
name|Loop
operator|*
name|Lp
argument_list|)
expr_stmt|;
comment|/// \brief Take the pointer operand from the Load/Store instruction.
comment|/// \returns NULL if this is not a valid Load/Store instruction.
specifier|static
name|Value
modifier|*
name|getPointerOperand
parameter_list|(
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// \brief Take the address space operand from the Load/Store instruction.
comment|/// \returns -1 if this is not a valid Load/Store instruction.
specifier|static
name|unsigned
name|getAddressSpaceOperand
parameter_list|(
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// \returns true if the memory operations A and B are consecutive.
name|bool
name|isConsecutiveAccess
parameter_list|(
name|Value
modifier|*
name|A
parameter_list|,
name|Value
modifier|*
name|B
parameter_list|)
function_decl|;
comment|/// \brief Vectorize the tree that starts with the elements in \p VL.
comment|/// \returns the vectorized value.
name|Value
modifier|*
name|vectorizeTree
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|,
name|int
name|VF
argument_list|)
decl_stmt|;
comment|/// \returns the vectorization cost of the subtree that starts at \p VL.
comment|/// A negative number means that this is profitable.
name|int
name|getTreeCost
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|)
decl_stmt|;
comment|/// \returns the scalarization cost for this list of values. Assuming that
comment|/// this subtree gets vectorized, we may need to extract the values from the
comment|/// roots. This method calculates the cost of extracting the values.
name|int
name|getScalarizationCost
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|)
decl_stmt|;
comment|/// \brief Attempts to order and vectorize a sequence of stores. This
comment|/// function does a quadratic scan of the given stores.
comment|/// \returns true if the basic block was modified.
name|bool
name|vectorizeStores
argument_list|(
name|ArrayRef
operator|<
name|StoreInst
operator|*
operator|>
name|Stores
argument_list|,
name|int
name|costThreshold
argument_list|)
decl_stmt|;
comment|/// \brief Vectorize a group of scalars into a vector tree.
name|void
name|vectorizeArith
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Operands
argument_list|)
decl_stmt|;
comment|/// \returns the list of new instructions that were added in order to collect
comment|/// scalars into vectors. This list can be used to further optimize the gather
comment|/// sequences.
name|ValueList
modifier|&
name|getGatherSeqInstructions
parameter_list|()
block|{
return|return
name|GatherInstructions
return|;
block|}
name|private
label|:
comment|/// \brief This method contains the recursive part of getTreeCost.
name|int
name|getTreeCost_rec
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|,
name|unsigned
name|Depth
argument_list|)
decl_stmt|;
comment|/// \brief This recursive method looks for vectorization hazards such as
comment|/// values that are used by multiple users and checks that values are used
comment|/// by only one vector lane. It updates the variables LaneMap, MultiUserVals.
name|void
name|getTreeUses_rec
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|,
name|unsigned
name|Depth
argument_list|)
decl_stmt|;
comment|/// \brief This method contains the recursive part of vectorizeTree.
name|Value
modifier|*
name|vectorizeTree_rec
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|,
name|int
name|VF
argument_list|)
decl_stmt|;
comment|/// \brief Number all of the instructions in the block.
name|void
name|numberInstructions
parameter_list|()
function_decl|;
comment|///  \brief Vectorize a sorted sequence of stores.
name|bool
name|vectorizeStoreChain
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Chain
argument_list|,
name|int
name|CostThreshold
argument_list|)
decl_stmt|;
comment|/// \returns the scalarization cost for this type. Scalarization in this
comment|/// context means the creation of vectors from a group of scalars.
name|int
name|getScalarizationCost
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// \returns the AA location that is being access by the instruction.
name|AliasAnalysis
operator|::
name|Location
name|getLocation
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
expr_stmt|;
comment|/// \brief Checks if it is possible to sink an instruction from
comment|/// \p Src to \p Dst.
comment|/// \returns the pointer to the barrier instruction if we can't sink.
name|Value
modifier|*
name|isUnsafeToSink
parameter_list|(
name|Instruction
modifier|*
name|Src
parameter_list|,
name|Instruction
modifier|*
name|Dst
parameter_list|)
function_decl|;
comment|/// \returns the instruction that appears last in the BB from \p VL.
comment|/// Only consider the first \p VF elements.
name|Instruction
modifier|*
name|GetLastInstr
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|,
name|unsigned
name|VF
argument_list|)
decl_stmt|;
comment|/// \returns a vector from a collection of scalars in \p VL.
name|Value
modifier|*
name|Scalarize
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|,
name|VectorType
operator|*
name|Ty
argument_list|)
decl_stmt|;
name|private
label|:
comment|/// Maps instructions to numbers and back.
name|SmallDenseMap
operator|<
name|Value
operator|*
operator|,
name|int
operator|>
name|InstrIdx
expr_stmt|;
comment|/// Maps integers to Instructions.
name|std
operator|::
name|vector
operator|<
name|Instruction
operator|*
operator|>
name|InstrVec
expr_stmt|;
comment|// -- containers that are used during getTreeCost -- //
comment|/// Contains values that must be scalarized because they are used
comment|/// by multiple lanes, or by users outside the tree.
comment|/// NOTICE: The vectorization methods also use this set.
name|ValueSet
name|MustScalarize
decl_stmt|;
comment|/// Contains a list of values that are used outside the current tree. This
comment|/// set must be reset between runs.
name|ValueSet
name|MultiUserVals
decl_stmt|;
comment|/// Maps values in the tree to the vector lanes that uses them. This map must
comment|/// be reset between runs of getCost.
name|std
operator|::
name|map
operator|<
name|Value
operator|*
operator|,
name|int
operator|>
name|LaneMap
expr_stmt|;
comment|/// A list of instructions to ignore while sinking
comment|/// memory instructions. This map must be reset between runs of getCost.
name|SmallPtrSet
operator|<
name|Value
operator|*
operator|,
literal|8
operator|>
name|MemBarrierIgnoreList
expr_stmt|;
comment|// -- Containers that are used during vectorizeTree -- //
comment|/// Maps between the first scalar to the vector. This map must be reset
comment|///between runs.
name|DenseMap
operator|<
name|Value
operator|*
operator|,
name|Value
operator|*
operator|>
name|VectorizedValues
expr_stmt|;
comment|// -- Containers that are used after vectorization by the caller -- //
comment|/// A list of instructions that are used when gathering scalars into vectors.
comment|/// In many cases these instructions can be hoisted outside of the BB.
comment|/// Iterating over this list is faster than calling LICM.
name|ValueList
name|GatherInstructions
decl_stmt|;
comment|// Analysis and block reference.
name|BasicBlock
modifier|*
name|BB
decl_stmt|;
name|ScalarEvolution
modifier|*
name|SE
decl_stmt|;
name|DataLayout
modifier|*
name|DL
decl_stmt|;
name|TargetTransformInfo
modifier|*
name|TTI
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
name|Loop
modifier|*
name|L
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end of namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_VECTORIZE_VECUTILS_H
end_comment

end_unit

