begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonSubtarget.h - Define Subtarget for the Hexagon ---*- C++ -*-===//
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
comment|// This file declares the Hexagon specific subclass of TargetSubtarget.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"HexagonFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"HexagonISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"HexagonInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"HexagonSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"HexagonGenSubtargetInfo.inc"
end_include

begin_define
define|#
directive|define
name|Hexagon_SMALL_DATA_THRESHOLD
value|8
end_define

begin_define
define|#
directive|define
name|Hexagon_SLOTS
value|4
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonSubtarget
range|:
name|public
name|HexagonGenSubtargetInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|bool
name|UseMemOps
block|,
name|UseHVXOps
block|,
name|UseHVXDblOps
block|;
name|bool
name|UseLongCalls
block|;
name|bool
name|ModeIEEERndNear
block|;
name|public
operator|:
include|#
directive|include
file|"HexagonDepArch.h"
name|HexagonArchEnum
name|HexagonArchVersion
block|;
comment|/// True if the target should use Back-Skip-Back scheduling. This is the
comment|/// default for V60.
name|bool
name|UseBSBScheduling
block|;
name|class
name|HexagonDAGMutation
operator|:
name|public
name|ScheduleDAGMutation
block|{
name|public
operator|:
name|void
name|apply
argument_list|(
argument|ScheduleDAGInstrs *DAG
argument_list|)
name|override
block|;   }
block|;
name|private
operator|:
name|std
operator|::
name|string
name|CPUString
block|;
name|HexagonInstrInfo
name|InstrInfo
block|;
name|HexagonTargetLowering
name|TLInfo
block|;
name|HexagonSelectionDAGInfo
name|TSInfo
block|;
name|HexagonFrameLowering
name|FrameLowering
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|void
name|initializeEnvironment
argument_list|()
block|;
name|public
operator|:
name|HexagonSubtarget
argument_list|(
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetMachine&TM
argument_list|)
block|;
comment|/// getInstrItins - Return the instruction itineraries based on subtarget
comment|/// selection.
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrItins
return|;
block|}
specifier|const
name|HexagonInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
specifier|const
name|HexagonRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
operator|.
name|getRegisterInfo
argument_list|()
return|;
block|}
specifier|const
name|HexagonTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
specifier|const
name|HexagonFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
specifier|const
name|HexagonSelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
name|HexagonSubtarget
operator|&
name|initializeSubtargetDependencies
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
comment|/// ParseSubtargetFeatures - Parses features string setting specified
comment|/// subtarget options.  Definition of function is auto generated by tblgen.
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|bool
name|useMemOps
argument_list|()
specifier|const
block|{
return|return
name|UseMemOps
return|;
block|}
name|bool
name|hasV5TOps
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|>=
name|V5
return|;
block|}
name|bool
name|hasV5TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|==
name|V5
return|;
block|}
name|bool
name|hasV55TOps
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|>=
name|V55
return|;
block|}
name|bool
name|hasV55TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|==
name|V55
return|;
block|}
name|bool
name|hasV60TOps
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|>=
name|V60
return|;
block|}
name|bool
name|hasV60TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|==
name|V60
return|;
block|}
name|bool
name|hasV62TOps
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|>=
name|V62
return|;
block|}
name|bool
name|hasV62TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|getHexagonArchVersion
argument_list|()
operator|==
name|V62
return|;
block|}
name|bool
name|modeIEEERndNear
argument_list|()
specifier|const
block|{
return|return
name|ModeIEEERndNear
return|;
block|}
name|bool
name|useHVXOps
argument_list|()
specifier|const
block|{
return|return
name|UseHVXOps
return|;
block|}
name|bool
name|useHVXDblOps
argument_list|()
specifier|const
block|{
return|return
name|UseHVXOps
operator|&&
name|UseHVXDblOps
return|;
block|}
name|bool
name|useHVXSglOps
argument_list|()
specifier|const
block|{
return|return
name|UseHVXOps
operator|&&
operator|!
name|UseHVXDblOps
return|;
block|}
name|bool
name|useLongCalls
argument_list|()
specifier|const
block|{
return|return
name|UseLongCalls
return|;
block|}
name|bool
name|useBSBScheduling
argument_list|()
specifier|const
block|{
return|return
name|UseBSBScheduling
return|;
block|}
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
name|override
block|;
comment|// Always use the TargetLowering default scheduler.
comment|// FIXME: This will use the vliw scheduler which is probably just hurting
comment|// compiler time and will be removed eventually anyway.
name|bool
name|enableMachineSchedDefaultSched
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|AntiDepBreakMode
name|getAntiDepBreakMode
argument_list|()
specifier|const
name|override
block|{
return|return
name|ANTIDEP_ALL
return|;
block|}
name|bool
name|enablePostRAScheduler
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|enableSubRegLiveness
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getCPUString
argument_list|()
specifier|const
block|{
return|return
name|CPUString
return|;
block|}
comment|// Threshold for small data section
name|unsigned
name|getSmallDataThreshold
argument_list|()
specifier|const
block|{
return|return
name|Hexagon_SMALL_DATA_THRESHOLD
return|;
block|}
specifier|const
name|HexagonArchEnum
operator|&
name|getHexagonArchVersion
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
return|;
block|}
name|void
name|getPostRAMutations
argument_list|(
argument|std::vector<std::unique_ptr<ScheduleDAGMutation>>&Mutations
argument_list|)
specifier|const
name|override
block|;
name|void
name|getSMSMutations
argument_list|(
argument|std::vector<std::unique_ptr<ScheduleDAGMutation>>&Mutations
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Perform target specific adjustments to the latency of a schedule
comment|/// dependency.
name|void
name|adjustSchedDependency
argument_list|(
argument|SUnit *def
argument_list|,
argument|SUnit *use
argument_list|,
argument|SDep& dep
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getL1CacheLineSize
argument_list|()
specifier|const
block|;
name|unsigned
name|getL1PrefetchDistance
argument_list|()
specifier|const
block|;
name|private
operator|:
comment|// Helper function responsible for increasing the latency only.
name|void
name|updateLatency
argument_list|(
argument|MachineInstr&SrcInst
argument_list|,
argument|MachineInstr&DstInst
argument_list|,
argument|SDep&Dep
argument_list|)
specifier|const
block|;
name|void
name|changeLatency
argument_list|(
argument|SUnit *Src
argument_list|,
argument|SmallVector<SDep
argument_list|,
literal|4
argument|>&Deps
argument_list|,
argument|SUnit *Dst
argument_list|,
argument|unsigned Lat
argument_list|)
specifier|const
block|;
name|bool
name|isBestZeroLatency
argument_list|(
argument|SUnit *Src
argument_list|,
argument|SUnit *Dst
argument_list|,
argument|const HexagonInstrInfo *TII
argument_list|)
specifier|const
block|;
name|void
name|changePhiLatency
argument_list|(
argument|MachineInstr&SrcInst
argument_list|,
argument|SUnit *Dst
argument_list|,
argument|SDep&Dep
argument_list|)
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

end_unit

