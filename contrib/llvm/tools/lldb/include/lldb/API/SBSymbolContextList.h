begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBSymbolContextList.h -----------------------------------*- C++ -*-===//
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
name|LLDB_SBSymbolContextList_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBSymbolContextList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBSymbolContext.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBSymbolContextList
block|{
name|public
label|:
name|SBSymbolContextList
argument_list|()
expr_stmt|;
name|SBSymbolContextList
argument_list|(
specifier|const
name|lldb
operator|::
name|SBSymbolContextList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBSymbolContextList
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBSymbolContextList
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBSymbolContextList
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBSymbolContext
name|GetContextAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|void
name|Append
argument_list|(
name|lldb
operator|::
name|SBSymbolContext
operator|&
name|sc
argument_list|)
decl_stmt|;
name|void
name|Append
argument_list|(
name|lldb
operator|::
name|SBSymbolContextList
operator|&
name|sc_list
argument_list|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|protected
label|:
name|friend
name|class
name|SBModule
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|lldb_private
operator|::
name|SymbolContextList
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
name|lldb_private
operator|::
name|SymbolContextList
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|SymbolContextList
operator|>
name|m_opaque_ap
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBSymbolContextList_h_
end_comment

end_unit

