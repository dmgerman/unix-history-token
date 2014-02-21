begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBFileSpecList.h --------------------------------------------*- C++ -*-===//
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
name|LLDB_SBFileSpecList_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBFileSpecList_h_
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
name|SBFileSpecList
block|{
name|public
label|:
name|SBFileSpecList
argument_list|()
expr_stmt|;
name|SBFileSpecList
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpecList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBFileSpecList
argument_list|()
expr_stmt|;
specifier|const
name|SBFileSpecList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|lldb
operator|::
name|SBFileSpecList
operator|&
name|rhs
operator|)
decl_stmt|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|SBStream
operator|&
name|description
argument_list|)
decl|const
decl_stmt|;
name|void
name|Append
parameter_list|(
specifier|const
name|SBFileSpec
modifier|&
name|sb_file
parameter_list|)
function_decl|;
name|bool
name|AppendIfUnique
parameter_list|(
specifier|const
name|SBFileSpec
modifier|&
name|sb_file
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|uint32_t
name|FindFileIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|,
specifier|const
name|SBFileSpec
modifier|&
name|sb_file
parameter_list|,
name|bool
name|full
parameter_list|)
function_decl|;
specifier|const
name|SBFileSpec
name|GetFileSpecAtIndex
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|friend
name|class
name|SBTarget
decl_stmt|;
specifier|const
name|lldb_private
operator|::
name|FileSpecList
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
name|FileSpecList
operator|*
name|get
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|ref
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|FileSpecList
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
comment|// LLDB_SBFileSpecList_h_
end_comment

end_unit

