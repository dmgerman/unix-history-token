begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MappedBlockStream.h - Reads stream data from a PDBFile ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_MAPPEDBLOCKSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_MAPPEDBLOCKSTREAM_H
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
file|"llvm/DebugInfo/CodeView/StreamInterface.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/IPDBStreamData.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
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
name|pdb
block|{
name|class
name|IPDBFile
decl_stmt|;
name|class
name|PDBFile
decl_stmt|;
name|class
name|MappedBlockStream
range|:
name|public
name|codeview
operator|::
name|StreamInterface
block|{
name|public
operator|:
name|Error
name|readBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|uint32_t Size
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
specifier|const
name|override
block|;
name|Error
name|readLongestContiguousChunk
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
specifier|const
name|override
block|;
name|Error
name|writeBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|ArrayRef<uint8_t> Buffer
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|getLength
argument_list|()
specifier|const
name|override
block|;
name|Error
name|commit
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getNumBytesCopied
argument_list|()
specifier|const
block|;
specifier|static
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MappedBlockStream
operator|>>
name|createIndexedStream
argument_list|(
argument|uint32_t StreamIdx
argument_list|,
argument|const IPDBFile&File
argument_list|)
block|;
specifier|static
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MappedBlockStream
operator|>>
name|createDirectoryStream
argument_list|(
specifier|const
name|PDBFile
operator|&
name|File
argument_list|)
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
name|protected
operator|:
name|MappedBlockStream
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBStreamData
operator|>
name|Data
argument_list|,
specifier|const
name|IPDBFile
operator|&
name|File
argument_list|)
block|;
name|Error
name|readBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|MutableArrayRef<uint8_t> Buffer
argument_list|)
specifier|const
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
specifier|const
block|;
specifier|const
name|IPDBFile
operator|&
name|Pdb
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBStreamData
operator|>
name|Data
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|CacheEntry
expr_stmt|;
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|Pool
decl_stmt|;
name|mutable
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
comment|// LLVM_DEBUGINFO_PDB_RAW_MAPPEDBLOCKSTREAM_H
end_comment

end_unit

