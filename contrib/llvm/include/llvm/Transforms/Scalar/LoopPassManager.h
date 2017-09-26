begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopPassManager.h - Loop pass management -----------------*- C++ -*-===//
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
comment|/// This header provides classes for managing a pipeline of passes over loops
end_comment

begin_comment
comment|/// in LLVM IR.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The primary loop pass pipeline is managed in a very particular way to
end_comment

begin_comment
comment|/// provide a set of core guarantees:
end_comment

begin_comment
comment|/// 1) Loops are, where possible, in simplified form.
end_comment

begin_comment
comment|/// 2) Loops are *always* in LCSSA form.
end_comment

begin_comment
comment|/// 3) A collection of Loop-specific analysis results are available:
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
comment|/// 4) All loop passes preserve #1 (where possible), #2, and #3.
end_comment

begin_comment
comment|/// 5) Loop passes run over each loop in the loop nest from the innermost to
end_comment

begin_comment
comment|///    the outermost. Specifically, all inner loops are processed before
end_comment

begin_comment
comment|///    passes run over outer loops. When running the pipeline across an inner
end_comment

begin_comment
comment|///    loop creates new inner loops, those are added and processed in this
end_comment

begin_comment
comment|///    order as well.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This process is designed to facilitate transformations which simplify,
end_comment

begin_comment
comment|/// reduce, and remove loops. For passes which are more oriented towards
end_comment

begin_comment
comment|/// optimizing loops, especially optimizing loop *nests* instead of single
end_comment

begin_comment
comment|/// loops in isolation, this framework is less interesting.
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
name|LLVM_TRANSFORMS_SCALAR_LOOPPASSMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPPASSMANAGER_H
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
file|"llvm/Analysis/LoopAnalysisManager.h"
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

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/LCSSA.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/LoopSimplify.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations of an update tracking API used in the pass manager.
name|class
name|LPMUpdater
decl_stmt|;
comment|// Explicit specialization and instantiation declarations for the pass manager.
comment|// See the comments on the definition of the specialization for details on how
comment|// it differs from the primary template.
name|template
operator|<
operator|>
name|PreservedAnalyses
name|PassManager
operator|<
name|Loop
operator|,
name|LoopAnalysisManager
operator|,
name|LoopStandardAnalysisResults
operator|&
operator|,
name|LPMUpdater
operator|&
operator|>
operator|::
name|run
argument_list|(
name|Loop
operator|&
name|InitialL
argument_list|,
name|LoopAnalysisManager
operator|&
name|AM
argument_list|,
name|LoopStandardAnalysisResults
operator|&
name|AnalysisResults
argument_list|,
name|LPMUpdater
operator|&
name|U
argument_list|)
expr_stmt|;
extern|extern template class PassManager<Loop
operator|,
extern|LoopAnalysisManager
operator|,
extern|LoopStandardAnalysisResults&
operator|,
extern|LPMUpdater&>;
comment|/// \brief The Loop pass manager.
comment|///
comment|/// See the documentation for the PassManager template for details. It runs
comment|/// a sequence of Loop passes over each Loop that the manager is run over. This
comment|/// typedef serves as a convenient way to refer to this construct.
typedef|typedef
name|PassManager
operator|<
name|Loop
operator|,
name|LoopAnalysisManager
operator|,
name|LoopStandardAnalysisResults
operator|&
operator|,
name|LPMUpdater
operator|&
operator|>
name|LoopPassManager
expr_stmt|;
comment|/// A partial specialization of the require analysis template pass to forward
comment|/// the extra parameters from a transformation's run method to the
comment|/// AnalysisManager's getResult.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
expr|struct
name|RequireAnalysisPass
operator|<
name|AnalysisT
operator|,
name|Loop
operator|,
name|LoopAnalysisManager
operator|,
name|LoopStandardAnalysisResults
operator|&
operator|,
name|LPMUpdater
operator|&
operator|>
operator|:
name|PassInfoMixin
operator|<
name|RequireAnalysisPass
operator|<
name|AnalysisT
operator|,
name|Loop
operator|,
name|LoopAnalysisManager
operator|,
name|LoopStandardAnalysisResults
operator|&
operator|,
name|LPMUpdater
operator|&
operator|>>
block|{
name|PreservedAnalyses
name|run
argument_list|(
argument|Loop&L
argument_list|,
argument|LoopAnalysisManager&AM
argument_list|,
argument|LoopStandardAnalysisResults&AR
argument_list|,
argument|LPMUpdater&
argument_list|)
block|{
operator|(
name|void
operator|)
name|AM
operator|.
name|template
name|getResult
operator|<
name|AnalysisT
operator|>
operator|(
name|L
operator|,
name|AR
operator|)
block|;
return|return
name|PreservedAnalyses
operator|::
name|all
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// An alias template to easily name a require analysis loop pass.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
name|using
name|RequireAnalysisLoopPass
operator|=
name|RequireAnalysisPass
operator|<
name|AnalysisT
block|,
name|Loop
block|,
name|LoopAnalysisManager
block|,
name|LoopStandardAnalysisResults
operator|&
block|,
name|LPMUpdater
operator|&
operator|>
block|;
name|namespace
name|internal
block|{
comment|/// Helper to implement appending of loops onto a worklist.
comment|///
comment|/// We want to process loops in postorder, but the worklist is a LIFO data
comment|/// structure, so we append to it in *reverse* postorder.
comment|///
comment|/// For trees, a preorder traversal is a viable reverse postorder, so we
comment|/// actually append using a preorder walk algorithm.
name|template
operator|<
name|typename
name|RangeT
operator|>
specifier|inline
name|void
name|appendLoopsToWorklist
argument_list|(
argument|RangeT&&Loops
argument_list|,
argument|SmallPriorityWorklist<Loop *
argument_list|,
literal|4
argument|>&Worklist
argument_list|)
block|{
comment|// We use an internal worklist to build up the preorder traversal without
comment|// recursion.
name|SmallVector
operator|<
name|Loop
operator|*
block|,
literal|4
operator|>
name|PreOrderLoops
block|,
name|PreOrderWorklist
block|;
comment|// We walk the initial sequence of loops in reverse because we generally want
comment|// to visit defs before uses and the worklist is LIFO.
for|for
control|(
name|Loop
modifier|*
name|RootL
range|:
name|reverse
argument_list|(
name|Loops
argument_list|)
control|)
block|{
name|assert
argument_list|(
name|PreOrderLoops
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must start with an empty preorder walk."
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|PreOrderWorklist
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must start with an empty preorder walk worklist."
argument_list|)
expr_stmt|;
name|PreOrderWorklist
operator|.
name|push_back
argument_list|(
name|RootL
argument_list|)
expr_stmt|;
do|do
block|{
name|Loop
modifier|*
name|L
init|=
name|PreOrderWorklist
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
name|PreOrderWorklist
operator|.
name|append
argument_list|(
name|L
operator|->
name|begin
argument_list|()
argument_list|,
name|L
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|PreOrderLoops
operator|.
name|push_back
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|PreOrderWorklist
operator|.
name|empty
argument_list|()
condition|)
empty_stmt|;
do|Worklist.insert(std::move(PreOrderLoops
block|)
block|)
block|;
name|PreOrderLoops
operator|.
name|clear
argument_list|()
block|;   }
block|}
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|LoopPassT
operator|>
name|class
name|FunctionToLoopPassAdaptor
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// This class provides an interface for updating the loop pass manager based
end_comment

begin_comment
comment|/// on mutations to the loop nest.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A reference to an instance of this class is passed as an argument to each
end_comment

begin_comment
comment|/// Loop pass, and Loop passes should use it to update LPM infrastructure if
end_comment

begin_comment
comment|/// they modify the loop nest structure.
end_comment

begin_decl_stmt
name|class
name|LPMUpdater
block|{
name|public
label|:
comment|/// This can be queried by loop passes which run other loop passes (like pass
comment|/// managers) to know whether the loop needs to be skipped due to updates to
comment|/// the loop nest.
comment|///
comment|/// If this returns true, the loop object may have been deleted, so passes
comment|/// should take care not to touch the object.
name|bool
name|skipCurrentLoop
argument_list|()
specifier|const
block|{
return|return
name|SkipCurrentLoop
return|;
block|}
comment|/// Loop passes should use this method to indicate they have deleted a loop
comment|/// from the nest.
comment|///
comment|/// Note that this loop must either be the current loop or a subloop of the
comment|/// current loop. This routine must be called prior to removing the loop from
comment|/// the loop nest.
comment|///
comment|/// If this is called for the current loop, in addition to clearing any
comment|/// state, this routine will mark that the current loop should be skipped by
comment|/// the rest of the pass management infrastructure.
name|void
name|markLoopAsDeleted
parameter_list|(
name|Loop
modifier|&
name|L
parameter_list|)
block|{
name|LAM
operator|.
name|clear
argument_list|(
name|L
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CurrentL
operator|->
name|contains
argument_list|(
operator|&
name|L
argument_list|)
operator|&&
literal|"Cannot delete a loop outside of the "
literal|"subloop tree currently being processed."
argument_list|)
expr_stmt|;
if|if
condition|(
operator|&
name|L
operator|==
name|CurrentL
condition|)
name|SkipCurrentLoop
operator|=
name|true
expr_stmt|;
block|}
comment|/// Loop passes should use this method to indicate they have added new child
comment|/// loops of the current loop.
comment|///
comment|/// \p NewChildLoops must contain only the immediate children. Any nested
comment|/// loops within them will be visited in postorder as usual for the loop pass
comment|/// manager.
name|void
name|addChildLoops
argument_list|(
name|ArrayRef
operator|<
name|Loop
operator|*
operator|>
name|NewChildLoops
argument_list|)
block|{
comment|// Insert ourselves back into the worklist first, as this loop should be
comment|// revisited after all the children have been processed.
name|Worklist
operator|.
name|insert
argument_list|(
name|CurrentL
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
for|for
control|(
name|Loop
modifier|*
name|NewL
range|:
name|NewChildLoops
control|)
name|assert
argument_list|(
name|NewL
operator|->
name|getParentLoop
argument_list|()
operator|==
name|CurrentL
operator|&&
literal|"All of the new loops must "
literal|"be immediate children of "
literal|"the current loop!"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|internal
operator|::
name|appendLoopsToWorklist
argument_list|(
name|NewChildLoops
argument_list|,
name|Worklist
argument_list|)
expr_stmt|;
comment|// Also skip further processing of the current loop--it will be revisited
comment|// after all of its newly added children are accounted for.
name|SkipCurrentLoop
operator|=
name|true
expr_stmt|;
block|}
comment|/// Loop passes should use this method to indicate they have added new
comment|/// sibling loops to the current loop.
comment|///
comment|/// \p NewSibLoops must only contain the immediate sibling loops. Any nested
comment|/// loops within them will be visited in postorder as usual for the loop pass
comment|/// manager.
name|void
name|addSiblingLoops
argument_list|(
name|ArrayRef
operator|<
name|Loop
operator|*
operator|>
name|NewSibLoops
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
for|for
control|(
name|Loop
modifier|*
name|NewL
range|:
name|NewSibLoops
control|)
name|assert
argument_list|(
name|NewL
operator|->
name|getParentLoop
argument_list|()
operator|==
name|ParentL
operator|&&
literal|"All of the new loops must be siblings of the current loop!"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|internal
operator|::
name|appendLoopsToWorklist
argument_list|(
name|NewSibLoops
argument_list|,
name|Worklist
argument_list|)
expr_stmt|;
comment|// No need to skip the current loop or revisit it, as sibling loops
comment|// shouldn't impact anything.
block|}
name|private
label|:
name|template
operator|<
name|typename
name|LoopPassT
operator|>
name|friend
name|class
name|llvm
operator|::
name|FunctionToLoopPassAdaptor
expr_stmt|;
comment|/// The \c FunctionToLoopPassAdaptor's worklist of loops to process.
name|SmallPriorityWorklist
operator|<
name|Loop
operator|*
operator|,
literal|4
operator|>
operator|&
name|Worklist
expr_stmt|;
comment|/// The analysis manager for use in the current loop nest.
name|LoopAnalysisManager
modifier|&
name|LAM
decl_stmt|;
name|Loop
modifier|*
name|CurrentL
decl_stmt|;
name|bool
name|SkipCurrentLoop
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// In debug builds we also track the parent loop to implement asserts even in
comment|// the face of loop deletion.
name|Loop
modifier|*
name|ParentL
decl_stmt|;
endif|#
directive|endif
name|LPMUpdater
argument_list|(
name|SmallPriorityWorklist
operator|<
name|Loop
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|Worklist
argument_list|,
name|LoopAnalysisManager
operator|&
name|LAM
argument_list|)
operator|:
name|Worklist
argument_list|(
name|Worklist
argument_list|)
operator|,
name|LAM
argument_list|(
argument|LAM
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Adaptor that maps from a function to its loops.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Designed to allow composition of a LoopPass(Manager) and a
end_comment

begin_comment
comment|/// FunctionPassManager. Note that if this pass is constructed with a \c
end_comment

begin_comment
comment|/// FunctionAnalysisManager it will run the \c LoopAnalysisManagerFunctionProxy
end_comment

begin_comment
comment|/// analysis prior to running the loop passes over the function to enable a \c
end_comment

begin_comment
comment|/// LoopAnalysisManager to be used within this run safely.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|LoopPassT
operator|>
name|class
name|FunctionToLoopPassAdaptor
operator|:
name|public
name|PassInfoMixin
operator|<
name|FunctionToLoopPassAdaptor
operator|<
name|LoopPassT
operator|>>
block|{
name|public
operator|:
name|explicit
name|FunctionToLoopPassAdaptor
argument_list|(
argument|LoopPassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{
name|LoopCanonicalizationFPM
operator|.
name|addPass
argument_list|(
name|LoopSimplifyPass
argument_list|()
argument_list|)
block|;
name|LoopCanonicalizationFPM
operator|.
name|addPass
argument_list|(
name|LCSSAPass
argument_list|()
argument_list|)
block|;   }
comment|/// \brief Runs the loop passes across every loop in the function.
name|PreservedAnalyses
name|run
argument_list|(
argument|Function&F
argument_list|,
argument|FunctionAnalysisManager&AM
argument_list|)
block|{
comment|// Before we even compute any loop analyses, first run a miniature function
comment|// pass pipeline to put loops into their canonical form. Note that we can
comment|// directly build up function analyses after this as the function pass
comment|// manager handles all the invalidation at that layer.
name|PreservedAnalyses
name|PA
operator|=
name|LoopCanonicalizationFPM
operator|.
name|run
argument_list|(
name|F
argument_list|,
name|AM
argument_list|)
block|;
comment|// Get the loop structure for this function
name|LoopInfo
operator|&
name|LI
operator|=
name|AM
operator|.
name|getResult
operator|<
name|LoopAnalysis
operator|>
operator|(
name|F
operator|)
block|;
comment|// If there are no loops, there is nothing to do here.
if|if
condition|(
name|LI
operator|.
name|empty
argument_list|()
condition|)
return|return
name|PA
return|;
comment|// Get the analysis results needed by loop passes.
name|LoopStandardAnalysisResults
name|LAR
operator|=
block|{
name|AM
operator|.
name|getResult
operator|<
name|AAManager
operator|>
operator|(
name|F
operator|)
block|,
name|AM
operator|.
name|getResult
operator|<
name|AssumptionAnalysis
operator|>
operator|(
name|F
operator|)
block|,
name|AM
operator|.
name|getResult
operator|<
name|DominatorTreeAnalysis
operator|>
operator|(
name|F
operator|)
block|,
name|AM
operator|.
name|getResult
operator|<
name|LoopAnalysis
operator|>
operator|(
name|F
operator|)
block|,
name|AM
operator|.
name|getResult
operator|<
name|ScalarEvolutionAnalysis
operator|>
operator|(
name|F
operator|)
block|,
name|AM
operator|.
name|getResult
operator|<
name|TargetLibraryAnalysis
operator|>
operator|(
name|F
operator|)
block|,
name|AM
operator|.
name|getResult
operator|<
name|TargetIRAnalysis
operator|>
operator|(
name|F
operator|)
block|}
block|;
comment|// Setup the loop analysis manager from its proxy. It is important that
comment|// this is only done when there are loops to process and we have built the
comment|// LoopStandardAnalysisResults object. The loop analyses cached in this
comment|// manager have access to those analysis results and so it must invalidate
comment|// itself when they go away.
name|LoopAnalysisManager
operator|&
name|LAM
operator|=
name|AM
operator|.
name|getResult
operator|<
name|LoopAnalysisManagerFunctionProxy
operator|>
operator|(
name|F
operator|)
operator|.
name|getManager
argument_list|()
block|;
comment|// A postorder worklist of loops to process.
name|SmallPriorityWorklist
operator|<
name|Loop
operator|*
block|,
literal|4
operator|>
name|Worklist
block|;
comment|// Register the worklist and loop analysis manager so that loop passes can
comment|// update them when they mutate the loop nest structure.
name|LPMUpdater
name|Updater
argument_list|(
name|Worklist
argument_list|,
name|LAM
argument_list|)
block|;
comment|// Add the loop nests in the reverse order of LoopInfo. For some reason,
comment|// they are stored in RPO w.r.t. the control flow graph in LoopInfo. For
comment|// the purpose of unrolling, loop deletion, and LICM, we largely want to
comment|// work forward across the CFG so that we visit defs before uses and can
comment|// propagate simplifications from one loop nest into the next.
comment|// FIXME: Consider changing the order in LoopInfo.
name|internal
operator|::
name|appendLoopsToWorklist
argument_list|(
name|reverse
argument_list|(
name|LI
argument_list|)
argument_list|,
name|Worklist
argument_list|)
block|;
do|do
block|{
name|Loop
modifier|*
name|L
init|=
name|Worklist
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
comment|// Reset the update structure for this loop.
name|Updater
operator|.
name|CurrentL
operator|=
name|L
expr_stmt|;
name|Updater
operator|.
name|SkipCurrentLoop
operator|=
name|false
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Save a parent loop pointer for asserts.
name|Updater
operator|.
name|ParentL
operator|=
name|L
operator|->
name|getParentLoop
argument_list|()
expr_stmt|;
comment|// Verify the loop structure and LCSSA form before visiting the loop.
name|L
operator|->
name|verifyLoop
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|L
operator|->
name|isRecursivelyLCSSAForm
argument_list|(
name|LAR
operator|.
name|DT
argument_list|,
name|LI
argument_list|)
operator|&&
literal|"Loops must remain in LCSSA form!"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
operator|*
name|L
argument_list|,
name|LAM
argument_list|,
name|LAR
argument_list|,
name|Updater
argument_list|)
decl_stmt|;
comment|// FIXME: We should verify the set of analyses relevant to Loop passes
comment|// are preserved.
comment|// If the loop hasn't been deleted, we need to handle invalidation here.
if|if
condition|(
operator|!
name|Updater
operator|.
name|skipCurrentLoop
argument_list|()
condition|)
comment|// We know that the loop pass couldn't have invalidated any other
comment|// loop's analyses (that's the contract of a loop pass), so directly
comment|// handle the loop analysis manager's invalidation here.
name|LAM
operator|.
name|invalidate
argument_list|(
operator|*
name|L
argument_list|,
name|PassPA
argument_list|)
expr_stmt|;
comment|// Then intersect the preserved set so that invalidation of module
comment|// analyses will eventually occur when the module pass completes.
name|PA
operator|.
name|intersect
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_while
while|while
condition|(
operator|!
name|Worklist
operator|.
name|empty
argument_list|()
condition|)
empty_stmt|;
end_while

begin_comment
comment|// By definition we preserve the proxy. We also preserve all analyses on
end_comment

begin_comment
comment|// Loops. This precludes *any* invalidation of loop analyses by the proxy,
end_comment

begin_comment
comment|// but that's OK because we've taken care to invalidate analyses in the
end_comment

begin_comment
comment|// loop analysis manager incrementally above.
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserveSet
operator|<
name|AllAnalysesOn
operator|<
name|Loop
operator|>>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|LoopAnalysisManagerFunctionProxy
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// We also preserve the set of standard analyses.
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|DominatorTreeAnalysis
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|LoopAnalysis
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|ScalarEvolutionAnalysis
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// FIXME: What we really want to do here is preserve an AA category, but
end_comment

begin_comment
comment|// that concept doesn't exist yet.
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|AAManager
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|BasicAA
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|GlobalsAA
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|SCEVAA
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|PA
return|;
end_return

begin_decl_stmt
unit|}  private:
name|LoopPassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FunctionPassManager
name|LoopCanonicalizationFPM
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief A function to deduce a loop pass type and wrap it in the templated
end_comment

begin_comment
comment|/// adaptor.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|LoopPassT
operator|>
name|FunctionToLoopPassAdaptor
operator|<
name|LoopPassT
operator|>
name|createFunctionToLoopPassAdaptor
argument_list|(
argument|LoopPassT Pass
argument_list|)
block|{
return|return
name|FunctionToLoopPassAdaptor
operator|<
name|LoopPassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Pass for printing a loop's contents as textual IR.
end_comment

begin_decl_stmt
name|class
name|PrintLoopPass
range|:
name|public
name|PassInfoMixin
operator|<
name|PrintLoopPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|std
operator|::
name|string
name|Banner
block|;
name|public
operator|:
name|PrintLoopPass
argument_list|()
block|;
name|PrintLoopPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Loop
operator|&
name|L
argument_list|,
name|LoopAnalysisManager
operator|&
argument_list|,
name|LoopStandardAnalysisResults
operator|&
argument_list|,
name|LPMUpdater
operator|&
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_LOOPPASSMANAGER_H
end_comment

end_unit

