begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDeclContext.h --------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDeclContext_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDeclContext_h_
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
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// DWARFDeclContext
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A class that represents a declaration context all the way down to a
end_comment

begin_comment
comment|// DIE. This is useful when trying to find a DIE in one DWARF to a DIE
end_comment

begin_comment
comment|// in another DWARF file.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|DWARFDeclContext
block|{
name|public
label|:
struct|struct
name|Entry
block|{
name|Entry
argument_list|()
operator|:
name|tag
argument_list|(
literal|0
argument_list|)
operator|,
name|name
argument_list|(
argument|NULL
argument_list|)
block|{}
name|Entry
argument_list|(
argument|dw_tag_t t
argument_list|,
argument|const char *n
argument_list|)
operator|:
name|tag
argument_list|(
name|t
argument_list|)
operator|,
name|name
argument_list|(
argument|n
argument_list|)
block|{}
name|bool
name|NameMatches
argument_list|(
argument|const Entry&rhs
argument_list|)
specifier|const
block|{
if|if
condition|(
name|name
operator|==
name|rhs
operator|.
name|name
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|name
operator|&&
name|rhs
operator|.
name|name
condition|)
return|return
name|strcmp
argument_list|(
name|name
argument_list|,
name|rhs
operator|.
name|name
argument_list|)
operator|==
literal|0
return|;
return|return
name|false
return|;
block|}
comment|// Test operator
name|explicit
name|operator
name|bool
argument_list|()
decl|const
block|{
return|return
name|tag
operator|!=
literal|0
return|;
block|}
name|dw_tag_t
name|tag
struct|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DWARFDeclContext
argument_list|()
operator|:
name|m_entries
argument_list|()
operator|,
name|m_language
argument_list|(
argument|lldb::eLanguageTypeUnknown
argument_list|)
block|{}
name|void
name|AppendDeclContext
argument_list|(
argument|dw_tag_t tag
argument_list|,
argument|const char *name
argument_list|)
block|{
name|m_entries
operator|.
name|push_back
argument_list|(
name|Entry
argument_list|(
name|tag
argument_list|,
name|name
argument_list|)
argument_list|)
block|;   }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DWARFDeclContext
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_entries
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|Entry
modifier|&
name|operator
function|[]
parameter_list|(
name|uint32_t
name|idx
parameter_list|)
block|{
comment|// "idx" must be valid
return|return
name|m_entries
index|[
name|idx
index|]
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|Entry
modifier|&
name|operator
index|[]
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
block|{
comment|// "idx" must be valid
return|return
name|m_entries
index|[
name|idx
index|]
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|GetQualifiedName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Same as GetQaulifiedName, but the life time of the returned string will
end_comment

begin_comment
comment|// be that of the LLDB session.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|ConstString
name|GetQualifiedNameAsConstString
argument_list|()
specifier|const
block|{
return|return
name|lldb_private
operator|::
name|ConstString
argument_list|(
name|GetQualifiedName
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|Clear
parameter_list|()
block|{
name|m_entries
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_qualified_name
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
block|{
return|return
name|m_language
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|SetLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
block|{
name|m_language
operator|=
name|language
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|collection
expr_stmt|;
end_typedef

begin_decl_stmt
name|collection
name|m_entries
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|mutable
name|std
operator|::
name|string
name|m_qualified_name
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|LanguageType
name|m_language
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFDeclContext_h_
end_comment

end_unit

