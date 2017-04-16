begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyBranchProbabilityInfo.h - Lazy Branch Probability ----*- C++ -*-===//
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
comment|// This is an alternative analysis pass to BranchProbabilityInfoWrapperPass.
end_comment

begin_comment
comment|// The difference is that with this pass the branch probabilities are not
end_comment

begin_comment
comment|// computed when the analysis pass is executed but rather when the BPI results
end_comment

begin_comment
comment|// is explicitly requested by the analysis client.
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
name|LLVM_ANALYSIS_LAZYBRANCHPROBABILITYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LAZYBRANCHPROBABILITYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/BranchProbabilityInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
comment|/// \brief This is an alternative analysis pass to
comment|/// BranchProbabilityInfoWrapperPass.  The difference is that with this pass the
comment|/// branch probabilities are not computed when the analysis pass is executed but
comment|/// rather when the BPI results is explicitly requested by the analysis client.
comment|///
comment|/// There are some additional requirements for any client pass that wants to use
comment|/// the analysis:
comment|///
comment|/// 1. The pass needs to initialize dependent passes with:
comment|///
comment|///   INITIALIZE_PASS_DEPENDENCY(LazyBPIPass)
comment|///
comment|/// 2. Similarly, getAnalysisUsage should call:
comment|///
comment|///   LazyBranchProbabilityInfoPass::getLazyBPIAnalysisUsage(AU)
comment|///
comment|/// 3. The computed BPI should be requested with
comment|///    getAnalysis<LazyBranchProbabilityInfoPass>().getBPI() before LoopInfo
comment|///    could be invalidated for example by changing the CFG.
comment|///
comment|/// Note that it is expected that we wouldn't need this functionality for the
comment|/// new PM since with the new PM, analyses are executed on demand.
name|class
name|LazyBranchProbabilityInfoPass
range|:
name|public
name|FunctionPass
block|{
comment|/// Wraps a BPI to allow lazy computation of the branch probabilities.
comment|///
comment|/// A pass that only conditionally uses BPI can uncondtionally require the
comment|/// analysis without paying for the overhead if BPI doesn't end up being used.
name|class
name|LazyBranchProbabilityInfo
block|{
name|public
operator|:
name|LazyBranchProbabilityInfo
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
specifier|const
name|LoopInfo
operator|*
name|LI
argument_list|)
operator|:
name|Calculated
argument_list|(
name|false
argument_list|)
block|,
name|F
argument_list|(
name|F
argument_list|)
block|,
name|LI
argument_list|(
argument|LI
argument_list|)
block|{}
comment|/// Retrieve the BPI with the branch probabilities computed.
name|BranchProbabilityInfo
operator|&
name|getCalculated
argument_list|()
block|{
if|if
condition|(
operator|!
name|Calculated
condition|)
block|{
name|assert
argument_list|(
name|F
operator|&&
name|LI
operator|&&
literal|"call setAnalysis"
argument_list|)
expr_stmt|;
name|BPI
operator|.
name|calculate
argument_list|(
operator|*
name|F
argument_list|,
operator|*
name|LI
argument_list|)
expr_stmt|;
name|Calculated
operator|=
name|true
expr_stmt|;
block|}
return|return
name|BPI
return|;
block|}
specifier|const
name|BranchProbabilityInfo
operator|&
name|getCalculated
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|LazyBranchProbabilityInfo
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCalculated
argument_list|()
return|;
block|}
name|private
operator|:
name|BranchProbabilityInfo
name|BPI
block|;
name|bool
name|Calculated
block|;
specifier|const
name|Function
operator|*
name|F
block|;
specifier|const
name|LoopInfo
operator|*
name|LI
block|;   }
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|LazyBranchProbabilityInfo
operator|>
name|LBPI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|LazyBranchProbabilityInfoPass
argument_list|()
block|;
comment|/// \brief Compute and return the branch probabilities.
name|BranchProbabilityInfo
operator|&
name|getBPI
argument_list|()
block|{
return|return
name|LBPI
operator|->
name|getCalculated
argument_list|()
return|;
block|}
comment|/// \brief Compute and return the branch probabilities.
specifier|const
name|BranchProbabilityInfo
operator|&
name|getBPI
argument_list|()
specifier|const
block|{
return|return
name|LBPI
operator|->
name|getCalculated
argument_list|()
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
comment|/// Helper for client passes to set up the analysis usage on behalf of this
comment|/// pass.
specifier|static
name|void
name|getLazyBPIAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// \brief Helper for client passes to initialize dependent passes for LBPI.
name|void
name|initializeLazyBPIPassPass
parameter_list|(
name|PassRegistry
modifier|&
name|Registry
parameter_list|)
function_decl|;
comment|/// \brief Simple trait class that provides a mapping between BPI passes and the
comment|/// corresponding BPInfo.
name|template
operator|<
name|typename
name|PassT
operator|>
expr|struct
name|BPIPassTrait
block|{
specifier|static
name|PassT
operator|&
name|getBPI
argument_list|(
argument|PassT *P
argument_list|)
block|{
return|return
operator|*
name|P
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|BPIPassTrait
operator|<
name|LazyBranchProbabilityInfoPass
operator|>
block|{
specifier|static
name|BranchProbabilityInfo
operator|&
name|getBPI
argument_list|(
argument|LazyBranchProbabilityInfoPass *P
argument_list|)
block|{
return|return
name|P
operator|->
name|getBPI
argument_list|()
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

