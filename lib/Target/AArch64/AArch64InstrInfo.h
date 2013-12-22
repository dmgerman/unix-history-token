begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AArch64InstrInfo.h - AArch64 Instruction Information -----*- C++ -*-===//
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
comment|// This file contains the AArch64 implementation of the TargetInstrInfo class.
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
name|LLVM_TARGET_AARCH64INSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_AARCH64INSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AArch64RegisterInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"AArch64GenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64Subtarget
decl_stmt|;
name|class
name|AArch64InstrInfo
range|:
name|public
name|AArch64GenInstrInfo
block|{
specifier|const
name|AArch64RegisterInfo
name|RI
block|;
specifier|const
name|AArch64Subtarget
operator|&
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|AArch64InstrInfo
argument_list|(
specifier|const
name|AArch64Subtarget
operator|&
name|TM
argument_list|)
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
specifier|const
name|TargetRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
specifier|const
name|AArch64Subtarget
operator|&
name|getSubTarget
argument_list|()
specifier|const
block|{
return|return
name|Subtarget
return|;
block|}
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
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
block|;
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
block|;
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
argument|bool AllowModify = false
argument_list|)
specifier|const
block|;
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
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
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
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
comment|/// Look through the instructions in this function and work out the largest
comment|/// the stack frame can be while maintaining the ability to address local
comment|/// slots with no complexities.
name|unsigned
name|estimateRSStackLimit
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// getAddressConstraints - For loads and stores (and PRFMs) taking an
comment|/// immediate offset, this function determines the constraints required for
comment|/// the immediate. It must satisfy:
comment|///    + MinOffset<= imm<= MaxOffset
comment|///    + imm % OffsetScale == 0
name|void
name|getAddressConstraints
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&AccessScale
argument_list|,
argument|int&MinOffset
argument_list|,
argument|int&MaxOffset
argument_list|)
specifier|const
block|;
name|unsigned
name|getInstSizeInBytes
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|getInstBundleLength
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;  }
decl_stmt|;
name|bool
name|rewriteA64FrameIndex
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|FrameRegIdx
parameter_list|,
name|unsigned
name|FrameReg
parameter_list|,
name|int
modifier|&
name|Offset
parameter_list|,
specifier|const
name|AArch64InstrInfo
modifier|&
name|TII
parameter_list|)
function_decl|;
name|void
name|emitRegUpdate
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|DebugLoc
name|dl
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|,
name|unsigned
name|DstReg
argument_list|,
name|unsigned
name|SrcReg
argument_list|,
name|unsigned
name|ScratchReg
argument_list|,
name|int64_t
name|NumBytes
argument_list|,
name|MachineInstr
operator|::
name|MIFlag
name|MIFlags
operator|=
name|MachineInstr
operator|::
name|NoFlags
argument_list|)
decl_stmt|;
name|void
name|emitSPUpdate
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|DebugLoc
name|dl
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|,
name|unsigned
name|ScratchReg
argument_list|,
name|int64_t
name|NumBytes
argument_list|,
name|MachineInstr
operator|::
name|MIFlag
name|MIFlags
operator|=
name|MachineInstr
operator|::
name|NoFlags
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

