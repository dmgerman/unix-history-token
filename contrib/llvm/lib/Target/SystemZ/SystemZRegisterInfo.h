begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZRegisterInfo.h - SystemZ register information ----*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"SystemZ.h"
end_include

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
file|"SystemZGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|SystemZ
block|{
comment|// Return the subreg to use for referring to the even and odd registers
comment|// in a GR128 pair.  Is32Bit says whether we want a GR32 or GR64.
specifier|inline
name|unsigned
name|even128
parameter_list|(
name|bool
name|Is32bit
parameter_list|)
block|{
return|return
name|Is32bit
condition|?
name|subreg_hl32
else|:
name|subreg_h64
return|;
block|}
specifier|inline
name|unsigned
name|odd128
parameter_list|(
name|bool
name|Is32bit
parameter_list|)
block|{
return|return
name|Is32bit
condition|?
name|subreg_l32
else|:
name|subreg_l64
return|;
block|}
block|}
comment|// end namespace SystemZ
name|struct
name|SystemZRegisterInfo
range|:
name|public
name|SystemZGenRegisterInfo
block|{
name|public
operator|:
name|SystemZRegisterInfo
argument_list|()
block|;
comment|/// getPointerRegClass - Return the register class to use to hold pointers.
comment|/// This is currently only used by LOAD_STACK_GUARD, which requires a non-%r0
comment|/// register, hence ADDR64.
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
name|override
block|{
return|return
operator|&
name|SystemZ
operator|::
name|ADDR64BitRegClass
return|;
block|}
comment|// Override TargetRegisterInfo.h.
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
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
name|override
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
name|override
block|{
return|return
name|true
return|;
block|}
specifier|const
name|MCPhysReg
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|CallingConv::ID CC
argument_list|)
specifier|const
name|override
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
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

end_unit

