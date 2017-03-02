begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LanaiInstrInfo.h - Lanai Instruction Information ---------*- C++ -*-===//
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
comment|// This file contains the Lanai implementation of the TargetInstrInfo class.
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
name|LLVM_LIB_TARGET_LANAI_LANAIINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_LANAIINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"LanaiRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"LanaiGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LanaiInstrInfo
range|:
name|public
name|LanaiGenInstrInfo
block|{
specifier|const
name|LanaiRegisterInfo
name|RegisterInfo
block|;
name|public
operator|:
name|LanaiInstrInfo
argument_list|()
block|;
comment|// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|// such, whenever a client has an instance of instruction info, it should
comment|// always be able to get register info as well (through this method).
name|virtual
specifier|const
name|LanaiRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RegisterInfo
return|;
block|}
name|bool
name|areMemAccessesTriviallyDisjoint
argument_list|(
argument|MachineInstr&MIa
argument_list|,
argument|MachineInstr&MIb
argument_list|,
argument|AliasAnalysis *AA
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isLoadFromStackSlotPostFE
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator Position
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|unsigned DestinationRegister
argument_list|,
argument|unsigned SourceRegister
argument_list|,
argument|bool KillSource
argument_list|)
specifier|const
name|override
block|;
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator Position
argument_list|,
argument|unsigned SourceRegister
argument_list|,
argument|bool IsKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RegisterClass
argument_list|,
argument|const TargetRegisterInfo *RegisterInfo
argument_list|)
specifier|const
name|override
block|;
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator Position
argument_list|,
argument|unsigned DestinationRegister
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RegisterClass
argument_list|,
argument|const TargetRegisterInfo *RegisterInfo
argument_list|)
specifier|const
name|override
block|;
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|getMemOpBaseRegImmOfs
argument_list|(
argument|MachineInstr&LdSt
argument_list|,
argument|unsigned&BaseReg
argument_list|,
argument|int64_t&Offset
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|getMemOpBaseRegImmOfsWidth
argument_list|(
argument|MachineInstr&LdSt
argument_list|,
argument|unsigned&BaseReg
argument_list|,
argument|int64_t&Offset
argument_list|,
argument|unsigned&Width
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|;
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|decomposeMachineOperandsTargetFlags
argument_list|(
argument|unsigned TF
argument_list|)
specifier|const
name|override
block|;
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|char
operator|*
operator|>>
name|getSerializableDirectMachineOperandTargetFlags
argument_list|()
specifier|const
name|override
block|;
name|bool
name|analyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TrueBlock
argument_list|,
argument|MachineBasicBlock *&FalseBlock
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Condition
argument_list|,
argument|bool AllowModify
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|removeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|int *BytesRemoved = nullptr
argument_list|)
specifier|const
name|override
block|;
comment|// For a comparison instruction, return the source registers in SrcReg and
comment|// SrcReg2 if having two register operands, and the value it compares against
comment|// in CmpValue. Return true if the comparison instruction can be analyzed.
name|bool
name|analyzeCompare
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&SrcReg2
argument_list|,
argument|int&CmpMask
argument_list|,
argument|int&CmpValue
argument_list|)
specifier|const
name|override
block|;
comment|// See if the comparison instruction can be converted into something more
comment|// efficient. E.g., on Lanai register-register instructions can set the flag
comment|// register, obviating the need for a separate compare.
name|bool
name|optimizeCompareInstr
argument_list|(
argument|MachineInstr&CmpInstr
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned SrcReg2
argument_list|,
argument|int CmpMask
argument_list|,
argument|int CmpValue
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
name|override
block|;
comment|// Analyze the given select instruction, returning true if it cannot be
comment|// understood. It is assumed that MI->isSelect() is true.
comment|//
comment|// When successful, return the controlling condition and the operands that
comment|// determine the true and false result values.
comment|//
comment|//   Result = SELECT Cond, TrueOp, FalseOp
comment|//
comment|// Lanai can optimize certain select instructions, for example by predicating
comment|// the instruction defining one of the operands and sets Optimizable to true.
name|bool
name|analyzeSelect
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|unsigned&TrueOp
argument_list|,
argument|unsigned&FalseOp
argument_list|,
argument|bool&Optimizable
argument_list|)
specifier|const
name|override
block|;
comment|// Given a select instruction that was understood by analyzeSelect and
comment|// returned Optimizable = true, attempt to optimize MI by merging it with one
comment|// of its operands. Returns NULL on failure.
comment|//
comment|// When successful, returns the new select instruction. The client is
comment|// responsible for deleting MI.
comment|//
comment|// If both sides of the select can be optimized, the TrueOp is modifed.
comment|// PreferFalse is not used.
name|MachineInstr
operator|*
name|optimizeSelect
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|SmallPtrSetImpl<MachineInstr *>&SeenMIs
argument_list|,
argument|bool PreferFalse
argument_list|)
specifier|const
name|override
block|;
name|bool
name|reverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Condition
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|insertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TrueBlock
argument_list|,
argument|MachineBasicBlock *FalseBlock
argument_list|,
argument|ArrayRef<MachineOperand> Condition
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|int *BytesAdded = nullptr
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isSPLSOpcode
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
switch|switch
condition|(
name|Opcode
condition|)
block|{
case|case
name|Lanai
operator|::
name|LDBs_RI
case|:
case|case
name|Lanai
operator|::
name|LDBz_RI
case|:
case|case
name|Lanai
operator|::
name|LDHs_RI
case|:
case|case
name|Lanai
operator|::
name|LDHz_RI
case|:
case|case
name|Lanai
operator|::
name|STB_RI
case|:
case|case
name|Lanai
operator|::
name|STH_RI
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
specifier|static
specifier|inline
name|bool
name|isRMOpcode
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
switch|switch
condition|(
name|Opcode
condition|)
block|{
case|case
name|Lanai
operator|::
name|LDW_RI
case|:
case|case
name|Lanai
operator|::
name|SW_RI
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
specifier|static
specifier|inline
name|bool
name|isRRMOpcode
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
switch|switch
condition|(
name|Opcode
condition|)
block|{
case|case
name|Lanai
operator|::
name|LDBs_RR
case|:
case|case
name|Lanai
operator|::
name|LDBz_RR
case|:
case|case
name|Lanai
operator|::
name|LDHs_RR
case|:
case|case
name|Lanai
operator|::
name|LDHz_RR
case|:
case|case
name|Lanai
operator|::
name|LDWz_RR
case|:
case|case
name|Lanai
operator|::
name|LDW_RR
case|:
case|case
name|Lanai
operator|::
name|STB_RR
case|:
case|case
name|Lanai
operator|::
name|STH_RR
case|:
case|case
name|Lanai
operator|::
name|SW_RR
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_LANAIINSTRINFO_H
end_comment

end_unit

