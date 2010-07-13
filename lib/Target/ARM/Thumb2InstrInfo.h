begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Thumb2InstrInfo.h - Thumb-2 Instruction Information ------*- C++ -*-===//
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
comment|// This file contains the Thumb-2 implementation of the TargetInstrInfo class.
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
name|THUMB2INSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|THUMB2INSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_include
include|#
directive|include
file|"ARMInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"Thumb2RegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ScheduleHazardRecognizer
decl_stmt|;
name|class
name|Thumb2InstrInfo
range|:
name|public
name|ARMBaseInstrInfo
block|{
name|Thumb2RegisterInfo
name|RI
block|;
name|public
operator|:
name|explicit
name|Thumb2InstrInfo
argument_list|(
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|// Return the non-pre/post incrementing version of 'Opc'. Return 0
comment|// if there is not such an opcode.
name|unsigned
name|getUnindexedOpcode
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
block|;
name|void
name|ReplaceTailWithBranchTo
argument_list|(
argument|MachineBasicBlock::iterator Tail
argument_list|,
argument|MachineBasicBlock *NewDest
argument_list|)
specifier|const
block|;
name|bool
name|isLegalToSplitMBBAt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|)
specifier|const
block|;
name|bool
name|isProfitableToIfCvt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned NumInstrs
argument_list|)
specifier|const
block|;
name|bool
name|isProfitableToIfCvt
argument_list|(
argument|MachineBasicBlock&TMBB
argument_list|,
argument|unsigned NumTInstrs
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|,
argument|unsigned NumFInstrs
argument_list|)
specifier|const
block|;
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|)
specifier|const
block|;
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|;
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|;
comment|/// scheduleTwoAddrSource - Schedule the copy / re-mat of the source of the
comment|/// two-addrss instruction inserted by two-address pass.
name|void
name|scheduleTwoAddrSource
argument_list|(
argument|MachineInstr *SrcMI
argument_list|,
argument|MachineInstr *UseMI
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|)
specifier|const
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
specifier|const
name|Thumb2RegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetPostRAHazardRecognizer
argument_list|(
argument|const InstrItineraryData&II
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// getITInstrPredicate - Valid only in Thumb2 mode. This function is identical
comment|/// to llvm::getInstrPredicate except it returns AL for conditional branch
comment|/// instructions which are "predicated", but are not in IT blocks.
name|ARMCC
operator|::
name|CondCodes
name|getITInstrPredicate
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
operator|&
name|PredReg
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// THUMB2INSTRUCTIONINFO_H
end_comment

end_unit

