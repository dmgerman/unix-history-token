begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/TargetSchedule.h - Sched Machine Model -----*- C++ -*-===//
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
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetSubtargetInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|MachineInstr
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
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
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
name|public
label|:
name|TargetSchedModel
argument_list|()
operator|:
name|STI
argument_list|(
literal|0
argument_list|)
operator|,
name|TII
argument_list|(
literal|0
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
literal|0
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
comment|/// \brief Number of cycles the OOO processor is expected to hide.
name|unsigned
name|getILPWindow
argument_list|()
specifier|const
block|{
return|return
name|SchedModel
operator|.
name|ILPWindow
return|;
block|}
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
literal|0
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
typedef|typedef
specifier|const
name|MCWriteProcResEntry
modifier|*
name|ProcResIter
typedef|;
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
comment|/// \brief Compute operand latency based on the available machine model.
comment|///
comment|/// Computes and return the latency of the given data dependent def and use
comment|/// when the operand indices are already known. UseMI may be NULL for an
comment|/// unknown user.
comment|///
comment|/// FindMin may be set to get the minimum vs. expected latency. Minimum
comment|/// latency is used for scheduling groups, while expected latency is for
comment|/// instruction cost and critical path.
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
argument_list|,
name|bool
name|FindMin
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Compute the instruction latency based on the available machine
comment|/// model.
comment|///
comment|/// Compute and return the expected latency of this instruction independent of
comment|/// a particular use. computeOperandLatency is the prefered API, but this is
comment|/// occasionally useful to help estimate instruction cost.
name|unsigned
name|computeInstrLatency
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
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
name|private
label|:
comment|/// getDefLatency is a helper for computeOperandLatency. Return the
comment|/// instruction's latency if operand lookup is not required.
comment|/// Otherwise return -1.
name|int
name|getDefLatency
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|bool
name|FindMin
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

