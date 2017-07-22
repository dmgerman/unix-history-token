begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessMinidump.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessMinidump_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessMinidump_h_
end_define

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"MinidumpParser.h"
end_include

begin_include
include|#
directive|include
file|"MinidumpTypes.h"
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StopInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
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

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|minidump
block|{
name|class
name|ProcessMinidump
range|:
name|public
name|Process
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
argument|const FileSpec *crash_file_path
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
name|ProcessMinidump
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const FileSpec&core_file
argument_list|,
argument|MinidumpParser minidump_parser
argument_list|)
block|;
operator|~
name|ProcessMinidump
argument_list|()
name|override
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
name|Status
name|DoLoadCore
argument_list|()
name|override
block|;
name|DynamicLoader
operator|*
name|GetDynamicLoader
argument_list|()
name|override
block|;
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
argument|Status&error
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
argument|Status&error
argument_list|)
name|override
block|;
name|ArchSpec
name|GetArchitecture
argument_list|()
block|;
name|Status
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|MemoryRegionInfo&range_info
argument_list|)
name|override
block|;
name|bool
name|GetProcessInfo
argument_list|(
argument|ProcessInstanceInfo&info
argument_list|)
name|override
block|;
name|MinidumpParser
name|m_minidump_parser
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
argument|ThreadList&old_thread_list
argument_list|,
argument|ThreadList&new_thread_list
argument_list|)
name|override
block|;
name|void
name|ReadModuleList
argument_list|()
block|;
name|private
operator|:
name|FileSpec
name|m_core_file
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|MinidumpThread
operator|>
name|m_thread_list
block|;
specifier|const
name|MinidumpExceptionStream
operator|*
name|m_active_exception
block|;
name|bool
name|m_is_wow64
block|; }
decl_stmt|;
block|}
comment|// namespace minidump
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessMinidump_h_
end_comment

end_unit

