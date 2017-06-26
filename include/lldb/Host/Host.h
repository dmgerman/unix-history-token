begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Host.h --------------------------------------------------*- C++ -*-===//
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
name|liblldb_Host_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/Host/File.h"
end_include

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
file|"lldb/Utility/StringList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|FileAction
decl_stmt|;
name|class
name|ProcessLaunchInfo
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// Exit Type for inferior processes
comment|//----------------------------------------------------------------------
struct|struct
name|WaitStatus
block|{
enum|enum
name|Type
enum|:
name|uint8_t
block|{
name|Exit
block|,
comment|// The status represents the return code from normal
comment|// program exit (i.e. WIFEXITED() was true)
name|Signal
block|,
comment|// The status represents the signal number that caused
comment|// the program to exit (i.e. WIFSIGNALED() was true)
name|Stop
block|,
comment|// The status represents the signal number that caused the
comment|// program to stop (i.e. WIFSTOPPED() was true)
block|}
enum|;
name|Type
name|type
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|WaitStatus
argument_list|(
argument|Type type
argument_list|,
argument|uint8_t status
argument_list|)
block|:
name|type
argument_list|(
name|type
argument_list|)
operator|,
name|status
argument_list|(
argument|status
argument_list|)
block|{}
specifier|static
name|WaitStatus
name|Decode
argument_list|(
argument|int wstatus
argument_list|)
expr_stmt|;
block|}
struct|;
comment|//----------------------------------------------------------------------
comment|/// @class Host Host.h "lldb/Host/Host.h"
comment|/// @brief A class that provides host computer information.
comment|///
comment|/// Host is a class that answers information about the host operating
comment|/// system.
comment|//----------------------------------------------------------------------
name|class
name|Host
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|bool exited
argument_list|,
argument|int signal
argument_list|,
comment|// Zero for no signal
argument|int status
argument_list|)
operator|>
comment|// Exit value of process if signal is zero
name|MonitorChildProcessCallback
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Start monitoring a child process.
comment|///
comment|/// Allows easy monitoring of child processes. \a callback will be
comment|/// called when the child process exits or if it gets a signal. The
comment|/// callback will only be called with signals if \a monitor_signals
comment|/// is \b true. \a callback will usually be called from another
comment|/// thread so the callback function must be thread safe.
comment|///
comment|/// When the callback gets called, the return value indicates if
comment|/// monitoring should stop. If \b true is returned from \a callback
comment|/// the information will be removed. If \b false is returned then
comment|/// monitoring will continue. If the child process exits, the
comment|/// monitoring will automatically stop after the callback returned
comment|/// regardless of the callback return value.
comment|///
comment|/// @param[in] callback
comment|///     A function callback to call when a child receives a signal
comment|///     (if \a monitor_signals is true) or a child exits.
comment|///
comment|/// @param[in] pid
comment|///     The process ID of a child process to monitor, -1 for all
comment|///     processes.
comment|///
comment|/// @param[in] monitor_signals
comment|///     If \b true the callback will get called when the child
comment|///     process gets a signal. If \b false, the callback will only
comment|///     get called if the child process exits.
comment|///
comment|/// @return
comment|///     A thread handle that can be used to cancel the thread that
comment|///     was spawned to monitor \a pid.
comment|///
comment|/// @see static void Host::StopMonitoringChildProcess (uint32_t)
comment|//------------------------------------------------------------------
specifier|static
name|HostThread
name|StartMonitoringChildProcess
argument_list|(
specifier|const
name|MonitorChildProcessCallback
operator|&
name|callback
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|bool
name|monitor_signals
argument_list|)
decl_stmt|;
enum|enum
name|SystemLogType
block|{
name|eSystemLogWarning
block|,
name|eSystemLogError
block|}
enum|;
specifier|static
name|void
name|SystemLog
parameter_list|(
name|SystemLogType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|SystemLog
parameter_list|(
name|SystemLogType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Get the process ID for the calling process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The process ID for the current process.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|pid_t
name|GetCurrentProcessID
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|void
name|Kill
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|int
name|signo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Get the thread token (the one returned by ThreadCreate when the thread was
end_comment

begin_comment
comment|/// created) for the
end_comment

begin_comment
comment|/// calling thread in the current process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The thread token for the calling thread in the current process.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|thread_t
name|GetCurrentThread
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|GetSignalAsCString
parameter_list|(
name|int
name|signo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Given an address in the current process (the process that
end_comment

begin_comment
comment|/// is running the LLDB code), return the name of the module that
end_comment

begin_comment
comment|/// it comes from. This can be useful when you need to know the
end_comment

begin_comment
comment|/// path to the shared library that your code is running in for
end_comment

begin_comment
comment|/// loading resources that are relative to your binary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] host_addr
end_comment

begin_comment
comment|///     The pointer to some code in the current process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b A file spec with the module that contains \a host_addr,
end_comment

begin_comment
comment|///     which may be invalid if \a host_addr doesn't fall into
end_comment

begin_comment
comment|///     any valid module address range.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|FileSpec
name|GetModuleFileSpecForHostAddress
parameter_list|(
specifier|const
name|void
modifier|*
name|host_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// If you have an executable that is in a bundle and want to get
end_comment

begin_comment
comment|/// back to the bundle directory from the path itself, this
end_comment

begin_comment
comment|/// function will change a path to a file within a bundle to the
end_comment

begin_comment
comment|/// bundle directory itself.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] file
end_comment

begin_comment
comment|///     A file spec that might point to a file in a bundle.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] bundle_directory
end_comment

begin_comment
comment|///     An object will be filled in with the bundle directory for
end_comment

begin_comment
comment|///     the bundle when \b true is returned. Otherwise \a file is
end_comment

begin_comment
comment|///     left untouched and \b false is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b true if \a file was resolved in \a bundle_directory,
end_comment

begin_comment
comment|///     \b false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|bool
name|GetBundleDirectory
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|,
name|FileSpec
modifier|&
name|bundle_directory
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// When executable files may live within a directory, where the
end_comment

begin_comment
comment|/// directory represents an executable bundle (like the MacOSX
end_comment

begin_comment
comment|/// app bundles), then locate the executable within the containing
end_comment

begin_comment
comment|/// bundle.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in,out] file
end_comment

begin_comment
comment|///     A file spec that currently points to the bundle that will
end_comment

begin_comment
comment|///     be filled in with the executable path within the bundle
end_comment

begin_comment
comment|///     if \b true is returned. Otherwise \a file is left untouched.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b true if \a file was resolved, \b false if this function
end_comment

begin_comment
comment|///     was not able to resolve the path.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|bool
name|ResolveExecutableInBundle
parameter_list|(
name|FileSpec
modifier|&
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|uint32_t
name|FindProcesses
parameter_list|(
specifier|const
name|ProcessInstanceInfoMatch
modifier|&
name|match_info
parameter_list|,
name|ProcessInstanceInfoList
modifier|&
name|proc_infos
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|pid_t
operator|,
name|bool
operator|>
name|TidMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|lldb
operator|::
name|pid_t
operator|,
name|bool
operator|>
name|TidPair
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
name|bool
name|FindProcessThreads
argument_list|(
specifier|const
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|TidMap
operator|&
name|tids_to_attach
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|GetProcessInfo
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|ProcessInstanceInfo
operator|&
name|proc_info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
specifier|const
name|lldb
operator|::
name|UnixSignalsSP
operator|&
name|GetUnixSignals
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|Status
name|LaunchProcess
parameter_list|(
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Perform expansion of the command-line for this launch info
end_comment

begin_comment
comment|/// This can potentially involve wildcard expansion
end_comment

begin_comment
comment|//  environment variable replacement, and whatever other
end_comment

begin_comment
comment|//  argument magic the platform defines as part of its typical
end_comment

begin_comment
comment|//  user experience
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|Status
name|ShellExpandArguments
parameter_list|(
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// TODO: Convert this function to take a StringRef.
end_comment

begin_decl_stmt
specifier|static
name|Status
name|RunShellCommand
argument_list|(
specifier|const
name|char
operator|*
name|command
argument_list|,
comment|// Shouldn't be NULL
specifier|const
name|FileSpec
operator|&
name|working_dir
argument_list|,
comment|// Pass empty FileSpec to use the current
comment|// working directory
name|int
operator|*
name|status_ptr
argument_list|,
comment|// Pass NULL if you don't want the process exit status
name|int
operator|*
name|signo_ptr
argument_list|,
comment|// Pass NULL if you don't want the signal that caused the
comment|// process to exit
name|std
operator|::
name|string
operator|*
name|command_output
argument_list|,
comment|// Pass NULL if you don't want the command output
name|uint32_t
name|timeout_sec
argument_list|,
name|bool
name|run_in_default_shell
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Status
name|RunShellCommand
argument_list|(
specifier|const
name|Args
operator|&
name|args
argument_list|,
specifier|const
name|FileSpec
operator|&
name|working_dir
argument_list|,
comment|// Pass empty FileSpec to use the current
comment|// working directory
name|int
operator|*
name|status_ptr
argument_list|,
comment|// Pass NULL if you don't want the process exit status
name|int
operator|*
name|signo_ptr
argument_list|,
comment|// Pass NULL if you don't want the signal that caused the
comment|// process to exit
name|std
operator|::
name|string
operator|*
name|command_output
argument_list|,
comment|// Pass NULL if you don't want the command output
name|uint32_t
name|timeout_sec
argument_list|,
name|bool
name|run_in_default_shell
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|bool
name|OpenFileInExternalEditor
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file_spec
parameter_list|,
name|uint32_t
name|line_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|size_t
name|GetEnvironment
parameter_list|(
name|StringList
modifier|&
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|lldb_private
operator|::
name|WaitStatus
operator|>
block|{
comment|/// Options = "" gives a human readable description of the status
comment|/// Options = "g" gives a gdb-remote protocol status (e.g., X09)
specifier|static
name|void
name|format
argument_list|(
argument|const lldb_private::WaitStatus&WS
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|llvm::StringRef Options
argument_list|)
block|; }
expr_stmt|;
block|}
end_block

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Host_h_
end_comment

end_unit

