begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepRange.h -----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ThreadPlanStepRange_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepRange_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StackID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlan.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlanShouldStopHere.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanStepRange
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|ThreadPlanStepRange
argument_list|(
argument|ThreadPlanKind kind
argument_list|,
argument|const char *name
argument_list|,
argument|Thread&thread
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|lldb::RunMode stop_others
argument_list|,
argument|bool given_ranges_only = false
argument_list|)
block|;
name|virtual
operator|~
name|ThreadPlanStepRange
argument_list|()
block|;
name|virtual
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|ValidatePlan
argument_list|(
name|Stream
operator|*
name|error
argument_list|)
block|;
name|virtual
name|bool
name|ShouldStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Vote
name|ShouldReportStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|virtual
name|bool
name|StopOthers
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
block|;
name|virtual
name|bool
name|WillStop
argument_list|()
block|;
name|virtual
name|bool
name|MischiefManaged
argument_list|()
block|;
name|virtual
name|void
name|DidPush
argument_list|()
block|;
name|virtual
name|bool
name|IsPlanStale
argument_list|()
block|;
name|void
name|AddRange
argument_list|(
specifier|const
name|AddressRange
operator|&
name|new_range
argument_list|)
block|;
name|protected
operator|:
name|bool
name|InRange
argument_list|()
block|;
name|lldb
operator|::
name|FrameComparison
name|CompareCurrentFrameToStartFrame
argument_list|()
block|;
name|bool
name|InSymbol
argument_list|()
block|;
name|void
name|DumpRanges
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
block|;
name|Disassembler
operator|*
name|GetDisassembler
argument_list|()
block|;
name|InstructionList
operator|*
name|GetInstructionsForAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t&range_index
argument_list|,
argument|size_t&insn_offset
argument_list|)
block|;
comment|// Pushes a plan to proceed through the next section of instructions in the range - usually just a RunToAddress
comment|// plan to run to the next branch.  Returns true if it pushed such a plan.  If there was no available 'quick run'
comment|// plan, then just single step.
name|bool
name|SetNextBranchBreakpoint
argument_list|()
block|;
name|void
name|ClearNextBranchBreakpoint
argument_list|()
block|;
name|bool
name|NextRangeBreakpointExplainsStop
argument_list|(
argument|lldb::StopInfoSP stop_info_sp
argument_list|)
block|;
name|SymbolContext
name|m_addr_context
block|;
name|std
operator|::
name|vector
operator|<
name|AddressRange
operator|>
name|m_address_ranges
block|;
name|lldb
operator|::
name|RunMode
name|m_stop_others
block|;
name|StackID
name|m_stack_id
block|;
comment|// Use the stack ID so we can tell step out from step in.
name|StackID
name|m_parent_stack_id
block|;
comment|// Use the parent stack ID so we can identify tail calls and the like.
name|bool
name|m_no_more_plans
block|;
comment|// Need this one so we can tell if we stepped into a call,
comment|// but can't continue, in which case we are done.
name|bool
name|m_first_run_event
block|;
comment|// We want to broadcast only one running event, our first.
name|lldb
operator|::
name|BreakpointSP
name|m_next_branch_bp_sp
block|;
name|bool
name|m_use_fast_step
block|;
name|bool
name|m_given_ranges_only
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|DisassemblerSP
operator|>
name|m_instruction_ranges
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepRange
argument_list|)
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadPlanStepRange_h_
end_comment

end_unit

