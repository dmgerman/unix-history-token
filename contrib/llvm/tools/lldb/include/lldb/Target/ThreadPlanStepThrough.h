begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepThrough.h ---------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanStepThrough_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepThrough_h_
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
name|ThreadPlanStepThrough
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|virtual
operator|~
name|ThreadPlanStepThrough
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
name|void
name|DidPush
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
name|virtual
name|bool
name|DoWillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|,
argument|bool current_plan
argument_list|)
block|;
name|ThreadPlanStepThrough
argument_list|(
argument|Thread&thread
argument_list|,
argument|StackID&return_stack_id
argument_list|,
argument|bool stop_others
argument_list|)
block|;
name|void
name|LookForPlanToStepThroughFromCurrentPC
argument_list|()
block|;
name|bool
name|HitOurBackstopBreakpoint
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
name|QueueThreadPlanForStepThrough
argument_list|(
argument|StackID&return_stack_id
argument_list|,
argument|bool abort_other_plans
argument_list|,
argument|bool stop_others
argument_list|)
block|;
name|void
name|ClearBackstopBreakpoint
argument_list|()
block|;
name|lldb
operator|::
name|ThreadPlanSP
name|m_sub_plan_sp
block|;
name|lldb
operator|::
name|addr_t
name|m_start_address
block|;
name|lldb
operator|::
name|break_id_t
name|m_backstop_bkpt_id
block|;
name|lldb
operator|::
name|addr_t
name|m_backstop_addr
block|;
name|StackID
name|m_return_stack_id
block|;
name|bool
name|m_stop_others
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepThrough
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
comment|// liblldb_ThreadPlanStepThrough_h_
end_comment

end_unit

