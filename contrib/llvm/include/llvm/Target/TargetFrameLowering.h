begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetFrameLowering.h ---------------------------*- C++ -*-===//
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
name|LLVM_TARGET_TARGETFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETFRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CalleeSavedInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|RegScavenger
decl_stmt|;
comment|/// Information about stack frame layout on the target.  It holds the direction
comment|/// of stack growth, the known stack alignment on entry to each function, and
comment|/// the offset to the locals area.
comment|///
comment|/// The offset to the local area is the offset from the stack pointer on
comment|/// function entry to the first location where function data (local variables,
comment|/// spill locations) can be stored.
name|class
name|TargetFrameLowering
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
name|bool
name|StackRealignable
decl_stmt|;
name|public
label|:
name|TargetFrameLowering
argument_list|(
argument|StackDirection D
argument_list|,
argument|unsigned StackAl
argument_list|,
argument|int LAO
argument_list|,
argument|unsigned TransAl =
literal|1
argument_list|,
argument|bool StackReal = true
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
name|LAO
argument_list|)
operator|,
name|StackRealignable
argument_list|(
argument|StackReal
argument_list|)
block|{}
name|virtual
operator|~
name|TargetFrameLowering
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
comment|/// isStackRealignable - This method returns whether the stack can be
comment|/// realigned.
name|bool
name|isStackRealignable
argument_list|()
specifier|const
block|{
return|return
name|StackRealignable
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
comment|/// isFPCloseToIncomingSP - Return true if the frame pointer is close to
comment|/// the incoming stack pointer, false if it is close to the post-prologue
comment|/// stack pointer.
name|virtual
name|bool
name|isFPCloseToIncomingSP
argument_list|()
specifier|const
block|{
return|return
name|true
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
comment|/// targetHandlesStackFrameRounding - Returns true if the target is
comment|/// responsible for rounding up the stack frame (probably at emitPrologue
comment|/// time).
name|virtual
name|bool
name|targetHandlesStackFrameRounding
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// emitProlog/emitEpilog - These methods insert prolog and epilog code into
comment|/// the function.
name|virtual
name|void
name|emitPrologue
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|emitEpilogue
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Adjust the prologue to have the function use segmented stacks. This works
comment|/// by adding a check even before the "normal" function prologue.
name|virtual
name|void
name|adjustForSegmentedStacks
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{ }
comment|/// Adjust the prologue to add Erlang Run-Time System (ERTS) specific code in
comment|/// the assembly prologue to explicitly handle the stack.
name|virtual
name|void
name|adjustForHiPEPrologue
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{ }
comment|/// spillCalleeSavedRegisters - Issues instruction(s) to spill all callee
comment|/// saved registers and returns true if it isn't possible / profitable to do
comment|/// so by issuing a series of store instructions via
comment|/// storeRegToStackSlot(). Returns false otherwise.
name|virtual
name|bool
name|spillCalleeSavedRegisters
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|CalleeSavedInfo
operator|>
operator|&
name|CSI
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// restoreCalleeSavedRegisters - Issues instruction(s) to restore all callee
comment|/// saved registers and returns true if it isn't possible / profitable to do
comment|/// so by issuing a series of load instructions via loadRegToStackSlot().
comment|/// Returns false otherwise.
name|virtual
name|bool
name|restoreCalleeSavedRegisters
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|CalleeSavedInfo
operator|>
operator|&
name|CSI
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// hasFP - Return true if the specified function should have a dedicated
comment|/// frame pointer register. For most targets this is true only if the function
comment|/// has variable sized allocas or if frame pointer elimination is disabled.
name|virtual
name|bool
name|hasFP
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// hasReservedCallFrame - Under normal circumstances, when a frame pointer is
comment|/// not required, we reserve argument space for call sites in the function
comment|/// immediately on entry to the current function. This eliminates the need for
comment|/// add/sub sp brackets around call sites. Returns true if the call frame is
comment|/// included as part of the stack frame.
name|virtual
name|bool
name|hasReservedCallFrame
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
operator|!
name|hasFP
argument_list|(
name|MF
argument_list|)
return|;
block|}
comment|/// canSimplifyCallFramePseudos - When possible, it's best to simplify the
comment|/// call frame pseudo ops before doing frame index elimination. This is
comment|/// possible only when frame index references between the pseudos won't
comment|/// need adjusting for the call frame adjustments. Normally, that's true
comment|/// if the function has a reserved call frame or a frame pointer. Some
comment|/// targets (Thumb2, for example) may have more complicated criteria,
comment|/// however, and can override this behavior.
name|virtual
name|bool
name|canSimplifyCallFramePseudos
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|hasReservedCallFrame
argument_list|(
name|MF
argument_list|)
operator|||
name|hasFP
argument_list|(
name|MF
argument_list|)
return|;
block|}
comment|/// getFrameIndexOffset - Returns the displacement from the frame register to
comment|/// the stack frame of the specified index.
name|virtual
name|int
name|getFrameIndexOffset
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|int
name|FI
argument_list|)
decl|const
decl_stmt|;
comment|/// getFrameIndexReference - This method should return the base register
comment|/// and offset used to reference a frame index location. The offset is
comment|/// returned directly, and the base register is returned via FrameReg.
name|virtual
name|int
name|getFrameIndexReference
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|int
name|FI
argument_list|,
name|unsigned
operator|&
name|FrameReg
argument_list|)
decl|const
decl_stmt|;
comment|/// processFunctionBeforeCalleeSavedScan - This method is called immediately
comment|/// before PrologEpilogInserter scans the physical registers used to determine
comment|/// what callee saved registers should be spilled. This method is optional.
name|virtual
name|void
name|processFunctionBeforeCalleeSavedScan
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|RegScavenger
operator|*
name|RS
operator|=
name|NULL
argument_list|)
decl|const
block|{    }
comment|/// processFunctionBeforeFrameFinalized - This method is called immediately
comment|/// before the specified function's frame layout (MF.getFrameInfo()) is
comment|/// finalized.  Once the frame is finalized, MO_FrameIndex operands are
comment|/// replaced with direct constants.  This method is optional.
comment|///
name|virtual
name|void
name|processFunctionBeforeFrameFinalized
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|RegScavenger
operator|*
name|RS
operator|=
name|NULL
argument_list|)
decl|const
block|{   }
comment|/// eliminateCallFramePseudoInstr - This method is called during prolog/epilog
comment|/// code insertion to eliminate call frame setup and destroy pseudo
comment|/// instructions (but only if the Target is using them).  It is responsible
comment|/// for eliminating these instructions, replacing them with concrete
comment|/// instructions.  This method need only be implemented if using call frame
comment|/// setup/destroy pseudo instructions.
comment|///
name|virtual
name|void
name|eliminateCallFramePseudoInstr
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Call Frame Pseudo Instructions do not exist on this "
literal|"target!"
argument_list|)
expr_stmt|;
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

