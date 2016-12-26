begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LanaiFrameLowering.h - Define frame lowering for Lanai --*- C++-*--===//
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
comment|// This class implements Lanai-specific bits of TargetFrameLowering class.
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
name|LLVM_LIB_TARGET_LANAI_LANAIFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_LANAIFRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"Lanai.h"
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
name|BitVector
decl_stmt|;
name|class
name|LanaiSubtarget
decl_stmt|;
name|class
name|LanaiFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|private
operator|:
name|void
name|determineFrameLayout
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|replaceAdjDynAllocPseudo
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|protected
operator|:
specifier|const
name|LanaiSubtarget
operator|&
name|STI
block|;
name|public
operator|:
name|explicit
name|LanaiFrameLowering
argument_list|(
specifier|const
name|LanaiSubtarget
operator|&
name|Subtarget
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
name|StackGrowsDown
argument_list|,
comment|/*StackAlignment=*/
literal|8
argument_list|,
comment|/*LocalAreaOffset=*/
literal|0
argument_list|)
block|,
name|STI
argument_list|(
argument|Subtarget
argument_list|)
block|{}
comment|// emitProlog/emitEpilog - These methods insert prolog and epilog code into
comment|// the function.
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
name|MachineBasicBlock
operator|::
name|iterator
name|eliminateCallFramePseudoInstr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&
comment|/*MF*/
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|void
name|determineCalleeSaves
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|BitVector&SavedRegs
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_LANAIFRAMELOWERING_H
end_comment

end_unit

