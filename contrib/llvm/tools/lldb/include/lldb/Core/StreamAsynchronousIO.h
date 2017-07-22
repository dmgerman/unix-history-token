begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StreamAsynchronousIO.h -----------------------------------*- C++-*-===//
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
name|liblldb_StreamAsynchronousIO_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StreamAsynchronousIO_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Debugger
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StreamAsynchronousIO
range|:
name|public
name|Stream
block|{
name|public
operator|:
name|StreamAsynchronousIO
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|bool for_stdout
argument_list|)
block|;
operator|~
name|StreamAsynchronousIO
argument_list|()
name|override
block|;
name|void
name|Flush
argument_list|()
name|override
block|;
name|size_t
name|Write
argument_list|(
argument|const void *src
argument_list|,
argument|size_t src_len
argument_list|)
name|override
block|;
name|private
operator|:
name|Debugger
operator|&
name|m_debugger
block|;
name|std
operator|::
name|string
name|m_data
block|;
name|bool
name|m_for_stdout
block|; }
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
comment|// liblldb_StreamAsynchronousIO_h
end_comment

end_unit

