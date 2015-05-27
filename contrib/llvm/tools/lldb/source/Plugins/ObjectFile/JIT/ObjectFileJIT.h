begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectFileJIT.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_ObjectFileJIT_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectFileJIT_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ObjectFile.h"
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// This class needs to be hidden as eventually belongs in a plugin that
end_comment

begin_comment
comment|// will export the ObjectFile protocol
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|ObjectFileJIT
range|:
name|public
name|lldb_private
operator|::
name|ObjectFile
block|{
name|public
operator|:
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
name|ObjectFile
operator|*
name|CreateInstance
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP& data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|const lldb_private::FileSpec* file
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|CreateMemoryInstance
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP& data_sp
argument_list|,
argument|const lldb::ProcessSP&process_sp
argument_list|,
argument|lldb::addr_t header_addr
argument_list|)
block|;
specifier|static
name|size_t
name|GetModuleSpecifications
argument_list|(
argument|const lldb_private::FileSpec& file
argument_list|,
argument|lldb::DataBufferSP& data_sp
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
comment|//------------------------------------------------------------------
comment|// Member Functions
comment|//------------------------------------------------------------------
name|ObjectFileJIT
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|ObjectFileJITDelegateSP
operator|&
name|delegate_sp
argument_list|)
block|;
name|virtual
operator|~
name|ObjectFileJIT
argument_list|()
block|;
name|virtual
name|bool
name|ParseHeader
argument_list|()
block|;
name|virtual
name|bool
name|SetLoadAddress
argument_list|(
argument|lldb_private::Target&target
argument_list|,
argument|lldb::addr_t value
argument_list|,
argument|bool value_is_offset
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|IsExecutable
argument_list|()
specifier|const
block|;
name|virtual
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
block|;
name|virtual
name|lldb_private
operator|::
name|Symtab
operator|*
name|GetSymtab
argument_list|()
block|;
name|virtual
name|bool
name|IsStripped
argument_list|()
block|;
name|virtual
name|void
name|CreateSections
argument_list|(
name|lldb_private
operator|::
name|SectionList
operator|&
name|unified_section_list
argument_list|)
block|;
name|virtual
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|)
block|;
name|virtual
name|bool
name|GetArchitecture
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|virtual
name|bool
name|GetUUID
argument_list|(
name|lldb_private
operator|::
name|UUID
operator|*
name|uuid
argument_list|)
block|;
name|virtual
name|uint32_t
name|GetDependentModules
argument_list|(
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|files
argument_list|)
block|;
name|virtual
name|size_t
name|ReadSectionData
argument_list|(
argument|const lldb_private::Section *section
argument_list|,
argument|lldb::offset_t section_offset
argument_list|,
argument|void *dst
argument_list|,
argument|size_t dst_len
argument_list|)
specifier|const
block|;
name|virtual
name|size_t
name|ReadSectionData
argument_list|(
argument|const lldb_private::Section *section
argument_list|,
argument|lldb_private::DataExtractor& section_data
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Address
name|GetEntryPointAddress
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Address
name|GetHeaderAddress
argument_list|()
block|;
name|virtual
name|ObjectFile
operator|::
name|Type
name|CalculateType
argument_list|()
block|;
name|virtual
name|ObjectFile
operator|::
name|Strata
name|CalculateStrata
argument_list|()
block|;
name|protected
operator|:
name|lldb
operator|::
name|ObjectFileJITDelegateWP
name|m_delegate_wp
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ObjectFileJIT_h_
end_comment

end_unit

