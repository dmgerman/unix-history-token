begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugPubnames.h ------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDebugPubnames_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDebugPubnames_h_
end_define

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|"DWARFDebugPubnamesSet.h"
end_include

begin_decl_stmt
name|class
name|DWARFDebugPubnames
block|{
name|public
label|:
name|DWARFDebugPubnames
argument_list|()
expr_stmt|;
name|bool
name|Extract
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|data
argument_list|)
decl_stmt|;
name|bool
name|GeneratePubnames
parameter_list|(
name|SymbolFileDWARF
modifier|*
name|dwarf2Data
parameter_list|)
function_decl|;
name|bool
name|GeneratePubBaseTypes
parameter_list|(
name|SymbolFileDWARF
modifier|*
name|dwarf2Data
parameter_list|)
function_decl|;
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
name|bool
name|Find
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|bool
name|ignore_case
argument_list|,
name|std
operator|::
name|vector
operator|<
name|dw_offset_t
operator|>
operator|&
name|die_offset_coll
argument_list|)
decl|const
decl_stmt|;
name|bool
name|Find
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegularExpression
operator|&
name|regex
argument_list|,
name|std
operator|::
name|vector
operator|<
name|dw_offset_t
operator|>
operator|&
name|die_offsets
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|list
operator|<
name|DWARFDebugPubnamesSet
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|collection
name|m_sets
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
comment|// SymbolFileDWARF_DWARFDebugPubnames_h_
end_comment

end_unit

