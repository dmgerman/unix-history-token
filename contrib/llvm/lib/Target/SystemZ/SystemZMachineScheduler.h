begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- SystemZMachineScheduler.h - SystemZ Scheduler Interface ----*- C++ -*-==//
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
comment|// -------------------------- Post RA scheduling ---------------------------- //
end_comment

begin_comment
comment|// SystemZPostRASchedStrategy is a scheduling strategy which is plugged into
end_comment

begin_comment
comment|// the MachineScheduler. It has a sorted Available set of SUs and a pickNode()
end_comment

begin_comment
comment|// implementation that looks to optimize decoder grouping and balance the
end_comment

begin_comment
comment|// usage of processor resources.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"SystemZHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineScheduler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZMACHINESCHEDULER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZMACHINESCHEDULER_H
end_define

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A MachineSchedStrategy implementation for SystemZ post RA scheduling.
name|class
name|SystemZPostRASchedStrategy
range|:
name|public
name|MachineSchedStrategy
block|{
name|ScheduleDAGMI
operator|*
name|DAG
block|;
comment|/// A candidate during instruction evaluation.
block|struct
name|Candidate
block|{
name|SUnit
operator|*
name|SU
operator|=
name|nullptr
block|;
comment|/// The decoding cost.
name|int
name|GroupingCost
operator|=
literal|0
block|;
comment|/// The processor resources cost.
name|int
name|ResourcesCost
operator|=
literal|0
block|;
name|Candidate
argument_list|()
operator|=
expr|default
block|;
name|Candidate
argument_list|(
name|SUnit
operator|*
name|SU_
argument_list|,
name|SystemZHazardRecognizer
operator|&
name|HazardRec
argument_list|)
block|;
comment|// Compare two candidates.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Candidate
operator|&
name|other
operator|)
block|;
comment|// Check if this node is free of cost ("as good as any").
name|bool
name|noCost
argument_list|()
specifier|const
block|{
return|return
operator|(
name|GroupingCost
operator|<=
literal|0
operator|&&
operator|!
name|ResourcesCost
operator|)
return|;
block|}
expr|}
block|;
comment|// A sorter for the Available set that makes sure that SUs are considered
comment|// in the best order.
block|struct
name|SUSorter
block|{
name|bool
name|operator
argument_list|()
operator|(
name|SUnit
operator|*
name|lhs
expr|,
name|SUnit
operator|*
name|rhs
operator|)
specifier|const
block|{
if|if
condition|(
name|lhs
operator|->
name|isScheduleHigh
operator|&&
operator|!
name|rhs
operator|->
name|isScheduleHigh
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|!
name|lhs
operator|->
name|isScheduleHigh
operator|&&
name|rhs
operator|->
name|isScheduleHigh
condition|)
return|return
name|false
return|;
if|if
condition|(
name|lhs
operator|->
name|getHeight
argument_list|()
operator|>
name|rhs
operator|->
name|getHeight
argument_list|()
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|lhs
operator|->
name|getHeight
argument_list|()
operator|<
name|rhs
operator|->
name|getHeight
argument_list|()
condition|)
return|return
name|false
return|;
return|return
operator|(
name|lhs
operator|->
name|NodeNum
operator|<
name|rhs
operator|->
name|NodeNum
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A set of SUs with a sorter and dump method.
end_comment

begin_decl_stmt
name|struct
name|SUSet
range|:
name|std
operator|::
name|set
operator|<
name|SUnit
operator|*
decl_stmt|,
name|SUSorter
decl|>
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|dump
argument_list|(
name|SystemZHazardRecognizer
operator|&
name|HazardRec
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// The set of available SUs to schedule next.
end_comment

begin_decl_stmt
name|SUSet
name|Available
decl_stmt|;
end_decl_stmt

begin_comment
comment|// HazardRecognizer that tracks the scheduler state for the current
end_comment

begin_comment
comment|// region.
end_comment

begin_decl_stmt
name|SystemZHazardRecognizer
name|HazardRec
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|SystemZPostRASchedStrategy
argument_list|(
specifier|const
name|MachineSchedContext
operator|*
name|C
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// PostRA scheduling does not track pressure.
end_comment

begin_expr_stmt
name|bool
name|shouldTrackPressure
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Initialize the strategy after building the DAG for a new region.
end_comment

begin_decl_stmt
name|void
name|initialize
argument_list|(
name|ScheduleDAGMI
operator|*
name|dag
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Pick the next node to schedule, or return NULL.
end_comment

begin_decl_stmt
name|SUnit
modifier|*
name|pickNode
argument_list|(
name|bool
operator|&
name|IsTopNode
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ScheduleDAGMI has scheduled an instruction - tell HazardRec
end_comment

begin_comment
comment|/// about it.
end_comment

begin_decl_stmt
name|void
name|schedNode
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|,
name|bool
name|IsTopNode
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// SU has had all predecessor dependencies resolved. Put it into
end_comment

begin_comment
comment|/// Available.
end_comment

begin_decl_stmt
name|void
name|releaseTopNode
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Currently only scheduling top-down, so this method is empty.
end_comment

begin_function
name|void
name|releaseBottomNode
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function|override
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZMACHINESCHEDULER_H
end_comment

end_unit

