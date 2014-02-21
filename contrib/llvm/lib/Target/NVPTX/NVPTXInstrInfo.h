begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NVPTXInstrInfo.h - NVPTX Instruction Information----------*- C++ -*-===//
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
comment|// This file is distributed under the niversity of Illinois Open Source
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
comment|// This file contains the NVPTX implementation of the TargetInstrInfo class.
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
name|NVPTXINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|NVPTXINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"NVPTX.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXRegisterInfo.h"
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
file|"NVPTXGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|NVPTXInstrInfo
range|:
name|public
name|NVPTXGenInstrInfo
block|{
name|NVPTXTargetMachine
operator|&
name|TM
block|;
specifier|const
name|NVPTXRegisterInfo
name|RegInfo
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|explicit
name|NVPTXInstrInfo
argument_list|(
name|NVPTXTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
specifier|const
name|NVPTXRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RegInfo
return|;
block|}
comment|/* The following virtual functions are used in register allocation.    * They are not implemented because the existing interface and the logic    * at the caller side do not work for the elementized vector load and store.    *    * virtual unsigned isLoadFromStackSlot(const MachineInstr *MI,    *                                  int&FrameIndex) const;    * virtual unsigned isStoreToStackSlot(const MachineInstr *MI,    *                                 int&FrameIndex) const;    * virtual void storeRegToStackSlot(MachineBasicBlock&MBB,    *                              MachineBasicBlock::iterator MBBI,    *                             unsigned SrcReg, bool isKill, int FrameIndex,    *                              const TargetRegisterClass *RC) const;    * virtual void loadRegFromStackSlot(MachineBasicBlock&MBB,    *                               MachineBasicBlock::iterator MBBI,    *                               unsigned DestReg, int FrameIndex,    *                               const TargetRegisterClass *RC) const;    */
name|virtual
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
name|virtual
name|bool
name|isMoveInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DestReg
argument_list|)
specifier|const
block|;
name|bool
name|isLoadInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&AddrSpace
argument_list|)
specifier|const
block|;
name|bool
name|isStoreInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&AddrSpace
argument_list|)
specifier|const
block|;
name|bool
name|isReadSpecialReg
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|CanTailMerge
argument_list|(
argument|const MachineInstr *MI
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
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
block|;
name|unsigned
name|getLdStCodeAddrSpace
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|{
return|return
name|MI
operator|.
name|getOperand
argument_list|(
literal|2
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

