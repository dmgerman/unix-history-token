begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/FunctionTargetTransformInfo.h --------------*- C++ -*-===//
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
comment|// This pass wraps a TargetTransformInfo in a FunctionPass so that it can
end_comment

begin_comment
comment|// forward along the current Function so that we can make target specific
end_comment

begin_comment
comment|// decisions based on the particular subtarget specified for each Function.
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
name|LLVM_ANALYSIS_FUNCTIONTARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_FUNCTIONTARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"TargetTransformInfo.h"
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
name|FunctionTargetTransformInfo
name|final
range|:
name|public
name|FunctionPass
block|{
name|private
operator|:
specifier|const
name|Function
operator|*
name|Fn
block|;
specifier|const
name|TargetTransformInfo
operator|*
name|TTI
block|;
name|FunctionTargetTransformInfo
argument_list|(
argument|const FunctionTargetTransformInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|FunctionTargetTransformInfo
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|FunctionTargetTransformInfo
argument_list|()
block|;
comment|// Implementation boilerplate.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
comment|// Shimmed functions from TargetTransformInfo.
name|void
name|getUnrollingPreferences
argument_list|(
argument|Loop *L
argument_list|,
argument|TargetTransformInfo::UnrollingPreferences&UP
argument_list|)
specifier|const
block|{
name|TTI
operator|->
name|getUnrollingPreferences
argument_list|(
name|Fn
argument_list|,
name|L
argument_list|,
name|UP
argument_list|)
block|;   }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

