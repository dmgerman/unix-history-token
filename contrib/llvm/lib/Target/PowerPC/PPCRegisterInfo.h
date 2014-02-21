begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCRegisterInfo.h - PowerPC Register Information Impl ---*- C++ -*-===//
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
comment|// This file contains the PowerPC implementation of the TargetRegisterInfo
end_comment

begin_comment
comment|// class.
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
name|POWERPC32_REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC32_REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_define
define|#
directive|define
name|GET_REGINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"PPCGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCSubtarget
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|PPCRegisterInfo
range|:
name|public
name|PPCGenRegisterInfo
block|{
name|DenseMap
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|ImmToIdxMap
block|;
specifier|const
name|PPCSubtarget
operator|&
name|Subtarget
block|;
name|public
operator|:
name|PPCRegisterInfo
argument_list|(
specifier|const
name|PPCSubtarget
operator|&
name|SubTarget
argument_list|)
block|;
comment|/// getPointerRegClass - Return the register class to use to hold pointers.
comment|/// This is used for addressing modes.
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Kind=
literal|0
argument_list|)
specifier|const
block|;
name|unsigned
name|getRegPressureLimit
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|uint16_t
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction* MF =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|CallingConv::ID CC
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getNoPreservedMask
argument_list|()
specifier|const
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// We require the register scavenger.
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|requiresVirtualBaseRegisters
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|void
name|lowerDynamicAlloc
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|)
specifier|const
block|;
name|void
name|lowerCRSpilling
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerCRRestore
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerVRSAVESpilling
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|void
name|lowerVRSAVERestore
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned FrameIndex
argument_list|)
specifier|const
block|;
name|bool
name|hasReservedSpillSlot
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Reg
argument_list|,
argument|int&FrameIdx
argument_list|)
specifier|const
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
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
comment|// Support for virtual base registers.
name|bool
name|needsFrameBaseReg
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
name|void
name|materializeFrameBaseRegister
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int FrameIdx
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
name|void
name|resolveFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
name|bool
name|isFrameOffsetLegal
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
comment|// Debug information queries.
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// Base pointer (stack realignment) support.
name|unsigned
name|getBaseRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|hasBasePointer
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|canRealignStack
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|needsStackRealignment
argument_list|(
argument|const MachineFunction&MF
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

