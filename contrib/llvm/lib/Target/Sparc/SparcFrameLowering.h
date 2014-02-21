begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcFrameLowering.h - Define frame lowering for Sparc --*- C++ -*-===//
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
name|SPARC_FRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPARC_FRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"Sparc.h"
end_include

begin_include
include|#
directive|include
file|"SparcSubtarget.h"
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
name|SparcSubtarget
decl_stmt|;
name|class
name|SparcFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
specifier|const
name|SparcSubtarget
operator|&
name|SubTarget
block|;
name|public
operator|:
name|explicit
name|SparcFrameLowering
argument_list|(
specifier|const
name|SparcSubtarget
operator|&
name|ST
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
name|TargetFrameLowering
operator|::
name|StackGrowsDown
argument_list|,
name|ST
operator|.
name|is64Bit
argument_list|()
condition|?
literal|16
else|:
literal|8
argument_list|,
literal|0
argument_list|,
name|ST
operator|.
name|is64Bit
argument_list|()
condition|?
literal|16
else|:
literal|8
argument_list|)
block|,
name|SubTarget
argument_list|(
argument|ST
argument_list|)
block|{}
comment|/// emitProlog/emitEpilog - These methods insert prolog and epilog code into
comment|/// the function.
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
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
block|;
name|bool
name|hasReservedCallFrame
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
block|;
name|void
name|processFunctionBeforeCalleeSavedScan
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|// Remap input registers to output registers for leaf procedure.
name|void
name|remapRegsForLeafProc
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// Returns true if MF is a leaf procedure.
name|bool
name|isLeafProc
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// Emits code for adjusting SP in function prologue/epilogue.
name|void
name|emitSPAdjustment
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|int NumBytes
argument_list|,
argument|unsigned ADDrr
argument_list|,
argument|unsigned ADDri
argument_list|)
specifier|const
block|;  }
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

