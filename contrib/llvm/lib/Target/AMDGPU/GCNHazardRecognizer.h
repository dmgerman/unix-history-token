begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GCNHazardRecognizers.h - GCN Hazard Recognizers ---------*- C++ -*-===//
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
comment|// This file defines hazard recognizers for scheduling on GCN processors.
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
name|LLVM_LIB_TARGET_AMDGPUHAZARDRECOGNIZERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPUHAZARDRECOGNIZERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|ScheduleDAG
decl_stmt|;
name|class
name|SIInstrInfo
decl_stmt|;
name|class
name|SISubtarget
decl_stmt|;
name|class
name|GCNHazardRecognizer
name|final
range|:
name|public
name|ScheduleHazardRecognizer
block|{
comment|// This variable stores the instruction that has been emitted this cycle. It
comment|// will be added to EmittedInstrs, when AdvanceCycle() or RecedeCycle() is
comment|// called.
name|MachineInstr
operator|*
name|CurrCycleInstr
block|;
name|std
operator|::
name|list
operator|<
name|MachineInstr
operator|*
operator|>
name|EmittedInstrs
block|;
specifier|const
name|MachineFunction
operator|&
name|MF
block|;
specifier|const
name|SISubtarget
operator|&
name|ST
block|;
specifier|const
name|SIInstrInfo
operator|&
name|TII
block|;
name|int
name|getWaitStatesSince
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|MachineInstr
operator|*
argument_list|)
operator|>
name|IsHazard
argument_list|)
block|;
name|int
name|getWaitStatesSinceDef
argument_list|(
argument|unsigned Reg
argument_list|,
argument|function_ref<bool(MachineInstr *)> IsHazardDef =                                 [](MachineInstr *) { return true; }
argument_list|)
block|;
name|int
name|getWaitStatesSinceSetReg
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|MachineInstr
operator|*
argument_list|)
operator|>
name|IsHazard
argument_list|)
block|;
name|int
name|checkSMEMSoftClauseHazards
argument_list|(
name|MachineInstr
operator|*
name|SMEM
argument_list|)
block|;
name|int
name|checkSMRDHazards
argument_list|(
name|MachineInstr
operator|*
name|SMRD
argument_list|)
block|;
name|int
name|checkVMEMHazards
argument_list|(
name|MachineInstr
operator|*
name|VMEM
argument_list|)
block|;
name|int
name|checkDPPHazards
argument_list|(
name|MachineInstr
operator|*
name|DPP
argument_list|)
block|;
name|int
name|checkDivFMasHazards
argument_list|(
name|MachineInstr
operator|*
name|DivFMas
argument_list|)
block|;
name|int
name|checkGetRegHazards
argument_list|(
name|MachineInstr
operator|*
name|GetRegInstr
argument_list|)
block|;
name|int
name|checkSetRegHazards
argument_list|(
name|MachineInstr
operator|*
name|SetRegInstr
argument_list|)
block|;
name|int
name|createsVALUHazard
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|int
name|checkVALUHazards
argument_list|(
name|MachineInstr
operator|*
name|VALU
argument_list|)
block|;
name|int
name|checkRWLaneHazards
argument_list|(
name|MachineInstr
operator|*
name|RWLane
argument_list|)
block|;
name|int
name|checkRFEHazards
argument_list|(
name|MachineInstr
operator|*
name|RFE
argument_list|)
block|;
name|int
name|checkAnyInstHazards
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|int
name|checkReadM0Hazards
argument_list|(
name|MachineInstr
operator|*
name|SMovRel
argument_list|)
block|;
name|public
operator|:
name|GCNHazardRecognizer
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
comment|// We can only issue one instruction per cycle.
name|bool
name|atIssueLimit
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|void
name|EmitInstruction
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|;
name|void
name|EmitInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|)
name|override
block|;
name|HazardType
name|getHazardType
argument_list|(
argument|SUnit *SU
argument_list|,
argument|int Stalls
argument_list|)
name|override
block|;
name|void
name|EmitNoop
argument_list|()
name|override
block|;
name|unsigned
name|PreEmitNoops
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|;
name|unsigned
name|PreEmitNoops
argument_list|(
argument|MachineInstr *
argument_list|)
name|override
block|;
name|void
name|AdvanceCycle
argument_list|()
name|override
block|;
name|void
name|RecedeCycle
argument_list|()
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
comment|//LLVM_LIB_TARGET_AMDGPUHAZARDRECOGNIZERS_H
end_comment

end_unit

