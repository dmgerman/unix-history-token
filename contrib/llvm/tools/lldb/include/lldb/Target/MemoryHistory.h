begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MemoryHistory.h ---------------------------------------------------*- C++ -*-===//
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
name|liblldb_MemoryHistory_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_MemoryHistory_h_
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

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ThreadSP
operator|>
name|HistoryThreads
expr_stmt|;
name|class
name|MemoryHistory
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|MemoryHistory
operator|>
decl_stmt|,
name|public
name|PluginInterface
block|{
name|public
label|:
specifier|static
name|lldb
operator|::
name|MemoryHistorySP
name|FindPlugin
argument_list|(
argument|const lldb::ProcessSP process
argument_list|)
expr_stmt|;
name|virtual
name|HistoryThreads
name|GetHistoryThreads
argument_list|(
name|lldb
operator|::
name|addr_t
name|address
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
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
comment|// liblldb_MemoryHistory_h_
end_comment

end_unit

