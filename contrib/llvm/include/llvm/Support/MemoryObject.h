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
name|MEMORYOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|MEMORYOBJECT_H
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
comment|/// MemoryObject - Abstract base class for contiguous addressable memory.
comment|///   Necessary for cases in which the memory is in another process, in a
comment|///   file, or on a remote machine.
comment|///   All size and offset parameters are uint64_ts, to allow 32-bit processes
comment|///   access to 64-bit address spaces.
name|class
name|MemoryObject
block|{
name|public
label|:
comment|/// Destructor      - Override as necessary.
name|virtual
operator|~
name|MemoryObject
argument_list|()
expr_stmt|;
comment|/// getBase         - Returns the lowest valid address in the region.
comment|///
comment|/// @result         - The lowest valid address.
name|virtual
name|uint64_t
name|getBase
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// getExtent       - Returns the size of the region in bytes.  (The region is
comment|///                   contiguous, so the highest valid address of the region
comment|///                   is getBase() + getExtent() - 1).
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
comment|/// readByte        - Tries to read a single byte from the region.
comment|///
comment|/// @param address  - The address of the byte, in the same space as getBase().
comment|/// @param ptr      - A pointer to a byte to be filled in.  Must be non-NULL.
comment|/// @result         - 0 if successful; -1 if not.  Failure may be due to a
comment|///                   bounds violation or an implementation-specific error.
name|virtual
name|int
name|readByte
argument_list|(
name|uint64_t
name|address
argument_list|,
name|uint8_t
operator|*
name|ptr
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// readBytes       - Tries to read a contiguous range of bytes from the
comment|///                   region, up to the end of the region.
comment|///                   You should override this function if there is a quicker
comment|///                   way than going back and forth with individual bytes.
comment|///
comment|/// @param address  - The address of the first byte, in the same space as
comment|///                   getBase().
comment|/// @param size     - The maximum number of bytes to copy.
comment|/// @param buf      - A pointer to a buffer to be filled in.  Must be non-NULL
comment|///                   and large enough to hold size bytes.
comment|/// @param copied   - A pointer to a nunber that is filled in with the number
comment|///                   of bytes actually read.  May be NULL.
comment|/// @result         - 0 if successful; -1 if not.  Failure may be due to a
comment|///                   bounds violation or an implementation-specific error.
name|virtual
name|int
name|readBytes
argument_list|(
name|uint64_t
name|address
argument_list|,
name|uint64_t
name|size
argument_list|,
name|uint8_t
operator|*
name|buf
argument_list|,
name|uint64_t
operator|*
name|copied
argument_list|)
decl|const
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

