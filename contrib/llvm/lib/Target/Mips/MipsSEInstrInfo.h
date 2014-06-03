begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsSEInstrInfo.h - Mips32/64 Instruction Information ---*- C++ -*-===//
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
comment|// This file contains the Mips32/64 implementation of the TargetInstrInfo class.
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
name|MIPSSEINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSSEINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"MipsInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsSERegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsSEInstrInfo
range|:
name|public
name|MipsInstrInfo
block|{
specifier|const
name|MipsSERegisterInfo
name|RI
block|;
name|bool
name|IsN64
block|;
name|public
operator|:
name|explicit
name|MipsSEInstrInfo
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
argument|MachineBasicBlock::iterator MI
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
argument|MachineBasicBlock::iterator MI
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
comment|/// Emit a series of instructions to load an immediate. If NewImm is a
comment|/// non-NULL parameter, the last instruction is not emitted, but instead
comment|/// its immediate operand is returned in NewImm.
name|unsigned
name|loadImmediate
argument_list|(
argument|int64_t Imm
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator II
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned *NewImm
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
name|expandRetRA
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned Opc
argument_list|)
specifier|const
block|;
name|std
operator|::
name|pair
operator|<
name|bool
block|,
name|bool
operator|>
name|compareOpndSize
argument_list|(
argument|unsigned Opc
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|expandPseudoMFHiLo
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned NewOpc
argument_list|)
specifier|const
block|;
name|void
name|expandPseudoMTLoHi
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned LoOpc
argument_list|,
argument|unsigned HiOpc
argument_list|,
argument|bool HasExplicitDef
argument_list|)
specifier|const
block|;
comment|/// Expand pseudo Int-to-FP conversion instructions.
comment|///
comment|/// For example, the following pseudo instruction
comment|///  PseudoCVT_D32_W D2, A5
comment|/// gets expanded into these two instructions:
comment|///  MTC1 F4, A5
comment|///  CVT_D32_W D2, F4
comment|///
comment|/// We do this expansion post-RA to avoid inserting a floating point copy
comment|/// instruction between MTC1 and CVT_D32_W.
name|void
name|expandCvtFPInt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned CvtOpc
argument_list|,
argument|unsigned MovOpc
argument_list|,
argument|bool IsI64
argument_list|)
specifier|const
block|;
name|void
name|expandExtractElementF64
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|bool FP64
argument_list|)
specifier|const
block|;
name|void
name|expandBuildPairF64
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|bool FP64
argument_list|)
specifier|const
block|;
name|void
name|expandEhReturn
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

