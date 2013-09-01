begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanBase.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanFundamental_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanFundamental_h_
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
file|"lldb/Target/Process.h"
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
comment|//------------------------------------------------------------------
comment|//  Base thread plans:
comment|//  This is the generic version of the bottom most plan on the plan stack.  It should
comment|//  be able to handle generic breakpoint hitting, and signals and exceptions.
comment|//------------------------------------------------------------------
name|class
name|ThreadPlanBase
range|:
name|public
name|ThreadPlan
block|{
name|friend
name|class
name|Process
block|;
comment|// RunThreadPlan manages "stopper" base plans.
name|public
operator|:
name|virtual
operator|~
name|ThreadPlanBase
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
name|bool
name|OkayToDiscard
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|IsBasePlan
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|virtual
name|bool
name|DoWillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|,
argument|bool current_plan
argument_list|)
block|;
name|virtual
name|bool
name|DoPlanExplainsStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|ThreadPlanBase
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
block|;
name|private
operator|:
name|friend
name|lldb
operator|::
name|ThreadPlanSP
name|Thread
operator|::
name|QueueFundamentalPlan
argument_list|(
argument|bool abort_other_plans
argument_list|)
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanBase
argument_list|)
block|; }
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
comment|// liblldb_ThreadPlanFundamental_h_
end_comment

end_unit

