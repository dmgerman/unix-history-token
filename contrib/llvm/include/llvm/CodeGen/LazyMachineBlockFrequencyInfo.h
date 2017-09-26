begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///===- LazyMachineBlockFrequencyInfo.h - Lazy Block Frequency -*- C++ -*--===//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|/// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///===---------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This is an alternative analysis pass to MachineBlockFrequencyInfo.  The
end_comment

begin_comment
comment|/// difference is that with this pass the block frequencies are not computed
end_comment

begin_comment
comment|/// when the analysis pass is executed but rather when the BFI result is
end_comment

begin_comment
comment|/// explicitly requested by the analysis client.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///===---------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_LAZYMACHINEBLOCKFREQUENCYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LAZYMACHINEBLOCKFREQUENCYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBlockFrequencyInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBranchProbabilityInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineDominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLoopInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief This is an alternative analysis pass to MachineBlockFrequencyInfo.
comment|/// The difference is that with this pass, the block frequencies are not
comment|/// computed when the analysis pass is executed but rather when the BFI result
comment|/// is explicitly requested by the analysis client.
comment|///
comment|/// This works by checking querying if MBFI is available and otherwise
comment|/// generating MBFI on the fly.  In this case the passes required for (LI, DT)
comment|/// are also queried before being computed on the fly.
comment|///
comment|/// Note that it is expected that we wouldn't need this functionality for the
comment|/// new PM since with the new PM, analyses are executed on demand.
name|class
name|LazyMachineBlockFrequencyInfoPass
range|:
name|public
name|MachineFunctionPass
block|{
name|private
operator|:
comment|/// If generated on the fly this own the instance.
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|MachineBlockFrequencyInfo
operator|>
name|OwnedMBFI
block|;
comment|/// If generated on the fly this own the instance.
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|MachineLoopInfo
operator|>
name|OwnedMLI
block|;
comment|/// If generated on the fly this own the instance.
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|MachineDominatorTree
operator|>
name|OwnedMDT
block|;
comment|/// The function.
name|MachineFunction
operator|*
name|MF
operator|=
name|nullptr
block|;
comment|/// \brief Calculate MBFI and all other analyses that's not available and
comment|/// required by BFI.
name|MachineBlockFrequencyInfo
operator|&
name|calculateIfNotAvailable
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|LazyMachineBlockFrequencyInfoPass
argument_list|()
block|;
comment|/// \brief Compute and return the block frequencies.
name|MachineBlockFrequencyInfo
operator|&
name|getBFI
argument_list|()
block|{
return|return
name|calculateIfNotAvailable
argument_list|()
return|;
block|}
comment|/// \brief Compute and return the block frequencies.
specifier|const
name|MachineBlockFrequencyInfo
operator|&
name|getBFI
argument_list|()
specifier|const
block|{
return|return
name|calculateIfNotAvailable
argument_list|()
return|;
block|}
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
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

