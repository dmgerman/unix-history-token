begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/TargetSchedule.h - Sched Machine Model ------*- C++ -*-===//
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
comment|// This file defines a wrapper around MCSchedModel that allows the interface to
end_comment

begin_comment
comment|// benefit from information currently only available in TargetInstrInfo.
end_comment

begin_comment
comment|// Ideally, the scheduling interface would be fully defined in the MC layer.
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
name|LLVM_CODEGEN_TARGETSCHEDULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_TARGETSCHEDULE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSchedule.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
comment|/// Provide an instruction scheduling machine model to CodeGen passes.
name|class
name|TargetSchedModel
block|{
comment|// For efficiency, hold a copy of the statically defined MCSchedModel for this
comment|// processor.
name|MCSchedModel
name|SchedModel
decl_stmt|;
name|InstrItineraryData
name|InstrItins
decl_stmt|;
specifier|const
name|TargetSubtargetInfo
modifier|*
name|STI
init|=
name|nullptr
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
init|=
name|nullptr
decl_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|16
operator|>
name|ResourceFactors
expr_stmt|;
name|unsigned
name|MicroOpFactor
decl_stmt|;
comment|// Multiply to normalize microops to resource units.
name|unsigned
name|ResourceLCM
decl_stmt|;
comment|// Resource units per cycle. Latency normalization factor.
name|unsigned
name|computeInstrLatency
argument_list|(
specifier|const
name|MCSchedClassDesc
operator|&
name|SCDesc
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|TargetSchedModel
argument_list|()
operator|:
name|SchedModel
argument_list|(
argument|MCSchedModel::GetDefaultSchedModel()
argument_list|)
block|{}
comment|/// \brief Initialize the machine model for instruction scheduling.
comment|///
comment|/// The machine model API keeps a copy of the top-level MCSchedModel table
comment|/// indices and may query TargetSubtargetInfo and TargetInstrInfo to resolve
comment|/// dynamic properties.
name|void
name|init
argument_list|(
specifier|const
name|MCSchedModel
operator|&
name|sm
argument_list|,
specifier|const
name|TargetSubtargetInfo
operator|*
name|sti
argument_list|,
specifier|const
name|TargetInstrInfo
operator|*
name|tii
argument_list|)
expr_stmt|;
comment|/// Return the MCSchedClassDesc for this instruction.
specifier|const
name|MCSchedClassDesc
modifier|*
name|resolveSchedClass
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief TargetSubtargetInfo getter.
specifier|const
name|TargetSubtargetInfo
operator|*
name|getSubtargetInfo
argument_list|()
specifier|const
block|{
return|return
name|STI
return|;
block|}
comment|/// \brief TargetInstrInfo getter.
specifier|const
name|TargetInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
name|TII
return|;
block|}
comment|/// \brief Return true if this machine model includes an instruction-level
comment|/// scheduling model.
comment|///
comment|/// This is more detailed than the course grain IssueWidth and default
comment|/// latency properties, but separate from the per-cycle itinerary data.
name|bool
name|hasInstrSchedModel
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|MCSchedModel
operator|*
name|getMCSchedModel
argument_list|()
specifier|const
block|{
return|return
operator|&
name|SchedModel
return|;
block|}
comment|/// \brief Return true if this machine model includes cycle-to-cycle itinerary
comment|/// data.
comment|///
comment|/// This models scheduling at each stage in the processor pipeline.
name|bool
name|hasInstrItineraries
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraries
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasInstrItineraries
argument_list|()
condition|)
return|return
operator|&
name|InstrItins
return|;
return|return
name|nullptr
return|;
block|}
comment|/// \brief Return true if this machine model includes an instruction-level
comment|/// scheduling model or cycle-to-cycle itinerary data.
name|bool
name|hasInstrSchedModelOrItineraries
argument_list|()
specifier|const
block|{
return|return
name|hasInstrSchedModel
argument_list|()
operator|||
name|hasInstrItineraries
argument_list|()
return|;
block|}
comment|/// \brief Identify the processor corresponding to the current subtarget.
name|unsigned
name|getProcessorID
argument_list|()
specifier|const
block|{
return|return
name|SchedModel
operator|.
name|getProcessorID
argument_list|()
return|;
block|}
comment|/// \brief Maximum number of micro-ops that may be scheduled per cycle.
name|unsigned
name|getIssueWidth
argument_list|()
specifier|const
block|{
return|return
name|SchedModel
operator|.
name|IssueWidth
return|;
block|}
comment|/// \brief Return true if new group must begin.
name|bool
name|mustBeginGroup
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if current group must end.
name|bool
name|mustEndGroup
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the number of issue slots required for this MI.
name|unsigned
name|getNumMicroOps
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the number of kinds of resources for this target.
name|unsigned
name|getNumProcResourceKinds
argument_list|()
specifier|const
block|{
return|return
name|SchedModel
operator|.
name|getNumProcResourceKinds
argument_list|()
return|;
block|}
comment|/// \brief Get a processor resource by ID for convenience.
specifier|const
name|MCProcResourceDesc
modifier|*
name|getProcResource
argument_list|(
name|unsigned
name|PIdx
argument_list|)
decl|const
block|{
return|return
name|SchedModel
operator|.
name|getProcResource
argument_list|(
name|PIdx
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|NDEBUG
specifier|const
name|char
modifier|*
name|getResourceName
argument_list|(
name|unsigned
name|PIdx
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|PIdx
condition|)
return|return
literal|"MOps"
return|;
return|return
name|SchedModel
operator|.
name|getProcResource
argument_list|(
name|PIdx
argument_list|)
operator|->
name|Name
return|;
block|}
endif|#
directive|endif
name|using
name|ProcResIter
init|=
specifier|const
name|MCWriteProcResEntry
operator|*
decl_stmt|;
comment|// \brief Get an iterator into the processor resources consumed by this
comment|// scheduling class.
name|ProcResIter
name|getWriteProcResBegin
argument_list|(
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
argument_list|)
decl|const
block|{
comment|// The subtarget holds a single resource table for all processors.
return|return
name|STI
operator|->
name|getWriteProcResBegin
argument_list|(
name|SC
argument_list|)
return|;
block|}
name|ProcResIter
name|getWriteProcResEnd
argument_list|(
specifier|const
name|MCSchedClassDesc
operator|*
name|SC
argument_list|)
decl|const
block|{
return|return
name|STI
operator|->
name|getWriteProcResEnd
argument_list|(
name|SC
argument_list|)
return|;
block|}
comment|/// \brief Multiply the number of units consumed for a resource by this factor
comment|/// to normalize it relative to other resources.
name|unsigned
name|getResourceFactor
argument_list|(
name|unsigned
name|ResIdx
argument_list|)
decl|const
block|{
return|return
name|ResourceFactors
index|[
name|ResIdx
index|]
return|;
block|}
comment|/// \brief Multiply number of micro-ops by this factor to normalize it
comment|/// relative to other resources.
name|unsigned
name|getMicroOpFactor
argument_list|()
specifier|const
block|{
return|return
name|MicroOpFactor
return|;
block|}
comment|/// \brief Multiply cycle count by this factor to normalize it relative to
comment|/// other resources. This is the number of resource units per cycle.
name|unsigned
name|getLatencyFactor
argument_list|()
specifier|const
block|{
return|return
name|ResourceLCM
return|;
block|}
comment|/// \brief Number of micro-ops that may be buffered for OOO execution.
name|unsigned
name|getMicroOpBufferSize
argument_list|()
specifier|const
block|{
return|return
name|SchedModel
operator|.
name|MicroOpBufferSize
return|;
block|}
comment|/// \brief Number of resource units that may be buffered for OOO execution.
comment|/// \return The buffer size in resource units or -1 for unlimited.
name|int
name|getResourceBufferSize
argument_list|(
name|unsigned
name|PIdx
argument_list|)
decl|const
block|{
return|return
name|SchedModel
operator|.
name|getProcResource
argument_list|(
name|PIdx
argument_list|)
operator|->
name|BufferSize
return|;
block|}
comment|/// \brief Compute operand latency based on the available machine model.
comment|///
comment|/// Compute and return the latency of the given data dependent def and use
comment|/// when the operand indices are already known. UseMI may be NULL for an
comment|/// unknown user.
name|unsigned
name|computeOperandLatency
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|unsigned
name|DefOperIdx
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|UseMI
argument_list|,
name|unsigned
name|UseOperIdx
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Compute the instruction latency based on the available machine
comment|/// model.
comment|///
comment|/// Compute and return the expected latency of this instruction independent of
comment|/// a particular use. computeOperandLatency is the preferred API, but this is
comment|/// occasionally useful to help estimate instruction cost.
comment|///
comment|/// If UseDefaultDefLatency is false and no new machine sched model is
comment|/// present this method falls back to TII->getInstrLatency with an empty
comment|/// instruction itinerary (this is so we preserve the previous behavior of the
comment|/// if converter after moving it to TargetSchedModel).
name|unsigned
name|computeInstrLatency
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|bool
name|UseDefaultDefLatency
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|computeInstrLatency
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Output dependency latency of a pair of defs of the same register.
comment|///
comment|/// This is typically one cycle.
name|unsigned
name|computeOutputLatency
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|unsigned
name|DefIdx
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|DepMI
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Compute the reciprocal throughput of the given instruction.
name|Optional
operator|<
name|double
operator|>
name|computeInstrRThroughput
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
expr_stmt|;
name|Optional
operator|<
name|double
operator|>
name|computeInstrRThroughput
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_TARGETSCHEDULE_H
end_comment

end_unit

