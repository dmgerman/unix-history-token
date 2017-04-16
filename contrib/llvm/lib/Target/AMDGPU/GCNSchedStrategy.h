begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GCNSchedStrategy.h - GCN Scheduler Strategy -*- C++ -*-------------===//
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
comment|/// \file
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
name|LLVM_LIB_TARGET_AMDGPU_GCNSCHEDSTRATEGY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_GCNSCHEDSTRATEGY_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineScheduler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SIMachineFunctionInfo
decl_stmt|;
name|class
name|SIRegisterInfo
decl_stmt|;
name|class
name|SISubtarget
decl_stmt|;
comment|/// This is a minimal scheduler strategy.  The main difference between this
comment|/// and the GenericScheduler is that GCNSchedStrategy uses different
comment|/// heuristics to determine excess/critical pressure sets.  Its goal is to
comment|/// maximize kernel occupancy (i.e. maximum number of waves per simd).
name|class
name|GCNMaxOccupancySchedStrategy
range|:
name|public
name|GenericScheduler
block|{
name|friend
name|class
name|GCNScheduleDAGMILive
block|;
name|SUnit
operator|*
name|pickNodeBidirectional
argument_list|(
name|bool
operator|&
name|IsTopNode
argument_list|)
block|;
name|void
name|pickNodeFromQueue
argument_list|(
name|SchedBoundary
operator|&
name|Zone
argument_list|,
specifier|const
name|CandPolicy
operator|&
name|ZonePolicy
argument_list|,
specifier|const
name|RegPressureTracker
operator|&
name|RPTracker
argument_list|,
name|SchedCandidate
operator|&
name|Cand
argument_list|)
block|;
name|void
name|initCandidate
argument_list|(
argument|SchedCandidate&Cand
argument_list|,
argument|SUnit *SU
argument_list|,
argument|bool AtTop
argument_list|,
argument|const RegPressureTracker&RPTracker
argument_list|,
argument|const SIRegisterInfo *SRI
argument_list|,
argument|unsigned SGPRPressure
argument_list|,
argument|unsigned VGPRPressure
argument_list|)
block|;
name|unsigned
name|SGPRExcessLimit
block|;
name|unsigned
name|VGPRExcessLimit
block|;
name|unsigned
name|SGPRCriticalLimit
block|;
name|unsigned
name|VGPRCriticalLimit
block|;
name|unsigned
name|TargetOccupancy
block|;
name|MachineFunction
operator|*
name|MF
block|;
name|public
operator|:
name|GCNMaxOccupancySchedStrategy
argument_list|(
specifier|const
name|MachineSchedContext
operator|*
name|C
argument_list|)
block|;
name|SUnit
operator|*
name|pickNode
argument_list|(
argument|bool&IsTopNode
argument_list|)
name|override
block|;
name|void
name|initialize
argument_list|(
argument|ScheduleDAGMI *DAG
argument_list|)
name|override
block|;
name|void
name|setTargetOccupancy
argument_list|(
argument|unsigned Occ
argument_list|)
block|{
name|TargetOccupancy
operator|=
name|Occ
block|; }
block|}
decl_stmt|;
name|class
name|GCNScheduleDAGMILive
range|:
name|public
name|ScheduleDAGMILive
block|{
specifier|const
name|SISubtarget
operator|&
name|ST
block|;
specifier|const
name|SIMachineFunctionInfo
operator|&
name|MFI
block|;
comment|// Occupancy target at the begining of function scheduling cycle.
name|unsigned
name|StartingOccupancy
block|;
comment|// Minimal real occupancy recorder for the function.
name|unsigned
name|MinOccupancy
block|;
comment|// Scheduling stage number.
name|unsigned
name|Stage
block|;
comment|// Vecor of regions recorder for later rescheduling
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineBasicBlock
operator|::
name|iterator
block|,
name|MachineBasicBlock
operator|::
name|iterator
operator|>
block|,
literal|32
operator|>
name|Regions
block|;
comment|// Region live-ins.
name|DenseMap
operator|<
name|unsigned
block|,
name|LaneBitmask
operator|>
name|LiveIns
block|;
comment|// Number of live-ins to the current region, first SGPR then VGPR.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|LiveInPressure
block|;
comment|// Collect current region live-ins.
name|void
name|discoverLiveIns
argument_list|()
block|;
comment|// Return current region pressure. First value is SGPR number, second is VGPR.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|getRealRegPressure
argument_list|()
specifier|const
block|;
name|public
operator|:
name|GCNScheduleDAGMILive
argument_list|(
name|MachineSchedContext
operator|*
name|C
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|MachineSchedStrategy
operator|>
name|S
argument_list|)
block|;
name|void
name|schedule
argument_list|()
name|override
block|;
name|void
name|finalizeSchedule
argument_list|()
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GCNSCHEDSTRATEGY_H
end_comment

end_unit

