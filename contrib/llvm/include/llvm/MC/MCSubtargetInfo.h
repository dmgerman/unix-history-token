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
file|"llvm/MC/SubtargetFeature.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrItineraries.h"
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
specifier|const
name|SubtargetInfoKV
modifier|*
name|ProcItins
decl_stmt|;
comment|// Scheduling itineraries
specifier|const
name|InstrStage
modifier|*
name|Stages
decl_stmt|;
comment|// Instruction stages
specifier|const
name|unsigned
modifier|*
name|OperandCycles
decl_stmt|;
comment|// Operand cycles
specifier|const
name|unsigned
modifier|*
name|ForwardingPathes
decl_stmt|;
comment|// Forwarding pathes
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
name|PI
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
comment|/// ReInitMCSubtargetInfo - Change CPU (and optionally supplemented with
comment|/// feature string), recompute and return feature bits.
name|uint64_t
name|ReInitMCSubtargetInfo
parameter_list|(
name|StringRef
name|CPU
parameter_list|,
name|StringRef
name|FS
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

