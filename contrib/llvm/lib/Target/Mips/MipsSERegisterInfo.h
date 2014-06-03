begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsSERegisterInfo.h - Mips32/64 Register Information ---*- C++ -*-===//
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
comment|// This file contains the Mips32/64 implementation of the TargetRegisterInfo
end_comment

begin_comment
comment|// class.
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
name|MIPSSEREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSSEREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"MipsRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsSEInstrInfo
decl_stmt|;
name|class
name|MipsSERegisterInfo
range|:
name|public
name|MipsRegisterInfo
block|{
name|public
operator|:
name|MipsSERegisterInfo
argument_list|(
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
argument_list|)
block|;
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|intRegClass
argument_list|(
argument|unsigned Size
argument_list|)
specifier|const
block|;
name|private
operator|:
name|virtual
name|void
name|eliminateFI
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|int FrameIndex
argument_list|,
argument|uint64_t StackSize
argument_list|,
argument|int64_t SPOffset
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

end_unit

