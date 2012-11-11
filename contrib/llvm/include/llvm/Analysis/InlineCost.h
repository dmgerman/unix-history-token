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
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CodeMetrics.h"
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

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallSite
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|namespace
name|InlineConstants
block|{
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
operator|-
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
comment|/// InlineCostAnalyzer - Cost analyzer used by inliner.
name|class
name|InlineCostAnalyzer
block|{
comment|// TargetData if available, or null.
specifier|const
name|TargetData
modifier|*
name|TD
decl_stmt|;
name|public
label|:
name|InlineCostAnalyzer
argument_list|()
operator|:
name|TD
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setTargetData
argument_list|(
argument|const TargetData *TData
argument_list|)
block|{
name|TD
operator|=
name|TData
block|; }
comment|/// \brief Get an InlineCost object representing the cost of inlining this
comment|/// callsite.
comment|///
comment|/// Note that threshold is passed into this function. Only costs below the
comment|/// threshold are computed with any accuracy. The threshold can be used to
comment|/// bound the computation necessary to determine whether the cost is
comment|/// sufficiently low to warrant inlining.
name|InlineCost
name|getInlineCost
argument_list|(
argument|CallSite CS
argument_list|,
argument|int Threshold
argument_list|)
expr_stmt|;
comment|/// getCalledFunction - The heuristic used to determine if we should inline
comment|/// the function call or not.  The callee is explicitly specified, to allow
comment|/// you to calculate the cost of inlining a function via a pointer.  This
comment|/// behaves exactly as the version with no explicit callee parameter in all
comment|/// other respects.
comment|//
comment|//  Note: This is used by out-of-tree passes, please do not remove without
comment|//  adding a replacement API.
name|InlineCost
name|getInlineCost
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|Function
modifier|*
name|Callee
parameter_list|,
name|int
name|Threshold
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

