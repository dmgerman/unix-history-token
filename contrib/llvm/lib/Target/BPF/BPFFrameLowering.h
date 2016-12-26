begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BPFFrameLowering.h - Define frame lowering for BPF -----*- C++ -*--===//
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
comment|// This class implements BPF-specific bits of TargetFrameLowering class.
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
name|LLVM_LIB_TARGET_BPF_BPFFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_BPF_BPFFRAMELOWERING_H
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
name|BPFSubtarget
decl_stmt|;
name|class
name|BPFFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|public
operator|:
name|explicit
name|BPFFrameLowering
argument_list|(
specifier|const
name|BPFSubtarget
operator|&
name|sti
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
argument|TargetFrameLowering::StackGrowsDown
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|)
block|{}
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|void
name|determineCalleeSaves
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|BitVector&SavedRegs
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|::
name|iterator
name|eliminateCallFramePseudoInstr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|override
block|{
return|return
name|MBB
operator|.
name|erase
argument_list|(
name|MI
argument_list|)
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

