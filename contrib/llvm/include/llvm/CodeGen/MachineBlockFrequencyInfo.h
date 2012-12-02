begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====----- MachineBlockFrequencyInfo.h - MachineBlock Frequency Analysis ----====//
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
name|LLVM_CODEGEN_MACHINEBLOCKFREQUENCYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEBLOCKFREQUENCYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
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
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineBranchProbabilityInfo
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
comment|/// MachineBlockFrequencyInfo pass uses BlockFrequencyImpl implementation to estimate
comment|/// machine basic block frequencies.
name|class
name|MachineBlockFrequencyInfo
range|:
name|public
name|MachineFunctionPass
block|{
name|BlockFrequencyImpl
operator|<
name|MachineBasicBlock
block|,
name|MachineFunction
block|,
name|MachineBranchProbabilityInfo
operator|>
operator|*
name|MBFI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|MachineBlockFrequencyInfo
argument_list|()
block|;
operator|~
name|MachineBlockFrequencyInfo
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
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
block|;
comment|/// getblockFreq - Return block frequency. Return 0 if we don't have the
comment|/// information. Please note that initial frequency is equal to 1024. It means
comment|/// that we should not rely on the value itself, but only on the comparison to
comment|/// the other block frequencies. We do this to avoid using of floating points.
comment|///
name|BlockFrequency
name|getBlockFreq
argument_list|(
argument|const MachineBasicBlock *MBB
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

