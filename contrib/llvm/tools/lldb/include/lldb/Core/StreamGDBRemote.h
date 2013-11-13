begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StreamGDBRemote.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_StreamGDBRemote_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StreamGDBRemote_h_
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
file|"lldb/Core/StreamString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StreamGDBRemote
range|:
name|public
name|StreamString
block|{
name|public
operator|:
name|StreamGDBRemote
argument_list|()
block|;
name|StreamGDBRemote
argument_list|(
argument|uint32_t flags
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
block|;
name|virtual
operator|~
name|StreamGDBRemote
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Output a block of data to the stream performing GDB-remote escaping.
comment|///
comment|/// @param[in] s
comment|///     A block of data.
comment|///
comment|/// @param[in] src_len
comment|///     The amount of data to write.
comment|///
comment|/// @return
comment|///     Number of bytes written.
comment|//------------------------------------------------------------------
name|int
name|PutEscapedBytes
argument_list|(
argument|const void* s
argument_list|,
argument|size_t src_len
argument_list|)
block|;     }
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
comment|// liblldb_StreamGDBRemote_h_
end_comment

end_unit

