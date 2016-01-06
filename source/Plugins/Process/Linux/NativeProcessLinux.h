begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeProcessLinux.h ---------------------------------- -*- C++ -*-===//
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
name|liblldb_NativeProcessLinux_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeProcessLinux_H_
end_define

begin_comment
comment|// C++ Includes
end_comment

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
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Debug.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/MemoryRegionInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeProcessProtocol.h"
end_include

begin_include
include|#
directive|include
file|"NativeThreadLinux.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Error
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Scalar
decl_stmt|;
name|namespace
name|process_linux
block|{
comment|/// @class NativeProcessLinux
comment|/// @brief Manages communication with the inferior (debugee) process.
comment|///
comment|/// Upon construction, this class prepares and launches an inferior process for
comment|/// debugging.
comment|///
comment|/// Changes in the inferior process state are broadcasted.
name|class
name|NativeProcessLinux
range|:
name|public
name|NativeProcessProtocol
block|{
name|friend
name|Error
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
name|Error
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
comment|// ---------------------------------------------------------------------
comment|// NativeProcessProtocol Interface
comment|// ---------------------------------------------------------------------
name|Error
name|Resume
argument_list|(
argument|const ResumeActionList&resume_actions
argument_list|)
name|override
block|;
name|Error
name|Halt
argument_list|()
name|override
block|;
name|Error
name|Detach
argument_list|()
name|override
block|;
name|Error
name|Signal
argument_list|(
argument|int signo
argument_list|)
name|override
block|;
name|Error
name|Interrupt
argument_list|()
name|override
block|;
name|Error
name|Kill
argument_list|()
name|override
block|;
name|Error
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|MemoryRegionInfo&range_info
argument_list|)
name|override
block|;
name|Error
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
name|Error
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
name|Error
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
name|Error
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
name|Error
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
name|Error
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
name|Error
name|GetLoadedModuleFileSpec
argument_list|(
argument|const char* module_path
argument_list|,
argument|FileSpec& file_spec
argument_list|)
name|override
block|;
name|Error
name|GetFileLoadAddress
argument_list|(
argument|const llvm::StringRef& file_name
argument_list|,
argument|lldb::addr_t& load_addr
argument_list|)
name|override
block|;
name|NativeThreadLinuxSP
name|GetThreadByID
argument_list|(
argument|lldb::tid_t id
argument_list|)
block|;
comment|// ---------------------------------------------------------------------
comment|// Interface used by NativeRegisterContext-derived classes.
comment|// ---------------------------------------------------------------------
specifier|static
name|Error
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
name|protected
operator|:
comment|// ---------------------------------------------------------------------
comment|// NativeProcessProtocol protected interface
comment|// ---------------------------------------------------------------------
name|Error
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
name|MainLoop
operator|::
name|SignalHandleUP
name|m_sigchld_handle
block|;
name|ArchSpec
name|m_arch
block|;
name|LazyBool
name|m_supports_mem_region
block|;
name|std
operator|::
name|vector
operator|<
name|MemoryRegionInfo
operator|>
name|m_mem_region_cache
block|;
name|Mutex
name|m_mem_region_cache_mutex
block|;
name|lldb
operator|::
name|tid_t
name|m_pending_notification_tid
block|;
comment|// List of thread ids stepping with a breakpoint with the address of
comment|// the relevan breakpoint
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|tid_t
block|,
name|lldb
operator|::
name|addr_t
operator|>
name|m_threads_stepping_with_breakpoint
block|;
comment|/// @class LauchArgs
comment|///
comment|/// @brief Simple structure to pass data to the thread responsible for
comment|/// launching a child process.
block|struct
name|LaunchArgs
block|{
name|LaunchArgs
argument_list|(
name|Module
operator|*
name|module
argument_list|,
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
name|FileSpec
operator|&
name|stdin_file_spec
argument_list|,
specifier|const
name|FileSpec
operator|&
name|stdout_file_spec
argument_list|,
specifier|const
name|FileSpec
operator|&
name|stderr_file_spec
argument_list|,
specifier|const
name|FileSpec
operator|&
name|working_dir
argument_list|,
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
operator|~
name|LaunchArgs
argument_list|()
block|;
name|Module
operator|*
name|m_module
block|;
comment|// The executable image to launch.
name|char
specifier|const
operator|*
operator|*
name|m_argv
block|;
comment|// Process arguments.
name|char
specifier|const
operator|*
operator|*
name|m_envp
block|;
comment|// Process environment.
specifier|const
name|FileSpec
name|m_stdin_file_spec
block|;
comment|// Redirect stdin if not empty.
specifier|const
name|FileSpec
name|m_stdout_file_spec
block|;
comment|// Redirect stdout if not empty.
specifier|const
name|FileSpec
name|m_stderr_file_spec
block|;
comment|// Redirect stderr if not empty.
specifier|const
name|FileSpec
name|m_working_dir
block|;
comment|// Working directory or empty.
specifier|const
name|ProcessLaunchInfo
operator|&
name|m_launch_info
block|;         }
block|;
typedef|typedef
name|std
operator|::
name|function
operator|<
operator|::
name|pid_t
argument_list|(
name|Error
operator|&
argument_list|)
operator|>
name|InitialOperation
expr_stmt|;
comment|// ---------------------------------------------------------------------
comment|// Private Instance Methods
comment|// ---------------------------------------------------------------------
name|NativeProcessLinux
argument_list|()
decl_stmt|;
comment|/// Launches an inferior process ready for debugging.  Forms the
comment|/// implementation of Process::DoLaunch.
name|void
name|LaunchInferior
parameter_list|(
name|MainLoop
modifier|&
name|mainloop
parameter_list|,
name|Module
modifier|*
name|module
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|,
name|char
specifier|const
modifier|*
name|envp
index|[]
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|stdin_file_spec
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|stdout_file_spec
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|stderr_file_spec
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|working_dir
parameter_list|,
specifier|const
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
comment|/// Attaches to an existing process.  Forms the
comment|/// implementation of Process::DoAttach
name|void
name|AttachToInferior
argument_list|(
name|MainLoop
operator|&
name|mainloop
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
operator|::
name|pid_t
name|Launch
argument_list|(
name|LaunchArgs
operator|*
name|args
argument_list|,
name|Error
operator|&
name|error
argument_list|)
expr_stmt|;
operator|::
name|pid_t
name|Attach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|Error&error
argument_list|)
expr_stmt|;
specifier|static
name|Error
name|SetDefaultPtraceOpts
argument_list|(
specifier|const
name|lldb
operator|::
name|pid_t
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|DupDescriptor
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file_spec
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
specifier|static
name|void
modifier|*
name|MonitorThread
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|void
name|MonitorCallback
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|bool
name|exited
argument_list|,
name|int
name|signal
argument_list|,
name|int
name|status
argument_list|)
decl_stmt|;
name|void
name|WaitForNewThread
argument_list|(
operator|::
name|pid_t
name|tid
argument_list|)
decl_stmt|;
name|void
name|MonitorSIGTRAP
parameter_list|(
specifier|const
name|siginfo_t
modifier|&
name|info
parameter_list|,
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|)
function_decl|;
name|void
name|MonitorTrace
parameter_list|(
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|)
function_decl|;
name|void
name|MonitorBreakpoint
parameter_list|(
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|)
function_decl|;
name|void
name|MonitorWatchpoint
parameter_list|(
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|,
name|uint32_t
name|wp_index
parameter_list|)
function_decl|;
name|void
name|MonitorSignal
parameter_list|(
specifier|const
name|siginfo_t
modifier|&
name|info
parameter_list|,
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|,
name|bool
name|exited
parameter_list|)
function_decl|;
name|bool
name|SupportHardwareSingleStepping
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|SetupSoftwareSingleStepping
parameter_list|(
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|)
function_decl|;
if|#
directive|if
literal|0
block|static ::ProcessMessage::CrashReason         GetCrashReasonForSIGSEGV(const siginfo_t *info);          static ::ProcessMessage::CrashReason         GetCrashReasonForSIGILL(const siginfo_t *info);          static ::ProcessMessage::CrashReason         GetCrashReasonForSIGFPE(const siginfo_t *info);          static ::ProcessMessage::CrashReason         GetCrashReasonForSIGBUS(const siginfo_t *info);
endif|#
directive|endif
name|bool
name|HasThreadNoLock
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
decl_stmt|;
name|bool
name|StopTrackingThread
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
decl_stmt|;
name|NativeThreadLinuxSP
name|AddThread
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
decl_stmt|;
name|Error
name|GetSoftwareBreakpointPCOffset
parameter_list|(
name|uint32_t
modifier|&
name|actual_opcode_size
parameter_list|)
function_decl|;
name|Error
name|FixupBreakpointPCAsNeeded
parameter_list|(
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|)
function_decl|;
comment|/// Writes a siginfo_t structure corresponding to the given thread ID to the
comment|/// memory region pointed to by @p siginfo.
name|Error
name|GetSignalInfo
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|siginfo
argument_list|)
decl_stmt|;
comment|/// Writes the raw event message code (vis-a-vis PTRACE_GETEVENTMSG)
comment|/// corresponding to the given thread ID to the memory pointed to by @p
comment|/// message.
name|Error
name|GetEventMessage
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|unsigned
name|long
operator|*
name|message
argument_list|)
decl_stmt|;
comment|/// Resumes the given thread.  If @p signo is anything but
comment|/// LLDB_INVALID_SIGNAL_NUMBER, deliver that signal to the thread.
name|Error
name|Resume
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|uint32_t
name|signo
argument_list|)
decl_stmt|;
comment|/// Single steps the given thread.  If @p signo is anything but
comment|/// LLDB_INVALID_SIGNAL_NUMBER, deliver that signal to the thread.
name|Error
name|SingleStep
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|uint32_t
name|signo
argument_list|)
decl_stmt|;
name|void
name|NotifyThreadDeath
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
decl_stmt|;
name|Error
name|Detach
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
decl_stmt|;
comment|// This method is requests a stop on all threads which are still running. It sets up a
comment|// deferred delegate notification, which will fire once threads report as stopped. The
comment|// triggerring_tid will be set as the current thread (main stop reason).
name|void
name|StopRunningThreads
argument_list|(
name|lldb
operator|::
name|tid_t
name|triggering_tid
argument_list|)
decl_stmt|;
comment|// Notify the delegate if all threads have stopped.
name|void
name|SignalIfAllThreadsStopped
parameter_list|()
function_decl|;
comment|// Resume the given thread, optionally passing it the given signal. The type of resume
comment|// operation (continue, single-step) depends on the state parameter.
name|Error
name|ResumeThread
argument_list|(
name|NativeThreadLinux
operator|&
name|thread
argument_list|,
name|lldb
operator|::
name|StateType
name|state
argument_list|,
name|int
name|signo
argument_list|)
decl_stmt|;
name|void
name|ThreadWasCreated
parameter_list|(
name|NativeThreadLinux
modifier|&
name|thread
parameter_list|)
function_decl|;
name|void
name|SigchldHandler
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace process_linux
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_NativeProcessLinux_H_
end_comment

end_unit

