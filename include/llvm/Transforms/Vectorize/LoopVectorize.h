begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- LoopVectorize.h ---------------------------------------*- C++ -*-===//
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
comment|// This is the LLVM loop vectorizer. This pass modifies 'vectorizable' loops
end_comment

begin_comment
comment|// and generates target-independent LLVM-IR.
end_comment

begin_comment
comment|// The vectorizer uses the TargetTransformInfo analysis to estimate the costs
end_comment

begin_comment
comment|// of instructions in order to estimate the profitability of vectorization.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The loop vectorizer combines consecutive loop iterations into a single
end_comment

begin_comment
comment|// 'wide' iteration. After this transformation the index is incremented
end_comment

begin_comment
comment|// by the SIMD vector width, and not by one.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass has three parts:
end_comment

begin_comment
comment|// 1. The main loop pass that drives the different parts.
end_comment

begin_comment
comment|// 2. LoopVectorizationLegality - A unit that checks for the legality
end_comment

begin_comment
comment|//    of the vectorization.
end_comment

begin_comment
comment|// 3. InnerLoopVectorizer - A unit that performs the actual
end_comment

begin_comment
comment|//    widening of instructions.
end_comment

begin_comment
comment|// 4. LoopVectorizationCostModel - A unit that checks for the profitability
end_comment

begin_comment
comment|//    of vectorization. It decides on the optimal vector width, which
end_comment

begin_comment
comment|//    can be one, if vectorization is not profitable.
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
comment|// The reduction-variable vectorization is based on the paper:
end_comment

begin_comment
comment|//  D. Nuzman and R. Henderson. Multi-platform Auto-vectorization.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Variable uniformity checks are inspired by:
end_comment

begin_comment
comment|//  Karrenberg, R. and Hack, S. Whole Function Vectorization.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The interleaved access vectorization is based on the paper:
end_comment

begin_comment
comment|//  Dorit Nuzman, Ira Rosen and Ayal Zaks.  Auto-Vectorization of Interleaved
end_comment

begin_comment
comment|//  Data for SIMD
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Other ideas/concepts are from:
end_comment

begin_comment
comment|//  A. Zaks and D. Nuzman. Autovectorization in GCC-two years later.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  S. Maleki, Y. Gao, M. Garzaran, T. Wong and D. Padua.  An Evaluation of
end_comment

begin_comment
comment|//  Vectorizing Compilers.
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
name|LLVM_TRANSFORMS_VECTORIZE_LOOPVECTORIZE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_VECTORIZE_LOOPVECTORIZE_H
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
file|"llvm/Analysis/BasicAliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/BlockFrequencyInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/DemandedBits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopAccessAnalysis.h"
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

begin_include
include|#
directive|include
file|"llvm/Transforms/Scalar/LoopPassManager.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// The LoopVectorize Pass.
name|struct
name|LoopVectorizePass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopVectorizePass
operator|>
block|{
name|bool
name|DisableUnrolling
operator|=
name|false
block|;
comment|/// If true, consider all loops for vectorization.
comment|/// If false, only loops that explicitly request vectorization are
comment|/// considered.
name|bool
name|AlwaysVectorize
operator|=
name|true
block|;
name|ScalarEvolution
operator|*
name|SE
block|;
name|LoopInfo
operator|*
name|LI
block|;
name|TargetTransformInfo
operator|*
name|TTI
block|;
name|DominatorTree
operator|*
name|DT
block|;
name|BlockFrequencyInfo
operator|*
name|BFI
block|;
name|TargetLibraryInfo
operator|*
name|TLI
block|;
name|DemandedBits
operator|*
name|DB
block|;
name|AliasAnalysis
operator|*
name|AA
block|;
name|AssumptionCache
operator|*
name|AC
block|;
name|std
operator|::
name|function
operator|<
specifier|const
name|LoopAccessInfo
operator|&
operator|(
name|Loop
operator|&
operator|)
operator|>
operator|*
name|GetLAA
block|;
name|OptimizationRemarkEmitter
operator|*
name|ORE
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|;
comment|// Shim for old PM.
name|bool
name|runImpl
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|ScalarEvolution
operator|&
name|SE_
argument_list|,
name|LoopInfo
operator|&
name|LI_
argument_list|,
name|TargetTransformInfo
operator|&
name|TTI_
argument_list|,
name|DominatorTree
operator|&
name|DT_
argument_list|,
name|BlockFrequencyInfo
operator|&
name|BFI_
argument_list|,
name|TargetLibraryInfo
operator|*
name|TLI_
argument_list|,
name|DemandedBits
operator|&
name|DB_
argument_list|,
name|AliasAnalysis
operator|&
name|AA_
argument_list|,
name|AssumptionCache
operator|&
name|AC_
argument_list|,
name|std
operator|::
name|function
operator|<
specifier|const
name|LoopAccessInfo
operator|&
operator|(
name|Loop
operator|&
operator|)
operator|>
operator|&
name|GetLAA_
argument_list|,
name|OptimizationRemarkEmitter
operator|&
name|ORE
argument_list|)
block|;
name|bool
name|processLoop
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_VECTORIZE_LOOPVECTORIZE_H
end_comment

end_unit

