begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/LiveVariables.h - Live Variable Analysis ---*- C++ -*-===//
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
comment|// This file implements the LiveVariables analysis pass.  For each machine
end_comment

begin_comment
comment|// instruction in the function, this pass calculates the set of registers that
end_comment

begin_comment
comment|// are immediately dead after the instruction (i.e., the instruction calculates
end_comment

begin_comment
comment|// the value, but it is never used) and the set of registers that are used by
end_comment

begin_comment
comment|// the instruction, but are never used after the instruction (i.e., they are
end_comment

begin_comment
comment|// killed).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class computes live variables using a sparse implementation based on
end_comment

begin_comment
comment|// the machine code SSA form.  This class computes live variable information for
end_comment

begin_comment
comment|// each virtual and _register allocatable_ physical register in a function.  It
end_comment

begin_comment
comment|// uses the dominance properties of SSA form to efficiently compute live
end_comment

begin_comment
comment|// variables for virtual registers, and assumes that physical registers are only
end_comment

begin_comment
comment|// live within a single basic block (allowing it to do a single local analysis
end_comment

begin_comment
comment|// to resolve physical register lifetimes in each basic block).  If a physical
end_comment

begin_comment
comment|// register is not register allocatable, it is not tracked.  This is useful for
end_comment

begin_comment
comment|// things like the stack pointer and condition codes.
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
name|LLVM_CODEGEN_LIVEVARIABLES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEVARIABLES_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseBitVector.h"
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
name|LiveVariables
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|LiveVariables
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|&ID
argument_list|)
block|{}
comment|/// VarInfo - This represents the regions where a virtual register is live in
comment|/// the program.  We represent this with three different pieces of
comment|/// information: the set of blocks in which the instruction is live
comment|/// throughout, the set of blocks in which the instruction is actually used,
comment|/// and the set of non-phi instructions that are the last users of the value.
comment|///
comment|/// In the common case where a value is defined and killed in the same block,
comment|/// There is one killing instruction, and AliveBlocks is empty.
comment|///
comment|/// Otherwise, the value is live out of the block.  If the value is live
comment|/// throughout any blocks, these blocks are listed in AliveBlocks.  Blocks
comment|/// where the liveness range ends are not included in AliveBlocks, instead
comment|/// being captured by the Kills set.  In these blocks, the value is live into
comment|/// the block (unless the value is defined and killed in the same block) and
comment|/// lives until the specified instruction.  Note that there cannot ever be a
comment|/// value whose Kills set contains two instructions from the same basic block.
comment|///
comment|/// PHI nodes complicate things a bit.  If a PHI node is the last user of a
comment|/// value in one of its predecessor blocks, it is not listed in the kills set,
comment|/// but does include the predecessor block in the AliveBlocks set (unless that
comment|/// block also defines the value).  This leads to the (perfectly sensical)
comment|/// situation where a value is defined in a block, and the last use is a phi
comment|/// node in the successor.  In this case, AliveBlocks is empty (the value is
comment|/// not live across any  blocks) and Kills is empty (phi nodes are not
comment|/// included). This is sensical because the value must be live to the end of
comment|/// the block, but is not live in any successor blocks.
expr|struct
name|VarInfo
block|{
comment|/// AliveBlocks - Set of blocks in which this value is alive completely
comment|/// through.  This is a bit set which uses the basic block number as an
comment|/// index.
comment|///
name|SparseBitVector
operator|<
operator|>
name|AliveBlocks
block|;
comment|/// NumUses - Number of uses of this register across the entire function.
comment|///
name|unsigned
name|NumUses
block|;
comment|/// Kills - List of MachineInstruction's which are the last use of this
comment|/// virtual register (kill it) in their basic block.
comment|///
name|std
operator|::
name|vector
operator|<
name|MachineInstr
operator|*
operator|>
name|Kills
block|;
name|VarInfo
argument_list|()
operator|:
name|NumUses
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// removeKill - Delete a kill corresponding to the specified
comment|/// machine instruction. Returns true if there was a kill
comment|/// corresponding to this instruction, false otherwise.
name|bool
name|removeKill
argument_list|(
argument|MachineInstr *MI
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|MachineInstr
operator|*
operator|>
operator|::
name|iterator
name|I
operator|=
name|std
operator|::
name|find
argument_list|(
name|Kills
operator|.
name|begin
argument_list|()
argument_list|,
name|Kills
operator|.
name|end
argument_list|()
argument_list|,
name|MI
argument_list|)
block|;
if|if
condition|(
name|I
operator|==
name|Kills
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
name|Kills
operator|.
name|erase
argument_list|(
name|I
argument_list|)
block|;
return|return
name|true
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
block|;   }
decl_stmt|;
name|private
label|:
comment|/// VirtRegInfo - This list is a mapping from virtual register number to
comment|/// variable information.  FirstVirtualRegister is subtracted from the virtual
comment|/// register number before indexing into this list.
comment|///
name|std
operator|::
name|vector
operator|<
name|VarInfo
operator|>
name|VirtRegInfo
expr_stmt|;
comment|/// ReservedRegisters - This vector keeps track of which registers
comment|/// are reserved register which are not allocatable by the target machine.
comment|/// We can not track liveness for values that are in this set.
comment|///
name|BitVector
name|ReservedRegisters
decl_stmt|;
name|private
label|:
comment|// Intermediate data structures
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
comment|// PhysRegInfo - Keep track of which instruction was the last def of a
comment|// physical register. This is a purely local property, because all physical
comment|// register references are presumed dead across basic blocks.
name|MachineInstr
modifier|*
modifier|*
name|PhysRegDef
decl_stmt|;
comment|// PhysRegInfo - Keep track of which instruction was the last use of a
comment|// physical register. This is a purely local property, because all physical
comment|// register references are presumed dead across basic blocks.
name|MachineInstr
modifier|*
modifier|*
name|PhysRegUse
decl_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
operator|*
name|PHIVarInfo
expr_stmt|;
comment|// DistanceMap - Keep track the distance of a MI from the start of the
comment|// current basic block.
name|DenseMap
operator|<
name|MachineInstr
operator|*
operator|,
name|unsigned
operator|>
name|DistanceMap
expr_stmt|;
comment|/// HandlePhysRegKill - Add kills of Reg and its sub-registers to the
comment|/// uses. Pay special attention to the sub-register uses which may come below
comment|/// the last use of the whole register.
name|bool
name|HandlePhysRegKill
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
name|void
name|HandlePhysRegUse
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
name|void
name|HandlePhysRegDef
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|,
name|SmallVector
operator|<
name|unsigned
argument_list|,
literal|4
operator|>
operator|&
name|Defs
argument_list|)
decl_stmt|;
name|void
name|UpdatePhysRegDefs
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|SmallVector
operator|<
name|unsigned
argument_list|,
literal|4
operator|>
operator|&
name|Defs
argument_list|)
decl_stmt|;
comment|/// FindLastPartialDef - Return the last partial def of the specified register.
comment|/// Also returns the sub-registers that're defined by the instruction.
name|MachineInstr
modifier|*
name|FindLastPartialDef
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|SmallSet
operator|<
name|unsigned
argument_list|,
literal|4
operator|>
operator|&
name|PartDefRegs
argument_list|)
decl_stmt|;
comment|/// analyzePHINodes - Gather information about the PHI nodes in here. In
comment|/// particular, we want to map the variable information of a virtual
comment|/// register which is used in a PHI node. We map that to the BB the vreg
comment|/// is coming from.
name|void
name|analyzePHINodes
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|public
label|:
name|virtual
name|bool
name|runOnMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// RegisterDefIsDead - Return true if the specified instruction defines the
comment|/// specified register, but that definition is dead.
name|bool
name|RegisterDefIsDead
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//  API to update live variable information
comment|/// replaceKillInstruction - Update register kill info by replacing a kill
comment|/// instruction with a new one.
name|void
name|replaceKillInstruction
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|MachineInstr
modifier|*
name|OldMI
parameter_list|,
name|MachineInstr
modifier|*
name|NewMI
parameter_list|)
function_decl|;
comment|/// addVirtualRegisterKilled - Add information about the fact that the
comment|/// specified register is killed after being used by the specified
comment|/// instruction. If AddIfNotFound is true, add a implicit operand if it's
comment|/// not found.
name|void
name|addVirtualRegisterKilled
parameter_list|(
name|unsigned
name|IncomingReg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|bool
name|AddIfNotFound
init|=
name|false
parameter_list|)
block|{
if|if
condition|(
name|MI
operator|->
name|addRegisterKilled
argument_list|(
name|IncomingReg
argument_list|,
name|TRI
argument_list|,
name|AddIfNotFound
argument_list|)
condition|)
name|getVarInfo
argument_list|(
name|IncomingReg
argument_list|)
operator|.
name|Kills
operator|.
name|push_back
argument_list|(
name|MI
argument_list|)
expr_stmt|;
block|}
comment|/// removeVirtualRegisterKilled - Remove the specified kill of the virtual
comment|/// register from the live variable information. Returns true if the
comment|/// variable was marked as killed by the specified instruction,
comment|/// false otherwise.
name|bool
name|removeVirtualRegisterKilled
parameter_list|(
name|unsigned
name|reg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
if|if
condition|(
operator|!
name|getVarInfo
argument_list|(
name|reg
argument_list|)
operator|.
name|removeKill
argument_list|(
name|MI
argument_list|)
condition|)
return|return
name|false
return|;
name|bool
name|Removed
init|=
name|false
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|MI
operator|->
name|getNumOperands
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|MachineOperand
modifier|&
name|MO
init|=
name|MI
operator|->
name|getOperand
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|MO
operator|.
name|isReg
argument_list|()
operator|&&
name|MO
operator|.
name|isKill
argument_list|()
operator|&&
name|MO
operator|.
name|getReg
argument_list|()
operator|==
name|reg
condition|)
block|{
name|MO
operator|.
name|setIsKill
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|Removed
operator|=
name|true
expr_stmt|;
break|break;
block|}
block|}
name|assert
argument_list|(
name|Removed
operator|&&
literal|"Register is not used by this instruction!"
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
comment|/// removeVirtualRegistersKilled - Remove all killed info for the specified
comment|/// instruction.
name|void
name|removeVirtualRegistersKilled
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// addVirtualRegisterDead - Add information about the fact that the specified
comment|/// register is dead after being used by the specified instruction. If
comment|/// AddIfNotFound is true, add a implicit operand if it's not found.
name|void
name|addVirtualRegisterDead
parameter_list|(
name|unsigned
name|IncomingReg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|bool
name|AddIfNotFound
init|=
name|false
parameter_list|)
block|{
if|if
condition|(
name|MI
operator|->
name|addRegisterDead
argument_list|(
name|IncomingReg
argument_list|,
name|TRI
argument_list|,
name|AddIfNotFound
argument_list|)
condition|)
name|getVarInfo
argument_list|(
name|IncomingReg
argument_list|)
operator|.
name|Kills
operator|.
name|push_back
argument_list|(
name|MI
argument_list|)
expr_stmt|;
block|}
comment|/// removeVirtualRegisterDead - Remove the specified kill of the virtual
comment|/// register from the live variable information. Returns true if the
comment|/// variable was marked dead at the specified instruction, false
comment|/// otherwise.
name|bool
name|removeVirtualRegisterDead
parameter_list|(
name|unsigned
name|reg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
if|if
condition|(
operator|!
name|getVarInfo
argument_list|(
name|reg
argument_list|)
operator|.
name|removeKill
argument_list|(
name|MI
argument_list|)
condition|)
return|return
name|false
return|;
name|bool
name|Removed
init|=
name|false
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|MI
operator|->
name|getNumOperands
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|MachineOperand
modifier|&
name|MO
init|=
name|MI
operator|->
name|getOperand
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|MO
operator|.
name|isReg
argument_list|()
operator|&&
name|MO
operator|.
name|isDef
argument_list|()
operator|&&
name|MO
operator|.
name|getReg
argument_list|()
operator|==
name|reg
condition|)
block|{
name|MO
operator|.
name|setIsDead
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|Removed
operator|=
name|true
expr_stmt|;
break|break;
block|}
block|}
name|assert
argument_list|(
name|Removed
operator|&&
literal|"Register is not defined by this instruction!"
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|releaseMemory
parameter_list|()
block|{
name|VirtRegInfo
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// getVarInfo - Return the VarInfo structure for the specified VIRTUAL
comment|/// register.
name|VarInfo
modifier|&
name|getVarInfo
parameter_list|(
name|unsigned
name|RegIdx
parameter_list|)
function_decl|;
name|void
name|MarkVirtRegAliveInBlock
parameter_list|(
name|VarInfo
modifier|&
name|VRInfo
parameter_list|,
name|MachineBasicBlock
modifier|*
name|DefBlock
parameter_list|,
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|void
name|MarkVirtRegAliveInBlock
argument_list|(
name|VarInfo
operator|&
name|VRInfo
argument_list|,
name|MachineBasicBlock
operator|*
name|DefBlock
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|WorkList
argument_list|)
decl_stmt|;
name|void
name|HandleVirtRegDef
parameter_list|(
name|unsigned
name|reg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
name|void
name|HandleVirtRegUse
parameter_list|(
name|unsigned
name|reg
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

