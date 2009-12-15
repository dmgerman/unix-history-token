begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AlphaInstrInfo.h - Alpha Instruction Information ---------*- C++ -*-===//
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
comment|// This file contains the Alpha implementation of the TargetInstrInfo class.
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
name|ALPHAINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ALPHAINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AlphaRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AlphaInstrInfo
range|:
name|public
name|TargetInstrInfoImpl
block|{
specifier|const
name|AlphaRegisterInfo
name|RI
block|;
name|public
operator|:
name|AlphaInstrInfo
argument_list|()
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
name|virtual
specifier|const
name|AlphaRegisterInfo
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
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|void
name|insertNoop
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
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
block|;
comment|/// getGlobalRetAddr - Return a virtual register initialized with the
comment|/// the global return address register value. Output instructions required to
comment|/// initialize the register in the function entry block, if necessary.
comment|///
name|unsigned
name|getGlobalRetAddr
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

