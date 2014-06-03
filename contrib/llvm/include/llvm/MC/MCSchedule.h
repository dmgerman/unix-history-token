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
name|LLVM_MC_MCSCHEDULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSCHEDULE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
struct_decl|struct
name|InstrItinerary
struct_decl|;
comment|/// Define a kind of processor resource that will be modeled by the scheduler.
struct|struct
name|MCProcResourceDesc
block|{
ifndef|#
directive|ifndef
name|NDEBUG
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|NumUnits
decl_stmt|;
comment|// Number of resource of this kind
name|unsigned
name|SuperIdx
decl_stmt|;
comment|// Index of the resources kind that contains this kind.
comment|// Number of resources that may be buffered.
comment|//
comment|// Buffered resources (BufferSize> 0 || BufferSize == -1) may be consumed at
comment|// some indeterminate cycle after dispatch (e.g. for instructions that may
comment|// issue out-of-order). Unbuffered resources (BufferSize == 0) always consume
comment|// their resource some fixed number of cycles after dispatch (e.g. for
comment|// instruction interlocking that may stall the pipeline).
name|int
name|BufferSize
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MCProcResourceDesc
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|NumUnits
operator|==
name|Other
operator|.
name|NumUnits
operator|&&
name|SuperIdx
operator|==
name|Other
operator|.
name|SuperIdx
operator|&&
name|BufferSize
operator|==
name|Other
operator|.
name|BufferSize
return|;
block|}
block|}
struct|;
comment|/// Identify one of the processor resource kinds consumed by a particular
comment|/// scheduling class for the specified number of cycles.
struct|struct
name|MCWriteProcResEntry
block|{
name|unsigned
name|ProcResourceIdx
decl_stmt|;
name|unsigned
name|Cycles
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MCWriteProcResEntry
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|ProcResourceIdx
operator|==
name|Other
operator|.
name|ProcResourceIdx
operator|&&
name|Cycles
operator|==
name|Other
operator|.
name|Cycles
return|;
block|}
block|}
struct|;
comment|/// Specify the latency in cpu cycles for a particular scheduling class and def
comment|/// index. -1 indicates an invalid latency. Heuristics would typically consider
comment|/// an instruction with invalid latency to have infinite latency.  Also identify
comment|/// the WriteResources of this def. When the operand expands to a sequence of
comment|/// writes, this ID is the last write in the sequence.
struct|struct
name|MCWriteLatencyEntry
block|{
name|int
name|Cycles
decl_stmt|;
name|unsigned
name|WriteResourceID
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MCWriteLatencyEntry
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Cycles
operator|==
name|Other
operator|.
name|Cycles
operator|&&
name|WriteResourceID
operator|==
name|Other
operator|.
name|WriteResourceID
return|;
block|}
block|}
struct|;
comment|/// Specify the number of cycles allowed after instruction issue before a
comment|/// particular use operand reads its registers. This effectively reduces the
comment|/// write's latency. Here we allow negative cycles for corner cases where
comment|/// latency increases. This rule only applies when the entry's WriteResource
comment|/// matches the write's WriteResource.
comment|///
comment|/// MCReadAdvanceEntries are sorted first by operand index (UseIdx), then by
comment|/// WriteResourceIdx.
struct|struct
name|MCReadAdvanceEntry
block|{
name|unsigned
name|UseIdx
decl_stmt|;
name|unsigned
name|WriteResourceID
decl_stmt|;
name|int
name|Cycles
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MCReadAdvanceEntry
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|UseIdx
operator|==
name|Other
operator|.
name|UseIdx
operator|&&
name|WriteResourceID
operator|==
name|Other
operator|.
name|WriteResourceID
operator|&&
name|Cycles
operator|==
name|Other
operator|.
name|Cycles
return|;
block|}
block|}
struct|;
comment|/// Summarize the scheduling resources required for an instruction of a
comment|/// particular scheduling class.
comment|///
comment|/// Defined as an aggregate struct for creating tables with initializer lists.
struct|struct
name|MCSchedClassDesc
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|InvalidNumMicroOps
init|=
name|UINT16_MAX
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|short
name|VariantNumMicroOps
init|=
name|UINT16_MAX
operator|-
literal|1
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|short
name|NumMicroOps
decl_stmt|;
name|bool
name|BeginGroup
decl_stmt|;
name|bool
name|EndGroup
decl_stmt|;
name|unsigned
name|WriteProcResIdx
decl_stmt|;
comment|// First index into WriteProcResTable.
name|unsigned
name|NumWriteProcResEntries
decl_stmt|;
name|unsigned
name|WriteLatencyIdx
decl_stmt|;
comment|// First index into WriteLatencyTable.
name|unsigned
name|NumWriteLatencyEntries
decl_stmt|;
name|unsigned
name|ReadAdvanceIdx
decl_stmt|;
comment|// First index into ReadAdvanceTable.
name|unsigned
name|NumReadAdvanceEntries
decl_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|NumMicroOps
operator|!=
name|InvalidNumMicroOps
return|;
block|}
name|bool
name|isVariant
argument_list|()
specifier|const
block|{
return|return
name|NumMicroOps
operator|==
name|VariantNumMicroOps
return|;
block|}
block|}
struct|;
comment|/// Machine model for scheduling, bundling, and heuristics.
comment|///
comment|/// The machine model directly provides basic information about the
comment|/// microarchitecture to the scheduler in the form of properties. It also
comment|/// optionally refers to scheduler resource tables and itinerary
comment|/// tables. Scheduler resource tables model the latency and cost for each
comment|/// instruction type. Itinerary tables are an independent mechanism that
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
comment|// MicroOpBufferSize is the number of micro-ops that the processor may buffer
comment|// for out-of-order execution.
comment|//
comment|// "0" means operations that are not ready in this cycle are not considered
comment|// for scheduling (they go in the pending queue). Latency is paramount. This
comment|// may be more efficient if many instructions are pending in a schedule.
comment|//
comment|// "1" means all instructions are considered for scheduling regardless of
comment|// whether they are ready in this cycle. Latency still causes issue stalls,
comment|// but we balance those stalls against other heuristics.
comment|//
comment|// "> 1" means the processor is out-of-order. This is a machine independent
comment|// estimate of highly machine specific characteristics such are the register
comment|// renaming pool and reorder buffer.
name|unsigned
name|MicroOpBufferSize
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|DefaultMicroOpBufferSize
init|=
literal|0
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
name|bool
name|CompleteModel
decl_stmt|;
name|private
label|:
name|unsigned
name|ProcID
decl_stmt|;
specifier|const
name|MCProcResourceDesc
modifier|*
name|ProcResourceTable
decl_stmt|;
specifier|const
name|MCSchedClassDesc
modifier|*
name|SchedClassTable
decl_stmt|;
name|unsigned
name|NumProcResourceKinds
decl_stmt|;
name|unsigned
name|NumSchedClasses
decl_stmt|;
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
name|MicroOpBufferSize
argument_list|(
name|DefaultMicroOpBufferSize
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
name|CompleteModel
argument_list|(
name|true
argument_list|)
operator|,
name|ProcID
argument_list|(
literal|0
argument_list|)
operator|,
name|ProcResourceTable
argument_list|(
literal|0
argument_list|)
operator|,
name|SchedClassTable
argument_list|(
literal|0
argument_list|)
operator|,
name|NumProcResourceKinds
argument_list|(
literal|0
argument_list|)
operator|,
name|NumSchedClasses
argument_list|(
literal|0
argument_list|)
operator|,
name|InstrItineraries
argument_list|(
literal|0
argument_list|)
block|{
operator|(
name|void
operator|)
name|NumProcResourceKinds
block|;
operator|(
name|void
operator|)
name|NumSchedClasses
block|;   }
comment|// Table-gen driven ctor.
name|MCSchedModel
argument_list|(
argument|unsigned iw
argument_list|,
argument|int mbs
argument_list|,
argument|unsigned ll
argument_list|,
argument|unsigned hl
argument_list|,
argument|unsigned mp
argument_list|,
argument|bool cm
argument_list|,
argument|unsigned pi
argument_list|,
argument|const MCProcResourceDesc *pr
argument_list|,
argument|const MCSchedClassDesc *sc
argument_list|,
argument|unsigned npr
argument_list|,
argument|unsigned nsc
argument_list|,
argument|const InstrItinerary *ii
argument_list|)
operator|:
name|IssueWidth
argument_list|(
name|iw
argument_list|)
operator|,
name|MicroOpBufferSize
argument_list|(
name|mbs
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
name|CompleteModel
argument_list|(
name|cm
argument_list|)
operator|,
name|ProcID
argument_list|(
name|pi
argument_list|)
operator|,
name|ProcResourceTable
argument_list|(
name|pr
argument_list|)
operator|,
name|SchedClassTable
argument_list|(
name|sc
argument_list|)
operator|,
name|NumProcResourceKinds
argument_list|(
name|npr
argument_list|)
operator|,
name|NumSchedClasses
argument_list|(
name|nsc
argument_list|)
operator|,
name|InstrItineraries
argument_list|(
argument|ii
argument_list|)
block|{}
name|unsigned
name|getProcessorID
argument_list|()
specifier|const
block|{
return|return
name|ProcID
return|;
block|}
comment|/// Does this machine model include instruction-level scheduling.
name|bool
name|hasInstrSchedModel
argument_list|()
specifier|const
block|{
return|return
name|SchedClassTable
return|;
block|}
comment|/// Return true if this machine model data for all instructions with a
comment|/// scheduling class (itinerary class or SchedRW list).
name|bool
name|isComplete
argument_list|()
specifier|const
block|{
return|return
name|CompleteModel
return|;
block|}
name|unsigned
name|getNumProcResourceKinds
argument_list|()
specifier|const
block|{
return|return
name|NumProcResourceKinds
return|;
block|}
specifier|const
name|MCProcResourceDesc
modifier|*
name|getProcResource
argument_list|(
name|unsigned
name|ProcResourceIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|hasInstrSchedModel
argument_list|()
operator|&&
literal|"No scheduling machine model"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|ProcResourceIdx
operator|<
name|NumProcResourceKinds
operator|&&
literal|"bad proc resource idx"
argument_list|)
expr_stmt|;
return|return
operator|&
name|ProcResourceTable
index|[
name|ProcResourceIdx
index|]
return|;
block|}
specifier|const
name|MCSchedClassDesc
modifier|*
name|getSchedClassDesc
argument_list|(
name|unsigned
name|SchedClassIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|hasInstrSchedModel
argument_list|()
operator|&&
literal|"No scheduling machine model"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|SchedClassIdx
operator|<
name|NumSchedClasses
operator|&&
literal|"bad scheduling class idx"
argument_list|)
expr_stmt|;
return|return
operator|&
name|SchedClassTable
index|[
name|SchedClassIdx
index|]
return|;
block|}
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

