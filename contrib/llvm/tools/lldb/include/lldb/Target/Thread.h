begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Thread.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_Thread_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Thread_h_
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
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
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
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Event.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserSettingsController.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterCheckpoint.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StackFrameList.h"
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

begin_define
define|#
directive|define
name|LLDB_THREAD_MAX_STOP_EXC_DATA
value|8
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadProperties
range|:
name|public
name|Properties
block|{
name|public
operator|:
name|ThreadProperties
argument_list|(
argument|bool is_global
argument_list|)
block|;
operator|~
name|ThreadProperties
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// The regular expression returned determines symbols that this
comment|/// thread won't stop in during "step-in" operations.
comment|///
comment|/// @return
comment|///    A pointer to a regular expression to compare against symbols,
comment|///    or nullptr if all symbols are allowed.
comment|///
comment|//------------------------------------------------------------------
specifier|const
name|RegularExpression
operator|*
name|GetSymbolsToAvoidRegexp
argument_list|()
block|;
name|FileSpecList
operator|&
name|GetLibrariesToAvoid
argument_list|()
specifier|const
block|;
name|bool
name|GetTraceEnabledState
argument_list|()
specifier|const
block|;
name|bool
name|GetStepInAvoidsNoDebug
argument_list|()
specifier|const
block|;
name|bool
name|GetStepOutAvoidsNoDebug
argument_list|()
specifier|const
block|; }
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|ThreadProperties
operator|>
name|ThreadPropertiesSP
expr_stmt|;
name|class
name|Thread
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Thread
operator|>
decl_stmt|,
name|public
name|ThreadProperties
decl_stmt|,
name|public
name|UserID
decl_stmt|,
name|public
name|ExecutionContextScope
decl_stmt|,
name|public
name|Broadcaster
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Broadcaster event bits definitions.
comment|//------------------------------------------------------------------
enum|enum
block|{
name|eBroadcastBitStackChanged
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastBitThreadSuspended
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eBroadcastBitThreadResumed
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|eBroadcastBitSelectedFrameChanged
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|eBroadcastBitThreadSelected
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|}
enum|;
specifier|static
name|ConstString
modifier|&
name|GetStaticBroadcasterClass
parameter_list|()
function_decl|;
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
name|override
block|{
return|return
name|GetStaticBroadcasterClass
argument_list|()
return|;
block|}
name|class
name|ThreadEventData
range|:
name|public
name|EventData
block|{
name|public
operator|:
name|ThreadEventData
argument_list|(
argument|const lldb::ThreadSP thread_sp
argument_list|)
block|;
name|ThreadEventData
argument_list|(
argument|const lldb::ThreadSP thread_sp
argument_list|,
argument|const StackID&stack_id
argument_list|)
block|;
name|ThreadEventData
argument_list|()
block|;
operator|~
name|ThreadEventData
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
block|{
return|return
name|ThreadEventData
operator|::
name|GetFlavorString
argument_list|()
return|;
block|}
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
name|override
block|;
specifier|static
specifier|const
name|ThreadEventData
operator|*
name|GetEventDataFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ThreadSP
name|GetThreadFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|StackID
name|GetStackIDFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|StackFrameSP
name|GetStackFrameFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ThreadSP
name|GetThread
argument_list|()
specifier|const
block|{
return|return
name|m_thread_sp
return|;
block|}
name|StackID
name|GetStackID
argument_list|()
specifier|const
block|{
return|return
name|m_stack_id
return|;
block|}
name|private
operator|:
name|lldb
operator|::
name|ThreadSP
name|m_thread_sp
block|;
name|StackID
name|m_stack_id
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadEventData
argument_list|)
block|;   }
decl_stmt|;
struct|struct
name|ThreadStateCheckpoint
block|{
name|uint32_t
name|orig_stop_id
decl_stmt|;
comment|// Dunno if I need this yet but it is an interesting
comment|// bit of data.
name|lldb
operator|::
name|StopInfoSP
name|stop_info_sp
expr_stmt|;
comment|// You have to restore the stop info or you
comment|// might continue with the wrong signals.
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ThreadPlanSP
operator|>
name|m_completed_plan_stack
expr_stmt|;
name|lldb
operator|::
name|RegisterCheckpointSP
name|register_backup_sp
expr_stmt|;
comment|// You need to restore the registers, of course...
name|uint32_t
name|current_inlined_depth
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|current_inlined_pc
expr_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param [in] process
comment|///
comment|/// @param [in] tid
comment|///
comment|/// @param [in] use_invalid_index_id
comment|///     Optional parameter, defaults to false.  The only subclass that
comment|///     is likely to set use_invalid_index_id == true is the HistoryThread
comment|///     class.  In that case, the Thread we are constructing represents
comment|///     a thread from earlier in the program execution.  We may have the
comment|///     tid of the original thread that they represent but we don't want
comment|///     to reuse the IndexID of that thread, or create a new one.  If a
comment|///     client wants to know the original thread's IndexID, they should use
comment|///     Thread::GetExtendedBacktraceOriginatingIndexID().
comment|//------------------------------------------------------------------
name|Thread
argument_list|(
argument|Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|,
argument|bool use_invalid_index_id = false
argument_list|)
empty_stmt|;
operator|~
name|Thread
argument_list|()
name|override
expr_stmt|;
specifier|static
name|void
name|SettingsInitialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|SettingsTerminate
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|ThreadPropertiesSP
modifier|&
name|GetGlobalProperties
parameter_list|()
function_decl|;
name|lldb
operator|::
name|ProcessSP
name|GetProcess
argument_list|()
specifier|const
block|{
return|return
name|m_process_wp
operator|.
name|lock
argument_list|()
return|;
block|}
name|int
name|GetResumeSignal
argument_list|()
specifier|const
block|{
return|return
name|m_resume_signal
return|;
block|}
name|void
name|SetResumeSignal
parameter_list|(
name|int
name|signal
parameter_list|)
block|{
name|m_resume_signal
operator|=
name|signal
expr_stmt|;
block|}
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetState
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sets the USER resume state for this thread.  If you set a thread to
comment|/// suspended with
comment|/// this API, it won't take part in any of the arbitration for ShouldResume,
comment|/// and will stay
comment|/// suspended even when other threads do get to run.
comment|///
comment|/// N.B. This is not the state that is used internally by thread plans to
comment|/// implement
comment|/// staying on one thread while stepping over a breakpoint, etc.  The is the
comment|/// TemporaryResume state, and if you are implementing some bit of strategy in
comment|/// the stepping
comment|/// machinery you should be using that state and not the user resume state.
comment|///
comment|/// If you are just preparing all threads to run, you should not override the
comment|/// threads that are
comment|/// marked as suspended by the debugger.  In that case, pass override_suspend
comment|/// = false.  If you want
comment|/// to force the thread to run (e.g. the "thread continue" command, or are
comment|/// resetting the state
comment|/// (e.g. in SBThread::Resume()), then pass true to override_suspend.
comment|/// @return
comment|///    The User resume state for this thread.
comment|//------------------------------------------------------------------
name|void
name|SetResumeState
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|,
name|bool
name|override_suspend
operator|=
name|false
argument_list|)
block|{
if|if
condition|(
name|m_resume_state
operator|==
name|lldb
operator|::
name|eStateSuspended
operator|&&
operator|!
name|override_suspend
condition|)
return|return;
name|m_resume_state
operator|=
name|state
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Gets the USER resume state for this thread.  This is not the same as what
comment|/// this thread is going to do for any particular step, however if this thread
comment|/// returns eStateSuspended, then the process control logic will never allow
comment|/// this
comment|/// thread to run.
comment|///
comment|/// @return
comment|///    The User resume state for this thread.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|StateType
name|GetResumeState
argument_list|()
specifier|const
block|{
return|return
name|m_resume_state
return|;
block|}
comment|// This function is called on all the threads before "ShouldResume" and
comment|// "WillResume" in case a thread needs to change its state before the
comment|// ThreadList polls all the threads to figure out which ones actually
comment|// will get to run and how.
name|void
name|SetupForResume
parameter_list|()
function_decl|;
comment|// Do not override this function, it is for thread plan logic only
name|bool
name|ShouldResume
argument_list|(
name|lldb
operator|::
name|StateType
name|resume_state
argument_list|)
decl_stmt|;
comment|// Override this to do platform specific tasks before resume.
name|virtual
name|void
name|WillResume
argument_list|(
name|lldb
operator|::
name|StateType
name|resume_state
argument_list|)
block|{}
comment|// This clears generic thread state after a resume.  If you subclass this,
comment|// be sure to call it.
name|virtual
name|void
name|DidResume
parameter_list|()
function_decl|;
comment|// This notifies the thread when a private stop occurs.
name|virtual
name|void
name|DidStop
parameter_list|()
function_decl|;
name|virtual
name|void
name|RefreshStateAfterStop
parameter_list|()
init|=
literal|0
function_decl|;
name|void
name|WillStop
parameter_list|()
function_decl|;
name|bool
name|ShouldStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|Vote
name|ShouldReportStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|Vote
name|ShouldReportRun
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|void
name|Flush
parameter_list|()
function_decl|;
comment|// Return whether this thread matches the specification in ThreadSpec.  This
comment|// is a virtual
comment|// method because at some point we may extend the thread spec with a platform
comment|// specific
comment|// dictionary of attributes, which then only the platform specific Thread
comment|// implementation
comment|// would know how to match.  For now, this just calls through to the
comment|// ThreadSpec's
comment|// ThreadPassesBasicTests method.
name|virtual
name|bool
name|MatchesSpec
parameter_list|(
specifier|const
name|ThreadSpec
modifier|*
name|spec
parameter_list|)
function_decl|;
name|lldb
operator|::
name|StopInfoSP
name|GetStopInfo
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
expr_stmt|;
name|bool
name|StopInfoIsUpToDate
argument_list|()
specifier|const
expr_stmt|;
comment|// This sets the stop reason to a "blank" stop reason, so you can call
comment|// functions on the thread
comment|// without having the called function run with whatever stop reason you
comment|// stopped with.
name|void
name|SetStopInfoToNothing
parameter_list|()
function_decl|;
name|bool
name|ThreadStoppedForAReason
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|RunModeAsCString
argument_list|(
name|lldb
operator|::
name|RunMode
name|mode
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|StopReasonAsCString
argument_list|(
name|lldb
operator|::
name|StopReason
name|reason
argument_list|)
decl_stmt|;
name|virtual
specifier|const
name|char
modifier|*
name|GetInfo
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Retrieve a dictionary of information about this thread
comment|///
comment|/// On Mac OS X systems there may be voucher information.
comment|/// The top level dictionary returned will have an "activity" key and the
comment|/// value of the activity is a dictionary.  Keys in that dictionary will
comment|/// be "name" and "id", among others.
comment|/// There may also be "trace_messages" (an array) with each entry in that
comment|/// array
comment|/// being a dictionary (keys include "message" with the text of the trace
comment|/// message).
comment|//------------------------------------------------------------------
name|StructuredData
operator|::
name|ObjectSP
name|GetExtendedInfo
argument_list|()
block|{
if|if
condition|(
name|m_extended_info_fetched
operator|==
name|false
condition|)
block|{
name|m_extended_info
operator|=
name|FetchThreadExtendedInfo
argument_list|()
expr_stmt|;
name|m_extended_info_fetched
operator|=
name|true
expr_stmt|;
block|}
return|return
name|m_extended_info
return|;
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|void
name|SetName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Whether this thread can be associated with a libdispatch queue
comment|///
comment|/// The Thread may know if it is associated with a libdispatch queue,
comment|/// it may know definitively that it is NOT associated with a libdispatch
comment|/// queue, or it may be unknown whether it is associated with a libdispatch
comment|/// queue.
comment|///
comment|/// @return
comment|///     eLazyBoolNo if this thread is definitely not associated with a
comment|///     libdispatch queue (e.g. on a non-Darwin system where GCD aka
comment|///     libdispatch is not available).
comment|///
comment|///     eLazyBoolYes this thread is associated with a libdispatch queue.
comment|///
comment|///     eLazyBoolCalculate this thread may be associated with a libdispatch
comment|///     queue but the thread doesn't know one way or the other.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|LazyBool
name|GetAssociatedWithLibdispatchQueue
argument_list|()
block|{
return|return
name|eLazyBoolNo
return|;
block|}
name|virtual
name|void
name|SetAssociatedWithLibdispatchQueue
argument_list|(
name|lldb_private
operator|::
name|LazyBool
name|associated_with_libdispatch_queue
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Retrieve the Queue ID for the queue currently using this Thread
comment|///
comment|/// If this Thread is doing work on behalf of a libdispatch/GCD queue,
comment|/// retrieve the QueueID.
comment|///
comment|/// This is a unique identifier for the libdispatch/GCD queue in a
comment|/// process.  Often starting at 1 for the initial system-created
comment|/// queues and incrementing, a QueueID will not be reused for a
comment|/// different queue during the lifetime of a process.
comment|///
comment|/// @return
comment|///     A QueueID if the Thread subclass implements this, else
comment|///     LLDB_INVALID_QUEUE_ID.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|queue_id_t
name|GetQueueID
argument_list|()
block|{
return|return
name|LLDB_INVALID_QUEUE_ID
return|;
block|}
name|virtual
name|void
name|SetQueueID
argument_list|(
name|lldb
operator|::
name|queue_id_t
name|new_val
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Retrieve the Queue name for the queue currently using this Thread
comment|///
comment|/// If this Thread is doing work on behalf of a libdispatch/GCD queue,
comment|/// retrieve the Queue name.
comment|///
comment|/// @return
comment|///     The Queue name, if the Thread subclass implements this, else
comment|///     nullptr.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|char
modifier|*
name|GetQueueName
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|void
name|SetQueueName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Retrieve the Queue kind for the queue currently using this Thread
comment|///
comment|/// If this Thread is doing work on behalf of a libdispatch/GCD queue,
comment|/// retrieve the Queue kind - either eQueueKindSerial or
comment|/// eQueueKindConcurrent, indicating that this queue processes work
comment|/// items serially or concurrently.
comment|///
comment|/// @return
comment|///     The Queue kind, if the Thread subclass implements this, else
comment|///     eQueueKindUnknown.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|QueueKind
name|GetQueueKind
argument_list|()
block|{
return|return
name|lldb
operator|::
name|eQueueKindUnknown
return|;
block|}
name|virtual
name|void
name|SetQueueKind
argument_list|(
name|lldb
operator|::
name|QueueKind
name|kind
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Retrieve the Queue for this thread, if any.
comment|///
comment|/// @return
comment|///     A QueueSP for the queue that is currently associated with this
comment|///     thread.
comment|///     An empty shared pointer indicates that this thread is not
comment|///     associated with a queue, or libdispatch queues are not
comment|///     supported on this target.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|QueueSP
name|GetQueue
argument_list|()
block|{
return|return
name|lldb
operator|::
name|QueueSP
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Retrieve the address of the libdispatch_queue_t struct for queue
comment|/// currently using this Thread
comment|///
comment|/// If this Thread is doing work on behalf of a libdispatch/GCD queue,
comment|/// retrieve the address of the libdispatch_queue_t structure describing
comment|/// the queue.
comment|///
comment|/// This address may be reused for different queues later in the Process
comment|/// lifetime and should not be used to identify a queue uniquely.  Use
comment|/// the GetQueueID() call for that.
comment|///
comment|/// @return
comment|///     The Queue's libdispatch_queue_t address if the Thread subclass
comment|///     implements this, else LLDB_INVALID_ADDRESS.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetQueueLibdispatchQueueAddress
argument_list|()
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
name|virtual
name|void
name|SetQueueLibdispatchQueueAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|dispatch_queue_t
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Whether this Thread already has all the Queue information cached or not
comment|///
comment|/// A Thread may be associated with a libdispatch work Queue at a given
comment|/// public stop event.  If so, the thread can satisify requests like
comment|/// GetQueueLibdispatchQueueAddress, GetQueueKind, GetQueueName, and
comment|/// GetQueueID
comment|/// either from information from the remote debug stub when it is initially
comment|/// created, or it can query the SystemRuntime for that information.
comment|///
comment|/// This method allows the SystemRuntime to discover if a thread has this
comment|/// information already, instead of calling the thread to get the information
comment|/// and having the thread call the SystemRuntime again.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|ThreadHasQueueInformation
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|uint32_t
name|GetStackFrameCount
parameter_list|()
block|{
return|return
name|GetStackFrameList
argument_list|()
operator|->
name|GetNumFrames
argument_list|()
return|;
block|}
name|virtual
name|lldb
operator|::
name|StackFrameSP
name|GetStackFrameAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
block|{
return|return
name|GetStackFrameList
argument_list|()
operator|->
name|GetFrameAtIndex
argument_list|(
name|idx
argument_list|)
return|;
block|}
name|virtual
name|lldb
operator|::
name|StackFrameSP
name|GetFrameWithConcreteFrameIndex
argument_list|(
argument|uint32_t unwind_idx
argument_list|)
expr_stmt|;
name|bool
name|DecrementCurrentInlinedDepth
parameter_list|()
block|{
return|return
name|GetStackFrameList
argument_list|()
operator|->
name|DecrementCurrentInlinedDepth
argument_list|()
return|;
block|}
name|uint32_t
name|GetCurrentInlinedDepth
parameter_list|()
block|{
return|return
name|GetStackFrameList
argument_list|()
operator|->
name|GetCurrentInlinedDepth
argument_list|()
return|;
block|}
name|Error
name|ReturnFromFrameWithIndex
argument_list|(
name|uint32_t
name|frame_idx
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
name|return_value_sp
argument_list|,
name|bool
name|broadcast
operator|=
name|false
argument_list|)
decl_stmt|;
name|Error
name|ReturnFromFrame
argument_list|(
name|lldb
operator|::
name|StackFrameSP
name|frame_sp
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
name|return_value_sp
argument_list|,
name|bool
name|broadcast
operator|=
name|false
argument_list|)
decl_stmt|;
name|Error
name|JumpToLine
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file
argument_list|,
name|uint32_t
name|line
argument_list|,
name|bool
name|can_leave_function
argument_list|,
name|std
operator|::
name|string
operator|*
name|warnings
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|virtual
name|lldb
operator|::
name|StackFrameSP
name|GetFrameWithStackID
argument_list|(
argument|const StackID&stack_id
argument_list|)
block|{
if|if
condition|(
name|stack_id
operator|.
name|IsValid
argument_list|()
condition|)
return|return
name|GetStackFrameList
argument_list|()
operator|->
name|GetFrameWithStackID
argument_list|(
name|stack_id
argument_list|)
return|;
return|return
name|lldb
operator|::
name|StackFrameSP
argument_list|()
return|;
block|}
name|uint32_t
name|GetSelectedFrameIndex
parameter_list|()
block|{
return|return
name|GetStackFrameList
argument_list|()
operator|->
name|GetSelectedFrameIndex
argument_list|()
return|;
block|}
name|lldb
operator|::
name|StackFrameSP
name|GetSelectedFrame
argument_list|()
expr_stmt|;
name|uint32_t
name|SetSelectedFrame
argument_list|(
name|lldb_private
operator|::
name|StackFrame
operator|*
name|frame
argument_list|,
name|bool
name|broadcast
operator|=
name|false
argument_list|)
decl_stmt|;
name|bool
name|SetSelectedFrameByIndex
parameter_list|(
name|uint32_t
name|frame_idx
parameter_list|,
name|bool
name|broadcast
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|SetSelectedFrameByIndexNoisily
parameter_list|(
name|uint32_t
name|frame_idx
parameter_list|,
name|Stream
modifier|&
name|output_stream
parameter_list|)
function_decl|;
name|void
name|SetDefaultFileAndLineToSelectedFrame
parameter_list|()
block|{
name|GetStackFrameList
argument_list|()
operator|->
name|SetDefaultFileAndLineToSelectedFrame
argument_list|()
expr_stmt|;
block|}
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|GetRegisterContext
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrame
argument_list|(
name|StackFrame
operator|*
name|frame
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|ClearStackFrames
parameter_list|()
function_decl|;
name|virtual
name|bool
name|SetBackingThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|lldb
operator|::
name|ThreadSP
name|GetBackingThread
argument_list|()
specifier|const
block|{
return|return
name|lldb
operator|::
name|ThreadSP
argument_list|()
return|;
block|}
name|virtual
name|void
name|ClearBackingThread
parameter_list|()
block|{
comment|// Subclasses can use this function if a thread is actually backed by
comment|// another thread. This is currently used for the OperatingSystem plug-ins
comment|// where they might have a thread that is in memory, yet its registers
comment|// are available through the lldb_private::Thread subclass for the current
comment|// lldb_private::Process class. Since each time the process stops the
comment|// backing
comment|// threads for memory threads can change, we need a way to clear the backing
comment|// thread for all memory threads each time we stop.
block|}
comment|// If stop_format is true, this will be the form used when we print stop info.
comment|// If false, it will be the form we use for thread list and co.
name|void
name|DumpUsingSettingsFormat
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
name|uint32_t
name|frame_idx
parameter_list|,
name|bool
name|stop_format
parameter_list|)
function_decl|;
name|bool
name|GetDescription
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|,
name|bool
name|print_json_thread
argument_list|,
name|bool
name|print_json_stopinfo
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Default implementation for stepping into.
comment|///
comment|/// This function is designed to be used by commands where the
comment|/// process is publicly stopped.
comment|///
comment|/// @param[in] source_step
comment|///     If true and the frame has debug info, then do a source level
comment|///     step in, else do a single instruction step in.
comment|///
comment|/// @param[in] step_in_avoids_code_without_debug_info
comment|///     If \a true, then avoid stepping into code that doesn't have
comment|///     debug info, else step into any code regardless of whether it
comment|///     has debug info.
comment|///
comment|/// @param[in] step_out_avoids_code_without_debug_info
comment|///     If \a true, then if you step out to code with no debug info, keep
comment|///     stepping out till you get to code with debug info.
comment|///
comment|/// @return
comment|///     An error that describes anything that went wrong
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|StepIn
parameter_list|(
name|bool
name|source_step
parameter_list|,
name|LazyBool
name|step_in_avoids_code_without_debug_info
init|=
name|eLazyBoolCalculate
parameter_list|,
name|LazyBool
name|step_out_avoids_code_without_debug_info
init|=
name|eLazyBoolCalculate
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Default implementation for stepping over.
comment|///
comment|/// This function is designed to be used by commands where the
comment|/// process is publicly stopped.
comment|///
comment|/// @param[in] source_step
comment|///     If true and the frame has debug info, then do a source level
comment|///     step over, else do a single instruction step over.
comment|///
comment|/// @return
comment|///     An error that describes anything that went wrong
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|StepOver
parameter_list|(
name|bool
name|source_step
parameter_list|,
name|LazyBool
name|step_out_avoids_code_without_debug_info
init|=
name|eLazyBoolCalculate
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Default implementation for stepping out.
comment|///
comment|/// This function is designed to be used by commands where the
comment|/// process is publicly stopped.
comment|///
comment|/// @return
comment|///     An error that describes anything that went wrong
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|StepOut
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Retrieves the per-thread data area.
comment|/// Most OSs maintain a per-thread pointer (e.g. the FS register on
comment|/// x64), which we return the value of here.
comment|///
comment|/// @return
comment|///     LLDB_INVALID_ADDRESS if not supported, otherwise the thread
comment|///     pointer value.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetThreadPointer
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Retrieves the per-module TLS block for a thread.
comment|///
comment|/// @param[in] module
comment|///     The module to query TLS data for.
comment|///
comment|/// @param[in] tls_file_addr
comment|///     The thread local address in module
comment|/// @return
comment|///     If the thread has TLS data allocated for the
comment|///     module, the address of the TLS block. Otherwise
comment|///     LLDB_INVALID_ADDRESS is returned.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetThreadLocalData
argument_list|(
argument|const lldb::ModuleSP module
argument_list|,
argument|lldb::addr_t tls_file_addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check whether this thread is safe to run functions
comment|///
comment|/// The SystemRuntime may know of certain thread states (functions in
comment|/// process of execution, for instance) which can make it unsafe for
comment|/// functions to be called.
comment|///
comment|/// @return
comment|///     True if it is safe to call functions on this thread.
comment|///     False if function calls should be avoided on this thread.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|SafeToCallFunctions
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Thread Plan Providers:
comment|// This section provides the basic thread plans that the Process control
comment|// machinery uses to run the target.  ThreadPlan.h provides more details on
comment|// how this mechanism works.
comment|// The thread provides accessors to a set of plans that perform basic
comment|// operations.
comment|// The idea is that particular Platform plugins can override these methods to
comment|// provide the implementation of these basic operations appropriate to their
comment|// environment.
comment|//
comment|// NB: All the QueueThreadPlanXXX providers return Shared Pointers to
comment|// Thread plans.  This is useful so that you can modify the plans after
comment|// creation in ways specific to that plan type.  Also, it is often necessary
comment|// for
comment|// ThreadPlans that utilize other ThreadPlans to implement their task to keep
comment|// a shared
comment|// pointer to the sub-plan.
comment|// But besides that, the shared pointers should only be held onto by entities
comment|// who live no longer
comment|// than the thread containing the ThreadPlan.
comment|// FIXME: If this becomes a problem, we can make a version that just returns a
comment|// pointer,
comment|// which it is clearly unsafe to hold onto, and a shared pointer version, and
comment|// only allow
comment|// ThreadPlan and Co. to use the latter.  That is made more annoying to do
comment|// because there's
comment|// no elegant way to friend a method to all sub-classes of a given class.
comment|//
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Queues the base plan for a thread.
comment|/// The version returned by Process does some things that are useful,
comment|/// like handle breakpoints and signals, so if you return a plugin specific
comment|/// one you probably want to call through to the Process one for anything
comment|/// your plugin doesn't explicitly handle.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueFundamentalPlan
argument_list|(
argument|bool abort_other_plans
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Queues the plan used to step one instruction from the current PC of \a
comment|/// thread.
comment|///
comment|/// @param[in] step_over
comment|///    \b true if we step over calls to functions, false if we step in.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @param[in] stop_other_threads
comment|///    \b true if we will stop other threads while we single step this one.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepSingleInstruction
argument_list|(
argument|bool step_over
argument_list|,
argument|bool abort_other_plans
argument_list|,
argument|bool stop_other_threads
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Queues the plan used to step through an address range, stepping  over
comment|/// function calls.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @param[in] type
comment|///    Type of step to do, only eStepTypeInto and eStepTypeOver are supported
comment|///    by this plan.
comment|///
comment|/// @param[in] range
comment|///    The address range to step through.
comment|///
comment|/// @param[in] addr_context
comment|///    When dealing with stepping through inlined functions the current PC is
comment|///    not enough information to know
comment|///    what "step" means.  For instance a series of nested inline functions
comment|///    might start at the same address.
comment|//     The \a addr_context provides the current symbol context the step
comment|///    is supposed to be out of.
comment|//   FIXME: Currently unused.
comment|///
comment|/// @param[in] stop_other_threads
comment|///    \b true if we will stop other threads while we single step this one.
comment|///
comment|/// @param[in] step_out_avoids_code_without_debug_info
comment|///    If eLazyBoolYes, if the step over steps out it will continue to step
comment|///    out till it comes to a frame with debug info.
comment|///    If eLazyBoolCalculate, we will consult the default set in the thread.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepOverRange
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|lldb::RunMode stop_other_threads
argument_list|,
argument|LazyBool step_out_avoids_code_without_debug_info = eLazyBoolCalculate
argument_list|)
expr_stmt|;
comment|// Helper function that takes a LineEntry to step, insted of an AddressRange.
comment|// This may combine multiple
comment|// LineEntries of the same source line number to step over a longer address
comment|// range in a single operation.
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepOverRange
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|const LineEntry&line_entry
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|lldb::RunMode stop_other_threads
argument_list|,
argument|LazyBool step_out_avoids_code_without_debug_info = eLazyBoolCalculate
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Queues the plan used to step through an address range, stepping into
comment|/// functions.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @param[in] type
comment|///    Type of step to do, only eStepTypeInto and eStepTypeOver are supported
comment|///    by this plan.
comment|///
comment|/// @param[in] range
comment|///    The address range to step through.
comment|///
comment|/// @param[in] addr_context
comment|///    When dealing with stepping through inlined functions the current PC is
comment|///    not enough information to know
comment|///    what "step" means.  For instance a series of nested inline functions
comment|///    might start at the same address.
comment|//     The \a addr_context provides the current symbol context the step
comment|///    is supposed to be out of.
comment|//   FIXME: Currently unused.
comment|///
comment|/// @param[in] step_in_target
comment|///    Name if function we are trying to step into.  We will step out if we
comment|///    don't land in that function.
comment|///
comment|/// @param[in] stop_other_threads
comment|///    \b true if we will stop other threads while we single step this one.
comment|///
comment|/// @param[in] step_in_avoids_code_without_debug_info
comment|///    If eLazyBoolYes we will step out if we step into code with no debug
comment|///    info.
comment|///    If eLazyBoolCalculate we will consult the default set in the thread.
comment|///
comment|/// @param[in] step_out_avoids_code_without_debug_info
comment|///    If eLazyBoolYes, if the step over steps out it will continue to step
comment|///    out till it comes to a frame with debug info.
comment|///    If eLazyBoolCalculate, it will consult the default set in the thread.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepInRange
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|const AddressRange&range
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|const char *step_in_target
argument_list|,
argument|lldb::RunMode stop_other_threads
argument_list|,
argument|LazyBool step_in_avoids_code_without_debug_info = eLazyBoolCalculate
argument_list|,
argument|LazyBool step_out_avoids_code_without_debug_info = eLazyBoolCalculate
argument_list|)
expr_stmt|;
comment|// Helper function that takes a LineEntry to step, insted of an AddressRange.
comment|// This may combine multiple
comment|// LineEntries of the same source line number to step over a longer address
comment|// range in a single operation.
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepInRange
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|const LineEntry&line_entry
argument_list|,
argument|const SymbolContext&addr_context
argument_list|,
argument|const char *step_in_target
argument_list|,
argument|lldb::RunMode stop_other_threads
argument_list|,
argument|LazyBool step_in_avoids_code_without_debug_info = eLazyBoolCalculate
argument_list|,
argument|LazyBool step_out_avoids_code_without_debug_info = eLazyBoolCalculate
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Queue the plan used to step out of the function at the current PC of
comment|/// \a thread.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @param[in] addr_context
comment|///    When dealing with stepping through inlined functions the current PC is
comment|///    not enough information to know
comment|///    what "step" means.  For instance a series of nested inline functions
comment|///    might start at the same address.
comment|//     The \a addr_context provides the current symbol context the step
comment|///    is supposed to be out of.
comment|//   FIXME: Currently unused.
comment|///
comment|/// @param[in] first_insn
comment|///     \b true if this is the first instruction of a function.
comment|///
comment|/// @param[in] stop_other_threads
comment|///    \b true if we will stop other threads while we single step this one.
comment|///
comment|/// @param[in] stop_vote
comment|/// @param[in] run_vote
comment|///    See standard meanings for the stop& run votes in ThreadPlan.h.
comment|///
comment|/// @param[in] step_out_avoids_code_without_debug_info
comment|///    If eLazyBoolYes, if the step over steps out it will continue to step
comment|///    out till it comes to a frame with debug info.
comment|///    If eLazyBoolCalculate, it will consult the default set in the thread.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepOut
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|SymbolContext *addr_context
argument_list|,
argument|bool first_insn
argument_list|,
argument|bool stop_other_threads
argument_list|,
argument|Vote stop_vote
argument_list|,
comment|// = eVoteYes,
argument|Vote run_vote
argument_list|,
comment|// = eVoteNoOpinion);
argument|uint32_t frame_idx
argument_list|,
argument|LazyBool step_out_avoids_code_without_debug_info = eLazyBoolCalculate
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Queue the plan used to step out of the function at the current PC of
comment|/// a thread.  This version does not consult the should stop here callback,
comment|/// and should only
comment|/// be used by other thread plans when they need to retain control of the step
comment|/// out.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @param[in] addr_context
comment|///    When dealing with stepping through inlined functions the current PC is
comment|///    not enough information to know
comment|///    what "step" means.  For instance a series of nested inline functions
comment|///    might start at the same address.
comment|//     The \a addr_context provides the current symbol context the step
comment|///    is supposed to be out of.
comment|//   FIXME: Currently unused.
comment|///
comment|/// @param[in] first_insn
comment|///     \b true if this is the first instruction of a function.
comment|///
comment|/// @param[in] stop_other_threads
comment|///    \b true if we will stop other threads while we single step this one.
comment|///
comment|/// @param[in] stop_vote
comment|/// @param[in] run_vote
comment|///    See standard meanings for the stop& run votes in ThreadPlan.h.
comment|///
comment|/// @param[in] continue_to_next_branch
comment|///    Normally this will enqueue a plan that will put a breakpoint on the
comment|///    return address and continue
comment|///    to there.  If continue_to_next_branch is true, this is an operation not
comment|///    involving the user --
comment|///    e.g. stepping "next" in a source line and we instruction stepped into
comment|///    another function --
comment|///    so instead of putting a breakpoint on the return address, advance the
comment|///    breakpoint to the
comment|///    end of the source line that is doing the call, or until the next flow
comment|///    control instruction.
comment|///    If the return value from the function call is to be retrieved /
comment|///    displayed to the user, you must stop
comment|///    on the return address.  The return value may be stored in volatile
comment|///    registers which are overwritten
comment|///    before the next branch instruction.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepOutNoShouldStop
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|SymbolContext *addr_context
argument_list|,
argument|bool first_insn
argument_list|,
argument|bool stop_other_threads
argument_list|,
argument|Vote stop_vote
argument_list|,
comment|// = eVoteYes,
argument|Vote run_vote
argument_list|,
comment|// = eVoteNoOpinion);
argument|uint32_t frame_idx
argument_list|,
argument|bool continue_to_next_branch = false
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the plan used to step through the code that steps from a function
comment|/// call site at the current PC into the actual function call.
comment|///
comment|///
comment|/// @param[in] return_stack_id
comment|///    The stack id that we will return to (by setting backstop breakpoints on
comment|///    the return
comment|///    address to that frame) if we fail to step through.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @param[in] stop_other_threads
comment|///    \b true if we will stop other threads while we single step this one.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepThrough
argument_list|(
argument|StackID&return_stack_id
argument_list|,
argument|bool abort_other_plans
argument_list|,
argument|bool stop_other_threads
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the plan used to continue from the current PC.
comment|/// This is a simple plan, mostly useful as a backstop when you are continuing
comment|/// for some particular purpose.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @param[in] target_addr
comment|///    The address to which we're running.
comment|///
comment|/// @param[in] stop_other_threads
comment|///    \b true if we will stop other threads while we single step this one.
comment|///
comment|/// @return
comment|///     A shared pointer to the newly queued thread plan, or nullptr if the
comment|///     plan could not be queued.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForRunToAddress
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|Address&target_addr
argument_list|,
argument|bool stop_other_threads
argument_list|)
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepUntil
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|lldb::addr_t *address_list
argument_list|,
argument|size_t num_addresses
argument_list|,
argument|bool stop_others
argument_list|,
argument|uint32_t frame_idx
argument_list|)
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|QueueThreadPlanForStepScripted
argument_list|(
argument|bool abort_other_plans
argument_list|,
argument|const char *class_name
argument_list|,
argument|bool stop_other_threads
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Thread Plan accessors:
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Gets the plan which will execute next on the plan stack.
comment|///
comment|/// @return
comment|///     A pointer to the next executed plan.
comment|//------------------------------------------------------------------
name|ThreadPlan
modifier|*
name|GetCurrentPlan
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Unwinds the thread stack for the innermost expression plan currently
comment|/// on the thread plan stack.
comment|///
comment|/// @return
comment|///     An error if the thread plan could not be unwound.
comment|//------------------------------------------------------------------
name|Error
name|UnwindInnermostExpression
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the outer-most plan that was popped off the plan stack in the
comment|/// most recent stop.  Useful for printing the stop reason accurately.
comment|///
comment|/// @return
comment|///     A pointer to the last completed plan.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ThreadPlanSP
name|GetCompletedPlan
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the outer-most return value from the completed plans
comment|///
comment|/// @return
comment|///     A ValueObjectSP, either empty if there is no return value,
comment|///     or containing the return value.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObject
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the outer-most expression variable from the completed plans
comment|///
comment|/// @return
comment|///     A ExpressionVariableSP, either empty if there is no
comment|///     plan completed an expression during the current stop
comment|///     or the expression variable that was made for the completed expression.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ExpressionVariableSP
name|GetExpressionVariable
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|///  Checks whether the given plan is in the completed plans for this
comment|///  stop.
comment|///
comment|/// @param[in] plan
comment|///     Pointer to the plan you're checking.
comment|///
comment|/// @return
comment|///     Returns true if the input plan is in the completed plan stack,
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsThreadPlanDone
parameter_list|(
name|ThreadPlan
modifier|*
name|plan
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|///  Checks whether the given plan is in the discarded plans for this
comment|///  stop.
comment|///
comment|/// @param[in] plan
comment|///     Pointer to the plan you're checking.
comment|///
comment|/// @return
comment|///     Returns true if the input plan is in the discarded plan stack,
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|WasThreadPlanDiscarded
parameter_list|(
name|ThreadPlan
modifier|*
name|plan
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check if we have completed plan to override breakpoint stop reason
comment|///
comment|/// @return
comment|///     Returns true if completed plan stack is not empty
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|CompletedPlanOverridesBreakpoint
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Queues a generic thread plan.
comment|///
comment|/// @param[in] plan_sp
comment|///    The plan to queue.
comment|///
comment|/// @param[in] abort_other_plans
comment|///    \b true if we discard the currently queued plans and replace them with
comment|///    this one.
comment|///    Otherwise this plan will go on the end of the plan stack.
comment|///
comment|/// @return
comment|///     A pointer to the last completed plan.
comment|//------------------------------------------------------------------
name|void
name|QueueThreadPlan
argument_list|(
name|lldb
operator|::
name|ThreadPlanSP
operator|&
name|plan_sp
argument_list|,
name|bool
name|abort_other_plans
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Discards the plans queued on the plan stack of the current thread.  This
comment|/// is
comment|/// arbitrated by the "Master" ThreadPlans, using the "OkayToDiscard" call.
comment|//  But if \a force is true, all thread plans are discarded.
comment|//------------------------------------------------------------------
name|void
name|DiscardThreadPlans
parameter_list|(
name|bool
name|force
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Discards the plans queued on the plan stack of the current thread up to
comment|/// and
comment|/// including up_to_plan_sp.
comment|//
comment|// @param[in] up_to_plan_sp
comment|//   Discard all plans up to and including this one.
comment|//------------------------------------------------------------------
name|void
name|DiscardThreadPlansUpToPlan
argument_list|(
name|lldb
operator|::
name|ThreadPlanSP
operator|&
name|up_to_plan_sp
argument_list|)
decl_stmt|;
name|void
name|DiscardThreadPlansUpToPlan
parameter_list|(
name|ThreadPlan
modifier|*
name|up_to_plan_ptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Discards the plans queued on the plan stack of the current thread up to
comment|/// and
comment|/// including the plan in that matches \a thread_index counting only
comment|/// the non-Private plans.
comment|///
comment|/// @param[in] up_to_plan_sp
comment|///   Discard all plans up to and including this user plan given by this
comment|///   index.
comment|///
comment|/// @return
comment|///    \b true if there was a thread plan with that user index, \b false
comment|///    otherwise.
comment|//------------------------------------------------------------------
name|bool
name|DiscardUserThreadPlansUpToIndex
parameter_list|(
name|uint32_t
name|thread_index
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Prints the current plan stack.
comment|///
comment|/// @param[in] s
comment|///    The stream to which to dump the plan stack info.
comment|///
comment|//------------------------------------------------------------------
name|void
name|DumpThreadPlans
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|desc_level
operator|=
name|lldb
operator|::
name|eDescriptionLevelVerbose
argument_list|,
name|bool
name|include_internal
operator|=
name|true
argument_list|,
name|bool
name|ignore_boring
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|CheckpointThreadState
parameter_list|(
name|ThreadStateCheckpoint
modifier|&
name|saved_state
parameter_list|)
function_decl|;
name|virtual
name|bool
name|RestoreRegisterStateFromCheckpoint
parameter_list|(
name|ThreadStateCheckpoint
modifier|&
name|saved_state
parameter_list|)
function_decl|;
name|virtual
name|bool
name|RestoreThreadStateFromCheckpoint
parameter_list|(
name|ThreadStateCheckpoint
modifier|&
name|saved_state
parameter_list|)
function_decl|;
name|void
name|EnableTracer
parameter_list|(
name|bool
name|value
parameter_list|,
name|bool
name|single_step
parameter_list|)
function_decl|;
name|void
name|SetTracer
argument_list|(
name|lldb
operator|::
name|ThreadPlanTracerSP
operator|&
name|tracer_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Get the thread index ID. The index ID that is guaranteed to not
comment|// be re-used by a process. They start at 1 and increase with each
comment|// new thread. This allows easy command line access by a unique ID
comment|// that is easier to type than the actual system thread ID.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetIndexID
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Get the originating thread's index ID.
comment|// In the case of an "extended" thread -- a thread which represents
comment|// the stack that enqueued/spawned work that is currently executing --
comment|// we need to provide the IndexID of the thread that actually did
comment|// this work.  We don't want to just masquerade as that thread's IndexID
comment|// by using it in our own IndexID because that way leads to madness -
comment|// but the driver program which is iterating over extended threads
comment|// may ask for the OriginatingThreadID to display that information
comment|// to the user.
comment|// Normal threads will return the same thing as GetIndexID();
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetExtendedBacktraceOriginatingIndexID
parameter_list|()
block|{
return|return
name|GetIndexID
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// The API ID is often the same as the Thread::GetID(), but not in
comment|// all cases. Thread::GetID() is the user visible thread ID that
comment|// clients would want to see. The API thread ID is the thread ID
comment|// that is used when sending data to/from the debugging protocol.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|user_id_t
name|GetProtocolID
argument_list|()
specifier|const
block|{
return|return
name|GetID
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// lldb::ExecutionContextScope pure virtual functions
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|CalculateTarget
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ProcessSP
name|CalculateProcess
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
name|override
expr_stmt|;
name|void
name|CalculateExecutionContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
name|override
decl_stmt|;
name|lldb
operator|::
name|StackFrameSP
name|GetStackFrameSPForStackFramePtr
argument_list|(
name|StackFrame
operator|*
name|stack_frame_ptr
argument_list|)
expr_stmt|;
name|size_t
name|GetStatus
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
name|uint32_t
name|start_frame
parameter_list|,
name|uint32_t
name|num_frames
parameter_list|,
name|uint32_t
name|num_frames_with_source
parameter_list|,
name|bool
name|stop_format
parameter_list|)
function_decl|;
name|size_t
name|GetStackFrameStatus
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
name|uint32_t
name|first_frame
parameter_list|,
name|uint32_t
name|num_frames
parameter_list|,
name|bool
name|show_frame_info
parameter_list|,
name|uint32_t
name|num_frames_with_source
parameter_list|)
function_decl|;
comment|// We need a way to verify that even though we have a thread in a shared
comment|// pointer that the object itself is still valid. Currently this won't be
comment|// the case if DestroyThread() was called. DestroyThread is called when
comment|// a thread has been removed from the Process' thread list.
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_destroy_called
return|;
block|}
comment|// Sets and returns a valid stop info based on the process stop ID and the
comment|// current thread plan. If the thread stop ID does not match the process'
comment|// stop ID, the private stop reason is not set and an invalid StopInfoSP may
comment|// be returned.
comment|//
comment|// NOTE: This function must be called before the current thread plan is
comment|// moved to the completed plan stack (in Thread::ShouldStop()).
comment|//
comment|// NOTE: If subclasses override this function, ensure they do not overwrite
comment|// the m_actual_stop_info if it is valid.  The stop info may be a
comment|// "checkpointed and restored" stop info, so if it is still around it is
comment|// right even if you have not calculated this yourself, or if it disagrees
comment|// with what you might have calculated.
name|virtual
name|lldb
operator|::
name|StopInfoSP
name|GetPrivateStopInfo
argument_list|()
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Ask the thread subclass to set its stop info.
comment|//
comment|// Thread subclasses should call Thread::SetStopInfo(...) with the
comment|// reason the thread stopped.
comment|//
comment|// @return
comment|//      True if Thread::SetStopInfo(...) was called, false otherwise.
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|CalculateStopInfo
parameter_list|()
init|=
literal|0
function_decl|;
comment|//----------------------------------------------------------------------
comment|// Gets the temporary resume state for a thread.
comment|//
comment|// This value gets set in each thread by complex debugger logic in
comment|// Thread::ShouldResume() and an appropriate thread resume state will get
comment|// set in each thread every time the process is resumed prior to calling
comment|// Process::DoResume(). The lldb_private::Process subclass should adhere
comment|// to the thread resume state request which will be one of:
comment|//
comment|//  eStateRunning   - thread will resume when process is resumed
comment|//  eStateStepping  - thread should step 1 instruction and stop when process
comment|//                    is resumed
comment|//  eStateSuspended - thread should not execute any instructions when
comment|//                    process is resumed
comment|//----------------------------------------------------------------------
name|lldb
operator|::
name|StateType
name|GetTemporaryResumeState
argument_list|()
specifier|const
block|{
return|return
name|m_temporary_resume_state
return|;
block|}
name|void
name|SetStopInfo
argument_list|(
specifier|const
name|lldb
operator|::
name|StopInfoSP
operator|&
name|stop_info_sp
argument_list|)
decl_stmt|;
name|void
name|ResetStopInfo
parameter_list|()
function_decl|;
name|void
name|SetShouldReportStop
parameter_list|(
name|Vote
name|vote
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Sets the extended backtrace token for this thread
comment|///
comment|/// Some Thread subclasses may maintain a token to help with providing
comment|/// an extended backtrace.  The SystemRuntime plugin will set/request this.
comment|///
comment|/// @param [in] token
comment|//----------------------------------------------------------------------
name|virtual
name|void
name|SetExtendedBacktraceToken
parameter_list|(
name|uint64_t
name|token
parameter_list|)
block|{}
comment|//----------------------------------------------------------------------
comment|/// Gets the extended backtrace token for this thread
comment|///
comment|/// Some Thread subclasses may maintain a token to help with providing
comment|/// an extended backtrace.  The SystemRuntime plugin will set/request this.
comment|///
comment|/// @return
comment|///     The token needed by the SystemRuntime to create an extended backtrace.
comment|///     LLDB_INVALID_ADDRESS is returned if no token is available.
comment|//----------------------------------------------------------------------
name|virtual
name|uint64_t
name|GetExtendedBacktraceToken
parameter_list|()
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
name|protected
label|:
name|friend
name|class
name|ThreadPlan
decl_stmt|;
name|friend
name|class
name|ThreadList
decl_stmt|;
name|friend
name|class
name|ThreadEventData
decl_stmt|;
name|friend
name|class
name|StackFrameList
decl_stmt|;
name|friend
name|class
name|StackFrame
decl_stmt|;
name|friend
name|class
name|OperatingSystem
decl_stmt|;
comment|// This is necessary to make sure thread assets get destroyed while the thread
comment|// is still in good shape
comment|// to call virtual thread methods.  This must be called by classes that derive
comment|// from Thread in their destructor.
name|virtual
name|void
name|DestroyThread
parameter_list|()
function_decl|;
name|void
name|PushPlan
argument_list|(
name|lldb
operator|::
name|ThreadPlanSP
operator|&
name|plan_sp
argument_list|)
decl_stmt|;
name|void
name|PopPlan
parameter_list|()
function_decl|;
name|void
name|DiscardPlan
parameter_list|()
function_decl|;
name|ThreadPlan
modifier|*
name|GetPreviousPlan
parameter_list|(
name|ThreadPlan
modifier|*
name|plan
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ThreadPlanSP
operator|>
name|plan_stack
expr_stmt|;
name|virtual
name|lldb_private
operator|::
name|Unwind
operator|*
name|GetUnwinder
argument_list|()
expr_stmt|;
comment|// Check to see whether the thread is still at the last breakpoint hit that
comment|// stopped it.
name|virtual
name|bool
name|IsStillAtLastBreakpointHit
parameter_list|()
function_decl|;
comment|// Some threads are threads that are made up by OperatingSystem plugins that
comment|// are threads that exist and are context switched out into memory. The
comment|// OperatingSystem plug-in need a ways to know if a thread is "real" or made
comment|// up.
name|virtual
name|bool
name|IsOperatingSystemPluginThread
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// Subclasses that have a way to get an extended info dictionary for this
comment|// thread should
comment|// fill
name|virtual
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|FetchThreadExtendedInfo
argument_list|()
block|{
return|return
name|StructuredData
operator|::
name|ObjectSP
argument_list|()
return|;
block|}
name|lldb
operator|::
name|StackFrameListSP
name|GetStackFrameList
argument_list|()
expr_stmt|;
name|void
name|SetTemporaryResumeState
argument_list|(
name|lldb
operator|::
name|StateType
name|new_state
argument_list|)
block|{
name|m_temporary_resume_state
operator|=
name|new_state
expr_stmt|;
block|}
name|void
name|FunctionOptimizationWarning
argument_list|(
name|lldb_private
operator|::
name|StackFrame
operator|*
name|frame
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Process can see and modify these
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
expr_stmt|;
comment|///< The process that owns this thread.
name|lldb
operator|::
name|StopInfoSP
name|m_stop_info_sp
expr_stmt|;
comment|///< The private stop reason for this thread
name|uint32_t
name|m_stop_info_stop_id
decl_stmt|;
comment|// This is the stop id for which the StopInfo is
comment|// valid.  Can use this so you know that
comment|// the thread's m_stop_info_sp is current and you don't have to fetch it again
name|uint32_t
name|m_stop_info_override_stop_id
decl_stmt|;
comment|// The stop ID containing the last time
comment|// the stop info was checked against
comment|// the stop info override
specifier|const
name|uint32_t
name|m_index_id
decl_stmt|;
comment|///< A unique 1 based index assigned to each thread
comment|///for easy UI/command line access.
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_context_sp
expr_stmt|;
comment|///< The register context for this
comment|///thread's current register state.
name|lldb
operator|::
name|StateType
name|m_state
expr_stmt|;
comment|///< The state of our process.
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_state_mutex
expr_stmt|;
comment|///< Multithreaded protection for m_state.
name|plan_stack
name|m_plan_stack
decl_stmt|;
comment|///< The stack of plans this thread is executing.
name|plan_stack
name|m_completed_plan_stack
decl_stmt|;
comment|///< Plans that have been completed by this
comment|///stop.  They get deleted when the thread
comment|///resumes.
name|plan_stack
name|m_discarded_plan_stack
decl_stmt|;
comment|///< Plans that have been discarded by this
comment|///stop.  They get deleted when the thread
comment|///resumes.
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_frame_mutex
expr_stmt|;
comment|///< Multithreaded protection for m_state.
name|lldb
operator|::
name|StackFrameListSP
name|m_curr_frames_sp
expr_stmt|;
comment|///< The stack frames that get lazily
comment|///populated after a thread stops.
name|lldb
operator|::
name|StackFrameListSP
name|m_prev_frames_sp
expr_stmt|;
comment|///< The previous stack frames from
comment|///the last time this thread stopped.
name|int
name|m_resume_signal
decl_stmt|;
comment|///< The signal that should be used when continuing this
comment|///thread.
name|lldb
operator|::
name|StateType
name|m_resume_state
expr_stmt|;
comment|///< This state is used to force a thread to
comment|///be suspended from outside the ThreadPlan
comment|///logic.
name|lldb
operator|::
name|StateType
name|m_temporary_resume_state
expr_stmt|;
comment|///< This state records what the
comment|///thread was told to do by the
comment|///thread plan logic for the current
comment|///resume.
comment|/// It gets set in Thread::ShouldResume.
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|Unwind
operator|>
name|m_unwinder_ap
expr_stmt|;
name|bool
name|m_destroy_called
decl_stmt|;
comment|// This is used internally to make sure derived Thread
comment|// classes call DestroyThread.
name|LazyBool
name|m_override_should_notify
decl_stmt|;
name|private
label|:
name|bool
name|m_extended_info_fetched
decl_stmt|;
comment|// Have we tried to retrieve the m_extended_info
comment|// for this thread?
name|StructuredData
operator|::
name|ObjectSP
name|m_extended_info
expr_stmt|;
comment|// The extended info for this thread
name|private
label|:
name|bool
name|PlanIsBasePlan
parameter_list|(
name|ThreadPlan
modifier|*
name|plan_ptr
parameter_list|)
function_decl|;
name|void
name|BroadcastSelectedFrameChange
parameter_list|(
name|StackID
modifier|&
name|new_frame_id
parameter_list|)
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Thread
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Thread_h_
end_comment

end_unit

