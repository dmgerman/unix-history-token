begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopAnalysisManager.h - Loop analysis management ---------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This header provides classes for managing per-loop analyses. These are
end_comment

begin_comment
comment|/// typically used as part of a loop pass pipeline over the loop nests of
end_comment

begin_comment
comment|/// a function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Loop analyses are allowed to make some simplifying assumptions:
end_comment

begin_comment
comment|/// 1) Loops are, where possible, in simplified form.
end_comment

begin_comment
comment|/// 2) Loops are *always* in LCSSA form.
end_comment

begin_comment
comment|/// 3) A collection of analysis results are available:
end_comment

begin_comment
comment|///    - LoopInfo
end_comment

begin_comment
comment|///    - DominatorTree
end_comment

begin_comment
comment|///    - ScalarEvolution
end_comment

begin_comment
comment|///    - AAManager
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The primary mechanism to provide these invariants is the loop pass manager,
end_comment

begin_comment
comment|/// but they can also be manually provided in order to reason about a loop from
end_comment

begin_comment
comment|/// outside of a dedicated pass manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_LOOPANALYSISMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPANALYSISMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PostOrderIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PriorityWorklist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/BasicAliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/GlobalsModRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolutionAliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
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
comment|/// The adaptor from a function pass to a loop pass computes these analyses and
comment|/// makes them available to the loop passes "for free". Each loop pass is
comment|/// expected expected to update these analyses if necessary to ensure they're
comment|/// valid after it runs.
struct|struct
name|LoopStandardAnalysisResults
block|{
name|AAResults
modifier|&
name|AA
decl_stmt|;
name|AssumptionCache
modifier|&
name|AC
decl_stmt|;
name|DominatorTree
modifier|&
name|DT
decl_stmt|;
name|LoopInfo
modifier|&
name|LI
decl_stmt|;
name|ScalarEvolution
modifier|&
name|SE
decl_stmt|;
name|TargetLibraryInfo
modifier|&
name|TLI
decl_stmt|;
name|TargetTransformInfo
modifier|&
name|TTI
decl_stmt|;
block|}
struct|;
comment|/// Extern template declaration for the analysis set for this IR unit.
extern|extern template class AllAnalysesOn<Loop>;
extern|extern template class AnalysisManager<Loop
operator|,
extern|LoopStandardAnalysisResults&>;
comment|/// \brief The loop analysis manager.
comment|///
comment|/// See the documentation for the AnalysisManager template for detail
comment|/// documentation. This typedef serves as a convenient way to refer to this
comment|/// construct in the adaptors and proxies used to integrate this into the larger
comment|/// pass manager infrastructure.
typedef|typedef
name|AnalysisManager
operator|<
name|Loop
operator|,
name|LoopStandardAnalysisResults
operator|&
operator|>
name|LoopAnalysisManager
expr_stmt|;
comment|/// A proxy from a \c LoopAnalysisManager to a \c Function.
typedef|typedef
name|InnerAnalysisManagerProxy
operator|<
name|LoopAnalysisManager
operator|,
name|Function
operator|>
name|LoopAnalysisManagerFunctionProxy
expr_stmt|;
comment|/// A specialized result for the \c LoopAnalysisManagerFunctionProxy which
comment|/// retains a \c LoopInfo reference.
comment|///
comment|/// This allows it to collect loop objects for which analysis results may be
comment|/// cached in the \c LoopAnalysisManager.
name|template
operator|<
operator|>
name|class
name|LoopAnalysisManagerFunctionProxy
operator|::
name|Result
block|{
name|public
operator|:
name|explicit
name|Result
argument_list|(
name|LoopAnalysisManager
operator|&
name|InnerAM
argument_list|,
name|LoopInfo
operator|&
name|LI
argument_list|)
operator|:
name|InnerAM
argument_list|(
operator|&
name|InnerAM
argument_list|)
block|,
name|LI
argument_list|(
argument|&LI
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|InnerAM
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|InnerAM
argument_list|)
argument_list|)
block|,
name|LI
argument_list|(
argument|Arg.LI
argument_list|)
block|{
comment|// We have to null out the analysis manager in the moved-from state
comment|// because we are taking ownership of the responsibilty to clear the
comment|// analysis state.
name|Arg
operator|.
name|InnerAM
operator|=
name|nullptr
block|;   }
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
operator|&&
name|RHS
operator|)
block|{
name|InnerAM
operator|=
name|RHS
operator|.
name|InnerAM
block|;
name|LI
operator|=
name|RHS
operator|.
name|LI
block|;
comment|// We have to null out the analysis manager in the moved-from state
comment|// because we are taking ownership of the responsibilty to clear the
comment|// analysis state.
name|RHS
operator|.
name|InnerAM
operator|=
name|nullptr
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|Result
argument_list|()
block|{
comment|// InnerAM is cleared in a moved from state where there is nothing to do.
if|if
condition|(
operator|!
name|InnerAM
condition|)
return|return;
comment|// Clear out the analysis manager if we're being destroyed -- it means we
comment|// didn't even see an invalidate call when we got invalidated.
name|InnerAM
operator|->
name|clear
argument_list|()
block|;   }
comment|/// Accessor for the analysis manager.
name|LoopAnalysisManager
operator|&
name|getManager
argument_list|()
block|{
return|return
operator|*
name|InnerAM
return|;
block|}
comment|/// Handler for invalidation of the proxy for a particular function.
comment|///
comment|/// If the proxy, \c LoopInfo, and associated analyses are preserved, this
comment|/// will merely forward the invalidation event to any cached loop analysis
comment|/// results for loops within this function.
comment|///
comment|/// If the necessary loop infrastructure is not preserved, this will forcibly
comment|/// clear all of the cached analysis results that are keyed on the \c
comment|/// LoopInfo for this function.
name|bool
name|invalidate
argument_list|(
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|FunctionAnalysisManager
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
decl_stmt|;
name|private
label|:
name|LoopAnalysisManager
modifier|*
name|InnerAM
decl_stmt|;
name|LoopInfo
modifier|*
name|LI
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Provide a specialized run method for the \c LoopAnalysisManagerFunctionProxy
end_comment

begin_comment
comment|/// so it can pass the \c LoopInfo to the result.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|LoopAnalysisManagerFunctionProxy
operator|::
name|Result
name|LoopAnalysisManagerFunctionProxy
operator|::
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Ensure the \c LoopAnalysisManagerFunctionProxy is provided as an extern
end_comment

begin_comment
comment|// template.
end_comment

begin_extern
extern|extern template class InnerAnalysisManagerProxy<LoopAnalysisManager
operator|,
extern|Function>;
end_extern

begin_extern
extern|extern template class OuterAnalysisManagerProxy<FunctionAnalysisManager
operator|,
extern|Loop
operator|,
extern|LoopStandardAnalysisResults&>;
end_extern

begin_comment
comment|/// A proxy from a \c FunctionAnalysisManager to a \c Loop.
end_comment

begin_typedef
typedef|typedef
name|OuterAnalysisManagerProxy
operator|<
name|FunctionAnalysisManager
operator|,
name|Loop
operator|,
name|LoopStandardAnalysisResults
operator|&
operator|>
name|FunctionAnalysisManagerLoopProxy
expr_stmt|;
end_typedef

begin_comment
comment|/// Returns the minimum set of Analyses that all loop passes must preserve.
end_comment

begin_function_decl
name|PreservedAnalyses
name|getLoopPassPreservedAnalyses
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ANALYSIS_LOOPANALYSISMANAGER_H
end_comment

end_unit

