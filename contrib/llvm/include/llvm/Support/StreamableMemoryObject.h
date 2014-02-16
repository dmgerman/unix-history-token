begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StreamableMemoryObject.h - Streamable data interface -----*- C++ -*-===//
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
name|LLVM_SUPPORT_STREAMABLEMEMORYOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STREAMABLEMEMORYOBJECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

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
file|"llvm/Support/MemoryObject.h"
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
comment|/// StreamableMemoryObject - Interface to data which might be streamed.
comment|/// Streamability has 2 important implications/restrictions. First, the data
comment|/// might not yet exist in memory when the request is made. This just means
comment|/// that readByte/readBytes might have to block or do some work to get it.
comment|/// More significantly, the exact size of the object might not be known until
comment|/// it has all been fetched. This means that to return the right result,
comment|/// getExtent must also wait for all the data to arrive; therefore it should
comment|/// not be called on objects which are actually streamed (this would defeat
comment|/// the purpose of streaming). Instead, isValidAddress and isObjectEnd can be
comment|/// used to test addresses without knowing the exact size of the stream.
comment|/// Finally, getPointer can be used instead of readBytes to avoid extra copying.
name|class
name|StreamableMemoryObject
range|:
name|public
name|MemoryObject
block|{
name|public
operator|:
comment|/// Destructor      - Override as necessary.
name|virtual
operator|~
name|StreamableMemoryObject
argument_list|()
block|;
comment|/// getBase         - Returns the lowest valid address in the region.
comment|///
comment|/// @result         - The lowest valid address.
name|virtual
name|uint64_t
name|getBase
argument_list|()
specifier|const
name|LLVM_OVERRIDE
operator|=
literal|0
block|;
comment|/// getExtent       - Returns the size of the region in bytes.  (The region is
comment|///                   contiguous, so the highest valid address of the region
comment|///                   is getBase() + getExtent() - 1).
comment|///                   May block until all bytes in the stream have been read
comment|///
comment|/// @result         - The size of the region.
name|virtual
name|uint64_t
name|getExtent
argument_list|()
specifier|const
name|LLVM_OVERRIDE
operator|=
literal|0
block|;
comment|/// readByte        - Tries to read a single byte from the region.
comment|///                   May block until (address - base) bytes have been read
comment|/// @param address  - The address of the byte, in the same space as getBase().
comment|/// @param ptr      - A pointer to a byte to be filled in.  Must be non-NULL.
comment|/// @result         - 0 if successful; -1 if not.  Failure may be due to a
comment|///                   bounds violation or an implementation-specific error.
name|virtual
name|int
name|readByte
argument_list|(
argument|uint64_t address
argument_list|,
argument|uint8_t *ptr
argument_list|)
specifier|const
name|LLVM_OVERRIDE
operator|=
literal|0
block|;
comment|/// readBytes       - Tries to read a contiguous range of bytes from the
comment|///                   region, up to the end of the region.
comment|///                   May block until (address - base + size) bytes have
comment|///                   been read. Additionally, StreamableMemoryObjects will
comment|///                   not do partial reads - if size bytes cannot be read,
comment|///                   readBytes will fail.
comment|///
comment|/// @param address  - The address of the first byte, in the same space as
comment|///                   getBase().
comment|/// @param size     - The number of bytes to copy.
comment|/// @param buf      - A pointer to a buffer to be filled in.  Must be non-NULL
comment|///                   and large enough to hold size bytes.
comment|/// @result         - 0 if successful; -1 if not.  Failure may be due to a
comment|///                   bounds violation or an implementation-specific error.
name|virtual
name|int
name|readBytes
argument_list|(
argument|uint64_t address
argument_list|,
argument|uint64_t size
argument_list|,
argument|uint8_t *buf
argument_list|)
specifier|const
name|LLVM_OVERRIDE
operator|=
literal|0
block|;
comment|/// getPointer  - Ensures that the requested data is in memory, and returns
comment|///               A pointer to it. More efficient than using readBytes if the
comment|///               data is already in memory.
comment|///               May block until (address - base + size) bytes have been read
comment|/// @param address - address of the byte, in the same space as getBase()
comment|/// @param size    - amount of data that must be available on return
comment|/// @result        - valid pointer to the requested data
name|virtual
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
operator|=
literal|0
block|;
comment|/// isValidAddress - Returns true if the address is within the object
comment|///                  (i.e. between base and base + extent - 1 inclusive)
comment|///                  May block until (address - base) bytes have been read
comment|/// @param address - address of the byte, in the same space as getBase()
comment|/// @result        - true if the address may be read with readByte()
name|virtual
name|bool
name|isValidAddress
argument_list|(
argument|uint64_t address
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// isObjectEnd    - Returns true if the address is one past the end of the
comment|///                  object (i.e. if it is equal to base + extent)
comment|///                  May block until (address - base) bytes have been read
comment|/// @param address - address of the byte, in the same space as getBase()
comment|/// @result        - true if the address is equal to base + extent
name|virtual
name|bool
name|isObjectEnd
argument_list|(
argument|uint64_t address
argument_list|)
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
comment|/// StreamingMemoryObject - interface to data which is actually streamed from
comment|/// a DataStreamer. In addition to inherited members, it has the
comment|/// dropLeadingBytes and setKnownObjectSize methods which are not applicable
comment|/// to non-streamed objects.
name|class
name|StreamingMemoryObject
range|:
name|public
name|StreamableMemoryObject
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
name|virtual
name|uint64_t
name|getBase
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|uint64_t
name|getExtent
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|int
name|readByte
argument_list|(
argument|uint64_t address
argument_list|,
argument|uint8_t *ptr
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|int
name|readBytes
argument_list|(
argument|uint64_t address
argument_list|,
argument|uint64_t size
argument_list|,
argument|uint8_t *buf
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
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
name|LLVM_OVERRIDE
block|{
comment|// This could be fixed by ensuring the bytes are fetched and making a copy,
comment|// requiring that the bitcode size be known, or otherwise ensuring that
comment|// the memory doesn't go away/get reallocated, but it's
comment|// not currently necessary. Users that need the pointer don't stream.
name|assert
argument_list|(
literal|0
operator|&&
literal|"getPointer in streaming memory objects not allowed"
argument_list|)
block|;
return|return
name|NULL
return|;
block|}
name|virtual
name|bool
name|isValidAddress
argument_list|(
argument|uint64_t address
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|isObjectEnd
argument_list|(
argument|uint64_t address
argument_list|)
specifier|const
name|LLVM_OVERRIDE
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
name|OwningPtr
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
operator|<
name|kChunkSize
condition|)
block|{
if|if
condition|(
name|ObjectSize
operator|&&
name|BytesRead
operator|<
name|Pos
condition|)
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unexpected short read fetching bitcode"
argument_list|)
expr_stmt|;
if|if
condition|(
name|BytesRead
operator|<=
name|Pos
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
return|return
name|false
return|;
block|}
block|}
block|}
return|return
name|true
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
name|StreamableMemoryObject
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
comment|// STREAMABLEMEMORYOBJECT_H_
end_comment

end_unit

