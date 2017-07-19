begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryItemStream.h ---------------------------------------*- C++ -*-===//
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
name|LLVM_SUPPORT_BINARYITEMSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYITEMSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
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
file|<cstddef>
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
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|BinaryItemTraits
block|{
specifier|static
name|size_t
name|length
argument_list|(
specifier|const
name|T
operator|&
name|Item
argument_list|)
operator|=
name|delete
block|;
specifier|static
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|bytes
argument_list|(
specifier|const
name|T
operator|&
name|Item
argument_list|)
operator|=
name|delete
block|; }
expr_stmt|;
comment|/// BinaryItemStream represents a sequence of objects stored in some kind of
comment|/// external container but for which it is useful to view as a stream of
comment|/// contiguous bytes.  An example of this might be if you have a collection of
comment|/// records and you serialize each one into a buffer, and store these serialized
comment|/// records in a container.  The pointers themselves are not laid out
comment|/// contiguously in memory, but we may wish to read from or write to these
comment|/// records as if they were.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Traits
operator|=
name|BinaryItemTraits
operator|<
name|T
operator|>>
name|class
name|BinaryItemStream
operator|:
name|public
name|BinaryStream
block|{
name|public
operator|:
name|explicit
name|BinaryItemStream
argument_list|(
argument|llvm::support::endianness Endian
argument_list|)
operator|:
name|Endian
argument_list|(
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
name|auto
name|ExpectedIndex
operator|=
name|translateOffsetIndex
argument_list|(
name|Offset
argument_list|)
block|;
if|if
condition|(
operator|!
name|ExpectedIndex
condition|)
return|return
name|ExpectedIndex
operator|.
name|takeError
argument_list|()
return|;
specifier|const
name|auto
operator|&
name|Item
operator|=
name|Items
index|[
operator|*
name|ExpectedIndex
index|]
block|;
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
if|if
condition|(
name|Size
operator|>
name|Traits
operator|::
name|length
argument_list|(
name|Item
argument_list|)
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
name|Buffer
operator|=
name|Traits
operator|::
name|bytes
argument_list|(
name|Item
argument_list|)
operator|.
name|take_front
argument_list|(
name|Size
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
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
name|auto
name|ExpectedIndex
init|=
name|translateOffsetIndex
argument_list|(
name|Offset
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ExpectedIndex
condition|)
return|return
name|ExpectedIndex
operator|.
name|takeError
argument_list|()
return|;
name|Buffer
operator|=
name|Traits
operator|::
name|bytes
argument_list|(
name|Items
index|[
operator|*
name|ExpectedIndex
index|]
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setItems
argument_list|(
name|ArrayRef
operator|<
name|T
operator|>
name|ItemArray
argument_list|)
block|{
name|Items
operator|=
name|ItemArray
expr_stmt|;
name|computeItemOffsets
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|uint32_t
name|getLength
parameter_list|()
function|override
block|{
return|return
name|ItemEndOffsets
operator|.
name|empty
argument_list|()
condition|?
literal|0
else|:
name|ItemEndOffsets
operator|.
name|back
argument_list|()
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_function
name|void
name|computeItemOffsets
parameter_list|()
block|{
name|ItemEndOffsets
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ItemEndOffsets
operator|.
name|reserve
argument_list|(
name|Items
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|uint32_t
name|CurrentOffset
init|=
literal|0
decl_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Item
range|:
name|Items
control|)
block|{
name|uint32_t
name|Len
init|=
name|Traits
operator|::
name|length
argument_list|(
name|Item
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Len
operator|>
literal|0
operator|&&
literal|"no empty items"
argument_list|)
expr_stmt|;
name|CurrentOffset
operator|+=
name|Len
expr_stmt|;
name|ItemEndOffsets
operator|.
name|push_back
argument_list|(
name|CurrentOffset
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
name|Expected
operator|<
name|uint32_t
operator|>
name|translateOffsetIndex
argument_list|(
argument|uint32_t Offset
argument_list|)
block|{
comment|// Make sure the offset is somewhere in our items array.
if|if
condition|(
name|Offset
operator|>=
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
name|stream_too_short
operator|)
return|;
operator|++
name|Offset
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|auto
name|Iter
init|=
name|std
operator|::
name|lower_bound
argument_list|(
name|ItemEndOffsets
operator|.
name|begin
argument_list|()
argument_list|,
name|ItemEndOffsets
operator|.
name|end
argument_list|()
argument_list|,
name|Offset
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|Idx
init|=
name|std
operator|::
name|distance
argument_list|(
name|ItemEndOffsets
operator|.
name|begin
argument_list|()
argument_list|,
name|Iter
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|assert
argument_list|(
name|Idx
operator|<
name|Items
operator|.
name|size
argument_list|()
operator|&&
literal|"binary search for offset failed"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Idx
return|;
end_return

begin_expr_stmt
unit|}    llvm
operator|::
name|support
operator|::
name|endianness
name|Endian
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ArrayRef
operator|<
name|T
operator|>
name|Items
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Sorted vector of offsets to accelerate lookup.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|ItemEndOffsets
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_BINARYITEMSTREAM_H
end_comment

end_unit

