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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SlotIndexes.h"
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
name|MachineBlockFrequencyInfo
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
comment|/// \brief Normalize the spill weight of a live interval
comment|///
comment|/// The spill weight of a live interval is computed as:
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
comment|// The constant 25 instructions is added to avoid depending too much on
comment|// accidental SlotIndex gaps for small intervals. The effect is that small
comment|// intervals have a spill weight that is mostly proportional to the number
comment|// of uses, while large intervals get a spill weight that is closer to a use
comment|// density.
return|return
name|UseDefFreq
operator|/
operator|(
name|Size
operator|+
literal|25
operator|*
name|SlotIndex
operator|::
name|InstrDist
operator|)
return|;
block|}
comment|/// \brief Calculate auxiliary information for a virtual register such as its
comment|/// spill weight and allocation hint.
name|class
name|VirtRegAuxInfo
block|{
name|public
label|:
typedef|typedef
name|float
function_decl|(
modifier|*
name|NormalizingFn
function_decl|)
parameter_list|(
name|float
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
name|private
label|:
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
name|LiveIntervals
modifier|&
name|LIS
decl_stmt|;
specifier|const
name|MachineLoopInfo
modifier|&
name|Loops
decl_stmt|;
specifier|const
name|MachineBlockFrequencyInfo
modifier|&
name|MBFI
decl_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|float
operator|>
name|Hint
expr_stmt|;
name|NormalizingFn
name|normalize
decl_stmt|;
name|public
label|:
name|VirtRegAuxInfo
argument_list|(
argument|MachineFunction&mf
argument_list|,
argument|LiveIntervals&lis
argument_list|,
argument|const MachineLoopInfo&loops
argument_list|,
argument|const MachineBlockFrequencyInfo&mbfi
argument_list|,
argument|NormalizingFn norm = normalizeSpillWeight
argument_list|)
block|:
name|MF
argument_list|(
name|mf
argument_list|)
operator|,
name|LIS
argument_list|(
name|lis
argument_list|)
operator|,
name|Loops
argument_list|(
name|loops
argument_list|)
operator|,
name|MBFI
argument_list|(
name|mbfi
argument_list|)
operator|,
name|normalize
argument_list|(
argument|norm
argument_list|)
block|{}
comment|/// \brief (re)compute li's spill weight and allocation hint.
name|void
name|calculateSpillWeightAndHint
argument_list|(
name|LiveInterval
operator|&
name|li
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Compute spill weights and allocation hints for all virtual register
comment|/// live intervals.
name|void
name|calculateSpillWeightsAndHints
argument_list|(
name|LiveIntervals
operator|&
name|LIS
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|,
specifier|const
name|MachineLoopInfo
operator|&
name|MLI
argument_list|,
specifier|const
name|MachineBlockFrequencyInfo
operator|&
name|MBFI
argument_list|,
name|VirtRegAuxInfo
operator|::
name|NormalizingFn
name|norm
operator|=
name|normalizeSpillWeight
argument_list|)
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

