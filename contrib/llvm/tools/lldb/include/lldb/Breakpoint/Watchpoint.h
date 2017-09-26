begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Watchpoint.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_Watchpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Watchpoint_h_
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
file|<memory>
end_include

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
file|"lldb/Breakpoint/StoppointLocation.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/WatchpointOptions.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Watchpoint
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Watchpoint
operator|>
decl_stmt|,
name|public
name|StoppointLocation
block|{
name|public
label|:
name|class
name|WatchpointEventData
range|:
name|public
name|EventData
block|{
name|public
operator|:
name|WatchpointEventData
argument_list|(
argument|lldb::WatchpointEventType sub_type
argument_list|,
argument|const lldb::WatchpointSP&new_watchpoint_sp
argument_list|)
block|;
operator|~
name|WatchpointEventData
argument_list|()
name|override
block|;
specifier|static
specifier|const
name|ConstString
operator|&
name|GetFlavorString
argument_list|()
block|;
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
name|override
block|;
name|lldb
operator|::
name|WatchpointEventType
name|GetWatchpointEventType
argument_list|()
specifier|const
block|;
name|lldb
operator|::
name|WatchpointSP
operator|&
name|GetWatchpoint
argument_list|()
block|;
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|lldb
operator|::
name|WatchpointEventType
name|GetWatchpointEventTypeFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|WatchpointSP
name|GetWatchpointFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|;
specifier|static
specifier|const
name|WatchpointEventData
operator|*
name|GetEventDataFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_sp
argument_list|)
block|;
name|private
operator|:
name|lldb
operator|::
name|WatchpointEventType
name|m_watchpoint_event
block|;
name|lldb
operator|::
name|WatchpointSP
name|m_new_watchpoint_sp
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|WatchpointEventData
argument_list|)
block|;   }
decl_stmt|;
name|Watchpoint
argument_list|(
argument|Target&target
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|uint32_t size
argument_list|,
argument|const CompilerType *type
argument_list|,
argument|bool hardware = true
argument_list|)
empty_stmt|;
operator|~
name|Watchpoint
argument_list|()
name|override
expr_stmt|;
name|void
name|IncrementFalseAlarmsAndReviseHitCount
parameter_list|()
function_decl|;
name|bool
name|IsEnabled
argument_list|()
specifier|const
expr_stmt|;
comment|// This doesn't really enable/disable the watchpoint.
comment|// It is currently just for use in the Process plugin's
comment|// {Enable,Disable}Watchpoint, which should be used instead.
name|void
name|SetEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|,
name|bool
name|notify
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|IsHardware
argument_list|()
specifier|const
name|override
expr_stmt|;
name|bool
name|ShouldStop
argument_list|(
name|StoppointCallbackContext
operator|*
name|context
argument_list|)
name|override
decl_stmt|;
name|bool
name|WatchpointRead
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|WatchpointWrite
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetIgnoreCount
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetIgnoreCount
parameter_list|(
name|uint32_t
name|n
parameter_list|)
function_decl|;
name|void
name|SetWatchpointType
parameter_list|(
name|uint32_t
name|type
parameter_list|,
name|bool
name|notify
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|SetDeclInfo
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|GetWatchSpec
argument_list|()
expr_stmt|;
name|void
name|SetWatchSpec
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
decl_stmt|;
comment|// Snapshot management interface.
name|bool
name|IsWatchVariable
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetWatchVariable
parameter_list|(
name|bool
name|val
parameter_list|)
function_decl|;
name|bool
name|CaptureWatchedValue
parameter_list|(
specifier|const
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl_stmt|;
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
name|override
decl_stmt|;
name|void
name|DumpSnapshots
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|prefix
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
name|void
name|DumpWithLevel
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|description_level
argument_list|)
decl|const
decl_stmt|;
name|Target
modifier|&
name|GetTarget
parameter_list|()
block|{
return|return
name|m_target
return|;
block|}
specifier|const
name|Status
modifier|&
name|GetError
parameter_list|()
block|{
return|return
name|m_error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns the WatchpointOptions structure set for this watchpoint.
comment|///
comment|/// @return
comment|///     A pointer to this watchpoint's WatchpointOptions.
comment|//------------------------------------------------------------------
name|WatchpointOptions
modifier|*
name|GetOptions
parameter_list|()
block|{
return|return
operator|&
name|m_options
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set the callback action invoked when the watchpoint is hit.
comment|///
comment|/// @param[in] callback
comment|///    The method that will get called when the watchpoint is hit.
comment|/// @param[in] callback_baton
comment|///    A void * pointer that will get passed back to the callback function.
comment|/// @param[in] is_synchronous
comment|///    If \b true the callback will be run on the private event thread
comment|///    before the stop event gets reported.  If false, the callback will get
comment|///    handled on the public event thread after the stop has been posted.
comment|///
comment|/// @return
comment|///    \b true if the process should stop when you hit the watchpoint.
comment|///    \b false if it should continue.
comment|//------------------------------------------------------------------
name|void
name|SetCallback
parameter_list|(
name|WatchpointHitCallback
name|callback
parameter_list|,
name|void
modifier|*
name|callback_baton
parameter_list|,
name|bool
name|is_synchronous
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|SetCallback
argument_list|(
name|WatchpointHitCallback
name|callback
argument_list|,
specifier|const
name|lldb
operator|::
name|BatonSP
operator|&
name|callback_baton_sp
argument_list|,
name|bool
name|is_synchronous
operator|=
name|false
argument_list|)
decl_stmt|;
name|void
name|ClearCallback
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Invoke the callback action when the watchpoint is hit.
comment|///
comment|/// @param[in] context
comment|///     Described the watchpoint event.
comment|///
comment|/// @return
comment|///     \b true if the target should stop at this watchpoint and \b false not.
comment|//------------------------------------------------------------------
name|bool
name|InvokeCallback
parameter_list|(
name|StoppointCallbackContext
modifier|*
name|context
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Condition
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Set the watchpoint's condition.
comment|///
comment|/// @param[in] condition
comment|///    The condition expression to evaluate when the watchpoint is hit.
comment|///    Pass in nullptr to clear the condition.
comment|//------------------------------------------------------------------
name|void
name|SetCondition
parameter_list|(
specifier|const
name|char
modifier|*
name|condition
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return a pointer to the text of the condition expression.
comment|///
comment|/// @return
comment|///    A pointer to the condition expression text, or nullptr if no
comment|//     condition has been set.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetConditionText
argument_list|()
specifier|const
expr_stmt|;
name|void
name|TurnOnEphemeralMode
parameter_list|()
function_decl|;
name|void
name|TurnOffEphemeralMode
parameter_list|()
function_decl|;
name|bool
name|IsDisabledDuringEphemeralMode
parameter_list|()
function_decl|;
specifier|const
name|CompilerType
modifier|&
name|GetCompilerType
parameter_list|()
block|{
return|return
name|m_type
return|;
block|}
name|private
label|:
name|friend
name|class
name|Target
decl_stmt|;
name|friend
name|class
name|WatchpointList
decl_stmt|;
name|void
name|ResetHitCount
parameter_list|()
block|{
name|m_hit_count
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|ResetHistoricValues
parameter_list|()
block|{
name|m_old_value_sp
operator|.
name|reset
argument_list|(
name|nullptr
argument_list|)
expr_stmt|;
name|m_new_value_sp
operator|.
name|reset
argument_list|(
name|nullptr
argument_list|)
expr_stmt|;
block|}
name|Target
modifier|&
name|m_target
decl_stmt|;
name|bool
name|m_enabled
decl_stmt|;
comment|// Is this watchpoint enabled
name|bool
name|m_is_hardware
decl_stmt|;
comment|// Is this a hardware watchpoint
name|bool
name|m_is_watch_variable
decl_stmt|;
comment|// True if set via 'watchpoint set variable'.
name|bool
name|m_is_ephemeral
decl_stmt|;
comment|// True if the watchpoint is in the ephemeral mode,
comment|// meaning that it is
comment|// undergoing a pair of temporary disable/enable actions to avoid recursively
comment|// triggering further watchpoint events.
name|uint32_t
name|m_disabled_count
decl_stmt|;
comment|// Keep track of the count that the watchpoint is
comment|// disabled while in ephemeral mode.
comment|// At the end of the ephemeral mode when the watchpoint is to be enabled
comment|// again,
comment|// we check the count, if it is more than 1, it means the user-supplied
comment|// actions
comment|// actually want the watchpoint to be disabled!
name|uint32_t
name|m_watch_read
range|:
literal|1
decl_stmt|,
comment|// 1 if we stop when the watched data is read from
name|m_watch_write
range|:
literal|1
decl_stmt|,
comment|// 1 if we stop when the watched data is written to
name|m_watch_was_read
range|:
literal|1
decl_stmt|,
comment|// Set to 1 when watchpoint is hit for a read access
name|m_watch_was_written
range|:
literal|1
decl_stmt|;
comment|// Set to 1 when watchpoint is hit for a write
comment|// access
name|uint32_t
name|m_ignore_count
decl_stmt|;
comment|// Number of times to ignore this watchpoint
name|uint32_t
name|m_false_alarms
decl_stmt|;
comment|// Number of false alarms.
name|std
operator|::
name|string
name|m_decl_str
expr_stmt|;
comment|// Declaration information, if any.
name|std
operator|::
name|string
name|m_watch_spec_str
expr_stmt|;
comment|// Spec for the watchpoint.
name|lldb
operator|::
name|ValueObjectSP
name|m_old_value_sp
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|m_new_value_sp
expr_stmt|;
name|CompilerType
name|m_type
decl_stmt|;
name|Status
name|m_error
decl_stmt|;
comment|// An error object describing errors associated with this
comment|// watchpoint.
name|WatchpointOptions
name|m_options
decl_stmt|;
comment|// Settable watchpoint options, which is a delegate to handle
comment|// the callback machinery.
name|bool
name|m_being_created
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|UserExpression
operator|>
name|m_condition_ap
expr_stmt|;
comment|// The condition to test.
name|void
name|SetID
argument_list|(
name|lldb
operator|::
name|watch_id_t
name|id
argument_list|)
block|{
name|m_loc_id
operator|=
name|id
expr_stmt|;
block|}
name|void
name|SendWatchpointChangedEvent
argument_list|(
name|lldb
operator|::
name|WatchpointEventType
name|eventKind
argument_list|)
decl_stmt|;
name|void
name|SendWatchpointChangedEvent
parameter_list|(
name|WatchpointEventData
modifier|*
name|data
parameter_list|)
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Watchpoint
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
comment|// liblldb_Watchpoint_h_
end_comment

end_unit

