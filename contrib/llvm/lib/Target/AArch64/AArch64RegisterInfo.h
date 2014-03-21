begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- AArch64RegisterInfo.h - AArch64 Register Information Impl -*- C++ -*-===//
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
comment|// This file contains the AArch64 implementation of the MCRegisterInfo class.
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
name|LLVM_TARGET_AARCH64REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_AARCH64REGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

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
name|struct
name|AArch64RegisterInfo
range|:
name|public
name|AArch64GenRegisterInfo
block|{
name|AArch64RegisterInfo
argument_list|()
block|;
specifier|const
name|uint16_t
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|CallingConv::ID
argument_list|)
specifier|const
block|;
specifier|const
name|uint32_t
operator|*
name|getTLSDescCallPreservedMask
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
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
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
argument|RegScavenger *Rs = NULL
argument_list|)
specifier|const
block|;
comment|/// getCrossCopyRegClass - Returns a legal register class to copy a register
comment|/// in the specified class to or from. Returns original class if it is
comment|/// possible to copy between a two registers of the specified class.
specifier|const
name|TargetRegisterClass
operator|*
name|getCrossCopyRegClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
comment|/// getLargestLegalSuperClass - Returns the largest super class of RC that is
comment|/// legal to use in the current sub-target and has the same spill size.
specifier|const
name|TargetRegisterClass
operator|*
name|getLargestLegalSuperClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|{
if|if
condition|(
name|RC
operator|==
operator|&
name|AArch64
operator|::
name|tcGPR64RegClass
condition|)
return|return
operator|&
name|AArch64
operator|::
name|GPR64RegClass
return|;
return|return
name|RC
return|;
block|}
name|bool
name|requiresRegisterScavenging
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
name|bool
name|requiresFrameIndexScavenging
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
name|bool
name|useFPForScavengingIndex
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_AARCH64REGISTERINFO_H
end_comment

end_unit

