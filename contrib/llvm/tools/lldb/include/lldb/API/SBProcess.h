begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBProcess.h ---------------------------------------------*- C++ -*-===//
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
name|LLDB_SBProcess_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBProcess_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBError.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBQueue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBTarget.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBEvent
decl_stmt|;
name|class
name|LLDB_API
name|SBProcess
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Broadcaster event bits definitions.
comment|//------------------------------------------------------------------
name|FLAGS_ANONYMOUS_ENUM
argument_list|()
block|{
name|eBroadcastBitStateChanged
operator|=
operator|(
literal|1
operator|<<
literal|0
operator|)
operator|,
name|eBroadcastBitInterrupt
operator|=
operator|(
literal|1
operator|<<
literal|1
operator|)
operator|,
name|eBroadcastBitSTDOUT
operator|=
operator|(
literal|1
operator|<<
literal|2
operator|)
operator|,
name|eBroadcastBitSTDERR
operator|=
operator|(
literal|1
operator|<<
literal|3
operator|)
operator|,
name|eBroadcastBitProfileData
operator|=
operator|(
literal|1
operator|<<
literal|4
operator|)
operator|,
name|eBroadcastBitStructuredData
operator|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|}
empty_stmt|;
name|SBProcess
argument_list|()
expr_stmt|;
name|SBProcess
argument_list|(
specifier|const
name|lldb
operator|::
name|SBProcess
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBProcess
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBProcess
operator|&
name|rhs
operator|)
expr_stmt|;
name|SBProcess
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
expr_stmt|;
operator|~
name|SBProcess
argument_list|()
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetBroadcasterClassName
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetPluginName
parameter_list|()
function_decl|;
comment|// DEPRECATED: use GetPluginName()
specifier|const
name|char
modifier|*
name|GetShortPluginName
parameter_list|()
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBTarget
name|GetTarget
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|PutSTDIN
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|src_len
parameter_list|)
function_decl|;
name|size_t
name|GetSTDOUT
argument_list|(
name|char
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|GetSTDERR
argument_list|(
name|char
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|GetAsyncProfileData
argument_list|(
name|char
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|)
decl|const
decl_stmt|;
name|void
name|ReportEventState
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|,
name|FILE
operator|*
name|out
argument_list|)
decl|const
decl_stmt|;
name|void
name|AppendEventStateReport
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|,
name|lldb
operator|::
name|SBCommandReturnObject
operator|&
name|result
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Remote connection related functions. These will fail if the
comment|/// process is not in eStateConnected. They are intended for use
comment|/// when connecting to an externally managed debugserver instance.
comment|//------------------------------------------------------------------
name|bool
name|RemoteAttachToProcessWithID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|bool
name|RemoteLaunch
argument_list|(
name|char
specifier|const
operator|*
operator|*
name|argv
argument_list|,
name|char
specifier|const
operator|*
operator|*
name|envp
argument_list|,
specifier|const
name|char
operator|*
name|stdin_path
argument_list|,
specifier|const
name|char
operator|*
name|stdout_path
argument_list|,
specifier|const
name|char
operator|*
name|stderr_path
argument_list|,
specifier|const
name|char
operator|*
name|working_directory
argument_list|,
name|uint32_t
name|launch_flags
argument_list|,
name|bool
name|stop_at_entry
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Thread related functions
comment|//------------------------------------------------------------------
name|uint32_t
name|GetNumThreads
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBThread
name|GetThreadAtIndex
argument_list|(
argument|size_t index
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBThread
name|GetThreadByID
argument_list|(
argument|lldb::tid_t sb_thread_id
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBThread
name|GetThreadByIndexID
argument_list|(
argument|uint32_t index_id
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBThread
name|GetSelectedThread
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Function for lazily creating a thread using the current OS
comment|// plug-in. This function will be removed in the future when there
comment|// are APIs to create SBThread objects through the interface and add
comment|// them to the process through the SBProcess API.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBThread
name|CreateOSPluginThread
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|lldb::addr_t context
argument_list|)
expr_stmt|;
name|bool
name|SetSelectedThread
argument_list|(
specifier|const
name|lldb
operator|::
name|SBThread
operator|&
name|thread
argument_list|)
decl_stmt|;
name|bool
name|SetSelectedThreadByID
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
decl_stmt|;
name|bool
name|SetSelectedThreadByIndexID
parameter_list|(
name|uint32_t
name|index_id
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Queue related functions
comment|//------------------------------------------------------------------
name|uint32_t
name|GetNumQueues
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBQueue
name|GetQueueAtIndex
argument_list|(
argument|size_t index
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Stepping related functions
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
expr_stmt|;
name|int
name|GetExitStatus
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetExitDescription
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the process ID
comment|///
comment|/// Returns the process identifier for the process as it is known
comment|/// on the system on which the process is running. For unix systems
comment|/// this is typically the same as if you called "getpid()" in the
comment|/// process.
comment|///
comment|/// @return
comment|///     Returns LLDB_INVALID_PROCESS_ID if this object does not
comment|///     contain a valid process object, or if the process has not
comment|///     been launched. Returns a valid process ID if the process is
comment|///     valid.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|pid_t
name|GetProcessID
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the unique ID associated with this process object
comment|///
comment|/// Unique IDs start at 1 and increment up with each new process
comment|/// instance. Since starting a process on a system might always
comment|/// create a process with the same process ID, there needs to be a
comment|/// way to tell two process instances apart.
comment|///
comment|/// @return
comment|///     Returns a non-zero integer ID if this object contains a
comment|///     valid process object, zero if this object does not contain
comment|///     a valid process object.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetUniqueID
parameter_list|()
function_decl|;
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBError
name|Destroy
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBError
name|Continue
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBError
name|Stop
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBError
name|Kill
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBError
name|Detach
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBError
name|Detach
argument_list|(
argument|bool keep_stopped
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBError
name|Signal
argument_list|(
argument|int signal
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBUnixSignals
name|GetUnixSignals
argument_list|()
expr_stmt|;
name|void
name|SendAsyncInterrupt
parameter_list|()
function_decl|;
name|uint32_t
name|GetStopID
parameter_list|(
name|bool
name|include_expression_stops
init|=
name|false
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the stop event corresponding to stop ID.
comment|//
comment|/// Note that it wasn't fully implemented and tracks only the stop
comment|/// event for the last natural stop ID.
comment|///
comment|/// @param [in] stop_id
comment|///   The ID of the stop event to return.
comment|///
comment|/// @return
comment|///   The stop event corresponding to stop ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBEvent
name|GetStopEventForStopID
argument_list|(
argument|uint32_t stop_id
argument_list|)
expr_stmt|;
name|size_t
name|ReadMemory
argument_list|(
name|addr_t
name|addr
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|size_t
name|WriteMemory
argument_list|(
name|addr_t
name|addr
argument_list|,
specifier|const
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|size_t
name|ReadCStringFromMemory
argument_list|(
name|addr_t
name|addr
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|uint64_t
name|ReadUnsignedFromMemory
argument_list|(
name|addr_t
name|addr
argument_list|,
name|uint32_t
name|byte_size
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|ReadPointerFromMemory
argument_list|(
argument|addr_t addr
argument_list|,
argument|lldb::SBError&error
argument_list|)
expr_stmt|;
comment|// Events
specifier|static
name|lldb
operator|::
name|StateType
name|GetStateFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|GetRestartedFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|GetNumRestartedReasonsFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetRestartedReasonAtIndexFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|,
name|size_t
name|idx
argument_list|)
decl_stmt|;
specifier|static
name|lldb
operator|::
name|SBProcess
name|GetProcessFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|GetInterruptedFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
decl_stmt|;
specifier|static
name|lldb
operator|::
name|SBStructuredData
name|GetStructuredDataFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|EventIsProcessEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|EventIsStructuredDataEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBBroadcaster
name|GetBroadcaster
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetBroadcasterClass
parameter_list|()
function_decl|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Start Tracing with the given SBTraceOptions.
comment|///
comment|/// @param[in] options
comment|///     Class containing trace options like trace buffer size, meta
comment|///     data buffer size, TraceType and any custom parameters
comment|///     {formatted as a JSON Dictionary}. In case of errors in
comment|///     formatting, an error would be reported.
comment|///     It must be noted that tracing options such as buffer sizes
comment|///     or other custom parameters passed maybe invalid for some
comment|///     trace technologies. In such cases the trace implementations
comment|///     could choose to either throw an error or could round off to
comment|///     the nearest valid options to start tracing if the passed
comment|///     value is not supported. To obtain the actual used trace
comment|///     options please use the GetTraceConfig API. For the custom
comment|///     parameters, only the parameters recognized by the target
comment|///     would be used and others would be ignored.
comment|///
comment|/// @param[out] error
comment|///     An error explaining what went wrong.
comment|///
comment|/// @return
comment|///     A SBTrace instance, which should be used
comment|///     to get the trace data or other trace related operations.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBTrace
name|StartTrace
argument_list|(
name|SBTraceOptions
operator|&
name|options
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
expr_stmt|;
name|uint32_t
name|GetNumSupportedHardwareWatchpoints
argument_list|(
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Load a shared library into this process.
comment|///
comment|/// @param[in] remote_image_spec
comment|///     The path for the shared library on the target what you want
comment|///     to load.
comment|///
comment|/// @param[out] error
comment|///     An error object that gets filled in with any errors that
comment|///     might occur when trying to load the shared library.
comment|///
comment|/// @return
comment|///     A token that represents the shared library that can be
comment|///     later used to unload the shared library. A value of
comment|///     LLDB_INVALID_IMAGE_TOKEN will be returned if the shared
comment|///     library can't be opened.
comment|//------------------------------------------------------------------
name|uint32_t
name|LoadImage
argument_list|(
name|lldb
operator|::
name|SBFileSpec
operator|&
name|remote_image_spec
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Load a shared library into this process.
comment|///
comment|/// @param[in] local_image_spec
comment|///     The file spec that points to the shared library that you
comment|///     want to load if the library is located on the host. The
comment|///     library will be copied over to the location specified by
comment|///     remote_image_spec or into the current working directory with
comment|///     the same filename if the remote_image_spec isn't specified.
comment|///
comment|/// @param[in] remote_image_spec
comment|///     If local_image_spec is specified then the location where the
comment|///     library should be copied over from the host. If
comment|///     local_image_spec isn't specified, then the path for the
comment|///     shared library on the target what you want to load.
comment|///
comment|/// @param[out] error
comment|///     An error object that gets filled in with any errors that
comment|///     might occur when trying to load the shared library.
comment|///
comment|/// @return
comment|///     A token that represents the shared library that can be
comment|///     later used to unload the shared library. A value of
comment|///     LLDB_INVALID_IMAGE_TOKEN will be returned if the shared
comment|///     library can't be opened.
comment|//------------------------------------------------------------------
name|uint32_t
name|LoadImage
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|local_image_spec
argument_list|,
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|remote_image_spec
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBError
name|UnloadImage
argument_list|(
argument|uint32_t image_token
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBError
name|SendEventData
argument_list|(
specifier|const
name|char
operator|*
name|data
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the number of different thread-origin extended backtraces
comment|/// this process can support.
comment|///
comment|/// When the process is stopped and you have an SBThread, lldb may be
comment|/// able to show a backtrace of when that thread was originally created,
comment|/// or the work item was enqueued to it (in the case of a libdispatch
comment|/// queue).
comment|///
comment|/// @return
comment|///   The number of thread-origin extended backtrace types that may be
comment|///   available.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetNumExtendedBacktraceTypes
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return the name of one of the thread-origin extended backtrace
comment|/// methods.
comment|///
comment|/// @param [in] idx
comment|///   The index of the name to return.  They will be returned in
comment|///   the order that the user will most likely want to see them.
comment|///   e.g. if the type at index 0 is not available for a thread,
comment|///   see if the type at index 1 provides an extended backtrace.
comment|///
comment|/// @return
comment|///   The name at that index.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetExtendedBacktraceTypeAtIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|)
function_decl|;
name|lldb
operator|::
name|SBThreadCollection
name|GetHistoryThreads
argument_list|(
argument|addr_t addr
argument_list|)
expr_stmt|;
name|bool
name|IsInstrumentationRuntimePresent
parameter_list|(
name|InstrumentationRuntimeType
name|type
parameter_list|)
function_decl|;
comment|/// Save the state of the process in a core file (or mini dump on Windows).
name|lldb
operator|::
name|SBError
name|SaveCore
argument_list|(
specifier|const
name|char
operator|*
name|file_name
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Query the address load_addr and store the details of the memory
comment|/// region that contains it in the supplied SBMemoryRegionInfo object.
comment|/// To iterate over all memory regions use GetMemoryRegionList.
comment|///
comment|/// @param[in] load_addr
comment|///     The address to be queried.
comment|///
comment|/// @param[out] region_info
comment|///     A reference to an SBMemoryRegionInfo object that will contain
comment|///     the details of the memory region containing load_addr.
comment|///
comment|/// @return
comment|///     An error object describes any errors that occurred while
comment|///     querying load_addr.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBError
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb::SBMemoryRegionInfo&region_info
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the list of memory regions within the process.
comment|///
comment|/// @return
comment|///     A list of all witin the process memory regions.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBMemoryRegionInfoList
name|GetMemoryRegions
argument_list|()
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBAddress
decl_stmt|;
name|friend
name|class
name|SBBreakpoint
decl_stmt|;
name|friend
name|class
name|SBBreakpointLocation
decl_stmt|;
name|friend
name|class
name|SBCommandInterpreter
decl_stmt|;
name|friend
name|class
name|SBDebugger
decl_stmt|;
name|friend
name|class
name|SBExecutionContext
decl_stmt|;
name|friend
name|class
name|SBFunction
decl_stmt|;
name|friend
name|class
name|SBModule
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|friend
name|class
name|SBThread
decl_stmt|;
name|friend
name|class
name|SBValue
decl_stmt|;
name|friend
name|class
name|lldb_private
operator|::
name|QueueImpl
expr_stmt|;
name|lldb
operator|::
name|ProcessSP
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ProcessWP
name|m_opaque_wp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBProcess_h_
end_comment

end_unit

