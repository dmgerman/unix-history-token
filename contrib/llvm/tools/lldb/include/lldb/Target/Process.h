begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Process.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_Process_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Process_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/Config.h"
end_include

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Communication.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Event.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StringList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ThreadSafeValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserSettingsController.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointSiteList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangPersistentVariables.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/IRDynamicChecks.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Host.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/ProcessRunLock.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Args.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Memory.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/QueueList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/UnixSignals.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/PseudoTerminal.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// ProcessProperties
comment|//----------------------------------------------------------------------
name|class
name|ProcessProperties
range|:
name|public
name|Properties
block|{
name|public
operator|:
name|ProcessProperties
argument_list|(
argument|bool is_global
argument_list|)
block|;
name|virtual
operator|~
name|ProcessProperties
argument_list|()
block|;
name|bool
name|GetDisableMemoryCache
argument_list|()
specifier|const
block|;
name|Args
name|GetExtraStartupCommands
argument_list|()
specifier|const
block|;
name|void
name|SetExtraStartupCommands
argument_list|(
specifier|const
name|Args
operator|&
name|args
argument_list|)
block|;
name|FileSpec
name|GetPythonOSPluginPath
argument_list|()
specifier|const
block|;
name|void
name|SetPythonOSPluginPath
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file
argument_list|)
block|;
name|bool
name|GetIgnoreBreakpointsInExpressions
argument_list|()
specifier|const
block|;
name|void
name|SetIgnoreBreakpointsInExpressions
argument_list|(
argument|bool ignore
argument_list|)
block|;
name|bool
name|GetUnwindOnErrorInExpressions
argument_list|()
specifier|const
block|;
name|void
name|SetUnwindOnErrorInExpressions
argument_list|(
argument|bool ignore
argument_list|)
block|;
name|bool
name|GetStopOnSharedLibraryEvents
argument_list|()
specifier|const
block|;
name|void
name|SetStopOnSharedLibraryEvents
argument_list|(
argument|bool stop
argument_list|)
block|;
name|bool
name|GetDetachKeepsStopped
argument_list|()
specifier|const
block|;
name|void
name|SetDetachKeepsStopped
argument_list|(
argument|bool keep_stopped
argument_list|)
block|; }
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|ProcessProperties
operator|>
name|ProcessPropertiesSP
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// ProcessInfo
comment|//
comment|// A base class for information for a process. This can be used to fill
comment|// out information for a process prior to launching it, or it can be
comment|// used for an instance of a process and can be filled in with the
comment|// existing values for that process.
comment|//----------------------------------------------------------------------
name|class
name|ProcessInfo
block|{
name|public
label|:
name|ProcessInfo
argument_list|()
operator|:
name|m_executable
argument_list|()
operator|,
name|m_arguments
argument_list|()
operator|,
name|m_environment
argument_list|()
operator|,
name|m_uid
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|m_gid
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|m_arch
argument_list|()
operator|,
name|m_pid
argument_list|(
argument|LLDB_INVALID_PROCESS_ID
argument_list|)
block|{     }
name|ProcessInfo
argument_list|(
argument|const char *name
argument_list|,
argument|const ArchSpec&arch
argument_list|,
argument|lldb::pid_t pid
argument_list|)
operator|:
name|m_executable
argument_list|(
name|name
argument_list|,
name|false
argument_list|)
operator|,
name|m_arguments
argument_list|()
operator|,
name|m_environment
argument_list|()
operator|,
name|m_uid
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|m_gid
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|m_arch
argument_list|(
name|arch
argument_list|)
operator|,
name|m_pid
argument_list|(
argument|pid
argument_list|)
block|{     }
name|void
name|Clear
argument_list|()
block|{
name|m_executable
operator|.
name|Clear
argument_list|()
block|;
name|m_arguments
operator|.
name|Clear
argument_list|()
block|;
name|m_environment
operator|.
name|Clear
argument_list|()
block|;
name|m_uid
operator|=
name|UINT32_MAX
block|;
name|m_gid
operator|=
name|UINT32_MAX
block|;
name|m_arch
operator|.
name|Clear
argument_list|()
block|;
name|m_pid
operator|=
name|LLDB_INVALID_PROCESS_ID
block|;     }
specifier|const
name|char
operator|*
name|GetName
argument_list|()
specifier|const
block|{
return|return
name|m_executable
operator|.
name|GetFilename
argument_list|()
operator|.
name|GetCString
argument_list|()
return|;
block|}
name|size_t
name|GetNameLength
argument_list|()
specifier|const
block|{
return|return
name|m_executable
operator|.
name|GetFilename
argument_list|()
operator|.
name|GetLength
argument_list|()
return|;
block|}
name|FileSpec
modifier|&
name|GetExecutableFile
parameter_list|()
block|{
return|return
name|m_executable
return|;
block|}
name|void
name|SetExecutableFile
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|exe_file
parameter_list|,
name|bool
name|add_exe_file_as_first_arg
parameter_list|)
block|{
if|if
condition|(
name|exe_file
condition|)
block|{
name|m_executable
operator|=
name|exe_file
expr_stmt|;
if|if
condition|(
name|add_exe_file_as_first_arg
condition|)
block|{
name|char
name|filename
index|[
name|PATH_MAX
index|]
decl_stmt|;
if|if
condition|(
name|exe_file
operator|.
name|GetPath
argument_list|(
name|filename
argument_list|,
sizeof|sizeof
argument_list|(
name|filename
argument_list|)
argument_list|)
condition|)
name|m_arguments
operator|.
name|InsertArgumentAtIndex
argument_list|(
literal|0
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|m_executable
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
block|}
specifier|const
name|FileSpec
operator|&
name|GetExecutableFile
argument_list|()
specifier|const
block|{
return|return
name|m_executable
return|;
block|}
name|uint32_t
name|GetUserID
argument_list|()
specifier|const
block|{
return|return
name|m_uid
return|;
block|}
name|uint32_t
name|GetGroupID
argument_list|()
specifier|const
block|{
return|return
name|m_gid
return|;
block|}
name|bool
name|UserIDIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_uid
operator|!=
name|UINT32_MAX
return|;
block|}
name|bool
name|GroupIDIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_gid
operator|!=
name|UINT32_MAX
return|;
block|}
name|void
name|SetUserID
parameter_list|(
name|uint32_t
name|uid
parameter_list|)
block|{
name|m_uid
operator|=
name|uid
expr_stmt|;
block|}
name|void
name|SetGroupID
parameter_list|(
name|uint32_t
name|gid
parameter_list|)
block|{
name|m_gid
operator|=
name|gid
expr_stmt|;
block|}
name|ArchSpec
modifier|&
name|GetArchitecture
parameter_list|()
block|{
return|return
name|m_arch
return|;
block|}
specifier|const
name|ArchSpec
operator|&
name|GetArchitecture
argument_list|()
specifier|const
block|{
return|return
name|m_arch
return|;
block|}
name|void
name|SetArchitecture
parameter_list|(
name|ArchSpec
name|arch
parameter_list|)
block|{
name|m_arch
operator|=
name|arch
expr_stmt|;
block|}
name|lldb
operator|::
name|pid_t
name|GetProcessID
argument_list|()
specifier|const
block|{
return|return
name|m_pid
return|;
block|}
name|void
name|SetProcessID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
block|{
name|m_pid
operator|=
name|pid
expr_stmt|;
block|}
name|bool
name|ProcessIDIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_pid
operator|!=
name|LLDB_INVALID_PROCESS_ID
return|;
block|}
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
name|Platform
operator|*
name|platform
argument_list|)
decl|const
decl_stmt|;
name|Args
modifier|&
name|GetArguments
parameter_list|()
block|{
return|return
name|m_arguments
return|;
block|}
specifier|const
name|Args
operator|&
name|GetArguments
argument_list|()
specifier|const
block|{
return|return
name|m_arguments
return|;
block|}
specifier|const
name|char
operator|*
name|GetArg0
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_arg0
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_arg0
operator|.
name|c_str
argument_list|()
return|;
block|}
name|void
name|SetArg0
parameter_list|(
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
block|{
if|if
condition|(
name|arg
operator|&&
name|arg
index|[
literal|0
index|]
condition|)
name|m_arg0
operator|=
name|arg
expr_stmt|;
else|else
name|m_arg0
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|void
name|SetArguments
parameter_list|(
specifier|const
name|Args
modifier|&
name|args
parameter_list|,
name|bool
name|first_arg_is_executable
parameter_list|)
function_decl|;
name|void
name|SetArguments
parameter_list|(
name|char
specifier|const
modifier|*
modifier|*
name|argv
parameter_list|,
name|bool
name|first_arg_is_executable
parameter_list|)
function_decl|;
name|Args
modifier|&
name|GetEnvironmentEntries
parameter_list|()
block|{
return|return
name|m_environment
return|;
block|}
specifier|const
name|Args
operator|&
name|GetEnvironmentEntries
argument_list|()
specifier|const
block|{
return|return
name|m_environment
return|;
block|}
name|protected
label|:
name|FileSpec
name|m_executable
decl_stmt|;
name|std
operator|::
name|string
name|m_arg0
expr_stmt|;
comment|// argv[0] if supported. If empty, then use m_executable.
comment|// Not all process plug-ins support specifying an argv[0]
comment|// that differs from the resolved platform executable
comment|// (which is in m_executable)
name|Args
name|m_arguments
decl_stmt|;
comment|// All program arguments except argv[0]
name|Args
name|m_environment
decl_stmt|;
name|uint32_t
name|m_uid
decl_stmt|;
name|uint32_t
name|m_gid
decl_stmt|;
name|ArchSpec
name|m_arch
decl_stmt|;
name|lldb
operator|::
name|pid_t
name|m_pid
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// ProcessInstanceInfo
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Describes an existing process and any discoverable information that
end_comment

begin_comment
comment|// pertains to that process.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|ProcessInstanceInfo
range|:
name|public
name|ProcessInfo
block|{
name|public
operator|:
name|ProcessInstanceInfo
argument_list|()
operator|:
name|ProcessInfo
argument_list|()
block|,
name|m_euid
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_egid
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_parent_pid
argument_list|(
argument|LLDB_INVALID_PROCESS_ID
argument_list|)
block|{     }
name|ProcessInstanceInfo
argument_list|(
argument|const char *name
argument_list|,
argument|const ArchSpec&arch
argument_list|,
argument|lldb::pid_t pid
argument_list|)
operator|:
name|ProcessInfo
argument_list|(
name|name
argument_list|,
name|arch
argument_list|,
name|pid
argument_list|)
block|,
name|m_euid
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_egid
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_parent_pid
argument_list|(
argument|LLDB_INVALID_PROCESS_ID
argument_list|)
block|{     }
name|void
name|Clear
argument_list|()
block|{
name|ProcessInfo
operator|::
name|Clear
argument_list|()
block|;
name|m_euid
operator|=
name|UINT32_MAX
block|;
name|m_egid
operator|=
name|UINT32_MAX
block|;
name|m_parent_pid
operator|=
name|LLDB_INVALID_PROCESS_ID
block|;     }
name|uint32_t
name|GetEffectiveUserID
argument_list|()
specifier|const
block|{
return|return
name|m_euid
return|;
block|}
name|uint32_t
name|GetEffectiveGroupID
argument_list|()
specifier|const
block|{
return|return
name|m_egid
return|;
block|}
name|bool
name|EffectiveUserIDIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_euid
operator|!=
name|UINT32_MAX
return|;
block|}
name|bool
name|EffectiveGroupIDIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_egid
operator|!=
name|UINT32_MAX
return|;
block|}
name|void
name|SetEffectiveUserID
argument_list|(
argument|uint32_t uid
argument_list|)
block|{
name|m_euid
operator|=
name|uid
block|;     }
name|void
name|SetEffectiveGroupID
argument_list|(
argument|uint32_t gid
argument_list|)
block|{
name|m_egid
operator|=
name|gid
block|;     }
name|lldb
operator|::
name|pid_t
name|GetParentProcessID
argument_list|()
specifier|const
block|{
return|return
name|m_parent_pid
return|;
block|}
name|void
name|SetParentProcessID
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|{
name|m_parent_pid
operator|=
name|pid
block|;     }
name|bool
name|ParentProcessIDIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_parent_pid
operator|!=
name|LLDB_INVALID_PROCESS_ID
return|;
block|}
name|void
name|Dump
argument_list|(
argument|Stream&s
argument_list|,
argument|Platform *platform
argument_list|)
specifier|const
block|;
specifier|static
name|void
name|DumpTableHeader
argument_list|(
argument|Stream&s
argument_list|,
argument|Platform *platform
argument_list|,
argument|bool show_args
argument_list|,
argument|bool verbose
argument_list|)
block|;
name|void
name|DumpAsTableRow
argument_list|(
argument|Stream&s
argument_list|,
argument|Platform *platform
argument_list|,
argument|bool show_args
argument_list|,
argument|bool verbose
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|uint32_t
name|m_euid
block|;
name|uint32_t
name|m_egid
block|;
name|lldb
operator|::
name|pid_t
name|m_parent_pid
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// ProcessLaunchInfo
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Describes any information that is required to launch a process.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|ProcessLaunchInfo
range|:
name|public
name|ProcessInfo
block|{
name|public
operator|:
name|class
name|FileAction
block|{
name|public
operator|:
expr|enum
name|Action
block|{
name|eFileActionNone
block|,
name|eFileActionClose
block|,
name|eFileActionDuplicate
block|,
name|eFileActionOpen
block|}
block|;
name|FileAction
argument_list|()
operator|:
name|m_action
argument_list|(
name|eFileActionNone
argument_list|)
block|,
name|m_fd
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|m_arg
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|m_path
argument_list|()
block|{         }
name|void
name|Clear
argument_list|()
block|{
name|m_action
operator|=
name|eFileActionNone
block|;
name|m_fd
operator|=
operator|-
literal|1
block|;
name|m_arg
operator|=
operator|-
literal|1
block|;
name|m_path
operator|.
name|clear
argument_list|()
block|;         }
name|bool
name|Close
argument_list|(
argument|int fd
argument_list|)
block|;
name|bool
name|Duplicate
argument_list|(
argument|int fd
argument_list|,
argument|int dup_fd
argument_list|)
block|;
name|bool
name|Open
argument_list|(
argument|int fd
argument_list|,
argument|const char *path
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|)
block|;
ifndef|#
directive|ifndef
name|LLDB_DISABLE_POSIX
specifier|static
name|bool
name|AddPosixSpawnFileAction
argument_list|(
name|void
operator|*
name|file_actions
argument_list|,
specifier|const
name|FileAction
operator|*
name|info
argument_list|,
name|Log
operator|*
name|log
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
endif|#
directive|endif
name|int
name|GetFD
argument_list|()
specifier|const
block|{
return|return
name|m_fd
return|;
block|}
name|Action
name|GetAction
argument_list|()
specifier|const
block|{
return|return
name|m_action
return|;
block|}
name|int
name|GetActionArgument
argument_list|()
specifier|const
block|{
return|return
name|m_arg
return|;
block|}
specifier|const
name|char
operator|*
name|GetPath
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_path
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_path
operator|.
name|c_str
argument_list|()
return|;
block|}
name|protected
operator|:
name|Action
name|m_action
block|;
comment|// The action for this file
name|int
name|m_fd
block|;
comment|// An existing file descriptor
name|int
name|m_arg
block|;
comment|// oflag for eFileActionOpen*, dup_fd for eFileActionDuplicate
name|std
operator|::
name|string
name|m_path
block|;
comment|// A file path to use for opening after fork or posix_spawn
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ProcessLaunchInfo
argument_list|()
operator|:
name|ProcessInfo
argument_list|()
operator|,
name|m_working_dir
argument_list|()
operator|,
name|m_plugin_name
argument_list|()
operator|,
name|m_shell
argument_list|()
operator|,
name|m_flags
argument_list|(
literal|0
argument_list|)
operator|,
name|m_file_actions
argument_list|()
operator|,
name|m_pty
argument_list|()
operator|,
name|m_resume_count
argument_list|(
literal|0
argument_list|)
operator|,
name|m_monitor_callback
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_monitor_callback_baton
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_monitor_signals
argument_list|(
name|false
argument_list|)
operator|,
name|m_hijack_listener_sp
argument_list|()
block|{     }
name|ProcessLaunchInfo
argument_list|(
argument|const char *stdin_path
argument_list|,
argument|const char *stdout_path
argument_list|,
argument|const char *stderr_path
argument_list|,
argument|const char *working_directory
argument_list|,
argument|uint32_t launch_flags
argument_list|)
operator|:
name|ProcessInfo
argument_list|()
operator|,
name|m_working_dir
argument_list|()
operator|,
name|m_plugin_name
argument_list|()
operator|,
name|m_shell
argument_list|()
operator|,
name|m_flags
argument_list|(
name|launch_flags
argument_list|)
operator|,
name|m_file_actions
argument_list|()
operator|,
name|m_pty
argument_list|()
operator|,
name|m_resume_count
argument_list|(
literal|0
argument_list|)
operator|,
name|m_monitor_callback
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_monitor_callback_baton
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_monitor_signals
argument_list|(
name|false
argument_list|)
operator|,
name|m_hijack_listener_sp
argument_list|()
block|{
if|if
condition|(
name|stdin_path
condition|)
block|{
name|ProcessLaunchInfo
operator|::
name|FileAction
name|file_action
expr_stmt|;
specifier|const
name|bool
name|read
init|=
name|true
decl_stmt|;
specifier|const
name|bool
name|write
init|=
name|false
decl_stmt|;
if|if
condition|(
name|file_action
operator|.
name|Open
argument_list|(
name|STDIN_FILENO
argument_list|,
name|stdin_path
argument_list|,
name|read
argument_list|,
name|write
argument_list|)
condition|)
name|AppendFileAction
argument_list|(
name|file_action
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|stdout_path
condition|)
block|{
name|ProcessLaunchInfo
operator|::
name|FileAction
name|file_action
expr_stmt|;
specifier|const
name|bool
name|read
init|=
name|false
decl_stmt|;
specifier|const
name|bool
name|write
init|=
name|true
decl_stmt|;
if|if
condition|(
name|file_action
operator|.
name|Open
argument_list|(
name|STDOUT_FILENO
argument_list|,
name|stdout_path
argument_list|,
name|read
argument_list|,
name|write
argument_list|)
condition|)
name|AppendFileAction
argument_list|(
name|file_action
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|stderr_path
condition|)
block|{
name|ProcessLaunchInfo
operator|::
name|FileAction
name|file_action
expr_stmt|;
specifier|const
name|bool
name|read
init|=
name|false
decl_stmt|;
specifier|const
name|bool
name|write
init|=
name|true
decl_stmt|;
if|if
condition|(
name|file_action
operator|.
name|Open
argument_list|(
name|STDERR_FILENO
argument_list|,
name|stderr_path
argument_list|,
name|read
argument_list|,
name|write
argument_list|)
condition|)
name|AppendFileAction
argument_list|(
name|file_action
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|working_directory
condition|)
name|SetWorkingDirectory
argument_list|(
name|working_directory
argument_list|)
expr_stmt|;
end_if

begin_macro
unit|}      void
name|AppendFileAction
argument_list|(
argument|const FileAction&info
argument_list|)
end_macro

begin_block
block|{
name|m_file_actions
operator|.
name|push_back
argument_list|(
name|info
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|bool
name|AppendCloseFileAction
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|FileAction
name|file_action
decl_stmt|;
if|if
condition|(
name|file_action
operator|.
name|Close
argument_list|(
name|fd
argument_list|)
condition|)
block|{
name|AppendFileAction
argument_list|(
name|file_action
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|AppendDuplicateFileAction
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|dup_fd
parameter_list|)
block|{
name|FileAction
name|file_action
decl_stmt|;
if|if
condition|(
name|file_action
operator|.
name|Duplicate
argument_list|(
name|fd
argument_list|,
name|dup_fd
argument_list|)
condition|)
block|{
name|AppendFileAction
argument_list|(
name|file_action
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|AppendOpenFileAction
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|read
parameter_list|,
name|bool
name|write
parameter_list|)
block|{
name|FileAction
name|file_action
decl_stmt|;
if|if
condition|(
name|file_action
operator|.
name|Open
argument_list|(
name|fd
argument_list|,
name|path
argument_list|,
name|read
argument_list|,
name|write
argument_list|)
condition|)
block|{
name|AppendFileAction
argument_list|(
name|file_action
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|AppendSuppressFileAction
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|read
parameter_list|,
name|bool
name|write
parameter_list|)
block|{
name|FileAction
name|file_action
decl_stmt|;
if|if
condition|(
name|file_action
operator|.
name|Open
argument_list|(
name|fd
argument_list|,
literal|"/dev/null"
argument_list|,
name|read
argument_list|,
name|write
argument_list|)
condition|)
block|{
name|AppendFileAction
argument_list|(
name|file_action
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_function_decl
name|void
name|FinalizeFileActions
parameter_list|(
name|Target
modifier|*
name|target
parameter_list|,
name|bool
name|default_to_use_pty
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
specifier|const
name|FileAction
modifier|*
name|GetFileActionAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
block|{
if|if
condition|(
name|idx
operator|<
name|m_file_actions
operator|.
name|size
argument_list|()
condition|)
return|return
operator|&
name|m_file_actions
index|[
name|idx
index|]
return|;
return|return
name|NULL
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|FileAction
modifier|*
name|GetFileActionForFD
argument_list|(
name|int
name|fd
argument_list|)
decl|const
block|{
for|for
control|(
name|size_t
name|idx
init|=
literal|0
init|,
name|count
init|=
name|m_file_actions
operator|.
name|size
argument_list|()
init|;
name|idx
operator|<
name|count
condition|;
operator|++
name|idx
control|)
block|{
if|if
condition|(
name|m_file_actions
index|[
name|idx
index|]
operator|.
name|GetFD
argument_list|()
operator|==
name|fd
condition|)
return|return
operator|&
name|m_file_actions
index|[
name|idx
index|]
return|;
block|}
return|return
name|NULL
return|;
block|}
end_decl_stmt

begin_function
name|Flags
modifier|&
name|GetFlags
parameter_list|()
block|{
return|return
name|m_flags
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|GetWorkingDirectory
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_working_dir
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
end_expr_stmt

begin_return
return|return
name|m_working_dir
operator|.
name|c_str
argument_list|()
return|;
end_return

begin_macro
unit|}      void
name|SetWorkingDirectory
argument_list|(
argument|const char *working_dir
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|working_dir
operator|&&
name|working_dir
index|[
literal|0
index|]
condition|)
name|m_working_dir
operator|.
name|assign
argument_list|(
name|working_dir
argument_list|)
expr_stmt|;
else|else
name|m_working_dir
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|void
name|SwapWorkingDirectory
argument_list|(
name|std
operator|::
name|string
operator|&
name|working_dir
argument_list|)
block|{
name|m_working_dir
operator|.
name|swap
argument_list|(
name|working_dir
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|GetProcessPluginName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_plugin_name
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
end_expr_stmt

begin_return
return|return
name|m_plugin_name
operator|.
name|c_str
argument_list|()
return|;
end_return

begin_macro
unit|}      void
name|SetProcessPluginName
argument_list|(
argument|const char *plugin
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|plugin
operator|&&
name|plugin
index|[
literal|0
index|]
condition|)
name|m_plugin_name
operator|.
name|assign
argument_list|(
name|plugin
argument_list|)
expr_stmt|;
else|else
name|m_plugin_name
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|const
name|char
operator|*
name|GetShell
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_shell
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
end_expr_stmt

begin_return
return|return
name|m_shell
operator|.
name|c_str
argument_list|()
return|;
end_return

begin_macro
unit|}      void
name|SetShell
argument_list|(
argument|const char * path
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|path
operator|&&
name|path
index|[
literal|0
index|]
condition|)
block|{
name|m_shell
operator|.
name|assign
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|m_flags
operator|.
name|Set
argument_list|(
name|lldb
operator|::
name|eLaunchFlagLaunchInShell
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_shell
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_flags
operator|.
name|Clear
argument_list|(
name|lldb
operator|::
name|eLaunchFlagLaunchInShell
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_expr_stmt
name|uint32_t
name|GetResumeCount
argument_list|()
specifier|const
block|{
return|return
name|m_resume_count
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetResumeCount
parameter_list|(
name|uint32_t
name|c
parameter_list|)
block|{
name|m_resume_count
operator|=
name|c
expr_stmt|;
block|}
end_function

begin_function
name|bool
name|GetLaunchInSeparateProcessGroup
parameter_list|()
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
end_function

begin_function
name|void
name|SetLaunchInSeparateProcessGroup
parameter_list|(
name|bool
name|separate
parameter_list|)
block|{
if|if
condition|(
name|separate
condition|)
name|m_flags
operator|.
name|Set
argument_list|(
name|lldb
operator|::
name|eLaunchFlagLaunchInSeparateProcessGroup
argument_list|)
expr_stmt|;
else|else
name|m_flags
operator|.
name|Clear
argument_list|(
name|lldb
operator|::
name|eLaunchFlagLaunchInSeparateProcessGroup
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|Clear
parameter_list|()
block|{
name|ProcessInfo
operator|::
name|Clear
argument_list|()
expr_stmt|;
name|m_working_dir
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_plugin_name
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_shell
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_flags
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|m_file_actions
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_resume_count
operator|=
literal|0
expr_stmt|;
name|m_hijack_listener_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|bool
name|ConvertArgumentsForLaunchingInShell
parameter_list|(
name|Error
modifier|&
name|error
parameter_list|,
name|bool
name|localhost
parameter_list|,
name|bool
name|will_debug
parameter_list|,
name|bool
name|first_arg_is_full_shell_command
parameter_list|,
name|int32_t
name|num_resumes
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|SetMonitorProcessCallback
argument_list|(
name|Host
operator|::
name|MonitorChildProcessCallback
name|callback
argument_list|,
name|void
operator|*
name|baton
argument_list|,
name|bool
name|monitor_signals
argument_list|)
block|{
name|m_monitor_callback
operator|=
name|callback
expr_stmt|;
name|m_monitor_callback_baton
operator|=
name|baton
expr_stmt|;
name|m_monitor_signals
operator|=
name|monitor_signals
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|Host
operator|::
name|MonitorChildProcessCallback
name|GetMonitorProcessCallback
argument_list|()
block|{
return|return
name|m_monitor_callback
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|void
operator|*
name|GetMonitorProcessBaton
argument_list|()
specifier|const
block|{
return|return
name|m_monitor_callback_baton
return|;
block|}
end_expr_stmt

begin_comment
comment|// If the LaunchInfo has a monitor callback, then arrange to monitor the process.
end_comment

begin_comment
comment|// Return true if the LaunchInfo has taken care of monitoring the process, and false if the
end_comment

begin_comment
comment|// caller might want to monitor the process themselves.
end_comment

begin_expr_stmt
name|bool
name|MonitorProcess
argument_list|()
specifier|const
block|{
if|if
condition|(
name|GetFlags
argument_list|()
operator|.
name|Test
argument_list|(
name|lldb
operator|::
name|eLaunchFlagsDontMonitorProcess
argument_list|)
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|m_monitor_callback
operator|&&
name|ProcessIDIsValid
argument_list|()
condition|)
block|{
name|Host
operator|::
name|StartMonitoringChildProcess
argument_list|(
name|m_monitor_callback
argument_list|,
name|m_monitor_callback_baton
argument_list|,
name|GetProcessID
argument_list|()
argument_list|,
name|m_monitor_signals
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_if

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}          lldb_utility
operator|::
name|PseudoTerminal
operator|&
name|GetPTY
argument_list|()
block|{
return|return
name|m_pty
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|void
name|SetHijackListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|)
block|{
name|m_hijack_listener_sp
operator|=
name|listener_sp
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|string
name|m_working_dir
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_plugin_name
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_shell
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Flags
name|m_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Bitwise OR of bits from lldb::LaunchFlags
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|FileAction
operator|>
name|m_file_actions
expr_stmt|;
end_expr_stmt

begin_comment
comment|// File actions for any other files
end_comment

begin_expr_stmt
name|lldb_utility
operator|::
name|PseudoTerminal
name|m_pty
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|m_resume_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|// How many times do we resume after launching
end_comment

begin_expr_stmt
name|Host
operator|::
name|MonitorChildProcessCallback
name|m_monitor_callback
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
modifier|*
name|m_monitor_callback_baton
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_monitor_signals
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ListenerSP
name|m_hijack_listener_sp
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// ProcessLaunchInfo
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Describes any information that is required to launch a process.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|ProcessAttachInfo
range|:
name|public
name|ProcessInstanceInfo
block|{
name|public
operator|:
name|ProcessAttachInfo
argument_list|()
operator|:
name|ProcessInstanceInfo
argument_list|()
block|,
name|m_plugin_name
argument_list|()
block|,
name|m_resume_count
argument_list|(
literal|0
argument_list|)
block|,
name|m_wait_for_launch
argument_list|(
name|false
argument_list|)
block|,
name|m_ignore_existing
argument_list|(
name|true
argument_list|)
block|,
name|m_continue_once_attached
argument_list|(
argument|false
argument_list|)
block|{     }
name|ProcessAttachInfo
argument_list|(
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
operator|:
name|ProcessInstanceInfo
argument_list|()
block|,
name|m_plugin_name
argument_list|()
block|,
name|m_resume_count
argument_list|(
literal|0
argument_list|)
block|,
name|m_wait_for_launch
argument_list|(
name|false
argument_list|)
block|,
name|m_ignore_existing
argument_list|(
name|true
argument_list|)
block|,
name|m_continue_once_attached
argument_list|(
argument|false
argument_list|)
block|{
name|ProcessInfo
operator|::
name|operator
operator|=
operator|(
name|launch_info
operator|)
block|;
name|SetProcessPluginName
argument_list|(
name|launch_info
operator|.
name|GetProcessPluginName
argument_list|()
argument_list|)
block|;
name|SetResumeCount
argument_list|(
name|launch_info
operator|.
name|GetResumeCount
argument_list|()
argument_list|)
block|;
name|SetHijackListener
argument_list|(
name|launch_info
operator|.
name|GetHijackListener
argument_list|()
argument_list|)
block|;     }
name|bool
name|GetWaitForLaunch
argument_list|()
specifier|const
block|{
return|return
name|m_wait_for_launch
return|;
block|}
name|void
name|SetWaitForLaunch
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_wait_for_launch
operator|=
name|b
block|;     }
name|bool
name|GetIgnoreExisting
argument_list|()
specifier|const
block|{
return|return
name|m_ignore_existing
return|;
block|}
name|void
name|SetIgnoreExisting
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_ignore_existing
operator|=
name|b
block|;     }
name|bool
name|GetContinueOnceAttached
argument_list|()
specifier|const
block|{
return|return
name|m_continue_once_attached
return|;
block|}
name|void
name|SetContinueOnceAttached
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_continue_once_attached
operator|=
name|b
block|;     }
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
block|;     }
specifier|const
name|char
operator|*
name|GetProcessPluginName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_plugin_name
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_plugin_name
operator|.
name|c_str
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|void
name|SetProcessPluginName
parameter_list|(
specifier|const
name|char
modifier|*
name|plugin
parameter_list|)
block|{
if|if
condition|(
name|plugin
operator|&&
name|plugin
index|[
literal|0
index|]
condition|)
name|m_plugin_name
operator|.
name|assign
argument_list|(
name|plugin
argument_list|)
expr_stmt|;
else|else
name|m_plugin_name
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|Clear
parameter_list|()
block|{
name|ProcessInstanceInfo
operator|::
name|Clear
argument_list|()
expr_stmt|;
name|m_plugin_name
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_resume_count
operator|=
literal|0
expr_stmt|;
name|m_wait_for_launch
operator|=
name|false
expr_stmt|;
name|m_ignore_existing
operator|=
name|true
expr_stmt|;
name|m_continue_once_attached
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|ProcessInfoSpecified
argument_list|()
specifier|const
block|{
if|if
condition|(
name|GetExecutableFile
argument_list|()
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|GetProcessID
argument_list|()
operator|!=
name|LLDB_INVALID_PROCESS_ID
condition|)
return|return
name|true
return|;
end_if

begin_if
if|if
condition|(
name|GetParentProcessID
argument_list|()
operator|!=
name|LLDB_INVALID_PROCESS_ID
condition|)
return|return
name|true
return|;
end_if

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}          lldb
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
end_expr_stmt

begin_decl_stmt
name|void
name|SetHijackListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|)
block|{
name|m_hijack_listener_sp
operator|=
name|listener_sp
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|lldb
operator|::
name|ListenerSP
name|m_hijack_listener_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_plugin_name
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|m_resume_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|// How many times do we resume after launching
end_comment

begin_decl_stmt
name|bool
name|m_wait_for_launch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_ignore_existing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_continue_once_attached
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Supports the use-case scenario of immediately continuing the process once attached.
end_comment

begin_decl_stmt
unit|};
name|class
name|ProcessLaunchCommandOptions
range|:
name|public
name|Options
block|{
name|public
operator|:
name|ProcessLaunchCommandOptions
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
operator|:
name|Options
argument_list|(
argument|interpreter
argument_list|)
block|{
comment|// Keep default values of all options in one place: OptionParsingStarting ()
name|OptionParsingStarting
argument_list|()
block|;     }
operator|~
name|ProcessLaunchCommandOptions
argument_list|()
block|{     }
name|Error
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|const char *option_arg
argument_list|)
block|;
name|void
name|OptionParsingStarting
argument_list|()
block|{
name|launch_info
operator|.
name|Clear
argument_list|()
block|;     }
specifier|const
name|OptionDefinition
operator|*
name|GetDefinitions
argument_list|()
block|{
return|return
name|g_option_table
return|;
block|}
comment|// Options table: Required for subclasses of Options.
specifier|static
name|OptionDefinition
name|g_option_table
index|[]
block|;
comment|// Instance variables to hold the values for command options.
name|ProcessLaunchInfo
name|launch_info
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// ProcessInstanceInfoMatch
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A class to help matching one ProcessInstanceInfo to another.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|ProcessInstanceInfoMatch
block|{
name|public
label|:
name|ProcessInstanceInfoMatch
argument_list|()
operator|:
name|m_match_info
argument_list|()
operator|,
name|m_name_match_type
argument_list|(
name|eNameMatchIgnore
argument_list|)
operator|,
name|m_match_all_users
argument_list|(
argument|false
argument_list|)
block|{     }
name|ProcessInstanceInfoMatch
argument_list|(
argument|const char *process_name
argument_list|,
argument|NameMatchType process_name_match_type
argument_list|)
operator|:
name|m_match_info
argument_list|()
operator|,
name|m_name_match_type
argument_list|(
name|process_name_match_type
argument_list|)
operator|,
name|m_match_all_users
argument_list|(
argument|false
argument_list|)
block|{
name|m_match_info
operator|.
name|GetExecutableFile
argument_list|()
operator|.
name|SetFile
argument_list|(
name|process_name
argument_list|,
name|false
argument_list|)
block|;     }
name|ProcessInstanceInfo
operator|&
name|GetProcessInfo
argument_list|()
block|{
return|return
name|m_match_info
return|;
block|}
specifier|const
name|ProcessInstanceInfo
operator|&
name|GetProcessInfo
argument_list|()
specifier|const
block|{
return|return
name|m_match_info
return|;
block|}
name|bool
name|GetMatchAllUsers
argument_list|()
specifier|const
block|{
return|return
name|m_match_all_users
return|;
block|}
name|void
name|SetMatchAllUsers
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_match_all_users
operator|=
name|b
expr_stmt|;
block|}
name|NameMatchType
name|GetNameMatchType
argument_list|()
specifier|const
block|{
return|return
name|m_name_match_type
return|;
block|}
name|void
name|SetNameMatchType
parameter_list|(
name|NameMatchType
name|name_match_type
parameter_list|)
block|{
name|m_name_match_type
operator|=
name|name_match_type
expr_stmt|;
block|}
name|bool
name|NameMatches
argument_list|(
specifier|const
name|char
operator|*
name|process_name
argument_list|)
decl|const
decl_stmt|;
name|bool
name|Matches
argument_list|(
specifier|const
name|ProcessInstanceInfo
operator|&
name|proc_info
argument_list|)
decl|const
decl_stmt|;
name|bool
name|MatchAllProcesses
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|protected
label|:
name|ProcessInstanceInfo
name|m_match_info
decl_stmt|;
name|NameMatchType
name|m_name_match_type
decl_stmt|;
name|bool
name|m_match_all_users
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ProcessInstanceInfoList
block|{
name|public
label|:
name|ProcessInstanceInfoList
argument_list|()
operator|:
name|m_infos
argument_list|()
block|{     }
name|void
name|Clear
argument_list|()
block|{
name|m_infos
operator|.
name|clear
argument_list|()
block|;     }
name|size_t
name|GetSize
argument_list|()
block|{
return|return
name|m_infos
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|Append
parameter_list|(
specifier|const
name|ProcessInstanceInfo
modifier|&
name|info
parameter_list|)
block|{
name|m_infos
operator|.
name|push_back
argument_list|(
name|info
argument_list|)
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|GetProcessNameAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_infos
index|[
name|idx
index|]
operator|.
name|GetName
argument_list|()
return|;
return|return
name|NULL
return|;
block|}
name|size_t
name|GetProcessNameLengthAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_infos
index|[
name|idx
index|]
operator|.
name|GetNameLength
argument_list|()
return|;
return|return
literal|0
return|;
block|}
name|lldb
operator|::
name|pid_t
name|GetProcessIDAtIndex
argument_list|(
argument|size_t idx
argument_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_infos
index|[
name|idx
index|]
operator|.
name|GetProcessID
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_function
name|bool
name|GetInfoAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|,
name|ProcessInstanceInfo
modifier|&
name|info
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
condition|)
block|{
name|info
operator|=
name|m_infos
index|[
name|idx
index|]
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|// You must ensure "idx" is valid before calling this function
end_comment

begin_decl_stmt
specifier|const
name|ProcessInstanceInfo
modifier|&
name|GetProcessInfoAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|m_infos
index|[
name|idx
index|]
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ProcessInstanceInfo
operator|>
name|collection
expr_stmt|;
end_typedef

begin_decl_stmt
name|collection
name|m_infos
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// This class tracks the Modification state of the process.  Things that can currently modify
end_comment

begin_comment
comment|// the program are running the program (which will up the StopID) and writing memory (which
end_comment

begin_comment
comment|// will up the MemoryID.)
end_comment

begin_comment
comment|// FIXME: Should we also include modification of register states?
end_comment

begin_decl_stmt
name|class
name|ProcessModID
block|{
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ProcessModID
operator|&
name|lhs
operator|,
specifier|const
name|ProcessModID
operator|&
name|rhs
operator|)
expr_stmt|;
name|public
label|:
name|ProcessModID
argument_list|()
operator|:
name|m_stop_id
argument_list|(
literal|0
argument_list|)
operator|,
name|m_last_natural_stop_id
argument_list|(
literal|0
argument_list|)
operator|,
name|m_resume_id
argument_list|(
literal|0
argument_list|)
operator|,
name|m_memory_id
argument_list|(
literal|0
argument_list|)
operator|,
name|m_last_user_expression_resume
argument_list|(
literal|0
argument_list|)
operator|,
name|m_running_user_expression
argument_list|(
argument|false
argument_list|)
block|{}
name|ProcessModID
argument_list|(
specifier|const
name|ProcessModID
operator|&
name|rhs
argument_list|)
operator|:
name|m_stop_id
argument_list|(
name|rhs
operator|.
name|m_stop_id
argument_list|)
operator|,
name|m_memory_id
argument_list|(
argument|rhs.m_memory_id
argument_list|)
block|{}
specifier|const
name|ProcessModID
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ProcessModID
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
block|{
name|m_stop_id
operator|=
name|rhs
operator|.
name|m_stop_id
expr_stmt|;
name|m_memory_id
operator|=
name|rhs
operator|.
name|m_memory_id
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
operator|~
name|ProcessModID
argument_list|()
block|{}
name|void
name|BumpStopID
argument_list|()
block|{
name|m_stop_id
operator|++
block|;
if|if
condition|(
operator|!
name|IsLastResumeForUserExpression
argument_list|()
condition|)
name|m_last_natural_stop_id
operator|++
expr_stmt|;
block|}
name|void
name|BumpMemoryID
parameter_list|()
block|{
name|m_memory_id
operator|++
expr_stmt|;
block|}
name|void
name|BumpResumeID
parameter_list|()
block|{
name|m_resume_id
operator|++
expr_stmt|;
if|if
condition|(
name|m_running_user_expression
operator|>
literal|0
condition|)
name|m_last_user_expression_resume
operator|=
name|m_resume_id
expr_stmt|;
block|}
name|uint32_t
name|GetStopID
argument_list|()
specifier|const
block|{
return|return
name|m_stop_id
return|;
block|}
name|uint32_t
name|GetLastNaturalStopID
argument_list|()
specifier|const
block|{
return|return
name|m_last_natural_stop_id
return|;
block|}
name|uint32_t
name|GetMemoryID
argument_list|()
specifier|const
block|{
return|return
name|m_memory_id
return|;
block|}
name|uint32_t
name|GetResumeID
argument_list|()
specifier|const
block|{
return|return
name|m_resume_id
return|;
block|}
name|uint32_t
name|GetLastUserExpressionResumeID
argument_list|()
specifier|const
block|{
return|return
name|m_last_user_expression_resume
return|;
block|}
name|bool
name|MemoryIDEqual
argument_list|(
specifier|const
name|ProcessModID
operator|&
name|compare
argument_list|)
decl|const
block|{
return|return
name|m_memory_id
operator|==
name|compare
operator|.
name|m_memory_id
return|;
block|}
name|bool
name|StopIDEqual
argument_list|(
specifier|const
name|ProcessModID
operator|&
name|compare
argument_list|)
decl|const
block|{
return|return
name|m_stop_id
operator|==
name|compare
operator|.
name|m_stop_id
return|;
block|}
name|void
name|SetInvalid
parameter_list|()
block|{
name|m_stop_id
operator|=
name|UINT32_MAX
expr_stmt|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_stop_id
operator|!=
name|UINT32_MAX
return|;
block|}
name|bool
name|IsLastResumeForUserExpression
argument_list|()
specifier|const
block|{
return|return
name|m_resume_id
operator|==
name|m_last_user_expression_resume
return|;
block|}
name|void
name|SetRunningUserExpression
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
comment|// REMOVEME printf ("Setting running user expression %s at resume id %d - value: %d.\n", on ? "on" : "off", m_resume_id, m_running_user_expression);
if|if
condition|(
name|on
condition|)
name|m_running_user_expression
operator|++
expr_stmt|;
else|else
name|m_running_user_expression
operator|--
expr_stmt|;
block|}
name|private
label|:
name|uint32_t
name|m_stop_id
decl_stmt|;
name|uint32_t
name|m_last_natural_stop_id
decl_stmt|;
name|uint32_t
name|m_resume_id
decl_stmt|;
name|uint32_t
name|m_memory_id
decl_stmt|;
name|uint32_t
name|m_last_user_expression_resume
decl_stmt|;
name|uint32_t
name|m_running_user_expression
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ProcessModID
operator|&
name|lhs
operator|,
specifier|const
name|ProcessModID
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|lhs
operator|.
name|StopIDEqual
argument_list|(
name|rhs
argument_list|)
operator|&&
name|lhs
operator|.
name|MemoryIDEqual
argument_list|(
name|rhs
argument_list|)
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ProcessModID
operator|&
name|lhs
operator|,
specifier|const
name|ProcessModID
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
operator|!
name|lhs
operator|.
name|StopIDEqual
argument_list|(
name|rhs
argument_list|)
operator|||
operator|!
name|lhs
operator|.
name|MemoryIDEqual
argument_list|(
name|rhs
argument_list|)
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|class
name|MemoryRegionInfo
block|{
name|public
label|:
typedef|typedef
name|Range
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|RangeType
expr_stmt|;
enum|enum
name|OptionalBool
block|{
name|eDontKnow
init|=
operator|-
literal|1
block|,
name|eNo
init|=
literal|0
block|,
name|eYes
init|=
literal|1
block|}
enum|;
name|MemoryRegionInfo
argument_list|()
operator|:
name|m_range
argument_list|()
operator|,
name|m_read
argument_list|(
name|eDontKnow
argument_list|)
operator|,
name|m_write
argument_list|(
name|eDontKnow
argument_list|)
operator|,
name|m_execute
argument_list|(
argument|eDontKnow
argument_list|)
block|{     }
operator|~
name|MemoryRegionInfo
argument_list|()
block|{     }
name|RangeType
operator|&
name|GetRange
argument_list|()
block|{
return|return
name|m_range
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_range
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|m_read
operator|=
name|m_write
operator|=
name|m_execute
operator|=
name|eDontKnow
expr_stmt|;
block|}
specifier|const
name|RangeType
operator|&
name|GetRange
argument_list|()
specifier|const
block|{
return|return
name|m_range
return|;
block|}
name|OptionalBool
name|GetReadable
argument_list|()
specifier|const
block|{
return|return
name|m_read
return|;
block|}
name|OptionalBool
name|GetWritable
argument_list|()
specifier|const
block|{
return|return
name|m_write
return|;
block|}
name|OptionalBool
name|GetExecutable
argument_list|()
specifier|const
block|{
return|return
name|m_execute
return|;
block|}
name|void
name|SetReadable
parameter_list|(
name|OptionalBool
name|val
parameter_list|)
block|{
name|m_read
operator|=
name|val
expr_stmt|;
block|}
name|void
name|SetWritable
parameter_list|(
name|OptionalBool
name|val
parameter_list|)
block|{
name|m_write
operator|=
name|val
expr_stmt|;
block|}
name|void
name|SetExecutable
parameter_list|(
name|OptionalBool
name|val
parameter_list|)
block|{
name|m_execute
operator|=
name|val
expr_stmt|;
block|}
name|protected
label|:
name|RangeType
name|m_range
decl_stmt|;
name|OptionalBool
name|m_read
decl_stmt|;
name|OptionalBool
name|m_write
decl_stmt|;
name|OptionalBool
name|m_execute
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class Process Process.h "lldb/Target/Process.h"
end_comment

begin_comment
comment|/// @brief A plug-in interface definition class for debugging a process.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|Process
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Process
operator|>
decl_stmt|,
name|public
name|ProcessProperties
decl_stmt|,
name|public
name|UserID
decl_stmt|,
name|public
name|Broadcaster
decl_stmt|,
name|public
name|ExecutionContextScope
decl_stmt|,
name|public
name|PluginInterface
block|{
name|friend
name|class
name|ClangFunction
decl_stmt|;
comment|// For WaitForStateChangeEventsPrivate
name|friend
name|class
name|ProcessEventData
decl_stmt|;
name|friend
name|class
name|StopInfo
decl_stmt|;
name|friend
name|class
name|Target
decl_stmt|;
name|friend
name|class
name|ThreadList
decl_stmt|;
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Broadcaster event bits definitions.
comment|//------------------------------------------------------------------
enum|enum
block|{
name|eBroadcastBitStateChanged
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastBitInterrupt
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eBroadcastBitSTDOUT
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|eBroadcastBitSTDERR
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|eBroadcastBitProfileData
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|}
enum|;
enum|enum
block|{
name|eBroadcastInternalStateControlStop
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastInternalStateControlPause
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eBroadcastInternalStateControlResume
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|}
enum|;
typedef|typedef
name|Range
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|LoadRange
expr_stmt|;
comment|// We use a read/write lock to allow on or more clients to
comment|// access the process state while the process is stopped (reader).
comment|// We lock the write lock to control access to the process
comment|// while it is running (readers, or clients that want the process
comment|// stopped can block waiting for the process to stop, or just
comment|// try to lock it to see if they can immediately access the stopped
comment|// process. If the try read lock fails, then the process is running.
typedef|typedef
name|ProcessRunLock
operator|::
name|ProcessRunLocker
name|StopLocker
expr_stmt|;
comment|// These two functions fill out the Broadcaster interface:
specifier|static
name|ConstString
modifier|&
name|GetStaticBroadcasterClass
parameter_list|()
function_decl|;
name|virtual
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
block|{
return|return
name|GetStaticBroadcasterClass
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// A notification structure that can be used by clients to listen
comment|/// for changes in a process's lifetime.
comment|///
comment|/// @see RegisterNotificationCallbacks (const Notifications&)
comment|/// @see UnregisterNotificationCallbacks (const Notifications&)
comment|//------------------------------------------------------------------
ifndef|#
directive|ifndef
name|SWIG
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|baton
decl_stmt|;
name|void
function_decl|(
modifier|*
name|initialize
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|Process
modifier|*
name|process
parameter_list|)
function_decl|;
name|void
argument_list|(
argument|*process_state_changed
argument_list|)
operator|(
name|void
operator|*
name|baton
operator|,
name|Process
operator|*
name|process
operator|,
name|lldb
operator|::
name|StateType
name|state
operator|)
expr_stmt|;
block|}
name|Notifications
typedef|;
name|class
name|ProcessEventData
range|:
name|public
name|EventData
block|{
name|friend
name|class
name|Process
block|;
name|public
operator|:
name|ProcessEventData
argument_list|()
block|;
name|ProcessEventData
argument_list|(
argument|const lldb::ProcessSP&process
argument_list|,
argument|lldb::StateType state
argument_list|)
block|;
name|virtual
operator|~
name|ProcessEventData
argument_list|()
block|;
specifier|static
specifier|const
name|ConstString
operator|&
name|GetFlavorString
argument_list|()
block|;
name|virtual
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
block|;
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|GetProcessSP
argument_list|()
specifier|const
block|{
return|return
name|m_process_sp
return|;
block|}
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
specifier|const
block|{
return|return
name|m_state
return|;
block|}
name|bool
name|GetRestarted
argument_list|()
specifier|const
block|{
return|return
name|m_restarted
return|;
block|}
name|size_t
name|GetNumRestartedReasons
argument_list|()
block|{
return|return
name|m_restarted_reasons
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|GetRestartedReasonAtIndex
argument_list|(
argument|size_t idx
argument_list|)
block|{
if|if
condition|(
name|idx
operator|>
name|m_restarted_reasons
operator|.
name|size
argument_list|()
condition|)
return|return
name|NULL
return|;
else|else
return|return
name|m_restarted_reasons
index|[
name|idx
index|]
operator|.
name|c_str
argument_list|()
return|;
block|}
name|bool
name|GetInterrupted
argument_list|()
specifier|const
block|{
return|return
name|m_interrupted
return|;
block|}
name|virtual
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|DoOnRemoval
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
specifier|const
name|Process
operator|::
name|ProcessEventData
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
name|ProcessSP
name|GetProcessFromEvent
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
name|StateType
name|GetStateFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|bool
name|GetRestartedFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|size_t
name|GetNumRestartedReasons
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetRestartedReasonAtIndex
argument_list|(
argument|const Event *event_ptr
argument_list|,
argument|size_t idx
argument_list|)
block|;
specifier|static
name|void
name|AddRestartedReason
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|,
specifier|const
name|char
operator|*
name|reason
argument_list|)
block|;
specifier|static
name|void
name|SetRestartedInEvent
argument_list|(
argument|Event *event_ptr
argument_list|,
argument|bool new_value
argument_list|)
block|;
specifier|static
name|bool
name|GetInterruptedFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|void
name|SetInterruptedInEvent
argument_list|(
argument|Event *event_ptr
argument_list|,
argument|bool new_value
argument_list|)
block|;
specifier|static
name|bool
name|SetUpdateStateOnRemoval
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|private
operator|:
name|void
name|SetUpdateStateOnRemoval
argument_list|()
block|{
name|m_update_state
operator|++
block|;             }
name|void
name|SetRestarted
argument_list|(
argument|bool new_value
argument_list|)
block|{
name|m_restarted
operator|=
name|new_value
block|;             }
name|void
name|SetInterrupted
argument_list|(
argument|bool new_value
argument_list|)
block|{
name|m_interrupted
operator|=
name|new_value
block|;             }
name|void
name|AddRestartedReason
argument_list|(
argument|const char *reason
argument_list|)
block|{
name|m_restarted_reasons
operator|.
name|push_back
argument_list|(
name|reason
argument_list|)
block|;             }
name|lldb
operator|::
name|ProcessSP
name|m_process_sp
block|;
name|lldb
operator|::
name|StateType
name|m_state
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|m_restarted_reasons
block|;
name|bool
name|m_restarted
block|;
comment|// For "eStateStopped" events, this is true if the target was automatically restarted.
name|int
name|m_update_state
block|;
name|bool
name|m_interrupted
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessEventData
argument_list|)
block|;      }
decl_stmt|;
endif|#
directive|endif
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
name|ProcessPropertiesSP
modifier|&
name|GetGlobalProperties
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Construct with a shared pointer to a target, and the Process listener.
comment|//------------------------------------------------------------------
name|Process
argument_list|(
name|Target
operator|&
name|target
argument_list|,
name|Listener
operator|&
name|listener
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class is designed to be
comment|/// inherited from by the plug-in instance.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|Process
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a Process plug-in that can debug \a module using the
comment|/// currently selected architecture.
comment|///
comment|/// Scans all loaded plug-in interfaces that implement versions of
comment|/// the Process plug-in interface and returns the first instance
comment|/// that can debug the file.
comment|///
comment|/// @param[in] module_sp
comment|///     The module shared pointer that this process will debug.
comment|///
comment|/// @param[in] plugin_name
comment|///     If NULL, select the best plug-in for the binary. If non-NULL
comment|///     then look for a plugin whose PluginInfo's name matches
comment|///     this string.
comment|///
comment|/// @see Process::CanDebug ()
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ProcessSP
name|FindPlugin
argument_list|(
name|Target
operator|&
name|target
argument_list|,
specifier|const
name|char
operator|*
name|plugin_name
argument_list|,
name|Listener
operator|&
name|listener
argument_list|,
specifier|const
name|FileSpec
operator|*
name|crash_file_path
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Static function that can be used with the \b host function
comment|/// Host::StartMonitoringChildProcess ().
comment|///
comment|/// This function can be used by lldb_private::Process subclasses
comment|/// when they want to watch for a local process and have its exit
comment|/// status automatically set when the host child process exits.
comment|/// Subclasses should call Host::StartMonitoringChildProcess ()
comment|/// with:
comment|///     callback = Process::SetHostProcessExitStatus
comment|///     callback_baton = NULL
comment|///     pid = Process::GetID()
comment|///     monitor_signals = false
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|SetProcessExitStatus
argument_list|(
name|void
operator|*
name|callback_baton
argument_list|,
comment|// The callback baton which should be set to NULL
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
comment|// The process ID we want to monitor
name|bool
name|exited
argument_list|,
name|int
name|signo
argument_list|,
comment|// Zero for no signal
name|int
name|status
argument_list|)
decl_stmt|;
comment|// Exit value of process if signal is zero
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetUniqueID
argument_list|()
specifier|const
block|{
return|return
name|m_process_unique_id
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Check if a plug-in instance can debug the file in \a module.
comment|///
comment|/// Each plug-in is given a chance to say whether it can debug
comment|/// the file in \a module. If the Process plug-in instance can
comment|/// debug a file on the current system, it should return \b true.
comment|///
comment|/// @return
comment|///     Returns \b true if this Process plug-in instance can
comment|///     debug the executable, \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|CanDebug
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|bool
name|plugin_specified_by_name
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// This object is about to be destroyed, do any necessary cleanup.
comment|///
comment|/// Subclasses that override this method should always call this
comment|/// superclass method.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Finalize
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return whether this object is valid (i.e. has not been finalized.)
comment|///
comment|/// @return
comment|///     Returns \b true if this Process has not been finalized
comment|///     and \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_finalize_called
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return a multi-word command object that can be used to expose
comment|/// plug-in specific commands.
comment|///
comment|/// This object will be used to resolve plug-in commands and can be
comment|/// triggered by a call to:
comment|///
comment|///     (lldb) process commmand<args>
comment|///
comment|/// @return
comment|///     A CommandObject which can be one of the concrete subclasses
comment|///     of CommandObject like CommandObjectRaw, CommandObjectParsed,
comment|///     or CommandObjectMultiword.
comment|//------------------------------------------------------------------
name|virtual
name|CommandObject
modifier|*
name|GetPluginCommandObject
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Launch a new process.
comment|///
comment|/// Launch a new process by spawning a new process using the
comment|/// target object's executable module's file as the file to launch.
comment|/// Arguments are given in \a argv, and the environment variables
comment|/// are in \a envp. Standard input and output files can be
comment|/// optionally re-directed to \a stdin_path, \a stdout_path, and
comment|/// \a stderr_path.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses. It will first call Process::WillLaunch (Module *)
comment|/// and if that returns \b true, Process::DoLaunch (Module*,
comment|/// char const *[],char const *[],const char *,const char *,
comment|/// const char *) will be called to actually do the launching. If
comment|/// DoLaunch returns \b true, then Process::DidLaunch() will be
comment|/// called.
comment|///
comment|/// @param[in] argv
comment|///     The argument array.
comment|///
comment|/// @param[in] envp
comment|///     The environment array.
comment|///
comment|/// @param[in] launch_flags
comment|///     Flags to modify the launch (@see lldb::LaunchFlags)
comment|///
comment|/// @param[in] stdin_path
comment|///     The path to use when re-directing the STDIN of the new
comment|///     process. If all stdXX_path arguments are NULL, a pseudo
comment|///     terminal will be used.
comment|///
comment|/// @param[in] stdout_path
comment|///     The path to use when re-directing the STDOUT of the new
comment|///     process. If all stdXX_path arguments are NULL, a pseudo
comment|///     terminal will be used.
comment|///
comment|/// @param[in] stderr_path
comment|///     The path to use when re-directing the STDERR of the new
comment|///     process. If all stdXX_path arguments are NULL, a pseudo
comment|///     terminal will be used.
comment|///
comment|/// @param[in] working_directory
comment|///     The working directory to have the child process run in
comment|///
comment|/// @return
comment|///     An error object. Call GetID() to get the process ID if
comment|///     the error object is success.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|Launch
parameter_list|(
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|)
function_decl|;
name|virtual
name|Error
name|LoadCore
parameter_list|()
function_decl|;
name|virtual
name|Error
name|DoLoadCore
parameter_list|()
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support loading core files."
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the dynamic loader plug-in for this process.
comment|///
comment|/// The default action is to let the DynamicLoader plug-ins check
comment|/// the main executable and the DynamicLoader will select itself
comment|/// automatically. Subclasses can override this if inspecting the
comment|/// executable is not desired, or if Process subclasses can only
comment|/// use a specific DynamicLoader plug-in.
comment|//------------------------------------------------------------------
name|virtual
name|DynamicLoader
modifier|*
name|GetDynamicLoader
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the system runtime plug-in for this process.
comment|///
comment|/// @return
comment|///   Returns a pointer to the SystemRuntime plugin for this Process
comment|///   if one is available.  Else returns NULL.
comment|//------------------------------------------------------------------
name|virtual
name|SystemRuntime
modifier|*
name|GetSystemRuntime
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Attach to an existing process using the process attach info.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses. It will first call WillAttach (lldb::pid_t)
comment|/// or WillAttach (const char *), and if that returns \b
comment|/// true, DoAttach (lldb::pid_t) or DoAttach (const char *) will
comment|/// be called to actually do the attach. If DoAttach returns \b
comment|/// true, then Process::DidAttach() will be called.
comment|///
comment|/// @param[in] pid
comment|///     The process ID that we should attempt to attach to.
comment|///
comment|/// @return
comment|///     Returns \a pid if attaching was successful, or
comment|///     LLDB_INVALID_PROCESS_ID if attaching fails.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|Attach
parameter_list|(
name|ProcessAttachInfo
modifier|&
name|attach_info
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Attach to a remote system via a URL
comment|///
comment|/// @param[in] strm
comment|///     A stream where output intended for the user
comment|///     (if the driver has a way to display that) generated during
comment|///     the connection.  This may be NULL if no output is needed.A
comment|///
comment|/// @param[in] remote_url
comment|///     The URL format that we are connecting to.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|ConnectRemote
parameter_list|(
name|Stream
modifier|*
name|strm
parameter_list|,
specifier|const
name|char
modifier|*
name|remote_url
parameter_list|)
function_decl|;
name|bool
name|GetShouldDetach
argument_list|()
specifier|const
block|{
return|return
name|m_should_detach
return|;
block|}
name|void
name|SetShouldDetach
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_should_detach
operator|=
name|b
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the image information address for the current process.
comment|///
comment|/// Some runtimes have system functions that can help dynamic
comment|/// loaders locate the dynamic loader information needed to observe
comment|/// shared libraries being loaded or unloaded. This function is
comment|/// in the Process interface (as opposed to the DynamicLoader
comment|/// interface) to ensure that remote debugging can take advantage of
comment|/// this functionality.
comment|///
comment|/// @return
comment|///     The address of the dynamic loader information, or
comment|///     LLDB_INVALID_ADDRESS if this is not supported by this
comment|///     interface.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Load a shared library into this process.
comment|///
comment|/// Try and load a shared library into the current process. This
comment|/// call might fail in the dynamic loader plug-in says it isn't safe
comment|/// to try and load shared libraries at the moment.
comment|///
comment|/// @param[in] image_spec
comment|///     The image file spec that points to the shared library that
comment|///     you want to load.
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
name|virtual
name|uint32_t
name|LoadImage
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|image_spec
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
name|virtual
name|Error
name|UnloadImage
parameter_list|(
name|uint32_t
name|image_token
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Register for process and thread notifications.
comment|///
comment|/// Clients can register nofication callbacks by filling out a
comment|/// Process::Notifications structure and calling this function.
comment|///
comment|/// @param[in] callbacks
comment|///     A structure that contains the notification baton and
comment|///     callback functions.
comment|///
comment|/// @see Process::Notifications
comment|//------------------------------------------------------------------
ifndef|#
directive|ifndef
name|SWIG
name|void
name|RegisterNotificationCallbacks
argument_list|(
specifier|const
name|Process
operator|::
name|Notifications
operator|&
name|callbacks
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|//------------------------------------------------------------------
comment|/// Unregister for process and thread notifications.
comment|///
comment|/// Clients can unregister nofication callbacks by passing a copy of
comment|/// the original baton and callbacks in \a callbacks.
comment|///
comment|/// @param[in] callbacks
comment|///     A structure that contains the notification baton and
comment|///     callback functions.
comment|///
comment|/// @return
comment|///     Returns \b true if the notification callbacks were
comment|///     successfully removed from the process, \b false otherwise.
comment|///
comment|/// @see Process::Notifications
comment|//------------------------------------------------------------------
ifndef|#
directive|ifndef
name|SWIG
name|bool
name|UnregisterNotificationCallbacks
argument_list|(
specifier|const
name|Process
operator|::
name|Notifications
operator|&
name|callbacks
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|//==================================================================
comment|// Built in Process Control functions
comment|//==================================================================
comment|//------------------------------------------------------------------
comment|/// Resumes all of a process's threads as configured using the
comment|/// Thread run control functions.
comment|///
comment|/// Threads for a process should be updated with one of the run
comment|/// control actions (resume, step, or suspend) that they should take
comment|/// when the process is resumed. If no run control action is given
comment|/// to a thread it will be resumed by default.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses. This function will take care of disabling any
comment|/// breakpoints that threads may be stopped at, single stepping, and
comment|/// re-enabling breakpoints, and enabling the basic flow control
comment|/// that the plug-in instances need not worry about.
comment|///
comment|/// N.B. This function also sets the Write side of the Run Lock,
comment|/// which is unset when the corresponding stop event is pulled off
comment|/// the Public Event Queue.  If you need to resume the process without
comment|/// setting the Run Lock, use PrivateResume (though you should only do
comment|/// that from inside the Process class.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|///
comment|/// @see Thread:Resume()
comment|/// @see Thread:Step()
comment|/// @see Thread:Suspend()
comment|//------------------------------------------------------------------
name|Error
name|Resume
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Halts a running process.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses.
comment|/// If the process is successfully halted, a eStateStopped
comment|/// process event with GetInterrupted will be broadcast.  If false, we will
comment|/// halt the process with no events generated by the halt.
comment|///
comment|/// @param[in] clear_thread_plans
comment|///     If true, when the process stops, clear all thread plans.
comment|///
comment|/// @return
comment|///     Returns an error object.  If the error is empty, the process is halted.
comment|///     otherwise the halt has failed.
comment|//------------------------------------------------------------------
name|Error
name|Halt
parameter_list|(
name|bool
name|clear_thread_plans
init|=
name|false
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Detaches from a running or stopped process.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses.
comment|///
comment|/// @param[in] keep_stopped
comment|///     If true, don't resume the process on detach.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|Error
name|Detach
parameter_list|(
name|bool
name|keep_stopped
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Kills the process and shuts down all threads that were spawned
comment|/// to track and monitor the process.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|Error
name|Destroy
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Sends a process a UNIX signal \a signal.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|Error
name|Signal
parameter_list|(
name|int
name|signal
parameter_list|)
function_decl|;
name|virtual
name|UnixSignals
modifier|&
name|GetUnixSignals
parameter_list|()
block|{
return|return
name|m_unix_signals
return|;
block|}
comment|//==================================================================
comment|// Plug-in Process Control Overrides
comment|//==================================================================
comment|//------------------------------------------------------------------
comment|/// Called before attaching to a process.
comment|///
comment|/// Allow Process plug-ins to execute some code before attaching a
comment|/// process.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|WillAttachToProcessWithID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
block|{
return|return
name|Error
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called before attaching to a process.
comment|///
comment|/// Allow Process plug-ins to execute some code before attaching a
comment|/// process.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|WillAttachToProcessWithName
parameter_list|(
specifier|const
name|char
modifier|*
name|process_name
parameter_list|,
name|bool
name|wait_for_launch
parameter_list|)
block|{
return|return
name|Error
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Attach to a remote system via a URL
comment|///
comment|/// @param[in] strm
comment|///     A stream where output intended for the user
comment|///     (if the driver has a way to display that) generated during
comment|///     the connection.  This may be NULL if no output is needed.A
comment|///
comment|/// @param[in] remote_url
comment|///     The URL format that we are connecting to.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoConnectRemote
parameter_list|(
name|Stream
modifier|*
name|strm
parameter_list|,
specifier|const
name|char
modifier|*
name|remote_url
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorString
argument_list|(
literal|"remote connections are not supported"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Attach to an existing process using a process ID.
comment|///
comment|/// @param[in] pid
comment|///     The process ID that we should attempt to attach to.
comment|///
comment|/// @return
comment|///     Returns \a pid if attaching was successful, or
comment|///     LLDB_INVALID_PROCESS_ID if attaching fails.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoAttachToProcessWithID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support attaching to a process by pid"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Attach to an existing process using a process ID.
comment|///
comment|/// @param[in] pid
comment|///     The process ID that we should attempt to attach to.
comment|///
comment|/// @param[in] attach_info
comment|///     Information on how to do the attach. For example, GetUserID()
comment|///     will return the uid to attach as.
comment|///
comment|/// @return
comment|///     Returns \a pid if attaching was successful, or
comment|///     LLDB_INVALID_PROCESS_ID if attaching fails.
comment|/// hanming : need flag
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoAttachToProcessWithID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
specifier|const
name|ProcessAttachInfo
operator|&
name|attach_info
argument_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support attaching to a process by pid"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Attach to an existing process using a partial process name.
comment|///
comment|/// @param[in] process_name
comment|///     The name of the process to attach to.
comment|///
comment|/// @param[in] attach_info
comment|///     Information on how to do the attach. For example, GetUserID()
comment|///     will return the uid to attach as.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoAttachToProcessWithName
parameter_list|(
specifier|const
name|char
modifier|*
name|process_name
parameter_list|,
specifier|const
name|ProcessAttachInfo
modifier|&
name|attach_info
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorString
argument_list|(
literal|"attach by name is not supported"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called after attaching a process.
comment|///
comment|/// Allow Process plug-ins to execute some code after attaching to
comment|/// a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidAttach
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Called after a process re-execs itself.
comment|///
comment|/// Allow Process plug-ins to execute some code after a process has
comment|/// exec'ed itself. Subclasses typically should override DoDidExec()
comment|/// as the lldb_private::Process class needs to remove its dynamic
comment|/// loader, runtime, ABI and other plug-ins, as well as unload all
comment|/// shared libraries.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidExec
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Subclasses of Process should implement this function if they
comment|/// need to do anything after a process exec's itself.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DoDidExec
parameter_list|()
block|{     }
comment|//------------------------------------------------------------------
comment|/// Called before launching to a process.
comment|///
comment|/// Allow Process plug-ins to execute some code before launching a
comment|/// process.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|WillLaunch
parameter_list|(
name|Module
modifier|*
name|module
parameter_list|)
block|{
return|return
name|Error
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Launch a new process.
comment|///
comment|/// Launch a new process by spawning a new process using \a module's
comment|/// file as the file to launch. Arguments are given in \a argv,
comment|/// and the environment variables are in \a envp. Standard input
comment|/// and output files can be optionally re-directed to \a stdin_path,
comment|/// \a stdout_path, and \a stderr_path.
comment|///
comment|/// @param[in] module
comment|///     The module from which to extract the file specification and
comment|///     launch.
comment|///
comment|/// @param[in] argv
comment|///     The argument array.
comment|///
comment|/// @param[in] envp
comment|///     The environment array.
comment|///
comment|/// @param[in] launch_flags
comment|///     Flags to modify the launch (@see lldb::LaunchFlags)
comment|///
comment|/// @param[in] stdin_path
comment|///     The path to use when re-directing the STDIN of the new
comment|///     process. If all stdXX_path arguments are NULL, a pseudo
comment|///     terminal will be used.
comment|///
comment|/// @param[in] stdout_path
comment|///     The path to use when re-directing the STDOUT of the new
comment|///     process. If all stdXX_path arguments are NULL, a pseudo
comment|///     terminal will be used.
comment|///
comment|/// @param[in] stderr_path
comment|///     The path to use when re-directing the STDERR of the new
comment|///     process. If all stdXX_path arguments are NULL, a pseudo
comment|///     terminal will be used.
comment|///
comment|/// @param[in] working_directory
comment|///     The working directory to have the child process run in
comment|///
comment|/// @return
comment|///     A new valid process ID, or LLDB_INVALID_PROCESS_ID if
comment|///     launching fails.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoLaunch
parameter_list|(
name|Module
modifier|*
name|exe_module
parameter_list|,
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support launching processes"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called after launching a process.
comment|///
comment|/// Allow Process plug-ins to execute some code after launching
comment|/// a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidLaunch
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Called before resuming to a process.
comment|///
comment|/// Allow Process plug-ins to execute some code before resuming a
comment|/// process.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|WillResume
parameter_list|()
block|{
return|return
name|Error
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Resumes all of a process's threads as configured using the
comment|/// Thread run control functions.
comment|///
comment|/// Threads for a process should be updated with one of the run
comment|/// control actions (resume, step, or suspend) that they should take
comment|/// when the process is resumed. If no run control action is given
comment|/// to a thread it will be resumed by default.
comment|///
comment|/// @return
comment|///     Returns \b true if the process successfully resumes using
comment|///     the thread run control actions, \b false otherwise.
comment|///
comment|/// @see Thread:Resume()
comment|/// @see Thread:Step()
comment|/// @see Thread:Suspend()
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoResume
parameter_list|()
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support resuming processes"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called after resuming a process.
comment|///
comment|/// Allow Process plug-ins to execute some code after resuming
comment|/// a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidResume
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Called before halting to a process.
comment|///
comment|/// Allow Process plug-ins to execute some code before halting a
comment|/// process.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|WillHalt
parameter_list|()
block|{
return|return
name|Error
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Halts a running process.
comment|///
comment|/// DoHalt must produce one and only one stop StateChanged event if it actually
comment|/// stops the process.  If the stop happens through some natural event (for
comment|/// instance a SIGSTOP), then forwarding that event will do.  Otherwise, you must
comment|/// generate the event manually.  Note also, the private event thread is stopped when
comment|/// DoHalt is run to prevent the events generated while halting to trigger
comment|/// other state changes before the halt is complete.
comment|///
comment|/// @param[out] caused_stop
comment|///     If true, then this Halt caused the stop, otherwise, the
comment|///     process was already stopped.
comment|///
comment|/// @return
comment|///     Returns \b true if the process successfully halts, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoHalt
parameter_list|(
name|bool
modifier|&
name|caused_stop
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support halting processes"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called after halting a process.
comment|///
comment|/// Allow Process plug-ins to execute some code after halting
comment|/// a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidHalt
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Called before detaching from a process.
comment|///
comment|/// Allow Process plug-ins to execute some code before detaching
comment|/// from a process.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|WillDetach
parameter_list|()
block|{
return|return
name|Error
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Detaches from a running or stopped process.
comment|///
comment|/// @return
comment|///     Returns \b true if the process successfully detaches, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoDetach
parameter_list|(
name|bool
name|keep_stopped
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support detaching from processes"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called after detaching from a process.
comment|///
comment|/// Allow Process plug-ins to execute some code after detaching
comment|/// from a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidDetach
parameter_list|()
block|{}
name|virtual
name|bool
name|DetachRequiresHalt
parameter_list|()
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called before sending a signal to a process.
comment|///
comment|/// Allow Process plug-ins to execute some code before sending a
comment|/// signal to a process.
comment|///
comment|/// @return
comment|///     Returns no error if it is safe to proceed with a call to
comment|///     Process::DoSignal(int), otherwise an error describing what
comment|///     prevents the signal from being sent.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|WillSignal
parameter_list|()
block|{
return|return
name|Error
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Sends a process a UNIX signal \a signal.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoSignal
parameter_list|(
name|int
name|signal
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support senging signals to processes"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
name|virtual
name|Error
name|WillDestroy
parameter_list|()
block|{
return|return
name|Error
argument_list|()
return|;
block|}
name|virtual
name|Error
name|DoDestroy
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|DidDestroy
parameter_list|()
block|{ }
name|virtual
name|bool
name|DestroyRequiresHalt
parameter_list|()
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Called after sending a signal to a process.
comment|///
comment|/// Allow Process plug-ins to execute some code after sending a
comment|/// signal to a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidSignal
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Currently called as part of ShouldStop.
comment|/// FIXME: Should really happen when the target stops before the
comment|/// event is taken from the queue...
comment|///
comment|/// This callback is called as the event
comment|/// is about to be queued up to allow Process plug-ins to execute
comment|/// some code prior to clients being notified that a process was
comment|/// stopped. Common operations include updating the thread list,
comment|/// invalidating any thread state (registers, stack, etc) prior to
comment|/// letting the notification go out.
comment|///
comment|//------------------------------------------------------------------
name|virtual
name|void
name|RefreshStateAfterStop
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the target object pointer for this module.
comment|///
comment|/// @return
comment|///     A Target object pointer to the target that owns this
comment|///     module.
comment|//------------------------------------------------------------------
name|Target
modifier|&
name|GetTarget
parameter_list|()
block|{
return|return
name|m_target
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the const target object pointer for this module.
comment|///
comment|/// @return
comment|///     A const Target object pointer to the target that owns this
comment|///     module.
comment|//------------------------------------------------------------------
specifier|const
name|Target
operator|&
name|GetTarget
argument_list|()
specifier|const
block|{
return|return
name|m_target
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Flush all data in the process.
comment|///
comment|/// Flush the memory caches, all threads, and any other cached data
comment|/// in the process.
comment|///
comment|/// This function can be called after a world changing event like
comment|/// adding a new symbol file, or after the process makes a large
comment|/// context switch (from boot ROM to booted into an OS).
comment|//------------------------------------------------------------------
name|void
name|Flush
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the current process state.
comment|///
comment|/// @return
comment|///     The current state of the process.
comment|///
comment|/// @see lldb::StateType
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
expr_stmt|;
name|ExecutionResults
name|RunThreadPlan
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|ThreadPlanSP
operator|&
name|thread_plan_sp
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|,
name|Stream
operator|&
name|errors
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|ExecutionResultAsCString
parameter_list|(
name|ExecutionResults
name|result
parameter_list|)
function_decl|;
name|void
name|GetStatus
parameter_list|(
name|Stream
modifier|&
name|ostrm
parameter_list|)
function_decl|;
name|size_t
name|GetThreadStatus
parameter_list|(
name|Stream
modifier|&
name|ostrm
parameter_list|,
name|bool
name|only_threads_with_stop_reason
parameter_list|,
name|uint32_t
name|start_frame
parameter_list|,
name|uint32_t
name|num_frames
parameter_list|,
name|uint32_t
name|num_frames_with_source
parameter_list|)
function_decl|;
name|void
name|SendAsyncInterrupt
parameter_list|()
function_decl|;
name|protected
label|:
name|void
name|SetState
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|StateType
name|GetPrivateState
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// The "private" side of resuming a process.  This doesn't alter the
comment|/// state of m_run_lock, but just causes the process to resume.
comment|///
comment|/// @return
comment|///     An Error object describing the success or failure of the resume.
comment|//------------------------------------------------------------------
name|Error
name|PrivateResume
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Called internally
comment|//------------------------------------------------------------------
name|void
name|CompleteAttach
parameter_list|()
function_decl|;
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Get the exit status for a process.
comment|///
comment|/// @return
comment|///     The process's return code, or -1 if the current process
comment|///     state is not eStateExited.
comment|//------------------------------------------------------------------
name|int
name|GetExitStatus
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get a textual description of what the process exited.
comment|///
comment|/// @return
comment|///     The textual description of why the process exited, or NULL
comment|///     if there is no description available.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetExitDescription
parameter_list|()
function_decl|;
name|virtual
name|void
name|DidExit
parameter_list|()
block|{     }
comment|//------------------------------------------------------------------
comment|/// Get the Modification ID of the process.
comment|///
comment|/// @return
comment|///     The modification ID of the process.
comment|//------------------------------------------------------------------
name|ProcessModID
name|GetModID
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
return|;
block|}
specifier|const
name|ProcessModID
operator|&
name|GetModIDRef
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
return|;
block|}
name|uint32_t
name|GetStopID
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
operator|.
name|GetStopID
argument_list|()
return|;
block|}
name|uint32_t
name|GetResumeID
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
operator|.
name|GetResumeID
argument_list|()
return|;
block|}
name|uint32_t
name|GetLastUserExpressionResumeID
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
operator|.
name|GetLastUserExpressionResumeID
argument_list|()
return|;
block|}
name|uint32_t
name|GetLastNaturalStopID
parameter_list|()
block|{
return|return
name|m_mod_id
operator|.
name|GetLastNaturalStopID
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the process exit status (return code).
comment|///
comment|/// Sometimes a child exits and the exit can be detected by global
comment|/// functions (signal handler for SIGCHLD for example). This
comment|/// accessor allows the exit status to be set from an external
comment|/// source.
comment|///
comment|/// Setting this will cause a eStateExited event to be posted to
comment|/// the process event queue.
comment|///
comment|/// @param[in] exit_status
comment|///     The value for the process's return code.
comment|///
comment|/// @see lldb::StateType
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|SetExitStatus
parameter_list|(
name|int
name|exit_status
parameter_list|,
specifier|const
name|char
modifier|*
name|cstr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check if a process is still alive.
comment|///
comment|/// @return
comment|///     Returns \b true if the process is still valid, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|IsAlive
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Before lldb detaches from a process, it warns the user that they are about to lose their debug session.
comment|/// In some cases, this warning doesn't need to be emitted -- for instance, with core file debugging where
comment|/// the user can reconstruct the "state" by simply re-running the debugger on the core file.
comment|///
comment|/// @return
comment|//      true if the user should be warned about detaching from this process.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|WarnBeforeDetach
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Actually do the reading of memory from a process.
comment|///
comment|/// Subclasses must override this function and can return fewer
comment|/// bytes than requested when memory requests are too large. This
comment|/// class will break up the memory requests and keep advancing the
comment|/// arguments along as needed.
comment|///
comment|/// @param[in] vm_addr
comment|///     A virtual load address that indicates where to start reading
comment|///     memory from.
comment|///
comment|/// @param[in] size
comment|///     The number of bytes to read.
comment|///
comment|/// @param[out] buf
comment|///     A byte buffer that is at least \a size bytes long that
comment|///     will receive the memory bytes.
comment|///
comment|/// @return
comment|///     The number of bytes that were actually read into \a buf.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|DoReadMemory
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
name|Error
operator|&
name|error
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Read of memory from a process.
comment|///
comment|/// This function will read memory from the current process's
comment|/// address space and remove any traps that may have been inserted
comment|/// into the memory.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses, the subclasses should implement
comment|/// Process::DoReadMemory (lldb::addr_t, size_t, void *).
comment|///
comment|/// @param[in] vm_addr
comment|///     A virtual load address that indicates where to start reading
comment|///     memory from.
comment|///
comment|/// @param[out] buf
comment|///     A byte buffer that is at least \a size bytes long that
comment|///     will receive the memory bytes.
comment|///
comment|/// @param[in] size
comment|///     The number of bytes to read.
comment|///
comment|/// @return
comment|///     The number of bytes that were actually read into \a buf. If
comment|///     the returned number is greater than zero, yet less than \a
comment|///     size, then this function will get called again with \a
comment|///     vm_addr, \a buf, and \a size updated appropriately. Zero is
comment|///     returned to indicate an error.
comment|//------------------------------------------------------------------
name|virtual
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
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Read a NULL terminated string from memory
comment|///
comment|/// This function will read a cache page at a time until a NULL
comment|/// string terminator is found. It will stop reading if an aligned
comment|/// sequence of NULL termination \a type_width bytes is not found
comment|/// before reading \a cstr_max_len bytes.  The results are always
comment|/// guaranteed to be NULL terminated, and that no more than
comment|/// (max_bytes - type_width) bytes will be read.
comment|///
comment|/// @param[in] vm_addr
comment|///     The virtual load address to start the memory read.
comment|///
comment|/// @param[in] str
comment|///     A character buffer containing at least max_bytes.
comment|///
comment|/// @param[in] max_bytes
comment|///     The maximum number of bytes to read.
comment|///
comment|/// @param[in] error
comment|///     The error status of the read operation.
comment|///
comment|/// @param[in] type_width
comment|///     The size of the null terminator (1 to 4 bytes per
comment|///     character).  Defaults to 1.
comment|///
comment|/// @return
comment|///     The error status or the number of bytes prior to the null terminator.
comment|//------------------------------------------------------------------
name|size_t
name|ReadStringFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
name|char
operator|*
name|str
argument_list|,
name|size_t
name|max_bytes
argument_list|,
name|Error
operator|&
name|error
argument_list|,
name|size_t
name|type_width
operator|=
literal|1
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Read a NULL terminated C string from memory
comment|///
comment|/// This function will read a cache page at a time until the NULL
comment|/// C string terminator is found. It will stop reading if the NULL
comment|/// termination byte isn't found before reading \a cstr_max_len
comment|/// bytes, and the results are always guaranteed to be NULL
comment|/// terminated (at most cstr_max_len - 1 bytes will be read).
comment|//------------------------------------------------------------------
name|size_t
name|ReadCStringFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
name|char
operator|*
name|cstr
argument_list|,
name|size_t
name|cstr_max_len
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|size_t
name|ReadCStringFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
name|std
operator|::
name|string
operator|&
name|out_str
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|size_t
name|ReadMemoryFromInferior
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
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Reads an unsigned integer of the specified byte size from
comment|/// process memory.
comment|///
comment|/// @param[in] load_addr
comment|///     A load address of the integer to read.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in byte of the integer to read.
comment|///
comment|/// @param[in] fail_value
comment|///     The value to return if we fail to read an integer.
comment|///
comment|/// @param[out] error
comment|///     An error that indicates the success or failure of this
comment|///     operation. If error indicates success (error.Success()),
comment|///     then the value returned can be trusted, otherwise zero
comment|///     will be returned.
comment|///
comment|/// @return
comment|///     The unsigned integer that was read from the process memory
comment|///     space. If the integer was smaller than a uint64_t, any
comment|///     unused upper bytes will be zero filled. If the process
comment|///     byte order differs from the host byte order, the integer
comment|///     value will be appropriately byte swapped into host byte
comment|///     order.
comment|//------------------------------------------------------------------
name|uint64_t
name|ReadUnsignedIntegerFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|size_t
name|byte_size
argument_list|,
name|uint64_t
name|fail_value
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|ReadPointerFromMemory
argument_list|(
argument|lldb::addr_t vm_addr
argument_list|,
argument|Error&error
argument_list|)
expr_stmt|;
name|bool
name|WritePointerToMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|ptr_value
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Actually do the writing of memory to a process.
comment|///
comment|/// @param[in] vm_addr
comment|///     A virtual load address that indicates where to start writing
comment|///     memory to.
comment|///
comment|/// @param[in] buf
comment|///     A byte buffer that is at least \a size bytes long that
comment|///     contains the data to write.
comment|///
comment|/// @param[in] size
comment|///     The number of bytes to write.
comment|///
comment|/// @param[out] error
comment|///     An error value in case the memory write fails.
comment|///
comment|/// @return
comment|///     The number of bytes that were actually written.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|DoWriteMemory
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
name|Error
operator|&
name|error
argument_list|)
block|{
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support writing to processes"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Write all or part of a scalar value to memory.
comment|///
comment|/// The value contained in \a scalar will be swapped to match the
comment|/// byte order of the process that is being debugged. If \a size is
comment|/// less than the size of scalar, the least significate \a size bytes
comment|/// from scalar will be written. If \a size is larger than the byte
comment|/// size of scalar, then the extra space will be padded with zeros
comment|/// and the scalar value will be placed in the least significant
comment|/// bytes in memory.
comment|///
comment|/// @param[in] vm_addr
comment|///     A virtual load address that indicates where to start writing
comment|///     memory to.
comment|///
comment|/// @param[in] scalar
comment|///     The scalar to write to the debugged process.
comment|///
comment|/// @param[in] size
comment|///     This value can be smaller or larger than the scalar value
comment|///     itself. If \a size is smaller than the size of \a scalar,
comment|///     the least significant bytes in \a scalar will be used. If
comment|///     \a size is larger than the byte size of \a scalar, then
comment|///     the extra space will be padded with zeros. If \a size is
comment|///     set to UINT32_MAX, then the size of \a scalar will be used.
comment|///
comment|/// @param[out] error
comment|///     An error value in case the memory write fails.
comment|///
comment|/// @return
comment|///     The number of bytes that were actually written.
comment|//------------------------------------------------------------------
name|size_t
name|WriteScalarToMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
specifier|const
name|Scalar
operator|&
name|scalar
argument_list|,
name|size_t
name|size
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|size_t
name|ReadScalarIntegerFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|uint32_t
name|byte_size
argument_list|,
name|bool
name|is_signed
argument_list|,
name|Scalar
operator|&
name|scalar
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Write memory to a process.
comment|///
comment|/// This function will write memory to the current process's
comment|/// address space and maintain any traps that might be present due
comment|/// to software breakpoints.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses, the subclasses should implement
comment|/// Process::DoWriteMemory (lldb::addr_t, size_t, void *).
comment|///
comment|/// @param[in] vm_addr
comment|///     A virtual load address that indicates where to start writing
comment|///     memory to.
comment|///
comment|/// @param[in] buf
comment|///     A byte buffer that is at least \a size bytes long that
comment|///     contains the data to write.
comment|///
comment|/// @param[in] size
comment|///     The number of bytes to write.
comment|///
comment|/// @return
comment|///     The number of bytes that were actually written.
comment|//------------------------------------------------------------------
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
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Actually allocate memory in the process.
comment|///
comment|/// This function will allocate memory in the process's address
comment|/// space.  This can't rely on the generic function calling mechanism,
comment|/// since that requires this function.
comment|///
comment|/// @param[in] size
comment|///     The size of the allocation requested.
comment|///
comment|/// @return
comment|///     The address of the allocated buffer in the process, or
comment|///     LLDB_INVALID_ADDRESS if the allocation failed.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|DoAllocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|Error&error
argument_list|)
block|{
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support allocating in the debug process"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
block|;
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// The public interface to allocating memory in the process.
comment|///
comment|/// This function will allocate memory in the process's address
comment|/// space.  This can't rely on the generic function calling mechanism,
comment|/// since that requires this function.
comment|///
comment|/// @param[in] size
comment|///     The size of the allocation requested.
comment|///
comment|/// @param[in] permissions
comment|///     Or together any of the lldb::Permissions bits.  The permissions on
comment|///     a given memory allocation can't be changed after allocation.  Note
comment|///     that a block that isn't set writable can still be written on from lldb,
comment|///     just not by the process itself.
comment|///
comment|/// @param[in/out] error
comment|///     An error object to fill in if things go wrong.
comment|/// @return
comment|///     The address of the allocated buffer in the process, or
comment|///     LLDB_INVALID_ADDRESS if the allocation failed.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|AllocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|Error&error
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Resolve dynamically loaded indirect functions.
comment|///
comment|/// @param[in] address
comment|///     The load address of the indirect function to resolve.
comment|///
comment|/// @param[out] error
comment|///     An error value in case the resolve fails.
comment|///
comment|/// @return
comment|///     The address of the resolved function.
comment|///     LLDB_INVALID_ADDRESS if the resolution failed.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|ResolveIndirectFunction
argument_list|(
specifier|const
name|Address
operator|*
name|address
argument_list|,
name|Error
operator|&
name|error
argument_list|)
expr_stmt|;
name|virtual
name|Error
name|GetMemoryRegionInfo
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|MemoryRegionInfo
operator|&
name|range_info
argument_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorString
argument_list|(
literal|"Process::GetMemoryRegionInfo() not supported"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
name|virtual
name|Error
name|GetWatchpointSupportInfo
parameter_list|(
name|uint32_t
modifier|&
name|num
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|num
operator|=
literal|0
expr_stmt|;
name|error
operator|.
name|SetErrorString
argument_list|(
literal|"Process::GetWatchpointSupportInfo() not supported"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
name|virtual
name|Error
name|GetWatchpointSupportInfo
parameter_list|(
name|uint32_t
modifier|&
name|num
parameter_list|,
name|bool
modifier|&
name|after
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|num
operator|=
literal|0
expr_stmt|;
name|after
operator|=
name|true
expr_stmt|;
name|error
operator|.
name|SetErrorString
argument_list|(
literal|"Process::GetWatchpointSupportInfo() not supported"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
name|lldb
operator|::
name|ModuleSP
name|ReadModuleFromMemory
argument_list|(
argument|const FileSpec& file_spec
argument_list|,
argument|lldb::addr_t header_addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Attempt to get the attributes for a region of memory in the process.
comment|///
comment|/// It may be possible for the remote debug server to inspect attributes
comment|/// for a region of memory in the process, such as whether there is a
comment|/// valid page of memory at a given address or whether that page is
comment|/// readable/writable/executable by the process.
comment|///
comment|/// @param[in] load_addr
comment|///     The address of interest in the process.
comment|///
comment|/// @param[out] permissions
comment|///     If this call returns successfully, this bitmask will have
comment|///     its Permissions bits set to indicate whether the region is
comment|///     readable/writable/executable.  If this call fails, the
comment|///     bitmask values are undefined.
comment|///
comment|/// @return
comment|///     Returns true if it was able to determine the attributes of the
comment|///     memory region.  False if not.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetLoadAddressPermissions
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|uint32_t
operator|&
name|permissions
argument_list|)
block|{
name|MemoryRegionInfo
name|range_info
decl_stmt|;
name|permissions
operator|=
literal|0
expr_stmt|;
name|Error
name|error
argument_list|(
name|GetMemoryRegionInfo
argument_list|(
name|load_addr
argument_list|,
name|range_info
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|error
operator|.
name|Success
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|range_info
operator|.
name|GetReadable
argument_list|()
operator|==
name|MemoryRegionInfo
operator|::
name|eDontKnow
operator|||
name|range_info
operator|.
name|GetWritable
argument_list|()
operator|==
name|MemoryRegionInfo
operator|::
name|eDontKnow
operator|||
name|range_info
operator|.
name|GetExecutable
argument_list|()
operator|==
name|MemoryRegionInfo
operator|::
name|eDontKnow
condition|)
block|{
return|return
name|false
return|;
block|}
if|if
condition|(
name|range_info
operator|.
name|GetReadable
argument_list|()
operator|==
name|MemoryRegionInfo
operator|::
name|eYes
condition|)
name|permissions
operator||=
name|lldb
operator|::
name|ePermissionsReadable
expr_stmt|;
if|if
condition|(
name|range_info
operator|.
name|GetWritable
argument_list|()
operator|==
name|MemoryRegionInfo
operator|::
name|eYes
condition|)
name|permissions
operator||=
name|lldb
operator|::
name|ePermissionsWritable
expr_stmt|;
if|if
condition|(
name|range_info
operator|.
name|GetExecutable
argument_list|()
operator|==
name|MemoryRegionInfo
operator|::
name|eYes
condition|)
name|permissions
operator||=
name|lldb
operator|::
name|ePermissionsExecutable
expr_stmt|;
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Determines whether executing JIT-compiled code in this process
comment|/// is possible.
comment|///
comment|/// @return
comment|///     True if execution of JIT code is possible; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|CanJIT
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Sets whether executing JIT-compiled code in this process
comment|/// is possible.
comment|///
comment|/// @param[in] can_jit
comment|///     True if execution of JIT code is possible; false otherwise.
comment|//------------------------------------------------------------------
name|void
name|SetCanJIT
parameter_list|(
name|bool
name|can_jit
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Actually deallocate memory in the process.
comment|///
comment|/// This function will deallocate memory in the process's address
comment|/// space that was allocated with AllocateMemory.
comment|///
comment|/// @param[in] ptr
comment|///     A return value from AllocateMemory, pointing to the memory you
comment|///     want to deallocate.
comment|///
comment|/// @return
comment|///     \btrue if the memory was deallocated, \bfalse otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|DoDeallocateMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|ptr
argument_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support deallocating in the debug process"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// The public interface to deallocating memory in the process.
comment|///
comment|/// This function will deallocate memory in the process's address
comment|/// space that was allocated with AllocateMemory.
comment|///
comment|/// @param[in] ptr
comment|///     A return value from AllocateMemory, pointing to the memory you
comment|///     want to deallocate.
comment|///
comment|/// @return
comment|///     \btrue if the memory was deallocated, \bfalse otherwise.
comment|//------------------------------------------------------------------
name|Error
name|DeallocateMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|ptr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get any available STDOUT.
comment|///
comment|/// If the process was launched without supplying valid file paths
comment|/// for stdin, stdout, and stderr, then the Process class might
comment|/// try to cache the STDOUT for the process if it is able. Events
comment|/// will be queued indicating that there is STDOUT available that
comment|/// can be retrieved using this function.
comment|///
comment|/// @param[out] buf
comment|///     A buffer that will receive any STDOUT bytes that are
comment|///     currently available.
comment|///
comment|/// @param[out] buf_size
comment|///     The size in bytes for the buffer \a buf.
comment|///
comment|/// @return
comment|///     The number of bytes written into \a buf. If this value is
comment|///     equal to \a buf_size, another call to this function should
comment|///     be made to retrieve more STDOUT data.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|GetSTDOUT
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_size
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get any available STDERR.
comment|///
comment|/// If the process was launched without supplying valid file paths
comment|/// for stdin, stdout, and stderr, then the Process class might
comment|/// try to cache the STDERR for the process if it is able. Events
comment|/// will be queued indicating that there is STDERR available that
comment|/// can be retrieved using this function.
comment|///
comment|/// @param[out] buf
comment|///     A buffer that will receive any STDERR bytes that are
comment|///     currently available.
comment|///
comment|/// @param[out] buf_size
comment|///     The size in bytes for the buffer \a buf.
comment|///
comment|/// @return
comment|///     The number of bytes written into \a buf. If this value is
comment|///     equal to \a buf_size, another call to this function should
comment|///     be made to retrieve more STDERR data.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|GetSTDERR
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_size
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
name|virtual
name|size_t
name|PutSTDIN
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_size
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
block|{
name|error
operator|.
name|SetErrorString
argument_list|(
literal|"stdin unsupported"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get any available profile data.
comment|///
comment|/// @param[out] buf
comment|///     A buffer that will receive any profile data bytes that are
comment|///     currently available.
comment|///
comment|/// @param[out] buf_size
comment|///     The size in bytes for the buffer \a buf.
comment|///
comment|/// @return
comment|///     The number of bytes written into \a buf. If this value is
comment|///     equal to \a buf_size, another call to this function should
comment|///     be made to retrieve more profile data.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|GetAsyncProfileData
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_size
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|// Process Breakpoints
comment|//----------------------------------------------------------------------
name|size_t
name|GetSoftwareBreakpointTrapOpcode
parameter_list|(
name|BreakpointSite
modifier|*
name|bp_site
parameter_list|)
function_decl|;
name|virtual
name|Error
name|EnableBreakpointSite
parameter_list|(
name|BreakpointSite
modifier|*
name|bp_site
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support enabling breakpoints"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
name|virtual
name|Error
name|DisableBreakpointSite
parameter_list|(
name|BreakpointSite
modifier|*
name|bp_site
parameter_list|)
block|{
name|Error
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support disabling breakpoints"
argument_list|,
name|GetPluginName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
comment|// This is implemented completely using the lldb::Process API. Subclasses
comment|// don't need to implement this function unless the standard flow of
comment|// read existing opcode, write breakpoint opcode, verify breakpoint opcode
comment|// doesn't work for a specific process plug-in.
name|virtual
name|Error
name|EnableSoftwareBreakpoint
parameter_list|(
name|BreakpointSite
modifier|*
name|bp_site
parameter_list|)
function_decl|;
comment|// This is implemented completely using the lldb::Process API. Subclasses
comment|// don't need to implement this function unless the standard flow of
comment|// restoring original opcode in memory and verifying the restored opcode
comment|// doesn't work for a specific process plug-in.
name|virtual
name|Error
name|DisableSoftwareBreakpoint
parameter_list|(
name|BreakpointSite
modifier|*
name|bp_site
parameter_list|)
function_decl|;
name|BreakpointSiteList
modifier|&
name|GetBreakpointSiteList
parameter_list|()
function_decl|;
specifier|const
name|BreakpointSiteList
operator|&
name|GetBreakpointSiteList
argument_list|()
specifier|const
expr_stmt|;
name|void
name|DisableAllBreakpointSites
parameter_list|()
function_decl|;
name|Error
name|ClearBreakpointSiteByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|break_id
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|break_id_t
name|CreateBreakpointSite
argument_list|(
argument|const lldb::BreakpointLocationSP&owner
argument_list|,
argument|bool use_hardware
argument_list|)
expr_stmt|;
name|Error
name|DisableBreakpointSiteByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|break_id
argument_list|)
decl_stmt|;
name|Error
name|EnableBreakpointSiteByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|break_id
argument_list|)
decl_stmt|;
comment|// BreakpointLocations use RemoveOwnerFromBreakpointSite to remove
comment|// themselves from the owner's list of this breakpoint sites.
name|void
name|RemoveOwnerFromBreakpointSite
argument_list|(
name|lldb
operator|::
name|user_id_t
name|owner_id
argument_list|,
name|lldb
operator|::
name|user_id_t
name|owner_loc_id
argument_list|,
name|lldb
operator|::
name|BreakpointSiteSP
operator|&
name|bp_site_sp
argument_list|)
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// Process Watchpoints (optional)
comment|//----------------------------------------------------------------------
name|virtual
name|Error
name|EnableWatchpoint
parameter_list|(
name|Watchpoint
modifier|*
name|wp
parameter_list|,
name|bool
name|notify
init|=
name|true
parameter_list|)
function_decl|;
name|virtual
name|Error
name|DisableWatchpoint
parameter_list|(
name|Watchpoint
modifier|*
name|wp
parameter_list|,
name|bool
name|notify
init|=
name|true
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Thread Queries
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|UpdateThreadList
parameter_list|(
name|ThreadList
modifier|&
name|old_thread_list
parameter_list|,
name|ThreadList
modifier|&
name|new_thread_list
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|UpdateThreadListIfNeeded
parameter_list|()
function_decl|;
name|ThreadList
modifier|&
name|GetThreadList
parameter_list|()
block|{
return|return
name|m_thread_list
return|;
block|}
comment|// When ExtendedBacktraces are requested, the HistoryThreads that are
comment|// created need an owner -- they're saved here in the Process.  The
comment|// threads in this list are not iterated over - driver programs need to
comment|// request the extended backtrace calls starting from a root concrete
comment|// thread one by one.
name|ThreadList
modifier|&
name|GetExtendedThreadList
parameter_list|()
block|{
return|return
name|m_extended_thread_list
return|;
block|}
name|ThreadList
operator|::
name|ThreadIterable
name|Threads
argument_list|()
block|{
return|return
name|m_thread_list
operator|.
name|Threads
argument_list|()
return|;
block|}
name|uint32_t
name|GetNextThreadIndexID
parameter_list|(
name|uint64_t
name|thread_id
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ThreadSP
name|CreateOSPluginThread
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|lldb::addr_t context
argument_list|)
expr_stmt|;
comment|// Returns true if an index id has been assigned to a thread.
name|bool
name|HasAssignedIndexIDToThread
parameter_list|(
name|uint64_t
name|sb_thread_id
parameter_list|)
function_decl|;
comment|// Given a thread_id, it will assign a more reasonable index id for display to the user.
comment|// If the thread_id has previously been assigned, the same index id will be used.
name|uint32_t
name|AssignIndexIDToThread
parameter_list|(
name|uint64_t
name|thread_id
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Queue Queries
comment|//------------------------------------------------------------------
name|void
name|UpdateQueueListIfNeeded
parameter_list|()
function_decl|;
name|QueueList
modifier|&
name|GetQueueList
parameter_list|()
block|{
name|UpdateQueueListIfNeeded
argument_list|()
expr_stmt|;
return|return
name|m_queue_list
return|;
block|}
name|QueueList
operator|::
name|QueueIterable
name|Queues
argument_list|()
block|{
name|UpdateQueueListIfNeeded
argument_list|()
block|;
return|return
name|m_queue_list
operator|.
name|Queues
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Event Handling
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|StateType
name|GetNextEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
expr_stmt|;
comment|// Returns the process state when it is stopped. If specified, event_sp_ptr
comment|// is set to the event which triggered the stop. If wait_always = false,
comment|// and the process is already stopped, this function returns immediately.
name|lldb
operator|::
name|StateType
name|WaitForProcessToStop
argument_list|(
argument|const TimeValue *timeout
argument_list|,
argument|lldb::EventSP *event_sp_ptr = NULL
argument_list|,
argument|bool wait_always = true
argument_list|,
argument|Listener *hijack_listener = NULL
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|StateType
name|WaitForStateChangedEvents
argument_list|(
specifier|const
name|TimeValue
operator|*
name|timeout
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
name|Listener
operator|*
name|hijack_listener
argument_list|)
expr_stmt|;
comment|// Pass NULL to use builtin listener
name|Event
modifier|*
name|PeekAtStateChangedEvents
parameter_list|()
function_decl|;
name|class
name|ProcessEventHijacker
block|{
name|public
label|:
name|ProcessEventHijacker
argument_list|(
name|Process
operator|&
name|process
argument_list|,
name|Listener
operator|*
name|listener
argument_list|)
operator|:
name|m_process
argument_list|(
argument|process
argument_list|)
block|{
name|m_process
operator|.
name|HijackProcessEvents
argument_list|(
name|listener
argument_list|)
block|;         }
operator|~
name|ProcessEventHijacker
argument_list|()
block|{
name|m_process
operator|.
name|RestoreProcessEvents
argument_list|()
block|;         }
name|private
operator|:
name|Process
operator|&
name|m_process
expr_stmt|;
block|}
empty_stmt|;
name|friend
name|class
name|ProcessEventHijacker
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// If you need to ensure that you and only you will hear about some public
comment|/// event, then make a new listener, set to listen to process events, and
comment|/// then call this with that listener.  Then you will have to wait on that
comment|/// listener explicitly for events (rather than using the GetNextEvent& WaitFor*
comment|/// calls above.  Be sure to call RestoreProcessEvents when you are done.
comment|///
comment|/// @param[in] listener
comment|///     This is the new listener to whom all process events will be delivered.
comment|///
comment|/// @return
comment|///     Returns \b true if the new listener could be installed,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|HijackProcessEvents
parameter_list|(
name|Listener
modifier|*
name|listener
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Restores the process event broadcasting to its normal state.
comment|///
comment|//------------------------------------------------------------------
name|void
name|RestoreProcessEvents
parameter_list|()
function_decl|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|/// This is the part of the event handling that for a process event.
comment|/// It decides what to do with the event and returns true if the
comment|/// event needs to be propagated to the user, and false otherwise.
comment|/// If the event is not propagated, this call will most likely set
comment|/// the target to executing again.
comment|/// There is only one place where this call should be called, HandlePrivateEvent.
comment|/// Don't call it from anywhere else...
comment|///
comment|/// @param[in] event_ptr
comment|///     This is the event we are handling.
comment|///
comment|/// @return
comment|///     Returns \b true if the event should be reported to the
comment|///     user, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ShouldBroadcastEvent
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|public
label|:
specifier|const
name|lldb
operator|::
name|ABISP
operator|&
name|GetABI
argument_list|()
expr_stmt|;
name|OperatingSystem
modifier|*
name|GetOperatingSystem
parameter_list|()
block|{
return|return
name|m_os_ap
operator|.
name|get
argument_list|()
return|;
block|}
name|virtual
name|LanguageRuntime
modifier|*
name|GetLanguageRuntime
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
name|bool
name|retry_if_null
operator|=
name|true
argument_list|)
decl_stmt|;
name|virtual
name|CPPLanguageRuntime
modifier|*
name|GetCPPLanguageRuntime
parameter_list|(
name|bool
name|retry_if_null
init|=
name|true
parameter_list|)
function_decl|;
name|virtual
name|ObjCLanguageRuntime
modifier|*
name|GetObjCLanguageRuntime
parameter_list|(
name|bool
name|retry_if_null
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|IsPossibleDynamicValue
parameter_list|(
name|ValueObject
modifier|&
name|in_value
parameter_list|)
function_decl|;
name|bool
name|IsRunning
argument_list|()
specifier|const
expr_stmt|;
name|DynamicCheckerFunctions
modifier|*
name|GetDynamicCheckers
parameter_list|()
block|{
return|return
name|m_dynamic_checkers_ap
operator|.
name|get
argument_list|()
return|;
block|}
name|void
name|SetDynamicCheckers
parameter_list|(
name|DynamicCheckerFunctions
modifier|*
name|dynamic_checkers
parameter_list|)
block|{
name|m_dynamic_checkers_ap
operator|.
name|reset
argument_list|(
name|dynamic_checkers
argument_list|)
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Call this to set the lldb in the mode where it breaks on new thread
comment|/// creations, and then auto-restarts.  This is useful when you are trying
comment|/// to run only one thread, but either that thread or the kernel is creating
comment|/// new threads in the process.  If you stop when the thread is created, you
comment|/// can immediately suspend it, and keep executing only the one thread you intend.
comment|///
comment|/// @return
comment|///     Returns \b true if we were able to start up the notification
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|StartNoticingNewThreads
parameter_list|()
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Call this to turn off the stop& notice new threads mode.
comment|///
comment|/// @return
comment|///     Returns \b true if we were able to start up the notification
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|StopNoticingNewThreads
parameter_list|()
block|{
return|return
name|true
return|;
block|}
name|void
name|SetRunningUserExpression
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// lldb::ExecutionContextScope pure virtual functions
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|TargetSP
name|CalculateTarget
argument_list|()
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ProcessSP
name|CalculateProcess
argument_list|()
block|{
return|return
name|shared_from_this
argument_list|()
return|;
block|}
name|virtual
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
block|{
return|return
name|lldb
operator|::
name|ThreadSP
argument_list|()
return|;
block|}
name|virtual
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
block|{
return|return
name|lldb
operator|::
name|StackFrameSP
argument_list|()
return|;
block|}
name|virtual
name|void
name|CalculateExecutionContext
parameter_list|(
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
name|void
name|SetSTDIOFileDescriptor
parameter_list|(
name|int
name|file_descriptor
parameter_list|)
function_decl|;
name|void
name|WatchForSTDIN
parameter_list|(
name|IOHandler
modifier|&
name|io_handler
parameter_list|)
function_decl|;
name|void
name|CancelWatchForSTDIN
parameter_list|(
name|bool
name|exited
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Add a permanent region of memory that should never be read or
comment|// written to. This can be used to ensure that memory reads or writes
comment|// to certain areas of memory never end up being sent to the
comment|// DoReadMemory or DoWriteMemory functions which can improve
comment|// performance.
comment|//------------------------------------------------------------------
name|void
name|AddInvalidMemoryRegion
parameter_list|(
specifier|const
name|LoadRange
modifier|&
name|region
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Remove a permanent region of memory that should never be read or
comment|// written to that was previously added with AddInvalidMemoryRegion.
comment|//------------------------------------------------------------------
name|bool
name|RemoveInvalidMemoryRange
parameter_list|(
specifier|const
name|LoadRange
modifier|&
name|region
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// If the setup code of a thread plan needs to do work that might involve
comment|// calling a function in the target, it should not do that work directly
comment|// in one of the thread plan functions (DidPush/WillResume) because
comment|// such work needs to be handled carefully.  Instead, put that work in
comment|// a PreResumeAction callback, and register it with the process.  It will
comment|// get done before the actual "DoResume" gets called.
comment|//------------------------------------------------------------------
typedef|typedef
name|bool
function_decl|(
name|PreResumeActionCallback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
name|AddPreResumeAction
parameter_list|(
name|PreResumeActionCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|bool
name|RunPreResumeActions
parameter_list|()
function_decl|;
name|void
name|ClearPreResumeActions
parameter_list|()
function_decl|;
name|ProcessRunLock
modifier|&
name|GetRunLock
parameter_list|()
block|{
if|if
condition|(
name|Host
operator|::
name|GetCurrentThread
argument_list|()
operator|==
name|m_private_state_thread
condition|)
return|return
name|m_private_run_lock
return|;
else|else
return|return
name|m_public_run_lock
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// NextEventAction provides a way to register an action on the next
comment|// event that is delivered to this process.  There is currently only
comment|// one next event action allowed in the process at one time.  If a
comment|// new "NextEventAction" is added while one is already present, the
comment|// old action will be discarded (with HandleBeingUnshipped called
comment|// after it is discarded.)
comment|//
comment|// If you want to resume the process as a result of a resume action,
comment|// call RequestResume, don't call Resume directly.
comment|//------------------------------------------------------------------
name|class
name|NextEventAction
block|{
name|public
label|:
typedef|typedef
enum|enum
name|EventActionResult
block|{
name|eEventActionSuccess
block|,
name|eEventActionRetry
block|,
name|eEventActionExit
block|}
name|EventActionResult
typedef|;
name|NextEventAction
argument_list|(
name|Process
operator|*
name|process
argument_list|)
operator|:
name|m_process
argument_list|(
argument|process
argument_list|)
block|{         }
name|virtual
operator|~
name|NextEventAction
argument_list|()
block|{         }
name|virtual
name|EventActionResult
name|PerformAction
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|HandleBeingUnshipped
parameter_list|()
block|{}
name|virtual
name|EventActionResult
name|HandleBeingInterrupted
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|char
modifier|*
name|GetExitString
parameter_list|()
init|=
literal|0
function_decl|;
name|void
name|RequestResume
parameter_list|()
block|{
name|m_process
operator|->
name|m_resume_requested
operator|=
name|true
expr_stmt|;
block|}
name|protected
label|:
name|Process
modifier|*
name|m_process
decl_stmt|;
block|}
empty_stmt|;
name|void
name|SetNextEventAction
argument_list|(
name|Process
operator|::
name|NextEventAction
operator|*
name|next_event_action
argument_list|)
block|{
if|if
condition|(
name|m_next_event_action_ap
operator|.
name|get
argument_list|()
condition|)
name|m_next_event_action_ap
operator|->
name|HandleBeingUnshipped
argument_list|()
expr_stmt|;
name|m_next_event_action_ap
operator|.
name|reset
argument_list|(
name|next_event_action
argument_list|)
expr_stmt|;
block|}
comment|// This is the completer for Attaching:
name|class
name|AttachCompletionHandler
range|:
name|public
name|NextEventAction
block|{
name|public
operator|:
name|AttachCompletionHandler
argument_list|(
argument|Process *process
argument_list|,
argument|uint32_t exec_count
argument_list|)
operator|:
name|NextEventAction
argument_list|(
name|process
argument_list|)
block|,
name|m_exec_count
argument_list|(
argument|exec_count
argument_list|)
block|{         }
name|virtual
operator|~
name|AttachCompletionHandler
argument_list|()
block|{         }
name|virtual
name|EventActionResult
name|PerformAction
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|;
name|virtual
name|EventActionResult
name|HandleBeingInterrupted
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetExitString
argument_list|()
block|;
name|private
operator|:
name|uint32_t
name|m_exec_count
block|;
name|std
operator|::
name|string
name|m_exit_string
block|;     }
decl_stmt|;
name|bool
name|HijackPrivateProcessEvents
parameter_list|(
name|Listener
modifier|*
name|listener
parameter_list|)
function_decl|;
name|void
name|RestorePrivateProcessEvents
parameter_list|()
function_decl|;
name|bool
name|PrivateStateThreadIsValid
argument_list|()
specifier|const
block|{
return|return
name|IS_VALID_LLDB_HOST_THREAD
argument_list|(
name|m_private_state_thread
argument_list|)
return|;
block|}
name|void
name|ForceNextEventDelivery
parameter_list|()
block|{
name|m_force_next_event_delivery
operator|=
name|true
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|// Type definitions
comment|//------------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|LanguageType
operator|,
name|lldb
operator|::
name|LanguageRuntimeSP
operator|>
name|LanguageRuntimeCollection
expr_stmt|;
struct|struct
name|PreResumeCallbackAndBaton
block|{
name|bool
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|baton
decl_stmt|;
name|PreResumeCallbackAndBaton
argument_list|(
argument|PreResumeActionCallback in_callback
argument_list|,
argument|void *in_baton
argument_list|)
block|:
name|callback
argument_list|(
name|in_callback
argument_list|)
operator|,
name|baton
argument_list|(
argument|in_baton
argument_list|)
block|{         }
block|}
struct|;
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|Target
modifier|&
name|m_target
decl_stmt|;
comment|///< The target that owns this process.
name|ThreadSafeValue
operator|<
name|lldb
operator|::
name|StateType
operator|>
name|m_public_state
expr_stmt|;
name|ThreadSafeValue
operator|<
name|lldb
operator|::
name|StateType
operator|>
name|m_private_state
expr_stmt|;
comment|// The actual state of our process
name|Broadcaster
name|m_private_state_broadcaster
decl_stmt|;
comment|// This broadcaster feeds state changed events into the private state thread's listener.
name|Broadcaster
name|m_private_state_control_broadcaster
decl_stmt|;
comment|// This is the control broadcaster, used to pause, resume& stop the private state thread.
name|Listener
name|m_private_state_listener
decl_stmt|;
comment|// This is the listener for the private state thread.
name|Predicate
operator|<
name|bool
operator|>
name|m_private_state_control_wait
expr_stmt|;
comment|/// This Predicate is used to signal that a control operation is complete.
name|lldb
operator|::
name|thread_t
name|m_private_state_thread
expr_stmt|;
comment|// Thread ID for the thread that watches interal state events
name|ProcessModID
name|m_mod_id
decl_stmt|;
comment|///< Tracks the state of the process over stops and other alterations.
name|uint32_t
name|m_process_unique_id
decl_stmt|;
comment|///< Each lldb_private::Process class that is created gets a unique integer ID that increments with each new instance
name|uint32_t
name|m_thread_index_id
decl_stmt|;
comment|///< Each thread is created with a 1 based index that won't get re-used.
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|uint32_t
operator|>
name|m_thread_id_to_index_id_map
expr_stmt|;
name|int
name|m_exit_status
decl_stmt|;
comment|///< The exit status of the process, or -1 if not set.
name|std
operator|::
name|string
name|m_exit_string
expr_stmt|;
comment|///< A textual description of why a process exited.
name|Mutex
name|m_thread_mutex
decl_stmt|;
name|ThreadList
name|m_thread_list_real
decl_stmt|;
comment|///< The threads for this process as are known to the protocol we are debugging with
name|ThreadList
name|m_thread_list
decl_stmt|;
comment|///< The threads for this process as the user will see them. This is usually the same as
comment|///< m_thread_list_real, but might be different if there is an OS plug-in creating memory threads
name|ThreadList
name|m_extended_thread_list
decl_stmt|;
comment|///< Owner for extended threads that may be generated, cleared on natural stops
name|uint32_t
name|m_extended_thread_stop_id
decl_stmt|;
comment|///< The natural stop id when extended_thread_list was last updated
name|QueueList
name|m_queue_list
decl_stmt|;
comment|///< The list of libdispatch queues at a given stop point
name|uint32_t
name|m_queue_list_stop_id
decl_stmt|;
comment|///< The natural stop id when queue list was last fetched
name|std
operator|::
name|vector
operator|<
name|Notifications
operator|>
name|m_notifications
expr_stmt|;
comment|///< The list of notifications that this process can deliver.
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|m_image_tokens
expr_stmt|;
name|Listener
modifier|&
name|m_listener
decl_stmt|;
name|BreakpointSiteList
name|m_breakpoint_site_list
decl_stmt|;
comment|///< This is the list of breakpoint locations we intend to insert in the target.
name|std
operator|::
name|unique_ptr
operator|<
name|DynamicLoader
operator|>
name|m_dyld_ap
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DynamicCheckerFunctions
operator|>
name|m_dynamic_checkers_ap
expr_stmt|;
comment|///< The functions used by the expression parser to validate data that expressions use.
name|std
operator|::
name|unique_ptr
operator|<
name|OperatingSystem
operator|>
name|m_os_ap
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|SystemRuntime
operator|>
name|m_system_runtime_ap
expr_stmt|;
name|UnixSignals
name|m_unix_signals
decl_stmt|;
comment|/// This is the current signal set for this process.
name|lldb
operator|::
name|ABISP
name|m_abi_sp
expr_stmt|;
name|lldb
operator|::
name|IOHandlerSP
name|m_process_input_reader
expr_stmt|;
name|Communication
name|m_stdio_communication
decl_stmt|;
name|Mutex
name|m_stdio_communication_mutex
decl_stmt|;
name|std
operator|::
name|string
name|m_stdout_data
expr_stmt|;
name|std
operator|::
name|string
name|m_stderr_data
expr_stmt|;
name|Mutex
name|m_profile_data_comm_mutex
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|m_profile_data
expr_stmt|;
name|MemoryCache
name|m_memory_cache
decl_stmt|;
name|AllocatedMemoryCache
name|m_allocated_memory_cache
decl_stmt|;
name|bool
name|m_should_detach
decl_stmt|;
comment|/// Should we detach if the process object goes away with an explicit call to Kill or Detach?
name|LanguageRuntimeCollection
name|m_language_runtimes
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|NextEventAction
operator|>
name|m_next_event_action_ap
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|PreResumeCallbackAndBaton
operator|>
name|m_pre_resume_actions
expr_stmt|;
name|ProcessRunLock
name|m_public_run_lock
decl_stmt|;
name|ProcessRunLock
name|m_private_run_lock
decl_stmt|;
name|Predicate
operator|<
name|bool
operator|>
name|m_currently_handling_event
expr_stmt|;
comment|// This predicate is set in HandlePrivateEvent while all its business is being done.
name|bool
name|m_currently_handling_do_on_removals
decl_stmt|;
name|bool
name|m_resume_requested
decl_stmt|;
comment|// If m_currently_handling_event or m_currently_handling_do_on_removals are true, Resume will only request a resume, using this flag to check.
name|bool
name|m_finalize_called
decl_stmt|;
name|bool
name|m_clear_thread_plans_on_stop
decl_stmt|;
name|bool
name|m_force_next_event_delivery
decl_stmt|;
name|lldb
operator|::
name|StateType
name|m_last_broadcast_state
expr_stmt|;
comment|/// This helps with the Public event coalescing in ShouldBroadcastEvent.
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|m_resolved_indirect_addresses
expr_stmt|;
name|bool
name|m_destroy_in_process
decl_stmt|;
enum|enum
block|{
name|eCanJITDontKnow
init|=
literal|0
block|,
name|eCanJITYes
block|,
name|eCanJITNo
block|}
name|m_can_jit
enum|;
name|size_t
name|RemoveBreakpointOpcodesFromBuffer
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size
argument_list|,
name|uint8_t
operator|*
name|buf
argument_list|)
decl|const
decl_stmt|;
name|void
name|SynchronouslyNotifyStateChanged
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|)
decl_stmt|;
name|void
name|SetPublicState
argument_list|(
name|lldb
operator|::
name|StateType
name|new_state
argument_list|,
name|bool
name|restarted
argument_list|)
decl_stmt|;
name|void
name|SetPrivateState
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|)
decl_stmt|;
name|bool
name|StartPrivateStateThread
parameter_list|(
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|StopPrivateStateThread
parameter_list|()
function_decl|;
name|void
name|PausePrivateStateThread
parameter_list|()
function_decl|;
name|void
name|ResumePrivateStateThread
parameter_list|()
function_decl|;
specifier|static
name|lldb
operator|::
name|thread_result_t
name|PrivateStateThread
argument_list|(
name|void
operator|*
name|arg
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|thread_result_t
name|RunPrivateStateThread
argument_list|()
expr_stmt|;
name|void
name|HandlePrivateEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|StateType
name|WaitForProcessStopPrivate
argument_list|(
specifier|const
name|TimeValue
operator|*
name|timeout
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
expr_stmt|;
comment|// This waits for both the state change broadcaster, and the control broadcaster.
comment|// If control_only, it only waits for the control broadcaster.
name|bool
name|WaitForEventsPrivate
argument_list|(
specifier|const
name|TimeValue
operator|*
name|timeout
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
name|bool
name|control_only
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|StateType
name|WaitForStateChangedEventsPrivate
argument_list|(
specifier|const
name|TimeValue
operator|*
name|timeout
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|StateType
name|WaitForState
argument_list|(
argument|const TimeValue *timeout
argument_list|,
argument|const lldb::StateType *match_states
argument_list|,
argument|const uint32_t num_match_states
argument_list|)
expr_stmt|;
name|size_t
name|WriteMemoryPrivate
argument_list|(
name|lldb
operator|::
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
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|AppendSTDOUT
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|void
name|AppendSTDERR
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|void
name|BroadcastAsyncProfileData
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|one_profile_data
argument_list|)
decl_stmt|;
specifier|static
name|void
name|STDIOReadThreadBytesReceived
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|src_len
parameter_list|)
function_decl|;
name|void
name|PushProcessIOHandler
parameter_list|()
function_decl|;
name|void
name|PopProcessIOHandler
parameter_list|()
function_decl|;
name|void
name|ResetProcessIOHandler
parameter_list|()
function_decl|;
name|Error
name|HaltForDestroyOrDetach
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|exit_event_sp
argument_list|)
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For Process only
comment|//------------------------------------------------------------------
name|void
name|ControlPrivateStateThread
parameter_list|(
name|uint32_t
name|signal
parameter_list|)
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Process
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
comment|// liblldb_Process_h_
end_comment

end_unit

