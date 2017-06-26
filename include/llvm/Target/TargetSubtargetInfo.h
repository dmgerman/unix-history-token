begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Target/TargetSubtargetInfo.h - Target Information ---*- C++ -*-===//
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
name|LLVM_TARGET_TARGETSUBTARGETINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETSUBTARGETINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/PBQPRAConstraint.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAGMutation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SchedulerRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallLowering
decl_stmt|;
name|class
name|InstrItineraryData
decl_stmt|;
struct_decl|struct
name|InstrStage
struct_decl|;
name|class
name|InstructionSelector
decl_stmt|;
name|class
name|LegalizerInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
struct_decl|struct
name|MachineSchedPolicy
struct_decl|;
struct_decl|struct
name|MCReadAdvanceEntry
struct_decl|;
struct_decl|struct
name|MCWriteLatencyEntry
struct_decl|;
struct_decl|struct
name|MCWriteProcResEntry
struct_decl|;
name|class
name|RegisterBankInfo
decl_stmt|;
name|class
name|SDep
decl_stmt|;
name|class
name|SelectionDAGTargetInfo
decl_stmt|;
struct_decl|struct
name|SubtargetFeatureKV
struct_decl|;
struct_decl|struct
name|SubtargetInfoKV
struct_decl|;
name|class
name|SUnit
decl_stmt|;
name|class
name|TargetFrameLowering
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetSchedModel
decl_stmt|;
name|class
name|Triple
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// TargetSubtargetInfo - Generic base class for all target subtargets.  All
comment|/// Target-specific options that control code generation and printing should
comment|/// be exposed through a TargetSubtargetInfo-derived class.
comment|///
name|class
name|TargetSubtargetInfo
range|:
name|public
name|MCSubtargetInfo
block|{
name|protected
operator|:
comment|// Can only create subclasses...
name|TargetSubtargetInfo
argument_list|(
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|ArrayRef<SubtargetFeatureKV> PF
argument_list|,
argument|ArrayRef<SubtargetFeatureKV> PD
argument_list|,
argument|const SubtargetInfoKV *ProcSched
argument_list|,
argument|const MCWriteProcResEntry *WPR
argument_list|,
argument|const MCWriteLatencyEntry *WL
argument_list|,
argument|const MCReadAdvanceEntry *RA
argument_list|,
argument|const InstrStage *IS
argument_list|,
argument|const unsigned *OC
argument_list|,
argument|const unsigned *FP
argument_list|)
block|;
name|public
operator|:
comment|// AntiDepBreakMode - Type of anti-dependence breaking that should
comment|// be performed before post-RA scheduling.
name|using
name|AntiDepBreakMode
operator|=
expr|enum
block|{
name|ANTIDEP_NONE
block|,
name|ANTIDEP_CRITICAL
block|,
name|ANTIDEP_ALL
block|}
block|;
name|using
name|RegClassVector
operator|=
name|SmallVectorImpl
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|>
block|;
name|TargetSubtargetInfo
argument_list|()
operator|=
name|delete
block|;
name|TargetSubtargetInfo
argument_list|(
specifier|const
name|TargetSubtargetInfo
operator|&
argument_list|)
operator|=
name|delete
block|;
name|TargetSubtargetInfo
operator|&
name|operator
operator|=
operator|(
specifier|const
name|TargetSubtargetInfo
operator|&
operator|)
operator|=
name|delete
block|;
operator|~
name|TargetSubtargetInfo
argument_list|()
name|override
block|;
name|virtual
name|bool
name|isXRaySupported
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// Interfaces to the major aspects of target machine information:
comment|//
comment|// -- Instruction opcode and operand information
comment|// -- Pipelines and scheduling information
comment|// -- Stack frame information
comment|// -- Selection DAG lowering information
comment|// -- Call lowering information
comment|//
comment|// N.B. These objects may change during compilation. It's not safe to cache
comment|// them between functions.
name|virtual
specifier|const
name|TargetInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|SelectionDAGTargetInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|CallLowering
operator|*
name|getCallLowering
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|// FIXME: This lets targets specialize the selector by subtarget (which lets
comment|// us do things like a dedicated avx512 selector).  However, we might want
comment|// to also specialize selectors by MachineFunction, which would let us be
comment|// aware of optsize/optnone and such.
name|virtual
specifier|const
name|InstructionSelector
operator|*
name|getInstructionSelector
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Target can subclass this hook to select a different DAG scheduler.
name|virtual
name|RegisterScheduler
operator|::
name|FunctionPassCtor
name|getDAGScheduler
argument_list|(
argument|CodeGenOpt::Level
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|LegalizerInfo
operator|*
name|getLegalizerInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// getRegisterInfo - If register information is available, return it.  If
comment|/// not, return null.
name|virtual
specifier|const
name|TargetRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// If the information for the register banks is available, return it.
comment|/// Otherwise return nullptr.
name|virtual
specifier|const
name|RegisterBankInfo
operator|*
name|getRegBankInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// getInstrItineraryData - Returns instruction itinerary data for the target
comment|/// or specific subtarget.
name|virtual
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Resolve a SchedClass at runtime, where SchedClass identifies an
comment|/// MCSchedClassDesc with the isVariant property. This may return the ID of
comment|/// another variant SchedClass, but repeated invocation must quickly terminate
comment|/// in a nonvariant SchedClass.
name|virtual
name|unsigned
name|resolveSchedClass
argument_list|(
argument|unsigned SchedClass
argument_list|,
argument|const MachineInstr *MI
argument_list|,
argument|const TargetSchedModel *SchedModel
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief True if the subtarget should run MachineScheduler after aggressive
comment|/// coalescing.
comment|///
comment|/// This currently replaces the SelectionDAG scheduler with the "source" order
comment|/// scheduler (though see below for an option to turn this off and use the
comment|/// TargetLowering preference). It does not yet disable the postRA scheduler.
name|virtual
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
block|;
comment|/// \brief Support printing of [latency:throughput] comment in output .S file.
name|virtual
name|bool
name|supportPrintSchedInfo
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief True if the machine scheduler should disable the TLI preference
comment|/// for preRA scheduling with the source level scheduler.
name|virtual
name|bool
name|enableMachineSchedDefaultSched
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief True if the subtarget should enable joining global copies.
comment|///
comment|/// By default this is enabled if the machine scheduler is enabled, but
comment|/// can be overridden.
name|virtual
name|bool
name|enableJoinGlobalCopies
argument_list|()
specifier|const
block|;
comment|/// True if the subtarget should run a scheduler after register allocation.
comment|///
comment|/// By default this queries the PostRAScheduling bit in the scheduling model
comment|/// which is the preferred way to influence this.
name|virtual
name|bool
name|enablePostRAScheduler
argument_list|()
specifier|const
block|;
comment|/// \brief True if the subtarget should run the atomic expansion pass.
name|virtual
name|bool
name|enableAtomicExpand
argument_list|()
specifier|const
block|;
comment|/// \brief Override generic scheduling policy within a region.
comment|///
comment|/// This is a convenient way for targets that don't provide any custom
comment|/// scheduling heuristics (no custom MachineSchedStrategy) to make
comment|/// changes to the generic scheduling policy.
name|virtual
name|void
name|overrideSchedPolicy
argument_list|(
argument|MachineSchedPolicy&Policy
argument_list|,
argument|unsigned NumRegionInstrs
argument_list|)
specifier|const
block|{}
comment|// \brief Perform target specific adjustments to the latency of a schedule
comment|// dependency.
name|virtual
name|void
name|adjustSchedDependency
argument_list|(
argument|SUnit *def
argument_list|,
argument|SUnit *use
argument_list|,
argument|SDep&dep
argument_list|)
specifier|const
block|{}
comment|// For use with PostRAScheduling: get the anti-dependence breaking that should
comment|// be performed before post-RA scheduling.
name|virtual
name|AntiDepBreakMode
name|getAntiDepBreakMode
argument_list|()
specifier|const
block|{
return|return
name|ANTIDEP_NONE
return|;
block|}
comment|// For use with PostRAScheduling: in CriticalPathRCs, return any register
comment|// classes that should only be considered for anti-dependence breaking if they
comment|// are on the critical path.
name|virtual
name|void
name|getCriticalPathRCs
argument_list|(
argument|RegClassVector&CriticalPathRCs
argument_list|)
specifier|const
block|{
return|return
name|CriticalPathRCs
operator|.
name|clear
argument_list|()
return|;
block|}
comment|// \brief Provide an ordered list of schedule DAG mutations for the post-RA
comment|// scheduler.
name|virtual
name|void
name|getPostRAMutations
argument_list|(
argument|std::vector<std::unique_ptr<ScheduleDAGMutation>>&Mutations
argument_list|)
specifier|const
block|{   }
comment|// \brief Provide an ordered list of schedule DAG mutations for the machine
comment|// pipeliner.
name|virtual
name|void
name|getSMSMutations
argument_list|(
argument|std::vector<std::unique_ptr<ScheduleDAGMutation>>&Mutations
argument_list|)
specifier|const
block|{   }
comment|// For use with PostRAScheduling: get the minimum optimization level needed
comment|// to enable post-RA scheduling.
name|virtual
name|CodeGenOpt
operator|::
name|Level
name|getOptLevelToEnablePostRAScheduler
argument_list|()
specifier|const
block|{
return|return
name|CodeGenOpt
operator|::
name|Default
return|;
block|}
comment|/// \brief True if the subtarget should run the local reassignment
comment|/// heuristic of the register allocator.
comment|/// This heuristic may be compile time intensive, \p OptLevel provides
comment|/// a finer grain to tune the register allocator.
name|virtual
name|bool
name|enableRALocalReassignment
argument_list|(
argument|CodeGenOpt::Level OptLevel
argument_list|)
specifier|const
block|;
comment|/// \brief Enable use of alias analysis during code generation (during MI
comment|/// scheduling, DAGCombine, etc.).
name|virtual
name|bool
name|useAA
argument_list|()
specifier|const
block|;
comment|/// \brief Enable the use of the early if conversion pass.
name|virtual
name|bool
name|enableEarlyIfConversion
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return PBQPConstraint(s) for the target.
comment|///
comment|/// Override to provide custom PBQP constraints.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|PBQPRAConstraint
operator|>
name|getCustomPBQPConstraints
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Enable tracking of subregister liveness in register allocator.
comment|/// Please use MachineRegisterInfo::subRegLivenessEnabled() instead where
comment|/// possible.
name|virtual
name|bool
name|enableSubRegLiveness
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns string representation of scheduler comment
name|std
operator|::
name|string
name|getSchedInfoStr
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getSchedInfoStr
argument_list|(
argument|MCInst const&MCI
argument_list|)
specifier|const
name|override
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
comment|// LLVM_TARGET_TARGETSUBTARGETINFO_H
end_comment

end_unit

