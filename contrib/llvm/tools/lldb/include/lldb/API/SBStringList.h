begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBStringList.h ------------------------------------------*- C++ -*-===//
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
name|LLDB_SBStringList_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBStringList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBStringList
block|{
name|public
label|:
name|SBStringList
argument_list|()
expr_stmt|;
name|SBStringList
argument_list|(
specifier|const
name|lldb
operator|::
name|SBStringList
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|SBStringList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBStringList
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|SBStringList
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|AppendString
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|void
name|AppendList
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|strv
parameter_list|,
name|int
name|strc
parameter_list|)
function_decl|;
name|void
name|AppendList
argument_list|(
specifier|const
name|lldb
operator|::
name|SBStringList
operator|&
name|strings
argument_list|)
decl_stmt|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetStringAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|protected
label|:
name|friend
name|class
name|SBCommandInterpreter
decl_stmt|;
name|friend
name|class
name|SBDebugger
decl_stmt|;
name|SBStringList
argument_list|(
specifier|const
name|lldb_private
operator|::
name|StringList
operator|*
name|lldb_strings
argument_list|)
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|StringList
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
specifier|const
name|lldb_private
operator|::
name|StringList
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
name|StringList
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
comment|// LLDB_SBStringList_h_
end_comment

end_unit

