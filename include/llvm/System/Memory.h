begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Memory.h - Memory Support --------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares the llvm::sys::Memory class.
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
name|LLVM_SYSTEM_MEMORY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_MEMORY_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This class encapsulates the notion of a memory block which has an address
comment|/// and a size. It is used by the Memory class (a friend) as the result of
comment|/// various memory allocation operations.
comment|/// @see Memory
comment|/// @brief Memory block abstraction.
name|class
name|MemoryBlock
block|{
name|public
label|:
name|MemoryBlock
argument_list|()
block|{ }
name|MemoryBlock
argument_list|(
argument|void *addr
argument_list|,
argument|size_t size
argument_list|)
block|:
name|Address
argument_list|(
name|addr
argument_list|)
operator|,
name|Size
argument_list|(
argument|size
argument_list|)
block|{ }
name|void
operator|*
name|base
argument_list|()
specifier|const
block|{
return|return
name|Address
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|private
label|:
name|void
modifier|*
name|Address
decl_stmt|;
comment|///< Address of first byte of memory area
name|size_t
name|Size
decl_stmt|;
comment|///< Size, in bytes of the memory area
name|friend
name|class
name|Memory
decl_stmt|;
block|}
empty_stmt|;
comment|/// This class provides various memory handling functions that manipulate
comment|/// MemoryBlock instances.
comment|/// @since 1.4
comment|/// @brief An abstraction for memory operations.
name|class
name|Memory
block|{
name|public
label|:
comment|/// This method allocates a block of Read/Write/Execute memory that is
comment|/// suitable for executing dynamically generated code (e.g. JIT). An
comment|/// attempt to allocate \p NumBytes bytes of virtual memory is made.
comment|/// \p NearBlock may point to an existing allocation in which case
comment|/// an attempt is made to allocate more memory near the existing block.
comment|///
comment|/// On success, this returns a non-null memory block, otherwise it returns
comment|/// a null memory block and fills in *ErrMsg.
comment|///
comment|/// @brief Allocate Read/Write/Execute memory.
specifier|static
name|MemoryBlock
name|AllocateRWX
argument_list|(
name|size_t
name|NumBytes
argument_list|,
specifier|const
name|MemoryBlock
operator|*
name|NearBlock
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// This method releases a block of Read/Write/Execute memory that was
comment|/// allocated with the AllocateRWX method. It should not be used to
comment|/// release any memory block allocated any other way.
comment|///
comment|/// On success, this returns false, otherwise it returns true and fills
comment|/// in *ErrMsg.
comment|/// @throws std::string if an error occurred.
comment|/// @brief Release Read/Write/Execute memory.
specifier|static
name|bool
name|ReleaseRWX
argument_list|(
name|MemoryBlock
operator|&
name|block
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// InvalidateInstructionCache - Before the JIT can run a block of code
comment|/// that has been emitted it must invalidate the instruction cache on some
comment|/// platforms.
specifier|static
name|void
name|InvalidateInstructionCache
parameter_list|(
specifier|const
name|void
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Len
parameter_list|)
function_decl|;
comment|/// setExecutable - Before the JIT can run a block of code, it has to be
comment|/// given read and executable privilege. Return true if it is already r-x
comment|/// or the system is able to change its previlege.
specifier|static
name|bool
name|setExecutable
argument_list|(
name|MemoryBlock
operator|&
name|M
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// setWritable - When adding to a block of code, the JIT may need
comment|/// to mark a block of code as RW since the protections are on page
comment|/// boundaries, and the JIT internal allocations are not page aligned.
specifier|static
name|bool
name|setWritable
argument_list|(
name|MemoryBlock
operator|&
name|M
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// setRangeExecutable - Mark the page containing a range of addresses
comment|/// as executable.
specifier|static
name|bool
name|setRangeExecutable
parameter_list|(
specifier|const
name|void
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
comment|/// setRangeWritable - Mark the page containing a range of addresses
comment|/// as writable.
specifier|static
name|bool
name|setRangeWritable
parameter_list|(
specifier|const
name|void
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

