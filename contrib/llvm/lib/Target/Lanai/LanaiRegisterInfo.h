begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LanaiRegisterInfo.h - Lanai Register Information Impl ----*- C++ -*-===//
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
comment|// This file contains the Lanai implementation of the TargetRegisterInfo class.
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
name|LLVM_LIB_TARGET_LANAI_LANAIREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_LANAIREGISTERINFO_H
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
file|"LanaiGenRegisterInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|struct
name|LanaiRegisterInfo
range|:
name|public
name|LanaiGenRegisterInfo
block|{
name|LanaiRegisterInfo
argument_list|()
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|CallingConv::ID
argument_list|)
specifier|const
name|override
block|;
comment|// Code Generation virtual methods.
specifier|const
name|uint16_t
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF = nullptr
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
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
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
comment|// Debug information queries.
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getBaseRegister
argument_list|()
specifier|const
block|;
name|bool
name|hasBasePointer
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// Exception handling queries.
name|unsigned
name|getEHExceptionRegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getEHHandlerRegister
argument_list|()
specifier|const
block|;
name|int
name|getDwarfRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool IsEH
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

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_LANAIREGISTERINFO_H
end_comment

end_unit

