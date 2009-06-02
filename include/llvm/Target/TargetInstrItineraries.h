begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetInstrItineraries.h - Scheduling -------*- C++ -*-===//
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
comment|// This file describes the structures used for instruction itineraries and
end_comment

begin_comment
comment|// states.  This is used by schedulers to determine instruction states and
end_comment

begin_comment
comment|// latencies.
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
name|LLVM_TARGET_TARGETINSTRITINERARIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETINSTRITINERARIES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|/// Instruction stage - These values represent a step in the execution of an
comment|/// instruction.  The latency represents the number of discrete time slots used
comment|/// need to complete the stage.  Units represent the choice of functional units
comment|/// that can be used to complete the stage.  Eg. IntUnit1, IntUnit2.
comment|///
struct|struct
name|InstrStage
block|{
name|unsigned
name|Cycles
decl_stmt|;
comment|///< Length of stage in machine cycles
name|unsigned
name|Units
decl_stmt|;
comment|///< Choice of functional units
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|/// Instruction itinerary - An itinerary represents a sequential series of steps
comment|/// required to complete an instruction.  Itineraries are represented as
comment|/// sequences of instruction stages.
comment|///
struct|struct
name|InstrItinerary
block|{
name|unsigned
name|First
decl_stmt|;
comment|///< Index of first stage in itinerary
name|unsigned
name|Last
decl_stmt|;
comment|///< Index of last + 1 stage in itinerary
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|/// Instruction itinerary Data - Itinerary data supplied by a subtarget to be
comment|/// used by a target.
comment|///
struct|struct
name|InstrItineraryData
block|{
specifier|const
name|InstrStage
modifier|*
name|Stages
decl_stmt|;
comment|///< Array of stages selected
specifier|const
name|InstrItinerary
modifier|*
name|Itineratries
decl_stmt|;
comment|///< Array of itineraries selected
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
name|Itineratries
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
name|Itineratries
argument_list|(
argument|I
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
name|Itineratries
operator|==
literal|0
return|;
block|}
comment|/// begin - Return the first stage of the itinerary.
comment|///
specifier|const
name|InstrStage
modifier|*
name|begin
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
name|unsigned
name|StageIdx
init|=
name|Itineratries
index|[
name|ItinClassIndx
index|]
operator|.
name|First
decl_stmt|;
return|return
name|Stages
operator|+
name|StageIdx
return|;
block|}
comment|/// end - Return the last+1 stage of the itinerary.
comment|///
specifier|const
name|InstrStage
modifier|*
name|end
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
name|unsigned
name|StageIdx
init|=
name|Itineratries
index|[
name|ItinClassIndx
index|]
operator|.
name|Last
decl_stmt|;
return|return
name|Stages
operator|+
name|StageIdx
return|;
block|}
comment|/// getLatency - Return the scheduling latency of the given class.  A
comment|/// simple latency value for an instruction is an over-simplification
comment|/// for some architectures, but it's a reasonable first approximation.
comment|///
name|unsigned
name|getLatency
argument_list|(
name|unsigned
name|ItinClassIndx
argument_list|)
decl|const
block|{
comment|// If the target doesn't provide latency information, use a simple
comment|// non-zero default value for all instructions.
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
return|return
literal|1
return|;
comment|// Just sum the cycle count for each stage.
name|unsigned
name|Latency
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
name|begin
argument_list|(
name|ItinClassIndx
argument_list|)
init|,
modifier|*
name|E
init|=
name|end
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
name|Latency
operator|+=
name|IS
operator|->
name|Cycles
expr_stmt|;
return|return
name|Latency
return|;
block|}
block|}
struct|;
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

