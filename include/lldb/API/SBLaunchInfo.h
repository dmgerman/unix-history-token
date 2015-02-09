begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBLaunchInfo.h ------------------------------------------*- C++ -*-===//
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
name|LLDB_SBLaunchInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBLaunchInfo_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBPlatform
decl_stmt|;
name|class
name|SBTarget
decl_stmt|;
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
name|lldb
operator|::
name|pid_t
name|GetProcessID
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
name|SBFileSpec
name|GetExecutableFile
parameter_list|()
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Set the executable file that will be used to launch the process and
comment|/// optionally set it as the first argument in the argument vector.
comment|///
comment|/// This only needs to be specified if clients wish to carefully control
comment|/// the exact path will be used to launch a binary. If you create a
comment|/// target with a symlink, that symlink will get resolved in the target
comment|/// and the resolved path will get used to launch the process. Calling
comment|/// this function can help you still launch your process using the
comment|/// path of your choice.
comment|///
comment|/// If this function is not called prior to launching with
comment|/// SBTarget::Launch(...), the target will use the resolved executable
comment|/// path that was used to create the target.
comment|///
comment|/// @param[in] exe_file
comment|///     The override path to use when launching the executable.
comment|///
comment|/// @param[in] add_as_first_arg
comment|///     If true, then the path will be inserted into the argument vector
comment|///     prior to launching. Otherwise the argument vector will be left
comment|///     alone.
comment|//----------------------------------------------------------------------
name|void
name|SetExecutableFile
parameter_list|(
name|SBFileSpec
name|exe_file
parameter_list|,
name|bool
name|add_as_first_arg
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Get the listener that will be used to receive process events.
comment|///
comment|/// If no listener has been set via a call to
comment|/// SBLaunchInfo::SetListener(), then an invalid SBListener will be
comment|/// returned (SBListener::IsValid() will return false). If a listener
comment|/// has been set, then the valid listener object will be returned.
comment|//----------------------------------------------------------------------
name|SBListener
name|GetListener
parameter_list|()
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Set the listener that will be used to receive process events.
comment|///
comment|/// By default the SBDebugger, which has a listener, that the SBTarget
comment|/// belongs to will listen for the process events. Calling this function
comment|/// allows a different listener to be used to listen for process events.
comment|//----------------------------------------------------------------------
name|void
name|SetListener
parameter_list|(
name|SBListener
modifier|&
name|listener
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
name|void
name|SetLaunchEventData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
specifier|const
name|char
operator|*
name|GetLaunchEventData
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|GetDetachOnError
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetDetachOnError
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|protected
label|:
name|friend
name|class
name|SBPlatform
decl_stmt|;
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
comment|// LLDB_SBLaunchInfo_h_
end_comment

end_unit

