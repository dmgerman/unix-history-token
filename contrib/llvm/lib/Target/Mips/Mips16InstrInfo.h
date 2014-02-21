begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Mips16InstrInfo.h - Mips16 Instruction Information ------*- C++ -*-===//
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
comment|// This file contains the Mips16 implementation of the TargetInstrInfo class.
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
name|MIPS16INSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS16INSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"Mips16RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Mips16InstrInfo
range|:
name|public
name|MipsInstrInfo
block|{
specifier|const
name|Mips16RegisterInfo
name|RI
block|;
name|public
operator|:
name|explicit
name|Mips16InstrInfo
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
specifier|const
name|MipsRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|;
comment|/// isLoadFromStackSlot - If the specified machine instruction is a direct
comment|/// load from a stack slot, return the virtual or physical register number of
comment|/// the destination along with the FrameIndex of the loaded stack slot.  If
comment|/// not, return 0.  This predicate must return 0 if the instruction has
comment|/// any side effects other than loading from the stack slot.
name|virtual
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
comment|/// isStoreToStackSlot - If the specified machine instruction is a direct
comment|/// store to a stack slot, return the virtual or physical register number of
comment|/// the source reg along with the FrameIndex of the loaded stack slot.  If
comment|/// not, return 0.  This predicate must return 0 if the instruction has
comment|/// any side effects other than storing to the stack slot.
name|virtual
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
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
name|virtual
name|void
name|storeRegToStack
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
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|loadRegFromStack
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
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getOppositeBranchOpc
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
block|;
comment|// Adjust SP by FrameSize bytes. Save RA, S0, S1
name|void
name|makeFrame
argument_list|(
argument|unsigned SP
argument_list|,
argument|int64_t FrameSize
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;
comment|// Adjust SP by FrameSize bytes. Restore RA, S0, S1
name|void
name|restoreFrame
argument_list|(
argument|unsigned SP
argument_list|,
argument|int64_t FrameSize
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;
comment|/// Adjust SP by Amount bytes.
name|void
name|adjustStackPtr
argument_list|(
argument|unsigned SP
argument_list|,
argument|int64_t Amount
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;
comment|/// Emit a series of instructions to load an immediate.
comment|// This is to adjust some FrameReg. We return the new register to be used
comment|// in place of FrameReg and the adjusted immediate field (&NewImm)
comment|//
name|unsigned
name|loadImmediate
argument_list|(
argument|unsigned FrameReg
argument_list|,
argument|int64_t Imm
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator II
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned&NewImm
argument_list|)
specifier|const
block|;
name|unsigned
name|basicLoadImmediate
argument_list|(
argument|unsigned FrameReg
argument_list|,
argument|int64_t Imm
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator II
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned&NewImm
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|validImmediate
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg
argument_list|,
argument|int64_t Amount
argument_list|)
block|;
specifier|static
name|bool
name|validSpImm8
argument_list|(
argument|int offset
argument_list|)
block|{
return|return
operator|(
operator|(
name|offset
operator|&
literal|7
operator|)
operator|==
literal|0
operator|)
operator|&&
name|isInt
operator|<
literal|11
operator|>
operator|(
name|offset
operator|)
return|;
block|}
comment|//
comment|// build the proper one based on the Imm field
comment|//
specifier|const
name|MCInstrDesc
operator|&
name|AddiuSpImm
argument_list|(
argument|int64_t Imm
argument_list|)
specifier|const
block|;
name|void
name|BuildAddiuSpImm
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|int64_t Imm
argument_list|)
specifier|const
block|;
name|unsigned
name|getInlineAsmLength
argument_list|(
argument|const char *Str
argument_list|,
argument|const MCAsmInfo&MAI
argument_list|)
specifier|const
block|;
name|private
operator|:
name|virtual
name|unsigned
name|getAnalyzableBrOpc
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
block|;
name|void
name|ExpandRetRA16
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned Opc
argument_list|)
specifier|const
block|;
comment|// Adjust SP by Amount bytes where bytes can be up to 32bit number.
name|void
name|adjustStackPtrBig
argument_list|(
argument|unsigned SP
argument_list|,
argument|int64_t Amount
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|unsigned Reg2
argument_list|)
specifier|const
block|;
comment|// Adjust SP by Amount bytes where bytes can be up to 32bit number.
name|void
name|adjustStackPtrBigUnrestricted
argument_list|(
argument|unsigned SP
argument_list|,
argument|int64_t Amount
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

