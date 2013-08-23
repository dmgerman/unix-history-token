begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDIECollection.h ------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDIECollection_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDIECollection_h_
end_define

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|class
name|DWARFDIECollection
block|{
name|public
label|:
name|DWARFDIECollection
argument_list|()
operator|:
name|m_dies
argument_list|()
block|{     }
operator|~
name|DWARFDIECollection
argument_list|()
block|{     }
name|void
name|Append
argument_list|(
specifier|const
name|DWARFDebugInfoEntry
operator|*
name|die
argument_list|)
expr_stmt|;
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|title
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|DWARFDebugInfoEntry
modifier|*
name|GetDIEPtrAtIndex
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
decl_stmt|;
name|bool
name|Insert
parameter_list|(
specifier|const
name|DWARFDebugInfoEntry
modifier|*
name|die
parameter_list|)
function_decl|;
name|size_t
name|Size
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|DWARFDebugInfoEntry
operator|*
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
name|m_dies
decl_stmt|;
comment|// Ordered list of die offsets
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
comment|// SymbolFileDWARF_DWARFDIECollection_h_
end_comment

end_unit

