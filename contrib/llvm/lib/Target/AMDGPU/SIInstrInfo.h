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
name|LLVM_LIB_TARGET_R600_SIINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_SIINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SIDefines.h"
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
name|void
name|swapOperands
argument_list|(
argument|MachineBasicBlock::iterator Inst
argument_list|)
specifier|const
block|;
name|void
name|lowerScalarAbs
argument_list|(
argument|SmallVectorImpl<MachineInstr *>&Worklist
argument_list|,
argument|MachineInstr *Inst
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
name|splitScalar64BitBFE
argument_list|(
argument|SmallVectorImpl<MachineInstr *>&Worklist
argument_list|,
argument|MachineInstr *Inst
argument_list|)
specifier|const
block|;
name|void
name|addUsersToMoveToVALUWorklist
argument_list|(
argument|unsigned Reg
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&Worklist
argument_list|)
specifier|const
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getDestEquivalentVGPRClass
argument_list|(
argument|const MachineInstr&Inst
argument_list|)
specifier|const
block|;
name|bool
name|checkInstOffsetsDoNotOverlap
argument_list|(
argument|MachineInstr *MIa
argument_list|,
argument|MachineInstr *MIb
argument_list|)
specifier|const
block|;
name|unsigned
name|findUsedSGPR
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int OpIndices[
literal|3
argument|]
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|MachineInstr
operator|*
name|commuteInstructionImpl
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI
argument_list|,
argument|unsigned OpIdx0
argument_list|,
argument|unsigned OpIdx1
argument_list|)
specifier|const
name|override
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
name|bool
name|isReallyTriviallyReMaterializable
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|AliasAnalysis *AA
argument_list|)
specifier|const
name|override
block|;
name|bool
name|areLoadsFromSameBasePtr
argument_list|(
argument|SDNode *Load1
argument_list|,
argument|SDNode *Load2
argument_list|,
argument|int64_t&Offset1
argument_list|,
argument|int64_t&Offset2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|getMemOpBaseRegImmOfs
argument_list|(
argument|MachineInstr *LdSt
argument_list|,
argument|unsigned&BaseReg
argument_list|,
argument|unsigned&Offset
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|final
block|;
name|bool
name|shouldClusterLoads
argument_list|(
argument|MachineInstr *FirstLdSt
argument_list|,
argument|MachineInstr *SecondLdSt
argument_list|,
argument|unsigned NumLoads
argument_list|)
specifier|const
name|final
block|;
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
name|unsigned
name|calculateLDSSpillAddress
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|RegScavenger *RS
argument_list|,
argument|unsigned TmpReg
argument_list|,
argument|unsigned Offset
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
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
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|override
block|;
comment|// \brief Returns an opcode that can be used to move a value to a \p DstRC
comment|// register.  If there is no hardware instruction that can store to \p
comment|// DstRC, then AMDGPU::COPY is returned.
name|unsigned
name|getMovOpcode
argument_list|(
argument|const TargetRegisterClass *DstRC
argument_list|)
specifier|const
block|;
name|LLVM_READONLY
name|int
name|commuteOpcode
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|findCommutedOpIndices
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned&SrcOpIdx1
argument_list|,
argument|unsigned&SrcOpIdx2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|areMemAccessesTriviallyDisjoint
argument_list|(
argument|MachineInstr *MIa
argument_list|,
argument|MachineInstr *MIb
argument_list|,
argument|AliasAnalysis *AA = nullptr
argument_list|)
specifier|const
name|override
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
name|FoldImmediate
argument_list|(
argument|MachineInstr *UseMI
argument_list|,
argument|MachineInstr *DefMI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|MachineRegisterInfo *MRI
argument_list|)
specifier|const
name|final
block|;
name|unsigned
name|getMachineCSELookAheadLimit
argument_list|()
specifier|const
name|override
block|{
return|return
literal|500
return|;
block|}
name|MachineInstr
operator|*
name|convertToThreeAddress
argument_list|(
argument|MachineFunction::iterator&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MI
argument_list|,
argument|LiveVariables *LV
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|isSALU
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SALU
return|;
block|}
name|bool
name|isSALU
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SALU
return|;
block|}
specifier|static
name|bool
name|isVALU
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VALU
return|;
block|}
name|bool
name|isVALU
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VALU
return|;
block|}
specifier|static
name|bool
name|isSOP1
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOP1
return|;
block|}
name|bool
name|isSOP1
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOP1
return|;
block|}
specifier|static
name|bool
name|isSOP2
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOP2
return|;
block|}
name|bool
name|isSOP2
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOP2
return|;
block|}
specifier|static
name|bool
name|isSOPC
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOPC
return|;
block|}
name|bool
name|isSOPC
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOPC
return|;
block|}
specifier|static
name|bool
name|isSOPK
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOPK
return|;
block|}
name|bool
name|isSOPK
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOPK
return|;
block|}
specifier|static
name|bool
name|isSOPP
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOPP
return|;
block|}
name|bool
name|isSOPP
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SOPP
return|;
block|}
specifier|static
name|bool
name|isVOP1
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOP1
return|;
block|}
name|bool
name|isVOP1
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOP1
return|;
block|}
specifier|static
name|bool
name|isVOP2
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOP2
return|;
block|}
name|bool
name|isVOP2
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOP2
return|;
block|}
specifier|static
name|bool
name|isVOP3
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOP3
return|;
block|}
name|bool
name|isVOP3
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOP3
return|;
block|}
specifier|static
name|bool
name|isVOPC
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOPC
return|;
block|}
name|bool
name|isVOPC
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VOPC
return|;
block|}
specifier|static
name|bool
name|isMUBUF
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|MUBUF
return|;
block|}
name|bool
name|isMUBUF
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|MUBUF
return|;
block|}
specifier|static
name|bool
name|isMTBUF
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|MTBUF
return|;
block|}
name|bool
name|isMTBUF
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|MTBUF
return|;
block|}
specifier|static
name|bool
name|isSMRD
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SMRD
return|;
block|}
name|bool
name|isSMRD
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|SMRD
return|;
block|}
specifier|static
name|bool
name|isDS
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|DS
return|;
block|}
name|bool
name|isDS
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|DS
return|;
block|}
specifier|static
name|bool
name|isMIMG
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|MIMG
return|;
block|}
name|bool
name|isMIMG
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|MIMG
return|;
block|}
specifier|static
name|bool
name|isFLAT
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|FLAT
return|;
block|}
name|bool
name|isFLAT
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|FLAT
return|;
block|}
specifier|static
name|bool
name|isWQM
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|WQM
return|;
block|}
name|bool
name|isWQM
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|WQM
return|;
block|}
specifier|static
name|bool
name|isVGPRSpill
argument_list|(
argument|const MachineInstr&MI
argument_list|)
block|{
return|return
name|MI
operator|.
name|getDesc
argument_list|()
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VGPRSpill
return|;
block|}
name|bool
name|isVGPRSpill
argument_list|(
argument|uint16_t Opcode
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|TSFlags
operator|&
name|SIInstrFlags
operator|::
name|VGPRSpill
return|;
block|}
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
argument_list|,
argument|unsigned OpSize
argument_list|)
specifier|const
block|;
name|bool
name|isLiteralConstant
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|unsigned OpSize
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
comment|/// \brief Returns true if this operand uses the constant bus.
name|bool
name|usesConstantBus
argument_list|(
argument|const MachineRegisterInfo&MRI
argument_list|,
argument|const MachineOperand&MO
argument_list|,
argument|unsigned OpSize
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if this instruction has any modifiers.
comment|///  e.g. src[012]_mod, omod, clamp.
name|bool
name|hasModifiers
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|hasModifiersSet
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned OpName
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
block|;
comment|/// \brief Return the size in bytes of the operand OpNo on the given
comment|// instruction opcode.
name|unsigned
name|getOpSize
argument_list|(
argument|uint16_t Opcode
argument_list|,
argument|unsigned OpNo
argument_list|)
specifier|const
block|{
specifier|const
name|MCOperandInfo
operator|&
name|OpInfo
operator|=
name|get
argument_list|(
name|Opcode
argument_list|)
operator|.
name|OpInfo
index|[
name|OpNo
index|]
block|;
if|if
condition|(
name|OpInfo
operator|.
name|RegClass
operator|==
operator|-
literal|1
condition|)
block|{
comment|// If this is an immediate operand, this must be a 32-bit literal.
name|assert
argument_list|(
name|OpInfo
operator|.
name|OperandType
operator|==
name|MCOI
operator|::
name|OPERAND_IMMEDIATE
argument_list|)
expr_stmt|;
return|return
literal|4
return|;
block|}
return|return
name|RI
operator|.
name|getRegClass
argument_list|(
name|OpInfo
operator|.
name|RegClass
argument_list|)
operator|->
name|getSize
argument_list|()
return|;
block|}
comment|/// \brief This form should usually be preferred since it handles operands
comment|/// with unknown register classes.
name|unsigned
name|getOpSize
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned OpNo
argument_list|)
specifier|const
block|{
return|return
name|getOpRegClass
argument_list|(
name|MI
argument_list|,
name|OpNo
argument_list|)
operator|->
name|getSize
argument_list|()
return|;
block|}
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
comment|/// \brief Check if \p MO is a legal operand if it was the \p OpIdx Operand
comment|/// for \p MI.
name|bool
name|isOperandLegal
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpIdx
argument_list|,
argument|const MachineOperand *MO = nullptr
argument_list|)
specifier|const
block|;
comment|/// \brief Check if \p MO would be a valid operand for the given operand
comment|/// definition \p OpInfo. Note this does not attempt to validate constant bus
comment|/// restrictions (e.g. literal constant usage).
name|bool
name|isLegalVSrcOperand
argument_list|(
argument|const MachineRegisterInfo&MRI
argument_list|,
argument|const MCOperandInfo&OpInfo
argument_list|,
argument|const MachineOperand&MO
argument_list|)
specifier|const
block|;
comment|/// \brief Check if \p MO (a register operand) is a legal register for the
comment|/// given operand description.
name|bool
name|isLegalRegOperand
argument_list|(
argument|const MachineRegisterInfo&MRI
argument_list|,
argument|const MCOperandInfo&OpInfo
argument_list|,
argument|const MachineOperand&MO
argument_list|)
specifier|const
block|;
comment|/// \brief Legalize operands in \p MI by either commuting it or inserting a
comment|/// copy of src1.
name|void
name|legalizeOperandsVOP2
argument_list|(
argument|MachineRegisterInfo&MRI
argument_list|,
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// \brief Fix operands in \p MI to satisfy constant bus requirements.
name|void
name|legalizeOperandsVOP3
argument_list|(
argument|MachineRegisterInfo&MRI
argument_list|,
argument|MachineInstr *MI
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
comment|/// \brief Split an SMRD instruction into two smaller loads of half the
comment|//  size storing the results in \p Lo and \p Hi.
name|void
name|splitSMRD
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const TargetRegisterClass *HalfRC
argument_list|,
argument|unsigned HalfImmOp
argument_list|,
argument|unsigned HalfSGPROp
argument_list|,
argument|MachineInstr *&Lo
argument_list|,
argument|MachineInstr *&Hi
argument_list|)
specifier|const
block|;
name|void
name|moveSMRDToVALU
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&Worklist
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
name|insertWaitStates
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int Count
argument_list|)
specifier|const
block|;
comment|/// \brief Returns the operand named \p Op.  If \p MI does not have an
comment|/// operand named \c Op, this function returns nullptr.
name|LLVM_READONLY
name|MachineOperand
operator|*
name|getNamedOperand
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned OperandName
argument_list|)
specifier|const
block|;
name|LLVM_READONLY
specifier|const
name|MachineOperand
operator|*
name|getNamedOperand
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned OpName
argument_list|)
specifier|const
block|{
return|return
name|getNamedOperand
argument_list|(
name|const_cast
operator|<
name|MachineInstr
operator|&
operator|>
operator|(
name|MI
operator|)
argument_list|,
name|OpName
argument_list|)
return|;
block|}
comment|/// Get required immediate operand
name|int64_t
name|getNamedImmOperand
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned OpName
argument_list|)
specifier|const
block|{
name|int
name|Idx
operator|=
name|AMDGPU
operator|::
name|getNamedOperandIdx
argument_list|(
name|MI
operator|.
name|getOpcode
argument_list|()
argument_list|,
name|OpName
argument_list|)
block|;
return|return
name|MI
operator|.
name|getOperand
argument_list|(
name|Idx
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
name|uint64_t
name|getDefaultRsrcDataFormat
argument_list|()
specifier|const
block|;
name|uint64_t
name|getScratchRsrcWords23
argument_list|()
specifier|const
block|;
name|bool
name|isLowLatencyInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|bool
name|isHighLatencyInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|namespace
name|AMDGPU
block|{
name|LLVM_READONLY
name|int
name|getVOPe64
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|LLVM_READONLY
name|int
name|getVOPe32
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|LLVM_READONLY
name|int
name|getCommuteRev
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|LLVM_READONLY
name|int
name|getCommuteOrig
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|LLVM_READONLY
name|int
name|getAddr64Inst
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|LLVM_READONLY
name|int
name|getAtomicRetOp
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|)
function_decl|;
name|LLVM_READONLY
name|int
name|getAtomicNoRetOp
parameter_list|(
name|uint16_t
name|Opcode
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
name|namespace
name|SI
block|{
name|namespace
name|KernelInputOffsets
block|{
comment|/// Offsets in bytes from the start of the input buffer
enum|enum
name|Offsets
block|{
name|NGROUPS_X
init|=
literal|0
block|,
name|NGROUPS_Y
init|=
literal|4
block|,
name|NGROUPS_Z
init|=
literal|8
block|,
name|GLOBAL_SIZE_X
init|=
literal|12
block|,
name|GLOBAL_SIZE_Y
init|=
literal|16
block|,
name|GLOBAL_SIZE_Z
init|=
literal|20
block|,
name|LOCAL_SIZE_X
init|=
literal|24
block|,
name|LOCAL_SIZE_Y
init|=
literal|28
block|,
name|LOCAL_SIZE_Z
init|=
literal|32
block|}
enum|;
block|}
comment|// End namespace KernelInputOffsets
block|}
comment|// End namespace SI
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

