begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- R600FrameLowering.h ------------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_AMDGPU_R600FRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_R600FRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUFrameLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|R600FrameLowering
range|:
name|public
name|AMDGPUFrameLowering
block|{
name|public
operator|:
name|R600FrameLowering
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
operator|:
name|AMDGPUFrameLowering
argument_list|(
argument|D
argument_list|,
argument|StackAl
argument_list|,
argument|LAO
argument_list|,
argument|TransAl
argument_list|)
block|{}
name|virtual
operator|~
name|R600FrameLowering
argument_list|()
block|;
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|{}
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|{}
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

