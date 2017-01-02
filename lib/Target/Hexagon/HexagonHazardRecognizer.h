begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- HexagonHazardRecognizer.h - Hexagon Post RA Hazard Recognizer ----===//
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
comment|// This file defines the hazard recognizer for scheduling on Hexagon.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONPROFITRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONPROFITRECOGNIZER_H
end_define

begin_include
include|#
directive|include
file|"HexagonInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"HexagonSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DFAPacketizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonHazardRecognizer
range|:
name|public
name|ScheduleHazardRecognizer
block|{
name|DFAPacketizer
operator|*
name|Resources
block|;
specifier|const
name|HexagonInstrInfo
operator|*
name|TII
block|;
name|unsigned
name|PacketNum
block|;
comment|// If the packet contains a potential dot cur instruction. This is
comment|// used for the scheduling priority function.
name|SUnit
operator|*
name|UsesDotCur
block|;
comment|// The packet number when a dor cur is emitted. If its use is not generated
comment|// in the same packet, then try to wait another cycle before emitting.
name|int
name|DotCurPNum
block|;
comment|// The set of registers defined by instructions in the current packet.
name|SmallSet
operator|<
name|unsigned
block|,
literal|8
operator|>
name|RegDefs
block|;
name|public
operator|:
name|HexagonHazardRecognizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|II
argument_list|,
specifier|const
name|HexagonInstrInfo
operator|*
name|HII
argument_list|,
specifier|const
name|HexagonSubtarget
operator|&
name|ST
argument_list|)
operator|:
name|Resources
argument_list|(
name|ST
operator|.
name|createDFAPacketizer
argument_list|(
name|II
argument_list|)
argument_list|)
block|,
name|TII
argument_list|(
name|HII
argument_list|)
block|,
name|PacketNum
argument_list|(
literal|0
argument_list|)
block|,
name|UsesDotCur
argument_list|(
name|nullptr
argument_list|)
block|,
name|DotCurPNum
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
operator|~
name|HexagonHazardRecognizer
argument_list|()
name|override
block|{
if|if
condition|(
name|Resources
condition|)
name|delete
name|Resources
decl_stmt|;
block|}
comment|/// This callback is invoked when a new block of instructions is about to be
comment|/// scheduled. The hazard state is set to an initialized state.
name|void
name|Reset
argument_list|()
name|override
block|;
comment|/// Return the hazard type of emitting this node.  There are three
comment|/// possible results.  Either:
comment|///  * NoHazard: it is legal to issue this instruction on this cycle.
comment|///  * Hazard: issuing this instruction would stall the machine.  If some
comment|///     other instruction is available, issue it first.
name|HazardType
name|getHazardType
argument_list|(
argument|SUnit *SU
argument_list|,
argument|int stalls
argument_list|)
name|override
block|;
comment|/// This callback is invoked when an instruction is emitted to be scheduled,
comment|/// to advance the hazard state.
name|void
name|EmitInstruction
argument_list|(
argument|SUnit *
argument_list|)
name|override
block|;
comment|/// This callback may be invoked if getHazardType returns NoHazard. If, even
comment|/// though there is no hazard, it would be better to schedule another
comment|/// available instruction, this callback should return true.
name|bool
name|ShouldPreferAnother
argument_list|(
argument|SUnit *
argument_list|)
name|override
block|;
comment|/// This callback is invoked whenever the next top-down instruction to be
comment|/// scheduled cannot issue in the current cycle, either because of latency
comment|/// or resource conflicts.  This should increment the internal state of the
comment|/// hazard recognizer so that previously "Hazard" instructions will now not
comment|/// be hazards.
name|void
name|AdvanceCycle
argument_list|()
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_HEXAGON_HEXAGONPROFITRECOGNIZER_H
end_comment

end_unit

