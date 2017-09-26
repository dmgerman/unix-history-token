begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- VectorIterator.h ----------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_VectorIterator_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_VectorIterator_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|formatters
block|{
name|class
name|VectorIteratorSyntheticFrontEnd
range|:
name|public
name|SyntheticChildrenFrontEnd
block|{
name|public
operator|:
name|VectorIteratorSyntheticFrontEnd
argument_list|(
argument|lldb::ValueObjectSP valobj_sp
argument_list|,
argument|ConstString item_name
argument_list|)
block|;
name|size_t
name|CalculateNumChildren
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndex
argument_list|(
argument|size_t idx
argument_list|)
name|override
block|;
name|bool
name|Update
argument_list|()
name|override
block|;
name|bool
name|MightHaveChildren
argument_list|()
name|override
block|;
name|size_t
name|GetIndexOfChildWithName
argument_list|(
argument|const ConstString&name
argument_list|)
name|override
block|;
name|private
operator|:
name|ExecutionContextRef
name|m_exe_ctx_ref
block|;
name|ConstString
name|m_item_name
block|;
name|lldb
operator|::
name|ValueObjectSP
name|m_item_sp
block|; }
decl_stmt|;
block|}
comment|// namespace formatters
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CF_h_
end_comment

end_unit

