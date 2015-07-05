begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ThumbRegisterInfo.h - Thumb Register Information Impl -*- C++ -*-===//
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
comment|// This file contains the Thumb implementation of the TargetRegisterInfo
end_comment

begin_comment
comment|// class. With the exception of emitLoadConstPool Thumb2 tracks
end_comment

begin_comment
comment|// ARMBaseRegisterInfo, Thumb1 overloads the functions below.
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
name|LLVM_LIB_TARGET_ARM_THUMB1REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_THUMB1REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"ARMBaseRegisterInfo.h"
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
name|struct
name|ThumbRegisterInfo
range|:
name|public
name|ARMBaseRegisterInfo
block|{
name|public
operator|:
name|ThumbRegisterInfo
argument_list|()
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getLargestLegalSuperClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Kind =
literal|0
argument_list|)
specifier|const
name|override
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
argument_list|,
argument|unsigned MIFlags = MachineInstr::NoFlags
argument_list|)
specifier|const
name|override
block|;
comment|// rewrite MI to access 'Offset' bytes from the FP. Update Offset to be
comment|// however much remains to be handled. Return 'true' if no further
comment|// work is required.
name|bool
name|rewriteFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameRegIdx
argument_list|,
argument|unsigned FrameReg
argument_list|,
argument|int&Offset
argument_list|,
argument|const ARMBaseInstrInfo&TII
argument_list|)
specifier|const
block|;
name|void
name|resolveFrameIndex
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
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
name|override
block|;
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

