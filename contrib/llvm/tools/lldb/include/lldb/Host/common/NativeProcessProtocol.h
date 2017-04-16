begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeProcessProtocol.h ---------------------------------*- C++ -*-===//
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
name|liblldb_NativeProcessProtocol_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeProcessProtocol_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/MainLoop.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"NativeBreakpointList.h"
end_include

begin_include
include|#
directive|include
file|"NativeWatchpointList.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|MemoryRegionInfo
decl_stmt|;
name|class
name|ResumeActionList
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// NativeProcessProtocol
comment|//------------------------------------------------------------------
name|class
name|NativeProcessProtocol
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|NativeProcessProtocol
operator|>
block|{
name|friend
name|class
name|SoftwareBreakpoint
block|;
name|public
operator|:
name|virtual
operator|~
name|NativeProcessProtocol
argument_list|()
block|{}
name|virtual
name|Error
name|Resume
argument_list|(
specifier|const
name|ResumeActionList
operator|&
name|resume_actions
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Error
name|Halt
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|Error
name|Detach
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Sends a process a UNIX signal \a signal.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|Signal
argument_list|(
argument|int signo
argument_list|)
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Tells a process to interrupt all operations as if by a Ctrl-C.
comment|///
comment|/// The default implementation will send a local host's equivalent of
comment|/// a SIGSTOP to the process via the NativeProcessProtocol::Signal()
comment|/// operation.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|Interrupt
argument_list|()
block|;
name|virtual
name|Error
name|Kill
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|// Tells a process not to stop the inferior on given signals
comment|// and just reinject them back.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|IgnoreSignals
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|int
operator|>
name|signals
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Memory and memory region functions
comment|//----------------------------------------------------------------------
name|virtual
name|Error
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|MemoryRegionInfo&range_info
argument_list|)
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|Error
name|AllocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|lldb::addr_t&addr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Error
name|DeallocateMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetSharedLibraryInfoAddress
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsAlive
argument_list|()
specifier|const
block|;
name|virtual
name|size_t
name|UpdateThreads
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetArchitecture
argument_list|(
argument|ArchSpec&arch
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// Breakpoint functions
comment|//----------------------------------------------------------------------
name|virtual
name|Error
name|SetBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|uint32_t size
argument_list|,
argument|bool hardware
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Error
name|RemoveBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|bool hardware = false
argument_list|)
block|;
name|virtual
name|Error
name|EnableBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
name|virtual
name|Error
name|DisableBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Hardware Breakpoint functions
comment|//----------------------------------------------------------------------
name|virtual
specifier|const
name|HardwareBreakpointMap
operator|&
name|GetHardwareBreakpointMap
argument_list|()
specifier|const
block|;
name|virtual
name|Error
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|virtual
name|Error
name|RemoveHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Watchpoint functions
comment|//----------------------------------------------------------------------
name|virtual
specifier|const
name|NativeWatchpointList
operator|::
name|WatchpointMap
operator|&
name|GetWatchpointMap
argument_list|()
specifier|const
block|;
name|virtual
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|pair
operator|<
name|uint32_t
block|,
name|uint32_t
operator|>>
name|GetHardwareDebugSupportInfo
argument_list|()
specifier|const
block|;
name|virtual
name|Error
name|SetWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|,
argument|bool hardware
argument_list|)
block|;
name|virtual
name|Error
name|RemoveWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Accessors
comment|//----------------------------------------------------------------------
name|lldb
operator|::
name|pid_t
name|GetID
argument_list|()
specifier|const
block|{
return|return
name|m_pid
return|;
block|}
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
specifier|const
block|;
name|bool
name|IsRunning
argument_list|()
specifier|const
block|{
return|return
name|m_state
operator|==
name|lldb
operator|::
name|eStateRunning
operator|||
name|IsStepping
argument_list|()
return|;
block|}
name|bool
name|IsStepping
argument_list|()
specifier|const
block|{
return|return
name|m_state
operator|==
name|lldb
operator|::
name|eStateStepping
return|;
block|}
name|bool
name|CanResume
argument_list|()
specifier|const
block|{
return|return
name|m_state
operator|==
name|lldb
operator|::
name|eStateStopped
return|;
block|}
name|bool
name|GetByteOrder
argument_list|(
argument|lldb::ByteOrder&byte_order
argument_list|)
specifier|const
block|;
name|virtual
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>>
name|GetAuxvData
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// Exit Status
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|GetExitStatus
argument_list|(
name|lldb_private
operator|::
name|ExitType
operator|*
name|exit_type
argument_list|,
name|int
operator|*
name|status
argument_list|,
name|std
operator|::
name|string
operator|&
name|exit_description
argument_list|)
block|;
name|virtual
name|bool
name|SetExitStatus
argument_list|(
argument|lldb_private::ExitType exit_type
argument_list|,
argument|int status
argument_list|,
argument|const char *exit_description
argument_list|,
argument|bool bNotifyStateChange
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Access to threads
comment|//----------------------------------------------------------------------
name|NativeThreadProtocolSP
name|GetThreadAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
block|;
name|NativeThreadProtocolSP
name|GetThreadByID
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|void
name|SetCurrentThreadID
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|{
name|m_current_thread_id
operator|=
name|tid
block|; }
name|lldb
operator|::
name|tid_t
name|GetCurrentThreadID
argument_list|()
block|{
return|return
name|m_current_thread_id
return|;
block|}
name|NativeThreadProtocolSP
name|GetCurrentThread
argument_list|()
block|{
return|return
name|GetThreadByID
argument_list|(
name|m_current_thread_id
argument_list|)
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// Access to inferior stdio
comment|//----------------------------------------------------------------------
name|virtual
name|int
name|GetTerminalFileDescriptor
argument_list|()
block|{
return|return
name|m_terminal_fd
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// Stop id interface
comment|//----------------------------------------------------------------------
name|uint32_t
name|GetStopID
argument_list|()
specifier|const
block|;
comment|// ---------------------------------------------------------------------
comment|// Callbacks for low-level process state changes
comment|// ---------------------------------------------------------------------
name|class
name|NativeDelegate
block|{
name|public
operator|:
name|virtual
operator|~
name|NativeDelegate
argument_list|()
block|{}
name|virtual
name|void
name|InitializeDelegate
argument_list|(
name|NativeProcessProtocol
operator|*
name|process
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|ProcessStateChanged
argument_list|(
argument|NativeProcessProtocol *process
argument_list|,
argument|lldb::StateType state
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|DidExec
argument_list|(
name|NativeProcessProtocol
operator|*
name|process
argument_list|)
operator|=
literal|0
block|;   }
block|;
comment|//------------------------------------------------------------------
comment|/// Register a native delegate.
comment|///
comment|/// Clients can register nofication callbacks by passing in a
comment|/// NativeDelegate impl and passing it into this function.
comment|///
comment|/// Note: it is required that the lifetime of the
comment|/// native_delegate outlive the NativeProcessProtocol.
comment|///
comment|/// @param[in] native_delegate
comment|///     A NativeDelegate impl to be called when certain events
comment|///     happen within the NativeProcessProtocol or related threads.
comment|///
comment|/// @return
comment|///     true if the delegate was registered successfully;
comment|///     false if the delegate was already registered.
comment|///
comment|/// @see NativeProcessProtocol::NativeDelegate.
comment|//------------------------------------------------------------------
name|bool
name|RegisterNativeDelegate
argument_list|(
name|NativeDelegate
operator|&
name|native_delegate
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Unregister a native delegate previously registered.
comment|///
comment|/// @param[in] native_delegate
comment|///     A NativeDelegate impl previously registered with this process.
comment|///
comment|/// @return Returns \b true if the NativeDelegate was
comment|/// successfully removed from the process, \b false otherwise.
comment|///
comment|/// @see NativeProcessProtocol::NativeDelegate
comment|//------------------------------------------------------------------
name|bool
name|UnregisterNativeDelegate
argument_list|(
name|NativeDelegate
operator|&
name|native_delegate
argument_list|)
block|;
name|virtual
name|Error
name|GetLoadedModuleFileSpec
argument_list|(
specifier|const
name|char
operator|*
name|module_path
argument_list|,
name|FileSpec
operator|&
name|file_spec
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Error
name|GetFileLoadAddress
argument_list|(
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|file_name
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|load_addr
argument_list|)
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Launch a process for debugging. This method will create an concrete
comment|/// instance of NativeProcessProtocol, based on the host platform.
comment|/// (e.g. NativeProcessLinux on linux, etc.)
comment|///
comment|/// @param[in] launch_info
comment|///     Information required to launch the process.
comment|///
comment|/// @param[in] native_delegate
comment|///     The delegate that will receive messages regarding the
comment|///     inferior.  Must outlive the NativeProcessProtocol
comment|///     instance.
comment|///
comment|/// @param[in] mainloop
comment|///     The mainloop instance with which the process can register
comment|///     callbacks. Must outlive the NativeProcessProtocol
comment|///     instance.
comment|///
comment|/// @param[out] process_sp
comment|///     On successful return from the method, this parameter
comment|///     contains the shared pointer to the
comment|///     NativeProcessProtocol that can be used to manipulate
comment|///     the native process.
comment|///
comment|/// @return
comment|///     An error object indicating if the operation succeeded,
comment|///     and if not, what error occurred.
comment|//------------------------------------------------------------------
specifier|static
name|Error
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
comment|//------------------------------------------------------------------
comment|/// Attach to an existing process. This method will create an concrete
comment|/// instance of NativeProcessProtocol, based on the host platform.
comment|/// (e.g. NativeProcessLinux on linux, etc.)
comment|///
comment|/// @param[in] pid
comment|///     pid of the process locatable
comment|///
comment|/// @param[in] native_delegate
comment|///     The delegate that will receive messages regarding the
comment|///     inferior.  Must outlive the NativeProcessProtocol
comment|///     instance.
comment|///
comment|/// @param[in] mainloop
comment|///     The mainloop instance with which the process can register
comment|///     callbacks. Must outlive the NativeProcessProtocol
comment|///     instance.
comment|///
comment|/// @param[out] process_sp
comment|///     On successful return from the method, this parameter
comment|///     contains the shared pointer to the
comment|///     NativeProcessProtocol that can be used to manipulate
comment|///     the native process.
comment|///
comment|/// @return
comment|///     An error object indicating if the operation succeeded,
comment|///     and if not, what error occurred.
comment|//------------------------------------------------------------------
specifier|static
name|Error
name|Attach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|NativeDelegate&native_delegate
argument_list|,
argument|MainLoop&mainloop
argument_list|,
argument|NativeProcessProtocolSP&process_sp
argument_list|)
block|;
name|protected
operator|:
name|lldb
operator|::
name|pid_t
name|m_pid
block|;
name|std
operator|::
name|vector
operator|<
name|NativeThreadProtocolSP
operator|>
name|m_threads
block|;
name|lldb
operator|::
name|tid_t
name|m_current_thread_id
block|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_threads_mutex
block|;
name|lldb
operator|::
name|StateType
name|m_state
block|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_state_mutex
block|;
name|lldb_private
operator|::
name|ExitType
name|m_exit_type
block|;
name|int
name|m_exit_status
block|;
name|std
operator|::
name|string
name|m_exit_description
block|;
name|std
operator|::
name|recursive_mutex
name|m_delegates_mutex
block|;
name|std
operator|::
name|vector
operator|<
name|NativeDelegate
operator|*
operator|>
name|m_delegates
block|;
name|NativeBreakpointList
name|m_breakpoint_list
block|;
name|NativeWatchpointList
name|m_watchpoint_list
block|;
name|HardwareBreakpointMap
name|m_hw_breakpoints_map
block|;
name|int
name|m_terminal_fd
block|;
name|uint32_t
name|m_stop_id
block|;
comment|// Set of signal numbers that LLDB directly injects back to inferior
comment|// without stopping it.
name|llvm
operator|::
name|DenseSet
operator|<
name|int
operator|>
name|m_signals_to_ignore
block|;
comment|// lldb_private::Host calls should be used to launch a process for debugging,
comment|// and
comment|// then the process should be attached to. When attaching to a process
comment|// lldb_private::Host calls should be used to locate the process to attach to,
comment|// and then this function should be called.
name|NativeProcessProtocol
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|;
comment|// -----------------------------------------------------------
comment|// Internal interface for state handling
comment|// -----------------------------------------------------------
name|void
name|SetState
argument_list|(
argument|lldb::StateType state
argument_list|,
argument|bool notify_delegates = true
argument_list|)
block|;
comment|// Derived classes need not implement this.  It can be used as a
comment|// hook to clear internal caches that should be invalidated when
comment|// stop ids change.
comment|//
comment|// Note this function is called with the state mutex obtained
comment|// by the caller.
name|virtual
name|void
name|DoStopIDBumped
argument_list|(
argument|uint32_t newBumpId
argument_list|)
block|;
comment|// -----------------------------------------------------------
comment|// Internal interface for software breakpoints
comment|// -----------------------------------------------------------
name|Error
name|SetSoftwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|uint32_t size_hint
argument_list|)
block|;
name|virtual
name|Error
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
argument|size_t trap_opcode_size_hint
argument_list|,
argument|size_t&actual_opcode_size
argument_list|,
argument|const uint8_t *&trap_opcode_bytes
argument_list|)
operator|=
literal|0
block|;
comment|// -----------------------------------------------------------
comment|/// Notify the delegate that an exec occurred.
comment|///
comment|/// Provide a mechanism for a delegate to clear out any exec-
comment|/// sensitive data.
comment|// -----------------------------------------------------------
name|void
name|NotifyDidExec
argument_list|()
block|;
name|NativeThreadProtocolSP
name|GetThreadByIDUnlocked
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
comment|// -----------------------------------------------------------
comment|// Static helper methods for derived classes.
comment|// -----------------------------------------------------------
specifier|static
name|Error
name|ResolveProcessArchitecture
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|ArchSpec&arch
argument_list|)
block|;
name|private
operator|:
name|void
name|SynchronouslyNotifyProcessStateChanged
argument_list|(
argument|lldb::StateType state
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_NativeProcessProtocol_h_
end_comment

end_unit

