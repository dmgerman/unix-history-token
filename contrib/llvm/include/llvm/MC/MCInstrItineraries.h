begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCInstrItineraries.h - Scheduling ---------------*- C++ -*-===//
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
comment|// This file describes the structures used for instruction
end_comment

begin_comment
comment|// itineraries, stages, and operand reads/writes.  This is used by
end_comment

begin_comment
comment|// schedulers to determine instruction stages and latencies.
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
name|LLVM_MC_MCINSTRITINERARIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCINSTRITINERARIES_H
end_define

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|/// Instruction stage - These values represent a non-pipelined step in
comment|/// the execution of an instruction.  Cycles represents the number of
comment|/// discrete time slots needed to complete the stage.  Units represent
comment|/// the choice of functional units that can be used to complete the
comment|/// stage.  Eg. IntUnit1, IntUnit2. NextCycles indicates how many
comment|/// cycles should elapse from the start of this stage to the start of
comment|/// the next stage in the itinerary. A value of -1 indicates that the
comment|/// next stage should start immediately after the current one.
comment|/// For example:
comment|///
comment|///   { 1, x, -1 }
comment|///      indicates that the stage occupies FU x for 1 cycle and that
comment|///      the next stage starts immediately after this one.
comment|///
comment|///   { 2, x|y, 1 }
comment|///      indicates that the stage occupies either FU x or FU y for 2
comment|///      consecuative cycles and that the next stage starts one cycle
comment|///      after this stage starts. That is, the stage requirements
comment|///      overlap in time.
comment|///
comment|///   { 1, x, 0 }
comment|///      indicates that the stage occupies FU x for 1 cycle and that
comment|///      the next stage starts in this same cycle. This can be used to
comment|///      indicate that the instruction requires multiple stages at the
comment|///      same time.
comment|///
comment|/// FU reservation can be of two different kinds:
comment|///  - FUs which instruction actually requires
comment|///  - FUs which instruction just reserves. Reserved unit is not available for
comment|///    execution of other instruction. However, several instructions can reserve
comment|///    the same unit several times.
comment|/// Such two types of units reservation is used to model instruction domain
comment|/// change stalls, FUs using the same resource (e.g. same register file), etc.
struct|struct
name|InstrStage
block|{
enum|enum
name|ReservationKinds
block|{
name|Required
init|=
literal|0
block|,
name|Reserved
init|=
literal|1
block|}
enum|;
name|unsigned
name|Cycles_
decl_stmt|;
comment|///< Length of stage in machine cycles
name|unsigned
name|Units_
decl_stmt|;
comment|///< Choice of functional units
name|int
name|NextCycles_
decl_stmt|;
comment|///< Number of machine cycles to next stage
name|ReservationKinds
name|Kind_
decl_stmt|;
comment|///< Kind of the FU reservation
comment|/// getCycles - returns the number of cycles the stage is occupied
name|unsigned
name|getCycles
argument_list|()
specifier|const
block|{
return|return
name|Cycles_
return|;
block|}
comment|/// getUnits - returns the choice of FUs
name|unsigned
name|getUnits
argument_list|()
specifier|const
block|{
return|return
name|Units_
return|;
block|}
name|ReservationKinds
name|getReservationKind
argument_list|()
specifier|const
block|{
return|return
name|Kind_
return|;
block|}
comment|/// getNextCycles - returns the number of cycles from the start of
comment|/// this stage to the start of the next stage in the itinerary
name|unsigned
name|getNextCycles
argument_list|()
specifier|const
block|{
return|return
operator|(
name|NextCycles_
operator|>=
literal|0
operator|)
operator|?
operator|(
name|unsigned
operator|)
name|NextCycles_
operator|:
name|Cycles_
return|;
block|}
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|/// Instruction itinerary - An itinerary represents the scheduling
comment|/// information for an instruction. This includes a set of stages
comment|/// occupies by the instruction, and the pipeline cycle in which
comment|/// operands are read and written.
comment|///
struct|struct
name|InstrItinerary
block|{
name|unsigned
name|NumMicroOps
decl_stmt|;
comment|///< # of micro-ops, 0 means it's variable
name|unsigned
name|FirstStage
decl_stmt|;
comment|///< Index of first stage in itinerary
name|unsigned
name|LastStage
decl_stmt|;
comment|///< Index of last + 1 stage in itinerary
name|unsigned
name|FirstOperandCycle
decl_stmt|;
comment|///< Index of first operand rd/wr
name|unsigned
name|LastOperandCycle
decl_stmt|;
comment|///< Index of last + 1 operand rd/wr
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|/// Instruction itinerary Data - Itinerary data supplied by a subtarget to be
comment|/// used by a target.
comment|///
name|class
name|InstrItineraryData
block|{
name|public
label|:
specifier|const
name|InstrStage
modifier|*
name|Stages
decl_stmt|;
comment|///< Array of stages selected
specifier|const
name|unsigned
modifier|*
name|OperandCycles
decl_stmt|;
comment|///< Array of operand cycles selected
specifier|const
name|unsigned
modifier|*
name|Forwardings
decl_stmt|;
comment|///< Array of pipeline forwarding pathes
specifier|const
name|InstrItinerary
modifier|*
name|Itineraries
decl_stmt|;
comment|///< Array of itineraries selected
name|unsigned
name|IssueWidth
decl_stmt|;
comment|///< Max issue per cycle. 0=Unknown.
comment|/// Ctors.
comment|///
name|InstrItineraryData
argument_list|()
operator|:
name|Stages
argument_list|(
literal|0
argument_list|)
operator|,
name|OperandCycles
argument_list|(
literal|0
argument_list|)
operator|,
name|Forwardings
argument_list|(
literal|0
argument_list|)
operator|,
name|Itineraries
argument_list|(
literal|0
argument_list|)
operator|,
name|IssueWidth
argument_list|(
literal|0
argument_list|)
block|{}
name|InstrItineraryData
argument_list|(
specifier|const
name|InstrStage
operator|*
name|S
argument_list|,
specifier|const
name|unsigned
operator|*
name|OS
argument_list|,
specifier|const
name|unsigned
operator|*
name|F
argument_list|,
specifier|const
name|InstrItinerary
operator|*
name|I
argument_list|)
operator|:
name|Stages
argument_list|(
name|S
argument_list|)
operator|,
name|OperandCycles
argument_list|(
name|OS
argument_list|)
operator|,
name|Forwardings
argument_list|(
name|F
argument_list|)
operator|,
name|Itineraries
argument_list|(
name|I
argument_list|)
operator|,
name|IssueWidth
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// isEmpty - Returns true if there are no itineraries.
comment|///
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|Itineraries
operator|==
literal|0
return|;
block|}
comment|/// isEndMarker - Returns true if the index is for the end marker
comment|/// itinerary.
comment|///
name|bool
name|isEndMarker
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
return|return
operator|(
operator|(
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|FirstStage
operator|==
operator|~
literal|0U
operator|)
operator|&&
operator|(
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|LastStage
operator|==
operator|~
literal|0U
operator|)
operator|)
return|;
block|}
comment|/// beginStage - Return the first stage of the itinerary.
comment|///
specifier|const
name|InstrStage
modifier|*
name|beginStage
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
name|unsigned
name|StageIdx
init|=
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|FirstStage
decl_stmt|;
return|return
name|Stages
operator|+
name|StageIdx
return|;
block|}
comment|/// endStage - Return the last+1 stage of the itinerary.
comment|///
specifier|const
name|InstrStage
modifier|*
name|endStage
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
name|unsigned
name|StageIdx
init|=
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|LastStage
decl_stmt|;
return|return
name|Stages
operator|+
name|StageIdx
return|;
block|}
comment|/// getStageLatency - Return the total stage latency of the given
comment|/// class.  The latency is the maximum completion time for any stage
comment|/// in the itinerary.
comment|///
name|unsigned
name|getStageLatency
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
comment|// If the target doesn't provide itinerary information, use a simple
comment|// non-zero default value for all instructions.  Some target's provide a
comment|// dummy (Generic) itinerary which should be handled as if it's itinerary is
comment|// empty. We identify this by looking for a reference to stage zero (invalid
comment|// stage). This is different from beginStage == endState != 0, which could
comment|// be used for zero-latency pseudo ops.
if|if
condition|(
name|isEmpty
argument_list|()
operator|||
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|FirstStage
operator|==
literal|0
condition|)
return|return
literal|1
return|;
comment|// Calculate the maximum completion time for any stage.
name|unsigned
name|Latency
init|=
literal|0
decl_stmt|,
name|StartCycle
init|=
literal|0
decl_stmt|;
for|for
control|(
specifier|const
name|InstrStage
modifier|*
name|IS
init|=
name|beginStage
argument_list|(
name|ItinClassIndx
argument_list|)
init|,
modifier|*
name|E
init|=
name|endStage
argument_list|(
name|ItinClassIndx
argument_list|)
init|;
name|IS
operator|!=
name|E
condition|;
operator|++
name|IS
control|)
block|{
name|Latency
operator|=
name|std
operator|::
name|max
argument_list|(
name|Latency
argument_list|,
name|StartCycle
operator|+
name|IS
operator|->
name|getCycles
argument_list|()
argument_list|)
expr_stmt|;
name|StartCycle
operator|+=
name|IS
operator|->
name|getNextCycles
argument_list|()
expr_stmt|;
block|}
return|return
name|Latency
return|;
block|}
comment|/// getOperandCycle - Return the cycle for the given class and
comment|/// operand. Return -1 if no cycle is specified for the operand.
comment|///
name|int
name|getOperandCycle
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|,
name|unsigned
name|OperandIdx
argument_list|)
decl|const
block|{
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
name|unsigned
name|FirstIdx
init|=
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|FirstOperandCycle
decl_stmt|;
name|unsigned
name|LastIdx
init|=
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|LastOperandCycle
decl_stmt|;
if|if
condition|(
operator|(
name|FirstIdx
operator|+
name|OperandIdx
operator|)
operator|>=
name|LastIdx
condition|)
return|return
operator|-
literal|1
return|;
return|return
operator|(
name|int
operator|)
name|OperandCycles
index|[
name|FirstIdx
operator|+
name|OperandIdx
index|]
return|;
block|}
comment|/// hasPipelineForwarding - Return true if there is a pipeline forwarding
comment|/// between instructions of itinerary classes DefClass and UseClasses so that
comment|/// value produced by an instruction of itinerary class DefClass, operand
comment|/// index DefIdx can be bypassed when it's read by an instruction of
comment|/// itinerary class UseClass, operand index UseIdx.
name|bool
name|hasPipelineForwarding
argument_list|(
name|unsigned
name|DefClass
argument_list|,
name|unsigned
name|DefIdx
argument_list|,
name|unsigned
name|UseClass
argument_list|,
name|unsigned
name|UseIdx
argument_list|)
decl|const
block|{
name|unsigned
name|FirstDefIdx
init|=
name|Itineraries
index|[
name|DefClass
index|]
operator|.
name|FirstOperandCycle
decl_stmt|;
name|unsigned
name|LastDefIdx
init|=
name|Itineraries
index|[
name|DefClass
index|]
operator|.
name|LastOperandCycle
decl_stmt|;
if|if
condition|(
operator|(
name|FirstDefIdx
operator|+
name|DefIdx
operator|)
operator|>=
name|LastDefIdx
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Forwardings
index|[
name|FirstDefIdx
operator|+
name|DefIdx
index|]
operator|==
literal|0
condition|)
return|return
name|false
return|;
name|unsigned
name|FirstUseIdx
init|=
name|Itineraries
index|[
name|UseClass
index|]
operator|.
name|FirstOperandCycle
decl_stmt|;
name|unsigned
name|LastUseIdx
init|=
name|Itineraries
index|[
name|UseClass
index|]
operator|.
name|LastOperandCycle
decl_stmt|;
if|if
condition|(
operator|(
name|FirstUseIdx
operator|+
name|UseIdx
operator|)
operator|>=
name|LastUseIdx
condition|)
return|return
name|false
return|;
return|return
name|Forwardings
index|[
name|FirstDefIdx
operator|+
name|DefIdx
index|]
operator|==
name|Forwardings
index|[
name|FirstUseIdx
operator|+
name|UseIdx
index|]
return|;
block|}
comment|/// getOperandLatency - Compute and return the use operand latency of a given
comment|/// itinerary class and operand index if the value is produced by an
comment|/// instruction of the specified itinerary class and def operand index.
name|int
name|getOperandLatency
argument_list|(
name|unsigned
name|DefClass
argument_list|,
name|unsigned
name|DefIdx
argument_list|,
name|unsigned
name|UseClass
argument_list|,
name|unsigned
name|UseIdx
argument_list|)
decl|const
block|{
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
name|int
name|DefCycle
init|=
name|getOperandCycle
argument_list|(
name|DefClass
argument_list|,
name|DefIdx
argument_list|)
decl_stmt|;
if|if
condition|(
name|DefCycle
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
name|int
name|UseCycle
init|=
name|getOperandCycle
argument_list|(
name|UseClass
argument_list|,
name|UseIdx
argument_list|)
decl_stmt|;
if|if
condition|(
name|UseCycle
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
name|UseCycle
operator|=
name|DefCycle
operator|-
name|UseCycle
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|UseCycle
operator|>
literal|0
operator|&&
name|hasPipelineForwarding
argument_list|(
name|DefClass
argument_list|,
name|DefIdx
argument_list|,
name|UseClass
argument_list|,
name|UseIdx
argument_list|)
condition|)
comment|// FIXME: This assumes one cycle benefit for every pipeline forwarding.
operator|--
name|UseCycle
expr_stmt|;
return|return
name|UseCycle
return|;
block|}
comment|/// isMicroCoded - Return true if the instructions in the given class decode
comment|/// to more than one micro-ops.
name|bool
name|isMicroCoded
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|Itineraries
index|[
name|ItinClassIndx
index|]
operator|.
name|NumMicroOps
operator|!=
literal|1
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

