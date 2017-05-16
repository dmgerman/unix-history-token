begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessMachCore.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessMachCore_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessMachCore_h_
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
file|<list>
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
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_decl_stmt
name|class
name|ThreadKDP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessMachCore
range|:
name|public
name|lldb_private
operator|::
name|Process
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ProcessMachCore
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener
argument_list|,
argument|const lldb_private::FileSpec&core_file
argument_list|)
block|;
operator|~
name|ProcessMachCore
argument_list|()
name|override
block|;
specifier|static
name|lldb
operator|::
name|ProcessSP
name|CreateInstance
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener
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
comment|//------------------------------------------------------------------
comment|// Check if a given Process
comment|//------------------------------------------------------------------
name|bool
name|CanDebug
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|bool plugin_specified_by_name
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Creating a new process, or attaching to an existing one
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|Status
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
comment|//------------------------------------------------------------------
comment|// Process Control
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|Status
name|DoDestroy
argument_list|()
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Queries
comment|//------------------------------------------------------------------
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
comment|//------------------------------------------------------------------
comment|// Process Memory
comment|//------------------------------------------------------------------
name|size_t
name|ReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Status&error
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
argument|lldb_private::Status&error
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Status
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb_private::MemoryRegionInfo&region_info
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
name|override
block|;
name|protected
operator|:
name|friend
name|class
name|ThreadMachCore
block|;
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
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|GetCoreObjectFile
argument_list|()
block|;
name|private
operator|:
name|bool
name|GetDynamicLoaderAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
typedef|typedef
enum|enum
name|CorefilePreference
block|{
name|eUserProcessCorefile
block|,
name|eKernelCorefile
decl|}
name|CorefilePreferences
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// If a core file can be interpreted multiple ways, this establishes
comment|/// which style wins.
comment|///
comment|/// If a core file contains both a kernel binary and a user-process
comment|/// dynamic loader, lldb needs to pick one over the other.  This could
comment|/// be a kernel corefile that happens to have a copy of dyld in its
comment|/// memory.  Or it could be a user process coredump of lldb while doing
comment|/// kernel debugging - so a copy of the kernel is in its heap.  This
comment|/// should become a setting so it can be over-ridden when necessary.
comment|//------------------------------------------------------------------
name|CorefilePreference
name|GetCorefilePreference
parameter_list|()
block|{
comment|// For now, if both user process and kernel binaries a present,
comment|// assume this is a kernel coredump which has a copy of a user
comment|// process dyld in one of its pages.
return|return
name|eKernelCorefile
return|;
block|}
comment|//------------------------------------------------------------------
comment|// For ProcessMachCore only
comment|//------------------------------------------------------------------
function|typedef lldb_private::Range<lldb::addr_t
operator|,
function|lldb::addr_t> FileRange;
typedef|typedef
name|lldb_private
operator|::
name|RangeDataVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
name|FileRange
operator|>
name|VMRangeToFileOffset
expr_stmt|;
typedef|typedef
name|lldb_private
operator|::
name|RangeDataVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
name|uint32_t
operator|>
name|VMRangeToPermissions
expr_stmt|;
name|VMRangeToFileOffset
name|m_core_aranges
block|;
name|VMRangeToPermissions
name|m_core_range_infos
block|;
name|lldb
decl|::
name|ModuleSP
name|m_core_module_sp
empty_stmt|;
name|lldb_private
decl|::
name|FileSpec
name|m_core_file
empty_stmt|;
name|lldb
decl|::
name|addr_t
name|m_dyld_addr
empty_stmt|;
name|lldb
decl|::
name|addr_t
name|m_mach_kernel_addr
empty_stmt|;
name|lldb_private
decl|::
name|ConstString
name|m_dyld_plugin_name
empty_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessMachCore
argument_list|)
empty_stmt|;
block|}
enum|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessMachCore_h_
end_comment

end_unit

