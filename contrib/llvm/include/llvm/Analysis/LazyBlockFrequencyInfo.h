begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyBlockFrequencyInfo.h - Lazy Block Frequency Analysis -*- C++ -*-===//
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
comment|// This is an alternative analysis pass to BlockFrequencyInfoWrapperPass.  The
end_comment

begin_comment
comment|// difference is that with this pass the block frequencies are not computed when
end_comment

begin_comment
comment|// the analysis pass is executed but rather when the BFI result is explicitly
end_comment

begin_comment
comment|// requested by the analysis client.
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
name|LLVM_ANALYSIS_LAZYBLOCKFREQUENCYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LAZYBLOCKFREQUENCYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/BlockFrequencyInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LazyBranchProbabilityInfo.h"
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
name|BranchProbabilityInfo
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
comment|/// Wraps a BFI to allow lazy computation of the block frequencies.
comment|///
comment|/// A pass that only conditionally uses BFI can uncondtionally require the
comment|/// analysis without paying for the overhead if BFI doesn't end up being used.
name|template
operator|<
name|typename
name|FunctionT
operator|,
name|typename
name|BranchProbabilityInfoPassT
operator|,
name|typename
name|LoopInfoT
operator|,
name|typename
name|BlockFrequencyInfoT
operator|>
name|class
name|LazyBlockFrequencyInfo
block|{
name|public
operator|:
name|LazyBlockFrequencyInfo
argument_list|()
operator|:
name|Calculated
argument_list|(
name|false
argument_list|)
block|,
name|F
argument_list|(
name|nullptr
argument_list|)
block|,
name|BPIPass
argument_list|(
name|nullptr
argument_list|)
block|,
name|LI
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// Set up the per-function input.
name|void
name|setAnalysis
argument_list|(
argument|const FunctionT *F
argument_list|,
argument|BranchProbabilityInfoPassT *BPIPass
argument_list|,
argument|const LoopInfoT *LI
argument_list|)
block|{
name|this
operator|->
name|F
operator|=
name|F
block|;
name|this
operator|->
name|BPIPass
operator|=
name|BPIPass
block|;
name|this
operator|->
name|LI
operator|=
name|LI
block|;   }
comment|/// Retrieve the BFI with the block frequencies computed.
name|BlockFrequencyInfoT
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
name|BPIPass
operator|&&
name|LI
operator|&&
literal|"call setAnalysis"
argument_list|)
expr_stmt|;
name|BFI
operator|.
name|calculate
argument_list|(
operator|*
name|F
argument_list|,
name|BPIPassTrait
operator|<
name|BranchProbabilityInfoPassT
operator|>
operator|::
name|getBPI
argument_list|(
name|BPIPass
argument_list|)
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
name|BFI
return|;
block|}
specifier|const
name|BlockFrequencyInfoT
operator|&
name|getCalculated
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|LazyBlockFrequencyInfo
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
name|void
name|releaseMemory
argument_list|()
block|{
name|BFI
operator|.
name|releaseMemory
argument_list|()
block|;
name|Calculated
operator|=
name|false
block|;
name|setAnalysis
argument_list|(
name|nullptr
argument_list|,
name|nullptr
argument_list|,
name|nullptr
argument_list|)
block|;   }
name|private
operator|:
name|BlockFrequencyInfoT
name|BFI
block|;
name|bool
name|Calculated
block|;
specifier|const
name|FunctionT
operator|*
name|F
block|;
name|BranchProbabilityInfoPassT
operator|*
name|BPIPass
block|;
specifier|const
name|LoopInfoT
operator|*
name|LI
block|; }
expr_stmt|;
comment|/// \brief This is an alternative analysis pass to
comment|/// BlockFrequencyInfoWrapperPass.  The difference is that with this pass the
comment|/// block frequencies are not computed when the analysis pass is executed but
comment|/// rather when the BFI result is explicitly requested by the analysis client.
comment|///
comment|/// There are some additional requirements for any client pass that wants to use
comment|/// the analysis:
comment|///
comment|/// 1. The pass needs to initialize dependent passes with:
comment|///
comment|///   INITIALIZE_PASS_DEPENDENCY(LazyBFIPass)
comment|///
comment|/// 2. Similarly, getAnalysisUsage should call:
comment|///
comment|///   LazyBlockFrequencyInfoPass::getLazyBFIAnalysisUsage(AU)
comment|///
comment|/// 3. The computed BFI should be requested with
comment|///    getAnalysis<LazyBlockFrequencyInfoPass>().getBFI() before either LoopInfo
comment|///    or BPI could be invalidated for example by changing the CFG.
comment|///
comment|/// Note that it is expected that we wouldn't need this functionality for the
comment|/// new PM since with the new PM, analyses are executed on demand.
name|class
name|LazyBlockFrequencyInfoPass
range|:
name|public
name|FunctionPass
block|{
name|private
operator|:
name|LazyBlockFrequencyInfo
operator|<
name|Function
block|,
name|LazyBranchProbabilityInfoPass
block|,
name|LoopInfo
block|,
name|BlockFrequencyInfo
operator|>
name|LBFI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|LazyBlockFrequencyInfoPass
argument_list|()
block|;
comment|/// \brief Compute and return the block frequencies.
name|BlockFrequencyInfo
operator|&
name|getBFI
argument_list|()
block|{
return|return
name|LBFI
operator|.
name|getCalculated
argument_list|()
return|;
block|}
comment|/// \brief Compute and return the block frequencies.
specifier|const
name|BlockFrequencyInfo
operator|&
name|getBFI
argument_list|()
specifier|const
block|{
return|return
name|LBFI
operator|.
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
name|getLazyBFIAnalysisUsage
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
comment|/// \brief Helper for client passes to initialize dependent passes for LBFI.
name|void
name|initializeLazyBFIPassPass
parameter_list|(
name|PassRegistry
modifier|&
name|Registry
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

