begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Vectorize.h - Vectorization Transformations -------------*- C++ -*-===//
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
comment|// This header file defines prototypes for accessor functions that expose passes
end_comment

begin_comment
comment|// in the Vectorize transformations library.
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
name|LLVM_TRANSFORMS_VECTORIZE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_VECTORIZE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|BasicBlockPass
decl_stmt|;
name|class
name|Pass
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// @brief Vectorize configuration.
struct|struct
name|VectorizeConfig
block|{
comment|//===--------------------------------------------------------------------===//
comment|// Target architecture related parameters
comment|/// @brief The size of the native vector registers.
name|unsigned
name|VectorBits
decl_stmt|;
comment|/// @brief Vectorize boolean values.
name|bool
name|VectorizeBools
decl_stmt|;
comment|/// @brief Vectorize integer values.
name|bool
name|VectorizeInts
decl_stmt|;
comment|/// @brief Vectorize floating-point values.
name|bool
name|VectorizeFloats
decl_stmt|;
comment|/// @brief Vectorize pointer values.
name|bool
name|VectorizePointers
decl_stmt|;
comment|/// @brief Vectorize casting (conversion) operations.
name|bool
name|VectorizeCasts
decl_stmt|;
comment|/// @brief Vectorize floating-point math intrinsics.
name|bool
name|VectorizeMath
decl_stmt|;
comment|/// @brief Vectorize bit intrinsics.
name|bool
name|VectorizeBitManipulations
decl_stmt|;
comment|/// @brief Vectorize the fused-multiply-add intrinsic.
name|bool
name|VectorizeFMA
decl_stmt|;
comment|/// @brief Vectorize select instructions.
name|bool
name|VectorizeSelect
decl_stmt|;
comment|/// @brief Vectorize comparison instructions.
name|bool
name|VectorizeCmp
decl_stmt|;
comment|/// @brief Vectorize getelementptr instructions.
name|bool
name|VectorizeGEP
decl_stmt|;
comment|/// @brief Vectorize loads and stores.
name|bool
name|VectorizeMemOps
decl_stmt|;
comment|/// @brief Only generate aligned loads and stores.
name|bool
name|AlignedOnly
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Misc parameters
comment|/// @brief The required chain depth for vectorization.
name|unsigned
name|ReqChainDepth
decl_stmt|;
comment|/// @brief The maximum search distance for instruction pairs.
name|unsigned
name|SearchLimit
decl_stmt|;
comment|/// @brief The maximum number of candidate pairs with which to use a full
comment|///        cycle check.
name|unsigned
name|MaxCandPairsForCycleCheck
decl_stmt|;
comment|/// @brief Replicating one element to a pair breaks the chain.
name|bool
name|SplatBreaksChain
decl_stmt|;
comment|/// @brief The maximum number of pairable instructions per group.
name|unsigned
name|MaxInsts
decl_stmt|;
comment|/// @brief The maximum number of candidate instruction pairs per group.
name|unsigned
name|MaxPairs
decl_stmt|;
comment|/// @brief The maximum number of pairing iterations.
name|unsigned
name|MaxIter
decl_stmt|;
comment|/// @brief Don't try to form odd-length vectors.
name|bool
name|Pow2LenOnly
decl_stmt|;
comment|/// @brief Don't boost the chain-depth contribution of loads and stores.
name|bool
name|NoMemOpBoost
decl_stmt|;
comment|/// @brief Use a fast instruction dependency analysis.
name|bool
name|FastDep
decl_stmt|;
comment|/// @brief Initialize the VectorizeConfig from command line options.
name|VectorizeConfig
argument_list|()
expr_stmt|;
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopVectorize - Create a loop vectorization pass.
comment|//
name|Pass
modifier|*
name|createLoopVectorizePass
parameter_list|(
name|bool
name|NoUnrolling
init|=
name|false
parameter_list|,
name|bool
name|AlwaysVectorize
init|=
name|true
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// SLPVectorizer - Create a bottom-up SLP vectorizer pass.
comment|//
name|Pass
modifier|*
name|createSLPVectorizerPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// @brief Vectorize the BasicBlock.
comment|///
comment|/// @param BB The BasicBlock to be vectorized
comment|/// @param P  The current running pass, should require AliasAnalysis and
comment|///           ScalarEvolution. After the vectorization, AliasAnalysis,
comment|///           ScalarEvolution and CFG are preserved.
comment|///
comment|/// @return True if the BB is changed, false otherwise.
comment|///
name|bool
name|vectorizeBasicBlock
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|BasicBlock
modifier|&
name|BB
parameter_list|,
specifier|const
name|VectorizeConfig
modifier|&
name|C
init|=
name|VectorizeConfig
argument_list|()
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoadStoreVectorizer - Create vector loads and stores, but leave scalar
comment|// operations.
comment|//
name|Pass
modifier|*
name|createLoadStoreVectorizerPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

