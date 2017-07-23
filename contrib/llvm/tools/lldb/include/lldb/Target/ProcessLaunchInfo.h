begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessLaunchInfo.h -------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessLaunch_Info_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessLaunch_Info_h
end_define

begin_comment
comment|// C++ Headers
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// LLDB Headers
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Host.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/PseudoTerminal.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/FileAction.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ProcessInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// ProcessLaunchInfo
comment|//
comment|// Describes any information that is required to launch a process.
comment|//----------------------------------------------------------------------
name|class
name|ProcessLaunchInfo
range|:
name|public
name|ProcessInfo
block|{
name|public
operator|:
name|ProcessLaunchInfo
argument_list|()
block|;
name|ProcessLaunchInfo
argument_list|(
argument|const FileSpec&stdin_file_spec
argument_list|,
argument|const FileSpec&stdout_file_spec
argument_list|,
argument|const FileSpec&stderr_file_spec
argument_list|,
argument|const FileSpec&working_dir
argument_list|,
argument|uint32_t launch_flags
argument_list|)
block|;
name|void
name|AppendFileAction
argument_list|(
argument|const FileAction&info
argument_list|)
block|{
name|m_file_actions
operator|.
name|push_back
argument_list|(
name|info
argument_list|)
block|;   }
name|bool
name|AppendCloseFileAction
argument_list|(
argument|int fd
argument_list|)
block|;
name|bool
name|AppendDuplicateFileAction
argument_list|(
argument|int fd
argument_list|,
argument|int dup_fd
argument_list|)
block|;
name|bool
name|AppendOpenFileAction
argument_list|(
argument|int fd
argument_list|,
argument|const FileSpec&file_spec
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|)
block|;
name|bool
name|AppendSuppressFileAction
argument_list|(
argument|int fd
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|)
block|;
name|void
name|FinalizeFileActions
argument_list|(
argument|Target *target
argument_list|,
argument|bool default_to_use_pty
argument_list|)
block|;
name|size_t
name|GetNumFileActions
argument_list|()
specifier|const
block|{
return|return
name|m_file_actions
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|FileAction
operator|*
name|GetFileActionAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
block|;
specifier|const
name|FileAction
operator|*
name|GetFileActionForFD
argument_list|(
argument|int fd
argument_list|)
specifier|const
block|;
name|Flags
operator|&
name|GetFlags
argument_list|()
block|{
return|return
name|m_flags
return|;
block|}
specifier|const
name|Flags
operator|&
name|GetFlags
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
specifier|const
name|FileSpec
operator|&
name|GetWorkingDirectory
argument_list|()
specifier|const
block|;
name|void
name|SetWorkingDirectory
argument_list|(
specifier|const
name|FileSpec
operator|&
name|working_dir
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetProcessPluginName
argument_list|()
specifier|const
block|;
name|void
name|SetProcessPluginName
argument_list|(
argument|llvm::StringRef plugin
argument_list|)
block|;
specifier|const
name|FileSpec
operator|&
name|GetShell
argument_list|()
specifier|const
block|;
name|void
name|SetShell
argument_list|(
specifier|const
name|FileSpec
operator|&
name|shell
argument_list|)
block|;
name|uint32_t
name|GetResumeCount
argument_list|()
specifier|const
block|{
return|return
name|m_resume_count
return|;
block|}
name|void
name|SetResumeCount
argument_list|(
argument|uint32_t c
argument_list|)
block|{
name|m_resume_count
operator|=
name|c
block|; }
name|bool
name|GetLaunchInSeparateProcessGroup
argument_list|()
specifier|const
block|{
return|return
name|m_flags
operator|.
name|Test
argument_list|(
name|lldb
operator|::
name|eLaunchFlagLaunchInSeparateProcessGroup
argument_list|)
return|;
block|}
name|void
name|SetLaunchInSeparateProcessGroup
argument_list|(
argument|bool separate
argument_list|)
block|;
name|bool
name|GetShellExpandArguments
argument_list|()
specifier|const
block|{
return|return
name|m_flags
operator|.
name|Test
argument_list|(
name|lldb
operator|::
name|eLaunchFlagShellExpandArguments
argument_list|)
return|;
block|}
name|void
name|SetShellExpandArguments
argument_list|(
argument|bool expand
argument_list|)
block|;
name|void
name|Clear
argument_list|()
block|;
name|bool
name|ConvertArgumentsForLaunchingInShell
argument_list|(
argument|Status&error
argument_list|,
argument|bool localhost
argument_list|,
argument|bool will_debug
argument_list|,
argument|bool first_arg_is_full_shell_command
argument_list|,
argument|int32_t num_resumes
argument_list|)
block|;
name|void
name|SetMonitorProcessCallback
argument_list|(
argument|const Host::MonitorChildProcessCallback&callback
argument_list|,
argument|bool monitor_signals
argument_list|)
block|;
name|Host
operator|::
name|MonitorChildProcessCallback
name|GetMonitorProcessCallback
argument_list|()
specifier|const
block|{
return|return
name|m_monitor_callback
return|;
block|}
name|bool
name|GetMonitorSignals
argument_list|()
specifier|const
block|{
return|return
name|m_monitor_signals
return|;
block|}
comment|// If the LaunchInfo has a monitor callback, then arrange to monitor the
comment|// process.
comment|// Return true if the LaunchInfo has taken care of monitoring the process, and
comment|// false if the
comment|// caller might want to monitor the process themselves.
name|bool
name|MonitorProcess
argument_list|()
specifier|const
block|;
name|lldb_utility
operator|::
name|PseudoTerminal
operator|&
name|GetPTY
argument_list|()
block|{
return|return
operator|*
name|m_pty
return|;
block|}
comment|// Get and set the actual listener that will be used for the process events
name|lldb
operator|::
name|ListenerSP
name|GetListener
argument_list|()
specifier|const
block|{
return|return
name|m_listener_sp
return|;
block|}
name|void
name|SetListener
argument_list|(
argument|const lldb::ListenerSP&listener_sp
argument_list|)
block|{
name|m_listener_sp
operator|=
name|listener_sp
block|;   }
name|lldb
operator|::
name|ListenerSP
name|GetListenerForProcess
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
block|;
name|lldb
operator|::
name|ListenerSP
name|GetHijackListener
argument_list|()
specifier|const
block|{
return|return
name|m_hijack_listener_sp
return|;
block|}
name|void
name|SetHijackListener
argument_list|(
argument|const lldb::ListenerSP&listener_sp
argument_list|)
block|{
name|m_hijack_listener_sp
operator|=
name|listener_sp
block|;   }
name|void
name|SetLaunchEventData
argument_list|(
argument|const char *data
argument_list|)
block|{
name|m_event_data
operator|.
name|assign
argument_list|(
name|data
argument_list|)
block|; }
specifier|const
name|char
operator|*
name|GetLaunchEventData
argument_list|()
specifier|const
block|{
return|return
name|m_event_data
operator|.
name|c_str
argument_list|()
return|;
block|}
name|void
name|SetDetachOnError
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|GetDetachOnError
argument_list|()
specifier|const
block|{
return|return
name|m_flags
operator|.
name|Test
argument_list|(
name|lldb
operator|::
name|eLaunchFlagDetachOnError
argument_list|)
return|;
block|}
name|protected
operator|:
name|FileSpec
name|m_working_dir
block|;
name|std
operator|::
name|string
name|m_plugin_name
block|;
name|FileSpec
name|m_shell
block|;
name|Flags
name|m_flags
block|;
comment|// Bitwise OR of bits from lldb::LaunchFlags
name|std
operator|::
name|vector
operator|<
name|FileAction
operator|>
name|m_file_actions
block|;
comment|// File actions for any other files
name|std
operator|::
name|shared_ptr
operator|<
name|lldb_utility
operator|::
name|PseudoTerminal
operator|>
name|m_pty
block|;
name|uint32_t
name|m_resume_count
block|;
comment|// How many times do we resume after launching
name|Host
operator|::
name|MonitorChildProcessCallback
name|m_monitor_callback
block|;
name|void
operator|*
name|m_monitor_callback_baton
block|;
name|bool
name|m_monitor_signals
block|;
name|std
operator|::
name|string
name|m_event_data
block|;
comment|// A string passed to the plugin launch, having no
comment|// meaning to the upper levels of lldb.
name|lldb
operator|::
name|ListenerSP
name|m_listener_sp
block|;
name|lldb
operator|::
name|ListenerSP
name|m_hijack_listener_sp
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessLaunch_Info_h
end_comment

end_unit

