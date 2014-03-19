begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFLocationList.h -------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFLocationList_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFLocationList_h_
end_define

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_decl_stmt
name|class
name|DWARFLocationList
block|{
name|public
label|:
specifier|static
name|dw_offset_t
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|DWARFCompileUnit
operator|*
name|cu
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_loc_data
argument_list|,
name|lldb
operator|::
name|offset_t
name|offset
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|Extract
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_loc_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|location_list_data
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|Size
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_loc_data
argument_list|,
name|lldb
operator|::
name|offset_t
name|offset
argument_list|)
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
comment|// SymbolFileDWARF_DWARFLocationList_h_
end_comment

end_unit

