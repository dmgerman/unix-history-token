begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- AMDGPUFrameLowering.h ----------------*- C++ -*-===//
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
comment|/// \brief Interface to describe a layout of a stack frame on an AMDGPU target.
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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUFRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Information about the stack frame layout on the AMDGPU targets.
comment|///
comment|/// It holds the direction of the stack growth, the known stack alignment on
comment|/// entry to each function, and the offset to the locals area.
comment|/// See TargetFrameInfo for more comments.
name|class
name|AMDGPUFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|public
operator|:
name|AMDGPUFrameLowering
argument_list|(
argument|StackDirection D
argument_list|,
argument|unsigned StackAl
argument_list|,
argument|int LAO
argument_list|,
argument|unsigned TransAl =
literal|1
argument_list|)
block|;
operator|~
name|AMDGPUFrameLowering
argument_list|()
name|override
block|;
comment|/// \returns The number of 32-bit sub-registers that are used when storing
comment|/// values to the stack.
name|unsigned
name|getStackWidth
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_AMDGPUFRAMELOWERING_H
end_comment

end_unit

