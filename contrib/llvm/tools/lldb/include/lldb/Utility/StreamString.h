begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StreamString.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_StreamString_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StreamString_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_comment
comment|// for Stream
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for ByteOrder
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// for string
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StreamString
range|:
name|public
name|Stream
block|{
name|public
operator|:
name|StreamString
argument_list|()
block|;
name|StreamString
argument_list|(
argument|uint32_t flags
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
block|;
operator|~
name|StreamString
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
argument|const void *s
argument_list|,
argument|size_t length
argument_list|)
name|override
block|;
name|void
name|Clear
argument_list|()
block|;
name|bool
name|Empty
argument_list|()
specifier|const
block|;
name|size_t
name|GetSize
argument_list|()
specifier|const
block|;
name|size_t
name|GetSizeOfLastLine
argument_list|()
specifier|const
block|;
name|llvm
operator|::
name|StringRef
name|GetString
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetData
argument_list|()
specifier|const
block|{
return|return
name|m_packet
operator|.
name|c_str
argument_list|()
return|;
block|}
name|void
name|FillLastLineToColumn
argument_list|(
argument|uint32_t column
argument_list|,
argument|char fill_char
argument_list|)
block|;
name|protected
operator|:
name|std
operator|::
name|string
name|m_packet
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
comment|// liblldb_StreamString_h_
end_comment

end_unit

