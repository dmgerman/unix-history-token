begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugRanges.h --------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDebugRanges_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDebugRanges_h_
end_define

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_include
include|#
directive|include
file|<map>
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

begin_decl_stmt
name|class
name|DWARFDebugRanges
block|{
name|public
label|:
typedef|typedef
name|lldb_private
operator|::
name|RangeArray
operator|<
name|dw_addr_t
operator|,
name|dw_addr_t
operator|,
literal|2
operator|>
name|RangeList
expr_stmt|;
typedef|typedef
name|RangeList
operator|::
name|Entry
name|Range
expr_stmt|;
name|DWARFDebugRanges
argument_list|()
expr_stmt|;
operator|~
name|DWARFDebugRanges
argument_list|()
expr_stmt|;
name|void
name|Extract
parameter_list|(
name|SymbolFileDWARF
modifier|*
name|dwarf2Data
parameter_list|)
function_decl|;
specifier|static
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_ranges_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|dw_addr_t
name|cu_base_addr
argument_list|)
decl_stmt|;
name|bool
name|FindRanges
argument_list|(
name|dw_offset_t
name|debug_ranges_offset
argument_list|,
name|DWARFDebugRanges
operator|::
name|RangeList
operator|&
name|range_list
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|bool
name|Extract
argument_list|(
name|SymbolFileDWARF
operator|*
name|dwarf2Data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|RangeList
operator|&
name|range_list
argument_list|)
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|dw_offset_t
operator|,
name|RangeList
operator|>
name|range_map
expr_stmt|;
typedef|typedef
name|range_map
operator|::
name|iterator
name|range_map_iterator
expr_stmt|;
typedef|typedef
name|range_map
operator|::
name|const_iterator
name|range_map_const_iterator
expr_stmt|;
name|range_map
name|m_range_map
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFDebugRanges_h_
end_comment

end_unit

