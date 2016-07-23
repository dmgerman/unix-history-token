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
comment|/// This header provides classes for managing passes over loops in LLVM IR.
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
name|LLVM_ANALYSIS_LOOPPASSMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPPASSMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
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
extern|extern template class PassManager<Loop>;
comment|/// \brief The loop pass manager.
comment|///
comment|/// See the documentation for the PassManager template for details. It runs a
comment|/// sequency of loop passes over each loop that the manager is run over. This
comment|/// typedef serves as a convenient way to refer to this construct.
typedef|typedef
name|PassManager
operator|<
name|Loop
operator|>
name|LoopPassManager
expr_stmt|;
extern|extern template class AnalysisManager<Loop>;
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
operator|>
name|LoopAnalysisManager
expr_stmt|;
extern|extern template class InnerAnalysisManagerProxy<LoopAnalysisManager
operator|,
extern|Function>;
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
extern|extern template class OuterAnalysisManagerProxy<FunctionAnalysisManager
operator|,
extern|Loop>;
comment|/// A proxy from a \c FunctionAnalysisManager to a \c Loop.
typedef|typedef
name|OuterAnalysisManagerProxy
operator|<
name|FunctionAnalysisManager
operator|,
name|Loop
operator|>
name|FunctionAnalysisManagerLoopProxy
expr_stmt|;
comment|/// Returns the minimum set of Analyses that all loop passes must preserve.
name|PreservedAnalyses
name|getLoopPassPreservedAnalyses
parameter_list|()
function_decl|;
comment|/// \brief Adaptor that maps from a function to its loops.
comment|///
comment|/// Designed to allow composition of a LoopPass(Manager) and a
comment|/// FunctionPassManager. Note that if this pass is constructed with a \c
comment|/// FunctionAnalysisManager it will run the \c LoopAnalysisManagerFunctionProxy
comment|/// analysis prior to running the loop passes over the function to enable a \c
comment|/// LoopAnalysisManager to be used within this run safely.
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
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|FunctionToLoopPassAdaptor
argument_list|(
specifier|const
name|FunctionToLoopPassAdaptor
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|FunctionToLoopPassAdaptor
argument_list|(
name|FunctionToLoopPassAdaptor
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|FunctionToLoopPassAdaptor&LHS
argument_list|,
argument|FunctionToLoopPassAdaptor&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|FunctionToLoopPassAdaptor
operator|&
name|operator
operator|=
operator|(
name|FunctionToLoopPassAdaptor
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Runs the loop passes across every loop in the function.
name|PreservedAnalyses
name|run
argument_list|(
argument|Function&F
argument_list|,
argument|FunctionAnalysisManager&AM
argument_list|)
block|{
comment|// Setup the loop analysis manager from its proxy.
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
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
comment|// We want to visit the loops in reverse post-order. We'll build the stack
comment|// of loops to visit in Loops by first walking the loops in pre-order.
name|SmallVector
operator|<
name|Loop
operator|*
block|,
literal|2
operator|>
name|Loops
block|;
name|SmallVector
operator|<
name|Loop
operator|*
block|,
literal|2
operator|>
name|WorkList
argument_list|(
name|LI
operator|.
name|begin
argument_list|()
argument_list|,
name|LI
operator|.
name|end
argument_list|()
argument_list|)
block|;
while|while
condition|(
operator|!
name|WorkList
operator|.
name|empty
argument_list|()
condition|)
block|{
name|Loop
modifier|*
name|L
init|=
name|WorkList
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
name|WorkList
operator|.
name|insert
argument_list|(
name|WorkList
operator|.
name|end
argument_list|()
argument_list|,
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
name|Loops
operator|.
name|push_back
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
comment|// Now pop each element off of the stack to visit the loops in reverse
comment|// post-order.
for|for
control|(
name|auto
operator|*
name|L
operator|:
name|reverse
argument_list|(
name|Loops
argument_list|)
control|)
block|{
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
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|PassPA
operator|.
name|preserved
argument_list|(
name|getLoopPassPreservedAnalyses
argument_list|()
argument_list|)
operator|&&
literal|"Loop passes must preserve all relevant analyses"
argument_list|)
expr_stmt|;
comment|// We know that the loop pass couldn't have invalidated any other loop's
comment|// analyses (that's the contract of a loop pass), so directly handle the
comment|// loop analysis manager's invalidation here.  Also, update the
comment|// preserved analyses to reflect that once invalidated these can again
comment|// be preserved.
name|PassPA
operator|=
name|LAM
operator|.
name|invalidate
argument_list|(
operator|*
name|L
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
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
comment|// By definition we preserve the proxy. This precludes *any* invalidation of
comment|// loop analyses by the proxy, but that's OK because we've taken care to
comment|// invalidate analyses in the loop analysis manager incrementally above.
name|PA
operator|.
name|preserve
operator|<
name|LoopAnalysisManagerFunctionProxy
operator|>
operator|(
operator|)
expr_stmt|;
return|return
name|PA
return|;
block|}
name|private
label|:
name|LoopPassT
name|Pass
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ANALYSIS_LOOPPASSMANAGER_H
end_comment

end_unit

