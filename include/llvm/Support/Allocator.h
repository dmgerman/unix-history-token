begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Allocator.h - Simple memory allocation abstraction -----*- C++ -*-===//
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
comment|// This file defines the MallocAllocator and BumpPtrAllocator interfaces.
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
name|LLVM_SUPPORT_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ALLOCATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MallocAllocator
block|{
name|public
label|:
name|MallocAllocator
argument_list|()
block|{}
operator|~
name|MallocAllocator
argument_list|()
block|{}
name|void
name|Reset
argument_list|()
block|{}
name|void
operator|*
name|Allocate
argument_list|(
argument|size_t Size
argument_list|,
argument|size_t
comment|/*Alignment*/
argument_list|)
block|{
return|return
name|malloc
argument_list|(
name|Size
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|Allocate
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|Allocate
argument_list|(
argument|size_t Num
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
name|Num
argument_list|)
operator|)
return|;
block|}
name|void
name|Deallocate
parameter_list|(
specifier|const
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
name|free
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|Ptr
operator|)
argument_list|)
expr_stmt|;
block|}
name|void
name|PrintStats
argument_list|()
specifier|const
block|{}
block|}
empty_stmt|;
comment|/// MemSlab - This structure lives at the beginning of every slab allocated by
comment|/// the bump allocator.
name|class
name|MemSlab
block|{
name|public
label|:
name|size_t
name|Size
decl_stmt|;
name|MemSlab
modifier|*
name|NextPtr
decl_stmt|;
block|}
empty_stmt|;
comment|/// SlabAllocator - This class can be used to parameterize the underlying
comment|/// allocation strategy for the bump allocator.  In particular, this is used
comment|/// by the JIT to allocate contiguous swathes of executable memory.  The
comment|/// interface uses MemSlab's instead of void *'s so that the allocator
comment|/// doesn't have to remember the size of the pointer it allocated.
name|class
name|SlabAllocator
block|{
name|public
label|:
name|virtual
operator|~
name|SlabAllocator
argument_list|()
expr_stmt|;
name|virtual
name|MemSlab
modifier|*
name|Allocate
parameter_list|(
name|size_t
name|Size
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|Deallocate
parameter_list|(
name|MemSlab
modifier|*
name|Slab
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// MallocSlabAllocator - The default slab allocator for the bump allocator
comment|/// is an adapter class for MallocAllocator that just forwards the method
comment|/// calls and translates the arguments.
name|class
name|MallocSlabAllocator
range|:
name|public
name|SlabAllocator
block|{
comment|/// Allocator - The underlying allocator that we forward to.
comment|///
name|MallocAllocator
name|Allocator
block|;
name|public
operator|:
name|MallocSlabAllocator
argument_list|()
operator|:
name|Allocator
argument_list|()
block|{ }
name|virtual
operator|~
name|MallocSlabAllocator
argument_list|()
block|;
name|virtual
name|MemSlab
operator|*
name|Allocate
argument_list|(
argument|size_t Size
argument_list|)
block|;
name|virtual
name|void
name|Deallocate
argument_list|(
name|MemSlab
operator|*
name|Slab
argument_list|)
block|; }
decl_stmt|;
comment|/// BumpPtrAllocator - This allocator is useful for containers that need
comment|/// very simple memory allocation strategies.  In particular, this just keeps
comment|/// allocating memory, and never deletes it until the entire block is dead. This
comment|/// makes allocation speedy, but must only be used when the trade-off is ok.
name|class
name|BumpPtrAllocator
block|{
name|BumpPtrAllocator
argument_list|(
specifier|const
name|BumpPtrAllocator
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|void
name|operator
init|=
operator|(
specifier|const
name|BumpPtrAllocator
operator|&
operator|)
decl_stmt|;
comment|// do not implement
comment|/// SlabSize - Allocate data into slabs of this size unless we get an
comment|/// allocation above SizeThreshold.
name|size_t
name|SlabSize
decl_stmt|;
comment|/// SizeThreshold - For any allocation larger than this threshold, we should
comment|/// allocate a separate slab.
name|size_t
name|SizeThreshold
decl_stmt|;
comment|/// Allocator - The underlying allocator we use to get slabs of memory.  This
comment|/// defaults to MallocSlabAllocator, which wraps malloc, but it could be
comment|/// changed to use a custom allocator.
name|SlabAllocator
modifier|&
name|Allocator
decl_stmt|;
comment|/// CurSlab - The slab that we are currently allocating into.
comment|///
name|MemSlab
modifier|*
name|CurSlab
decl_stmt|;
comment|/// CurPtr - The current pointer into the current slab.  This points to the
comment|/// next free byte in the slab.
name|char
modifier|*
name|CurPtr
decl_stmt|;
comment|/// End - The end of the current slab.
comment|///
name|char
modifier|*
name|End
decl_stmt|;
comment|/// BytesAllocated - This field tracks how many bytes we've allocated, so
comment|/// that we can compute how much space was wasted.
name|size_t
name|BytesAllocated
decl_stmt|;
comment|/// AlignPtr - Align Ptr to Alignment bytes, rounding up.  Alignment should
comment|/// be a power of two.  This method rounds up, so AlignPtr(7, 4) == 8 and
comment|/// AlignPtr(8, 4) == 8.
specifier|static
name|char
modifier|*
name|AlignPtr
parameter_list|(
name|char
modifier|*
name|Ptr
parameter_list|,
name|size_t
name|Alignment
parameter_list|)
function_decl|;
comment|/// StartNewSlab - Allocate a new slab and move the bump pointers over into
comment|/// the new slab.  Modifies CurPtr and End.
name|void
name|StartNewSlab
parameter_list|()
function_decl|;
comment|/// DeallocateSlabs - Deallocate all memory slabs after and including this
comment|/// one.
name|void
name|DeallocateSlabs
parameter_list|(
name|MemSlab
modifier|*
name|Slab
parameter_list|)
function_decl|;
specifier|static
name|MallocSlabAllocator
name|DefaultSlabAllocator
decl_stmt|;
name|public
label|:
name|BumpPtrAllocator
argument_list|(
argument|size_t size =
literal|4096
argument_list|,
argument|size_t threshold =
literal|4096
argument_list|,
argument|SlabAllocator&allocator = DefaultSlabAllocator
argument_list|)
empty_stmt|;
operator|~
name|BumpPtrAllocator
argument_list|()
expr_stmt|;
comment|/// Reset - Deallocate all but the current slab and reset the current pointer
comment|/// to the beginning of it, freeing all memory allocated so far.
name|void
name|Reset
parameter_list|()
function_decl|;
comment|/// Allocate - Allocate space at the specified alignment.
comment|///
name|void
modifier|*
name|Allocate
parameter_list|(
name|size_t
name|Size
parameter_list|,
name|size_t
name|Alignment
parameter_list|)
function_decl|;
comment|/// Allocate space, but do not construct, one object.
comment|///
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|Allocate
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
argument_list|)
operator|)
return|;
block|}
comment|/// Allocate space for an array of objects.  This does not construct the
comment|/// objects though.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|Allocate
argument_list|(
argument|size_t Num
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Allocate
argument_list|(
name|Num
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
argument_list|)
operator|)
return|;
block|}
comment|/// Allocate space for a specific count of elements and with a specified
comment|/// alignment.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|Allocate
argument_list|(
argument|size_t Num
argument_list|,
argument|size_t Alignment
argument_list|)
block|{
comment|// Round EltSize up to the specified alignment.
name|size_t
name|EltSize
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|+
name|Alignment
operator|-
literal|1
operator|)
operator|&
operator|(
operator|-
name|Alignment
operator|)
block|;
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Allocate
argument_list|(
name|Num
operator|*
name|EltSize
argument_list|,
name|Alignment
argument_list|)
operator|)
return|;
block|}
name|void
name|Deallocate
parameter_list|(
specifier|const
name|void
modifier|*
comment|/*Ptr*/
parameter_list|)
block|{}
name|unsigned
name|GetNumSlabs
argument_list|()
specifier|const
expr_stmt|;
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_ALLOCATOR_H
end_comment

end_unit

