begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Thumb2InstrInfo.h - Thumb-2 Instruction Information -----*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_THUMB2INSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_THUMB2INSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"ARMBaseInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ThumbRegisterInfo.h"
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
name|ThumbRegisterInfo
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
comment|/// Return the noop instruction to use for a noop.
name|void
name|getNoop
argument_list|(
argument|MCInst&NopInst
argument_list|)
specifier|const
name|override
block|;
comment|// Return the non-pre/post incrementing version of 'Opc'. Return 0
comment|// if there is not such an opcode.
name|unsigned
name|getUnindexedOpcode
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
name|override
block|;
name|void
name|ReplaceTailWithBranchTo
argument_list|(
argument|MachineBasicBlock::iterator Tail
argument_list|,
argument|MachineBasicBlock *NewDest
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isLegalToSplitMBBAt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|)
specifier|const
name|override
block|;
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|)
specifier|const
name|override
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
name|override
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
name|override
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
specifier|const
name|ThumbRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
name|RI
return|;
block|}
name|private
operator|:
name|void
name|expandLoadStackGuard
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|override
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
operator|&
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

end_unit

