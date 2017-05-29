begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MachineBlockFrequencyInfo.h - MBB Frequency Analysis -----*- C++ -*-===//
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
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|BlockT
operator|>
name|class
name|BlockFrequencyInfoImpl
expr_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineBranchProbabilityInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MachineBlockFrequencyInfo pass uses BlockFrequencyInfoImpl implementation
comment|/// to estimate machine basic block frequencies.
name|class
name|MachineBlockFrequencyInfo
range|:
name|public
name|MachineFunctionPass
block|{
name|using
name|ImplType
operator|=
name|BlockFrequencyInfoImpl
operator|<
name|MachineBasicBlock
operator|>
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ImplType
operator|>
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
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&F
argument_list|)
name|override
block|;
comment|/// calculate - compute block frequency info for the given function.
name|void
name|calculate
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|F
argument_list|,
specifier|const
name|MachineBranchProbabilityInfo
operator|&
name|MBPI
argument_list|,
specifier|const
name|MachineLoopInfo
operator|&
name|MLI
argument_list|)
block|;
name|void
name|releaseMemory
argument_list|()
name|override
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
block|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getBlockProfileCount
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getProfileCountFromFreq
argument_list|(
argument|uint64_t Freq
argument_list|)
specifier|const
block|;
specifier|const
name|MachineFunction
operator|*
name|getFunction
argument_list|()
specifier|const
block|;
specifier|const
name|MachineBranchProbabilityInfo
operator|*
name|getMBPI
argument_list|()
specifier|const
block|;
name|void
name|view
argument_list|(
argument|const Twine&Name
argument_list|,
argument|bool isSimple = true
argument_list|)
specifier|const
block|;
comment|// Print the block frequency Freq to OS using the current functions entry
comment|// frequency to convert freq into a relative decimal form.
name|raw_ostream
operator|&
name|printBlockFreq
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const BlockFrequency Freq
argument_list|)
specifier|const
block|;
comment|// Convenience method that attempts to look up the frequency associated with
comment|// BB and print it to OS.
name|raw_ostream
operator|&
name|printBlockFreq
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|uint64_t
name|getEntryFreq
argument_list|()
specifier|const
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
comment|// LLVM_CODEGEN_MACHINEBLOCKFREQUENCYINFO_H
end_comment

end_unit

