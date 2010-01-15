begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/AggressiveAntiDepBreaker.h - Anti-Dep Support -*- C++ -*-=//
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
comment|// This file implements the AggressiveAntiDepBreaker class, which
end_comment

begin_comment
comment|// implements register anti-dependence breaking during post-RA
end_comment

begin_comment
comment|// scheduling. It attempts to break all anti-dependencies within a
end_comment

begin_comment
comment|// block.
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
name|LLVM_CODEGEN_AGGRESSIVEANTIDEPBREAKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_AGGRESSIVEANTIDEPBREAKER_H
end_define

begin_include
include|#
directive|include
file|"AntiDepBreaker.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Class AggressiveAntiDepState
comment|/// Contains all the state necessary for anti-dep breaking.
name|class
name|AggressiveAntiDepState
block|{
name|public
label|:
comment|/// RegisterReference - Information about a register reference
comment|/// within a liverange
typedef|typedef
struct|struct
block|{
comment|/// Operand - The registers operand
name|MachineOperand
modifier|*
name|Operand
decl_stmt|;
comment|/// RC - The register class
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
decl_stmt|;
block|}
name|RegisterReference
typedef|;
name|private
label|:
comment|/// NumTargetRegs - Number of non-virtual target registers
comment|/// (i.e. TRI->getNumRegs()).
specifier|const
name|unsigned
name|NumTargetRegs
decl_stmt|;
comment|/// GroupNodes - Implements a disjoint-union data structure to
comment|/// form register groups. A node is represented by an index into
comment|/// the vector. A node can "point to" itself to indicate that it
comment|/// is the parent of a group, or point to another node to indicate
comment|/// that it is a member of the same group as that node.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|GroupNodes
expr_stmt|;
comment|/// GroupNodeIndices - For each register, the index of the GroupNode
comment|/// currently representing the group that the register belongs to.
comment|/// Register 0 is always represented by the 0 group, a group
comment|/// composed of registers that are not eligible for anti-aliasing.
name|unsigned
name|GroupNodeIndices
index|[
name|TargetRegisterInfo
operator|::
name|FirstVirtualRegister
index|]
decl_stmt|;
comment|/// RegRefs - Map registers to all their references within a live range.
name|std
operator|::
name|multimap
operator|<
name|unsigned
operator|,
name|RegisterReference
operator|>
name|RegRefs
expr_stmt|;
comment|/// KillIndices - The index of the most recent kill (proceding bottom-up),
comment|/// or ~0u if the register is not live.
name|unsigned
name|KillIndices
index|[
name|TargetRegisterInfo
operator|::
name|FirstVirtualRegister
index|]
decl_stmt|;
comment|/// DefIndices - The index of the most recent complete def (proceding bottom
comment|/// up), or ~0u if the register is live.
name|unsigned
name|DefIndices
index|[
name|TargetRegisterInfo
operator|::
name|FirstVirtualRegister
index|]
decl_stmt|;
name|public
label|:
name|AggressiveAntiDepState
argument_list|(
argument|const unsigned TargetRegs
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
empty_stmt|;
comment|/// GetKillIndices - Return the kill indices.
name|unsigned
modifier|*
name|GetKillIndices
parameter_list|()
block|{
return|return
name|KillIndices
return|;
block|}
comment|/// GetDefIndices - Return the define indices.
name|unsigned
modifier|*
name|GetDefIndices
parameter_list|()
block|{
return|return
name|DefIndices
return|;
block|}
comment|/// GetRegRefs - Return the RegRefs map.
name|std
operator|::
name|multimap
operator|<
name|unsigned
operator|,
name|RegisterReference
operator|>
operator|&
name|GetRegRefs
argument_list|()
block|{
return|return
name|RegRefs
return|;
block|}
comment|// GetGroup - Get the group for a register. The returned value is
comment|// the index of the GroupNode representing the group.
name|unsigned
name|GetGroup
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|// GetGroupRegs - Return a vector of the registers belonging to a
comment|// group. If RegRefs is non-NULL then only included referenced registers.
name|void
name|GetGroupRegs
argument_list|(
name|unsigned
name|Group
argument_list|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|Regs
argument_list|,
name|std
operator|::
name|multimap
operator|<
name|unsigned
argument_list|,
name|AggressiveAntiDepState
operator|::
name|RegisterReference
operator|>
operator|*
name|RegRefs
argument_list|)
decl_stmt|;
comment|// UnionGroups - Union Reg1's and Reg2's groups to form a new
comment|// group. Return the index of the GroupNode representing the
comment|// group.
name|unsigned
name|UnionGroups
parameter_list|(
name|unsigned
name|Reg1
parameter_list|,
name|unsigned
name|Reg2
parameter_list|)
function_decl|;
comment|// LeaveGroup - Remove a register from its current group and place
comment|// it alone in its own group. Return the index of the GroupNode
comment|// representing the registers new group.
name|unsigned
name|LeaveGroup
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|/// IsLive - Return true if Reg is live
name|bool
name|IsLive
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Class AggressiveAntiDepBreaker
name|class
name|AggressiveAntiDepBreaker
range|:
name|public
name|AntiDepBreaker
block|{
name|MachineFunction
operator|&
name|MF
block|;
name|MachineRegisterInfo
operator|&
name|MRI
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
comment|/// AllocatableSet - The set of allocatable registers.
comment|/// We'll be ignoring anti-dependencies on non-allocatable registers,
comment|/// because they may not be safe to break.
specifier|const
name|BitVector
name|AllocatableSet
block|;
comment|/// CriticalPathSet - The set of registers that should only be
comment|/// renamed if they are on the critical path.
name|BitVector
name|CriticalPathSet
block|;
comment|/// State - The state used to identify and rename anti-dependence
comment|/// registers.
name|AggressiveAntiDepState
operator|*
name|State
block|;
name|public
operator|:
name|AggressiveAntiDepBreaker
argument_list|(
name|MachineFunction
operator|&
name|MFi
argument_list|,
name|TargetSubtarget
operator|::
name|RegClassVector
operator|&
name|CriticalPathRCs
argument_list|)
block|;
operator|~
name|AggressiveAntiDepBreaker
argument_list|()
block|;
comment|/// Start - Initialize anti-dep breaking for a new basic block.
name|void
name|StartBlock
argument_list|(
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// BreakAntiDependencies - Identifiy anti-dependencies along the critical
comment|/// path
comment|/// of the ScheduleDAG and break them by renaming registers.
comment|///
name|unsigned
name|BreakAntiDependencies
argument_list|(
argument|std::vector<SUnit>& SUnits
argument_list|,
argument|MachineBasicBlock::iterator& Begin
argument_list|,
argument|MachineBasicBlock::iterator& End
argument_list|,
argument|unsigned InsertPosIndex
argument_list|)
block|;
comment|/// Observe - Update liveness information to account for the current
comment|/// instruction, which will not be scheduled.
comment|///
name|void
name|Observe
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Count
argument_list|,
argument|unsigned InsertPosIndex
argument_list|)
block|;
comment|/// Finish - Finish anti-dep breaking for a basic block.
name|void
name|FinishBlock
argument_list|()
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|,
name|TargetRegisterClass
operator|::
name|const_iterator
operator|>
name|RenameOrderType
expr_stmt|;
comment|/// IsImplicitDefUse - Return true if MO represents a register
comment|/// that is both implicitly used and defined in MI
name|bool
name|IsImplicitDefUse
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineOperand
operator|&
name|MO
argument_list|)
decl_stmt|;
comment|/// GetPassthruRegs - If MI implicitly def/uses a register, then
comment|/// return that register and all subregisters.
name|void
name|GetPassthruRegs
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|std
operator|::
name|set
operator|<
name|unsigned
operator|>
operator|&
name|PassthruRegs
argument_list|)
decl_stmt|;
name|void
name|HandleLastUse
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|KillIdx
parameter_list|,
specifier|const
name|char
modifier|*
name|tag
parameter_list|,
specifier|const
name|char
modifier|*
name|header
init|=
name|NULL
parameter_list|,
specifier|const
name|char
modifier|*
name|footer
init|=
name|NULL
parameter_list|)
function_decl|;
name|void
name|PrescanInstruction
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
name|Count
argument_list|,
name|std
operator|::
name|set
operator|<
name|unsigned
operator|>
operator|&
name|PassthruRegs
argument_list|)
decl_stmt|;
name|void
name|ScanInstruction
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
name|BitVector
name|GetRenameRegisters
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
name|bool
name|FindSuitableFreeRegisters
argument_list|(
name|unsigned
name|AntiDepGroupIndex
argument_list|,
name|RenameOrderType
operator|&
name|RenameOrder
argument_list|,
name|std
operator|::
name|map
operator|<
name|unsigned
argument_list|,
name|unsigned
operator|>
operator|&
name|RenameMap
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

