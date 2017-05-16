begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeProcessDarwin.h --------------------------------- -*- C++ -*-===//
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
name|NativeProcessDarwin_h
end_ifndef

begin_define
define|#
directive|define
name|NativeProcessDarwin_h
end_define

begin_comment
comment|// NOTE: this code should only be compiled on Apple Darwin systems.  It is
end_comment

begin_comment
comment|// not cross-platform code and is not intended to build on any other platform.
end_comment

begin_comment
comment|// Therefore, platform-specific headers and code are okay here.
end_comment

begin_comment
comment|// C includes
end_comment

begin_include
include|#
directive|include
file|<mach/mach_types.h>
end_include

begin_comment
comment|// C++ includes
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<unordered_set>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Debug.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Pipe.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeProcessProtocol.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/MemoryRegionInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"LaunchFlavor.h"
end_include

begin_include
include|#
directive|include
file|"MachException.h"
end_include

begin_include
include|#
directive|include
file|"NativeThreadDarwin.h"
end_include

begin_include
include|#
directive|include
file|"NativeThreadListDarwin.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
name|class
name|Scalar
decl_stmt|;
name|namespace
name|process_darwin
block|{
comment|/// @class NativeProcessDarwin
comment|/// @brief Manages communication with the inferior (debugee) process.
comment|///
comment|/// Upon construction, this class prepares and launches an inferior
comment|/// process for debugging.
comment|///
comment|/// Changes in the inferior process state are broadcasted.
name|class
name|NativeProcessDarwin
range|:
name|public
name|NativeProcessProtocol
block|{
name|friend
name|Status
name|NativeProcessProtocol
operator|::
name|Launch
argument_list|(
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|NativeDelegate
operator|&
name|native_delegate
argument_list|,
name|MainLoop
operator|&
name|mainloop
argument_list|,
name|NativeProcessProtocolSP
operator|&
name|process_sp
argument_list|)
block|;
name|friend
name|Status
name|NativeProcessProtocol
operator|::
name|Attach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|NativeProcessProtocol::NativeDelegate&native_delegate
argument_list|,
argument|MainLoop&mainloop
argument_list|,
argument|NativeProcessProtocolSP&process_sp
argument_list|)
block|;
name|public
operator|:
operator|~
name|NativeProcessDarwin
argument_list|()
name|override
block|;
comment|// -----------------------------------------------------------------
comment|// NativeProcessProtocol Interface
comment|// -----------------------------------------------------------------
name|Status
name|Resume
argument_list|(
argument|const ResumeActionList&resume_actions
argument_list|)
name|override
block|;
name|Status
name|Halt
argument_list|()
name|override
block|;
name|Status
name|Detach
argument_list|()
name|override
block|;
name|Status
name|Signal
argument_list|(
argument|int signo
argument_list|)
name|override
block|;
name|Status
name|Interrupt
argument_list|()
name|override
block|;
name|Status
name|Kill
argument_list|()
name|override
block|;
name|Status
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|MemoryRegionInfo&range_info
argument_list|)
name|override
block|;
name|Status
name|ReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|size_t&bytes_read
argument_list|)
name|override
block|;
name|Status
name|ReadMemoryWithoutTrap
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|size_t&bytes_read
argument_list|)
name|override
block|;
name|Status
name|WriteMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|size_t&bytes_written
argument_list|)
name|override
block|;
name|Status
name|AllocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|lldb::addr_t&addr
argument_list|)
name|override
block|;
name|Status
name|DeallocateMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetSharedLibraryInfoAddress
argument_list|()
name|override
block|;
name|size_t
name|UpdateThreads
argument_list|()
name|override
block|;
name|bool
name|GetArchitecture
argument_list|(
argument|ArchSpec&arch
argument_list|)
specifier|const
name|override
block|;
name|Status
name|SetBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|uint32_t size
argument_list|,
argument|bool hardware
argument_list|)
name|override
block|;
name|void
name|DoStopIDBumped
argument_list|(
argument|uint32_t newBumpId
argument_list|)
name|override
block|;
name|Status
name|GetLoadedModuleFileSpec
argument_list|(
argument|const char *module_path
argument_list|,
argument|FileSpec&file_spec
argument_list|)
name|override
block|;
name|Status
name|GetFileLoadAddress
argument_list|(
argument|const llvm::StringRef&file_name
argument_list|,
argument|lldb::addr_t&load_addr
argument_list|)
name|override
block|;
name|NativeThreadDarwinSP
name|GetThreadByID
argument_list|(
argument|lldb::tid_t id
argument_list|)
block|;
name|task_t
name|GetTask
argument_list|()
specifier|const
block|{
return|return
name|m_task
return|;
block|}
comment|// -----------------------------------------------------------------
comment|// Interface used by NativeRegisterContext-derived classes.
comment|// -----------------------------------------------------------------
specifier|static
name|Status
name|PtraceWrapper
argument_list|(
argument|int req
argument_list|,
argument|lldb::pid_t pid
argument_list|,
argument|void *addr = nullptr
argument_list|,
argument|void *data = nullptr
argument_list|,
argument|size_t data_size =
literal|0
argument_list|,
argument|long *result = nullptr
argument_list|)
block|;
name|bool
name|SupportHardwareSingleStepping
argument_list|()
specifier|const
block|;
name|protected
operator|:
comment|// -----------------------------------------------------------------
comment|// NativeProcessProtocol protected interface
comment|// -----------------------------------------------------------------
name|Status
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
argument|size_t trap_opcode_size_hint
argument_list|,
argument|size_t&actual_opcode_size
argument_list|,
argument|const uint8_t *&trap_opcode_bytes
argument_list|)
name|override
block|;
name|private
operator|:
comment|// -----------------------------------------------------------------
comment|/// Mach task-related Member Variables
comment|// -----------------------------------------------------------------
comment|// The task port for the inferior process.
name|mutable
name|task_t
name|m_task
block|;
comment|// True if the inferior process did an exec since we started
comment|// monitoring it.
name|bool
name|m_did_exec
block|;
comment|// The CPU type of this process.
name|mutable
name|cpu_type_t
name|m_cpu_type
block|;
comment|// -----------------------------------------------------------------
comment|/// Exception/Signal Handling Member Variables
comment|// -----------------------------------------------------------------
comment|// Exception port on which we will receive child exceptions
name|mach_port_t
name|m_exception_port
block|;
comment|// Saved state of the child exception port prior to us installing
comment|// our own intercepting port.
name|MachException
operator|::
name|PortInfo
name|m_exc_port_info
block|;
comment|// The thread that runs the Mach exception read and reply handler.
name|pthread_t
name|m_exception_thread
block|;
comment|// TODO see if we can remove this if we get the exception collection
comment|// and distribution to happen in a single-threaded fashion.
name|std
operator|::
name|recursive_mutex
name|m_exception_messages_mutex
block|;
comment|// A collection of exception messages caught when listening to the
comment|// exception port.
name|MachException
operator|::
name|Message
operator|::
name|collection
name|m_exception_messages
block|;
comment|// When we call MachProcess::Interrupt(), we want to send this
comment|// signal (if non-zero).
name|int
name|m_sent_interrupt_signo
block|;
comment|// If we resume the process and still haven't received our
comment|// interrupt signal (if this is non-zero).
name|int
name|m_auto_resume_signo
block|;
comment|// -----------------------------------------------------------------
comment|/// Thread-related Member Variables
comment|// -----------------------------------------------------------------
name|NativeThreadListDarwin
name|m_thread_list
block|;
name|ResumeActionList
name|m_thread_actions
block|;
comment|// -----------------------------------------------------------------
comment|/// Process Lifetime Member Variable
comment|// -----------------------------------------------------------------
comment|// The pipe over which the waitpid thread and the main loop will
comment|// communicate.
name|Pipe
name|m_waitpid_pipe
block|;
comment|// The thread that runs the waitpid handler.
name|pthread_t
name|m_waitpid_thread
block|;
comment|// waitpid reader callback handle.
name|MainLoop
operator|::
name|ReadHandleUP
name|m_waitpid_reader_handle
block|;
if|#
directive|if
literal|0
block|ArchSpec m_arch;              LazyBool m_supports_mem_region;             std::vector<MemoryRegionInfo> m_mem_region_cache;              lldb::tid_t m_pending_notification_tid;
comment|// List of thread ids stepping with a breakpoint with the address of
comment|// the relevan breakpoint
block|std::map<lldb::tid_t, lldb::addr_t>             m_threads_stepping_with_breakpoint;
endif|#
directive|endif
comment|// -----------------------------------------------------------------
comment|// Private Instance Methods
comment|// -----------------------------------------------------------------
name|NativeProcessDarwin
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|int pty_master_fd
argument_list|)
block|;
comment|// -----------------------------------------------------------------
comment|/// Finalize the launch.
comment|///
comment|/// This method associates the NativeProcessDarwin instance with
comment|/// the host process that was just launched.  It peforms actions
comment|/// like attaching a listener to the inferior exception port,
comment|/// ptracing the process, and the like.
comment|///
comment|/// @param[in] launch_flavor
comment|///     The launch flavor that was used to launch the process.
comment|///
comment|/// @param[in] main_loop
comment|///     The main loop that will run the process monitor.  Work
comment|///     that needs to be done (e.g. reading files) gets registered
comment|///     here along with callbacks to process the work.
comment|///
comment|/// @return
comment|///     Any error that occurred during the aforementioned
comment|///     operations.  Failure here will force termination of the
comment|///     launched process and debugging session.
comment|// -----------------------------------------------------------------
name|Status
name|FinalizeLaunch
argument_list|(
argument|LaunchFlavor launch_flavor
argument_list|,
argument|MainLoop&main_loop
argument_list|)
block|;
name|Status
name|SaveExceptionPortInfo
argument_list|()
block|;
name|void
name|ExceptionMessageReceived
argument_list|(
specifier|const
name|MachException
operator|::
name|Message
operator|&
name|message
argument_list|)
block|;
name|void
name|MaybeRaiseThreadPriority
argument_list|()
block|;
name|Status
name|StartExceptionThread
argument_list|()
block|;
name|Status
name|SendInferiorExitStatusToMainLoop
argument_list|(
argument|::pid_t pid
argument_list|,
argument|int status
argument_list|)
block|;
name|Status
name|HandleWaitpidResult
argument_list|()
block|;
name|bool
name|ProcessUsingSpringBoard
argument_list|()
specifier|const
block|;
name|bool
name|ProcessUsingBackBoard
argument_list|()
specifier|const
block|;
specifier|static
name|void
operator|*
name|ExceptionThread
argument_list|(
name|void
operator|*
name|arg
argument_list|)
block|;
name|void
operator|*
name|DoExceptionThread
argument_list|()
block|;
name|lldb
operator|::
name|addr_t
name|GetDYLDAllImageInfosAddress
argument_list|(
argument|Status&error
argument_list|)
specifier|const
block|;
specifier|static
name|uint32_t
name|GetCPUTypeForLocalProcess
argument_list|(
argument|::pid_t pid
argument_list|)
block|;
name|uint32_t
name|GetCPUType
argument_list|()
specifier|const
block|;
name|task_t
name|ExceptionMessageBundleComplete
argument_list|()
block|;
name|void
name|StartSTDIOThread
argument_list|()
block|;
name|Status
name|StartWaitpidThread
argument_list|(
name|MainLoop
operator|&
name|main_loop
argument_list|)
block|;
specifier|static
name|void
operator|*
name|WaitpidThread
argument_list|(
name|void
operator|*
name|arg
argument_list|)
block|;
name|void
operator|*
name|DoWaitpidThread
argument_list|()
block|;
name|task_t
name|TaskPortForProcessID
argument_list|(
argument|Status&error
argument_list|,
argument|bool force = false
argument_list|)
specifier|const
block|;
comment|/// Attaches to an existing process.  Forms the
comment|/// implementation of Process::DoAttach.
name|void
name|AttachToInferior
argument_list|(
argument|MainLoop&mainloop
argument_list|,
argument|lldb::pid_t pid
argument_list|,
argument|Status&error
argument_list|)
block|;
operator|::
name|pid_t
name|Attach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|Status&error
argument_list|)
block|;
name|Status
name|PrivateResume
argument_list|()
block|;
name|Status
name|ReplyToAllExceptions
argument_list|()
block|;
name|Status
name|ResumeTask
argument_list|()
block|;
name|bool
name|IsTaskValid
argument_list|()
specifier|const
block|;
name|bool
name|IsTaskValid
argument_list|(
argument|task_t task
argument_list|)
specifier|const
block|;
name|mach_port_t
name|GetExceptionPort
argument_list|()
specifier|const
block|;
name|bool
name|IsExceptionPortValid
argument_list|()
specifier|const
block|;
name|Status
name|GetTaskBasicInfo
argument_list|(
argument|task_t task
argument_list|,
argument|struct task_basic_info *info
argument_list|)
specifier|const
block|;
name|Status
name|SuspendTask
argument_list|()
block|;
specifier|static
name|Status
name|SetDefaultPtraceOpts
argument_list|(
specifier|const
name|lldb
operator|::
name|pid_t
argument_list|)
block|;
specifier|static
name|void
operator|*
name|MonitorThread
argument_list|(
name|void
operator|*
name|baton
argument_list|)
block|;
name|void
name|MonitorCallback
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|bool exited
argument_list|,
argument|int signal
argument_list|,
argument|int status
argument_list|)
block|;
name|void
name|WaitForNewThread
argument_list|(
argument|::pid_t tid
argument_list|)
block|;
name|void
name|MonitorSIGTRAP
argument_list|(
specifier|const
name|siginfo_t
operator|&
name|info
argument_list|,
name|NativeThreadDarwin
operator|&
name|thread
argument_list|)
block|;
name|void
name|MonitorTrace
argument_list|(
name|NativeThreadDarwin
operator|&
name|thread
argument_list|)
block|;
name|void
name|MonitorBreakpoint
argument_list|(
name|NativeThreadDarwin
operator|&
name|thread
argument_list|)
block|;
name|void
name|MonitorWatchpoint
argument_list|(
argument|NativeThreadDarwin&thread
argument_list|,
argument|uint32_t wp_index
argument_list|)
block|;
name|void
name|MonitorSignal
argument_list|(
argument|const siginfo_t&info
argument_list|,
argument|NativeThreadDarwin&thread
argument_list|,
argument|bool exited
argument_list|)
block|;
name|Status
name|SetupSoftwareSingleStepping
argument_list|(
name|NativeThreadDarwin
operator|&
name|thread
argument_list|)
block|;
if|#
directive|if
literal|0
block|static ::ProcessMessage::CrashReason             GetCrashReasonForSIGSEGV(const siginfo_t *info);              static ::ProcessMessage::CrashReason             GetCrashReasonForSIGILL(const siginfo_t *info);              static ::ProcessMessage::CrashReason             GetCrashReasonForSIGFPE(const siginfo_t *info);              static ::ProcessMessage::CrashReason             GetCrashReasonForSIGBUS(const siginfo_t *info);
endif|#
directive|endif
name|bool
name|HasThreadNoLock
argument_list|(
argument|lldb::tid_t thread_id
argument_list|)
block|;
name|bool
name|StopTrackingThread
argument_list|(
argument|lldb::tid_t thread_id
argument_list|)
block|;
name|NativeThreadDarwinSP
name|AddThread
argument_list|(
argument|lldb::tid_t thread_id
argument_list|)
block|;
name|Status
name|GetSoftwareBreakpointPCOffset
argument_list|(
name|uint32_t
operator|&
name|actual_opcode_size
argument_list|)
block|;
name|Status
name|FixupBreakpointPCAsNeeded
argument_list|(
name|NativeThreadDarwin
operator|&
name|thread
argument_list|)
block|;
comment|/// Writes a siginfo_t structure corresponding to the given thread
comment|/// ID to the memory region pointed to by @p siginfo.
name|Status
name|GetSignalInfo
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|void *siginfo
argument_list|)
block|;
comment|/// Writes the raw event message code (vis-a-vis PTRACE_GETEVENTMSG)
comment|/// corresponding to the given thread ID to the memory pointed to
comment|/// by @p message.
name|Status
name|GetEventMessage
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|unsigned long *message
argument_list|)
block|;
name|void
name|NotifyThreadDeath
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|Status
name|Detach
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
comment|// This method is requests a stop on all threads which are still
comment|// running. It sets up a deferred delegate notification, which will
comment|// fire once threads report as stopped. The triggerring_tid will be
comment|// set as the current thread (main stop reason).
name|void
name|StopRunningThreads
argument_list|(
argument|lldb::tid_t triggering_tid
argument_list|)
block|;
comment|// Notify the delegate if all threads have stopped.
name|void
name|SignalIfAllThreadsStopped
argument_list|()
block|;
comment|// Resume the given thread, optionally passing it the given signal.
comment|// The type of resume operation (continue, single-step) depends on
comment|// the state parameter.
name|Status
name|ResumeThread
argument_list|(
argument|NativeThreadDarwin&thread
argument_list|,
argument|lldb::StateType state
argument_list|,
argument|int signo
argument_list|)
block|;
name|void
name|ThreadWasCreated
argument_list|(
name|NativeThreadDarwin
operator|&
name|thread
argument_list|)
block|;
name|void
name|SigchldHandler
argument_list|()
block|; }
decl_stmt|;
block|}
comment|// namespace process_darwin
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
comment|/* NativeProcessDarwin_h */
end_comment

end_unit

