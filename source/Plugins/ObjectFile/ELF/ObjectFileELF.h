begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectFileELF.h --------------------------------------- -*- C++ -*-===//
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
name|liblldb_ObjectFileELF_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectFileELF_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<functional>
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
file|"lldb/Core/ArchSpec.h"
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
file|"lldb/Utility/UUID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"ELFHeader.h"
end_include

begin_struct
struct|struct
name|ELFNote
block|{
name|elf
operator|::
name|elf_word
name|n_namesz
expr_stmt|;
name|elf
operator|::
name|elf_word
name|n_descsz
expr_stmt|;
name|elf
operator|::
name|elf_word
name|n_type
expr_stmt|;
name|std
operator|::
name|string
name|n_name
expr_stmt|;
name|ELFNote
argument_list|()
operator|:
name|n_namesz
argument_list|(
literal|0
argument_list|)
operator|,
name|n_descsz
argument_list|(
literal|0
argument_list|)
operator|,
name|n_type
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Parse an ELFNote entry from the given DataExtractor starting at position
comment|/// \p offset.
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFRel entry was successfully read and false otherwise.
name|bool
name|Parse
argument_list|(
specifier|const
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
name|offset
argument_list|)
expr_stmt|;
name|size_t
name|GetByteSize
argument_list|()
specifier|const
block|{
return|return
literal|12
operator|+
name|llvm
operator|::
name|alignTo
argument_list|(
name|n_namesz
argument_list|,
literal|4
argument_list|)
operator|+
name|llvm
operator|::
name|alignTo
argument_list|(
name|n_descsz
argument_list|,
literal|4
argument_list|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class ObjectFileELF
end_comment

begin_comment
comment|/// @brief Generic ELF object file reader.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class provides a generic ELF (32/64 bit) reader plugin implementing the
end_comment

begin_comment
comment|/// ObjectFile protocol.
end_comment

begin_decl_stmt
name|class
name|ObjectFileELF
range|:
name|public
name|lldb_private
operator|::
name|ObjectFile
block|{
name|public
operator|:
operator|~
name|ObjectFileELF
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
comment|// ObjectFile Protocol.
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
name|lldb_private
operator|::
name|FileSpecList
name|GetDebugSymbolFilePaths
argument_list|()
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
name|Address
name|GetImageInfoAddress
argument_list|(
argument|lldb_private::Target *target
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Address
name|GetEntryPointAddress
argument_list|()
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
comment|// Returns number of program headers found in the ELF file.
name|size_t
name|GetProgramHeaderCount
argument_list|()
block|;
comment|// Returns the program header with the given index.
specifier|const
name|elf
operator|::
name|ELFProgramHeader
operator|*
name|GetProgramHeaderByIndex
argument_list|(
argument|lldb::user_id_t id
argument_list|)
block|;
comment|// Returns segment data for the given index.
name|lldb_private
operator|::
name|DataExtractor
name|GetSegmentDataByIndex
argument_list|(
argument|lldb::user_id_t id
argument_list|)
block|;
name|llvm
operator|::
name|StringRef
name|StripLinkerSymbolAnnotations
argument_list|(
argument|llvm::StringRef symbol_name
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|ObjectFileELF
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
name|ObjectFileELF
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP&header_data_sp
argument_list|,
argument|const lldb::ProcessSP&process_sp
argument_list|,
argument|lldb::addr_t header_addr
argument_list|)
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|elf
operator|::
name|ELFProgramHeader
operator|>
name|ProgramHeaderColl
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|ProgramHeaderColl
operator|::
name|iterator
name|ProgramHeaderCollIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ProgramHeaderColl
operator|::
name|const_iterator
name|ProgramHeaderCollConstIter
expr_stmt|;
end_typedef

begin_decl_stmt
name|struct
name|ELFSectionHeaderInfo
range|:
name|public
name|elf
operator|::
name|ELFSectionHeader
block|{
name|lldb_private
operator|::
name|ConstString
name|section_name
block|;   }
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ELFSectionHeaderInfo
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

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|elf
operator|::
name|ELFDynamic
operator|>
name|DynamicSymbolColl
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DynamicSymbolColl
operator|::
name|iterator
name|DynamicSymbolCollIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DynamicSymbolColl
operator|::
name|const_iterator
name|DynamicSymbolCollConstIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|AddressClass
operator|>
name|FileAddressToAddressClassMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|function
operator|<
name|lldb
operator|::
name|offset_t
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
argument_list|,
name|lldb
operator|::
name|offset_t
argument_list|,
name|lldb
operator|::
name|offset_t
argument_list|)
operator|>
name|SetDataFunction
expr_stmt|;
end_typedef

begin_comment
comment|/// Version of this reader common to all plugins based on this class.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|m_plugin_version
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|g_core_uuid_magic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ELF file header.
end_comment

begin_expr_stmt
name|elf
operator|::
name|ELFHeader
name|m_header
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ELF build ID.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|UUID
name|m_uuid
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ELF .gnu_debuglink file and crc data if available.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|m_gnu_debuglink_file
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|m_gnu_debuglink_crc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Collection of program headers.
end_comment

begin_decl_stmt
name|ProgramHeaderColl
name|m_program_headers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Collection of section headers.
end_comment

begin_decl_stmt
name|SectionHeaderColl
name|m_section_headers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Collection of symbols from the dynamic table.
end_comment

begin_decl_stmt
name|DynamicSymbolColl
name|m_dynamic_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// List of file specifications corresponding to the modules (shared
end_comment

begin_comment
comment|/// libraries) on which this object file depends.
end_comment

begin_expr_stmt
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|FileSpecList
operator|>
name|m_filespec_ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Cached value of the entry point for this module.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|m_entry_point_address
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The architecture detected from parsing elf file contents.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|ArchSpec
name|m_arch_spec
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The address class for each symbol in the elf file
end_comment

begin_decl_stmt
name|FileAddressToAddressClassMap
name|m_address_class_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns a 1 based index of the given section header.
end_comment

begin_function_decl
name|size_t
name|SectionIndex
parameter_list|(
specifier|const
name|SectionHeaderCollIter
modifier|&
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns a 1 based index of the given section header.
end_comment

begin_decl_stmt
name|size_t
name|SectionIndex
argument_list|(
specifier|const
name|SectionHeaderCollConstIter
operator|&
name|I
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Parses the ELF program headers.
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|GetProgramHeaderInfo
argument_list|(
name|ProgramHeaderColl
operator|&
name|program_headers
argument_list|,
specifier|const
name|SetDataFunction
operator|&
name|set_data
argument_list|,
specifier|const
name|elf
operator|::
name|ELFHeader
operator|&
name|header
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Finds PT_NOTE segments and calculates their crc sum.
end_comment

begin_decl_stmt
specifier|static
name|uint32_t
name|CalculateELFNotesSegmentsCRC32
argument_list|(
specifier|const
name|ProgramHeaderColl
operator|&
name|program_headers
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Parses all section headers present in this object file and populates
end_comment

begin_comment
comment|/// m_program_headers.  This method will compute the header list only once.
end_comment

begin_comment
comment|/// Returns the number of headers parsed.
end_comment

begin_function_decl
name|size_t
name|ParseProgramHeaders
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Parses all section headers present in this object file and populates
end_comment

begin_comment
comment|/// m_section_headers.  This method will compute the header list only once.
end_comment

begin_comment
comment|/// Returns the number of headers parsed.
end_comment

begin_function_decl
name|size_t
name|ParseSectionHeaders
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|void
name|ParseARMAttributes
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|uint64_t
name|length
argument_list|,
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch_spec
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Parses the elf section headers and returns the uuid, debug link name, crc,
end_comment

begin_comment
comment|/// archspec.
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|GetSectionHeaderInfo
argument_list|(
name|SectionHeaderColl
operator|&
name|section_headers
argument_list|,
specifier|const
name|SetDataFunction
operator|&
name|set_data
argument_list|,
specifier|const
name|elf
operator|::
name|ELFHeader
operator|&
name|header
argument_list|,
name|lldb_private
operator|::
name|UUID
operator|&
name|uuid
argument_list|,
name|std
operator|::
name|string
operator|&
name|gnu_debuglink_file
argument_list|,
name|uint32_t
operator|&
name|gnu_debuglink_crc
argument_list|,
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch_spec
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Scans the dynamic section and locates all dependent modules (shared
end_comment

begin_comment
comment|/// libraries) populating m_filespec_ap.  This method will compute the
end_comment

begin_comment
comment|/// dependent module list only once.  Returns the number of dependent
end_comment

begin_comment
comment|/// modules parsed.
end_comment

begin_function_decl
name|size_t
name|ParseDependentModules
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Parses the dynamic symbol table and populates m_dynamic_symbols.  The
end_comment

begin_comment
comment|/// vector retains the order as found in the object file.  Returns the
end_comment

begin_comment
comment|/// number of dynamic symbols parsed.
end_comment

begin_function_decl
name|size_t
name|ParseDynamicSymbols
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Populates m_symtab_ap will all non-dynamic linker symbols.  This method
end_comment

begin_comment
comment|/// will parse the symbols only once.  Returns the number of symbols parsed.
end_comment

begin_decl_stmt
name|unsigned
name|ParseSymbolTable
argument_list|(
name|lldb_private
operator|::
name|Symtab
operator|*
name|symbol_table
argument_list|,
name|lldb
operator|::
name|user_id_t
name|start_id
argument_list|,
name|lldb_private
operator|::
name|Section
operator|*
name|symtab
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Helper routine for ParseSymbolTable().
end_comment

begin_decl_stmt
name|unsigned
name|ParseSymbols
argument_list|(
name|lldb_private
operator|::
name|Symtab
operator|*
name|symbol_table
argument_list|,
name|lldb
operator|::
name|user_id_t
name|start_id
argument_list|,
name|lldb_private
operator|::
name|SectionList
operator|*
name|section_list
argument_list|,
specifier|const
name|size_t
name|num_symbols
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|symtab_data
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|strtab_data
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Scans the relocation entries and adds a set of artificial symbols to the
end_comment

begin_comment
comment|/// given symbol table for each PLT slot.  Returns the number of symbols
end_comment

begin_comment
comment|/// added.
end_comment

begin_decl_stmt
name|unsigned
name|ParseTrampolineSymbols
argument_list|(
name|lldb_private
operator|::
name|Symtab
operator|*
name|symbol_table
argument_list|,
name|lldb
operator|::
name|user_id_t
name|start_id
argument_list|,
specifier|const
name|ELFSectionHeaderInfo
operator|*
name|rela_hdr
argument_list|,
name|lldb
operator|::
name|user_id_t
name|section_id
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ParseUnwindSymbols
argument_list|(
name|lldb_private
operator|::
name|Symtab
operator|*
name|symbol_table
argument_list|,
name|lldb_private
operator|::
name|DWARFCallFrameInfo
operator|*
name|eh_frame
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Relocates debug sections
end_comment

begin_decl_stmt
name|unsigned
name|RelocateDebugSections
argument_list|(
specifier|const
name|elf
operator|::
name|ELFSectionHeader
operator|*
name|rel_hdr
argument_list|,
name|lldb
operator|::
name|user_id_t
name|rel_id
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|RelocateSection
argument_list|(
name|lldb_private
operator|::
name|Symtab
operator|*
name|symtab
argument_list|,
specifier|const
name|elf
operator|::
name|ELFHeader
operator|*
name|hdr
argument_list|,
specifier|const
name|elf
operator|::
name|ELFSectionHeader
operator|*
name|rel_hdr
argument_list|,
specifier|const
name|elf
operator|::
name|ELFSectionHeader
operator|*
name|symtab_hdr
argument_list|,
specifier|const
name|elf
operator|::
name|ELFSectionHeader
operator|*
name|debug_hdr
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|rel_data
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|symtab_data
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|debug_data
argument_list|,
name|lldb_private
operator|::
name|Section
operator|*
name|rel_section
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Loads the section name string table into m_shstr_data.  Returns the
end_comment

begin_comment
comment|/// number of bytes constituting the table.
end_comment

begin_function_decl
name|size_t
name|GetSectionHeaderStringTable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Utility method for looking up a section given its name.  Returns the
end_comment

begin_comment
comment|/// index of the corresponding section or zero if no section with the given
end_comment

begin_comment
comment|/// name can be found (note that section indices are always 1 based, and so
end_comment

begin_comment
comment|/// section index 0 is never valid).
end_comment

begin_expr_stmt
name|lldb
operator|::
name|user_id_t
name|GetSectionIndexByName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns the ID of the first section that has the given type.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|user_id_t
name|GetSectionIndexByType
argument_list|(
argument|unsigned type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns the section header with the given id or NULL.
end_comment

begin_decl_stmt
specifier|const
name|ELFSectionHeaderInfo
modifier|*
name|GetSectionHeaderByIndex
argument_list|(
name|lldb
operator|::
name|user_id_t
name|id
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @name  ELF header dump routines
end_comment

begin_comment
comment|//@{
end_comment

begin_decl_stmt
specifier|static
name|void
name|DumpELFHeader
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|elf
operator|::
name|ELFHeader
operator|&
name|header
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpELFHeader_e_ident_EI_DATA
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
name|unsigned
name|char
name|ei_data
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpELFHeader_e_type
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
name|elf
operator|::
name|elf_half
name|e_type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// @name ELF program header dump routines
end_comment

begin_comment
comment|//@{
end_comment

begin_decl_stmt
name|void
name|DumpELFProgramHeaders
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
specifier|static
name|void
name|DumpELFProgramHeader
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|elf
operator|::
name|ELFProgramHeader
operator|&
name|ph
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpELFProgramHeader_p_type
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
name|elf
operator|::
name|elf_word
name|p_type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpELFProgramHeader_p_flags
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
name|elf
operator|::
name|elf_word
name|p_flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// @name ELF section header dump routines
end_comment

begin_comment
comment|//@{
end_comment

begin_decl_stmt
name|void
name|DumpELFSectionHeaders
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
specifier|static
name|void
name|DumpELFSectionHeader
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|ELFSectionHeaderInfo
operator|&
name|sh
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpELFSectionHeader_sh_type
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
name|elf
operator|::
name|elf_word
name|sh_type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|DumpELFSectionHeader_sh_flags
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
name|elf
operator|::
name|elf_xword
name|sh_flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// ELF dependent module dump routine.
end_comment

begin_decl_stmt
name|void
name|DumpDependentModules
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|elf
operator|::
name|ELFDynamic
operator|*
name|FindDynamicSymbol
argument_list|(
argument|unsigned tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|unsigned
name|PLTRelocationType
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|Error
name|RefineModuleDetailsFromNote
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch_spec
argument_list|,
name|lldb_private
operator|::
name|UUID
operator|&
name|uuid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|offset_t
name|SetData
argument_list|(
argument|const lldb_private::DataExtractor&src
argument_list|,
argument|lldb_private::DataExtractor&dst
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|offset_t
name|SetDataWithReadMemoryFallback
argument_list|(
argument|lldb_private::DataExtractor&dst
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ObjectFileELF_h_
end_comment

end_unit

