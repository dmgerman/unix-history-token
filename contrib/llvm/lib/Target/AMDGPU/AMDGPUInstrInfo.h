begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUInstrInfo.h - AMDGPU Instruction Information ------*- C++ -*-===//
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
comment|/// \brief Contains the definition of a TargetInstrInfo class that is common
end_comment

begin_comment
comment|/// to all AMD GPUs.
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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"Utils/AMDGPUBaseInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUSubtarget
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineInstrBuilder
decl_stmt|;
name|class
name|AMDGPUInstrInfo
range|:
name|public
name|AMDGPUGenInstrInfo
block|{
name|private
operator|:
specifier|const
name|AMDGPUSubtarget
operator|&
name|ST
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|AMDGPUAS
name|AMDGPUASI
block|;
name|public
operator|:
name|explicit
name|AMDGPUInstrInfo
argument_list|(
specifier|const
name|AMDGPUSubtarget
operator|&
name|st
argument_list|)
block|;
name|bool
name|shouldScheduleLoadsNear
argument_list|(
argument|SDNode *Load1
argument_list|,
argument|SDNode *Load2
argument_list|,
argument|int64_t Offset1
argument_list|,
argument|int64_t Offset2
argument_list|,
argument|unsigned NumLoads
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Return a target-specific opcode if Opcode is a pseudo instruction.
comment|/// Return -1 if the target-specific opcode for the pseudo instruction does
comment|/// not exist. If Opcode is not a pseudo instruction, this is identity.
name|int
name|pseudoToMCOpcode
argument_list|(
argument|int Opcode
argument_list|)
specifier|const
block|;
comment|/// \brief Given a MIMG \p Opcode that writes all 4 channels, return the
comment|/// equivalent opcode that writes \p Channels Channels.
name|int
name|getMaskedMIMGOp
argument_list|(
argument|uint16_t Opcode
argument_list|,
argument|unsigned Channels
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

