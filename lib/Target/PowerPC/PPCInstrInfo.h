begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PPCInstrInfo.h - PowerPC Instruction Information ---------*- C++ -*-===//
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
comment|// This file contains the PowerPC implementation of the TargetInstrInfo class.
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
name|POWERPC32_INSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC32_INSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"PPCRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PPCII - This namespace holds all of the PowerPC target-specific
comment|/// per-instruction flags.  These must match the corresponding definitions in
comment|/// PPC.td and PPCInstrFormats.td.
name|namespace
name|PPCII
block|{
enum|enum
block|{
comment|// PPC970 Instruction Flags.  These flags describe the characteristics of the
comment|// PowerPC 970 (aka G5) dispatch groups and how they are formed out of
comment|// raw machine instructions.
comment|/// PPC970_First - This instruction starts a new dispatch group, so it will
comment|/// always be the first one in the group.
name|PPC970_First
init|=
literal|0x1
block|,
comment|/// PPC970_Single - This instruction starts a new dispatch group and
comment|/// terminates it, so it will be the sole instruction in the group.
name|PPC970_Single
init|=
literal|0x2
block|,
comment|/// PPC970_Cracked - This instruction is cracked into two pieces, requiring
comment|/// two dispatch pipes to be available to issue.
name|PPC970_Cracked
init|=
literal|0x4
block|,
comment|/// PPC970_Mask/Shift - This is a bitmask that selects the pipeline type that
comment|/// an instruction is issued to.
name|PPC970_Shift
init|=
literal|3
block|,
name|PPC970_Mask
init|=
literal|0x07
operator|<<
name|PPC970_Shift
block|}
enum|;
enum|enum
name|PPC970_Unit
block|{
comment|/// These are the various PPC970 execution unit pipelines.  Each instruction
comment|/// is one of these.
name|PPC970_Pseudo
init|=
literal|0
operator|<<
name|PPC970_Shift
block|,
comment|// Pseudo instruction
name|PPC970_FXU
init|=
literal|1
operator|<<
name|PPC970_Shift
block|,
comment|// Fixed Point (aka Integer/ALU) Unit
name|PPC970_LSU
init|=
literal|2
operator|<<
name|PPC970_Shift
block|,
comment|// Load Store Unit
name|PPC970_FPU
init|=
literal|3
operator|<<
name|PPC970_Shift
block|,
comment|// Floating Point Unit
name|PPC970_CRU
init|=
literal|4
operator|<<
name|PPC970_Shift
block|,
comment|// Control Register Unit
name|PPC970_VALU
init|=
literal|5
operator|<<
name|PPC970_Shift
block|,
comment|// Vector ALU
name|PPC970_VPERM
init|=
literal|6
operator|<<
name|PPC970_Shift
block|,
comment|// Vector Permute Unit
name|PPC970_BRU
init|=
literal|7
operator|<<
name|PPC970_Shift
comment|// Branch Unit
block|}
enum|;
block|}
name|class
name|PPCInstrInfo
range|:
name|public
name|TargetInstrInfoImpl
block|{
name|PPCTargetMachine
operator|&
name|TM
block|;
specifier|const
name|PPCRegisterInfo
name|RI
block|;
name|bool
name|StoreRegToStackSlot
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|;
name|void
name|LoadRegFromStackSlot
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|;
name|public
operator|:
name|explicit
name|PPCInstrInfo
argument_list|(
name|PPCTargetMachine
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
name|PPCRegisterInfo
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
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
comment|// commuteInstruction - We can commute rlwimi instructions, but only if the
comment|// rotate amt is zero.  We also have to munge the immediates a bit.
name|virtual
name|MachineInstr
operator|*
name|commuteInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI
argument_list|)
specifier|const
block|;
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
name|copyRegToReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
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
comment|/// foldMemoryOperand - PowerPC (like most RISC's) can only fold spills into
comment|/// copy instructions, turning them into load/store instructions.
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
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
comment|/// GetInstSize - Return the number of bytes of code the specified
comment|/// instruction may be.  This returns the maximum number of bytes.
comment|///
name|virtual
name|unsigned
name|GetInstSizeInBytes
argument_list|(
argument|const MachineInstr *MI
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

