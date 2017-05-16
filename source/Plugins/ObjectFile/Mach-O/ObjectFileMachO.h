begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectFileMachO.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ObjectFileMachO_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectFileMachO_h_
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
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/FileSpecList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ObjectFile.h"
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
name|ObjectFileMachO
range|:
name|public
name|lldb_private
operator|::
name|ObjectFile
block|{
name|public
operator|:
name|ObjectFileMachO
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
name|ObjectFileMachO
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|const lldb::ProcessSP&process_sp
argument_list|,
argument|lldb::addr_t header_addr
argument_list|)
block|;
operator|~
name|ObjectFileMachO
argument_list|()
name|override
operator|=
expr|default
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
name|ObjectFile
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
argument|lldb::DataBufferSP&data_sp
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
name|SaveCore
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|outfile
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
block|;
specifier|static
name|bool
name|MagicBytesMatch
argument_list|(
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|lldb::addr_t length
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
name|bool
name|SetLoadAddress
argument_list|(
argument|lldb_private::Target&target
argument_list|,
argument|lldb::addr_t value
argument_list|,
argument|bool value_is_offset
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsExecutable
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
name|override
block|;
name|lldb
operator|::
name|AddressClass
name|GetAddressClass
argument_list|(
argument|lldb::addr_t file_addr
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Symtab
operator|*
name|GetSymtab
argument_list|()
name|override
block|;
name|bool
name|IsStripped
argument_list|()
name|override
block|;
name|void
name|CreateSections
argument_list|(
argument|lldb_private::SectionList&unified_section_list
argument_list|)
name|override
block|;
name|void
name|Dump
argument_list|(
argument|lldb_private::Stream *s
argument_list|)
name|override
block|;
name|bool
name|GetArchitecture
argument_list|(
argument|lldb_private::ArchSpec&arch
argument_list|)
name|override
block|;
name|bool
name|GetUUID
argument_list|(
argument|lldb_private::UUID *uuid
argument_list|)
name|override
block|;
name|uint32_t
name|GetDependentModules
argument_list|(
argument|lldb_private::FileSpecList&files
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|FileSpecList
name|GetReExportedLibraries
argument_list|()
name|override
block|{
return|return
name|m_reexported_dylibs
return|;
block|}
name|lldb_private
operator|::
name|Address
name|GetEntryPointAddress
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Address
name|GetHeaderAddress
argument_list|()
name|override
block|;
name|uint32_t
name|GetNumThreadContexts
argument_list|()
name|override
block|;
name|std
operator|::
name|string
name|GetIdentifierString
argument_list|()
name|override
block|;
name|bool
name|GetCorefileMainBinaryInfo
argument_list|(
argument|lldb::addr_t&address
argument_list|,
argument|lldb_private::UUID&uuid
argument_list|)
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|GetThreadContextAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb_private::Thread&thread
argument_list|)
name|override
block|;
name|ObjectFile
operator|::
name|Type
name|CalculateType
argument_list|()
name|override
block|;
name|ObjectFile
operator|::
name|Strata
name|CalculateStrata
argument_list|()
name|override
block|;
name|uint32_t
name|GetVersion
argument_list|(
argument|uint32_t *versions
argument_list|,
argument|uint32_t num_versions
argument_list|)
name|override
block|;
name|uint32_t
name|GetMinimumOSVersion
argument_list|(
argument|uint32_t *versions
argument_list|,
argument|uint32_t num_versions
argument_list|)
name|override
block|;
name|uint32_t
name|GetSDKVersion
argument_list|(
argument|uint32_t *versions
argument_list|,
argument|uint32_t num_versions
argument_list|)
name|override
block|;
name|bool
name|GetIsDynamicLinkEditor
argument_list|()
name|override
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
name|lldb
operator|::
name|offset_t
operator|*
name|data_offset_ptr
argument_list|,
name|llvm
operator|::
name|MachO
operator|::
name|mach_header
operator|&
name|header
argument_list|)
block|;
name|bool
name|AllowAssemblyEmulationUnwindPlans
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
name|protected
operator|:
specifier|static
name|bool
name|GetUUID
argument_list|(
argument|const llvm::MachO::mach_header&header
argument_list|,
argument|const lldb_private::DataExtractor&data
argument_list|,
argument|lldb::offset_t lc_offset
argument_list|,
comment|// Offset to the first load command
argument|lldb_private::UUID&uuid
argument_list|)
block|;
specifier|static
name|bool
name|GetArchitecture
argument_list|(
argument|const llvm::MachO::mach_header&header
argument_list|,
argument|const lldb_private::DataExtractor&data
argument_list|,
argument|lldb::offset_t lc_offset
argument_list|,
argument|lldb_private::ArchSpec&arch
argument_list|)
block|;
comment|// Intended for same-host arm device debugging where lldb needs to
comment|// detect libraries in the shared cache and augment the nlist entries
comment|// with an on-disk dyld_shared_cache file.  The process will record
comment|// the shared cache UUID so the on-disk cache can be matched or rejected
comment|// correctly.
name|lldb_private
operator|::
name|UUID
name|GetProcessSharedCacheUUID
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
argument_list|)
block|;
comment|// Intended for same-host arm device debugging where lldb will read
comment|// shared cache libraries out of its own memory instead of the remote
comment|// process' memory as an optimization.  If lldb's shared cache UUID
comment|// does not match the process' shared cache UUID, this optimization
comment|// should not be used.
name|lldb_private
operator|::
name|UUID
name|GetLLDBSharedCacheUUID
argument_list|()
block|;
name|lldb_private
operator|::
name|Section
operator|*
name|GetMachHeaderSection
argument_list|()
block|;
name|lldb
operator|::
name|addr_t
name|CalculateSectionLoadAddressForMemoryImage
argument_list|(
argument|lldb::addr_t mach_header_load_address
argument_list|,
argument|const lldb_private::Section *mach_header_section
argument_list|,
argument|const lldb_private::Section *section
argument_list|)
block|;
name|lldb_private
operator|::
name|UUID
name|GetSharedCacheUUID
argument_list|(
argument|lldb_private::FileSpec dyld_shared_cache
argument_list|,
argument|const lldb::ByteOrder byte_order
argument_list|,
argument|const uint32_t addr_byte_size
argument_list|)
block|;
name|size_t
name|ParseSymtab
argument_list|()
block|;
name|llvm
operator|::
name|MachO
operator|::
name|mach_header
name|m_header
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|GetSegmentNameTEXT
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|GetSegmentNameDATA
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|GetSegmentNameDATA_DIRTY
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|GetSegmentNameDATA_CONST
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|GetSegmentNameOBJC
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|GetSegmentNameLINKEDIT
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|GetSectionNameEHFrame
argument_list|()
block|;
name|llvm
operator|::
name|MachO
operator|::
name|dysymtab_command
name|m_dysymtab
block|;
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|MachO
operator|::
name|segment_command_64
operator|>
name|m_mach_segments
block|;
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|MachO
operator|::
name|section_64
operator|>
name|m_mach_sections
block|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|m_min_os_versions
block|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|m_sdk_versions
block|;
typedef|typedef
name|lldb_private
operator|::
name|RangeVector
operator|<
name|uint32_t
operator|,
name|uint32_t
operator|>
name|FileRangeArray
expr_stmt|;
name|lldb_private
operator|::
name|Address
name|m_entry_point_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FileRangeArray
name|m_thread_context_offsets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_thread_context_offsets_valid
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|FileSpecList
name|m_reexported_dylibs
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_allow_assembly_emulation_unwind_plans
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ObjectFileMachO_h_
end_comment

end_unit

