begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/ExactHazardRecognizer.h - Scheduling Support -*- C++ -*-=//
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
comment|// This file implements the ExactHazardRecognizer class, which
end_comment

begin_comment
comment|// implements hazard-avoidance heuristics for scheduling, based on the
end_comment

begin_comment
comment|// scheduling itineraries specified for the target.
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
name|LLVM_CODEGEN_EXACTHAZARDRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_EXACTHAZARDRECOGNIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrItineraries.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ExactHazardRecognizer
range|:
name|public
name|ScheduleHazardRecognizer
block|{
comment|// Itinerary data for the target.
specifier|const
name|InstrItineraryData
operator|&
name|ItinData
block|;
comment|// Scoreboard to track function unit usage. Scoreboard[0] is a
comment|// mask of the FUs in use in the cycle currently being
comment|// schedule. Scoreboard[1] is a mask for the next cycle. The
comment|// Scoreboard is used as a circular buffer with the current cycle
comment|// indicated by ScoreboardHead.
name|unsigned
operator|*
name|Scoreboard
block|;
comment|// The maximum number of cycles monitored by the Scoreboard. This
comment|// value is determined based on the target itineraries to ensure
comment|// that all hazards can be tracked.
name|unsigned
name|ScoreboardDepth
block|;
comment|// Indices into the Scoreboard that represent the current cycle.
name|unsigned
name|ScoreboardHead
block|;
comment|// Return the scoreboard index to use for 'offset' cycles in the
comment|// future. 'offset' of 0 returns ScoreboardHead.
name|unsigned
name|getFutureIndex
argument_list|(
argument|unsigned offset
argument_list|)
block|;
comment|// Print the scoreboard.
name|void
name|dumpScoreboard
argument_list|()
block|;
name|public
operator|:
name|ExactHazardRecognizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|&
name|ItinData
argument_list|)
block|;
operator|~
name|ExactHazardRecognizer
argument_list|()
block|;
name|virtual
name|HazardType
name|getHazardType
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|virtual
name|void
name|Reset
argument_list|()
block|;
name|virtual
name|void
name|EmitInstruction
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|virtual
name|void
name|AdvanceCycle
argument_list|()
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

