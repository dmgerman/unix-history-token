begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DebuggerThread.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_DebuggerThread_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_DebuggerThread_H_
end_define

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|"ForwardDecl.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostProcess.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/windows/windows.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// DebuggerThread
comment|//
comment|// Debugs a single process, notifying listeners as appropriate when interesting
comment|// things occur.
comment|//----------------------------------------------------------------------
name|class
name|DebuggerThread
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|DebuggerThread
operator|>
block|{
name|public
operator|:
name|DebuggerThread
argument_list|(
argument|DebugDelegateSP debug_delegate
argument_list|)
block|;
name|virtual
operator|~
name|DebuggerThread
argument_list|()
block|;
name|Status
name|DebugLaunch
argument_list|(
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
name|Status
name|DebugAttach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|const ProcessAttachInfo&attach_info
argument_list|)
block|;
name|HostProcess
name|GetProcess
argument_list|()
specifier|const
block|{
return|return
name|m_process
return|;
block|}
name|HostThread
name|GetMainThread
argument_list|()
specifier|const
block|{
return|return
name|m_main_thread
return|;
block|}
name|std
operator|::
name|weak_ptr
operator|<
name|ExceptionRecord
operator|>
name|GetActiveException
argument_list|()
block|{
return|return
name|m_active_exception
return|;
block|}
name|Status
name|StopDebugging
argument_list|(
argument|bool terminate
argument_list|)
block|;
name|void
name|ContinueAsyncException
argument_list|(
argument|ExceptionResult result
argument_list|)
block|;
name|private
operator|:
name|void
name|FreeProcessHandles
argument_list|()
block|;
name|void
name|DebugLoop
argument_list|()
block|;
name|ExceptionResult
name|HandleExceptionEvent
argument_list|(
argument|const EXCEPTION_DEBUG_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleCreateThreadEvent
argument_list|(
argument|const CREATE_THREAD_DEBUG_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleCreateProcessEvent
argument_list|(
argument|const CREATE_PROCESS_DEBUG_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleExitThreadEvent
argument_list|(
argument|const EXIT_THREAD_DEBUG_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleExitProcessEvent
argument_list|(
argument|const EXIT_PROCESS_DEBUG_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleLoadDllEvent
argument_list|(
argument|const LOAD_DLL_DEBUG_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleUnloadDllEvent
argument_list|(
argument|const UNLOAD_DLL_DEBUG_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleODSEvent
argument_list|(
argument|const OUTPUT_DEBUG_STRING_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DWORD
name|HandleRipEvent
argument_list|(
argument|const RIP_INFO&info
argument_list|,
argument|DWORD thread_id
argument_list|)
block|;
name|DebugDelegateSP
name|m_debug_delegate
block|;
name|HostProcess
name|m_process
block|;
comment|// The process being debugged.
name|HostThread
name|m_main_thread
block|;
comment|// The main thread of the inferior.
comment|// The image file of the process being debugged.
name|HANDLE
name|m_image_file
operator|=
name|nullptr
block|;
comment|// The current exception waiting to be handled
name|ExceptionRecordSP
name|m_active_exception
block|;
comment|// A predicate which gets signalled when an exception is finished processing
comment|// and the debug loop can be continued.
name|Predicate
operator|<
name|ExceptionResult
operator|>
name|m_exception_pred
block|;
comment|// An event which gets signalled by the debugger thread when it exits the
comment|// debugger loop and is detached from the inferior.
name|HANDLE
name|m_debugging_ended_event
operator|=
name|nullptr
block|;
comment|// Signals the loop to detach from the process (specified by pid).
name|std
operator|::
name|atomic
operator|<
name|DWORD
operator|>
name|m_pid_to_detach
block|;
comment|// Signals the debug loop to stop processing certain types of events that
comment|// block shutdown.
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_is_shutting_down
block|;
comment|// Indicates we've detached from the inferior process and the debug loop can
comment|// exit.
name|bool
name|m_detached
operator|=
name|false
block|;
specifier|static
name|lldb
operator|::
name|thread_result_t
name|DebuggerThreadLaunchRoutine
argument_list|(
name|void
operator|*
name|data
argument_list|)
block|;
name|lldb
operator|::
name|thread_result_t
name|DebuggerThreadLaunchRoutine
argument_list|(
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|thread_result_t
name|DebuggerThreadAttachRoutine
argument_list|(
name|void
operator|*
name|data
argument_list|)
block|;
name|lldb
operator|::
name|thread_result_t
name|DebuggerThreadAttachRoutine
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|const ProcessAttachInfo&launch_info
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

