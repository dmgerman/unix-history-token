begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/ScoreboardHazardRecognizer.h - Schedule Support -*- C++ -*-=//
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
comment|// This file defines the ScoreboardHazardRecognizer class, which
end_comment

begin_comment
comment|// encapsulates hazard-avoidance heuristics for scheduling, based on the
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
name|LLVM_CODEGEN_SCOREBOARDHAZARDRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCOREBOARDHAZARDRECOGNIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|InstrItineraryData
decl_stmt|;
name|class
name|ScheduleDAG
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
name|class
name|ScoreboardHazardRecognizer
range|:
name|public
name|ScheduleHazardRecognizer
block|{
comment|// Scoreboard to track function unit usage. Scoreboard[0] is a
comment|// mask of the FUs in use in the cycle currently being
comment|// schedule. Scoreboard[1] is a mask for the next cycle. The
comment|// Scoreboard is used as a circular buffer with the current cycle
comment|// indicated by Head.
comment|//
comment|// Scoreboard always counts cycles in forward execution order. If used by a
comment|// bottom-up scheduler, then the scoreboard cycles are the inverse of the
comment|// scheduler's cycles.
name|class
name|Scoreboard
block|{
name|unsigned
operator|*
name|Data
operator|=
name|nullptr
block|;
comment|// The maximum number of cycles monitored by the Scoreboard. This
comment|// value is determined based on the target itineraries to ensure
comment|// that all hazards can be tracked.
name|size_t
name|Depth
operator|=
literal|0
block|;
comment|// Indices into the Scoreboard that represent the current cycle.
name|size_t
name|Head
operator|=
literal|0
block|;
name|public
operator|:
name|Scoreboard
argument_list|()
operator|=
expr|default
block|;
operator|~
name|Scoreboard
argument_list|()
block|{
name|delete
index|[]
name|Data
block|;     }
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
comment|// Depth is expected to be a power-of-2.
name|assert
argument_list|(
name|Depth
operator|&&
operator|!
operator|(
name|Depth
operator|&
operator|(
name|Depth
operator|-
literal|1
operator|)
operator|)
operator|&&
literal|"Scoreboard was not initialized properly!"
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
operator|&
operator|(
name|Depth
operator|-
literal|1
operator|)
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
operator|!
name|Data
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
block|;     }
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
operator|&
operator|(
name|Depth
operator|-
literal|1
operator|)
block|;     }
name|void
name|recede
argument_list|()
block|{
name|Head
operator|=
operator|(
name|Head
operator|-
literal|1
operator|)
operator|&
operator|(
name|Depth
operator|-
literal|1
operator|)
block|;     }
comment|// Print the scoreboard.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
decl_stmt|;
comment|// Support for tracing ScoreboardHazardRecognizer as a component within
comment|// another module.
specifier|const
name|char
modifier|*
name|DebugType
decl_stmt|;
comment|// Itinerary data for the target.
specifier|const
name|InstrItineraryData
modifier|*
name|ItinData
decl_stmt|;
specifier|const
name|ScheduleDAG
modifier|*
name|DAG
decl_stmt|;
comment|/// IssueWidth - Max issue per cycle. 0=Unknown.
name|unsigned
name|IssueWidth
init|=
literal|0
decl_stmt|;
comment|/// IssueCount - Count instructions issued in this cycle.
name|unsigned
name|IssueCount
init|=
literal|0
decl_stmt|;
name|Scoreboard
name|ReservedScoreboard
decl_stmt|;
name|Scoreboard
name|RequiredScoreboard
decl_stmt|;
name|public
label|:
name|ScoreboardHazardRecognizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
specifier|const
name|ScheduleDAG
operator|*
name|DAG
argument_list|,
specifier|const
name|char
operator|*
name|ParentDebugType
operator|=
literal|""
argument_list|)
expr_stmt|;
comment|/// atIssueLimit - Return true if no more instructions may be issued in this
comment|/// cycle.
name|bool
name|atIssueLimit
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|// Stalls provides an cycle offset at which SU will be scheduled. It will be
comment|// negative for bottom-up scheduling.
name|HazardType
name|getHazardType
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|,
name|int
name|Stalls
argument_list|)
name|override
decl_stmt|;
name|void
name|Reset
argument_list|()
name|override
expr_stmt|;
name|void
name|EmitInstruction
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
name|override
decl_stmt|;
name|void
name|AdvanceCycle
argument_list|()
name|override
expr_stmt|;
name|void
name|RecedeCycle
argument_list|()
name|override
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
comment|// LLVM_CODEGEN_SCOREBOARDHAZARDRECOGNIZER_H
end_comment

end_unit

