begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterPressure.h - Dynamic Register Pressure -*- C++ -*-------===//
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
comment|// This file defines the RegisterPressure class which can be used to track
end_comment

begin_comment
comment|// MachineInstr level register pressure.
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
name|LLVM_CODEGEN_REGISTERPRESSURE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGISTERPRESSURE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SparseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SlotIndexes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|LiveInterval
decl_stmt|;
name|class
name|RegisterClassInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
comment|/// Base class for register pressure results.
struct|struct
name|RegisterPressure
block|{
comment|/// Map of max reg pressure indexed by pressure set ID, not class ID.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|MaxSetPressure
expr_stmt|;
comment|/// List of live in virtual registers or physical register units.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|8
operator|>
name|LiveInRegs
expr_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|8
operator|>
name|LiveOutRegs
expr_stmt|;
comment|/// Increase register pressure for each pressure set impacted by this register
comment|/// class. Normally called by RegPressureTracker, but may be called manually
comment|/// to account for live through (global liveness).
comment|///
comment|/// \param Reg is either a virtual register number or register unit number.
name|void
name|increase
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|,
specifier|const
name|MachineRegisterInfo
modifier|*
name|MRI
parameter_list|)
function_decl|;
comment|/// Decrease register pressure for each pressure set impacted by this register
comment|/// class. This is only useful to account for spilling or rematerialization.
comment|///
comment|/// \param Reg is either a virtual register number or register unit number.
name|void
name|decrease
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|,
specifier|const
name|MachineRegisterInfo
modifier|*
name|MRI
parameter_list|)
function_decl|;
name|void
name|dump
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
comment|/// RegisterPressure computed within a region of instructions delimited by
comment|/// TopIdx and BottomIdx.  During pressure computation, the maximum pressure per
comment|/// register pressure set is increased. Once pressure within a region is fully
comment|/// computed, the live-in and live-out sets are recorded.
comment|///
comment|/// This is preferable to RegionPressure when LiveIntervals are available,
comment|/// because delimiting regions by SlotIndex is more robust and convenient than
comment|/// holding block iterators. The block contents can change without invalidating
comment|/// the pressure result.
name|struct
name|IntervalPressure
range|:
name|RegisterPressure
block|{
comment|/// Record the boundary of the region being tracked.
name|SlotIndex
name|TopIdx
block|;
name|SlotIndex
name|BottomIdx
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|openTop
argument_list|(
argument|SlotIndex NextTop
argument_list|)
block|;
name|void
name|openBottom
argument_list|(
argument|SlotIndex PrevBottom
argument_list|)
block|; }
decl_stmt|;
comment|/// RegisterPressure computed within a region of instructions delimited by
comment|/// TopPos and BottomPos. This is a less precise version of IntervalPressure for
comment|/// use when LiveIntervals are unavailable.
name|struct
name|RegionPressure
range|:
name|RegisterPressure
block|{
comment|/// Record the boundary of the region being tracked.
name|MachineBasicBlock
operator|::
name|const_iterator
name|TopPos
block|;
name|MachineBasicBlock
operator|::
name|const_iterator
name|BottomPos
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|openTop
argument_list|(
argument|MachineBasicBlock::const_iterator PrevTop
argument_list|)
block|;
name|void
name|openBottom
argument_list|(
argument|MachineBasicBlock::const_iterator PrevBottom
argument_list|)
block|; }
decl_stmt|;
comment|/// An element of pressure difference that identifies the pressure set and
comment|/// amount of increase or decrease in units of pressure.
struct|struct
name|PressureElement
block|{
name|unsigned
name|PSetID
decl_stmt|;
name|int
name|UnitIncrease
decl_stmt|;
name|PressureElement
argument_list|()
operator|:
name|PSetID
argument_list|(
operator|~
literal|0U
argument_list|)
operator|,
name|UnitIncrease
argument_list|(
literal|0
argument_list|)
block|{}
name|PressureElement
argument_list|(
argument|unsigned id
argument_list|,
argument|int inc
argument_list|)
operator|:
name|PSetID
argument_list|(
name|id
argument_list|)
operator|,
name|UnitIncrease
argument_list|(
argument|inc
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|PSetID
operator|!=
operator|~
literal|0U
return|;
block|}
block|}
struct|;
comment|/// Store the effects of a change in pressure on things that MI scheduler cares
comment|/// about.
comment|///
comment|/// Excess records the value of the largest difference in register units beyond
comment|/// the target's pressure limits across the affected pressure sets, where
comment|/// largest is defined as the absolute value of the difference. Negative
comment|/// ExcessUnits indicates a reduction in pressure that had already exceeded the
comment|/// target's limits.
comment|///
comment|/// CriticalMax records the largest increase in the tracker's max pressure that
comment|/// exceeds the critical limit for some pressure set determined by the client.
comment|///
comment|/// CurrentMax records the largest increase in the tracker's max pressure that
comment|/// exceeds the current limit for some pressure set determined by the client.
struct|struct
name|RegPressureDelta
block|{
name|PressureElement
name|Excess
decl_stmt|;
name|PressureElement
name|CriticalMax
decl_stmt|;
name|PressureElement
name|CurrentMax
decl_stmt|;
name|RegPressureDelta
argument_list|()
block|{}
block|}
struct|;
comment|/// \brief A set of live virtual registers and physical register units.
comment|///
comment|/// Virtual and physical register numbers require separate sparse sets, but most
comment|/// of the RegisterPressureTracker handles them uniformly.
struct|struct
name|LiveRegSet
block|{
name|SparseSet
operator|<
name|unsigned
operator|>
name|PhysRegs
expr_stmt|;
name|SparseSet
operator|<
name|unsigned
operator|,
name|VirtReg2IndexFunctor
operator|>
name|VirtRegs
expr_stmt|;
name|bool
name|contains
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|VirtRegs
operator|.
name|count
argument_list|(
name|Reg
argument_list|)
return|;
return|return
name|PhysRegs
operator|.
name|count
argument_list|(
name|Reg
argument_list|)
return|;
block|}
name|bool
name|insert
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|VirtRegs
operator|.
name|insert
argument_list|(
name|Reg
argument_list|)
operator|.
name|second
return|;
return|return
name|PhysRegs
operator|.
name|insert
argument_list|(
name|Reg
argument_list|)
operator|.
name|second
return|;
block|}
name|bool
name|erase
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|VirtRegs
operator|.
name|erase
argument_list|(
name|Reg
argument_list|)
return|;
return|return
name|PhysRegs
operator|.
name|erase
argument_list|(
name|Reg
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// Track the current register pressure at some position in the instruction
comment|/// stream, and remember the high water mark within the region traversed. This
comment|/// does not automatically consider live-through ranges. The client may
comment|/// independently adjust for global liveness.
comment|///
comment|/// Each RegPressureTracker only works within a MachineBasicBlock. Pressure can
comment|/// be tracked across a larger region by storing a RegisterPressure result at
comment|/// each block boundary and explicitly adjusting pressure to account for block
comment|/// live-in and live-out register sets.
comment|///
comment|/// RegPressureTracker holds a reference to a RegisterPressure result that it
comment|/// computes incrementally. During downward tracking, P.BottomIdx or P.BottomPos
comment|/// is invalid until it reaches the end of the block or closeRegion() is
comment|/// explicitly called. Similarly, P.TopIdx is invalid during upward
comment|/// tracking. Changing direction has the side effect of closing region, and
comment|/// traversing past TopIdx or BottomIdx reopens it.
name|class
name|RegPressureTracker
block|{
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
specifier|const
name|RegisterClassInfo
modifier|*
name|RCI
decl_stmt|;
specifier|const
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
specifier|const
name|LiveIntervals
modifier|*
name|LIS
decl_stmt|;
comment|/// We currently only allow pressure tracking within a block.
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
comment|/// Track the max pressure within the region traversed so far.
name|RegisterPressure
modifier|&
name|P
decl_stmt|;
comment|/// Run in two modes dependending on whether constructed with IntervalPressure
comment|/// or RegisterPressure. If requireIntervals is false, LIS are ignored.
name|bool
name|RequireIntervals
decl_stmt|;
comment|/// Register pressure corresponds to liveness before this instruction
comment|/// iterator. It may point to the end of the block or a DebugValue rather than
comment|/// an instruction.
name|MachineBasicBlock
operator|::
name|const_iterator
name|CurrPos
expr_stmt|;
comment|/// Pressure map indexed by pressure set ID, not class ID.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|CurrSetPressure
expr_stmt|;
comment|/// Set of live registers.
name|LiveRegSet
name|LiveRegs
decl_stmt|;
name|public
label|:
name|RegPressureTracker
argument_list|(
name|IntervalPressure
operator|&
name|rp
argument_list|)
operator|:
name|MF
argument_list|(
literal|0
argument_list|)
operator|,
name|TRI
argument_list|(
literal|0
argument_list|)
operator|,
name|RCI
argument_list|(
literal|0
argument_list|)
operator|,
name|LIS
argument_list|(
literal|0
argument_list|)
operator|,
name|MBB
argument_list|(
literal|0
argument_list|)
operator|,
name|P
argument_list|(
name|rp
argument_list|)
operator|,
name|RequireIntervals
argument_list|(
argument|true
argument_list|)
block|{}
name|RegPressureTracker
argument_list|(
name|RegionPressure
operator|&
name|rp
argument_list|)
operator|:
name|MF
argument_list|(
literal|0
argument_list|)
operator|,
name|TRI
argument_list|(
literal|0
argument_list|)
operator|,
name|RCI
argument_list|(
literal|0
argument_list|)
operator|,
name|LIS
argument_list|(
literal|0
argument_list|)
operator|,
name|MBB
argument_list|(
literal|0
argument_list|)
operator|,
name|P
argument_list|(
name|rp
argument_list|)
operator|,
name|RequireIntervals
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|init
argument_list|(
argument|const MachineFunction *mf
argument_list|,
argument|const RegisterClassInfo *rci
argument_list|,
argument|const LiveIntervals *lis
argument_list|,
argument|const MachineBasicBlock *mbb
argument_list|,
argument|MachineBasicBlock::const_iterator pos
argument_list|)
expr_stmt|;
comment|/// Force liveness of virtual registers or physical register
comment|/// units. Particularly useful to initialize the livein/out state of the
comment|/// tracker before the first call to advance/recede.
name|void
name|addLiveRegs
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Regs
argument_list|)
decl_stmt|;
comment|/// Get the MI position corresponding to this register pressure.
name|MachineBasicBlock
operator|::
name|const_iterator
name|getPos
argument_list|()
specifier|const
block|{
return|return
name|CurrPos
return|;
block|}
comment|// Reset the MI position corresponding to the register pressure. This allows
comment|// schedulers to move instructions above the RegPressureTracker's
comment|// CurrPos. Since the pressure is computed before CurrPos, the iterator
comment|// position changes while pressure does not.
name|void
name|setPos
argument_list|(
name|MachineBasicBlock
operator|::
name|const_iterator
name|Pos
argument_list|)
block|{
name|CurrPos
operator|=
name|Pos
expr_stmt|;
block|}
comment|/// \brief Get the SlotIndex for the first nondebug instruction including or
comment|/// after the current position.
name|SlotIndex
name|getCurrSlot
argument_list|()
specifier|const
expr_stmt|;
comment|/// Recede across the previous instruction.
name|bool
name|recede
parameter_list|()
function_decl|;
comment|/// Advance across the current instruction.
name|bool
name|advance
parameter_list|()
function_decl|;
comment|/// Finalize the region boundaries and recored live ins and live outs.
name|void
name|closeRegion
parameter_list|()
function_decl|;
comment|/// Get the resulting register pressure over the traversed region.
comment|/// This result is complete if either advance() or recede() has returned true,
comment|/// or if closeRegion() was explicitly invoked.
name|RegisterPressure
modifier|&
name|getPressure
parameter_list|()
block|{
return|return
name|P
return|;
block|}
specifier|const
name|RegisterPressure
operator|&
name|getPressure
argument_list|()
specifier|const
block|{
return|return
name|P
return|;
block|}
comment|/// Get the register set pressure at the current position, which may be less
comment|/// than the pressure across the traversed region.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|getRegSetPressureAtPos
argument_list|()
block|{
return|return
name|CurrSetPressure
return|;
block|}
name|void
name|discoverLiveOut
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
name|void
name|discoverLiveIn
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
name|bool
name|isTopClosed
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isBottomClosed
argument_list|()
specifier|const
expr_stmt|;
name|void
name|closeTop
parameter_list|()
function_decl|;
name|void
name|closeBottom
parameter_list|()
function_decl|;
comment|/// Consider the pressure increase caused by traversing this instruction
comment|/// bottom-up. Find the pressure set with the most change beyond its pressure
comment|/// limit based on the tracker's current pressure, and record the number of
comment|/// excess register units of that pressure set introduced by this instruction.
name|void
name|getMaxUpwardPressureDelta
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|RegPressureDelta
operator|&
name|Delta
argument_list|,
name|ArrayRef
operator|<
name|PressureElement
operator|>
name|CriticalPSets
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|MaxPressureLimit
argument_list|)
decl_stmt|;
comment|/// Consider the pressure increase caused by traversing this instruction
comment|/// top-down. Find the pressure set with the most change beyond its pressure
comment|/// limit based on the tracker's current pressure, and record the number of
comment|/// excess register units of that pressure set introduced by this instruction.
name|void
name|getMaxDownwardPressureDelta
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|RegPressureDelta
operator|&
name|Delta
argument_list|,
name|ArrayRef
operator|<
name|PressureElement
operator|>
name|CriticalPSets
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|MaxPressureLimit
argument_list|)
decl_stmt|;
comment|/// Find the pressure set with the most change beyond its pressure limit after
comment|/// traversing this instruction either upward or downward depending on the
comment|/// closed end of the current region.
name|void
name|getMaxPressureDelta
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|RegPressureDelta
operator|&
name|Delta
argument_list|,
name|ArrayRef
operator|<
name|PressureElement
operator|>
name|CriticalPSets
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|MaxPressureLimit
argument_list|)
block|{
if|if
condition|(
name|isTopClosed
argument_list|()
condition|)
return|return
name|getMaxDownwardPressureDelta
argument_list|(
name|MI
argument_list|,
name|Delta
argument_list|,
name|CriticalPSets
argument_list|,
name|MaxPressureLimit
argument_list|)
return|;
name|assert
argument_list|(
name|isBottomClosed
argument_list|()
operator|&&
literal|"Uninitialized pressure tracker"
argument_list|)
expr_stmt|;
return|return
name|getMaxUpwardPressureDelta
argument_list|(
name|MI
argument_list|,
name|Delta
argument_list|,
name|CriticalPSets
argument_list|,
name|MaxPressureLimit
argument_list|)
return|;
block|}
comment|/// Get the pressure of each PSet after traversing this instruction bottom-up.
name|void
name|getUpwardPressure
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|PressureResult
argument_list|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|MaxPressureResult
argument_list|)
decl_stmt|;
comment|/// Get the pressure of each PSet after traversing this instruction top-down.
name|void
name|getDownwardPressure
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|PressureResult
argument_list|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|MaxPressureResult
argument_list|)
decl_stmt|;
name|void
name|getPressureAfterInst
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|PressureResult
argument_list|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|MaxPressureResult
argument_list|)
block|{
if|if
condition|(
name|isTopClosed
argument_list|()
condition|)
return|return
name|getUpwardPressure
argument_list|(
name|MI
argument_list|,
name|PressureResult
argument_list|,
name|MaxPressureResult
argument_list|)
return|;
name|assert
argument_list|(
name|isBottomClosed
argument_list|()
operator|&&
literal|"Uninitialized pressure tracker"
argument_list|)
expr_stmt|;
return|return
name|getDownwardPressure
argument_list|(
name|MI
argument_list|,
name|PressureResult
argument_list|,
name|MaxPressureResult
argument_list|)
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
specifier|const
name|LiveInterval
modifier|*
name|getInterval
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
name|void
name|increaseRegPressure
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Regs
argument_list|)
decl_stmt|;
name|void
name|decreaseRegPressure
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Regs
argument_list|)
decl_stmt|;
name|void
name|bumpUpwardPressure
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
name|void
name|bumpDownwardPressure
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

