begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- LiveRangeEdit.h - Basic tools for split and spill -----*- C++ -*-===//
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
comment|// The LiveRangeEdit class represents changes done to a virtual register when it
end_comment

begin_comment
comment|// is spilled or split.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The parent register is never changed. Instead, a number of new virtual
end_comment

begin_comment
comment|// registers are created and added to the newRegs vector.
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
name|LLVM_CODEGEN_LIVERANGEEDIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVERANGEEDIT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineBlockFrequencyInfo
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|LiveRangeEdit
range|:
name|private
name|MachineRegisterInfo
operator|::
name|Delegate
block|{
name|public
operator|:
comment|/// Callback methods for LiveRangeEdit owners.
name|class
name|Delegate
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
comment|/// Called immediately before erasing a dead machine instruction.
name|virtual
name|void
name|LRE_WillEraseInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|)
block|{}
comment|/// Called when a virtual register is no longer used. Return false to defer
comment|/// its deletion from LiveIntervals.
name|virtual
name|bool
name|LRE_CanEraseVirtReg
argument_list|(
argument|unsigned
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// Called before shrinking the live range of a virtual register.
name|virtual
name|void
name|LRE_WillShrinkVirtReg
argument_list|(
argument|unsigned
argument_list|)
block|{}
comment|/// Called after cloning a virtual register.
comment|/// This is used for new registers representing connected components of Old.
name|virtual
name|void
name|LRE_DidCloneVirtReg
argument_list|(
argument|unsigned New
argument_list|,
argument|unsigned Old
argument_list|)
block|{}
name|virtual
operator|~
name|Delegate
argument_list|()
block|{}
expr|}
block|;
name|private
operator|:
name|LiveInterval
operator|*
name|Parent
block|;
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|NewRegs
block|;
name|MachineRegisterInfo
operator|&
name|MRI
block|;
name|LiveIntervals
operator|&
name|LIS
block|;
name|VirtRegMap
operator|*
name|VRM
block|;
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|Delegate
operator|*
specifier|const
name|TheDelegate
block|;
comment|/// FirstNew - Index of the first register added to NewRegs.
specifier|const
name|unsigned
name|FirstNew
block|;
comment|/// ScannedRemattable - true when remattable values have been identified.
name|bool
name|ScannedRemattable
block|;
comment|/// Remattable - Values defined by remattable instructions as identified by
comment|/// tii.isTriviallyReMaterializable().
name|SmallPtrSet
operator|<
specifier|const
name|VNInfo
operator|*
block|,
literal|4
operator|>
name|Remattable
block|;
comment|/// Rematted - Values that were actually rematted, and so need to have their
comment|/// live range trimmed or entirely removed.
name|SmallPtrSet
operator|<
specifier|const
name|VNInfo
operator|*
block|,
literal|4
operator|>
name|Rematted
block|;
comment|/// scanRemattable - Identify the Parent values that may rematerialize.
name|void
name|scanRemattable
argument_list|(
name|AliasAnalysis
operator|*
name|aa
argument_list|)
block|;
comment|/// allUsesAvailableAt - Return true if all registers used by OrigMI at
comment|/// OrigIdx are also available with the same value at UseIdx.
name|bool
name|allUsesAvailableAt
argument_list|(
argument|const MachineInstr *OrigMI
argument_list|,
argument|SlotIndex OrigIdx
argument_list|,
argument|SlotIndex UseIdx
argument_list|)
specifier|const
block|;
comment|/// foldAsLoad - If LI has a single use and a single def that can be folded as
comment|/// a load, eliminate the register by folding the def into the use.
name|bool
name|foldAsLoad
argument_list|(
name|LiveInterval
operator|*
name|LI
argument_list|,
name|SmallVectorImpl
operator|<
name|MachineInstr
operator|*
operator|>
operator|&
name|Dead
argument_list|)
block|;
typedef|typedef
name|SetVector
operator|<
name|LiveInterval
operator|*
operator|,
name|SmallVector
operator|<
name|LiveInterval
operator|*
operator|,
literal|8
operator|>
operator|,
name|SmallPtrSet
operator|<
name|LiveInterval
operator|*
operator|,
literal|8
operator|>
expr|>
name|ToShrinkSet
expr_stmt|;
comment|/// Helper for eliminateDeadDefs.
name|void
name|eliminateDeadDef
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|ToShrinkSet
operator|&
name|ToShrink
argument_list|)
block|;
comment|/// MachineRegisterInfo callback to notify when new virtual
comment|/// registers are created.
name|void
name|MRI_NoteNewVirtualRegister
argument_list|(
argument|unsigned VReg
argument_list|)
block|;
name|public
operator|:
comment|/// Create a LiveRangeEdit for breaking down parent into smaller pieces.
comment|/// @param parent The register being spilled or split.
comment|/// @param newRegs List to receive any new registers created. This needn't be
comment|///                empty initially, any existing registers are ignored.
comment|/// @param MF The MachineFunction the live range edit is taking place in.
comment|/// @param lis The collection of all live intervals in this function.
comment|/// @param vrm Map of virtual registers to physical registers for this
comment|///            function.  If NULL, no virtual register map updates will
comment|///            be done.  This could be the case if called before Regalloc.
name|LiveRangeEdit
argument_list|(
name|LiveInterval
operator|*
name|parent
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|newRegs
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|,
name|LiveIntervals
operator|&
name|lis
argument_list|,
name|VirtRegMap
operator|*
name|vrm
argument_list|,
name|Delegate
operator|*
name|delegate
operator|=
literal|0
argument_list|)
operator|:
name|Parent
argument_list|(
name|parent
argument_list|)
block|,
name|NewRegs
argument_list|(
name|newRegs
argument_list|)
block|,
name|MRI
argument_list|(
name|MF
operator|.
name|getRegInfo
argument_list|()
argument_list|)
block|,
name|LIS
argument_list|(
name|lis
argument_list|)
block|,
name|VRM
argument_list|(
name|vrm
argument_list|)
block|,
name|TII
argument_list|(
operator|*
name|MF
operator|.
name|getTarget
argument_list|()
operator|.
name|getInstrInfo
argument_list|()
argument_list|)
block|,
name|TheDelegate
argument_list|(
name|delegate
argument_list|)
block|,
name|FirstNew
argument_list|(
name|newRegs
operator|.
name|size
argument_list|()
argument_list|)
block|,
name|ScannedRemattable
argument_list|(
argument|false
argument_list|)
block|{
name|MRI
operator|.
name|setDelegate
argument_list|(
name|this
argument_list|)
block|; }
operator|~
name|LiveRangeEdit
argument_list|()
block|{
name|MRI
operator|.
name|resetDelegate
argument_list|(
name|this
argument_list|)
block|; }
name|LiveInterval
operator|&
name|getParent
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Parent
operator|&&
literal|"No parent LiveInterval"
argument_list|)
block|;
return|return
operator|*
name|Parent
return|;
block|}
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
return|return
name|getParent
argument_list|()
operator|.
name|reg
return|;
block|}
comment|/// Iterator for accessing the new registers added by this edit.
typedef|typedef
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|NewRegs
operator|.
name|begin
argument_list|()
operator|+
name|FirstNew
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|NewRegs
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NewRegs
operator|.
name|size
argument_list|()
operator|-
name|FirstNew
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
name|unsigned
name|get
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|{
return|return
name|NewRegs
index|[
name|idx
operator|+
name|FirstNew
index|]
return|;
block|}
name|ArrayRef
operator|<
name|unsigned
operator|>
name|regs
argument_list|()
specifier|const
block|{
return|return
name|makeArrayRef
argument_list|(
name|NewRegs
argument_list|)
operator|.
name|slice
argument_list|(
name|FirstNew
argument_list|)
return|;
block|}
comment|/// createEmptyIntervalFrom - Create a new empty interval based on OldReg.
name|LiveInterval
operator|&
name|createEmptyIntervalFrom
argument_list|(
argument|unsigned OldReg
argument_list|)
decl_stmt|;
comment|/// createFrom - Create a new virtual register based on OldReg.
name|unsigned
name|createFrom
parameter_list|(
name|unsigned
name|OldReg
parameter_list|)
function_decl|;
comment|/// create - Create a new register with the same class and original slot as
comment|/// parent.
name|LiveInterval
modifier|&
name|createEmptyInterval
parameter_list|()
block|{
return|return
name|createEmptyIntervalFrom
argument_list|(
name|getReg
argument_list|()
argument_list|)
return|;
block|}
name|unsigned
name|create
parameter_list|()
block|{
return|return
name|createFrom
argument_list|(
name|getReg
argument_list|()
argument_list|)
return|;
block|}
comment|/// anyRematerializable - Return true if any parent values may be
comment|/// rematerializable.
comment|/// This function must be called before any rematerialization is attempted.
name|bool
name|anyRematerializable
parameter_list|(
name|AliasAnalysis
modifier|*
parameter_list|)
function_decl|;
comment|/// checkRematerializable - Manually add VNI to the list of rematerializable
comment|/// values if DefMI may be rematerializable.
name|bool
name|checkRematerializable
parameter_list|(
name|VNInfo
modifier|*
name|VNI
parameter_list|,
specifier|const
name|MachineInstr
modifier|*
name|DefMI
parameter_list|,
name|AliasAnalysis
modifier|*
parameter_list|)
function_decl|;
comment|/// Remat - Information needed to rematerialize at a specific location.
struct|struct
name|Remat
block|{
name|VNInfo
modifier|*
name|ParentVNI
decl_stmt|;
comment|// parent_'s value at the remat location.
name|MachineInstr
modifier|*
name|OrigMI
decl_stmt|;
comment|// Instruction defining ParentVNI.
name|explicit
name|Remat
argument_list|(
name|VNInfo
operator|*
name|ParentVNI
argument_list|)
operator|:
name|ParentVNI
argument_list|(
name|ParentVNI
argument_list|)
operator|,
name|OrigMI
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|/// canRematerializeAt - Determine if ParentVNI can be rematerialized at
comment|/// UseIdx. It is assumed that parent_.getVNINfoAt(UseIdx) == ParentVNI.
comment|/// When cheapAsAMove is set, only cheap remats are allowed.
name|bool
name|canRematerializeAt
parameter_list|(
name|Remat
modifier|&
name|RM
parameter_list|,
name|SlotIndex
name|UseIdx
parameter_list|,
name|bool
name|cheapAsAMove
parameter_list|)
function_decl|;
comment|/// rematerializeAt - Rematerialize RM.ParentVNI into DestReg by inserting an
comment|/// instruction into MBB before MI. The new instruction is mapped, but
comment|/// liveness is not updated.
comment|/// Return the SlotIndex of the new instruction.
name|SlotIndex
name|rematerializeAt
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
name|unsigned
name|DestReg
argument_list|,
specifier|const
name|Remat
operator|&
name|RM
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
argument_list|,
name|bool
name|Late
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// markRematerialized - explicitly mark a value as rematerialized after doing
comment|/// it manually.
name|void
name|markRematerialized
parameter_list|(
specifier|const
name|VNInfo
modifier|*
name|ParentVNI
parameter_list|)
block|{
name|Rematted
operator|.
name|insert
argument_list|(
name|ParentVNI
argument_list|)
expr_stmt|;
block|}
comment|/// didRematerialize - Return true if ParentVNI was rematerialized anywhere.
name|bool
name|didRematerialize
argument_list|(
specifier|const
name|VNInfo
operator|*
name|ParentVNI
argument_list|)
decl|const
block|{
return|return
name|Rematted
operator|.
name|count
argument_list|(
name|ParentVNI
argument_list|)
return|;
block|}
comment|/// eraseVirtReg - Notify the delegate that Reg is no longer in use, and try
comment|/// to erase it from LIS.
name|void
name|eraseVirtReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|/// eliminateDeadDefs - Try to delete machine instructions that are now dead
comment|/// (allDefsAreDead returns true). This may cause live intervals to be trimmed
comment|/// and further dead efs to be eliminated.
comment|/// RegsBeingSpilled lists registers currently being spilled by the register
comment|/// allocator.  These registers should not be split into new intervals
comment|/// as currently those new intervals are not guaranteed to spill.
name|void
name|eliminateDeadDefs
argument_list|(
name|SmallVectorImpl
operator|<
name|MachineInstr
operator|*
operator|>
operator|&
name|Dead
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|RegsBeingSpilled
operator|=
name|None
argument_list|)
decl_stmt|;
comment|/// calculateRegClassAndHint - Recompute register class and hint for each new
comment|/// register.
name|void
name|calculateRegClassAndHint
parameter_list|(
name|MachineFunction
modifier|&
parameter_list|,
specifier|const
name|MachineLoopInfo
modifier|&
parameter_list|,
specifier|const
name|MachineBlockFrequencyInfo
modifier|&
parameter_list|)
function_decl|;
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

