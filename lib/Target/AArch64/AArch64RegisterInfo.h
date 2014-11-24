begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- AArch64RegisterInfo.h - AArch64 Register Information Impl --*- C++ -*-==//
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
comment|// This file contains the AArch64 implementation of the MRegisterInfo class.
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
name|LLVM_TARGET_AArch64REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_AArch64REGISTERINFO_H
end_define

begin_define
define|#
directive|define
name|GET_REGINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"AArch64GenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64InstrInfo
decl_stmt|;
name|class
name|AArch64Subtarget
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|RegScavenger
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|struct
name|AArch64RegisterInfo
range|:
name|public
name|AArch64GenRegisterInfo
block|{
name|private
operator|:
specifier|const
name|AArch64InstrInfo
operator|*
name|TII
block|;
specifier|const
name|AArch64Subtarget
operator|*
name|STI
block|;
name|public
operator|:
name|AArch64RegisterInfo
argument_list|(
specifier|const
name|AArch64InstrInfo
operator|*
name|tii
argument_list|,
specifier|const
name|AArch64Subtarget
operator|*
name|sti
argument_list|)
block|;
name|bool
name|isReservedReg
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Reg
argument_list|)
specifier|const
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|MCPhysReg
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF = nullptr
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|CallingConv::ID
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getCSRFirstUseCost
argument_list|()
specifier|const
name|override
block|{
comment|// The cost will be compared against BlockFrequency where entry has the
comment|// value of 1<< 14. A value of 5 will choose to spill or split really
comment|// cold path instead of using a callee-saved register.
return|return
literal|5
return|;
block|}
comment|// Calls involved in thread-local variable lookup save more registers than
comment|// normal calls, so they need a different mask to represent this.
specifier|const
name|uint32_t
operator|*
name|getTLSCallPreservedMask
argument_list|()
specifier|const
block|;
comment|/// getThisReturnPreservedMask - Returns a call preserved mask specific to the
comment|/// case that 'returned' is on an i64 first argument if the calling convention
comment|/// is one that can (partially) model this attribute with a preserved mask
comment|/// (i.e. it is a calling convention that uses the same register for the first
comment|/// i64 argument and an i64 return value)
comment|///
comment|/// Should return NULL in the case that the calling convention does not have
comment|/// this property
specifier|const
name|uint32_t
operator|*
name|getThisReturnPreservedMask
argument_list|(
argument|CallingConv::ID
argument_list|)
specifier|const
block|;
name|BitVector
name|getReservedRegs
argument_list|(
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
specifier|const
name|TargetRegisterClass
operator|*
name|getCrossCopyRegClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|useFPForScavengingIndex
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|needsFrameBaseReg
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFrameOffsetLegal
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
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
name|override
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
block|;
name|bool
name|cannotEliminateFrame
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|requiresVirtualBaseRegisters
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasBasePointer
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getBaseRegister
argument_list|()
specifier|const
block|;
comment|// Debug information queries.
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRegPressureLimit
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
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

begin_comment
comment|// LLVM_TARGET_AArch64REGISTERINFO_H
end_comment

end_unit

