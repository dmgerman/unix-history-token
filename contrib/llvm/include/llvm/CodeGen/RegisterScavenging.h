begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterScavenging.h - Machine register scavenging ------*- C++ -*-===//
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
comment|// This file declares the machine register scavenger class. It can provide
end_comment

begin_comment
comment|// information such as unused register at any point in a machine basic block.
end_comment

begin_comment
comment|// It also provides a mechanism to make registers availbale by evicting them
end_comment

begin_comment
comment|// to spill slots.
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
name|LLVM_CODEGEN_REGISTER_SCAVENGING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGISTER_SCAVENGING_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|RegScavenger
block|{
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
name|MachineBasicBlock
operator|::
name|iterator
name|MBBI
expr_stmt|;
name|unsigned
name|NumPhysRegs
decl_stmt|;
comment|/// Tracking - True if RegScavenger is currently tracking the liveness of
comment|/// registers.
name|bool
name|Tracking
decl_stmt|;
comment|/// ScavengingFrameIndex - Special spill slot used for scavenging a register
comment|/// post register allocation.
name|int
name|ScavengingFrameIndex
decl_stmt|;
comment|/// ScavengedReg - If none zero, the specific register is currently being
comment|/// scavenged. That is, it is spilled to the special scavenging stack slot.
name|unsigned
name|ScavengedReg
decl_stmt|;
comment|/// ScavengedRC - Register class of the scavenged register.
comment|///
specifier|const
name|TargetRegisterClass
modifier|*
name|ScavengedRC
decl_stmt|;
comment|/// ScavengeRestore - Instruction that restores the scavenged register from
comment|/// stack.
specifier|const
name|MachineInstr
modifier|*
name|ScavengeRestore
decl_stmt|;
comment|/// CalleeSavedrRegs - A bitvector of callee saved registers for the target.
comment|///
name|BitVector
name|CalleeSavedRegs
decl_stmt|;
comment|/// ReservedRegs - A bitvector of reserved registers.
comment|///
name|BitVector
name|ReservedRegs
decl_stmt|;
comment|/// RegsAvailable - The current state of all the physical registers immediately
comment|/// before MBBI. One bit per physical register. If bit is set that means it's
comment|/// available, unset means the register is currently being used.
name|BitVector
name|RegsAvailable
decl_stmt|;
name|public
label|:
name|RegScavenger
argument_list|()
operator|:
name|MBB
argument_list|(
name|NULL
argument_list|)
operator|,
name|NumPhysRegs
argument_list|(
literal|0
argument_list|)
operator|,
name|Tracking
argument_list|(
name|false
argument_list|)
operator|,
name|ScavengingFrameIndex
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|ScavengedReg
argument_list|(
literal|0
argument_list|)
operator|,
name|ScavengedRC
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|/// enterBasicBlock - Start tracking liveness from the begin of the specific
comment|/// basic block.
name|void
name|enterBasicBlock
argument_list|(
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
expr_stmt|;
comment|/// initRegState - allow resetting register state info for multiple
comment|/// passes over/within the same function.
name|void
name|initRegState
parameter_list|()
function_decl|;
comment|/// forward - Move the internal MBB iterator and update register states.
name|void
name|forward
parameter_list|()
function_decl|;
comment|/// forward - Move the internal MBB iterator and update register states until
comment|/// it has processed the specific iterator.
name|void
name|forward
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|I
argument_list|)
block|{
if|if
condition|(
operator|!
name|Tracking
operator|&&
name|MBB
operator|->
name|begin
argument_list|()
operator|!=
name|I
condition|)
name|forward
argument_list|()
expr_stmt|;
while|while
condition|(
name|MBBI
operator|!=
name|I
condition|)
name|forward
argument_list|()
expr_stmt|;
block|}
comment|/// skipTo - Move the internal MBB iterator but do not update register states.
comment|///
name|void
name|skipTo
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|I
argument_list|)
block|{
name|MBBI
operator|=
name|I
expr_stmt|;
block|}
comment|/// getRegsUsed - return all registers currently in use in used.
name|void
name|getRegsUsed
parameter_list|(
name|BitVector
modifier|&
name|used
parameter_list|,
name|bool
name|includeReserved
parameter_list|)
function_decl|;
comment|/// FindUnusedReg - Find a unused register of the specified register class.
comment|/// Return 0 if none is found.
name|unsigned
name|FindUnusedReg
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RegClass
argument_list|)
decl|const
decl_stmt|;
comment|/// setScavengingFrameIndex / getScavengingFrameIndex - accessor and setter of
comment|/// ScavengingFrameIndex.
name|void
name|setScavengingFrameIndex
parameter_list|(
name|int
name|FI
parameter_list|)
block|{
name|ScavengingFrameIndex
operator|=
name|FI
expr_stmt|;
block|}
name|int
name|getScavengingFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|ScavengingFrameIndex
return|;
block|}
comment|/// scavengeRegister - Make a register of the specific register class
comment|/// available and do the appropriate bookkeeping. SPAdj is the stack
comment|/// adjustment due to call frame, it's passed along to eliminateFrameIndex().
comment|/// Returns the scavenged register.
name|unsigned
name|scavengeRegister
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RegClass
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|I
argument_list|,
name|int
name|SPAdj
argument_list|)
decl_stmt|;
name|unsigned
name|scavengeRegister
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|RegClass
parameter_list|,
name|int
name|SPAdj
parameter_list|)
block|{
return|return
name|scavengeRegister
argument_list|(
name|RegClass
argument_list|,
name|MBBI
argument_list|,
name|SPAdj
argument_list|)
return|;
block|}
comment|/// setUsed - Tell the scavenger a register is used.
comment|///
name|void
name|setUsed
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
name|private
label|:
comment|/// isReserved - Returns true if a register is reserved. It is never "unused".
name|bool
name|isReserved
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|ReservedRegs
operator|.
name|test
argument_list|(
name|Reg
argument_list|)
return|;
block|}
comment|/// isUsed / isUnused - Test if a register is currently being used.
comment|///
name|bool
name|isUsed
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
operator|!
name|RegsAvailable
operator|.
name|test
argument_list|(
name|Reg
argument_list|)
return|;
block|}
name|bool
name|isUnused
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|RegsAvailable
operator|.
name|test
argument_list|(
name|Reg
argument_list|)
return|;
block|}
comment|/// isAliasUsed - Is Reg or an alias currently in use?
name|bool
name|isAliasUsed
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|/// setUsed / setUnused - Mark the state of one or a number of registers.
comment|///
name|void
name|setUsed
parameter_list|(
name|BitVector
modifier|&
name|Regs
parameter_list|)
block|{
name|RegsAvailable
operator|&=
operator|~
name|Regs
expr_stmt|;
block|}
name|void
name|setUnused
parameter_list|(
name|BitVector
modifier|&
name|Regs
parameter_list|)
block|{
name|RegsAvailable
operator||=
name|Regs
expr_stmt|;
block|}
comment|/// Add Reg and all its sub-registers to BV.
name|void
name|addRegWithSubRegs
parameter_list|(
name|BitVector
modifier|&
name|BV
parameter_list|,
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|/// Add Reg and its aliases to BV.
name|void
name|addRegWithAliases
parameter_list|(
name|BitVector
modifier|&
name|BV
parameter_list|,
name|unsigned
name|Reg
parameter_list|)
function_decl|;
name|unsigned
name|findSurvivorReg
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|BitVector
operator|&
name|Candidates
argument_list|,
name|unsigned
name|InstrLimit
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
operator|&
name|UseMI
argument_list|)
decl_stmt|;
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

