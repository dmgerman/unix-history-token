begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UniqueDWARFASTType.h ------------------------------------*- C++ -*-===//
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
name|lldb_UniqueDWARFASTType_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_UniqueDWARFASTType_h_
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
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Symbol/Declaration.h"
end_include

begin_decl_stmt
name|class
name|DWARFCompileUnit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFDebugInfoEntry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|SymbolFileDWARF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|UniqueDWARFASTType
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|UniqueDWARFASTType
argument_list|()
operator|:
name|m_type_sp
argument_list|()
operator|,
name|m_symfile
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_cu
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_die
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_declaration
argument_list|()
operator|,
name|m_byte_size
argument_list|(
argument|-
literal|1
argument_list|)
comment|// Set to negative value to make sure we have a valid value
block|{     }
name|UniqueDWARFASTType
argument_list|(
argument|lldb::TypeSP&type_sp
argument_list|,
argument|SymbolFileDWARF *symfile
argument_list|,
argument|DWARFCompileUnit *cu
argument_list|,
argument|DWARFDebugInfoEntry *die
argument_list|,
argument|const lldb_private::Declaration&decl
argument_list|,
argument|int32_t byte_size
argument_list|)
operator|:
name|m_type_sp
argument_list|(
name|type_sp
argument_list|)
operator|,
name|m_symfile
argument_list|(
name|symfile
argument_list|)
operator|,
name|m_cu
argument_list|(
name|cu
argument_list|)
operator|,
name|m_die
argument_list|(
name|die
argument_list|)
operator|,
name|m_declaration
argument_list|(
name|decl
argument_list|)
operator|,
name|m_byte_size
argument_list|(
argument|byte_size
argument_list|)
block|{     }
name|UniqueDWARFASTType
argument_list|(
specifier|const
name|UniqueDWARFASTType
operator|&
name|rhs
argument_list|)
operator|:
name|m_type_sp
argument_list|(
name|rhs
operator|.
name|m_type_sp
argument_list|)
operator|,
name|m_symfile
argument_list|(
name|rhs
operator|.
name|m_symfile
argument_list|)
operator|,
name|m_cu
argument_list|(
name|rhs
operator|.
name|m_cu
argument_list|)
operator|,
name|m_die
argument_list|(
name|rhs
operator|.
name|m_die
argument_list|)
operator|,
name|m_declaration
argument_list|(
name|rhs
operator|.
name|m_declaration
argument_list|)
operator|,
name|m_byte_size
argument_list|(
argument|rhs.m_byte_size
argument_list|)
block|{     }
operator|~
name|UniqueDWARFASTType
argument_list|()
block|{     }
name|UniqueDWARFASTType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|UniqueDWARFASTType
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
block|{
name|m_type_sp
operator|=
name|rhs
operator|.
name|m_type_sp
expr_stmt|;
name|m_symfile
operator|=
name|rhs
operator|.
name|m_symfile
expr_stmt|;
name|m_cu
operator|=
name|rhs
operator|.
name|m_cu
expr_stmt|;
name|m_die
operator|=
name|rhs
operator|.
name|m_die
expr_stmt|;
name|m_declaration
operator|=
name|rhs
operator|.
name|m_declaration
expr_stmt|;
name|m_byte_size
operator|=
name|rhs
operator|.
name|m_byte_size
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|lldb
operator|::
name|TypeSP
name|m_type_sp
expr_stmt|;
name|SymbolFileDWARF
modifier|*
name|m_symfile
decl_stmt|;
specifier|const
name|DWARFCompileUnit
modifier|*
name|m_cu
decl_stmt|;
specifier|const
name|DWARFDebugInfoEntry
modifier|*
name|m_die
decl_stmt|;
name|lldb_private
operator|::
name|Declaration
name|m_declaration
expr_stmt|;
name|int32_t
name|m_byte_size
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|UniqueDWARFASTTypeList
block|{
name|public
label|:
name|UniqueDWARFASTTypeList
argument_list|()
operator|:
name|m_collection
argument_list|()
block|{     }
operator|~
name|UniqueDWARFASTTypeList
argument_list|()
block|{     }
name|uint32_t
name|GetSize
argument_list|()
block|{
return|return
operator|(
name|uint32_t
operator|)
name|m_collection
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|Append
parameter_list|(
specifier|const
name|UniqueDWARFASTType
modifier|&
name|entry
parameter_list|)
block|{
name|m_collection
operator|.
name|push_back
argument_list|(
name|entry
argument_list|)
expr_stmt|;
block|}
name|bool
name|Find
argument_list|(
name|SymbolFileDWARF
operator|*
name|symfile
argument_list|,
specifier|const
name|DWARFCompileUnit
operator|*
name|cu
argument_list|,
specifier|const
name|DWARFDebugInfoEntry
operator|*
name|die
argument_list|,
specifier|const
name|lldb_private
operator|::
name|Declaration
operator|&
name|decl
argument_list|,
specifier|const
name|int32_t
name|byte_size
argument_list|,
name|UniqueDWARFASTType
operator|&
name|entry
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|UniqueDWARFASTType
operator|>
name|collection
expr_stmt|;
name|collection
name|m_collection
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|UniqueDWARFASTTypeMap
block|{
name|public
label|:
name|UniqueDWARFASTTypeMap
argument_list|()
operator|:
name|m_collection
argument_list|()
block|{     }
operator|~
name|UniqueDWARFASTTypeMap
argument_list|()
block|{     }
name|void
name|Insert
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|,
argument|const UniqueDWARFASTType&entry
argument_list|)
block|{
name|m_collection
index|[
name|name
operator|.
name|GetCString
argument_list|()
index|]
operator|.
name|Append
argument_list|(
name|entry
argument_list|)
block|;     }
name|bool
name|Find
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|,
argument|SymbolFileDWARF *symfile
argument_list|,
argument|const DWARFCompileUnit *cu
argument_list|,
argument|const DWARFDebugInfoEntry *die
argument_list|,
argument|const lldb_private::Declaration&decl
argument_list|,
argument|const int32_t byte_size
argument_list|,
argument|UniqueDWARFASTType&entry
argument_list|)
specifier|const
block|{
specifier|const
name|char
operator|*
name|unique_name_cstr
operator|=
name|name
operator|.
name|GetCString
argument_list|()
block|;
name|collection
operator|::
name|const_iterator
name|pos
operator|=
name|m_collection
operator|.
name|find
argument_list|(
name|unique_name_cstr
argument_list|)
block|;
if|if
condition|(
name|pos
operator|!=
name|m_collection
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|pos
operator|->
name|second
operator|.
name|Find
argument_list|(
name|symfile
argument_list|,
name|cu
argument_list|,
name|die
argument_list|,
name|decl
argument_list|,
name|byte_size
argument_list|,
name|entry
argument_list|)
return|;
block|}
return|return
name|false
return|;
block|}
name|protected
label|:
comment|// A unique name string should be used
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|char
operator|*
operator|,
name|UniqueDWARFASTTypeList
operator|>
name|collection
expr_stmt|;
name|collection
name|m_collection
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
comment|// lldb_UniqueDWARFASTType_h_
end_comment

end_unit

