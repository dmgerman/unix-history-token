begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MappedBlockStream.h - Discontiguous stream data in an MSF -*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|LLVM_DEBUGINFO_MSF_MAPPEDBLOCKSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_MSF_MAPPEDBLOCKSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/MSF/MSFStreamLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
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

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|msf
block|{
struct_decl|struct
name|MSFLayout
struct_decl|;
comment|/// MappedBlockStream represents data stored in an MSF file into chunks of a
comment|/// particular size (called the Block Size), and whose chunks may not be
comment|/// necessarily contiguous.  The arrangement of these chunks MSF the file
comment|/// is described by some other metadata contained within the MSF file.  In
comment|/// the case of a standard MSF Stream, the layout of the stream's blocks
comment|/// is described by the MSF "directory", but in the case of the directory
comment|/// itself, the layout is described by an array at a fixed location within
comment|/// the MSF.  MappedBlockStream provides methods for reading from and writing
comment|/// to one of these streams transparently, as if it were a contiguous sequence
comment|/// of bytes.
name|class
name|MappedBlockStream
range|:
name|public
name|BinaryStream
block|{
name|friend
name|class
name|WritableMappedBlockStream
block|;
name|public
operator|:
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MappedBlockStream
operator|>
name|createStream
argument_list|(
argument|uint32_t BlockSize
argument_list|,
argument|const MSFStreamLayout&Layout
argument_list|,
argument|BinaryStreamRef MsfData
argument_list|)
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MappedBlockStream
operator|>
name|createIndexedStream
argument_list|(
argument|const MSFLayout&Layout
argument_list|,
argument|BinaryStreamRef MsfData
argument_list|,
argument|uint32_t StreamIndex
argument_list|)
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MappedBlockStream
operator|>
name|createFpmStream
argument_list|(
argument|const MSFLayout&Layout
argument_list|,
argument|BinaryStreamRef MsfData
argument_list|)
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MappedBlockStream
operator|>
name|createDirectoryStream
argument_list|(
argument|const MSFLayout&Layout
argument_list|,
argument|BinaryStreamRef MsfData
argument_list|)
block|;
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
name|llvm
operator|::
name|support
operator|::
name|little
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
block|;
name|Error
name|readLongestContiguousChunk
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
name|override
block|;
name|uint32_t
name|getLength
argument_list|()
name|override
block|;
name|uint32_t
name|getNumBytesCopied
argument_list|()
specifier|const
block|;
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|getAllocator
argument_list|()
block|{
return|return
name|Pool
return|;
block|}
name|void
name|invalidateCache
argument_list|()
block|;
name|uint32_t
name|getBlockSize
argument_list|()
specifier|const
block|{
return|return
name|BlockSize
return|;
block|}
name|uint32_t
name|getNumBlocks
argument_list|()
specifier|const
block|{
return|return
name|StreamLayout
operator|.
name|Blocks
operator|.
name|size
argument_list|()
return|;
block|}
name|uint32_t
name|getStreamLength
argument_list|()
specifier|const
block|{
return|return
name|StreamLayout
operator|.
name|Length
return|;
block|}
name|protected
operator|:
name|MappedBlockStream
argument_list|(
argument|uint32_t BlockSize
argument_list|,
argument|const MSFStreamLayout&StreamLayout
argument_list|,
argument|BinaryStreamRef MsfData
argument_list|)
block|;
name|private
operator|:
specifier|const
name|MSFStreamLayout
operator|&
name|getStreamLayout
argument_list|()
specifier|const
block|{
return|return
name|StreamLayout
return|;
block|}
name|void
name|fixCacheAfterWrite
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t> Data
argument_list|)
specifier|const
block|;
name|Error
name|readBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|MutableArrayRef<uint8_t> Buffer
argument_list|)
block|;
name|bool
name|tryReadContiguously
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|uint32_t Size
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
block|;
specifier|const
name|uint32_t
name|BlockSize
block|;
specifier|const
name|MSFStreamLayout
name|StreamLayout
block|;
name|BinaryStreamRef
name|MsfData
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|CacheEntry
expr_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Pool
decl_stmt|;
name|DenseMap
operator|<
name|uint32_t
operator|,
name|std
operator|::
name|vector
operator|<
name|CacheEntry
operator|>>
name|CacheMap
expr_stmt|;
block|}
empty_stmt|;
name|class
name|WritableMappedBlockStream
range|:
name|public
name|WritableBinaryStream
block|{
name|public
operator|:
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|WritableMappedBlockStream
operator|>
name|createStream
argument_list|(
argument|uint32_t BlockSize
argument_list|,
argument|const MSFStreamLayout&Layout
argument_list|,
argument|WritableBinaryStreamRef MsfData
argument_list|)
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|WritableMappedBlockStream
operator|>
name|createIndexedStream
argument_list|(
argument|const MSFLayout&Layout
argument_list|,
argument|WritableBinaryStreamRef MsfData
argument_list|,
argument|uint32_t StreamIndex
argument_list|)
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|WritableMappedBlockStream
operator|>
name|createDirectoryStream
argument_list|(
argument|const MSFLayout&Layout
argument_list|,
argument|WritableBinaryStreamRef MsfData
argument_list|)
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|WritableMappedBlockStream
operator|>
name|createFpmStream
argument_list|(
argument|const MSFLayout&Layout
argument_list|,
argument|WritableBinaryStreamRef MsfData
argument_list|)
block|;
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
name|llvm
operator|::
name|support
operator|::
name|little
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
block|;
name|Error
name|readLongestContiguousChunk
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
name|override
block|;
name|uint32_t
name|getLength
argument_list|()
name|override
block|;
name|Error
name|writeBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t> Buffer
argument_list|)
name|override
block|;
name|Error
name|commit
argument_list|()
name|override
block|;
specifier|const
name|MSFStreamLayout
operator|&
name|getStreamLayout
argument_list|()
specifier|const
block|{
return|return
name|ReadInterface
operator|.
name|getStreamLayout
argument_list|()
return|;
block|}
name|uint32_t
name|getBlockSize
argument_list|()
specifier|const
block|{
return|return
name|ReadInterface
operator|.
name|getBlockSize
argument_list|()
return|;
block|}
name|uint32_t
name|getNumBlocks
argument_list|()
specifier|const
block|{
return|return
name|ReadInterface
operator|.
name|getNumBlocks
argument_list|()
return|;
block|}
name|uint32_t
name|getStreamLength
argument_list|()
specifier|const
block|{
return|return
name|ReadInterface
operator|.
name|getStreamLength
argument_list|()
return|;
block|}
name|protected
operator|:
name|WritableMappedBlockStream
argument_list|(
argument|uint32_t BlockSize
argument_list|,
argument|const MSFStreamLayout&StreamLayout
argument_list|,
argument|WritableBinaryStreamRef MsfData
argument_list|)
block|;
name|private
operator|:
name|MappedBlockStream
name|ReadInterface
block|;
name|WritableBinaryStreamRef
name|WriteInterface
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace pdb
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_MSF_MAPPEDBLOCKSTREAM_H
end_comment

end_unit

