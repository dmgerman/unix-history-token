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
file|<chrono>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

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
file|<unordered_set>
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
file|"lldb/Breakpoint/BreakpointSiteList.h"
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
file|"lldb/Core/Event.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Listener.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/LoadedModuleInfoList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ThreadSafeValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserSettingsController.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/ProcessRunLock.h"
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
file|"lldb/Target/InstrumentationRuntime.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Memory.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ProcessInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ProcessLaunchInfo.h"
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
file|"lldb/Utility/NameMatches.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/TraceOptions.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|template
operator|<
name|typename
name|B
operator|,
name|typename
name|S
operator|>
expr|struct
name|Range
expr_stmt|;
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
comment|// Pass nullptr for "process" if the ProcessProperties are to be the global
comment|// copy
name|ProcessProperties
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
operator|~
name|ProcessProperties
argument_list|()
name|override
block|;
name|bool
name|GetDisableMemoryCache
argument_list|()
specifier|const
block|;
name|uint64_t
name|GetMemoryCacheLineSize
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
block|;
name|bool
name|GetWarningsOptimization
argument_list|()
specifier|const
block|;
name|protected
operator|:
specifier|static
name|void
name|OptionValueChangedCallback
argument_list|(
name|void
operator|*
name|baton
argument_list|,
name|OptionValue
operator|*
name|option_value
argument_list|)
block|;
name|Process
operator|*
name|m_process
block|;
comment|// Can be nullptr for global ProcessProperties
block|}
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
comment|// ProcessInstanceInfo
comment|//
comment|// Describes an existing process and any discoverable information that
comment|// pertains to that process.
comment|//----------------------------------------------------------------------
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
block|{}
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
block|{}
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
block|;   }
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
block|; }
name|void
name|SetEffectiveGroupID
argument_list|(
argument|uint32_t gid
argument_list|)
block|{
name|m_egid
operator|=
name|gid
block|; }
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
block|; }
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
comment|//----------------------------------------------------------------------
comment|// ProcessAttachInfo
comment|//
comment|// Describes any information that is required to attach to a process.
comment|//----------------------------------------------------------------------
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
name|m_listener_sp
argument_list|()
block|,
name|m_hijack_listener_sp
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
name|false
argument_list|)
block|,
name|m_detach_on_error
argument_list|(
name|true
argument_list|)
block|,
name|m_async
argument_list|(
argument|false
argument_list|)
block|{}
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
name|m_listener_sp
argument_list|()
block|,
name|m_hijack_listener_sp
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
name|false
argument_list|)
block|,
name|m_detach_on_error
argument_list|(
name|true
argument_list|)
block|,
name|m_async
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
name|SetListener
argument_list|(
name|launch_info
operator|.
name|GetListener
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
block|;
name|m_detach_on_error
operator|=
name|launch_info
operator|.
name|GetDetachOnError
argument_list|()
block|;   }
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
block|; }
name|bool
name|GetAsync
argument_list|()
specifier|const
block|{
return|return
name|m_async
return|;
block|}
name|void
name|SetAsync
argument_list|(
argument|bool b
argument_list|)
block|{
name|m_async
operator|=
name|b
block|; }
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
block|; }
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
block|; }
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
specifier|const
name|char
operator|*
name|GetProcessPluginName
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_plugin_name
operator|.
name|empty
argument_list|()
operator|?
name|nullptr
operator|:
name|m_plugin_name
operator|.
name|c_str
argument_list|()
operator|)
return|;
block|}
name|void
name|SetProcessPluginName
argument_list|(
argument|llvm::StringRef plugin
argument_list|)
block|{
name|m_plugin_name
operator|=
name|plugin
block|; }
name|void
name|Clear
argument_list|()
block|{
name|ProcessInstanceInfo
operator|::
name|Clear
argument_list|()
block|;
name|m_plugin_name
operator|.
name|clear
argument_list|()
block|;
name|m_resume_count
operator|=
literal|0
block|;
name|m_wait_for_launch
operator|=
name|false
block|;
name|m_ignore_existing
operator|=
name|true
block|;
name|m_continue_once_attached
operator|=
name|false
block|;   }
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
return|return
name|false
return|;
block|}
end_decl_stmt

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

begin_expr_stmt
name|bool
name|GetDetachOnError
argument_list|()
specifier|const
block|{
return|return
name|m_detach_on_error
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetDetachOnError
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|m_detach_on_error
operator|=
name|enable
expr_stmt|;
block|}
end_function

begin_comment
comment|// Get and set the actual listener that will be used for the process events
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|void
name|SetListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|)
block|{
name|m_listener_sp
operator|=
name|listener_sp
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ListenerSP
name|GetListenerForProcess
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|lldb
operator|::
name|ListenerSP
name|m_listener_sp
expr_stmt|;
end_expr_stmt

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
comment|// Supports the use-case scenario of
end_comment

begin_comment
comment|// immediately continuing the process once
end_comment

begin_comment
comment|// attached.
end_comment

begin_decl_stmt
name|bool
name|m_detach_on_error
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If we are debugging remotely, instruct the stub to
end_comment

begin_comment
comment|// detach rather than killing the target on error.
end_comment

begin_decl_stmt
name|bool
name|m_async
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Use an async attach where we start the attach and return
end_comment

begin_comment
comment|// immediately (used by GUI programs with --waitfor so they can
end_comment

begin_comment
comment|// call SBProcess::Stop() to cancel attach)
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
argument_list|()
operator|:
name|Options
argument_list|()
block|{
comment|// Keep default values of all options in one place: OptionParsingStarting ()
name|OptionParsingStarting
argument_list|(
name|nullptr
argument_list|)
block|;   }
operator|~
name|ProcessLaunchCommandOptions
argument_list|()
name|override
operator|=
expr|default
block|;
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_arg
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|{
name|launch_info
operator|.
name|Clear
argument_list|()
block|;
name|disable_aslr
operator|=
name|eLazyBoolCalculate
block|;   }
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
name|override
block|;
comment|// Instance variables to hold the values for command options.
name|ProcessLaunchInfo
name|launch_info
block|;
name|lldb_private
operator|::
name|LazyBool
name|disable_aslr
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
name|NameMatch
operator|::
name|Ignore
argument_list|)
operator|,
name|m_match_all_users
argument_list|(
argument|false
argument_list|)
block|{}
name|ProcessInstanceInfoMatch
argument_list|(
argument|const char *process_name
argument_list|,
argument|NameMatch process_name_match_type
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
block|;   }
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
name|NameMatch
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
name|NameMatch
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
name|NameMatch
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
operator|=
expr|default
expr_stmt|;
name|void
name|Clear
parameter_list|()
block|{
name|m_infos
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|size_t
name|GetSize
parameter_list|()
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
return|return
operator|(
operator|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
operator|)
condition|?
name|m_infos
index|[
name|idx
index|]
operator|.
name|GetName
argument_list|()
else|:
name|nullptr
operator|)
return|;
block|}
name|size_t
name|GetProcessNameLengthAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
return|return
operator|(
operator|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
operator|)
condition|?
name|m_infos
index|[
name|idx
index|]
operator|.
name|GetNameLength
argument_list|()
else|:
literal|0
operator|)
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
return|return
operator|(
operator|(
name|idx
operator|<
name|m_infos
operator|.
name|size
argument_list|()
operator|)
operator|?
name|m_infos
index|[
name|idx
index|]
operator|.
name|GetProcessID
argument_list|()
operator|:
literal|0
operator|)
return|;
block|}
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
comment|// You must ensure "idx" is valid before calling this function
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
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ProcessInstanceInfo
operator|>
name|collection
expr_stmt|;
name|collection
name|m_infos
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This class tracks the Modification state of the process.  Things that can
end_comment

begin_comment
comment|// currently modify
end_comment

begin_comment
comment|// the program are running the program (which will up the StopID) and writing
end_comment

begin_comment
comment|// memory (which
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
operator|=
expr|default
expr_stmt|;
name|void
name|BumpStopID
parameter_list|()
block|{
name|m_stop_id
operator|++
expr_stmt|;
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
comment|// If we haven't yet resumed the target, then it can't be for a user
comment|// expression...
if|if
condition|(
name|m_resume_id
operator|==
literal|0
condition|)
return|return
name|false
return|;
return|return
name|m_resume_id
operator|==
name|m_last_user_expression_resume
return|;
block|}
end_decl_stmt

begin_function
name|void
name|SetRunningUserExpression
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
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
end_function

begin_decl_stmt
name|void
name|SetStopEventForLastNaturalStopID
argument_list|(
name|lldb
operator|::
name|EventSP
name|event_sp
argument_list|)
block|{
name|m_last_natural_stop_event
operator|=
name|event_sp
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|EventSP
name|GetStopEventForStopID
argument_list|(
argument|uint32_t stop_id
argument_list|)
specifier|const
block|{
if|if
condition|(
name|stop_id
operator|==
name|m_last_natural_stop_id
condition|)
return|return
name|m_last_natural_stop_event
return|;
end_expr_stmt

begin_return
return|return
name|lldb
operator|::
name|EventSP
argument_list|()
return|;
end_return

begin_decl_stmt
unit|}  private:
name|uint32_t
name|m_stop_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_last_natural_stop_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_resume_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_memory_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_last_user_expression_resume
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_running_user_expression
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|EventSP
name|m_last_natural_stop_event
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
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
return|return
operator|(
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
operator|)
return|;
block|}
end_expr_stmt

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
name|FunctionCaller
decl_stmt|;
comment|// For WaitForStateChangeEventsPrivate
name|friend
name|class
name|Debugger
decl_stmt|;
comment|// For PopProcessIOHandler and ProcessIOHandlerIsActive
name|friend
name|class
name|DynamicLoader
decl_stmt|;
comment|// For LoadOperatingSystemPlugin
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
block|,
name|eBroadcastBitStructuredData
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,   }
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
comment|//------------------------------------------------------------------
comment|/// Process warning types.
comment|//------------------------------------------------------------------
enum|enum
name|Warnings
block|{
name|eWarningsOptimization
init|=
literal|1
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
operator|~
name|ProcessEventData
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
name|ProcessSP
name|GetProcessSP
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
return|return
operator|(
operator|(
name|idx
operator|<
name|m_restarted_reasons
operator|.
name|size
argument_list|()
operator|)
operator|?
name|m_restarted_reasons
index|[
name|idx
index|]
operator|.
name|c_str
argument_list|()
operator|:
name|nullptr
operator|)
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
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
name|override
block|;
name|void
name|DoOnRemoval
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
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
block|; }
name|void
name|SetRestarted
argument_list|(
argument|bool new_value
argument_list|)
block|{
name|m_restarted
operator|=
name|new_value
block|; }
name|void
name|SetInterrupted
argument_list|(
argument|bool new_value
argument_list|)
block|{
name|m_interrupted
operator|=
name|new_value
block|; }
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
block|;     }
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
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
comment|// For "eStateStopped" events, this is true if the target
comment|// was automatically restarted.
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
block|;   }
decl_stmt|;
endif|#
directive|endif
comment|// SWIG
comment|//------------------------------------------------------------------
comment|/// Construct with a shared pointer to a target, and the Process listener.
comment|/// Uses the Host UnixSignalsSP by default.
comment|//------------------------------------------------------------------
name|Process
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a shared pointer to a target, the Process listener,
comment|/// and the appropriate UnixSignalsSP for the process.
comment|//------------------------------------------------------------------
name|Process
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const lldb::UnixSignalsSP&unix_signals_sp
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class is designed to be
comment|/// inherited from by the plug-in instance.
comment|//------------------------------------------------------------------
operator|~
name|Process
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
name|ProcessPropertiesSP
modifier|&
name|GetGlobalProperties
parameter_list|()
function_decl|;
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
comment|///     If nullptr, select the best plug-in for the binary. If non-nullptr
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
argument|lldb::TargetSP target_sp
argument_list|,
argument|llvm::StringRef plugin_name
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const FileSpec *crash_file_path
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
comment|///     pid = Process::GetID()
comment|///     monitor_signals = false
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|SetProcessExitStatus
argument_list|(
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
argument_list|(
name|lldb
operator|::
name|TargetSP
name|target
argument_list|,
name|bool
name|plugin_specified_by_name
argument_list|)
init|=
literal|0
decl_stmt|;
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
name|nullptr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Launch a new process.
comment|///
comment|/// Launch a new process by spawning a new process using the
comment|/// target object's executable module's file as the file to launch.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses. It will first call Process::WillLaunch (Module *)
comment|/// and if that returns \b true, Process::DoLaunch (Module*,
comment|/// char const *[],char const *[],const char *,const char *,
comment|/// const char *) will be called to actually do the launching. If
comment|/// DoLaunch returns \b true, then Process::DidLaunch() will be
comment|/// called.
comment|///
comment|/// @param[in] launch_info
comment|///     Details regarding the environment, STDIN/STDOUT/STDERR
comment|///     redirection, working path, etc. related to the requested launch.
comment|///
comment|/// @return
comment|///     An error object. Call GetID() to get the process ID if
comment|///     the error object is success.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|Launch
parameter_list|(
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|)
function_decl|;
name|virtual
name|Status
name|LoadCore
parameter_list|()
function_decl|;
name|virtual
name|Status
name|DoLoadCore
parameter_list|()
block|{
name|Status
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
comment|// Returns AUXV structure found in many ELF-based environments.
comment|//
comment|// The default action is to return an empty data buffer.
comment|//
comment|// @return
comment|//    A data buffer containing the contents of the AUXV data.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|lldb
operator|::
name|DataBufferSP
name|GetAuxvData
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sometimes processes know how to retrieve and load shared libraries.
comment|/// This is normally done by DynamicLoader plug-ins, but sometimes the
comment|/// connection to the process allows retrieving this information. The
comment|/// dynamic loader plug-ins can use this function if they can't
comment|/// determine the current shared library load state.
comment|///
comment|/// @return
comment|///    The number of shared libraries that were loaded
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|LoadModules
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|size_t
name|LoadModules
parameter_list|(
name|LoadedModuleInfoList
modifier|&
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
name|protected
label|:
name|virtual
name|JITLoaderList
modifier|&
name|GetJITLoaders
parameter_list|()
function_decl|;
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Get the system runtime plug-in for this process.
comment|///
comment|/// @return
comment|///   Returns a pointer to the SystemRuntime plugin for this Process
comment|///   if one is available.  Else returns nullptr.
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
name|Status
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
comment|///     the connection.  This may be nullptr if no output is needed.A
comment|///
comment|/// @param[in] remote_url
comment|///     The URL format that we are connecting to.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|ConnectRemote
argument_list|(
name|Stream
operator|*
name|strm
argument_list|,
name|llvm
operator|::
name|StringRef
name|remote_url
argument_list|)
decl_stmt|;
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
comment|/// Called when the process is about to broadcast a public stop.
comment|///
comment|/// There are public and private stops. Private stops are when the
comment|/// process is doing things like stepping and the client doesn't
comment|/// need to know about starts and stop that implement a thread plan.
comment|/// Single stepping over a source line in code might end up being
comment|/// implemented by one or more process starts and stops. Public stops
comment|/// are when clients will be notified that the process is stopped.
comment|/// These events typically trigger UI updates (thread stack frames to
comment|/// be displayed, variables to be displayed, and more). This function
comment|/// can be overriden and allows process subclasses to do something
comment|/// before the eBroadcastBitStateChanged event is sent to public
comment|/// clients.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|WillPublicStop
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Register for process and thread notifications.
comment|///
comment|/// Clients can register notification callbacks by filling out a
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
comment|/// Clients can unregister notification callbacks by passing a copy of
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
name|Status
name|Resume
parameter_list|()
function_decl|;
name|Status
name|ResumeSynchronous
parameter_list|(
name|Stream
modifier|*
name|stream
parameter_list|)
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
comment|/// @param[in] use_run_lock
comment|///     Whether to release the run lock after the stop.
comment|///
comment|/// @return
comment|///     Returns an error object.  If the error is empty, the process is
comment|///     halted.
comment|///     otherwise the halt has failed.
comment|//------------------------------------------------------------------
name|Status
name|Halt
parameter_list|(
name|bool
name|clear_thread_plans
init|=
name|false
parameter_list|,
name|bool
name|use_run_lock
init|=
name|true
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
name|Status
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
comment|/// @param[in] force_kill
comment|///     Whether lldb should force a kill (instead of a detach) from
comment|///     the inferior process.  Normally if lldb launched a binary and
comment|///     Destory is called, lldb kills it.  If lldb attached to a
comment|///     running process and Destory is called, lldb detaches.  If
comment|///     this behavior needs to be over-ridden, this is the bool that
comment|///     can be used.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|Status
name|Destroy
parameter_list|(
name|bool
name|force_kill
parameter_list|)
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
name|Status
name|Signal
parameter_list|(
name|int
name|signal
parameter_list|)
function_decl|;
name|void
name|SetUnixSignals
argument_list|(
name|lldb
operator|::
name|UnixSignalsSP
operator|&&
name|signals_sp
argument_list|)
decl_stmt|;
specifier|const
name|lldb
operator|::
name|UnixSignalsSP
operator|&
name|GetUnixSignals
argument_list|()
expr_stmt|;
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
name|Status
name|WillAttachToProcessWithID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
block|{
return|return
name|Status
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
name|Status
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
name|Status
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Attach to a remote system via a URL
comment|///
comment|/// @param[in] strm
comment|///     A stream where output intended for the user
comment|///     (if the driver has a way to display that) generated during
comment|///     the connection.  This may be nullptr if no output is needed.A
comment|///
comment|/// @param[in] remote_url
comment|///     The URL format that we are connecting to.
comment|///
comment|/// @return
comment|///     Returns an error object.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|DoConnectRemote
argument_list|(
name|Stream
operator|*
name|strm
argument_list|,
name|llvm
operator|::
name|StringRef
name|remote_url
argument_list|)
block|{
name|Status
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
comment|/// @param[in] attach_info
comment|///     Information on how to do the attach. For example, GetUserID()
comment|///     will return the uid to attach as.
comment|///
comment|/// @return
comment|///     Returns a successful Status attaching was successful, or
comment|///     an appropriate (possibly platform-specific) error code if
comment|///     attaching fails.
comment|/// hanming : need flag
comment|//------------------------------------------------------------------
name|virtual
name|Status
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
name|Status
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
comment|///     Returns a successful Status attaching was successful, or
comment|///     an appropriate (possibly platform-specific) error code if
comment|///     attaching fails.
comment|//------------------------------------------------------------------
name|virtual
name|Status
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
name|Status
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
comment|/// @param[in] process_arch
comment|///     If you can figure out the process architecture after attach, fill it
comment|///     in here.
comment|///
comment|/// Allow Process plug-ins to execute some code after attaching to
comment|/// a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidAttach
parameter_list|(
name|ArchSpec
modifier|&
name|process_arch
parameter_list|)
block|{
name|process_arch
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
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
block|{}
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
name|Status
name|WillLaunch
parameter_list|(
name|Module
modifier|*
name|module
parameter_list|)
block|{
return|return
name|Status
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Launch a new process.
comment|///
comment|/// Launch a new process by spawning a new process using
comment|/// \a exe_module's file as the file to launch. Launch details are
comment|/// provided in \a launch_info.
comment|///
comment|/// @param[in] exe_module
comment|///     The module from which to extract the file specification and
comment|///     launch.
comment|///
comment|/// @param[in] launch_info
comment|///     Details (e.g. arguments, stdio redirection, etc.) for the
comment|///     requested launch.
comment|///
comment|/// @return
comment|///     An Status instance indicating success or failure of the
comment|///     operation.
comment|//------------------------------------------------------------------
name|virtual
name|Status
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
name|Status
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
name|Status
name|WillResume
parameter_list|()
block|{
return|return
name|Status
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
name|Status
name|DoResume
parameter_list|()
block|{
name|Status
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
name|Status
name|WillHalt
parameter_list|()
block|{
return|return
name|Status
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Halts a running process.
comment|///
comment|/// DoHalt must produce one and only one stop StateChanged event if it
comment|/// actually
comment|/// stops the process.  If the stop happens through some natural event (for
comment|/// instance a SIGSTOP), then forwarding that event will do.  Otherwise, you
comment|/// must
comment|/// generate the event manually. This function is called from the context of
comment|/// the
comment|/// private state thread.
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
name|Status
name|DoHalt
parameter_list|(
name|bool
modifier|&
name|caused_stop
parameter_list|)
block|{
name|Status
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
name|Status
name|WillDetach
parameter_list|()
block|{
return|return
name|Status
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
name|Status
name|DoDetach
parameter_list|(
name|bool
name|keep_stopped
parameter_list|)
block|{
name|Status
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
name|Status
name|WillSignal
parameter_list|()
block|{
return|return
name|Status
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
name|Status
name|DoSignal
parameter_list|(
name|int
name|signal
parameter_list|)
block|{
name|Status
name|error
decl_stmt|;
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"error: %s does not support sending signals to processes"
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
name|Status
name|WillDestroy
parameter_list|()
block|{
return|return
name|Status
argument_list|()
return|;
block|}
name|virtual
name|Status
name|DoDestroy
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|DidDestroy
parameter_list|()
block|{}
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
comment|/// Sometimes the connection to a process can detect the host OS
comment|/// version that the process is running on. The current platform
comment|/// should be checked first in case the platform is connected, but
comment|/// clients can fall back onto this function if the platform fails
comment|/// to identify the host OS version. The platform should be checked
comment|/// first in case you are running a simulator platform that might
comment|/// itself be running natively, but have different heuristics for
comment|/// figuring out which OS is is emulating.
comment|///
comment|/// @param[out] major
comment|///    The major OS version, or UINT32_MAX if it can't be determined
comment|///
comment|/// @param[out] minor
comment|///    The minor OS version, or UINT32_MAX if it can't be determined
comment|///
comment|/// @param[out] update
comment|///    The update OS version, or UINT32_MAX if it can't be determined
comment|///
comment|/// @return
comment|///     Returns \b true if the host OS version info was filled in
comment|///     and \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetHostOSVersion
parameter_list|(
name|uint32_t
modifier|&
name|major
parameter_list|,
name|uint32_t
modifier|&
name|minor
parameter_list|,
name|uint32_t
modifier|&
name|update
parameter_list|)
block|{
name|major
operator|=
name|UINT32_MAX
expr_stmt|;
name|minor
operator|=
name|UINT32_MAX
expr_stmt|;
name|update
operator|=
name|UINT32_MAX
expr_stmt|;
return|return
name|false
return|;
block|}
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
operator|*
name|m_target_sp
operator|.
name|lock
argument_list|()
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
operator|*
name|m_target_sp
operator|.
name|lock
argument_list|()
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
name|lldb
operator|::
name|ExpressionResults
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
name|DiagnosticManager
operator|&
name|diagnostic_manager
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|ExecutionResultAsCString
argument_list|(
name|lldb
operator|::
name|ExpressionResults
name|result
argument_list|)
decl_stmt|;
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
parameter_list|,
name|bool
name|stop_format
parameter_list|)
function_decl|;
name|void
name|SendAsyncInterrupt
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Notify this process class that modules got loaded.
comment|//
comment|// If subclasses override this method, they must call this version
comment|// before doing anything in the subclass version of the function.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|ModulesDidLoad
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Retrieve the list of shared libraries that are loaded for this process
comment|/// This method is used on pre-macOS 10.12, pre-iOS 10, pre-tvOS 10,
comment|/// pre-watchOS 3 systems.  The following two methods are for newer versions
comment|/// of those OSes.
comment|///
comment|/// For certain platforms, the time it takes for the DynamicLoader plugin to
comment|/// read all of the shared libraries out of memory over a slow communication
comment|/// channel may be too long.  In that instance, the gdb-remote stub may be
comment|/// able to retrieve the necessary information about the solibs out of memory
comment|/// and return a concise summary sufficient for the DynamicLoader plugin.
comment|///
comment|/// @param [in] image_list_address
comment|///     The address where the table of shared libraries is stored in memory,
comment|///     if that is appropriate for this platform.  Else this may be
comment|///     passed as LLDB_INVALID_ADDRESS.
comment|///
comment|/// @param [in] image_count
comment|///     The number of shared libraries that are present in this process, if
comment|///     that is appropriate for this platofrm  Else this may be passed as
comment|///     LLDB_INVALID_ADDRESS.
comment|///
comment|/// @return
comment|///     A StructureDataSP object which, if non-empty, will contain the
comment|///     information the DynamicLoader needs to get the initial scan of
comment|///     solibs resolved.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|GetLoadedDynamicLibrariesInfos
argument_list|(
argument|lldb::addr_t image_list_address
argument_list|,
argument|lldb::addr_t image_count
argument_list|)
block|{
return|return
name|StructuredData
operator|::
name|ObjectSP
argument_list|()
return|;
block|}
comment|// On macOS 10.12, tvOS 10, iOS 10, watchOS 3 and newer, debugserver can
comment|// return
comment|// the full list of loaded shared libraries without needing any input.
name|virtual
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|GetLoadedDynamicLibrariesInfos
argument_list|()
block|{
return|return
name|StructuredData
operator|::
name|ObjectSP
argument_list|()
return|;
block|}
comment|// On macOS 10.12, tvOS 10, iOS 10, watchOS 3 and newer, debugserver can
comment|// return
comment|// information about binaries given their load addresses.
name|virtual
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|GetLoadedDynamicLibrariesInfos
argument_list|(
argument|const std::vector<lldb::addr_t>&load_addresses
argument_list|)
block|{
return|return
name|StructuredData
operator|::
name|ObjectSP
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Get information about the library shared cache, if that exists
comment|//
comment|// On macOS 10.12, tvOS 10, iOS 10, watchOS 3 and newer, debugserver can
comment|// return
comment|// information about the library shared cache (a set of standard libraries
comment|// that are
comment|// loaded at the same location for all processes on a system) in use.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|GetSharedCacheInfo
argument_list|()
block|{
return|return
name|StructuredData
operator|::
name|ObjectSP
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Print a user-visible warning about a module being built with optimization
comment|///
comment|/// Prints a async warning message to the user one time per Module
comment|/// where a function is found that was compiled with optimization, per
comment|/// Process.
comment|///
comment|/// @param [in] sc
comment|///     A SymbolContext with eSymbolContextFunction and eSymbolContextModule
comment|///     pre-computed.
comment|//------------------------------------------------------------------
name|void
name|PrintWarningOptimization
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|sc
parameter_list|)
function_decl|;
name|virtual
name|bool
name|GetProcessInfo
parameter_list|(
name|ProcessInstanceInfo
modifier|&
name|info
parameter_list|)
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
comment|///     The textual description of why the process exited, or nullptr
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
block|{}
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
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
operator|.
name|GetLastNaturalStopID
argument_list|()
return|;
block|}
name|lldb
operator|::
name|EventSP
name|GetStopEventForStopID
argument_list|(
argument|uint32_t stop_id
argument_list|)
specifier|const
block|{
return|return
name|m_mod_id
operator|.
name|GetStopEventForStopID
argument_list|(
name|stop_id
argument_list|)
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
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Before lldb detaches from a process, it warns the user that they are about
comment|/// to lose their debug session.
comment|/// In some cases, this warning doesn't need to be emitted -- for instance,
comment|/// with core file debugging where
comment|/// the user can reconstruct the "state" by simply re-running the debugger on
comment|/// the core file.
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
name|Status
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
name|Status
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
name|Status
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
name|Status
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
name|Status
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
name|Status
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
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
name|int64_t
name|ReadSignedIntegerFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|size_t
name|byte_size
argument_list|,
name|int64_t
name|fail_value
argument_list|,
name|Status
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
argument|Status&error
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
name|Status
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
name|Status
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
comment|/// less than the size of scalar, the least significant \a size bytes
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
name|Status
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
name|Status
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
comment|// TODO: change this to take an ArrayRef<uint8_t>
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
name|Status
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
argument|Status&error
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
comment|///     that a block that isn't set writable can still be written on from
comment|///     lldb,
comment|///     just not by the process itself.
comment|///
comment|/// @param[in,out] error
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
argument|Status&error
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// The public interface to allocating memory in the process, this also
comment|/// clears the allocated memory.
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
comment|///     that a block that isn't set writable can still be written on from
comment|///     lldb,
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
name|CallocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|Status&error
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
name|Status
operator|&
name|error
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Locate the memory region that contains load_addr.
comment|///
comment|/// If load_addr is within the address space the process has mapped
comment|/// range_info will be filled in with the start and end of that range
comment|/// as well as the permissions for that range and range_info.GetMapped
comment|/// will return true.
comment|///
comment|/// If load_addr is outside any mapped region then range_info will
comment|/// have its start address set to load_addr and the end of the
comment|/// range will indicate the start of the next mapped range or be
comment|/// set to LLDB_INVALID_ADDRESS if there are no valid mapped ranges
comment|/// between load_addr and the end of the process address space.
comment|///
comment|/// GetMemoryRegionInfo will only return an error if it is
comment|/// unimplemented for the current process.
comment|///
comment|/// @param[in] load_addr
comment|///     The load address to query the range_info for.
comment|///
comment|/// @param[out] range_info
comment|///     An range_info value containing the details of the range.
comment|///
comment|/// @return
comment|///     An error value.
comment|//------------------------------------------------------------------
name|virtual
name|Status
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
name|Status
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
comment|//------------------------------------------------------------------
comment|/// Obtain all the mapped memory regions within this process.
comment|///
comment|/// @param[out] region_list
comment|///     A vector to contain MemoryRegionInfo objects for all mapped
comment|///     ranges.
comment|///
comment|/// @return
comment|///     An error value.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|GetMemoryRegions
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|MemoryRegionInfoSP
operator|>
operator|&
name|region_list
argument_list|)
decl_stmt|;
name|virtual
name|Status
name|GetWatchpointSupportInfo
parameter_list|(
name|uint32_t
modifier|&
name|num
parameter_list|)
block|{
name|Status
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
name|Status
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
name|Status
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
argument|const FileSpec&file_spec
argument_list|,
argument|lldb::addr_t header_addr
argument_list|,
argument|size_t size_to_read =
literal|512
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
decl_stmt|;
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
comment|/// Determines whether executing function calls using the interpreter
comment|/// is possible for this process.
comment|///
comment|/// @return
comment|///     True if possible; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|CanInterpretFunctionCalls
parameter_list|()
block|{
return|return
name|m_can_interpret_function_calls
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Sets whether executing function calls using the interpreter
comment|/// is possible for this process.
comment|///
comment|/// @param[in] can_interpret_function_calls
comment|///     True if possible; false otherwise.
comment|//------------------------------------------------------------------
name|void
name|SetCanInterpretFunctionCalls
parameter_list|(
name|bool
name|can_interpret_function_calls
parameter_list|)
block|{
name|m_can_interpret_function_calls
operator|=
name|can_interpret_function_calls
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Sets whether executing code in this process is possible.
comment|/// This could be either through JIT or interpreting.
comment|///
comment|/// @param[in] can_run_code
comment|///     True if execution of code is possible; false otherwise.
comment|//------------------------------------------------------------------
name|void
name|SetCanRunCode
parameter_list|(
name|bool
name|can_run_code
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
name|Status
name|DoDeallocateMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|ptr
argument_list|)
block|{
name|Status
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
name|Status
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
comment|/// Calling this method is a valid operation only if all of the
comment|/// following conditions are true:
comment|/// 1) The process was launched, and not attached to.
comment|/// 2) The process was not launched with eLaunchFlagDisableSTDIO.
comment|/// 3) The process was launched without supplying a valid file path
comment|///    for STDOUT.
comment|///
comment|/// Note that the implementation will probably need to start a read
comment|/// thread in the background to make sure that the pipe is drained
comment|/// and the STDOUT buffered appropriately, to prevent the process
comment|/// from deadlocking trying to write to a full buffer.
comment|///
comment|/// Events will be queued indicating that there is STDOUT available
comment|/// that can be retrieved using this function.
comment|///
comment|/// @param[out] buf
comment|///     A buffer that will receive any STDOUT bytes that are
comment|///     currently available.
comment|///
comment|/// @param[in] buf_size
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
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get any available STDERR.
comment|///
comment|/// Calling this method is a valid operation only if all of the
comment|/// following conditions are true:
comment|/// 1) The process was launched, and not attached to.
comment|/// 2) The process was not launched with eLaunchFlagDisableSTDIO.
comment|/// 3) The process was launched without supplying a valid file path
comment|///    for STDERR.
comment|///
comment|/// Note that the implementation will probably need to start a read
comment|/// thread in the background to make sure that the pipe is drained
comment|/// and the STDERR buffered appropriately, to prevent the process
comment|/// from deadlocking trying to write to a full buffer.
comment|///
comment|/// Events will be queued indicating that there is STDERR available
comment|/// that can be retrieved using this function.
comment|///
comment|/// @param[in] buf
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
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Puts data into this process's STDIN.
comment|///
comment|/// Calling this method is a valid operation only if all of the
comment|/// following conditions are true:
comment|/// 1) The process was launched, and not attached to.
comment|/// 2) The process was not launched with eLaunchFlagDisableSTDIO.
comment|/// 3) The process was launched without supplying a valid file path
comment|///    for STDIN.
comment|///
comment|/// @param[in] buf
comment|///     A buffer that contains the data to write to the process's STDIN.
comment|///
comment|/// @param[in] buf_size
comment|///     The size in bytes for the buffer \a buf.
comment|///
comment|/// @return
comment|///     The number of bytes written into \a buf. If this value is
comment|///     less than \a buf_size, another call to this function should
comment|///     be made to write the rest of the data.
comment|//------------------------------------------------------------------
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
name|Status
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
name|Status
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
name|Status
name|EnableBreakpointSite
parameter_list|(
name|BreakpointSite
modifier|*
name|bp_site
parameter_list|)
block|{
name|Status
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
name|Status
name|DisableBreakpointSite
parameter_list|(
name|BreakpointSite
modifier|*
name|bp_site
parameter_list|)
block|{
name|Status
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
name|Status
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
name|Status
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
name|Status
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
name|Status
name|DisableBreakpointSiteByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|break_id
argument_list|)
decl_stmt|;
name|Status
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
name|Status
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
name|Status
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
comment|// Given a thread_id, it will assign a more reasonable index id for display to
comment|// the user.
comment|// If the thread_id has previously been assigned, the same index id will be
comment|// used.
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
comment|// If the process is hijacked and use_run_lock is true (the default), then
comment|// this
comment|// function releases the run lock after the stop. Setting use_run_lock to
comment|// false
comment|// will avoid this behavior.
name|lldb
operator|::
name|StateType
name|WaitForProcessToStop
argument_list|(
argument|const Timeout<std::micro>&timeout
argument_list|,
argument|lldb::EventSP *event_sp_ptr = nullptr
argument_list|,
argument|bool wait_always = true
argument_list|,
argument|lldb::ListenerSP hijack_listener = lldb::ListenerSP()
argument_list|,
argument|Stream *stream = nullptr
argument_list|,
argument|bool use_run_lock = true
argument_list|)
expr_stmt|;
name|uint32_t
name|GetIOHandlerID
argument_list|()
specifier|const
block|{
return|return
name|m_iohandler_sync
operator|.
name|GetValue
argument_list|()
return|;
block|}
comment|//--------------------------------------------------------------------------------------
comment|/// Waits for the process state to be running within a given msec timeout.
comment|///
comment|/// The main purpose of this is to implement an interlock waiting for
comment|/// HandlePrivateEvent
comment|/// to push an IOHandler.
comment|///
comment|/// @param[in] timeout_msec
comment|///     The maximum time length to wait for the process to transition to the
comment|///     eStateRunning state, specified in milliseconds.
comment|//--------------------------------------------------------------------------------------
name|void
name|SyncIOHandler
parameter_list|(
name|uint32_t
name|iohandler_id
parameter_list|,
name|uint64_t
name|timeout_msec
parameter_list|)
function_decl|;
name|lldb
operator|::
name|StateType
name|GetStateChangedEvents
argument_list|(
argument|lldb::EventSP&event_sp
argument_list|,
argument|const Timeout<std::micro>&timeout
argument_list|,
argument|lldb::ListenerSP           hijack_listener
argument_list|)
expr_stmt|;
comment|// Pass an empty ListenerSP to use builtin listener
comment|//--------------------------------------------------------------------------------------
comment|/// Centralize the code that handles and prints descriptions for process state
comment|/// changes.
comment|///
comment|/// @param[in] event_sp
comment|///     The process state changed event
comment|///
comment|/// @param[in] stream
comment|///     The output stream to get the state change description
comment|///
comment|/// @param[in,out] pop_process_io_handler
comment|///     If this value comes in set to \b true, then pop the Process IOHandler
comment|///     if needed.
comment|///     Else this variable will be set to \b true or \b false to indicate if
comment|///     the process
comment|///     needs to have its process IOHandler popped.
comment|///
comment|/// @return
comment|///     \b true if the event describes a process state changed event, \b false
comment|///     otherwise.
comment|//--------------------------------------------------------------------------------------
specifier|static
name|bool
name|HandleProcessStateChangedEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
name|Stream
operator|*
name|stream
argument_list|,
name|bool
operator|&
name|pop_process_io_handler
argument_list|)
decl_stmt|;
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
argument|Process&process
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|)
block|:
name|m_process
argument_list|(
argument|process
argument_list|)
block|{
name|m_process
operator|.
name|HijackProcessEvents
argument_list|(
name|listener_sp
argument_list|)
expr_stmt|;
block|}
operator|~
name|ProcessEventHijacker
argument_list|()
block|{
name|m_process
operator|.
name|RestoreProcessEvents
argument_list|()
block|; }
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
name|friend
name|class
name|ProcessProperties
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// If you need to ensure that you and only you will hear about some public
comment|/// event, then make a new listener, set to listen to process events, and
comment|/// then call this with that listener.  Then you will have to wait on that
comment|/// listener explicitly for events (rather than using the GetNextEvent&
comment|/// WaitFor*
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
argument_list|(
name|lldb
operator|::
name|ListenerSP
name|listener_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Restores the process event broadcasting to its normal state.
comment|///
comment|//------------------------------------------------------------------
name|void
name|RestoreProcessEvents
parameter_list|()
function_decl|;
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
name|ArchSpec
operator|::
name|StopInfoOverrideCallbackType
name|GetStopInfoOverrideCallback
argument_list|()
specifier|const
block|{
return|return
name|m_stop_info_override_callback
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
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Call this to set the lldb in the mode where it breaks on new thread
comment|/// creations, and then auto-restarts.  This is useful when you are trying
comment|/// to run only one thread, but either that thread or the kernel is creating
comment|/// new threads in the process.  If you stop when the thread is created, you
comment|/// can immediately suspend it, and keep executing only the one thread you
comment|/// intend.
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
block|{
return|return
name|shared_from_this
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
name|override
block|{
return|return
name|lldb
operator|::
name|ThreadSP
argument_list|()
return|;
block|}
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
name|override
block|{
return|return
name|lldb
operator|::
name|StackFrameSP
argument_list|()
return|;
block|}
name|void
name|CalculateExecutionContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
name|override
decl_stmt|;
name|void
name|SetSTDIOFileDescriptor
parameter_list|(
name|int
name|file_descriptor
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
name|void
name|ClearPreResumeAction
parameter_list|(
name|PreResumeActionCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|ProcessRunLock
modifier|&
name|GetRunLock
parameter_list|()
function_decl|;
name|virtual
name|Status
name|SendEventData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
name|Status
name|return_error
argument_list|(
literal|"Sending an event is not supported for this process."
argument_list|)
decl_stmt|;
return|return
name|return_error
return|;
block|}
name|lldb
operator|::
name|ThreadCollectionSP
name|GetHistoryThreads
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|InstrumentationRuntimeSP
name|GetInstrumentationRuntime
argument_list|(
argument|lldb::InstrumentationRuntimeType type
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Try to fetch the module specification for a module with the
comment|/// given file name and architecture. Process sub-classes have to
comment|/// override this method if they support platforms where the
comment|/// Platform object can't get the module spec for all module.
comment|///
comment|/// @param[in] module_file_spec
comment|///     The file name of the module to get specification for.
comment|///
comment|/// @param[in] arch
comment|///     The architecture of the module to get specification for.
comment|///
comment|/// @param[out] module_spec
comment|///     The fetched module specification if the return value is
comment|///     \b true, unchanged otherwise.
comment|///
comment|/// @return
comment|///     Returns \b true if the module spec fetched successfully,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetModuleSpec
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|module_file_spec
parameter_list|,
specifier|const
name|ArchSpec
modifier|&
name|arch
parameter_list|,
name|ModuleSpec
modifier|&
name|module_spec
parameter_list|)
function_decl|;
name|virtual
name|void
name|PrefetchModuleSpecs
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|FileSpec
operator|>
name|module_file_specs
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Try to find the load address of a file.
comment|/// The load address is defined as the address of the first memory
comment|/// region what contains data mapped from the specified file.
comment|///
comment|/// @param[in] file
comment|///     The name of the file whose load address we are looking for
comment|///
comment|/// @param[out] is_loaded
comment|///     \b True if the file is loaded into the memory and false
comment|///     otherwise.
comment|///
comment|/// @param[out] load_addr
comment|///     The load address of the file if it is loaded into the
comment|///     processes address space, LLDB_INVALID_ADDRESS otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|GetFileLoadAddress
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file
argument_list|,
name|bool
operator|&
name|is_loaded
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|load_addr
argument_list|)
block|{
return|return
name|Status
argument_list|(
literal|"Not supported"
argument_list|)
return|;
block|}
name|size_t
name|AddImageToken
argument_list|(
name|lldb
operator|::
name|addr_t
name|image_ptr
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|GetImagePtrFromToken
argument_list|(
argument|size_t token
argument_list|)
specifier|const
expr_stmt|;
name|void
name|ResetImageToken
parameter_list|(
name|size_t
name|token
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find the next branch instruction to set a breakpoint on
comment|///
comment|/// When instruction stepping through a source line, instead of
comment|/// stepping through each instruction, we can put a breakpoint on
comment|/// the next branch instruction (within the range of instructions
comment|/// we are stepping through) and continue the process to there,
comment|/// yielding significant performance benefits over instruction
comment|/// stepping.
comment|///
comment|/// @param[in] default_stop_addr
comment|///     The address of the instruction where lldb would put a
comment|///     breakpoint normally.
comment|///
comment|/// @param[in] range_bounds
comment|///     The range which the breakpoint must be contained within.
comment|///     Typically a source line.
comment|///
comment|/// @return
comment|///     The address of the next branch instruction, or the end of
comment|///     the range provided in range_bounds.  If there are any
comment|///     problems with the disassembly or getting the instructions,
comment|///     the original default_stop_addr will be returned.
comment|//------------------------------------------------------------------
name|Address
name|AdvanceAddressToNextBranchInstruction
parameter_list|(
name|Address
name|default_stop_addr
parameter_list|,
name|AddressRange
name|range_bounds
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Configure asynchronous structured data feature.
comment|///
comment|/// Each Process type that supports using an asynchronous StructuredData
comment|/// feature should implement this to enable/disable/configure the feature.
comment|/// The default implementation here will always return an error indiciating
comment|/// the feature is unsupported.
comment|///
comment|/// StructuredDataPlugin implementations will call this to configure
comment|/// a feature that has been reported as being supported.
comment|///
comment|/// @param[in] type_name
comment|///     The StructuredData type name as previously discovered by
comment|///     the Process-derived instance.
comment|///
comment|/// @param[in] config
comment|///     Configuration data for the feature being enabled.  This config
comment|///     data, which may be null, will be passed along to the feature
comment|///     to process.  The feature will dictate whether this is a dictionary,
comment|///     an array or some other object.  If the feature needs to be
comment|///     set up properly before it can be enabled, then the config should
comment|///     also take an enable/disable flag.
comment|///
comment|/// @return
comment|///     Returns the result of attempting to configure the feature.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|ConfigureStructuredData
argument_list|(
specifier|const
name|ConstString
operator|&
name|type_name
argument_list|,
specifier|const
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|config_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Broadcasts the given structured data object from the given
comment|/// plugin.
comment|///
comment|/// StructuredDataPlugin instances can use this to optionally
comment|/// broadcast any of their data if they want to make it available
comment|/// for clients.  The data will come in on the structured data
comment|/// event bit (eBroadcastBitStructuredData).
comment|///
comment|/// @param[in] object_sp
comment|///     The structured data object to broadcast.
comment|///
comment|/// @param[in] plugin_sp
comment|///     The plugin that will be reported in the event's plugin
comment|///     parameter.
comment|//------------------------------------------------------------------
name|void
name|BroadcastStructuredData
argument_list|(
specifier|const
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|object_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|StructuredDataPluginSP
operator|&
name|plugin_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the StructuredDataPlugin associated with a given type
comment|/// name, if there is one.
comment|///
comment|/// There will only be a plugin for a given StructuredDataType if the
comment|/// debugged process monitor claims that the feature is supported.
comment|/// This is one way to tell whether a feature is available.
comment|///
comment|/// @return
comment|///     The plugin if one is available for the specified feature;
comment|///     otherwise, returns an empty shared pointer.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|StructuredDataPluginSP
name|GetStructuredDataPlugin
argument_list|(
argument|const ConstString&type_name
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Starts tracing with the configuration provided in options. To
comment|/// enable tracing on the complete process the thread_id in the
comment|/// options should be set to LLDB_INVALID_THREAD_ID. The API returns
comment|/// a user_id which is needed by other API's that manipulate the
comment|/// trace instance.
comment|/// The handling of erroneous or unsupported configuration is left
comment|/// to the trace technology implementations in the server, as they
comment|/// could be returned as an error, or rounded to a valid
comment|/// configuration to start tracing. In the later case the
comment|/// GetTraceConfig should supply the actual used trace
comment|/// configuration.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|user_id_t
name|StartTrace
argument_list|(
argument|const TraceOptions&options
argument_list|,
argument|Status&error
argument_list|)
block|{
name|error
operator|.
name|SetErrorString
argument_list|(
literal|"Not implemented"
argument_list|)
block|;
return|return
name|LLDB_INVALID_UID
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Stops the tracing instance leading to deletion of the trace
comment|/// data. The tracing instance is identified by the user_id which
comment|/// is obtained when tracing was started from the StartTrace.
comment|/// In case tracing of the complete process needs to be stopped
comment|/// the thread_id should be set to LLDB_INVALID_THREAD_ID.
comment|/// In the other case that tracing on an individual thread needs
comment|/// to be stopped a thread_id can be supplied.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|StopTrace
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|,
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
block|{
return|return
name|Status
argument_list|(
literal|"Not implemented"
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Provides the trace data as raw bytes. A buffer needs to be
comment|/// supplied to copy the trace data. The exact behavior of this API
comment|/// may vary across trace technology, as some may support partial
comment|/// reading of the trace data from a specified offset while some
comment|/// may not. The thread_id should be used to select a particular
comment|/// thread for trace extraction.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|GetData
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|,
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|,
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|buffer
argument_list|,
name|size_t
name|offset
operator|=
literal|0
argument_list|)
block|{
return|return
name|Status
argument_list|(
literal|"Not implemented"
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Similar API as above except for obtaining meta data
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|GetMetaData
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|,
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|,
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|buffer
argument_list|,
name|size_t
name|offset
operator|=
literal|0
argument_list|)
block|{
return|return
name|Status
argument_list|(
literal|"Not implemented"
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// API to obtain the trace configuration used by a trace instance.
comment|/// Configurations that may be specific to some trace technology
comment|/// should be stored in the custom parameters. The options are
comment|/// transported to the server, which shall interpret accordingly.
comment|/// The thread_id can be specified in the options to obtain the
comment|/// configuration used by a specific thread. The thread_id specified
comment|/// should also match the uid otherwise an error will be returned.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|GetTraceConfig
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|,
name|TraceOptions
operator|&
name|options
argument_list|)
block|{
return|return
name|Status
argument_list|(
literal|"Not implemented"
argument_list|)
return|;
block|}
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
comment|///     An Status object describing the success or failure of the resume.
comment|//------------------------------------------------------------------
name|Status
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
comment|//------------------------------------------------------------------
comment|/// Print a user-visible warning one time per Process
comment|///
comment|/// A facility for printing a warning to the user once per repeat_key.
comment|///
comment|/// warning_type is from the Process::Warnings enums.
comment|/// repeat_key is a pointer value that will be used to ensure that the
comment|/// warning message is not printed multiple times.  For instance, with a
comment|/// warning about a function being optimized, you can pass the CompileUnit
comment|/// pointer to have the warning issued for only the first function in a
comment|/// CU, or the Function pointer to have it issued once for every function,
comment|/// or a Module pointer to have it issued once per Module.
comment|///
comment|/// Classes outside Process should call a specific PrintWarning method
comment|/// so that the warning strings are all centralized in Process, instead of
comment|/// calling PrintWarning() directly.
comment|///
comment|/// @param [in] warning_type
comment|///     One of the types defined in Process::Warnings.
comment|///
comment|/// @param [in] repeat_key
comment|///     A pointer value used to ensure that the warning is only printed once.
comment|///     May be nullptr, indicating that the warning is printed unconditionally
comment|///     every time.
comment|///
comment|/// @param [in] fmt
comment|///     printf style format string
comment|//------------------------------------------------------------------
name|void
name|PrintWarning
parameter_list|(
name|uint64_t
name|warning_type
parameter_list|,
specifier|const
name|void
modifier|*
name|repeat_key
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|4
operator|,
function_decl|5
block|)
decl_stmt|)
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// NextEventAction provides a way to register an action on the next
end_comment

begin_comment
comment|// event that is delivered to this process.  There is currently only
end_comment

begin_comment
comment|// one next event action allowed in the process at one time.  If a
end_comment

begin_comment
comment|// new "NextEventAction" is added while one is already present, the
end_comment

begin_comment
comment|// old action will be discarded (with HandleBeingUnshipped called
end_comment

begin_comment
comment|// after it is discarded.)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If you want to resume the process as a result of a resume action,
end_comment

begin_comment
comment|// call RequestResume, don't call Resume directly.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
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
block|{}
name|virtual
operator|~
name|NextEventAction
argument_list|()
operator|=
expr|default
expr_stmt|;
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
init|=
literal|0
decl_stmt|;
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|// This is the completer for Attaching:
end_comment

begin_decl_stmt
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
block|;
operator|~
name|AttachCompletionHandler
argument_list|()
name|override
operator|=
expr|default
block|;
name|EventActionResult
name|PerformAction
argument_list|(
argument|lldb::EventSP&event_sp
argument_list|)
name|override
block|;
name|EventActionResult
name|HandleBeingInterrupted
argument_list|()
name|override
block|;
specifier|const
name|char
operator|*
name|GetExitString
argument_list|()
name|override
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
block|;   }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|PrivateStateThreadIsValid
argument_list|()
specifier|const
block|{
name|lldb
operator|::
name|StateType
name|state
operator|=
name|m_private_state
operator|.
name|GetValue
argument_list|()
block|;
return|return
name|state
operator|!=
name|lldb
operator|::
name|eStateInvalid
operator|&&
name|state
operator|!=
name|lldb
operator|::
name|eStateDetached
operator|&&
name|state
operator|!=
name|lldb
operator|::
name|eStateExited
operator|&&
name|m_private_state_thread
operator|.
name|IsJoinable
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|ForceNextEventDelivery
parameter_list|()
block|{
name|m_force_next_event_delivery
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Loads any plugins associated with asynchronous structured data
end_comment

begin_comment
comment|/// and maps the relevant supported type name to the plugin.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processes can receive asynchronous structured data from the
end_comment

begin_comment
comment|/// process monitor.  This method will load and map any structured
end_comment

begin_comment
comment|/// data plugins that support the given set of supported type names.
end_comment

begin_comment
comment|/// Later, if any of these features are enabled, the process monitor
end_comment

begin_comment
comment|/// is free to generate asynchronous structured data.  The data must
end_comment

begin_comment
comment|/// come in as a single \b StructuredData::Dictionary.  That dictionary
end_comment

begin_comment
comment|/// must have a string field named 'type', with a value that equals
end_comment

begin_comment
comment|/// the relevant type name string (one of the values in
end_comment

begin_comment
comment|/// \b supported_type_names).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] supported_type_names
end_comment

begin_comment
comment|///     An array of zero or more type names.  Each must be unique.
end_comment

begin_comment
comment|///     For each entry in the list, a StructuredDataPlugin will be
end_comment

begin_comment
comment|///     searched for that supports the structured data type name.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|void
name|MapSupportedStructuredDataPlugins
argument_list|(
specifier|const
name|StructuredData
operator|::
name|Array
operator|&
name|supported_type_names
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Route the incoming structured data dictionary to the right plugin.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The incoming structured data must be a dictionary, and it must
end_comment

begin_comment
comment|/// have a key named 'type' that stores a string value.  The string
end_comment

begin_comment
comment|/// value must be the name of the structured data feature that
end_comment

begin_comment
comment|/// knows how to handle it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] object_sp
end_comment

begin_comment
comment|///     When non-null and pointing to a dictionary, the 'type'
end_comment

begin_comment
comment|///     key's string value is used to look up the plugin that
end_comment

begin_comment
comment|///     was registered for that structured data type.  It then
end_comment

begin_comment
comment|///     calls the following method on the StructuredDataPlugin
end_comment

begin_comment
comment|///     instance:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     virtual void
end_comment

begin_comment
comment|///     HandleArrivalOfStructuredData(Process&process,
end_comment

begin_comment
comment|///                                   const ConstString&type_name,
end_comment

begin_comment
comment|///                                   const StructuredData::ObjectSP
end_comment

begin_comment
comment|///&object_sp)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     True if the structured data was routed to a plugin; otherwise,
end_comment

begin_comment
comment|///     false.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|bool
name|RouteAsyncStructuredData
argument_list|(
specifier|const
name|StructuredData
operator|::
name|ObjectSP
name|object_sp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Type definitions
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_typedef
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
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|unordered_set
operator|<
specifier|const
name|void
operator|*
operator|>
name|WarningsPointerSet
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|WarningsPointerSet
operator|>
name|WarningsCollection
expr_stmt|;
end_typedef

begin_struct
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
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|PreResumeCallbackAndBaton
operator|&
name|rhs
operator|)
block|{
return|return
name|callback
operator|==
name|rhs
operator|.
name|callback
operator|&&
name|baton
operator|==
name|rhs
operator|.
name|baton
return|;
block|}
block|}
struct|;
end_struct

begin_decl_stmt
name|using
name|StructuredDataPluginMap
init|=
name|std
operator|::
name|map
operator|<
name|ConstString
decl_stmt|,
name|lldb
decl|::
name|StructuredDataPluginSP
decl|>
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Member variables
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|std
operator|::
name|weak_ptr
operator|<
name|Target
operator|>
name|m_target_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< The target that owns this process.
end_comment

begin_expr_stmt
name|ThreadSafeValue
operator|<
name|lldb
operator|::
name|StateType
operator|>
name|m_public_state
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ThreadSafeValue
operator|<
name|lldb
operator|::
name|StateType
operator|>
name|m_private_state
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The actual state of our process
end_comment

begin_decl_stmt
name|Broadcaster
name|m_private_state_broadcaster
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This broadcaster feeds state
end_comment

begin_comment
comment|// changed events into the private
end_comment

begin_comment
comment|// state thread's listener.
end_comment

begin_decl_stmt
name|Broadcaster
name|m_private_state_control_broadcaster
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This is the control
end_comment

begin_comment
comment|// broadcaster, used to
end_comment

begin_comment
comment|// pause, resume& stop the
end_comment

begin_comment
comment|// private state thread.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ListenerSP
name|m_private_state_listener_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This is the listener for the
end_comment

begin_comment
comment|// private state thread.
end_comment

begin_decl_stmt
name|HostThread
name|m_private_state_thread
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Thread ID for the thread that watches
end_comment

begin_comment
comment|///internal state events
end_comment

begin_decl_stmt
name|ProcessModID
name|m_mod_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Tracks the state of the process over stops and
end_comment

begin_comment
comment|///other alterations.
end_comment

begin_decl_stmt
name|uint32_t
name|m_process_unique_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Each lldb_private::Process class that is
end_comment

begin_comment
comment|///created gets a unique integer ID that
end_comment

begin_comment
comment|///increments with each new instance
end_comment

begin_decl_stmt
name|uint32_t
name|m_thread_index_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Each thread is created with a 1 based index
end_comment

begin_comment
comment|///that won't get re-used.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|int
name|m_exit_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The exit status of the process, or -1 if not set.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|m_exit_string
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< A textual description of why a process exited.
end_comment

begin_expr_stmt
name|std
operator|::
name|mutex
name|m_exit_status_mutex
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< Mutex so m_exit_status m_exit_string can
end_comment

begin_comment
comment|///be safely accessed from multiple threads
end_comment

begin_expr_stmt
name|std
operator|::
name|recursive_mutex
name|m_thread_mutex
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ThreadList
name|m_thread_list_real
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The threads for this process as are known
end_comment

begin_comment
comment|///to the protocol we are debugging with
end_comment

begin_decl_stmt
name|ThreadList
name|m_thread_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The threads for this process as the user will
end_comment

begin_comment
comment|///see them. This is usually the same as
end_comment

begin_comment
comment|///< m_thread_list_real, but might be different if there is an OS plug-in
end_comment

begin_comment
comment|///creating memory threads
end_comment

begin_decl_stmt
name|ThreadList
name|m_extended_thread_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Owner for extended threads that may be
end_comment

begin_comment
comment|///generated, cleared on natural stops
end_comment

begin_decl_stmt
name|uint32_t
name|m_extended_thread_stop_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The natural stop id when
end_comment

begin_comment
comment|///extended_thread_list was last updated
end_comment

begin_decl_stmt
name|QueueList
name|m_queue_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The list of libdispatch queues at a given stop point
end_comment

begin_decl_stmt
name|uint32_t
name|m_queue_list_stop_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The natural stop id when queue list was
end_comment

begin_comment
comment|///last fetched
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|Notifications
operator|>
name|m_notifications
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< The list of notifications
end_comment

begin_comment
comment|///that this process can deliver.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ListenerSP
name|m_listener_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< Shared pointer to the listener used for
end_comment

begin_comment
comment|///public events.  Can not be empty.
end_comment

begin_decl_stmt
name|BreakpointSiteList
name|m_breakpoint_site_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< This is the list of breakpoint
end_comment

begin_comment
comment|///locations we intend to insert in
end_comment

begin_comment
comment|///the target.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|DynamicLoaderUP
name|m_dyld_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|JITLoaderListUP
name|m_jit_loaders_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|DynamicCheckerFunctionsUP
name|m_dynamic_checkers_ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< The functions used
end_comment

begin_comment
comment|///by the expression
end_comment

begin_comment
comment|///parser to validate
end_comment

begin_comment
comment|///data that
end_comment

begin_comment
comment|///expressions use.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|OperatingSystemUP
name|m_os_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|SystemRuntimeUP
name|m_system_runtime_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|UnixSignalsSP
name|m_unix_signals_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// This is the current signal set for this process.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ABISP
name|m_abi_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|IOHandlerSP
name|m_process_input_reader
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Communication
name|m_stdio_communication
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|recursive_mutex
name|m_stdio_communication_mutex
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_stdin_forward
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Remember if stdin must be forwarded to remote debug
end_comment

begin_comment
comment|/// server
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|m_stdout_data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_stderr_data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|recursive_mutex
name|m_profile_data_comm_mutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|Predicate
operator|<
name|uint32_t
operator|>
name|m_iohandler_sync
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|MemoryCache
name|m_memory_cache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AllocatedMemoryCache
name|m_allocated_memory_cache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_should_detach
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Should we detach if the process object goes away
end_comment

begin_comment
comment|/// with an explicit call to Kill or Detach?
end_comment

begin_decl_stmt
name|LanguageRuntimeCollection
name|m_language_runtimes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|InstrumentationRuntimeCollection
name|m_instrumentation_runtimes
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|NextEventAction
operator|>
name|m_next_event_action_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|PreResumeCallbackAndBaton
operator|>
name|m_pre_resume_actions
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ProcessRunLock
name|m_public_run_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ProcessRunLock
name|m_private_run_lock
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ArchSpec
operator|::
name|StopInfoOverrideCallbackType
name|m_stop_info_override_callback
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_currently_handling_do_on_removals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_resume_requested
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If m_currently_handling_event or
end_comment

begin_comment
comment|// m_currently_handling_do_on_removals are true,
end_comment

begin_comment
comment|// Resume will only request a resume, using this flag
end_comment

begin_comment
comment|// to check.
end_comment

begin_decl_stmt
name|bool
name|m_finalizing
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This is set at the beginning of Process::Finalize() to
end_comment

begin_comment
comment|// stop functions from looking up or creating things during
end_comment

begin_comment
comment|// a finalize call
end_comment

begin_decl_stmt
name|bool
name|m_finalize_called
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This is set at the end of Process::Finalize()
end_comment

begin_decl_stmt
name|bool
name|m_clear_thread_plans_on_stop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_force_next_event_delivery
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|StateType
name|m_last_broadcast_state
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// This helps with the Public event
end_comment

begin_comment
comment|/// coalescing in
end_comment

begin_comment
comment|/// ShouldBroadcastEvent.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|bool
name|m_destroy_in_process
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_can_interpret_function_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Some targets, e.g the OSX kernel,
end_comment

begin_comment
comment|// don't support the ability to modify
end_comment

begin_comment
comment|// the stack.
end_comment

begin_decl_stmt
name|WarningsCollection
name|m_warnings_issued
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A set of object pointers which have
end_comment

begin_comment
comment|// already had warnings printed
end_comment

begin_expr_stmt
name|std
operator|::
name|mutex
name|m_run_thread_plan_lock
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|StructuredDataPluginMap
name|m_structured_data_plugin_map
decl_stmt|;
end_decl_stmt

begin_enum
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
end_enum

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
name|void
name|SynchronouslyNotifyStateChanged
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
name|void
name|SetPrivateState
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|StartPrivateStateThread
parameter_list|(
name|bool
name|is_secondary_thread
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StopPrivateStateThread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PausePrivateStateThread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ResumePrivateStateThread
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_struct
struct|struct
name|PrivateStateThreadArgs
block|{
name|PrivateStateThreadArgs
argument_list|(
argument|Process *p
argument_list|,
argument|bool s
argument_list|)
block|:
name|process
argument_list|(
name|p
argument_list|)
operator|,
name|is_secondary_thread
argument_list|(
argument|s
argument_list|)
block|{}
expr_stmt|;
name|Process
modifier|*
name|process
decl_stmt|;
name|bool
name|is_secondary_thread
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// arg is a pointer to a new'ed PrivateStateThreadArgs structure.
end_comment

begin_comment
comment|// PrivateStateThread will free it for you.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|// The starts up the private state thread that will watch for events from the
end_comment

begin_comment
comment|// debugee.
end_comment

begin_comment
comment|// Pass true for is_secondary_thread in the case where you have to temporarily
end_comment

begin_comment
comment|// spin up a
end_comment

begin_comment
comment|// secondary state thread to handle events from a hand-called function on the
end_comment

begin_comment
comment|// primary
end_comment

begin_comment
comment|// private state thread.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|thread_result_t
name|RunPrivateStateThread
argument_list|(
argument|bool is_secondary_thread
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
name|Status
name|HaltPrivate
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb
operator|::
name|StateType
name|WaitForProcessStopPrivate
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This waits for both the state change broadcaster, and the control
end_comment

begin_comment
comment|// broadcaster.
end_comment

begin_comment
comment|// If control_only, it only waits for the control broadcaster.
end_comment

begin_decl_stmt
name|bool
name|GetEventsPrivate
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|,
name|bool
name|control_only
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|StateType
name|GetStateChangedEventsPrivate
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
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
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_function_decl
name|bool
name|PushProcessIOHandler
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PopProcessIOHandler
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ProcessIOHandlerIsActive
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|ProcessIOHandlerExists
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|bool
operator|>
operator|(
name|m_process_input_reader
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|Status
name|StopForDestroyOrDetach
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|exit_event_sp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|Status
name|UpdateAutomaticSignalFiltering
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|StateChangedIsExternallyHijacked
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LoadOperatingSystemPlugin
parameter_list|(
name|bool
name|flush
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// This is the part of the event handling that for a process event.
end_comment

begin_comment
comment|/// It decides what to do with the event and returns true if the
end_comment

begin_comment
comment|/// event needs to be propagated to the user, and false otherwise.
end_comment

begin_comment
comment|/// If the event is not propagated, this call will most likely set
end_comment

begin_comment
comment|/// the target to executing again.
end_comment

begin_comment
comment|/// There is only one place where this call should be called,
end_comment

begin_comment
comment|/// HandlePrivateEvent.
end_comment

begin_comment
comment|/// Don't call it from anywhere else...
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] event_ptr
end_comment

begin_comment
comment|///     This is the event we are handling.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     Returns \b true if the event should be reported to the
end_comment

begin_comment
comment|///     user, \b false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|bool
name|ShouldBroadcastEvent
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ControlPrivateStateThread
parameter_list|(
name|uint32_t
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
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

