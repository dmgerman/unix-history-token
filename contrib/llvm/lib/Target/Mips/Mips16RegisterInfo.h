begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Mips16RegisterInfo.h - Mips16 Register Information ------*- C++ -*-===//
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
comment|// This file contains the Mips16 implementation of the TargetRegisterInfo class.
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
name|MIPS16REGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS16REGISTERINFO_H
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
name|Mips16InstrInfo
decl_stmt|;
name|class
name|Mips16RegisterInfo
range|:
name|public
name|MipsRegisterInfo
block|{
specifier|const
name|Mips16InstrInfo
operator|&
name|TII
block|;
name|public
operator|:
name|Mips16RegisterInfo
argument_list|(
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
argument_list|,
specifier|const
name|Mips16InstrInfo
operator|&
name|TII
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
name|bool
name|useFPForScavengingIndex
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|saveScavengerRegister
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|MachineBasicBlock::iterator&UseMI
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned Reg
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

