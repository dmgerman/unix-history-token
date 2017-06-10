begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InlineCost.h - Cost analysis for inliner -----------------*- C++ -*-===//
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
comment|// This file implements heuristics for inlining decisions.
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
name|LLVM_ANALYSIS_INLINECOST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_INLINECOST_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CallGraphSCCPass.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|AssumptionCacheTracker
decl_stmt|;
name|class
name|BlockFrequencyInfo
decl_stmt|;
name|class
name|CallSite
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|ProfileSummaryInfo
decl_stmt|;
name|class
name|TargetTransformInfo
decl_stmt|;
name|namespace
name|InlineConstants
block|{
comment|// Various thresholds used by inline cost analysis.
comment|/// Use when optsize (-Os) is specified.
specifier|const
name|int
name|OptSizeThreshold
init|=
literal|50
decl_stmt|;
comment|/// Use when minsize (-Oz) is specified.
specifier|const
name|int
name|OptMinSizeThreshold
init|=
literal|5
decl_stmt|;
comment|/// Use when -O3 is specified.
specifier|const
name|int
name|OptAggressiveThreshold
init|=
literal|250
decl_stmt|;
comment|// Various magic constants used to adjust heuristics.
specifier|const
name|int
name|InstrCost
init|=
literal|5
decl_stmt|;
specifier|const
name|int
name|IndirectCallThreshold
init|=
literal|100
decl_stmt|;
specifier|const
name|int
name|CallPenalty
init|=
literal|25
decl_stmt|;
specifier|const
name|int
name|LastCallToStaticBonus
init|=
literal|15000
decl_stmt|;
specifier|const
name|int
name|ColdccPenalty
init|=
literal|2000
decl_stmt|;
specifier|const
name|int
name|NoreturnPenalty
init|=
literal|10000
decl_stmt|;
comment|/// Do not inline functions which allocate this many bytes on the stack
comment|/// when the caller is recursive.
specifier|const
name|unsigned
name|TotalAllocaSizeRecursiveCaller
init|=
literal|1024
decl_stmt|;
block|}
comment|/// \brief Represents the cost of inlining a function.
comment|///
comment|/// This supports special values for functions which should "always" or
comment|/// "never" be inlined. Otherwise, the cost represents a unitless amount;
comment|/// smaller values increase the likelihood of the function being inlined.
comment|///
comment|/// Objects of this type also provide the adjusted threshold for inlining
comment|/// based on the information available for a particular callsite. They can be
comment|/// directly tested to determine if inlining should occur given the cost and
comment|/// threshold for this cost metric.
name|class
name|InlineCost
block|{
enum|enum
name|SentinelValues
block|{
name|AlwaysInlineCost
init|=
name|INT_MIN
block|,
name|NeverInlineCost
init|=
name|INT_MAX
block|}
enum|;
comment|/// \brief The estimated cost of inlining this callsite.
specifier|const
name|int
name|Cost
decl_stmt|;
comment|/// \brief The adjusted threshold against which this cost was computed.
specifier|const
name|int
name|Threshold
decl_stmt|;
comment|// Trivial constructor, interesting logic in the factory functions below.
name|InlineCost
argument_list|(
argument|int Cost
argument_list|,
argument|int Threshold
argument_list|)
block|:
name|Cost
argument_list|(
name|Cost
argument_list|)
operator|,
name|Threshold
argument_list|(
argument|Threshold
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|InlineCost
name|get
argument_list|(
argument|int Cost
argument_list|,
argument|int Threshold
argument_list|)
block|{
name|assert
argument_list|(
name|Cost
operator|>
name|AlwaysInlineCost
operator|&&
literal|"Cost crosses sentinel value"
argument_list|)
block|;
name|assert
argument_list|(
name|Cost
operator|<
name|NeverInlineCost
operator|&&
literal|"Cost crosses sentinel value"
argument_list|)
block|;
return|return
name|InlineCost
argument_list|(
name|Cost
argument_list|,
name|Threshold
argument_list|)
return|;
block|}
specifier|static
name|InlineCost
name|getAlways
parameter_list|()
block|{
return|return
name|InlineCost
argument_list|(
name|AlwaysInlineCost
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|InlineCost
name|getNever
parameter_list|()
block|{
return|return
name|InlineCost
argument_list|(
name|NeverInlineCost
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// \brief Test whether the inline cost is low enough for inlining.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Cost
operator|<
name|Threshold
return|;
block|}
name|bool
name|isAlways
argument_list|()
specifier|const
block|{
return|return
name|Cost
operator|==
name|AlwaysInlineCost
return|;
block|}
name|bool
name|isNever
argument_list|()
specifier|const
block|{
return|return
name|Cost
operator|==
name|NeverInlineCost
return|;
block|}
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isAlways
argument_list|()
operator|&&
operator|!
name|isNever
argument_list|()
return|;
block|}
comment|/// \brief Get the inline cost estimate.
comment|/// It is an error to call this on an "always" or "never" InlineCost.
name|int
name|getCost
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isVariable
argument_list|()
operator|&&
literal|"Invalid access of InlineCost"
argument_list|)
block|;
return|return
name|Cost
return|;
block|}
comment|/// \brief Get the cost delta from the threshold for inlining.
comment|/// Only valid if the cost is of the variable kind. Returns a negative
comment|/// value if the cost is too high to inline.
name|int
name|getCostDelta
argument_list|()
specifier|const
block|{
return|return
name|Threshold
operator|-
name|getCost
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// Thresholds to tune inline cost analysis. The inline cost analysis decides
comment|/// the condition to apply a threshold and applies it. Otherwise,
comment|/// DefaultThreshold is used. If a threshold is Optional, it is applied only
comment|/// when it has a valid value. Typically, users of inline cost analysis
comment|/// obtain an InlineParams object through one of the \c getInlineParams methods
comment|/// and pass it to \c getInlineCost. Some specialized versions of inliner
comment|/// (such as the pre-inliner) might have custom logic to compute \c InlineParams
comment|/// object.
struct|struct
name|InlineParams
block|{
comment|/// The default threshold to start with for a callee.
name|int
name|DefaultThreshold
decl_stmt|;
comment|/// Threshold to use for callees with inline hint.
name|Optional
operator|<
name|int
operator|>
name|HintThreshold
expr_stmt|;
comment|/// Threshold to use for cold callees.
name|Optional
operator|<
name|int
operator|>
name|ColdThreshold
expr_stmt|;
comment|/// Threshold to use when the caller is optimized for size.
name|Optional
operator|<
name|int
operator|>
name|OptSizeThreshold
expr_stmt|;
comment|/// Threshold to use when the caller is optimized for minsize.
name|Optional
operator|<
name|int
operator|>
name|OptMinSizeThreshold
expr_stmt|;
comment|/// Threshold to use when the callsite is considered hot.
name|Optional
operator|<
name|int
operator|>
name|HotCallSiteThreshold
expr_stmt|;
comment|/// Threshold to use when the callsite is considered cold.
name|Optional
operator|<
name|int
operator|>
name|ColdCallSiteThreshold
expr_stmt|;
block|}
struct|;
comment|/// Generate the parameters to tune the inline cost analysis based only on the
comment|/// commandline options.
name|InlineParams
name|getInlineParams
parameter_list|()
function_decl|;
comment|/// Generate the parameters to tune the inline cost analysis based on command
comment|/// line options. If -inline-threshold option is not explicitly passed,
comment|/// \p Threshold is used as the default threshold.
name|InlineParams
name|getInlineParams
parameter_list|(
name|int
name|Threshold
parameter_list|)
function_decl|;
comment|/// Generate the parameters to tune the inline cost analysis based on command
comment|/// line options. If -inline-threshold option is not explicitly passed,
comment|/// the default threshold is computed from \p OptLevel and \p SizeOptLevel.
comment|/// An \p OptLevel value above 3 is considered an aggressive optimization mode.
comment|/// \p SizeOptLevel of 1 corresponds to the the -Os flag and 2 corresponds to
comment|/// the -Oz flag.
name|InlineParams
name|getInlineParams
parameter_list|(
name|unsigned
name|OptLevel
parameter_list|,
name|unsigned
name|SizeOptLevel
parameter_list|)
function_decl|;
comment|/// Return the cost associated with a callsite, including paramater passing
comment|/// and the call/return instruction.
name|int
name|getCallsiteCost
parameter_list|(
name|CallSite
name|CS
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|/// \brief Get an InlineCost object representing the cost of inlining this
comment|/// callsite.
comment|///
comment|/// Note that a default threshold is passed into this function. This threshold
comment|/// could be modified based on callsite's properties and only costs below this
comment|/// new threshold are computed with any accuracy. The new threshold can be
comment|/// used to bound the computation necessary to determine whether the cost is
comment|/// sufficiently low to warrant inlining.
comment|///
comment|/// Also note that calling this function *dynamically* computes the cost of
comment|/// inlining the callsite. It is an expensive, heavyweight call.
name|InlineCost
name|getInlineCost
argument_list|(
name|CallSite
name|CS
argument_list|,
specifier|const
name|InlineParams
operator|&
name|Params
argument_list|,
name|TargetTransformInfo
operator|&
name|CalleeTTI
argument_list|,
name|std
operator|::
name|function
operator|<
name|AssumptionCache
operator|&
operator|(
name|Function
operator|&
operator|)
operator|>
operator|&
name|GetAssumptionCache
argument_list|,
name|Optional
operator|<
name|function_ref
operator|<
name|BlockFrequencyInfo
operator|&
operator|(
name|Function
operator|&
operator|)
operator|>>
name|GetBFI
argument_list|,
name|ProfileSummaryInfo
operator|*
name|PSI
argument_list|)
decl_stmt|;
comment|/// \brief Get an InlineCost with the callee explicitly specified.
comment|/// This allows you to calculate the cost of inlining a function via a
comment|/// pointer. This behaves exactly as the version with no explicit callee
comment|/// parameter in all other respects.
comment|//
name|InlineCost
name|getInlineCost
argument_list|(
name|CallSite
name|CS
argument_list|,
name|Function
operator|*
name|Callee
argument_list|,
specifier|const
name|InlineParams
operator|&
name|Params
argument_list|,
name|TargetTransformInfo
operator|&
name|CalleeTTI
argument_list|,
name|std
operator|::
name|function
operator|<
name|AssumptionCache
operator|&
operator|(
name|Function
operator|&
operator|)
operator|>
operator|&
name|GetAssumptionCache
argument_list|,
name|Optional
operator|<
name|function_ref
operator|<
name|BlockFrequencyInfo
operator|&
operator|(
name|Function
operator|&
operator|)
operator|>>
name|GetBFI
argument_list|,
name|ProfileSummaryInfo
operator|*
name|PSI
argument_list|)
decl_stmt|;
comment|/// \brief Minimal filter to detect invalid constructs for inlining.
name|bool
name|isInlineViable
parameter_list|(
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

