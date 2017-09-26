begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBAttachInfo.h ------------------------------------------*- C++ -*-===//
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
name|LLDB_SBAttachInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBAttachInfo_h_
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
name|SBTarget
decl_stmt|;
name|class
name|LLDB_API
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
comment|//------------------------------------------------------------------
comment|/// Attach to a process by name.
comment|///
comment|/// This function implies that a future call to SBTarget::Attach(...)
comment|/// will be synchronous.
comment|///
comment|/// @param[in] path
comment|///     A full or partial name for the process to attach to.
comment|///
comment|/// @param[in] wait_for
comment|///     If \b false, attach to an existing process whose name matches.
comment|///     If \b true, then wait for the next process whose name matches.
comment|//------------------------------------------------------------------
name|SBAttachInfo
argument_list|(
argument|const char *path
argument_list|,
argument|bool wait_for
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Attach to a process by name.
comment|///
comment|/// Future calls to SBTarget::Attach(...) will be synchronous or
comment|/// asynchronous depending on the \a async argument.
comment|///
comment|/// @param[in] path
comment|///     A full or partial name for the process to attach to.
comment|///
comment|/// @param[in] wait_for
comment|///     If \b false, attach to an existing process whose name matches.
comment|///     If \b true, then wait for the next process whose name matches.
comment|///
comment|/// @param[in] async
comment|///     If \b false, then the SBTarget::Attach(...) call will be a
comment|///     synchronous call with no way to cancel the attach in
comment|///     progress.
comment|///     If \b true, then the SBTarget::Attach(...) function will
comment|///     return immediately and clients are expected to wait for a
comment|///     process eStateStopped event if a suitable process is
comment|///     eventually found. If the client wants to cancel the event,
comment|///     SBProcess::Stop() can be called and an eStateExited process
comment|///     event will be delivered.
comment|//------------------------------------------------------------------
name|SBAttachInfo
argument_list|(
argument|const char *path
argument_list|,
argument|bool wait_for
argument_list|,
argument|bool async
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
comment|//------------------------------------------------------------------
comment|/// Set attach by process name settings.
comment|///
comment|/// Designed to be used after a call to SBAttachInfo::SetExecutable().
comment|/// This function implies that a call to SBTarget::Attach(...) will
comment|/// be synchronous.
comment|///
comment|/// @param[in] b
comment|///     If \b false, attach to an existing process whose name matches.
comment|///     If \b true, then wait for the next process whose name matches.
comment|//------------------------------------------------------------------
name|void
name|SetWaitForLaunch
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set attach by process name settings.
comment|///
comment|/// Designed to be used after a call to SBAttachInfo::SetExecutable().
comment|/// Future calls to SBTarget::Attach(...) will be synchronous or
comment|/// asynchronous depending on the \a async argument.
comment|///
comment|/// @param[in] b
comment|///     If \b false, attach to an existing process whose name matches.
comment|///     If \b true, then wait for the next process whose name matches.
comment|///
comment|/// @param[in] async
comment|///     If \b false, then the SBTarget::Attach(...) call will be a
comment|///     synchronous call with no way to cancel the attach in
comment|///     progress.
comment|///     If \b true, then the SBTarget::Attach(...) function will
comment|///     return immediately and clients are expected to wait for a
comment|///     process eStateStopped event if a suitable process is
comment|///     eventually found. If the client wants to cancel the event,
comment|///     SBProcess::Stop() can be called and an eStateExited process
comment|///     event will be delivered.
comment|//------------------------------------------------------------------
name|void
name|SetWaitForLaunch
parameter_list|(
name|bool
name|b
parameter_list|,
name|bool
name|async
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
comment|//----------------------------------------------------------------------
comment|/// Get the listener that will be used to receive process events.
comment|///
comment|/// If no listener has been set via a call to
comment|/// SBAttachInfo::SetListener(), then an invalid SBListener will be
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
comment|// LLDB_SBAttachInfo_h_
end_comment

end_unit

