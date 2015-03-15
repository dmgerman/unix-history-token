begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsFrameLowering.h - Define frame lowering for Mips ----*- C++ -*-===//
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
comment|//
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
name|LLVM_LIB_TARGET_MIPS_MIPSFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSFRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"Mips.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsSubtarget
decl_stmt|;
name|class
name|MipsFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|protected
operator|:
specifier|const
name|MipsSubtarget
operator|&
name|STI
block|;
name|public
operator|:
name|explicit
name|MipsFrameLowering
argument_list|(
argument|const MipsSubtarget&sti
argument_list|,
argument|unsigned Alignment
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
name|StackGrowsDown
argument_list|,
name|Alignment
argument_list|,
literal|0
argument_list|,
name|Alignment
argument_list|)
block|,
name|STI
argument_list|(
argument|sti
argument_list|)
block|{}
specifier|static
specifier|const
name|MipsFrameLowering
operator|*
name|create
argument_list|(
specifier|const
name|MipsSubtarget
operator|&
name|ST
argument_list|)
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|protected
operator|:
name|uint64_t
name|estimateStackSize
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// Create MipsFrameLowering objects.
specifier|const
name|MipsFrameLowering
modifier|*
name|createMips16FrameLowering
parameter_list|(
specifier|const
name|MipsSubtarget
modifier|&
name|ST
parameter_list|)
function_decl|;
specifier|const
name|MipsFrameLowering
modifier|*
name|createMipsSEFrameLowering
parameter_list|(
specifier|const
name|MipsSubtarget
modifier|&
name|ST
parameter_list|)
function_decl|;
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

