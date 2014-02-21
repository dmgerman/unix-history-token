begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugAbbrev.h --------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDebugAbbrev_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDebugAbbrev_h_
end_define

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_include
include|#
directive|include
file|"DWARFAbbreviationDeclaration.h"
end_include

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DWARFAbbreviationDeclaration
operator|>
name|DWARFAbbreviationDeclarationColl
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DWARFAbbreviationDeclarationColl
operator|::
name|iterator
name|DWARFAbbreviationDeclarationCollIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DWARFAbbreviationDeclarationColl
operator|::
name|const_iterator
name|DWARFAbbreviationDeclarationCollConstIter
expr_stmt|;
end_typedef

begin_decl_stmt
name|class
name|DWARFAbbreviationDeclarationSet
block|{
name|public
label|:
name|DWARFAbbreviationDeclarationSet
argument_list|()
operator|:
name|m_offset
argument_list|(
name|DW_INVALID_OFFSET
argument_list|)
operator|,
name|m_idx_offset
argument_list|(
literal|0
argument_list|)
operator|,
name|m_decls
argument_list|()
block|{         }
name|DWARFAbbreviationDeclarationSet
argument_list|(
argument|dw_offset_t offset
argument_list|,
argument|uint32_t idx_offset
argument_list|)
operator|:
name|m_offset
argument_list|(
name|offset
argument_list|)
operator|,
name|m_idx_offset
argument_list|(
name|idx_offset
argument_list|)
operator|,
name|m_decls
argument_list|()
block|{         }
name|void
name|Clear
argument_list|()
expr_stmt|;
name|dw_offset_t
name|GetOffset
argument_list|()
specifier|const
block|{
return|return
name|m_offset
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
name|bool
name|Extract
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl_stmt|;
comment|//void Encode(BinaryStreamBuf& debug_abbrev_buf) const;
name|dw_uleb128_t
name|AppendAbbrevDeclSequential
parameter_list|(
specifier|const
name|DWARFAbbreviationDeclaration
modifier|&
name|abbrevDecl
parameter_list|)
function_decl|;
specifier|const
name|DWARFAbbreviationDeclaration
modifier|*
name|GetAbbreviationDeclaration
argument_list|(
name|dw_uleb128_t
name|abbrCode
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|dw_offset_t
name|m_offset
decl_stmt|;
name|uint32_t
name|m_idx_offset
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|DWARFAbbreviationDeclaration
operator|>
name|m_decls
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|dw_offset_t
operator|,
name|DWARFAbbreviationDeclarationSet
operator|>
name|DWARFAbbreviationDeclarationCollMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DWARFAbbreviationDeclarationCollMap
operator|::
name|iterator
name|DWARFAbbreviationDeclarationCollMapIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DWARFAbbreviationDeclarationCollMap
operator|::
name|const_iterator
name|DWARFAbbreviationDeclarationCollMapConstIter
expr_stmt|;
end_typedef

begin_decl_stmt
name|class
name|DWARFDebugAbbrev
block|{
name|public
label|:
name|DWARFDebugAbbrev
argument_list|()
expr_stmt|;
specifier|const
name|DWARFAbbreviationDeclarationSet
modifier|*
name|GetAbbreviationDeclarationSet
argument_list|(
name|dw_offset_t
name|cu_abbr_offset
argument_list|)
decl|const
decl_stmt|;
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
name|void
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|data
argument_list|)
decl_stmt|;
name|protected
label|:
name|DWARFAbbreviationDeclarationCollMap
name|m_abbrevCollMap
decl_stmt|;
name|mutable
name|DWARFAbbreviationDeclarationCollMapConstIter
name|m_prev_abbr_offset_pos
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
comment|// SymbolFileDWARF_DWARFDebugAbbrev_h_
end_comment

end_unit

