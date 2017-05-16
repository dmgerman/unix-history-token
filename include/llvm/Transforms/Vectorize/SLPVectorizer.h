begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- SLPVectorizer.h ---------------------------------------*- C++ -*-===//
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
comment|// This pass implements the Bottom Up SLP vectorizer. It detects consecutive
end_comment

begin_comment
comment|// stores that can be put together into vector-stores. Next, it attempts to
end_comment

begin_comment
comment|// construct vectorizable tree using the use-def chains. If a profitable tree
end_comment

begin_comment
comment|// was found, the SLP vectorizer performs vectorization on the tree.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The pass is inspired by the work described in the paper:
end_comment

begin_comment
comment|//  "Loop-Aware SLP in GCC" by Ira Rosen, Dorit Nuzman, Ayal Zaks.
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
name|LLVM_TRANSFORMS_VECTORIZE_SLPVECTORIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_VECTORIZE_SLPVECTORIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/DemandedBits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/OptimizationDiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A private "module" namespace for types and utilities used by this pass.
comment|/// These are implementation details and should not be used by clients.
name|namespace
name|slpvectorizer
block|{
name|class
name|BoUpSLP
decl_stmt|;
block|}
name|struct
name|SLPVectorizerPass
range|:
name|public
name|PassInfoMixin
operator|<
name|SLPVectorizerPass
operator|>
block|{
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
typedef|typedef
name|MapVector
operator|<
name|Value
operator|*
operator|,
name|StoreList
operator|>
name|StoreListMap
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|WeakTrackingVH
operator|,
literal|8
operator|>
name|WeakTrackingVHList
expr_stmt|;
typedef|typedef
name|MapVector
operator|<
name|Value
operator|*
operator|,
name|WeakTrackingVHList
operator|>
name|WeakTrackingVHListMap
expr_stmt|;
name|ScalarEvolution
modifier|*
name|SE
init|=
name|nullptr
decl_stmt|;
name|TargetTransformInfo
modifier|*
name|TTI
init|=
name|nullptr
decl_stmt|;
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
init|=
name|nullptr
decl_stmt|;
name|LoopInfo
modifier|*
name|LI
init|=
name|nullptr
decl_stmt|;
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
decl_stmt|;
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
decl_stmt|;
name|DemandedBits
modifier|*
name|DB
init|=
name|nullptr
decl_stmt|;
specifier|const
name|DataLayout
modifier|*
name|DL
init|=
name|nullptr
decl_stmt|;
name|public
label|:
name|PreservedAnalyses
name|run
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
name|FunctionAnalysisManager
modifier|&
name|AM
parameter_list|)
function_decl|;
comment|// Glue for old PM.
name|bool
name|runImpl
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE_
parameter_list|,
name|TargetTransformInfo
modifier|*
name|TTI_
parameter_list|,
name|TargetLibraryInfo
modifier|*
name|TLI_
parameter_list|,
name|AliasAnalysis
modifier|*
name|AA_
parameter_list|,
name|LoopInfo
modifier|*
name|LI_
parameter_list|,
name|DominatorTree
modifier|*
name|DT_
parameter_list|,
name|AssumptionCache
modifier|*
name|AC_
parameter_list|,
name|DemandedBits
modifier|*
name|DB_
parameter_list|,
name|OptimizationRemarkEmitter
modifier|*
name|ORE_
parameter_list|)
function_decl|;
name|private
label|:
comment|/// \brief Collect store and getelementptr instructions and organize them
comment|/// according to the underlying object of their pointer operands. We sort the
comment|/// instructions by their underlying objects to reduce the cost of
comment|/// consecutive access queries.
comment|///
comment|/// TODO: We can further reduce this cost if we flush the chain creation
comment|///       every time we run into a memory barrier.
name|void
name|collectSeedInstructions
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// \brief Try to vectorize a chain that starts at two arithmetic instrs.
name|bool
name|tryToVectorizePair
argument_list|(
name|Value
operator|*
name|A
argument_list|,
name|Value
operator|*
name|B
argument_list|,
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|)
decl_stmt|;
comment|/// \brief Try to vectorize a list of operands.
comment|/// \@param BuildVector A list of users to ignore for the purpose of
comment|///                     scheduling and that don't need extracting.
comment|/// \returns true if a value was vectorized.
name|bool
name|tryToVectorizeList
argument_list|(
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|VL
argument_list|,
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|BuildVector
operator|=
name|None
argument_list|,
name|bool
name|AllowReorder
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Try to vectorize a chain that may start at the operands of \V;
name|bool
name|tryToVectorize
argument_list|(
name|BinaryOperator
operator|*
name|V
argument_list|,
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|)
decl_stmt|;
comment|/// \brief Vectorize the store instructions collected in Stores.
name|bool
name|vectorizeStoreChains
argument_list|(
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|)
decl_stmt|;
comment|/// \brief Vectorize the index computations of the getelementptr instructions
comment|/// collected in GEPs.
name|bool
name|vectorizeGEPIndices
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|)
decl_stmt|;
comment|/// Try to find horizontal reduction or otherwise vectorize a chain of binary
comment|/// operators.
name|bool
name|vectorizeRootInstruction
argument_list|(
name|PHINode
operator|*
name|P
argument_list|,
name|Value
operator|*
name|V
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|,
name|TargetTransformInfo
operator|*
name|TTI
argument_list|)
decl_stmt|;
comment|/// \brief Scan the basic block and look for patterns that are likely to start
comment|/// a vectorization chain.
name|bool
name|vectorizeChainsInBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|)
decl_stmt|;
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
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|,
name|unsigned
name|VecRegSize
argument_list|)
decl_stmt|;
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
name|slpvectorizer
operator|::
name|BoUpSLP
operator|&
name|R
argument_list|)
decl_stmt|;
comment|/// The store instructions in a basic block organized by base pointer.
name|StoreListMap
name|Stores
decl_stmt|;
comment|/// The getelementptr instructions in a basic block organized by base pointer.
name|WeakTrackingVHListMap
name|GEPs
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_VECTORIZE_SLPVECTORIZER_H
end_comment

end_unit

