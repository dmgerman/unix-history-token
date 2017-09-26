begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StructuredDataDarwinLog.h -------------------------------*- C++ -*-===//
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
name|StructuredDataDarwinLog_h
end_ifndef

begin_define
define|#
directive|define
name|StructuredDataDarwinLog_h
end_define

begin_include
include|#
directive|include
file|"lldb/Target/StructuredDataPlugin.h"
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_comment
comment|// Forward declarations
end_comment

begin_decl_stmt
name|namespace
name|sddarwinlog_private
block|{
name|class
name|EnableCommand
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StructuredDataDarwinLog
range|:
name|public
name|StructuredDataPlugin
block|{
name|friend
name|sddarwinlog_private
operator|::
name|EnableCommand
block|;
name|public
operator|:
comment|// -------------------------------------------------------------------------
comment|// Public static API
comment|// -------------------------------------------------------------------------
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
name|ConstString
operator|&
name|GetStaticPluginName
argument_list|()
block|;
comment|// -------------------------------------------------------------------------
comment|/// Return whether the DarwinLog functionality is enabled.
comment|///
comment|/// The DarwinLog functionality is enabled if the user expicitly enabled
comment|/// it with the enable command, or if the user has the setting set
comment|/// that controls if we always enable it for newly created/attached
comment|/// processes.
comment|///
comment|/// @return
comment|///      True if DarwinLog support is/will be enabled for existing or
comment|///      newly launched/attached processes.
comment|// -------------------------------------------------------------------------
specifier|static
name|bool
name|IsEnabled
argument_list|()
block|;
comment|// -------------------------------------------------------------------------
comment|// PluginInterface API
comment|// -------------------------------------------------------------------------
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
comment|// -------------------------------------------------------------------------
comment|// StructuredDataPlugin API
comment|// -------------------------------------------------------------------------
name|bool
name|SupportsStructuredDataType
argument_list|(
argument|const ConstString&type_name
argument_list|)
name|override
block|;
name|void
name|HandleArrivalOfStructuredData
argument_list|(
argument|Process&process
argument_list|,
argument|const ConstString&type_name
argument_list|,
argument|const StructuredData::ObjectSP&object_sp
argument_list|)
name|override
block|;
name|Status
name|GetDescription
argument_list|(
argument|const StructuredData::ObjectSP&object_sp
argument_list|,
argument|lldb_private::Stream&stream
argument_list|)
name|override
block|;
name|bool
name|GetEnabled
argument_list|(
argument|const ConstString&type_name
argument_list|)
specifier|const
name|override
block|;
name|void
name|ModulesDidLoad
argument_list|(
argument|Process&process
argument_list|,
argument|ModuleList&module_list
argument_list|)
name|override
block|;
operator|~
name|StructuredDataDarwinLog
argument_list|()
block|;
name|private
operator|:
comment|// -------------------------------------------------------------------------
comment|// Private constructors
comment|// -------------------------------------------------------------------------
name|StructuredDataDarwinLog
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessWP
operator|&
name|process_wp
argument_list|)
block|;
comment|// -------------------------------------------------------------------------
comment|// Private static methods
comment|// -------------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|StructuredDataPluginSP
name|CreateInstance
argument_list|(
name|Process
operator|&
name|process
argument_list|)
block|;
specifier|static
name|void
name|DebuggerInitialize
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
block|;
specifier|static
name|bool
name|InitCompletionHookCallback
argument_list|(
argument|void *baton
argument_list|,
argument|StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
specifier|static
name|Status
name|FilterLaunchInfo
argument_list|(
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|Target
operator|*
name|target
argument_list|)
block|;
comment|// -------------------------------------------------------------------------
comment|// Internal helper methods used by friend classes
comment|// -------------------------------------------------------------------------
name|void
name|SetEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|AddInitCompletionHook
argument_list|(
name|Process
operator|&
name|process
argument_list|)
block|;
comment|// -------------------------------------------------------------------------
comment|// Private methods
comment|// -------------------------------------------------------------------------
name|void
name|DumpTimestamp
argument_list|(
argument|Stream&stream
argument_list|,
argument|uint64_t timestamp
argument_list|)
block|;
name|size_t
name|DumpHeader
argument_list|(
name|Stream
operator|&
name|stream
argument_list|,
specifier|const
name|StructuredData
operator|::
name|Dictionary
operator|&
name|event
argument_list|)
block|;
name|size_t
name|HandleDisplayOfEvent
argument_list|(
specifier|const
name|StructuredData
operator|::
name|Dictionary
operator|&
name|event
argument_list|,
name|Stream
operator|&
name|stream
argument_list|)
block|;
comment|// -------------------------------------------------------------------------
comment|/// Call the enable command again, using whatever settings were initially
comment|/// made.
comment|// -------------------------------------------------------------------------
name|void
name|EnableNow
argument_list|()
block|;
comment|// -------------------------------------------------------------------------
comment|// Private data
comment|// -------------------------------------------------------------------------
name|bool
name|m_recorded_first_timestamp
block|;
name|uint64_t
name|m_first_timestamp_seen
block|;
name|bool
name|m_is_enabled
block|;
name|std
operator|::
name|mutex
name|m_added_breakpoint_mutex
block|;
name|bool
name|m_added_breakpoint
block|;
name|lldb
operator|::
name|user_id_t
name|m_breakpoint_id
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* StructuredDataPluginDarwinLog_hpp */
end_comment

end_unit

