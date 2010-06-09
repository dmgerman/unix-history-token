begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SPUFrameInfo.h - Top-level interface for Cell SPU Target -*- C++ -*-==//
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
comment|// This file contains CellSPU frame information that doesn't fit anywhere else
end_comment

begin_comment
comment|// cleanly...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SPUFRAMEINFO_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"SPURegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SPUFrameInfo
range|:
name|public
name|TargetFrameInfo
block|{
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|int
operator|>
name|LR
index|[
literal|1
index|]
block|;
name|public
operator|:
name|SPUFrameInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|tm
argument_list|)
block|;
comment|//! Return a function's saved spill slots
comment|/*!       For CellSPU, a function's saved spill slots is just the link register.      */
specifier|const
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|int
operator|>
operator|*
name|getCalleeSaveSpillSlots
argument_list|(
argument|unsigned&NumEntries
argument_list|)
specifier|const
block|;
comment|//! Stack slot size (16 bytes)
specifier|static
name|int
name|stackSlotSize
argument_list|()
block|{
return|return
literal|16
return|;
block|}
comment|//! Maximum frame offset representable by a signed 10-bit integer
comment|/*!       This is the maximum frame offset that can be expressed as a 10-bit       integer, used in D-form addresses.      */
specifier|static
name|int
name|maxFrameOffset
argument_list|()
block|{
return|return
operator|(
operator|(
literal|1
operator|<<
literal|9
operator|)
operator|-
literal|1
operator|)
operator|*
name|stackSlotSize
argument_list|()
return|;
block|}
comment|//! Minimum frame offset representable by a signed 10-bit integer
specifier|static
name|int
name|minFrameOffset
argument_list|()
block|{
return|return
operator|-
operator|(
literal|1
operator|<<
literal|9
operator|)
operator|*
name|stackSlotSize
argument_list|()
return|;
block|}
comment|//! Minimum frame size (enough to spill LR + SP)
specifier|static
name|int
name|minStackSize
argument_list|()
block|{
return|return
operator|(
literal|2
operator|*
name|stackSlotSize
argument_list|()
operator|)
return|;
block|}
comment|//! Frame size required to spill all registers plus frame info
specifier|static
name|int
name|fullSpillSize
argument_list|()
block|{
return|return
operator|(
name|SPURegisterInfo
operator|::
name|getNumArgRegs
argument_list|()
operator|*
name|stackSlotSize
argument_list|()
operator|)
return|;
block|}
comment|//! Convert frame index to stack offset
specifier|static
name|int
name|FItoStackOffset
argument_list|(
argument|int frame_index
argument_list|)
block|{
return|return
name|frame_index
operator|*
name|stackSlotSize
argument_list|()
return|;
block|}
comment|//! Number of instructions required to overcome hint-for-branch latency
comment|/*!       HBR (hint-for-branch) instructions can be inserted when, for example,       we know that a given function is going to be called, such as printf(),       in the control flow graph. HBRs are only inserted if a sufficient number       of instructions occurs between the HBR and the target. Currently, HBRs       take 6 cycles, ergo, the magic number 6.      */
specifier|static
name|int
name|branchHintPenalty
argument_list|()
block|{
return|return
literal|6
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_define
define|#
directive|define
name|SPUFRAMEINFO_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

