begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MachineBlockFrequencyInfo.h - MBB Frequency Analysis -*- C++ -*-----===//
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
file|"llvm/ADT/Optional.h"
end_include

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
name|class
name|MachineLoopInfo
decl_stmt|;
name|template
operator|<
name|class
name|BlockT
operator|>
name|class
name|BlockFrequencyInfoImpl
expr_stmt|;
comment|/// MachineBlockFrequencyInfo pass uses BlockFrequencyInfoImpl implementation
comment|/// to estimate machine basic block frequencies.
name|class
name|MachineBlockFrequencyInfo
range|:
name|public
name|MachineFunctionPass
block|{
typedef|typedef
name|BlockFrequencyInfoImpl
operator|<
name|MachineBasicBlock
operator|>
name|ImplType
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ImplType
operator|>
name|MBFI
decl_stmt|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
name|MachineBlockFrequencyInfo
argument_list|()
expr_stmt|;
operator|~
name|MachineBlockFrequencyInfo
argument_list|()
name|override
expr_stmt|;
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
name|override
decl_stmt|;
comment|/// calculate - compute block frequency info for the given function.
name|void
name|calculate
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|F
parameter_list|,
specifier|const
name|MachineBranchProbabilityInfo
modifier|&
name|MBPI
parameter_list|,
specifier|const
name|MachineLoopInfo
modifier|&
name|MLI
parameter_list|)
function_decl|;
name|void
name|releaseMemory
argument_list|()
name|override
expr_stmt|;
comment|/// getblockFreq - Return block frequency. Return 0 if we don't have the
comment|/// information. Please note that initial frequency is equal to 1024. It means
comment|/// that we should not rely on the value itself, but only on the comparison to
comment|/// the other block frequencies. We do this to avoid using of floating points.
comment|///
name|BlockFrequency
name|getBlockFreq
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getBlockProfileCount
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getProfileCountFromFreq
argument_list|(
argument|uint64_t Freq
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|MachineFunction
operator|*
name|getFunction
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|MachineBranchProbabilityInfo
operator|*
name|getMBPI
argument_list|()
specifier|const
expr_stmt|;
name|void
name|view
argument_list|(
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
name|bool
name|isSimple
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|// Print the block frequency Freq to OS using the current functions entry
comment|// frequency to convert freq into a relative decimal form.
name|raw_ostream
modifier|&
name|printBlockFreq
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|BlockFrequency
name|Freq
argument_list|)
decl|const
decl_stmt|;
comment|// Convenience method that attempts to look up the frequency associated with
comment|// BB and print it to OS.
name|raw_ostream
modifier|&
name|printBlockFreq
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getEntryFreq
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

