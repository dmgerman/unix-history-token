begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MemoryObject.h - Abstract memory interface ---------------*- C++ -*-===//
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
name|LLVM_SUPPORT_MEMORYOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MEMORYOBJECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Interface to data which might be streamed. Streamability has 2 important
comment|/// implications/restrictions. First, the data might not yet exist in memory
comment|/// when the request is made. This just means that readByte/readBytes might have
comment|/// to block or do some work to get it. More significantly, the exact size of
comment|/// the object might not be known until it has all been fetched. This means that
comment|/// to return the right result, getExtent must also wait for all the data to
comment|/// arrive; therefore it should not be called on objects which are actually
comment|/// streamed (this would defeat the purpose of streaming). Instead,
comment|/// isValidAddress can be used to test addresses without knowing the exact size
comment|/// of the stream. Finally, getPointer can be used instead of readBytes to avoid
comment|/// extra copying.
name|class
name|MemoryObject
block|{
name|public
label|:
name|virtual
operator|~
name|MemoryObject
argument_list|()
expr_stmt|;
comment|/// Returns the size of the region in bytes.  (The region is contiguous, so
comment|/// the highest valid address of the region is getExtent() - 1).
comment|///
comment|/// @result         - The size of the region.
name|virtual
name|uint64_t
name|getExtent
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Tries to read a contiguous range of bytes from the region, up to the end
comment|/// of the region.
comment|///
comment|/// @param Buf      - A pointer to a buffer to be filled in.  Must be non-NULL
comment|///                   and large enough to hold size bytes.
comment|/// @param Size     - The number of bytes to copy.
comment|/// @param Address  - The address of the first byte, in the same space as
comment|///                   getBase().
comment|/// @result         - The number of bytes read.
name|virtual
name|uint64_t
name|readBytes
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|,
name|uint64_t
name|Size
argument_list|,
name|uint64_t
name|Address
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Ensures that the requested data is in memory, and returns a pointer to it.
comment|/// More efficient than using readBytes if the data is already in memory. May
comment|/// block until (address - base + size) bytes have been read
comment|/// @param address - address of the byte, in the same space as getBase()
comment|/// @param size    - amount of data that must be available on return
comment|/// @result        - valid pointer to the requested data
name|virtual
specifier|const
name|uint8_t
modifier|*
name|getPointer
argument_list|(
name|uint64_t
name|address
argument_list|,
name|uint64_t
name|size
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Returns true if the address is within the object (i.e. between base and
comment|/// base + extent - 1 inclusive). May block until (address - base) bytes have
comment|/// been read
comment|/// @param address - address of the byte, in the same space as getBase()
comment|/// @result        - true if the address may be read with readByte()
name|virtual
name|bool
name|isValidAddress
argument_list|(
name|uint64_t
name|address
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

