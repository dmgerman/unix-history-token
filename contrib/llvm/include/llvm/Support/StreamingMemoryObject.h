begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StreamingMemoryObject.h - Streamable data interface -----*- C++ -*-===//
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
name|LLVM_SUPPORT_STREAMINGMEMORYOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STREAMINGMEMORYOBJECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryObject.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<memory>
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
comment|/// Interface to data which is actually streamed from a DataStreamer. In
comment|/// addition to inherited members, it has the dropLeadingBytes and
comment|/// setKnownObjectSize methods which are not applicable to non-streamed objects.
name|class
name|StreamingMemoryObject
range|:
name|public
name|MemoryObject
block|{
name|public
operator|:
name|StreamingMemoryObject
argument_list|(
name|DataStreamer
operator|*
name|streamer
argument_list|)
block|;
name|uint64_t
name|getExtent
argument_list|()
specifier|const
name|override
block|;
name|uint64_t
name|readBytes
argument_list|(
argument|uint8_t *Buf
argument_list|,
argument|uint64_t Size
argument_list|,
argument|uint64_t Address
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|uint8_t
operator|*
name|getPointer
argument_list|(
argument|uint64_t address
argument_list|,
argument|uint64_t size
argument_list|)
specifier|const
name|override
block|{
comment|// This could be fixed by ensuring the bytes are fetched and making a copy,
comment|// requiring that the bitcode size be known, or otherwise ensuring that
comment|// the memory doesn't go away/get reallocated, but it's
comment|// not currently necessary. Users that need the pointer don't stream.
name|llvm_unreachable
argument_list|(
literal|"getPointer in streaming memory objects not allowed"
argument_list|)
block|;
return|return
name|nullptr
return|;
block|}
name|bool
name|isValidAddress
argument_list|(
argument|uint64_t address
argument_list|)
specifier|const
name|override
block|;
comment|/// Drop s bytes from the front of the stream, pushing the positions of the
comment|/// remaining bytes down by s. This is used to skip past the bitcode header,
comment|/// since we don't know a priori if it's present, and we can't put bytes
comment|/// back into the stream once we've read them.
name|bool
name|dropLeadingBytes
argument_list|(
argument|size_t s
argument_list|)
block|;
comment|/// If the data object size is known in advance, many of the operations can
comment|/// be made more efficient, so this method should be called before reading
comment|/// starts (although it can be called anytime).
name|void
name|setKnownObjectSize
argument_list|(
argument|size_t size
argument_list|)
block|;
name|private
operator|:
specifier|const
specifier|static
name|uint32_t
name|kChunkSize
operator|=
literal|4096
operator|*
literal|4
block|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|Bytes
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|DataStreamer
operator|>
name|Streamer
block|;
name|mutable
name|size_t
name|BytesRead
block|;
comment|// Bytes read from stream
name|size_t
name|BytesSkipped
block|;
comment|// Bytes skipped at start of stream (e.g. wrapper/header)
name|mutable
name|size_t
name|ObjectSize
block|;
comment|// 0 if unknown, set if wrapper seen or EOF reached
name|mutable
name|bool
name|EOFReached
block|;
comment|// Fetch enough bytes such that Pos can be read or EOF is reached
comment|// (i.e. BytesRead> Pos). Return true if Pos can be read.
comment|// Unlike most of the functions in BitcodeReader, returns true on success.
comment|// Most of the requests will be small, but we fetch at kChunkSize bytes
comment|// at a time to avoid making too many potentially expensive GetBytes calls
name|bool
name|fetchToPos
argument_list|(
argument|size_t Pos
argument_list|)
specifier|const
block|{
if|if
condition|(
name|EOFReached
condition|)
return|return
name|Pos
operator|<
name|ObjectSize
return|;
while|while
condition|(
name|Pos
operator|>=
name|BytesRead
condition|)
block|{
name|Bytes
operator|.
name|resize
argument_list|(
name|BytesRead
operator|+
name|BytesSkipped
operator|+
name|kChunkSize
argument_list|)
expr_stmt|;
name|size_t
name|bytes
init|=
name|Streamer
operator|->
name|GetBytes
argument_list|(
operator|&
name|Bytes
index|[
name|BytesRead
operator|+
name|BytesSkipped
index|]
argument_list|,
name|kChunkSize
argument_list|)
decl_stmt|;
name|BytesRead
operator|+=
name|bytes
expr_stmt|;
if|if
condition|(
name|bytes
operator|!=
name|kChunkSize
condition|)
block|{
comment|// reached EOF/ran out of bytes
name|ObjectSize
operator|=
name|BytesRead
expr_stmt|;
name|EOFReached
operator|=
name|true
expr_stmt|;
break|break;
block|}
block|}
return|return
name|Pos
operator|<
name|BytesRead
return|;
block|}
name|StreamingMemoryObject
argument_list|(
argument|const StreamingMemoryObject&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|StreamingMemoryObject
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|MemoryObject
modifier|*
name|getNonStreamedMemoryObject
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|Start
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|End
parameter_list|)
function_decl|;
end_function_decl

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// STREAMINGMEMORYOBJECT_H_
end_comment

end_unit

