begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------- BlockFrequencyInfo.h - Block Frequency Analysis --*- C++ -*---===//
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
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|FunctionT
operator|,
name|class
name|BranchProbInfoT
operator|>
name|class
name|BlockFrequencyImpl
expr_stmt|;
comment|/// BlockFrequencyInfo pass uses BlockFrequencyImpl implementation to estimate
comment|/// IR basic block frequencies.
name|class
name|BlockFrequencyInfo
range|:
name|public
name|FunctionPass
block|{
name|BlockFrequencyImpl
operator|<
name|BasicBlock
block|,
name|Function
block|,
name|BranchProbabilityInfo
operator|>
operator|*
name|BFI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|BlockFrequencyInfo
argument_list|()
block|;
operator|~
name|BlockFrequencyInfo
argument_list|()
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const Module *M
argument_list|)
specifier|const
block|;
specifier|const
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
block|;
name|void
name|view
argument_list|()
specifier|const
block|;
comment|/// getblockFreq - Return block frequency. Return 0 if we don't have the
comment|/// information. Please note that initial frequency is equal to ENTRY_FREQ. It
comment|/// means that we should not rely on the value itself, but only on the
comment|/// comparison to the other block frequencies. We do this to avoid using of
comment|/// floating points.
name|BlockFrequency
name|getBlockFreq
argument_list|(
argument|const BasicBlock *BB
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

