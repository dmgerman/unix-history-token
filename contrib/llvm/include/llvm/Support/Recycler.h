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
file|"llvm/Support/AlignOf.h"
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
comment|/// RecyclerStruct - Implementation detail for Recycler. This is a
comment|/// class that the recycler imposes on free'd memory to carve out
comment|/// next/prev pointers.
struct|struct
name|RecyclerStruct
block|{
name|RecyclerStruct
modifier|*
name|Prev
decl_stmt|,
modifier|*
name|Next
decl_stmt|;
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|RecyclerStruct
operator|>
operator|:
name|public
name|ilist_default_traits
operator|<
name|RecyclerStruct
operator|>
block|{
specifier|static
name|RecyclerStruct
operator|*
name|getPrev
argument_list|(
argument|const RecyclerStruct *t
argument_list|)
block|{
return|return
name|t
operator|->
name|Prev
return|;
block|}
specifier|static
name|RecyclerStruct
operator|*
name|getNext
argument_list|(
argument|const RecyclerStruct *t
argument_list|)
block|{
return|return
name|t
operator|->
name|Next
return|;
block|}
specifier|static
name|void
name|setPrev
argument_list|(
argument|RecyclerStruct *t
argument_list|,
argument|RecyclerStruct *p
argument_list|)
block|{
name|t
operator|->
name|Prev
operator|=
name|p
block|; }
specifier|static
name|void
name|setNext
argument_list|(
argument|RecyclerStruct *t
argument_list|,
argument|RecyclerStruct *n
argument_list|)
block|{
name|t
operator|->
name|Next
operator|=
name|n
block|; }
name|mutable
name|RecyclerStruct
name|Sentinel
block|;
name|RecyclerStruct
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
return|return
operator|&
name|Sentinel
return|;
block|}
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|RecyclerStruct *
argument_list|)
block|{}
name|RecyclerStruct
operator|*
name|provideInitialHead
argument_list|()
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
name|RecyclerStruct
operator|*
name|ensureHead
argument_list|(
argument|RecyclerStruct*
argument_list|)
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
specifier|static
name|void
name|noteHead
argument_list|(
argument|RecyclerStruct*
argument_list|,
argument|RecyclerStruct*
argument_list|)
block|{}
specifier|static
name|void
name|deleteNode
argument_list|(
argument|RecyclerStruct *
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Recycler's ilist_traits shouldn't see a deleteNode call!"
argument_list|)
block|;   }
expr|}
block|;
comment|/// Recycler - This class manages a linked-list of deallocated nodes
comment|/// and facilitates reusing deallocated memory in place of allocating
comment|/// new memory.
comment|///
name|template
operator|<
name|class
name|T
block|,
name|size_t
name|Size
operator|=
sizeof|sizeof
argument_list|(
name|T
argument_list|)
block|,
name|size_t
name|Align
operator|=
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
operator|>
name|class
name|Recycler
block|{
comment|/// FreeList - Doubly-linked list of nodes that have deleted contents and
comment|/// are not in active use.
comment|///
name|iplist
operator|<
name|RecyclerStruct
operator|>
name|FreeList
block|;
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
name|FreeList
operator|.
name|empty
argument_list|()
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
operator|!
name|FreeList
operator|.
name|empty
argument_list|()
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
name|FreeList
operator|.
name|remove
argument_list|(
name|FreeList
operator|.
name|begin
argument_list|()
argument_list|)
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
name|assert
argument_list|(
sizeof|sizeof
argument_list|(
name|SubClass
argument_list|)
operator|<=
name|Size
operator|&&
literal|"Recycler allocation size is less than object size!"
argument_list|)
block|;
name|assert
argument_list|(
name|AlignOf
operator|<
name|SubClass
operator|>
operator|::
name|Alignment
operator|<=
name|Align
operator|&&
literal|"Recycler allocation alignment is less than object alignment!"
argument_list|)
block|;
return|return
operator|!
name|FreeList
operator|.
name|empty
argument_list|()
condition|?
name|reinterpret_cast
operator|<
name|SubClass
operator|*
operator|>
operator|(
name|FreeList
operator|.
name|remove
argument_list|(
name|FreeList
operator|.
name|begin
argument_list|()
argument_list|)
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
name|FreeList
operator|.
name|push_front
argument_list|(
name|reinterpret_cast
operator|<
name|RecyclerStruct
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
block|{
name|PrintRecyclerStats
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|,
name|FreeList
operator|.
name|size
argument_list|()
argument_list|)
block|;   }
block|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

