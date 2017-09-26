begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryByteStream.h ---------------------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// A BinaryStream which stores data in a single continguous memory buffer.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_BINARYBYTESTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYBYTESTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamError.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileOutputBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief An implementation of BinaryStream which holds its entire data set
comment|/// in a single contiguous buffer.  BinaryByteStream guarantees that no read
comment|/// operation will ever incur a copy.  Note that BinaryByteStream does not
comment|/// own the underlying buffer.
name|class
name|BinaryByteStream
range|:
name|public
name|BinaryStream
block|{
name|public
operator|:
name|BinaryByteStream
argument_list|()
operator|=
expr|default
block|;
name|BinaryByteStream
argument_list|(
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|llvm::support::endianness Endian
argument_list|)
operator|:
name|Endian
argument_list|(
name|Endian
argument_list|)
block|,
name|Data
argument_list|(
argument|Data
argument_list|)
block|{}
name|BinaryByteStream
argument_list|(
argument|StringRef Data
argument_list|,
argument|llvm::support::endianness Endian
argument_list|)
operator|:
name|Endian
argument_list|(
name|Endian
argument_list|)
block|,
name|Data
argument_list|(
argument|Data.bytes_begin()
argument_list|,
argument|Data.bytes_end()
argument_list|)
block|{}
name|llvm
operator|::
name|support
operator|::
name|endianness
name|getEndian
argument_list|()
specifier|const
name|override
block|{
return|return
name|Endian
return|;
block|}
name|Error
name|readBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|uint32_t Size
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
name|override
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|checkOffset
argument_list|(
name|Offset
argument_list|,
name|Size
argument_list|)
condition|)
return|return
name|EC
return|;
name|Buffer
operator|=
name|Data
operator|.
name|slice
argument_list|(
name|Offset
argument_list|,
name|Size
argument_list|)
block|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
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
name|override
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|checkOffset
argument_list|(
name|Offset
argument_list|,
literal|1
argument_list|)
condition|)
return|return
name|EC
return|;
name|Buffer
operator|=
name|Data
operator|.
name|slice
argument_list|(
name|Offset
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|uint32_t
name|getLength
parameter_list|()
function|override
block|{
return|return
name|Data
operator|.
name|size
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|data
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
name|StringRef
name|str
argument_list|()
specifier|const
block|{
specifier|const
name|char
operator|*
name|CharData
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|Data
operator|.
name|data
argument_list|()
operator|)
block|;
return|return
name|StringRef
argument_list|(
name|CharData
argument_list|,
name|Data
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
name|protected
label|:
name|llvm
operator|::
name|support
operator|::
name|endianness
name|Endian
expr_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief An implementation of BinaryStream whose data is backed by an llvm
end_comment

begin_comment
comment|/// MemoryBuffer object.  MemoryBufferByteStream owns the MemoryBuffer in
end_comment

begin_comment
comment|/// question.  As with BinaryByteStream, reading from a MemoryBufferByteStream
end_comment

begin_comment
comment|/// will never cause a copy.
end_comment

begin_decl_stmt
name|class
name|MemoryBufferByteStream
range|:
name|public
name|BinaryByteStream
block|{
name|public
operator|:
name|MemoryBufferByteStream
argument_list|(
argument|std::unique_ptr<MemoryBuffer> Buffer
argument_list|,
argument|llvm::support::endianness Endian
argument_list|)
operator|:
name|BinaryByteStream
argument_list|(
name|Buffer
operator|->
name|getBuffer
argument_list|()
argument_list|,
name|Endian
argument_list|)
block|,
name|MemBuffer
argument_list|(
argument|std::move(Buffer)
argument_list|)
block|{}
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|MemBuffer
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief An implementation of BinaryStream which holds its entire data set
end_comment

begin_comment
comment|/// in a single contiguous buffer.  As with BinaryByteStream, the mutable
end_comment

begin_comment
comment|/// version also guarantees that no read operation will ever incur a copy,
end_comment

begin_comment
comment|/// and similarly it does not own the underlying buffer.
end_comment

begin_decl_stmt
name|class
name|MutableBinaryByteStream
range|:
name|public
name|WritableBinaryStream
block|{
name|public
operator|:
name|MutableBinaryByteStream
argument_list|()
operator|=
expr|default
block|;
name|MutableBinaryByteStream
argument_list|(
argument|MutableArrayRef<uint8_t> Data
argument_list|,
argument|llvm::support::endianness Endian
argument_list|)
operator|:
name|Data
argument_list|(
name|Data
argument_list|)
block|,
name|ImmutableStream
argument_list|(
argument|Data
argument_list|,
argument|Endian
argument_list|)
block|{}
name|llvm
operator|::
name|support
operator|::
name|endianness
name|getEndian
argument_list|()
specifier|const
name|override
block|{
return|return
name|ImmutableStream
operator|.
name|getEndian
argument_list|()
return|;
block|}
name|Error
name|readBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|uint32_t Size
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
name|override
block|{
return|return
name|ImmutableStream
operator|.
name|readBytes
argument_list|(
name|Offset
argument_list|,
name|Size
argument_list|,
name|Buffer
argument_list|)
return|;
block|}
name|Error
name|readLongestContiguousChunk
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
name|override
block|{
return|return
name|ImmutableStream
operator|.
name|readLongestContiguousChunk
argument_list|(
name|Offset
argument_list|,
name|Buffer
argument_list|)
return|;
block|}
name|uint32_t
name|getLength
argument_list|()
name|override
block|{
return|return
name|ImmutableStream
operator|.
name|getLength
argument_list|()
return|;
block|}
name|Error
name|writeBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t> Buffer
argument_list|)
name|override
block|{
if|if
condition|(
name|Buffer
operator|.
name|empty
argument_list|()
condition|)
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
if|if
condition|(
name|auto
name|EC
init|=
name|checkOffset
argument_list|(
name|Offset
argument_list|,
name|Buffer
operator|.
name|size
argument_list|()
argument_list|)
condition|)
return|return
name|EC
return|;
name|uint8_t
operator|*
name|DataPtr
operator|=
name|const_cast
operator|<
name|uint8_t
operator|*
operator|>
operator|(
name|Data
operator|.
name|data
argument_list|()
operator|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|::
name|memcpy
argument_list|(
name|DataPtr
operator|+
name|Offset
argument_list|,
name|Buffer
operator|.
name|data
argument_list|()
argument_list|,
name|Buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
end_return

begin_macro
unit|}    Error
name|commit
argument_list|()
end_macro

begin_macro
name|override
end_macro

begin_block
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_block

begin_expr_stmt
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|data
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|Data
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|BinaryByteStream
name|ImmutableStream
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief An implementation of WritableBinaryStream backed by an llvm
end_comment

begin_comment
comment|/// FileOutputBuffer.
end_comment

begin_decl_stmt
name|class
name|FileBufferByteStream
range|:
name|public
name|WritableBinaryStream
block|{
name|private
operator|:
name|class
name|StreamImpl
operator|:
name|public
name|MutableBinaryByteStream
block|{
name|public
operator|:
name|StreamImpl
argument_list|(
argument|std::unique_ptr<FileOutputBuffer> Buffer
argument_list|,
argument|llvm::support::endianness Endian
argument_list|)
operator|:
name|MutableBinaryByteStream
argument_list|(
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|(
name|Buffer
operator|->
name|getBufferStart
argument_list|()
expr|,
name|Buffer
operator|->
name|getBufferEnd
argument_list|()
operator|)
argument_list|,
name|Endian
argument_list|)
block|,
name|FileBuffer
argument_list|(
argument|std::move(Buffer)
argument_list|)
block|{}
name|Error
name|commit
argument_list|()
name|override
block|{
if|if
condition|(
name|FileBuffer
operator|->
name|commit
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
name|filesystem_error
operator|)
return|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|FileOutputBuffer
operator|>
name|FileBuffer
block|;   }
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|FileBufferByteStream
argument_list|(
argument|std::unique_ptr<FileOutputBuffer> Buffer
argument_list|,
argument|llvm::support::endianness Endian
argument_list|)
end_macro

begin_macro
unit|:
name|Impl
argument_list|(
argument|std::move(Buffer)
argument_list|,
argument|Endian
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|llvm
operator|::
name|support
operator|::
name|endianness
name|getEndian
argument_list|()
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|getEndian
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
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
name|override
block|{
return|return
name|Impl
operator|.
name|readBytes
argument_list|(
name|Offset
argument_list|,
name|Size
argument_list|,
name|Buffer
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
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
name|override
block|{
return|return
name|Impl
operator|.
name|readLongestContiguousChunk
argument_list|(
name|Offset
argument_list|,
name|Buffer
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|uint32_t
name|getLength
parameter_list|()
function|override
block|{
return|return
name|Impl
operator|.
name|getLength
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|Error
name|writeBytes
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|writeBytes
argument_list|(
name|Offset
argument_list|,
name|Data
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|Error
name|commit
parameter_list|()
function|override
block|{
return|return
name|Impl
operator|.
name|commit
argument_list|()
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|StreamImpl
name|Impl
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_BYTESTREAM_H
end_comment

end_unit

