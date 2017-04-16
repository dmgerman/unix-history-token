begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectContainerUniversalMachO.h -------------------------*- C++ -*-===//
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
name|liblldb_ObjectContainerUniversalMachO_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectContainerUniversalMachO_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Symbol/ObjectContainer.h"
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

begin_decl_stmt
name|class
name|ObjectContainerUniversalMachO
range|:
name|public
name|lldb_private
operator|::
name|ObjectContainer
block|{
name|public
operator|:
name|ObjectContainerUniversalMachO
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|const lldb_private::FileSpec *file
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
block|;
operator|~
name|ObjectContainerUniversalMachO
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
name|ObjectContainer
operator|*
name|CreateInstance
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|const lldb_private::FileSpec *file
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
block|;
specifier|static
name|size_t
name|GetModuleSpecifications
argument_list|(
argument|const lldb_private::FileSpec&file
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|lldb_private::ModuleSpecList&specs
argument_list|)
block|;
specifier|static
name|bool
name|MagicBytesMatch
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Member Functions
comment|//------------------------------------------------------------------
name|bool
name|ParseHeader
argument_list|()
name|override
block|;
name|void
name|Dump
argument_list|(
argument|lldb_private::Stream *s
argument_list|)
specifier|const
name|override
block|;
name|size_t
name|GetNumArchitectures
argument_list|()
specifier|const
name|override
block|;
name|bool
name|GetArchitectureAtIndex
argument_list|(
argument|uint32_t cpu_idx
argument_list|,
argument|lldb_private::ArchSpec&arch
argument_list|)
specifier|const
name|override
block|;
name|lldb
operator|::
name|ObjectFileSP
name|GetObjectFile
argument_list|(
argument|const lldb_private::FileSpec *file
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
name|llvm
operator|::
name|MachO
operator|::
name|fat_header
name|m_header
block|;
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|MachO
operator|::
name|fat_arch
operator|>
name|m_fat_archs
block|;
specifier|static
name|bool
name|ParseHeader
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|llvm
operator|::
name|MachO
operator|::
name|fat_header
operator|&
name|header
argument_list|,
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|MachO
operator|::
name|fat_arch
operator|>
operator|&
name|fat_archs
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ObjectContainerUniversalMachO_h_
end_comment

end_unit

