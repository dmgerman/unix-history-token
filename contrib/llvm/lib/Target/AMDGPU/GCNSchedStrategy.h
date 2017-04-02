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
name|SIRegisterInfo
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
argument|int SGPRPressure
argument_list|,
argument|int VGPRPressure
argument_list|,
argument|int SGPRExcessLimit
argument_list|,
argument|int VGPRExcessLimit
argument_list|,
argument|int SGPRCriticalLimit
argument_list|,
argument|int VGPRCriticalLimit
argument_list|)
block|;
name|void
name|tryCandidate
argument_list|(
argument|SchedCandidate&Cand
argument_list|,
argument|SchedCandidate&TryCand
argument_list|,
argument|SchedBoundary *Zone
argument_list|,
argument|const SIRegisterInfo *SRI
argument_list|,
argument|unsigned SGPRPressure
argument_list|,
argument|unsigned VGPRPressure
argument_list|)
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

