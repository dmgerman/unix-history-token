begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryStream.h - Base interface for a stream of data -----*- C++ -*-===//
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
name|LLVM_SUPPORT_BINARYSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamError.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief An interface for accessing data in a stream-like format, but which
comment|/// discourages copying.  Instead of specifying a buffer in which to copy
comment|/// data on a read, the API returns an ArrayRef to data owned by the stream's
comment|/// implementation.  Since implementations may not necessarily store data in a
comment|/// single contiguous buffer (or even in memory at all), in such cases a it may
comment|/// be necessary for an implementation to cache such a buffer so that it can
comment|/// return it.
name|class
name|BinaryStream
block|{
name|public
label|:
name|virtual
operator|~
name|BinaryStream
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|llvm
operator|::
name|support
operator|::
name|endianness
name|getEndian
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Given an offset into the stream and a number of bytes, attempt to
comment|/// read the bytes and set the output ArrayRef to point to data owned by the
comment|/// stream.
name|virtual
name|Error
name|readBytes
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|uint32_t
name|Size
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|Buffer
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief Given an offset into the stream, read as much as possible without
comment|/// copying any data.
name|virtual
name|Error
name|readLongestContiguousChunk
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|Buffer
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief Return the number of bytes of data in this stream.
name|virtual
name|uint32_t
name|getLength
parameter_list|()
init|=
literal|0
function_decl|;
name|protected
label|:
name|Error
name|checkOffset
parameter_list|(
name|uint32_t
name|Offset
parameter_list|,
name|uint32_t
name|DataSize
parameter_list|)
block|{
if|if
condition|(
name|Offset
operator|>
name|getLength
argument_list|()
condition|)
return|return
name|make_error
operator|<
name|BinaryStreamError
operator|>
operator|(
name|stream_error_code
operator|::
name|invalid_offset
operator|)
return|;
if|if
condition|(
name|getLength
argument_list|()
operator|<
name|DataSize
operator|+
name|Offset
condition|)
return|return
name|make_error
operator|<
name|BinaryStreamError
operator|>
operator|(
name|stream_error_code
operator|::
name|stream_too_short
operator|)
return|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief A BinaryStream which can be read from as well as written to.  Note
comment|/// that writing to a BinaryStream always necessitates copying from the input
comment|/// buffer to the stream's backing store.  Streams are assumed to be buffered
comment|/// so that to be portable it is necessary to call commit() on the stream when
comment|/// all data has been written.
name|class
name|WritableBinaryStream
range|:
name|public
name|BinaryStream
block|{
name|public
operator|:
operator|~
name|WritableBinaryStream
argument_list|()
name|override
operator|=
expr|default
block|;
comment|/// \brief Attempt to write the given bytes into the stream at the desired
comment|/// offset. This will always necessitate a copy.  Cannot shrink or grow the
comment|/// stream, only writes into existing allocated space.
name|virtual
name|Error
name|writeBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief For buffered streams, commits changes to the backing store.
name|virtual
name|Error
name|commit
argument_list|()
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_BINARYSTREAM_H
end_comment

end_unit

