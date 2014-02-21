begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/MC/MCSubtargetInfo.h - Subtarget Information ---------*- C++ -*-==//
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
comment|// This file describes the subtarget options of a Target machine.
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
name|LLVM_MC_MCSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SubtargetFeature.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// MCSubtargetInfo - Generic base class for all target subtargets.
comment|///
name|class
name|MCSubtargetInfo
block|{
name|std
operator|::
name|string
name|TargetTriple
expr_stmt|;
comment|// Target triple
specifier|const
name|SubtargetFeatureKV
modifier|*
name|ProcFeatures
decl_stmt|;
comment|// Processor feature list
specifier|const
name|SubtargetFeatureKV
modifier|*
name|ProcDesc
decl_stmt|;
comment|// Processor descriptions
comment|// Scheduler machine model
specifier|const
name|SubtargetInfoKV
modifier|*
name|ProcSchedModels
decl_stmt|;
specifier|const
name|MCWriteProcResEntry
modifier|*
name|WriteProcResTable
decl_stmt|;
specifier|const
name|MCWriteLatencyEntry
modifier|*
name|WriteLatencyTable
decl_stmt|;
specifier|const
name|MCReadAdvanceEntry
modifier|*
name|ReadAdvanceTable
decl_stmt|;
specifier|const
name|MCSchedModel
modifier|*
name|CPUSchedModel
decl_stmt|;
specifier|const
name|InstrStage
modifier|*
name|Stages
decl_stmt|;
comment|// Instruction itinerary stages
specifier|const
name|unsigned
modifier|*
name|OperandCycles
decl_stmt|;
comment|// Itinerary operand cycles
specifier|const
name|unsigned
modifier|*
name|ForwardingPaths
decl_stmt|;
comment|// Forwarding paths
name|unsigned
name|NumFeatures
decl_stmt|;
comment|// Number of processor features
name|unsigned
name|NumProcs
decl_stmt|;
comment|// Number of processors
name|uint64_t
name|FeatureBits
decl_stmt|;
comment|// Feature bits for current CPU + FS
name|public
label|:
name|void
name|InitMCSubtargetInfo
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|,
name|StringRef
name|FS
parameter_list|,
specifier|const
name|SubtargetFeatureKV
modifier|*
name|PF
parameter_list|,
specifier|const
name|SubtargetFeatureKV
modifier|*
name|PD
parameter_list|,
specifier|const
name|SubtargetInfoKV
modifier|*
name|ProcSched
parameter_list|,
specifier|const
name|MCWriteProcResEntry
modifier|*
name|WPR
parameter_list|,
specifier|const
name|MCWriteLatencyEntry
modifier|*
name|WL
parameter_list|,
specifier|const
name|MCReadAdvanceEntry
modifier|*
name|RA
parameter_list|,
specifier|const
name|InstrStage
modifier|*
name|IS
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|OC
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|FP
parameter_list|,
name|unsigned
name|NF
parameter_list|,
name|unsigned
name|NP
parameter_list|)
function_decl|;
comment|/// getTargetTriple - Return the target triple string.
name|StringRef
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
comment|/// getFeatureBits - Return the feature bits.
comment|///
name|uint64_t
name|getFeatureBits
argument_list|()
specifier|const
block|{
return|return
name|FeatureBits
return|;
block|}
comment|/// InitMCProcessorInfo - Set or change the CPU (optionally supplemented with
comment|/// feature string). Recompute feature bits and scheduling model.
name|void
name|InitMCProcessorInfo
parameter_list|(
name|StringRef
name|CPU
parameter_list|,
name|StringRef
name|FS
parameter_list|)
function_decl|;
comment|/// InitCPUSchedModel - Recompute scheduling model based on CPU.
name|void
name|InitCPUSchedModel
parameter_list|(
name|StringRef
name|CPU
parameter_list|)
function_decl|;
comment|/// ToggleFeature - Toggle a feature and returns the re-computed feature
comment|/// bits. This version does not change the implied bits.
name|uint64_t
name|ToggleFeature
parameter_list|(
name|uint64_t
name|FB
parameter_list|)
function_decl|;
comment|/// ToggleFeature - Toggle a feature and returns the re-computed feature
comment|/// bits. This version will also change all implied bits.
name|uint64_t
name|ToggleFeature
parameter_list|(
name|StringRef
name|FS
parameter_list|)
function_decl|;
comment|/// getSchedModelForCPU - Get the machine model of a CPU.
comment|///
specifier|const
name|MCSchedModel
modifier|*
name|getSchedModelForCPU
argument_list|(
name|StringRef
name|CPU
argument_list|)
decl|const
decl_stmt|;
comment|/// getSchedModel - Get the machine model for this subtarget's CPU.
comment|///
specifier|const
name|MCSchedModel
operator|*
name|getSchedModel
argument_list|()
specifier|const
block|{
return|return
name|CPUSchedModel
return|;
block|}
comment|/// Return an iterator at the first process resource consumed by the given
comment|/// scheduling class.
specifier|const
name|MCWriteProcResEntry
modifier|*
name|getWriteProcResBegin
argument_list|(
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
argument_list|)
decl|const
block|{
return|return
operator|&
name|WriteProcResTable
index|[
name|SC
operator|->
name|WriteProcResIdx
index|]
return|;
block|}
specifier|const
name|MCWriteProcResEntry
modifier|*
name|getWriteProcResEnd
argument_list|(
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
argument_list|)
decl|const
block|{
return|return
name|getWriteProcResBegin
argument_list|(
name|SC
argument_list|)
operator|+
name|SC
operator|->
name|NumWriteProcResEntries
return|;
block|}
specifier|const
name|MCWriteLatencyEntry
modifier|*
name|getWriteLatencyEntry
argument_list|(
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
argument_list|,
name|unsigned
name|DefIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|DefIdx
operator|<
name|SC
operator|->
name|NumWriteLatencyEntries
operator|&&
literal|"MachineModel does not specify a WriteResource for DefIdx"
argument_list|)
expr_stmt|;
return|return
operator|&
name|WriteLatencyTable
index|[
name|SC
operator|->
name|WriteLatencyIdx
operator|+
name|DefIdx
index|]
return|;
block|}
name|int
name|getReadAdvanceCycles
argument_list|(
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
argument_list|,
name|unsigned
name|UseIdx
argument_list|,
name|unsigned
name|WriteResID
argument_list|)
decl|const
block|{
comment|// TODO: The number of read advance entries in a class can be significant
comment|// (~50). Consider compressing the WriteID into a dense ID of those that are
comment|// used by ReadAdvance and representing them as a bitset.
for|for
control|(
specifier|const
name|MCReadAdvanceEntry
modifier|*
name|I
init|=
operator|&
name|ReadAdvanceTable
index|[
name|SC
operator|->
name|ReadAdvanceIdx
index|]
init|,
modifier|*
name|E
init|=
name|I
operator|+
name|SC
operator|->
name|NumReadAdvanceEntries
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
if|if
condition|(
name|I
operator|->
name|UseIdx
operator|<
name|UseIdx
condition|)
continue|continue;
if|if
condition|(
name|I
operator|->
name|UseIdx
operator|>
name|UseIdx
condition|)
break|break;
comment|// Find the first WriteResIdx match, which has the highest cycle count.
if|if
condition|(
operator|!
name|I
operator|->
name|WriteResourceID
operator|||
name|I
operator|->
name|WriteResourceID
operator|==
name|WriteResID
condition|)
block|{
return|return
name|I
operator|->
name|Cycles
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
comment|/// getInstrItineraryForCPU - Get scheduling itinerary of a CPU.
comment|///
name|InstrItineraryData
name|getInstrItineraryForCPU
argument_list|(
name|StringRef
name|CPU
argument_list|)
decl|const
decl_stmt|;
comment|/// Initialize an InstrItineraryData instance.
name|void
name|initInstrItins
argument_list|(
name|InstrItineraryData
operator|&
name|InstrItins
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

