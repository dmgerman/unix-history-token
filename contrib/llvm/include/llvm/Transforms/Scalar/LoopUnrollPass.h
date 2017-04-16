begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopUnrollPass.h -----------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_SCALAR_LOOPUNROLLPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_LOOPUNROLLPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Scalar/LoopPassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LoopUnrollPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopUnrollPass
operator|>
block|{
specifier|const
name|bool
name|AllowPartialUnrolling
block|;
specifier|const
name|int
name|OptLevel
block|;
name|explicit
name|LoopUnrollPass
argument_list|(
argument|bool AllowPartialUnrolling
argument_list|,
argument|int OptLevel
argument_list|)
operator|:
name|AllowPartialUnrolling
argument_list|(
name|AllowPartialUnrolling
argument_list|)
block|,
name|OptLevel
argument_list|(
argument|OptLevel
argument_list|)
block|{}
name|public
operator|:
comment|/// Create an instance of the loop unroll pass that will support both full
comment|/// and partial unrolling.
comment|///
comment|/// This uses the target information (or flags) to control the thresholds for
comment|/// different unrolling stategies but supports all of them.
specifier|static
name|LoopUnrollPass
name|create
argument_list|(
argument|int OptLevel =
literal|2
argument_list|)
block|{
return|return
name|LoopUnrollPass
argument_list|(
comment|/*AllowPartialUnrolling*/
name|true
argument_list|,
name|OptLevel
argument_list|)
return|;
block|}
comment|/// Create an instance of the loop unroll pass that only does full loop
comment|/// unrolling.
comment|///
comment|/// This will disable any runtime or partial unrolling.
specifier|static
name|LoopUnrollPass
name|createFull
argument_list|(
argument|int OptLevel =
literal|2
argument_list|)
block|{
return|return
name|LoopUnrollPass
argument_list|(
comment|/*AllowPartialUnrolling*/
name|false
argument_list|,
name|OptLevel
argument_list|)
return|;
block|}
name|PreservedAnalyses
name|run
argument_list|(
name|Loop
operator|&
name|L
argument_list|,
name|LoopAnalysisManager
operator|&
name|AM
argument_list|,
name|LoopStandardAnalysisResults
operator|&
name|AR
argument_list|,
name|LPMUpdater
operator|&
name|U
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_LOOPUNROLLPASS_H
end_comment

end_unit

