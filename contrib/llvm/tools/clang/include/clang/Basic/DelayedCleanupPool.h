begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== DelayedCleanupPool.h - Delayed Clean-up Pool Implementation *- C++ -*===//
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
comment|// This file defines a facility to delay calling cleanup methods until specific
end_comment

begin_comment
comment|// points.
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
name|LLVM_CLANG_BASIC_DELAYEDCLEANUPPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_DELAYEDCLEANUPPOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Gathers pairs of pointer-to-object/pointer-to-cleanup-function
comment|/// allowing the cleanup functions to get called (with the pointer as parameter)
comment|/// at specific points.
comment|///
comment|/// The use case is to simplify clean-up of certain resources that, while their
comment|/// lifetime is well-known and restricted, cleaning them up manually is easy to
comment|/// miss and cause a leak.
comment|///
comment|/// The same pointer can be added multiple times; its clean-up function will
comment|/// only be called once.
name|class
name|DelayedCleanupPool
block|{
name|public
label|:
typedef|typedef
name|void
function_decl|(
modifier|*
name|CleanupFn
function_decl|)
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
comment|/// \brief Adds a pointer and its associated cleanup function to be called
comment|/// at a later point.
comment|///
comment|/// \returns false if the pointer is already added, true otherwise.
name|bool
name|delayCleanup
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|CleanupFn
name|fn
parameter_list|)
block|{
name|assert
argument_list|(
name|ptr
operator|&&
literal|"Expected valid pointer to object"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|fn
operator|&&
literal|"Expected valid pointer to function"
argument_list|)
expr_stmt|;
name|CleanupFn
modifier|&
name|mapFn
init|=
name|Ptrs
index|[
name|ptr
index|]
decl_stmt|;
name|assert
argument_list|(
operator|(
operator|!
name|mapFn
operator|||
name|mapFn
operator|==
name|fn
operator|)
operator|&&
literal|"Adding a pointer with different cleanup function!"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mapFn
condition|)
block|{
name|mapFn
operator|=
name|fn
expr_stmt|;
name|Cleanups
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|ptr
argument_list|,
name|fn
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|delayDelete
argument_list|(
argument|T *ptr
argument_list|)
block|{
return|return
name|delayCleanup
argument_list|(
name|ptr
argument_list|,
name|cleanupWithDelete
operator|<
name|T
operator|>
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|void
argument_list|(
name|T
operator|::
operator|*
name|Fn
argument_list|)
argument_list|()
operator|>
name|bool
name|delayMemberFunc
argument_list|(
argument|T *ptr
argument_list|)
block|{
return|return
name|delayCleanup
argument_list|(
name|ptr
argument_list|,
name|cleanupWithMemberFunc
operator|<
name|T
argument_list|,
name|Fn
operator|>
argument_list|)
return|;
block|}
name|void
name|doCleanup
parameter_list|()
block|{
for|for
control|(
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
operator|,
name|CleanupFn
operator|>
operator|,
literal|8
operator|>
operator|::
name|reverse_iterator
name|I
operator|=
name|Cleanups
operator|.
name|rbegin
argument_list|()
operator|,
name|E
operator|=
name|Cleanups
operator|.
name|rend
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|I
operator|->
name|second
argument_list|(
name|I
operator|->
name|first
argument_list|)
expr_stmt|;
name|Cleanups
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Ptrs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
operator|~
name|DelayedCleanupPool
argument_list|()
block|{
name|doCleanup
argument_list|()
block|;   }
name|private
operator|:
name|llvm
operator|::
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|CleanupFn
operator|>
name|Ptrs
expr_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
operator|,
name|CleanupFn
operator|>
operator|,
literal|8
operator|>
name|Cleanups
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|cleanupWithDelete
argument_list|(
argument|void *ptr
argument_list|)
block|{
name|delete
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|ptr
operator|)
block|;   }
name|template
operator|<
name|typename
name|T
operator|,
name|void
argument_list|(
name|T
operator|::
operator|*
name|Fn
argument_list|)
argument_list|()
operator|>
specifier|static
name|void
name|cleanupWithMemberFunc
argument_list|(
argument|void *ptr
argument_list|)
block|{
operator|(
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|ptr
operator|)
operator|->*
name|Fn
operator|)
operator|(
operator|)
block|;   }
block|}
empty_stmt|;
comment|/// \brief RAII object for triggering a cleanup of a DelayedCleanupPool.
name|class
name|DelayedCleanupPoint
block|{
name|DelayedCleanupPool
modifier|&
name|Pool
decl_stmt|;
name|public
label|:
name|DelayedCleanupPoint
argument_list|(
name|DelayedCleanupPool
operator|&
name|pool
argument_list|)
operator|:
name|Pool
argument_list|(
argument|pool
argument_list|)
block|{ }
operator|~
name|DelayedCleanupPoint
argument_list|()
block|{
name|Pool
operator|.
name|doCleanup
argument_list|()
block|;   }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

