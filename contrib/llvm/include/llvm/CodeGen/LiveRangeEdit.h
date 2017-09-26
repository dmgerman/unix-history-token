begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LiveRangeEdit.h - Basic tools for split and spill --------*- C++ -*-===//
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
file|"llvm/ADT/None.h"
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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
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
file|"llvm/CodeGen/SlotIndexes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineBlockFrequencyInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
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
name|virtual
operator|~
name|Delegate
argument_list|()
operator|=
expr|default
block|;
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
operator|=
name|false
block|;
comment|/// DeadRemats - The saved instructions which have already been dead after
comment|/// rematerialization but not deleted yet -- to be done in postOptimization.
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
block|,
literal|32
operator|>
operator|*
name|DeadRemats
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
name|using
name|ToShrinkSet
operator|=
name|SetVector
operator|<
name|LiveInterval
operator|*
block|,
name|SmallVector
operator|<
name|LiveInterval
operator|*
block|,
literal|8
operator|>
block|,
name|SmallPtrSet
operator|<
name|LiveInterval
operator|*
block|,
literal|8
operator|>>
block|;
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
argument_list|,
name|AliasAnalysis
operator|*
name|AA
argument_list|)
block|;
comment|/// MachineRegisterInfo callback to notify when new virtual
comment|/// registers are created.
name|void
name|MRI_NoteNewVirtualRegister
argument_list|(
argument|unsigned VReg
argument_list|)
name|override
block|;
comment|/// \brief Check if MachineOperand \p MO is a last use/kill either in the
comment|/// main live range of \p LI or in one of the matching subregister ranges.
name|bool
name|useIsKill
argument_list|(
argument|const LiveInterval&LI
argument_list|,
argument|const MachineOperand&MO
argument_list|)
specifier|const
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
comment|/// @param deadRemats The collection of all the instructions defining an
comment|///                   original reg and are dead after remat.
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
name|nullptr
argument_list|,
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
argument_list|,
literal|32
operator|>
operator|*
name|deadRemats
operator|=
name|nullptr
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
name|getSubtarget
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
name|DeadRemats
argument_list|(
argument|deadRemats
argument_list|)
block|{
name|MRI
operator|.
name|setDelegate
argument_list|(
name|this
argument_list|)
block|;   }
operator|~
name|LiveRangeEdit
argument_list|()
name|override
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
name|using
name|iterator
operator|=
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
block|;
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
comment|/// pop_back - It allows LiveRangeEdit users to drop new registers.
comment|/// The context is when an original def instruction of a register is
comment|/// dead after rematerialization, we still want to keep it for following
comment|/// rematerializations. We save the def instruction in DeadRemats,
comment|/// and replace the original dst register with a new dummy register so
comment|/// the live range of original dst register can be shrinked normally.
comment|/// We don't want to allocate phys register for the dummy register, so
comment|/// we want to drop it from the NewRegs set.
name|void
name|pop_back
argument_list|()
block|{
name|NewRegs
operator|.
name|pop_back
argument_list|()
block|; }
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
block|;
comment|/// createFrom - Create a new virtual register based on OldReg.
name|unsigned
name|createFrom
argument_list|(
argument|unsigned OldReg
argument_list|)
block|;
comment|/// create - Create a new register with the same class and original slot as
comment|/// parent.
name|LiveInterval
operator|&
name|createEmptyInterval
argument_list|()
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
argument_list|()
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
argument_list|(
name|AliasAnalysis
operator|*
argument_list|)
block|;
comment|/// checkRematerializable - Manually add VNI to the list of rematerializable
comment|/// values if DefMI may be rematerializable.
name|bool
name|checkRematerializable
argument_list|(
name|VNInfo
operator|*
name|VNI
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|AliasAnalysis
operator|*
argument_list|)
block|;
comment|/// Remat - Information needed to rematerialize at a specific location.
block|struct
name|Remat
block|{
name|VNInfo
operator|*
name|ParentVNI
block|;
comment|// parent_'s value at the remat location.
name|MachineInstr
operator|*
name|OrigMI
operator|=
name|nullptr
block|;
comment|// Instruction defining OrigVNI. It contains
comment|// the real expr for remat.
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
argument|ParentVNI
argument_list|)
block|{}
block|}
block|;
comment|/// canRematerializeAt - Determine if ParentVNI can be rematerialized at
comment|/// UseIdx. It is assumed that parent_.getVNINfoAt(UseIdx) == ParentVNI.
comment|/// When cheapAsAMove is set, only cheap remats are allowed.
name|bool
name|canRematerializeAt
argument_list|(
argument|Remat&RM
argument_list|,
argument|VNInfo *OrigVNI
argument_list|,
argument|SlotIndex UseIdx
argument_list|,
argument|bool cheapAsAMove
argument_list|)
block|;
comment|/// rematerializeAt - Rematerialize RM.ParentVNI into DestReg by inserting an
comment|/// instruction into MBB before MI. The new instruction is mapped, but
comment|/// liveness is not updated.
comment|/// Return the SlotIndex of the new instruction.
name|SlotIndex
name|rematerializeAt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|const Remat&RM
argument_list|,
argument|const TargetRegisterInfo&
argument_list|,
argument|bool Late = false
argument_list|)
block|;
comment|/// markRematerialized - explicitly mark a value as rematerialized after doing
comment|/// it manually.
name|void
name|markRematerialized
argument_list|(
argument|const VNInfo *ParentVNI
argument_list|)
block|{
name|Rematted
operator|.
name|insert
argument_list|(
name|ParentVNI
argument_list|)
block|;   }
comment|/// didRematerialize - Return true if ParentVNI was rematerialized anywhere.
name|bool
name|didRematerialize
argument_list|(
argument|const VNInfo *ParentVNI
argument_list|)
specifier|const
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
name|void
name|markDeadRemat
argument_list|(
argument|MachineInstr *inst
argument_list|)
block|{
comment|// DeadRemats is an optional field.
if|if
condition|(
name|DeadRemats
condition|)
name|DeadRemats
operator|->
name|insert
argument_list|(
name|inst
argument_list|)
expr_stmt|;
block|}
comment|/// eraseVirtReg - Notify the delegate that Reg is no longer in use, and try
comment|/// to erase it from LIS.
name|void
name|eraseVirtReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|;
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
argument_list|,
name|AliasAnalysis
operator|*
name|AA
operator|=
name|nullptr
argument_list|)
block|;
comment|/// calculateRegClassAndHint - Recompute register class and hint for each new
comment|/// register.
name|void
name|calculateRegClassAndHint
argument_list|(
name|MachineFunction
operator|&
argument_list|,
specifier|const
name|MachineLoopInfo
operator|&
argument_list|,
specifier|const
name|MachineBlockFrequencyInfo
operator|&
argument_list|)
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_LIVERANGEEDIT_H
end_comment

end_unit

