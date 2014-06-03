begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBTarget.h ----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBTarget_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBTarget_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBAddress.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBBroadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBFileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBFileSpecList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBSymbolContextList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBWatchpoint.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBLaunchInfo
block|{
name|public
label|:
name|SBLaunchInfo
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|argv
argument_list|)
expr_stmt|;
operator|~
name|SBLaunchInfo
argument_list|()
expr_stmt|;
name|uint32_t
name|GetUserID
parameter_list|()
function_decl|;
name|uint32_t
name|GetGroupID
parameter_list|()
function_decl|;
name|bool
name|UserIDIsValid
parameter_list|()
function_decl|;
name|bool
name|GroupIDIsValid
parameter_list|()
function_decl|;
name|void
name|SetUserID
parameter_list|(
name|uint32_t
name|uid
parameter_list|)
function_decl|;
name|void
name|SetGroupID
parameter_list|(
name|uint32_t
name|gid
parameter_list|)
function_decl|;
name|uint32_t
name|GetNumArguments
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetArgumentAtIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|)
function_decl|;
name|void
name|SetArguments
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|bool
name|append
parameter_list|)
function_decl|;
name|uint32_t
name|GetNumEnvironmentEntries
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetEnvironmentEntryAtIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|)
function_decl|;
name|void
name|SetEnvironmentEntries
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|envp
parameter_list|,
name|bool
name|append
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
specifier|const
name|char
operator|*
name|GetWorkingDirectory
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetWorkingDirectory
parameter_list|(
specifier|const
name|char
modifier|*
name|working_dir
parameter_list|)
function_decl|;
name|uint32_t
name|GetLaunchFlags
parameter_list|()
function_decl|;
name|void
name|SetLaunchFlags
parameter_list|(
name|uint32_t
name|flags
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetProcessPluginName
parameter_list|()
function_decl|;
name|void
name|SetProcessPluginName
parameter_list|(
specifier|const
name|char
modifier|*
name|plugin_name
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetShell
parameter_list|()
function_decl|;
name|void
name|SetShell
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
name|uint32_t
name|GetResumeCount
parameter_list|()
function_decl|;
name|void
name|SetResumeCount
parameter_list|(
name|uint32_t
name|c
parameter_list|)
function_decl|;
name|bool
name|AddCloseFileAction
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
name|bool
name|AddDuplicateFileAction
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|dup_fd
parameter_list|)
function_decl|;
name|bool
name|AddOpenFileAction
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
function_decl|;
name|bool
name|AddSuppressFileAction
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
function_decl|;
name|protected
label|:
name|friend
name|class
name|SBTarget
decl_stmt|;
name|lldb_private
operator|::
name|ProcessLaunchInfo
operator|&
name|ref
argument_list|()
expr_stmt|;
name|ProcessLaunchInfoSP
name|m_opaque_sp
decl_stmt|;
block|}
empty_stmt|;
name|class
name|SBAttachInfo
block|{
name|public
label|:
name|SBAttachInfo
argument_list|()
expr_stmt|;
name|SBAttachInfo
argument_list|(
argument|lldb::pid_t pid
argument_list|)
empty_stmt|;
name|SBAttachInfo
argument_list|(
argument|const char *path
argument_list|,
argument|bool wait_for
argument_list|)
empty_stmt|;
name|SBAttachInfo
argument_list|(
specifier|const
name|SBAttachInfo
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBAttachInfo
argument_list|()
expr_stmt|;
name|SBAttachInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBAttachInfo
operator|&
name|rhs
operator|)
decl_stmt|;
name|lldb
operator|::
name|pid_t
name|GetProcessID
argument_list|()
expr_stmt|;
name|void
name|SetProcessID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
name|void
name|SetExecutable
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
name|void
name|SetExecutable
argument_list|(
name|lldb
operator|::
name|SBFileSpec
name|exe_file
argument_list|)
decl_stmt|;
name|bool
name|GetWaitForLaunch
parameter_list|()
function_decl|;
name|void
name|SetWaitForLaunch
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|bool
name|GetIgnoreExisting
parameter_list|()
function_decl|;
name|void
name|SetIgnoreExisting
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|uint32_t
name|GetResumeCount
parameter_list|()
function_decl|;
name|void
name|SetResumeCount
parameter_list|(
name|uint32_t
name|c
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetProcessPluginName
parameter_list|()
function_decl|;
name|void
name|SetProcessPluginName
parameter_list|(
specifier|const
name|char
modifier|*
name|plugin_name
parameter_list|)
function_decl|;
name|uint32_t
name|GetUserID
parameter_list|()
function_decl|;
name|uint32_t
name|GetGroupID
parameter_list|()
function_decl|;
name|bool
name|UserIDIsValid
parameter_list|()
function_decl|;
name|bool
name|GroupIDIsValid
parameter_list|()
function_decl|;
name|void
name|SetUserID
parameter_list|(
name|uint32_t
name|uid
parameter_list|)
function_decl|;
name|void
name|SetGroupID
parameter_list|(
name|uint32_t
name|gid
parameter_list|)
function_decl|;
name|uint32_t
name|GetEffectiveUserID
parameter_list|()
function_decl|;
name|uint32_t
name|GetEffectiveGroupID
parameter_list|()
function_decl|;
name|bool
name|EffectiveUserIDIsValid
parameter_list|()
function_decl|;
name|bool
name|EffectiveGroupIDIsValid
parameter_list|()
function_decl|;
name|void
name|SetEffectiveUserID
parameter_list|(
name|uint32_t
name|uid
parameter_list|)
function_decl|;
name|void
name|SetEffectiveGroupID
parameter_list|(
name|uint32_t
name|gid
parameter_list|)
function_decl|;
name|lldb
operator|::
name|pid_t
name|GetParentProcessID
argument_list|()
expr_stmt|;
name|void
name|SetParentProcessID
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
name|bool
name|ParentProcessIDIsValid
parameter_list|()
function_decl|;
name|protected
label|:
name|friend
name|class
name|SBTarget
decl_stmt|;
name|lldb_private
operator|::
name|ProcessAttachInfo
operator|&
name|ref
argument_list|()
expr_stmt|;
name|ProcessAttachInfoSP
name|m_opaque_sp
decl_stmt|;
block|}
empty_stmt|;
name|class
name|SBTarget
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Broadcaster bits.
comment|//------------------------------------------------------------------
enum|enum
block|{
name|eBroadcastBitBreakpointChanged
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastBitModulesLoaded
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eBroadcastBitModulesUnloaded
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|eBroadcastBitWatchpointChanged
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|eBroadcastBitSymbolsLoaded
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|}
enum|;
comment|//------------------------------------------------------------------
comment|// Constructors
comment|//------------------------------------------------------------------
name|SBTarget
argument_list|()
expr_stmt|;
name|SBTarget
argument_list|(
specifier|const
name|lldb
operator|::
name|SBTarget
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|SBTarget
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBTarget
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBTarget
operator|&
name|rhs
operator|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Destructor
comment|//------------------------------------------------------------------
operator|~
name|SBTarget
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetBroadcasterClassName
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBProcess
name|GetProcess
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Install any binaries that need to be installed.
comment|///
comment|/// This function does nothing when debugging on the host system.
comment|/// When connected to remote platforms, the target's main executable
comment|/// and any modules that have their remote install path set will be
comment|/// installed on the remote platform. If the main executable doesn't
comment|/// have an install location set, it will be installed in the remote
comment|/// platform's working directory.
comment|///
comment|/// @return
comment|///     An error describing anything that went wrong during
comment|///     installation.
comment|//------------------------------------------------------------------
name|SBError
name|Install
parameter_list|()
function_decl|;
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
comment|/// @param[in] listener
comment|///     An optional listener that will receive all process events.
comment|///     If \a listener is valid then \a listener will listen to all
comment|///     process events. If not valid, then this target's debugger
comment|///     (SBTarget::GetDebugger()) will listen to all process events.
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
comment|/// @param[in] launch_flags
comment|///     Some launch options specified by logical OR'ing
comment|///     lldb::LaunchFlags enumeration values together.
comment|///
comment|/// @param[in] stop_at_endtry
comment|///     If false do not stop the inferior at the entry point.
comment|///
comment|/// @param[out]
comment|///     An error object. Contains the reason if there is some failure.
comment|///
comment|/// @return
comment|///      A process object for the newly created process.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBProcess
name|Launch
argument_list|(
argument|SBListener&listener
argument_list|,
argument|char const **argv
argument_list|,
argument|char const **envp
argument_list|,
argument|const char *stdin_path
argument_list|,
argument|const char *stdout_path
argument_list|,
argument|const char *stderr_path
argument_list|,
argument|const char *working_directory
argument_list|,
argument|uint32_t launch_flags
argument_list|,
comment|// See LaunchFlags
argument|bool stop_at_entry
argument_list|,
argument|lldb::SBError& error
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Launch a new process with sensible defaults.
comment|///
comment|/// @param[in] argv
comment|///     The argument array.
comment|///
comment|/// @param[in] envp
comment|///     The environment array.
comment|///
comment|/// @param[in] working_directory
comment|///     The working directory to have the child process run in
comment|///
comment|/// Default: listener
comment|///     Set to the target's debugger (SBTarget::GetDebugger())
comment|///
comment|/// Default: launch_flags
comment|///     Empty launch flags
comment|///
comment|/// Default: stdin_path
comment|/// Default: stdout_path
comment|/// Default: stderr_path
comment|///     A pseudo terminal will be used.
comment|///
comment|/// @return
comment|///      A process object for the newly created process.
comment|//------------------------------------------------------------------
name|SBProcess
name|LaunchSimple
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|envp
parameter_list|,
specifier|const
name|char
modifier|*
name|working_directory
parameter_list|)
function_decl|;
name|SBProcess
name|Launch
parameter_list|(
name|SBLaunchInfo
modifier|&
name|launch_info
parameter_list|,
name|SBError
modifier|&
name|error
parameter_list|)
function_decl|;
name|SBProcess
name|LoadCore
parameter_list|(
specifier|const
name|char
modifier|*
name|core_file
parameter_list|)
function_decl|;
name|SBProcess
name|Attach
parameter_list|(
name|SBAttachInfo
modifier|&
name|attach_info
parameter_list|,
name|SBError
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Attach to process with pid.
comment|///
comment|/// @param[in] listener
comment|///     An optional listener that will receive all process events.
comment|///     If \a listener is valid then \a listener will listen to all
comment|///     process events. If not valid, then this target's debugger
comment|///     (SBTarget::GetDebugger()) will listen to all process events.
comment|///
comment|/// @param[in] pid
comment|///     The process ID to attach to.
comment|///
comment|/// @param[out]
comment|///     An error explaining what went wrong if attach fails.
comment|///
comment|/// @return
comment|///      A process object for the attached process.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBProcess
name|AttachToProcessWithID
argument_list|(
argument|SBListener&listener
argument_list|,
argument|lldb::pid_t pid
argument_list|,
argument|lldb::SBError& error
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
comment|// We need to keep this around for a build or two since Xcode links
comment|// to the 32 bit version of this function. We will take it out soon.
name|lldb
operator|::
name|SBProcess
name|AttachToProcessWithID
argument_list|(
argument|SBListener&listener
argument_list|,
argument|::pid_t pid
argument_list|,
comment|// 32 bit int process ID
argument|lldb::SBError& error
argument_list|)
expr_stmt|;
comment|// DEPRECATED
endif|#
directive|endif
comment|//------------------------------------------------------------------
comment|/// Attach to process with name.
comment|///
comment|/// @param[in] listener
comment|///     An optional listener that will receive all process events.
comment|///     If \a listener is valid then \a listener will listen to all
comment|///     process events. If not valid, then this target's debugger
comment|///     (SBTarget::GetDebugger()) will listen to all process events.
comment|///
comment|/// @param[in] name
comment|///     Basename of process to attach to.
comment|///
comment|/// @param[in] wait_for
comment|///     If true wait for a new instance of 'name' to be launched.
comment|///
comment|/// @param[out]
comment|///     An error explaining what went wrong if attach fails.
comment|///
comment|/// @return
comment|///      A process object for the attached process.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBProcess
name|AttachToProcessWithName
argument_list|(
argument|SBListener&listener
argument_list|,
argument|const char *name
argument_list|,
argument|bool wait_for
argument_list|,
argument|lldb::SBError& error
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Connect to a remote debug server with url.
comment|///
comment|/// @param[in] listener
comment|///     An optional listener that will receive all process events.
comment|///     If \a listener is valid then \a listener will listen to all
comment|///     process events. If not valid, then this target's debugger
comment|///     (SBTarget::GetDebugger()) will listen to all process events.
comment|///
comment|/// @param[in] url
comment|///     The url to connect to, e.g., 'connect://localhost:12345'.
comment|///
comment|/// @param[in] plugin_name
comment|///     The plugin name to be used; can be NULL.
comment|///
comment|/// @param[out]
comment|///     An error explaining what went wrong if the connect fails.
comment|///
comment|/// @return
comment|///      A process object for the connected process.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBProcess
name|ConnectRemote
argument_list|(
name|SBListener
operator|&
name|listener
argument_list|,
specifier|const
name|char
operator|*
name|url
argument_list|,
specifier|const
name|char
operator|*
name|plugin_name
argument_list|,
name|SBError
operator|&
name|error
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBFileSpec
name|GetExecutable
argument_list|()
expr_stmt|;
name|bool
name|AddModule
argument_list|(
name|lldb
operator|::
name|SBModule
operator|&
name|module
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBModule
name|AddModule
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
specifier|const
name|char
operator|*
name|triple
argument_list|,
specifier|const
name|char
operator|*
name|uuid
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBModule
name|AddModule
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
specifier|const
name|char
operator|*
name|triple
argument_list|,
specifier|const
name|char
operator|*
name|uuid_cstr
argument_list|,
specifier|const
name|char
operator|*
name|symfile
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBModule
name|AddModule
argument_list|(
specifier|const
name|SBModuleSpec
operator|&
name|module_spec
argument_list|)
expr_stmt|;
name|uint32_t
name|GetNumModules
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBModule
name|GetModuleAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
name|bool
name|RemoveModule
argument_list|(
name|lldb
operator|::
name|SBModule
name|module
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBDebugger
name|GetDebugger
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBModule
name|FindModule
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|file_spec
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
expr_stmt|;
name|uint32_t
name|GetAddressByteSize
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetTriple
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the base load address for a module section.
comment|///
comment|/// @param[in] section
comment|///     The section whose base load address will be set within this
comment|///     target.
comment|///
comment|/// @param[in] section_base_addr
comment|///     The base address for the section.
comment|///
comment|/// @return
comment|///      An error to indicate success, fail, and any reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBError
name|SetSectionLoadAddress
argument_list|(
argument|lldb::SBSection section
argument_list|,
argument|lldb::addr_t section_base_addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the base load address for a module section.
comment|///
comment|/// @param[in] section
comment|///     The section whose base load address will be cleared within
comment|///     this target.
comment|///
comment|/// @return
comment|///      An error to indicate success, fail, and any reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBError
name|ClearSectionLoadAddress
argument_list|(
argument|lldb::SBSection section
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Slide all file addresses for all module sections so that \a module
comment|/// appears to loaded at these slide addresses.
comment|///
comment|/// When you need all sections within a module to be loaded at a
comment|/// rigid slide from the addresses found in the module object file,
comment|/// this function will allow you to easily and quickly slide all
comment|/// module sections.
comment|///
comment|/// @param[in] module
comment|///     The module to load.
comment|///
comment|/// @param[in] sections_offset
comment|///     An offset that will be applied to all section file addresses
comment|///     (the virtual addresses found in the object file itself).
comment|///
comment|/// @return
comment|///     An error to indicate success, fail, and any reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBError
name|SetModuleLoadAddress
argument_list|(
argument|lldb::SBModule module
argument_list|,
argument|int64_t sections_offset
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// The the section base load addresses for all sections in a module.
comment|///
comment|/// @param[in] module
comment|///     The module to unload.
comment|///
comment|/// @return
comment|///     An error to indicate success, fail, and any reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBError
name|ClearModuleLoadAddress
argument_list|(
argument|lldb::SBModule module
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find functions by name.
comment|///
comment|/// @param[in] name
comment|///     The name of the function we are looking for.
comment|///
comment|/// @param[in] name_type_mask
comment|///     A logical OR of one or more FunctionNameType enum bits that
comment|///     indicate what kind of names should be used when doing the
comment|///     lookup. Bits include fully qualified names, base names,
comment|///     C++ methods, or ObjC selectors.
comment|///     See FunctionNameType for more details.
comment|///
comment|/// @return
comment|///     A lldb::SBSymbolContextList that gets filled in with all of
comment|///     the symbol contexts for all the matches.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBSymbolContextList
name|FindFunctions
argument_list|(
argument|const char *name
argument_list|,
argument|uint32_t name_type_mask = lldb::eFunctionNameTypeAny
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find global and static variables by name.
comment|///
comment|/// @param[in] name
comment|///     The name of the global or static variable we are looking
comment|///     for.
comment|///
comment|/// @param[in] max_matches
comment|///     Allow the number of matches to be limited to \a max_matches.
comment|///
comment|/// @return
comment|///     A list of matched variables in an SBValueList.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBValueList
name|FindGlobalVariables
argument_list|(
argument|const char *name
argument_list|,
argument|uint32_t max_matches
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find the first global (or static) variable by name.
comment|///
comment|/// @param[in] name
comment|///     The name of the global or static variable we are looking
comment|///     for.
comment|///
comment|/// @return
comment|///     An SBValue that gets filled in with the found variable (if any).
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBValue
name|FindFirstGlobalVariable
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Resolve a current load address into a section offset address.
comment|///
comment|/// @param[in] vm_addr
comment|///     A virtual address from the current process state that is to
comment|///     be translated into a section offset address.
comment|///
comment|/// @return
comment|///     An SBAddress which will be valid if \a vm_addr was
comment|///     successfully resolved into a section offset address, or an
comment|///     invalid SBAddress if \a vm_addr doesn't resolve to a section
comment|///     in a module.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBAddress
name|ResolveLoadAddress
argument_list|(
argument|lldb::addr_t vm_addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Resolve a current load address into a section offset address
comment|/// using the process stop ID to identify a time in the past.
comment|///
comment|/// @param[in] stop_id
comment|///     Each time a process stops, the process stop ID integer gets
comment|///     incremented. These stop IDs are used to identify past times
comment|///     and can be used in history objects as a cheap way to store
comment|///     the time at which the sample was taken. Specifying
comment|///     UINT32_MAX will always resolve the address using the
comment|///     currently loaded sections.
comment|///
comment|/// @param[in] vm_addr
comment|///     A virtual address from the current process state that is to
comment|///     be translated into a section offset address.
comment|///
comment|/// @return
comment|///     An SBAddress which will be valid if \a vm_addr was
comment|///     successfully resolved into a section offset address, or an
comment|///     invalid SBAddress if \a vm_addr doesn't resolve to a section
comment|///     in a module.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBAddress
name|ResolvePastLoadAddress
argument_list|(
argument|uint32_t stop_id
argument_list|,
argument|lldb::addr_t vm_addr
argument_list|)
expr_stmt|;
name|SBSymbolContext
name|ResolveSymbolContextForAddress
parameter_list|(
specifier|const
name|SBAddress
modifier|&
name|addr
parameter_list|,
name|uint32_t
name|resolve_scope
parameter_list|)
function_decl|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByLocation
argument_list|(
argument|const char *file
argument_list|,
argument|uint32_t line
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByLocation
argument_list|(
argument|const lldb::SBFileSpec&file_spec
argument_list|,
argument|uint32_t line
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByName
argument_list|(
specifier|const
name|char
operator|*
name|symbol_name
argument_list|,
specifier|const
name|char
operator|*
name|module_name
operator|=
name|NULL
argument_list|)
expr_stmt|;
comment|// This version uses name_type_mask = eFunctionNameTypeAuto
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByName
argument_list|(
specifier|const
name|char
operator|*
name|symbol_name
argument_list|,
specifier|const
name|SBFileSpecList
operator|&
name|module_list
argument_list|,
specifier|const
name|SBFileSpecList
operator|&
name|comp_unit_list
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByName
argument_list|(
argument|const char *symbol_name
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
comment|// Logical OR one or more FunctionNameType enum bits
argument|const SBFileSpecList&module_list
argument_list|,
argument|const SBFileSpecList&comp_unit_list
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByNames
argument_list|(
argument|const char *symbol_name[]
argument_list|,
argument|uint32_t num_names
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
comment|// Logical OR one or more FunctionNameType enum bits
argument|const SBFileSpecList&module_list
argument_list|,
argument|const SBFileSpecList&comp_unit_list
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByRegex
argument_list|(
specifier|const
name|char
operator|*
name|symbol_name_regex
argument_list|,
specifier|const
name|char
operator|*
name|module_name
operator|=
name|NULL
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByRegex
argument_list|(
specifier|const
name|char
operator|*
name|symbol_name_regex
argument_list|,
specifier|const
name|SBFileSpecList
operator|&
name|module_list
argument_list|,
specifier|const
name|SBFileSpecList
operator|&
name|comp_unit_list
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateBySourceRegex
argument_list|(
specifier|const
name|char
operator|*
name|source_regex
argument_list|,
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|source_file
argument_list|,
specifier|const
name|char
operator|*
name|module_name
operator|=
name|NULL
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateBySourceRegex
argument_list|(
specifier|const
name|char
operator|*
name|source_regex
argument_list|,
specifier|const
name|SBFileSpecList
operator|&
name|module_list
argument_list|,
specifier|const
name|lldb
operator|::
name|SBFileSpecList
operator|&
name|source_file
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateForException
argument_list|(
argument|lldb::LanguageType language
argument_list|,
argument|bool catch_bp
argument_list|,
argument|bool throw_bp
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|BreakpointCreateByAddress
argument_list|(
argument|addr_t address
argument_list|)
expr_stmt|;
name|uint32_t
name|GetNumBreakpoints
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBBreakpoint
name|GetBreakpointAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|BreakpointDelete
parameter_list|(
name|break_id_t
name|break_id
parameter_list|)
function_decl|;
name|lldb
operator|::
name|SBBreakpoint
name|FindBreakpointByID
argument_list|(
argument|break_id_t break_id
argument_list|)
expr_stmt|;
name|bool
name|EnableAllBreakpoints
parameter_list|()
function_decl|;
name|bool
name|DisableAllBreakpoints
parameter_list|()
function_decl|;
name|bool
name|DeleteAllBreakpoints
parameter_list|()
function_decl|;
name|uint32_t
name|GetNumWatchpoints
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBWatchpoint
name|GetWatchpointAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|DeleteWatchpoint
argument_list|(
name|lldb
operator|::
name|watch_id_t
name|watch_id
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBWatchpoint
name|FindWatchpointByID
argument_list|(
argument|lldb::watch_id_t watch_id
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBWatchpoint
name|WatchAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|,
argument|SBError& error
argument_list|)
expr_stmt|;
name|bool
name|EnableAllWatchpoints
parameter_list|()
function_decl|;
name|bool
name|DisableAllWatchpoints
parameter_list|()
function_decl|;
name|bool
name|DeleteAllWatchpoints
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBBroadcaster
name|GetBroadcaster
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBType
name|FindFirstType
argument_list|(
specifier|const
name|char
operator|*
name|type
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBTypeList
name|FindTypes
argument_list|(
specifier|const
name|char
operator|*
name|type
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBType
name|GetBasicType
argument_list|(
argument|lldb::BasicType type
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|CreateValueFromAddress
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::SBAddress addr
argument_list|,
argument|lldb::SBType type
argument_list|)
expr_stmt|;
name|SBSourceManager
name|GetSourceManager
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBInstructionList
name|ReadInstructions
argument_list|(
argument|lldb::SBAddress base_addr
argument_list|,
argument|uint32_t count
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBInstructionList
name|ReadInstructions
argument_list|(
argument|lldb::SBAddress base_addr
argument_list|,
argument|uint32_t count
argument_list|,
argument|const char *flavor_string
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBInstructionList
name|GetInstructions
argument_list|(
argument|lldb::SBAddress base_addr
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
comment|// The "WithFlavor" is necessary to keep SWIG from getting confused about overloaded arguments when
comment|// using the buf + size -> Python Object magic.
name|lldb
operator|::
name|SBInstructionList
name|GetInstructionsWithFlavor
argument_list|(
argument|lldb::SBAddress base_addr
argument_list|,
argument|const char *flavor_string
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBInstructionList
name|GetInstructions
argument_list|(
argument|lldb::addr_t base_addr
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBInstructionList
name|GetInstructionsWithFlavor
argument_list|(
argument|lldb::addr_t base_addr
argument_list|,
argument|const char *flavor_string
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBSymbolContextList
name|FindSymbols
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::SymbolType type = eSymbolTypeAny
argument_list|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|lldb
operator|::
name|SBTarget
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|lldb
operator|::
name|SBTarget
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|description_level
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBValue
name|EvaluateExpression
argument_list|(
specifier|const
name|char
operator|*
name|expr
argument_list|,
specifier|const
name|SBExpressionOptions
operator|&
name|options
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetStackRedZoneSize
argument_list|()
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBAddress
decl_stmt|;
name|friend
name|class
name|SBBlock
decl_stmt|;
name|friend
name|class
name|SBDebugger
decl_stmt|;
name|friend
name|class
name|SBFunction
decl_stmt|;
name|friend
name|class
name|SBInstruction
decl_stmt|;
name|friend
name|class
name|SBModule
decl_stmt|;
name|friend
name|class
name|SBProcess
decl_stmt|;
name|friend
name|class
name|SBSection
decl_stmt|;
name|friend
name|class
name|SBSourceManager
decl_stmt|;
name|friend
name|class
name|SBSymbol
decl_stmt|;
name|friend
name|class
name|SBValue
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors are private, use static Target::Create function to
comment|// create an instance of this class.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For Target only
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|m_opaque_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBTarget_h_
end_comment

end_unit

