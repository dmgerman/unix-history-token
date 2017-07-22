begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Platform.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Platform_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Platform_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
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
file|"lldb/Core/ArchSpec.h"
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
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_comment
comment|// TODO pull NativeDelegate class out of NativeProcessProtocol so we
end_comment

begin_comment
comment|// can just forward ref the NativeDelegate rather than include it here.
end_comment

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeProcessProtocol.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ModuleCache
decl_stmt|;
enum|enum
name|MmapFlags
block|{
name|eMmapFlagsPrivate
init|=
literal|1
block|,
name|eMmapFlagsAnon
init|=
literal|2
block|}
enum|;
name|class
name|PlatformProperties
range|:
name|public
name|Properties
block|{
name|public
operator|:
name|PlatformProperties
argument_list|()
block|;
specifier|static
name|ConstString
name|GetSettingName
argument_list|()
block|;
name|bool
name|GetUseModuleCache
argument_list|()
specifier|const
block|;
name|bool
name|SetUseModuleCache
argument_list|(
argument|bool use_module_cache
argument_list|)
block|;
name|FileSpec
name|GetModuleCacheDirectory
argument_list|()
specifier|const
block|;
name|bool
name|SetModuleCacheDirectory
argument_list|(
specifier|const
name|FileSpec
operator|&
name|dir_spec
argument_list|)
block|; }
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|PlatformProperties
operator|>
name|PlatformPropertiesSP
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class Platform Platform.h "lldb/Target/Platform.h"
comment|/// @brief A plug-in interface definition class for debug platform that
comment|/// includes many platform abilities such as:
comment|///     @li getting platform information such as supported architectures,
comment|///         supported binary file formats and more
comment|///     @li launching new processes
comment|///     @li attaching to existing processes
comment|///     @li download/upload files
comment|///     @li execute shell commands
comment|///     @li listing and getting info for existing processes
comment|///     @li attaching and possibly debugging the platform's kernel
comment|//----------------------------------------------------------------------
name|class
name|Platform
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Default Constructor
comment|//------------------------------------------------------------------
name|Platform
argument_list|(
argument|bool is_host_platform
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class is designed to be
comment|/// inherited from by the plug-in instance.
comment|//------------------------------------------------------------------
operator|~
name|Platform
argument_list|()
name|override
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
specifier|const
name|PlatformPropertiesSP
operator|&
name|GetGlobalPlatformProperties
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get the native host platform plug-in.
comment|///
comment|/// There should only be one of these for each host that LLDB runs
comment|/// upon that should be statically compiled in and registered using
comment|/// preprocessor macros or other similar build mechanisms in a
comment|/// PlatformSubclass::Initialize() function.
comment|///
comment|/// This platform will be used as the default platform when launching
comment|/// or attaching to processes unless another platform is specified.
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|PlatformSP
name|GetHostPlatform
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|PlatformSP
name|GetPlatformForArchitecture
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|,
name|ArchSpec
operator|*
name|platform_arch_ptr
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetHostPlatformName
argument_list|()
block|;
specifier|static
name|void
name|SetHostPlatform
argument_list|(
specifier|const
name|lldb
operator|::
name|PlatformSP
operator|&
name|platform_sp
argument_list|)
block|;
comment|// Find an existing platform plug-in by name
specifier|static
name|lldb
operator|::
name|PlatformSP
name|Find
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|PlatformSP
name|Create
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|Status
operator|&
name|error
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|PlatformSP
name|Create
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|,
name|ArchSpec
operator|*
name|platform_arch_ptr
argument_list|,
name|Status
operator|&
name|error
argument_list|)
block|;
specifier|static
name|uint32_t
name|GetNumConnectedRemotePlatforms
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|PlatformSP
name|GetConnectedRemotePlatformAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Find a platform plugin for a given process.
comment|///
comment|/// Scans the installed Platform plug-ins and tries to find
comment|/// an instance that can be used for \a process
comment|///
comment|/// @param[in] process
comment|///     The process for which to try and locate a platform
comment|///     plug-in instance.
comment|///
comment|/// @param[in] plugin_name
comment|///     An optional name of a specific platform plug-in that
comment|///     should be used. If nullptr, pick the best plug-in.
comment|//------------------------------------------------------------------
comment|//        static lldb::PlatformSP
comment|//        FindPlugin (Process *process, const ConstString&plugin_name);
comment|//------------------------------------------------------------------
comment|/// Set the target's executable based off of the existing
comment|/// architecture information in \a target given a path to an
comment|/// executable \a exe_file.
comment|///
comment|/// Each platform knows the architectures that it supports and can
comment|/// select the correct architecture slice within \a exe_file by
comment|/// inspecting the architecture in \a target. If the target had an
comment|/// architecture specified, then in can try and obey that request
comment|/// and optionally fail if the architecture doesn't match up.
comment|/// If no architecture is specified, the platform should select the
comment|/// default architecture from \a exe_file. Any application bundles
comment|/// or executable wrappers can also be inspected for the actual
comment|/// application binary within the bundle that should be used.
comment|///
comment|/// @return
comment|///     Returns \b true if this Platform plug-in was able to find
comment|///     a suitable executable, \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|ResolveExecutable
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|FileSpecList
operator|*
name|module_search_paths_ptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Find a symbol file given a symbol file module specification.
comment|///
comment|/// Each platform might have tricks to find symbol files for an
comment|/// executable given information in a symbol file ModuleSpec. Some
comment|/// platforms might also support symbol files that are bundles and
comment|/// know how to extract the right symbol file given a bundle.
comment|///
comment|/// @param[in] target
comment|///     The target in which we are trying to resolve the symbol file.
comment|///     The target has a list of modules that we might be able to
comment|///     use in order to help find the right symbol file. If the
comment|///     "m_file" or "m_platform_file" entries in the \a sym_spec
comment|///     are filled in, then we might be able to locate a module in
comment|///     the target, extract its UUID and locate a symbol file.
comment|///     If just the "m_uuid" is specified, then we might be able
comment|///     to find the module in the target that matches that UUID
comment|///     and pair the symbol file along with it. If just "m_symbol_file"
comment|///     is specified, we can use a variety of tricks to locate the
comment|///     symbols in an SDK, PDK, or other development kit location.
comment|///
comment|/// @param[in] sym_spec
comment|///     A module spec that describes some information about the
comment|///     symbol file we are trying to resolve. The ModuleSpec might
comment|///     contain the following:
comment|///     m_file - A full or partial path to an executable from the
comment|///              target (might be empty).
comment|///     m_platform_file - Another executable hint that contains
comment|///                       the path to the file as known on the
comment|///                       local/remote platform.
comment|///     m_symbol_file - A full or partial path to a symbol file
comment|///                     or symbol bundle that should be used when
comment|///                     trying to resolve the symbol file.
comment|///     m_arch - The architecture we are looking for when resolving
comment|///              the symbol file.
comment|///     m_uuid - The UUID of the executable and symbol file. This
comment|///              can often be used to match up an executable with
comment|///              a symbol file, or resolve an symbol file in a
comment|///              symbol file bundle.
comment|///
comment|/// @param[out] sym_file
comment|///     The resolved symbol file spec if the returned error
comment|///     indicates success.
comment|///
comment|/// @return
comment|///     Returns an error that describes success or failure.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|ResolveSymbolFile
argument_list|(
name|Target
operator|&
name|target
argument_list|,
specifier|const
name|ModuleSpec
operator|&
name|sym_spec
argument_list|,
name|FileSpec
operator|&
name|sym_file
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Resolves the FileSpec to a (possibly) remote path. Remote
comment|/// platforms must override this to resolve to a path on the remote
comment|/// side.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|ResolveRemotePath
argument_list|(
specifier|const
name|FileSpec
operator|&
name|platform_path
argument_list|,
name|FileSpec
operator|&
name|resolved_platform_path
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Get the OS version from a connected platform.
comment|///
comment|/// Some platforms might not be connected to a remote platform, but
comment|/// can figure out the OS version for a process. This is common for
comment|/// simulator platforms that will run native programs on the current
comment|/// host, but the simulator might be simulating a different OS. The
comment|/// \a process parameter might be specified to help to determine
comment|/// the OS version.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetOSVersion
argument_list|(
name|uint32_t
operator|&
name|major
argument_list|,
name|uint32_t
operator|&
name|minor
argument_list|,
name|uint32_t
operator|&
name|update
argument_list|,
name|Process
operator|*
name|process
operator|=
name|nullptr
argument_list|)
block|;
name|bool
name|SetOSVersion
argument_list|(
argument|uint32_t major
argument_list|,
argument|uint32_t minor
argument_list|,
argument|uint32_t update
argument_list|)
block|;
name|bool
name|GetOSBuildString
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
name|bool
name|GetOSKernelDescription
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
comment|// Returns the name of the platform
name|ConstString
name|GetName
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetHostname
argument_list|()
block|;
name|virtual
name|ConstString
name|GetFullNameForDylib
argument_list|(
argument|ConstString basename
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Report the current status for this platform.
comment|///
comment|/// The returned string usually involves returning the OS version
comment|/// (if available), and any SDK directory that might be being used
comment|/// for local file caching, and if connected a quick blurb about
comment|/// what this platform is connected to.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|GetStatus
argument_list|(
name|Stream
operator|&
name|strm
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Subclasses must be able to fetch the current OS version
comment|//
comment|// Remote classes must be connected for this to succeed. Local
comment|// subclasses don't need to override this function as it will just
comment|// call the HostInfo::GetOSVersion().
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetRemoteOSVersion
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|GetRemoteOSBuildString
argument_list|(
argument|std::string&s
argument_list|)
block|{
name|s
operator|.
name|clear
argument_list|()
block|;
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|GetRemoteOSKernelDescription
argument_list|(
argument|std::string&s
argument_list|)
block|{
name|s
operator|.
name|clear
argument_list|()
block|;
return|return
name|false
return|;
block|}
comment|// Remote Platform subclasses need to override this function
name|virtual
name|ArchSpec
name|GetRemoteSystemArchitecture
argument_list|()
block|{
return|return
name|ArchSpec
argument_list|()
return|;
comment|// Return an invalid architecture
block|}
name|virtual
name|FileSpec
name|GetRemoteWorkingDirectory
argument_list|()
block|{
return|return
name|m_working_dir
return|;
block|}
name|virtual
name|bool
name|SetRemoteWorkingDirectory
argument_list|(
specifier|const
name|FileSpec
operator|&
name|working_dir
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetUserName
argument_list|(
argument|uint32_t uid
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetGroupName
argument_list|(
argument|uint32_t gid
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Locate a file for a platform.
comment|///
comment|/// The default implementation of this function will return the same
comment|/// file patch in \a local_file as was in \a platform_file.
comment|///
comment|/// @param[in] platform_file
comment|///     The platform file path to locate and cache locally.
comment|///
comment|/// @param[in] uuid_ptr
comment|///     If we know the exact UUID of the file we are looking for, it
comment|///     can be specified. If it is not specified, we might now know
comment|///     the exact file. The UUID is usually some sort of MD5 checksum
comment|///     for the file and is sometimes known by dynamic linkers/loaders.
comment|///     If the UUID is known, it is best to supply it to platform
comment|///     file queries to ensure we are finding the correct file, not
comment|///     just a file at the correct path.
comment|///
comment|/// @param[out] local_file
comment|///     A locally cached version of the platform file. For platforms
comment|///     that describe the current host computer, this will just be
comment|///     the same file. For remote platforms, this file might come from
comment|///     and SDK directory, or might need to be sync'ed over to the
comment|///     current machine for efficient debugging access.
comment|///
comment|/// @return
comment|///     An error object.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|GetFileWithUUID
argument_list|(
specifier|const
name|FileSpec
operator|&
name|platform_file
argument_list|,
specifier|const
name|UUID
operator|*
name|uuid_ptr
argument_list|,
name|FileSpec
operator|&
name|local_file
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Locate the scripting resource given a module specification.
comment|//
comment|// Locating the file should happen only on the local computer or using
comment|// the current computers global settings.
comment|//----------------------------------------------------------------------
name|virtual
name|FileSpecList
name|LocateExecutableScriptingResources
argument_list|(
name|Target
operator|*
name|target
argument_list|,
name|Module
operator|&
name|module
argument_list|,
name|Stream
operator|*
name|feedback_stream
argument_list|)
block|;
name|virtual
name|Status
name|GetSharedModule
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|Process
operator|*
name|process
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|FileSpecList
operator|*
name|module_search_paths_ptr
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|*
name|old_module_sp_ptr
argument_list|,
name|bool
operator|*
name|did_create_ptr
argument_list|)
block|;
name|virtual
name|bool
name|GetModuleSpec
argument_list|(
specifier|const
name|FileSpec
operator|&
name|module_file_spec
argument_list|,
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|,
name|ModuleSpec
operator|&
name|module_spec
argument_list|)
block|;
name|virtual
name|Status
name|ConnectRemote
argument_list|(
name|Args
operator|&
name|args
argument_list|)
block|;
name|virtual
name|Status
name|DisconnectRemote
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get the platform's supported architectures in the order in which
comment|/// they should be searched.
comment|///
comment|/// @param[in] idx
comment|///     A zero based architecture index
comment|///
comment|/// @param[out] arch
comment|///     A copy of the architecture at index if the return value is
comment|///     \b true.
comment|///
comment|/// @return
comment|///     \b true if \a arch was filled in and is valid, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|ArchSpec&arch
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
name|Target
operator|&
name|target
argument_list|,
name|BreakpointSite
operator|*
name|bp_site
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Launch a new process on a platform, not necessarily for
comment|/// debugging, it could be just for running the process.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|LaunchProcess
argument_list|(
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Perform expansion of the command-line for this launch info
comment|/// This can potentially involve wildcard expansion
comment|//  environment variable replacement, and whatever other
comment|//  argument magic the platform defines as part of its typical
comment|//  user experience
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|ShellExpandArguments
argument_list|(
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Kill process on a platform.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|KillProcess
argument_list|(
argument|const lldb::pid_t pid
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Lets a platform answer if it is compatible with a given
comment|/// architecture and the target triple contained within.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|IsCompatibleArchitecture
argument_list|(
argument|const ArchSpec&arch
argument_list|,
argument|bool exact_arch_match
argument_list|,
argument|ArchSpec *compatible_arch_ptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Not all platforms will support debugging a process by spawning
comment|/// somehow halted for a debugger (specified using the
comment|/// "eLaunchFlagDebug" launch flag) and then attaching. If your
comment|/// platform doesn't support this, override this function and return
comment|/// false.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|CanDebugProcess
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Subclasses do not need to implement this function as it uses
comment|/// the Platform::LaunchProcess() followed by Platform::Attach ().
comment|/// Remote platforms will want to subclass this function in order
comment|/// to be able to intercept STDIO and possibly launch a separate
comment|/// process that will debug the debuggee.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ProcessSP
name|DebugProcess
argument_list|(
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|Debugger
operator|&
name|debugger
argument_list|,
name|Target
operator|*
name|target
argument_list|,
comment|// Can be nullptr, if nullptr create a new
comment|// target, else use existing one
name|Status
operator|&
name|error
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ProcessSP
name|ConnectProcess
argument_list|(
argument|llvm::StringRef connect_url
argument_list|,
argument|llvm::StringRef plugin_name
argument_list|,
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Target *target
argument_list|,
argument|lldb_private::Status&error
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Attach to an existing process using a process ID.
comment|///
comment|/// Each platform subclass needs to implement this function and
comment|/// attempt to attach to the process with the process ID of \a pid.
comment|/// The platform subclass should return an appropriate ProcessSP
comment|/// subclass that is attached to the process, or an empty shared
comment|/// pointer with an appropriate error.
comment|///
comment|/// @param[in] pid
comment|///     The process ID that we should attempt to attach to.
comment|///
comment|/// @return
comment|///     An appropriate ProcessSP containing a valid shared pointer
comment|///     to the default Process subclass for the platform that is
comment|///     attached to the process, or an empty shared pointer with an
comment|///     appropriate error fill into the \a error object.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ProcessSP
name|Attach
argument_list|(
name|ProcessAttachInfo
operator|&
name|attach_info
argument_list|,
name|Debugger
operator|&
name|debugger
argument_list|,
name|Target
operator|*
name|target
argument_list|,
comment|// Can be nullptr, if nullptr
comment|// create a new target, else
comment|// use existing one
name|Status
operator|&
name|error
argument_list|)
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Attach to an existing process by process name.
comment|///
comment|/// This function is not meant to be overridden by Process
comment|/// subclasses. It will first call
comment|/// Process::WillAttach (const char *) and if that returns \b
comment|/// true, Process::DoAttach (const char *) will be called to
comment|/// actually do the attach. If DoAttach returns \b true, then
comment|/// Process::DidAttach() will be called.
comment|///
comment|/// @param[in] process_name
comment|///     A process name to match against the current process list.
comment|///
comment|/// @return
comment|///     Returns \a pid if attaching was successful, or
comment|///     LLDB_INVALID_PROCESS_ID if attaching fails.
comment|//------------------------------------------------------------------
comment|//        virtual lldb::ProcessSP
comment|//        Attach (const char *process_name,
comment|//                bool wait_for_launch,
comment|//                Status&error) = 0;
comment|//------------------------------------------------------------------
comment|// The base class Platform will take care of the host platform.
comment|// Subclasses will need to fill in the remote case.
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|FindProcesses
argument_list|(
specifier|const
name|ProcessInstanceInfoMatch
operator|&
name|match_info
argument_list|,
name|ProcessInstanceInfoList
operator|&
name|proc_infos
argument_list|)
block|;
name|virtual
name|bool
name|GetProcessInfo
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|ProcessInstanceInfo&proc_info
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Set a breakpoint on all functions that can end up creating a thread
comment|// for this platform. This is needed when running expressions and
comment|// also for process control.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|BreakpointSP
name|SetThreadCreationBreakpoint
argument_list|(
name|Target
operator|&
name|target
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Given a target, find the local SDK directory if one exists on the
comment|// current host.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetSDKDirectory
argument_list|(
argument|lldb_private::Target&target
argument_list|)
block|{
return|return
name|lldb_private
operator|::
name|ConstString
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|GetRemoteURL
argument_list|()
specifier|const
block|{
return|return
name|m_remote_url
return|;
block|}
name|bool
name|IsHost
argument_list|()
specifier|const
block|{
return|return
name|m_is_host
return|;
comment|// Is this the default host platform?
block|}
name|bool
name|IsRemote
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_is_host
return|;
block|}
name|virtual
name|bool
name|IsConnected
argument_list|()
specifier|const
block|{
comment|// Remote subclasses should override this function
return|return
name|IsHost
argument_list|()
return|;
block|}
specifier|const
name|ArchSpec
operator|&
name|GetSystemArchitecture
argument_list|()
block|;
name|void
name|SetSystemArchitecture
argument_list|(
argument|const ArchSpec&arch
argument_list|)
block|{
name|m_system_arch
operator|=
name|arch
block|;
if|if
condition|(
name|IsHost
argument_list|()
condition|)
name|m_os_version_set_while_connected
operator|=
name|m_system_arch
operator|.
name|IsValid
argument_list|()
expr_stmt|;
block|}
comment|// Used for column widths
name|size_t
name|GetMaxUserIDNameLength
argument_list|()
specifier|const
block|{
return|return
name|m_max_uid_name_len
return|;
block|}
comment|// Used for column widths
name|size_t
name|GetMaxGroupIDNameLength
argument_list|()
specifier|const
block|{
return|return
name|m_max_gid_name_len
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetSDKRootDirectory
argument_list|()
specifier|const
block|{
return|return
name|m_sdk_sysroot
return|;
block|}
name|void
name|SetSDKRootDirectory
argument_list|(
argument|const ConstString&dir
argument_list|)
block|{
name|m_sdk_sysroot
operator|=
name|dir
block|; }
specifier|const
name|ConstString
operator|&
name|GetSDKBuild
argument_list|()
specifier|const
block|{
return|return
name|m_sdk_build
return|;
block|}
name|void
name|SetSDKBuild
argument_list|(
argument|const ConstString&sdk_build
argument_list|)
block|{
name|m_sdk_build
operator|=
name|sdk_build
block|; }
comment|// Override this to return true if your platform supports Clang modules.
comment|// You may also need to override AddClangModuleCompilationOptions to pass the
comment|// right Clang flags for your platform.
name|virtual
name|bool
name|SupportsModules
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|// Appends the platform-specific options required to find the modules for the
comment|// current platform.
name|virtual
name|void
name|AddClangModuleCompilationOptions
argument_list|(
name|Target
operator|*
name|target
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|options
argument_list|)
block|;
name|FileSpec
name|GetWorkingDirectory
argument_list|()
block|;
name|bool
name|SetWorkingDirectory
argument_list|(
specifier|const
name|FileSpec
operator|&
name|working_dir
argument_list|)
block|;
comment|// There may be modules that we don't want to find by default for operations
comment|// like "setting breakpoint by name".
comment|// The platform will return "true" from this call if the passed in module
comment|// happens to be one of these.
name|virtual
name|bool
name|ModuleIsExcludedForUnconstrainedSearches
argument_list|(
argument|Target&target
argument_list|,
argument|const lldb::ModuleSP&module_sp
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|Status
name|MakeDirectory
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t permissions
argument_list|)
block|;
name|virtual
name|Status
name|GetFilePermissions
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|,
name|uint32_t
operator|&
name|file_permissions
argument_list|)
block|;
name|virtual
name|Status
name|SetFilePermissions
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t file_permissions
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t mode
argument_list|,
argument|Status&error
argument_list|)
block|{
return|return
name|UINT64_MAX
return|;
block|}
name|virtual
name|bool
name|CloseFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|Status&error
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
argument|const FileSpec&file_spec
argument_list|)
block|{
return|return
name|UINT64_MAX
return|;
block|}
name|virtual
name|uint64_t
name|ReadFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|void *dst
argument_list|,
argument|uint64_t dst_len
argument_list|,
argument|Status&error
argument_list|)
block|{
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"Platform::ReadFile() is not supported in the %s platform"
argument_list|,
name|GetName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
block|;
return|return
operator|-
literal|1
return|;
block|}
name|virtual
name|uint64_t
name|WriteFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|const void *src
argument_list|,
argument|uint64_t src_len
argument_list|,
argument|Status&error
argument_list|)
block|{
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"Platform::ReadFile() is not supported in the %s platform"
argument_list|,
name|GetName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
block|;
return|return
operator|-
literal|1
return|;
block|}
name|virtual
name|Status
name|GetFile
argument_list|(
specifier|const
name|FileSpec
operator|&
name|source
argument_list|,
specifier|const
name|FileSpec
operator|&
name|destination
argument_list|)
block|;
name|virtual
name|Status
name|PutFile
argument_list|(
argument|const FileSpec&source
argument_list|,
argument|const FileSpec&destination
argument_list|,
argument|uint32_t uid = UINT32_MAX
argument_list|,
argument|uint32_t gid = UINT32_MAX
argument_list|)
block|;
name|virtual
name|Status
name|CreateSymlink
argument_list|(
specifier|const
name|FileSpec
operator|&
name|src
argument_list|,
comment|// The name of the link is in src
specifier|const
name|FileSpec
operator|&
name|dst
argument_list|)
block|;
comment|// The symlink points to dst
comment|//----------------------------------------------------------------------
comment|/// Install a file or directory to the remote system.
comment|///
comment|/// Install is similar to Platform::PutFile(), but it differs in that if
comment|/// an application/framework/shared library is installed on a remote
comment|/// platform and the remote platform requires something to be done to
comment|/// register the application/framework/shared library, then this extra
comment|/// registration can be done.
comment|///
comment|/// @param[in] src
comment|///     The source file/directory to install on the remote system.
comment|///
comment|/// @param[in] dst
comment|///     The destination file/directory where \a src will be installed.
comment|///     If \a dst has no filename specified, then its filename will
comment|///     be set from \a src. It \a dst has no directory specified, it
comment|///     will use the platform working directory. If \a dst has a
comment|///     directory specified, but the directory path is relative, the
comment|///     platform working directory will be prepended to the relative
comment|///     directory.
comment|///
comment|/// @return
comment|///     An error object that describes anything that went wrong.
comment|//----------------------------------------------------------------------
name|virtual
name|Status
name|Install
argument_list|(
specifier|const
name|FileSpec
operator|&
name|src
argument_list|,
specifier|const
name|FileSpec
operator|&
name|dst
argument_list|)
block|;
name|virtual
name|size_t
name|GetEnvironment
argument_list|(
name|StringList
operator|&
name|environment
argument_list|)
block|;
name|virtual
name|bool
name|GetFileExists
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|virtual
name|Status
name|Unlink
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|virtual
name|uint64_t
name|ConvertMmapFlagsToPlatform
argument_list|(
argument|const ArchSpec&arch
argument_list|,
argument|unsigned flags
argument_list|)
block|;
name|virtual
name|bool
name|GetSupportsRSync
argument_list|()
block|{
return|return
name|m_supports_rsync
return|;
block|}
name|virtual
name|void
name|SetSupportsRSync
argument_list|(
argument|bool flag
argument_list|)
block|{
name|m_supports_rsync
operator|=
name|flag
block|; }
name|virtual
specifier|const
name|char
operator|*
name|GetRSyncOpts
argument_list|()
block|{
return|return
name|m_rsync_opts
operator|.
name|c_str
argument_list|()
return|;
block|}
name|virtual
name|void
name|SetRSyncOpts
argument_list|(
argument|const char *opts
argument_list|)
block|{
name|m_rsync_opts
operator|.
name|assign
argument_list|(
name|opts
argument_list|)
block|; }
name|virtual
specifier|const
name|char
operator|*
name|GetRSyncPrefix
argument_list|()
block|{
return|return
name|m_rsync_prefix
operator|.
name|c_str
argument_list|()
return|;
block|}
name|virtual
name|void
name|SetRSyncPrefix
argument_list|(
argument|const char *prefix
argument_list|)
block|{
name|m_rsync_prefix
operator|.
name|assign
argument_list|(
name|prefix
argument_list|)
block|;   }
name|virtual
name|bool
name|GetSupportsSSH
argument_list|()
block|{
return|return
name|m_supports_ssh
return|;
block|}
name|virtual
name|void
name|SetSupportsSSH
argument_list|(
argument|bool flag
argument_list|)
block|{
name|m_supports_ssh
operator|=
name|flag
block|; }
name|virtual
specifier|const
name|char
operator|*
name|GetSSHOpts
argument_list|()
block|{
return|return
name|m_ssh_opts
operator|.
name|c_str
argument_list|()
return|;
block|}
name|virtual
name|void
name|SetSSHOpts
argument_list|(
argument|const char *opts
argument_list|)
block|{
name|m_ssh_opts
operator|.
name|assign
argument_list|(
name|opts
argument_list|)
block|; }
name|virtual
name|bool
name|GetIgnoresRemoteHostname
argument_list|()
block|{
return|return
name|m_ignores_remote_hostname
return|;
block|}
name|virtual
name|void
name|SetIgnoresRemoteHostname
argument_list|(
argument|bool flag
argument_list|)
block|{
name|m_ignores_remote_hostname
operator|=
name|flag
block|;   }
name|virtual
name|lldb_private
operator|::
name|OptionGroupOptions
operator|*
name|GetConnectionOptions
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|lldb_private
operator|::
name|Status
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
comment|// Shouldn't be nullptr
argument|const FileSpec&working_dir
argument_list|,
comment|// Pass empty FileSpec to use the current
comment|// working directory
argument|int *status_ptr
argument_list|,
comment|// Pass nullptr if you don't want the process exit status
argument|int *signo_ptr
argument_list|,
comment|// Pass nullptr if you don't want the signal that caused
comment|// the process to exit
argument|std::string           *command_output
argument_list|,
comment|// Pass nullptr if you don't want the command output
argument|uint32_t timeout_sec
argument_list|)
block|;
comment|// Timeout in seconds to wait for shell program to
comment|// finish
name|virtual
name|void
name|SetLocalCacheDirectory
argument_list|(
specifier|const
name|char
operator|*
name|local
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetLocalCacheDirectory
argument_list|()
block|;
name|virtual
name|std
operator|::
name|string
name|GetPlatformSpecificConnectionInformation
argument_list|()
block|{
return|return
literal|""
return|;
block|}
name|virtual
name|bool
name|CalculateMD5
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|,
name|uint64_t
operator|&
name|low
argument_list|,
name|uint64_t
operator|&
name|high
argument_list|)
block|;
name|virtual
name|int32_t
name|GetResumeCountForLaunchInfo
argument_list|(
argument|ProcessLaunchInfo&launch_info
argument_list|)
block|{
return|return
literal|1
return|;
block|}
name|virtual
specifier|const
name|lldb
operator|::
name|UnixSignalsSP
operator|&
name|GetRemoteUnixSignals
argument_list|()
block|;
specifier|const
name|lldb
operator|::
name|UnixSignalsSP
operator|&
name|GetUnixSignals
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Locate a queue name given a thread's qaddr
comment|///
comment|/// On a system using libdispatch ("Grand Central Dispatch") style
comment|/// queues, a thread may be associated with a GCD queue or not,
comment|/// and a queue may be associated with multiple threads.
comment|/// The process/thread must provide a way to find the "dispatch_qaddr"
comment|/// for each thread, and from that dispatch_qaddr this Platform method
comment|/// will locate the queue name and provide that.
comment|///
comment|/// @param[in] process
comment|///     A process is required for reading memory.
comment|///
comment|/// @param[in] dispatch_qaddr
comment|///     The dispatch_qaddr for this thread.
comment|///
comment|/// @return
comment|///     The name of the queue, if there is one.  An empty string
comment|///     means that this thread is not associated with a dispatch
comment|///     queue.
comment|//------------------------------------------------------------------
name|virtual
name|std
operator|::
name|string
name|GetQueueNameForThreadQAddress
argument_list|(
argument|Process *process
argument_list|,
argument|lldb::addr_t dispatch_qaddr
argument_list|)
block|{
return|return
literal|""
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Locate a queue ID given a thread's qaddr
comment|///
comment|/// On a system using libdispatch ("Grand Central Dispatch") style
comment|/// queues, a thread may be associated with a GCD queue or not,
comment|/// and a queue may be associated with multiple threads.
comment|/// The process/thread must provide a way to find the "dispatch_qaddr"
comment|/// for each thread, and from that dispatch_qaddr this Platform method
comment|/// will locate the queue ID and provide that.
comment|///
comment|/// @param[in] process
comment|///     A process is required for reading memory.
comment|///
comment|/// @param[in] dispatch_qaddr
comment|///     The dispatch_qaddr for this thread.
comment|///
comment|/// @return
comment|///     The queue_id for this thread, if this thread is associated
comment|///     with a dispatch queue.  Else LLDB_INVALID_QUEUE_ID is returned.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|queue_id_t
name|GetQueueIDForThreadQAddress
argument_list|(
argument|Process *process
argument_list|,
argument|lldb::addr_t dispatch_qaddr
argument_list|)
block|{
return|return
name|LLDB_INVALID_QUEUE_ID
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Provide a list of trap handler function names for this platform
comment|///
comment|/// The unwinder needs to treat trap handlers specially -- the stack
comment|/// frame may not be aligned correctly for a trap handler (the kernel
comment|/// often won't perturb the stack pointer, or won't re-align it properly,
comment|/// in the process of calling the handler) and the frame above the handler
comment|/// needs to be treated by the unwinder's "frame 0" rules instead of its
comment|/// "middle of the stack frame" rules.
comment|///
comment|/// In a user process debugging scenario, the list of trap handlers is
comment|/// typically just "_sigtramp".
comment|///
comment|/// The Platform base class provides the m_trap_handlers ivar but it does
comment|/// not populate it.  Subclasses should add the names of the asynchronous
comment|/// signal handler routines as needed.  For most Unix platforms, add
comment|/// _sigtramp.
comment|///
comment|/// @return
comment|///     A list of symbol names.  The list may be empty.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|GetTrapHandlerSymbolNames
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Find a support executable that may not live within in the
comment|/// standard locations related to LLDB.
comment|///
comment|/// Executable might exist within the Platform SDK directories, or
comment|/// in standard tool directories within the current IDE that is
comment|/// running LLDB.
comment|///
comment|/// @param[in] basename
comment|///     The basename of the executable to locate in the current
comment|///     platform.
comment|///
comment|/// @return
comment|///     A FileSpec pointing to the executable on disk, or an invalid
comment|///     FileSpec if the executable cannot be found.
comment|//------------------------------------------------------------------
name|virtual
name|FileSpec
name|LocateExecutable
argument_list|(
argument|const char *basename
argument_list|)
block|{
return|return
name|FileSpec
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Allow the platform to set preferred memory cache line size. If non-zero
comment|/// (and the user
comment|/// has not set cache line size explicitly), this value will be used as the
comment|/// cache line
comment|/// size for memory reads.
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetDefaultMemoryCacheLineSize
argument_list|()
block|{
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Load a shared library into this process.
comment|///
comment|/// Try and load a shared library into the current process. This
comment|/// call might fail in the dynamic loader plug-in says it isn't safe
comment|/// to try and load shared libraries at the moment.
comment|///
comment|/// @param[in] process
comment|///     The process to load the image.
comment|///
comment|/// @param[in] local_file
comment|///     The file spec that points to the shared library that you want
comment|///     to load if the library is located on the host. The library will
comment|///     be copied over to the location specified by remote_file or into
comment|///     the current working directory with the same filename if the
comment|///     remote_file isn't specified.
comment|///
comment|/// @param[in] remote_file
comment|///     If local_file is specified then the location where the library
comment|///     should be copied over from the host. If local_file isn't
comment|///     specified, then the path for the shared library on the target
comment|///     what you want to load.
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
name|uint32_t
name|LoadImage
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|local_file
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|remote_file
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
block|;
name|virtual
name|uint32_t
name|DoLoadImage
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|remote_file
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
block|;
name|virtual
name|Status
name|UnloadImage
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|uint32_t image_token
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Connect to all processes waiting for a debugger to attach
comment|///
comment|/// If the platform have a list of processes waiting for a debugger
comment|/// to connect to them then connect to all of these pending processes.
comment|///
comment|/// @param[in] debugger
comment|///     The debugger used for the connect.
comment|///
comment|/// @param[out] error
comment|///     If an error occurred during the connect then this object will
comment|///     contain the error message.
comment|///
comment|/// @return
comment|///     The number of processes we are successfully connected to.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|ConnectToWaitingProcesses
argument_list|(
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
block|;
name|protected
operator|:
name|bool
name|m_is_host
block|;
comment|// Set to true when we are able to actually set the OS version while
comment|// being connected. For remote platforms, we might set the version ahead
comment|// of time before we actually connect and this version might change when
comment|// we actually connect to a remote platform. For the host platform this
comment|// will be set to the once we call HostInfo::GetOSVersion().
name|bool
name|m_os_version_set_while_connected
block|;
name|bool
name|m_system_arch_set_while_connected
block|;
name|ConstString
name|m_sdk_sysroot
block|;
comment|// the root location of where the SDK files are all located
name|ConstString
name|m_sdk_build
block|;
name|FileSpec
name|m_working_dir
block|;
comment|// The working directory which is used when installing
comment|// modules that have no install path set
name|std
operator|::
name|string
name|m_remote_url
block|;
name|std
operator|::
name|string
name|m_name
block|;
name|uint32_t
name|m_major_os_version
block|;
name|uint32_t
name|m_minor_os_version
block|;
name|uint32_t
name|m_update_os_version
block|;
name|ArchSpec
name|m_system_arch
block|;
comment|// The architecture of the kernel or the remote platform
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|ConstString
operator|>
name|IDToNameMap
expr_stmt|;
comment|// Mutex for modifying Platform data structures that should only be used for
comment|// non-reentrant code
name|std
operator|::
name|mutex
name|m_mutex
decl_stmt|;
name|IDToNameMap
name|m_uid_map
decl_stmt|;
name|IDToNameMap
name|m_gid_map
decl_stmt|;
name|size_t
name|m_max_uid_name_len
decl_stmt|;
name|size_t
name|m_max_gid_name_len
decl_stmt|;
name|bool
name|m_supports_rsync
decl_stmt|;
name|std
operator|::
name|string
name|m_rsync_opts
expr_stmt|;
name|std
operator|::
name|string
name|m_rsync_prefix
expr_stmt|;
name|bool
name|m_supports_ssh
decl_stmt|;
name|std
operator|::
name|string
name|m_ssh_opts
expr_stmt|;
name|bool
name|m_ignores_remote_hostname
decl_stmt|;
name|std
operator|::
name|string
name|m_local_cache_directory
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
name|m_trap_handlers
expr_stmt|;
name|bool
name|m_calculated_trap_handlers
decl_stmt|;
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleCache
operator|>
name|m_module_cache
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Ask the Platform subclass to fill in the list of trap handler names
comment|///
comment|/// For most Unix user process environments, this will be a single
comment|/// function name, _sigtramp.  More specialized environments may have
comment|/// additional handler names.  The unwinder code needs to know when a
comment|/// trap handler is on the stack because the unwind rules for the frame
comment|/// that caused the trap are different.
comment|///
comment|/// The base class Platform ivar m_trap_handlers should be updated by
comment|/// the Platform subclass when this method is called.  If there are no
comment|/// predefined trap handlers, this method may be a no-op.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CalculateTrapHandlerSymbolNames
parameter_list|()
init|=
literal|0
function_decl|;
specifier|const
name|char
modifier|*
name|GetCachedUserName
parameter_list|(
name|uint32_t
name|uid
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
comment|// return the empty string if our string is NULL
comment|// so we can tell when things were in the negative
comment|// cached (didn't find a valid user name, don't keep
comment|// trying)
specifier|const
specifier|auto
name|pos
init|=
name|m_uid_map
operator|.
name|find
argument_list|(
name|uid
argument_list|)
decl_stmt|;
return|return
operator|(
operator|(
name|pos
operator|!=
name|m_uid_map
operator|.
name|end
argument_list|()
operator|)
condition|?
name|pos
operator|->
name|second
operator|.
name|AsCString
argument_list|(
literal|""
argument_list|)
else|:
name|nullptr
operator|)
return|;
block|}
specifier|const
name|char
modifier|*
name|SetCachedUserName
parameter_list|(
name|uint32_t
name|uid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_len
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|ConstString
name|const_name
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|m_uid_map
index|[
name|uid
index|]
operator|=
name|const_name
expr_stmt|;
if|if
condition|(
name|m_max_uid_name_len
operator|<
name|name_len
condition|)
name|m_max_uid_name_len
operator|=
name|name_len
expr_stmt|;
comment|// Const strings lives forever in our const string pool, so we can return
comment|// the const char *
return|return
name|const_name
operator|.
name|GetCString
argument_list|()
return|;
block|}
name|void
name|SetUserNameNotFound
parameter_list|(
name|uint32_t
name|uid
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_uid_map
index|[
name|uid
index|]
operator|=
name|ConstString
argument_list|()
expr_stmt|;
block|}
name|void
name|ClearCachedUserNames
parameter_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_uid_map
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|GetCachedGroupName
parameter_list|(
name|uint32_t
name|gid
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
comment|// return the empty string if our string is NULL
comment|// so we can tell when things were in the negative
comment|// cached (didn't find a valid group name, don't keep
comment|// trying)
specifier|const
specifier|auto
name|pos
init|=
name|m_gid_map
operator|.
name|find
argument_list|(
name|gid
argument_list|)
decl_stmt|;
return|return
operator|(
operator|(
name|pos
operator|!=
name|m_gid_map
operator|.
name|end
argument_list|()
operator|)
condition|?
name|pos
operator|->
name|second
operator|.
name|AsCString
argument_list|(
literal|""
argument_list|)
else|:
name|nullptr
operator|)
return|;
block|}
specifier|const
name|char
modifier|*
name|SetCachedGroupName
parameter_list|(
name|uint32_t
name|gid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_len
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|ConstString
name|const_name
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|m_gid_map
index|[
name|gid
index|]
operator|=
name|const_name
expr_stmt|;
if|if
condition|(
name|m_max_gid_name_len
operator|<
name|name_len
condition|)
name|m_max_gid_name_len
operator|=
name|name_len
expr_stmt|;
comment|// Const strings lives forever in our const string pool, so we can return
comment|// the const char *
return|return
name|const_name
operator|.
name|GetCString
argument_list|()
return|;
block|}
name|void
name|SetGroupNameNotFound
parameter_list|(
name|uint32_t
name|gid
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_gid_map
index|[
name|gid
index|]
operator|=
name|ConstString
argument_list|()
expr_stmt|;
block|}
name|void
name|ClearCachedGroupNames
parameter_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_gid_map
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|Status
name|GetCachedExecutable
argument_list|(
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|FileSpecList
operator|*
name|module_search_paths_ptr
argument_list|,
name|Platform
operator|&
name|remote_platform
argument_list|)
decl_stmt|;
name|virtual
name|Status
name|DownloadModuleSlice
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|src_file_spec
parameter_list|,
specifier|const
name|uint64_t
name|src_offset
parameter_list|,
specifier|const
name|uint64_t
name|src_size
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|dst_file_spec
parameter_list|)
function_decl|;
name|virtual
name|Status
name|DownloadSymbolFile
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|FileSpec
operator|&
name|dst_file_spec
argument_list|)
decl_stmt|;
name|virtual
specifier|const
name|char
modifier|*
name|GetCacheHostname
parameter_list|()
function_decl|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|Status
argument_list|(
specifier|const
name|ModuleSpec
operator|&
argument_list|)
operator|>
name|ModuleResolver
expr_stmt|;
name|Status
name|GetRemoteSharedModule
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|Process
operator|*
name|process
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|ModuleResolver
operator|&
name|module_resolver
argument_list|,
name|bool
operator|*
name|did_create_ptr
argument_list|)
decl_stmt|;
name|bool
name|GetCachedSharedModule
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
name|bool
operator|*
name|did_create_ptr
argument_list|)
decl_stmt|;
name|Status
name|LoadCachedExecutable
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|FileSpecList
operator|*
name|module_search_paths_ptr
argument_list|,
name|Platform
operator|&
name|remote_platform
argument_list|)
decl_stmt|;
name|FileSpec
name|GetModuleCacheRoot
parameter_list|()
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Platform
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|PlatformList
block|{
name|public
label|:
name|PlatformList
argument_list|()
operator|:
name|m_mutex
argument_list|()
operator|,
name|m_platforms
argument_list|()
operator|,
name|m_selected_platform_sp
argument_list|()
block|{}
operator|~
name|PlatformList
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|Append
argument_list|(
specifier|const
name|lldb
operator|::
name|PlatformSP
operator|&
name|platform_sp
argument_list|,
name|bool
name|set_selected
argument_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_platforms
operator|.
name|push_back
argument_list|(
name|platform_sp
argument_list|)
expr_stmt|;
if|if
condition|(
name|set_selected
condition|)
name|m_selected_platform_sp
operator|=
name|m_platforms
operator|.
name|back
argument_list|()
expr_stmt|;
block|}
name|size_t
name|GetSize
parameter_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
return|return
name|m_platforms
operator|.
name|size
argument_list|()
return|;
block|}
name|lldb
operator|::
name|PlatformSP
name|GetAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
block|{
name|lldb
operator|::
name|PlatformSP
name|platform_sp
block|;
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
block|;
if|if
condition|(
name|idx
operator|<
name|m_platforms
operator|.
name|size
argument_list|()
condition|)
name|platform_sp
operator|=
name|m_platforms
index|[
name|idx
index|]
expr_stmt|;
block|}
return|return
name|platform_sp
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Select the active platform.
comment|///
comment|/// In order to debug remotely, other platform's can be remotely
comment|/// connected to and set as the selected platform for any subsequent
comment|/// debugging. This allows connection to remote targets and allows
comment|/// the ability to discover process info, launch and attach to remote
comment|/// processes.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|PlatformSP
name|GetSelectedPlatform
argument_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
block|;
if|if
condition|(
operator|!
name|m_selected_platform_sp
operator|&&
operator|!
name|m_platforms
operator|.
name|empty
argument_list|()
condition|)
name|m_selected_platform_sp
operator|=
name|m_platforms
operator|.
name|front
argument_list|()
expr_stmt|;
return|return
name|m_selected_platform_sp
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|SetSelectedPlatform
argument_list|(
specifier|const
name|lldb
operator|::
name|PlatformSP
operator|&
name|platform_sp
argument_list|)
block|{
if|if
condition|(
name|platform_sp
condition|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|guard
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
specifier|const
name|size_t
name|num_platforms
init|=
name|m_platforms
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|size_t
name|idx
init|=
literal|0
init|;
name|idx
operator|<
name|num_platforms
condition|;
operator|++
name|idx
control|)
block|{
if|if
condition|(
name|m_platforms
index|[
name|idx
index|]
operator|.
name|get
argument_list|()
operator|==
name|platform_sp
operator|.
name|get
argument_list|()
condition|)
block|{
name|m_selected_platform_sp
operator|=
name|m_platforms
index|[
name|idx
index|]
expr_stmt|;
return|return;
block|}
block|}
name|m_platforms
operator|.
name|push_back
argument_list|(
name|platform_sp
argument_list|)
expr_stmt|;
name|m_selected_platform_sp
operator|=
name|m_platforms
operator|.
name|back
argument_list|()
expr_stmt|;
block|}
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
name|lldb
operator|::
name|PlatformSP
operator|>
name|collection
expr_stmt|;
end_typedef

begin_expr_stmt
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|collection
name|m_platforms
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|PlatformSP
name|m_selected_platform_sp
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|OptionGroupPlatformRSync
range|:
name|public
name|lldb_private
operator|::
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupPlatformRSync
argument_list|()
operator|=
expr|default
block|;
operator|~
name|OptionGroupPlatformRSync
argument_list|()
name|override
operator|=
expr|default
block|;
name|lldb_private
operator|::
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
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
block|;
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
comment|// Options table: Required for subclasses of Options.
specifier|static
name|lldb_private
operator|::
name|OptionDefinition
name|g_option_table
index|[]
block|;
comment|// Instance variables to hold the values for command options.
name|bool
name|m_rsync
block|;
name|std
operator|::
name|string
name|m_rsync_opts
block|;
name|std
operator|::
name|string
name|m_rsync_prefix
block|;
name|bool
name|m_ignores_remote_hostname
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|OptionGroupPlatformRSync
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|OptionGroupPlatformSSH
range|:
name|public
name|lldb_private
operator|::
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupPlatformSSH
argument_list|()
operator|=
expr|default
block|;
operator|~
name|OptionGroupPlatformSSH
argument_list|()
name|override
operator|=
expr|default
block|;
name|lldb_private
operator|::
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
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
block|;
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
comment|// Options table: Required for subclasses of Options.
specifier|static
name|lldb_private
operator|::
name|OptionDefinition
name|g_option_table
index|[]
block|;
comment|// Instance variables to hold the values for command options.
name|bool
name|m_ssh
block|;
name|std
operator|::
name|string
name|m_ssh_opts
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|OptionGroupPlatformSSH
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|OptionGroupPlatformCaching
range|:
name|public
name|lldb_private
operator|::
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupPlatformCaching
argument_list|()
operator|=
expr|default
block|;
operator|~
name|OptionGroupPlatformCaching
argument_list|()
name|override
operator|=
expr|default
block|;
name|lldb_private
operator|::
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
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
block|;
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
comment|// Options table: Required for subclasses of Options.
specifier|static
name|lldb_private
operator|::
name|OptionDefinition
name|g_option_table
index|[]
block|;
comment|// Instance variables to hold the values for command options.
name|std
operator|::
name|string
name|m_cache_dir
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|OptionGroupPlatformCaching
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Platform_h_
end_comment

end_unit

