begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepInstruction.h -----------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanStepInstruction_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepInstruction_h_
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
file|"lldb/lldb-private.h"
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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanStepInstruction
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|virtual
operator|~
name|ThreadPlanStepInstruction
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
name|bool
name|IsPlanStale
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|bool
name|DoPlanExplainsStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|ThreadPlanStepInstruction
argument_list|(
argument|Thread&thread
argument_list|,
argument|bool step_over
argument_list|,
argument|bool stop_others
argument_list|,
argument|Vote stop_vote
argument_list|,
argument|Vote run_vote
argument_list|)
block|;
name|void
name|SetUpState
argument_list|()
block|;
name|private
operator|:
name|friend
name|lldb
operator|::
name|ThreadPlanSP
name|Thread
operator|::
name|QueueThreadPlanForStepSingleInstruction
argument_list|(
argument|bool step_over
argument_list|,
argument|bool abort_other_plans
argument_list|,
argument|bool stop_other_threads
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|m_instruction_addr
block|;
name|bool
name|m_stop_other_threads
block|;
name|bool
name|m_step_over
block|;
comment|// These two are used only for the step over case.
name|bool
name|m_start_has_symbol
block|;
name|StackID
name|m_stack_id
block|;
name|StackID
name|m_parent_frame_id
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepInstruction
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
comment|// liblldb_ThreadPlanStepInstruction_h_
end_comment

end_unit

