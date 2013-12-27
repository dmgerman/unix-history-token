begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StreamCallback.h -----------------------------------*- C++ -*-===//
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
name|liblldb_StreamCallback_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StreamCallback_h_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StreamCallback
range|:
name|public
name|Stream
block|{
name|public
operator|:
name|StreamCallback
argument_list|(
argument|lldb::LogOutputCallback callback
argument_list|,
argument|void *baton
argument_list|)
block|;
name|virtual
operator|~
name|StreamCallback
argument_list|()
block|;
name|virtual
name|void
name|Flush
argument_list|()
block|;
name|virtual
name|size_t
name|Write
argument_list|(
argument|const void *src
argument_list|,
argument|size_t src_len
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|tid_t
operator|,
name|StreamString
operator|>
name|collection
expr_stmt|;
name|lldb
operator|::
name|LogOutputCallback
name|m_callback
decl_stmt|;
name|void
modifier|*
name|m_baton
decl_stmt|;
name|collection
name|m_accumulated_data
decl_stmt|;
name|Mutex
name|m_collection_mutex
decl_stmt|;
name|StreamString
modifier|&
name|FindStreamForThread
argument_list|(
name|lldb
operator|::
name|tid_t
name|cur_tid
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_StreamCallback_h
end_comment

end_unit

