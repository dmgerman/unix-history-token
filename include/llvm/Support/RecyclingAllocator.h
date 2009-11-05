begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- llvm/Support/RecyclingAllocator.h - Recycling Allocator ----*- C++ -*-==//
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
comment|// This file defines the RecyclingAllocator class.  See the doxygen comment for
end_comment

begin_comment
comment|// RecyclingAllocator for more details on the implementation.
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
name|LLVM_SUPPORT_RECYCLINGALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_RECYCLINGALLOCATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Recycler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// RecyclingAllocator - This class wraps an Allocator, adding the
comment|/// functionality of recycling deleted objects.
comment|///
name|template
operator|<
name|class
name|AllocatorType
operator|,
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
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
operator|>
name|class
name|RecyclingAllocator
block|{
name|private
operator|:
comment|/// Base - Implementation details.
comment|///
name|Recycler
operator|<
name|T
block|,
name|Size
block|,
name|Align
operator|>
name|Base
block|;
comment|/// Allocator - The wrapped allocator.
comment|///
name|AllocatorType
name|Allocator
block|;
name|public
operator|:
operator|~
name|RecyclingAllocator
argument_list|()
block|{
name|Base
operator|.
name|clear
argument_list|(
name|Allocator
argument_list|)
block|; }
comment|/// Allocate - Return a pointer to storage for an object of type
comment|/// SubClass. The storage may be either newly allocated or recycled.
comment|///
name|template
operator|<
name|class
name|SubClass
operator|>
name|SubClass
operator|*
name|Allocate
argument_list|()
block|{
return|return
name|Base
operator|.
name|template
name|Allocate
operator|<
name|SubClass
operator|>
operator|(
name|Allocator
operator|)
return|;
block|}
name|T
operator|*
name|Allocate
argument_list|()
block|{
return|return
name|Base
operator|.
name|Allocate
argument_list|(
name|Allocator
argument_list|)
return|;
block|}
comment|/// Deallocate - Release storage for the pointed-to object. The
comment|/// storage will be kept track of and may be recycled.
comment|///
name|template
operator|<
name|class
name|SubClass
operator|>
name|void
name|Deallocate
argument_list|(
argument|SubClass* E
argument_list|)
block|{
return|return
name|Base
operator|.
name|Deallocate
argument_list|(
name|Allocator
argument_list|,
name|E
argument_list|)
return|;
block|}
name|void
name|PrintStats
argument_list|()
block|{
name|Base
operator|.
name|PrintStats
argument_list|()
block|; }
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

