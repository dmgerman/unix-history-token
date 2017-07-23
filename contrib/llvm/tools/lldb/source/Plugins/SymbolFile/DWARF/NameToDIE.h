begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NameToDIE.h ---------------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_NameToDIE_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_NameToDIE_h_
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|"DIERef.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UniqueCStringMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/dwarf.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_decl_stmt
name|class
name|SymbolFileDWARF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|NameToDIE
block|{
name|public
label|:
name|NameToDIE
argument_list|()
operator|:
name|m_map
argument_list|()
block|{}
operator|~
name|NameToDIE
argument_list|()
block|{}
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|)
expr_stmt|;
name|void
name|Insert
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|name
argument_list|,
specifier|const
name|DIERef
operator|&
name|die_ref
argument_list|)
decl_stmt|;
name|void
name|Append
parameter_list|(
specifier|const
name|NameToDIE
modifier|&
name|other
parameter_list|)
function_decl|;
name|void
name|Finalize
parameter_list|()
function_decl|;
name|size_t
name|Find
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|name
argument_list|,
name|DIEArray
operator|&
name|info_array
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|Find
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegularExpression
operator|&
name|regex
argument_list|,
name|DIEArray
operator|&
name|info_array
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|FindAllEntriesForCompileUnit
argument_list|(
name|dw_offset_t
name|cu_offset
argument_list|,
name|DIEArray
operator|&
name|info_array
argument_list|)
decl|const
decl_stmt|;
name|void
name|ForEach
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|lldb_private::ConstString name
argument_list|,
argument|const DIERef&die_ref
argument_list|)
operator|>
specifier|const
operator|&
name|callback
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|lldb_private
operator|::
name|UniqueCStringMap
operator|<
name|DIERef
operator|>
name|m_map
expr_stmt|;
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
comment|// SymbolFileDWARF_NameToDIE_h_
end_comment

end_unit

