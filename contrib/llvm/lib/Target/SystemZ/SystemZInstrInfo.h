begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZInstrInfo.h - SystemZ instruction information ----*- C++ -*-===//
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
comment|// This file contains the SystemZ implementation of the TargetInstrInfo class.
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
name|LLVM_TARGET_SYSTEMZINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_SYSTEMZINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"SystemZ.h"
end_include

begin_include
include|#
directive|include
file|"SystemZRegisterInfo.h"
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
file|"SystemZGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SystemZTargetMachine
decl_stmt|;
name|namespace
name|SystemZII
block|{
enum|enum
block|{
comment|// See comments in SystemZInstrFormats.td.
name|SimpleBDXLoad
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|SimpleBDXStore
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|Has20BitOffset
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|HasIndex
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|Is128Bit
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|}
enum|;
comment|// SystemZ MachineOperand target flags.
enum|enum
block|{
comment|// Masks out the bits for the access model.
name|MO_SYMBOL_MODIFIER
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|// @GOT (aka @GOTENT)
name|MO_GOT
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|}
enum|;
block|}
name|class
name|SystemZInstrInfo
range|:
name|public
name|SystemZGenInstrInfo
block|{
specifier|const
name|SystemZRegisterInfo
name|RI
block|;
name|void
name|splitMove
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned NewOpcode
argument_list|)
specifier|const
block|;
name|void
name|splitAdjDynAlloc
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
name|public
operator|:
name|explicit
name|SystemZInstrInfo
argument_list|(
name|SystemZTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|// Override TargetInstrInfo.
name|virtual
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|LLVM_OVERRIDE
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
name|LLVM_OVERRIDE
block|;
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
name|LLVM_OVERRIDE
block|;
name|virtual
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
name|LLVM_OVERRIDE
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
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
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
name|LLVM_OVERRIDE
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
name|LLVM_OVERRIDE
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
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineBasicBlock::iterator MBBI
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
comment|// Return the SystemZRegisterInfo, which this class owns.
specifier|const
name|SystemZRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
comment|// Return true if MI is a conditional or unconditional branch.
comment|// When returning true, set Cond to the mask of condition-code
comment|// values on which the instruction will branch, and set Target
comment|// to the operand that contains the branch target.  This target
comment|// can be a register or a basic block.
name|bool
name|isBranch
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned&Cond
argument_list|,
argument|const MachineOperand *&Target
argument_list|)
specifier|const
block|;
comment|// Get the load and store opcodes for a given register class.
name|void
name|getLoadStoreOpcodes
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned&LoadOpcode
argument_list|,
argument|unsigned&StoreOpcode
argument_list|)
specifier|const
block|;
comment|// Opcode is the opcode of an instruction that has an address operand,
comment|// and the caller wants to perform that instruction's operation on an
comment|// address that has displacement Offset.  Return the opcode of a suitable
comment|// instruction (which might be Opcode itself) or 0 if no such instruction
comment|// exists.
name|unsigned
name|getOpcodeForOffset
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
comment|// Emit code before MBBI in MI to move immediate value Value into
comment|// physical register Reg.
name|void
name|loadImmediate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|uint64_t Value
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

