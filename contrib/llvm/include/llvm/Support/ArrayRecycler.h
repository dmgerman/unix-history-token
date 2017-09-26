begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- llvm/Support/ArrayRecycler.h - Recycling of Arrays ---------*- C++ -*-==//
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
comment|// This file defines the ArrayRecycler class template which can recycle small
end_comment

begin_comment
comment|// arrays allocated from one of the allocators in Allocator.h
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
name|LLVM_SUPPORT_ARRAYRECYCLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ARRAYRECYCLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Recycle small arrays allocated from a BumpPtrAllocator.
comment|///
comment|/// Arrays are allocated in a small number of fixed sizes. For each supported
comment|/// array size, the ArrayRecycler keeps a free list of available arrays.
comment|///
name|template
operator|<
name|class
name|T
operator|,
name|size_t
name|Align
operator|=
name|alignof
argument_list|(
name|T
argument_list|)
operator|>
name|class
name|ArrayRecycler
block|{
comment|// The free list for a given array size is a simple singly linked list.
comment|// We can't use iplist or Recycler here since those classes can't be copied.
block|struct
name|FreeList
block|{
name|FreeList
operator|*
name|Next
block|;   }
block|;
name|static_assert
argument_list|(
name|Align
operator|>=
name|alignof
argument_list|(
name|FreeList
argument_list|)
argument_list|,
literal|"Object underaligned"
argument_list|)
block|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|FreeList
argument_list|)
argument_list|,
literal|"Objects are too small"
argument_list|)
block|;
comment|// Keep a free list for each array size.
name|SmallVector
operator|<
name|FreeList
operator|*
block|,
literal|8
operator|>
name|Bucket
block|;
comment|// Remove an entry from the free list in Bucket[Idx] and return it.
comment|// Return NULL if no entries are available.
name|T
operator|*
name|pop
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
if|if
condition|(
name|Idx
operator|>=
name|Bucket
operator|.
name|size
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|FreeList
operator|*
name|Entry
operator|=
name|Bucket
index|[
name|Idx
index|]
block|;
if|if
condition|(
operator|!
name|Entry
condition|)
return|return
name|nullptr
return|;
name|__asan_unpoison_memory_region
argument_list|(
name|Entry
argument_list|,
name|Capacity
operator|::
name|get
argument_list|(
name|Idx
argument_list|)
operator|.
name|getSize
argument_list|()
argument_list|)
expr_stmt|;
name|Bucket
index|[
name|Idx
index|]
operator|=
name|Entry
operator|->
name|Next
expr_stmt|;
name|__msan_allocated_memory
argument_list|(
name|Entry
argument_list|,
name|Capacity
operator|::
name|get
argument_list|(
name|Idx
argument_list|)
operator|.
name|getSize
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Entry
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Add an entry to the free list at Bucket[Idx].
end_comment

begin_function
name|void
name|push
parameter_list|(
name|unsigned
name|Idx
parameter_list|,
name|T
modifier|*
name|Ptr
parameter_list|)
block|{
name|assert
argument_list|(
name|Ptr
operator|&&
literal|"Cannot recycle NULL pointer"
argument_list|)
expr_stmt|;
name|FreeList
modifier|*
name|Entry
init|=
name|reinterpret_cast
operator|<
name|FreeList
operator|*
operator|>
operator|(
name|Ptr
operator|)
decl_stmt|;
if|if
condition|(
name|Idx
operator|>=
name|Bucket
operator|.
name|size
argument_list|()
condition|)
name|Bucket
operator|.
name|resize
argument_list|(
name|size_t
argument_list|(
name|Idx
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|Entry
operator|->
name|Next
operator|=
name|Bucket
index|[
name|Idx
index|]
expr_stmt|;
name|Bucket
index|[
name|Idx
index|]
operator|=
name|Entry
expr_stmt|;
name|__asan_poison_memory_region
argument_list|(
name|Ptr
argument_list|,
name|Capacity
operator|::
name|get
argument_list|(
name|Idx
argument_list|)
operator|.
name|getSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// The size of an allocated array is represented by a Capacity instance.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class is much smaller than a size_t, and it provides methods to work
end_comment

begin_comment
comment|/// with the set of legal array capacities.
end_comment

begin_decl_stmt
name|class
name|Capacity
block|{
name|uint8_t
name|Index
decl_stmt|;
name|explicit
name|Capacity
argument_list|(
argument|uint8_t idx
argument_list|)
block|:
name|Index
argument_list|(
argument|idx
argument_list|)
block|{}
name|public
label|:
name|Capacity
argument_list|()
operator|:
name|Index
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Get the capacity of an array that can hold at least N elements.
specifier|static
name|Capacity
name|get
argument_list|(
argument|size_t N
argument_list|)
block|{
return|return
name|Capacity
argument_list|(
name|N
operator|?
name|Log2_64_Ceil
argument_list|(
name|N
argument_list|)
operator|:
literal|0
argument_list|)
return|;
block|}
comment|/// Get the number of elements in an array with this capacity.
name|size_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|size_t
argument_list|(
literal|1u
argument_list|)
operator|<<
name|Index
return|;
block|}
comment|/// Get the bucket number for this capacity.
name|unsigned
name|getBucket
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
comment|/// Get the next larger capacity. Large capacities grow exponentially, so
comment|/// this function can be used to reallocate incrementally growing vectors
comment|/// in amortized linear time.
name|Capacity
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Capacity
argument_list|(
name|Index
operator|+
literal|1
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|ArrayRecycler
argument_list|()
block|{
comment|// The client should always call clear() so recycled arrays can be returned
comment|// to the allocator.
name|assert
argument_list|(
name|Bucket
operator|.
name|empty
argument_list|()
operator|&&
literal|"Non-empty ArrayRecycler deleted!"
argument_list|)
block|;   }
comment|/// Release all the tracked allocations to the allocator. The recycler must
comment|/// be free of any tracked allocations before being deleted.
name|template
operator|<
name|class
name|AllocatorType
operator|>
name|void
name|clear
argument_list|(
argument|AllocatorType&Allocator
argument_list|)
block|{
for|for
control|(
init|;
operator|!
name|Bucket
operator|.
name|empty
argument_list|()
condition|;
name|Bucket
operator|.
name|pop_back
argument_list|()
control|)
while|while
condition|(
name|T
modifier|*
name|Ptr
init|=
name|pop
argument_list|(
name|Bucket
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
condition|)
name|Allocator
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// Special case for BumpPtrAllocator which has an empty Deallocate()
end_comment

begin_comment
comment|/// function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There is no need to traverse the free lists, pulling all the objects into
end_comment

begin_comment
comment|/// cache.
end_comment

begin_function
name|void
name|clear
parameter_list|(
name|BumpPtrAllocator
modifier|&
parameter_list|)
block|{
name|Bucket
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Allocate an array of at least the requested capacity.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return an existing recycled array, or allocate one from Allocator if
end_comment

begin_comment
comment|/// none are available for recycling.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|AllocatorType
operator|>
name|T
operator|*
name|allocate
argument_list|(
argument|Capacity Cap
argument_list|,
argument|AllocatorType&Allocator
argument_list|)
block|{
comment|// Try to recycle an existing array.
if|if
condition|(
name|T
modifier|*
name|Ptr
init|=
name|pop
argument_list|(
name|Cap
operator|.
name|getBucket
argument_list|()
argument_list|)
condition|)
return|return
name|Ptr
return|;
end_expr_stmt

begin_comment
comment|// Nope, get more memory.
end_comment

begin_return
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Allocator
operator|.
name|Allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
name|Cap
operator|.
name|getSize
argument_list|()
argument_list|,
name|Align
argument_list|)
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// Deallocate an array with the specified Capacity.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cap must be the same capacity that was given to allocate().
end_comment

begin_comment
comment|///
end_comment

begin_macro
unit|void
name|deallocate
argument_list|(
argument|Capacity Cap
argument_list|,
argument|T *Ptr
argument_list|)
end_macro

begin_block
block|{
name|push
argument_list|(
name|Cap
operator|.
name|getBucket
argument_list|()
argument_list|,
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
unit|};  }
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

