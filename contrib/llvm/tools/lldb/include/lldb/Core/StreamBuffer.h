begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StreamBuffer.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_StreamBuffer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StreamBuffer_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|template
operator|<
name|unsigned
name|N
operator|>
name|class
name|StreamBuffer
operator|:
name|public
name|Stream
block|{
name|public
operator|:
name|StreamBuffer
argument_list|()
operator|:
name|Stream
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|,
name|lldb
operator|::
name|eByteOrderBig
argument_list|)
block|,
name|m_packet
argument_list|()
block|{}
name|StreamBuffer
argument_list|(
argument|uint32_t flags
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
operator|:
name|Stream
argument_list|(
name|flags
argument_list|,
name|addr_size
argument_list|,
name|byte_order
argument_list|)
block|,
name|m_packet
argument_list|()
block|{}
name|virtual
operator|~
name|StreamBuffer
argument_list|()
block|{}
name|virtual
name|void
name|Flush
argument_list|()
block|{
comment|// Nothing to do when flushing a buffer based stream...
block|}
name|virtual
name|size_t
name|Write
argument_list|(
argument|const void *s
argument_list|,
argument|size_t length
argument_list|)
block|{
if|if
condition|(
name|s
operator|&&
name|length
condition|)
name|m_packet
operator|.
name|append
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s
argument_list|,
operator|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|s
operator|)
operator|+
name|length
argument_list|)
expr_stmt|;
return|return
name|length
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_packet
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// Beware, this might not be NULL terminated as you can expect from
comment|// StringString as there may be random bits in the llvm::SmallVector. If
comment|// you are using this class to create a C string, be sure the call PutChar
comment|// ('\0')
comment|// after you have created your string, or use StreamString.
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
name|data
argument_list|()
return|;
block|}
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_packet
operator|.
name|size
argument_list|()
return|;
block|}
name|protected
label|:
name|llvm
operator|::
name|SmallVector
operator|<
name|char
operator|,
name|N
operator|>
name|m_packet
expr_stmt|;
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
comment|// #ifndef liblldb_StreamBuffer_h_
end_comment

end_unit

