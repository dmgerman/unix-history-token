begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompactUnwindInfo.h -------------------------------------*- C++ -*-===//
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
name|liblldb_CompactUnwindInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CompactUnwindInfo_h_
end_define

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
file|"lldb/Symbol/UnwindPlan.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
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
comment|// Compact Unwind info is an unwind format used on Darwin.  The unwind
comment|// instructions
comment|// for typical compiler-generated functions can be expressed in a 32-bit
comment|// encoding.
comment|// The format includes a two-level index so the unwind information for a
comment|// function
comment|// can be found by two binary searches in the section.  It can represent both
comment|// stack frames that use a frame-pointer register and frameless functions, on
comment|// i386/x86_64 for instance.  When a function is too complex to be represented
comment|// in
comment|// the compact unwind format, it calls out to eh_frame unwind instructions.
comment|// On Mac OS X / iOS, a function will have either a compact unwind
comment|// representation
comment|// or an eh_frame representation.  If lldb is going to benefit  from the
comment|// compiler's
comment|// description about saved register locations, it must be able to read both
comment|// sources of information.
name|class
name|CompactUnwindInfo
block|{
name|public
label|:
name|CompactUnwindInfo
argument_list|(
name|ObjectFile
operator|&
name|objfile
argument_list|,
name|lldb
operator|::
name|SectionSP
operator|&
name|section
argument_list|)
expr_stmt|;
operator|~
name|CompactUnwindInfo
argument_list|()
expr_stmt|;
name|bool
name|GetUnwindPlan
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|Address
name|addr
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|)
function_decl|;
name|bool
name|IsValid
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
name|private
label|:
comment|// The top level index entries of the compact unwind info
comment|//   (internal representation of struct
comment|//   unwind_info_section_header_index_entry)
comment|// There are relatively few of these (one per 500/1000 functions, depending on
comment|// format) so
comment|// creating them on first scan will not be too costly.
struct|struct
name|UnwindIndex
block|{
name|uint32_t
name|function_offset
decl_stmt|;
comment|// The offset of the first function covered by
comment|// this index
name|uint32_t
name|second_level
decl_stmt|;
comment|// The offset (inside unwind_info sect) to the second
comment|// level page for this index
comment|// (either UNWIND_SECOND_LEVEL_REGULAR or UNWIND_SECOND_LEVEL_COMPRESSED)
name|uint32_t
name|lsda_array_start
decl_stmt|;
comment|// The offset (inside unwind_info sect) LSDA
comment|// array for this index
name|uint32_t
name|lsda_array_end
decl_stmt|;
comment|// The offset to the LSDA array for the NEXT index
name|bool
name|sentinal_entry
decl_stmt|;
comment|// There is an empty index at the end which provides
comment|// the upper bound of
comment|// function addresses that are described
name|UnwindIndex
argument_list|()
operator|:
name|function_offset
argument_list|(
literal|0
argument_list|)
operator|,
name|second_level
argument_list|(
literal|0
argument_list|)
operator|,
name|lsda_array_start
argument_list|(
literal|0
argument_list|)
operator|,
name|lsda_array_end
argument_list|(
literal|0
argument_list|)
operator|,
name|sentinal_entry
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CompactUnwindInfo
operator|::
name|UnwindIndex
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|function_offset
operator|<
name|rhs
operator|.
name|function_offset
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CompactUnwindInfo
operator|::
name|UnwindIndex
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|function_offset
operator|==
name|rhs
operator|.
name|function_offset
return|;
block|}
block|}
struct|;
comment|// An internal object used to store the information we retrieve about a
comment|// function --
comment|// the encoding bits and possibly the LSDA/personality function.
struct|struct
name|FunctionInfo
block|{
name|uint32_t
name|encoding
decl_stmt|;
comment|// compact encoding 32-bit value for this function
name|Address
name|lsda_address
decl_stmt|;
comment|// the address of the LSDA data for this function
name|Address
name|personality_ptr_address
decl_stmt|;
comment|// the address where the personality
comment|// routine addr can be found
name|uint32_t
name|valid_range_offset_start
decl_stmt|;
comment|// first offset that this encoding is
comment|// valid for (start of the function)
name|uint32_t
name|valid_range_offset_end
decl_stmt|;
comment|// the offset of the start of the next function
name|FunctionInfo
argument_list|()
operator|:
name|encoding
argument_list|(
literal|0
argument_list|)
operator|,
name|lsda_address
argument_list|()
operator|,
name|personality_ptr_address
argument_list|()
operator|,
name|valid_range_offset_start
argument_list|(
literal|0
argument_list|)
operator|,
name|valid_range_offset_end
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|UnwindHeader
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|common_encodings_array_offset
decl_stmt|;
name|uint32_t
name|common_encodings_array_count
decl_stmt|;
name|uint32_t
name|personality_array_offset
decl_stmt|;
name|uint32_t
name|personality_array_count
decl_stmt|;
name|UnwindHeader
argument_list|()
operator|:
name|common_encodings_array_offset
argument_list|(
literal|0
argument_list|)
operator|,
name|common_encodings_array_count
argument_list|(
literal|0
argument_list|)
operator|,
name|personality_array_offset
argument_list|(
literal|0
argument_list|)
operator|,
name|personality_array_count
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
name|void
name|ScanIndex
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
name|bool
name|GetCompactUnwindInfoForFunction
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|Address
name|address
parameter_list|,
name|FunctionInfo
modifier|&
name|unwind_info
parameter_list|)
function_decl|;
name|lldb
operator|::
name|offset_t
name|BinarySearchRegularSecondPage
argument_list|(
argument|uint32_t entry_page_offset
argument_list|,
argument|uint32_t entry_count
argument_list|,
argument|uint32_t function_offset
argument_list|,
argument|uint32_t *entry_func_start_offset
argument_list|,
argument|uint32_t *entry_func_end_offset
argument_list|)
expr_stmt|;
name|uint32_t
name|BinarySearchCompressedSecondPage
parameter_list|(
name|uint32_t
name|entry_page_offset
parameter_list|,
name|uint32_t
name|entry_count
parameter_list|,
name|uint32_t
name|function_offset_to_find
parameter_list|,
name|uint32_t
name|function_offset_base
parameter_list|,
name|uint32_t
modifier|*
name|entry_func_start_offset
parameter_list|,
name|uint32_t
modifier|*
name|entry_func_end_offset
parameter_list|)
function_decl|;
name|uint32_t
name|GetLSDAForFunctionOffset
parameter_list|(
name|uint32_t
name|lsda_offset
parameter_list|,
name|uint32_t
name|lsda_count
parameter_list|,
name|uint32_t
name|function_offset
parameter_list|)
function_decl|;
name|bool
name|CreateUnwindPlan_x86_64
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|FunctionInfo
modifier|&
name|function_info
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|,
name|Address
name|pc_or_function_start
parameter_list|)
function_decl|;
name|bool
name|CreateUnwindPlan_i386
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|FunctionInfo
modifier|&
name|function_info
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|,
name|Address
name|pc_or_function_start
parameter_list|)
function_decl|;
name|bool
name|CreateUnwindPlan_arm64
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|FunctionInfo
modifier|&
name|function_info
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|,
name|Address
name|pc_or_function_start
parameter_list|)
function_decl|;
name|bool
name|CreateUnwindPlan_armv7
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|FunctionInfo
modifier|&
name|function_info
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|,
name|Address
name|pc_or_function_start
parameter_list|)
function_decl|;
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
name|DataBufferSP
name|m_section_contents_if_encrypted
expr_stmt|;
comment|// if the binary is
comment|// encrypted, read the
comment|// sect contents
comment|// out of live memory and cache them here
name|std
operator|::
name|mutex
name|m_mutex
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|UnwindIndex
operator|>
name|m_indexes
expr_stmt|;
name|LazyBool
name|m_indexes_computed
decl_stmt|;
comment|// eLazyBoolYes once we've tried to parse the
comment|// unwind info
comment|// eLazyBoolNo means we cannot parse the unwind info& should not retry
comment|// eLazyBoolCalculate means we haven't tried to parse it yet
name|DataExtractor
name|m_unwindinfo_data
decl_stmt|;
name|bool
name|m_unwindinfo_data_computed
decl_stmt|;
comment|// true once we've mapped in the unwindinfo
comment|// data
name|UnwindHeader
name|m_unwind_header
decl_stmt|;
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
comment|// liblldb_CompactUnwindInfo_h_
end_comment

end_unit

