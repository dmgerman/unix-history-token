begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIInstrInfo.h - SI Instruction Info Interface -----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Interface definition for SIInstrInfo.
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
name|SIINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SIINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SIRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SIInstrInfo
range|:
name|public
name|AMDGPUInstrInfo
block|{
name|private
operator|:
specifier|const
name|SIRegisterInfo
name|RI
block|;
name|unsigned
name|buildExtractSubReg
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|,
argument|MachineOperand&SuperReg
argument_list|,
argument|const TargetRegisterClass *SuperRC
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|const TargetRegisterClass *SubRC
argument_list|)
specifier|const
block|;
name|MachineOperand
name|buildExtractSubRegOrImm
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|,
argument|MachineOperand&SuperReg
argument_list|,
argument|const TargetRegisterClass *SuperRC
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|const TargetRegisterClass *SubRC
argument_list|)
specifier|const
block|;
name|unsigned
name|split64BitImm
argument_list|(
argument|SmallVectorImpl<MachineInstr *>&Worklist
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const MachineOperand&Op
argument_list|)
specifier|const
block|;
name|void
name|splitScalar64BitUnaryOp
argument_list|(
argument|SmallVectorImpl<MachineInstr *>&Worklist
argument_list|,
argument|MachineInstr *Inst
argument_list|,
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|void
name|splitScalar64BitBinaryOp
argument_list|(
argument|SmallVectorImpl<MachineInstr *>&Worklist
argument_list|,
argument|MachineInstr *Inst
argument_list|,
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|void
name|splitScalar64BitBCNT
argument_list|(
argument|SmallVectorImpl<MachineInstr *>&Worklist
argument_list|,
argument|MachineInstr *Inst
argument_list|)
specifier|const
block|;
name|void
name|addDescImplicitUseDef
argument_list|(
argument|const MCInstrDesc&Desc
argument_list|,
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|public
operator|:
name|explicit
name|SIInstrInfo
argument_list|(
specifier|const
name|AMDGPUSubtarget
operator|&
name|st
argument_list|)
block|;
specifier|const
name|SIRegisterInfo
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
name|override
block|;
name|void
name|storeRegToStackSlot
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
argument_list|)
specifier|const
name|override
block|;
name|void
name|loadRegFromStackSlot
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
argument_list|)
specifier|const
name|override
block|;
name|virtual
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
name|unsigned
name|commuteOpcode
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|MachineInstr
operator|*
name|commuteInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI=false
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTriviallyReMaterializable
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|AliasAnalysis *AA = nullptr
argument_list|)
specifier|const
block|;
name|MachineInstr
operator|*
name|buildMovInstr
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|unsigned SrcReg
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isMov
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSafeToMoveRegClassDefs
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isDS
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|;
name|int
name|isMIMG
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|;
name|int
name|isSMRD
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isVOP1
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isVOP2
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isVOP3
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isVOPC
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isInlineConstant
argument_list|(
argument|const APInt&Imm
argument_list|)
specifier|const
block|;
name|bool
name|isInlineConstant
argument_list|(
argument|const MachineOperand&MO
argument_list|)
specifier|const
block|;
name|bool
name|isLiteralConstant
argument_list|(
argument|const MachineOperand&MO
argument_list|)
specifier|const
block|;
name|bool
name|isImmOperandLegal
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|const MachineOperand&MO
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if this 64-bit VALU instruction has a 32-bit encoding.
comment|/// This function will return false if you pass it a 32-bit instruction.
name|bool
name|hasVALU32BitEncoding
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|verifyInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|StringRef&ErrInfo
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSALUInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
specifier|static
name|unsigned
name|getVALUOp
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|bool
name|isSALUOpSupportedOnVALU
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
comment|/// \brief Return the correct register class for \p OpNo.  For target-specific
comment|/// instructions, this will return the register class that has been defined
comment|/// in tablegen.  For generic instructions, like REG_SEQUENCE it will return
comment|/// the register class of its machine operand.
comment|/// to infer the correct register class base on the other operands.
specifier|const
name|TargetRegisterClass
operator|*
name|getOpRegClass
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned OpNo
argument_list|)
specifier|const
block|;\
comment|/// \returns true if it is legal for the operand at index \p OpNo
comment|/// to read a VGPR.
name|bool
name|canReadVGPR
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned OpNo
argument_list|)
specifier|const
block|;
comment|/// \brief Legalize the \p OpIndex operand of this instruction by inserting
comment|/// a MOV.  For example:
comment|/// ADD_I32_e32 VGPR0, 15
comment|/// to
comment|/// MOV VGPR1, 15
comment|/// ADD_I32_e32 VGPR0, VGPR1
comment|///
comment|/// If the operand being legalized is a register, then a COPY will be used
comment|/// instead of MOV.
name|void
name|legalizeOpWithMove
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned OpIdx
argument_list|)
specifier|const
block|;
comment|/// \brief Legalize all operands in this instruction.  This function may
comment|/// create new instruction and insert them before \p MI.
name|void
name|legalizeOperands
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|void
name|moveSMRDToVALU
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|)
specifier|const
block|;
comment|/// \brief Replace this instruction's opcode with the equivalent VALU
comment|/// opcode.  This function will also move the users of \p MI to the
comment|/// VALU if necessary.
name|void
name|moveToVALU
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|calculateIndirectAddress
argument_list|(
argument|unsigned RegIndex
argument_list|,
argument|unsigned Channel
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getIndirectAddrRegClass
argument_list|()
specifier|const
name|override
block|;
name|MachineInstrBuilder
name|buildIndirectWrite
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned ValueReg
argument_list|,
argument|unsigned Address
argument_list|,
argument|unsigned OffsetReg
argument_list|)
specifier|const
name|override
block|;
name|MachineInstrBuilder
name|buildIndirectRead
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned ValueReg
argument_list|,
argument|unsigned Address
argument_list|,
argument|unsigned OffsetReg
argument_list|)
specifier|const
name|override
block|;
name|void
name|reserveIndirectRegisters
argument_list|(
argument|BitVector&Reserved
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|LoadM0
argument_list|(
argument|MachineInstr *MoveRel
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned SavReg
argument_list|,
argument|unsigned IndexReg
argument_list|)
specifier|const
block|;
name|void
name|insertNOPs
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int Count
argument_list|)
specifier|const
block|;
comment|/// \brief Returns the operand named \p Op.  If \p MI does not have an
comment|/// operand named \c Op, this function returns nullptr.
specifier|const
name|MachineOperand
operator|*
name|getNamedOperand
argument_list|(
argument|const MachineInstr& MI
argument_list|,
argument|unsigned OperandName
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|namespace
name|AMDGPU
block|{
name|int
name|getVOPe64
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|int
name|getVOPe32
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|int
name|getCommuteRev
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|int
name|getCommuteOrig
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|int
name|getMCOpcode
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|,
name|unsigned
name|Gen
parameter_list|)
function_decl|;
specifier|const
name|uint64_t
name|RSRC_DATA_FORMAT
init|=
literal|0xf00000000000LL
decl_stmt|;
specifier|const
name|uint64_t
name|RSRC_TID_ENABLE
init|=
literal|1LL
operator|<<
literal|55
decl_stmt|;
block|}
comment|// End namespace AMDGPU
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|SIInstrFlags
block|{
enum|enum
name|Flags
block|{
comment|// First 4 bits are the instruction encoding
name|VM_CNT
init|=
literal|1
operator|<<
literal|0
block|,
name|EXP_CNT
init|=
literal|1
operator|<<
literal|1
block|,
name|LGKM_CNT
init|=
literal|1
operator|<<
literal|2
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//SIINSTRINFO_H
end_comment

end_unit

