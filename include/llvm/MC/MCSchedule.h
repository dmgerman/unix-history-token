begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCSchedule.h - Scheduling -----------------------*- C++ -*-===//
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
comment|// This file defines the classes used to describe a subtarget's machine model
end_comment

begin_comment
comment|// for scheduling and other instruction cost heuristics.
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
name|LLVM_MC_MCSCHEDMODEL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSCHEDMODEL_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|InstrItinerary
struct_decl|;
comment|/// Machine model for scheduling, bundling, and heuristics.
comment|///
comment|/// The machine model directly provides basic information about the
comment|/// microarchitecture to the scheduler in the form of properties. It also
comment|/// optionally refers to scheduler resources tables and itinerary
comment|/// tables. Scheduler resources tables model the latency and cost for each
comment|/// instruction type. Itinerary tables are an independant mechanism that
comment|/// provides a detailed reservation table describing each cycle of instruction
comment|/// execution. Subtargets may define any or all of the above categories of data
comment|/// depending on the type of CPU and selected scheduler.
name|class
name|MCSchedModel
block|{
name|public
label|:
specifier|static
name|MCSchedModel
name|DefaultSchedModel
decl_stmt|;
comment|// For unknown processors.
comment|// IssueWidth is the maximum number of instructions that may be scheduled in
comment|// the same per-cycle group.
name|unsigned
name|IssueWidth
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|DefaultIssueWidth
init|=
literal|1
decl_stmt|;
comment|// MinLatency is the minimum latency between a register write
comment|// followed by a data dependent read. This determines which
comment|// instructions may be scheduled in the same per-cycle group. This
comment|// is distinct from *expected* latency, which determines the likely
comment|// critical path but does not guarantee a pipeline
comment|// hazard. MinLatency can always be overridden by the number of
comment|// InstrStage cycles.
comment|//
comment|// (-1) Standard in-order processor.
comment|//      Use InstrItinerary OperandCycles as MinLatency.
comment|//      If no OperandCycles exist, then use the cycle of the last InstrStage.
comment|//
comment|//  (0) Out-of-order processor, or in-order with bundled dependencies.
comment|//      RAW dependencies may be dispatched in the same cycle.
comment|//      Optional InstrItinerary OperandCycles provides expected latency.
comment|//
comment|// (>0) In-order processor with variable latencies.
comment|//      Use the greater of this value or the cycle of the last InstrStage.
comment|//      Optional InstrItinerary OperandCycles provides expected latency.
comment|//      TODO: can't yet specify both min and expected latency per operand.
name|int
name|MinLatency
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|DefaultMinLatency
init|=
operator|-
literal|1
decl_stmt|;
comment|// LoadLatency is the expected latency of load instructions.
comment|//
comment|// If MinLatency>= 0, this may be overriden for individual load opcodes by
comment|// InstrItinerary OperandCycles.
name|unsigned
name|LoadLatency
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|DefaultLoadLatency
init|=
literal|4
decl_stmt|;
comment|// HighLatency is the expected latency of "very high latency" operations.
comment|// See TargetInstrInfo::isHighLatencyDef().
comment|// By default, this is set to an arbitrarily high number of cycles
comment|// likely to have some impact on scheduling heuristics.
comment|// If MinLatency>= 0, this may be overriden by InstrItinData OperandCycles.
name|unsigned
name|HighLatency
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|DefaultHighLatency
init|=
literal|10
decl_stmt|;
comment|// MispredictPenalty is the typical number of extra cycles the processor
comment|// takes to recover from a branch misprediction.
name|unsigned
name|MispredictPenalty
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|DefaultMispredictPenalty
init|=
literal|10
decl_stmt|;
name|private
label|:
comment|// TODO: Add a reference to proc resource types and sched resource tables.
comment|// Instruction itinerary tables used by InstrItineraryData.
name|friend
name|class
name|InstrItineraryData
decl_stmt|;
specifier|const
name|InstrItinerary
modifier|*
name|InstrItineraries
decl_stmt|;
name|public
label|:
comment|// Default's must be specified as static const literals so that tablegenerated
comment|// target code can use it in static initializers. The defaults need to be
comment|// initialized in this default ctor because some clients directly instantiate
comment|// MCSchedModel instead of using a generated itinerary.
name|MCSchedModel
argument_list|()
operator|:
name|IssueWidth
argument_list|(
name|DefaultIssueWidth
argument_list|)
operator|,
name|MinLatency
argument_list|(
name|DefaultMinLatency
argument_list|)
operator|,
name|LoadLatency
argument_list|(
name|DefaultLoadLatency
argument_list|)
operator|,
name|HighLatency
argument_list|(
name|DefaultHighLatency
argument_list|)
operator|,
name|MispredictPenalty
argument_list|(
name|DefaultMispredictPenalty
argument_list|)
operator|,
name|InstrItineraries
argument_list|(
literal|0
argument_list|)
block|{}
comment|// Table-gen driven ctor.
name|MCSchedModel
argument_list|(
argument|unsigned iw
argument_list|,
argument|int ml
argument_list|,
argument|unsigned ll
argument_list|,
argument|unsigned hl
argument_list|,
argument|unsigned mp
argument_list|,
argument|const InstrItinerary *ii
argument_list|)
operator|:
name|IssueWidth
argument_list|(
name|iw
argument_list|)
operator|,
name|MinLatency
argument_list|(
name|ml
argument_list|)
operator|,
name|LoadLatency
argument_list|(
name|ll
argument_list|)
operator|,
name|HighLatency
argument_list|(
name|hl
argument_list|)
operator|,
name|MispredictPenalty
argument_list|(
name|mp
argument_list|)
operator|,
name|InstrItineraries
argument_list|(
argument|ii
argument_list|)
block|{}
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

