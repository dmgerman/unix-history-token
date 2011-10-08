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

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"MipsGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Mips
block|{
comment|/// GetOppositeBranchOpc - Return the inverse of the specified
comment|/// opcode, e.g. turning BEQ to BNE.
name|unsigned
name|GetOppositeBranchOpc
parameter_list|(
name|unsigned
name|Opc
parameter_list|)
function_decl|;
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
comment|/// MO_ABS_HI/LO - Represents the hi or low part of an absolute symbol
comment|/// address.
name|MO_ABS_HI
block|,
name|MO_ABS_LO
block|,
comment|/// MO_TLSGD - Represents the offset into the global offset table at which
comment|// the module ID and TSL block offset reside during execution (General
comment|// Dynamic TLS).
name|MO_TLSGD
block|,
comment|/// MO_GOTTPREL - Represents the offset from the thread pointer (Initial
comment|// Exec TLS).
name|MO_GOTTPREL
block|,
comment|/// MO_TPREL_HI/LO - Represents the hi and low part of the offset from
comment|// the thread pointer (Local Exec TLS).
name|MO_TPREL_HI
block|,
name|MO_TPREL_LO
block|}
enum|;
block|}
name|class
name|MipsInstrInfo
range|:
name|public
name|MipsGenInstrInfo
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
name|private
operator|:
name|void
name|BuildCondBr
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|const SmallVectorImpl<MachineOperand>& Cond
argument_list|)
specifier|const
block|;
name|public
operator|:
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
argument_list|,
argument|DebugLoc DL
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
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|emitFrameIndexDebugValue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|int FrameIx
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|const MDNode *MDPtr
argument_list|,
argument|DebugLoc DL
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

