begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- CFLAliasAnalysisUtils.h - Utilities for CFL Alias Analysis ----*- C++-*-=//
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
comment|// \file
end_comment

begin_comment
comment|// These are the utilities/helpers used by the CFL Alias Analyses available in
end_comment

begin_comment
comment|// tree, i.e. Steensgaard's and Andersens'.
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
name|LLVM_ANALYSIS_CFLALIASANALYSISUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CFLALIASANALYSISUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|cflaa
block|{
name|template
operator|<
name|typename
name|AAResult
operator|>
expr|struct
name|FunctionHandle
name|final
operator|:
name|public
name|CallbackVH
block|{
name|FunctionHandle
argument_list|(
name|Function
operator|*
name|Fn
argument_list|,
name|AAResult
operator|*
name|Result
argument_list|)
operator|:
name|CallbackVH
argument_list|(
name|Fn
argument_list|)
block|,
name|Result
argument_list|(
argument|Result
argument_list|)
block|{
name|assert
argument_list|(
name|Fn
operator|!=
name|nullptr
argument_list|)
block|;
name|assert
argument_list|(
name|Result
operator|!=
name|nullptr
argument_list|)
block|;   }
name|void
name|deleted
argument_list|()
name|override
block|{
name|removeSelfFromCache
argument_list|()
block|; }
name|void
name|allUsesReplacedWith
argument_list|(
argument|Value *
argument_list|)
name|override
block|{
name|removeSelfFromCache
argument_list|()
block|; }
name|private
operator|:
name|AAResult
operator|*
name|Result
block|;
name|void
name|removeSelfFromCache
argument_list|()
block|{
name|assert
argument_list|(
name|Result
operator|!=
name|nullptr
argument_list|)
block|;
name|auto
operator|*
name|Val
operator|=
name|getValPtr
argument_list|()
block|;
name|Result
operator|->
name|evict
argument_list|(
name|cast
operator|<
name|Function
operator|>
operator|(
name|Val
operator|)
argument_list|)
block|;
name|setValPtr
argument_list|(
name|nullptr
argument_list|)
block|;   }
block|}
expr_stmt|;
specifier|static
specifier|inline
specifier|const
name|Function
modifier|*
name|parentFunctionOfValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|Val
parameter_list|)
block|{
if|if
condition|(
name|auto
operator|*
name|Inst
operator|=
name|dyn_cast
operator|<
name|Instruction
operator|>
operator|(
name|Val
operator|)
condition|)
block|{
name|auto
operator|*
name|Bb
operator|=
name|Inst
operator|->
name|getParent
argument_list|()
expr_stmt|;
return|return
name|Bb
operator|->
name|getParent
argument_list|()
return|;
block|}
if|if
condition|(
name|auto
operator|*
name|Arg
operator|=
name|dyn_cast
operator|<
name|Argument
operator|>
operator|(
name|Val
operator|)
condition|)
return|return
name|Arg
operator|->
name|getParent
argument_list|()
return|;
return|return
name|nullptr
return|;
block|}
comment|// namespace cflaa
block|}
comment|// namespace llvm
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ANALYSIS_CFLALIASANALYSISUTILS_H
end_comment

end_unit

