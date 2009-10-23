begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Thumb1RegisterInfo.h - Thumb-1 Register Information Impl ----*- C++ -*-===//
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
comment|// This file contains the Thumb-1 implementation of the TargetRegisterInfo class.
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
name|THUMB1REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|THUMB1REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_include
include|#
directive|include
file|"ARMRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ARMBaseInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|struct
name|Thumb1RegisterInfo
range|:
name|public
name|ARMBaseRegisterInfo
block|{
name|public
operator|:
name|Thumb1RegisterInfo
argument_list|(
specifier|const
name|ARMBaseInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// emitLoadConstPool - Emits a load from constpool to materialize the
comment|/// specified immediate.
name|void
name|emitLoadConstPool
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|int Val
argument_list|,
argument|ARMCC::CondCodes Pred = ARMCC::AL
argument_list|,
argument|unsigned PredReg =
literal|0
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|TargetRegisterClass
operator|*
name|getPhysicalRegisterRegClass
argument_list|(
argument|unsigned Reg
argument_list|,
argument|EVT VT = MVT::Other
argument_list|)
specifier|const
block|;
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|hasReservedCallFrame
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|eliminateCallFramePseudoInstr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;
comment|// rewrite MI to access 'Offset' bytes from the FP. Return the offset that
comment|// could not be handled directly in MI.
name|int
name|rewriteFrameIndex
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned FrameRegIdx
argument_list|,
argument|unsigned FrameReg
argument_list|,
argument|int Offset
argument_list|,
argument|unsigned MOVOpc
argument_list|,
argument|unsigned ADDriOpc
argument_list|,
argument|unsigned SUBriOpc
argument_list|)
specifier|const
block|;
name|bool
name|saveScavengerRegister
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|MachineBasicBlock::iterator&UseMI
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned Reg
argument_list|)
specifier|const
block|;
name|unsigned
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|int *Value = NULL
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
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

begin_comment
comment|// THUMB1REGISTERINFO_H
end_comment

end_unit

