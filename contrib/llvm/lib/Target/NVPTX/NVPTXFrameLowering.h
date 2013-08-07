begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- NVPTXFrameLowering.h - Define frame lowering for NVPTX -*- C++ -*-===//
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
name|NVPTX_FRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|NVPTX_FRAMELOWERING_H
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
name|class
name|NVPTXTargetMachine
decl_stmt|;
name|class
name|NVPTXFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|NVPTXTargetMachine
operator|&
name|tm
block|;
name|bool
name|is64bit
block|;
name|public
operator|:
name|explicit
name|NVPTXFrameLowering
argument_list|(
argument|NVPTXTargetMachine&_tm
argument_list|,
argument|bool _is64bit
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
name|TargetFrameLowering
operator|::
name|StackGrowsUp
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|)
block|,
name|tm
argument_list|(
name|_tm
argument_list|)
block|,
name|is64bit
argument_list|(
argument|_is64bit
argument_list|)
block|{}
name|virtual
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|void
name|eliminateCallFramePseudoInstr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
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

