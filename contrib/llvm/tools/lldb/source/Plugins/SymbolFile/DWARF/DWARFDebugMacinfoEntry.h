begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugMacinfoEntry.h --------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDebugMacinfoEntry_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDebugMacinfoEntry_h_
end_define

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_decl_stmt
name|class
name|DWARFDebugMacinfoEntry
block|{
name|public
label|:
name|DWARFDebugMacinfoEntry
argument_list|()
expr_stmt|;
operator|~
name|DWARFDebugMacinfoEntry
argument_list|()
expr_stmt|;
name|uint8_t
name|TypeCode
argument_list|()
specifier|const
block|{
return|return
name|m_type_code
return|;
block|}
name|uint8_t
name|GetLineNumber
argument_list|()
specifier|const
block|{
return|return
name|m_line
return|;
block|}
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|char
operator|*
name|GetCString
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|Extract
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|mac_info_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl_stmt|;
name|protected
label|:
name|private
label|:
name|uint8_t
name|m_type_code
decl_stmt|;
name|dw_uleb128_t
name|m_line
decl_stmt|;
union|union
block|{
name|dw_uleb128_t
name|file_idx
decl_stmt|;
specifier|const
name|char
modifier|*
name|cstr
decl_stmt|;
block|}
name|m_op2
union|;
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
comment|// SymbolFileDWARF_DWARFDebugMacinfoEntry_h_
end_comment

end_unit

