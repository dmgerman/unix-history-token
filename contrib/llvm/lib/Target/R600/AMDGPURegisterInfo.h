begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPURegisterInfo.h - AMDGPURegisterInfo Interface -*- C++ -*-----===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief TargetRegisterInfo interface that is implemented by all hw codegen
end_comment

begin_comment
comment|/// targets.
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
name|AMDGPUREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPUREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
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

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUTargetMachine
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|struct
name|AMDGPURegisterInfo
range|:
name|public
name|AMDGPUGenRegisterInfo
block|{
name|TargetMachine
operator|&
name|TM
block|;
specifier|static
specifier|const
name|uint16_t
name|CalleeSavedReg
block|;
name|AMDGPURegisterInfo
argument_list|(
name|TargetMachine
operator|&
name|tm
argument_list|)
block|;
name|virtual
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
literal|"Unimplemented"
argument_list|)
block|;
return|return
name|BitVector
argument_list|()
return|;
block|}
comment|/// \param RC is an AMDIL reg class.
comment|///
comment|/// \returns The ISA reg class that is equivalent to \p RC.
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getISARegClass
argument_list|(
argument|const TargetRegisterClass * RC
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
literal|"Unimplemented"
argument_list|)
block|;
return|return
name|NULL
return|;
block|}
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getCFGStructurizerRegClass
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
literal|"Unimplemented"
argument_list|)
block|;
return|return
name|NULL
return|;
block|}
name|virtual
name|unsigned
name|getHWRegIndex
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
literal|"Unimplemented"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
comment|/// \returns the sub reg enum value for the given \p Channel
comment|/// (e.g. getSubRegFromChannel(0) -> AMDGPU::sub0)
name|unsigned
name|getSubRegFromChannel
argument_list|(
argument|unsigned Channel
argument_list|)
specifier|const
block|;
specifier|const
name|uint16_t
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
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
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getIndirectSubReg
argument_list|(
argument|unsigned IndirectIndex
argument_list|)
specifier|const
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDIDSAREGISTERINFO_H
end_comment

end_unit

