begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InlineCost.cpp - Cost analysis for inliner ---------------*- C++ -*-===//
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
file|<map>
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
comment|// CodeMetrics - Calculate size and a few similar metrics for a set of
comment|// basic blocks.
struct|struct
name|CodeMetrics
block|{
comment|/// NeverInline - True if this callee should never be inlined into a
comment|/// caller.
name|bool
name|NeverInline
decl_stmt|;
comment|/// usesDynamicAlloca - True if this function calls alloca (in the C sense).
name|bool
name|usesDynamicAlloca
decl_stmt|;
comment|/// NumInsts, NumBlocks - Keep track of how large each function is, which
comment|/// is used to estimate the code size cost of inlining it.
name|unsigned
name|NumInsts
decl_stmt|,
name|NumBlocks
decl_stmt|;
comment|/// NumVectorInsts - Keep track of how many instructions produce vector
comment|/// values.  The inliner is being more aggressive with inlining vector
comment|/// kernels.
name|unsigned
name|NumVectorInsts
decl_stmt|;
comment|/// NumRets - Keep track of how many Ret instructions the block contains.
name|unsigned
name|NumRets
decl_stmt|;
name|CodeMetrics
argument_list|()
operator|:
name|NeverInline
argument_list|(
name|false
argument_list|)
operator|,
name|usesDynamicAlloca
argument_list|(
name|false
argument_list|)
operator|,
name|NumInsts
argument_list|(
literal|0
argument_list|)
operator|,
name|NumBlocks
argument_list|(
literal|0
argument_list|)
operator|,
name|NumVectorInsts
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRets
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// analyzeBasicBlock - Add information about the specified basic block
comment|/// to the current structure.
name|void
name|analyzeBasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
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
block|}
struct|;
name|namespace
name|InlineConstants
block|{
comment|// Various magic constants used to adjust heuristics.
specifier|const
name|int
name|CallPenalty
init|=
literal|5
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
comment|/// CountCodeReductionForConstant - Figure out an approximation for how
comment|/// many instructions will be constant folded if the specified value is
comment|/// constant.
name|unsigned
name|CountCodeReductionForConstant
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// CountCodeReductionForAlloca - Figure out an approximation of how much
comment|/// smaller the function will be if it is inlined into a context where an
comment|/// argument becomes an alloca.
comment|///
name|unsigned
name|CountCodeReductionForAlloca
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
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
block|}
struct|;
name|std
operator|::
name|map
operator|<
specifier|const
name|Function
operator|*
operator|,
name|FunctionInfo
operator|>
name|CachedFunctionInfo
expr_stmt|;
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

