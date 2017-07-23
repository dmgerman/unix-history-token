begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StopInfo.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_StopInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StopInfo_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

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
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StopInfo
block|{
name|friend
name|class
name|Process
operator|::
name|ProcessEventData
expr_stmt|;
name|friend
name|class
name|ThreadPlanBase
decl_stmt|;
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|StopInfo
argument_list|(
argument|Thread&thread
argument_list|,
argument|uint64_t value
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|StopInfo
argument_list|()
block|{}
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
block|{
name|m_thread_wp
operator|=
name|thread_sp
expr_stmt|;
block|}
name|lldb
operator|::
name|ThreadSP
name|GetThread
argument_list|()
specifier|const
block|{
return|return
name|m_thread_wp
operator|.
name|lock
argument_list|()
return|;
block|}
comment|// The value of the StopInfo depends on the StopReason.
comment|// StopReason                  Meaning
comment|// ----------------------------------------------
comment|// eStopReasonBreakpoint       BreakpointSiteID
comment|// eStopReasonSignal           Signal number
comment|// eStopReasonWatchpoint       WatchpointLocationID
comment|// eStopReasonPlanComplete     No significance
name|uint64_t
name|GetValue
argument_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
name|virtual
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// ShouldStopSynchronous will get called before any thread plans are
comment|// consulted, and if it says we should
comment|// resume the target, then we will just immediately resume.  This should not
comment|// run any code in or resume the
comment|// target.
name|virtual
name|bool
name|ShouldStopSynchronous
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|void
name|OverrideShouldNotify
parameter_list|(
name|bool
name|override_value
parameter_list|)
block|{
name|m_override_should_notify
operator|=
name|override_value
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
comment|// If should stop returns false, check if we should notify of this event
name|virtual
name|bool
name|ShouldNotify
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
block|{
if|if
condition|(
name|m_override_should_notify
operator|==
name|eLazyBoolCalculate
condition|)
return|return
name|DoShouldNotify
argument_list|(
name|event_ptr
argument_list|)
return|;
else|else
return|return
name|m_override_should_notify
operator|==
name|eLazyBoolYes
return|;
block|}
name|virtual
name|void
name|WillResume
argument_list|(
name|lldb
operator|::
name|StateType
name|resume_state
argument_list|)
block|{
comment|// By default, don't do anything
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetDescription
parameter_list|()
block|{
return|return
name|m_description
operator|.
name|c_str
argument_list|()
return|;
block|}
name|virtual
name|void
name|SetDescription
parameter_list|(
specifier|const
name|char
modifier|*
name|desc_cstr
parameter_list|)
block|{
if|if
condition|(
name|desc_cstr
operator|&&
name|desc_cstr
index|[
literal|0
index|]
condition|)
name|m_description
operator|.
name|assign
argument_list|(
name|desc_cstr
argument_list|)
expr_stmt|;
else|else
name|m_description
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|virtual
name|bool
name|IsValidForOperatingSystemThread
parameter_list|(
name|Thread
modifier|&
name|thread
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Sometimes the thread plan logic will know that it wants a given stop to
comment|// stop or not,
comment|// regardless of what the ordinary logic for that StopInfo would dictate.  The
comment|// main example
comment|// of this is the ThreadPlanCallFunction, which for instance knows - based on
comment|// how that particular
comment|// expression was executed - whether it wants all breakpoints to auto-continue
comment|// or not.
comment|// Use OverrideShouldStop on the StopInfo to implement this.
name|void
name|OverrideShouldStop
parameter_list|(
name|bool
name|override_value
parameter_list|)
block|{
name|m_override_should_stop
operator|=
name|override_value
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|bool
name|GetOverrideShouldStop
parameter_list|()
block|{
return|return
name|m_override_should_stop
operator|!=
name|eLazyBoolCalculate
return|;
block|}
name|bool
name|GetOverriddenShouldStopValue
parameter_list|()
block|{
return|return
name|m_override_should_stop
operator|==
name|eLazyBoolYes
return|;
block|}
name|StructuredData
operator|::
name|ObjectSP
name|GetExtendedInfo
argument_list|()
block|{
return|return
name|m_extended_info
return|;
block|}
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithBreakpointSiteID
argument_list|(
argument|Thread&thread
argument_list|,
argument|lldb::break_id_t break_id
argument_list|)
expr_stmt|;
comment|// This creates a StopInfo for the thread where the should_stop is already
comment|// set, and won't be recalculated.
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithBreakpointSiteID
argument_list|(
argument|Thread&thread
argument_list|,
argument|lldb::break_id_t break_id
argument_list|,
argument|bool should_stop
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithWatchpointID
argument_list|(
argument|Thread&thread
argument_list|,
argument|lldb::break_id_t watch_id
argument_list|,
argument|lldb::addr_t watch_hit_addr = LLDB_INVALID_ADDRESS
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithSignal
argument_list|(
argument|Thread&thread
argument_list|,
argument|int signo
argument_list|,
argument|const char *description = nullptr
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonToTrace
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithPlan
argument_list|(
argument|lldb::ThreadPlanSP&plan
argument_list|,
argument|lldb::ValueObjectSP return_valobj_sp
argument_list|,
argument|lldb::ExpressionVariableSP expression_variable_sp
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithException
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
specifier|const
name|char
operator|*
name|description
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithExec
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObject
argument_list|(
name|lldb
operator|::
name|StopInfoSP
operator|&
name|stop_info_sp
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|ExpressionVariableSP
name|GetExpressionVariable
argument_list|(
name|lldb
operator|::
name|StopInfoSP
operator|&
name|stop_info_sp
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|GetCrashingDereference
argument_list|(
name|lldb
operator|::
name|StopInfoSP
operator|&
name|stop_info_sp
argument_list|,
name|lldb
operator|::
name|addr_t
operator|*
name|crashing_address
operator|=
name|nullptr
argument_list|)
expr_stmt|;
name|protected
label|:
comment|// Perform any action that is associated with this stop.  This is done as the
comment|// Event is removed from the event queue.  ProcessEventData::DoOnRemoval does
comment|// the job.
name|virtual
name|void
name|PerformAction
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
block|{}
name|virtual
name|bool
name|DoShouldNotify
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Stop the thread by default. Subclasses can override this to allow
comment|// the thread to continue if desired.  The ShouldStop method should not do
comment|// anything
comment|// that might run code.  If you need to run code when deciding whether to stop
comment|// at this StopInfo, that must be done in the PerformAction.
comment|// The PerformAction will always get called before the ShouldStop.  This is
comment|// done by the
comment|// ProcessEventData::DoOnRemoval, though the ThreadPlanBase needs to consult
comment|// this later on.
name|virtual
name|bool
name|ShouldStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Classes that inherit from StackID can see and modify these
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ThreadWP
name|m_thread_wp
expr_stmt|;
comment|// The thread corresponding to the stop reason.
name|uint32_t
name|m_stop_id
decl_stmt|;
comment|// The process stop ID for which this stop info is valid
name|uint32_t
name|m_resume_id
decl_stmt|;
comment|// This is the resume ID when we made this stop ID.
name|uint64_t
name|m_value
decl_stmt|;
comment|// A generic value that can be used for things pertaining to
comment|// this stop info
name|std
operator|::
name|string
name|m_description
expr_stmt|;
comment|// A textual description describing this stop.
name|LazyBool
name|m_override_should_notify
decl_stmt|;
name|LazyBool
name|m_override_should_stop
decl_stmt|;
name|StructuredData
operator|::
name|ObjectSP
name|m_extended_info
expr_stmt|;
comment|// The extended info for this stop info
comment|// This determines whether the target has run since this stop info.
comment|// N.B. running to evaluate a user expression does not count.
name|bool
name|HasTargetRunSinceMe
parameter_list|()
function_decl|;
comment|// MakeStopInfoValid is necessary to allow saved stop infos to resurrect
comment|// themselves as valid.
comment|// It should only be used by Thread::RestoreThreadStateFromCheckpoint and to
comment|// make sure the one-step
comment|// needed for before-the-fact watchpoints does not prevent us from stopping
name|void
name|MakeStopInfoValid
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|class
name|Thread
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|StopInfo
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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
comment|// liblldb_StopInfo_h_
end_comment

end_unit

