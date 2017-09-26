begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessMonitor.h -------------------------------------- -*- C++ -*-===//
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
name|liblldb_ProcessMonitor_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessMonitor_H_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<semaphore.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Scalar
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End lldb_private namespace.
end_comment

begin_decl_stmt
name|class
name|ProcessFreeBSD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|Operation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @class ProcessMonitor
end_comment

begin_comment
comment|/// @brief Manages communication with the inferior (debugee) process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Upon construction, this class prepares and launches an inferior process for
end_comment

begin_comment
comment|/// debugging.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Changes in the inferior process state are propagated to the associated
end_comment

begin_comment
comment|/// ProcessFreeBSD instance by calling ProcessFreeBSD::SendMessage with the
end_comment

begin_comment
comment|/// appropriate ProcessMessage events.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A purposely minimal set of operations are provided to interrogate and change
end_comment

begin_comment
comment|/// the inferior process state.
end_comment

begin_decl_stmt
name|class
name|ProcessMonitor
block|{
name|public
label|:
comment|/// Launches an inferior process ready for debugging.  Forms the
comment|/// implementation of Process::DoLaunch.
name|ProcessMonitor
argument_list|(
name|ProcessFreeBSD
operator|*
name|process
argument_list|,
name|lldb_private
operator|::
name|Module
operator|*
name|module
argument_list|,
name|char
specifier|const
operator|*
name|argv
index|[]
argument_list|,
name|char
specifier|const
operator|*
name|envp
index|[]
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|stdin_file_spec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|stdout_file_spec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|stderr_file_spec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|working_dir
argument_list|,
specifier|const
name|lldb_private
operator|::
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
expr_stmt|;
name|ProcessMonitor
argument_list|(
argument|ProcessFreeBSD *process
argument_list|,
argument|lldb::pid_t pid
argument_list|,
argument|lldb_private::Status&error
argument_list|)
empty_stmt|;
operator|~
name|ProcessMonitor
argument_list|()
expr_stmt|;
comment|/// Provides the process number of debugee.
name|lldb
operator|::
name|pid_t
name|GetPID
argument_list|()
specifier|const
block|{
return|return
name|m_pid
return|;
block|}
comment|/// Returns the process associated with this ProcessMonitor.
name|ProcessFreeBSD
modifier|&
name|GetProcess
parameter_list|()
block|{
return|return
operator|*
name|m_process
return|;
block|}
comment|/// Returns a file descriptor to the controlling terminal of the inferior
comment|/// process.
comment|///
comment|/// Reads from this file descriptor yield both the standard output and
comment|/// standard error of this debugee.  Even if stderr and stdout were
comment|/// redirected on launch it may still happen that data is available on this
comment|/// descriptor (if the inferior process opens /dev/tty, for example). This
comment|/// descriptor is
comment|/// closed after a call to StopMonitor().
comment|///
comment|/// If this monitor was attached to an existing process this method returns
comment|/// -1.
name|int
name|GetTerminalFD
argument_list|()
specifier|const
block|{
return|return
name|m_terminal_fd
return|;
block|}
comment|/// Reads @p size bytes from address @vm_adder in the inferior process
comment|/// address space.
comment|///
comment|/// This method is provided to implement Process::DoReadMemory.
name|size_t
name|ReadMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
comment|/// Writes @p size bytes from address @p vm_adder in the inferior process
comment|/// address space.
comment|///
comment|/// This method is provided to implement Process::DoWriteMemory.
name|size_t
name|WriteMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
specifier|const
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
comment|/// Reads the contents from the register identified by the given (architecture
comment|/// dependent) offset.
comment|///
comment|/// This method is provided for use by RegisterContextFreeBSD derivatives.
name|bool
name|ReadRegisterValue
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|unsigned
name|offset
argument_list|,
specifier|const
name|char
operator|*
name|reg_name
argument_list|,
name|unsigned
name|size
argument_list|,
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
comment|/// Writes the given value to the register identified by the given
comment|/// (architecture dependent) offset.
comment|///
comment|/// This method is provided for use by RegisterContextFreeBSD derivatives.
name|bool
name|WriteRegisterValue
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|unsigned
name|offset
argument_list|,
specifier|const
name|char
operator|*
name|reg_name
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
comment|/// Reads the contents from the debug register identified by the given
comment|/// (architecture dependent) offset.
comment|///
comment|/// This method is provided for use by RegisterContextFreeBSD derivatives.
name|bool
name|ReadDebugRegisterValue
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|unsigned
name|offset
argument_list|,
specifier|const
name|char
operator|*
name|reg_name
argument_list|,
name|unsigned
name|size
argument_list|,
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
comment|/// Writes the given value to the debug register identified by the given
comment|/// (architecture dependent) offset.
comment|///
comment|/// This method is provided for use by RegisterContextFreeBSD derivatives.
name|bool
name|WriteDebugRegisterValue
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|unsigned
name|offset
argument_list|,
specifier|const
name|char
operator|*
name|reg_name
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
comment|/// Reads all general purpose registers into the specified buffer.
name|bool
name|ReadGPR
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|buf_size
argument_list|)
decl_stmt|;
comment|/// Reads all floating point registers into the specified buffer.
name|bool
name|ReadFPR
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|buf_size
argument_list|)
decl_stmt|;
comment|/// Reads the specified register set into the specified buffer.
comment|///
comment|/// This method is provided for use by RegisterContextFreeBSD derivatives.
name|bool
name|ReadRegisterSet
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|buf_size
argument_list|,
name|unsigned
name|int
name|regset
argument_list|)
decl_stmt|;
comment|/// Writes all general purpose registers into the specified buffer.
name|bool
name|WriteGPR
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|buf_size
argument_list|)
decl_stmt|;
comment|/// Writes all floating point registers into the specified buffer.
name|bool
name|WriteFPR
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|buf_size
argument_list|)
decl_stmt|;
comment|/// Writes the specified register set into the specified buffer.
comment|///
comment|/// This method is provided for use by RegisterContextFreeBSD derivatives.
name|bool
name|WriteRegisterSet
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|buf_size
argument_list|,
name|unsigned
name|int
name|regset
argument_list|)
decl_stmt|;
comment|/// Reads the value of the thread-specific pointer for a given thread ID.
name|bool
name|ReadThreadPointer
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|value
argument_list|)
decl_stmt|;
comment|/// Returns current thread IDs in process
name|size_t
name|GetCurrentThreadIDs
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|tid_t
operator|>
operator|&
name|thread_ids
argument_list|)
decl_stmt|;
comment|/// Writes a ptrace_lwpinfo structure corresponding to the given thread ID
comment|/// to the memory region pointed to by @p lwpinfo.
name|bool
name|GetLwpInfo
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|void
operator|*
name|lwpinfo
argument_list|,
name|int
operator|&
name|error_no
argument_list|)
decl_stmt|;
comment|/// Suspends or unsuspends a thread prior to process resume or step.
name|bool
name|ThreadSuspend
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|bool
name|suspend
argument_list|)
decl_stmt|;
comment|/// Writes the raw event message code (vis-a-vis PTRACE_GETEVENTMSG)
comment|/// corresponding to the given thread IDto the memory pointed to by @p
comment|/// message.
name|bool
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
comment|/// Resumes the process.  If @p signo is anything but
comment|/// LLDB_INVALID_SIGNAL_NUMBER, deliver that signal to the process.
name|bool
name|Resume
argument_list|(
name|lldb
operator|::
name|tid_t
name|unused
argument_list|,
name|uint32_t
name|signo
argument_list|)
decl_stmt|;
comment|/// Single steps the process.  If @p signo is anything but
comment|/// LLDB_INVALID_SIGNAL_NUMBER, deliver that signal to the process.
name|bool
name|SingleStep
argument_list|(
name|lldb
operator|::
name|tid_t
name|unused
argument_list|,
name|uint32_t
name|signo
argument_list|)
decl_stmt|;
comment|/// Terminate the traced process.
name|bool
name|Kill
parameter_list|()
function_decl|;
name|lldb_private
operator|::
name|Status
name|Detach
argument_list|(
argument|lldb::tid_t tid
argument_list|)
expr_stmt|;
name|void
name|StopMonitor
parameter_list|()
function_decl|;
comment|// Waits for the initial stop message from a new thread.
name|bool
name|WaitForInitialTIDStop
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
decl_stmt|;
name|private
label|:
name|ProcessFreeBSD
modifier|*
name|m_process
decl_stmt|;
name|lldb_private
operator|::
name|HostThread
name|m_operation_thread
expr_stmt|;
name|lldb_private
operator|::
name|HostThread
name|m_monitor_thread
expr_stmt|;
name|lldb
operator|::
name|pid_t
name|m_pid
expr_stmt|;
name|int
name|m_terminal_fd
decl_stmt|;
comment|// current operation which must be executed on the privileged thread
name|Operation
modifier|*
name|m_operation
decl_stmt|;
name|std
operator|::
name|mutex
name|m_operation_mutex
expr_stmt|;
comment|// semaphores notified when Operation is ready to be processed and when
comment|// the operation is complete.
name|sem_t
name|m_operation_pending
decl_stmt|;
name|sem_t
name|m_operation_done
decl_stmt|;
struct|struct
name|OperationArgs
block|{
name|OperationArgs
argument_list|(
name|ProcessMonitor
operator|*
name|monitor
argument_list|)
expr_stmt|;
operator|~
name|OperationArgs
argument_list|()
expr_stmt|;
name|ProcessMonitor
modifier|*
name|m_monitor
decl_stmt|;
comment|// The monitor performing the attach.
name|sem_t
name|m_semaphore
decl_stmt|;
comment|// Posted to once operation complete.
name|lldb_private
operator|::
name|Status
name|m_error
expr_stmt|;
comment|// Set if process operation failed.
block|}
struct|;
comment|/// @class LauchArgs
comment|///
comment|/// @brief Simple structure to pass data to the thread responsible for
comment|/// launching a child process.
name|struct
name|LaunchArgs
range|:
name|OperationArgs
block|{
name|LaunchArgs
argument_list|(
name|ProcessMonitor
operator|*
name|monitor
argument_list|,
name|lldb_private
operator|::
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
name|lldb_private
operator|::
name|FileSpec
operator|&
name|stdin_file_spec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|stdout_file_spec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|stderr_file_spec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|working_dir
argument_list|)
block|;
operator|~
name|LaunchArgs
argument_list|()
block|;
name|lldb_private
operator|::
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
name|lldb_private
operator|::
name|FileSpec
name|m_stdin_file_spec
block|;
comment|// Redirect stdin or empty.
specifier|const
name|lldb_private
operator|::
name|FileSpec
name|m_stdout_file_spec
block|;
comment|// Redirect stdout or empty.
specifier|const
name|lldb_private
operator|::
name|FileSpec
name|m_stderr_file_spec
block|;
comment|// Redirect stderr or empty.
specifier|const
name|lldb_private
operator|::
name|FileSpec
name|m_working_dir
block|;
comment|// Working directory or empty.
block|}
decl_stmt|;
name|void
name|StartLaunchOpThread
argument_list|(
name|LaunchArgs
operator|*
name|args
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
specifier|static
name|void
modifier|*
name|LaunchOpThread
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
specifier|static
name|bool
name|Launch
parameter_list|(
name|LaunchArgs
modifier|*
name|args
parameter_list|)
function_decl|;
name|struct
name|AttachArgs
range|:
name|OperationArgs
block|{
name|AttachArgs
argument_list|(
argument|ProcessMonitor *monitor
argument_list|,
argument|lldb::pid_t pid
argument_list|)
block|;
operator|~
name|AttachArgs
argument_list|()
block|;
name|lldb
operator|::
name|pid_t
name|m_pid
block|;
comment|// pid of the process to be attached.
block|}
decl_stmt|;
name|void
name|StartAttachOpThread
argument_list|(
name|AttachArgs
operator|*
name|args
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
specifier|static
name|void
modifier|*
name|AttachOpThread
parameter_list|(
name|void
modifier|*
name|args
parameter_list|)
function_decl|;
specifier|static
name|void
name|Attach
parameter_list|(
name|AttachArgs
modifier|*
name|args
parameter_list|)
function_decl|;
specifier|static
name|void
name|ServeOperation
parameter_list|(
name|OperationArgs
modifier|*
name|args
parameter_list|)
function_decl|;
specifier|static
name|bool
name|DupDescriptor
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|,
name|int
name|fd
argument_list|,
name|int
name|flags
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|MonitorCallback
argument_list|(
name|ProcessMonitor
operator|*
name|monitor
argument_list|,
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
specifier|static
name|ProcessMessage
name|MonitorSIGTRAP
argument_list|(
name|ProcessMonitor
operator|*
name|monitor
argument_list|,
specifier|const
name|siginfo_t
operator|*
name|info
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
specifier|static
name|ProcessMessage
name|MonitorSignal
argument_list|(
name|ProcessMonitor
operator|*
name|monitor
argument_list|,
specifier|const
name|siginfo_t
operator|*
name|info
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
name|void
name|DoOperation
parameter_list|(
name|Operation
modifier|*
name|op
parameter_list|)
function_decl|;
comment|/// Stops the child monitor thread.
name|void
name|StopMonitoringChildProcess
parameter_list|()
function_decl|;
comment|/// Stops the operation thread used to attach/launch a process.
name|void
name|StopOpThread
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_ProcessMonitor_H_
end_comment

end_unit

