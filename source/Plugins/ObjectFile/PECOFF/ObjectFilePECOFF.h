begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectFilePECOFF.h --------------------------------------*- C++ -*-===//
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
name|liblldb_ObjectFilePECOFF_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectFilePECOFF_h_
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
file|"lldb/Symbol/ObjectFile.h"
end_include

begin_decl_stmt
name|class
name|ObjectFilePECOFF
range|:
name|public
name|lldb_private
operator|::
name|ObjectFile
block|{
name|public
operator|:
typedef|typedef
enum|enum
name|MachineType
block|{
name|MachineUnknown
init|=
literal|0x0
block|,
name|MachineAm33
init|=
literal|0x1d3
block|,
name|MachineAmd64
init|=
literal|0x8664
block|,
name|MachineArm
init|=
literal|0x1c0
block|,
name|MachineArmNt
init|=
literal|0x1c4
block|,
name|MachineArm64
init|=
literal|0xaa64
block|,
name|MachineEbc
init|=
literal|0xebc
block|,
name|MachineX86
init|=
literal|0x14c
block|,
name|MachineIA64
init|=
literal|0x200
block|,
name|MachineM32R
init|=
literal|0x9041
block|,
name|MachineMips16
init|=
literal|0x266
block|,
name|MachineMipsFpu
init|=
literal|0x366
block|,
name|MachineMipsFpu16
init|=
literal|0x466
block|,
name|MachinePowerPc
init|=
literal|0x1f0
block|,
name|MachinePowerPcfp
init|=
literal|0x1f1
block|,
name|MachineR4000
init|=
literal|0x166
block|,
name|MachineSh3
init|=
literal|0x1a2
block|,
name|MachineSh3dsp
init|=
literal|0x1a3
block|,
name|MachineSh4
init|=
literal|0x1a6
block|,
name|MachineSh5
init|=
literal|0x1a8
block|,
name|MachineThumb
init|=
literal|0x1c2
block|,
name|MachineWcemIpsv2
init|=
literal|0x169
init|}
name|MachineType
empty_stmt|;
name|ObjectFilePECOFF
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
empty_stmt|;
name|ObjectFilePECOFF
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP&header_data_sp
argument_list|,
argument|const lldb::ProcessSP&process_sp
argument_list|,
argument|lldb::addr_t header_addr
argument_list|)
empty_stmt|;
operator|~
name|ObjectFilePECOFF
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|Terminate
parameter_list|()
function_decl|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetPluginDescriptionStatic
parameter_list|()
function_decl|;
specifier|static
name|ObjectFile
modifier|*
name|CreateInstance
block|(const
name|lldb
block|::
name|ModuleSP
modifier|&
name|module_sp
block|,
name|lldb
decl|::
name|DataBufferSP
modifier|&
name|data_sp
block|,
name|lldb
decl|::
name|offset_t
name|data_offset
block|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|*
name|file
operator|,
name|lldb
operator|::
name|offset_t
name|offset
operator|,
name|lldb
operator|::
name|offset_t
name|length
block|)
enum|;
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|size_t
name|GetModuleSpecifications
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file
argument_list|,
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|,
name|lldb
operator|::
name|offset_t
name|data_offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|file_offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|length
argument_list|,
name|lldb_private
operator|::
name|ModuleSpecList
operator|&
name|specs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|MagicBytesMatch
argument_list|(
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|SymbolType
name|MapSymbolType
argument_list|(
argument|uint16_t coff_symbol_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|ParseHeader
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|SetLoadAddress
argument_list|(
name|lldb_private
operator|::
name|Target
operator|&
name|target
argument_list|,
name|lldb
operator|::
name|addr_t
name|value
argument_list|,
name|bool
name|value_is_offset
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsExecutable
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|//    virtual lldb_private::AddressClass
end_comment

begin_comment
comment|//    GetAddressClass (lldb::addr_t file_addr);
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Symtab
operator|*
name|GetSymtab
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsStripped
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|CreateSections
argument_list|(
name|lldb_private
operator|::
name|SectionList
operator|&
name|unified_section_list
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|GetArchitecture
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|GetUUID
argument_list|(
name|lldb_private
operator|::
name|UUID
operator|*
name|uuid
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|GetDependentModules
argument_list|(
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|files
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|lldb_private
operator|::
name|Address
name|GetEntryPointAddress
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ObjectFile
operator|::
name|Type
name|CalculateType
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ObjectFile
operator|::
name|Strata
name|CalculateStrata
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// PluginInterface protocol
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|IsWindowsSubsystem
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb_private
operator|::
name|DataExtractor
name|ReadImageData
argument_list|(
argument|uint32_t offset
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|bool
name|NeedsEndianSwap
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|dos_header
block|{
comment|// DOS .EXE header
name|uint16_t
name|e_magic
decl_stmt|;
comment|// Magic number
name|uint16_t
name|e_cblp
decl_stmt|;
comment|// Bytes on last page of file
name|uint16_t
name|e_cp
decl_stmt|;
comment|// Pages in file
name|uint16_t
name|e_crlc
decl_stmt|;
comment|// Relocations
name|uint16_t
name|e_cparhdr
decl_stmt|;
comment|// Size of header in paragraphs
name|uint16_t
name|e_minalloc
decl_stmt|;
comment|// Minimum extra paragraphs needed
name|uint16_t
name|e_maxalloc
decl_stmt|;
comment|// Maximum extra paragraphs needed
name|uint16_t
name|e_ss
decl_stmt|;
comment|// Initial (relative) SS value
name|uint16_t
name|e_sp
decl_stmt|;
comment|// Initial SP value
name|uint16_t
name|e_csum
decl_stmt|;
comment|// Checksum
name|uint16_t
name|e_ip
decl_stmt|;
comment|// Initial IP value
name|uint16_t
name|e_cs
decl_stmt|;
comment|// Initial (relative) CS value
name|uint16_t
name|e_lfarlc
decl_stmt|;
comment|// File address of relocation table
name|uint16_t
name|e_ovno
decl_stmt|;
comment|// Overlay number
name|uint16_t
name|e_res
index|[
literal|4
index|]
decl_stmt|;
comment|// Reserved words
name|uint16_t
name|e_oemid
decl_stmt|;
comment|// OEM identifier (for e_oeminfo)
name|uint16_t
name|e_oeminfo
decl_stmt|;
comment|// OEM information; e_oemid specific
name|uint16_t
name|e_res2
index|[
literal|10
index|]
decl_stmt|;
comment|// Reserved words
name|uint32_t
name|e_lfanew
decl_stmt|;
comment|// File address of new exe header
block|}
name|dos_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|coff_header
block|{
name|uint16_t
name|machine
decl_stmt|;
name|uint16_t
name|nsects
decl_stmt|;
name|uint32_t
name|modtime
decl_stmt|;
name|uint32_t
name|symoff
decl_stmt|;
name|uint32_t
name|nsyms
decl_stmt|;
name|uint16_t
name|hdrsize
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
block|}
name|coff_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|data_directory
block|{
name|uint32_t
name|vmaddr
decl_stmt|;
name|uint32_t
name|vmsize
decl_stmt|;
block|}
name|data_directory_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|coff_opt_header
block|{
name|uint16_t
name|magic
decl_stmt|;
name|uint8_t
name|major_linker_version
decl_stmt|;
name|uint8_t
name|minor_linker_version
decl_stmt|;
name|uint32_t
name|code_size
decl_stmt|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|bss_size
decl_stmt|;
name|uint32_t
name|entry
decl_stmt|;
name|uint32_t
name|code_offset
decl_stmt|;
name|uint32_t
name|data_offset
decl_stmt|;
name|uint64_t
name|image_base
decl_stmt|;
name|uint32_t
name|sect_alignment
decl_stmt|;
name|uint32_t
name|file_alignment
decl_stmt|;
name|uint16_t
name|major_os_system_version
decl_stmt|;
name|uint16_t
name|minor_os_system_version
decl_stmt|;
name|uint16_t
name|major_image_version
decl_stmt|;
name|uint16_t
name|minor_image_version
decl_stmt|;
name|uint16_t
name|major_subsystem_version
decl_stmt|;
name|uint16_t
name|minor_subsystem_version
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|image_size
decl_stmt|;
name|uint32_t
name|header_size
decl_stmt|;
name|uint32_t
name|checksum
decl_stmt|;
name|uint16_t
name|subsystem
decl_stmt|;
name|uint16_t
name|dll_flags
decl_stmt|;
name|uint64_t
name|stack_reserve_size
decl_stmt|;
name|uint64_t
name|stack_commit_size
decl_stmt|;
name|uint64_t
name|heap_reserve_size
decl_stmt|;
name|uint64_t
name|heap_commit_size
decl_stmt|;
name|uint32_t
name|loader_flags
decl_stmt|;
comment|//    uint32_t	num_data_dir_entries;
name|std
operator|::
name|vector
operator|<
name|data_directory
operator|>
name|data_dirs
expr_stmt|;
comment|// will contain num_data_dir_entries entries
block|}
name|coff_opt_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|coff_data_dir_type
block|{
name|coff_data_dir_export_table
init|=
literal|0
block|,
name|coff_data_dir_import_table
init|=
literal|1
block|,   }
name|coff_data_dir_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|section_header
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|vmsize
decl_stmt|;
comment|// Virtual Size
name|uint32_t
name|vmaddr
decl_stmt|;
comment|// Virtual Addr
name|uint32_t
name|size
decl_stmt|;
comment|// File size
name|uint32_t
name|offset
decl_stmt|;
comment|// File offset
name|uint32_t
name|reloff
decl_stmt|;
comment|// Offset to relocations
name|uint32_t
name|lineoff
decl_stmt|;
comment|// Offset to line table entries
name|uint16_t
name|nreloc
decl_stmt|;
comment|// Number of relocation entries
name|uint16_t
name|nline
decl_stmt|;
comment|// Number of line table entries
name|uint32_t
name|flags
decl_stmt|;
block|}
name|section_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|coff_symbol
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|value
decl_stmt|;
name|uint16_t
name|sect
decl_stmt|;
name|uint16_t
name|type
decl_stmt|;
name|uint8_t
name|storage
decl_stmt|;
name|uint8_t
name|naux
decl_stmt|;
block|}
name|coff_symbol_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|export_directory_entry
block|{
name|uint32_t
name|characteristics
decl_stmt|;
name|uint32_t
name|time_date_stamp
decl_stmt|;
name|uint16_t
name|major_version
decl_stmt|;
name|uint16_t
name|minor_version
decl_stmt|;
name|uint32_t
name|name
decl_stmt|;
name|uint32_t
name|base
decl_stmt|;
name|uint32_t
name|number_of_functions
decl_stmt|;
name|uint32_t
name|number_of_names
decl_stmt|;
name|uint32_t
name|address_of_functions
decl_stmt|;
name|uint32_t
name|address_of_names
decl_stmt|;
name|uint32_t
name|address_of_name_ordinals
decl_stmt|;
block|}
name|export_directory_entry
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|bool
name|ParseDOSHeader
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|dos_header_t
operator|&
name|dos_header
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ParseCOFFHeader
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
name|offset_ptr
argument_list|,
name|coff_header_t
operator|&
name|coff_header
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ParseCOFFOptionalHeader
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|ParseSectionHeaders
parameter_list|(
name|uint32_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|void
name|DumpDOSHeader
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|dos_header_t
operator|&
name|header
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpCOFFHeader
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|coff_header_t
operator|&
name|header
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpOptCOFFHeader
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|coff_opt_header_t
operator|&
name|header
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DumpSectionHeaders
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DumpSectionHeader
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|section_header_t
operator|&
name|sh
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|GetSectionName
argument_list|(
name|std
operator|::
name|string
operator|&
name|sect_name
argument_list|,
specifier|const
name|section_header_t
operator|&
name|sect
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|section_header_t
operator|>
name|SectionHeaderColl
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SectionHeaderColl
operator|::
name|iterator
name|SectionHeaderCollIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SectionHeaderColl
operator|::
name|const_iterator
name|SectionHeaderCollConstIter
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|dos_header_t
name|m_dos_header
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|coff_header_t
name|m_coff_header
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|coff_opt_header_t
name|m_coff_header_opt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SectionHeaderColl
name|m_sect_headers
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_image_base
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|m_entry_point_address
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ObjectFilePECOFF_h_
end_comment

end_unit

