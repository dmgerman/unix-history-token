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

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|CallSite
decl_stmt|;
name|template
operator|<
name|class
name|PtrType
operator|,
name|unsigned
name|SmallSize
operator|>
name|class
name|SmallPtrSet
expr_stmt|;
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
name|IndirectCallBonus
init|=
operator|-
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
comment|/// InlineCost - Represent the cost of inlining a function. This
comment|/// supports special values for functions which should "always" or
comment|/// "never" be inlined. Otherwise, the cost represents a unitless
comment|/// amount; smaller values increase the likelyhood of the function
comment|/// being inlined.
name|class
name|InlineCost
block|{
enum|enum
name|Kind
block|{
name|Value
block|,
name|Always
block|,
name|Never
block|}
enum|;
comment|// This is a do-it-yourself implementation of
comment|//   int Cost : 30;
comment|//   unsigned Type : 2;
comment|// We used to use bitfields, but they were sometimes miscompiled (PR3822).
enum|enum
block|{
name|TYPE_BITS
init|=
literal|2
block|}
enum|;
enum|enum
block|{
name|COST_BITS
init|=
name|unsigned
argument_list|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
argument_list|)
operator|*
name|CHAR_BIT
operator|-
name|TYPE_BITS
block|}
enum|;
name|unsigned
name|TypedCost
decl_stmt|;
comment|// int Cost : COST_BITS; unsigned Type : TYPE_BITS;
name|Kind
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Kind
argument_list|(
name|TypedCost
operator|>>
name|COST_BITS
argument_list|)
return|;
block|}
name|int
name|getCost
argument_list|()
specifier|const
block|{
comment|// Sign-extend the bottom COST_BITS bits.
return|return
operator|(
name|int
argument_list|(
name|TypedCost
operator|<<
name|TYPE_BITS
argument_list|)
operator|)
operator|>>
name|TYPE_BITS
return|;
block|}
name|InlineCost
argument_list|(
argument|int C
argument_list|,
argument|int T
argument_list|)
block|{
name|TypedCost
operator|=
operator|(
name|unsigned
argument_list|(
name|C
operator|<<
name|TYPE_BITS
argument_list|)
operator|>>
name|TYPE_BITS
operator|)
operator||
operator|(
name|T
operator|<<
name|COST_BITS
operator|)
expr_stmt|;
name|assert
argument_list|(
name|getCost
argument_list|()
operator|==
name|C
operator|&&
literal|"Cost exceeds InlineCost precision"
argument_list|)
expr_stmt|;
block|}
name|public
label|:
specifier|static
name|InlineCost
name|get
parameter_list|(
name|int
name|Cost
parameter_list|)
block|{
return|return
name|InlineCost
argument_list|(
name|Cost
argument_list|,
name|Value
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
literal|0
argument_list|,
name|Always
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
literal|0
argument_list|,
name|Never
argument_list|)
return|;
block|}
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|==
name|Value
return|;
block|}
name|bool
name|isAlways
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|==
name|Always
return|;
block|}
name|bool
name|isNever
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|==
name|Never
return|;
block|}
comment|/// getValue() - Return a "variable" inline cost's amount. It is
comment|/// an error to call this on an "always" or "never" InlineCost.
name|int
name|getValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getType
argument_list|()
operator|==
name|Value
operator|&&
literal|"Invalid access of InlineCost"
argument_list|)
block|;
return|return
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
struct|struct
name|ArgInfo
block|{
name|public
label|:
name|unsigned
name|ConstantWeight
decl_stmt|;
name|unsigned
name|AllocaWeight
decl_stmt|;
name|ArgInfo
argument_list|(
argument|unsigned CWeight
argument_list|,
argument|unsigned AWeight
argument_list|)
block|:
name|ConstantWeight
argument_list|(
name|CWeight
argument_list|)
operator|,
name|AllocaWeight
argument_list|(
argument|AWeight
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|FunctionInfo
block|{
name|CodeMetrics
name|Metrics
decl_stmt|;
comment|/// ArgumentWeights - Each formal argument of the function is inspected to
comment|/// see if it is used in any contexts where making it a constant or alloca
comment|/// would reduce the code size.  If so, we add some value to the argument
comment|/// entry here.
name|std
operator|::
name|vector
operator|<
name|ArgInfo
operator|>
name|ArgumentWeights
expr_stmt|;
comment|/// analyzeFunction - Add information about the specified function
comment|/// to the current structure.
name|void
name|analyzeFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// NeverInline - Returns true if the function should never be
comment|/// inlined into any caller.
name|bool
name|NeverInline
parameter_list|()
function_decl|;
block|}
struct|;
comment|// The Function* for a function can be changed (by ArgumentPromotion);
comment|// the ValueMap will update itself when this happens.
name|ValueMap
operator|<
specifier|const
name|Function
operator|*
operator|,
name|FunctionInfo
operator|>
name|CachedFunctionInfo
expr_stmt|;
name|int
name|CountBonusForConstant
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|Constant
modifier|*
name|C
init|=
name|NULL
parameter_list|)
function_decl|;
name|int
name|ConstantFunctionBonus
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|Constant
modifier|*
name|C
parameter_list|)
function_decl|;
name|int
name|getInlineSize
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|Function
modifier|*
name|Callee
parameter_list|)
function_decl|;
name|int
name|getInlineBonuses
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|Function
modifier|*
name|Callee
parameter_list|)
function_decl|;
name|public
label|:
comment|/// getInlineCost - The heuristic used to determine if we should inline the
comment|/// function call or not.
comment|///
name|InlineCost
name|getInlineCost
argument_list|(
name|CallSite
name|CS
argument_list|,
name|SmallPtrSet
operator|<
specifier|const
name|Function
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|NeverInline
argument_list|)
decl_stmt|;
comment|/// getCalledFunction - The heuristic used to determine if we should inline
comment|/// the function call or not.  The callee is explicitly specified, to allow
comment|/// you to calculate the cost of inlining a function via a pointer.  The
comment|/// result assumes that the inlined version will always be used.  You should
comment|/// weight it yourself in cases where this callee will not always be called.
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
name|SmallPtrSet
operator|<
specifier|const
name|Function
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|NeverInline
argument_list|)
decl_stmt|;
comment|/// getSpecializationBonus - The heuristic used to determine the per-call
comment|/// performance boost for using a specialization of Callee with argument
comment|/// SpecializedArgNos replaced by a constant.
name|int
name|getSpecializationBonus
argument_list|(
name|Function
operator|*
name|Callee
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|SpecializedArgNo
argument_list|)
decl_stmt|;
comment|/// getSpecializationCost - The heuristic used to determine the code-size
comment|/// impact of creating a specialized version of Callee with argument
comment|/// SpecializedArgNo replaced by a constant.
name|InlineCost
name|getSpecializationCost
argument_list|(
name|Function
operator|*
name|Callee
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|SpecializedArgNo
argument_list|)
decl_stmt|;
comment|/// getInlineFudgeFactor - Return a> 1.0 factor if the inliner should use a
comment|/// higher threshold to determine if the function call should be inlined.
name|float
name|getInlineFudgeFactor
parameter_list|(
name|CallSite
name|CS
parameter_list|)
function_decl|;
comment|/// resetCachedFunctionInfo - erase any cached cost info for this function.
name|void
name|resetCachedCostInfo
parameter_list|(
name|Function
modifier|*
name|Caller
parameter_list|)
block|{
name|CachedFunctionInfo
index|[
name|Caller
index|]
operator|=
name|FunctionInfo
argument_list|()
expr_stmt|;
block|}
comment|/// growCachedCostInfo - update the cached cost info for Caller after Callee
comment|/// has been inlined. If Callee is NULL it means a dead call has been
comment|/// eliminated.
name|void
name|growCachedCostInfo
parameter_list|(
name|Function
modifier|*
name|Caller
parameter_list|,
name|Function
modifier|*
name|Callee
parameter_list|)
function_decl|;
comment|/// clear - empty the cache of inline costs
name|void
name|clear
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// callIsSmall - If a call is likely to lower to a single target instruction,
comment|/// or is otherwise deemed small return true.
name|bool
name|callIsSmall
parameter_list|(
specifier|const
name|Function
modifier|*
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

