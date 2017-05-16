begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoaderMacOS.h -------------------------------*- C++ -*-===//
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

begin_comment
comment|// This is the DynamicLoader plugin for Darwin (macOS / iPhoneOS / tvOS /
end_comment

begin_comment
comment|// watchOS)
end_comment

begin_comment
comment|// platforms late 2016 and newer, where lldb will call dyld SPI functions to get
end_comment

begin_comment
comment|// information about shared libraries, information about the shared cache, and
end_comment

begin_comment
comment|// the _dyld_debugger_notification function we put a breakpoint on give us an
end_comment

begin_comment
comment|// array of load addresses for solibs loaded and unloaded.  The SPI will tell us
end_comment

begin_comment
comment|// about both dyld and the executable, in addition to all of the usual solibs.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_DynamicLoaderMacOS_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLoaderMacOS_h_
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
file|<mutex>
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
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/DynamicLoader.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/SafeMachO.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UUID.h"
end_include

begin_include
include|#
directive|include
file|"DynamicLoaderDarwin.h"
end_include

begin_decl_stmt
name|class
name|DynamicLoaderMacOS
range|:
name|public
name|lldb_private
operator|::
name|DynamicLoaderDarwin
block|{
name|public
operator|:
name|DynamicLoaderMacOS
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|virtual
operator|~
name|DynamicLoaderMacOS
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
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
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|DynamicLoader
operator|*
name|CreateInstance
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|bool force
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Called after attaching a process.
comment|///
comment|/// Allow DynamicLoader plug-ins to execute some code after
comment|/// attaching to a process.
comment|//------------------------------------------------------------------
name|bool
name|ProcessDidExec
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Status
name|CanLoadImage
argument_list|()
name|override
block|;
name|bool
name|GetSharedCacheInformation
argument_list|(
argument|lldb::addr_t&base_address
argument_list|,
argument|lldb_private::UUID&uuid
argument_list|,
argument|lldb_private::LazyBool&using_shared_cache
argument_list|,
argument|lldb_private::LazyBool&private_shared_cache
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
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
name|protected
operator|:
name|void
name|PutToLog
argument_list|(
argument|lldb_private::Log *log
argument_list|)
specifier|const
block|;
name|void
name|DoInitialImageFetch
argument_list|()
name|override
block|;
name|bool
name|NeedToDoInitialImageFetch
argument_list|()
name|override
block|;
name|bool
name|DidSetNotificationBreakpoint
argument_list|()
name|override
block|;
name|void
name|AddBinaries
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
operator|&
name|load_addresses
argument_list|)
block|;
name|void
name|DoClear
argument_list|()
name|override
block|;
specifier|static
name|bool
name|NotifyBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
name|bool
name|SetNotificationBreakpoint
argument_list|()
name|override
block|;
name|void
name|ClearNotificationBreakpoint
argument_list|()
name|override
block|;
name|void
name|UpdateImageInfosHeaderAndLoadCommands
argument_list|(
argument|ImageInfo::collection&image_infos
argument_list|,
argument|uint32_t infos_count
argument_list|,
argument|bool update_executable
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetDyldLockVariableAddressFromModule
argument_list|(
name|lldb_private
operator|::
name|Module
operator|*
name|module
argument_list|)
block|;
name|uint32_t
name|m_image_infos_stop_id
block|;
comment|// The Stop ID the last time we
comment|// loaded/unloaded images
name|lldb
operator|::
name|user_id_t
name|m_break_id
block|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLoaderMacOS
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DynamicLoaderMacOS_h_
end_comment

end_unit

