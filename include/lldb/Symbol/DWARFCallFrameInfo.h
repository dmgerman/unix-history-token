begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFCallFrameInfo.h ------------------------------------*- C++ -*-===//
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
name|liblldb_DWARFCallFrameInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DWARFCallFrameInfo_h_
end_define

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/dwarf.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/UnwindPlan.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/VMRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// DWARFCallFrameInfo is a class which can read eh_frame and DWARF
comment|// Call Frame Information FDEs.  It stores little information internally.
comment|// Only two APIs are exported - one to find the high/low pc values
comment|// of a function given a text address via the information in the
comment|// eh_frame / debug_frame, and one to generate an UnwindPlan based
comment|// on the FDE in the eh_frame / debug_frame section.
name|class
name|DWARFCallFrameInfo
block|{
name|public
label|:
name|DWARFCallFrameInfo
argument_list|(
argument|ObjectFile&objfile
argument_list|,
argument|lldb::SectionSP&section
argument_list|,
argument|lldb::RegisterKind reg_kind
argument_list|,
argument|bool is_eh_frame
argument_list|)
empty_stmt|;
operator|~
name|DWARFCallFrameInfo
argument_list|()
expr_stmt|;
comment|// Locate an AddressRange that includes the provided Address in this
comment|// object's eh_frame/debug_info
comment|// Returns true if a range is found to cover that address.
name|bool
name|GetAddressRange
parameter_list|(
name|Address
name|addr
parameter_list|,
name|AddressRange
modifier|&
name|range
parameter_list|)
function_decl|;
comment|// Return an UnwindPlan based on the call frame information encoded
comment|// in the FDE of this DWARFCallFrameInfo section.
name|bool
name|GetUnwindPlan
parameter_list|(
name|Address
name|addr
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|)
function_decl|;
typedef|typedef
name|RangeVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|uint32_t
operator|>
name|FunctionAddressAndSizeVector
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Build a vector of file address and size for all functions in this Module
comment|// based on the eh_frame FDE entries.
comment|//
comment|// The eh_frame information can be a useful source of file address and size of
comment|// the functions in a Module.  Often a binary's non-exported symbols are
comment|// stripped
comment|// before shipping so lldb won't know the start addr / size of many functions
comment|// in the Module.  But the eh_frame can help to give the addresses of these
comment|// stripped symbols, at least.
comment|//
comment|// @param[out] function_info
comment|//      A vector provided by the caller is filled out.  May be empty if no
comment|//      FDEs/no eh_frame
comment|//      is present in this Module.
name|void
name|GetFunctionAddressAndSizeVector
parameter_list|(
name|FunctionAddressAndSizeVector
modifier|&
name|function_info
parameter_list|)
function_decl|;
name|void
name|ForEachFDEEntries
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|lldb
operator|::
name|addr_t
argument_list|,
name|uint32_t
argument_list|,
name|dw_offset_t
argument_list|)
operator|>
operator|&
name|callback
argument_list|)
decl_stmt|;
name|private
label|:
enum|enum
block|{
name|CFI_AUG_MAX_SIZE
init|=
literal|8
block|,
name|CFI_HEADER_SIZE
init|=
literal|8
block|}
enum|;
struct|struct
name|CIE
block|{
name|dw_offset_t
name|cie_offset
decl_stmt|;
name|uint8_t
name|version
decl_stmt|;
name|char
name|augmentation
index|[
name|CFI_AUG_MAX_SIZE
index|]
decl_stmt|;
comment|// This is typically empty or very
comment|// short.
name|uint32_t
name|code_align
decl_stmt|;
name|int32_t
name|data_align
decl_stmt|;
name|uint32_t
name|return_addr_reg_num
decl_stmt|;
name|dw_offset_t
name|inst_offset
decl_stmt|;
comment|// offset of CIE instructions in mCFIData
name|uint32_t
name|inst_length
decl_stmt|;
comment|// length of CIE instructions in mCFIData
name|uint8_t
name|ptr_encoding
decl_stmt|;
name|uint8_t
name|lsda_addr_encoding
decl_stmt|;
comment|// The encoding of the LSDA address in the FDE
comment|// augmentation data
name|lldb
operator|::
name|addr_t
name|personality_loc
expr_stmt|;
comment|// (file) address of the pointer to the
comment|// personality routine
name|lldb_private
operator|::
name|UnwindPlan
operator|::
name|Row
name|initial_row
expr_stmt|;
name|CIE
argument_list|(
argument|dw_offset_t offset
argument_list|)
block|:
name|cie_offset
argument_list|(
name|offset
argument_list|)
operator|,
name|version
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|code_align
argument_list|(
literal|0
argument_list|)
operator|,
name|data_align
argument_list|(
literal|0
argument_list|)
operator|,
name|return_addr_reg_num
argument_list|(
name|LLDB_INVALID_REGNUM
argument_list|)
operator|,
name|inst_offset
argument_list|(
literal|0
argument_list|)
operator|,
name|inst_length
argument_list|(
literal|0
argument_list|)
operator|,
name|ptr_encoding
argument_list|(
literal|0
argument_list|)
operator|,
name|lsda_addr_encoding
argument_list|(
name|DW_EH_PE_omit
argument_list|)
operator|,
name|personality_loc
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|initial_row
argument_list|()
block|{}
block|}
struct|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|CIE
operator|>
name|CIESP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|dw_offset_t
operator|,
name|CIESP
operator|>
name|cie_map_t
expr_stmt|;
comment|// Start address (file address), size, offset of FDE location
comment|// used for finding an FDE for a given File address; the start address field
comment|// is
comment|// an offset into an individual Module.
typedef|typedef
name|RangeDataVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|uint32_t
operator|,
name|dw_offset_t
operator|>
name|FDEEntryMap
expr_stmt|;
name|bool
name|IsEHFrame
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|GetFDEEntryByFileAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|file_offset
argument_list|,
name|FDEEntryMap
operator|::
name|Entry
operator|&
name|fde_entry
argument_list|)
decl_stmt|;
name|void
name|GetFDEIndex
parameter_list|()
function_decl|;
name|bool
name|FDEToUnwindPlan
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
name|Address
name|startaddr
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|)
function_decl|;
specifier|const
name|CIE
modifier|*
name|GetCIE
parameter_list|(
name|dw_offset_t
name|cie_offset
parameter_list|)
function_decl|;
name|void
name|GetCFIData
parameter_list|()
function_decl|;
comment|// Applies the specified DWARF opcode to the given row. This function handle
comment|// the commands
comment|// operates only on a single row (these are the ones what can appear both in
comment|// CIE and in FDE).
comment|// Returns true if the opcode is handled and false otherwise.
name|bool
name|HandleCommonDwarfOpcode
argument_list|(
name|uint8_t
name|primary_opcode
argument_list|,
name|uint8_t
name|extended_opcode
argument_list|,
name|int32_t
name|data_align
argument_list|,
name|lldb
operator|::
name|offset_t
operator|&
name|offset
argument_list|,
name|UnwindPlan
operator|::
name|Row
operator|&
name|row
argument_list|)
decl_stmt|;
name|ObjectFile
modifier|&
name|m_objfile
decl_stmt|;
name|lldb
operator|::
name|SectionSP
name|m_section_sp
expr_stmt|;
name|lldb
operator|::
name|RegisterKind
name|m_reg_kind
expr_stmt|;
name|Flags
name|m_flags
decl_stmt|;
name|cie_map_t
name|m_cie_map
decl_stmt|;
name|DataExtractor
name|m_cfi_data
decl_stmt|;
name|bool
name|m_cfi_data_initialized
decl_stmt|;
comment|// only copy the section into the DE once
name|FDEEntryMap
name|m_fde_index
decl_stmt|;
name|bool
name|m_fde_index_initialized
decl_stmt|;
comment|// only scan the section for FDEs once
name|std
operator|::
name|mutex
name|m_fde_index_mutex
expr_stmt|;
comment|// and isolate the thread that does it
name|bool
name|m_is_eh_frame
decl_stmt|;
name|CIESP
name|ParseCIE
parameter_list|(
specifier|const
name|uint32_t
name|cie_offset
parameter_list|)
function_decl|;
block|}
empty_stmt|;
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
comment|// liblldb_DWARFCallFrameInfo_h_
end_comment

end_unit

