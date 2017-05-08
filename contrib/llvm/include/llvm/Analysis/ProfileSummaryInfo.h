begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/ProfileSummaryInfo.h - profile summary ---*- C++ -*-===//
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
comment|// This file contains a pass that provides access to profile summary
end_comment

begin_comment
comment|// information.
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
name|LLVM_ANALYSIS_PROFILE_SUMMARY_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PROFILE_SUMMARY_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ProfileSummary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|BlockFrequencyInfo
decl_stmt|;
name|class
name|CallSite
decl_stmt|;
name|class
name|ProfileSummary
decl_stmt|;
comment|/// \brief Analysis providing profile information.
comment|///
comment|/// This is an immutable analysis pass that provides ability to query global
comment|/// (program-level) profile information. The main APIs are isHotCount and
comment|/// isColdCount that tells whether a given profile count is considered hot/cold
comment|/// based on the profile summary. This also provides convenience methods to
comment|/// check whether a function is hot or cold.
comment|// FIXME: Provide convenience methods to determine hotness/coldness of other IR
comment|// units. This would require making this depend on BFI.
name|class
name|ProfileSummaryInfo
block|{
name|private
label|:
name|Module
modifier|&
name|M
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ProfileSummary
operator|>
name|Summary
expr_stmt|;
name|bool
name|computeSummary
parameter_list|()
function_decl|;
name|void
name|computeThresholds
parameter_list|()
function_decl|;
comment|// Count thresholds to answer isHotCount and isColdCount queries.
name|Optional
operator|<
name|uint64_t
operator|>
name|HotCountThreshold
operator|,
name|ColdCountThreshold
expr_stmt|;
name|public
label|:
name|ProfileSummaryInfo
argument_list|(
name|Module
operator|&
name|M
argument_list|)
operator|:
name|M
argument_list|(
argument|M
argument_list|)
block|{}
name|ProfileSummaryInfo
argument_list|(
name|ProfileSummaryInfo
operator|&&
name|Arg
argument_list|)
operator|:
name|M
argument_list|(
name|Arg
operator|.
name|M
argument_list|)
operator|,
name|Summary
argument_list|(
argument|std::move(Arg.Summary)
argument_list|)
block|{}
comment|/// Handle the invalidation of this information.
comment|///
comment|/// When used as a result of \c ProfileSummaryAnalysis this method will be
comment|/// called when the module this was computed for changes. Since profile
comment|/// summary is immutable after it is annotated on the module, we return false
comment|/// here.
name|bool
name|invalidate
argument_list|(
argument|Module&
argument_list|,
argument|const PreservedAnalyses&
argument_list|,
argument|ModuleAnalysisManager::Invalidator&
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Returns the profile count for \p CallInst.
specifier|static
name|Optional
operator|<
name|uint64_t
operator|>
name|getProfileCount
argument_list|(
specifier|const
name|Instruction
operator|*
name|CallInst
argument_list|,
name|BlockFrequencyInfo
operator|*
name|BFI
argument_list|)
expr_stmt|;
comment|/// \brief Returns true if \p F has hot function entry.
name|bool
name|isFunctionEntryHot
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// Returns true if \p F has hot function entry or hot call edge.
name|bool
name|isFunctionHotInCallGraph
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// \brief Returns true if \p F has cold function entry.
name|bool
name|isFunctionEntryCold
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// Returns true if \p F has cold function entry or cold call edge.
name|bool
name|isFunctionColdInCallGraph
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// \brief Returns true if \p F is a hot function.
name|bool
name|isHotCount
parameter_list|(
name|uint64_t
name|C
parameter_list|)
function_decl|;
comment|/// \brief Returns true if count \p C is considered cold.
name|bool
name|isColdCount
parameter_list|(
name|uint64_t
name|C
parameter_list|)
function_decl|;
comment|/// \brief Returns true if BasicBlock \p B is considered hot.
name|bool
name|isHotBB
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|B
parameter_list|,
name|BlockFrequencyInfo
modifier|*
name|BFI
parameter_list|)
function_decl|;
comment|/// \brief Returns true if BasicBlock \p B is considered cold.
name|bool
name|isColdBB
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|B
parameter_list|,
name|BlockFrequencyInfo
modifier|*
name|BFI
parameter_list|)
function_decl|;
comment|/// \brief Returns true if CallSite \p CS is considered hot.
name|bool
name|isHotCallSite
parameter_list|(
specifier|const
name|CallSite
modifier|&
name|CS
parameter_list|,
name|BlockFrequencyInfo
modifier|*
name|BFI
parameter_list|)
function_decl|;
comment|/// \brief Returns true if Callsite \p CS is considered cold.
name|bool
name|isColdCallSite
parameter_list|(
specifier|const
name|CallSite
modifier|&
name|CS
parameter_list|,
name|BlockFrequencyInfo
modifier|*
name|BFI
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// An analysis pass based on legacy pass manager to deliver ProfileSummaryInfo.
name|class
name|ProfileSummaryInfoWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ProfileSummaryInfo
operator|>
name|PSI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|ProfileSummaryInfoWrapperPass
argument_list|()
block|;
name|ProfileSummaryInfo
operator|*
name|getPSI
argument_list|()
block|{
return|return
operator|&
operator|*
name|PSI
return|;
block|}
name|bool
name|doInitialization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|bool
name|doFinalization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
block|}
decl_stmt|;
comment|/// An analysis pass based on the new PM to deliver ProfileSummaryInfo.
name|class
name|ProfileSummaryAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|ProfileSummaryAnalysis
operator|>
block|{
name|public
operator|:
typedef|typedef
name|ProfileSummaryInfo
name|Result
typedef|;
name|Result
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|AnalysisInfoMixin
operator|<
name|ProfileSummaryAnalysis
operator|>
expr_stmt|;
specifier|static
name|AnalysisKey
name|Key
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Printer pass that uses \c ProfileSummaryAnalysis.
end_comment

begin_decl_stmt
name|class
name|ProfileSummaryPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|ProfileSummaryPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|ProfileSummaryPrinterPass
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
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

