begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanStepOverBreakpoint.h --------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanStepOverBreakpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanStepOverBreakpoint_h_
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
name|ThreadPlanStepOverBreakpoint
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|virtual
operator|~
name|ThreadPlanStepOverBreakpoint
argument_list|()
block|;
name|ThreadPlanStepOverBreakpoint
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
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
name|ThreadDestroyed
argument_list|()
block|;
name|void
name|SetAutoContinue
argument_list|(
argument|bool do_it
argument_list|)
block|;
name|virtual
name|bool
name|ShouldAutoContinue
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|virtual
name|bool
name|IsPlanStale
argument_list|()
block|;
name|lldb
operator|::
name|addr_t
name|GetBreakpointLoadAddress
argument_list|()
specifier|const
block|{
return|return
name|m_breakpoint_addr
return|;
block|}
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
name|void
name|ReenableBreakpointSite
argument_list|()
block|;
name|private
operator|:
name|lldb
operator|::
name|addr_t
name|m_breakpoint_addr
block|;
name|lldb
operator|::
name|user_id_t
name|m_breakpoint_site_id
block|;
name|bool
name|m_auto_continue
block|;
name|bool
name|m_reenabled_breakpoint_site
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanStepOverBreakpoint
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
comment|// liblldb_ThreadPlanStepOverBreakpoint_h_
end_comment

end_unit

