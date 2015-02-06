begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MemoryHistoryASan.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_MemoryHistoryASan_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_MemoryHistoryASan_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

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
file|"lldb/Target/ABI.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/MemoryHistory.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|MemoryHistoryASan
range|:
name|public
name|lldb_private
operator|::
name|MemoryHistory
block|{
name|public
operator|:
specifier|static
name|lldb
operator|::
name|MemoryHistorySP
name|CreateInstance
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
name|virtual
operator|~
name|MemoryHistoryASan
argument_list|()
block|{}
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|{
return|return
name|GetPluginNameStatic
argument_list|()
return|;
block|}
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|{
return|return
literal|1
return|;
block|}
name|virtual
name|lldb_private
operator|::
name|HistoryThreads
name|GetHistoryThreads
argument_list|(
argument|lldb::addr_t address
argument_list|)
block|;
name|private
operator|:
name|MemoryHistoryASan
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
block|;
name|lldb
operator|::
name|ProcessSP
name|m_process_sp
block|;      }
decl_stmt|;
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
comment|// liblldb_MemoryHistoryASan_h_
end_comment

end_unit

