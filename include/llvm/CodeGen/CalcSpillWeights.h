begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---------------- lib/CodeGen/CalcSpillWeights.h ------------*- C++ -*-===//
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
name|LLVM_CODEGEN_CALCSPILLWEIGHTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_CALCSPILLWEIGHTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveInterval
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
comment|/// normalizeSpillWeight - The spill weight of a live interval is computed as:
comment|///
comment|///   (sum(use freq) + sum(def freq)) / (K + size)
comment|///
comment|/// @param UseDefFreq Expected number of executed use and def instructions
comment|///                   per function call. Derived from block frequencies.
comment|/// @param Size       Size of live interval as returnexd by getSize()
comment|///
specifier|static
specifier|inline
name|float
name|normalizeSpillWeight
parameter_list|(
name|float
name|UseDefFreq
parameter_list|,
name|unsigned
name|Size
parameter_list|)
block|{
comment|// The magic constant 200 corresponds to approx. 25 instructions since
comment|// SlotIndexes allocate 8 slots per instruction.
comment|//
comment|// The constant is added to avoid depending too much on accidental SlotIndex
comment|// gaps for small intervals. The effect is that small intervals have a spill
comment|// weight that is mostly proportional to the number of uses, while large
comment|// intervals get a spill weight that is closer to a use density.
comment|//
return|return
name|UseDefFreq
operator|/
operator|(
name|Size
operator|+
literal|200
operator|)
return|;
block|}
comment|/// VirtRegAuxInfo - Calculate auxiliary information for a virtual
comment|/// register such as its spill weight and allocation hint.
name|class
name|VirtRegAuxInfo
block|{
name|MachineFunction
modifier|&
name|mf_
decl_stmt|;
name|LiveIntervals
modifier|&
name|lis_
decl_stmt|;
specifier|const
name|MachineLoopInfo
modifier|&
name|loops_
decl_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|float
operator|>
name|hint_
expr_stmt|;
name|public
label|:
name|VirtRegAuxInfo
argument_list|(
name|MachineFunction
operator|&
name|mf
argument_list|,
name|LiveIntervals
operator|&
name|lis
argument_list|,
specifier|const
name|MachineLoopInfo
operator|&
name|loops
argument_list|)
operator|:
name|mf_
argument_list|(
name|mf
argument_list|)
operator|,
name|lis_
argument_list|(
name|lis
argument_list|)
operator|,
name|loops_
argument_list|(
argument|loops
argument_list|)
block|{}
comment|/// CalculateRegClass - recompute the register class for reg from its uses.
comment|/// Since the register class can affect the allocation hint, this function
comment|/// should be called before CalculateWeightAndHint if both are called.
name|void
name|CalculateRegClass
argument_list|(
argument|unsigned reg
argument_list|)
expr_stmt|;
comment|/// CalculateWeightAndHint - (re)compute li's spill weight and allocation
comment|/// hint.
name|void
name|CalculateWeightAndHint
parameter_list|(
name|LiveInterval
modifier|&
name|li
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// CalculateSpillWeights - Compute spill weights for all virtual register
comment|/// live intervals.
name|class
name|CalculateSpillWeights
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|CalculateSpillWeights
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeCalculateSpillWeightsPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&au
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|fn
argument_list|)
block|;
name|private
operator|:
comment|/// Returns true if the given live interval is zero length.
name|bool
name|isZeroLengthInterval
argument_list|(
argument|LiveInterval *li
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_CALCSPILLWEIGHTS_H
end_comment

end_unit

