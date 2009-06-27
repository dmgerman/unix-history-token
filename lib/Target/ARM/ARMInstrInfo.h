begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMInstrInfo.h - ARM Instruction Information -------------*- C++ -*-===//
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
comment|// This file contains the ARM implementation of the TargetInstrInfo class.
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
name|ARMINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
comment|/// ARMII - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|ARMII
block|{
enum|enum
block|{
comment|//===------------------------------------------------------------------===//
comment|// Instruction Flags.
comment|//===------------------------------------------------------------------===//
comment|// This four-bit field describes the addressing mode used.
name|AddrModeMask
init|=
literal|0xf
block|,
name|AddrModeNone
init|=
literal|0
block|,
name|AddrMode1
init|=
literal|1
block|,
name|AddrMode2
init|=
literal|2
block|,
name|AddrMode3
init|=
literal|3
block|,
name|AddrMode4
init|=
literal|4
block|,
name|AddrMode5
init|=
literal|5
block|,
name|AddrModeT1
init|=
literal|6
block|,
name|AddrModeT2
init|=
literal|7
block|,
name|AddrModeT4
init|=
literal|8
block|,
name|AddrModeTs
init|=
literal|9
block|,
comment|// i8 * 4 for pc and sp relative data
comment|// Size* - Flags to keep track of the size of an instruction.
name|SizeShift
init|=
literal|4
block|,
name|SizeMask
init|=
literal|7
operator|<<
name|SizeShift
block|,
name|SizeSpecial
init|=
literal|1
block|,
comment|// 0 byte pseudo or special case.
name|Size8Bytes
init|=
literal|2
block|,
name|Size4Bytes
init|=
literal|3
block|,
name|Size2Bytes
init|=
literal|4
block|,
comment|// IndexMode - Unindex, pre-indexed, or post-indexed. Only valid for load
comment|// and store ops
name|IndexModeShift
init|=
literal|7
block|,
name|IndexModeMask
init|=
literal|3
operator|<<
name|IndexModeShift
block|,
name|IndexModePre
init|=
literal|1
block|,
name|IndexModePost
init|=
literal|2
block|,
comment|//===------------------------------------------------------------------===//
comment|// Misc flags.
comment|// UnaryDP - Indicates this is a unary data processing instruction, i.e.
comment|// it doesn't have a Rn operand.
name|UnaryDP
init|=
literal|1
operator|<<
literal|9
block|,
comment|//===------------------------------------------------------------------===//
comment|// Instruction encoding formats.
comment|//
name|FormShift
init|=
literal|10
block|,
name|FormMask
init|=
literal|0x1f
operator|<<
name|FormShift
block|,
comment|// Pseudo instructions
name|Pseudo
init|=
literal|0
operator|<<
name|FormShift
block|,
comment|// Multiply instructions
name|MulFrm
init|=
literal|1
operator|<<
name|FormShift
block|,
comment|// Branch instructions
name|BrFrm
init|=
literal|2
operator|<<
name|FormShift
block|,
name|BrMiscFrm
init|=
literal|3
operator|<<
name|FormShift
block|,
comment|// Data Processing instructions
name|DPFrm
init|=
literal|4
operator|<<
name|FormShift
block|,
name|DPSoRegFrm
init|=
literal|5
operator|<<
name|FormShift
block|,
comment|// Load and Store
name|LdFrm
init|=
literal|6
operator|<<
name|FormShift
block|,
name|StFrm
init|=
literal|7
operator|<<
name|FormShift
block|,
name|LdMiscFrm
init|=
literal|8
operator|<<
name|FormShift
block|,
name|StMiscFrm
init|=
literal|9
operator|<<
name|FormShift
block|,
name|LdStMulFrm
init|=
literal|10
operator|<<
name|FormShift
block|,
comment|// Miscellaneous arithmetic instructions
name|ArithMiscFrm
init|=
literal|11
operator|<<
name|FormShift
block|,
comment|// Extend instructions
name|ExtFrm
init|=
literal|12
operator|<<
name|FormShift
block|,
comment|// VFP formats
name|VFPUnaryFrm
init|=
literal|13
operator|<<
name|FormShift
block|,
name|VFPBinaryFrm
init|=
literal|14
operator|<<
name|FormShift
block|,
name|VFPConv1Frm
init|=
literal|15
operator|<<
name|FormShift
block|,
name|VFPConv2Frm
init|=
literal|16
operator|<<
name|FormShift
block|,
name|VFPConv3Frm
init|=
literal|17
operator|<<
name|FormShift
block|,
name|VFPConv4Frm
init|=
literal|18
operator|<<
name|FormShift
block|,
name|VFPConv5Frm
init|=
literal|19
operator|<<
name|FormShift
block|,
name|VFPLdStFrm
init|=
literal|20
operator|<<
name|FormShift
block|,
name|VFPLdStMulFrm
init|=
literal|21
operator|<<
name|FormShift
block|,
name|VFPMiscFrm
init|=
literal|22
operator|<<
name|FormShift
block|,
comment|// Thumb format
name|ThumbFrm
init|=
literal|23
operator|<<
name|FormShift
block|,
comment|// NEON format
name|NEONFrm
init|=
literal|24
operator|<<
name|FormShift
block|,
name|NEONGetLnFrm
init|=
literal|25
operator|<<
name|FormShift
block|,
name|NEONSetLnFrm
init|=
literal|26
operator|<<
name|FormShift
block|,
name|NEONDupFrm
init|=
literal|27
operator|<<
name|FormShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// Field shifts - such shifts are used to set field while generating
comment|// machine instructions.
name|M_BitShift
init|=
literal|5
block|,
name|ShiftImmShift
init|=
literal|5
block|,
name|ShiftShift
init|=
literal|7
block|,
name|N_BitShift
init|=
literal|7
block|,
name|ImmHiShift
init|=
literal|8
block|,
name|SoRotImmShift
init|=
literal|8
block|,
name|RegRsShift
init|=
literal|8
block|,
name|ExtRotImmShift
init|=
literal|10
block|,
name|RegRdLoShift
init|=
literal|12
block|,
name|RegRdShift
init|=
literal|12
block|,
name|RegRdHiShift
init|=
literal|16
block|,
name|RegRnShift
init|=
literal|16
block|,
name|S_BitShift
init|=
literal|20
block|,
name|W_BitShift
init|=
literal|21
block|,
name|AM3_I_BitShift
init|=
literal|22
block|,
name|D_BitShift
init|=
literal|22
block|,
name|U_BitShift
init|=
literal|23
block|,
name|P_BitShift
init|=
literal|24
block|,
name|I_BitShift
init|=
literal|25
block|,
name|CondShift
init|=
literal|28
block|}
enum|;
block|}
name|class
name|ARMBaseInstrInfo
range|:
name|public
name|TargetInstrInfoImpl
block|{
specifier|const
name|ARMRegisterInfo
name|RI
block|;
name|protected
operator|:
comment|// Can be only subclassed.
name|explicit
name|ARMBaseInstrInfo
argument_list|(
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
name|public
operator|:
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
name|virtual
specifier|const
name|ARMRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
name|void
name|reMaterialize
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|const MachineInstr *Orig
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|convertToThreeAddress
argument_list|(
argument|MachineFunction::iterator&MFI
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|LiveVariables *LV
argument_list|)
specifier|const
block|;
comment|// Branch analysis.
name|virtual
name|bool
name|AnalyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|InsertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|canFoldMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|BlockHasNoFallThrough
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
comment|// Predication support.
name|virtual
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|ARMCC
operator|::
name|CondCodes
name|getPredicate
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|{
name|int
name|PIdx
operator|=
name|MI
operator|->
name|findFirstPredOperandIdx
argument_list|()
block|;
return|return
name|PIdx
operator|!=
operator|-
literal|1
condition|?
operator|(
name|ARMCC
operator|::
name|CondCodes
operator|)
name|MI
operator|->
name|getOperand
argument_list|(
name|PIdx
argument_list|)
operator|.
name|getImm
argument_list|()
else|:
name|ARMCC
operator|::
name|AL
return|;
block|}
name|virtual
name|bool
name|PredicateInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|SubsumesPredicate
argument_list|(
argument|const SmallVectorImpl<MachineOperand>&Pred1
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|DefinesPredicate
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|std::vector<MachineOperand>&Pred
argument_list|)
specifier|const
block|;
comment|/// GetInstSize - Returns the size of the specified MachineInstr.
comment|///
name|virtual
name|unsigned
name|GetInstSizeInBytes
argument_list|(
argument|const MachineInstr* MI
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|class
name|ARMInstrInfo
range|:
name|public
name|ARMBaseInstrInfo
block|{
name|public
operator|:
name|explicit
name|ARMInstrInfo
argument_list|(
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// Return true if the instruction is a register to register move and return
comment|/// the source and dest operands and their sub-register indices by reference.
name|virtual
name|bool
name|isMoveInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DstReg
argument_list|,
argument|unsigned&SrcSubIdx
argument_list|,
argument|unsigned&DstSubIdx
argument_list|)
specifier|const
block|;
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
name|bool
name|copyRegToReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|const TargetRegisterClass *DestRC
argument_list|,
argument|const TargetRegisterClass *SrcRC
argument_list|)
specifier|const
block|;
name|virtual
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
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|storeRegToAddr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Addr
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|;
name|virtual
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
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|loadRegFromAddr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Addr
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr* MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr* MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|MachineInstr* LoadMI
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

