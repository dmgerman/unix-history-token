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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StringList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/File.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
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
name|bool
argument_list|(
argument|*MonitorChildProcessCallback
argument_list|)
operator|(
name|void
operator|*
name|callback_baton
operator|,
name|lldb
operator|::
name|pid_t
name|pid
operator|,
name|bool
name|exited
operator|,
name|int
name|signal
operator|,
comment|// Zero for no signal
name|int
name|status
operator|)
expr_stmt|;
comment|// Exit value of process if signal is zero
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
comment|/// minotoring should stop. If \b true is returned from \a callback
comment|/// the information will be removed. If \b false is returned then
comment|/// monitoring will continue. If the child process exits, the
comment|/// monitoring will automatically stop after the callback returned
comment|/// ragardless of the callback return value.
comment|///
comment|/// @param[in] callback
comment|///     A function callback to call when a child receives a signal
comment|///     (if \a monitor_signals is true) or a child exits.
comment|///
comment|/// @param[in] callback_baton
comment|///     A void * of user data that will be pass back when
comment|///     \a callback is called.
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
name|lldb
operator|::
name|thread_t
name|StartMonitoringChildProcess
argument_list|(
argument|MonitorChildProcessCallback callback
argument_list|,
argument|void *callback_baton
argument_list|,
argument|lldb::pid_t pid
argument_list|,
argument|bool monitor_signals
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the host page size.
comment|///
comment|/// @return
comment|///     The size in bytes of a VM page on the host system.
comment|//------------------------------------------------------------------
specifier|static
name|size_t
name|GetPageSize
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the endianness of the host system.
comment|///
comment|/// @return
comment|///     Returns the endianness of the host system as a lldb::ByteOrder
comment|///     enumeration.
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the number of CPUs on this current host.
comment|///
comment|/// @return
comment|///     Number of CPUs on this current host, or zero if the number
comment|///     of CPUs can't be determined on this host.
comment|//------------------------------------------------------------------
specifier|static
name|uint32_t
name|GetNumberCPUS
parameter_list|()
function_decl|;
specifier|static
name|bool
name|GetOSVersion
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
function_decl|;
specifier|static
name|bool
name|GetOSBuildString
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|GetOSKernelDescription
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|GetHostname
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetUserName
argument_list|(
name|uint32_t
name|uid
argument_list|,
name|std
operator|::
name|string
operator|&
name|user_name
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetGroupName
argument_list|(
name|uint32_t
name|gid
argument_list|,
name|std
operator|::
name|string
operator|&
name|group_name
argument_list|)
decl_stmt|;
specifier|static
name|uint32_t
name|GetUserID
parameter_list|()
function_decl|;
specifier|static
name|uint32_t
name|GetGroupID
parameter_list|()
function_decl|;
specifier|static
name|uint32_t
name|GetEffectiveUserID
parameter_list|()
function_decl|;
specifier|static
name|uint32_t
name|GetEffectiveGroupID
parameter_list|()
function_decl|;
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
comment|/// Gets the host architecture.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A const architecture object that represents the host
end_comment

begin_comment
comment|///     architecture.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_enum
enum|enum
name|SystemDefaultArchitecture
block|{
name|eSystemDefaultArchitecture
block|,
comment|// The overall default architecture that applications will run on this host
name|eSystemDefaultArchitecture32
block|,
comment|// If this host supports 32 bit programs, return the default 32 bit arch
name|eSystemDefaultArchitecture64
comment|// If this host supports 64 bit programs, return the default 64 bit arch
block|}
enum|;
end_enum

begin_function_decl
specifier|static
specifier|const
name|ArchSpec
modifier|&
name|GetArchitecture
parameter_list|(
name|SystemDefaultArchitecture
name|arch_kind
init|=
name|eSystemDefaultArchitecture
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Gets the host vendor string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A const string object containing the host vendor name.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
specifier|const
name|ConstString
modifier|&
name|GetVendorString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Gets the host Operating System (OS) string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A const string object containing the host OS name.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
specifier|const
name|ConstString
modifier|&
name|GetOSString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Gets the host target triple as a const string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A const string object containing the host target triple.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
specifier|const
name|ConstString
modifier|&
name|GetTargetTriple
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Gets the name of the distribution (i.e. distributor id).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// On Linux, this will return the equivalent of lsb_release -i.
end_comment

begin_comment
comment|/// Android will return 'android'.  Other systems may return
end_comment

begin_comment
comment|/// nothing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A ConstString reference containing the OS distribution id.
end_comment

begin_comment
comment|///     The return string will be all lower case, with whitespace
end_comment

begin_comment
comment|///     replaced with underscores.  The return string will be
end_comment

begin_comment
comment|///     empty (result.AsCString() will return NULL) if the distribution
end_comment

begin_comment
comment|///     cannot be obtained.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
specifier|const
name|ConstString
modifier|&
name|GetDistributionId
parameter_list|()
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
comment|/// Get the thread ID for the calling thread in the current process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The thread ID for the calling thread in the current process.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|tid_t
name|GetCurrentThreadID
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Get the thread token (the one returned by ThreadCreate when the thread was created) for the
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

begin_function_decl
specifier|static
name|void
name|WillTerminate
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Host specific thread created function call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function call lets the current host OS do any thread
end_comment

begin_comment
comment|/// specific initialization that it needs, including naming the
end_comment

begin_comment
comment|/// thread. No cleanup routine is exptected to be called
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] name
end_comment

begin_comment
comment|///     The current thread's name in the current process.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|void
name|ThreadCreated
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|thread_t
name|ThreadCreate
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::thread_func_t function
argument_list|,
argument|lldb::thread_arg_t thread_arg
argument_list|,
argument|Error *err
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|ThreadCancel
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|,
name|Error
operator|*
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ThreadDetach
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|,
name|Error
operator|*
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ThreadJoin
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|,
name|lldb
operator|::
name|thread_result_t
operator|*
name|thread_result_ptr
argument_list|,
name|Error
operator|*
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ThreadLocalStorageCleanupCallback
function_decl|)
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|thread_key_t
name|ThreadLocalStorageCreate
argument_list|(
argument|ThreadLocalStorageCleanupCallback callback
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|void
modifier|*
name|ThreadLocalStorageGet
argument_list|(
name|lldb
operator|::
name|thread_key_t
name|key
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ThreadLocalStorageSet
argument_list|(
name|lldb
operator|::
name|thread_key_t
name|key
argument_list|,
name|void
operator|*
name|value
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Gets the name of a thread in a process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function will name a thread in a process using it's own
end_comment

begin_comment
comment|/// thread name pool, and also will attempt to set a thread name
end_comment

begin_comment
comment|/// using any supported host OS APIs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] pid
end_comment

begin_comment
comment|///     The process ID in which we are trying to get the name of
end_comment

begin_comment
comment|///     a thread.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] tid
end_comment

begin_comment
comment|///     The thread ID for which we are trying retrieve the name of.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A std::string containing the thread name.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|GetThreadName
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|lldb::tid_t tid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Sets the name of a thread in the current process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] pid
end_comment

begin_comment
comment|///     The process ID in which we are trying to name a thread.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] tid
end_comment

begin_comment
comment|///     The thread ID which we are trying to name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] name
end_comment

begin_comment
comment|///     The current thread's name in the current process to \a name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b true if the thread name was able to be set, \b false
end_comment

begin_comment
comment|///     otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
specifier|static
name|bool
name|SetThreadName
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Sets a shortened name of a thread in the current process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] pid
end_comment

begin_comment
comment|///     The process ID in which we are trying to name a thread.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] tid
end_comment

begin_comment
comment|///     The thread ID which we are trying to name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] name
end_comment

begin_comment
comment|///     The current thread's name in the current process to \a name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] len
end_comment

begin_comment
comment|///     The maximum length for the thread's shortened name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b true if the thread name was able to be set, \b false
end_comment

begin_comment
comment|///     otherwise.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|SetShortThreadName
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
name|size_t
name|len
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Gets the FileSpec of the current process (the process that
end_comment

begin_comment
comment|/// that is running the LLDB code).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b A file spec with the program name.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|FileSpec
name|GetProgramFileSpec
parameter_list|()
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
comment|/// app bundles), the locate the executable within the containing
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

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Find a resource files that are related to LLDB.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Operating systems have different ways of storing shared
end_comment

begin_comment
comment|/// libraries and related resources. This function abstracts the
end_comment

begin_comment
comment|/// access to these paths.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] path_type
end_comment

begin_comment
comment|///     The type of LLDB resource path you are looking for. If the
end_comment

begin_comment
comment|///     enumeration ends with "Dir", then only the \a file_spec's
end_comment

begin_comment
comment|///     directory member gets filled in.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] file_spec
end_comment

begin_comment
comment|///     A file spec that gets filled in with the appriopriate path.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b true if \a resource_path was resolved, \a false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|bool
name|GetLLDBPath
parameter_list|(
name|PathType
name|path_type
parameter_list|,
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set a string that can be displayed if host application crashes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Some operating systems have the ability to print a description
end_comment

begin_comment
comment|/// for shared libraries when a program crashes. If the host OS
end_comment

begin_comment
comment|/// supports such a mechanism, it should be implemented to help
end_comment

begin_comment
comment|/// with crash triage.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] format
end_comment

begin_comment
comment|///     A printf format that will be used to form a new crash
end_comment

begin_comment
comment|///     description string.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|void
name|SetCrashDescriptionWithFormat
parameter_list|(
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
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|void
name|SetCrashDescription
parameter_list|(
specifier|const
name|char
modifier|*
name|description
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_function_decl
specifier|static
name|short
name|GetPosixspawnFlags
parameter_list|(
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|Error
name|LaunchProcessPosixSpawn
argument_list|(
specifier|const
name|char
operator|*
name|exe_path
argument_list|,
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
operator|::
name|pid_t
operator|&
name|pid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|pid_t
name|LaunchApplication
argument_list|(
specifier|const
name|FileSpec
operator|&
name|app_file_spec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|Error
name|LaunchProcess
parameter_list|(
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|Error
name|RunShellCommand
argument_list|(
specifier|const
name|char
operator|*
name|command
argument_list|,
comment|// Shouldn't be NULL
specifier|const
name|char
operator|*
name|working_dir
argument_list|,
comment|// Pass NULL to use the current working directory
name|int
operator|*
name|status_ptr
argument_list|,
comment|// Pass NULL if you don't want the process exit status
name|int
operator|*
name|signo_ptr
argument_list|,
comment|// Pass NULL if you don't want the signal that caused the process to exit
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
specifier|const
name|char
operator|*
name|shell
operator|=
name|LLDB_DEFAULT_SHELL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|DataBufferSP
name|GetAuxvData
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|TargetSP
name|GetDummyTarget
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|void
name|Backtrace
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
name|uint32_t
name|max_frames
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

begin_enum
enum|enum
name|DynamicLibraryOpenOptions
block|{
name|eDynamicLibraryOpenOptionLazy
init|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|,
comment|// Lazily resolve symbols in this dynamic library
name|eDynamicLibraryOpenOptionLocal
init|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|,
comment|// Only open a shared library with local access (hide it from the global symbol namespace)
name|eDynamicLibraryOpenOptionLimitGetSymbol
init|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
comment|// DynamicLibraryGetSymbol calls on this handle will only return matches from this shared library
block|}
enum|;
end_enum

begin_function_decl
specifier|static
name|void
modifier|*
name|DynamicLibraryOpen
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file_spec
parameter_list|,
name|uint32_t
name|options
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Error
name|DynamicLibraryClose
parameter_list|(
name|void
modifier|*
name|dynamic_library_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
modifier|*
name|DynamicLibraryGetSymbol
parameter_list|(
name|void
modifier|*
name|dynamic_library_handle
parameter_list|,
specifier|const
name|char
modifier|*
name|symbol_name
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Error
name|MakeDirectory
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|uint32_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Error
name|GetFilePermissions
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|uint32_t
modifier|&
name|file_permissions
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Error
name|SetFilePermissions
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|uint32_t
name|file_permissions
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Error
name|Symlink
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
specifier|const
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Error
name|Readlink
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Error
name|Unlink
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const FileSpec& file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t mode
argument_list|,
argument|Error&error
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|CloseFile
argument_list|(
name|lldb
operator|::
name|user_id_t
name|fd
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint64_t
name|WriteFile
argument_list|(
name|lldb
operator|::
name|user_id_t
name|fd
argument_list|,
name|uint64_t
name|offset
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|uint64_t
name|src_len
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint64_t
name|ReadFile
argument_list|(
name|lldb
operator|::
name|user_id_t
name|fd
argument_list|,
name|uint64_t
name|offset
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint64_t
name|dst_len
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|bool
name|GetFileExists
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|CalculateMD5
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file_spec
parameter_list|,
name|uint64_t
modifier|&
name|low
parameter_list|,
name|uint64_t
modifier|&
name|high
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// namespace lldb_private
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

