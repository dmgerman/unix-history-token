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
comment|// ScoreBoard to track function unit usage. ScoreBoard[0] is a
comment|// mask of the FUs in use in the cycle currently being
comment|// schedule. ScoreBoard[1] is a mask for the next cycle. The
comment|// ScoreBoard is used as a circular buffer with the current cycle
comment|// indicated by Head.
name|class
name|ScoreBoard
block|{
name|unsigned
operator|*
name|Data
block|;
comment|// The maximum number of cycles monitored by the Scoreboard. This
comment|// value is determined based on the target itineraries to ensure
comment|// that all hazards can be tracked.
name|size_t
name|Depth
block|;
comment|// Indices into the Scoreboard that represent the current cycle.
name|size_t
name|Head
block|;
name|public
operator|:
name|ScoreBoard
argument_list|()
operator|:
name|Data
argument_list|(
name|NULL
argument_list|)
block|,
name|Depth
argument_list|(
literal|0
argument_list|)
block|,
name|Head
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|ScoreBoard
argument_list|()
block|{
name|delete
index|[]
name|Data
block|;       }
name|size_t
name|getDepth
argument_list|()
specifier|const
block|{
return|return
name|Depth
return|;
block|}
name|unsigned
operator|&
name|operator
index|[]
operator|(
name|size_t
name|idx
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Depth
operator|&&
literal|"ScoreBoard was not initialized properly!"
argument_list|)
block|;
return|return
name|Data
index|[
operator|(
name|Head
operator|+
name|idx
operator|)
operator|%
name|Depth
index|]
return|;
block|}
name|void
name|reset
argument_list|(
argument|size_t d =
literal|1
argument_list|)
block|{
if|if
condition|(
name|Data
operator|==
name|NULL
condition|)
block|{
name|Depth
operator|=
name|d
expr_stmt|;
name|Data
operator|=
name|new
name|unsigned
index|[
name|Depth
index|]
expr_stmt|;
block|}
name|memset
argument_list|(
name|Data
argument_list|,
literal|0
argument_list|,
name|Depth
operator|*
sizeof|sizeof
argument_list|(
name|Data
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|Head
operator|=
literal|0
block|;       }
name|void
name|advance
argument_list|()
block|{
name|Head
operator|=
operator|(
name|Head
operator|+
literal|1
operator|)
operator|%
name|Depth
block|;       }
comment|// Print the scoreboard.
name|void
name|dump
argument_list|()
specifier|const
block|;     }
decl_stmt|;
comment|// Itinerary data for the target.
specifier|const
name|InstrItineraryData
modifier|&
name|ItinData
decl_stmt|;
name|ScoreBoard
name|ReservedScoreboard
decl_stmt|;
name|ScoreBoard
name|RequiredScoreboard
decl_stmt|;
name|public
label|:
name|ExactHazardRecognizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|&
name|ItinData
argument_list|)
expr_stmt|;
name|virtual
name|HazardType
name|getHazardType
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
name|virtual
name|void
name|Reset
parameter_list|()
function_decl|;
name|virtual
name|void
name|EmitInstruction
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
name|virtual
name|void
name|AdvanceCycle
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

