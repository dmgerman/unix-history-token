begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetFrameInfo.h ---------------------------*- C++ -*-===//
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
comment|// Interface to describe the layout of a stack frame on the target machine.
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
name|LLVM_TARGET_TARGETFRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETFRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Information about stack frame layout on the target.  It holds the direction
comment|/// of stack growth, the known stack alignment on entry to each function, and
comment|/// the offset to the locals area.
comment|///
comment|/// The offset to the local area is the offset from the stack pointer on
comment|/// function entry to the first location where function data (local variables,
comment|/// spill locations) can be stored.
name|class
name|TargetFrameInfo
block|{
name|public
label|:
enum|enum
name|StackDirection
block|{
name|StackGrowsUp
block|,
comment|// Adding to the stack increases the stack address
name|StackGrowsDown
comment|// Adding to the stack decreases the stack address
block|}
enum|;
comment|// Maps a callee saved register to a stack slot with a fixed offset.
struct|struct
name|SpillSlot
block|{
name|unsigned
name|Reg
decl_stmt|;
name|int
name|Offset
decl_stmt|;
comment|// Offset relative to stack pointer on function entry.
block|}
struct|;
name|private
label|:
name|StackDirection
name|StackDir
decl_stmt|;
name|unsigned
name|StackAlignment
decl_stmt|;
name|unsigned
name|TransientStackAlignment
decl_stmt|;
name|int
name|LocalAreaOffset
decl_stmt|;
name|public
label|:
name|TargetFrameInfo
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
block|:
name|StackDir
argument_list|(
name|D
argument_list|)
operator|,
name|StackAlignment
argument_list|(
name|StackAl
argument_list|)
operator|,
name|TransientStackAlignment
argument_list|(
name|TransAl
argument_list|)
operator|,
name|LocalAreaOffset
argument_list|(
argument|LAO
argument_list|)
block|{}
name|virtual
operator|~
name|TargetFrameInfo
argument_list|()
expr_stmt|;
comment|// These methods return information that describes the abstract stack layout
comment|// of the target machine.
comment|/// getStackGrowthDirection - Return the direction the stack grows
comment|///
name|StackDirection
name|getStackGrowthDirection
argument_list|()
specifier|const
block|{
return|return
name|StackDir
return|;
block|}
comment|/// getStackAlignment - This method returns the number of bytes to which the
comment|/// stack pointer must be aligned on entry to a function.  Typically, this
comment|/// is the largest alignment for any data object in the target.
comment|///
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
block|{
return|return
name|StackAlignment
return|;
block|}
comment|/// getTransientStackAlignment - This method returns the number of bytes to
comment|/// which the stack pointer must be aligned at all times, even between
comment|/// calls.
comment|///
name|unsigned
name|getTransientStackAlignment
argument_list|()
specifier|const
block|{
return|return
name|TransientStackAlignment
return|;
block|}
comment|/// getOffsetOfLocalArea - This method returns the offset of the local area
comment|/// from the stack pointer on entrance to a function.
comment|///
name|int
name|getOffsetOfLocalArea
argument_list|()
specifier|const
block|{
return|return
name|LocalAreaOffset
return|;
block|}
comment|/// getCalleeSavedSpillSlots - This method returns a pointer to an array of
comment|/// pairs, that contains an entry for each callee saved register that must be
comment|/// spilled to a particular stack location if it is spilled.
comment|///
comment|/// Each entry in this array contains a<register,offset> pair, indicating the
comment|/// fixed offset from the incoming stack pointer that each register should be
comment|/// spilled at. If a register is not listed here, the code generator is
comment|/// allowed to spill it anywhere it chooses.
comment|///
name|virtual
specifier|const
name|SpillSlot
modifier|*
name|getCalleeSavedSpillSlots
argument_list|(
name|unsigned
operator|&
name|NumEntries
argument_list|)
decl|const
block|{
name|NumEntries
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
empty_stmt|;
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

