begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/ScheduleHazardRecognizer.h - Scheduling Support -*- C++ -*-=//
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
comment|// This file implements the ScheduleHazardRecognizer class, which implements
end_comment

begin_comment
comment|// hazard-avoidance heuristics for scheduling.
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
name|LLVM_CODEGEN_SCHEDULEHAZARDRECOGNIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCHEDULEHAZARDRECOGNIZER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
comment|/// HazardRecognizer - This determines whether or not an instruction can be
comment|/// issued this cycle, and whether or not a noop needs to be inserted to handle
comment|/// the hazard.
name|class
name|ScheduleHazardRecognizer
block|{
name|protected
label|:
comment|/// MaxLookAhead - Indicate the number of cycles in the scoreboard
comment|/// state. Important to restore the state after backtracking. Additionally,
comment|/// MaxLookAhead=0 identifies a fake recognizer, allowing the client to
comment|/// bypass virtual calls. Currently the PostRA scheduler ignores it.
name|unsigned
name|MaxLookAhead
init|=
literal|0
decl_stmt|;
name|public
label|:
name|ScheduleHazardRecognizer
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
operator|~
name|ScheduleHazardRecognizer
argument_list|()
expr_stmt|;
enum|enum
name|HazardType
block|{
name|NoHazard
block|,
comment|// This instruction can be emitted at this cycle.
name|Hazard
block|,
comment|// This instruction can't be emitted at this cycle.
name|NoopHazard
comment|// This instruction can't be emitted, and needs noops.
block|}
enum|;
name|unsigned
name|getMaxLookAhead
argument_list|()
specifier|const
block|{
return|return
name|MaxLookAhead
return|;
block|}
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
name|MaxLookAhead
operator|!=
literal|0
return|;
block|}
comment|/// atIssueLimit - Return true if no more instructions may be issued in this
comment|/// cycle.
comment|///
comment|/// FIXME: remove this once MachineScheduler is the only client.
name|virtual
name|bool
name|atIssueLimit
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// getHazardType - Return the hazard type of emitting this node.  There are
comment|/// three possible results.  Either:
comment|///  * NoHazard: it is legal to issue this instruction on this cycle.
comment|///  * Hazard: issuing this instruction would stall the machine.  If some
comment|///     other instruction is available, issue it first.
comment|///  * NoopHazard: issuing this instruction would break the program.  If
comment|///     some other instruction can be issued, do so, otherwise issue a noop.
name|virtual
name|HazardType
name|getHazardType
parameter_list|(
name|SUnit
modifier|*
name|m
parameter_list|,
name|int
name|Stalls
init|=
literal|0
parameter_list|)
block|{
return|return
name|NoHazard
return|;
block|}
comment|/// Reset - This callback is invoked when a new block of
comment|/// instructions is about to be schedule. The hazard state should be
comment|/// set to an initialized state.
name|virtual
name|void
name|Reset
parameter_list|()
block|{}
comment|/// EmitInstruction - This callback is invoked when an instruction is
comment|/// emitted, to advance the hazard state.
name|virtual
name|void
name|EmitInstruction
parameter_list|(
name|SUnit
modifier|*
parameter_list|)
block|{}
comment|/// This overload will be used when the hazard recognizer is being used
comment|/// by a non-scheduling pass, which does not use SUnits.
name|virtual
name|void
name|EmitInstruction
parameter_list|(
name|MachineInstr
modifier|*
parameter_list|)
block|{}
comment|/// PreEmitNoops - This callback is invoked prior to emitting an instruction.
comment|/// It should return the number of noops to emit prior to the provided
comment|/// instruction.
comment|/// Note: This is only used during PostRA scheduling. EmitNoop is not called
comment|/// for these noops.
name|virtual
name|unsigned
name|PreEmitNoops
parameter_list|(
name|SUnit
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// This overload will be used when the hazard recognizer is being used
comment|/// by a non-scheduling pass, which does not use SUnits.
name|virtual
name|unsigned
name|PreEmitNoops
parameter_list|(
name|MachineInstr
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// ShouldPreferAnother - This callback may be invoked if getHazardType
comment|/// returns NoHazard. If, even though there is no hazard, it would be better to
comment|/// schedule another available instruction, this callback should return true.
name|virtual
name|bool
name|ShouldPreferAnother
parameter_list|(
name|SUnit
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// AdvanceCycle - This callback is invoked whenever the next top-down
comment|/// instruction to be scheduled cannot issue in the current cycle, either
comment|/// because of latency or resource conflicts.  This should increment the
comment|/// internal state of the hazard recognizer so that previously "Hazard"
comment|/// instructions will now not be hazards.
name|virtual
name|void
name|AdvanceCycle
parameter_list|()
block|{}
comment|/// RecedeCycle - This callback is invoked whenever the next bottom-up
comment|/// instruction to be scheduled cannot issue in the current cycle, either
comment|/// because of latency or resource conflicts.
name|virtual
name|void
name|RecedeCycle
parameter_list|()
block|{}
comment|/// EmitNoop - This callback is invoked when a noop was added to the
comment|/// instruction stream.
name|virtual
name|void
name|EmitNoop
parameter_list|()
block|{
comment|// Default implementation: count it as a cycle.
name|AdvanceCycle
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
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
comment|// LLVM_CODEGEN_SCHEDULEHAZARDRECOGNIZER_H
end_comment

end_unit

