begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- llvm/Support/Recycler.h - Recycling Allocator --------------*- C++ -*-==//
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
comment|// This file defines the Recycler class template.  See the doxygen comment for
end_comment

begin_comment
comment|// Recycler for more details.
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
name|LLVM_SUPPORT_RECYCLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_RECYCLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PrintRecyclingAllocatorStats - Helper for RecyclingAllocator for
comment|/// printing statistics.
comment|///
name|void
name|PrintRecyclerStats
parameter_list|(
name|size_t
name|Size
parameter_list|,
name|size_t
name|Align
parameter_list|,
name|size_t
name|FreeListSize
parameter_list|)
function_decl|;
comment|/// Recycler - This class manages a linked-list of deallocated nodes
comment|/// and facilitates reusing deallocated memory in place of allocating
comment|/// new memory.
comment|///
name|template
operator|<
name|class
name|T
operator|,
name|size_t
name|Size
operator|=
sizeof|sizeof
argument_list|(
name|T
argument_list|)
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
name|Recycler
block|{   struct
name|FreeNode
block|{
name|FreeNode
operator|*
name|Next
block|;   }
block|;
comment|/// List of nodes that have deleted contents and are not in active use.
name|FreeNode
operator|*
name|FreeList
operator|=
name|nullptr
block|;
name|FreeNode
operator|*
name|pop_val
argument_list|()
block|{
name|auto
operator|*
name|Val
operator|=
name|FreeList
block|;
name|__asan_unpoison_memory_region
argument_list|(
name|Val
argument_list|,
name|Size
argument_list|)
block|;
name|FreeList
operator|=
name|FreeList
operator|->
name|Next
block|;
name|__msan_allocated_memory
argument_list|(
name|Val
argument_list|,
name|Size
argument_list|)
block|;
return|return
name|Val
return|;
block|}
name|void
name|push
argument_list|(
argument|FreeNode *N
argument_list|)
block|{
name|N
operator|->
name|Next
operator|=
name|FreeList
block|;
name|FreeList
operator|=
name|N
block|;
name|__asan_poison_memory_region
argument_list|(
name|N
argument_list|,
name|Size
argument_list|)
block|;   }
name|public
operator|:
operator|~
name|Recycler
argument_list|()
block|{
comment|// If this fails, either the callee has lost track of some allocation,
comment|// or the callee isn't tracking allocations and should just call
comment|// clear() before deleting the Recycler.
name|assert
argument_list|(
operator|!
name|FreeList
operator|&&
literal|"Non-empty recycler deleted!"
argument_list|)
block|;   }
comment|/// clear - Release all the tracked allocations to the allocator. The
comment|/// recycler must be free of any tracked allocations before being
comment|/// deleted; calling clear is one way to ensure this.
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
while|while
condition|(
name|FreeList
condition|)
block|{
name|T
modifier|*
name|t
init|=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|pop_val
argument_list|()
operator|)
decl_stmt|;
name|Allocator
operator|.
name|Deallocate
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// Special case for BumpPtrAllocator which has an empty Deallocate()
comment|/// function.
comment|///
comment|/// There is no need to traverse the free list, pulling all the objects into
comment|/// cache.
name|void
name|clear
argument_list|(
argument|BumpPtrAllocator&
argument_list|)
block|{
name|FreeList
operator|=
name|nullptr
block|; }
name|template
operator|<
name|class
name|SubClass
block|,
name|class
name|AllocatorType
operator|>
name|SubClass
operator|*
name|Allocate
argument_list|(
argument|AllocatorType&Allocator
argument_list|)
block|{
name|static_assert
argument_list|(
name|alignof
argument_list|(
name|SubClass
argument_list|)
operator|<=
name|Align
argument_list|,
literal|"Recycler allocation alignment is less than object align!"
argument_list|)
block|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|SubClass
argument_list|)
operator|<=
name|Size
argument_list|,
literal|"Recycler allocation size is less than object size!"
argument_list|)
block|;
return|return
name|FreeList
condition|?
name|reinterpret_cast
operator|<
name|SubClass
operator|*
operator|>
operator|(
name|pop_val
argument_list|()
operator|)
else|:
name|static_cast
operator|<
name|SubClass
operator|*
operator|>
operator|(
name|Allocator
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
operator|)
return|;
block|}
name|template
operator|<
name|class
name|AllocatorType
operator|>
name|T
operator|*
name|Allocate
argument_list|(
argument|AllocatorType&Allocator
argument_list|)
block|{
return|return
name|Allocate
operator|<
name|T
operator|>
operator|(
name|Allocator
operator|)
return|;
block|}
name|template
operator|<
name|class
name|SubClass
block|,
name|class
name|AllocatorType
operator|>
name|void
name|Deallocate
argument_list|(
argument|AllocatorType&
comment|/*Allocator*/
argument_list|,
argument|SubClass* Element
argument_list|)
block|{
name|push
argument_list|(
name|reinterpret_cast
operator|<
name|FreeNode
operator|*
operator|>
operator|(
name|Element
operator|)
argument_list|)
block|;   }
name|void
name|PrintStats
argument_list|()
block|; }
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|,
name|size_t
name|Size
operator|,
name|size_t
name|Align
operator|>
name|void
name|Recycler
operator|<
name|T
operator|,
name|Size
operator|,
name|Align
operator|>
operator|::
name|PrintStats
argument_list|()
block|{
name|size_t
name|S
operator|=
literal|0
block|;
for|for
control|(
name|auto
operator|*
name|I
operator|=
name|FreeList
init|;
name|I
condition|;
name|I
operator|=
name|I
operator|->
name|Next
control|)
operator|++
name|S
expr_stmt|;
name|PrintRecyclerStats
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|,
name|S
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

