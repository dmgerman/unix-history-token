begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessWinMiniDump.h ------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessWinMiniDump_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessWinMiniDump_h_
end_define

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Windows/Common/ProcessWindows.h"
end_include

begin_struct_decl
struct_decl|struct
name|ThreadData
struct_decl|;
end_struct_decl

begin_decl_stmt
name|class
name|ProcessWinMiniDump
range|:
name|public
name|lldb_private
operator|::
name|ProcessWindows
block|{
name|public
operator|:
specifier|static
name|lldb
operator|::
name|ProcessSP
name|CreateInstance
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const lldb_private::FileSpec *crash_file_path
argument_list|)
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
name|ProcessWinMiniDump
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const lldb_private::FileSpec&core_file
argument_list|)
block|;
name|virtual
operator|~
name|ProcessWinMiniDump
argument_list|()
block|;
name|bool
name|CanDebug
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|bool plugin_specified_by_name
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DoLoadCore
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|DynamicLoader
operator|*
name|GetDynamicLoader
argument_list|()
name|override
block|;
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
name|lldb_private
operator|::
name|Error
name|DoDestroy
argument_list|()
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
name|bool
name|IsAlive
argument_list|()
name|override
block|;
name|bool
name|WarnBeforeDetach
argument_list|()
specifier|const
name|override
block|;
name|size_t
name|ReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|size_t
name|DoReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|ArchSpec
name|GetArchitecture
argument_list|()
block|;
name|lldb_private
operator|::
name|Error
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb_private::MemoryRegionInfo&range_info
argument_list|)
name|override
block|;
name|protected
operator|:
name|void
name|Clear
argument_list|()
block|;
name|bool
name|UpdateThreadList
argument_list|(
argument|lldb_private::ThreadList&old_thread_list
argument_list|,
argument|lldb_private::ThreadList&new_thread_list
argument_list|)
name|override
block|;
name|private
operator|:
comment|// Keep Windows-specific types out of this header.
name|class
name|Impl
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|Impl
operator|>
name|m_impl_up
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessWinMiniDump_h_
end_comment

end_unit

