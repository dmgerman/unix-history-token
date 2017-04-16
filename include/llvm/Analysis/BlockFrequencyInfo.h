begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BlockFrequencyInfo.h - Block Frequency Analysis ----------*- C++ -*-===//
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
comment|// Loops should be simplified before this analysis.
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
name|LLVM_ANALYSIS_BLOCKFREQUENCYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_BLOCKFREQUENCYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BlockFrequency.h"
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BranchProbabilityInfo
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|template
operator|<
name|class
name|BlockT
operator|>
name|class
name|BlockFrequencyInfoImpl
expr_stmt|;
comment|/// BlockFrequencyInfo pass uses BlockFrequencyInfoImpl implementation to
comment|/// estimate IR basic block frequencies.
name|class
name|BlockFrequencyInfo
block|{
typedef|typedef
name|BlockFrequencyInfoImpl
operator|<
name|BasicBlock
operator|>
name|ImplType
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ImplType
operator|>
name|BFI
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|BlockFrequencyInfo
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|BlockFrequencyInfo
argument_list|(
specifier|const
name|BlockFrequencyInfo
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|public
label|:
name|BlockFrequencyInfo
argument_list|()
expr_stmt|;
name|BlockFrequencyInfo
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|BranchProbabilityInfo
operator|&
name|BPI
argument_list|,
specifier|const
name|LoopInfo
operator|&
name|LI
argument_list|)
expr_stmt|;
name|BlockFrequencyInfo
argument_list|(
name|BlockFrequencyInfo
operator|&&
name|Arg
argument_list|)
expr_stmt|;
name|BlockFrequencyInfo
modifier|&
name|operator
init|=
operator|(
name|BlockFrequencyInfo
operator|&&
name|RHS
operator|)
decl_stmt|;
operator|~
name|BlockFrequencyInfo
argument_list|()
expr_stmt|;
comment|/// Handle invalidation explicitly.
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
argument_list|)
decl_stmt|;
specifier|const
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|BranchProbabilityInfo
operator|*
name|getBPI
argument_list|()
specifier|const
expr_stmt|;
name|void
name|view
argument_list|()
specifier|const
expr_stmt|;
comment|/// getblockFreq - Return block frequency. Return 0 if we don't have the
comment|/// information. Please note that initial frequency is equal to ENTRY_FREQ. It
comment|/// means that we should not rely on the value itself, but only on the
comment|/// comparison to the other block frequencies. We do this to avoid using of
comment|/// floating points.
name|BlockFrequency
name|getBlockFreq
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the estimated profile count of \p BB.
comment|/// This computes the relative block frequency of \p BB and multiplies it by
comment|/// the enclosing function's count (if available) and returns the value.
name|Optional
operator|<
name|uint64_t
operator|>
name|getBlockProfileCount
argument_list|(
argument|const BasicBlock *BB
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Returns the estimated profile count of \p Freq.
comment|/// This uses the frequency \p Freq and multiplies it by
comment|/// the enclosing function's count (if available) and returns the value.
name|Optional
operator|<
name|uint64_t
operator|>
name|getProfileCountFromFreq
argument_list|(
argument|uint64_t Freq
argument_list|)
specifier|const
expr_stmt|;
comment|// Set the frequency of the given basic block.
name|void
name|setBlockFreq
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|uint64_t
name|Freq
parameter_list|)
function_decl|;
comment|/// Set the frequency of \p ReferenceBB to \p Freq and scale the frequencies
comment|/// of the blocks in \p BlocksToScale such that their frequencies relative
comment|/// to \p ReferenceBB remain unchanged.
name|void
name|setBlockFreqAndScale
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|ReferenceBB
argument_list|,
name|uint64_t
name|Freq
argument_list|,
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|BlocksToScale
argument_list|)
decl_stmt|;
comment|/// calculate - compute block frequency info for the given function.
name|void
name|calculate
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
specifier|const
name|BranchProbabilityInfo
modifier|&
name|BPI
parameter_list|,
specifier|const
name|LoopInfo
modifier|&
name|LI
parameter_list|)
function_decl|;
comment|// Print the block frequency Freq to OS using the current functions entry
comment|// frequency to convert freq into a relative decimal form.
name|raw_ostream
modifier|&
name|printBlockFreq
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|BlockFrequency
name|Freq
argument_list|)
decl|const
decl_stmt|;
comment|// Convenience method that attempts to look up the frequency associated with
comment|// BB and print it to OS.
name|raw_ostream
modifier|&
name|printBlockFreq
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getEntryFreq
argument_list|()
specifier|const
expr_stmt|;
name|void
name|releaseMemory
parameter_list|()
function_decl|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Analysis pass which computes \c BlockFrequencyInfo.
name|class
name|BlockFrequencyAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|BlockFrequencyAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|BlockFrequencyAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// \brief Provide the result typedef for this analysis pass.
typedef|typedef
name|BlockFrequencyInfo
name|Result
typedef|;
comment|/// \brief Run the analysis pass over a function and produce BFI.
name|Result
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
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Printer pass for the \c BlockFrequencyInfo results.
end_comment

begin_decl_stmt
name|class
name|BlockFrequencyPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|BlockFrequencyPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|BlockFrequencyPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
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
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Legacy analysis pass which computes \c BlockFrequencyInfo.
end_comment

begin_decl_stmt
name|class
name|BlockFrequencyInfoWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|BlockFrequencyInfo
name|BFI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|BlockFrequencyInfoWrapperPass
argument_list|()
block|;
operator|~
name|BlockFrequencyInfoWrapperPass
argument_list|()
name|override
block|;
name|BlockFrequencyInfo
operator|&
name|getBFI
argument_list|()
block|{
return|return
name|BFI
return|;
block|}
specifier|const
name|BlockFrequencyInfo
operator|&
name|getBFI
argument_list|()
specifier|const
block|{
return|return
name|BFI
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
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

