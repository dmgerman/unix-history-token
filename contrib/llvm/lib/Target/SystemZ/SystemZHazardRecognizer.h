begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- SystemZHazardRecognizer.h - SystemZ Hazard Recognizer -----*- C++ -*-===//
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
comment|// This file declares a hazard recognizer for the SystemZ scheduler.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class is used by the SystemZ scheduling strategy to maintain
end_comment

begin_comment
comment|// the state during scheduling, and provide cost functions for
end_comment

begin_comment
comment|// scheduling candidates. This includes:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// * Decoder grouping. A decoder group can maximally hold 3 uops, and
end_comment

begin_comment
comment|// instructions that always begin a new group should be scheduled when
end_comment

begin_comment
comment|// the current decoder group is empty.
end_comment

begin_comment
comment|// * Processor resources usage. It is beneficial to balance the use of
end_comment

begin_comment
comment|// resources.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ===---------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZHAZARDRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZHAZARDRECOGNIZER_H
end_define

begin_include
include|#
directive|include
file|"SystemZSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineScheduler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SystemZHazardRecognizer maintains the state during scheduling.
name|class
name|SystemZHazardRecognizer
range|:
name|public
name|ScheduleHazardRecognizer
block|{
name|ScheduleDAGMI
operator|*
name|DAG
block|;
specifier|const
name|TargetSchedModel
operator|*
name|SchedModel
block|;
comment|/// Keep track of the number of decoder slots used in the current
comment|/// decoder group.
name|unsigned
name|CurrGroupSize
block|;
comment|/// The tracking of resources here are quite similar to the common
comment|/// code use of a critical resource. However, z13 differs in the way
comment|/// that it has two processor sides which may be interesting to
comment|/// model in the future (a work in progress).
comment|/// Counters for the number of uops scheduled per processor
comment|/// resource.
name|SmallVector
operator|<
name|int
block|,
literal|0
operator|>
name|ProcResourceCounters
block|;
comment|/// This is the resource with the greatest queue, which the
comment|/// scheduler tries to avoid.
name|unsigned
name|CriticalResourceIdx
block|;
comment|/// Return the number of decoder slots MI requires.
specifier|inline
name|unsigned
name|getNumDecoderSlots
argument_list|(
argument|SUnit *SU
argument_list|)
specifier|const
block|;
comment|/// Return true if MI fits into current decoder group.
name|bool
name|fitsIntoCurrentGroup
argument_list|(
argument|SUnit *SU
argument_list|)
specifier|const
block|;
comment|/// Two decoder groups per cycle are formed (for z13), meaning 2x3
comment|/// instructions. This function returns a number between 0 and 5,
comment|/// representing the current decoder slot of the current cycle.
name|unsigned
name|getCurrCycleIdx
argument_list|()
block|;
comment|/// LastFPdOpCycleIdx stores the numbeer returned by getCurrCycleIdx()
comment|/// when a stalling operation is scheduled (which uses the FPd resource).
name|unsigned
name|LastFPdOpCycleIdx
block|;
comment|/// A counter of decoder groups scheduled.
name|unsigned
name|GrpCount
block|;
name|unsigned
name|getCurrGroupSize
argument_list|()
block|{
return|return
name|CurrGroupSize
return|;
block|}
block|;
comment|/// Start next decoder group.
name|void
name|nextGroup
argument_list|(
argument|bool DbgOutput = true
argument_list|)
block|;
comment|/// Clear all counters for processor resources.
name|void
name|clearProcResCounters
argument_list|()
block|;
comment|/// With the goal of alternating processor sides for stalling (FPd)
comment|/// ops, return true if it seems good to schedule an FPd op next.
name|bool
name|isFPdOpPreferred_distance
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|public
operator|:
name|SystemZHazardRecognizer
argument_list|(
specifier|const
name|MachineSchedContext
operator|*
name|C
argument_list|)
block|;
name|void
name|setDAG
argument_list|(
argument|ScheduleDAGMI *dag
argument_list|)
block|{
name|DAG
operator|=
name|dag
block|;
name|SchedModel
operator|=
name|dag
operator|->
name|getSchedModel
argument_list|()
block|;   }
name|HazardType
name|getHazardType
argument_list|(
argument|SUnit *m
argument_list|,
argument|int Stalls =
literal|0
argument_list|)
name|override
block|;
name|void
name|Reset
argument_list|()
name|override
block|;
name|void
name|EmitInstruction
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|;
comment|// Cost functions used by SystemZPostRASchedStrategy while
comment|// evaluating candidates.
comment|/// Return the cost of decoder grouping for SU. If SU must start a
comment|/// new decoder group, this is negative if this fits the schedule or
comment|/// positive if it would mean ending a group prematurely. For normal
comment|/// instructions this returns 0.
name|int
name|groupingCost
argument_list|(
argument|SUnit *SU
argument_list|)
specifier|const
block|;
comment|/// Return the cost of SU in regards to processor resources usage.
comment|/// A positive value means it would be better to wait with SU, while
comment|/// a negative value means it would be good to schedule SU next.
name|int
name|resourcesCost
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Debug dumping.
name|std
operator|::
name|string
name|CurGroupDbg
block|;
comment|// current group as text
name|void
name|dumpSU
argument_list|(
argument|SUnit *SU
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|dumpCurrGroup
argument_list|(
argument|std::string Msg =
literal|""
argument_list|)
specifier|const
block|;
name|void
name|dumpProcResourceCounters
argument_list|()
specifier|const
block|;
endif|#
directive|endif
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZHAZARDRECOGNIZER_H */
end_comment

end_unit

