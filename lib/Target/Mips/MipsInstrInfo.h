begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MipsInstrInfo.h - Mips Instruction Information -----------*- C++ -*-===//
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
comment|// This file contains the Mips implementation of the TargetInstrInfo class.
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
name|MIPSINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"Mips.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Mips
block|{
comment|// Mips Branch Codes
enum|enum
name|FPBranchCode
block|{
name|BRANCH_F
block|,
name|BRANCH_T
block|,
name|BRANCH_FL
block|,
name|BRANCH_TL
block|,
name|BRANCH_INVALID
block|}
enum|;
comment|// Mips Condition Codes
enum|enum
name|CondCode
block|{
comment|// To be used with float branch True
name|FCOND_F
block|,
name|FCOND_UN
block|,
name|FCOND_EQ
block|,
name|FCOND_UEQ
block|,
name|FCOND_OLT
block|,
name|FCOND_ULT
block|,
name|FCOND_OLE
block|,
name|FCOND_ULE
block|,
name|FCOND_SF
block|,
name|FCOND_NGLE
block|,
name|FCOND_SEQ
block|,
name|FCOND_NGL
block|,
name|FCOND_LT
block|,
name|FCOND_NGE
block|,
name|FCOND_LE
block|,
name|FCOND_NGT
block|,
comment|// To be used with float branch False
comment|// This conditions have the same mnemonic as the
comment|// above ones, but are used with a branch False;
name|FCOND_T
block|,
name|FCOND_OR
block|,
name|FCOND_NEQ
block|,
name|FCOND_OGL
block|,
name|FCOND_UGE
block|,
name|FCOND_OGE
block|,
name|FCOND_UGT
block|,
name|FCOND_OGT
block|,
name|FCOND_ST
block|,
name|FCOND_GLE
block|,
name|FCOND_SNE
block|,
name|FCOND_GL
block|,
name|FCOND_NLT
block|,
name|FCOND_GE
block|,
name|FCOND_NLE
block|,
name|FCOND_GT
block|,
comment|// Only integer conditions
name|COND_E
block|,
name|COND_GZ
block|,
name|COND_GEZ
block|,
name|COND_LZ
block|,
name|COND_LEZ
block|,
name|COND_NE
block|,
name|COND_INVALID
block|}
enum|;
comment|// Turn condition code into conditional branch opcode.
name|unsigned
name|GetCondBranchFromCond
parameter_list|(
name|CondCode
name|CC
parameter_list|)
function_decl|;
comment|/// GetOppositeBranchCondition - Return the inverse of the specified cond,
comment|/// e.g. turning COND_E to COND_NE.
name|CondCode
name|GetOppositeBranchCondition
argument_list|(
name|Mips
operator|::
name|CondCode
name|CC
argument_list|)
decl_stmt|;
comment|/// MipsCCToString - Map each FP condition code to its string
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|MipsFCCToString
argument_list|(
name|Mips
operator|::
name|CondCode
name|CC
argument_list|)
block|{
switch|switch
condition|(
name|CC
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown condition code"
argument_list|)
expr_stmt|;
case|case
name|FCOND_F
case|:
case|case
name|FCOND_T
case|:
return|return
literal|"f"
return|;
case|case
name|FCOND_UN
case|:
case|case
name|FCOND_OR
case|:
return|return
literal|"un"
return|;
case|case
name|FCOND_EQ
case|:
case|case
name|FCOND_NEQ
case|:
return|return
literal|"eq"
return|;
case|case
name|FCOND_UEQ
case|:
case|case
name|FCOND_OGL
case|:
return|return
literal|"ueq"
return|;
case|case
name|FCOND_OLT
case|:
case|case
name|FCOND_UGE
case|:
return|return
literal|"olt"
return|;
case|case
name|FCOND_ULT
case|:
case|case
name|FCOND_OGE
case|:
return|return
literal|"ult"
return|;
case|case
name|FCOND_OLE
case|:
case|case
name|FCOND_UGT
case|:
return|return
literal|"ole"
return|;
case|case
name|FCOND_ULE
case|:
case|case
name|FCOND_OGT
case|:
return|return
literal|"ule"
return|;
case|case
name|FCOND_SF
case|:
case|case
name|FCOND_ST
case|:
return|return
literal|"sf"
return|;
case|case
name|FCOND_NGLE
case|:
case|case
name|FCOND_GLE
case|:
return|return
literal|"ngle"
return|;
case|case
name|FCOND_SEQ
case|:
case|case
name|FCOND_SNE
case|:
return|return
literal|"seq"
return|;
case|case
name|FCOND_NGL
case|:
case|case
name|FCOND_GL
case|:
return|return
literal|"ngl"
return|;
case|case
name|FCOND_LT
case|:
case|case
name|FCOND_NLT
case|:
return|return
literal|"lt"
return|;
case|case
name|FCOND_NGE
case|:
case|case
name|FCOND_GE
case|:
return|return
literal|"ge"
return|;
case|case
name|FCOND_LE
case|:
case|case
name|FCOND_NLE
case|:
return|return
literal|"nle"
return|;
case|case
name|FCOND_NGT
case|:
case|case
name|FCOND_GT
case|:
return|return
literal|"gt"
return|;
block|}
block|}
block|}
comment|/// MipsII - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|MipsII
block|{
comment|/// Target Operand Flag enum.
enum|enum
name|TOF
block|{
comment|//===------------------------------------------------------------------===//
comment|// Mips Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
comment|/// MO_GOT - Represents the offset into the global offset table at which
comment|/// the address the relocation entry symbol resides during execution.
name|MO_GOT
block|,
comment|/// MO_GOT_CALL - Represents the offset into the global offset table at
comment|/// which the address of a call site relocation entry symbol resides
comment|/// during execution. This is different from the above since this flag
comment|/// can only be present in call instructions.
name|MO_GOT_CALL
block|,
comment|/// MO_GPREL - Represents the offset from the current gp value to be used
comment|/// for the relocatable object file being produced.
name|MO_GPREL
block|,
comment|/// MO_ABS_HILO - Represents the hi or low part of an absolute symbol
comment|/// address.
name|MO_ABS_HILO
block|}
enum|;
block|}
name|class
name|MipsInstrInfo
range|:
name|public
name|TargetInstrInfoImpl
block|{
name|MipsTargetMachine
operator|&
name|TM
block|;
specifier|const
name|MipsRegisterInfo
name|RI
block|;
name|public
operator|:
name|explicit
name|MipsInstrInfo
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
name|virtual
specifier|const
name|MipsRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
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
comment|/// Branch Analysis
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
comment|/// Insert nop instruction when hazard condition is found
name|virtual
name|void
name|insertNoop
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
comment|/// getGlobalBaseReg - Return a virtual register initialized with the
comment|/// the global base register value. Output instructions required to
comment|/// initialize the register in the function entry block, if necessary.
comment|///
name|unsigned
name|getGlobalBaseReg
argument_list|(
argument|MachineFunction *MF
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

