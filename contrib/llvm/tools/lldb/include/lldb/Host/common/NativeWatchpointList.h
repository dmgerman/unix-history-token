begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeWatchpointList.h ----------------------------------*- C++ -*-===//
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
name|liblldb_NativeWatchpointList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeWatchpointList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
struct|struct
name|NativeWatchpoint
block|{
name|lldb
operator|::
name|addr_t
name|m_addr
expr_stmt|;
name|size_t
name|m_size
decl_stmt|;
name|uint32_t
name|m_watch_flags
decl_stmt|;
name|bool
name|m_hardware
decl_stmt|;
block|}
struct|;
name|class
name|NativeWatchpointList
block|{
name|public
label|:
name|Status
name|Add
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size
argument_list|,
name|uint32_t
name|watch_flags
argument_list|,
name|bool
name|hardware
argument_list|)
decl_stmt|;
name|Status
name|Remove
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
name|using
name|WatchpointMap
init|=
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
decl_stmt|,
name|NativeWatchpoint
decl|>
decl_stmt|;
specifier|const
name|WatchpointMap
operator|&
name|GetWatchpointMap
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|WatchpointMap
name|m_watchpoints
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ifndef liblldb_NativeWatchpointList_h_
end_comment

end_unit

