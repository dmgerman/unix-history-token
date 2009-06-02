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
comment|/// BumpPtrAllocator - This allocator is useful for containers that need very
comment|/// simple memory allocation strategies.  In particular, this just keeps
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
name|void
modifier|*
name|TheMemory
decl_stmt|;
name|public
label|:
name|BumpPtrAllocator
argument_list|()
expr_stmt|;
operator|~
name|BumpPtrAllocator
argument_list|()
expr_stmt|;
name|void
name|Reset
parameter_list|()
function_decl|;
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

end_unit

